-----------------------------------
-- Area: Nashmau
-- NPC: Leleroon
-- Standard Info NPC -- Corsair SideQuests
-- @pos -14.687 0.000 25.114 53
-----------------------------------
package.loaded["scripts/zones/Nashmau/TextIDs"] = nil;
-----------------------------------

require("scripts/zones/Nashmau/TextIDs");
require("scripts/globals/settings");
require("scripts/globals/quests");
require("scripts/globals/keyitems");
require("scripts/globals/status");

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)

    local job = player:getMainJob();
    local lvl = player:getMainLvl();
    local pants = player:getVar("COR_AF_PANTS");
    local hands = player:getVar("COR_AF_HANDS");
    local body = player:getVar("COR_AF_BODY");
    local feet = player:getVar("COR_AF_FEET");
    local head = player:getVar("COR_AF_HEAD");
	
	if (player:getQuestStatus(AHT_URHGAN,NAVIGATING_THE_UNFRIENDLY_SEAS) == QUEST_ACCEPTED and player:getVar("NavigatingtheUnfriendlySeas") <= 2) then
		if (trade:hasItemQty(2341,1) and trade:getItemCount() == 1) then -- Trade Hydrogauage
			player:startEvent(0x11B);
			player:setVar("NavigatingtheUnfriendlySeas",2);
		end
	
	end
	
    if (job == JOBS.COR and lvl >= 50) then 
    -- Check for armor Completions
    if (pants == 0) then -- Haven't Done Feet
	    if ((trade:hasItemQty(823,1)) and (trade:hasItemQty(2304,1)) and (trade:hasItemQty(879,1))) then
		player:PrintToPlayer("Leleroon : Perfect. Give me a moment and your Corsair's Bootes will be available for purchase.", 0xD);
		player:setVar("COR_AF_FEET",1);
		player:tradeComplete();
		end	
    elseif (hands == 0) then -- Haven't Done Pants
	    if ((trade:hasItemQty(823,1)) and (trade:hasItemQty(1829,1)) and (trade:hasItemQty(879,1)) and (trade:hasItemQty(2304,1))) then
		player:PrintToPlayer("Leleroon : Perfect. Give me a moment and your Corsair's Culottes will be available for purchase.", 0xD);
		player:setVar("COR_AF_PANTS",1);
		player:tradeComplete();
		end
	elseif (feet == 0) then -- Haven't Done Hands
        if ((trade:hasItemQty(879,1)) and (trade:hasItemQty(2007,1)) and (trade:hasItemQty(663,1)) and (trade:hasItemQty(2010,1))) then
        player:PrintToPlayer("Leleroon : Perfect. Give me a moment and your Corsair's Gnats will be available for purchase.", 0xD);
		player:setVar("COR_AF_HANDS",1);
		player:tradeComplete();
		end
	elseif (body == 0) then -- Haven't Done Body
        if ((trade:hasItemQty(761,1)) and (trade:hasItemQty(1829,1)) and (trade:hasItemQty(1997,1)) and (trade:hasItemQty(828,1))) then		
		player:PrintToPlayer("Leleroon : Perfect. Give me a moment and your Corsair's Frac will be available for purchase.", 0xD);
		player:setVar("COR_AF_BODY",1);
		player:tradeComplete();
		end
	elseif (body == 0) then -- Haven't Done Head
        if ((trade:hasItemQty(828,3)) and (trade:hasItemQty(1997,3)) and (trade:hasItemQty(2007,3)) and (trade:hasItemQty(2175,5))) then		
		player:PrintToPlayer("Leleroon : Perfect. Give me a moment and your Corsair's Tricorne will be available for purchase.", 0xD);
		player:setVar("COR_AF_HEAD",1);
		player:tradeComplete();
		end		
	end
end	

-- Gold Chain      761		
-- Velvet          828
-- Sail Cloth      1997
-- Red Grass Cloth  1829
-- Wamoura Silk   2304
-- Gold Thread    823
-- Karakul Leather 879
-- Mythril Sheet    663
-- Wolf Felt  2010
	
end;  

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)
	
    local job = player:getMainJob();
    local lvl = player:getMainLvl();
    local pants = player:getVar("COR_AF_PANTS");
    local hands = player:getVar("COR_AF_HANDS");
    local body = player:getVar("COR_AF_BODY");
    local feet = player:getVar("COR_AF_FEET");
    local head = player:getVar("COR_AF_HEAD");	
	local mJob = player:getMainJob();
	local mLvl = player:getMainLvl();
	
	-- if (player:getVar("AgainstAllOddsSideQuests") == 1 and mJob == 17 and mLvl >= AF3_QUEST_LEVEL) then
		-- player:startEvent(0x11A); -- CS with 3 Options
	-- else
		-- player:startEvent(0x0108); -- Basic Dialog		
	-- end
	
if (job == JOBS.COR and lvl >= 50) then
    -- Check for armor Completions
    if (pants == 0) then -- Haven't Done pants
        player:PrintToPlayer("Leleroon : I see you are a Corsair, but you lack the attire.  Bring me a Gold Thread,", 0xD);
		player:PrintToPlayer("Leleroon : Wamoura Silk, and Karakul Leather, and I'll sell you a Corsair's Bottes", 0xD);	
    elseif (hands == 0) then -- Haven't Done hands
        player:PrintToPlayer("Leleroon : I see you are a Corsair, but you lack the attire.  Bring me a Gold Thread,", 0xD);
		player:PrintToPlayer("Leleroon : Karakul Leather, Red Grass Cloth, and Wamoura Silk and I'll sell you a Corsair's Culottes", 0xD);
    elseif (feet == 0) then -- Haven't Done Hands
        player:PrintToPlayer("Leleroon : I see you are a Corsair, but you lack the attire.  Bring me a Karakul Leather,", 0xD);
		player:PrintToPlayer("Leleroon : Laminated Buffalo Leather, Mythril Sheet, and Wolf Felt and I'll sell you a Corsair's Gnats", 0xD);    
    elseif (body == 0) then -- Haven't Done Body
        player:PrintToPlayer("Leleroon : I see you are a Corsair, but you lack the attire.  Bring me a Gold Chain,", 0xD);
		player:PrintToPlayer("Leleroon : Red Grass Cloth, Sailcloth, and Velvet Cloth and I'll sell you a Corsair's Frac", 0xD);
    elseif (head == 0) then -- Haven't Done Head
        player:PrintToPlayer("Leleroon : I see you are a Corsair, but you lack the attire.  Bring me a Velvet Cloth,", 0xD);
		player:PrintToPlayer("Leleroon : Sailcloth x 3, and Laminated Buffalo Leather x3 and I'll sell you a Corsair's Tricorne", 0xD);
    end
	
	-- Display Menu 
	if (head == 1) then
	    local afshop = {
		    0x3BA2,    50000, -- Corairs Tricorn
			0x38BA,    15000, -- Corsair's Frac
		    0x3D45,    10000,  -- Corsair Feet
		    0x3A51,    20000, -- Corsair's Hands			
		    0x3CF1,    30000  -- Corsairs Legs			
		}
		showShop(player, STATIC, afshop);		
	elseif (body == 1) then
	    local afshop = {
			0x38BA,    15000, -- Corsair's Frac
		    0x3D45,    10000,  -- Corsair Feet
		    0x3A51,    20000, -- Corsair's Hands			
		    0x3CF1,    30000  -- Corsairs Legs		
		}
		showShop(player, STATIC, afshop);	
	elseif (feet == 1) then
	    local afshop = {
		    0x3D45,    10000,  -- Corsair Feet
		    0x3A51,    20000, -- Corsair's Hands			
		    0x3CF1,    30000  -- Corsairs Legs			
		}
		showShop(player, STATIC, afshop);		
	elseif (hands == 1) then
	    local afshop = {
		    0x3A51,    20000, -- Corsair's Hands			
		    0x3CF1,    30000  -- Corsairs Legs	
		}
		showShop(player, STATIC, afshop);	
	elseif (pants == 1) then
	    local afshop = {			
		    0x3CF1,    30000  -- Corsairs Legs	
		}
		showShop(player, STATIC, afshop);		
	end	
else




player:startEvent(0x0302);
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
--printf("CSID: %u",csid);
--printf("RESULT: %u",option);


	if (option == 0) then
	
	elseif (option == 1) then
		if (player:hasKeyItem(LELEROONS_LETTER_RED) or player:hasKeyItem(LELEROONS_LETTER_BLUE) or player:hasKeyItem(LELEROONS_LETTER_GREEN) == false) then  -- 
			player:addKeyItem(LELEROONS_LETTER_GREEN);
			player:messageSpecial(KEYITEM_OBTAINED,LELEROONS_LETTER_GREEN)
			player:setVar("LeleroonsLetterGreen",1);
			player:setVar("AgainstAllOddsSideQuests",2);
		end
	elseif (option == 2) then 
		if (player:hasKeyItem(LELEROONS_LETTER_RED) or player:hasKeyItem(LELEROONS_LETTER_BLUE) or player:hasKeyItem(LELEROONS_LETTER_GREEN) == false) then -- 
			player:addKeyItem(LELEROONS_LETTER_BLUE);
			player:messageSpecial(KEYITEM_OBTAINED,LELEROONS_LETTER_BLUE)
			player:setVar("LeleroonsLetterBlue",1);
			player:setVar("AgainstAllOddsSideQuests",2);
		end	
	elseif (option == 3) then 
		if (player:hasKeyItem(LELEROONS_LETTER_RED) or player:hasKeyItem(LELEROONS_LETTER_BLUE) or player:hasKeyItem(LELEROONS_LETTER_GREEN) == false) then -- 
			player:addKeyItem(LELEROONS_LETTER_RED);
			player:messageSpecial(KEYITEM_OBTAINED,LELEROONS_LETTER_RED)
			player:setVar("LeleroonsLetterRed",1);
			player:setVar("AgainstAllOddsSideQuests",2);
		end
	end		

end;



