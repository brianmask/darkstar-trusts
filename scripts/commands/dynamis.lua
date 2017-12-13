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
local dynatime = player:getVar("Dynamis_Time_Remaining");
local currentm = 0;
local current = 0;
local currentpres = 0;
local currents = 0;
local scyldmult = player:getVar("ScyldMultiplier");
current = (dynatime / 1000) / 60;
currentm = math.floor((dynatime / 1000) / 60);
currentpres = current - currentm;
currents = math.floor(currentpres * 60);
if (currentm < 1) then
player:PrintToPlayer("You have less than 1 minute remaining in Dynamis.", 0x15);
elseif (currentm < 10) then
player:PrintToPlayer("You have 0:0"..currentm..":"..currents.." minutes remaining in Dynamis.", 0x15);
elseif (currentm < 10) and (currents < 10) then
player:PrintToPlayer("You have 0:0"..currentm..":0"..currents.." minutes remaining in Dynamis.", 0x15);
elseif (currents < 10) then
player:PrintToPlayer("You have 0:"..currentm..":0"..currents.." minutes remaining in Dynamis.", 0x15);
else
player:PrintToPlayer("You have 0:"..currentm..":"..currents.." minutes remaining in Dynamis.", 0x15);
end
player:PrintToPlayer("You currently have a +"..scyldmult.."% scyld bonus", 0x15);

end