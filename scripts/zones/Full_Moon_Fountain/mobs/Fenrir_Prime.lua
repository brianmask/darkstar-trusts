-----------------------------------
-- Area: Full Moon Fountain
-- NPC:  Fenrir
-- Moonlit Path BCNM Fight
-----------------------------------

require("scripts/globals/titles");

-----------------------------------
-- onMobSpawn Action
-----------------------------------

function onMobSpawn(mob)
mob:setLocalVar("astralflows",1);
end;



function onMobFight(mob, target)

local astralFlows = mob:getLocalVar("astralflows");
local afTrigger = math.random(25,50);



if (mob:getHPP() <= afTrigger) and (astralFlows == 1) then
mob:useMobAbility(582);
mob:setLocalVar("astralflows",2);
end




end;