-----------------------------------
-- Area: Aht Urhgan Whitegate
-- NPC: Lathuya
-- Standard Info NPC
-----------------------------------
package.loaded["scripts/zones/Aht_Urhgan_Whitegate/TextIDs"] = nil;
-----------------------------------

require("scripts/zones/Aht_Urhgan_Whitegate/TextIDs");
require("scripts/globals/quests");
require("scripts/globals/settings");
require("scripts/globals/status");

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)

local job = player:getMainJob();
local lvl = player:getMainLvl();
local Omens = player:getQuestStatus(AHT_URHGAN,OMENS);
local pants = player:getVar("BLU_AF_PANTS");
local hands = player:getVar("BLU_AF_HANDS");
local body = player:getVar("BLU_AF_BODY");
local feet = player:getVar("BLU_AF_FEET");
local head = player:getVar("BLU_AF_HEAD");

if (job == JOBS.BLU and lvl >= 50) then
   
    -- Check for armor Completions
    if (feet == 0) then -- Haven't Done Feet
	    if ((trade:hasItemQty(761,1)) and (trade:hasItemQty(828,1)) and (trade:hasItemQty(2340,1))) then
		player:PrintToPlayer("Lathuya : Perfect. Give me a moment and your Magus Charqus will be available for purchase.", 0xD);
		player:setVar("BLU_AF_FEET",1);
		player:tradeComplete();
		end	
    elseif (pants == 0) then -- Haven't Done Pants
	    if ((trade:hasItemQty(761,1)) and (trade:hasItemQty(828,1)) and (trade:hasItemQty(2175,1)) and (trade:hasItemQty(2340,1))) then
		player:PrintToPlayer("Lathuya : Perfect. Give me a moment and your Magus Shalwar will be available for purchase.", 0xD);
		player:setVar("BLU_AF_PANTS",1);
		player:tradeComplete();
		end
	elseif (hands == 0) then -- Haven't Done Hands
        if ((trade:hasItemQty(754,1)) and (trade:hasItemQty(828,1)) and (trade:hasItemQty(879,1)) and (trade:hasItemQty(4158,1))) then
        player:PrintToPlayer("Lathuya : Perfect. Give me a moment and your Magus Bazubands will be available for purchase.", 0xD);
		player:setVar("BLU_AF_HANDS",1);
		player:tradeComplete();
		end
	elseif (body == 0) then -- Haven't Done Body
        if ((trade:hasItemQty(828,1)) and (trade:hasItemQty(2229,1)) and (trade:hasItemQty(2288,1)) and (trade:hasItemQty(2340,1))) then		
		player:PrintToPlayer("Lathuya : Perfect. Give me a moment and your Magus Jubbah will be available for purchase.", 0xD);
		player:setVar("BLU_AF_BODY",1);
		player:tradeComplete();
		end
	elseif (body == 0) then -- Haven't Done Head
        if ((trade:hasItemQty(761,3)) and (trade:hasItemQty(828,1)) and (trade:hasItemQty(2340,1)) and (trade:hasItemQty(2175,5))) then		
		player:PrintToPlayer("Lathuya : Perfect. Give me a moment and your Magus Keffiyeh will be available for purchase.", 0xD);
		player:setVar("BLU_AF_HEAD",1);
		player:tradeComplete();
		end		
	end
end	
		




		
--Gold Chain 761		
-- Velvet 828
-- Flan Meat  2175
-- Imperial Silk  2340

-- Karakul Leather 879
-- Venom Potion 4158
-- Platinum Sheet 754

-- Chimera Blood  2229
-- Karakul Cloth 2288
	
end; 

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)

local job = player:getMainJob();
local lvl = player:getMainLvl();
local pants = player:getVar("BLU_AF_PANTS");
local hands = player:getVar("BLU_AF_HANDS");
local body = player:getVar("BLU_AF_BODY");
local feet = player:getVar("BLU_AF_FEET");
local head = player:getVar("BLU_AF_HEAD");


if (job == JOBS.BLU and lvl >= 50) then
    -- Check for armor Completions
    if (feet == 0) then -- Haven't Done feet
        player:PrintToPlayer("Lathuya : I see you are a BLU Mage, but you lack the attire.  Bring me a Gold Chain,", 0xD);
		player:PrintToPlayer("Lathuya : Velvet Cloth and Imp. Silk Cloth and I'll sell you a Magus Charuqs", 0xD);	
    elseif (pants == 0) then -- Haven't Done Pants
        player:PrintToPlayer("Lathuya : I see you are a BLU Mage, but you lack the attire.  Bring me a Gold Chain,", 0xD);
		player:PrintToPlayer("Lathuya : Velvet Cloth, Flan Meat, and Imp. Silk Cloth and I'll sell you a Magus Shalwar ", 0xD);
    elseif (hands == 0) then -- Haven't Done Hands
        player:PrintToPlayer("Lathuya : I see you are a BLU Mage, but you lack the attire.  Bring me a Platinum Sheet,", 0xD);
		player:PrintToPlayer("Lathuya : Velvet Cloth, Karakul Leather, and Venom Potion and I'll sell you a Magus Bazubands ", 0xD);    
    elseif (body == 0) then -- Haven't Done Body
        player:PrintToPlayer("Lathuya : I see you are a BLU Mage, but you lack the attire.  Bring me a Velvet Cloth,", 0xD);
		player:PrintToPlayer("Lathuya : Chimera Blod, Karakul Cloth, and Imp. Silk Cloth and I'll sell you a Magus Jubbah ", 0xD);
    elseif (head == 0) then -- Haven't Done Head
        player:PrintToPlayer("Lathuya : I see you are a BLU Mage, but you lack the attire.  Bring me a Velvet Cloth,", 0xD);
		player:PrintToPlayer("Lathuya : Gold Chain x3 and Imp. Silk Cloth, and Flan meat x5 and I'll sell you a Magus Keffiyeh ", 0xD);
    end
	
	-- Display Menu 
	if (head == 1) then
	    local afshop = {
		    0x3BA1,    50000, -- Magus Keffiyeh
			0x3CF0,    15000, -- Magus Shalwar
		    0x3A50,    20000, -- Magus Bazubands
		    0x38B9,    30000,  -- Magus Jubbah
		    0x3D44,    10000  -- Magus Charuqs	
		}
		showShop(player, STATIC, afshop);		
	elseif (body == 1) then
	    local afshop = {
		    0x3CF0,    15000, -- Magus Shalwar
		    0x3A50,    20000, -- Magus Bazubands
		    0x38B9,    30000,  -- Magus Jubbah
		    0x3D44,    10000  -- Magus Charuqs	
		}
		showShop(player, STATIC, afshop);	
	elseif (hands == 1) then
	    local afshop = {
		    0x3CF0,    15000, -- Magus Shalwar
		    0x3A50,    20000, -- Magus Bazubands	
            0x3D44,    10000  -- Magus Charuqs			
		}
		showShop(player, STATIC, afshop);		
	elseif (pants == 1) then
	    local afshop = {
		    0x3CF0,    15000, -- Magus Shalwar	
			0x3D44,    10000  -- Magus Charuqs
		}
		showShop(player, STATIC, afshop);	
	elseif (feet == 1) then
	    local afshop = {
			0x3D44,    10000  -- Magus Charuqs
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



