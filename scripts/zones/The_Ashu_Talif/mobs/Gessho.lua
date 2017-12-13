-----------------------------------
-- Area: The Ashu Talif (The Black Coffin)
-- MOB: Gessho
-- TOAU-15 Mission Battle
-----------------------------------

local TheAshuTalif = require("scripts/zones/The_Ashu_Talif/IDs");

require("scripts/globals/allyassist");
require("scripts/globals/instance");
require("scripts/globals/status");
require("scripts/globals/magic");

-----------------------------------
-- onMobInitialize Action
-----------------------------------

function onMobInitialize(mob)
end

-----------------------------------
-- onMobSpawn Action
-----------------------------------

function onMobSpawn(mob)
    -- Gessho will engage by himself ~1min in if you stall too long.
    -- Give a little buffer for while the instance loads
	-- printf("SPAWNING GESHO!!!");
    
       -- if(mob:getLocalVar("ready") == 0 and not(mob:getTarget())) then
         --    startAllyAssist(mob, ALLY_ASSIST_PLAYER);
			-- print("Random too choose");
        -- end
    

 
end;

-----------------------------------
-- onMobEngaged Action
-----------------------------------

function onMobEngaged(mob, target)
    local dialog = mob:getLocalVar("dialog");

    if(dialog == 0) then
        mob:showText(mob,TheAshuTalif.text.BATTLE_HIGH_SEAS);
        mob:setLocalVar("dialog",1);
    end
end;

-----------------------------------
-- onMobRoam Action
-----------------------------------

function onMobRoam(mob)
local start = mob:getLocalVar("start");
local targets;
local chars;
local wait = mob:getLocalVar("wait");
targets = mob:getInstance():getMobs(); -- gets the current mobs in the zone
chars = mob:getInstance():getChars(); -- Gets all characters in the instance

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
    -- printf("Time to Attack!!!!");
    for i,fight in pairs(targets) do -- Loop thru all mobs and attack the first one
                if (fight:isAlly()) then
				   -- printf("This is Gessho");
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
-- onMobFight Action
-----------------------------------

function onMobFight(mob, target)
    local dialog = mob:getLocalVar("dialog");

    if(mob:getHPP() <= 20 and dialog == 1) then
        mob:showText(mob,TheAshuTalif.text.TIME_IS_NEAR);
        mob:setLocalVar("dialog",2);
    end
end;

-----------------------------------
-- onMobDeath
-----------------------------------

function onMobDeath(mob, player, isKiller)
    mob:showText(mob,TheAshuTalif.text.SO_I_FALL);
end;
