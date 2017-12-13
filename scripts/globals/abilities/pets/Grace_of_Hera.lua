---------------------------------------------------
-- Benediction
---------------------------------------------------

require("scripts/globals/settings");
require("scripts/globals/status");
require("scripts/globals/monstertpmoves");

---------------------------------------------------

function onAbilityCheck(player, target, ability)
    local level = player:getMainLvl() * 2;
    
    if(player:getMP()<level) then
       return 87,0;
    end
    
    return 0,0;
end;

function onPetAbility(target, pet, skill, master)
    target:eraseAllStatusEffect();
    local reghp = master:getSkillLevel(SKILL_SUM);
	local regen = (reghp / 10);
	local regain = (reghp / 69) + 1;
    local base = target:getMaxHP() - target:getHP();

    target:addHP(base);
    target:wakeUp();

    skill:setMsg(MSG_SELF_HEAL);
    target:addStatusEffect(EFFECT_REGEN, regen, 3, 60);
	target:addStatusEffect(EFFECT_REGAIN, regain, 3, 60);
    master:delMod(MOD_UFASTCAST, -300);	
    return base;
end;
