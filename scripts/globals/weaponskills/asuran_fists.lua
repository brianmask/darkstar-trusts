-----------------------------------
-- Asuran Fists
-- Hand-to-Hand weapon skill
-- Skill Level: 250
-- Delivers an eightfold attack. params.accuracy varies with TP.
-- In order to obtain Asuran Fists, the quest The Walls of Your Mind must be completed.
-- Due to the 95% params.accuracy cap there is only a 66% chance of all 8 hits landing, so approximately a one third chance of missing some of the hits at the cap.
-- Will stack with Sneak Attack.
-- Aligned with the Shadow Gorget, Soil Gorget & Flame Gorget.
-- Aligned with the Shadow Belt, Soil Belt & Flame Belt.
-- Element: None
-- Modifiers: STR:10% ; VIT:10%
-- 100%TP    200%TP    300%TP
-- 1.00      1.00      1.00
-----------------------------------

require("scripts/globals/status");
require("scripts/globals/settings");
require("scripts/globals/weaponskills");
require("scripts/globals/quests");
-----------------------------------

function onUseWeaponSkill(player, target, wsID)

	local params = {};
	params.numHits = 8;
	params.ftp100 = 1; params.ftp200 = 1; params.ftp300 = 1;
	params.str_wsc = 0.1; params.dex_wsc = 0.0; params.vit_wsc = 0.1; params.agi_wsc = 0.0; params.int_wsc = 0.0; params.mnd_wsc = 0.0; params.chr_wsc = 0.0;
	params.crit100 = 0.0; params.crit200 = 0.0; params.crit300 = 0.0;
	params.canCrit = false;
	params.acc100 = 0.8; params.acc200= 0.9; params.acc300= 1;
	params.atkmulti = 1;

	if (USE_ADOULIN_WEAPON_SKILL_CHANGES == true) then
		params.str_wsc = 0.15; params.vit_wsc = 0.15;
	end

	local damage, criticalHit, tpHits, extraHits = doPhysicalWeaponskill(player, target, params);
	
	local wsnm = player:getVar("ASURAN_FISTS");
	local unlock = 0;
    if (player:hasCompleteQuest(BASTOK,THE_WALLS_OF_YOUR_MIND) == true) then -- Asuran Fists Quest is done
	unlock = 1;
	elseif (player:getQuestStatus(BASTOK,THE_WALLS_OF_YOUR_MIND) == QUEST_ACCEPTED and wsnm > 1) then -- Asuran Fists Quest Active
	unlock = 0.05;
	wsnm = wsnm - 1;
    if (wsnm < 1) then
	wsnm = 1;
	end
	player:setVar("ASURAN_FISTS",wsnm);
	elseif (player:getQuestStatus(BASTOK,THE_WALLS_OF_YOUR_MIND) == QUEST_ACCEPTED and wsnm <= 1) then -- Asuran Fists powered up
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
	
	damage = damage * WEAPON_SKILL_POWER * unlock
	return tpHits, extraHits, criticalHit, damage;

end
