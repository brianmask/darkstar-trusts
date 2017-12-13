-----------------------------------
--  Area: Bastok Markets
--  NPC: Goldsmith Traineee
--  Guild Merchant NPC: Goldsmithing Guild 
--  @pos -202.000 -7.814 -56.823 235
-----------------------------------
package.loaded["scripts/zones/Bastok_Markets/TextIDs"] = nil;
-----------------------------------

require("scripts/globals/settings");
require("scripts/globals/shop");
require("scripts/zones/Bastok_Markets/TextIDs");

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)
end; 

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)
   
 player:PrintToPlayer( "Jorra : I am quitting the Goldsmithing Business.  Please buy my stuff.", 0xD);   
-- player:showText(npc,ADELFLETE_SHOP_DIALOG);

stock = {0x02F2,30000, -- Platinum Sheet
		 0x02F9,20000, -- Gold Chain
		 0x02E9,10000, -- Gold Ingot
		 0x09E8,10000, -- Electrum Ingot
		 0x02EB,15000, -- Orichalcum Ingot
		 0x0312,9000,  -- Ruby
		 0x0314,15000, -- Peridot
		 0x031E,15000, -- Turquoise
		 0x031D,15000, -- Painite
		 0x0328,25000, -- Goshinite
		 0x0662,25000, -- Rhodinite
		 0x06CC,30000, -- Iolite
		 0x032D,10000, -- Deathstone
		 0x032C,10000, -- Angelstone
		 0x0AB7,25000, -- Oxblood Orb
		 0x0AB8,45000} -- Angelskin Orb
 
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

