---------------------------------------------------
-- Ability: Afflatus Solace
-- Inspires Kupipi to draw strength from the healing spells she casts.
-- Obtained: Level 40
-- Recast Time: 1:00
-- Duration: 2 hours
---------------------------------------------------

require("/scripts/globals/settings");
require("/scripts/globals/status");
--require("/scripts/globals/monstertpmoves");

---------------------------------------------------

function onMobSkillCheck(target,mob,skill)
    return 0;
end;

function onPetAbility(target, pet, skill)
    pet:delStatusEffect(EFFECT_AFFLATUS_SOLACE);
    pet:delStatusEffect(EFFECT_AFFLATUS_MISERY);
    pet:addStatusEffect(EFFECT_AFFLATUS_SOLACE,8,0,7200);
	return EFFECT_AFFLATUS_SOLACE;

end;
