-----------------------------------
-- Ability: Chi Blast
-- Releases Chi to attack an enemy.
-- Obtained: Monk Level 41
-- Recast Time: 3:00
-- Duration: Instant
-----------------------------------

require("scripts/globals/settings");
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
	local lvl = player:getMainLvl();
	local rand = math.random(25,50);
	local rand = (rand / 100) + 1;
    local multiplier = 1.0;
    if (boost ~= nil) then
        multiplier = player:getActiveBoosts();
		multiplier = multiplier + 1;
    end
	
	local slow = multiplier * 8;
	local duration = multiplier * 5;
    
    local dmg = math.floor((player:getStat(MOD_MND) + (lvl * 0.66)) * multiplier);

    dmg = utils.stoneskin(target, dmg);
    
    target:delHP(dmg);
    
    target:updateClaim(player);
    target:updateEnmityFromDamage(player,dmg);
    player:removeAllBoosts();
	player:addStatusEffect(EFFECT_SLOW,duration,0,15)
    return dmg;
end;
