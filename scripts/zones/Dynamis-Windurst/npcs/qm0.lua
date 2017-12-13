-----------------------------------
-- Area: Dynamis Windurst
-- NPC:  qm0 (???)
-- Notes: Spawns Megaboss
-----------------------------------
package.loaded["scripts/zones/Dynamis-Windurst/TextIDs"] = nil;
-----------------------------------

require("scripts/globals/keyitems");
require("scripts/zones/Dynamis-Windurst/TextIDs");

-----------------------------------
-- onTrade
-----------------------------------

function onTrade(player,npc,trade)
if ((trade:hasItemQty(3388,1)) and (trade:hasItemQty(3389,1)) and (trade:hasItemQty(3390,1)) and (trade:hasItemQty(3391,1))) then
player:addKeyItem(ALABASTER_GRANULES_OF_TIME);
player:messageSpecial(KEYITEM_OBTAINED,ALABASTER_GRANULES_OF_TIME);
player:tradeComplete();
elseif ((trade:hasItemQty(3388,1)) and (trade:hasItemQty(3389,1)) and (trade:hasItemQty(3390,1))) then
player:addKeyItem(AMBER_GRANULES_OF_TIME);
player:messageSpecial(KEYITEM_OBTAINED,AMBER_GRANULES_OF_TIME);
player:tradeComplete();
elseif ((trade:hasItemQty(3388,1)) and (trade:hasItemQty(3389,1))) then
player:addKeyItem(AZURE_GRANULES_OF_TIME);
player:messageSpecial(KEYITEM_OBTAINED,AZURE_GRANULES_OF_TIME);
player:tradeComplete();
elseif (trade:hasItemQty(3388,1)) then
player:addKeyItem(CRIMSON_GRANULES_OF_TIME);
player:messageSpecial(KEYITEM_OBTAINED,CRIMSON_GRANULES_OF_TIME);
player:tradeComplete();
end

if (GetMobAction(17543169) == 0 and trade:hasItemQty(3415,1)) and trade:hasItemQty(3416,1) and trade:hasItemQty(3417,1) and trade:hasItemQty(3418,1) and player:hasKeyItem(ALABASTER_GRANULES_OF_TIME) then
	player:setVar("DynaWeakener",4);
	player:tradeComplete();
	SpawnMob(17543169):updateClaim(player);
	player:delKeyItem(ALABASTER_GRANULES_OF_TIME);
elseif (GetMobAction(17543169) == 0 and trade:hasItemQty(3415,1)) and trade:hasItemQty(3416,1) and trade:hasItemQty(3417,1) and trade:hasItemQty(3418,1) and player:hasKeyItem(AMBER_GRANULES_OF_TIME) then
	player:setVar("DynaWeakener",2);
	player:tradeComplete();
	SpawnMob(17543169):updateClaim(player);
    player:delKeyItem(AMBER_GRANULES_OF_TIME);
elseif (GetMobAction(17543169) == 0 and trade:hasItemQty(3415,1)) and trade:hasItemQty(3416,1) and trade:hasItemQty(3417,1) and trade:hasItemQty(3418,1) and player:hasKeyItem(AZURE_GRANULES_OF_TIME) then
	player:setVar("DynaWeakener",2);
	player:tradeComplete();
	SpawnMob(17543169):updateClaim(player);
	player:delKeyItem(AZURE_GRANULES_OF_TIME);
elseif (GetMobAction(17543169) == 0 and trade:hasItemQty(3415,1)) and trade:hasItemQty(3416,1) and trade:hasItemQty(3417,1) and trade:hasItemQty(3418,1) and player:hasKeyItem(CRIMSON_GRANULES_OF_TIME) then
    player:setVar("DynaWeakener",1);
	player:tradeComplete();
	SpawnMob(17543169):updateClaim(player);
	player:delKeyItem(CRIMSON_GRANULES_OF_TIME);	
elseif (GetMobAction(17543169) == 0 and trade:hasItemQty(3415,1)) and trade:hasItemQty(3416,1) and trade:hasItemQty(3417,1) and trade:hasItemQty(3418,1) then
player:setVar("DynaWeakener",0);
    player:tradeComplete();
	SpawnMob(17543169):updateClaim(player);	
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