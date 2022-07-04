AlteringCave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AlteringCave_OnTransition
	.byte 0

AlteringCave_OnTransition:
	addvar VAR_ALTERING_CAVE_WILD_SET, 1
	setflag FLAG_LANDMARK_ALTERING_CAVE
	end

