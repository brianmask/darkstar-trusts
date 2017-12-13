-----------------------------------
-- Area: Dragons Aery
--  HNM: Fafnir
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
	mob:setLocalVar("PartySize",9); 
    if (math.random(1,100) <= 5) then -- Hardcoded the drop of ridill to 5%
        SetDropRate(918,16555,1000); -- Ridill
    else
        SetDropRate(918,16555,0);
    end	

end;

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
    killer:addTitle(FAFNIR_SLAYER);
	if (killer:getObjType() == TYPE_PC) then
	killer:setVar("Fafnir_Win",1);
	killer:addCurrency('prestige', 100);
	killer:PrintToPlayer("You obtain 100 Prestige Points!", 0xD);
	end
	
end;

-----------------------------------
-- onMobDespawn
-----------------------------------

function onMobDespawn(mob)
    local Fafnir = mob:getID();
    local Nidhogg = mob:getID()+1;
    local ToD = GetServerVariable("[POP]Nidhogg");
    local kills = GetServerVariable("[PH]Nidhogg");
    local popNow = (math.random(1,5) == 3 or kills > 6);

    if (LandKingSystem_HQ ~= 1 and ToD <= os.time(t) and popNow == true) then
        -- 0 = timed spawn, 1 = force pop only, 2 = BOTH
        if (LandKingSystem_NQ == 0) then
            DeterMob(Fafnir, true);
        end
        
        DeterMob(Nidhogg, false);
        UpdateNMSpawnPoint(Nidhogg);
        GetMobByID(Nidhogg):setRespawnTime(math.random(75600,86400));
    else
        if (LandKingSystem_NQ ~= 1) then
            UpdateNMSpawnPoint(Fafnir);
            mob:setRespawnTime(math.random(75600,86400));
            SetServerVariable("[PH]Nidhogg", kills + 1);
        end
    end
end;