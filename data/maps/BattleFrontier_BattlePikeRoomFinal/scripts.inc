.set LOCALID_ATTENDANT, 1

BattleFrontier_BattlePikeRoomFinal_MapScripts::
	.byte 0

BattleFrontier_BattlePikeRoomFinal_OnFrame:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePikeRoomFinal_EventScript_EnterRoom
	.2byte 0

BattleFrontier_BattlePikeRoomFinal_EventScript_EnterRoom::
	delay 16
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePikeRoomFinal_Movement_AttendantApproachPlayer
	waitmovement 0
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
	lockall
	msgbox BattleFrontier_BattlePikeRoomFinal_Text_CongratsThisWayPlease, MSGBOX_DEFAULT
	closemessage
	releaseall
	warp MAP_BATTLE_FRONTIER_BATTLE_PIKE_LOBBY, 5, 6
	waitstate
	end

BattleFrontier_BattlePikeRoomFinal_Movement_AttendantApproachPlayer:
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeRoomFinal_OnWarp:
	map_script_2 VAR_TEMP_4, 0, BattleFrontier_BattlePikeRoomFinal_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePikeRoomFinal_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_4, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePikeRoomFinal_EventScript_Lucy::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeRoomFinal_Text_CongratsThisWayPlease, MSGBOX_DEFAULT
	closemessage
	release
	end

BattleFrontier_BattlePikeRoomFinal_Text_CongratsThisWayPlease:
	.string "… … … … … …\p"
	.string "Looks like my luck finally ran out…\n"
	.string "Humph…\p"
	.string "I hope the others were more fortunate…$"

