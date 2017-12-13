---------------------------------------------------
-- Third Eye
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
    pet:addStatusEffect(EFFECT_THIRD_EYE,0,0,30); --power keeps track of procs
    return EFFECT_THIRD_EYE;
end;
