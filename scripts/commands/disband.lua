---------------------------------------------------------------------------------------------------
-- func: goto
-- desc: Goes to the target player.
---------------------------------------------------------------------------------------------------

cmdprops =
{
    permission = 0,
    parameters = "s"
};

function onTrigger(player, hp, target)
    local hp = 0;
	local ally = player:getRecentAlly();
	
	if (ally == nil) then
	player:PrintToPlayer("Not a valid target");
    else
	
    ally:injectActionPacket(4, 261);
	ally:setHP( hp );

	-- player:PrintToPlayer(string.format("(%s) We've done good work today.  I'll see you around.", ally:getName()),0xF);  

	end
	
end