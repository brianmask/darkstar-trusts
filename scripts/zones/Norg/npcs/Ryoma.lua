-----------------------------------
-- Area: Norg
-- NPC:  Ryoma
-- Start and Finish Quest: 20 in Pirate Years, I'll Take the Big Box, True Will
-- Involved in Quest: Ayame and Kaede
-- @pos -23 0 -9 252
-----------------------------------
package.loaded["scripts/zones/Norg/TextIDs"] = nil;
-----------------------------------

require("scripts/globals/settings");
require("scripts/globals/keyitems");
require("scripts/globals/shop");
require("scripts/globals/quests");
require("scripts/zones/Norg/TextIDs");

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)
end;

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)

	twentyInPirateYears = player:getQuestStatus(OUTLANDS,TWENTY_IN_PIRATE_YEARS);
	illTakeTheBigBox = player:getQuestStatus(OUTLANDS,I_LL_TAKE_THE_BIG_BOX);
	trueWill = player:getQuestStatus(OUTLANDS,TRUE_WILL);
	
	mLvl = player:getMainLvl();
	mJob = player:getMainJob();
	local wsnm = player:getVar("BLADE_KU");
    local mainlvl = player:getMainLvl();
    local skill = player:getSkillLevel(9);
	
	if (player:getQuestStatus(BASTOK,AYAME_AND_KAEDE) == QUEST_ACCEPTED) then
		if (player:getVar("AyameAndKaede_Event") == 3) then
			player:startEvent(0x005f); -- During Quest "Ayame and Kaede"
		else
			player:startEvent(0x005e);
		end
	elseif (twentyInPirateYears == QUEST_AVAILABLE and mJob == 13 and mLvl >= 40) then
		player:startEvent(0x0085); -- Start Quest "20 in Pirate Years"
	elseif (twentyInPirateYears == QUEST_ACCEPTED and player:hasKeyItem(TRICK_BOX)) then
		player:startEvent(0x0086); -- Finish Quest "20 in Pirate Years"
	elseif (twentyInPirateYears == QUEST_COMPLETED and illTakeTheBigBox == QUEST_AVAILABLE and mJob == 13 and mLvl >= 50 and player:needToZone() == false) then
		player:startEvent(0x0087); -- Start Quest "I'll Take the Big Box"
	elseif (illTakeTheBigBox == QUEST_COMPLETED and trueWill == QUEST_AVAILABLE and mJob == 13) then
		player:startEvent(0x0088); -- Start Quest "True Will"
	elseif (player:hasKeyItem(OLD_TRICK_BOX) and player:getVar("trueWillCS") == 0) then
		player:startEvent(0x0089);
	elseif (player:getVar("trueWillCS") == 1) then
		player:startEvent(0x008a);
	elseif (mainlvl >= 71 and skill >= 250 and player:getQuestStatus(OUTLANDS,BUGI_SODEN) ~= QUEST_ACCEPTED) then
	   player:PrintToPlayer("Ryoma : Blade: Ku eh?  Use it 100 times and then come see me afterwards.",0x0D);
	   player:setVar("BLADE_KU",100);
	   player:addQuest(OUTLANDS,BUGI_SODEN);
    elseif (wsnm == 1 and player:getQuestStatus(OUTLANDS,BUGI_SODEN) == QUEST_ACCEPTED) then
	   player:PrintToPlayer("Ryoma : Good Job.  Go to the Labrynth of Onzozo and fight the monster that dwells there.",0x0D);
	   player:addKeyItem(MAP_TO_THE_ANNALS_OF_TRUTH);
 	   player:messageSpecial(MAP_TO_THE_ANNALS_OF_TRUTH);
	   player:setVar("BLADE_KU_WIN",1);
    elseif (player:hasKeyItem(ANNALS_OF_TRUTH) and player:getVar("BLADE_KU_WIN") == 2) then
	   player:PrintToPlayer("Ryoma : You have done well.  Blade: Ku is now at full power!",0x0D);
	   player:delKeyItem(ANNALS_OF_TRUTH);
	   player:completeQuest(OUTLANDS,BUGI_SODEN);
	else
		player:startEvent(0x005e);
	end
	
end;

--0x00af  0x005e  0x005f  0x0085  0x0086  0x0087  0x0088  0x0089  0x008a  0x00b8  0x00b9  0x00ba  0x00bb  0x00bc  0x00bd

-----------------------------------
-- onEventUpdate
-----------------------------------

function onEventUpdate(player,csid,option)
--printf("CSID: %u",csid);
--printf("RESULT: %u",option);
end;

-----------------------------------
-- onEventFinish
-----------------------------------

function onEventFinish(player,csid,option)
--printf("CSID: %u",csid);
--printf("RESULT: %u",option);

	if (csid == 0x005f) then
		player:addKeyItem(SEALED_DAGGER);
		player:messageSpecial(KEYITEM_OBTAINED, SEALED_DAGGER);
		player:delKeyItem(STRANGELY_SHAPED_CORAL);
		player:setVar("AyameAndKaede_Event", 4);
	elseif (csid == 0x0085) then
		player:addQuest(OUTLANDS,TWENTY_IN_PIRATE_YEARS);
		player:setVar("twentyInPirateYearsCS",1);
	elseif (csid == 0x0086) then
		if (player:getFreeSlotsCount() <= 1) then 
			player:messageSpecial(ITEM_CANNOT_BE_OBTAINED,17771);
		else
			player:delKeyItem(TRICK_BOX);
			player:addItem(17771);
			player:addItem(17772);
			player:messageSpecial(ITEM_OBTAINED, 17771); -- Anju 
			player:messageSpecial(ITEM_OBTAINED, 17772); -- Zushio
			player:needToZone();
			player:setVar("twentyInPirateYearsCS",0);
			player:addFame(OUTLANDS,NORG_FAME*30);
			player:completeQuest(OUTLANDS,TWENTY_IN_PIRATE_YEARS);
		end
	elseif (csid == 0x0087) then
		player:addQuest(OUTLANDS,I_LL_TAKE_THE_BIG_BOX);
	elseif (csid == 0x0088) then
		player:addQuest(OUTLANDS,TRUE_WILL);
	elseif (csid == 0x0089) then
		player:setVar("trueWillCS",1);
	end
	
end;