-----------------------------------
-- Area: Behemoth's Dominion
--  HNM: King Behemoth
-----------------------------------

require("scripts/globals/settings");
require("scripts/globals/titles");
require("scripts/globals/status");
require("scripts/globals/mobscaler");

-----------------------------------
-- onMobInitialize Action
-----------------------------------

function onMobInitialize(mob)
    mob:setMobMod(MOBMOD_MAGIC_COOL, 60);
end;

function onMobSpawn(mob)
	mob:setLocalVar("PartySize",8); 
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
-- onSpellPrecast
-----------------------------------

function onSpellPrecast(mob, spell)
    if (spell:getID() == 218) then
        spell:setAoE(SPELLAOE_RADIAL);
        spell:setFlag(SPELLFLAG_HIT_ALL);
        spell:setRadius(30);
        spell:setAnimation(280);
        spell:setMPCost(1);
    end
end;



-----------------------------------
-- onMobDeath
-----------------------------------

function onMobDeath(mob, killer)

    killer:addTitle(BEHEMOTH_DETHRONER);
	if (killer:getObjType() == TYPE_PC) then
	killer:setVar("King_Behemoth_Win",1);
	killer:addCurrency('prestige', 250);
	killer:PrintToPlayer("You obtain 250 Prestige Points!", 0xD);
	end

    -- Todo: move this to SQL after drop slots are a thing
    if (math.random(1,100) <= 5) then -- Hardcoded "this or this item" drop rate until implemented.
        SetDropRate(1936,13566,1000); -- Defending Ring
        SetDropRate(1936,13415,0);
    else
        SetDropRate(1936,13566,0);
        SetDropRate(1936,13415,1000); -- Pixie Earring
    end

    -- Set King_Behemoth's Window Open Time
    if (LandKingSystem_HQ ~= 1) then
        local wait = 72 * 3600;
        SetServerVariable("[POP]King_Behemoth", os.time(t) + wait); -- 3 days
        if (LandKingSystem_HQ == 0) then -- Is time spawn only
            DeterMob(mob:getID(), true);
        end
    end

    -- Set Behemoth's spawnpoint and respawn time (21-24 hours)
    if (LandKingSystem_NQ ~= 1) then
        SetServerVariable("[PH]King_Behemoth", 0);
        local Behemoth = mob:getID()-1;
        DeterMob(Behemoth, false);
        UpdateNMSpawnPoint(Behemoth);
        GetMobByID(Behemoth):setRespawnTime(math.random(75600,86400));
    end
end;