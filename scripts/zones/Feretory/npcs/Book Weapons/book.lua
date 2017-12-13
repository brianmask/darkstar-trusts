-----------------------------------
-- Area: Ferretory
-- NPC: Spell NPC
-- Standard Info NPC
-----------------------------------
package.loaded["scripts/zones/Heavens_Tower/TextIDs"] = nil;
-----------------------------------

require("scripts/zones/Heavens_Tower/TextIDs");





-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)
balance = 0;
scroll = 20000;

local blmquest = player:getVar("FerretoryBLM");	
local infamy = player:getCurrency("infamy");
local job = player:getMainJob();



-- White Mage Trade

if (trade:hasItemQty( 4611, 1 )) and (blmquest == 1) and (job == 3) then
	if (infamy >= scroll) then
    player:delCurrency("infamy", 20000);
	player:tradeComplete();
	player:setVar("FerretoryBLM",2);  -- Set to Second part of the quest to kill the NM

	player:PrintToPlayer("Grimoire : You are worthy. Investigate ??? @ G-4 in Tahrongi Canyon ", 0xD);
	else
	balance = scroll - infamy;
	player:PrintToPlayer( "Grimoire : You need "..balance.." more Infamy Points to continue.", 0xD);
end
else
player:PrintToPlayer("Griomoire : I can't accept that trade.");
end


-- Black Mage Trade

if (trade:hasItemQty( 4772, 1 )) and (blmquest == 1) and (job == 4) then
	if (infamy >= scroll) then
    player:delCurrency("infamy", 20000);
	player:tradeComplete();
	player:setVar("FerretoryBLM",2);  -- Set to Second part of the quest to kill the NM

	player:PrintToPlayer("Grimoire : You are worthy. Investigate ??? @ G-4 in Tahrongi Canyon ", 0xD);
	else
	balance = scroll - infamy;
	player:PrintToPlayer( "Grimoire : You need "..balance.." more Infamy Points to continue.", 0xD);
end
else
player:PrintToPlayer("Griomoire : I can't accept that trade.");
end


if (trade:hasItemQty( 4711, 1 )) and (blmquest == 1) and (job == 5) then
	if (infamy >= scroll) then
    player:delCurrency("infamy", 20000);
	player:tradeComplete();
	player:setVar("FerretoryBLM",2);  -- Set to Second part of the quest to kill the NM

	player:PrintToPlayer("Grimoire : You are worthy. Investigate ??? @ G-4 in Tahrongi Canyon ", 0xD);
	else
	balance = scroll - infamy;
	player:PrintToPlayer( "Grimoire : You need "..balance.." more Infamy Points to continue.", 0xD);
end
else
player:PrintToPlayer("Griomoire : I can't accept that trade.");
end







end; 

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)
local aura = player:getVar("FerretoryAura");
local blmquest = player:getVar("FerretoryBLM");	
local kills = player:getVar("FerretoryBLMkills");
local questactive = player:getVar("FerretoryBLMQ1"); 
local level = player:getMainLvl();

local job = player:getMainJob();	

-- White Mage Scroll Quest

-- if (job == 3) and (aura > 0) and (blmquest == 0) and (blmquest == 0) then
--	player:PrintToPlayer("Grimoire : Bring me a scroll of Cure III and 20,000 Infamy Points and I'll tell you a secret.", 0xD);
--	player:setVar("FerretoryBLM",1); -- turns quest on
--	else if (job == 3) and (aura > 0) and (blmquest == 1) then
--	player:PrintToPlayer("Grimoire : Remember, scroll of Cure III and 20,000 Infamy Points", 0xD);
	-- else if (job == 4) and (questactive == 2) and (level < 29) and (aura <3) then
	-- player:PrintToPlayer("Grimoire : Level 30+ and Aura Level 3 Required.", 0xD);
--	else
--	player:PrintToPlayer("Grimoire : Access Denied.", 0xD);
--	end
--	end








--- Black Mage Scroll Quest
-- if (job == 4) and (aura > 0) and (blmquest == 0) and (blmquest == 0) then
--	player:PrintToPlayer("Grimoire : Bring me a scroll of thunder and 20,000 Infamy Points and I'll tell you a secret.", 0xD);
--	player:setVar("FerretoryBLM",1); -- turns quest on
--	else if (job == 4) and (aura > 0) and (blmquest == 1) then
--	player:PrintToPlayer("Grimoire : Remember, scroll of thunder and 20,000 Infamy Points", 0xD);
	-- else if (job == 4) and (questactive == 2) and (level < 29) and (aura <3) then
	-- player:PrintToPlayer("Grimoire : Level 30+ and Aura Level 3 Required.", 0xD);
--	else
--	player:PrintToPlayer("Grimoire : Access Denied.", 0xD);
--	end
--	end
	
	
--- Red Mage Scroll Quest

-- if (job == 5) and (aura > 0) and (blmquest == 0) and (blmquest == 0) then
--	player:PrintToPlayer("Grimoire : Bring me a scroll of enstone and 20,000 Infamy Points and I'll tell you a secret.", 0xD);
--	player:setVar("FerretoryBLM",1); -- turns quest on
--	else if (job == 5) and (aura > 0) and (blmquest == 1) then
--	player:PrintToPlayer("Grimoire : Remember, scroll of enstone and 20,000 Infamy Points", 0xD);
	-- else if (job == 4) and (questactive == 2) and (level < 29) and (aura <3) then
	-- player:PrintToPlayer("Grimoire : Level 30+ and Aura Level 3 Required.", 0xD);
--	else
--	player:PrintToPlayer("Grimoire : Access Denied.", 0xD);
--	end	
--	end
	

player:PrintToPlayer("Grimoire : I have nothing for you, therefore I can't help you right now", 0xD);	
	
	
	

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



