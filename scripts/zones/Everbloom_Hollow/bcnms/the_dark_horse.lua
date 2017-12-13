-----------------------------------
-- Area: Everbloom Hollow
-- Name: Mission Rank 2
-- @pos 299 -123 345 146
-----------------------------------
package.loaded["scripts/zones/Everbloom_Hollow/TextIDs"] = nil;
-------------------------------------

require("scripts/globals/keyitems");
require("scripts/zones/Everbloom_Hollow/TextIDs");

-----------------------------------

-- After registering the BCNM via bcnmRegister(bcnmid)
function onBcnmRegister(player,instance)
player:addTempItem(5349,1);
end;

-- Physically entering the BCNM via bcnmEnter(bcnmid)
function onBcnmEnter(player,instance)
end;

-- Leaving the BCNM by every mean possible, given by the LeaveCode
-- 1=Select Exit on circle
-- 2=Winning the BC
-- 3=Disconnected or warped out
-- 4=Losing the BC
-- via bcnmLeave(1) or bcnmLeave(2). LeaveCodes 3 and 4 are called
-- from the core when a player disconnects or the time limit is up, etc

function onBcnmLeave(player,instance,leavecode)
-- print("leave code "..leavecode);
if (leavecode == 2) then 
     player:PrintToPlayer("You Win");
    -- player:addStatusEffect(EFFECT_LEVEL_RESTRICTION,75,3,300);
	end
if (leavecode == 4) then 
         player:PrintToPlayer("You Lose");
	end	
	

	
	
end;

function onEventUpdate(player,csid,option)
-- print("bc update csid "..csid.." and option "..option);
end;
	
function onEventFinish(player,csid,option)
-- print("bc finish csid "..csid.." and option "..option);
	

	
end;