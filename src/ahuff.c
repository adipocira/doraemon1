#include "bitio.h"
#include "ultra64.h"

#define END_OF_STREAM 256
#define ESCAPE 257
#define SYMBOL_COUNT 258
#define NODE_TABLE_COUNT ((SYMBOL_COUNT * 2) - 1)
#define ROOT_NODE 0
#define MAX_WEIGHT 0x8000

#define EOF -1


typedef struct tree {
    int leaf[SYMBOL_COUNT];
    int next_free_node;
    struct node {
        unsigned int weight;
        int parent;
        int child_is_leaf;
        int child;
    } nodes[NODE_TABLE_COUNT];
} TREE;

void ExpandFile(TREE* tree, BIT_FILE* input, u8* output);
void InitializeTree(TREE* tree);
int DecodeSymbol(TREE* tree, BIT_FILE* input);
void UpdateModel(TREE* tree, int c);
void RebuildTree(TREE* tree);
void swap_nodes(TREE* tree, int i, int j);
void add_new_node(TREE* tree, int c);

void ExpandFile(TREE* tree, BIT_FILE* input, u8* output) {
    int c;

    InitializeTree(tree);

    while ((c = DecodeSymbol(tree, input)) != END_OF_STREAM) {
        if (putc(c, output) == EOF) {
            fatal_error("Error writing character");
        }
        UpdateModel(tree, c);
    }
}

void InitializeTree(TREE* tree) {
    int i;

    tree->nodes[ROOT_NODE].child = ROOT_NODE + 1;
    tree->nodes[ROOT_NODE].child_is_leaf = FALSE;
    tree->nodes[ROOT_NODE].weight = 2;
    tree->nodes[ROOT_NODE].parent = -1;

    tree->nodes[ROOT_NODE + 1].child = END_OF_STREAM;
    tree->nodes[ROOT_NODE + 1].child_is_leaf = TRUE;
    tree->nodes[ROOT_NODE + 1].weight = 1;
    tree->nodes[ROOT_NODE + 1].parent = ROOT_NODE;
    tree->leaf[END_OF_STREAM] = ROOT_NODE + 1;

    tree->nodes[ROOT_NODE + 2].child = ESCAPE;
    tree->nodes[ROOT_NODE + 2].child_is_leaf = TRUE;
    tree->nodes[ROOT_NODE + 2].weight = 1;
    tree->nodes[ROOT_NODE + 2].parent = ROOT_NODE;
    tree->leaf[ESCAPE] = ROOT_NODE + 2;

    tree->next_free_node = ROOT_NODE + 3;

    for (i = 0; i < END_OF_STREAM; i++) {
        tree->leaf[i] = -1;
    }
}

int DecodeSymbol(TREE* tree, BIT_FILE* input) {
    int current_node;
    int c;

    current_node = ROOT_NODE;
    while (!tree->nodes[current_node].child_is_leaf) {
        current_node = tree->nodes[current_node].child;
        current_node += InputBit(input);
    }
    c = tree->nodes[current_node].child;

    if (c == ESCAPE) {
        c = (int)InputBits(input, 8);
        add_new_node(tree, c);
    }
    return (c);
}

void UpdateModel(TREE* tree, int c) {
    int current_node;
    int new_node;

    if (tree->nodes[ROOT_NODE].weight == MAX_WEIGHT) {
        RebuildTree(tree);
    }
    current_node = tree->leaf[c];
    while (current_node != -1) {
        tree->nodes[current_node].weight++;
        for (new_node = current_node; new_node > ROOT_NODE; new_node--) {
            if (tree->nodes[new_node - 1].weight >= tree->nodes[current_node].weight) {
                break;
            }
        }
        if (current_node != new_node) {
            swap_nodes(tree, current_node, new_node);
            current_node = new_node;
        }
        current_node = tree->nodes[current_node].parent;
    }
}

void RebuildTree(TREE* tree) {
    int i;
    int j;
    int k;
    u32 weight;

    j = tree->next_free_node - 1;
    for (i = j; i >= ROOT_NODE; i--) {
        if (tree->nodes[i].child_is_leaf) {
            tree->nodes[j] = tree->nodes[i];
            tree->nodes[j].weight = (tree->nodes[j].weight + 1) / 2;
            j--;
        }
    }
    for (i = tree->next_free_node - 2; j >= ROOT_NODE; i -= 2, j--) {
        k = i + 1;
        tree->nodes[j].weight = tree->nodes[i].weight + tree->nodes[k].weight;
        weight = tree->nodes[j].weight;
        tree->nodes[j].child_is_leaf = FALSE;
        for (k = j + 1; weight < tree->nodes[k].weight; k++) {};

        k--;

        memmove(&tree->nodes[j], &tree->nodes[j + 1], (k - j) * sizeof(struct node));

        tree->nodes[k].weight = weight;
        tree->nodes[k].child = i;
        tree->nodes[k].child_is_leaf = FALSE;
    }

    for (i = tree->next_free_node - 1; i >= ROOT_NODE; i--) {
        if (tree->nodes[i].child_is_leaf) {
            k = tree->nodes[i].child;
            tree->leaf[k] = i;
        } else {
            k = tree->nodes[i].child;
            tree->nodes[k].parent = tree->nodes[k + 1].parent = i;
        }
    }
}

void swap_nodes(TREE* tree, int i, int j) {
    struct node temp;

    if (tree->nodes[i].child_is_leaf) {
        tree->leaf[tree->nodes[i].child] = j;
    } else {
        tree->nodes[tree->nodes[i].child].parent = j;
        tree->nodes[tree->nodes[i].child + 1].parent = j;
    }
    if (tree->nodes[j].child_is_leaf) {
        tree->leaf[tree->nodes[j].child] = i;
    } else {
        tree->nodes[tree->nodes[j].child].parent = i;
        tree->nodes[tree->nodes[j].child + 1].parent = i;
    }
    temp = tree->nodes[i];
    tree->nodes[i] = tree->nodes[j];
    tree->nodes[i].parent = temp.parent;
    temp.parent = tree->nodes[j].parent;
    tree->nodes[j] = temp;
}

void add_new_node(TREE* tree, int c) {
    int lightest_node;
    int new_node;
    int zero_weight_node;

    lightest_node = tree->next_free_node - 1;
    new_node = tree->next_free_node;
    zero_weight_node = tree->next_free_node + 1;
    tree->next_free_node += 2;

    tree->nodes[new_node] = tree->nodes[lightest_node];
    tree->nodes[new_node].parent = lightest_node;
    tree->leaf[tree->nodes[new_node].child] = new_node;

    tree->nodes[lightest_node].child = new_node;
    tree->nodes[lightest_node].child_is_leaf = FALSE;

    tree->nodes[zero_weight_node].child = c;
    tree->nodes[zero_weight_node].child_is_leaf = TRUE;
    tree->nodes[zero_weight_node].weight = 0;
    tree->nodes[zero_weight_node].parent = lightest_node;
    tree->leaf[c] = zero_weight_node;
}
