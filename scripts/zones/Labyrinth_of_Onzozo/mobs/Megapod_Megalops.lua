-----------------------------------	
-- Area: Labrynth of Onzozo
-- MOB: Megapod Megalops
-- Blade: Ku WSNM
-----------------------------------		
require("scripts/globals/keyitems");
require("scripts/zones/Labyrinth_of_Onzozo/TextIDs");
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
    if (killer:getVar("BLADE_KU_WIN") == 1) then
    killer:addKeyItem(ANNALS_OF_TRUTH);
    killer:messageSpecial(KEYITEM_OBTAINED,ANNALS_OF_TRUTH);
	killer:delKeyItem(MAP_TO_THE_ANNALS_OF_TRUTH);
	killer:setVar("BLADE_KU_WIN",2);
	killer:setVar("BLADE_KU",0);	
	end
end;	
