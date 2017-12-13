-----------------------------------
--    Area: Quicksand Caves
--     NPC:  qm2
--  Notes: Spawns Girtablulu Savage Blade WSNM
--     @pos -144.856,1.935,446.109
-----------------------------------
package.loaded["scripts/zones/Quicksand_Caves/TextIDs"] = nil;
-----------------------------------

require("scripts/zones/Quicksand_Caves/TextIDs");
require("scripts/globals/keyitems");
-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)
    
    
end;

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)
	 if (player:hasKeyItem(MAP_TO_THE_ANNALS_OF_TRUTH) and player:getVar("SAVAGE_BLADE_WIN") == 1) then
	 SpawnMob(17629645):updateClaim(player);
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