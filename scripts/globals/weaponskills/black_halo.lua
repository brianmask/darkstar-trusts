-----------------------------------
-- Black Halo
-- Club weapon skill
-- Skill level: 230
-- In order to obtain Black Halo, the quest Orastery Woes must be completed.
-- Delivers a two-hit attack. Damage varies with TP.
-- Will stack with Sneak Attack.
-- Aligned with the Shadow Gorget, Thunder Gorget & Breeze Gorget.
-- Aligned with the Shadow Belt, Thunder Belt & Breeze Belt.
-- Element: None
-- Modifiers: STR:30% ; MND:50%
-- 100%TP    200%TP    300%TP
-- 1.50      2.50      3.00
-----------------------------------

require("scripts/globals/status");
require("scripts/globals/settings");
require("scripts/globals/weaponskills");
require("scripts/globals/quests");
-----------------------------------

function onUseWeaponSkill(player, target, wsID)

	local params = {};
	params.numHits = 2;
	params.ftp100 = 1.5; params.ftp200 = 2.5; params.ftp300 = 3;
	params.str_wsc = 0.3; params.dex_wsc = 0.0; params.vit_wsc = 0.0; params.agi_wsc = 0.0; params.int_wsc = 0.0; params.mnd_wsc = 0.5; params.chr_wsc = 0.0;
	params.crit100 = 0.0; params.crit200 = 0.0; params.crit300 = 0.0;
	params.canCrit = false;
	params.acc100 = 0.0; params.acc200= 0.0; params.acc300= 0.0;
	params.atkmulti = 1;

	if (USE_ADOULIN_WEAPON_SKILL_CHANGES == true) then
		params.ftp100 = 3.0; params.ftp200 = 7.25; params.ftp300 = 9.75;
		params.mnd_wsc = 0.7;
	end

	local wsnm = player:getVar("BLACK_HALO");
	local unlock = 0;
    if (player:hasCompleteQuest(WINDURST,ORASTERY_WOES) == true) then -- Black Halo Quest is done
	unlock = 1;
	elseif (player:getQuestStatus(WINDURST,ORASTERY_WOES) == QUEST_ACCEPTED and wsnm > 1) then -- Black Halo Quest Active
	wsnm = wsnm - 1;
	if (wsnm < 1) then
	wsnm = 1;
	end
	player:setVar("BLACK_HALO",wsnm);
	elseif (player:getQuestStatus(WINDURST,ORASTERY_WOES) == QUEST_ACCEPTED and wsnm <= 1) then -- Black Halo powered up
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
	
	local damage, criticalHit, tpHits, extraHits = doPhysicalWeaponskill(player, target, params);
		if (player:getEquipID(SLOT_MAIN) == 18870 and player:getVar("WHMHAFight") == 2) then
	damage = damage * WEAPON_SKILL_POWER * unlock * 1.10;
	else
	damage = damage * WEAPON_SKILL_POWER * unlock;
	end
	return tpHits, extraHits, criticalHit, damage;
    
end
