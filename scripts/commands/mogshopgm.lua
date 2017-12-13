--------------------------------------------------------------
-- func: @mogshop <page number>
-- auth: forgottenandlost
-- desc: opens the custom moogle shop menu anywhere in the world
--------------------------------------------------------------

cmdprops =
{
    permission = 0,
    parameters = "i"
};

function onTrigger(player,page)
    if (page == 0 or page == nil) then
        player:PrintToPlayer( "1: Crystal Depot, 2: Pharmacy, 3: Food, 4: Tools & Ammo, 5: Weaponry, 6: Armory, 7: Beyond Infinity, 8: Misc ");
        
    elseif (page == 1) then -- HQ Crystals
        local stock_1 =
        {
            4238,   5000,   -- HQ Fire Crystal
            4239,   5000,   -- HQ Ice Crystal
            4240,   5000,   -- HQ Wind Crystal
            4241,   5000,   -- HQ Earth Crystal
            4242,   5000,   -- HQ Lightning Crystal
            4243,   5000,   -- HQ Water Crystal
            4244,   5000,   -- HQ Light Crystal
            4245,   5000    -- HQ Dark Crystal
        };
        showShop(player, STATIC, stock_1);
        player:PrintToPlayer( "Crystal Depot: Welcome, Kupo!");
    elseif (page == 2) then -- Pharmacy
        local stock_2 =
        {
            4148,   1000,     -- Antidote
            4154,   1500,    -- Holy Water
            4150,   1000,    -- Eye Drops
            4151,   1000,    -- Echo Drops
            4153,   2500,    -- Bottle of Antacid
            5418,   1500,    -- Tincture
            5328,   2500,    -- Hi-Potion Drop
            5358,   2500,    -- Hi-Ether Drop
            5356,   2500,    -- Remedy Ointment
            4202,   25000   -- Daedalus Wing

        };
        showShop(player, STATIC, stock_2);
        player:PrintToPlayer( "Pharmacy: Welcome, Kupo!");
    elseif (page == 3) then -- MogDonalds
        local stock_3 =
        {
            4271,   1500,   -- Rice Dumpling
            4381,   2100,   -- Meat Mithkabob
            4398,   2100,   -- Fish Mithkabob
            4457,   5500,   -- Eel Kabob
            5166,   2100,   -- Coeurl Sub Sandwich
            4355,   4000,   -- Salmon Sub Sandwich
            5686,   799,    -- Cheese Sandwich
			5743,   6000,    -- Pizza
            5561,   799,    -- Moogle Pie
            4270,   999,    -- Sweet Rice Cake
            5944,   2000,   -- Frontier Soda
            5932,   1600,   -- Kitron Juice
            4424,   1100,   -- Melon Juice
            4422,   700     -- Orange Juice
        };
        showShop(player, STATIC, stock_3);
        player:PrintToPlayer( "Food: Welcome, Kupo!");
    elseif (page == 4) then
        local stock_4 =
        {
            605,    1000,     -- Pickaxe
            1021,   1000,     -- Hatchet
            1020,   1000,     -- Sickle
            4165,   2300,    -- Silent Oil
            4164,   1300,    -- Prism Powder
            5362,   1300,    -- Rainbow Powder
            5319,   9200,    -- Toolbag (Shinobi-Tabi)
            5314,   11000,    -- Toolbag (Shihei)
            1022,   5200,     -- Thief's Tools
			4219,   1100,     -- Stone Quiver 
			4225,   2100,     -- Iron Quiver
			4226,   3100,     -- Silver Quiver
			5335,   1000,     -- Acid Bolt QUiver
			5337,   11000,     -- Sleep Bolt Quiver
			5339,   6100,     -- Bloody Bolt Quiver
		   19229,   10,       -- Tin Bullet	
		    5363,   3200,     -- Bullet Pouch
        };
        showShop(player, STATIC, stock_4);
        player:PrintToPlayer( "Tools & Ammo Shop: Welcome, Kupo!");
		elseif (page == 5) then
		player:PrintToPlayer( "Weaponry: Welcome, Kupo! 51: One-Handed Weapons, 52: Two-Handed Weapons, 53: Ranged Weapons");
		elseif (page == 51) then
        local stock_5a =
        {
            16391,		3000,	 -- Brass Knuckles
			16386,		5100,	  -- Lizard Cesti
		    16409,		5100,	  -- Lynx Baghnakhs
		    17514,	    10000,	  -- Hydro Claws
		    16393,		10000,	  -- Mythril Knuckles
		    16466,		900,	  -- Knife
		    16473,		5600,	  -- Kukri
			16479,		7200,	  -- Acid Kukri
			16572,		500,	  -- Bee Spatha
			16517,		4700,	  -- Degen
			16532,		7800,	  -- Gladius
			16648,		2200,	  -- Legionnaires Axe
			16649,		4200,	  -- Bone Pick
			17940,		6000,	  -- Military Pick
			16644,		7500,	  -- Mythril Axe
			17780,		1000,	  -- Kyofu
			16917,		2300,	  -- Suzume
			17775,		5500,	  -- Fukuro
			19276,		7000,	  -- Midare
			17025,		1500,	  -- Chestnut Club
			17441,		6800	  -- Eremite's Wand
        };
        showShop(player, STATIC, stock_5a);
        player:PrintToPlayer( "One-Handed Weapons: Welcome, Kupo!");	
		elseif (page == 52) then
        local stock_5b =
        {
            16705,		1200,	  -- Greataxe
			18209,		3500,	  -- Platoon Cutter
			16712,		7100,	  -- Centurion's Axe
			16708,		8000,	  -- Horror Voulge
			18956,		1300,	  -- Serpett
			16770,		3500,	  -- Zaghnal
			16776,		7800,	  -- Mrc Cpt Scythe
			16834,		1200,	  -- Brass Speak
			16852,		4000,	  -- Royal spr spear
			16844,		8000,	  -- Ryal Halberd
			16960,		1200,	  -- Ughigatana
			17820,		3500,	  -- Gunromaru
			16988,		6200,	  -- Kotetsu
			16970,		8300,	  -- Hosodachi
			17089,		1300,	  -- Holy Staff
			17096,		2600,	  -- Holly Pole
			17090,		5900,	  -- Elm Staff
			17580,		8100,	  -- Military Pole
			16606,      1200,     -- Rusty GS
			16583,      2900,     -- Claymore
			16930,      4000,     -- Merc Captain GS
			16584,      7800     -- Mythril GS
			
        };
        showShop(player, STATIC, stock_5b);
        player:PrintToPlayer( "Two-Handed Weapons: Welcome, Kupo!");
		elseif (page == 53) then
        local stock_5c =
        {
            17153,		1200,	  -- Self Bow
			17161,		3500,	  -- Power Bow
			17155,		7100,	  -- Composite Bow
			17257,		1900,	  -- Bandits Gun
			17248,		4900,	  -- Arquebus
			17272,		7300,	  -- Military Gun
			17217,      1300,     -- Cross Bow
			17230,      3600,     -- Power Crossbow
			17247,      7100,     -- Rikonodo
        };
        showShop(player, STATIC, stock_5c);
        player:PrintToPlayer( "Ranged Weapons: Welcome, Kupo!");
	elseif (page == 6) then
	player:PrintToPlayer( "Armory: Welcome, Kupo! 61: Head, 62: Body, 63: Hands, 64, Legs, 65: Feet, 66: Accessories");
	elseif (page == 61) then
        local stock_6a =	
		{	
			12497,	250,	  -- Brass Hairpin		 
			12530,	900,  -- Sage's Circlet		30F2	
			12498,	400,	 -- Cotton Headband		30D2	
			13833,	400,	  -- Noble's Ribbon		3609	
			15208,	1200, -- Baron's Chap		3B68	
			13827,	1900,  -- Beetle Mask +1		3603	
			15166,	4200, -- Seer's Crown +1		3B3E	
			13824,	1200,  -- Strong Bandana		3600			
			12533,	2200,  -- Silver Mask +1		30F5	
			15170,	8000,  -- Blink Band		    3B42	
			13831,	3200, -- Sallet +1		    3607
			15166,  4200,     -- Seer's Crown +1
			12480,  2000,     -- Lizard Mask +1
			12432,   250,     -- Facegard	
			13840,  5100,     -- Electrum Hairpin
			13829,  5000,    -- Caprice Mask +1
        };			
		showShop(player, STATIC, stock_6a);
        player:PrintToPlayer( "Armory Head: Welcome, Kupo!");
		elseif (page == 62) then
	    local stock_6b =
        {
            12608,  1000,     -- Tunic
			13729,  1200,     -- Priest's Robe 
		    12602,  1500,     -- Wool Robe
			14424,  2400,     -- Seer's Tunic
			12568,   300,     -- Leather Vest   
			12616,   2500,    -- Tunic +1 
			14490,   2500,    -- Mana Tunic
			12661,   1000,    -- Solid Mail
			12591,   1000,    -- Doublet +1
			14495,   1500,    -- Healing Harness
			13697,   1800,    -- Fine Jerkin
			14447,   2500,    -- Baron 
			13717,   3200,    -- Beetle Harness
			12567,   4000,    -- Steam Scale Mail
			13731,   4000,    -- Faerie Tunic
			13707,   5200,    -- Strong Vest 
			11339,   6300,    -- Channeling Robe   
			12663,   7000,    -- Strong Harness 
			13709,   8000,    -- Cuir Bouilli +1
			13724,   9000,    -- Breastplate +1 
			11348,   10000,   -- Salutary Robe +1
			13714,   11000,   -- Carapace Harness +1
			13727,   12500,   -- Dino Jerkin
			13737,   15000,   -- Mithril Breaste+1
			12651,   35000,   -- White Cloak +1
            12579,   40000    -- Scorpion Harness			
        };
        showShop(player, STATIC, stock_6b);
		player:PrintToPlayer( "Armory Body: Welcome, Kupo!");
		elseif (page == 63) then
	    local stock_6c =
        {
			12696,	100,  -- Leather Gloves		
			12736,	100,	 -- Mitts			    
			12778,	250,	 -- Linen Cuffs +1		
			12785,	350,  -- Fine Gloves		    
			12789,	1550,	 -- Beetle Mittens +1	
			14863,	800,  -- Kampfhentzes		
			12726,	1500,  -- Gigas Bracelets		
			12793,	2000,  -- Mage's Cuffs		
			12791,	2250,  -- Gauntlets + 1		    
			14052,	2750,  -- Luisant Moufles		
			12795,	3100,  -- Dino Gloves		    
			13958,	4000,  -- Mythril Gauntts +1	
			12794,	4000,  -- Mage's Mitts	
            12790,  4000,   -- Caprice Mitts			
        };
        showShop(player, STATIC, stock_6c);
        player:PrintToPlayer( "Armory Hands: Welcome, Kupo!");
		elseif (page == 64) then
	    local stock_6d =
        {
			12824,		125,  -- Leather Trousers	
			12898,		900,  -- Slacks +1		    
			12912,		1250,  -- Bone Subligar +1	
			15405,		900,  -- Baron's Slops		
			12808,		1200, -- Chain Hose +1		
			14328,		2250, -- Seer's Slacks +1	
			14332,		2250, -- Kampfdiechlings		
			12910,		2500, -- Strong Trousers		
			12891,		3200, -- Iron Subligar +1	
			12918,		3800, -- Mage's Slops		
			12919,		4800, -- Dino Trousers		
			14211,		6400, -- Mythril Cuisses +1	
			12926,		7000,  -- White Slacks +1
			12870,      5000,  -- Combat Cast Slacks
        };
        showShop(player, STATIC, stock_6d);
        player:PrintToPlayer( "Armory Legs: Welcome, Kupo!");
		elseif (page == 65) then
	    local stock_6e =
        {
			12952,	70,  -- Leather Highboots	
			13027,	1250,  -- Brass Leggins +1	
			12991,	250, -- Holly Clogs +1		
			13052,	900,  -- Light Soleas			
			13042,	500,  -- Bone Leggings +1	
			13048,	800,  -- Mage's Sandles		
			14133,	3200,  -- Winged Boots +1		
			15321,	1600,  -- Kampfschuhs		    
			13041,	2400,  -- Cuir Highboots +1	
			13023,	2400,  -- Ebony Sabots +1		
			13715,	3200,  -- Carapace Legs +1	
			14086,	3800,  -- Mythril Legs +1		
			12995,	4000  -- Mocassins +1	
        };
        showShop(player, STATIC, stock_6e);
        player:PrintToPlayer( "Armory Feet: Welcome, Kupo!");
		elseif (page == 66) then
        local stock_6f =
		{
			13457,  4500,   -- Beetle Ring
			13476,  4500,    -- Peridot
			13477,  4500,    -- Garnet
			13478,  4500,    -- Goshenite
			13479,  4500,    -- Ametrine Ring
			13480,  4500,    -- Turqoise
			13481,  4500,    -- Sphene Ring
			13482,  4500,    -- Black Ring
			13483,  4500,    -- Pearl Ring
			13076,  2300,    -- Fang Necklace
			13073,  2100,    -- Holy Phial
			13584,  2450,    -- Cotton Cape
			13588,  2300,    -- DHamel Mantle
			13614,  2300,    -- Bronze Cape
			13577,  2100,    -- Black Cape		
			13323,  4700,    -- Beetle Earring
			13366,  4700,    -- Dodge Earring
			13320,  4700,    -- Black Earring
			13211,  4100,    -- Friars Rope
			13225,  4600    -- Brave Belt	
		
		};
		showShop(player, STATIC, stock_6f);
        player:PrintToPlayer( "Armory Accessories: Welcome, Kupo!");
	    elseif (page == 7) then -- Beyond infinity
        local plevel = player:getMainLvl();
           if (plevel > 98) then
            local stock_7=
            {
                10902,  5000,     -- Euxine Hat
				10475,  5000,     -- Euxine Coat
				10524,  5000,     -- Euxine Gloves
				10555,  5000,     -- Euxine Kecks
				10621,  5000,     -- Euxine Nails
            };
            showShop(player, STATIC, stock_7);
            player:PrintToPlayer( "Beyond Infinity: Welcome, Kupo!");
        else
            player:PrintToPlayer( "You must be Level 99 to unlock this, Kupo!");
        end
	
	
		elseif (page == 8) then
	    local stock_8 =
        {
            1839,    200,     -- Tactics Manual of Might
            1820,    200,     -- Tactics Manual of Fortitude
			1876,    200,     -- Tactics Manual of Endurance
			1042,    25000,   -- Davoi Coffer Key
			1043,    25000,     -- Bdx
			1044,    25000,     -- Ozt
			1045,    25000,     -- Nest
			1046,    25000,      -- Eld
			1047,    25000,       -- Grl
			1048,    25000,       -- Zvahl
			1049,    25000,       -- Ugl
			1050,    25000,       -- Den
			1051,    25000,       -- Kuftal
			1052,    25000,       -- Byd
			1053,    25000,       -- Cld
			1054,    25000,       -- QSC
			1057,    25000,       -- Tor
			1059,    25000,       -- Groto
			17583,   7000, 
			17584,   7000,   
			17585,   7000
			
			
        };
        showShop(player, STATIC, stock_8);
        player:PrintToPlayer( "Misc. Items: Welcome, Kupo!");
		
		
		
		
       else
        -- local Mog = 16982044;
        -- message = "Test!";
        -- SpoofSay(Mog,player:getID(),message);
        player:PrintToPlayer( string.format( "The MogShop catalog doesn't have a page %i, Kupo!", page ) );
    end
end;