.set LOCALID_FOSSIL, 1

DesertUnderpass_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DesertUnderpass_OnTransition
	.byte 0

DesertUnderpass_OnTransition:
	setflag FLAG_LANDMARK_DESERT_UNDERPASS
	end

DesertUnderpass_EventScript_Fossil::
	lock
	faceplayer
	goto_if_set FLAG_CHOSE_ROOT_FOSSIL, DesertUnderpass_EventScript_GiveClawFossil
	goto_if_set FLAG_CHOSE_CLAW_FOSSIL, DesertUnderpass_EventScript_GiveRootFossil
	release
	end

DesertUnderpass_EventScript_GiveClawFossil::
	giveitem ITEM_CLAW_FOSSIL
	removeobject LOCALID_FOSSIL
	release
	end

DesertUnderpass_EventScript_GiveRootFossil::
	giveitem ITEM_ROOT_FOSSIL
	removeobject LOCALID_FOSSIL
	release
	end

DesertUnderpass_EventScript_SorryNothing::
	lock
	faceplayer
	playse SE_PIKE_CURTAIN_OPEN
	msgbox DesertUnderpass_Text_SorryNothing, MSGBOX_DEFAULT
	closemessage
	release
	end

DesertUnderpass_Text_SorryNothing::
	.string "SORRY NOTHING$"

@ Unused
DesertUnderpass_Text_FoundClawFossil::
	.string "{PLAYER} found the CLAW FOSSIL.$"

