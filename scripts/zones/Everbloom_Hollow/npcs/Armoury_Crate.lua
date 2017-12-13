-----------------------------------
-- Area: Everbloom Hollow
-- NPC:  Armoury Crate
-- 
-----------------------------------
package.loaded["scripts/zones/Balgas_Dais/TextIDs"] = nil;
-------------------------------------

require("scripts/globals/titles");
require("scripts/globals/quests");
require("scripts/zones/Everbloom_Hollow/TextIDs");

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
    local kill = player:getVar("IxionKill");
		
    player:getBCNMloot();
	player:setPos(-345, 12, 19);
	player:addStatusEffect(EFFECT_LEVEL_RESTRICTION,75,3,300);
	if (kill == 1) then
	player:setVar("IxionChest",1);
	elseif (kill == 2) then
	player:setVar("IxionChest",2);
	end
	player:PrintToPlayer("Battlefield Timer has been reset to 5 minutes",0x0D);	
	player:addTempItem(5349,1);

	
	
end;

-----------------------------------
-- onEventUpdate
-----------------------------------

function onEventUpdate(player,csid,option)
end;

-----------------------------------
-- onEventFinish Action
-----------------------------------

function onEventFinish(player,csid,option)
end;