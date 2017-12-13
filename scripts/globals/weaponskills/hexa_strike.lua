-----------------------------------
-- Hexa Strike
-- Club weapon skill
-- Skill level: 220
-- Delivers a six-hit attack. Chance of params.critical varies with TP.
-- Will stack with Sneak Attack.
-- Aligned with the Flame Gorget & Light Gorget.
-- Aligned with the Flame Belt & Light Belt.
-- Element: None
-- Modifiers: STR:20% ; MND:20%
-- 100%TP    200%TP    300%TP
-- 1.00      1.00      1.00
-----------------------------------

require("scripts/globals/status");
require("scripts/globals/settings");
require("scripts/globals/weaponskills");
-----------------------------------

function onUseWeaponSkill(player, target, wsID)

	local params = {};
	params.numHits = 6;
	params.ftp100 = 1; params.ftp200 = 1; params.ftp300 = 1;
	params.str_wsc = 0.2; params.dex_wsc = 0.0; params.vit_wsc = 0.0; params.agi_wsc = 0.0; params.int_wsc = 0.0; params.mnd_wsc = 0.2; params.chr_wsc = 0.0;
	params.crit100 = 0.3; params.crit200 = 0.5; params.crit300 = 0.7;
	params.canCrit = true;
	params.acc100 = 0.0; params.acc200= 0.0; params.acc300= 0.0;
	params.atkmulti = 1.33;

	if (USE_ADOULIN_WEAPON_SKILL_CHANGES == true) then
		params.ftp100 = 1.125; params.ftp200 = 1.125; params.ftp300 = 1.125;
		params.str_wsc = 0.3; params.mnd_wsc = 0.3;
	end

	local damage, criticalHit, tpHits, extraHits = doPhysicalWeaponskill(player, target, params);
	
	if ((player:getEquipID(SLOT_MAIN) == 17422) and (player:getVar("HA_WHM_FIGHT") == 3)) then
		if (damage > 0) then
            if (player:getTP() >= 100 and player:getTP() <200) then
                player:addStatusEffect(EFFECT_AFTERMATH, 28, 0, 30, 0, 15);
            elseif (player:getTP() >= 200 and player:getTP() <300) then
                player:addStatusEffect(EFFECT_AFTERMATH, 28, 0, 45, 0, 15);
            elseif (player:getTP() == 300) then
                player:addStatusEffect(EFFECT_AFTERMATH, 28, 0, 60, 0, 15);
            end
        end
    end
	
	
	damage = damage * WEAPON_SKILL_POWER
	return tpHits, extraHits, criticalHit, damage;

end
