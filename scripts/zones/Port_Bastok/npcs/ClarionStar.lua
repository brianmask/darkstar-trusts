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
if ((trade:hasItemQty(10183,1) and (player:hasSpell(991) == false) and (player:getNation() == 1) and (player:hasKeyItem(BASTOK_TRUST_PERMIT) == true))) then	
player:addSpell(991);
player:PrintToPlayer("You may now summon Darrcullin as a Trust!", 0x15);
else if ((trade:hasItemQty(10153,1) and (player:hasSpell(968) == false) and (player:getNation() == 1) and (player:hasKeyItem(BASTOK_TRUST_PERMIT) == true))) then	
player:addSpell(968);
player:PrintToPlayer("You may now summon Adelhied as a Trust!", 0x15);
end
end
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

