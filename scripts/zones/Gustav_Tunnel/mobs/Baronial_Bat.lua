-----------------------------------	
-- Area: Gustav Tunnel
-- MOB:  Baronial Bat
-- Evisceration
-----------------------------------		
require("scripts/globals/keyitems");
require("scripts/zones/Gustav_Tunnel/TextIDs");
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
    if (killer:getVar("EVISCERATION_WIN") == 1) then
    killer:addKeyItem(ANNALS_OF_TRUTH);
    killer:messageSpecial(KEYITEM_OBTAINED,ANNALS_OF_TRUTH);
	killer:delKeyItem(MAP_TO_THE_ANNALS_OF_TRUTH);
	killer:setVar("EVISCERATION_WIN",2);
	killer:setVar("EVISCERATION",0);
	end
end;	
