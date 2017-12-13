---------------------------------------------------------------------------------------------------
-- func: goto
-- desc: Goes to the target player.
---------------------------------------------------------------------------------------------------

cmdprops =
{
    permission = 1,
    parameters = "s"
};

function onTrigger(player, target)
local pet = player:getPet();
local wind = player:getEffectsCount(EFFECT_WIND_MANEUVER);
player:PrintToPlayer(wind);
end