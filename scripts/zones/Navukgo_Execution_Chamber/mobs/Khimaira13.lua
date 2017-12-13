-----------------------------------
-- Area: Navukgo Execution Chamber
-- MOB: Khimaira 13
-----------------------------------

require("scripts/globals/allyassist");

-----------------------------------
-- onMobInitialize Action
-----------------------------------

function onMobInitialize(mob)
end;

function onMobSpawn(mob)
  mob:addMod(MOD_DEF, -75);
 -- mob:addMod(MOD_VIT, 30);
 mob:addMod(MOD_INT, 20);
 -- mob:addMod(MOD_AGI, 40);
 mob:addMod(MOD_MATT, -30);
end;

-----------------------------------
-- onMobEngaged Action
-----------------------------------

function onMobEngaged(mob,target)
end;

-----------------------------------
-- onMobFight Action
-----------------------------------

function onMobFight(mob,target)
    local assist = mob:getLocalVar("assist");

    if (assist == 0) then
        startAllyAssist(mob);
        mob:setLocalVar("assist", 1);
    end
end;

-----------------------------------
-- onSpellPrecast
-----------------------------------

function onSpellPrecast(mob, spell)
end;

-----------------------------------
-- onMobDeath
-----------------------------------

function onMobDeath(mob, player, isKiller)
end;

-----------------------------------
-- onEventUpdate
-----------------------------------

function onEventUpdate(player,csid,option)
    -- printf("updateCSID: %u",csid);
    -- printf("RESULT: %u",option);
end;

-----------------------------------
-- onEventFinish
-----------------------------------

function onEventFinish(player,csid,option,target)
    -- printf("finishCSID: %u",csid);
    -- printf("RESULT: %u",option);
	
end;