-----------------------------------	
-- Area: The Sanctuary of ZiTah	
-- MOB:  Greenman
-- Steel Cyclone NM	
-----------------------------------		
require("scripts/globals/keyitems");
require("scripts/zones/The_Sanctuary_of_ZiTah/TextIDs");
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
    if (killer:getVar("STEEL_CYCLONE_WIN") == 1) then
    killer:addKeyItem(ANNALS_OF_TRUTH);
    killer:messageSpecial(KEYITEM_OBTAINED,ANNALS_OF_TRUTH);
	killer:delKeyItem(MAP_TO_THE_ANNALS_OF_TRUTH);
	killer:setVar("STEEL_CYCLONE_WIN",2);
	killer:setVar("STEEL_CYCLONE",0);
	end
end;	
