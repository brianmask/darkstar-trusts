---------------------------------------------------------------------------------------------------
-- func: @db <1-5> 
-- desc: Disbands Trust in the party based on slot
---------------------------------------------------------------------------------------------------

cmdprops =
{
    permission = 1,
    parameters = "is"
};

function onTrigger(player, memberID)
    local hp = 0;
	local size = player:getPartySize();
	
	if (memberID == nil) then
	player:PrintToPlayer("Syntax: @db <1-5> where # is the slot in the party the Trust occupies." ,0x1C);	
	-- elseif (size == 1) then
	-- player:PrintToPlayer("You do not have any Trusts to disband!" ,0x1C);		
	elseif (memberID - 1 > size) then
	player:PrintToPlayer("You do not have a trust active in that member slot!" ,0x1C);
	elseif (memberID <= 1) then
	player:PrintToPlayer("Slot 1 is you.  Please choose a party slot bigger than 1" ,0x1C);	
	else
	local ally = player:getAlly(memberID - 1);
	
	if (ally == nil) then
	player:PrintToPlayer("Not a valid target");
    else
	
    ally:injectActionPacket(4, 261);
	ally:setHP( hp );
    end
    end
    
end