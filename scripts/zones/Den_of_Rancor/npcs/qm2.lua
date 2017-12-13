-----------------------------------
-- Area: Den of Rancor
-- NPC:  ??? - Mokumokuren
-- @pos 117, 35, -280
-----------------------------------
package.loaded["scripts/zones/Den_of_Rancor/TextIDs"] = nil;
-----------------------------------

require("scripts/zones/Den_of_Rancor/TextIDs");

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)

 
end; 

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)

	 if (player:hasKeyItem(MAP_TO_THE_ANNALS_OF_TRUTH) and player:getVar("SPIRAL_HELL_WIN") == 1) then
	 SpawnMob(17433006):updateClaim(player);
	 end


end;