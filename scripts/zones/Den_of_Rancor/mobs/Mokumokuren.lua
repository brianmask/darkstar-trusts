-----------------------------------	
-- Area: Den of Rancor	
-- MOB:  Mokumokuren
-- Spiral Hell
-----------------------------------		
require("scripts/globals/keyitems");
require("scripts/zones/Den_of_Rancor/TextIDs");
-----------------------------------	

function onMobSpawn(mob)
mob:addMod(MOD_EVA,-50);
mob:addMod(MOD_ACC,-50);
mob:addMod(MOD_ATT,-50);
end;



-----------------------------------	
-- onMobDeath	
-----------------------------------	
	
function onMobDeath(mob,killer)	
    if (killer:getVar("SPIRAL_HELL_WIN") == 1) then
    killer:addKeyItem(ANNALS_OF_TRUTH);
    killer:messageSpecial(KEYITEM_OBTAINED,ANNALS_OF_TRUTH);
	killer:delKeyItem(MAP_TO_THE_ANNALS_OF_TRUTH);
	killer:setVar("SPIRAL_HELL_WIN",2);
	killer:setVar("SPIRAL_HELL",0);
	end
end;	
