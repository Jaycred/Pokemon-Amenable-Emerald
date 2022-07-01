.set LOCALID_WALLACE, 1
.set LOCALID_STEVEN, 2

EverGrandeCity_HallOfFame_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_HallOfFame_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_HallOfFame_OnWarp
	.byte 0

EverGrandeCity_HallOfFame_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_HallOfFame_EventScript_TurnPlayerNorth
	.2byte 0

EverGrandeCity_HallOfFame_EventScript_TurnPlayerNorth::
	hideobjectat LOCALID_STEVEN, MAP_EVER_GRANDE_CITY_HALL_OF_FAME
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_HallOfFame_OnFrame:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_HallOfFame_EventScript_EnterHallOfFame
	.2byte 0

EverGrandeCity_HallOfFame_EventScript_EnterHallOfFame::
	lockall
	applymovement LOCALID_WALLACE, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame1
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame1
	waitmovement 0
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox EverGrandeCity_HallOfFame_Text_HereWeHonorLeagueChampions, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLACE, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame2
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame2
	waitmovement 0
	delay 20

	msgbox EverGrandeCity_HallOfFame_Text_StevenWasHopingToSeeYou, MSGBOX_DEFAULT
	closemessage
	showobjectat LOCALID_STEVEN, MAP_EVER_GRANDE_CITY_HALL_OF_FAME
	applymovement LOCALID_STEVEN, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame2
	waitmovement 0
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_HallOfFame_Text_StevenPardonTheInterruption, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, EverGrandeCity_HallOfFame_EventScript_TurnDownSteven
	case YES, EverGrandeCity_HallOfFame_EventScript_BattleSteven
	case MULTI_B_PRESSED, EverGrandeCity_HallOfFame_EventScript_FinishHallOfFame
	end


EverGrandeCity_HallOfFame_EventScript_FinishHallOfFame::
	delay 20

	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox EverGrandeCity_HallOfFame_Text_LetsRecordYouAndYourPartnersNames, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD
	delay 40
	setvar VAR_TEMP_1, 1
	call EverGrandeCity_HallOfFame_EventScript_SetGameClearFlags
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_HallOfFame_EventScript_GameClearMale
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_HallOfFame_EventScript_GameClearFemale
	end

EverGrandeCity_HallOfFame_EventScript_GameClearMale::
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	fadescreenspeed FADE_TO_BLACK, 24
	special GameClear
	waitstate
	releaseall
	end

EverGrandeCity_HallOfFame_EventScript_GameClearFemale::
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
	fadescreenspeed FADE_TO_BLACK, 24
	special GameClear
	waitstate
	releaseall
	end


EverGrandeCity_HallOfFame_EventScript_TurnDownSteven::
	msgbox EverGrandeCity_HallOfFame_Text_StevenBattleTurnedDown, MSGBOX_DEFAULT
	goto EverGrandeCity_HallOfFame_EventScript_PostStevenBattle
	end
EverGrandeCity_HallOfFame_EventScript_BattleSteven::
	msgbox EverGrandeCity_HallOfFame_Text_StevenBattleAccepted, MSGBOX_DEFAULT
	special HealPlayerParty
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, EverGrandeCity_HallOfFame_EventScript_BattleMeteorFallsSteven
	trainerbattle_no_intro TRAINER_STEVEN_RS, EverGrandeCity_HallOfFame_Text_StevenDefeat
	goto EverGrandeCity_HallOfFame_EventScript_StevenGiveFossils
	end
EverGrandeCity_HallOfFame_EventScript_BattleMeteorFallsSteven::
	trainerbattle_no_intro TRAINER_STEVEN, EverGrandeCity_HallOfFame_Text_StevenDefeat
	goto EverGrandeCity_HallOfFame_EventScript_StevenGiveFossils
	end
EverGrandeCity_HallOfFame_EventScript_StevenGiveFossils::
	msgbox EverGrandeCity_HallOfFame_Text_StevenPostBattle, MSGBOX_DEFAULT
	goto_if_set FLAG_RECEIVED_KANTO_FOSSILS, EverGrandeCity_HallOfFame_EventScript_PostStevenBattle
	msgbox EverGrandeCity_HallOfFame_Text_StevenPresentWithGift, MSGBOX_DEFAULT
	giveitem ITEM_HELIX_FOSSIL
	giveitem ITEM_DOME_FOSSIL
	giveitem ITEM_OLD_AMBER
	setflag FLAG_RECEIVED_KANTO_FOSSILS
	goto EverGrandeCity_HallOfFame_EventScript_PostStevenBattle
	end
EverGrandeCity_HallOfFame_EventScript_PostStevenBattle::
	closemessage
	applymovement LOCALID_STEVEN, EverGrandeCity_HallOfFame_Movement_ExitHallOfFame
	waitmovement 0
	hideobjectat LOCALID_STEVEN, MAP_EVER_GRANDE_CITY_HALL_OF_FAME
	goto EverGrandeCity_HallOfFame_EventScript_FinishHallOfFame
	end


EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

EverGrandeCity_HallOfFame_Movement_ExitHallOfFame:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end


EverGrandeCity_HallOfFame_Text_HereWeHonorLeagueChampions:
	.string "WALLACE: This room…\p"
	.string "This is where we keep records of\n"
	.string "POKéMON that prevailed through\l"
	.string "harsh battles.\p"
	.string "It is here that the LEAGUE CHAMPIONS\n"
	.string "are honored.$"

EverGrandeCity_HallOfFame_Text_LetsRecordYouAndYourPartnersNames:
	.string "WALLACE: Come on, let's record your\n"
	.string "name as a TRAINER who triumphed over\l"
	.string "the POKéMON LEAGUE, and the names of\l"
	.string "the partners who battled with you.$"


EverGrandeCity_HallOfFame_Text_StevenWasHopingToSeeYou:
	.string "I was hoping I would get to see you\n"
	.string "make it here one day.$"

EverGrandeCity_HallOfFame_Text_StevenPardonTheInterruption:
	.string "STEVEN: Pardon the interruption.\p"
	.string "I know you've already faced a\n"
	.string "grand challenge here, but would you\l"
	.string "grace me with an extra battle?\p"
	.string "I will restore your tired\n"
	.string "POKéMON beforehand, of course.\p"
	.string "Are you prepared to take a risk and\n"
	.string "accept my challenge?$"

EverGrandeCity_HallOfFame_Text_StevenBattleTurnedDown:
	.string "STEVEN: I understand. Perhaps\n"
	.string "another time. Move forward and pursue\l"
	.string "your destiny, CHAMPION!$"

EverGrandeCity_HallOfFame_Text_StevenBattleAccepted:
	.string "STEVEN: Tell me… What have you seen\n"
	.string "on your journey with your POKéMON?\p"
	.string "I want you to come at me with all\n"
	.string "that you’ve learned.\p"
	.string "My POKéMON and I will respond in turn\n"
	.string "with all that we know!\p"
	.string "Let it begin!$"

EverGrandeCity_HallOfFame_Text_StevenDefeat:
	.string "Just as I have come to expect.\n"
	.string "{PLAYER}{KUN}, you are truly an\l"
	.string "excellent POKéMON TRAINER.\p"
	.string "Congratulations to you!$"

EverGrandeCity_HallOfFame_Text_StevenPostBattle:
	.string "STEVEN: The feelings you have for\n"
	.string "your POKéMON…\p"
	.string "And the way that your\n"
	.string "POKéMON gave their all in battle\l"
	.string "in response to those feelings…\p"
	.string "Those two together created a\n"
	.string "great power.\p"
	.string "You are rightfully\n"
	.string "the HOENN region’s CHAMPION!$"

EverGrandeCity_HallOfFame_Text_StevenPresentWithGift:
	.string "STEVEN: I present you with a gift\n"
	.string "to celebrate this occasion.$"

