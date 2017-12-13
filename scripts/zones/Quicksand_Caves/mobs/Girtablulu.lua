-----------------------------------	
-- Area: Quicksand Caves
-- MOB:  Gritablulu
-- Savage Blade
-----------------------------------		
require("scripts/globals/keyitems");
require("scripts/zones/Quicksand_Caves/TextIDs");
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
    if (killer:getVar("SAVAGE_BLADE_WIN") == 1) then
    killer:addKeyItem(ANNALS_OF_TRUTH);
    killer:messageSpecial(KEYITEM_OBTAINED,ANNALS_OF_TRUTH);
	killer:delKeyItem(MAP_TO_THE_ANNALS_OF_TRUTH);
	killer:setVar("SAVAGE_BLADE_WIN",2);
	killer:setVar("SAVAGE_BLADE",0);	
	end
end;	
