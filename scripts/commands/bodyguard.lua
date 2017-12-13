---------------------------------------------------------------------------------------------------
-- func: trust
-- desc: displays trust options
---------------------------------------------------------------------------------------------------

cmdprops =
{
    permission = 0,
    parameters = "s"
};

function onTrigger(player, toggle)
 	if (toggle == nil or tonumber(toggle) == nil or tonumber(toggle) > 1 or tonumber(toggle) < 0) then
	player:PrintToPlayer("Toggle the option to have Trust attack mobs that agro you automatically." ,0x1C);
	player:PrintToPlayer("Type @bodygaurd <#> 0: OFF | 1: ON - Default is set to 'OFF'" ,0x1C);
    elseif (tonumber(toggle) == 1) then
	player:PrintToPlayer("Bodygaurd set to ON.  Trusts will auto-attack mobs that you agro." ,0x1C);
	player:setVar("TrustBodygaurd", 1);
	elseif (tonumber(toggle) == 0) then
	player:PrintToPlayer("Bodygaurd set to OFF.  Trusts will ignore mobs that you agro." ,0x1C);
	player:setVar("TrustBodygaurd", 0);
	end

   	
end