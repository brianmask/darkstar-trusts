-----------------------------------	
-- Area: Western Altepa Desert
-- MOB: Maharaja
-- Ground Strike WSNM
-----------------------------------		
require("scripts/globals/keyitems");
require("scripts/zones/Western_Altepa_Desert/TextIDs");
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
    if (killer:getVar("GROUND_STRIKE_WIN") == 1) then
    killer:addKeyItem(ANNALS_OF_TRUTH);
    killer:messageSpecial(KEYITEM_OBTAINED,ANNALS_OF_TRUTH);
	killer:delKeyItem(MAP_TO_THE_ANNALS_OF_TRUTH);
	killer:setVar("GROUND_STRIKE_WIN",2);
	killer:setVar("GROUND_STRIKE",0);	
	end
end;	
