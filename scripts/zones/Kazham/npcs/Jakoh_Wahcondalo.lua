-----------------------------------
-- Area: Kazham
-- NPC:  Jakoh Wahcondalo
-- @pos 101 -16 -115 250
-----------------------------------
package.loaded["scripts/zones/Kazham/TextIDs"] = nil;
-----------------------------------

require("scripts/globals/missions");
require("scripts/zones/Kazham/TextIDs");
require("scripts/globals/quests");

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)
end;

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)

local wsnm = player:getVar("EVISCERATION");
local mainlvl = player:getMainLvl();
local skill = player:getSkillLevel(2);

player:PrintToPlayer(mainlvl);
	
	if (player:getCurrentMission(ZILART) == KAZAMS_CHIEFTAINESS) then
		player:startEvent(0x0072);
	elseif (player:getCurrentMission(ZILART) == THE_TEMPLE_OF_UGGALEPIH) then
		player:startEvent(0x0073);
	elseif (player:getCurrentMission(WINDURST) == AWAKENING_OF_THE_GODS and player:getVar("MissionStatus") == 2) then
		player:startEvent(0x0109);
	elseif (mainlvl >= 71 and skill >= 230 and player:getQuestStatus(OUTLANDS,CLOAK_AND_DAGGER) ~= QUEST_ACCEPTED) then
	   player:PrintToPlayer("Jakoh Wahcondalo : Evisceration eh?  Use it 100 times and then come see me afterwards.",0x0D);
	   player:setVar("EVISCERATION",100);
	   player:addQuest(OUTLANDS,CLOAK_AND_DAGGER);
	elseif (wsnm == 1 and player:getQuestStatus(OUTLANDS,CLOAK_AND_DAGGER) == QUEST_ACCEPTED) then
	   player:PrintToPlayer("Jakoh Wahcondalo : Good Job.  Take this to Gustav Tunnel and kill the monster there.",0x0D);
	   player:addKeyItem(MAP_TO_THE_ANNALS_OF_TRUTH);
 	   player:messageSpecial(MAP_TO_THE_ANNALS_OF_TRUTH);
	   player:setVar("EVISCERATION_WIN",1);
	elseif (player:hasKeyItem(ANNALS_OF_TRUTH) and player:getVar("EVISCERATION_WIN") == 2) then
	   player:PrintToPlayer("Jakoh Wahcondalo : You have done well.  Evisceration is now at full power!",0x0D);
	   player:delKeyItem(ANNALS_OF_TRUTH);
	   player:completeQuest(OUTLANDS,CLOAK_AND_DAGGER);
	else
		player:startEvent(0x0071);
	end
	
end;

-----------------------------------
-- onEventUpdate
-----------------------------------

function onEventUpdate(player,csid,option)
-- printf("CSID: %u",csid);
-- printf("RESULT: %u",option);
end;

-----------------------------------
-- onEventFinish
-----------------------------------

function onEventFinish(player,csid,option)
-- printf("CSID: %u",csid);
-- printf("RESULT: %u",option);
	
	if (csid == 0x0072) then
		player:addKeyItem(SACRIFICIAL_CHAMBER_KEY);
		player:messageSpecial(KEYITEM_OBTAINED,SACRIFICIAL_CHAMBER_KEY);
		player:completeMission(ZILART,KAZAMS_CHIEFTAINESS);
		player:addMission(ZILART,THE_TEMPLE_OF_UGGALEPIH);
	elseif (csid == 0x0109) then
		player:setVar("MissionStatus",3);
	end
	
end;
