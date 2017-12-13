-----------------------------------
-- Area: Dynamis Beaucedine
-- NPC:  Quadav
-- Drops Azure Granules of Time Randomly
-----------------------------------
package.loaded["scripts/zones/Dynamis-Beaucedine/TextIDs"] = nil;
-----------------------------------
require("scripts/globals/status");
require("scripts/globals/dynamis");
require("scripts/zones/Dynamis-Beaucedine/TextIDs");
require("scripts/globals/keyitems");

-----------------------------------
-- onMobSpawn Action
-----------------------------------

function onMobSpawn(mob)
	
end;

-----------------------------------
-- onMobEngaged
-----------------------------------

function onMobEngaged(mob,target)

end;

-----------------------------------
-- onMobDeath
-----------------------------------

function onMobDeath(mob,killer)
local rand = math.random(1,100);

if (rand < 15 and killer:getObjType() == TYPE_PC) then
    if (killer:hasKeyItem(AZURE_GRANULES_OF_TIME) == false) then
	killer:addKeyItem(AZURE_GRANULES_OF_TIME);
	killer:messageSpecial(KEYITEM_OBTAINED,AZURE_GRANULES_OF_TIME);
	end
end

	
end;
