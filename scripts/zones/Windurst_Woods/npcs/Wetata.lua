-----------------------------------
--  Area: Windurst Woods
--   NPC: Wetata
--  Type: Trust NPC
-- @zone: 241
--  @pos 7.800 -3.5 -10.064
--
-- Auto-Script: Requires Verification (Verfied by Brawndo)
-----------------------------------
package.loaded["scripts/zones/Windurst_Woods/TextIDs"] = nil;
require("scripts/zones/Windurst_Woods/TextIDs");
require("scripts/globals/settings");
require("scripts/globals/keyitems");
-----------------------------------

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)
if ((trade:hasItemQty(10183,1) and (player:hasSpell(991) == false) and (player:getNation() == 2) and (player:hasKeyItem(WINDURST_TRUST_PERMIT) == true))) then	
player:addSpell(991);
player:PrintToPlayer("You may now summon Darrcullin as a Trust!", 0x15);
else if ((trade:hasItemQty(10153,1) and (player:hasSpell(968) == false) and (player:getNation() == 2) and (player:hasKeyItem(WINDURST_TRUST_PERMIT) == true))) then	
player:addSpell(968);
player:PrintToPlayer("You may now summon Adelhied as a Trust!", 0x15);
end
end	

end;

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)
if (player:getNation() == 2) and (player:hasKeyItem(WINDURST_TRUST_PERMIT) == false) then
    player:addKeyItem(WINDURST_TRUST_PERMIT);
	player:addKeyItem(GREEN_INSTITUTE_CARD);
	player:messageSpecial(KEYITEM_OBTAINED,WINDURST_TRUST_PERMIT);
	player:messageSpecial(KEYITEM_OBTAINED,GREEN_INSTITUTE_CARD);	
    else if (player:getNation() == 2) and (player:hasKeyItem(WINDURST_TRUST_PERMIT)) then
	player:PrintToPlayer("Wetata : If you find any of those Cipher thingies, trade them to me.", 0xD);
	else
	player:PrintToPlayer("Wetata : You seem to be from another Nation.  Sadly I cantaru help you", 0xD);
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

