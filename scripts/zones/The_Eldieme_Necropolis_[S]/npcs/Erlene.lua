-----------------------------------
-- Area: The Eldieme Necropolis (S)
-- NPC:  Erlene
-- Involved in Quest: "A Little Knowledge"
-- @pos 376.936 -39.999 17.914 175
-----------------------------------
package.loaded["scripts/zones/The_Eldieme_Necropolis_[S]/TextIDs"] = nil;
-----------------------------------

require("scripts/zones/The_Eldieme_Necropolis_[S]/TextIDs");
require("scripts/globals/keyitems");
require("scripts/globals/quests");
require("scripts/globals/titles");
require("scripts/globals/settings");
require("scripts/globals/status");

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)
    local ALittleKnowledge = player:getQuestStatus(CRYSTAL_WAR, A_LITTLE_KNOWLEDGE);
    local ALittleKnowledgeProgress = player:getVar("ALittleKnowledge");
    local currentTokens = player:getVar("CurrentTokens_Adel"); 	

    if (ALittleKnowledge == QUEST_ACCEPTED and ALittleKnowledgeProgress == 1) then
        if (trade:hasItemQty(2550, 12) and trade:getGil() == 0 and trade:getItemCount() == 12) then
            if( player:getMainJob() == JOB_BLM or
                player:getMainJob() == JOB_RDM or
                player:getMainJob() == JOB_SMN or
                player:getMainJob() == JOB_BLU) then
                player:startEvent(0x000C, 1);
            else
                player:startEvent(0x000C);
            end
        end
    end
	
   
	
	if ((player:getVar("ADEL_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Adel") == 0) and (trade:hasItemQty(65535, 1000)) and (currentTokens >= 1)) then
      player:PrintToPlayer("Erlene : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Adelheid's Magic Attack is raised by 5 points! (Total: 5)", 0x15);
	  player:setVar("TrustMatt_Adel",5);
	  player:setVar("TributeRank_Adel",1);
	  currentTokens = currentTokens - 1;
	  player:setVar("CurrentTokens_Adel",currentTokens);
    elseif ((player:getVar("ADEL_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Adel") == 1) and (trade:hasItemQty(65535, 2000)) and (currentTokens >= 2)) then
	  player:PrintToPlayer("Erlene : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Adelheid's Magic Accuracy is raised by 2 points! (Total: 2)", 0x15);
	  player:setVar("TrustMacc_Adel",2);	
	  player:setVar("TributeRank_Adel",2);
	  currentTokens = currentTokens - 2;
	  player:setVar("CurrentTokens_Adel",currentTokens);	  
    elseif ((player:getVar("ADEL_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Adel") == 2) and (trade:hasItemQty(65535, 3000)) and (currentTokens >= 3)) then
      player:PrintToPlayer("Erlene : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Adelheid's MP is raised by 5 points! (Total: 5)", 0x15);
	  player:setVar("TrustMP_Adel",10);	
	  player:setVar("TributeRank_Adel",3);
	  currentTokens = currentTokens - 3;
	  player:setVar("CurrentTokens_Adel",currentTokens);	  
    elseif ((player:getVar("ADEL_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Adel") == 3) and (trade:hasItemQty(65535, 4000)) and (currentTokens >= 4)) then
      player:PrintToPlayer("Erlene : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Adelheid's Magic Attack is raised by 3 points! (Total: 5)", 0x15);
	  player:setVar("TrustMatt_Adel",5);	
	  player:setVar("TributeRank_Adel",4);
	  currentTokens = currentTokens - 4;
	  player:setVar("CurrentTokens_Adel",currentTokens);	  
    elseif ((player:getVar("ADEL_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Adel") == 4) and (trade:hasItemQty(65535, 5000)) and (currentTokens >= 5)) then
      player:PrintToPlayer("Erlene : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Adelheid's Magic Accuracy is raised by 5 points! (Total: 10)", 0x15);
	  player:setVar("TrustMacc_Adel",10);	
	  player:setVar("TributeRank_Adel",5);
	  currentTokens = currentTokens - 5;
	  player:setVar("CurrentTokens_Adel",currentTokens);	  
    elseif ((player:getVar("ADEL_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Adel") == 5) and (trade:hasItemQty(65535, 10000)) and (currentTokens >= 10)) then
      player:PrintToPlayer("Erlene : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Adelheid's MP is raised by 10 points! (Total: 15)", 0x15);
	  player:setVar("TrustMP_Adel",15);	
	  player:setVar("TributeRank_Adel",6);
	  currentTokens = currentTokens - 10;
	  player:setVar("CurrentTokens_Adel",currentTokens);	  
    elseif ((player:getVar("ADEL_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Adel") == 6) and (trade:hasItemQty(65535, 15000)) and (currentTokens >= 15)) then
      player:PrintToPlayer("Erlene : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Adelheid's Magic Attack is raised by 5 points! (Total: 15)", 0x15);
	  player:setVar("TrustMatt_Adel",15);	
	  player:setVar("TributeRank_Adel",7);
	  currentTokens = currentTokens - 15;
	  player:setVar("CurrentTokens_Adel",currentTokens);	  
    elseif ((player:getVar("ADEL_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Adel") == 7) and (trade:hasItemQty(65535, 30000)) and (currentTokens >= 20)) then
      player:PrintToPlayer("Erlene : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Adelheid's Magic Accuracy is raised by 5 points! (Total: 15)", 0x15);
	  player:setVar("TrustMacc_Adel",15);	
	  player:setVar("TributeRank_Adel",8);
	  currentTokens = currentTokens - 20;
	  player:setVar("CurrentTokens_Adel",currentTokens);	  
    elseif ((player:getVar("ADEL_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Adel") == 8) and (trade:hasItemQty(65535, 75000)) and (currentTokens >= 30)) then
      player:PrintToPlayer("Erlene : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Adelheid's MP is raised by 15! (Total: 30)", 0x15);
	  player:setVar("TrustMP_Adel",30);	
	  player:setVar("TributeRank_Adel",9);	
	  currentTokens = currentTokens - 30;
	  player:setVar("CurrentTokens_Adel",currentTokens);	  
    elseif ((player:getVar("ADEL_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Adel") == 9) and (trade:hasItemQty(65535, 150000)) and (currentTokens >= 35)) then
      player:PrintToPlayer("Erlene : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Adelheid's Sublimiation Effect has increased by 2", 0x15);
	  player:setVar("TrustSub_Adel",2);	
	  player:setVar("TributeRank_Adel",10);
	  currentTokens = currentTokens - 35;
	  player:setVar("CurrentTokens_Adel",currentTokens);	
    else
      player:PrintToPlayer("Erlene : Please trade the correct amount of Tokens and Gil.",0x0D);	
	end		
end;

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)

    local ALittleKnowledge = player:getQuestStatus(CRYSTAL_WAR, A_LITTLE_KNOWLEDGE);
    local ALittleKnowledgeProgress = player:getVar("ALittleKnowledge");
    local mLvl = player:getMainLvl();
    local mJob = player:getMainJob();
    local onSabbatical = player:getQuestStatus(CRYSTAL_WAR,ON_SABBATICAL);
    local onSabbaticalProgress = player:getVar("OnSabbatical");
    local downwardHelix = player:getQuestStatus(CRYSTAL_WAR, DOWNWARD_HELIX);
	local mainlvl = player:getMainLvl();
    local tribfight = player:getVar("ADEL_TRIB_FIGHT");	

    if (ALittleKnowledge == QUEST_AVAILABLE) then
        if (mLvl >= ADVANCED_JOB_LEVEL) then
            player:startEvent(0x000A,1);
        else
            player:startEvent(0x000A);
        end
    elseif (ALittleKnowledgeProgress == 1 and ALittleKnowledge == QUEST_ACCEPTED) then
        player:startEvent(0x000B);
    elseif (ALittleKnowledgeProgress == 2 and ALittleKnowledge == QUEST_ACCEPTED) then
        if (player:hasStatusEffect(EFFECT_MANAFONT) or
            player:hasStatusEffect(EFFECT_CHAINSPELL) or
            player:hasStatusEffect(EFFECT_ASTRAL_FLOW) or
            player:hasStatusEffect(EFFECT_AZURE_LORE)) then
            player:startEvent(0x000E);
        else
            player:startEvent(0x000D);
        end
    elseif (ALittleKnowledge == QUEST_COMPLETED and mJob == JOB_SCH and mLvl >= 5 and not (player:hasSpell(478) and player:hasSpell(502))) then
            player:startEvent(0x002F);   
    elseif (onSabbatical == QUEST_AVAILABLE and mJob == JOB_SCH and mLvl >= AF1_QUEST_LEVEL) then
            player:startEvent(0x0012);
    elseif (onSabbatical == QUEST_ACCEPTED) then
        if (onSabbaticalProgress < 3) then
            player:startEvent(0x0013);
        else
            player:startEvent(0x0014);
        end
    elseif (onSabbatical == QUEST_COMPLETED and player:getVar("Erlene_Sabbatical_Timer")~=VanadielDayOfTheYear() and mJob == JOB_SCH and mLvl >= AF2_QUEST_LEVEL and downwardHelix == QUEST_AVAILABLE) then
        player:startEvent(0x0017);
	elseif (onSabbatical == QUEST_COMPLETED and mJob == JOB_SCH and player:getVar("SCHAFstaff") ~= 1) then           
			player:addItem(17098, 1, 296, 0);
            player:messageSpecial(ITEM_OBTAINED, 17098);
            player:setVar("SCHAFstaff",1);			
    elseif (downwardHelix == QUEST_ACCEPTED) then
        if (player:getVar("DownwardHelix") == 0) then
            player:startEvent(0x0018);
        elseif (player:getVar("DownwardHelix") == 1) then
            player:startEvent(0x0019);
        elseif (player:getVar("DownwardHelix") < 4) then
            player:startEvent(0x001A);
        else
            player:startEvent(0x001B);
        end
    else
        player:startEvent(0x000F);
    end
	
	if (player:getMainJob() == 20) and (player:hasSpell(968) == false) and (player:getMainLvl() >= 15) then
	player:addItem(10153);
    player:messageSpecial(ITEM_OBTAINED,10153);
	player:setVar("TrustMB",10);
	end
    if ((mainlvl >= 75 and tribfight == 0 and (player:hasSpell(968)) and (player:getVar("FerretoryAura") >= 7)) and (player:getVar("TRIB_FIGHT") ~= 1)) then
	player:PrintToPlayer("Erlene : There is someone running around claming to be Adelheid at Fei'Yin.  Please head there and I'll join you.", 0xD);
    player:PrintToPlayer("Erlene : When you are ready, examine the Burning Circle in QuBai Arena and Adelheid to your side.", 0xD);
	player:setVar("ADEL_TRIB_FIGHT",1);
	player:setVar("TRIB_FIGHT",1);
	elseif (mainlvl >= 75 and tribfight == 2 and (player:hasSpell(968))) then
	player:PrintToPlayer("Erlene : You have done well to help with the imposter investigation.  I am in your debt.", 0xD);
	player:PrintToPlayer("You are now able to collect Trust Tokens for Adelheid!", 0x15);
	player:setVar("ADEL_TRIB_FIGHT",3);	
	player:setVar("TRIB_FIGHT",0);
	end
	
-- Handle Token Quest
  if ((player:getVar("ADEL_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Adel") == 0)) then
    player:PrintToPlayer("Nareema : Bring me 1 of Adelheid's Trust Tokens and 1,000 gil to raise Adelheid's Magic Attack by 5",0x0D);
  elseif ((player:getVar("ADEL_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Adel") == 1)) then
    player:PrintToPlayer("Nareema : Bring me 2 of Adelheid's Trust Tokens and 2,000 gil to raise Adelheid's Magic Accuracy by 5",0x0D);
  elseif ((player:getVar("ADEL_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Adel") == 2)) then
    player:PrintToPlayer("Nareema : Bring me 3 of Adelheid's Trust Tokens and 3,000 gil to raise Adelheid's MP by 5",0x0D);
  elseif ((player:getVar("ADEL_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Adel") == 3)) then
    player:PrintToPlayer("Nareema : Bring me 4 of Adelheid's Trust Tokens and 4,000 gil to raise Adelheid's Magic Attack by 5",0x0D);
  elseif ((player:getVar("ADEL_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Adel") == 4)) then
    player:PrintToPlayer("Nareema : Bring me 5 of Adelheid's Trust Tokens and 5,000 gil to raise Adelheid's Magic Accuracy by 5",0x0D);
  elseif ((player:getVar("ADEL_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Adel") == 5)) then
    player:PrintToPlayer("Nareema : Bring me 10 of Adelheid's Trust Tokens and 10,000 gil to raise Adelheid's MP by 10",0x0D);
  elseif ((player:getVar("ADEL_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Adel") == 6)) then
    player:PrintToPlayer("Nareema : Bring me 15 of Adelheid's Trust Tokens and 15,000 gil to raise Adelheid's Magic Attack by 5",0x0D);
  elseif ((player:getVar("ADEL_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Adel") == 7)) then
    player:PrintToPlayer("Nareema : Bring me 20 of Adelheid's Trust Tokens and 30,000 gil to raise Adelheid's Magic Accuracy by 5",0x0D);
  elseif ((player:getVar("ADEL_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Adel") == 8)) then
    player:PrintToPlayer("Nareema : Bring me 30 of Adelheid's Trust Tokens and 75,000 gil to raise Adelheid's MP by 10",0x0D);
  elseif ((player:getVar("ADEL_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Adel") == 9)) then
    player:PrintToPlayer("Nareema : Bring me 35 of Adelheid's Trust Tokens and 150,000 gil to grant a Sublimation Bonus of +2",0x0D);
  end		
    
end; 

-----------------------------------
-- onEventUpdate
-----------------------------------

function onEventUpdate(player,csid,option)
-- printf("CSID: %u",csid);
-- printf("RESULT: %u",option);
end;

-----------------------------------
-- onEventFinish
-----------------------------------

function onEventFinish(player,csid,option)
-- printf("CSID: %u",csid);
-- printf("RESULT: %u",option);
    
    if (csid == 0x000A and option == 0) then
        player:addQuest(CRYSTAL_WAR, A_LITTLE_KNOWLEDGE);
        player:setVar("ALittleKnowledge", 1);
    elseif (csid == 0x000C) then
        player:tradeComplete();
        player:setVar("ALittleKnowledge", 2);
    elseif (csid == 0x000E) then
        player:addKeyItem(GRIMOIRE);
        player:unlockJob(JOB_SCH);
        player:addTitle(SCHULTZ_SCHOLAR);
        player:setVar("ALittleKnowledge", 0);
        player:setVar("SheetsofVellum", 0);
        player:messageSpecial(YOU_CAN_NOW_BECOME_A_SCHOLAR);
        player:completeQuest(CRYSTAL_WAR, A_LITTLE_KNOWLEDGE);
    elseif (csid == 0x002F) then
        if (player:canLearnSpell(478) and player:canLearnSpell(502)) then
            player:addSpell(478, true);
            player:addSpell(502, true);
            player:messageSpecial(YOU_LEARN_EMBRAVA_AND_KAUSTRA);
        end
    elseif (csid == 0x0012) then
        player:addQuest(CRYSTAL_WAR, ON_SABBATICAL);
        player:addKeyItem(ULBRECHTS_SEALED_LETTER);
        player:messageSpecial(KEYITEM_OBTAINED, ULBRECHTS_SEALED_LETTER);
        player:setVar("OnSabbatical", 1);
    elseif (csid == 0x0014) then
        if (player:getFreeSlotsCount() == 0) then
            player:messageSpecial(ITEM_CANNOT_BE_OBTAINED);
        else
            player:delKeyItem(ULBRECHTS_SEALED_LETTER);
            player:delKeyItem(SCHULTS_SEALED_LETTER);
            player:completeQuest(CRYSTAL_WAR,ON_SABBATICAL);
            player:addItem(6058); --klimaform
			player:addItem(17098, 1, 296, 0);
            player:messageSpecial(ITEM_OBTAINED, 6058);
            player:messageSpecial(ITEM_OBTAINED, 17098);			
            player:setVar("onSabbatical",0);
            player:setVar("Erlene_Sabbatical_Timer",VanadielDayOfTheYear());
        end
    elseif (csid == 0x0017) then
        player:setVar("Erlene_Sabbatical_Timer",0);
        player:addQuest(CRYSTAL_WAR, DOWNWARD_HELIX);
    elseif (csid == 0x0019) then
        player:setVar("DownwardHelix",2);
    elseif (csid == 0x001B) then
        if (player:getFreeSlotsCount() == 0) then
            player:messageSpecial(ITEM_CANNOT_BE_OBTAINED);
        else
            player:completeQuest(CRYSTAL_WAR, DOWNWARD_HELIX);
            player:addItem(15004); -- Schlar's Bracers
            player:messageSpecial(ITEM_OBTAINED, 15004);
            player:setVar("DownwardHelix",0);
        end
    end
end;
