-----------------------------------
-- Area: Ifrit's Cauldron
-- NPC:  ???
-- Involved in Quest: Blood and Glory
-- @pos 118.794,19.986,143.763
-----------------------------------
package.loaded["scripts/zones/Ifrits_Cauldron/TextIDs"] = nil;
-----------------------------------

require("scripts/globals/missions");
require("scripts/zones/Ifrits_Cauldron/TextIDs");
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
	 if (player:hasKeyItem(MAP_TO_THE_ANNALS_OF_TRUTH) and player:getVar("RETRIBUTION_WIN") == 1) then
	 SpawnMob(17617165):updateClaim(player);
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