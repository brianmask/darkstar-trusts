-----------------------------------
-- Ability: Dodge
-- Enhances user's evasion.
-- Obtained: Monk Level 15
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
    if (sLegs == 14090 or sLegs == 15353) then
        power = power + 10;
    end
	
	player:setVar("MNKBoostNumberDodge",0);
	if (boost ~= nil) then
    local activeboost = player:getActiveBoosts();
	player:setVar("MNKBoostNumberDodge",activeboost);
    end
	
	player:removeAllBoosts();
	
	
    player:addStatusEffect(EFFECT_DODGE,power,0,120);
end;