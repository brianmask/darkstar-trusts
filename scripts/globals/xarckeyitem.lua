-------------------------------------------
-- Xarc Key Item
-- This function is a global setting
-- For the drop rate and Key Item
-- Distribution for Xarcabard
-- This allows the drops to be
-- Globally Adjusted
-------------------------------


require("scripts/globals/keyitems");
require("scripts/zones/Dynamis-Xarcabard/TextIDs");

-----------------------------------
-- xarcKeyItem
-----------------------------------

function xarcKeyItem(killer)

    local rate = 90; -- % where Key Item Drops from Kindred
    local chance = math.random(1,100);
    local keydrop = math.random(1,100); 
	-- killer:PrintToPlayer("Chance to Drop is"..chance);
	-- killer:PrintToPlayer("Keydrop is: "..keydrop);
    if (chance <= rate) then
	    if (keydrop < 26) then
		    killer:addKeyItem(ALABASTER_GRANULES_OF_TIME);
			killer:messageSpecial(KEYITEM_OBTAINED,ALABASTER_GRANULES_OF_TIME);			
			if (killer:getObjType() == TYPE_PET) then
			    killer:addKeyItem(ALABASTER_GRANULES_OF_TIME);
				killer:messageSpecial(KEYITEM_OBTAINED,ALABASTER_GRANULES_OF_TIME);
			end
	    elseif (keydrop < 51) then
		    killer:addKeyItem(AMBER_GRANULES_OF_TIME);
			killer:messageSpecial(KEYITEM_OBTAINED,AMBER_GRANULES_OF_TIME);					
			if (killer:getObjType() == TYPE_PET) then
			    killer:addKeyItem(AMBER_GRANULES_OF_TIME);
				killer:messageSpecial(KEYITEM_OBTAINED,AMBER_GRANULES_OF_TIME);
			end
	    elseif (keydrop < 76) then
		    killer:addKeyItem(AZURE_GRANULES_OF_TIME);
			killer:messageSpecial(KEYITEM_OBTAINED,AZURE_GRANULES_OF_TIME);		
			if (killer:getObjType() == TYPE_PET) then
			    killer:addKeyItem(AZURE_GRANULES_OF_TIME);
				killer:messageSpecial(KEYITEM_OBTAINED,AZURE_GRANULES_OF_TIME);
			end
	    elseif (keydrop < 101) then
		    killer:addKeyItem(CRIMSON_GRANULES_OF_TIME);
		    killer:messageSpecial(KEYITEM_OBTAINED,CRIMSON_GRANULES_OF_TIME);			
			if (killer:getObjType() == TYPE_PET) then
			    killer:addKeyItem(CRIMSON_GRANULES_OF_TIME);
				killer:messageSpecial(KEYITEM_OBTAINED,CRIMSON_GRANULES_OF_TIME);
			end			
        end

    end
end;

function xarcRelic(mob, killer)
-- Yes I am hardcoding this
local nqchance = 50; -- 30% chance
local hqchance = 20;
local relic = math.random(1,20);

local chance = math.random(1,100);

if (chance <= hqchance) then
    -- Decide what HQ relic
	printf("This is the number u%",relic);
	if (relic == 1) then
	    SetDropRate(1848,15252,1000); 
    elseif (relic == 2) then
	    SetDropRate(1848,14914,1000);		
    elseif (relic == 2) then
	    SetDropRate(1848,14911,1000);
    elseif (relic == 2) then
	    SetDropRate(1848,15249,1000);
    elseif (relic == 2) then
	    SetDropRate(1848,14921,1000);
    elseif (relic == 2) then
	    SetDropRate(1848,15246,1000);
    elseif (relic == 2) then
	    SetDropRate(1848,11472,1000);
    elseif (relic == 2) then
	    SetDropRate(1848,14510,1000);
    elseif (relic == 2) then
	    SetDropRate(1848,15259,1000);
    elseif (relic == 2) then
	    SetDropRate(1848,14500,1000);
    elseif (relic == 2) then
	    SetDropRate(1848,11481,1000);
    elseif (relic == 2) then
	    SetDropRate(1848,15589,1000);
    elseif (relic == 2) then
	    SetDropRate(1848,11469,1000);
    elseif (relic == 2) then
	    SetDropRate(1848,11306,1000);
    elseif (relic == 2) then
	    SetDropRate(1848,11466,1000);
    elseif (relic == 2) then
	    SetDropRate(1848,14917,1000);
    elseif (relic == 2) then
	    SetDropRate(1848,15256,1000);
    elseif (relic == 2) then
	    SetDropRate(1848,15248,1000);
    elseif (relic == 2) then
	    SetDropRate(1848,14506,1000);
    elseif (relic == 2) then
	    SetDropRate(1848,15258,1000);
    end		
elseif (chance <= nqchance) then
    -- Decide what NQ relic
	printf("This is the number u%",relic);
	if (relic == 1) then
	    SetDropRate(1848,15079,1000);
	elseif (relic == 2) then
        SetDropRate(1848,15107,1000);	
	elseif (relic == 3) then
        SetDropRate(1848,15104,1000);	
	elseif (relic == 4) then
        SetDropRate(1848,15076,1000);	
	elseif (relic == 5) then
        SetDropRate(1848,15114,1000);	
	elseif (relic == 6) then
        SetDropRate(1848,15073,1000);	
	elseif (relic == 7) then
        SetDropRate(1848,11471,1000);	
	elseif (relic == 8) then
        SetDropRate(1848,15107,1000);	
	elseif (relic == 9) then
        SetDropRate(1848,15086,1000);	
	elseif (relic == 10) then
        SetDropRate(1848,15087,1000);	
	elseif (relic == 11) then
        SetDropRate(1848,11480,1000);	
	elseif (relic == 12) then
        SetDropRate(1848,15126,1000);	
	elseif (relic == 13) then
        SetDropRate(1848,11468,1000);	
	elseif (relic == 14) then
        SetDropRate(1848,11305,1000);	
	elseif (relic == 15) then
        SetDropRate(1848,11465,1000);	
	elseif (relic == 16) then
        SetDropRate(1848,15110,1000);	
	elseif (relic == 17) then
        SetDropRate(1848,15083,1000);	
	elseif (relic == 18) then
        SetDropRate(1848,15073,1000);	
	elseif (relic == 19) then
        SetDropRate(1848,15093,1000);	
	elseif (relic == 20) then
        SetDropRate(1848,15085,1000);	
    end	
end	
	





end;
