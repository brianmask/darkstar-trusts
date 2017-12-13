-----------------------------------
--  Area: Aht Urhgan Whitegate
--  NPC:  Naja Salaheem
--  Type: Standard NPC
--  @pos 22.700 -8.804 -45.591 50
-----------------------------------
package.loaded["scripts/zones/Aht_Urhgan_Whitegate/TextIDs"] = nil;
-----------------------------------

require("scripts/globals/missions");
require("scripts/zones/Aht_Urhgan_Whitegate/TextIDs");
require("scripts/globals/titles");
require("scripts/globals/keyitems");

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)
end;

-----------------------------------
-- onTrigger Action
-----------------------------------
function onTrigger(player,npc)

	local TOAUM3_DAY = player:getVar("TOAUM3_STARTDAY");
	local realday = tonumber(os.date("%M")); -- %M for next minute, %j for next day
	local needToZone = player:needToZone();
	
	if (player:getCurrentMission(TOAU) == IMMORTAL_SENTRIES) then
	 	if (player:getVar("TOAUM2") == 1 or player:getVar("TOAUM2") == 2) then
	 		player:startEvent(0x0BBA,0,0,0,0,0,0,0,0,0);
	 	end
	elseif (player:getCurrentMission(TOAU) == PRESIDENT_SALAHEEM and player:getVar("TOAUM3") == 1) then
            player:startEvent(0x0049,0,0,0,0,0,0,0,0,0);
	elseif (player:getCurrentMission(TOAU) == PRESIDENT_SALAHEEM and player:getVar("TOAUM3") == 2 and TOAUM3_DAY ~= realday and needToZone == false) then
            player:startEvent(0x0BCC,0,0,0,0,0,0,0,0,0);
        elseif (player:getCurrentMission(TOAU) == KNIGHT_OF_GOLD and player:getVar("TOAUM4") == 0) then
            player:startEvent(0x0bcd,0,0,0,0,0,0,0,0,0);
        elseif (player:getCurrentMission(TOAU) == WESTERLY_WINDS and player:getVar("TOAUM7") == 1) then
            player:startEvent(0x0Bd4,0,0,0,0,0,0,0,0,0);
        elseif (player:getCurrentMission(TOAU) == UNDERSEA_SCOUTING) then
            player:startEvent(0x0beb,0,0,0,0,0,0,0,0,0);
        elseif (player:getCurrentMission(TOAU) == ASTRAL_WAVES) then
            player:startEvent(0x0bec,0,0,0,0,0,0,0,0,0);
        elseif (player:getCurrentMission(TOAU) == IMPERIAL_SCHEMES) then
            player:startEvent(0x0bfe,0,0,0,0,0,0,0,0,0);
        elseif (player:getCurrentMission(TOAU) == ROYAL_PUPPETEER) then
            player:startEvent(0x0bff,0,0,0,0,0,0,0,0,0);
        elseif (player:getCurrentMission(TOAU) == THE_DOLPHIN_CREST) then
            player:startEvent(0x0c00,0,0,0,0,0,0,0,0,0);
        elseif (player:getCurrentMission(TOAU) == THE_BLACK_COFFIN) then
            player:startEvent(0x0c01,0,0,0,0,0,0,0,0,0);
        elseif (player:getCurrentMission(TOAU) == GHOSTS_OF_THE_PAST_TOAU) then
            if (doRoyalPalaceArmorCheck(player) == true) then
                player:startEvent(3074,1,0,0,0,0,0,0,1,0);
            else
                player:startEvent(3074,0,0,0,0,0,0,0,0,0);
            end
        elseif (player:getCurrentMission(TOAU) == GUESTS_OF_THE_EMPIRE) then
            if (doRoyalPalaceArmorCheck(player) == true) then
                if (player:getVar("AhtUrganStatus") == 0) then
                    player:startEvent(3076,1,0,0,0,0,0,0,1,0);
                else
                    player:startEvent(3077,1,0,0,0,0,0,0,1,0);
                end
            else
                if (player:getVar("AhtUrganStatus") == 0) then
                    player:startEvent(3076,0,0,0,0,0,0,0,0,0);
                else
                    player:startEvent(3077,0,0,0,0,0,0,0,0,0);
                end
            end
        elseif (player:getCurrentMission(TOAU) == PASSING_GLORY and needToZone == false) then
            player:startEvent(3090,0,0,0,0,0,0,0,0,0);	
	
	
	
	
	
	
	
	
	else
		player:startEvent(0x0bbb,1,0,0,0,0,0,0,1,0) -- go back to work
		-- player:messageSpecial(0);--  need to find correct normal chat CS..
	end
	
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
	if (csid == 0x0BBA) then
		player:setVar("TOAUM2",0);
		player:completeMission(TOAU,IMMORTAL_SENTRIES);
		player:addMission(TOAU,PRESIDENT_SALAHEEM);
		player:addCurrency("imperial_standing", 150);
		player:addTitle(PRIVATE_SECOND_CLASS);
		player:addKeyItem(PSC_WILDCAT_BADGE);
		player:messageSpecial(KEYITEM_OBTAINED,PSC_WILDCAT_BADGE);
	elseif (csid == 0x0BCC) then
		player:completeMission(TOAU,PRESIDENT_SALAHEEM);
		player:addMission(TOAU,KNIGHT_OF_GOLD);
		player:setVar("TOAUM3",0);
		player:setVar("TOAUM3_DAY", 0);
	elseif (csid == 0x0049) then
		player:setVar("TOAUM3",2);
		player:setVar("TOAUM3_DAY", os.date("%M")); -- %M for next minute, %j for next day
        elseif (csid == 0x0bd4) then
            player:setVar("TOAUM7",0)
            player:completeMission(TOAU,WESTERLY_WINDS)
	    player:addMission(TOAU,A_MERCENARY_LIFE)
	        if (player:getFreeSlotsCount() == 0) then 
		    player:messageSpecial(ITEM_CANNOT_BE_OBTAINED,2185);
                else
		    player:addItem(2185,1)
                    player:messageSpecial(ITEM_OBTAINED,2185)
                    player:addItem(2185,1)
                end
        elseif (csid == 0x0bec) then
            player:completeMission(TOAU,ASTRAL_WAVES);
            player:addMission(TOAU,IMPERIAL_SCHEMES);
        elseif (csid == 0x0bfe) then
            player:completeMission(TOAU,IMPERIAL_SCHEMES);
            player:addMission(TOAU,ROYAL_PUPPETEER);
        elseif (csid == 0x0c00) then
            player:completeMission(TOAU,THE_DOLPHIN_CREST);
            player:addMission(TOAU,THE_BLACK_COFFIN);
------------------- New
        elseif (csid == 3074) then
            player:completeMission(TOAU,GHOSTS_OF_THE_PAST_TOAU);
            player:addMission(TOAU,GUESTS_OF_THE_EMPIRE);
			player:setVar("AhtUrganStatus", 1);

        if(option == 2) then
            player:setVar("AhtUrganStatus", 1);
        end
    elseif (csid == 3090) then
        player:completeMission(TOAU,PASSING_GLORY);
        player:setVar("TOAUM18_STARTDAY", 0);
        player:addMission(TOAU,SWEETS_FOR_THE_SOUL);		
		
		
		
	end
end;