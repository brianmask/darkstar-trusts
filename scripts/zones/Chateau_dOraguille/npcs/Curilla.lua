-----------------------------------
-- Area: Chateau d'Oraguille
-- NPC:  Curilla
-- Starts and Finishes Quest: The General's Secret, Enveloped in Darkness, Peace for the Spirit, Lure of the Wildcat (San d'Oria)
-- @pos 27 0.1 0.1 233
-----------------------------------
package.loaded["scripts/zones/Chateau_dOraguille/TextIDs"] = nil;
-----------------------------------

require("scripts/globals/settings");
require("scripts/globals/keyitems");
require("scripts/globals/quests");
require("scripts/zones/Chateau_dOraguille/TextIDs");

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)

    local currentTokens = player:getVar("CurrentTokens_Cur");
	
	if (player:getQuestStatus(SANDORIA,FLYERS_FOR_REGINE) == QUEST_ACCEPTED) then
		if (trade:hasItemQty(532,1) and trade:getItemCount() == 1) then -- Trade Magicmart_flyer
			player:messageSpecial(FLYER_REFUSED);
		end
	end
	
    if ((player:getVar("CURILLA_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Cur") == 0) and (trade:hasItemQty(65535, 1000)) and (currentTokens >= 1)) then
      player:PrintToPlayer("Curilla : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Curilla's Attack is raised by 5 points! (Total: 5)", 0x15);
	  player:setVar("TrustAtt_Cur",5);
	  player:setVar("TributeRank_Cur",1);
	  currentTokens = currentTokens - 1;
	  player:setVar("CurrentTokens_Cur",currentTokens);
    elseif ((player:getVar("CURILLA_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Cur") == 1) and (trade:hasItemQty(65535, 2000)) and (currentTokens >= 2)) then
	  player:PrintToPlayer("Curilla : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Curilla's Accuracy is raised by 5 points! (Total: 5)", 0x15);
	  player:setVar("TrustAcc_Cur",5);	
	  player:setVar("TributeRank_Cur",2);
	  currentTokens = currentTokens - 2;
	  player:setVar("CurrentTokens_Cur",currentTokens);	  
    elseif ((player:getVar("CURILLA_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Cur") == 2) and (trade:hasItemQty(65535, 3000)) and (currentTokens >= 3)) then
      player:PrintToPlayer("Curilla : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Curilla's Defense is raised by 10 points! (Total: 10)", 0x15);
	  player:setVar("TrustDEF_Cur",10);	
	  player:setVar("TributeRank_Cur",3);
	  currentTokens = currentTokens - 3;
	  player:setVar("CurrentTokens_Cur",currentTokens);	  
    elseif ((player:getVar("CURILLA_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Cur") == 3) and (trade:hasItemQty(65535, 4000)) and (currentTokens >= 4)) then
      player:PrintToPlayer("Curilla : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Curilla's Attack is raised by 5 points! (Total: 10)", 0x15);
	  player:setVar("TrustAtt_Cur",10);	
	  player:setVar("TributeRank_Cur",4);
	  currentTokens = currentTokens - 4;
	  player:setVar("CurrentTokens_Cur",currentTokens);	  
    elseif ((player:getVar("CURILLA_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Cur") == 4) and (trade:hasItemQty(65535, 5000)) and (currentTokens >= 5)) then
      player:PrintToPlayer("Curilla : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Curilla's Accuracy is raised by 5 points! (Total: 10)", 0x15);
	  player:setVar("TrustAcc_Cur",10);	
	  player:setVar("TributeRank_Cur",5);
	  currentTokens = currentTokens - 5;
	  player:setVar("CurrentTokens_Cur",currentTokens);	  
    elseif ((player:getVar("CURILLA_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Cur") == 5) and (trade:hasItemQty(65535, 10000)) and (currentTokens >= 10)) then
      player:PrintToPlayer("Curilla : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Curilla's Defense is raised by 10 points! (Total: 20)", 0x15);
	  player:setVar("TrustDEF_Cur",20);	
	  player:setVar("TributeRank_Cur",6);
	  currentTokens = currentTokens - 10;
	  player:setVar("CurrentTokens_Cur",currentTokens);	  
    elseif ((player:getVar("CURILLA_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Cur") == 6) and (trade:hasItemQty(65535, 15000)) and (currentTokens >= 15)) then
      player:PrintToPlayer("Curilla : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Curilla's Attack is raised by 5 points! (Total: 15)", 0x15);
	  player:setVar("TrustAtt_Cur",15);	
	  player:setVar("TributeRank_Cur",7);
	  currentTokens = currentTokens - 15;
	  player:setVar("CurrentTokens_Cur",currentTokens);	  
    elseif ((player:getVar("CURILLA_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Cur") == 7) and (trade:hasItemQty(65535, 30000)) and (currentTokens >= 20)) then
      player:PrintToPlayer("Curilla : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Curilla's Accuracy is raised by 5 points! (Total: 15)", 0x15);
	  player:setVar("TrustAcc_Cur",15);	
	  player:setVar("TributeRank_Cur",8);
	  currentTokens = currentTokens - 20;
	  player:setVar("CurrentTokens_Cur",currentTokens);	  
    elseif ((player:getVar("CURILLA_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Cur") == 8) and (trade:hasItemQty(65535, 75000)) and (currentTokens >= 30)) then
      player:PrintToPlayer("Curilla : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Curilla's Enmity is raised by 5 points! (Total: 5)", 0x15);
	  player:setVar("TrustEnm_Cur",5);	
	  player:setVar("TributeRank_Cur",9);	
	  currentTokens = currentTokens - 30;
	  player:setVar("CurrentTokens_Cur",currentTokens);	  
    elseif ((player:getVar("CURILLA_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Cur") == 9) and (trade:hasItemQty(65535, 150000)) and (currentTokens >= 35)) then
      player:PrintToPlayer("Curilla : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Curilla learns the ability 'Chivalry'!", 0x15);
	  player:setVar("TrustTrait1_Cur",5);	
	  player:setVar("TributeRank_Cur",10);
	  currentTokens = currentTokens - 35;
	  player:setVar("CurrentTokens_Cur",currentTokens);	
    else
      player:PrintToPlayer("Curilla : Please trade the correct amount of Tokens and Gil.",0x0D);	
	end	
	
end;

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)
	
	local mLvL = player:getMainLvl();
	local mJob = player:getMainJob();
	local theGeneralSecret = player:getQuestStatus(SANDORIA,THE_GENERAL_S_SECRET);
	local envelopedInDarkness = player:getQuestStatus(SANDORIA,ENVELOPED_IN_DARKNESS);
	local peaceForTheSpirit = player:getQuestStatus(SANDORIA,PEACE_FOR_THE_SPIRIT);
	local WildcatSandy = player:getVar("WildcatSandy");
	local wsnm = player:getVar("SAVAGE_BLADE");
    local mainlvl = player:getMainLvl();
    local skill = player:getSkillLevel(3);
	local pNation = player:getNation();
	local tribfight = player:getVar("CURILLA_TRIB_FIGHT");

	
	if (player:getQuestStatus(SANDORIA,LURE_OF_THE_WILDCAT_SAN_D_ORIA) == QUEST_ACCEPTED and player:getMaskBit(WildcatSandy,15) == false) then
		player:startEvent(0x0232);	
	elseif (player:getNation() == 0) and (player:hasKeyItem(SAN_DORIA_TRUST_PERMIT)) and (player:hasSpell(902) == false) then  -- Sandy Nation
	player:PrintToPlayer("Your Red Institute Card flashes brilliantly ", 0x1C);
    player:PrintToPlayer("Curilla : I humbly accept your request.  I will fight by your side", 0xD);
    player:addSpell(902);
	player:PrintToPlayer("You are now able to summon the trust Curilla!", 0x15);	
	elseif (player:getNation() == 1) and (player:hasKeyItem(BASTOK_TRUST_PERMIT)) and (player:hasSpell(902) == false) then  -- Bastok Nation
	player:PrintToPlayer("Your Blue Institute Card flashes brilliantly ", 0x1C);
    player:PrintToPlayer("Curilla : I humbly accept your request.  I will fight by your side", 0xD);
    player:addSpell(902);
	player:PrintToPlayer("You are now able to summon the trust Curilla!", 0x15);		
	elseif (pNation == WINDURST) and (player:hasKeyItem(WINDURST_TRUST_PERMIT)) and (player:hasSpell(902) == false) then  -- Windurst Nation
	player:PrintToPlayer("Your Green Institute Card flashes brilliantly ", 0x1C);
    player:PrintToPlayer("Curilla : I humbly accept your request.  I will fight by your side", 0xD);
    player:addSpell(902);
	player:PrintToPlayer("You are now able to summon the trust Curilla!", 0x15);
	elseif (mainlvl >= 71 and skill >= 240 and player:getQuestStatus(SANDORIA,OLD_WOUNDS) ~= QUEST_ACCEPTED and wsnm == nil) then
	   player:PrintToPlayer("Curilla : Savage Blade eh?  Use it 100 times and then come see me afterwards.",0x0D);
	   player:setVar("SAVAGE_BLADE",100);
	   player:addQuest(SANDORIA,OLD_WOUNDS);
    elseif (wsnm == 1) and (player:getQuestStatus(SANDORIA,OLD_WOUNDS) == QUEST_ACCEPTED) then
	   player:PrintToPlayer("Curilla : Good Job.  Take this to Quicksand Caves and kill the monster there.",0x0D);
	   player:addKeyItem(MAP_TO_THE_ANNALS_OF_TRUTH);
 	   player:messageSpecial(MAP_TO_THE_ANNALS_OF_TRUTH);
	   player:setVar("SAVAGE_BLADE_WIN",1);
    elseif (player:hasKeyItem(ANNALS_OF_TRUTH) and player:getVar("SAVAGE_BLADE_WIN") == 2) then
	   player:PrintToPlayer("Curilla : You have done well.  Savage Blade is now at full power!",0x0D);
	   player:delKeyItem(ANNALS_OF_TRUTH);
	   player:completeQuest(SANDORIA,OLD_WOUNDS);	
	elseif (theGeneralSecret == QUEST_AVAILABLE and player:getFameLevel(SANDORIA) >= 2) then
		player:startEvent(0x0037); -- Start Quest "The General's Secret"
	elseif (mJob == 5 and mLvL >= AF2_QUEST_LEVEL and player:getQuestStatus(SANDORIA,THE_CRIMSON_TRIAL) == QUEST_COMPLETED and envelopedInDarkness == QUEST_AVAILABLE) then
		player:startEvent(0x005E); -- Start Quest "Enveloped in Darkness"
	elseif (player:hasKeyItem(OLD_POCKET_WATCH) and player:hasKeyItem(OLD_BOOTS) == false) then
		player:startEvent(0x005D);
	elseif (player:hasKeyItem(OLD_BOOTS) and player:getVar("needs_crawler_blood") == 0) then
		player:startEvent(0x0065);
	elseif (player:getVar("needs_crawler_blood") == 1) then
		player:startEvent(0x0075);
	elseif (mJob == 5 and mLvL >= AF2_QUEST_LEVEL and envelopedInDarkness == QUEST_COMPLETED and peaceForTheSpirit == QUEST_AVAILABLE) then
		player:startEvent(0x006D); -- Start Quest "Peace for the Spirit"
	elseif (peaceForTheSpirit == QUEST_ACCEPTED) then
		player:startEvent(0x006C); -- Standard dialog during Peace of the spirit
	elseif (peaceForTheSpirit == QUEST_ACCEPTED and (player:getVar("peaceForTheSpiritCS") >= 2 and player:getVar("peaceForTheSpiritCS") <= 4)) then
		player:startEvent(0x0071);
	elseif (peaceForTheSpirit == QUEST_ACCEPTED and player:getVar("peaceForTheSpiritCS") == 5) then
		player:startEvent(0x0033);
	elseif (theGeneralSecret == QUEST_ACCEPTED and player:hasKeyItem(CURILLAS_BOTTLE_EMPTY)) then
		player:startEvent(0x0035);
	elseif (theGeneralSecret == QUEST_ACCEPTED and player:hasKeyItem(CURILLAS_BOTTLE_FULL)) then
		player:startEvent(0x0036);
	elseif (envelopedInDarkness == QUEST_COMPLETED and peaceForTheSpirit == QUEST_AVAILABLE) then
		player:startEvent(0x0072); -- Standard dialog after Enveloped in darkness
	elseif (peaceForTheSpirit == QUEST_COMPLETED) then
		player:startEvent(0x0034); -- Standard dialog after Peace of the spirit
	else
		player:startEvent(0x0212); -- Standard dialog
	end
	
	    ---------------------------- Curilla Tribute Unlock ----------------------------------
	if ((mainlvl >= 75 and tribfight == 0 and (player:hasSpell(902)) and (player:getVar("FerretoryAura") >= 7)) and (player:getVar("TRIB_FIGHT") ~= 1)) then
	player:PrintToPlayer("Curilla : There is someone running around claming to be me at Horlais Peak.  Please head there and I'll join you.", 0xD);
    player:PrintToPlayer("Curilla : When you are ready, examine the Burning Circle in Yughott Grotto and call me to your side.", 0xD);
	player:setVar("CURILLA_TRIB_FIGHT",1);
    player:setVar("TRIB_FIGHT",1);	
	elseif (mainlvl >= 75 and tribfight == 2 and (player:hasSpell(902))) then
	player:PrintToPlayer("Curilla : You have done well to help with the imposter investigation.  I am in your debt.", 0xD);
	player:PrintToPlayer("You are now able to collect Trust Tokens for Curilla!", 0x15);
	player:setVar("CURILLA_TRIB_FIGHT",3);
	player:setVar("TRIB_FIGHT",0);
	end
	
	-- Handle Token Quest
    if ((player:getVar("CURILLA_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Cur") == 0)) then
      player:PrintToPlayer("Curilla : Bring me 1 of my Trust Tokens and 1,000 gil to raise my Attack by 5",0x0D);
    elseif ((player:getVar("CURILLA_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Cur") == 1)) then
      player:PrintToPlayer("Curilla : Bring me 2 of my Trust Tokens and 2,000 gil to raise my Accuracy by 5",0x0D);
    elseif ((player:getVar("CURILLA_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Cur") == 2)) then
      player:PrintToPlayer("Curilla : Bring me 3 of my Trust Tokens and 3,000 gil to raise my Defense by 10",0x0D);
    elseif ((player:getVar("CURILLA_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Cur") == 3)) then
      player:PrintToPlayer("Curilla : Bring me 4 of my Trust Tokens and 4,000 gil to raise my Attack by 5",0x0D);
    elseif ((player:getVar("CURILLA_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Cur") == 4)) then
      player:PrintToPlayer("Curilla : Bring me 5 of my Trust Tokens and 5,000 gil to raise my Accuracy by 5",0x0D);
    elseif ((player:getVar("CURILLA_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Cur") == 5)) then
      player:PrintToPlayer("Curilla : Bring me 10 of my Trust Tokens and 10,000 gil to raise my Defense by 10",0x0D);
    elseif ((player:getVar("CURILLA_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Cur") == 6)) then
      player:PrintToPlayer("Curilla : Bring me 15 of my Trust Tokens and 15,000 gil to raise my Attack by 5",0x0D);
    elseif ((player:getVar("CURILLA_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Cur") == 7)) then
      player:PrintToPlayer("Curilla : Bring me 20 of my Trust Tokens and 30,000 gil to raise my Accuracy by 5",0x0D);
    elseif ((player:getVar("CURILLA_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Cur") == 8)) then
      player:PrintToPlayer("Curilla : Bring me 30 of my Trust Tokens and 75,000 gil to raise my Enmity by 5",0x0D);
    elseif ((player:getVar("CURILLA_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Cur") == 9)) then
      player:PrintToPlayer("Curilla : Bring me 35 of my Trust Tokens and 150,000 gil so I can learn Chivalry",0x0D);
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

	if (csid == 0x0037 and option == 1) then 
		player:addQuest(SANDORIA,THE_GENERAL_S_SECRET)
		player:addKeyItem(CURILLAS_BOTTLE_EMPTY);
		player:messageSpecial(KEYITEM_OBTAINED,CURILLAS_BOTTLE_EMPTY);
	elseif (csid == 0x0036) then 
		if (player:getFreeSlotsCount() == 0) then 
			player:messageSpecial(ITEM_CANNOT_BE_OBTAINED,16409); -- Lynx Baghnakhs
		else
			player:delKeyItem(CURILLAS_BOTTLE_FULL);
			player:addItem(16409);
			player:messageSpecial(ITEM_OBTAINED,16409); -- Lynx Baghnakhs
			player:addFame(SANDORIA,SAN_FAME*30);
			player:completeQuest(SANDORIA,THE_GENERAL_S_SECRET);
		end
	elseif (csid == 0x005E and option == 1) then
		player:addQuest(SANDORIA,ENVELOPED_IN_DARKNESS);
		player:addKeyItem(OLD_POCKET_WATCH);
		player:messageSpecial(KEYITEM_OBTAINED,OLD_POCKET_WATCH);
	elseif (csid == 0x006D and option == 1) then
		player:addQuest(SANDORIA,PEACE_FOR_THE_SPIRIT);
		player:setVar("needs_crawler_blood",0);
	elseif (csid == 0x0065) then 
		player:setVar("needs_crawler_blood",1);
	elseif (csid == 0x0232) then
		player:setMaskBit(player:getVar("WildcatSandy"),"WildcatSandy",15,true);
	end

end;
