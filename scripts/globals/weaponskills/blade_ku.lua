-----------------------------------
-- Blade Ku
-- Katana weapon skill
-- Skill level: N/A
-- Description: Delivers a five-hit attack. params.accuracy varies with TP.
-- In order to obtain Blade: Ku, the quest Bugi Soden must be completed.
-- Will stack with Sneak Attack.
-- Aligned with the Shadow Gorget, Soil Gorget & Light Gorget.
-- Aligned with the Shadow Belt, Soil Belt & Light Belt.
-- Skillchain Properties: Gravitation/Transfixion
-- Modifiers: STR:10% ; DEX:10%
-- 100%TP    200%TP    300%TP
-- 1.00      1.00      1.00
--
--         params.acc
-- 100%TP    200%TP    300%TP
-- ??        ??        ??
-----------------------------------
require("scripts/globals/status");
require("scripts/globals/settings");
require("scripts/globals/weaponskills");
require("scripts/globals/quests");
-----------------------------------

function onUseWeaponSkill(player, target, wsID)

	local params = {};
	params.numHits = 5;
	params.ftp100 = 1; params.ftp200 = 1; params.ftp300 = 1;
	params.str_wsc = 0.1; params.dex_wsc = 0.1; params.vit_wsc = 0.0; params.agi_wsc = 0.0; params.int_wsc = 0.0; params.mnd_wsc = 0.0; params.chr_wsc = 0.0;
	params.crit100 = 0.0; params.crit200 = 0.0; params.crit300 = 0.0;
	params.canCrit = false;
	params.acc100 = 0.8; params.acc200= 0.9; params.acc300= 1.0;
	params.atkmulti = 1;

	if (USE_ADOULIN_WEAPON_SKILL_CHANGES == true) then
		params.ftp100 = 2.25; params.ftp200 = 2.25; params.ftp300 = 2.25;
		params.str_wsc = 0.5; params.dex_wsc = 0.5;
	end

	local damage, criticalHit, tpHits, extraHits = doPhysicalWeaponskill(player, target, params);
	
    local wsnm = player:getVar("BLADE_KU");
	local unlock = 0;
    if (player:hasCompleteQuest(OUTLANDS,BUGI_SODEN) == true) then -- Blade Ku Quest is done
	unlock = 1;
	elseif (player:getQuestStatus(OUTLANDS,BUGI_SODEN) == QUEST_ACCEPTED and wsnm > 1) then -- Blade Ku Quest Active
	unlock = 0.05;
	wsnm = wsnm - 1;
	if (wsnm < 1) then
	wsnm = 1;
	end
	player:setVar("BLADE_KU",wsnm);
	elseif (player:getQuestStatus(OUTLANDS,BUGI_SODEN) == QUEST_ACCEPTED and wsnm <= 1) then -- Blade Ku powered up
	unlock = 0.30;
	else
	unlock = 0.05;
	end

	if (wsnm > 75) then
	player:PrintToPlayer("Your form is off...", 0x1C);	
	elseif (wsnm > 50) then
	player:PrintToPlayer("Your form has improved slightly", 0x1C);	
	elseif (wsnm > 25) then
	player:PrintToPlayer("Your form is getting better", 0x1C);
	elseif (wsnm >= 2) then
	player:PrintToPlayer("Your form is has improved greatly!", 0x1C);	
	elseif (wsnm == 1) then	
	player:PrintToPlayer("Your form is excellent!", 0x1C);
	end	
	
	if (player:getEquipID(SLOT_MAIN) == 19275 and player:getVar("NINHAFight") == 2) then
	damage = damage * WEAPON_SKILL_POWER * unlock * 1.10;
	else
	damage = damage * WEAPON_SKILL_POWER * unlock;
	end
	return tpHits, extraHits, criticalHit, damage;

end