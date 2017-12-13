-----------------------------------
-- Area: Sealion's Den
-- NPC:  Sueleen
-- @pos 612 132 774 32
-----------------------------------
package.loaded["scripts/zones/Sealions_Den/TextIDs"] = nil;
package.loaded["scripts/globals/bcnm"] = nil;
-----------------------------------

require("scripts/globals/missions");
require("scripts/zones/Sealions_Den/TextIDs");
require("scripts/globals/bcnm");
require("scripts/globals/keyitems");
require("scripts/globals/teleports");


-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)
end;

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)

    local party = player:getParty();
    if (party ~= nil) then
	    for i,member in ipairs(party) do
	        member:setVar("PRISHE_WIN",1);
	    end	
	elseif (party == nil) then
	    player:setVar("PRISHE_WIN",1);
	end	

    player:getBCNMloot();
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