-----------------------------------
--  Area: Port Bastok
--   NPC: Clarion Star
--  Type: Trust NPC

-----------------------------------
package.loaded["scripts/zones/Port_Bastok/TextIDs"] = nil;
-----------------------------------
require("scripts/zones/Port_Bastok/TextIDs");
require("scripts/globals/settings");
require("scripts/globals/keyitems");
-----------------------------------

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)
	

end;

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)
if (player:getNation() == 1) and (player:hasKeyItem(BASTOK_TRUST_PERMIT) == false) then
    player:addKeyItem(BASTOK_TRUST_PERMIT);
	player:addKeyItem(BLUE_INSTITUTE_CARD);
	player:messageSpecial(KEYITEM_OBTAINED,BASTOK_TRUST_PERMIT);
	player:messageSpecial(KEYITEM_OBTAINED,BLUE_INSTITUTE_CARD);
    else if (player:getNation() == 1) and (player:hasKeyItem(BASTOK_TRUST_PERMIT)) then
	player:PrintToPlayer("Clarion Star : Once you get a trust cipher, bring it to me", 0xD);
	else
	player:PrintToPlayer("Clarion Star : You seem to be from another Nation.  I can't really help you", 0xD);
	end
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

end;

