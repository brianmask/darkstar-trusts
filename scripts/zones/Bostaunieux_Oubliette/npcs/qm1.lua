-----------------------------------
-- Area: Bostaunieux Obliette
-- Mob:  Bodach
-- @pos 20, 17, -140
-----------------------------------

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)
end;

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)
	if (player:hasKeyItem(MAP_TO_THE_ANNALS_OF_TRUTH) and player:getVar("ASURAN_FISTS_WIN") == 1) then
	SpawnMob(17461479):updateClaim(player);
	end;
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

function onEventFinish(player,csid,option,npc)
--printf("CSID: %u",csid);
--printf("RESULT: %u",option);
end;