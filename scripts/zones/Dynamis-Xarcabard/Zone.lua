-----------------------------------
--
-- Zone: Dynamis-Xarcabard
--
-----------------------------------
package.loaded["scripts/zones/Dynamis-Xarcabard/TextIDs"] = nil;
-----------------------------------

require("scripts/globals/settings");
require("scripts/zones/Dynamis-Xarcabard/TextIDs");

-----------------------------------
--  onInitialize
-----------------------------------

function onInitialize(zone)
end;

-----------------------------------
-- onConquestUpdate
-----------------------------------

function onConquestUpdate(zone, updatetype)
    local players = zone:getPlayers();

    for name, player in pairs(players) do
        conquestUpdate(zone, player, updatetype, CONQUEST_BASE);
    end
end;

-----------------------------------
-- onZoneIn
-----------------------------------

function onZoneIn(player,prevZone)
    local cs = -1;
	local d1 = 0;
	local d2 = 0;
	local d3 = 0;
	local d4 = 0;
	local d5 = 0;
	local d6 = 0;
	local reduction = 0;
	local reentertime = 43200;
	
	
	if (player:hasKeyItem(HYDRA_CORPS_COMMAND_SCEPTER)) then
	d1 = 1;
	end
	if (player:hasKeyItem(HYDRA_CORPS_EYEGLASS)) then
	d2 = 1;
	end
	if (player:hasKeyItem(HYDRA_CORPS_LANTERN)) then
	d3 = 1;
	end
	if (player:hasKeyItem(HYDRA_CORPS_TACTICAL_MAP)) then
	d4 = 1;
	end
	if (player:hasKeyItem(HYDRA_CORPS_INSIGNIA)) then
	d5 = 1;
	end
	if (player:hasKeyItem(HYDRA_CORPS_BATTLE_STANDARD)) then	
	d6 = 1;
	end
	
	reduction = d1 + d2 + d3 + d4 + d5 + d6;
	
	if (reduction == 1) then
	reentertime = 28800;
	elseif (reduction == 2) then
	reentertime = 21600;
	elseif (reduction == 3) then
	reentertime = 14400;
	elseif (reduction == 4) then
	reentertime = 10800;
	elseif (reduction == 5) then
	reentertime = 7200;
	elseif (reduction == 6) then
	reentertime = 0;
	end
	
	printf("Entering Xarc");
	if (player:hasStatusEffect(EFFECT_DYNA_RESTRICTION) == false) then
	printf("adding Dyna Restriction");
	player:addStatusEffectEx(EFFECT_DYNA_RESTRICTION,EFFECT_LEVEL_RESTRICTION,75,3,5400);
    player:PrintToPlayer("You have 90 minutes remaining in Dynamis", 0xD);
	if (reduction == 0) then
    player:PrintToPlayer("You may re-enter Dynamis in 12 Hours", 0xD);	
	elseif (reduction == 1) then
    player:PrintToPlayer("Due to certain Key Items, you may re-enter Dynamis in 8 Hours", 0xD);
	elseif (reduction == 2) then
    player:PrintToPlayer("Due to certain Key Items, you may re-enter Dynamis in 6 Hours", 0xD);
	elseif (reduction == 3) then
    player:PrintToPlayer("Due to certain Key Items, you may re-enter Dynamis in 4 Hours", 0xD);
	elseif (reduction == 4) then
    player:PrintToPlayer("Due to certain Key Items, you may re-enter Dynamis in 3 Hours", 0xD);
	elseif (reduction == 5) then
    player:PrintToPlayer("Due to certain Key Items, you may re-enter Dynamis in 2 Hours", 0xD);
	elseif (reduction == 6) then
    player:PrintToPlayer("Defeating all areas of Dynamis has granted you immediate re-entry", 0xD);
	end
	 player:setVar("Dynamis_Time_Remaining",5400000);
	 player:setVar("ScyldMultiplier",0);
	 player:setVar("Dynamis_Reenter",os.time() + reentertime);
	 end
	return cs;
end;

-----------------------------------
-- onRegionEnter
-----------------------------------

function onRegionEnter(player,region)
end;

-----------------------------------
-- onEventUpdate
-----------------------------------

function onEventUpdate(player,csid,option)
    -- printf("CSID: %u",csid);
    -- printf("RESULT: %u",option);
end;

-----------------------------------
-- onEventFinish
-----------------------------------

function onEventFinish(player,csid,option)
    -- printf("CSID: %u",csid);
    -- printf("RESULT: %u",option);
    if (csid == 0) then
        player:setPos(569.312,-0.098,-270.158,90,0x70);
    end
end;