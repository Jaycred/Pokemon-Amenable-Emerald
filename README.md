This is a romhack of Pokémon Emerald built off of [pokeemerald](https://github.com/pret/pokeemerald).

# Pokemon Amenable Emerald

This is my first romhack, and my goal with it was to build on the Pokemon Emerald experience while largely preserving the vanilla game’s campaign. It repurposes unused/underutilized features, inserts a few new features and content I wanted to see in the game, and adds some quality of life improvements to enhance the gameplay.
## General QoL/UI Improvements

#### Text Boxes

* You can hold A/B on most text to auto-click through it.
* Default text speed is Fast.
* Slow and Medium text speeds are faster than before, but still slower than Fast.
#### Movement

* Once you have the running shoes, you can press R to toggle auto-running.
* You can run indoors and on tiles you couldn’t before such as Fortree and Pacifidlog bridges.
#### Battles

* Trainer/Pokemon sprites slide in faster at the start.
* Less delay between battle messages and animations, makes turns much snappier.
* HP bars drop a bit faster when taking damage.
* Low HP beeping fades out over a couple seconds.
#### Menus

* A/B presses are no longer required to advance most of the PC text boxes, and a couple excessive text boxes were removed. Nurse Joy gets a similar treatment with her dialogue.
* The cursor defaults to ‘Use’ instead of ‘Check Tag’ when selecting a berry in the bag.
#### Other

* Trainer and gym leader rematches are available far more frequently. Keep in mind that rematches don’t happen until you have the fifth gym badge.
* Talk to the leftmost guy in the Contest Hall lobby to reset a Pokemon’s contest stats and sheen.
* You start the game with a random Walda wallpaper unlocked.
## “STAB Split”

Physical/special split is great for the later generations, but this is an alternate idea I wanted to try that mixes up the original battle system just enough to fix Pokemon that were stunted by their typing not synergizing with their stats. You’re welcome, Flareon. And Gengar.
* When a Pokemon gets Same-Type Attack Bonus, the move is converted to physical or special to use the Pokemon’s higher attack stat. The higher attack stat is determined after boosts from abilities and items but before stat changes and the Attack drop from burn.
* For balance, Overheat and Psycho Boost lower whichever attack stat they use, and Superpower likewise lowers attack and defense stats adaptively.
* I haven’t tested this with Counter/Mirror Coat, but I believe they still function based on the type of the move, regardless of whether it was converted.
## Battle Palace Format
I think most would agree that the Battle Palace format is boring at best. You’re at the mercy of random move selection, even if you can set your team up for better odds of getting the outcome you want. I reworked it into something that’s maybe not as flavorful but mechanically more engaging.
* You and the opponent get to choose moves normally, but all moves start at 1 PP.
* In the vanilla format, the first time a Pokemon falls below 50% HP, a special message is displayed and its decision-making changes. I’ve kept the message, but now when it happens the Pokemon gets a second wind and recovers 1 PP in each of its moves.
* These changes are also applied to the Verdanturf Battle Tent.
* The text explanations of the old format have been adjusted to match the new format.
## Items

#### TMs and Tutor Moves

* TMs are infinitely reusable and have the same importance as HMs (can’t be given/sold/stored in PC). Text that describes them as single-use has been adjusted.
* You can only buy one copy of a buyable TM at a time, and you can’t buy a TM once you already have it. This is mainly done to prevent wasting money. There are some TMs that are obtainable in multiple places (like Thunderbolt and Ice Beam), but having multiple copies won’t cause problems.
* Rest, Earthquake, and Focus Punch TMs in the Pickup table are replaced by PP Max. You only need one copy of each, and these TMs are already available in the overworld.
* The Return/Frustration guy no longer has his weekly event where he evaluates your Pokemon’s happiness and gives you one of the TMs. He instead gives you both TMs at once and that’s it.
* The move tutors spread around the overworld (Rollout, Metronome, Mimic, etc) are infinitely reusable and no longer say that they’re single-use.
#### HMs and Field Moves

* HM slaves are no more! HM field moves are usable without teaching them to party members as long as you have the badge for it (and the HM in Dive’s case, to avoid a small sequence break). You can still teach and use them with your Pokemon, of course. You can also use Secret Power right from the beginning of the game.
* However, the animation that shows off your Pokemon before using a field move is gone. As cool as it was, it slowed down field moves quite a bit. Perhaps I could make a toggle for it in a future update.
* Flash and Fly require use in-menu, and Cut has its grass-cutting feature that requires you to use it in-menu, so when you get their HMs you also get new Key Items to use these field moves: the Weavile Figure, Luminous Orb, and Warp Scarf. Warp Scarf is a bit awkward with a few screen transitions before initiating the Fly menu, but it’s functional for now.
* HM moves can be replaced when learning a move.
* Cut always cuts a 2-tile radius of grass, as it normally does when the Pokemon using it has Hyper Cutter.
#### Link Cable

* Can be bought from the Secret Power shop in Slateport City that previously sold TMs.
* Acts as an evolution stone for trade evolution Pokemon such as Kadabra, Graveler, Haunter, and Machoke. Evolves Feebas too.
* Items used in trade evolutions (King’s Rock, Metal Coat, Up-Grade, etc) can similarly be used from the bag to evolve the Pokemon they work with.
#### Lucky Charm

* Professor Cozmo gives you this new Key Item instead of the Return TM when you give him the Meteorite.
* Can be toggled on/off. While on, a newly generated Pokemon will have its personality value rerolled up to 3 times if it isn’t shiny, so the odds go from 1/8192 to about 1/2048 (you could technically reroll the same personality, so it’s a tad lower than that). Also multiplies the odds of contracting Pokerus by 12, changing it from 1/21845 to 1/1820.
#### Max Repel

* Buffed to 350 steps so it's actually cost-effective (using ¥ for Pokedollars, Repel is ¥3.5/step, Super Repel is ¥2.5/step, and new Max Repel is ¥2.0/step while old was ¥2.8/step).
#### Exp. Share and Lucky Egg

* Exp. Share gives 50% more experience, additive. This effectively makes it a Lucky Egg when equipped to the main battler, and it causes a benched Pokemon to get 100% of the experience. I haven’t tested this thoroughly with experience split across many party members and/or multiple Exp. Shares.
* Lucky Egg buffed to double exp. point gain to compensate.
#### Bikes

* Rydel gives you both bikes and doesn’t try to make you switch.
#### Enigma Berry

* The Enigma Berry is obtainable from Norman after defeating him. This was an unused or obscure event already in the game but normally activated by mystery gift. I haven’t added any functionality to the berry, it’s just there if you want it.
#### Regi Dolls
* Effectively unused/unobtainable outside a Japan-exclusive event, these are now purchasable at Mauville Casino for 2500 coins each.
#### Minor Shop Changes

* Luxury Ball available in Sootopolis Pokemart.
* Poke Doll available from Secret Power Slateport market, alongside the Link Cable.
* Glass blower requires much less soot from the Soot Sack to craft his wares.
## Pokemon

#### Encounters

Unless I’ve missed some, all 386 Pokemon programmed into the game are now obtainable at least once. A lot of the additions are in postgame areas, listed in the Postgame section. Changes to the pre-Elite Four areas are listed here.
* Surskit:
  - Route 102 and Route 114 grass 1%
  - Route 117 grass 4%
  - Route 120 grass 5%
* Roselia:
  - Route 117 grass 10%
* Meditite:
  - Mt. Pyre exterior+summit and Victory Road B1F 10%
* Medicham:
  - Victory Road B1F+B2F 5%
* Lunatone:
  - 10% in all Meteor Falls rooms on land
* Zangoose:
  - Route 114 grass 5%
* Safari Zone has all areas open before postgame. Step limit increased from 500 to 3000 and Safari Ball catch rate doubled.
  - Northwest area:
    - Scyther 5% replacing Dodrio
    - Bellsprout 5%
    - Mantine surfing 10% replacing Golduck
  - Northeast area:
    - Tauros 5% replacing Hoothoot (Hoothoot still available in Southeast)
  - South area:
    - Bellsprout 20%
    - Kangaskhan 5% replacing Gloom
  - Southwest area:
    - Bellsprout 20%
    - Lickitung 5% replacing Gloom
    - Qwilfish surfing 10%
  - North area:
    - Bellsprout 10%
    - Farfetch’d 5%
* Shoal Cave ice room gets more exotic ice types.
  - Delibird, Swinub: 30%
  - Sneasel: 20%
  - Snorunt: 10%
  - Lapras, Jynx: 5%
* Mirage Island is always active and contains some rare Pokemon. Encounters are randomly level 5-50.
  - Cleffa, Hoppip: 30%
  - Tyrogue, Cubone: 10%
  - Elekid, Magby: 5%
  - Togepi, Eevee: 4%
  - Dratini, Larvitar: 1%
#### Wild Hold Items

* Rare chance to hold an item increased from 5% to 10%
* When the lead party member has Compound Eyes, rare item chance is increased from 20% to 30% and common items are 70% instead of their base 50% (you’re guaranteed to get a common item if not rare)
* Shuckle: guaranteed Berry Juice
* Mew and Celebi: guaranteed Starf Berry and Lansat Berry, respectively
* Mewtwo: guaranteed Master Ball
* Lugia: guaranteed White Herb
* Clamperl: rare chance for Deep Sea Tooth, Blue Shard changed to common
* Relicanth: Green Shard changed to common
* Corsola: Red Shard changed to common
* Chinchou and Lanturn: rare chance for Deep Sea Scale, Yellow Shard changed to common
* Poliwag, Onix/Scyther, Porygon: rare chance to hold King’s Rock/Metal Coat/Up-Grade, respectively
* Chansey: common chance for Lucky Punch
#### Learnsets

I may have missed some, but every applicable Pokemon should have additional moves that were exclusive to their FireRed/LeafGreen learnsets.
* Some notable ones include Crawdaunt getting Crunch, Nidoqueen getting Superpower, Nidoking and Goldeen/Seaking getting Megahorn, and Kirlia/Gardevoir getting Magical Leaf.
* Frenzy Plant, Hydro Cannon, and Blast Burn were originally exclusive to a FireRed/LeafGreen tutor. I added them to the beginning of the learnsets of all fully evolved starters, so you can visit the move relearner to learn them.
* I also added moves from XD: Gale of Darkness. The exclusive moves you’d get for purifying a shadow Pokemon in that game are given to that Pokemon and its evolutionary line (for instance, Poochyena and Mightyena get Heal Bell).
  - Lugia gets Psycho Boost and Feather Dance from this, so I decided to give Ho-Oh Feather Dance and Sky Attack to compensate.
## Campaign

As mentioned, I wanted to maintain most of the campaign’s content, but there were a couple disappointing parts that I think would be more interesting with small tweaks.
#### Rival

* The final rival battle in the vanilla game had their starter at level 34 and therefore not fully evolved. Now their starter is level 36 and you get to see its final evolution.
#### Steven

* You get an optional battle with Steven at the end of the Pokemon League, just before you complete the campaign in the Hall of Fame. He’ll heal you beforehand, but keep in mind you’re still taking the risk of whiting out if you accept his challenge.
* E4 Steven initially uses his team from Ruby/Sapphire, but after you defeat Meteor Falls Steven he’ll use the Meteor Falls team.
* The first time you beat E4 Steven, he’ll give you each of the Kanto fossils. The Helix/Dome Fossils and Old Amber previously had no function in this game, but they’re now revivable at the Devon building.
#### Team Magma/Aqua

* A few Team Magma/Aqua grunts have more diversity in their parties in place of so many Zubat/Poochyena. Magma got some Vulpix and Aqua got some Wailmer. Also threw in a couple instances of Torchic/Mudkip and their evolutions, notably featured in Tabitha and Shelly’s teams.
## Postgame

#### Altering Cave

I made use of the largely unused rotating encounter table mechanic to stuff a bunch of previously unobtainable Pokemon in here. Each time you enter, the encounter table rotates. Encounters range from level 5-50 except for the legendaries, which are always level 50. Unown’s form is randomly selected from the full set of letters.
* Table 1:
  - Bulbasaur
  - Chikorita
  - Treecko
  - Exeggcute
  - Tangela
  - Ekans
  - Nidoran♀
  - Nidoran♂
  - Celebi
  - Unown
* Table 2:
  - Squirtle
  - Totodile
  - Mudkip
  - Poliwag
  - Slowpoke
  - Krabby
  - Seel
  - Shellder
  - Suicune
  - Articuno
  - Unown
* Table 3:
  - Charmander
  - Cyndaquil
  - Torchic
  - Growlithe
  - Ponyta
  - Gastly
  - Misdreavus
  - Onix
  - Entei
  - Moltres
  - Unown
* Table 4:
  - Caterpie
  - Weedle
  - Paras
  - Venonat
  - Yanma
  - Drowzee
  - Mr. Mime
  - Porygon
  - Jirachi
  - Mewtwo
  - Unown
* Table 5:
  - Pidgey
  - Spearow
  - Rattata
  - Sentret
  - Murkrow
  - Mankey
  - Dunsparce
  - Diglett
  - Raikou
  - Zapdos
  - Unown
* All of these Pokemon, unless they have a particular hold item I've added (e.g. Onix with Metal Coat and Celebi with Lansat Berry) have a rare chance of holding a Liechi/Ganlon/Petaya/Apicot/Salac Berry, typically based on the Pokemon’s color scheme.
* The default battle music here is FireRed/LeafGreen’s wild battle music. Encountering a legendary causes a blur transition and different battle music, including the unused legendary beast music for Suicune/Entei/Raikou.
#### Desert Underpass

* Encounter table changed: Ditto and Loudred are 40%, Snorlax and Chansey are 10%.
#### Battle Frontier

* Made BP rewards cheaper, especially the secret base items.
* Removed Leftovers, Quick Claw, King’s Rock, and Focus Band from rewards and replaced them with Max Revive, Rare Candy, PP Up, and PP Max.
* Multiplied BP gain by 4.

* Just a small change for fun; the Smeargle in Artisan Cave now range from level 5-100, weighted heavily around 50.
#### Events

* Some of the event tickets are obtainable before beating the game, but game completion is required to access the Lilycove ferry and use them.
  - Aurora Ticket: given by the sailor at the Mossdeep Space Center who normally gives you a Sun Stone.
  - Mystic Ticket: given by Captain Stern in exchange for the Scanner instead of Deep Sea Scale/Tooth.
  - Old Sea Map: found on Mirage Island (which is always active now).
  - Eon Ticket: given by Meteor Falls Steven.
#### Other

* The scrapped E-Reader house in Sootopolis is refurbished and has a ‘mysterious’ trainer you can battle each time you beat the game.
* Clear-out sale on the roof of Lilycove Dept. Store is always active in postgame.
* I haven’t tested this, but the random outbreak events are supposed to contain only level 70 Blissey that appear in Victory Road, Altering Cave, or Desert Underpass.
## Competitive

Gen 3 isn't the most interesting competitively, but I may as well destroy the competitive grind and make it reasonably accessible.

#### Nature Manipulation

* You can change a Pokemon’s nickname directly in the party menu, no NPC required.
* The Name Rater is repurposed into the Nature Rater, who can change your Pokemon’s nature for a Heart Scale. Competitive natures only (non-neutral natures that aren’t Gentle or Lax). Also performs stat recalculation afterward. You don’t get charged for choosing the same nature the Pokemon currently has.
#### IV Manipulation

* The IV checker NPC in the Battle Frontier will set a Pokemon’s IVs to 31 for a Heart Scale.
#### EV Training

* EV max value per stat is now capped at 252 instead of 255, like in modern gens to avoid wasting points.
* Vitamins aren’t capped; you can use them to bring a Pokemon from 0 to 252.
* Vitamins are more affordable at 3800 Pokedollars.
* The Energy Guru in the Slateport City market sells EV-reducing berries instead of vitamins; they’re 200 Pokedollars each.
* Macho Brace and Pokerus multiply EV gain in battle by 5 instead of 2.

# Credits
* The [pokeemerald decomp project](https://github.com/pret/pokeemerald) and its [wiki tutorials](https://github.com/pret/pokeemerald/wiki/Tutorials) made by the community, such as [auto-run](https://www.pokecommunity.com/showpost.php?p=10161076&postcount=72), [nickname from party menu](https://github.com/shinny456/pokeemerald/commit/c92e5861e3ba85abaf53af81aa0bb70acae505af), [quick Nurse Joy heal](https://github.com/pret/pokeemerald/wiki/Speedy-Nurse-Joy)
* The [YouTube video](https://www.youtube.com/watch?v=pA_4emRVq3w) that incidentally pointed me in this direction.

# pokeemerald README stuff

To set up the repository, see [INSTALL.md](https://github.com/pret/pokeemerald/blob/master/INSTALL.md).


## See also

Other disassembly and/or decompilation projects:
* [**Pokémon Red and Blue**](https://github.com/pret/pokered)
* [**Pokémon Gold and Silver (Space World '97 demo)**](https://github.com/pret/pokegold-spaceworld)
* [**Pokémon Yellow**](https://github.com/pret/pokeyellow)
* [**Pokémon Trading Card Game**](https://github.com/pret/poketcg)
* [**Pokémon Pinball**](https://github.com/pret/pokepinball)
* [**Pokémon Stadium**](https://github.com/pret/pokestadium)
* [**Pokémon Gold and Silver**](https://github.com/pret/pokegold)
* [**Pokémon Crystal**](https://github.com/pret/pokecrystal)
* [**Pokémon Ruby and Sapphire**](https://github.com/pret/pokeruby)
* [**Pokémon Pinball: Ruby & Sapphire**](https://github.com/pret/pokepinballrs)
* [**Pokémon FireRed and LeafGreen**](https://github.com/pret/pokefirered)
* [**Pokémon Mystery Dungeon: Red Rescue Team**](https://github.com/pret/pmd-red)


## Contacts

You can find us on [Discord](https://discord.gg/d5dubZ3) and [IRC](https://web.libera.chat/?#pret).