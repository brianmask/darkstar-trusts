-----------------------------------
-- Area: Windurst Waters
-- NPC:  Fomina
-- Only sells when Windurst controlls Elshimo Lowlands
-- Confirmed shop stock, August 2013
-----------------------------------

require("scripts/globals/shop");


-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)
end;

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)
local aura = player:getVar("FerretoryAura");
 
if (aura > 0) and (aura < 5) then

stock = {0x22E5,1000,	--Leafslit 
	         0x22EE,1000,	--leaftip
	         0x22F7,1000,	--Leafdim
	         0x2300,1000,	--Leaforb
			 0x22E2,1000,  -- Snowslit
			 0x22EB,1000,  -- Snowtip
			 0x22F4,1000,  -- Snowdim
			 0x22FD,1000}  -- Snoworb
player:PrintToPlayer("Stone Merchant : Access Level 1 Granted", 0xD);
 
 
showShop(player, STATIC, stock);  
else if (aura > 4) and (aura < 10) then
stock = {0x22E5,1000,	--Leafslit 
	         0x22EE,1000,	--leaftip
	         0x22F7,1000,	--Leafdim
	         0x2300,1000,	--Leaforb
			 0x22E2,1000,  -- Snowslit
			 0x22EB,1000,  -- Snowtip
			 0x22F4,1000,  -- Snowdim
			 0x22FD,1000,  -- Snoworb
			 0x22E6,3000,  -- leafslit +1
			 0x22EF,3000,  -- leaftip +1
			 0x22F8,3000,  -- leafdim +1
			 0x2301,3000,  -- leaforb +1
			 0x22E3,3000,  -- snowslit +1
			 0x22EC,3000,  -- snowtip +1
			 0x22F5,3000,  -- snowdim +1
			 0x22FE,3000}  -- snoworb +1


 player:PrintToPlayer("Stone Merchant : Access Level 2 Granted", 0xD);
 
showShop(player, STATIC, stock);  
else if (aura > 9) then
stock = {0x22E5,1000,	--Leafslit 
	         0x22EE,1000,	--leaftip
	         0x22F7,1000,	--Leafdim
	         0x2300,1000,	--Leaforb
			 0x22E2,1000,  -- Snowslit
			 0x22EB,1000,  -- Snowtip
			 0x22F4,1000,  -- Snowdim
			 0x22FD,1000,  -- Snoworb
			 0x22E6,3000,  -- leafslit +1
			 0x22EF,3000,  -- leaftip +1
			 0x22F8,3000,  -- leafdim +1
			 0x2301,3000,  -- leaforb +1
			 0x22E3,3000,  -- snowslit +1
			 0x22EC,3000,  -- snowtip +1
			 0x22F5,3000,  -- snowdim +1
			 0x22FE,3000,  -- snoworb +1
			 0x22E7,5000,  -- leafslit +2
			 0x22F0,5000,  -- leaftip +2
			 0x22F9,5000,  -- leafdim +2
			 0x2302,5000,  -- leaforb +2
			 0x22E4,5000,  -- snowslit +2
			 0x22ED,5000,  -- snowtip +2
			 0x22F6,5000,  -- snowdim +2
			 0x22FF,5000}  -- snoworb +2
			 


 player:PrintToPlayer("Stone Merchant : Access Level 3 Granted", 0xD);
 
showShop(player, STATIC, stock); 
else
 player:PrintToPlayer("Stone Merchant : You don't have access", 0xD);

end
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
