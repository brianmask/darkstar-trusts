-----------------------------------
--
-- TOAU-15: The Black Coffin
--
-----------------------------------

require("scripts/globals/instance")
require("scripts/globals/keyitems");
require("scripts/globals/missions");
local TheAshuTalif = require("scripts/zones/The_Ashu_Talif/IDs");

-----------------------------------
-- afterInstanceRegister
-----------------------------------

function afterInstanceRegister(player)
    local instance = player:getInstance();
    player:messageSpecial(TheAshuTalif.text.FADES_INTO_NOTHINGNESS, EPHRAMADIAN_GOLD_COIN);
    player:delKeyItem(EPHRAMADIAN_GOLD_COIN);
    player:messageSpecial(TheAshuTalif.text.TIME_TO_COMPLETE, instance:getTimeLimit());
end;

-----------------------------------
-- onInstanceCreated
-----------------------------------

function onInstanceCreated(instance)
    SpawnMob(TheAshuTalif.mobs.GESSHO, instance);
    for i,v in pairs(TheAshuTalif.mobs[1]) do
        SpawnMob(v, instance);
    end
end;

-----------------------------------
-- onInstanceTimeUpdate
-----------------------------------

function onInstanceTimeUpdate(instance, elapsed)
    updateInstanceTime(instance, elapsed, TheAshuTalif.text)
end;

-----------------------------------
-- onInstanceFailure
-----------------------------------

function onInstanceFailure(instance)

    local chars = instance:getChars();

    for i,v in pairs(chars) do
        v:messageSpecial(TheAshuTalif.text.MISSION_FAILED,10,10);
        v:startEvent(102);
    end
end;

-----------------------------------
-- onInstanceProgressUpdate
-----------------------------------

function onInstanceProgressUpdate(instance, progress)

    if (progress == 1) then
        for i,v in pairs(TheAshuTalif.mobs[2]) do
            SpawnMob(v, instance);
        end
    elseif (progress >= 10 and instance:completed() == false) then
        local v = GetMobByID(TheAshuTalif.mobs.GESSHO, instance);

 

        local chars = instance:getChars();

        for i,v in pairs(chars) do
		    printf("Event 102 because Captain is under 70% HP");
            v:startEvent(101);
        end

        instance:complete();
    end

end;

-----------------------------------
-- onInstanceComplete
-----------------------------------

function onInstanceComplete(instance)
   
	-- for i,v in pairs(TheAshuTalif.mobs[2]) do
	   --     printf("DespawnMobs");
         --   DespawnMob(v, instance);
	-- end

	
    local chars = instance:getChars();

    for i,v in pairs(chars) do
        if (v:getCurrentMission(TOAU) == THE_BLACK_COFFIN) then
            v:setVar("AhtUrganStatus", 2);
            v:startEvent(101);
			v:setPos(-462,-2,-394,0,54);
		else
            v:startEvent(101);
			v:setPos(-462,-2,-394,0,54);		
        end
    end
end;

function onEventUpdate(player,csid,option)

end;

function onEventFinish(player,csid,option)

end;

