-----------------------------------
-- Area: Valley of Sorrows
--  HNM: Adamantoise
-----------------------------------

require("scripts/globals/settings");
require("scripts/globals/titles");
require("scripts/globals/status");
require("scripts/globals/mobscaler");

-----------------------------------
-- onMobInitialize
-----------------------------------

function onMobInitialize(mob)
end;

function onMobSpawn(mob)
	mob:setLocalVar("PartySize",1);
end	

function onMobFight(mob, target)
    mobScaler(mob,target);
    local mobId = mob:getID();
    if (GetMobAction(mobId) ~= ACTION_ATTACK) then
	mob:setLocalVar("depopTime", os.time());
    end
	
end;

-----------------------------------
-- onMobDeath
-----------------------------------

function onMobDeath(mob, killer)
    killer:addTitle(TORTOISE_TORTURER);
	if (killer:getObjType() == TYPE_PC) then
	killer:setVar("Adamantoise_Win",1);
	killer:addCurrency('prestige', 100);
	killer:PrintToPlayer("You obtain 100 Prestige Points!", 0xD);
	end
end;

function onMobRoam(mob)
    local despawnTime = mob:getLocalVar("depopTime");

    if (os.time() - despawnTime > 180) then
        DespawnMob(mob:getID());
    end
end;	

-----------------------------------
-- onMobDespawn
-----------------------------------

function onMobDespawn(mob)
    local Adamantoise = mob:getID();
    local Aspidochelone = mob:getID()+1;
    local ToD = GetServerVariable("[POP]Aspidochelone");
    local kills = GetServerVariable("[PH]Aspidochelone");
    local popNow = (math.random(1,5) == 3 or kills > 6);

    if (LandKingSystem_HQ ~= 1 and ToD <= os.time(t) and popNow == true) then
        -- 0 = timed spawn, 1 = force pop only, 2 = BOTH
        if (LandKingSystem_NQ == 0) then
            DeterMob(Adamantoise, true);
        end

        DeterMob(Aspidochelone, false);
        UpdateNMSpawnPoint(Aspidochelone);
        GetMobByID(Aspidochelone):setRespawnTime(math.random(75600,86400));
    else
        if (LandKingSystem_NQ ~= 1) then
            UpdateNMSpawnPoint(Adamantoise);
            mob:setRespawnTime(math.random(75600,86400));
            SetServerVariable("[PH]Aspidochelone", kills + 1);
        end
    end
end;