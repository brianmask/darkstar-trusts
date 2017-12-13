---------------------------------------------------
-- Meditate
-- Trust: Ayame
-- 
---------------------------------------------------

require("/scripts/globals/settings");
require("/scripts/globals/status");
--require("/scripts/globals/monstertpmoves");

---------------------------------------------------

function onMobSkillCheck(target,mob,skill)
    return 0, 0;
end;

function onPetAbility(target, pet, skill)
    local amount = 20;


    local tick = 15;
    local extratick = 0;

    -- Todo: change these item checks into a modifier.

    if (extratick == 1) then
        extratick = math.random(1,2);
    elseif (extratick == 2) then
        extratick = math.random(2,3);
    end

    tick = tick + (extratick * 3);
    pet:addStatusEffectEx(EFFECT_MEDITATE,0,amount,3,tick);
    return EFFECT_MEDITATE;
end;
