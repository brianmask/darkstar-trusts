---------------------------------------------------------------------------------------------------
-- func: nexus
-- desc: Goes to the party leader.
---------------------------------------------------------------------------------------------------
require("scripts/globals/status");

cmdprops =
{
    permission = 0,
    parameters = "s"
};

function onTrigger(player, target)
    if (target == nil) then
        player:PrintToPlayer("You must enter a valid player name.");
        return;
    end

    local targ = player:getPartyLeader();
	local leader = GetPlayerByName(player:getPartyLeader());
	local X = leader:getXPos();
	player:PrintToPlayer(X);
	    local Y = leader:getYPos();
    local Z = leader:getZPos();
    if (leader ~= nil) then
        player:setPos(X, Y, Z, 0, leader:getZoneID() );    
    else
        player:PrintToPlayer("You must be in a party for this command to work");
    end
end