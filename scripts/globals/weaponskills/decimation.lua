-----------------------------------
-- Decimation
-- Axe weapon skill
-- Skill level: 240
-- In order to obtain Decimation, the quest Axe the Competition must be completed.
-- Delivers a three-hit attack. params.accuracy varies with TP.
-- Will stack with Sneak Attack.
-- Aligned with the Flame Gorget, Light Gorget & Aqua Gorget.
-- Aligned with the Flame Belt, Light Belt & Aqua Belt.
-- Element: None
-- Modifiers: STR:50%
-- 100%TP    200%TP    300%TP
-- 1.25      1.25      1.25
-----------------------------------

require("scripts/globals/status");
require("scripts/globals/settings");
require("scripts/globals/weaponskills");
require("scripts/globals/quests");
-----------------------------------

function onUseWeaponSkill(player, target, wsID)

	local params = {};
	params.numHits = 3;
	params.ftp100 = 1.25; params.ftp200 = 1.25; params.ftp300 = 1.25;
	params.str_wsc = 0.5; params.dex_wsc = 0.0; params.vit_wsc = 0.0; params.agi_wsc = 0.0; params.int_wsc = 0.0; params.mnd_wsc = 0.0; params.chr_wsc = 0.0;
	params.crit100 = 0.0; params.crit200 = 0.0; params.crit300 = 0.0;
	params.canCrit = false;
	params.acc100 = 0.8; params.acc200= 0.9; params.acc300= 1;
	params.atkmulti = 1;

	if (USE_ADOULIN_WEAPON_SKILL_CHANGES == true) then
		params.ftp100 = 1.75; params.ftp200 = 1.75; params.ftp300 = 1.75;
	end

	local damage, criticalHit, tpHits, extraHits = doPhysicalWeaponskill(player, target, params);
	
	local wsnm = player:getVar("DECIMATION");
	local unlock = 0;
    if (player:hasCompleteQuest(JEUNO,AXE_THE_COMPETITION) == true) then -- Decimation Quest is done
	unlock = 1;
	elseif (player:getQuestStatus(JEUNO,AXE_THE_COMPETITION) == true and wsnm > 1) then -- Decimation Quest Active
	wsnm = wsnm - 1;
	if (wsnm < 1) then
	wsnm = 1;
	end
	player:setVar("DECIMATION",wsnm);
	elseif (player:getQuestStatus(JEUNO,AXE_THE_COMPETITION) == true and wsnm <= 1) then -- Decimation powered up
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
	
	if (player:getEquipID(SLOT_MAIN) == 17966 and player:getVar("BSTHAFight") == 2) then
	damage = damage * WEAPON_SKILL_POWER * unlock * 1.10;
	else
	damage = damage * WEAPON_SKILL_POWER * unlock;
	end
	return tpHits, extraHits, criticalHit, damage;

end
