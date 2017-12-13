-----------------------------------
-- Area: Dynamis Jeuno
-- NPC:  Vanguard Pitfighter

-----------------------------------
package.loaded["scripts/zones/Dynamis-Jeuno/TextIDs"] = nil;
-----------------------------------

require("scripts/globals/dynamis");
require("scripts/zones/Dynamis-Jeuno/TextIDs");

-----------------------------------
-- onMobSpawn Action
-----------------------------------

function onMobSpawn(mob)
	
end;

-----------------------------------
-- onMobEngaged
-----------------------------------

function onMobEngaged(mob,target)
    local hp = math.random(80,90)
    mob:setLocalVar("HundredFists", hp);
end;


-----------------------------------
-- onMobFight Action
-----------------------------------
function onMobFight(mob,target)

    local hf = mob:getLocalVar("HundredFists");


    if (mob:getHPP() < hf) then
        mob:useMobAbility(434);
		
        mob:setLocalVar("HundredFists", 0);
    end

end;




-----------------------------------
-- onMobDeath
-----------------------------------

function onMobDeath(mob,killer)

	
end;
