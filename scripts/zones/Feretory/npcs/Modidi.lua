-----------------------------------
-- Area: Bibiki Bay
-- NPC:  ??? Spawns Mob for High Artifact
-- @pos -602 -3 -686
-----------------------------------
package.loaded["scripts/zones/Bibiki_Bay/TextIDs"] = nil;
-----------------------------------

require("scripts/zones/Bibiki_Bay/TextIDs");

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)
if (player:getVar("WARHAFight") == 2 and trade:hasItemQty(18505,1)) then
	player:PrintToPlayer("Daruru : I can unleash the full power of that weapon.  Trade me 200,000 infamy and 50 Shadow Geodes.", 0xD); 
elseif (player:getVar("MNKHAWeapon") == 2 and trade:hasItemQty(18764,1)) then

	player:PrintToPlayer("Your weapon begins to react violently!", 0xD); 
elseif (player:getVar("WHMHAWeapon") == 2 and trade:hasItemQty(18870,1)) then

	player:PrintToPlayer("Your weapon begins to react violently!", 0xD); 
elseif (player:getVar("BLMHAWeapon") == 2 and trade:hasItemQty(18589,1)) then

	player:PrintToPlayer("Your weapon begins to react violently!", 0xD); 
elseif (player:getVar("RDMHAWeapon") == 2 and trade:hasItemQty(17761,1)) then

	player:PrintToPlayer("Your weapon begins to react violently!", 0xD); 
elseif (player:getVar("THFHAWeapon") == 2 and trade:hasItemQty(19115,1)) then

	player:PrintToPlayer("Your weapon begins to react violently!", 0xD); 
elseif (player:getVar("PLDHAWeapon") == 2 and trade:hasItemQty(17762,1)) then

	player:PrintToPlayer("Your weapon begins to react violently!", 0xD); 
elseif (player:getVar("DRKHAWeapon") == 2 and trade:hasItemQty(18995,1)) then

	player:PrintToPlayer("Your weapon begins to react violently!", 0xD); 
elseif (player:getVar("BSTHAWeapon") == 2 and trade:hasItemQty(17966,1)) then

	player:PrintToPlayer("Your weapon begins to react violently!", 0xD); 
elseif (player:getVar("BRDHAWeapon") == 2 and trade:hasItemQty(19116,1)) then

	player:PrintToPlayer("Your weapon begins to react violently!", 0xD); 
elseif (player:getVar("RNGHAWeapon") == 2 and trade:hasItemQty(18763,1)) then

	player:PrintToPlayer("Your weapon begins to react violently!", 0xD); 
elseif (player:getVar("SAMHAWeapon") == 2 and trade:hasItemQty(18452,1)) then

	player:PrintToPlayer("Your weapon begins to react violently!", 0xD); 
elseif (player:getVar("NINHAWeapon") == 2 and trade:hasItemQty(19275,1)) then

	player:PrintToPlayer("Your weapon begins to react violently!", 0xD); 	
elseif (player:getVar("DRGHAWeapon") == 2 and trade:hasItemQty(19303,1)) then

	player:PrintToPlayer("Your weapon begins to react violently!", 0xD); 	
elseif (player:getVar("SMNHAWeapon") == 2 and trade:hasItemQty(18601,1)) then

	player:PrintToPlayer("Your weapon begins to react violently!", 0xD);
elseif (player:getVar("BLUHAWeapon") == 2 and trade:hasItemQty(17763,1)) then

	player:PrintToPlayer("Your weapon begins to react violently!", 0xD); 
elseif (player:getVar("CORHAWeapon") == 2 and trade:hasItemQty(18737,1)) then

	player:PrintToPlayer("Your weapon begins to react violently!", 0xD); 
elseif (player:getVar("PUPHAWeapon") == 2 and trade:hasItemQty(18765,1)) then

	player:PrintToPlayer("Your weapon begins to react violently!", 0xD);
elseif (player:getVar("DNCHAWeapon") == 2 and trade:hasItemQty(19117,1)) then

	player:PrintToPlayer("Your weapon begins to react violently!", 0xD); 
elseif (player:getVar("SCHHAWeapon") == 2 and trade:hasItemQty(18602,1)) then

	player:PrintToPlayer("Your weapon begins to react violently!", 0xD); 
	
-- turn in


elseif (player:getVar("WARHAFight") == 2 and trade:hasItemQty(18505,1) and trade:hasItemQty(3304,50)) then  -- Shadow Geodes
    player:tradeComplete();
	player:setVar("WARHAFight",3);
    player:addItem(18505,1,143,1,2047,90,59,0)  
	player:messageSpecial(ITEM_OBTAINED,18505);	
	player:PrintToPlayer("Daruru : Here you go, enjoy your new weapon!", 0xD); 
elseif (player:getVar("MNKHAFight") == 2 and trade:hasItemQty(18764,1) and trade:hasItemQty(3302,50)) then  -- Aqua Geodes
    player:tradeComplete();
	player:setVar("MNKHAFight",3);
    player:addItem(18764,1,194,1,890,12,59,0);  
	player:messageSpecial(ITEM_OBTAINED,18764);	
	player:PrintToPlayer("Daruru : Here you go, enjoy your new weapon!", 0xD); 
elseif (player:getVar("WHMHAFight") == 2 and trade:hasItemQty(18870,1) and trade:hasItemQty(3303,50)) then  -- Light Geodes
    player:tradeComplete();
	player:setVar("WHMHAFight",3);
    player:addItem(18870,1,329,9,890,171,59,0);
	player:messageSpecial(ITEM_OBTAINED,18870);	
	player:PrintToPlayer("Daruru : Here you go, enjoy your new weapon!", 0xD); 
elseif (player:getVar("BLMHAFight") == 2 and trade:hasItemQty(18589,1) and trade:hasItemQty(3304,50)) then  -- Shadow Geodes
    player:tradeComplete();
	player:setVar("BLMHAFight",3);    
    player:addItem(18589,1,362,4,890,188,59,0);
	player:messageSpecial(ITEM_OBTAINED,18589);		
	player:PrintToPlayer("Daruru : Here you go, enjoy your new weapon!", 0xD); 	
elseif (player:getVar("RDMHAFight") == 2 and trade:hasItemQty(17761,1) and trade:hasItemQty(3304,50)) then  -- Shadow Geodes
    player:tradeComplete();
	player:setVar("RDMHAFight",3);    
	player:addItem(17761,1,896,1,890,46,59,0) 
	player:messageSpecial(ITEM_OBTAINED,17761);		
	player:PrintToPlayer("Daruru : Here you go, enjoy your new weapon!", 0xD); 	
elseif (player:getVar("THFHAFight") == 2 and trade:hasItemQty(19115,1) and trade:hasItemQty(3299,50)) then -- Breeze Geodes
    player:tradeComplete();
	player:setVar("THFHAFight",3);
    player:addItem(19115,1,303,0,890,29,59,0)  
	player:messageSpecial(ITEM_OBTAINED,19115);	
	player:PrintToPlayer("Daruru : Here you go, enjoy your new weapon!", 0xD); 
elseif (player:getVar("PLDHAFight") == 2 and trade:hasItemQty(17762,1) and trade:hasItemQty(3304,50)) then  -- Shadow Geodes
    player:tradeComplete();
	player:setVar("PLDHAFight",3);    
	player:addItem(17762,1,370,0,890,46,59,0) 
	player:messageSpecial(ITEM_OBTAINED,17762);		
	player:PrintToPlayer("Daruru : Here you go, enjoy your new weapon!", 0xD); 	
elseif (player:getVar("DRKHAFight") == 2 and trade:hasItemQty(18995,1) and trade:hasItemQty(3304,50)) then  -- Shadow Geodes
    player:tradeComplete();
	player:setVar("DRKHAFight",3);    
	player:addItem(18995,1,343,9,890,106,59,0) 
	player:messageSpecial(ITEM_OBTAINED,18995);		
	player:PrintToPlayer("Daruru : Here you go, enjoy your new weapon!", 0xD); 
elseif (player:getVar("BSTHAFight") == 2 and trade:hasItemQty(17966,1) and trade:hasItemQty(3299,50)) then  -- Snow Geodes
    player:tradeComplete();
	player:setVar("BSTHAFight",3);
    player:addItem(17966,1,124,6,890,74,59,0);  
	player:messageSpecial(ITEM_OBTAINED,17966);	
	player:PrintToPlayer("Daruru : Here you go, enjoy your new weapon!", 0xD); 
elseif (player:getVar("BRDHAFight") == 2 and trade:hasItemQty(19116,1) and trade:hasItemQty(3299,50)) then -- Breeze Geodes
    player:tradeComplete();
	player:setVar("BRDHAFight",3);
    player:addItem(19116,1,322,4,890,29,59,0)  
	player:messageSpecial(ITEM_OBTAINED,19116);	
	player:PrintToPlayer("Daruru : Here you go, enjoy your new weapon!", 0xD); 
elseif (player:getVar("RNGHAFight") == 2 and trade:hasItemQty(18763,1) and trade:hasItemQty(3302,50)) then  -- Aqua Geodes
    player:tradeComplete();
	player:setVar("RNGHAFight",3);
    player:addItem(18763,1,139,4,890,200,59,0);  
	player:messageSpecial(ITEM_OBTAINED,18763);	
	player:PrintToPlayer("Daruru : Here you go, enjoy your new weapon!", 0xD); 
elseif (player:getVar("SAMHAFight") == 2 and trade:hasItemQty(18452,1) and trade:hasItemQty(3300,50)) then  -- Soil Geodes
    player:tradeComplete();
	player:setVar("SAMHAFight",3);
    player:addItem(19275,1,164,4,890,138,59,0);  
	player:messageSpecial(ITEM_OBTAINED,19275);	
	player:PrintToPlayer("Daruru : Here you go, enjoy your new weapon!", 0xD); 
elseif (player:getVar("NINHAFight") == 2 and trade:hasItemQty(19275,1) and trade:hasItemQty(3302,50)) then  -- Aqua Geodes
    player:tradeComplete();
	player:setVar("NINHAFight",3);
    player:addItem(19275,1,164,4,890,138,59,0);  
	player:messageSpecial(ITEM_OBTAINED,19275);	
	player:PrintToPlayer("Daruru : Here you go, enjoy your new weapon!", 0xD); 
elseif (player:getVar("DRGHAFight") == 2 and trade:hasItemQty(19303,1) and trade:hasItemQty(3299,50)) then  -- Snow Geodes
    player:tradeComplete();
	player:setVar("DRGHAFight",3);
    player:addItem(19303,1,121,9,890,122,59,0);  
	player:messageSpecial(ITEM_OBTAINED,19303);	
	player:PrintToPlayer("Daruru : Here you go, enjoy your new weapon!", 0xD); 
elseif (player:getVar("SMNHAFight") == 2 and trade:hasItemQty(18601,1) and trade:hasItemQty(3304,50)) then  -- Shadow Geodes
    player:tradeComplete();
	player:setVar("SMNHAFight",3);    
    player:addItem(18601,1,321,2,890,188,59,0);
	player:messageSpecial(ITEM_OBTAINED,18601);		
	player:PrintToPlayer("Daruru : Here you go, enjoy your new weapon!", 0xD); 	
elseif (player:getVar("BLUHAFight") == 2 and trade:hasItemQty(17763,1)) and trade:hasItemQty(3304,50)) then -- Shadow Geodes
    player:tradeComplete();
	player:setVar("BLUHAFight",3);    
	player:addItem(17763,1,299,9,890,46,59,0) 
	player:messageSpecial(ITEM_OBTAINED,17763);		
	player:PrintToPlayer("Daruru : Here you go, enjoy your new weapon!", 0xD); 	
elseif (player:getVar("CORHAFight") == 2 and trade:hasItemQty(18737,1) and trade:hasItemQty(3299,50)) then  -- Snow Geodes
    player:tradeComplete();
	player:setVar("CORHAFight",3);
    player:addItem(18737,1,133,9,890,218,59,0);  
	player:messageSpecial(ITEM_OBTAINED,18737);	
	player:PrintToPlayer("Daruru : Here you go, enjoy your new weapon!", 0xD); 
elseif (player:getVar("PUPHAFight") == 2 and trade:hasItemQty(18765,1) and trade:hasItemQty(3302,50)) then  -- Aqua Geodes
    player:tradeComplete();
	player:setVar("PUPHAFight",3);
    player:addItem(18765,1,124,6,890,12,59,0);  
	player:messageSpecial(ITEM_OBTAINED,18765);	
	player:PrintToPlayer("Daruru : Here you go, enjoy your new weapon!", 0xD); 
elseif (player:getVar("DNCHAFight") == 2 and trade:hasItemQty(19117,1) and trade:hasItemQty(3299,50)) then -- Breeze Geodes
    player:tradeComplete();
	player:setVar("DNCHAFight",3);
    player:addItem(19117,1,330,9,890,29,59,0)  
	player:messageSpecial(ITEM_OBTAINED,19117);	
	player:PrintToPlayer("Daruru : Here you go, enjoy your new weapon!", 0xD); 
elseif (player:getVar("SCHHAFight") == 2 and trade:hasItemQty(18602,1) and trade:hasItemQty(3304,50)) then  -- Shadow Geodes
    player:tradeComplete();
	player:setVar("SCHHAFight",3);    
    player:addItem(18602,1,1249,14,890,188,59,0);
	player:messageSpecial(ITEM_OBTAINED,18602);		
	player:PrintToPlayer("Daruru : Here you go, enjoy your new weapon!", 0xD); 	
end  	
end;

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)
-- Spawn Mechanism

if ((player:getVar("WARHAFight") == 1) or (player:getVar("MNKHAFight") == 1) or (player:getVar("WHMHAFight") == 1) or (player:getVar("BLMHAFight") == 1) or (player:getVar("RDMHAFight") == 1) or 
   (player:getVar("THFHAFight") == 1) or (player:getVar("PLDHAFight") == 1) or (player:getVar("DRKHAFight") == 1) or (player:getVar("BSTHAFight") == 1) or (player:getVar("BRDHAFight") == 1) or 
   (player:getVar("RNGHAFight") == 1) or (player:getVar("SAMHAFight") == 1) or (player:getVar("NINHAFight") == 1) or (player:getVar("DRGHAFight") == 1) or (player:getVar("SMNHAFight") == 1) or 
   (player:getVar("BLUHAFight") == 1) or (player:getVar("CORHAFight") == 1) or (player:getVar("PUPHAFight") == 1) or (player:getVar("DNCHAFight") == 1) or (player:getVar("SCHHAFight") == 1)) then
    SpawnMob(16793977):updateEnmity(player);
end	

-- Obtain High Artifact
if (player:getVar("WARHAFight") == 2) then  -- WAR
    player:addItem(18505,1,551,6,143,1,1047,1) 
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
    player:addItem(18995,1,558,6,315,9,1051,1) 
	player:messageSpecial(ITEM_OBTAINED,18995);		
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