-----------------------------------	
-- Area: Ro'Maeve
-- MOB:  Eldhrimnir
-- Black Halo NM
-----------------------------------		
require("scripts/globals/keyitems");
require("scripts/zones/RoMaeve/TextIDs");
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
    if (killer:getVar("BLACK_HALO_WIN") == 1) then	
    killer:addKeyItem(ANNALS_OF_TRUTH);
    killer:messageSpecial(KEYITEM_OBTAINED,ANNALS_OF_TRUTH);
	killer:delKeyItem(MAP_TO_THE_ANNALS_OF_TRUTH);
	killer:setVar("BLACK_HALO_WIN",2);
	killer:setVar("BLACK_HALO",0);	
	end
end;	
