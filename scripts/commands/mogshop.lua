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
local level = player:getMainLvl();
local aura = player:getVar("FerretoryAura");

-- printf("%s just triggered Mogshop", player:getName());

    if (page == 0 or page == nil) then
        player:PrintToPlayer( "Merchant Moogle : 1: Crystals, 2: Meds, 3: Food, 4: Tools/Ammo, 5: Weapons, 6: Armor, 7: Beyond Infinity, 8: Misc, 9: Attachments", 0x1F);
        
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
        player:PrintToPlayer( "Merchant Moogle : Welcome to Crystal Depot Kupo!", 0x1F);
    elseif (page == 2) then -- Pharmacy
        local stock_2 =
        {
            4148,   400,     -- Antidote
            4154,   4000,    -- Holy Water
            4150,   600,    -- Eye Drops
            4151,   1200,    -- Echo Drops
            4153,   35000,    -- Bottle of Antacid
            5418,   1500,    -- Tincture
            5328,   3000,    -- Hi-Potion Drop
            5358,   3000,    -- Hi-Ether Drop
            5356,   3500,    -- Remedy Ointment
            4202,   25000   -- Daedalus Wing

        };
        showShop(player, STATIC, stock_2);
        player:PrintToPlayer( "Merchant Moogle : Medicines for you, Kupo!", 0x1F);
    elseif (page == 3) then -- MogDonalds
        local stock_3 =
        {
			-- attack foods
			4381,	650,   -- Meat mithkabob *
			5142,	12000,  -- bison Steak 
			5146,	4500,  -- Hedgehog Pie 
			5759,	6500,   -- red curry bun 
			5166,   2100,  -- Coeurl Sub Sandwich
			-- acc food
			5721,	600,   -- Crab Sushi  
			5176,	1100,   -- Bream Sushi 
			5148,	2500,   -- Squid Sushi 
			5149,	5500,   -- Sole Sushi 
			-- hybrid foods
			5743,   11000,  -- Pizza
			5685,   11000,  -- Rabbit Pie
			-- tank foods
			4488,	3100,  -- Jack-o'-Lantern
			5178,	6300,   -- Dorado Sushi
			5191,	22050,   -- Pescatora
			5174,	5500,   -- Tavnazian Taco 
			-- mage food
			4421,	1200,   -- Melon Pie  
			4414,	4000,   -- Rolanberry Pie *
			5718,	3000,   -- Cream Puff
			4502,	4200,  -- Marron Glace
			-- Juice
			5932,   1200,   -- Kitron Juice
			4424,   700,   -- Melon Juice
			4422,   600,    -- Orange Juice
			4558,	2200    -- Yagudo Drink
        };
        showShop(player, STATIC, stock_3);
        player:PrintToPlayer( "Merchant Moogle : Fresh food for your adventures, Kupo!", 0x1F);
    elseif (page == 4) then
        local stock_4 =
        {
            605,    1100,     -- Pickaxe
            1021,   1100,     -- Hatchet
            1020,   1100,     -- Sickle
            4165,   2300,    -- Silent Oil
            4164,   1300,    -- Prism Powder
            5362,   1300,    -- Rainbow Powder
            5319,   11000,    -- Toolbag (Shinobi-Tabi)
            5314,   12000,    -- Toolbag (Shihei)
            1022,   5200,     -- Thief's Tools
			4219,   1100,     -- Stone Quiver *
			4225,   1100,     -- Iron Quiver  *
			4226,   3500,     -- Silver Quiver*
			5335,   4000,     -- Acid Bolt QUiver
			5337,   5000,     -- Sleep Bolt Quiver
			5339,   5000,     -- Bloody Bolt Quiver
		   19229,   110,       -- Tin Bullet	
		    5363,   3200,     -- Bullet Pouch
        };
        showShop(player, STATIC, stock_4);
        player:PrintToPlayer( "Merchant Moogle : Tools and ammo just for you, Kupo!", 0x1F);
		elseif (page == 5) then
        player:PrintToPlayer( "Merchant Moogle : Choose your type 51: One-Handed Weapons, 52: Two-Handed Weapons, 53: Ranged Weapons", 0x1F);		
		elseif (page == 51) and (level < 50) then
        local stock_5a =
        {
            16391,		3100,	 -- Brass Knuckles
			16386,		5100,	  -- Lizard Cesti
		    16409,		5100,	  -- Lynx Baghnakhs
		    17514,	    11000,	  -- Hydro Claws
		    16393,		10000,	  -- Mythril Knuckles
		    16466,		3200,	  -- Knife
		    16473,		3500,	  -- Kukri
			16479,		22350,	  -- Acid Kukri
			16572,		5500,	  -- Bee Spatha
			16517,		4700,	  -- Degen
			16532,		22000,	  -- Gladius
			16648,		5200,	  -- Legionnaires Axe
			16649,		2200,	  -- Bone Pick
			17940,		52000,	  -- Military Pick
			16644,		15500,	  -- Mythril Axe
			17780,		6000,	  -- Kyofu
			16917,		5300,	  -- Suzume
			17775,		12500,	  -- Fukuro
			19276,		12000,	  -- Midare
			17025,		2500,	  -- Chestnut Club
			17441,		11800	  -- Eremite's Wand
        };
        showShop(player, STATIC, stock_5a);
        player:PrintToPlayer( "Merchant Moogle : One-Handed Weapons!", 0x1F);
        elseif (page == 51) and (level >= 50) then
        local stock_5m =
        {
			16394,		21000,    -- Darksteel Knuckles
			18743,		52000,    -- Darksteel Santi
			18748,	   100000,    -- Hades Sainti
			16468,		70000,    -- Darksteel knife
			16477,		21000,    -- Cement Kukuri
			17628,		28000,    -- Behemoth Knife
			18023,	   310200,    -- Jambiya
			16538,      16000,     -- Darksteel Sword
			16560,	    53000,     -- Cutlass
			17720,      11000,     -- Company Flurret
			16547,     110600,     -- Anelace			
			16645,      16000,     -- Darksteel Axe
			16652,      52000,     -- Darksteel Pick
			16659,     210000,     -- Tabarzin
			16913,      22520,     -- Shinogi
			16903,      42000,     -- Kabutowari
			16904,      32000,     -- Fudo
			17037,      53500,     -- Darksteel Mace
			17046,      53600,     -- Darksteel Maul
			18848,      11200     -- Brass Jadagna
        };
        showShop(player, STATIC, stock_5m);
        player:PrintToPlayer( "Merchant Moogle : One-Handed Weapons!", 0x1F);		
		elseif (page == 52) and (level < 50) then
        local stock_5b =
        {
            16705,		11000,	  -- Greataxe
			18209,		5500,	  -- Platoon Cutter
			16712,		11100,	  -- Centurion's Axe
			16708,		16000,	  -- Horror Voulge
			18956,		12000,	  -- Serpett
			16770,		4500,	  -- Zaghnal
			16776,		22000,	  -- Mrc Cpt Scythe
			16834,		5200,	  -- Brass Speak
			16852,		4200,	  -- Royal spr spear
			16844,		12000,	  -- Ryal Halberd
			16960,		5200,	  -- Ughigatana
			17820,		23500,	  -- Gunromaru
			16988,		22200,	  -- Kotetsu
			16970,		22300,	  -- Hosodachi
			17089,		3300,	  -- Holly Staff
			17096,		2600,	  -- Holly Pole
			17090,		12900,	  -- Elm Staff
			17580,		22100,	  -- Military Pole
			16606,      22200,     -- Rusty GS
			16583,      11400,     -- Claymore
			16930,      22600,     -- Merc Captain GS
			16584,      12800     -- Mythril GS
			
        };
        showShop(player, STATIC, stock_5b);
        player:PrintToPlayer( "Merchant Moogle : Two-Handed Weapons!", 0x1F);
		elseif (page == 52) and (level >= 50) then
        local stock_5n =
        {
			17545,		12000,   -- Fire Staff
			17547,		12000,   -- Ice Staff
			17549,		22000,   -- Wind Staff
			17551,		32000,   -- Earth Staff
			17553,		12000,   -- Thunder Staff
			17555,		17000,   -- Water Staff
			17557,		12000,   -- Light Staff
			17559,		17000,   -- Dark Staff
			16585, 		52300,	-- Darksteel Claymore
			16596,		43000,	-- Flamberge
			-- 16592,		12000,	-- Giant Sword
			18226,		375000,	-- Darksteel Voulge
			16730,		32500,	-- Colossal Axe
			16707,		43000,	-- Bhuj
			16848,		21000,	-- Darksteel Lance
			16849,		12000,	-- Cement Lance
			16855,		32000,	-- Colossal Lance
			16984,		62000,	-- Jindachi
			16972,		82500,	-- Kazaridachi
			18439,		92000	-- Shirogotana
		
		
		
			
        };
        showShop(player, STATIC, stock_5n);
        player:PrintToPlayer( "Merchant Moogle : Two-Handed Weapons!", 0x1F);			
		elseif (page == 53) and (level < 50) then
        local stock_5c =
        {
            17153,		2200,	  -- Self Bow
			17161,		27500,	  -- Power Bow
			17155,		12100,	  -- Composite Bow
			17257,		22900,	  -- Bandits Gun
			17248,		52000,	  -- Arquebus
			17272,		42300,	  -- Military Gun
			17217,      2300,     -- Cross Bow
			17230,      12600,     -- Power Crossbow
			17247,      32000     -- Rikonodo
        };
        showShop(player, STATIC, stock_5c);
        player:PrintToPlayer( "Merchant Moogle : Ranged Weapons!", 0x1F);
		elseif (page == 53) and (level >= 50) then
        local stock_5o =
        {
			19226,		32000,	   -- Blunderbuss
			17157,      22000,     -- Rapid Bow
			17251,		62000,	   -- Hellfire
			17200,      22500      -- Rosenbogen	
        };
        showShop(player, STATIC, stock_5o);
        player:PrintToPlayer("Merchant Moogle : Ranged Weapons!", 0x1F);		
	elseif (page == 6) then
	player:PrintToPlayer( "Merchant Moogle : Welcome, Kupo! 61: Head, 62: Body, 63: Hands, 64, Legs, 65: Feet, 66: Accessories", 0x1F);
	elseif (page == 61) and (level < 50) then
        local stock_6a =	
		{	
			12497,	4250,	  -- Brass Hairpin		 
			12530,	15300,  -- Sage's Circlet		30F2	
			12498,	2400,	 -- Cotton Headband		30D2	
			13833,	5200,	  -- Noble's Ribbon		3609	
			15208,	22200, -- Baron's Chap		3B68	
			13827,	12000,  -- Beetle Mask +1		3603	
			15166,  42200,     -- Seer's Crown +1
			13824,	8200,  -- Strong Bandana		3600			
			12533,	22200,  -- Silver Mask +1		30F5	
			15170,	102000,  -- Blink Band		    3B42	
			13831,	13200, -- Sallet +1		    3607
			12480,  12000,     -- Lizard Mask +1
			12432,   1250,     -- Facegard	
			13840,  12100,     -- Electrum Hairpin
			13829,  11000    -- Caprice Mask +1
        };			
		showShop(player, STATIC, stock_6a);
        player:PrintToPlayer( "Armory Head: I have some HQ items, Kupo!");
	elseif (page == 61) and (level >=50) then    -- Shop for Level 50 and Above Head Pieces
        local stock_6r =	
		{	
			13939,	52000,  -- Austers Hat
			13698,	12000,  -- Beak Helm
			16063,  41500,  -- Jeridah Hat
			16061,	52000,  -- Sipahi Turban
			13881,  11000,  -- Arhat Jinpachi
			12477,  13000,  -- Nobles Crown
			12428,  27000   -- Caleta
        };			
		showShop(player, STATIC, stock_6r);
        player:PrintToPlayer("Merchant Moogle : Head Armor Kupo!", 0x1F);		
		elseif (page == 62) and (level < 50) then
	    local stock_6b =
        {
            12608,  1200,     -- Tunic
			13729,  12200,     -- Priest's Robe 
		    12602,  2500,     -- Wool Robe
			14427,  52000,     -- Seer's Tunic +1
			12568,   2300,     -- Leather Vest   
			12616,   12500,    -- Tunic +1 
			14490,   12500,    -- Mana Tunic
			12661,   21000,    -- Solid Mail
			12591,   22000,    -- Doublet +1
			14495,   23500,    -- Healing Harness
			13697,   12800,    -- Fine Jerkin
			14447,   52500,    -- Baron 
			13717,   3200,    -- Beetle Harness
			12567,   11000,    -- Steam Scale Mail
			13731,   11300,    -- Faerie Tunic
			13707,   12500,    -- Strong Vest 
			11339,   6300,    -- Channeling Robe   
			12663,   42000,    -- Strong Harness 
			13709,   12000,    -- Cuir Bouilli +1
			13724,   52000,    -- Breastplate +1 
			11348,   86000,   -- Salutary Robe +1
			13714,   16000,   -- Carapace Harness +1
			13727,   32500,   -- Dino Jerkin
			13737,   15000,   -- Mithril Breaste+1
			12651,   46000,   -- White Cloak +1
	        12554,   9000    -- Banded Mail 		
		
        };
        showShop(player, STATIC, stock_6b);
        player:PrintToPlayer("Merchant Moogle : Body Armor Kupo!", 0x1F);	
		elseif (page == 62) and (level >= 50) then
	    local stock_6s =
        {
			13814,  51500,  -- Austers
			12579,  42000,  -- Scorpion Harness	
			13748,	310000,  -- Vermillion Cloak
			14526,	52000,  -- Jeridah Peti
			14524,  95000,  -- Sipahi
			13744,	42000,  -- Justaucorps
			13740,  51000,  -- Byrnie
			13754,	42000,  -- Black Cotehardie 
			13795,	52000,  -- Arhat
			12605,	67000,  -- Nobles Tunic
			13779,	22000,  -- Black Cloak
			14436,	12000   -- Blessed Briault		
        };
        showShop(player, STATIC, stock_6s);
        player:PrintToPlayer("Merchant Moogle : Body Armor Kupo!", 0x1F);	
		elseif (page == 63) and (level < 50) then
	    local stock_6c =
        {
			12696,	1200,   -- Leather Gloves		
			12736,	1200,   -- Mitts			    
			12778,	21650,   -- Linen Cuffs +1		
			12785,	3350,   -- Fine Gloves		    
			12789,	16550,  -- Beetle Mittens +1	
			14863,	32000,  -- Kampfhentzes		
			12726,	6800,  -- Merc Capt gloves		
			12793,	12000,  -- Mage's Cuffs	
			12791,	12050,  -- Gauntlets + 1		    
			14052,	62750,  -- Luisant Moufles		
			12795,	12600,  -- Dino Gloves		    
			13958,	42000,  -- Mythril Gauntts +1	
			12794,	12000,  -- Mage's Mitts	
            12790,  8000   -- Caprice Mitts			
        };
        showShop(player, STATIC, stock_6c);
        showShop(player, STATIC, stock_6s);
        player:PrintToPlayer("Merchant Moogle : Hand Armor Kupo!", 0x1F);
		elseif (page == 63) and (level >=50) then
	    local stock_6t =
        {
			14826,	52000,   -- Austers Cuffs
			14934,  52100,  -- Jeridah
			14932,  21200,  -- Sipahi
			14023,  22000,  -- Arhats Tekko
			12724,  19000,  -- Battle Bracers	
			12733,  22000,  -- Nobles Mitts
			14875,  32000,  -- Blessed Mitts
        };
        showShop(player, STATIC, stock_6t);
        showShop(player, STATIC, stock_6s);
        player:PrintToPlayer("Merchant Moogle : Hand Armor Kupo!", 0x1F);	
		elseif (page == 64) and (level < 50) then
	    local stock_6d =
        {
			12824,		1225,  -- Leather Trousers	
			12898,		16000,  -- Slacks +1		    
			12912,		16050,  -- Bone Subligar +1	
			15405,		52000,  -- Baron's Slops		
			12808,		8200, -- Chain Hose +1		
			14328,		42250, -- Seer's Slacks +1	
			14332,		32250, -- Kampfdiechlings		
			12910,		12500, -- Strong Trousers		
			12891,		12200, -- Iron Subligar +1	
			12918,		12800, -- Mage's Slops		
			12919,		13800, -- Dino Trousers		
			14211,		12400, -- Mythril Cuisses +1	
			12926,		32000,  -- White Slacks +1
			12870,      22000,  -- Combat Cast Slacks
        };
        showShop(player, STATIC, stock_6d);
        player:PrintToPlayer("Merchant Moogle : Leg Armor Kupo!", 0x1F);
		elseif (page == 64) and (level >= 50) then
	    local stock_6u =
        {
			14310,		52000,  -- Austers Slops
			15605,      32200,  -- Jeridah
			15603,      52000,  -- Sipahi
			12829,		13500,  -- Beak Trousers
			12852,      105000,  -- Battle Hose
			14253,      32500,  -- Arhat
			12861,      42000,  -- Nobles Slacks
			15391,      22000  -- Blessed			
        };
        showShop(player, STATIC, stock_6u);
        player:PrintToPlayer("Merchant Moogle : Leg Armor Kupo!", 0x1F);		
		elseif (page == 65) and (level < 50) then
	    local stock_6e =
        {
			12952,	1100,  -- Leather Highboots	
			13027,	7250,  -- Brass Leggins +1	
			12991,	6650, -- Holly Clogs +1		
			13052,	12000,  -- Light Soleas			
			13042,	21000,  -- Bone Leggings +1	
			13048,	32000,  -- Mage's Sandles		
			14133,	210000,  -- Winged Boots +1		
			15321,	32600,  -- Kampfschuhs		    
			13041,	12000,  -- Cuir Highboots +1	
			13023,	7400,  -- Ebony Sabots +1		
			13715,	9200,  -- Carapace Legs +1	
			14086,	42800,  -- Mythril Legs +1		
			12995,	62000  -- Mocassins +1	
        };
        showShop(player, STATIC, stock_6e);
        player:PrintToPlayer("Merchant Moogle : Feet Armor Kupo!", 0x1F);
		elseif (page == 65) and (level >= 50) then
	    local stock_6v =
        {
			14189,	52000,  -- Austers
			13702,  12500,  -- Beak
			15689,  52950,  -- Jeridah
			15687,  9000,  -- Sipahi
			12980,  33000,  -- Battle Boots
			14129,  12100, -- Arhat
			12989,  32500, -- Nobles Pumps
			15329,  22530  -- Blessed	
        };
        showShop(player, STATIC, stock_6v);
        player:PrintToPlayer("Merchant Moogle : Feet Armor Kupo!", 0x1F);			
		elseif (page == 66) and (level < 50) then
        local stock_6f =
		{
			13457,  5500,   -- Beetle Ring
			13476,  5500,    -- Peridot
			13477,  12000,    -- Garnet
			13478,  12400,    -- Goshenite
			13479,  5500,    -- Ametrine Ring
			13480,  4500,    -- Turqoise
			13481,  4500,    -- Sphene Ring
			13482,  6500,    -- Black Ring
			13483,  5500,    -- Pearl Ring
			13076,  2300,    -- Fang Necklace
			13073,  12100,    -- Holy Phial
			13584,  2450,    -- Cotton Cape
			13588,  2300,    -- DHamel Mantle
			-- 13614,  2300,    -- Bronze Cape
			13577,  6100,    -- Black Cape		
			13323,  4700,    -- Beetle Earring
			13366,  31000,    -- Dodge Earring
			13320,  6700,    -- Black Earring
			13211,  9100,    -- Friars Rope
			13225,  22600     -- Brave Belt		
		};
		showShop(player, STATIC, stock_6f);
        player:PrintToPlayer("Merchant Moogle : Accessories and more Kupo!", 0x1F);
		elseif (page == 66) and (level >= 50) then
        local stock_6w =
		{
			13134,	12000,   -- Ashura Necklace
			16263,  7000,    -- Beak Necklace
			13325,  3000,   -- Fang Earring
			13416,  11000,   -- Bat Earring
			14761,  105000,   -- Elusive Earring
			13312,  22000,   -- Coral Earring
			14630,  55000,   -- Flame Ring
			14640,  52000,   -- Snow Ring
			14636,  52000,   -- Breeze Ring
			14634,  52000,   -- Soil Ring
			14638,  52000,   -- Thunder Ring
			14632,  52000,   -- Aqua Ring
			14642,  42000,   -- Light Ring
			14644,  52000,   -- Dark Ring
			15431,  7000,   -- Astral Rope
			15292,  32000,   -- Penetints Rope
			15884,  52000,   -- Potenet Belt
			13597,  9000,   -- Beak Mantle
			13591,  12400,   -- Behemoth Mantle
			13687,  83000,   -- Sapient Cape
			13645,  12000,   -- Amemet Mantle
			16231,  3500    -- Smilidon Mantle		
		};
		showShop(player, STATIC, stock_6w);
        player:PrintToPlayer("Merchant Moogle : Accessories and more Kupo!", 0x1F);		
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
        player:PrintToPlayer("Merchant Moogle : That store is not accessible yet Kupo", 0x1F);	
        end
	
	
		elseif (page == 8) and (aura >= 4) then
	    local stock_8 =
        {
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
			17585,   7000,
			606,     2000,        -- Fetich Head
			607,     2000,        -- Fetich Torso
			608,     2000,        -- Fetich Arms
			609,     2000,        -- Fetich Legs
			
			
        };
        showShop(player, STATIC, stock_8);
        player:PrintToPlayer("Merchant Moogle : Miscellaneous items Kupo", 0x1F);	
		elseif (page == 8) and (aura < 4) and (aura > 1) then
	    local stock_8 =
        {
			17583,   7000, 
			17584,   7000,   
			17585,   7000,
			606,     2000,        -- Fetich Head
			607,     2000,        -- Fetich Torso
			608,     2000,        -- Fetich Arms
			609,     2000,        -- Fetich Legs
			
			
        };
        showShop(player, STATIC, stock_8);
        player:PrintToPlayer("Merchant Moogle : Miscellaneous items Kupo.  Unlock more items with Feretory Aura!", 0x1F);			
		elseif (page == 8) and (aura < 2) then
	    local stock_8 =
        {
			606,     2000,        -- Fetich Head
			607,     2000,        -- Fetich Torso
			608,     2000,        -- Fetich Arms
			609,     2000,        -- Fetich Legs
			
			
        };
        showShop(player, STATIC, stock_8);
        player:PrintToPlayer("Merchant Moogle : Miscellaneous items Kupo.  Unlock more items with Feretory Aura!", 0x1F);
		
		elseif (page == 9) then
	    local stock_9 =
        {
            8513,     12000,    -- Accelerator
            8516,    32000,    -- Accelerator II
			8546,     11000,    -- Armor Plate
			8548,    22000,    -- Armor Plate II
			8641,    11000,    -- Auto-Repair Kit 
			8644,    35000,    -- Auto-Repair Kit II
			8520,    12000,    -- Barrage Turbine
			8583,    12000,    -- Coiler
			8643,     12000,    -- Damage Gauge
			8517,    3000,    -- Drum Magazine
			8582,    11000,    -- Dynamo
			1050,    12000,    -- Flashbulb
			8642,    32000,    -- Hammermill
			8451,    12000,    -- Inhibitor
			8482,     12000,    -- Loudspeaker I
			8484,    32000,    -- Loudspeaker II
			8674,    12000,    -- Mana Converter
			8609,    12000,    -- Mana Jammer
			8612,     7000,    -- Mana Jammer II
			8673,     12000,    -- Mana Tank
			8676,    32000,    -- Mana Tank II
			8483,     12000,    -- Scanner
			8545,    16000,    -- Shock Absorber
			8577,     12000,    -- Stabilizer I
			8580,    12000,    -- Stabilizer II
			8449,     32000,    -- Strobe
			8450,     12000,    -- Tension Spring
			8452,    32000,    -- Tension Spring II
            8518,    92000     -- Tubro Charger
			
			
        };
        showShop(player, STATIC, stock_9);
        player:PrintToPlayer("Merchant Moogle : Attachments Kupo", 0x1F);	
		
		
		
       else
        -- local Mog = 16982044;
        -- message = "Test!";
        -- SpoofSay(Mog,player:getID(),message);
        player:PrintToPlayer( string.format( "The MogShop catalog doesn't have a page %i, Kupo!", page ) );
    end
end;