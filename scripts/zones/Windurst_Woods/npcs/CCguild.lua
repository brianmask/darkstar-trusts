-----------------------------------
--  Area: Windurst Woods
--   NPC: Lucia
--  Type: Clothcraft Vendor NPC
-- @zone: 241
--  @pos 7.800 -3.5 -10.064
--
-- Auto-Script: Requires Verification (Verfied by Brawndo)
-----------------------------------
package.loaded["scripts/zones/Windurst_Woods/TextIDs"] = nil;
require("scripts/zones/Windurst_Woods/TextIDs");
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
   
 player:PrintToPlayer( "Lucia : I want to skillup but I have too many items from my synths.  Please help me make room!", 0xD);   
-- player:showText(npc,ADELFLETE_SHOP_DIALOG);

stock = {0x08F1,5000, -- Wamoura Cloth
		 0x0335,15000, -- Rainbow Thread
		 0x06A3,25000, -- Scarlet Linene
		 0x0664,35000, -- Moblinweave
		 0x033C,5000, -- Velvet Cloth
		 0x0924,15000, -- Imperial Silk Cloth
		 0x033A,5000, -- Linen Cloth
		 0x033B,8000, -- Wool Cloth
		 0x033D,9000, -- Silk Cloth
		 0x06CB,10000, -- Balloon Cloth
		 0x033E,10000, -- Rainbow Cloth
		 0x09E9,10000, -- Square of Cilice
		 0x0A90,35000, -- Oil Soaked Cloth
		 0x0A91,35000} -- Foulard
 
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


