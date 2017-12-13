-----------------------------------
-- Area: Metalworks
-- NPC:  Iron Eater
-- Involved in Missions
-- @pos 92.936 -19.532 1.814 237
-----------------------------------
package.loaded["scripts/zones/Metalworks/TextIDs"] = nil;
-----------------------------------

require("scripts/globals/missions");
require("scripts/zones/Metalworks/TextIDs");
require("scripts/globals/titles");
require("scripts/globals/settings");

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)
end;

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)

    local currentMission = player:getCurrentMission(BASTOK);
    local missionStatus = player:getVar("MissionStatus");
	local wsnm = player:getVar("STEEL_CYCLONE");
    local mainlvl = player:getMainLvl();
    local skill = player:getSkillLevel(6);

    if (currentMission == THE_FOUR_MUSKETEERS and missionStatus == 0) then -- Four Musketeers
        player:startEvent(0x02cb);
    elseif (currentMission == WHERE_TWO_PATHS_CONVERGE and player:getVar("BASTOK92") == 0) then 
        player:startEvent(0x030c);
    elseif (currentMission == WHERE_TWO_PATHS_CONVERGE and player:getVar("BASTOK92") == 2) then 
        player:startEvent(0x030e);
    elseif (player:getVar("Flagbastok") == 1) then
        if (player:getFreeSlotsCount() == 0) then 
            player:messageSpecial(ITEM_CANNOT_BE_OBTAINED,182);
        else
            player:setVar("Flagbastok",0);
            player:addItem(182);
            player:messageSpecial(ITEM_OBTAINED,182);
        end
    elseif (currentMission == THE_FOUR_MUSKETEERS and missionStatus == 1) then
        player:startEvent(0x02cc);
    elseif (currentMission == THE_CHAINS_THAT_BIND_US and missionStatus == 0) then
        player:startEvent(0x02ff); -- First cutscene of mission
    elseif (currentMission == THE_CHAINS_THAT_BIND_US) and (missionStatus == 2) then
        player:showText(npc, 8596); -- Dialogue after first cutscene
    elseif (currentMission == THE_CHAINS_THAT_BIND_US) and (missionStatus == 3) then
        player:startEvent(0x0300); -- Cutscene on return from Quicksand Caves
    elseif (player:getQuestStatus(CRYSTAL_WAR,FIRES_OF_DISCONTENT) == QUEST_ACCEPTED) then
        if (player:getVar("FiresOfDiscProg") == 1) then
            player:startEvent(0x03BC);
        else
            player:startEvent(0x03BD);
        end
    elseif (mainlvl >= 71 and skill >= 240 and player:getQuestStatus(BASTOK,THE_WEIGHT_OF_YOUR_LIMITS) ~= QUEST_ACCEPTED) then
	   player:PrintToPlayer("Iron Eater : Steel Cyclone eh?  Use it 100 times and then come see me afterwards.",0x0D);
	   player:setVar("STEEL_CYCLONE",100);
	   player:addQuest(BASTOK,THE_WEIGHT_OF_YOUR_LIMITS);
    elseif (wsnm == 1 and player:getQuestStatus(BASTOK,THE_WEIGHT_OF_YOUR_LIMITS) == QUEST_ACCEPTED) then
	   player:PrintToPlayer("Iron Eater :  Good Job.  Go to The Sanctuary of Zi'Tah and fight the monster that dwells there.",0x0D);
	   player:addKeyItem(MAP_TO_THE_ANNALS_OF_TRUTH);
 	   player:messageSpecial(MAP_TO_THE_ANNALS_OF_TRUTH);
	   player:setVar("STEEL_CYCLONE_WIN",1);
    elseif (player:hasKeyItem(ANNALS_OF_TRUTH) and player:getVar("STEEL_CYCLONE_WIN") == 2) then
	   player:PrintToPlayer("Iron Eater : You have done well.  Steel Cyclone is now at full power!",0x0D);
	   player:delKeyItem(ANNALS_OF_TRUTH);
	   player:completeQuest(BASTOK,THE_WEIGHT_OF_YOUR_LIMITS);
	else
        player:startEvent(0x025c);
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
    if (csid == 0x02cb and option == 0) then
        player:setVar("MissionStatus",1);
    elseif (csid == 0x030c) then
        player:setVar("BASTOK92", 1);
    elseif (csid == 0x02ff and option == 0) then
        player:setVar("MissionStatus", 1);
    elseif (csid == 0x0300) then
        finishMissionTimeline(player, 1, csid, option);
    elseif (csid == 0x030e) then
        if (player:getFreeSlotsCount() == 0) then 
            player:messageSpecial(ITEM_CANNOT_BE_OBTAINED,182);
            player:setVar("Flagbastok",1);
        else    
            player:addItem(182);
            player:messageSpecial(ITEM_OBTAINED,182);
        end
        player:setVar("BASTOK92",0);
        player:completeMission(BASTOK,WHERE_TWO_PATHS_CONVERGE);
        player:setRank(10);
        player:addGil(GIL_RATE*100000);
        player:messageSpecial(GIL_OBTAINED,GIL_RATE*100000);
        player:setTitle(296);
    elseif (csid == 0x03BC) then
        player:setVar("FiresOfDiscProg",2);
    end
end;