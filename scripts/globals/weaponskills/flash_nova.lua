-----------------------------------
-- Skill level: 290
-- Delivers light elemental damage. Additional effect: Flash. Chance of effect varies with TP.
-- Generates a significant amount of Enmity.
-- Does not stack with Sneak Attack
-- Aligned with Aqua Gorget.
-- Aligned with Aqua Belt.
-- Properties:
-- Element: Light
-- Skillchain Properties:Induration Reverberation
-- Modifiers: STR:30% MND:30%
-- Damage Multipliers by TP:
--     100%TP	200%TP	 300%TP
--      3.00	 3.00	 3.00
-----------------------------------
require("scripts/globals/magic");
require("scripts/globals/status");
require("scripts/globals/settings");
require("scripts/globals/weaponskills");
-----------------------------------

function onUseWeaponSkill(player, target, wsID)

	local params = {};
	params.ftp100 = 3; params.ftp200 = 3; params.ftp300 = 3;
	params.str_wsc = 0.3; params.dex_wsc = 0.0; params.vit_wsc = 0.0; params.agi_wsc = 0.0; params.int_wsc = 0.0; params.mnd_wsc = 0.3; params.chr_wsc = 0.0;
	params.ele = ELE_LIGHT;
	params.skill = SKILL_CLB;
	params.includemab = true;

	if (USE_ADOULIN_WEAPON_SKILL_CHANGES == true) then
		params.str_wsc = 0.5; params.mnd_wsc = 0.5;
	end

	local damage, criticalHit, tpHits, extraHits = doMagicWeaponskill(player, target, params);
	if((player:getEquipID(SLOT_MAIN) == 18870)) then
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
