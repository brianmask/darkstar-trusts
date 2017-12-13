-----------------------------------
--
-- Zone: The_Ashu_Talif
--
-----------------------------------

require("scripts/globals/settings");
local TheAshuTalif = require("scripts/zones/The_Ashu_Talif/IDs");

-----------------------------------
--  onInitialize
-----------------------------------

function onInitialize(zone)
zone:registerRegion(1,-1,-1,-1,1,1,1);
end;

-----------------------------------
-- onZoneIn
-----------------------------------

function onZoneIn(player,prevZone)
    local cs = -1;
    return cs;
end;

-----------------------------------
-- onRegionEnter
-----------------------------------

function onRegionEnter(player,region)
    local regionID = region:GetRegionID();
	if (regionID == 1) then
	    player:setPos(-456,-3,-405,54);
	end	
end;

-----------------------------------
-- onEventUpdate
-----------------------------------

-----------------------------------
-- onEventUpdate
-----------------------------------

function onEventUpdate(player,csid,option,target)
    printf("Zone Update CSID: %u",csid);
    -- printf("Zone Update RESULT: %u",option);
end;

-----------------------------------
-- onEventFinish
-----------------------------------

function onEventFinish(player,csid,option)
    printf("Zone Finish CSID: %u",csid);
    -- printf("Zone Finish RESULT: %u",option);
   
    if (csid == 101 or csid == 102) then
	 printf("TRIGGED!!!!");
         player:setPos(0,0,0,0,54);
    end
end;
