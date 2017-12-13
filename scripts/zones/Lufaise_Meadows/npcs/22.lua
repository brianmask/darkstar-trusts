-----------------------------------
-- Area: Lufaise Meadows
-- NPC:  Blank Spot for obtaining Ulmia Trust
-- @pos 186 -22 342 24
-----------------------------------
package.loaded["scripts/zones/Lufaise_Meadows/TextIDs"] = nil;
-----------------------------------

require("scripts/globals/quests");
require("scripts/globals/missions");
require("scripts/globals/settings");
require("scripts/zones/Lufaise_Meadows/TextIDs");

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)
    if (trade:hasItemQty(604,1) and player:hasSpell(914) == false) then
	    player:PrintToPlayer("Ulmia : I will now play music for you...", 0xD); 
		player:PrintToPlayer("You are now able to summon  Ulmia as a Trust!", 0x1C);
		player:addSpell(914);
		player:tradeComplete();
	end
end;

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)
    player:PrintToPlayer("You think you can hear a soft ballad in the breeze...or maybe it's your imagination.", 0x1C);
end;