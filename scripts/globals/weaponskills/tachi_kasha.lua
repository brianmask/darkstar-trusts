-----------------------------------
-- Tachi Kasha
-- Great Katana weapon skill
-- Skill Level: 250
-- Paralyzes target. Damage varies with TP.
-- Paralyze effect duration is 60 seconds when unresisted.
-- In order to obtain Tachi: Kasha, the quest The Potential Within must be completed.
-- Will stack with Sneak Attack.
-- Tachi: Kasha appears to have a moderate attack bonus of +50%. [1]
-- Aligned with the Flame Gorget, Light Gorget & Shadow Gorget.
-- Aligned with the Flame Belt, Light Belt & Shadow Belt.
-- Element: None
-- Modifiers: STR:75%
-- 100%TP    200%TP    300%TP
-- 1.5625    2.6875    4.125
-----------------------------------
require("scripts/globals/status");
require("scripts/globals/settings");
require("scripts/globals/weaponskills");
require("scripts/globals/quests");
-----------------------------------

function onUseWeaponSkill(player, target, wsID)

	local params = {};
	params.numHits = 1;
	params.ftp100 = 1.56; params.ftp200 = 1.88; params.ftp300 = 2.5;
	params.str_wsc = 0.75; params.dex_wsc = 0.0; params.vit_wsc = 0.0; params.agi_wsc = 0.0; params.int_wsc = 0.0; params.mnd_wsc = 0.0; params.chr_wsc = 0.0;
	params.crit100 = 0.0; params.crit200 = 0.0; params.crit300 = 0.0;
	params.canCrit = false;
	params.acc100 = 0.0; params.acc200= 0.0; params.acc300= 0.0;
	params.atkmulti = 1.5;

	if (USE_ADOULIN_WEAPON_SKILL_CHANGES == true) then
		params.ftp100 = 1.5625; params.ftp200 = 2.6875; params.ftp300 = 4.125;
		params.str_wsc = 0.75; params.dex_wsc = 0.0; params.vit_wsc = 0.0; params.agi_wsc = 0.0; params.int_wsc = 0.0; params.mnd_wsc = 0.0; params.chr_wsc = 0.0;
		params.atkmulti = 1.65
	end

	local damage, criticalHit, tpHits, extraHits = doPhysicalWeaponskill(player, target, params);

		
	local wsnm = player:getVar("KASHA");
	local unlock = 0;
    if (player:hasCompleteQuest(OUTLANDS,THE_POTENTIAL_WITHIN) == true) then -- Tachi:Kasha Quest is done
	unlock = 1;
	elseif (player:getQuestStatus(OUTLANDS,THE_POTENTIAL_WITHIN) == QUEST_ACCEPTED and wsnm > 1) then -- Tachi:Kasha Quest Active
	unlock = 0.05;
	wsnm = wsnm - 1;
	if (wsnm < 1) then
	wsnm = 1;
	end
	player:setVar("KASHA",wsnm);
	elseif (player:getQuestStatus(OUTLANDS,THE_POTENTIAL_WITHIN) == QUEST_ACCEPTED and wsnm <= 1) then -- Tachi:Kasha powered up
	unlock = 0.30;
	else
	unlock = 0.05;
	end
	
	
	
	
	
	if damage > 0 and (target:hasStatusEffect(EFFECT_PARALYSIS) == false) then
		target:addStatusEffect(EFFECT_PARALYSIS, 25, 0, 60);
	end	
	
	if (player:getEquipID(SLOT_MAIN) == 21052 and damage > 0) then
	unlock = 1.50; -- High Artifact Multiplier

			if (player:getTP() >= 100 and player:getTP() <200) then
				player:addStatusEffect(EFFECT_AFTERMATH, 20, 0, 20, 0, 13);
			elseif (player:getTP() >= 200 and player:getTP() <300) then
				player:addStatusEffect(EFFECT_AFTERMATH, 20, 0, 40, 0, 13);
			elseif (player:getTP() == 300) then
				player:addStatusEffect(EFFECT_AFTERMATH, 20, 0, 60, 0, 13);
			end
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
		
	if (player:getEquipID(SLOT_MAIN) == 18452 and player:getVar("SAMHAFight") == 2) then
	damage = damage * WEAPON_SKILL_POWER * unlock * 1.10;
	else
	damage = damage * WEAPON_SKILL_POWER * unlock;
	end
	return tpHits, extraHits, criticalHit, damage;

end
