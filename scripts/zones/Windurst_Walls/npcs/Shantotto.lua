-----------------------------------
--	Area: Windurst Walls
--	NPC:  Shantotto
--	@pos 122 -2 112 239
--  CSID's missing in autoEventID please check the old forums under resources for all of shantotto's csid's. I found them all manually.
-----------------------------------
package.loaded["scripts/zones/Windurst_Walls/TextIDs"] = nil;
-----------------------------------

require("scripts/zones/Windurst_Walls/TextIDs");
require("scripts/globals/settings");
require("scripts/globals/quests");
require("scripts/globals/keyitems");
require("scripts/globals/titles");
require("scripts/globals/missions");

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)

	local count = trade:getItemCount();
	
	local lvl = player:getMainLvl();
	local job = player:getMainJob();
	local viruscurse = player:getVar("BLMVirusCurse");
	
	-- Shantotto Trust
    if (player:getNation() == 0) and (player:hasKeyItem(RED_INSTITUTE_CARD)) and (player:hasSpell(896) == false) and (player:hasCompletedMission(TOAU,SHIELD_OF_DIPLOMACY) == true) then  -- ToAU Shield of Diplomacy Completed
	player:PrintToPlayer("Your Red Institute Card flashes brilliantly!", 0x1C);
    player:PrintToPlayer("Shantotto : Ah I see you have a Red Institute Card.  From now on, you can summon me if your battle is too hard.", 0xD);
    player:addSpell(896);	
	player:PrintToPlayer("You are now able to summon the trust Shantotto!", 0x15);		
    elseif (player:getNation() == 1) and (player:hasKeyItem(BLUE_INSTITUTE_CARD)) and (player:hasSpell(896) == false) and (player:hasCompletedMission(TOAU,SHIELD_OF_DIPLOMACY) == true) then  -- ToAU Shield of Diplomacy Completed
	player:PrintToPlayer("Your Blue Institute Card flashes brilliantly!", 0x1C);
    player:PrintToPlayer("Shantotto : Ah I see you have a Blue Institute Card.  From now on, you can summon me if your battle is too hard.", 0xD);
    player:addSpell(896);
	player:PrintToPlayer("You are now able to summon the trust Shantotto!", 0x15);		
    elseif (player:getNation() == 2) and (player:hasKeyItem(GREEN_INSTITUTE_CARD)) and (player:hasSpell(896) == false) and (player:hasCompletedMission(TOAU,SHIELD_OF_DIPLOMACY) == true) then  -- ToAU Shield of Diplomacy Completed
	player:PrintToPlayer("Your Green Institute Card flashes brilliantly!", 0x1C);
    player:PrintToPlayer("Shantotto : Ah I see you have a Green Institute Card.  From now on, you can summon me if your battle is too hard.", 0xD);
    player:addSpell(896);
	player:PrintToPlayer("You are now able to summon the trust Shantotto!", 0x15);	
    end
		
	
	
	
	
	-- Curses Foiled Again!
	if (player:getQuestStatus(WINDURST,CURSES_FOILED_AGAIN_1) == QUEST_ACCEPTED) then
		if (trade:hasItemQty(928,1) and trade:hasItemQty(880,2) and count == 3) then
			player:startEvent(0xad,0,0,0,0,0,0,928,880); -- Correct items given, complete quest.
		else
			player:startEvent(0x00AC,0,0,0,0,0,0,928,880); -- Incorrect or not enough items
		end
		
	-- Curses,Foiled ... Again!?
	elseif (player:getQuestStatus(WINDURST,CURSES_FOILED_AGAIN_2) == QUEST_ACCEPTED) then
		if (trade:hasItemQty(17316,2) and trade:hasItemQty(940,1) and trade:hasItemQty(552,1) and count == 4) then
			player:startEvent(0x00B7); -- Correct items given, complete quest.
		else
			player:startEvent(0x00B5,0,0,0,0,0,0,17316,940); -- Incorrect or not enough items
		end
	
		
	end
	if (trade:hasItemQty(955,3) and (job == 4) and (lvl >= 50) and (viruscurse == 1) and (player:hasSpell(257) == false)) then
	player:PrintToPlayer("Shantotto : No pain, no gain!", 0xD);
    player:addSpell(257);
	player:setVar("BLMVirusCurse",2);
    end
     
	if (trade:hasItemQty(935,3) and (job == 4) and (lvl >= 50) and (viruscurse == 3) and (player:hasSpell(256) == false)) then
	player:PrintToPlayer("Shantotto : No pain, no gain!", 0xD);
    player:addSpell(256);
	player:setVar("BLMVirusCurse",0);
    end  
	
end; 

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)

	local foiledAgain = player:getQuestStatus(WINDURST,CURSES_FOILED_AGAIN_1);
	local CFA2 = player:getQuestStatus(WINDURST,CURSES_FOILED_AGAIN_2);
	local CFAtimer = player:getVar("CursesFoiledAgain");
	local FoiledAGolem = player:getQuestStatus(WINDURST,CURSES_FOILED_A_GOLEM);
	local golemdelivery = player:getVar("foiledagolemdeliverycomplete");
	local WildcatWindurst = player:getVar("WildcatWindurst");
	local wsnm = player:getVar("RETRIBUTION");
	local mainlvl = player:getMainLvl();
	local skill = player:getSkillLevel(12);
	local viruscurse = player:getVar("BLMVirusCurse");
	local lvl = player:getMainLvl();
	local job = player:getMainJob();

	if ((job == 4) and (lvl >= 50) and (player:hasSpell(257) == false)) then
	player:PrintToPlayer("Shantotto : A black mage can never show all their cards.  A new spell for you for 3 Golem Shards", 0xD);
	player:setVar("BLMVirusCurse",1);
	elseif ((job == 5) and (lvl >= 50) and (viruscurse == 2) and (player:hasSpell(256) == false)) then
	player:PrintToPlayer("Shantotto : I have something for you amongst all these things. A new spell for you for 3 Ahriman Wings", 0xD);
	player:setVar("BLMVirusCurse",3);
	elseif (player:getCurrentMission(WINDURST) == THE_JESTER_WHO_D_BE_KING and player:getVar("MissionStatus") == 7) then
		player:startEvent(0x18d,0,0,0,282);
	elseif (player:getQuestStatus(WINDURST,LURE_OF_THE_WILDCAT_WINDURST) == QUEST_ACCEPTED and player:getMaskBit(WildcatWindurst,6) == false) then
		player:startEvent(0x01f2);
	elseif (player:getQuestStatus(WINDURST,CLASS_REUNION) == QUEST_ACCEPTED and player:getVar("ClassReunionProgress") == 3) then
		player:startEvent(0x0199); -- she mentions that Sunny-Pabonny left for San d'Oria
	-------------------------------------------------------
	-- Curses Foiled Again!
	elseif (foiledAgain == QUEST_AVAILABLE) then
		player:startEvent(0xab,0,0,0,0,0,0,928,880);
	elseif (foiledAgain == QUEST_ACCEPTED) then
		player:startEvent(0xac,0,0,0,0,0,0,928,880);
	elseif (foiledAgain == QUEST_COMPLETED and CFA2 == QUEST_AVAILABLE and CFAtimer == 0) then
	    local cDay = VanadielDayOfTheYear();
		local cYear = VanadielYear();
		local dFinished = player:getVar("CursesFoiledAgainDay");
		local yFinished = player:getVar("CursesFoiledAgainYear");
		
		-- player:PrintToPlayer("Vana Day and year:  "..cDay..", "..cYear);
		-- player:PrintToPlayer("Database Day and year:  "..dFinished..", "..yFinished);
		
		if (cDay == dFinished and cYear == yFinished) then
		    player:startEvent(0xae);
		elseif (cDay == dFinished + 1 and cYear == yFinished) then
            player:startEvent(0xb2);
		elseif ((cDay >= dFinished + 2 and cYear == yFinished) or (cYear > yFinished)) then
			player:startEvent(0xb3);
		end	
	
		
	-- Curses,Foiled...Again!?
	elseif (foiledAgain == QUEST_COMPLETED and CFA2 == QUEST_AVAILABLE and player:getFameLevel (WINDURST) >= 2 and player:getMainLvl() >= 5 and CFAtimer == 1) then
		player:startEvent(0x00B4,0,0,0,0,928,880,17316,940);		-- Quest Start
	elseif (CFA2 == QUEST_ACCEPTED) then
		player:startEvent(0x00B5,0,0,0,0,0,0,17316,940);  -- Reminder dialog
	
		
	-- Curses,Foiled A-Golem!?
	elseif (CFA2 == QUEST_COMPLETED and FoiledAGolem == QUEST_AVAILABLE and player:getFameLevel (WINDURST) >= 4 and player:getMainLvl() >= 10) then
		player:startEvent(0x0154);  --quest start
	elseif (golemdelivery == 1) then
		player:startEvent(0x0156);  -- finish
	elseif (FoiledAGolem == QUEST_ACCEPTED) then
		player:startEvent(0x0155);  -- reminder dialog
	elseif (mainlvl >= 71 and skill >= 250 and player:getQuestStatus(WINDURST,BLOOD_AND_GLORY) ~= QUEST_ACCEPTED) then
	   player:PrintToPlayer("Shantotto : Full power Retribution you say?  100 enemies with it you must slay!",0x0D);
	   player:setVar("RETRIBUTION",100);
	   player:addQuest(WINDURST,BLOOD_AND_GLORY);
	elseif (wsnm == 1 and player:getQuestStatus(WINDURST,BLOOD_AND_GLORY) == QUEST_ACCEPTED) then
	   player:PrintToPlayer("Shantotto : You finished your task with such flair. Now defeat the monster near Ifrit's Lair!",0x0D);
	   player:addKeyItem(MAP_TO_THE_ANNALS_OF_TRUTH);
 	   player:messageSpecial(MAP_TO_THE_ANNALS_OF_TRUTH);
	   player:setVar("RETRIBUTION_WIN",1);
	elseif (player:hasKeyItem(ANNALS_OF_TRUTH) and player:getVar("RETRIBUTION_WIN") == 2) then
	   player:PrintToPlayer("Shantotto : You have done well to make the moster cower.  Retribution is now at the fullest of power!",0x0D);
	   player:delKeyItem(ANNALS_OF_TRUTH);
	   player:completeQuest(WINDURST,BLOOD_AND_GLORY);
	
	-- Standard dialog
	elseif (FoiledAGolem == QUEST_COMPLETED) then
		player:startEvent(0x0157);  -- new standard dialog after Curses,Foiled A-Golem!?
	
	elseif (CFA2 == QUEST_COMPLETED) then
		player:startEvent(0x00B8); 	-- New standard dialog after CFA2
	elseif (player:hasCompletedMission(WINDURST,THE_JESTER_WHO_D_BE_KING) and player:getVar("ShantottoCS") == 1) then
		player:startEvent(0x18f,0,0,282);
	else
		player:startEvent(0xa4);
	end
	

end;

-----------------------------------
-- onEventUpdate
-----------------------------------

function onEventUpdate(player,csid,option)
--printf("CSID: %u",csid);
--printf("RESULT: %u",option);

end;

-----------------------------------
-- onEventFinish
-----------------------------------

function onEventFinish(player,csid,option)
--printf("CSID: %u",csid);
--printf("RESULT: %u",option);
	if (csid == 0xad) then
		if (player:getFreeSlotsCount() == 0) then 
			player:messageSpecial(ITEM_CANNOT_BE_OBTAINED,17081); 
		else
			player:tradeComplete();
			player:setVar("CursesFoiledAgainDay",VanadielDayOfTheYear());
			player:setVar("CursesFoiledAgainYear",VanadielYear());
			player:addFame(WINDURST,WIN_FAME*80);
			player:addItem(17081);
			player:messageSpecial(ITEM_OBTAINED,17081);
			player:completeQuest(WINDURST,CURSES_FOILED_AGAIN_1);
		end
	
	elseif (csid == 0xab and option ~= 1) then
		player:addQuest(WINDURST,CURSES_FOILED_AGAIN_1);

	elseif (csid == 0xb3) then
		player:setVar("CursesFoiledAgainDayFinished",0);
	    player:setVar("CursesFoiledAgainYearFinished",0);
		player:setVar("CursesFoiledAgainDay",0);
		player:setVar("CursesFoiledAgainYear",0);
		player:setVar("CursesFoiledAgain",1); -- Used to acknowledge that the two days have passed, Use this to initiate next quest 
		player:needToZone(true);       
	
	elseif (csid == 0x00B4 and option == 3) then
		player:setVar("CursesFoiledAgain",0);
		player:addQuest(WINDURST,CURSES_FOILED_AGAIN_2);
		player:setTitle(TARUTARU_MURDER_SUSPECT);
	
	elseif (csid == 0x00B7) then
		if (player:getFreeSlotsCount() == 0) then 
			player:messageSpecial(ITEM_CANNOT_BE_OBTAINED,17116); 
		else
			player:tradeComplete();
			player:setTitle(HEXER_VEXER);
			player:addItem(17116);
			player:messageSpecial(ITEM_OBTAINED,17116);
			player:completeQuest(WINDURST,CURSES_FOILED_AGAIN_2);
			player:needToZone(true);
			player:addFame(WINDURST,WIN_FAME*90);
		end
		
	elseif (csid == 0x0154) then
		if (option == 1) then
			player:addQuest(WINDURST,CURSES_FOILED_A_GOLEM);
		else
			player:setTitle(TOTAL_LOSER);
		end
		
	elseif (csid == 0x0156) then
		if (player:getFreeSlotsCount() == 0) then 
			player:messageSpecial(ITEM_CANNOT_BE_OBTAINED,4870); 
		else
			player:completeQuest(WINDURST,CURSES_FOILED_A_GOLEM);
			player:setVar("foiledagolemdeliverycomplete",0);
			player:addItem(4870);
			player:messageSpecial(ITEM_OBTAINED,4870);
			player:setTitle(DOCTOR_SHANTOTTOS_FLAVOR_OF_THE_MONTH);
			player:addFame(WINDURST,WIN_FAME*120);
		end
	elseif (csid == 0x0199) then
		player:setVar("ClassReunionProgress",4);
	elseif (csid == 0x01f2) then
		player:setMaskBit(player:getVar("WildcatWindurst"),"WildcatWindurst",6,true);
	elseif (csid == 0x018D) then
		player:addKeyItem(GLOVE_OF_PERPETUAL_TWILIGHT)
		player:messageSpecial(KEYITEM_OBTAINED,GLOVE_OF_PERPETUAL_TWILIGHT);
		player:setVar("MissionStatus",8)
	elseif (csid == 0x18f) then
		player:setVar("ShantottoCS",0)
	end
end;
