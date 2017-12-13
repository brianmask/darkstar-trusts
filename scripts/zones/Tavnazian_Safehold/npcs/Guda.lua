-----------------------------------
-- Area: Tavnazian Safehold
-- NPC: Guda
-- Standard Info NPC
-- 95 -41 39
-----------------------------------
package.loaded["scripts/zones/Tavnazian_Safehold/TextIDs"] = nil;
-----------------------------------
require("scripts/globals/missions");
-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)

    if (trade:hasItemQty(65535,15000) and player:hasCompletedMission(COP,ONE_TO_BE_FEARED) == true and player:hasItem(3557) == false and player:getFreeSlotsCount() == 0) then
        player:messageSpecial(ITEM_CANNOT_BE_OBTAINED,3557);
    elseif (trade:hasItemQty(65535,15000) and player:hasCompletedMission(COP,ONE_TO_BE_FEARED) == true and player:hasItem(3557) == false) then
	    player:addItem(3557);
		player:messageSpecial(ITEM_OBTAINED,3557);
		tradeComplete();
	elseif (trade:hasItemQty(65535,15000) and player:hasCompletedMission(COP,ONE_TO_BE_FEARED) == true and player:hasItem(3557)) then
	    player:PrintToPlayer("Guda : Looks like you already have an Athena Orb.",0xD);
	end
end; 

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)
    if (player:getVar("PRISHE_WIN") == 1 and player:getFreeSlotsCount() == 0) then
	    player:messageSpecial(ITEM_CANNOT_BE_OBTAINED,604);
    elseif (player:getVar("PRISHE_WIN") == 1) then
	    player:PrintToPlayer("Guda : Hopefully Prishe and Ulmia weren't too much trouble for you.  Here have this.",0xD);
	    player:setVar("PRISHE_WIN",0);
		player:addItem(604);
		player:messageSpecial(ITEM_OBTAINED,604);
	end

player:startEvent(0x0142);

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
end;



