-----------------------------------	
-- Area: Temple of Uggalepih
-- MOB: Yallery Brown
-- Decimation WS
-----------------------------------		
require("scripts/globals/keyitems");
require("scripts/zones/Temple_of_Uggalepih/TextIDs");
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
    if (killer:getVar("DECIMATION_WIN") == 1) then
    killer:addKeyItem(ANNALS_OF_TRUTH);
    killer:messageSpecial(KEYITEM_OBTAINED,ANNALS_OF_TRUTH);
	killer:delKeyItem(MAP_TO_THE_ANNALS_OF_TRUTH);
	killer:setVar("DECIMATION_WIN",2);
	killer:setVar("DECIMATION",0);	
	end
end;	
