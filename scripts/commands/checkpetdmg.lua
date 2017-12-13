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
local getdmg = pet:getRangedDmg();
local attack = pet:getStat(MOD_ATT);
player:PrintToPlayer(getdmg);
player:PrintToPlayer(attack);
end