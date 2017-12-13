
-----------------------------------
-- mob : Megalobugard
-- zone : Lufaise_Meadows
-----------------------------------

-----------------------------------
-- onMobDeath
-----------------------------------

function onMobDeath(mob, player, isKiller)
end;

-----------------------------------
-- onMobDespawn
-----------------------------------

function onMobDespawn(mob)

    -- Set Megalobugard Window Open Time
    local wait = math.random((2700),(3600));
    SetServerVariable("[POP]Megalobugard", os.time(t) + wait); -- 45min to 1hr
    DeterMob(mob:getID(), true);

    -- Set PH back to normal, then set to respawn spawn
    local PH = GetServerVariable("[PH]Megalobugard");
    SetServerVariable("[PH]Megalobugard", 0);
    DeterMob(PH, false);
    GetMobByID(PH):setRespawnTime(GetMobRespawnTime(PH));

end;