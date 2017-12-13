-----------------------------------
-- Area: Navukgo Execution Chamber
-- MOB: Karababa
-----------------------------------

package.loaded["scripts/zones/Navukgo_Execution_Chamber/TextIDs"] = nil;
-----------------------------------

require("scripts/globals/status");
require("scripts/zones/Navukgo_Execution_Chamber/TextIDs");

-----------------------------------
-- onMobInitialize Action
-----------------------------------

function onMobInitialize(mob)
    --50% fast cast, no standback
   mob:setMobMod(MOBMOD_HP_STANDBACK,50);
   mob:addMod(MOD_MATT, -50);
   mob:addMod(MOD_DEF, 220);
end;

-----------------------------------
-- onMobRoam Action
-----------------------------------

function onMobRoam(mob)
local start = mob:getLocalVar("start");
local targets;
local chars;
    mob:addMP(1500);
	
local wait = mob:getLocalVar("wait");
targets = mob:getBattlefield():getEnemies(); -- gets the current mobs in the zone
chars = mob:getBattlefield():getPlayers(); -- Gets all characters in the instance



-- Loop thru chars to see if a character is attacking

    for j,player in pairs(chars) do
	    local battleTarget = player:getTarget();
		
		if (battleTarget ~= nil) then
		   printf("Battle Target Acquired!!");
		   mob:addEnmity(battleTarget, 0, 1);
		   break;
		 end
	end	 

if (start == 0 and wait > 100) then -- Wait 100 Seconds before Attacking
     printf("Time to Attack!!!!");
    for i,fight in pairs(targets) do -- Loop thru all mobs and attack the first one
                if (fight:isAlly()) then
				    printf("This is Shantotto");
				else
				    -- fight:delHP(100);
					-- printf("This THE ENEMY!!!");
				    mob:addEnmity(fight, 0, 10);
				
				-- mob:setLocalVar("start",1);
		        break;
				end
	end	
else
  printf("Wait is %u",wait);
  mob:setLocalVar("wait", wait+3);
  printf("I am NOT ready to fight yet");
end  
		
end;






-----------------------------------
-- onMobEngaged Action
-----------------------------------

function onMobEngaged(mob,target)
end;

-----------------------------------
-- onMobFight Action
-----------------------------------

function onMobFight(mob,target)
    printf("Karababa Fighting");
    local warp = mob:getLocalVar("warp");

    if (mob:getHPP() <= 50 and mob:getLocalVar("powerup") == 0) then
        target:showText(mob,KARABABA_ENOUGH);
        target:showText(mob,KARABABA_ROUGH);
        mob:addStatusEffect(EFFECT_MAGIC_ATK_BOOST,15,0,1800);
        mob:setLocalVar("powerup",1);
    elseif (mob:getHPP() <= 20 and warp == 0) then
        mob:setLocalVar("warp",1);
    end
end;

-----------------------------------
-- onSpellPrecast
-----------------------------------

function onSpellPrecast(mob, spell)
    printf("Trying to cast");
end;

-----------------------------------
-- onSpellPrecast
-----------------------------------

function onMonsterMagicPrepare(mob, target)
    local powerup = mob:getLocalVar("powerup");
    local rnd = math.random(1, 6)
    local warp = mob:getLocalVar("warp");
    local hp = target:getHPP();
	
    if (warp == 1) then
        mob:showText(mob,KARABABA_QUIT);
        mob:setLocalVar("warp",2);
        return 261;
    elseif (mob:getLocalVar("warp") == 2) then
        mob:getBattlefield():lose();
        return -1;
    elseif (rnd == 1 and hp < 90) then
        mob:showText(mob,KARABARA_FIRE);
        return 205 - powerup;
    elseif (rnd == 2 and hp < 90) then
        mob:showText(mob,KARABARA_ICE);
        return 207 - powerup;
    elseif (rnd == 3 and hp < 90) then
        mob:showText(mob,KARABARA_WIND);
        return 209 - powerup;
    elseif (rnd == 4 and hp < 90) then
        mob:showText(mob,KARABARA_EARTH);
        return 211 - powerup;
    elseif (rnd == 5 and hp < 90) then
        mob:showText(mob,KARABARA_LIGHTNING);
        return 213 - powerup;
    elseif (rnd == 6 and hp < 90) then
        mob:showText(mob,KARABARA_WATER);
        return 215 - powerup;
    end

end;

-----------------------------------
-- onMobDespawn
-----------------------------------

function onMobDespawn(mob, killer)
    mob:getBattlefield():lose();
end;

-----------------------------------
-- onMobDeath
-----------------------------------

function onMobDeath(mob, killer)
    mob:getBattlefield():lose();
end;