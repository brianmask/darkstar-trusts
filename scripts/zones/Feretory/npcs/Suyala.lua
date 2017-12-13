-----------------------------------
-- Area: Ferretory
-- NPC: Maccus
-- Grants Aura Quests (aura is like fame)
-----------------------------------
package.loaded["scripts/zones/Heavens_Tower/TextIDs"] = nil;
-----------------------------------

require("scripts/zones/Heavens_Tower/TextIDs");
require("scripts/globals/missions");

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)

local balance = 0;
local quest11 = 10000; 
local pinfamy = player:getCurrency("infamy");

if (trade:hasItemQty( 613, 1 )) and (player:getVar("FerretoryQuest75noaura") == 11) then 
    if (pinfamy >= quest11) then   
    player:delCurrency("infamy", quest11);
    player:tradeComplete();
	player:PrintToPlayer("Your infamy cap and bonus multiplier have increased.  You can now access Achievement NPC's!", 0x15);
	player:setVar("infamymult",20);
	player:setVar("infamycap",200000);
	player:setVar("FerretoryQuest75",12); -- New Non Aura Quests
	else
    balance = quest11 - pinfamy; 
    player:PrintToPlayer( "Macus : I'm sorry, you need "..balance.." more infamy.", 0xD);
    end
	end
	
	
if (player:getVar("WARHAFight") == 2) and (trade:hasItemQty( 18505, 1 )) and (trade:hasItemQty( 3299, 50 )) then  -- WAR and Breeze Geode
    player:addItem(18505,1,143,1,59,14); 
	player:messageSpecial(ITEM_OBTAINED,18505);
	player:setVar("WARHAFight",2);
elseif (player:getVar("MNKHAFight") == 2) then  -- MNK
    player:addItem(18764,1,551,6,194,1,1027,1) 
	player:messageSpecial(ITEM_OBTAINED,18764);	
	player:setVar("MNKHAFight",2);	
elseif (player:getVar("WHMHAFight") == 2) then  -- WHM
    player:addItem(18870,1,559,6,374,9,1067,1) 
	player:messageSpecial(ITEM_OBTAINED,18870);		
	player:setVar("WHMHAFight",2);
elseif (player:getVar("BLMHAFight") == 2) then  -- BLM
    player:addItem(18589,1,559,6,311,4,1071,1) 
	player:messageSpecial(ITEM_OBTAINED,18589);		
	player:setVar("BLMHAFight",2);
elseif (player:getVar("RDMHAFight") == 2) then  -- RDM
    player:addItem(17761,1,559,6,896,1,1035,1) 
	player:messageSpecial(ITEM_OBTAINED,17761);		
	player:setVar("RDMHAFight",2);	
elseif (player:getVar("THFHAFight") == 2) then  -- THF
    player:addItem(19115,1,553,6,303,0,1031,1) 
	player:messageSpecial(ITEM_OBTAINED,19115);		
	player:setVar("THFHAFight",2);
elseif (player:getVar("PLDHAFight") == 2) then  -- PLD
    player:addItem(17762,1,559,6,370,0,1035,1) 
	player:messageSpecial(ITEM_OBTAINED,17762);		
	player:setVar("PLDHAFight",2);
elseif (player:getVar("DRKHAFight") == 2) then  -- DRK
    player:addItem(18955,1,558,6,315,9,1051,1) 
	player:messageSpecial(ITEM_OBTAINED,18955);		
	player:setVar("DRKHAFight",2);
elseif (player:getVar("BSTHAFight") == 2) then  -- BST
    player:addItem(17966,1,550,6,124,6,1043,1) 
	player:messageSpecial(ITEM_OBTAINED,17966);		
	player:setVar("BSTHAFight",2);
elseif (player:getVar("BRDHAFight") == 2) then  -- BRD
    player:addItem(19116,1,513,6,518,6,455,4,1031,1) 
	player:messageSpecial(ITEM_OBTAINED,19116);		
	player:setVar("BRDHAFight",2);
elseif (player:getVar("RNGHAFight") == 2) then  -- RNG
    player:addItem(18763,1,552,6,359,4,1075,1) 
	player:messageSpecial(ITEM_OBTAINED,18763);		
	player:setVar("RNGHAFight",2);
elseif (player:getVar("SAMHAFight") == 2) then  -- SAM
    player:addItem(18452,1,512,6,353,2,1063,1) 
	player:messageSpecial(ITEM_OBTAINED,18452);		
	player:setVar("SAMHAFight",2);	
elseif (player:getVar("NINHAFight") == 2) then  -- NIN
    player:addItem(19275,1,550,6,259,4,1059,1) 
	player:messageSpecial(ITEM_OBTAINED,19275);		
	player:setVar("NINHAFight",2);
elseif (player:getVar("DRGHAFight") == 2) then  -- DRG
    player:addItem(19303,1,512,6,124,6,1055,1) 
	player:messageSpecial(ITEM_OBTAINED,19303);		
	player:setVar("DRGHAFight",2);	
elseif (player:getVar("SMNHAFight") == 2) then  -- SMN
    player:addItem(18601,1,559,6,346,2,1071,1) 
	player:messageSpecial(ITEM_OBTAINED,18601);		
	player:setVar("SMNHAFight",2);
elseif (player:getVar("BLUHAFight") == 2) then  -- BLU
    player:addItem(17763,1,559,6,299,9,1035,1) 
	player:messageSpecial(ITEM_OBTAINED,17763);		
	player:setVar("BLUHAFight",2);		
elseif (player:getVar("CORHAFight") == 2) then  -- COR
    player:addItem(18737,1,550,6,133,14,1079,1) 
	player:messageSpecial(ITEM_OBTAINED,18737);		
	player:setVar("CORHAFight",2);
elseif (player:getVar("PUPHAFight") == 2) then  -- PUP
    player:addItem(18765,1,551,6,124,6,1027,1) 
	player:messageSpecial(ITEM_OBTAINED,18765);	
	player:setVar("PUPHAFight",2);
elseif (player:getVar("DNCHAFight") == 2) then  -- DNC
    player:addItem(19117,1,553,6,330,9,1031,1) 
	player:messageSpecial(ITEM_OBTAINED,19117);		
	player:setVar("DNCHAFight",2);	
elseif (player:getVar("SCHHAFight") == 2) then  -- SCH
    player:addItem(18602,1,559,6,1249,14,1071,1) 
	player:messageSpecial(ITEM_OBTAINED,18602);		
	player:setVar("SCHHAFight",2);	
-- Standard Message
end	

	
end; 

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)

	
	
	
	
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
end;



