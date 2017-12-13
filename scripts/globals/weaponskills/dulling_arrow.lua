-----------------------------------
-- Dulling Arrow
-- Archery weapon skill
-- Skill level: 80
-- Lowers enemy's INT. Chance of params.critical varies with TP.
-- Aligned with the Flame Gorget & Light Gorget.
-- Aligned with the Flame Belt & Light Belt.
-- Element: None
-- Modifiers: STR:16% ; AGI:25%
-- 100%TP    200%TP    300%TP
-- 1.00      1.00      1.00
-----------------------------------

require("scripts/globals/status");
require("scripts/globals/settings");
require("scripts/globals/weaponskills");
-----------------------------------

function onUseWeaponSkill(player, target, wsID)

	local params = {};
	params.numHits = 1;
	params.ftp100 = 1; params.ftp200 = 1; params.ftp300 = 1;
	params.str_wsc = 0.16; params.dex_wsc = 0.0; params.vit_wsc = 0.0; params.agi_wsc = 0.25; params.int_wsc = 0.0; params.mnd_wsc = 0.0; params.chr_wsc = 0.0;
	params.crit100 = 0.25; params.crit200 = 0.40; params.crit300 = 0.70;
	params.canCrit = true;
	params.acc100 = 0.0; params.acc200= 0.0; params.acc300= 0.0;
	params.atkmulti = 1;

	if (USE_ADOULIN_WEAPON_SKILL_CHANGES == true) then
		params.str_wsc = 0.2; params.agi_wsc = 0.5;
	end

	local damage, tpHits, extraHits = doRangedWeaponskill(player, target, params);
	damage = damage * WEAPON_SKILL_POWER
	
		 if (damage > 0 and target:getStatusEffect(EFFECT_INT_DOWN) == nil) then
        local intdown = math.floor(player:getMainLvl()/10) + 3;
        local duration = (30 * (player:getTP() / 100));
        target:addStatusEffect(EFFECT_INT_DOWN, intdown, 3, duration, FLAG_ERASBLE);
    end
	
	
	
	
	return tpHits, extraHits, criticalHit, damage;

end
