-----------------------------------
--  Area: Southern Sandy
--   NPC: Myxlu
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
   
 player:PrintToPlayer( "Myxlu : Too much leftovers from crafting.  Please buy!", 0xD);   
-- player:showText(npc,ADELFLETE_SHOP_DIALOG);

stock = {0x0868,20000,  -- Marid Leather
		 0x036F,25000, -- Karakul Leather
		 0x0350,8000, -- Dhalmel Leather
		 0x0353,4000, -- Ram Leather
		 0x0357,7000, -- Tiger Leather
		 0x0665,7000, -- Bugard Leather
		 0x06CD,5000, -- HQ Eft Skin
		 0x09E2,22000, -- Lynx Leather
		 0x09E1,13000, -- Smilidon Leather
		 0x09EA,28000, -- Peiste Leather
		 0x05B3,31000} -- Griffon Leather
 
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


