-----------------------------------
-- Area: Salvage
--  MOB: Naraka
-----------------------------------

require("scripts/globals/status");

-----------------------------------
-- onMobInitialize Action
-----------------------------------

function onMobInitialize(mob)
end;

-----------------------------------
-- onMobSpawn Action
-----------------------------------

function onMobSpawn(mob)
end;

-----------------------------------
-- onMobFight Action
-----------------------------------


function onMobFight(mob, target)
end;


-----------------------------------
-- onWeaponskillHit
-----------------------------------
function onWeaponskillHit(mob, attacker, weaponskill)
local pos = mob:getPos();


SpawnMob(17637701):setPos(pos.x + 3, pos.y, pos.z);
attacker:PrintToPlayer("The Naraka sheds a part of its armor.", 0x15);
mob:delHP(10000);
GetMobByID(17637701):updateEnmity(attacker);
end;

-----------------------------------
-- onMobDeath
-----------------------------------

function onMobDeath(mob, killer, ally)
end;