-----------------------------------
-- Sanguine Blade
-- Sword weapon skill
-- Skill Level: 300
-- Drains a percentage of damage dealt to HP varies with TP.
-- Will not stack with Sneak Attack.
-- Not aligned with any "elemental gorgets" or "elemental belts" due to it's absence of Skillchain properties.
-- Element: Dark
-- Modifiers: STR:30% ; MND:50%
-- 100%TP    200%TP    300%TP
-- 2.75      2.75      2.75
-- HP Drained by TP:
-- 100%TP    200%TP    300%TP
-- 50%       75%    100%
-----------------------------------
require("scripts/globals/magic");
require("scripts/globals/status");
require("scripts/globals/settings");
require("scripts/globals/weaponskills");
-----------------------------------

function onUseWeaponSkill(player, target, wsID)
    local tp = player:getTP();
    local drain = 0;

    if (tp >= 100 and tp <=199) then
        drain = 50;
    elseif (tp >= 200 and tp <= 299) then
        drain = 75;
    elseif (tp == 300) then
        drain = 100;
    end

    local params = {};
    params.ftp100 = 2.75; params.ftp200 = 2.75; params.ftp300 = 2.75;
    params.str_wsc = 0.3; params.dex_wsc = 0.0; params.vit_wsc = 0.0; params.agi_wsc = 0.0; params.int_wsc = 0.0; params.mnd_wsc = 0.5; params.chr_wsc = 0.0;
    params.ele = ELE_DARK;
    params.skill = SKILL_SWD;
    params.includemab = true;

    local damage, criticalHit, tpHits, extraHits = doMagicWeaponskill(player, target, params);
	if((player:getEquipID(SLOT_MAIN) == 17761) or (player:getEquipID(SLOT_MAIN) == 17762) or (player:getEquipID(SLOT_MAIN) == 17763)) then
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

    if (target:isUndead() == false) then
        player:addHP((damage/100) * drain);
    end

    return tpHits, extraHits, criticalHit, damage;
end
