-----------------------------------
-- Area: The Ashu Talif (The Black Coffin)
--  MOB: Ashu Talif Crew
-----------------------------------

require("scripts/globals/instance");
local TheAshuTalif = require("scripts/zones/The_Ashu_Talif/IDs");

-----------------------------------
-- onMobSpawn Action
-----------------------------------

function onMobSpawn(mob)
    mob:setUnkillable(false);
	mob:untargetable(false); 

end;

-----------------------------------
-- OnMobFight Action
-----------------------------------

function onMobFight(mob, target)
    -- The captain gives up at <= 20% HP. Everyone disengages
    local instance = target:getInstance();
    if (mob:getHPP() <= 20 and instance:completed() == false) then
	    mob:addStatusEffect(EFFECT_TERROR,1,0,120);
		mob:untargetable(true); 

		
	    printf("Should be done");
		mob:setHP(0);

        mob:setPos(0,-28,-7);
		instance:complete();
    end


 
end;

-----------------------------------
-- onMobRoam Action
-----------------------------------

function onMobRoam(mob)
    local jumped = mob:getLocalVar("jump");
    local ready = mob:getLocalVar("ready");
mob:untargetable(false); 
    -- Becomes ready when the Crew is engaged. Jump down!


        mob:setLocalVar("jump", 1);
    

end;

-----------------------------------
-- onMobEngaged Action
-----------------------------------

function onMobEngaged(mob,target)
end;

-----------------------------------
-- onMobDisengage Action
-----------------------------------

function onMobDisengage(mob,target)
end;

-----------------------------------
-- onMobDeath
-----------------------------------

function onMobDeath(mob, killer)
  printf("Mob Died");
	
end;

-----------------------------------
-- onMobDespawn
-----------------------------------

function onMobDespawn(mob)

end;
