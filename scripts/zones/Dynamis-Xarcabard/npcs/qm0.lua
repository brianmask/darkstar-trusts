-----------------------------------
-- Area: Dynamis Xarcabard
-- NPC:  ??? (Spawn when mega is defeated)
-----------------------------------
package.loaded["scripts/zones/Dynamis-Xarcabard/TextIDs"] = nil;
-----------------------------------

require("scripts/globals/titles");
require("scripts/globals/keyitems");
require("scripts/zones/Dynamis-Xarcabard/TextIDs");

-----------------------------------
-- onTrade
-----------------------------------

function onTrade(player,npc,trade)

end;

-----------------------------------
-- onTrigger
-----------------------------------

function onTrigger(player,npc)
if ((player:hasKeyItem(ALABASTER_GRANULES_OF_TIME)) and (player:hasKeyItem(AMBER_GRANULES_OF_TIME)) and (player:hasKeyItem(AZURE_GRANULES_OF_TIME))
and (player:hasKeyItem(CRIMSON_GRANULES_OF_TIME))) then
SpawnMob(17330177):updateEnmity(player); 
player:delKeyItem(ALABASTER_GRANULES_OF_TIME);
player:delKeyItem(AMBER_GRANULES_OF_TIME);
player:delKeyItem(AZURE_GRANULES_OF_TIME);
player:delKeyItem(CRIMSON_GRANULES_OF_TIME);

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