---------------------------------------------------
-- Last Resort
-- Trust: Zeid
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

    pet:addStatusEffectEx(EFFECT_TRUST_LAST_RESORT,EFFECT_LAST_RESORT,1,3,180);
    return EFFECT_LAST_RESORT;
end;
