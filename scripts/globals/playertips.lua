---------------------------------------------------------------------------------------------------
-- func: trust
-- desc: displays trust options
---------------------------------------------------------------------------------------------------

cmdprops =
{
    permission = 0,
    parameters = "s"
};



function onTrigger(player)
    local tip = math.random(1,15);
 
    if (tip == 1) then
        player:PrintToPlayer("(Player Tip#001) On Monk, Boost doesn't wear off when striking an enemy and can be stored up to three times at Level 75.", 0xD); 
    elseif (tip == 2) then	
        player:PrintToPlayer("(Player Tip#002) Last Resort's defense penalty is 0 when a DRK has full MP, and -25% when DRK has no MP", 0xD); 	
    elseif (tip == 3) then	
        player:PrintToPlayer("(Player Tip#003) Last Resort provides a Parry Bonus when DRK is the main job.", 0xD); 
    elseif (tip == 4) then	
        player:PrintToPlayer("(Player Tip#004) The spell 'Stun' has an enmity Bonus when used by a Dark Knight.", 0xD);
	elseif (tip == 5) then	
        player:PrintToPlayer("(Player Tip#005) Unlimited Shot on RNG provides lightning quick shooting, but sacrafices power and accuracy.", 0xD); 
 	elseif (tip == 6) then	
        player:PrintToPlayer("(Player Tip#006) The retail buff Avatar's Favor is enabled by default when summoning and has no penalty.  The Job ability", 0xD);   
        player:PrintToPlayer("Avatar's Favor will increase an avatars attack power at the cost of avatar perpetuation", 0xD); 		
  	elseif (tip == 7) then	
        player:PrintToPlayer("(Player Tip#007) Wyvern Breaths on DRG also provide an elemental debuff to the mob.", 0xD); 
  	elseif (tip == 8) then	
        player:PrintToPlayer("(Player Tip#008) Bard has the ability to equip a bow.  Threnodies on a mob cause arrows to do elemental damage", 0xD);  	
  	elseif (tip == 9) then	
        player:PrintToPlayer("(Player Tip#009) When in use, Paladin's Sentinel will also convert damage to MP", 0xD);
  	elseif (tip == 10) then	
        player:PrintToPlayer("(Player Tip#010) Divine Seal will not wear off after casting a spell.  Cure Potency will decrease over time", 0xD);  
  	elseif (tip == 11) then	
        player:PrintToPlayer("(Player Tip#011) Elemental Seal will not wear off after casting a spell.  Damage and accuracy bonuses decrease over time.", 0xD); 
  	elseif (tip == 12) then	
        player:PrintToPlayer("(Player Tip#012) In addition to stealing an item, THF's 'Steal' ability can take some of the mobs TP", 0xD); 
  	elseif (tip == 13) then	
        player:PrintToPlayer("(Player Tip#013) Ninja's Innin also provides a Magic Attack Bonus for elemental ninjitsu nukes.", 0xD);  
  	elseif (tip == 14) then	
        player:PrintToPlayer("(Player Tip#014) On this server, Ninja has Fast Cast and Magic Attack Bonus Traits", 0xD);  	
  	elseif (tip == 15) then	
        player:PrintToPlayer("(Player Tip#015) On this server, White Mage, Red Mage, Black Mage, Paladain, and Dark Knight all receive Auto-Refresh Traits", 0xD);  

    end		
end;