-----------------------------------
-- Area: Kuftal Tunnel
-- NPC:  ??? (qm3)
-- Note: Used to spawn Kettenkaefer Tachi Kasha WSNM
-- @pos 200.608,11.249,99.380
-----------------------------------
package.loaded["scripts/zones/Kuftal_Tunnel/TextIDs"] = nil;
-----------------------------------

require("scripts/zones/Kuftal_Tunnel/TextIDs");


-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)
    
    
end; 

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)
	 if (player:hasKeyItem(MAP_TO_THE_ANNALS_OF_TRUTH) and player:getVar("TACHI_KASHA_WIN") == 1) then
	 SpawnMob(17490235):updateClaim(player);
     else
     player:messageSpecial(NOTHING_OUT_OF_ORDINARY);
	 end

end;
