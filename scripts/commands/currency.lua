---------------------------------------------------------------------------------------------------
-- func: checks time
-- desc: Checks time remaining in Dynamis
---------------------------------------------------------------------------------------------------

cmdprops =
{
    permission = 0,
    parameters = "i"
};

function onTrigger(player)
local scyld = player:getCurrency("scyld");
local infamy = player:getCurrency("infamy");
player:PrintToPlayer("Your current balances are:", 0x15);
player:PrintToPlayer("Infamy: "..infamy..".", 0x15);
player:PrintToPlayer("Scyld: "..scyld..".", 0x15);
end