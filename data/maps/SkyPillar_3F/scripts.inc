SkyPillar_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_3F_OnTransition
	.byte 0

SkyPillar_3F_OnTransition:
	end

SkyPillar_3F_EventScript_CleanFloor::
	setmaplayoutindex LAYOUT_SKY_PILLAR_3F_CLEAN
	return

