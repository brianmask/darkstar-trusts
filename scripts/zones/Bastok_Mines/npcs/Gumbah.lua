-----------------------------------
-- Area: Bastok Mines
-- NPC: Gumbah
-- Finishes Quest: Blade of Darkness
-----------------------------------
package.loaded["scripts/zones/Bastok_Mines/TextIDs"] = nil;
-----------------------------------

require("scripts/globals/settings");
require("scripts/globals/keyitems");
require("scripts/globals/quests");
require("scripts/zones/Bastok_Mines/TextIDs");

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)
end; 

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)

	local bladeDarkness = player:getQuestStatus(BASTOK, BLADE_OF_DARKNESS);
	local wsnm = player:getVar("GROUND_STRIKE");
	local mainlvl = player:getMainLvl();
	local skill = player:getSkillLevel(4);


	if (player:getMainLvl() >= ADVANCED_JOB_LEVEL and  bladeDarkness == QUEST_AVAILABLE) then
		--DARK KNIGHT QUEST
		player:startEvent(0x0063);
	elseif (bladeDarkness == QUEST_COMPLETED and player:getQuestStatus(BASTOK,BLADE_OF_DEATH) == QUEST_AVAILABLE) then	
		player:startEvent(0x0082);
	elseif ((player:hasCompletedMission(BASTOK, ON_MY_WAY) == true) 
	or ((player:getCurrentMission(BASTOK) == ON_MY_WAY) and (player:getVar("MissionStatus") == 3)))
		and (player:getVar("[B7-2]Werei") == 0) then
		player:startEvent(0x00b1);
	elseif (mainlvl >= 71 and skill >= 250 and player:getQuestStatus(BASTOK,INHERITANCE) ~= QUEST_ACCEPTED) then
	   player:PrintToPlayer("Gumbah : Ground Strike?  Use it 100 times and then come see me afterwards.",0x0D);
	   player:setVar("GROUND_STRIKE",100);
	   player:addQuest(BASTOK,INHERITANCE);
	elseif (wsnm == 1 and player:getQuestStatus(BASTOK,INHERITANCE) == QUEST_ACCEPTED) then
	   player:PrintToPlayer("Gumbah : Good Job.  Travel to Western Altepa Desert and fight the monster that dwells there.",0x0D);
	   player:addKeyItem(MAP_TO_THE_ANNALS_OF_TRUTH);
 	   player:messageSpecial(MAP_TO_THE_ANNALS_OF_TRUTH);
	   player:setVar("GROUND_STRIKE_WIN",1);
	elseif (player:hasKeyItem(ANNALS_OF_TRUTH) and player:getVar("GROUND_STRIKE_WIN") == 2) then
	   player:PrintToPlayer("Gumbah : You have done well.  Ground Strike is now at full power!",0x0D);
	   player:delKeyItem(ANNALS_OF_TRUTH);
	   player:completeQuest(BASTOK,INHERITANCE);
	else 
		--DEFAULT 
		player:startEvent(0x0034);
	end
end;

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

	if (csid == 0x0063) then
		player:addQuest(BASTOK, BLADE_OF_DARKNESS);
	elseif (csid == 0x0082) then
		player:addQuest(BASTOK, BLADE_OF_DEATH);
		player:addKeyItem(LETTER_FROM_ZEID);
		player:messageSpecial(KEYITEM_OBTAINED,LETTER_FROM_ZEID);
	elseif (csid == 0x00b1) then
		player:setVar("[B7-2]Werei", 1);
	end
end;