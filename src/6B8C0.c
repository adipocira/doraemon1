#include "6B8C0.h"
#include "23B20.h"
#include "29980.h"
#include "9320.h"
#include "73660.h"
#include "11F10.h"
#include "common.h"

#include "libc/math.h"

extern s16 D_800FB340;
extern s16 D_800B5370;

extern s32 D_801DA7E4[];
extern s32 D_801DA7FC[];
extern s32 D_801DA814[];
extern s32 D_801DA868[];
extern s32 D_801DA894[];
extern s32 D_801DA8C0[];
extern s32 D_801DA8EC[];
extern s32 D_801DA918[];

extern s32 D_800B61A0;

extern u8 D_801522E4;
extern u8 D_801522E5;
extern u8 D_801522E6;
extern u8 D_801522E7;
extern u8 D_801522E8;
extern u8 D_801522E9;

void func_8006ACC0(s16 idx){
    f32 dist = func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0);

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            GET_ACTOR_PTR(idx)->status = 1;
            break;
        case 1:
            D_800FB340 = 1;

            func_800240CC(2);
            func_800240CC(3);
            func_800240CC(4);
            func_800240CC(5);
            func_800240CC(6);
            func_800240CC(7);
            func_800240CC(8);
            func_800240CC(9);

            func_80023468(D_801DA7E4);

            GET_ACTOR_PTR(idx)->status = 2;
            break;
        case 2:
            if(dist >= 1200.0f){
                GET_ACTOR_PTR(idx)->status = 3;
            }
            break;
        case 3:
            if(dist < 1200.0f){
                GET_ACTOR_PTR(idx)->status = 0;
            }
            break;
    }
}

void func_8006AE08(s16 idx){
    f32 dist = func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0);

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            GET_ACTOR_PTR(idx)->status = 1;
            break;
        case 1:
            D_800FB340 = 2;

            func_800240CC(2);
            func_800240CC(3);
            func_800240CC(4);
            func_800240CC(5);
            func_800240CC(6);
            func_800240CC(7);
            func_800240CC(8);
            func_800240CC(9);

            func_80023468(D_801DA7FC);

            GET_ACTOR_PTR(idx)->status = 2;
            break;
        case 2:
            if(dist >= 1200.0f){
                GET_ACTOR_PTR(idx)->status = 3;
            }
            break;
        case 3:
            if(dist < 1200.0f){
                GET_ACTOR_PTR(idx)->status = 0;
            }
            break;
    }
}

void func_8006AF54(s16 idx){
    f32 dist = func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0);
    s32 id;
    
    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            GET_ACTOR_PTR(idx)->status = 1;
            break;
        case 1:
            D_800FB340 = 3;

            func_800240CC(2);
            func_800240CC(3);
            func_800240CC(4);
            func_800240CC(5);
            func_800240CC(6);
            func_800240CC(7);
            func_800240CC(8);
            func_800240CC(9);

            if(func_80076FA0(0x23)){
                id = func_80023644(8, 0x63, -1411.0f, -1099.0f, -658.0f, 0.0f, 90.0f, 0.0f);

                if(id != -1){
                    GET_ACTOR_PTR(id)->actorVars.varA0.integer = 1;
                    GET_ACTOR_PTR(id)->unk64 = 3;
                }
            }
            else if(func_80076FA0(0x40U)){
                id = func_80023644(8, 0x63, -1411.0f, -1099.0f, -658.0f, 0.0f, 90.0f, 0.0f);

                if(id != -1){
                    GET_ACTOR_PTR(id)->actorVars.varA0.integer = 2;
                    GET_ACTOR_PTR(id)->unk64 = 3;
                }
            }
            else if(func_80076FA0(0x3B)){
                id = func_80023644(8, 0x63, -1411.0f, -1099.0f, -658.0f, 0.0f, 90.0f, 0.0f);

                if(id != -1){
                    GET_ACTOR_PTR(id)->actorVars.varA0.integer = 3;
                    GET_ACTOR_PTR(id)->unk64 = 3;
                }

                func_80076FA0(0x3B);
            }

            func_80023468(D_801DA814);

            GET_ACTOR_PTR(idx)->status = 2;
            break;
        case 2:
            if(dist >= 1200.0f){
                GET_ACTOR_PTR(idx)->status = 3;
            }
            break;
        case 3:
            if(dist < 1200.0f){
                GET_ACTOR_PTR(idx)->status = 0;
            }
            break;
    }
}

void func_8006B208(s16 idx){
    f32 dist = func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0);

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            GET_ACTOR_PTR(idx)->status = 1;
            break;
        case 1:
            D_800FB340 = 4;

            func_800240CC(2);
            func_800240CC(3);
            func_800240CC(4);
            func_800240CC(5);
            func_800240CC(6);
            func_800240CC(7);
            func_800240CC(8);
            func_800240CC(9);

            func_80023468(D_801DA868);

            GET_ACTOR_PTR(idx)->status = 2;
            break;
        case 2:
            if(dist >= 1200.0f){
                GET_ACTOR_PTR(idx)->status = 3;
            }
            break;
        case 3:
            if(dist < 1200.0f){
                GET_ACTOR_PTR(idx)->status = 0;
            }
            break;
    }
}

void func_8006B354(s16 idx){
    f32 dist = func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0);

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            GET_ACTOR_PTR(idx)->status = 1;
            break;
        case 1:
            D_800FB340 = 5;

            func_800240CC(2);
            func_800240CC(3);
            func_800240CC(4);
            func_800240CC(5);
            func_800240CC(6);
            func_800240CC(7);
            func_800240CC(8);
            func_800240CC(9);

            func_80023468(D_801DA894);

            GET_ACTOR_PTR(idx)->status = 2;
            break;
        case 2:
            if(dist >= 1200.0f){
                GET_ACTOR_PTR(idx)->status = 3;
            }
            break;
        case 3:
            if(dist < 1200.0f){
                GET_ACTOR_PTR(idx)->status = 0;
            }
            break;
    }
}

void func_8006B4A0(s16 idx){
    f32 dist = func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0);

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            GET_ACTOR_PTR(idx)->status = 1;
            break;
        case 1:
            D_800FB340 = 6;

            func_800240CC(2);
            func_800240CC(3);
            func_800240CC(4);
            func_800240CC(5);
            func_800240CC(6);
            func_800240CC(7);
            func_800240CC(8);
            func_800240CC(9);

            func_80023468(D_801DA8C0);

            GET_ACTOR_PTR(idx)->status = 2;
            break;
        case 2:
            if(dist >= 1200.0f){
                GET_ACTOR_PTR(idx)->status = 3;
            }
            break;
        case 3:
            if(dist < 1200.0f){
                GET_ACTOR_PTR(idx)->status = 0;
            }
            break;
    }
}

void func_8006B5EC(s16 idx){
    f32 dist = func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0);

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            GET_ACTOR_PTR(idx)->status = 1;
            break;
        case 1:
            D_800FB340 = 7;

            func_800240CC(2);
            func_800240CC(3);
            func_800240CC(4);
            func_800240CC(5);
            func_800240CC(6);
            func_800240CC(7);
            func_800240CC(8);
            func_800240CC(9);

            func_80023468(D_801DA8EC);

            GET_ACTOR_PTR(idx)->status = 2;
            break;
        case 2:
            if(dist >= 1200.0f){
                GET_ACTOR_PTR(idx)->status = 3;
            }
            break;
        case 3:
            if(dist < 1200.0f){
                GET_ACTOR_PTR(idx)->status = 0;
            }
            break;
    }
}

void func_8006B738(s16 idx){
    f32 dist = func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0);
    s32 i;
    s32 id;
    s32 a2;

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            GET_ACTOR_PTR(idx)->status = 1;
            break;
        case 1:
            D_800FB340 = 8;

            func_800240CC(2);
            func_800240CC(3);
            func_800240CC(4);
            func_800240CC(5);
            func_800240CC(6);
            func_800240CC(7);
            func_800240CC(8);
            func_800240CC(9);

            func_80023468(D_801DA918);

            GET_ACTOR_PTR(idx)->status = 2;
            break;
        case 2:
            if(dist >= 1200.0f){
                GET_ACTOR_PTR(idx)->status = 3;
            }
            if(func_80076FA0(0x40)){
                a2 = 0;
                
                if((D_800B5370 & 4) != 4){ 
                    for(i = 0; i < 0x100; i++){
                        if(GET_ACTOR_PTR(i)->unk0 && D_800FB340 == GET_ACTOR_PTR(i)->unk64 && GET_ACTOR_PTR(i)->unk48 == 0x5E){
                            a2 = 1;
                            break;
                        }
                    }

                    if(a2 == 0 && func_80076FA0(0x40)){
                        if((D_800B5370 & 4) != 4){
                            func_800073C0(0x37, 1);
                            id = func_80023644(8, 0x81, 3393.0f, 1231.0f, 518.0f, 0.0f, 270.0f, 0.0f);

                            if(id != -1){
                                GET_ACTOR_PTR(id)->unk68 = 0x40;
                                D_800B5370 |= 4;
                            }
                        }
                    }
                }
            }
            break;
        case 3:
            if(dist < 1200.0f){
                GET_ACTOR_PTR(idx)->status = 0;
            }
            break;
    }
}


void func_8006B9AC(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    s16 i;
    s16 s0;
    s16 id;
    s32 temp;
    f32 fs2;
    f32 fs3;
    f32 fs1;
    f32 f2;
    f32 t4;
    f32 f0;

    (void)"current group = %d ( %d, %d )\n";
    (void)" cast\n";
    
    switch(GET_ACTOR_PTR(idx)->status){ 
        case 0:
            id = func_80023498(8, 0x1CC, -4489.0f, -1999.0f, -52.0f, 0.0f, 0.0f, 0.0f);

            if(id != -1){
                func_80022F20(id, func_8006ACC0);
            }
            
            id = func_80023498(8, 0x1CC, -3042.0f, -1499.0f, 436.0f, 0.0f, 0.0f, 0.0f);

            if(id != -1){
                func_80022F20(id, func_8006AE08);
            }
            
            id = func_80023498(8, 0x1CC, -1422.0f, -1099.0f, -687.0f, 0.0f, 0.0f, 0.0f);

            if(id != -1){
                func_80022F20(id, func_8006AF54);
            }
            
            id = func_80023498(8, 0x1CC, -49.0f, -704.0f, 378.0f, 0.0f, 0.0f, 0.0f);

            if(id != -1){
                func_80022F20(id, func_8006B208);
            }
            
            id = func_80023498(8, 0x1CC, 758.0f, 301.0f, -682.0f, 0.0f, 0.0f, 0.0f);

            if(id != -1){
                func_80022F20(id, func_8006B354);
            }
            
            id = func_80023498(8, 0x1CC, 2052.0f, 701.0f, -16.0f, 0.0f, 0.0f, 0.0f);

            if(id != -1){
                func_80022F20(id, func_8006B4A0);
            }
            
            id = func_80023498(8, 0x1CC, 3392.0f, 1201.0f, 510.0f, 0.0f, 0.0f, 0.0f);

            if(id != -1){
                func_80022F20(id, func_8006B5EC);
            }
            
            id = func_80023498(8, 0x1CC, 4643.0f, 1442.0f, -559.0f, 0.0f, 0.0f, 0.0f);

            if(id != -1){
                func_80022F20(id, func_8006B738);
            }

            func_80008C6C(0xE5, 5);

            if(func_80076FA0(0x32)){
                id = func_80023644(1, 0x32, 4575.0f, 1497.0f, -590.0f, 0.0f, 0.0f, 0.0f);
            }
            else{
                id = func_80023644(8, 0x81, 4645.0f, 1880.0f, -547.0f, 0.0f, 180.0f, 0.0f);

                if(id != -1){
                    GET_ACTOR_PTR(id)->unk68 = 0x3B;
                }
            }

            D_800B5370 = 0;

            if(func_80076FA0(0x23)){
                D_800B5370 &= ~1;
            }
            else{
                D_800B5370 |= ~4;
            }
            if(func_80076FA0(0x39)){
                D_800B5370 &= ~2;
            }
            else{
                D_800B5370 |= 2;
            }
            if(func_80076FA0(0x40)){
                D_800B5370 &= ~4;
            }
            else{
                D_800B5370 |= 4;
            }

            actor->actorVars.varA0.integer = 0;
            actor->actorVars.varA4.integer = 0;
            actor->actorVars.varA8.integer = 0;
            actor->actorVars.varB4.integer = 0;

            GET_ACTOR_PTR(idx)->status = 1;
            D_800B61A0 = 0;
            break;
        case 1:
            if(D_800F0548.unk4 == -50.0f){
                func_80008C6C(1, 4);
            }
            if(D_800F0548.unk4 > -10.0f){
                GET_ACTOR_PTR(idx)->status = 2;
                func_800090B0(5);
            }

            actor->actorVars.varB4.integer++;
            break;
        case 2:
            if(D_800F0548.unk4 <= -10.0f){
                func_80008C6C(0xE5, 5);
                GET_ACTOR_PTR(idx)->status = 1;
            }

            actor->actorVars.varB4.integer++;
            break;
    }

    if(D_800F0548.unk4 < -3000.0f){
        actor->actorVars.varA0.integer = 11;
    }
    else if(D_800F0548.unk4 < -1750.0f){
        actor->actorVars.varA0.integer = 12;
    }
    else if(D_800F0548.unk4 < -250.0f){
        actor->actorVars.varA0.integer = 13;
    }
    else if(D_800F0548.unk4 < 1250.0f){
        actor->actorVars.varA0.integer = 14;
    }
    else{
        actor->actorVars.varA0.integer = 15;
    }

    for(i = 1; actor->actorVars.varA4.integer != actor->actorVars.varA0.integer && actor->actorVars.varA8.integer != actor->actorVars.varA0.integer && i < 3; i++){
        temp = actor->actorVars.rawVars[i].integer - actor->actorVars.varA0.integer;

        if(temp >= 2 || temp < -1){
            if(actor->actorVars.rawVars[i].integer != 0){
                func_800240CC(actor->actorVars.rawVars[i].integer);
            }
            switch(actor->actorVars.varA0.integer){
                case 11:
                    id = func_80023644(6, 0x184, -300.0f, -3500.0f, 500.0f, 0.0f, 0.0f, 0.0f);
                    break;
                case 12:
                    id = func_80023644(6, 0x184, -500.0f, -2500.0f, -600.0f, 0.0f, 0.0f, 0.0f);
                    break;
                case 13:
                    id = func_80023644(6, 0x184, 200.0f, -1000.0f, -200.0f, 0.0f, 0.0f, 0.0f);
                    break;
                case 14:
                    id = func_80023644(6, 0x184, 500.0f, 500.0f, -400.0f, 0.0f, 0.0f, 0.0f);
                    break;
                case 15:
                    id = func_80023644(6, 0x184, 200.0f, 2000.0f, 200.0f, 0.0f, 0.0f, 0.0f);
                    break;
            }
            if(id != -1){
                GET_ACTOR_PTR(id)->unk64 = actor->actorVars.varA0.integer;
                actor->actorVars.rawVars[i].integer = actor->actorVars.varA0.integer;
                actor->actorVars.rawVars[i+2].integer = id;
            }
        }
    }
    for(i = 1; i < 3; i++){
        if(GET_ACTOR_PTR(actor->actorVars.rawVars[i+2].integer)->unk0 == 0 || GET_ACTOR_PTR(actor->actorVars.rawVars[i+2].integer)->unk48 != 0x184){
            actor->actorVars.rawVars[i].integer = 0;
        }
    }
    if(D_800F0548.unk4 > -400.0f){
        if(D_800F0548.unk4 < 24.0f){
            for(i = 0; i < 3; i++){
                fs2 = (random(0) % 300U) - 150.0f;
                fs3 = (random(0) % 100U) - 50.0f;
                fs1 = (random(0) % 300U) - 150.0f;

                id = func_80023644(6, 0x183, fs2 + D_800F0548.unk0, fs3 + D_800F0548.unk4, fs1 + D_800F0548.unk8, 0.0f, 0.0f, 0.0f);

                if(id != -1){
                    func_80022F20(id, func_8002B6D4);

                    GET_ACTOR_PTR(id)->actorVars.varA4.fp = fs2;
                    GET_ACTOR_PTR(id)->actorVars.varA8.fp = fs3;
                    GET_ACTOR_PTR(id)->actorVars.varAC.fp = fs1;
                    
                }
            }
        }
    }
    if(D_800F0548.unk4 < -240.0f){
        if(actor->actorVars.varB4.integer % 2U){
            if(D_800F0548.unk4 > -620.0f){
                s0 = 2;
            }
            else{
                s0 = 3;
            }

            for(i = 0; i < s0; i++){
                fs1 = func_80025C48(D_800F0548.unk14 - D_800F0548.unk8, D_800F0548.unkC - D_800F0548.unk0);
                
                f2 = (random(0) % 120U) - 60.0f + fs1; // sp68
            
                NORM_ANGLE(f2);

                t4 = (random(0) % 300U) + 60.0f;
                fs2 = DEG2RAD_ALT3(f2);
                
                fs1 = t4 * cosf(fs2);
                fs2 = t4 * sinf(fs2);
                
                fs2 += D_800F0548.unk0;
                fs3 = D_800F0548.unk4 + 300.0f;
                fs1 += D_800F0548.unk8;

                func_80023644(6, 0x187, fs2, fs3, fs1, 0.0f, 0.0f, 0.0f);
            }
        }
        D_801522E4 = 0xA0;
        D_801522E5 = 0xA0;
        D_801522E6 = 0xA0;
        D_801522E7 = 0x3C;
        D_801522E8 = 0x3C;
        D_801522E9 = 0x3C;
    }
    else{
        f0 = D_800F0548.unk4 - -240.0f;

        if(f0 > 90.0f){
            f0 = 90.0f;
        }        
        
        D_801522E4 = f0 * 1.5 + 115;
        D_801522E5 = f0 * 1.5 + 115;
        D_801522E6 = 160.0f + f0;
        D_801522E7 = 60.0f + f0;
        D_801522E8 = 60.0f + f0;
        D_801522E9 = 60.0f + f0;
    }
    
}
