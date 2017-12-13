---------------------------------------------------------------------------------------------------
-- func: petmp
-- desc: Sets the players pet mp.
---------------------------------------------------------------------------------------------------

cmdprops =
{
    permission = 1,
    parameters = "i"
};

function onTrigger(player, mp)
    if (player:getPet() == nil or mp == nil) then
        return;
    end

    player:getPet():setMP(mp);
end