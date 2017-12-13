-----------------------------------
-- Ability: Boost
-- Enhances user's next attack.
-- Obtained: Monk Level 5
-- Recast Time: 0:15
-- Duration: 3:00
-----------------------------------

require("scripts/globals/status");

-----------------------------------
-- onAbilityCheck
-----------------------------------

function onAbilityCheck(player,target,ability)
	return 0,0;
end;

-----------------------------------
-- onUseAbility
-----------------------------------

function onUseAbility(player,target,ability)
    local sHands = player:getEquipID(SLOT_HANDS);
	local effect = player:getStatusEffect(EFFECT_BOOST);
    local level = player:getMainLvl();
	local power = 3.5
    if (sHands == 13962 or sHands == 14891) then
        power = power + 1.5;
    end
	

	
	if ((level < 40) and (player:getActiveBoosts() == 1) and (player:getMainJob() == 2)) then
	player:removeOldestBoost();	
	end
	if ((level < 60) and (player:getActiveBoosts() == 2) and (player:getMainJob() == 2)) then
	player:removeOldestBoost();	
    end	
	if ((level <= 75) and (player:getActiveBoosts() == 3) and (player:getMainJob() == 2)) then
	player:removeOldestBoost();	
    end


   -- if (player:hasStatusEffect(EFFECT_BOOST) == true) then
      --  local effect = player:getStatusEffect(EFFECT_BOOST);
      --  effect:setPower(effect:getPower() + power);
      --  player:addMod(MOD_ATTP,power);
   -- else

        target:addStatusEffect(EFFECT_BOOST,power,1,180);
		--effect:setIcon(EFFECT_FIRE_MANEUVER);
   -- end
	
	    return EFFECT_BOOST;
end;