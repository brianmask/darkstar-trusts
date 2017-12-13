-----------------------------------
-- Ground Strike
-- Great Sword weapon skill
-- Skill level: 250 QUESTED
-- Delivers a single-hit attack. Damage varies with TP.
-- Modifiers: STR:50% INT:50%
-- 100%TP 	200%TP 	300%TP
-- 1.5 		1.75	3.0
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
	params.ftp100 = 2; params.ftp200 = 2.5; params.ftp300 = 3.0;
	--wscs are in % so 0.2=20%
	params.str_wsc = 0.5; params.dex_wsc = 0.0; params.vit_wsc = 0.0; params.agi_wsc = 0.0; params.int_wsc = 0.5; params.mnd_wsc = 0.0; params.chr_wsc = 0.0;
	--critical mods, again in % (ONLY USE FOR CRITICAL HIT VARIES WITH TP)
	params.crit100 = 0.0; params.crit200=0.0; params.crit300=0.0;
	params.canCrit = false;
	--accuracy mods (ONLY USE FOR ACCURACY VARIES WITH TP) , should be the params.acc at those %s NOT the penalty values. Leave 0 if params.acc doesnt vary with tp.
	params.acc100 = 0; params.acc200=0; params.acc300=0;
	--attack multiplier (only some WSes use this, this varies the actual ratio value, see Tachi: Kasha) 1 is default.
	params.atkmulti = 1.75;

	local damage, criticalHit, tpHits, extraHits = doPhysicalWeaponskill(player, target, params);
	
	local wsnm = player:getVar("GROUND_STRIKE");
	local unlock = 0;
    if (player:hasCompleteQuest(BASTOK,INHERITANCE) == true) then -- Inheritance Quest is done
	unlock = 1;
	elseif (player:getQuestStatus(BASTOK,INHERITANCE) == true and wsnm > 1) then -- Inheritance Quest Active
	wsnm = wsnm - 1;
	if (wsnm < 1) then
	wsnm = 1;
	end
	player:setVar("GROUND_STRIKE",wsnm);
	elseif (player:getQuestStatus(BASTOK,INHERITANCE) == true and wsnm <= 1) then -- Inheritance powered up
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
