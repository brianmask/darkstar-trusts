-----------------------------------
--
--
--
-----------------------------------
package.loaded["scripts/globals/conquest"] = nil;
-----------------------------------

require("scripts/globals/quests");
require("scripts/globals/missions");
require("scripts/globals/conquest");
require("scripts/globals/status");
require("scripts/globals/trustpoints");

-----------------------------------
--
-----------------------------------

-- function onMobDeathEx(mob, killer, isKillShot, killType)
function onMobDeathEx(mob, killer, isKillShot, isWeaponSkillKill)
	-- DRK quest - Blade Of Darkness
	local BladeofDarkness = killer:getQuestStatus(BASTOK, BLADE_OF_DARKNESS);
	local BladeofDeath = killer:getQuestStatus(BASTOK, BLADE_OF_DEATH);
	local ChaosbringerKills = killer:getVar("ChaosbringerKills");
	local mobfamily = mob:getSystem();
    local lvldif = (mob:getMainLvl() - killer:getMainLvl());
    local kill = killer:getVar("FerretoryPlantoid");
	local killa = killer:getVar("FerretoryUndead");
	local killb = killer:getVar("FerretoryArcana");
	local killc = killer:getVar("FerretoryDragonDemon");
	local killd = killer:getVar("FerretoryBeastmen");
	local job = killer:getMainJob();
	local ferretoryblmquest = killer:getVar("FerretoryBLM"); -- turns quest on
	local ferretoryblmkills = killer:getVar("FerretoryBLMkills"); -- sets kill number
	local multiplier = 2;  -- 2 is normal and 4 is double
	local infamy = killer:getVar("Infamy");
	local playerlvl = killer:getMainLvl();
	local moblvl = mob:getMainLvl();
	local infamycap = killer:getVar("infamycap");
	local infamymult = killer:getVar("infamymult");
	local newinfamymult = (infamymult / 2);
 
	


	
		
	
	
	if (BladeofDarkness == QUEST_ACCEPTED or BladeofDeath == QUEST_ACCEPTED) then
		if (killer:getEquipID(SLOT_MAIN) == 16607 and isKillShot == true and isWeaponSkillKill == false) then
			if (ChaosbringerKills < 200) then
				killer:setVar("ChaosbringerKills", ChaosbringerKills + 1);
			end
		end
	end

	if (killer:getCurrentMission(WINDURST) == A_TESTING_TIME) then
		if (killer:hasCompletedMission(WINDURST,A_TESTING_TIME) and killer:getZoneID() == 118) then
			killer:setVar("testingTime_crea_count",killer:getVar("testingTime_crea_count") + 1);
		elseif (killer:hasCompletedMission(WINDURST,A_TESTING_TIME) == false and killer:getZoneID() == 117) then
			killer:setVar("testingTime_crea_count",killer:getVar("testingTime_crea_count") + 1);
		end
	end
	
	--//TODO create a calculator based on level.  Replace the < # with a number that determines the level difference based on level.  If player level < 75 difference is 15.  If it is greater than 74 then it is 44?
	
	-------------------- Ferretory Quest #1 (Plantoid) -----------------------
	
	if (mobfamily == 17) and (killer:getVar("FerretoryQuest1") == 1) and (mob:checkBaseExp()) then  -- check for plantoid, check if quest is active, and check if the level difference is less than 10
		if  (killer:getVar("FerretoryPlantoid")) > 0 then  -- if the kills needed are greater than 0
		killer:setVar("FerretoryPlantoid",kill - 1);  -- Subtract kill
		kill = killer:getVar("FerretoryPlantoid");
		if (killer:getVar("FerretoryPlantoid") > 0) then 
		killer:PrintToPlayer("Aura Quest #1 Objectives Remaining: " ..kill..".", 0x15);  -- Print objectives remaining
		else if (killer:getVar("FerretoryPlantoid") == 0) then  -- check to see kills have been completed
		killer:PrintToPlayer("You have completed your objective.  Please report to Maccus for your reward", 0x15);  -- Print message to player
		killer:setVar("FerretoryPlantoidComplete",1);
		end
		end
		end	
end	





	-------------------- Ferretory Quest #2 (Lizard) -----------------------
	
	if (mobfamily == 14) and (killer:getVar("FerretoryQuest1") == 2) and (mob:checkBaseExp()) then  -- check for plantoid, check if quest is active, and check if the level difference is less than 10
		if  (killer:getVar("FerretoryPlantoid")) > 0 then  -- if the kills needed are greater than 0
		killer:setVar("FerretoryPlantoid",kill - 1);  -- Subtract kill
		kill = killer:getVar("FerretoryPlantoid");
		if (killer:getVar("FerretoryPlantoid") > 0) then 
		killer:PrintToPlayer("Aura Quest #2 Objectives Remaining: " ..kill..".", 0x15);  -- Print objectives remaining
		else if (killer:getVar("FerretoryPlantoid") == 0) then  -- check to see kills have been completed
		killer:PrintToPlayer("You have completed your objective.  Please report to Maccus for your reward", 0x15);  -- Print message to player
		killer:setVar("FerretoryPlantoidComplete",2);
		end
		end
		end	
end	


	-------------------- Ferretory Quest #3 (Birds) -----------------------
	
	if (mobfamily == 8) and (killer:getVar("FerretoryQuest1") == 3) and (mob:checkBaseExp()) then  -- check for Birds, check if quest is active, and check if the level difference is less than 10
		if  (killer:getVar("FerretoryPlantoid")) > 0 then  -- if the kills needed are greater than 0
		killer:setVar("FerretoryPlantoid",kill - 1);  -- Subtract kill
		kill = killer:getVar("FerretoryPlantoid");
		if (killer:getVar("FerretoryPlantoid") > 0) then 
		killer:PrintToPlayer("Aura Quest #3 Objectives Remaining: " ..kill..".", 0x15);  -- Print objectives remaining
		else if (killer:getVar("FerretoryPlantoid") == 0) then  -- check to see kills have been completed
		killer:PrintToPlayer("You have completed your objective.  Please report to Maccus for your reward", 0x15);  -- Print message to player
		killer:setVar("FerretoryPlantoidComplete",3);
		end
		end
		end	
end	




	-------------------- Ferretory Quest #4 (Beast) -----------------------
	
	if (mobfamily == 6) and (killer:getVar("FerretoryQuest1") == 4) and (mob:checkBaseExp()) then  -- check for Birds, check if quest is active, and check if the level difference is less than 10
		if  (killer:getVar("FerretoryPlantoid")) > 0 then  -- if the kills needed are greater than 0
		killer:setVar("FerretoryPlantoid",kill - 1);  -- Subtract kill
		kill = killer:getVar("FerretoryPlantoid");
		if (killer:getVar("FerretoryPlantoid") > 0) then 
		killer:PrintToPlayer("Aura Quest #4 Objectives Remaining: " ..kill..".", 0x15);  -- Print objectives remaining
		else if (killer:getVar("FerretoryPlantoid") == 0) then  -- check to see kills have been completed
		killer:PrintToPlayer("You have completed your objective.  Please report to Maccus for your reward", 0x15);  -- Print message to player
		killer:setVar("FerretoryPlantoidComplete",4);
		end
		end
		end	
end	




	-------------------- Ferretory Quest #5 (Amorph) -----------------------
	
	if (mobfamily == 1) and (killer:getVar("FerretoryQuest1") == 5) and (mob:checkBaseExp())then  -- check for Amorph, check if quest is active, and check if the level difference is less than 10
		if  (killer:getVar("FerretoryPlantoid")) > 0 then  -- if the kills needed are greater than 0
		killer:setVar("FerretoryPlantoid",kill - 1);  -- Subtract kill
		kill = killer:getVar("FerretoryPlantoid");
		if (killer:getVar("FerretoryPlantoid") > 0) then 
		killer:PrintToPlayer("Aura Quest #5 Objectives Remaining: " ..kill..".", 0x15);  -- Print objectives remaining
		else if (killer:getVar("FerretoryPlantoid") < 1) then  -- check to see kills have been completed
		killer:PrintToPlayer("You have completed your objective.  Please report to Maccus for your reward", 0x15);  -- Print message to player
		killer:setVar("FerretoryPlantoidComplete",5);
		end
		end
		end	
end	



	-------------------- Ferretory Quest #6 (Vermin) -----------------------
	
	if (mobfamily == 20) and (killer:getVar("FerretoryQuest1") == 6) and (mob:checkBaseExp())then  -- check for Vermin, check if quest is active, and check if the level difference is less than 10
		if  (killer:getVar("FerretoryPlantoid")) > 0 then  -- if the kills needed are greater than 0
		killer:setVar("FerretoryPlantoid",kill - 1);  -- Subtract kill
		kill = killer:getVar("FerretoryPlantoid");
		if (killer:getVar("FerretoryPlantoid") > 0) then 
		killer:PrintToPlayer("Aura Quest #6 Objectives Remaining: " ..kill..".", 0x15);  -- Print objectives remaining
		else if (killer:getVar("FerretoryPlantoid") == 0) then  -- check to see kills have been completed
		killer:PrintToPlayer("You have completed your objective.  Please report to Maccus for your reward", 0x15);  -- Print message to player
		killer:setVar("FerretoryPlantoidComplete",6);
		end
		end
		end	
end	



	-------------------- Ferretory Quest #7 (Aquan) -----------------------
	
	if (mobfamily == 2) and (killer:getVar("FerretoryQuest1") == 7) and (mob:checkBaseExp())then  -- check for Birds, check if quest is active, and check if the level difference is less than 10
		if  (killer:getVar("FerretoryPlantoid")) > 0 then  -- if the kills needed are greater than 0
		killer:setVar("FerretoryPlantoid",kill - 1);  -- Subtract kill
		kill = killer:getVar("FerretoryPlantoid");
		if (killer:getVar("FerretoryPlantoid") > 0) then 
		killer:PrintToPlayer("Aura Quest #7 Objectives Remaining: " ..kill..".", 0x15);  -- Print objectives remaining
		else if (killer:getVar("FerretoryPlantoid") == 0) then  -- check to see kills have been completed
		killer:PrintToPlayer("You have completed your objective.  Please report to Maccus for your reward", 0x15);  -- Print message to player
		killer:setVar("FerretoryPlantoidComplete",7);
		end
		end
		end	
end	

    -------------------- Ferretory Quest #8 (Undead and Arcana) -----------------------
    if (mobfamily == 19) and (killer:getVar("FerretoryQuest75Exp") == 8) and (mob:checkBaseExp())then
	    if (killer:getVar("FerretoryUndead")) > 0 then -- if the kills needed are greater than 0
        killer:setVar("FerretoryUndead",killa - 1); -- subtract kill
		killa = killer:getVar("FerretoryUndead");
		killb = killer:getVar("FerretoryArcana");
		if (killer:getVar("FerretoryUndead")) > 0 then
		killer:PrintToPlayer("Feretory Quest #8 Objectives Remaining: Undead(" ..killa..")/Arcana(" ..killb.."),", 0x15);  -- Print objectives remaining
        else if (killer:getVar("FerretoryUndead") == 0) and (killer:getVar("FerretoryArcana") == 0) then  -- check to see kills have been completed
		killer:PrintToPlayer("You have completed your objectives.  Please report to Maccus for your reward", 0x15);  -- Print message to player
		killer:setVar("FerretoryLv75Complete",8);
        end
		end
		end	
    end
	if (mobfamily == 3) and (killer:getVar("FerretoryQuest75Exp") == 8) and (mob:checkBaseExp())then
	    if (killer:getVar("FerretoryArcana")) > 0 then -- if the kills needed are greater than 0
        killer:setVar("FerretoryArcana",killb - 1); -- subtract kill
		killa = killer:getVar("FerretoryUndead");
		killb = killer:getVar("FerretoryArcana");
		if (killer:getVar("FerretoryArcana")) > 0 then
		killer:PrintToPlayer("Feretory Quest #8 Objectives Remaining: Undead(" ..killa..")/Arcana(" ..killb.."),", 0x15);  -- Print objectives remaining
        else if (killer:getVar("FerretoryUndead") == 0) and (killer:getVar("FerretoryArcana") == 0) then  -- check to see kills have been completed
		killer:PrintToPlayer("You have completed your objectives.  Please report to Maccus for your reward", 0x15);  -- Print message to player
		killer:setVar("FerretoryLv75Complete",8);
        end
		end
		end	
    end

	-------------------- Ferretory Quest #9 (Demon/Dragon) -----------------------
	
	if ((mobfamily == 9) or (mobfamily == 10)) and (killer:getVar("FerretoryQuest75Exp") == 9) and (mob:checkBaseExp())then  -- check for Birds, check if quest is active, and check if the level difference is less than 10
		if  (killer:getVar("FerretoryDragonDemon")) > 0 then  -- if the kills needed are greater than 0
		killer:setVar("FerretoryDragonDemon",killc - 1);  -- Subtract kill
		killc = killer:getVar("FerretoryDragonDemon");
		if (killer:getVar("FerretoryDragonDemon") > 0) then 
		killer:PrintToPlayer("Feretory Quest #9 Objectives Remaining: " ..killc..".", 0x15);  -- Print objectives remaining
		else if (killer:getVar("FerretoryDragonDemon") == 0) then  -- check to see kills have been completed
		killer:PrintToPlayer("You have completed your objective.  Please report to Maccus for your reward", 0x15);  -- Print message to player
		killer:setVar("FerretoryLv75Complete",9);
		end
		end
		end	
end	

	-------------------- Ferretory Quest #10 (Beastmen) -----------------------
	
	if ((mobfamily == 7) and (killer:getVar("FerretoryQuest75Exp") == 10) and (mob:checkBaseExp())) then 
		if (killer:getVar("FerretoryBeastmen")) > 0 then  -- if the kills needed are greater than 0
		killer:setVar("FerretoryBeastmen",killd - 1);  -- Subtract kill
		killd = killer:getVar("FerretoryBeastmen");
		if (killer:getVar("FerretoryBeastmen") > 0) then 
		killer:PrintToPlayer("Feretory Quest #10 Objectives Remaining: " ..killd..".", 0x15);  -- Print objectives remaining
		else if (killer:getVar("FerretoryBeastmen") == 0) then  -- check to see kills have been completed
		killer:PrintToPlayer("You have completed your objective.  Please report to Maccus for your reward", 0x15);  -- Print message to player
		killer:setVar("FerretoryLv75Complete",10);
		end
		end
		end	
end	





-- Black Mage Ferretory Quest

if (job == 4) and (killer:getVar("FerretoryBLM") == 1) and (mobfamily == 11) then
	if  (killer:getVar("FerretoryBLMkills")) > 0 then
	killer:setVar("FerretoryBLMkills",ferretoryblmkills - 1);  -- Subtract kill
	ferretoryblmkills = killer:getVar("FerretoryBLMkills");
	if (killer:getVar("FerretoryBLMkills") > 0) then 
	killer:PrintToPlayer("Grimoire Black Mage Quest #1 Objectives Remaining: " ..ferretoryblmkills..".", 0x15);  -- Print objectives remaining
	else if (killer:getVar("FerretoryBLMkills") == 0) then  -- check to see kills have been completed
	killer:PrintToPlayer("You have completed your objective.  Please report to Maccus for your reward", 0x15);  -- Print message to player
	killer:setVar("FerretoryBLMQ1",1);
	killer:setVar("FerretoryBLM",0);
	end
	end
	end
end

--  Infamy Point Calculations
-- Check to see if they have finished the respective mob family quest.  Only get infamy based on mob families you've quested.
if ((mobfamily == 17) and (killer:getVar("FerretoryExp") > 1)) or ((mobfamily == 14) and (killer:getVar("FerretoryExp") > 2)) or
((mobfamily == 8) and (killer:getVar("FerretoryExp") > 3)) or ((mobfamily == 6) and (killer:getVar("FerretoryExp") > 4)) or
((mobfamily == 1) and (killer:getVar("FerretoryExp") > 5)) or ((mobfamily == 20) and (killer:getVar("FerretoryExp") > 6)) or
((mobfamily == 2) and (killer:getVar("FerretoryExp") > 7)) or ((mobfamily == 3) and (killer:getVar("FerretoryQuest75Exp") > 8)) or
((mobfamily == 19) and (killer:getVar("FerretoryQuest75Exp") > 8)) or ((mobfamily == 9) and (killer:getVar("FerretoryQuest75Exp") > 9)) or 
((mobfamily == 10) and (killer:getVar("FerretoryQuest75Exp") > 9)) or ((mobfamily == 15) and (killer:getVar("FerretoryQuest75Exp") > 10)) or
((mobfamily == 16) and (killer:getVar("FerretoryQuest75Exp") > 10) or ((mobfamily == 7) and (killer:getVar("FerretoryQuest75Exp") >= 11))) then



if (infamy == 1) and (playerlvl <= 75) and (mob:checkBaseExp()) then -- check if infamy is turned on
if (lvldif < -11) then  -- EP
multiplier = 1.7;
else if (lvldif <= -3) then
multiplier = 2.3;
else if (lvldif <= -1) then
multiplier = 2.5;
else if (lvldif == 0) then 
multiplier = 2.7;
else if (lvldif <= 4) then
multiplier = 3;
else if (lvldif == 5) then
multiplier = 3.5;
else 
multiplier = 4.3;
end
end
end
end
end
end


local infamypoints = math.floor(((lvldif + 25) * multiplier) * infamymult);
killer:addCurrency("infamy",infamypoints);
if (killer:getCurrency("infamy") > infamycap) then
killer:setCurrency("infamy",infamycap);
end
if (infamypoints > 0) then
killer:PrintToPlayer(string.format("%s gains "..infamypoints.." infamy points.", killer:getName()), 0x15);
-- killer:PrintToPlayer(lvldif);
else
-- killer:PrintToPlayer(infamypoints);
-- killer:PrintToPlayer(lvldif);
end

end
end




-- if (mob:checkBaseExp()) then
  --   newbonus = restexp - reduction;
	-- killer:setVar("RestExp",newbonus);
	-- end
	
-- Set Resting Bonus Variable for dashboard


local restpower = 0;
if (killer:hasStatusEffect(EFFECT_RESTING_BONUS)) then
    local resting = killer:getStatusEffect(EFFECT_RESTING_BONUS);
    power = resting:getPower();
	killer:setVar("RestingBonus",power);
end


trustPoints(killer,mob);



-- Check to see if trust is in party and reward points 




	
	

	-- doMagiantTrialCheck(mob, killer, isKillShot, killType);
end;


