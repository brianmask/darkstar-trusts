-----------------------------------
--	Area: Windurst Waters
--	NPC:  Churano-Shurano
--	Working 100%
-----------------------------------

require("scripts/globals/settings");
require("scripts/globals/keyitems");

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)

local balance = 0;
local papyrus = 50000; 
local pinfamy = player:getCurrency("infamy");
local astro = player:getVar("ASTROLABE");

if (trade:hasItemQty( 1088, 1 ) and (astro == 1)) then 
    if (pinfamy >= papyrus) then   
    player:delCurrency("infamy", papyrus);
    player:tradeComplete();
	player:PrintToPlayer("Churano-Shurano : Here you go. Now you can open all sorts of doors.  Shh...don't tell anyone!", 0xD);
    player:messageSpecial(KEYITEM_OBTAINED,MAGICKED_ASTROLABE);
	player:addKeyItem(MAGICKED_ASTROLABE);
	player:setVar("ASTROLABE",0); 
	else
    balance = papyrus - pinfamy; 
    player:PrintToPlayer( "Churano-Shurano : Hey!!!  You need "..balance.." more infamy.", 0xD);
    end
end


end;

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)
	if ((player:hasKeyItem(MAGICKED_ASTROLABE) == false) and (player:getMainLvl() >= 50)) then
	player:PrintToPlayer("Churano-Shurano : Hey I can make you a sort of master key.  Just trade me the following:", 0xD);
	player:PrintToPlayer("Churano-Shurano : Ancient Papyrus and 50,000 of that infamy I keep hearing about.", 0xD);
    player:setVar("ASTROLABE",1);
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



