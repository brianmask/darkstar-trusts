-----------------------------------
-- Area: Western Altepa Desert
-- NPC:  qm1 (???)
-- Involved in Mission: Inheritance
-- @pos -659.294,0.237,-338.234
-----------------------------------
package.loaded["scripts/zones/Western_Altepa_Desert/TextIDs"] = nil;
-----------------------------------

require("scripts/globals/keyitems");
require("scripts/globals/missions");
require("scripts/zones/Western_Altepa_Desert/TextIDs");

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)
end; 

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)
     if (player:hasKeyItem(MAP_TO_THE_ANNALS_OF_TRUTH) and player:getVar("GROUND_STRIKE_WIN") == 1) then
	 SpawnMob(17289656):updateClaim(player);
     else
     player:messageSpecial(NOTHING_OUT_OF_ORDINARY);
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
end;