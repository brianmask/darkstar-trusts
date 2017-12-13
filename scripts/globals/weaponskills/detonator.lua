-----------------------------------
-- Detonator
-- Marksmanship weapon skill
-- Skill Level: 250
-- Delivers a single-hit attack. Damage varies with TP.
-- In order to obtain Detonator, the quest Shoot First, Ask Questions Later must be completed.
-- Despite the lack of a STR weaponskill mod, STR is still the most potent stat for increasing this weaponskill's damage to the point at which fSTR2 is capped.
-- Aligned with the Flame Gorget & Light Gorget.
-- Aligned with the Flame Belt & Light Belt.
-- Element: None
-- Modifiers: AGI:30%
-- 100%TP    200%TP    300%TP
-- 1.50      2.00      2.50
-----------------------------------

require("scripts/globals/status");
require("scripts/globals/settings");
require("scripts/globals/weaponskills");
require("scripts/globals/quests");
-----------------------------------

function onUseWeaponSkill(player, target, wsID)

	local params = {};
	params.numHits = 1;
	params.ftp100 = 1.5; params.ftp200 = 2; params.ftp300 = 2.5;
	params.str_wsc = 0.0; params.dex_wsc = 0.0; params.vit_wsc = 0.0; params.agi_wsc = 0.3; params.int_wsc = 0.0; params.mnd_wsc = 0.0; params.chr_wsc = 0.0;
	params.crit100 = 0.0; params.crit200 = 0.0; params.crit300 = 0.0;
	params.canCrit = false;
	params.acc100 = 0.0; params.acc200= 0.0; params.acc300= 0.0;
	params.atkmulti = 1;

	if (USE_ADOULIN_WEAPON_SKILL_CHANGES == true) then
		params.ftp100 = 1.5; params.ftp200 = 2.5; params.ftp300 = 5.0;
		params.agi_wsc = 0.7;
	end

	local damage, tpHits, extraHits = doRangedWeaponskill(player, target, params);
	
	local wsnm = player:getVar("DETONATOR");
	local unlock = 0;
    if (player:hasCompleteQuest(BASTOK,SHOOT_FIRST_ASK_QUESTIONS_LATER) == true) then -- Detonator Quest is done
	unlock = 1;
	elseif (player:getQuestStatus(BASTOK,SHOOT_FIRST_ASK_QUESTIONS_LATER) == QUEST_ACCEPTED and wsnm > 1) then -- Detonator Quest Active
	wsnm = wsnm - 1;
	if (wsnm < 1) then
	wsnm = 1;
	end
	player:setVar("DETONATOR",wsnm);
	elseif (player:getQuestStatus(BASTOK,SHOOT_FIRST_ASK_QUESTIONS_LATER) == QUEST_ACCEPTED and wsnm <= 1) then -- Detonator powered up
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
	
	if (player:getEquipID(SLOT_MAIN) == 18737 and player:getVar("CORHAFight") == 2) then
	damage = damage * WEAPON_SKILL_POWER * unlock * 1.10;
	else
	damage = damage * WEAPON_SKILL_POWER * unlock;
	end
	return tpHits, extraHits, criticalHit, damage;

end
