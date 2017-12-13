-----------------------------------
-- 
-- Zone: Everbloom_Hollow
-- 
-----------------------------------

require("scripts/globals/settings");
package.loaded["scripts/zones/Everbloom_Hollow/TextIDs"] = nil;
require("scripts/zones/Everbloom_Hollow/TextIDs");

-----------------------------------
--  onInitialize
-----------------------------------

function onInitialize(zone)
end;

-----------------------------------
-- onZoneIn
-----------------------------------

function onZoneIn(player,prevZone)
cs = -1;

if (prevZone == 98) then
player:addTempItem(5349,1);
 player:PrintToPlayer("REGISTERED22");
 if (player:isBcnmsFull() == 1) then
            if (player:hasStatusEffect(EFFECT_DYNAMIS, 0) == false) then
                inst = player:addPlayerToBcnm(1375);
                player:PrintToPlayer("REGISTERED");
                if (inst == 1) then
                    player:bcnmEnter(1375);
                else
                     cs = 0;
                end
            else
                player:bcnmEnter(1375);
            end
        else
            inst = player:bcnmRegister(1375);

            if (inst == 1) then
                player:bcnmEnter(1375);
            else
                cs = 0;
            end

       
  
    end
else if (prevZone == 90) then
player:addTempItem(5349,1);
 player:PrintToPlayer("REGISTERED22");
 if (player:isBcnmsFull() == 1) then
            if (player:hasStatusEffect(EFFECT_DYNAMIS, 0) == false) then
                inst = player:addPlayerToBcnm(1376);
                player:PrintToPlayer("REGISTERED");
                if (inst == 1) then
                    player:bcnmEnter(1376);
                else
                     cs = 0;
                end
            else
                player:bcnmEnter(1376);
            end
        else
            inst = player:bcnmRegister(1376);

            if (inst == 1) then
                player:bcnmEnter(1376);
            else
                cs = 0;
            end

       
  
    end
	end
	end
	

    return cs;
end;

-----------------------------------
-- onRegionEnter          
-----------------------------------

function onRegionEnter(player,region)
end;

-----------------------------------
-- onEventUpdate
-----------------------------------

function onEventUpdate(player,csid,option)
--printf("CSID: %u",csid);
--printf("RESULT: %u",option);
end;

-----------------------------------
-- onEventFinish
-----------------------------------

function onEventFinish(player,csid,option)
--printf("CSID: %u",csid);
--printf("RESULT: %u",option);
end;



