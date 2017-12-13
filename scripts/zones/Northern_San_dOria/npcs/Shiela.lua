-----------------------------------
-- Area: Northern San d'Oria
-- NPC: Sheila
-- Smithing Merchant
-----------------------------------
package.loaded["scripts/zones/Northern_San_dOria/TextIDs"] = nil;
-----------------------------------

require("scripts/globals/settings");
require("scripts/globals/shop");
require("scripts/globals/quests");
require("scripts/zones/Northern_San_dOria/TextIDs");

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)

end;
-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)
		 player:PrintToPlayer("Shiela : Smithing items for sale", 0xD);

	stock = {0x1159,837,1,	--Steel Ingot 
			 0x1104,180,2,	--Mythril Ingot
			 0x111c,198,2,	--Gold Ingot
			 0x1147,270,2,	--Darksteel Ingot
			 0x110c,108,3,	--Paktong Ingot
			 0x1118,108,3,	--Shakudo Ingot 
			 0x119d,10,3,	--Adaman Ingot 
			 0x138F,163,3}	--Electrum Ingot
							--Orichalcum Ingot
							--Molybdenum Ingot

	showNationShop(player, SANDORIA, stock);
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




