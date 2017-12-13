---------------------------------------------------------------------------------------------------
-- func: pettp
-- desc: Sets the players pet tp.
---------------------------------------------------------------------------------------------------

cmdprops =
{
    permission = 1,
    parameters = "i"
};

function onTrigger(player, tp)
    local pet = player:getPet();
	local autotp = pet:getTP();
	player:PrintToPlayer(autotp);
end