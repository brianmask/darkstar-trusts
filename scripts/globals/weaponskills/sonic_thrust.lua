-----------------------------------
-- Sonic Thrust
-- Polearm weapon skill
-- Skill Level: 300
-- Delivers an area attack. Damage varies with TP.
-- Will stack with Sneak Attack.
-- Element: None
-- Modifiers: STR:40% ; DEX:40%
-- 100%TP    200%TP    300%TP
-- 3.00       3.7       4.50
-----------------------------------
require("scripts/globals/status");
require("scripts/globals/settings");
require("scripts/globals/weaponskills");
-----------------------------------

function onUseWeaponSkill(player, target, wsID)

	local params = {};
	params.numHits = 1;
	params.ftp100 = 3; params.ftp200 = 3.25; params.ftp300 = 3.5;
	params.str_wsc = 0.3; params.dex_wsc = 0.3; params.vit_wsc = 0.0; params.agi_wsc = 0.0; params.int_wsc = 0.0; params.mnd_wsc = 0.0; params.chr_wsc = 0.0;
	params.crit100 = 0.0; params.crit200 = 0.0; params.crit300 = 0.0;
	params.canCrit = false;
	params.acc100 = 0.0; params.acc200= 0.0; params.acc300= 0.0;
	params.atkmulti = 1;

	if (USE_ADOULIN_WEAPON_SKILL_CHANGES == true) then
		params.ftp200 = 3.7; params.ftp300 = 4.5;
		params.str_wsc = 0.4; params.dex_wsc = 0.4;
	end

	local damage, criticalHit, tpHits, extraHits = doPhysicalWeaponskill(player, target, params);
	if((player:getEquipID(SLOT_MAIN) == 19303)) then
		if(damage > 0) then
			if(player:getTP() >= 100 and player:getTP() < 200 and ((player:hasStatusEffect(EFFECT_AFTERMATH_LV2) == false) and (player:hasStatusEffect(EFFECT_AFTERMATH_LV3) == false))) then
				player:addStatusEffect(EFFECT_AFTERMATH_LV1, 5, 0, 30, 0, 13);
			elseif(player:getTP() >= 200 and player:getTP() < 300 and (player:hasStatusEffect(EFFECT_AFTERMATH_LV3) == false)) then
				player:addStatusEffect(EFFECT_AFTERMATH_LV2, 7, 0, 45, 0, 13);
			elseif(player:getTP() == 300) then
				player:addStatusEffect(EFFECT_AFTERMATH_LV3, 10, 0, 60, 0, 13);
			end		
		
		end
	end		
	damage = damage * WEAPON_SKILL_POWER
	return tpHits, extraHits, criticalHit, damage;

end
