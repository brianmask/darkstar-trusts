-----------------------------------
--  Area: Northern Sandy
--   NPC: Cheru
--  Type: Clothcraft Vendor NPC
-- @zone: 241
--  @pos 7.800 -3.5 -10.064
--
-- Auto-Script: Requires Verification (Verfied by Brawndo)
-----------------------------------
package.loaded["scripts/zones/Southern_San_dOria/TextIDs"] = nil;
require("scripts/zones/Southern_San_dOria//TextIDs");
require("scripts/globals/settings");
require("scripts/globals/quests");
-----------------------------------

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)
end; 

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)
   
 player:PrintToPlayer( "Cheru : Need to make room for more crafts.", 0xD);   
-- player:showText(npc,ADELFLETE_SHOP_DIALOG);

stock = {0x028C,15000, -- Steel Ingot
		 0x028E,9000, -- Darksteel Ingot
		 0x0663,12000, --Paktong Ingot
		 0x06CA,9000, -- Shakudo Ingot
		 0x028F,9000, -- Adaman Ingot
		 0x06AF,33000} -- Molybdenum Ingot
 
showShop(player, STATIC, stock);
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


