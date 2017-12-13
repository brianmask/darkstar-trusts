-----------------------------------	
-- Area: Kuftal Tunnel	
-- MOB:  Kettenkaefer
-- Tachi: Kasha NM
-----------------------------------		
require("scripts/globals/keyitems");
require("scripts/zones/Kuftal_Tunnel/TextIDs");
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
    if (killer:getVar("TACHI_KASHA_WIN") == 1) then	
    killer:addKeyItem(ANNALS_OF_TRUTH);
    killer:messageSpecial(KEYITEM_OBTAINED,ANNALS_OF_TRUTH);
	killer:delKeyItem(MAP_TO_THE_ANNALS_OF_TRUTH);
	killer:setVar("TACHI_KASHA_WIN",2);
	killer:setVar("TACHI_KASHA",0);
	end
end;	
