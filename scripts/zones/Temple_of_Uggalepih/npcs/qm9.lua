-----------------------------------
-- Area: Temple of Uggalepih
-- NPC:  ??? Decimation NM
-- @pos 218.242,-8.107,205.827
-----------------------------------
package.loaded["scripts/zones/Temple_of_Uggalepih/TextIDs"] = nil;
-----------------------------------
require("scripts/globals/keyitems");
require("scripts/zones/Temple_of_Uggalepih/TextIDs");

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)
end;

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)
	 if (player:hasKeyItem(MAP_TO_THE_ANNALS_OF_TRUTH) and player:getVar("DECIMATION_WIN") == 1) then
	 SpawnMob(17428817):updateClaim(player);
     else
     player:messageSpecial(NOTHING_OUT_OF_ORDINARY);

	end
	
end;