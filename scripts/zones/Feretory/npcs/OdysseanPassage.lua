-----------------------------------
--	Area: Feretory
--	NPC:  Odyssean Passage
--	Working 100%
-----------------------------------

require("scripts/globals/settings");

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)
end; 

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)
    local warp = player:getVar("FeretoryWarp");
	if (warp == 1) then -- Windurst Warp
	player:setPos(218,-12,223,123,240);
	else if (warp == 2) then -- Bastok Warp
	player:setPos(78,8,-230,131,236);
	else
	player:setPos(78,0,40,124,231); -- North Sandy Warp
	end
	end
	
end;

-----------------------------------
-- onEventUpdate
-----------------------------------

function onEventUpdate(player,csid,option)
--printf("CSID: %u",csid);
--printf("RESULT: %u",option);
end;

-----------------------------------
-- onEventFinish
-----------------------------------

function onEventFinish(player,csid,option)
--printf("CSID: %u",csid);
--printf("RESULT: %u",option);
end;



