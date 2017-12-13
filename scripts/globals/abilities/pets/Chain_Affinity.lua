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
    pet:addStatusEffect(EFFECT_CHAIN_AFFINITY,1,0,30);

    return EFFECT_CHAIN_AFFINITY;
end;
