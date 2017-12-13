-----------------------------------	
-- Area: The Boyahda Tree
-- MOB:  Beet Leafhopper
-- Detonator NM
-----------------------------------		
require("scripts/globals/keyitems");
require("scripts/zones/The_Boyahda_Tree/TextIDs");
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
    if (killer:getVar("DETONATOR_WIN") == 1) then
    killer:addKeyItem(ANNALS_OF_TRUTH);
    killer:messageSpecial(KEYITEM_OBTAINED,ANNALS_OF_TRUTH);
	killer:delKeyItem(MAP_TO_THE_ANNALS_OF_TRUTH);
	killer:setVar("DETONATOR_WIN",2);
	killer:setVar("DETONATOR",0);	
	end
end;	
