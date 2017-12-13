-----------------------------------
-- Area: Sealion's Den
-- NPC:  Iron Gate
-- @pos 612 132 774 32
-----------------------------------
package.loaded["scripts/zones/Sealions_Den/TextIDs"] = nil;
-----------------------------------

require("scripts/globals/bcnm");
require("scripts/globals/missions");
require("scripts/globals/titles");
require("scripts/globals/teleports");
require("scripts/zones/Sealions_Den/TextIDs");

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)
	
	if (TradeBCNM(player,player:getZoneID(),trade,npc)) then
		return;
	end
	
	local party = player:getParty();
    if (party ~= nil) then
        for i,member in ipairs(party) do
		    if (member:hasItem(3557) == true) then
	        member:setVar("PrisheFight",1);
		    else
			member:PrintToPlayer("Not all members have the required item",0x0D);
			end
		end
	elseif (party == nil) then
	    if (player:hasItem(3557)) then
     		player:setVar("PrisheFight",1);	
		else
		    player:PrintToPlayer("You do not meet the requirements",0x0D);
		end
	end

	
	if (player:getVar("PrisheFight") == 1) then
        if (party ~= nil) then
            for i,member in ipairs(party) do
			    member:delItem(3557,1);
			    member:setPos(-640,-231,529,66,0x20);
			end
	    else
	        player:delItem(3557,1);
	        player:setPos(-640,-231,529,66,0x20);
	    end
	end

end;

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)
    if (player:getCurrentMission(COP) == SLANDEROUS_UTTERINGS and player:getVar("PromathiaStatus") == 1) then
		player:startEvent(0x000D);
	elseif (EventTriggerBCNM(player,npc)) then
		return;
	elseif (player:getCurrentMission(COP) > THE_WARRIOR_S_PATH) then
		player:startEvent(0x000C);
	end	
end;

-----------------------------------
-- onEventUpdate
-----------------------------------

function onEventUpdate(player,csid,option)
--printf("onUpdate CSID: %u",csid);
--printf("onUpdate RESULT: %u",option);
	EventUpdateBCNM(player,csid,option)
end;

-----------------------------------
-- onEventFinish Action 
-----------------------------------

function onEventFinish(player,csid,option)
--printf("onFinish CSID: %u",csid);
--printf("onFinish RESULT: %u",option);
	
	if (EventFinishBCNM(player,csid,option)) then
		return;
	end
	if (csid == 0x000c and option == 1) then 
		toPalaceEntrance(player);
	elseif (csid == 0x000D) then
		player:setVar("PromathiaStatus",0);
		player:completeMission(COP,SLANDEROUS_UTTERINGS);
		player:addMission(COP,THE_ENDURING_TUMULT_OF_WAR);
		player:addTitle(THE_LOST_ONE);
	end
end;