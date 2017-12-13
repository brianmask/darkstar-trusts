---------------------------------------------------------------------------------------------------
-- func: @db <1-5> 
-- desc: Disbands Trust in the party based on slot
---------------------------------------------------------------------------------------------------

cmdprops =
{
    permission = 0,
    parameters = "is"
};

function onTrigger(player, toggle)
 	if (toggle == nil or tonumber(toggle) == nil or tonumber(toggle) > 2 or tonumber(toggle) < 0) then
	player:PrintToPlayer("Set the amount of time for trusts to WS at the start of a fight (excl. Curilla)" ,0x1C);
	player:PrintToPlayer("Type @tptrust <#> 0: (7 seconds) | 1: (15 seconds) | 2: (30 seconds)" ,0x1C);
    elseif (tonumber(toggle) == 0) then
	player:PrintToPlayer("Trust set to weapon skill 7 seconds after engaging if 100% TP or greater" ,0x1C);
	player:setVar("tpWait", 0);
	elseif (tonumber(toggle) == 1) then
	player:PrintToPlayer("Trust set to weapon skill 15 seconds after engaging if 100% TP or greater" ,0x1C);
	player:setVar("tpWait", 8000);
	elseif (tonumber(toggle) == 2) then
	player:PrintToPlayer("Trust set to weapon skill 30 seconds after engaging if 100% TP or greater" ,0x1C);
	player:setVar("tpWait", 23000);	
	end
    
end