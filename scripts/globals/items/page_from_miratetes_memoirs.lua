-----------------------------------------
-- ID: 4247
-- Item: Page From Miratete's Memo
-- Grants 4-8 Whiteshells
--
-----------------------------------------

require("scripts/globals/status");

-----------------------------------------
-- OnItemCheck
-----------------------------------------

function onItemCheck(target)
	local check = 56;
	if (target:getMainLvl() >= 20) then
		check = 0;
	end
	return check;
end;

-----------------------------------------
-- OnItemUse
-----------------------------------------

function onItemUse(target)
	local currencyrand = math.random(4,8);
	
	target:addItem(1449,currencyrand);
	target:PrintToPlayer("You obtain "..currencyrand.." Tukuku Whiteshells.", 0x15);
end;
