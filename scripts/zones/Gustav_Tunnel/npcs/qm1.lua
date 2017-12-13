-----------------------------------
-- Area: Gustav tunnel
-- NPC:  qm1 (???)
-- @zone 212
-- @pos 52.761,-0.999,19.852
-----------------------------------
package.loaded["scripts/zones/Gustav_Tunnel/TextIDs"] = nil;
-----------------------------------

require("scripts/globals/settings");
require("scripts/globals/quests");
require("scripts/zones/Gustav_Tunnel/TextIDs");
require("scripts/globals/keyitems");

-----------------------------------
-- onTrade Action
----------------------------------

function onTrade(player,npc,trade)
	
end;

----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)
	 if (player:hasKeyItem(MAP_TO_THE_ANNALS_OF_TRUTH) and player:getVar("EVISCERATION_WIN") == 1) then
	 SpawnMob(17645809):updateClaim(player);
     else
	 player:messageSpecial(NOTHING_OUT_OF_ORDINARY);
	 end
	 
end;

-----------------------------------
-- onEventUpdate
-----------------------------------

function onEventUpdate(player,csid,option)
--printf("CSID2: %u",csid);
--printf("RESULT2: %u",option);
end;

-----------------------------------
-- onEventFinish
-----------------------------------

function onEventFinish(player,csid,option)
--printf("CSID: %u",csid);
--printf("RESULT: %u",option);
end;
