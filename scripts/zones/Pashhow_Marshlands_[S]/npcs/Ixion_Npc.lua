-----------------------------------
-- Area: Sauromugue Champaign [S]
--  NPC: Waypoint
-- @pos -321 -1 528
-- Quest NPC
-----------------------------------
package.loaded["scripts/zones/Pashhow_Marshlands_[S]/TextIDs"] = nil;
-----------------------------------

require("scripts/globals/campaign");
require("scripts/zones/Pashhow_Marshlands_[S]/TextIDs");
require("scripts/globals/titles");
require("scripts/globals/quests");
require("scripts/globals/settings");
require("scripts/globals/bcnm");

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)
 if (trade:hasItemQty(19210, 1)) then
    player:PrintToPlayer("Deshul : Perfect, just examine the waypoint next to me.  A word of caution...",0x0D);
	player:PrintToPlayer("Deshul : Do not go alone....",0x0D);
	player:setVar("LightIxionStart",3);
	end

end;

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)
	local ixion = player:getVar("LightIxionWin");
	if (ixion == 1) then
	player:PrintToPlayer("Deshul : There have been rumblings of a horse wrapped in light down in",0x0D);
	player:PrintToPlayer("Deshul : Everbloom Hollow.  If you bring me a Stygian Ash, I can grant you access.",0x0D);
	player:setVar("LightIxionStart",2);
    elseif (ixion == 2) then
	player:PrintToPlayer("Deshul : Remember, bring me a Stygian Ash.  I've seen them fall off Goblins.",0x0D);
	elseif (ixion == 3) then
	player:PrintToPlayer("Deshul : Just examine the waypoint next to me but remember not to go alone",0x0D);
	else
    player:PrintToPlayer("Deshul : Sorry, I can't help you right now.",0x0D);
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