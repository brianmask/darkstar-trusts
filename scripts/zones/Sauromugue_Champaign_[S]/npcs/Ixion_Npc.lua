-----------------------------------
-- Area: Sauromugue Champaign [S]
--  NPC: Waypoint
-- @pos -321 -1 528
-- Quest NPC
-----------------------------------
package.loaded["scripts/zones/Sauromugue_Champaign_[S]/TextIDs"] = nil;
-----------------------------------

require("scripts/globals/campaign");
require("scripts/zones/Sauromugue_Champaign_[S]/TextIDs");
require("scripts/globals/titles");
require("scripts/globals/quests");
require("scripts/globals/settings");
require("scripts/globals/bcnm");

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)
 if (trade:hasItemQty(19210, 1)) then
    player:PrintToPlayer("Jouya : Perfect, just examine the waypoint next to me.  A word of caution...",0x0D);
	player:PrintToPlayer("Jouya : Do not go alone....",0x0D);
	player:setVar("IxionStart",2);
	end

end;

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)
	local ixion = player:getVar("IxionStart");
	if (ixion == nil) then
	player:PrintToPlayer("Jouya : There have been rumblings of a horse wrapped in lightning down in",0x0D);
	player:PrintToPlayer("Jouya : Everbloom Hollow.  If you bring me a Stygian Ash, I can grant you access.",0x0D);
	player:setVar("IxionStart",1);
    elseif (ixion == 1) then
	player:PrintToPlayer("Jouya : Remember, bring me a Stygian Ash.  I've seen them on Goblins around here",0x0D);
	elseif (ixion == 2) then
	player:PrintToPlayer("Jouya : Just trade the ash to the waypoint next to me but remember not to go alone",0x0D);
	end

end;

-----------------------------------
-- onEventUpdate
-----------------------------------

function onEventUpdate(player,csid,option)

end;

-----------------------------------
-- onEventFinish Action
-----------------------------------

function onEventFinish(player,csid,option)


end;