-----------------------------------	
-- Area: Ifrits Cauldron
-- MOB:  Cailleach Bheur
-- Retribution NM
-----------------------------------		
require("scripts/globals/keyitems");
require("scripts/zones/Ifrits_Cauldron/TextIDs");
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
    if (killer:getVar("RETRIBUTION_WIN") == 1) then    
	killer:addKeyItem(ANNALS_OF_TRUTH);
    killer:messageSpecial(KEYITEM_OBTAINED,ANNALS_OF_TRUTH);
	killer:delKeyItem(MAP_TO_THE_ANNALS_OF_TRUTH);
	killer:setVar("RETRIBUTION_WIN",2);
	killer:setVar("RETRIBUTION",0);	
	end
end;	
