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



end;

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)
	 local ixion = player:getVar("LightIxionStart");
	if (player:hasItem(19210) == true) and (ixion == 3) then
	player:startEvent(0x0003, 10);
	--player:startEvent(0x00C9, 0, 0, 0, 5, 0, 0, 0, 0);
	else
	player:PrintToPlayer("The device does not respond.",0x0D);
	end
	
	if (EventTriggerBCNM(player,npc)) then
		return;
	end


end;

-----------------------------------
-- onEventUpdate
-----------------------------------

function onEventUpdate(player,csid,option)
	if (csid == 3) and (option == 0) then
	player:killcs();
	player:killcs();
	-- check if all members have item
    local party = player:getParty();
    if (party ~= nil) then
        for i,member in ipairs(party) do
		    if (member:hasItem(19210) == true) then
	        player:setVar("IxionEnter",1);
		    else
			member:PrintToPlayer("Not all members have the required item",0x0D);
			end
			end
			end
	else
	        player:setVar("IxionEnter",1);	
	
	end
    

	    if (EventUpdateBCNM(player,csid,option)) then
        return;
    end
end;

-----------------------------------
-- onEventFinish Action
-----------------------------------

function onEventFinish(player,csid,option)
    local enter = player:getVar("IxionEnter");
	if (enter == 1) then
	player:setVar("IxionEnter",0);
	local party = player:getParty();
    if (party ~= nil) then
        for i,member in ipairs(party) do
		    member:startEvent(0x0004, 0, 0, 0, 5, 0, 0, 0, 0);
			member:delItem(19210,1);
			member:setPos(112,10,-16,147,0x56);
			end
	else
	 player:startEvent(0x0004, 0, 0, 0, 5, 0, 0, 0, 0);
	 player:delItem(19210,1);
	 player:setPos(112,10,-16,147,0x56);
	end
	end

end;