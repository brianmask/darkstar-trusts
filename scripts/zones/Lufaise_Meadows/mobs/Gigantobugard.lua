
-----------------------------------
-- mob : Gigantobugard
-- zone : Lufaise_Meadows
-----------------------------------

require("scripts/zones/Lufaise_Meadows/MobIDs");

-----------------------------------
-- onMobDeath
-----------------------------------

function onMobDeath(mob, player, isKiller)
end;

-----------------------------------
-- onMobDespawn
-----------------------------------

function onMobDespawn(mob)
    local mobID = mob:getID();


    -- Megalobugard
    if (Megalobugard_PH[mobID] ~= nil) then
        local ToD = GetServerVariable("[POP]Megalobugard");
        if (ToD <= os.time(t) and GetMobAction(Nue) == 0) then
            if (math.random(1,15) == 5) then
                UpdateNMSpawnPoint(Megalobugard);
                GetMobByID(Megalobugard):setRespawnTime(GetMobRespawnTime(mobID));
                SetServerVariable("[PH]Megalobugard", mobID);
                DeterMob(mobID, true);
            end
        end
    end
end;