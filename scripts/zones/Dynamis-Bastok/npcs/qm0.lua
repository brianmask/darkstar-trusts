-----------------------------------
-- Area:  Dynamis Bastok
-- NPC:   qm0 (???)
-- Notes: Spawns Megaboss
-----------------------------------
package.loaded["scripts/zones/Dynamis-Bastok/TextIDs"] = nil;
-----------------------------------

require("scripts/globals/keyitems");
require("scripts/zones/Dynamis-Bastok/TextIDs");

-----------------------------------
-- onTrade
-----------------------------------

function onTrade(player,npc,trade)
if ((trade:hasItemQty(3384,1)) and (trade:hasItemQty(3385,1)) and (trade:hasItemQty(3386,1)) and (trade:hasItemQty(3387,1))) then
player:addKeyItem(ALABASTER_GRANULES_OF_TIME);
player:messageSpecial(KEYITEM_OBTAINED,ALABASTER_GRANULES_OF_TIME);
player:tradeComplete();
elseif ((trade:hasItemQty(3384,1)) and (trade:hasItemQty(3385,1)) and (trade:hasItemQty(3386,1))) then
player:addKeyItem(AMBER_GRANULES_OF_TIME);
player:messageSpecial(KEYITEM_OBTAINED,AMBER_GRANULES_OF_TIME);
player:tradeComplete();
elseif ((trade:hasItemQty(3384,1)) and (trade:hasItemQty(3385,1))) then
player:addKeyItem(AZURE_GRANULES_OF_TIME);
player:messageSpecial(KEYITEM_OBTAINED,AZURE_GRANULES_OF_TIME);
player:tradeComplete();
elseif (trade:hasItemQty(3384,1)) then
player:addKeyItem(CRIMSON_GRANULES_OF_TIME);
player:messageSpecial(KEYITEM_OBTAINED,CRIMSON_GRANULES_OF_TIME);
player:tradeComplete();
end

if (GetMobAction(17539073) == 0 and trade:hasItemQty(3410,1)) and trade:hasItemQty(3411,1) and trade:hasItemQty(3412,1) and trade:hasItemQty(3413,1) and player:hasKeyItem(ALABASTER_GRANULES_OF_TIME) then
	player:setVar("DynaWeakener",4);
	SpawnMob(17539073):updateClaim(player);
	player:tradeComplete();
	player:delKeyItem(ALABASTER_GRANULES_OF_TIME);
elseif (GetMobAction(17539073) == 0 and trade:hasItemQty(3410,1)) and trade:hasItemQty(3411,1) and trade:hasItemQty(3412,1) and trade:hasItemQty(3413,1) and player:hasKeyItem(AMBER_GRANULES_OF_TIME) then
	player:setVar("DynaWeakener",2);
	SpawnMob(17539073):updateClaim(player);
	player:tradeComplete();
    player:delKeyItem(AMBER_GRANULES_OF_TIME);
elseif (GetMobAction(17539073) == 0 and trade:hasItemQty(3410,1)) and trade:hasItemQty(3411,1) and trade:hasItemQty(3412,1) and trade:hasItemQty(3413,1) and player:hasKeyItem(AZURE_GRANULES_OF_TIME) then
	player:setVar("DynaWeakener",2);
	SpawnMob(17539073):updateClaim(player);
	player:tradeComplete();
	player:delKeyItem(AZURE_GRANULES_OF_TIME);
elseif (GetMobAction(17539073) == 0 and trade:hasItemQty(3410,1)) and trade:hasItemQty(3411,1) and trade:hasItemQty(3412,1) and trade:hasItemQty(3413,1) and player:hasKeyItem(CRIMSON_GRANULES_OF_TIME) then
    player:setVar("DynaWeakener",1);
	SpawnMob(17539073):updateClaim(player);
	player:tradeComplete();
	player:delKeyItem(CRIMSON_GRANULES_OF_TIME);	
elseif (GetMobAction(17539073) == 0 and trade:hasItemQty(3410,1)) and trade:hasItemQty(3411,1) and trade:hasItemQty(3412,1) and trade:hasItemQty(3413,1) then
player:setVar("DynaWeakener",0);
    player:tradeComplete();
	SpawnMob(17539073):updateClaim(player);	
end	

end;

-----------------------------------
-- onTrigger
-----------------------------------

function onTrigger(player,npc)
	

	
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