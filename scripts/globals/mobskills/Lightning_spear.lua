---------------------------------------------------
-- Thunderstorm
-- Ramuh deals lightning damage to target.
---------------------------------------------------

require("scripts/globals/settings");
require("scripts/globals/status");
require("scripts/globals/monstertpmoves");

---------------------------------------------------

function onMobSkillCheck(target,mob,skill)
    return 0;
end;

function onMobWeaponSkill(target, mob, skill)

    local dmgmod = MobBreathMove(mob, target, 0.3, 1, ELE_THUNDER, 500);

    local dmg = MobFinalAdjustments(dmgmod,mob,skill,target,MOBSKILL_BREATH,MOBPARAM_THUNDER,MOBPARAM_IGNORE_SHADOWS);
    target:delHP(dmg);
    return dmg;

end