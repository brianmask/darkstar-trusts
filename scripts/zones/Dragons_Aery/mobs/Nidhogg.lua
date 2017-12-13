-----------------------------------
-- Area: Dragons Aery
--  HNM: Nidhogg
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
	mob:setLocalVar("PartySize",11); 
end	

-----------------------------------
-- onMobFight Action
-----------------------------------

function onMobFight(mob, target)
    mobScaler(mob,target);
    local battletime = mob:getBattleTime();
    local twohourTime = mob:getLocalVar("twohourTime");

    if (twohourTime == 0) then
        mob:setLocalVar("twohourTime",math.random(30,90));
    end

    if (battletime >= twohourTime) then
        mob:useMobAbility(700);
        -- technically aerial hurricane wing, but I'm using 700 for his two hour
        --(since I have no inclination to spend millions on a PI to cap one name you never see)
        mob:setLocalVar("twohourTime",battletime + math.random(60,120));
    end
	
	    if (GetMobAction(17408019) ~= ACTION_ATTACK) then
	mob:setLocalVar("depopTime", os.time());
    end
end;
	
function onMobRoam(mob)
    local despawnTime = mob:getLocalVar("depopTime");

    if (os.time() - despawnTime > 180) then
        DespawnMob(17408019);
    end
end;

-----------------------------------
-- onMobDeath
-----------------------------------

function onMobDeath(mob, killer)

    killer:addTitle(NIDHOGG_SLAYER);
	
    if (killer:getObjType() == TYPE_PC) then
	killer:setVar("Nidhogg_Win",1);
	killer:addCurrency('prestige', 250);
	killer:PrintToPlayer("You obtain 250 Prestige Points!", 0xD);
	end

    -- Set Nidhogg's Window Open Time
    if (LandKingSystem_HQ ~= 1) then
        local wait = 72 * 3600;
        SetServerVariable("[POP]Nidhogg", os.time(t) + wait); -- 3 days
        if (LandKingSystem_HQ == 0) then -- Is time spawn only
            DeterMob(mob:getID(), true);
        end
    end

    -- Set Fafnir's spawnpoint and respawn time (21-24 hours)
    if (LandKingSystem_NQ ~= 1) then
        local Fafnir = mob:getID()-1;
        SetServerVariable("[PH]Nidhogg", 0);
        DeterMob(Fafnir, false);
        UpdateNMSpawnPoint(Fafnir);
        GetMobByID(Fafnir):setRespawnTime(math.random(75600,86400));
    end

end;