-----------------------------------
-- Area: Lower Jeuno
--  NPC: Relic Goblin
-- Type: Starts Relic Process changing AF to Relic
-----------------------------------

require("scripts/globals/chocobo");
require("scripts/globals/keyitems");
require("scripts/globals/settings");
require("scripts/globals/status");

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)
local level = player:getMainLvl();
local job = player:getMainJob();

-- Warrior Trade
	if (job == 1) and (trade:hasItemQty(18214, 1)) and trade:hasItemQty( 1450, 10 ) and (player:getVar("WARAFweapon") == 3) then
             -- Complete the trade..
            player:tradeComplete();
			player:PrintToPlayer("Netblyx : Here you go.", 0xD);
			player:addItem(18292, 1, 519, 6); -- Attack +5
			player:setVar("WARAFweapon", 0);
			player:setVar("WARRelicweapon", 1);
			player:messageSpecial(ITEM_OBTAINED, 18292);
			
    end
	if (job == 1) and (trade:hasItemQty(18214, 1)) and (player:getVar("WARAFweapon") == 3) then
			player:PrintToPlayer("Netblyx : I can make this into a Bravura...eventually with 10 L.Jadeshells", 0xD);		
    end


--------------------------------------------------------
--       MONK TRADE Beat Cesti 17478                  --
--------------------------------------------------------


	if (job == 2) and (trade:hasItemQty(17478, 1)) and trade:hasItemQty( 1453, 10 ) and (player:getVar("MNKAFweapon") == 3) then
             -- Complete the trade..
            player:tradeComplete();
			player:PrintToPlayer("Netblyx : Here you go.", 0xD);
			player:addItem(18262, 1, 519,6);
			player:setVar("MNKAFweapon", 0);
			player:setVar("MNKRelicweapon", 1);
			player:messageSpecial(ITEM_OBTAINED, 18262);
	end		
	if (job == 2) and (trade:hasItemQty(17478, 1)) and (player:getVar("MNKAFweapon") == 3) then
			player:PrintToPlayer("Netblyx : I can make this into a Spharai...eventually with 10 Montion Silverpieces", 0xD);		
    end



--------------------------------------------------------
--      WHITE MAGE TRADE Blessed Hammer 17422         --
--------------------------------------------------------

if (job == 3) and (trade:hasItemQty(17422, 1)) and trade:hasItemQty( 1453, 10 ) and (player:getVar("WHMAFweapon") == 3) then
             -- Complete the trade..
            player:tradeComplete();
			player:PrintToPlayer("Netblyx : Here you go.", 0xD);
			player:addItem(18322, 1, 524,6);
			player:setVar("WHMAFweapon", 0);
			player:setVar("WHMRelicweapon", 1);
			player:messageSpecial(ITEM_OBTAINED, 18322);
	end		
	if (job == 3) and (trade:hasItemQty(17422, 1)) and (player:getVar("WHMAFweapon") == 3) then
			player:PrintToPlayer("Netblyx : I can make this into a Mjolnir...eventually with 10 Montiont Silverpieces", 0xD);		
    end



--------------------------------------------------------
--      BLACK MAGE TRADE DUSKY STAFF 17572             --
--------------------------------------------------------



if (job == 4) and (trade:hasItemQty(17572, 1)) and trade:hasItemQty( 1450, 10 ) and (player:getVar("BLMAFweapon") == 3) then
             -- Complete the trade..
            player:tradeComplete();
			player:PrintToPlayer("Netblyx : Here you go.", 0xD);
			player:addItem(18328, 1, 523,6);
			player:setVar("BLMAFweapon", 0);
			player:setVar("BLMRelicweapon", 1);
			player:messageSpecial(ITEM_OBTAINED, 18328);
	end		
	if (job == 4) and (trade:hasItemQty(17572, 1)) and (player:getVar("BLMAFweapon") == 3) then
			player:PrintToPlayer("Netblyx : I can make this into an Claustrum...eventually with 10 L.Jadeshells", 0xD);		
    end

--------------------------------------------------------
--      RED MAGE TRADE FENCING DEGEN 16829            --
--------------------------------------------------------



if (job == 5) and (trade:hasItemQty(16829, 1)) and trade:hasItemQty( 1456, 10 ) and (player:getVar("RDMAFweapon") == 3) then
             -- Complete the trade..
            player:tradeComplete();
			player:PrintToPlayer("Netblyx : Here you go.", 0xD);
			player:addItem(18274, 1, 519,6);
			player:setVar("RDMAFweapon", 0);
			player:setVar("RDMRelicweapon", 1);
			player:messageSpecial(ITEM_OBTAINED, 18274);
	end		
	if (job == 5) and (trade:hasItemQty(16829, 1)) and (player:getVar("RDMAFweapon") == 3) then
			player:PrintToPlayer("Netblyx : I can make this into an Excalibur...eventually with 10 One-Hundred Byne Bills.", 0xD);		
    end


--------------------------------------------------------
--      THF TRADE MARAUDER'S KNIFE 16764              --
--------------------------------------------------------



if (job == 6) and (trade:hasItemQty(16764, 1)) and trade:hasItemQty( 1453, 10 ) and (player:getVar("THFAFweapon") == 3) then
             -- Complete the trade..
            player:tradeComplete();
			player:PrintToPlayer("Netblyx : Here you go.", 0xD);
			player:addItem(18268, 1, 520,6);
			player:setVar("THFAFweapon", 0);
			player:setVar("THFRelicweapon", 1);
			player:messageSpecial(ITEM_OBTAINED, 18268);
	end		
	if (job == 6) and (trade:hasItemQty(16764, 1)) and (player:getVar("THFAFweapon") == 3) then
			player:PrintToPlayer("Netblyx : I can make this into a Mandau...eventually with 10 Montiont Silverpieces", 0xD);		
    end


--------------------------------------------------------
--      PLD TRADE HONOR SWORD 17643                   --
--------------------------------------------------------



if (job == 7) and (trade:hasItemQty(17643, 1)) and trade:hasItemQty( 1456, 10 ) and (player:getVar("PLDAFweapon") == 3) then
             -- Complete the trade..
            player:tradeComplete();
			player:PrintToPlayer("Netblyx : Here you go.", 0xD);
			player:addItem(18274, 1, 519,6);
			player:setVar("PLDAFweapon", 0);
			player:setVar("PLDRelicweapon", 1);
			player:messageSpecial(ITEM_OBTAINED, 18274);
	end		
	if (job == 7) and (trade:hasItemQty(17643, 1)) and (player:getVar("PLDAFweapon") == 3) then
			player:PrintToPlayer("Netblyx : I can make this into an Excalibur...eventually with 10 One-Hundred Byne Bills.", 0xD);		
    end




--------------------------------------------------------
--      PLD TRADE HEATER SHIELD 12307                 --
--------------------------------------------------------


if (job == 7) and (trade:hasItemQty(12307, 1)) and trade:hasItemQty( 1453, 10 ) and (player:getVar("PLDAFshield") == 3) then
             -- Complete the trade..
            player:tradeComplete();
			player:PrintToPlayer("Netblyx : Here you go.", 0xD);
			player:addItem(15068, 1, 521,6);
			player:setVar("PLDAFshield", 0);
			player:setVar("PLDRelicshield", 1);
			player:messageSpecial(ITEM_OBTAINED, 15068);
	end		
	if (job == 7) and (trade:hasItemQty(12307, 1)) and (player:getVar("PLDAFshield") == 3) then
			player:PrintToPlayer("Netblyx : I can make this into an Aegis...eventually with 10 Montiont Silverpieces", 0xD);		
    end




--------------------------------------------------------
--      DRK TRADE RAVEN SCYTHE 16798                  --
--------------------------------------------------------



if (job == 8) and (trade:hasItemQty(16798, 1)) and trade:hasItemQty( 1456, 10 ) and (player:getVar("DRKAFweapon") == 3) then
             -- Complete the trade..
            player:tradeComplete();
			player:PrintToPlayer("Netblyx : Here you go.", 0xD);
			player:addItem(18304, 1, 519,6);
			player:setVar("DRKAFweapon", 0);
			player:setVar("DRKRelicweapon", 1);
			player:messageSpecial(ITEM_OBTAINED, 18304);
	end		
	if (job == 8) and (trade:hasItemQty(16798, 1)) and (player:getVar("DRKAFweapon") == 3) then
			player:PrintToPlayer("Netblyx : I can make this into an Apocalypse...eventually with 10 One-Hundred Byne Bills.", 0xD);		
    end




--------------------------------------------------------
--      DRK TRADE GREATSWORD 16590                    --
--------------------------------------------------------



if (job == 8) and (trade:hasItemQty(16590, 1)) and trade:hasItemQty( 1450, 10 ) and (player:getVar("DRKAFweapongs") == 3) then
             -- Complete the trade..
            player:tradeComplete();
			player:PrintToPlayer("Netblyx : Here you go.", 0xD);
			player:addItem(18280, 1, 519,6);
			player:setVar("DRKAFweapongs", 0);
			player:setVar("DRKRelicweapongs", 1);
			player:messageSpecial(ITEM_OBTAINED, 18280);
	end		
	if (job == 8) and (trade:hasItemQty(16590, 1)) and (player:getVar("DRKAFweapongs") == 3) then
			player:PrintToPlayer("Netblyx : I can make this into an Ragnarok...eventually with 10 L.Jadeshells", 0xD);		
    end


--------------------------------------------------------
--      BST TRADE BARABORI AXE 16680                  --
--------------------------------------------------------



if (job == 9) and (trade:hasItemQty(16680, 1)) and trade:hasItemQty( 1453, 10 ) and (player:getVar("BSTAFweapon") == 3) then
             -- Complete the trade..
            player:tradeComplete();
			player:PrintToPlayer("Netblyx : Here you go.", 0xD);
			player:addItem(18286, 1, 519,6);
			player:setVar("BSTAFweapon", 0);
			player:setVar("BSTRelicweapon", 1);
			player:messageSpecial(ITEM_OBTAINED, 18286);
	end		
	if (job == 9) and (trade:hasItemQty(16680, 1)) and (player:getVar("BSTAFweapon") == 3) then
			player:PrintToPlayer("Netblyx : I can make this into a Guttler...eventually with 10 Montiont Silverpieces", 0xD);		
    end



--------------------------------------------------------
--      BRD TRADE PAPER KNIFE 16766                   --
--------------------------------------------------------




if (job == 10) and (trade:hasItemQty(16766, 1)) and trade:hasItemQty( 1453, 10 ) and (player:getVar("BRDAFweapon") == 3) then
             -- Complete the trade..
            player:tradeComplete();
			player:PrintToPlayer("Netblyx : Here you go.", 0xD);
			player:addItem(18268, 1, 520,6);
			player:setVar("BRDAFweapon", 0);
			player:setVar("BRDRelicweapon", 1);
			player:messageSpecial(ITEM_OBTAINED, 18268);
	end		
	if (job == 10) and (trade:hasItemQty(16766, 1)) and (player:getVar("BRDAFweapon") == 3) then
			player:PrintToPlayer("Netblyx : I can make this into a Mandau...eventually with 10 Montiont Silverpieces", 0xD);		
    end

--------------------------------------------------------
--             BRD TRADE HORN 17352                   --
--------------------------------------------------------

if (job == 10) and (trade:hasItemQty(17352, 1)) and trade:hasItemQty( 1450, 10 ) and (player:getVar("BRDAFweapon") == 3) then
             -- Complete the trade..
            player:tradeComplete();
			player:PrintToPlayer("Netblyx : Here you go.", 0xD);
			player:addItem(18340, 1, 525,6);
			player:setVar("BRDAFweapon", 0);
			player:setVar("BRDRelicweapon", 1);
			player:messageSpecial(ITEM_OBTAINED, 18340);
	end		
	if (job == 10) and (trade:hasItemQty(17352, 1)) and (player:getVar("BRDAFweapon") == 3) then
			player:PrintToPlayer("Netblyx : I can make this into a Gjallahorn...eventually with 10 L.Jadeshells", 0xD);		
    end


--------------------------------------------------------
--      RNG TRADE SNIPING BOW 17188                   --
--------------------------------------------------------



if (job == 11) and (trade:hasItemQty(17188, 1)) and trade:hasItemQty( 1450, 10 ) and (player:getVar("RNGAFweaponbow") == 3) then
             -- Complete the trade..
            player:tradeComplete();
			player:PrintToPlayer("Netblyx : Here you go.", 0xD);
			player:addItem(18346, 1, 519,6);
			player:setVar("RNGAFweaponbow", 0);
			player:setVar("RNGRelicbowweapon", 1);
			player:messageSpecial(ITEM_OBTAINED, 18346);
	end		
	if (job == 11) and (trade:hasItemQty(17188, 1)) and (player:getVar("RNGAFweaponbow") == 3) then
			player:PrintToPlayer("Netblyx : I can make this into a Yoichinoyumi...eventually with 10 L.Jadeshells", 0xD);		
    end


--------------------------------------------------------
--      RNG TRADE SERPENTINE GUN 17256                --
--------------------------------------------------------


if (job == 11) and (trade:hasItemQty(17256, 1)) and trade:hasItemQty( 1453, 10 ) and (player:getVar("RNGAFweapongun") == 3) then
             -- Complete the trade..
            player:tradeComplete();
			player:PrintToPlayer("Netblyx : Here you go.", 0xD);
			player:addItem(18334, 1, 519,6);
			player:setVar("RNGAFweapongun", 0);
			player:setVar("RNGRelicgunweapon", 1);
			player:messageSpecial(ITEM_OBTAINED, 18334);
	end		
	if (job == 11) and (trade:hasItemQty(17256, 1)) and (player:getVar("RNGAFweapongun") == 3) then
			player:PrintToPlayer("Netblyx : I can make this into an Annihilator...eventually with 10 Montiont Silverpieces", 0xD);		
    end

	
--------------------------------------------------------
--         SMN TRADE DRAGON STAFF 17597               --
--------------------------------------------------------

if (job == 12) and (trade:hasItemQty(17597, 1)) and trade:hasItemQty( 1450, 10 ) and (player:getVar("SMNAFweapon") == 3) then
             -- Complete the trade..
            player:tradeComplete();
			player:PrintToPlayer("Netblyx : Here you go.", 0xD);
			player:addItem(18328, 1, 523,6);
			player:setVar("SMNAFweapon", 0);
			player:setVar("SMNRelicweapon", 1);
			player:messageSpecial(ITEM_OBTAINED, 18328);
	end		
	if (job == 12) and (trade:hasItemQty(17597, 1)) and (player:getVar("SMNAFweapon") == 3) then
			player:PrintToPlayer("Netblyx : I can make this into an Claustrum...eventually with 10 L.Jadeshells", 0xD);		
    end

	
	

--------------------------------------------------------
--      NIN TRADE ANJU & ZUSHIO 17771 / 17772         --
--------------------------------------------------------



if (job == 13) and (trade:hasItemQty(17772, 1)) and trade:hasItemQty( 1453, 10 ) and (player:getVar("NINAFweapon") == 3) then
             -- Complete the trade..
            player:tradeComplete();
			player:PrintToPlayer("Netblyx : Here you go.", 0xD);
			player:addItem(18310, 1, 519,6);
			player:setVar("NINAFweapon", 0);
			player:setVar("NINRelicweapon", 1);
			player:messageSpecial(ITEM_OBTAINED, 18310);
	end		
if (job == 13) and ((trade:hasItemQty(17771, 1)) or (trade:hasItemQty(17772, 1))) and (player:getVar("NINAFweapon") == 3) then
			player:PrintToPlayer("Netblyx : Here's the deal, trade me your Zushio and I'll make it a Kikoku eventually with 10 Montiont Silvers", 0xD);		
    end


--------------------------------------------------------
--            DRG TRADE PEREGRINE 16887               --
--------------------------------------------------------



if (job == 14) and (trade:hasItemQty(17478, 1)) and trade:hasItemQty( 1456, 10 ) and (player:getVar("DRGAFweapon") == 3) then
             -- Complete the trade..
            player:tradeComplete();
			player:PrintToPlayer("Netblyx : Here you go.", 0xD);
			player:addItem(18298, 1, 519,6);
			player:setVar("DRGAFweapon", 0);
			player:setVar("DRGRelicweapon", 1);
			player:messageSpecial(ITEM_OBTAINED, 18298);
	end		
	if (job == 14) and (trade:hasItemQty(17478, 1)) and (player:getVar("DRGAFweapon") == 3) then
			player:PrintToPlayer("Netblyx : I can make this into a Gungnir...eventually with 10 One-Hundren Byne Bills", 0xD);		
    end



--------------------------------------------------------
--            SAM TRADE MAGOROKU 17812                --
--------------------------------------------------------



if (job == 15) and (trade:hasItemQty(17812, 1)) and trade:hasItemQty( 1450, 10 ) and (player:getVar("SAMAFweapon") == 3) then
             -- Complete the trade..
            player:tradeComplete();
			player:PrintToPlayer("Netblyx : Here you go.", 0xD);
			player:addItem(18316, 1, 519,6);
			player:setVar("SAMAFweapon", 0);
			player:setVar("SAMRelicweapon", 1);
			player:messageSpecial(ITEM_OBTAINED, 18316);
	end		
	if (job == 15) and (trade:hasItemQty(17812, 1)) and (player:getVar("SAMAFweapon") == 3) then
			player:PrintToPlayer("Netblyx : I can make this into a Amanomurakumo...eventually with 10 L.Jadeshells", 0xD);		
    end





	


end;

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)
local job = player:getMainJob();

	if ((job == 1) and (player:getVar("WARAFweapon") == 3)) or
	((job == 2) and (player:getVar("MNKAFweapon") == 3)) or
	((job == 3) and (player:getVar("WHMAFweapon") == 3)) or
	((job == 4) and (player:getVar("BLMAFweapon") == 3)) or
	((job == 5) and (player:getVar("RDMAFweapon") == 3)) or
	((job == 6) and (player:getVar("THFAFweapon") == 3)) or
	((job == 7) and (player:getVar("PLDAFweapon") == 3)) or
	((job == 7) and (player:getVar("PLDAFshield") == 3)) or
	((job == 8) and (player:getVar("DRKAFweapon") == 3)) or
	((job == 8) and (player:getVar("DRKAFweapongs") == 3)) or
	((job == 9) and (player:getVar("BSTAFweapon") == 3)) or
	((job == 10) and (player:getVar("BRDAFweapon") == 3)) or
	((job == 10) and (player:getVar("BRDAFhorn") == 3)) or
	((job == 10) and (player:getVar("BRDAFharp") == 3)) or
	((job == 11) and (player:getVar("RNGAFweaponbow") == 3)) or
	((job == 11) and (player:getVar("RNGAFweapongun") == 3)) or
	((job == 12) and (player:getVar("SMNAFweapon") == 3)) or
	((job == 13) and (player:getVar("NINAFweapon") == 3)) or
	((job == 14) and (player:getVar("DRGAFweapon") == 3)) or
	((job == 15) and (player:getVar("SAMAFweapon") == 3)) then
	player:PrintToPlayer("Netblyx : You want relic thingy? Trade me your artifact and I tell you a secret", 0xD);
   elseif ((job == 1) and (player:getVar("WARRelicweapon") == 1)) or
	((job == 2) and (player:getVar("MNKRelicweapon") == 1)) or
	((job == 3) and (player:getVar("WHMRelicweapon") == 1)) or
	((job == 4) and (player:getVar("BLMRelicweapon") == 1)) or
	((job == 5) and (player:getVar("RDMRelicweapon") == 1)) or
	((job == 6) and (player:getVar("THFRelicweapon") == 1)) or
	((job == 7) and (player:getVar("PLDRelicweapon") == 1)) or
	((job == 7) and (player:getVar("PLDRelicshield") == 1)) or
	((job == 8) and (player:getVar("DRKRelicweapon") == 1)) or
	((job == 8) and (player:getVar("DRKRelicweapongs") == 1)) or
	((job == 9) and (player:getVar("BSTRelicweapon") == 1)) or
	((job == 10) and (player:getVar("BRDRelicweapon") == 1)) or
	((job == 10) and (player:getVar("BRDRelichorn") == 1)) or
	((job == 11) and (player:getVar("RNGRelicbowweapon") == 1)) or
	((job == 11) and (player:getVar("RNGRelicgunweapon") == 1)) or
	((job == 12) and (player:getVar("SMNRelicweapon") == 1)) or
	((job == 13) and (player:getVar("NINRelicweapon") == 1)) or
	((job == 14) and (player:getVar("DRGRelicweapon") == 1)) or
	((job == 15) and (player:getVar("SAMRelicweapon") == 1)) then
	player:PrintToPlayer("Netblyx : Dyn..Beau..Dyn..Xarc... I've said too much.  Come back later.", 0xD);  
   else
   player:PrintToPlayer("Netblyx : Go away!", 0xD);
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
-- onEventFinish Action
-----------------------------------

function onEventFinish(player,csid,option)
    -- printf("CSID: %u",csid);
    -- printf("RESULT: %u",option);

    
end;