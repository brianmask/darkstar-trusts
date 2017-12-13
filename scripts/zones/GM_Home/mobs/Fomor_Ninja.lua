-----------------------------------
-- Area: Salvage
--  MOB: Fomor Ninja
-----------------------------------

require("scripts/globals/status");

-----------------------------------
-- onMobInitialize Action
-----------------------------------

function onMobInitialize(mob)
mob:setMobMod(MOBMOD_HP_STANDBACK,-1);
end;

-----------------------------------
-- onMobSpawn Action
-----------------------------------

function onMobSpawn(mob)
mob:setLocalVar("FomorDespawn", os.time(t) + 15);
end;

-----------------------------------
-- onMobFight Action
-----------------------------------

function onMobFight(mob, target)


local depoptime = mob:getLocalVar("FomorDespawn");

 if (os.time(t) > depoptime) then
 local mobhp = mob:getHP();
 mob:useMobAbility(765);

 GetMobByID(17637700):addHP(mobhp);
 target:PrintToPlayer("The Naraka recovers "..mobhp.." HP.", 0xD);
 -- mob:setHP(1);
 mob:setLocalVar("FomorDespawn", os.time(t) + 2);
 end
end;


-----------------------------------
-- onMobDeath
-----------------------------------

function onMobDeath(mob, killer, ally)
end;