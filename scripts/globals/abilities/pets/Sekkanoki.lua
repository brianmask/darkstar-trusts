---------------------------------------------------
-- Sekkanoki
-- Trust: Ayame
-- All weaponskills consume 1000% TP regardless
---------------------------------------------------

require("/scripts/globals/settings");
require("/scripts/globals/status");
--require("/scripts/globals/monstertpmoves");

---------------------------------------------------

function onMobSkillCheck(target,mob,skill)
    return 0;
end;

function onPetAbility(target, pet, skill)
    pet:delStatusEffect(EFFECT_SEKKANOKI);
    pet:addStatusEffect(EFFECT_SEKKANOKI,1,0,60);
    return EFFECT_SEKKANOKI;
end;
