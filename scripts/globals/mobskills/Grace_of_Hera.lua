---------------------------------------------------
-- Benediction
---------------------------------------------------

require("scripts/globals/settings");
require("scripts/globals/status");
require("scripts/globals/monstertpmoves");

---------------------------------------------------

function onMobSkillCheck(target,mob,skill)

end;

function onMobWeaponSkill(target, mob, skill)
    mob:eraseAllStatusEffect();
    local reghp = mob:getHPP();
	local regen = reghp * 2;
    local maxHeal = mob:getMaxHP() - mob:getHP();

    mob:addHP(maxHeal);
    mob:wakeUp();

    skill:setMsg(MSG_SELF_HEAL);
	mob:addStatusEffect(EFFECT_REGEN, regen, 3, 60);

    return maxHeal;
end;
