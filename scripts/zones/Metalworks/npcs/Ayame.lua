-----------------------------------
-- Area: Metalworks
-- NPC:  Ayame
-- Involved in Missions
-- Starts and Finishes Quest: True Strength
-- @pos 133 -19 34 237
-----------------------------------
package.loaded["scripts/zones/Metalworks/TextIDs"] = nil;
-----------------------------------

require("scripts/globals/settings");
require("scripts/globals/titles");
require("scripts/globals/keyitems");
require("scripts/globals/missions");
require("scripts/globals/quests");
require("scripts/zones/Metalworks/TextIDs");

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)
	
	if (player:getQuestStatus(BASTOK,TRUE_STRENGTH) == QUEST_ACCEPTED) then 
		if (trade:hasItemQty(1100,1) and trade:getItemCount() == 1) then -- Trade Xalmo Feather
			player:startEvent(0x02ed); -- Finish Quest "True Strength"
		end	
	end
	
    local currentTokens = player:getVar("CurrentTokens_Ayame");	

    if ((player:getVar("AYAME_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Ayame") == 0) and (trade:hasItemQty(65535, 1000)) and (currentTokens >= 1)) then
      player:PrintToPlayer("Ayame : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Ayame's Attack is raised by 5 points! (Total: 5)", 0x15);
	  player:setVar("TrustAtt_Ayame",5);
	  player:setVar("TributeRank_Ayame",1);
	  currentTokens = currentTokens - 1;
	  player:setVar("CurrentTokens_Ayame",currentTokens);
    elseif ((player:getVar("AYAME_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Ayame") == 1) and (trade:hasItemQty(65535, 2000)) and (currentTokens >= 2)) then
	  player:PrintToPlayer("Ayame : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Ayame's Accuracy is raised by 5 points! (Total: 5)", 0x15);
	  player:setVar("TrustAcc_Ayame",5);	
	  player:setVar("TributeRank_Ayame",2);
	  currentTokens = currentTokens - 2;
	  player:setVar("CurrentTokens_Ayame",currentTokens);	  
    elseif ((player:getVar("AYAME_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Ayame") == 2) and (trade:hasItemQty(65535, 3000)) and (currentTokens >= 3)) then
      player:PrintToPlayer("Ayame : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Ayame's Store TP has been raised by 5! (Total: 5)", 0x15);
	  player:setVar("TrustSTP_Ayame",5);	
	  player:setVar("TributeRank_Ayame",3);
	  currentTokens = currentTokens - 3;
	  player:setVar("CurrentTokens_Ayame",currentTokens);	  
    elseif ((player:getVar("AYAME_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Ayame") == 3) and (trade:hasItemQty(65535, 4000)) and (currentTokens >= 4)) then
      player:PrintToPlayer("Ayame : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Ayame's Attack is raised by 5 points! (Total: 10)", 0x15);
	  player:setVar("TrustAtt_Ayame",10);	
	  player:setVar("TributeRank_Ayame",4);
	  currentTokens = currentTokens - 4;
	  player:setVar("CurrentTokens_Ayame",currentTokens);	  
    elseif ((player:getVar("AYAME_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Ayame") == 4) and (trade:hasItemQty(65535, 5000)) and (currentTokens >= 5)) then
      player:PrintToPlayer("Ayame : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Ayame's Accuracy is raised by 5 points! (Total: 10)", 0x15);
	  player:setVar("TrustAcc_Ayame",10);	
	  player:setVar("TributeRank_Ayame",5);
	  currentTokens = currentTokens - 5;
	  player:setVar("CurrentTokens_Ayame",currentTokens);	  
    elseif ((player:getVar("AYAME_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Ayame") == 5) and (trade:hasItemQty(65535, 10000)) and (currentTokens >= 10)) then
      player:PrintToPlayer("Ayame : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Ayame's Store TP has been raised by 5! (Total: 10)", 0x15);
	  player:setVar("TrustSTP_Ayame",0);	
	  player:setVar("TributeRank_Ayame",6);
	  currentTokens = currentTokens - 10;
	  player:setVar("CurrentTokens_Ayame",currentTokens);	  
    elseif ((player:getVar("AYAME_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Ayame") == 6) and (trade:hasItemQty(65535, 15000)) and (currentTokens >= 15)) then
      player:PrintToPlayer("Ayame : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Ayame's Attack is raised by 5 points! (Total: 15)", 0x15);
	  player:setVar("TrustAtt_Ayame",15);	
	  player:setVar("TributeRank_Ayame",7);
	  currentTokens = currentTokens - 15;
	  player:setVar("CurrentTokens_Ayame",currentTokens);	  
    elseif ((player:getVar("AYAME_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Ayame") == 7) and (trade:hasItemQty(65535, 30000)) and (currentTokens >= 20)) then
      player:PrintToPlayer("Ayame : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Ayame's Accuracy is raised by 5 points! (Total: 15)", 0x15);
	  player:setVar("TrustAcc_Ayame",15);	
	  player:setVar("TributeRank_Ayame",8);
	  currentTokens = currentTokens - 20;
	  player:setVar("CurrentTokens_Ayame",currentTokens);	  
    elseif ((player:getVar("AYAME_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Ayame") == 8) and (trade:hasItemQty(65535, 75000)) and (currentTokens >= 30)) then
      player:PrintToPlayer("Ayame : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Ayame's Zanshin has been increased by 5 (Total: 5)", 0x15);
	  player:setVar("TrustZan_Ayame",5);	
	  player:setVar("TributeRank_Ayame",9);	
	  currentTokens = currentTokens - 30;
	  player:setVar("CurrentTokens_Ayame",currentTokens);	  
    elseif ((player:getVar("AYAME_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Ayame") == 9) and (trade:hasItemQty(65535, 150000)) and (currentTokens >= 35)) then
      player:PrintToPlayer("Ayame : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Ayame's Meditate Effect increases by 20 TP!", 0x15);
	  player:setVar("TrustJA_Ayame",20);	
	  player:setVar("TributeRank_Ayame",10);
	  currentTokens = currentTokens - 35;
	  player:setVar("CurrentTokens_Ayame",currentTokens);	
    else
      player:PrintToPlayer("Ayame : Please trade the correct amount of Tokens and Gil.",0x0D);	
	end	
	
end;

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)
	
	local trueStrength = player:getQuestStatus(BASTOK,TRUE_STRENGTH);
	local WildcatBastok = player:getVar("WildcatBastok");
	local pNation = player:getNation();
	local currentMission = player:getCurrentMission(pNation);
	local srank = getNationRank(SANDORIA);
	local tribfight = player:getVar("AYAME_TRIB_FIGHT");
	local mainlvl = player:getMainLvl();
		
    if (player:getNation() == 1) and (player:hasKeyItem(BLUE_INSTITUTE_CARD)) and (player:hasSpell(900) == false) then  -- Bastok Nation and mission 2-3
	player:PrintToPlayer("Your Blue Institute Card flashes brilliantly!", 0x1C);
    player:PrintToPlayer("Ayame : Ah a Red Institute Card.  My blade is ready to assist you", 0xD);
    player:addSpell(900);	
	player:PrintToPlayer("You are now able to summon the trust Ayame!", 0x15);
    elseif (player:getNation() == 2) and (player:hasKeyItem(GREEN_INSTITUTE_CARD)) and (player:hasSpell(900) == false) and (player:hasCompletedMission(WINDURST,THE_PRICE_OF_PEACE) == true) then -- Windy Nation can obtain when rank is higher than 1
	player:PrintToPlayer("Your Green Institute Card flashes brilliantly!", 0x1C);
    player:PrintToPlayer("Ayame : Ah a Green Institute Card.  My blade is ready to assist you", 0xD);
    player:addSpell(900);	
	player:PrintToPlayer("You are now able to summon the trust Ayame!", 0x15);	
	elseif (player:getNation() == 0) and (player:hasKeyItem(RED_INSTITUTE_CARD)) and (player:hasSpell(900) == false) and (player:hasCompletedMission(SANDORIA,SAVE_THE_CHILDREN) == true) then  -- Sandy Nation can obtain when rank is higher than 2
	player:PrintToPlayer("Your Red Institute Card flashes brilliantly!", 0x1C);
    player:PrintToPlayer("Ayame : Ah a Red Institute Card.  My blade is ready to assist you", 0xD);
    player:addSpell(900);
	player:PrintToPlayer("You are now able to summon the trust Ayame!", 0x15);	
	elseif (((mainlvl >= 75 and tribfight == 0 and (player:hasSpell(900))) and (player:getVar("FerretoryAura") >= 7)) and (player:getVar("TRIB_FIGHT") ~= 1)) then
	player:PrintToPlayer("Ayame : There is someone running around claming to be me at Palborough Mines.  Please head there and I'll join you.", 0xD);
    player:PrintToPlayer("Ayame : When you are ready, examine the Burning Circle in Palborough Mines and call me to your side.", 0xD);
	player:setVar("AYAME_TRIB_FIGHT",1);
    player:setVar("TRIB_FIGHT",1);	
	elseif (mainlvl >= 75 and tribfight == 2 and (player:hasSpell(900))) then
	player:PrintToPlayer("Ayame : You have done well to help with the imposter investigation.  I am in your debt.", 0xD);
	player:PrintToPlayer("You are now able to collect Trust Tokens for Ayame!", 0x15);
	player:setVar("AYAME_TRIB_FIGHT",3);
	player:setVar("TRIB_FIGHT",0);
	-- Handle Token Quest
    elseif ((player:getVar("AYAME_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Cur") == 0)) then
      player:PrintToPlayer("Ayame : Bring me 1 of my Trust Tokens and 1,000 gil to raise my Attack by 5",0x0D);
    elseif ((player:getVar("AYAME_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Cur") == 1)) then
      player:PrintToPlayer("Ayame : Bring me 2 of my Trust Tokens and 2,000 gil to raise my Accuracy by 5",0x0D);
    elseif ((player:getVar("AYAME_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Cur") == 2)) then
      player:PrintToPlayer("Ayame : Bring me 3 of my Trust Tokens and 3,000 gil to raise my Store TP by 5",0x0D);
    elseif ((player:getVar("AYAME_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Cur") == 3)) then
      player:PrintToPlayer("Ayame : Bring me 4 of my Trust Tokens and 4,000 gil to raise my Attack by 5",0x0D);
    elseif ((player:getVar("AYAME_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Cur") == 4)) then
      player:PrintToPlayer("Ayame : Bring me 5 of my Trust Tokens and 5,000 gil to raise my Accuracy by 5",0x0D);
    elseif ((player:getVar("AYAME_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Cur") == 5)) then
      player:PrintToPlayer("Ayame : Bring me 10 of my Trust Tokens and 10,000 gil to raise my Store TP by 5",0x0D);
    elseif ((player:getVar("AYAME_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Cur") == 6)) then
      player:PrintToPlayer("Ayame : Bring me 15 of my Trust Tokens and 15,000 gil to raise my Attack by 5",0x0D);
    elseif ((player:getVar("AYAME_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Cur") == 7)) then
      player:PrintToPlayer("Ayame : Bring me 20 of my Trust Tokens and 30,000 gil to raise my Accuracy by 5",0x0D);
    elseif ((player:getVar("AYAME_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Cur") == 8)) then
      player:PrintToPlayer("Ayame : Bring me 30 of my Trust Tokens and 75,000 gil to increase by Zanshin by 5",0x0D);
    elseif ((player:getVar("AYAME_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Cur") == 9)) then
      player:PrintToPlayer("Ayame : Bring me 35 of my Trust Tokens and 150,000 gil so I can Meditate by 20 TP",0x0D);
    end	
	
	
	
	
	
	
	if (player:getQuestStatus(BASTOK,LURE_OF_THE_WILDCAT_BASTOK) == QUEST_ACCEPTED and player:getMaskBit(WildcatBastok,9) == false) then
		player:startEvent(0x03a7);
	elseif (player:getCurrentMission(BASTOK) == THE_CRYSTAL_LINE and player:hasKeyItem(C_L_REPORTS)) then
		player:startEvent(0x02c8);
	elseif (trueStrength == QUEST_AVAILABLE and player:getMainJob() == 2 and player:getMainLvl() >= 50) then
		player:startEvent(0x02ec); -- Start Quest "True Strength"
	else
		player:startEvent(0x02bd); -- Standard dialog
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

	if (csid == 0x02c8) then
		finishMissionTimeline(player,1,csid,option);
	elseif (csid == 0x02ec) then
		player:addQuest(BASTOK,TRUE_STRENGTH);
	elseif (csid == 0x02ed) then
		if (player:getFreeSlotsCount() == 0) then 
			player:messageSpecial(ITEM_CANNOT_BE_OBTAINED,14215); -- Temple Hose
		else
			player:tradeComplete();
			player:addTitle(PARAGON_OF_MONK_EXCELLENCE);
			player:addItem(14215);
			player:messageSpecial(ITEM_OBTAINED,14215); -- Temple Hose
			player:addFame(BASTOK,AF3_FAME);
			player:completeQuest(BASTOK,TRUE_STRENGTH);
		end
	elseif (csid == 0x03a7) then
		player:setMaskBit(player:getVar("WildcatBastok"),"WildcatBastok",9,true);
	end
	
end;