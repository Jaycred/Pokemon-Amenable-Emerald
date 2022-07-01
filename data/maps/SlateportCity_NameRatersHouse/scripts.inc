SlateportCity_NameRatersHouse_MapScripts::
	.byte 0

SlateportCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox SlateportCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, SlateportCity_NameRatersHouse_EventScript_CantRateEgg

	special BufferMonNature

	msgbox SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox SlateportCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_ChangeNickname::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_NameRatersHouse_EventScript_ComeBackWithHeartScale

	copyvar VAR_TEMP_0, VAR_0x8004 @Store Pokemon to be changed

	message SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe
	waitmessage

	setvar VAR_TEMP_E, 0
	setvar VAR_0x8004, SCROLL_MULTI_NATURE_RATER
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_D, VAR_RESULT
	switch VAR_RESULT
	case 0, SlateportCity_NameRatersHouse_EventScript_ChooseLonely
	case 1, SlateportCity_NameRatersHouse_EventScript_ChooseAdamant
	case 2, SlateportCity_NameRatersHouse_EventScript_ChooseNaughty
	case 3, SlateportCity_NameRatersHouse_EventScript_ChooseBrave
	case 4, SlateportCity_NameRatersHouse_EventScript_ChooseBold
	case 5, SlateportCity_NameRatersHouse_EventScript_ChooseImpish
	case 6, SlateportCity_NameRatersHouse_EventScript_ChooseRelaxed
	case 7, SlateportCity_NameRatersHouse_EventScript_ChooseModest
	case 8, SlateportCity_NameRatersHouse_EventScript_ChooseMild
	case 9, SlateportCity_NameRatersHouse_EventScript_ChooseRash
	case 10, SlateportCity_NameRatersHouse_EventScript_ChooseQuiet
	case 11, SlateportCity_NameRatersHouse_EventScript_ChooseCalm
	case 12, SlateportCity_NameRatersHouse_EventScript_ChooseCareful
	case 13, SlateportCity_NameRatersHouse_EventScript_ChooseSassy
	case 14, SlateportCity_NameRatersHouse_EventScript_ChooseTimid
	case 15, SlateportCity_NameRatersHouse_EventScript_ChooseHasty
	case 16, SlateportCity_NameRatersHouse_EventScript_ChooseJolly
	case 17, SlateportCity_NameRatersHouse_EventScript_ChooseNaive
	case 18, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	case MULTI_B_PRESSED, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate


	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_NewNameDifferent

	goto SlateportCity_NameRatersHouse_EventScript_DeclineNatureChange
	end

SlateportCity_NameRatersHouse_EventScript_ChooseLonely::
	setvar VAR_0x8004, NATURE_LONELY
	goto SlateportCity_NameRatersHouse_EventScript_SetNature
	end
SlateportCity_NameRatersHouse_EventScript_ChooseAdamant::
	setvar VAR_0x8004, NATURE_ADAMANT
	goto SlateportCity_NameRatersHouse_EventScript_SetNature
	end
SlateportCity_NameRatersHouse_EventScript_ChooseNaughty::
	setvar VAR_0x8004, NATURE_NAUGHTY
	goto SlateportCity_NameRatersHouse_EventScript_SetNature
	end
SlateportCity_NameRatersHouse_EventScript_ChooseBrave::
	setvar VAR_0x8004, NATURE_BRAVE
	goto SlateportCity_NameRatersHouse_EventScript_SetNature
	end
SlateportCity_NameRatersHouse_EventScript_ChooseBold::
	setvar VAR_0x8004, NATURE_BOLD
	goto SlateportCity_NameRatersHouse_EventScript_SetNature
	end
SlateportCity_NameRatersHouse_EventScript_ChooseImpish::
	setvar VAR_0x8004, NATURE_IMPISH
	goto SlateportCity_NameRatersHouse_EventScript_SetNature
	end
SlateportCity_NameRatersHouse_EventScript_ChooseRelaxed::
	setvar VAR_0x8004, NATURE_RELAXED
	goto SlateportCity_NameRatersHouse_EventScript_SetNature
	end
SlateportCity_NameRatersHouse_EventScript_ChooseModest::
	setvar VAR_0x8004, NATURE_MODEST
	goto SlateportCity_NameRatersHouse_EventScript_SetNature
	end
SlateportCity_NameRatersHouse_EventScript_ChooseMild::
	setvar VAR_0x8004, NATURE_MILD
	goto SlateportCity_NameRatersHouse_EventScript_SetNature
	end
SlateportCity_NameRatersHouse_EventScript_ChooseRash::
	setvar VAR_0x8004, NATURE_RASH
	goto SlateportCity_NameRatersHouse_EventScript_SetNature
	end
SlateportCity_NameRatersHouse_EventScript_ChooseQuiet::
	setvar VAR_0x8004, NATURE_QUIET
	goto SlateportCity_NameRatersHouse_EventScript_SetNature
	end
SlateportCity_NameRatersHouse_EventScript_ChooseCalm::
	setvar VAR_0x8004, NATURE_CALM
	goto SlateportCity_NameRatersHouse_EventScript_SetNature
	end
SlateportCity_NameRatersHouse_EventScript_ChooseCareful::
	setvar VAR_0x8004, NATURE_CAREFUL
	goto SlateportCity_NameRatersHouse_EventScript_SetNature
	end
SlateportCity_NameRatersHouse_EventScript_ChooseSassy::
	setvar VAR_0x8004, NATURE_SASSY
	goto SlateportCity_NameRatersHouse_EventScript_SetNature
	end
SlateportCity_NameRatersHouse_EventScript_ChooseTimid::
	setvar VAR_0x8004, NATURE_TIMID
	goto SlateportCity_NameRatersHouse_EventScript_SetNature
	end
SlateportCity_NameRatersHouse_EventScript_ChooseHasty::
	setvar VAR_0x8004, NATURE_HASTY
	goto SlateportCity_NameRatersHouse_EventScript_SetNature
	end
SlateportCity_NameRatersHouse_EventScript_ChooseJolly::
	setvar VAR_0x8004, NATURE_JOLLY
	goto SlateportCity_NameRatersHouse_EventScript_SetNature
	end
SlateportCity_NameRatersHouse_EventScript_ChooseNaive::
	setvar VAR_0x8004, NATURE_NAIVE
	goto SlateportCity_NameRatersHouse_EventScript_SetNature
	end

SlateportCity_NameRatersHouse_EventScript_SetNature::
	special SetMonNature
	goto_if_eq VAR_TEMP_1, 1, SlateportCity_NameRatersHouse_EventScript_DeclineNatureChange
	goto SlateportCity_NameRatersHouse_EventScript_NewNameDifferent
	end


SlateportCity_NameRatersHouse_EventScript_NewNameDifferent::
	copyvar VAR_0x8004, VAR_TEMP_0 @Set selected Pokemon back into appropriate var
	special BufferMonNature
	msgbox SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	removeitem ITEM_HEART_SCALE
	msgbox SlateportCity_NameRatersHouse_Text_HandedOverHeartScale, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_DeclineNatureChange::
	copyvar VAR_0x8004, VAR_TEMP_0 @Set selected Pokemon back into appropriate var
	special BufferMonNature
	msgbox SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_ComeBackWithHeartScale::
	msgbox SlateportCity_NameRatersHouse_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "Hi, hi! I'm the NATURE RATER!\n"
	.string "I'm the fortune-teller of natures!\p"
	.string "I shall be pleased to rate your\n"
	.string "POKéMON's nature.$"

SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "Which POKéMON's nature should\n"
	.string "I critique?$"

SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "Hmmm… {STR_VAR_1}, is it? That is\n"
	.string "quite a fine nature it has.\p"
	.string "But! What say you, if I were to\n"
	.string "suggest a slightly better nature?\l"
	.string "I shall do it for a HEART SCALE.$"

SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "Ah, good. Then, what shall the new\n"
	.string "nature be?$"

SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "Done! From now on, this POKéMON\n"
	.string "shall be {STR_VAR_1}!\p"
	.string "It is a better nature than before!\n"
	.string "How fortunate for you!$"

SlateportCity_NameRatersHouse_Text_ComeBackWithHeartScale:
	.string "It seems you do not have a\n"
	.string "HEART SCALE. Do come visit again\l"
	.string "once you have one.$"

SlateportCity_NameRatersHouse_Text_DoVisitAgain:
	.string "I see.\n"
	.string "Do come visit again.$"

SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "Done! From now on, this POKéMON\n"
	.string "shall be {STR_VAR_1}!\p"
	.string "It looks no different from before,\n"
	.string "and yet, this is vastly superior!\p"
	.string "How fortunate for you!\n"
	.string "I require no payment for this.$"

SlateportCity_NameRatersHouse_Text_MagnificentName:
	.string "Hmmm… {STR_VAR_1} it is!\p"
	.string "This is a magnificent nature!\n"
	.string "It is impeccably beyond reproach!\p"
	.string "You'll do well to cherish your\n"
	.string "POKéMON now and beyond.$"

SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "Now, now.\n"
	.string "That is merely an EGG!$"

SlateportCity_NameRatersHouse_Text_HandedOverHeartScale:
	.string "{PLAYER} handed over one HEART SCALE\n"
	.string "in exchange.$"

