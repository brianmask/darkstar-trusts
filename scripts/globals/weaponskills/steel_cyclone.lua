-----------------------------------
-- Steel Cyclone
-- Great Axe weapon skill
-- Skill level: 240
-- Delivers a single-hit attack. Damage varies with TP.
-- In order to obtain Steel Cyclone, the quest The Weight of Your Limits must be completed.
-- Will stack with Sneak Attack.
-- Aligned with the Breeze Gorget, Aqua Gorget & Snow Gorget.
-- Aligned with the Breeze Belt, Aqua Belt & Snow Belt.
-- Element: None
-- Modifiers: STR:60% ; VIT:60%
-- 100%TP    200%TP    300%TP
-- 1.50       2.5       4.00
-----------------------------------
require("scripts/globals/status");
require("scripts/globals/settings");
require("scripts/globals/weaponskills");
require("scripts/globals/quests");
-----------------------------------

function onUseWeaponSkill(player, target, wsID)

	local params = {};
	params.numHits = 1;
	params.ftp100 = 1.5; params.ftp200 = 1.75; params.ftp300 = 3;
	params.str_wsc = 0.5; params.dex_wsc = 0.0; params.vit_wsc = 0.5; params.agi_wsc = 0.0; params.int_wsc = 0.0; params.mnd_wsc = 0.0; params.chr_wsc = 0.0;
	params.crit100 = 0.0; params.crit200 = 0.0; params.crit300 = 0.0;
	params.canCrit = false;
	params.acc100 = 0.0; params.acc200= 0.0; params.acc300= 0.0;
	params.atkmulti = 1.66;

	if (USE_ADOULIN_WEAPON_SKILL_CHANGES == true) then
		params.ftp200 = 2.5; params.ftp300 = 4;
		params.str_wsc = 0.6; params.vit_wsc = 0.6;
		params.atkmulti = 1.5;
	end

	local damage, criticalHit, tpHits, extraHits = doPhysicalWeaponskill(player, target, params);
	
	local wsnm = player:getVar("STEEL_CYCLONE");
	local unlock = 0;
    if (player:hasCompleteQuest(BASTOK,THE_WEIGHT_OF_YOUR_LIMITS) == true) then -- Steel Cyclone Quest is done
	unlock = 1;
	elseif (player:getQuestStatus(BASTOK,THE_WEIGHT_OF_YOUR_LIMITS) == true and wsnm > 1) then -- Steel Cyclone Quest Active
	wsnm = wsnm - 1;
	if (wsnm < 1) then
	wsnm = 1;
	end
	player:setVar("STEEL_CYCLONE",wsnm);
	elseif (player:getQuestStatus(BASTOK,THE_WEIGHT_OF_YOUR_LIMITS) == true and wsnm <= 1) then -- Steel Cyclone powered up
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
	
	if (player:getEquipID(SLOT_MAIN) == 18505 and player:getVar("WARHAFight") == 2) then
	damage = damage * WEAPON_SKILL_POWER * unlock * 1.10
	else
	damage = damage * WEAPON_SKILL_POWER * unlock
	end
	return tpHits, extraHits, criticalHit, damage;

end
