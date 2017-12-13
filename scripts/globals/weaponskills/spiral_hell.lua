-----------------------------------
-- Spiral Hell
-- Scythe weapon skill
-- Skill level: 240 QUESTED
-- Delivers a single-hit attack. Damage varies with TP.
-- Modifiers: STR:50% ; INT:50%
-- 100%TP 	200%TP 	300%TP
-- 1.375	 2.75	 4.75
-----------------------------------
require("scripts/globals/status");
require("scripts/globals/settings");
require("scripts/globals/weaponskills");
require("scripts/globals/quests");
-----------------------------------
function onUseWeaponSkill(player, target, wsID)

	local params = {};
	params.numHits = 1;
	--ftp damage mods (for Damage Varies with TP; lines are calculated in the function
	params.ftp100 = 2.0; params.ftp200 = 2.875; params.ftp300 = 3.625;
	--wscs are in % so 0.2=20%
	params.str_wsc = 0.5; params.dex_wsc = 0.0; params.vit_wsc = 0.0; params.agi_wsc = 0.0; params.int_wsc = 0.5; params.mnd_wsc = 0.0; params.chr_wsc = 0.0;
	--critical mods, again in % (ONLY USE FOR critICAL HIT VARIES WITH TP)
	params.crit100 = 0.0; params.crit200=0.0; params.crit300=0.0;
	params.canCrit = false;
	--accuracy mods (ONLY USE FOR accURACY VARIES WITH TP) , should be the acc at those %s NOT the penalty values. Leave 0 if acc doesnt vary with tp.
	params.acc100 = 0; params.acc200=0; params.acc300=0;
	--attack multiplier (only some WSes use this, this varies the actual ratio value, see Tachi: Kasha) 1 is default.
	params.atkmulti = 1.15;

	if (USE_ADOULIN_WEAPON_SKILL_CHANGES == true) then
		params.ftp200 = 3.75; params.ftp300 = 4.75;
	end

	local damage, criticalHit, tpHits, extraHits = doPhysicalWeaponskill(player, target, params);
	
	local wsnm = player:getVar("SPIRAL_HELL");
	local unlock = 0;
    if (player:hasCompleteQuest(SANDORIA,SOULS_IN_SHADOW) == true) then -- Spiral Hell Quest is done
	unlock = 1;
	elseif (player:getQuestStatus(SANDORIA,SOULS_IN_SHADOW) == QUEST_ACCEPTED and wsnm > 1) then -- Spiral Hell Quest Active
	unlock = 0.05;
	wsnm = wsnm - 1;
	if (wsnm < 1) then
	wsnm = 1;
	end
	player:setVar("SPIRAL_HELL",wsnm);
	elseif (player:getQuestStatus(SANDORIA,SOULS_IN_SHADOW) == QUEST_ACCEPTED and wsnm <= 1) then -- Spiral Hell powered up
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
	
	if (player:getEquipID(SLOT_MAIN) == 18995 and player:getVar("DRKHAFight") == 2) then
	damage = damage * WEAPON_SKILL_POWER * unlock * 1.10;
	else
	damage = damage * WEAPON_SKILL_POWER * unlock;
	end
	return tpHits, extraHits, criticalHit, damage;
end
