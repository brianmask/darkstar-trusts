-----------------------------------
-- Area: The Shrine of Ru'Avitau
-- NPC:  All Cerment Doors
-- Opens Doors for Sky
-----------------------------------
package.loaded["scripts/zones/The_Shrine_of_RuAvitau/TextIDs"] = nil;
-----------------------------------

require("scripts/zones/The_Shrine_of_RuAvitau/TextIDs");	
require("scripts/globals/keyitems");
	
	
function skyDoors(player,npc)	
	local npcID = npc:getID();
	local Door_Offset = 17506718; -- _4y0
	
	if (player:hasKeyItem(MAGICKED_ASTROLABE)) then
	if (npcID == Door_Offset or npcID == Door_Offset+1 or npcID == Door_Offset+2 or npcID == Door_Offset+3 or npcID == Door_Offset+4 or 
	   npcID == Door_Offset+5 or npcID == Door_Offset+6 or npcID == Door_Offset+7 or npcID == Door_Offset+8 or npcID == Door_Offset+9 or
	   npcID == Door_Offset+10 or npcID == Door_Offset+11 or npcID == Door_Offset+12 or npcID == Door_Offset+13 or npcID == Door_Offset+14 or 
	   npcID == Door_Offset+15 or npcID == Door_Offset+16 or npcID == Door_Offset+17 or npcID == Door_Offset+18 or npcID == Door_Offset+19 or 
	   npcID == Door_Offset+20 or npcID == Door_Offset+21) then
		GetNPCByID(Door_Offset+4):setAnimation(8); --blue door
		GetNPCByID(Door_Offset+5):setAnimation(8);
		GetNPCByID(Door_Offset+6):setAnimation(8);
		GetNPCByID(Door_Offset+7):setAnimation(8);
		GetNPCByID(Door_Offset+10):setAnimation(8);
		GetNPCByID(Door_Offset+11):setAnimation(8);
		GetNPCByID(Door_Offset+16):setAnimation(8);
		GetNPCByID(Door_Offset+17):setAnimation(8);
		GetNPCByID(Door_Offset+18):setAnimation(8);
		GetNPCByID(Door_Offset+20):setAnimation(8);
		GetNPCByID(Door_Offset+3):setAnimation(9); --yellow door
		GetNPCByID(Door_Offset+2):setAnimation(9);
		GetNPCByID(Door_Offset+1):setAnimation(9);
		GetNPCByID(Door_Offset):setAnimation(9);
		GetNPCByID(Door_Offset+12):setAnimation(9);
		GetNPCByID(Door_Offset+13):setAnimation(9);
		GetNPCByID(Door_Offset+14):setAnimation(9);
		GetNPCByID(Door_Offset+15):setAnimation(9);
		GetNPCByID(Door_Offset+19):setAnimation(9);
		GetNPCByID(Door_Offset+21):setAnimation(9);
		GetNPCByID(Door_Offset+30):setAnimation(8); --blue monolith
		GetNPCByID(Door_Offset+32):setAnimation(8);
		GetNPCByID(Door_Offset+34):setAnimation(8);
		GetNPCByID(Door_Offset+36):setAnimation(8);
		GetNPCByID(Door_Offset+42):setAnimation(8);
		GetNPCByID(Door_Offset+44):setAnimation(8);
		GetNPCByID(Door_Offset+50):setAnimation(8);
		GetNPCByID(Door_Offset+52):setAnimation(8);
		GetNPCByID(Door_Offset+60):setAnimation(8);
		GetNPCByID(Door_Offset+22):setAnimation(9); --yellow monolith
		GetNPCByID(Door_Offset+24):setAnimation(9);
		GetNPCByID(Door_Offset+26):setAnimation(9);
		GetNPCByID(Door_Offset+28):setAnimation(9);
		GetNPCByID(Door_Offset+46):setAnimation(9);
		GetNPCByID(Door_Offset+48):setAnimation(9);
		GetNPCByID(Door_Offset+54):setAnimation(9);
		GetNPCByID(Door_Offset+56):setAnimation(9);
		GetNPCByID(Door_Offset+58):setAnimation(9);
	else
		GetNPCByID(Door_Offset+4):setAnimation(9); -- blue door
		GetNPCByID(Door_Offset+5):setAnimation(9);
		GetNPCByID(Door_Offset+6):setAnimation(9);
		GetNPCByID(Door_Offset+7):setAnimation(9);
		GetNPCByID(Door_Offset+10):setAnimation(9);
		GetNPCByID(Door_Offset+11):setAnimation(9);
		GetNPCByID(Door_Offset+16):setAnimation(9);
		GetNPCByID(Door_Offset+17):setAnimation(9);
		GetNPCByID(Door_Offset+18):setAnimation(9);
		GetNPCByID(Door_Offset+20):setAnimation(9);
		GetNPCByID(Door_Offset+3):setAnimation(8); -- yellow door
		GetNPCByID(Door_Offset+2):setAnimation(8);
		GetNPCByID(Door_Offset+1):setAnimation(8);
		GetNPCByID(Door_Offset):setAnimation(8);
		GetNPCByID(Door_Offset+12):setAnimation(8);
		GetNPCByID(Door_Offset+13):setAnimation(8);
		GetNPCByID(Door_Offset+14):setAnimation(8);
		GetNPCByID(Door_Offset+15):setAnimation(8);
		GetNPCByID(Door_Offset+19):setAnimation(8);
		GetNPCByID(Door_Offset+21):setAnimation(8);
		GetNPCByID(Door_Offset+30):setAnimation(9); --blue monolith
		GetNPCByID(Door_Offset+32):setAnimation(9);
		GetNPCByID(Door_Offset+34):setAnimation(9);
		GetNPCByID(Door_Offset+36):setAnimation(9);
		GetNPCByID(Door_Offset+42):setAnimation(9);
		GetNPCByID(Door_Offset+44):setAnimation(9);
		GetNPCByID(Door_Offset+50):setAnimation(9);
		GetNPCByID(Door_Offset+52):setAnimation(9);
		GetNPCByID(Door_Offset+60):setAnimation(9);
		GetNPCByID(Door_Offset+22):setAnimation(8); --yellow monolith
		GetNPCByID(Door_Offset+24):setAnimation(8);
		GetNPCByID(Door_Offset+26):setAnimation(8);
		GetNPCByID(Door_Offset+28):setAnimation(8);
		GetNPCByID(Door_Offset+46):setAnimation(8);
		GetNPCByID(Door_Offset+48):setAnimation(8);
		GetNPCByID(Door_Offset+54):setAnimation(8);
		GetNPCByID(Door_Offset+56):setAnimation(8);
		GetNPCByID(Door_Offset+58):setAnimation(8);
	end
	end
end;	