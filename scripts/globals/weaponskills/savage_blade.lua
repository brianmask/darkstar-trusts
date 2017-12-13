-----------------------------------
-- Savage Blade
-- Sword weapon skill
-- Skill Level: 240
-- Delivers an aerial attack comprised of two hits. Damage varies with TP.
-- In order to obtain Savage Blade, the quest Old Wounds must be completed.
-- Will stack with Sneak Attack.
-- Aligned with the Breeze Gorget, Thunder Gorget & Soil Gorget
-- Aligned with the Breeze Belt, Thunder Belt & Soil Belt.
-- Element: None
-- Modifiers: STR:50% ; MND:50%
-- 100%TP    200%TP    300%TP
-- 4.00      10.25      13.75
-----------------------------------
require("scripts/globals/status");
require("scripts/globals/settings");
require("scripts/globals/weaponskills");
require("scripts/globals/quests");
-----------------------------------

function onUseWeaponSkill(player, target, wsID)

	local params = {};
	params.numHits = 2;
	params.ftp100 = 1; params.ftp200 = 1.75; params.ftp300 = 3.5;
	params.str_wsc = 0.3; params.dex_wsc = 0.0; params.vit_wsc = 0.0; params.agi_wsc = 0.0; params.int_wsc = 0.0; params.mnd_wsc = 0.5; params.chr_wsc = 0.0;
	params.crit100 = 0.0; params.crit200 = 0.0; params.crit300 = 0.0;
	params.canCrit = false;
	params.acc100 = 0.0; params.acc200= 0.0; params.acc300= 0.0;
	params.atkmulti = 1;

	if (USE_ADOULIN_WEAPON_SKILL_CHANGES == true) then
		params.ftp100 = 2; params.ftp200 = 2.5; params.ftp300 = 3;
		params.str_wsc = 0.5;
	end

	local damage, criticalHit, tpHits, extraHits = doPhysicalWeaponskill(player, target, params);
	
    local wsnm = player:getVar("SAVAGE_BLADE");
	local unlock = 0;
    if (player:hasCompleteQuest(SANDORIA,OLD_WOUNDS) == true) then -- Savage Blade Quest is done
	unlock = 1;
	elseif (player:getQuestStatus(SANDORIA,OLD_WOUNDS) == QUEST_ACCEPTED and wsnm > 1) then -- Savage Blade Quest Active
	unlock = 0.05;
	wsnm = wsnm - 1;
	if (wsnm < 1) then
	wsnm = 1;
	end
	player:setVar("SAVAGE_BLADE",wsnm);
	elseif (player:getQuestStatus(SANDORIA,OLD_WOUNDS) == QUEST_ACCEPTED and wsnm <= 1) then -- Savage Blade powered up
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
	if ((player:getEquipID(SLOT_MAIN) == 17761 and player:getVar("RDMHAFight") == 2) or (player:getEquipID(SLOT_MAIN) == 17762 and player:getVar("PLDHAFight") == 2) 
	or (player:getEquipID(SLOT_MAIN) == 17763 and player:getVar("BLUHAFight") == 2)) then
	damage = damage * WEAPON_SKILL_POWER * 1.10
	else
	damage = damage * WEAPON_SKILL_POWER
	end
	return tpHits, extraHits, criticalHit, damage;

end
