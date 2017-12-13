---------------------------------------------------------------------------------------------------
-- func: @ah
-- desc: opens the Auction House menu anywhere in the world just to see if we can
---------------------------------------------------------------------------------------------------

cmdprops =
{
    permission = 1,
    parameters = ""
};

function onTrigger(player,target)
    local angle = player:getAngle(target);
	player:PrintToPlayer(angle);
end;