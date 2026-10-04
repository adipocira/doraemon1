#ifndef ZZ_EVENTS_H
#define ZZ_EVENTS_H

#include "ultra64.h"

#define GAME_LEVEL_EVENT(x) (u32)(1 << (x))

typedef enum Game0LevelDevilEvents{
	ZZ_LEVEL_DEVIL_EVENT_FIGHT_WON = 14,
	ZZ_LEVEL_DEVIL_EVENT_FIGHT_VISIT = 15,
}Game0LevelDevilEvents;

typedef enum Game0Level11Events{
	ZZ_LEVEL_1_1_EVENT_FIGHT_WON = 14,
	ZZ_LEVEL_1_1_EVENT_FIGHT_VISIT = 15,
}Game0Level11Events;

typedef enum Game0Level12Events{
	_Game0Level12Events_dummy,
}Game0Level12Events;

typedef enum Game0Level13Events{
	_Game0Level13Events_dummy,
}Game0Level13Events;

typedef enum Game0Level14Events{
	ZZ_LEVEL_1_4_EVENT_LAVA_LOWERED = 0,
	ZZ_LEVEL_1_4_EVENT_FIGHT_WON = 14,
	ZZ_LEVEL_1_4_EVENT_FIGHT_VISIT = 15,
}Game0Level14Events;

typedef enum Game0Level21Events{
	ZZ_LEVEL_2_1_EVENT_WATER_RAISED = 0,
}Game0Level21Events;

typedef enum Game0Level22Events{
	ZZ_LEVEL_2_2_EVENT_RACE_NOT_STARTED = 0,
	ZZ_LEVEL_2_2_EVENT_RACE_STARTED = 1,
}Game0Level22Events;

typedef enum Game0Level23Events{
	ZZ_LEVEL_2_3_EVENT_WESTERN_STALACTITE_DOWN = 0,
	ZZ_LEVEL_2_3_EVENT_MIDDLE_STALACTITE_DOWN = 1,
	ZZ_LEVEL_2_3_EVENT_EASTERN_STALACTITE_DOWN = 2,
	ZZ_LEVEL_2_3_EVENT_SHIP_RAISED = 3,
	ZZ_LEVEL_2_3_EVENT_FIGHT_WON = 14,
	ZZ_LEVEL_2_3_EVENT_FIGHT_VISIT = 15,
}Game0Level23Events;

typedef enum Game0Level24Events{
	ZZ_LEVEL_2_4_EVENT_DRAWBRIDGE_LOWERED = 0,
	ZZ_LEVEL_2_4_EVENT_FIGHT_WON = 14,
	ZZ_LEVEL_2_4_EVENT_FIGHT_VISIT = 15,
}Game0Level24Events;

typedef enum Game0Level31Events{
	ZZ_LEVEL_3_1_EVENT_FIGHT_WON = 14,
	ZZ_LEVEL_3_1_EVENT_FIGHT_VISIT = 15,
}Game0Level31Events;

typedef enum Game0Level32Events{
	_Game0Level32Events_dummy,
}Game0Level32Events;

typedef enum Game0Level33Events{
	_Game0Level33Events_dummy,
}Game0Level33Events;

typedef enum Game0Level34Events{
	ZZ_LEVEL_3_4_EVENT_FIGHT_WON = 14,
	ZZ_LEVEL_3_4_EVENT_FIGHT_VISIT = 15,
}Game0Level34Events;

typedef enum Game0LevelOverworldGroundEvents{
	ZZ_LEVEL_OVERWORLD_GROUND_EVENT_POKERA_DIALOG = 1,
	ZZ_LEVEL_OVERWORLD_GROUND_EVENT_CAVE_DIALOG = 2,
	ZZ_LEVEL_OVERWORLD_GROUND_EVENT_VOLCANO_DIALOG = 3,
	ZZ_LEVEL_OVERWORLD_GROUND_EVENT_RACE_DIALOG = 5,
	ZZ_LEVEL_OVERWORLD_GROUND_EVENT_SHIP_DIALOG = 6,
	ZZ_LEVEL_OVERWORLD_GROUND_EVENT_SANTA_DIALOG = 7,
	ZZ_LEVEL_OVERWORLD_GROUND_EVENT_SEA_DIALOG = 8,
	ZZ_LEVEL_OVERWORLD_GROUND_EVENT_AIR_DIALOG = 9,
}Game0LevelOverworldGroundEvents;

typedef enum Game0LevelOverworldAirEvents{
	ZZ_LEVEL_OVERWORLD_AIR_EVENT_BIRD_AVAILABLE = 1,
	ZZ_LEVEL_OVERWORLD_AIR_EVENT_THUNDER_DIALOG = 2,
	ZZ_LEVEL_OVERWORLD_AIR_EVENT_CASTLE_DIALOG = 3,
	ZZ_LEVEL_OVERWORLD_AIR_EVENT_FIRST_DIALOG = 4,
}Game0LevelOverworldAirEvents;

typedef enum Game0LevelIntroTokyoEvents{
	_Game0LevelIntroTokyoEvents_dummy,
}Game0LevelIntroTokyoEvents;

typedef enum Game0LevelIntroDebugEvents{
	_Game0LevelIntroDebugEvents_dummy,
}Game0LevelIntroDebugEvents;

#endif
