-----------------------------------
-- Area: The Boyahda Tree
-- NPC: qm1 (???)
-- Involved in Quest: Shoot First, Ask questions later
-----------------------------------
package.loaded["scripts/zones/The_Boyahda_Tree/TextIDs"] = nil;
-----------------------------------

require("scripts/zones/The_Boyahda_Tree/TextIDs");
require("scripts/globals/quests");
require("scripts/globals/keyitems");

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)
end;

-----------------------------------
-- onTrigger Action
-----------------------------------


function onTrigger(player,npc)
 if (player:hasKeyItem(MAP_TO_THE_ANNALS_OF_TRUTH) and player:getVar("DETONATOR_WIN") == 1) then
	 SpawnMob(17404338):updateClaim(player);
     else
     player:messageSpecial(NOTHING_OUT_OF_ORDINARY);
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
