-----------------------------------
-- Area: 
-- NPC: Velosareon
-----------------------------------

require("scripts/globals/titles");
require("scripts/globals/dynamis");

-----------------------------------
-- onMobSpawn Action
-----------------------------------

function onMobSpawn(mob)
-- mob:addMod(MOD_EVA,50);






end;

-----------------------------------
-- onMobEngaged
-----------------------------------

function onMobEngaged(mob,target)

-- mob:addMod(MOD_HPP,-30);
-- mob:setMod(MOD_ATT,-100);
mob:setMod(MOD_EVA,230);
mob:setMod(MOD_VIT,60);
mob:setMod(MOD_STR,60);
mob:setMod(MOD_DEF,100);
mob:setMod(MOD_ATT,100);
mob:setMod(MOD_INT,45);
local mobdef = mob:getStat(MOD_DEF);
local mobatt = mob:getStat(MOD_ATT);
print(mobatt);
print(mobdef);


end;






-----------------------------------
-- onMobDeath
-----------------------------------

function onMobDeath(mob,killer)

end;