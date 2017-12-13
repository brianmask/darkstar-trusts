-- Aeolian Edge
-- Dagger weapon skill
-- Delivers an area attack that deals wind elemental damage. Damage varies with TP.
-- Skill Level: 290
-- Aligned with the Breeze Gorget, Soil Gorget & Thunder Gorget.
-- Aligned with the Breeze Belt, Soil Belt & Thunder Belt.
-- Element: Wind
-- Skillchain Properties: Impaction / Scission / Detonation
-- Modifiers: DEX:28%; INT:28%
-- 100%TP    200%TP    300%TP
-- 2.75      3.50       4
-----------------------------------
require("scripts/globals/magic");
require("scripts/globals/status");
require("scripts/globals/settings");
require("scripts/globals/weaponskills");
-----------------------------------

function onUseWeaponSkill(player, target, wsID)

	local params = {};
	params.ftp100 = 2.75; params.ftp200 = 3.50; params.ftp300 = 4;
	params.str_wsc = 0.0; params.dex_wsc = 0.28; params.vit_wsc = 0.0; params.agi_wsc = 0.0; params.int_wsc = 0.28; params.mnd_wsc = 0.0; params.chr_wsc = 0.0;
	params.ele = ELE_WIND;
	params.skill = SKILL_DAG;
	params.includemab = true;

	if (USE_ADOULIN_WEAPON_SKILL_CHANGES == true) then
		params.dex_wsc = 0.4;params.int_wsc = 0.4;
	end

	local damage, criticalHit, tpHits, extraHits = doMagicWeaponskill(player, target, params);
	if((player:getEquipID(SLOT_MAIN) == 19115) or (player:getEquipID(SLOT_MAIN) == 19116) or (player:getEquipID(SLOT_MAIN) == 19117)) then
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
