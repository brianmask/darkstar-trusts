-----------------------------------
-- Burning Blade
-- Sword weapon skill
-- Skill Level: 30
-- Desription: Deals Fire elemental damage to enemy. Damage varies with TP.
-- Aligned with the Flame Gorget.
-- Aligned with the Flame Belt.
-- Element: Fire
-- Modifiers: STR:40% ; INT:40%
-- 100%TP    200%TP    300%TP
-- 1.25      2.00      2.50
-----------------------------------
require("scripts/globals/magic");
require("scripts/globals/status");
require("scripts/globals/settings");
require("scripts/globals/weaponskills");
-----------------------------------

function onUseWeaponSkill(player, target, wsID)

	local params = {};
	params.ftp100 = 1.25; params.ftp200 = 2; params.ftp300 = 2.5;
	params.str_wsc = 0.4; params.dex_wsc = 0.0; params.vit_wsc = 0.0; params.agi_wsc = 0.0; params.int_wsc = 0.4; params.mnd_wsc = 0.0; params.chr_wsc = 0.0;
	params.ele = ELE_FIRE;
	params.skill = SKILL_SWD;
	params.includemab = true;

	if (USE_ADOULIN_WEAPON_SKILL_CHANGES == true) then
		params.ftp200 = 2.1; params.ftp300 = 3.4;
		params.str_wsc = 0.4; params.int_wsc = 0.4;
	end

	local damage, criticalHit, tpHits, extraHits = doMagicWeaponskill(player, target, params);
		damage = damage * WEAPON_SKILL_POWER
	
	 if (damage > 0 and target:getStatusEffect(EFFECT_BURN) == nil) then
        local DOT = math.floor(player:getMainLvl()/10) + 2;
        local duration = (30 * (player:getTP() / 100));
        target:addStatusEffect(EFFECT_BURN, DOT, 3, duration, FLAG_ERASBLE);
    end
	
	

	return tpHits, extraHits, criticalHit, damage;

end
