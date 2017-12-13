-----------------------------------
-- Area: Aht Urhgan Whitegate
-- NPC: Dhima Polevhia
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
local pants = player:getVar("PUP_AF_PANTS");
local hands = player:getVar("PUP_AF_HANDS");
local body = player:getVar("PUP_AF_BODY");
local feet = player:getVar("PUP_AF_FEET");
local head = player:getVar("PUP_AF_HEAD");

if (job == JOBS.PUP and lvl >= 50) then 
    -- Check for armor Completions
    if (pants == 0) then -- Haven't Done Feet
	    if ((trade:hasItemQty(821,1)) and (trade:hasItemQty(2289,1)) and (trade:hasItemQty(2152,1))) then
		player:PrintToPlayer("Dhima Polevhia : Perfect. Give me a moment and your Puppetry's Babouches will be available for purchase.", 0xD);
		player:setVar("PUP_AF_FEET",1);
		player:tradeComplete();
		end	
	elseif (feet == 0) then -- Haven't Done Hands
        if ((trade:hasItemQty(786,1)) and (trade:hasItemQty(2289,1)) and (trade:hasItemQty(2152,1)) and (trade:hasItemQty(754,1))) then
        player:PrintToPlayer("Dhima Polevhia : Perfect. Give me a moment and your Puppetry Dastanas will be available for purchase.", 0xD);
		player:setVar("PUP_AF_HANDS",1);
		player:tradeComplete();
		end		
    elseif (hands == 0) then -- Haven't Done Pants
	    if ((trade:hasItemQty(821,1)) and (trade:hasItemQty(2289,1)) and (trade:hasItemQty(2152,1)) and (trade:hasItemQty(754,1))) then
		player:PrintToPlayer("Dhima Polevhia : Perfect. Give me a moment and your Puppetry Churidars will be available for purchase.", 0xD);
		player:setVar("PUP_AF_PANTS",1);
		player:tradeComplete();
		end

	elseif (body == 0) then -- Haven't Done Body
        if ((trade:hasItemQty(786,1)) and (trade:hasItemQty(2289,1)) and (trade:hasItemQty(1636,1)) and (trade:hasItemQty(1699,1))) then		
		player:PrintToPlayer("Dhima Polevhia : Perfect. Give me a moment and your Puppetry Tobe will be available for purchase.", 0xD);
		player:setVar("PUP_AF_BODY",1);
		player:tradeComplete();
		end
	elseif (body == 0) then -- Haven't Done Head
        if ((trade:hasItemQty(786,3)) and (trade:hasItemQty(2289,3)) and (trade:hasItemQty(2007,3)) and (trade:hasItemQty(1636,5))) then		
		player:PrintToPlayer("Dhima Polevhia : Perfect. Give me a moment and your Puppetry Taj will be available for purchase.", 0xD);
		player:setVar("PUP_AF_HEAD",1);
		player:tradeComplete();
		end		
	end
end	
		




-- Marid Leather	   2152	
-- Rainbow Cloth	    821
-- Ruby                 786
-- Platinum Sheet        754
-- Wamoura Cloth       2289
-- Scarlet Linen    1699
-- Moblinweave   1636


end; 

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)

local job = player:getMainJob();
local lvl = player:getMainLvl();
local pants = player:getVar("PUP_AF_PANTS");
local hands = player:getVar("PUP_AF_HANDS");
local body = player:getVar("PUP_AF_BODY");
local feet = player:getVar("PUP_AF_FEET");
local head = player:getVar("PUP_AF_HEAD");


if (job == JOBS.PUP and lvl >= 50) then
    -- Check for armor Completions
    if (pants == 0) then -- Haven't Done pants
        player:PrintToPlayer("Dhima Polevhia : I see you are a Puppetmaster, but you lack the attire.  Bring me a Rainbow Thread,", 0xD);
		player:PrintToPlayer("Dhima Polevhia : Wamoura Cloth, and Marid Leather, and I'll sell you a Puppetry Babouches", 0xD);	
    elseif (feet == 0) then -- Haven't Done Hands
        player:PrintToPlayer("Dhima Polevhia : I see you are a Puppetmaster, but you lack the attire.  Bring me a Ruby,", 0xD);
		player:PrintToPlayer("Dhima Polevhia : Wamoura Cloth, Marid Leather, and Platinum Sheet and I'll sell you a Puppetry Dastanas", 0xD);   
    elseif (hands == 0) then -- Haven't Done hands
        player:PrintToPlayer("Dhima Polevhia : I see you are a Puppetmaster, but you lack the attire.  Bring me a Rainbow Thread,", 0xD);
		player:PrintToPlayer("Dhima Polevhia : Wamoura Cloth, Marid Leather, and Platinum Sheet and I'll sell you a Puppetry Churidars", 0xD);		
    elseif (body == 0) then -- Haven't Done Body
        player:PrintToPlayer("Dhima Polevhia : I see you are a Puppetmaster, but you lack the attire.  Bring me a Ruby,", 0xD);
		player:PrintToPlayer("Dhima Polevhia : Wamoura Cloth, Moblinwave, and Scarlette Linene and I'll sell you a Puppetry Tobe", 0xD);
    elseif (head == 0) then -- Haven't Done Head
        player:PrintToPlayer("Dhima Polevhia : I see you are a Puppetmaster, but you lack the attire.  Bring me a Ruby,", 0xD);
		player:PrintToPlayer("Dhima Polevhia : Wamoura Cloth x3, and Moblinweave x3 and I'll sell you a Puppetry Taj", 0xD);
    end
	
	-- Display Menu 
	if (head == 1) then
	    local afshop = {
		    0x3BA3,    50000, -- Puppetry Taj
			0x38BB,    30000, -- Puppetry Tobe
		    0x3A52,    20000, -- Puppetry's Hands	
		    0x3D46,    10000,  -- Puppetry Feet			
		    0x3CF2,    15000  -- Puppetrys Legs			
		}
		showShop(player, STATIC, afshop);		
	elseif (body == 1) then
	    local afshop = {
			0x38BB,    30000, -- Puppetry Tobe
		    0x3A52,    20000, -- Puppetry's Hands	
		    0x3D46,    10000, -- Puppetry Feet			
		    0x3CF2,    15000  -- Puppetrys Legs		
		}
		showShop(player, STATIC, afshop);		
	elseif (hands == 1) then
	    local afshop = {
		    0x3A52,    20000, -- Puppetry's Hands	
		    0x3D46,    10000,  -- Puppetry Feet			
		    0x3CF2,    15000  -- Puppetrys Legs		
		}
		showShop(player, STATIC, afshop);	
	elseif (feet == 1) then
	    local afshop = {	
		    0x3D46,    10000,  -- Puppetry Feet			
		    0x3CF2,    15000  -- Puppetrys Legs				
		}
		showShop(player, STATIC, afshop);		
	elseif (pants == 1) then
	    local afshop = {						
		    0x3CF2,    15000  -- Puppetrys Legs	
		}
		showShop(player, STATIC, afshop);		
	end	
else




player:startEvent(0x0302);
end
end; 



