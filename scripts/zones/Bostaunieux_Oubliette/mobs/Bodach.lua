-----------------------------------	
-- Area: Bostaunieux Oubliette
-- MOB:  Bodach
-- Asuran Fists
-----------------------------------		
require("scripts/globals/keyitems");
require("scripts/zones/Bostaunieux_Oubliette/TextIDs");
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
    if (killer:getVar("ASURAN_FISTS_WIN") == 1) then 
    killer:addKeyItem(ANNALS_OF_TRUTH);
    killer:messageSpecial(KEYITEM_OBTAINED,ANNALS_OF_TRUTH);
	killer:delKeyItem(MAP_TO_THE_ANNALS_OF_TRUTH);
	killer:setVar("ASURAN_FISTS_WIN",2);
	killer:setVar("ASURAN_FISTS",0);
	end
end;	
