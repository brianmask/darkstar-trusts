-----------------------------------
-- Area: Valley of Sorrows
--  HNM: Aspidochelone
-----------------------------------

require("scripts/globals/settings");
require("scripts/globals/titles");
require("scripts/globals/status");
require("scripts/globals/mobscaler");

-----------------------------------
-- onMobInitialize Action
-----------------------------------

function onMobInitialize(mob)
end;

function onMobSpawn(mob)
	mob:setLocalVar("PartySize",5); 
end	

function onMobFight(mob, target)
    mobScaler(mob,target);
   local mobId = mob:getID();
    if (GetMobAction(mobId) ~= ACTION_ATTACK) then
	mob:setLocalVar("depopTime", os.time());
    end
	
end;

function onMobRoam(mob)
    local despawnTime = mob:getLocalVar("depopTime");

    if (os.time() - despawnTime > 180) then
        DespawnMob(mob:getID());
    end
end;
-----------------------------------
-- onMobDeath
-----------------------------------

function onMobDeath(mob, killer)

    killer:addTitle(ASPIDOCHELONE_SINKER);
	if (killer:getObjType() == TYPE_PC) then
	killer:setVar("Aspi_Win",1);
	killer:addCurrency('prestige', 250);
	killer:PrintToPlayer("You obtain 250 Prestige Points!", 0xD);
	end

    -- Set Aspidochelone's Window Open Time
    if (LandKingSystem_HQ ~= 1) then
        local wait = 72 * 3600;
        SetServerVariable("[POP]Aspidochelone", os.time(t) + wait); -- 3 days
        if (LandKingSystem_HQ == 0) then -- Is time spawn only
            DeterMob(mob:getID(), true);
        end
    end

    -- Set Adamantoise's spawnpoint and respawn time (21-24 hours)
    if (LandKingSystem_NQ ~= 1) then
        Adamantoise = mob:getID()-1;
        SetServerVariable("[PH]Aspidochelone", 0);
        DeterMob(Adamantoise, false);
        UpdateNMSpawnPoint(Adamantoise);
        GetMobByID(Adamantoise):setRespawnTime(math.random(75600,86400));
    end

end;