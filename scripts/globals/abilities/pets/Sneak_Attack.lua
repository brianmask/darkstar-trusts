---------------------------------------------------
-- Sneak Attack
-- Trust: Nanaa Mihgo
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
 pet:addStatusEffect(EFFECT_TRUST_SNEAK_ATTACK,1,0,60);
 return EFFECT_SNEAK_ATTACK;

end;
