-----------------------------------
-- Area: Heaven's Tower
-- NPC:  Kupipi
-- Involved in Mission 2-3
-- Involved in Quest: Riding on the Clouds
-- @pos 2 0.1 30 242
-----------------------------------
package.loaded["scripts/zones/Heavens_Tower/TextIDs"] = nil;
-----------------------------------

require("scripts/globals/keyitems");
require("scripts/globals/quests");
require("scripts/globals/missions");
require("scripts/zones/Heavens_Tower/TextIDs");

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)

    local currentTokens = player:getVar("CurrentTokens_Kup");
	
	if (player:getQuestStatus(JEUNO,RIDING_ON_THE_CLOUDS) == QUEST_ACCEPTED and player:getVar("ridingOnTheClouds_4") == 8) then
		if (trade:hasItemQty(1127,1) and trade:getItemCount() == 1) then -- Trade Kindred seal
			player:setVar("ridingOnTheClouds_4",0);
			player:tradeComplete();
			player:addKeyItem(SPIRITED_STONE);
			player:messageSpecial(KEYITEM_OBTAINED,SPIRITED_STONE);
		end
	end
	if (trade:hasItemQty(4365,1) and trade:getItemCount() == 1 and player:getNation() == WINDURST and player:getRank() >= 2 and player:hasKeyItem(PORTAL_CHARM) == false) then -- Trade Rolanberry
		if (player:hasCompletedMission(WINDURST,WRITTEN_IN_THE_STARS)) then
			player:startEvent(0x0123); -- Qualifies for the reward immediately
		else
			player:startEvent(0x0124); -- Kupipi owes you the portal charm later
		end
	end

    if ((player:getVar("KUPIPI_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Kup") == 0) and (trade:hasItemQty(65535, 1000)) and (currentTokens >= 1)) then
      player:PrintToPlayer("Kupipi : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Kupipi's Attack is raised by 5 points! (Total: 5)", 0x15);
	  player:setVar("TrustAtt_Kup",5);
	  player:setVar("TributeRank_Kup",1);
	  currentTokens = currentTokens - 1;
	  player:setVar("CurrentTokens_Kup",currentTokens);
    elseif ((player:getVar("KUPIPI_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Kup") == 1) and (trade:hasItemQty(65535, 2000)) and (currentTokens >= 2)) then
	  player:PrintToPlayer("Kupipi : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Kupipi's Accuracy is raised by 5 points! (Total: 5)", 0x15);
	  player:setVar("TrustAcc_Kup",5);	
	  player:setVar("TributeRank_Kup",2);
	  currentTokens = currentTokens - 2;
	  player:setVar("CurrentTokens_Kup",currentTokens);	  
    elseif ((player:getVar("KUPIPI_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Kup") == 2) and (trade:hasItemQty(65535, 3000)) and (currentTokens >= 3)) then
      player:PrintToPlayer("Kupipi : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Kupipi's Cure Potency is raised by 2%! (Total: 2%)", 0x15);
	  player:setVar("TrustCure_Kup",2);	
	  player:setVar("TributeRank_Kup",3);
	  currentTokens = currentTokens - 3;
	  player:setVar("CurrentTokens_Kup",currentTokens);	  
    elseif ((player:getVar("KUPIPI_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Kup") == 3) and (trade:hasItemQty(65535, 4000)) and (currentTokens >= 4)) then
      player:PrintToPlayer("Kupipi : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Kupipi's Cure Spellcasting Time is reduced by 4%! (Total: 4%)", 0x15);
	  player:setVar("TrustCast_Kup",4);	
	  player:setVar("TributeRank_Kup",4);
	  currentTokens = currentTokens - 4;
	  player:setVar("CurrentTokens_Kup",currentTokens);	  
    elseif ((player:getVar("KUPIPI_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Kup") == 4) and (trade:hasItemQty(65535, 5000)) and (currentTokens >= 5)) then
      player:PrintToPlayer("Kupipi : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Kupipi's Attack is raised by 5 points! (Total: 10)", 0x15);
	  player:setVar("TrustAtt_Kup",10);	
	  player:setVar("TributeRank_Kup",5);
	  currentTokens = currentTokens - 5;
	  player:setVar("CurrentTokens_Kup",currentTokens);	  
    elseif ((player:getVar("KUPIPI_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Kup") == 5) and (trade:hasItemQty(65535, 10000)) and (currentTokens >= 10)) then
      player:PrintToPlayer("Kupipi : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Kupipi's Accuracy is raised by 5 points! (Total: 10)", 0x15);
	  player:setVar("TrustAcc_Kup",10);	
	  player:setVar("TributeRank_Kup",6);
	  currentTokens = currentTokens - 10;
	  player:setVar("CurrentTokens_Kup",currentTokens);	  
    elseif ((player:getVar("KUPIPI_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Kup") == 6) and (trade:hasItemQty(65535, 15000)) and (currentTokens >= 15)) then
      player:PrintToPlayer("Kupipi : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Kupipi's Cure Potency is raised by 3%! (Total: 5%)", 0x15);
	  player:setVar("TrustCure_Kup",5);	
	  player:setVar("TributeRank_Kup",7);
	  currentTokens = currentTokens - 15;
	  player:setVar("CurrentTokens_Kup",currentTokens);	  
    elseif ((player:getVar("KUPIPI_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Kup") == 7) and (trade:hasItemQty(65535, 30000)) and (currentTokens >= 20)) then
      player:PrintToPlayer("Kupipi : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Kupipi's Cure Spellcasting Time is reduced by 4%! (Total: 8%)", 0x15);
	  player:setVar("TrustCast_Kup",8);	
	  player:setVar("TributeRank_Kup",8);
	  currentTokens = currentTokens - 20;
	  player:setVar("CurrentTokens_Kup",currentTokens);	  
    elseif ((player:getVar("KUPIPI_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Kup") == 8) and (trade:hasItemQty(65535, 75000)) and (currentTokens >= 30)) then
      player:PrintToPlayer("Kupipi : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Kupipi's learns the spell 'Protectra V!", 0x15);
	  player:setVar("TrustPro_Kup",1);	
	  player:setVar("TributeRank_Kup",9);	
	  currentTokens = currentTokens - 30;
	  player:setVar("CurrentTokens_Kup",currentTokens);	  
    elseif ((player:getVar("KUPIPI_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Kup") == 9) and (trade:hasItemQty(65535, 150000)) and (currentTokens >= 35)) then
      player:PrintToPlayer("Kupipi : Thank you for your Tribute.",0x0D);
      player:PrintToPlayer("Kupipi learns the spell 'Shellra V!", 0x15);
	  player:setVar("TrustShell_Kup",1);	
	  player:setVar("TributeRank_Kup",10);
	  currentTokens = currentTokens - 35;
	  player:setVar("CurrentTokens_Kup",currentTokens);	
    else
      player:PrintToPlayer("Kupipi : Please trade the correct amount of Tokens and Gil.",0x0D);	
	end		
	
end;

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)
	
	local pNation = player:getNation();
	local currentMission = player:getCurrentMission(pNation);
	local MissionStatus = player:getVar("MissionStatus");
	local tribfight = player:getVar("KUPIPI_TRIB_FIGHT");
	local mainlvl = player:getMainLvl();
	
	
	
    if (player:getNation() == 0) and (player:hasKeyItem(RED_INSTITUTE_CARD)) and (player:hasSpell(898) == false) and (player:hasCompletedMission(SANDORIA,SAVE_THE_CHILDREN) == true) then  -- Sandy Nation and mission 2-3 completed
	player:PrintToPlayer("Your Red Institute Card flashes brilliantly!", 0x1C);
    player:PrintToPlayer("Kupipi : Ah a Red Institute Card.  From now on, you can summon me to help you with your battles", 0xD);
    player:addSpell(898);	
	player:PrintToPlayer("You are now able to summon the trust Kupipi!", 0x15);		
    elseif (player:getNation() == 1) and (player:hasKeyItem(BLUE_INSTITUTE_CARD)) and (player:hasSpell(898) == false) and (player:hasCompletedMission(BASTOK,FETICHISM) == true) then  -- Bastok Nation and mission 2-3 completed
	player:PrintToPlayer("Your Blue Institute Card flashes brilliantly!", 0x1C);
    player:PrintToPlayer("Kupipi : Ah a Red Institute Card.  From now on, you can summon me to help you with your battles", 0xD);
    player:addSpell(898);
	player:PrintToPlayer("You are now able to summon the trust Kupipi!", 0x15);		
    elseif (player:getNation() == 2) and (player:hasKeyItem(GREEN_INSTITUTE_CARD)) and (player:hasSpell(898) == false) then  -- Windy Nation can obtain without pre-requisites
	player:PrintToPlayer("Your Green Institute Card flashes brilliantly!", 0x1C);
    player:PrintToPlayer("Kupipi : Ah a Green Institute Card.  From now on, you can summon me to help you with your battles", 0xD);
    player:addSpell(898);
	player:PrintToPlayer("You are now able to summon the trust Kupipi!", 0x15);	
    end
	
	
	
	if (pNation == SANDORIA) then
		-- San d'Oria Mission 2-3 Part I - Windurst > Bastok
		if (currentMission == JOURNEY_TO_WINDURST) then
			if (MissionStatus == 4) then
				player:startEvent(0x00ee,1,1,1,1,pNation);
			elseif (MissionStatus == 5) then
				player:startEvent(0x00f0);
			elseif (MissionStatus == 6) then
				player:startEvent(0x00f1);
			end
		-- San d'Oria Mission 2-3 Part II - Bastok > Windurst
		elseif (currentMission == JOURNEY_TO_WINDURST2) then
			if (MissionStatus == 7) then
				player:startEvent(0x00f2,1,1,1,1,0);
			elseif (MissionStatus == 8) then
				player:startEvent(0x00f3);
			elseif (MissionStatus == 9) then
				player:startEvent(0x00f6);
			elseif (MissionStatus == 10) then
				player:startEvent(0x00f7);
			end
		else
			player:startEvent(0x00fb);
		end
	elseif (pNation == BASTOK) then
		-- Bastok Mission 2-3 Part I - Windurst > San d'Oria
		if (currentMission == THE_EMISSARY_WINDURST) then
			if (MissionStatus == 3) then
				player:startEvent(0x00ee,1,1,1,1,pNation);
			elseif (MissionStatus <= 5) then
				player:startEvent(0x00f0);
			elseif (MissionStatus == 6) then
				player:startEvent(0x00f1);
			end
		-- Bastok Mission 2-3 Part II - San d'Oria > Windurst
		elseif (currentMission == THE_EMISSARY_WINDURST2) then
			if (MissionStatus == 7) then
				player:startEvent(0x00f2,1,1,1,1,pNation);
			elseif (MissionStatus == 8) then
				player:startEvent(0x00f3);
			elseif (MissionStatus == 9) then
				player:startEvent(0x00f4);
			elseif (MissionStatus == 10) then
				player:startEvent(0x00f5);
			end
		else
			player:startEvent(0x00fb);
		end
	elseif (pNation == WINDURST) then
		if (currentMission == THE_THREE_KINGDOMS and MissionStatus == 0) then
			player:startEvent(0x005F,0,0,0,LETTER_TO_THE_CONSULS_WINDURST);
		elseif (currentMission == THE_THREE_KINGDOMS and MissionStatus == 11) then
			player:startEvent(0x0065,0,0,ADVENTURERS_CERTIFICATE);
		elseif (currentMission == THE_THREE_KINGDOMS) then
			player:startEvent(0x0061);
		elseif (currentMission == TO_EACH_HIS_OWN_RIGHT and MissionStatus == 0) then
			player:startEvent(0x0067,0,0,STARWAY_STAIRWAY_BAUBLE);
		elseif (currentMission == TO_EACH_HIS_OWN_RIGHT and MissionStatus == 1) then
			player:startEvent(0x0068);
		elseif (player:getCurrentMission(WINDURST) == THE_JESTER_WHO_D_BE_KING and MissionStatus == 3) then
			player:startEvent(0x0146);
		elseif (player:hasCompletedMission(WINDURST,WRITTEN_IN_THE_STARS) and player:getVar("OwesPortalCharm") == 1) then
			player:startEvent(0x0125); -- Kupipi repays your favor
		else
			player:startEvent(0x00fb);
		end
	
	else
		player:startEvent(0x00fb);
	end
	
	    ------- Trust Fight --------
	if ((mainlvl >= 71 and tribfight == 0 and (player:hasSpell(898)) and (player:getVar("FerretoryAura") >= 7) and (player:getVar("TRIB_FIGHT") ~= 1))) then
	player:PrintToPlayer("Kupipi : There is someone running around claming to be me at Balgas.  Please head there and I'll join you.", 0xD);
    player:PrintToPlayer("Kupipi : When you are ready, examine the Burning Circle in Balgas Dias and call me to your side.", 0xD);
	player:setVar("KUPIPI_TRIB_FIGHT",1);
    player:setVar("TRIB_FIGHT",1);	
	elseif (mainlvl >= 75 and tribfight == 2 and (player:hasSpell(898))) then
	player:PrintToPlayer("Kupipi : You have done well to help with the imposter investigation.  I am in your debt.", 0xD);
	player:PrintToPlayer("You are now able to collect Trust Tokens for Kupipi!", 0x15);
	player:setVar("KUPIPI_TRIB_FIGHT",3);
    player:setVar("TRIB_FIGHT",0);	
	end
	
-- Handle Token Quest
  if ((player:getVar("KUPIPI_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Kup") == 0)) then
    player:PrintToPlayer("Kupipi : Bring me 1 of my Trust Tokens and 1,000 gil to raise my Attack by 5",0x0D);
  elseif ((player:getVar("KUPIPI_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Kup") == 1)) then
    player:PrintToPlayer("Kupipi : Bring me 2 of my Trust Tokens and 2,000 gil to raise my Accuracy by 5",0x0D);
  elseif ((player:getVar("KUPIPI_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Kup") == 2)) then
    player:PrintToPlayer("Kupipi : Bring me 3 of my Trust Tokens and 3,000 gil to raise my Cure Potency by 2%",0x0D);
  elseif ((player:getVar("KUPIPI_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Kup") == 3)) then
    player:PrintToPlayer("Kupipi : Bring me 4 of my Trust Tokens and 4,000 gil to lower my Cure Casting by 4%",0x0D);
  elseif ((player:getVar("KUPIPI_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Kup") == 4)) then
    player:PrintToPlayer("Kupipi : Bring me 5 of my Trust Tokens and 5,000 gil to raise my Attack by 5",0x0D);
  elseif ((player:getVar("KUPIPI_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Kup") == 5)) then
    player:PrintToPlayer("Kupipi : Bring me 10 of my Trust Tokens and 10,000 gil to raise my Accuracy by 5",0x0D);
  elseif ((player:getVar("KUPIPI_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Kup") == 6)) then
    player:PrintToPlayer("Kupipi : Bring me 15 of my Trust Tokens and 15,000 gil to raise Cure Potency by 3%",0x0D);
  elseif ((player:getVar("KUPIPI_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Kup") == 7)) then
    player:PrintToPlayer("Kupipi : Bring me 20 of my Trust Tokens and 30,000 gil to lower my Cure Casting by 4%",0x0D);
  elseif ((player:getVar("KUPIPI_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Kup") == 8)) then
    player:PrintToPlayer("Kupipi : Bring me 30 of my Trust Tokens and 75,000 gil so I can learn the spell 'Protectra V'",0x0D);
  elseif ((player:getVar("KUPIPI_TRIB_FIGHT") == 3) and (player:getVar("TributeRank_Kup") == 9)) then
    player:PrintToPlayer("Kupipi : Bring me 35 of my Trust Tokens and 150,000 gil so I can learn the spell 'Shellra V'",0x0D);
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
	
	if (csid == 0x00ee) then
		if (player:getNation() == BASTOK) then
			player:setVar("MissionStatus",4);
			player:addKeyItem(SWORD_OFFERING);
			player:messageSpecial(KEYITEM_OBTAINED,SWORD_OFFERING);
		else
			player:setVar("MissionStatus",5);
			player:addKeyItem(SHIELD_OFFERING);
			player:messageSpecial(KEYITEM_OBTAINED,SHIELD_OFFERING);
		end
	elseif (csid == 0x00f4 or csid == 0x00f6) then
		player:setVar("MissionStatus",10);
	elseif (csid == 0x00f2) then
		player:addKeyItem(DARK_KEY);
		player:messageSpecial(KEYITEM_OBTAINED,DARK_KEY);
		player:setVar("MissionStatus",8);
	elseif (csid == 0x005F) then
		player:setVar("MissionStatus",1);
		player:addKeyItem(LETTER_TO_THE_CONSULS_WINDURST);
		player:messageSpecial(KEYITEM_OBTAINED,LETTER_TO_THE_CONSULS_WINDURST);
	elseif (csid == 0x0067) then
		player:setVar("MissionStatus",1);
		player:addKeyItem(STARWAY_STAIRWAY_BAUBLE);
		player:messageSpecial(KEYITEM_OBTAINED,STARWAY_STAIRWAY_BAUBLE);
	elseif (csid == 0x0065) then
		finishMissionTimeline(player,1,csid,option);
	elseif (csid == 0x0123) then -- All condition met, grant Portal Charm
		player:tradeComplete();
		player:addKeyItem(PORTAL_CHARM);
		player:messageSpecial(KEYITEM_OBTAINED,PORTAL_CHARM);
	elseif (csid == 0x0124) then -- Traded rolanberry, but not all conditions met
		player:tradeComplete();
		player:setVar("OwesPortalCharm",1);
	elseif (csid == 0x0125) then -- Traded rolanberry before, and all conditions are now met
		player:setVar("OwesPortalCharm",0);
		player:addKeyItem(PORTAL_CHARM);
		player:messageSpecial(KEYITEM_OBTAINED,PORTAL_CHARM);
	elseif (csid == 0x0146) then
		player:setVar("MissionStatus",4);
	end
	
end;