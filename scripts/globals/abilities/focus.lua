-----------------------------------
-- Ability: Focus
-- Enhances user's accuracy.
-- Obtained: Monk Level 25
-- Recast Time: 5:00
-- Duration: 2:00
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
    local boost = player:getStatusEffect(EFFECT_BOOST);
    local sLegs = player:getEquipID(SLOT_LEGS);
    local power = 20
    if (sLegs == 12512 or sLegs == 15226) then
        power = power + 10;
    end
	player:setVar("MNKBoostNumber",0);
	if (boost ~= nil) then
    local activeboost = player:getActiveBoosts();
	player:setVar("MNKBoostNumber",activeboost);
    end
	
	player:removeAllBoosts();
	
	
	
   player:addStatusEffect(EFFECT_FOCUS,power,0,120);
end;