-----------------------------------
-- Ability: Last Resort
-- Increases user's attack, but lowers defense.
-- Obtained: Dark Knight Level 15
-- Recast Time: 5:00
-- Duration: 3:00
-----------------------------------

require("scripts/globals/settings");
require("scripts/globals/status");

-----------------------------------
-- onAbilityCheck
-----------------------------------

function onAbilityCheck(player,target,ability)
    local level = player:getMainLvl();
	
	player:setVar("LastResortLevelMod",level);
	return 0,0;
end;

-----------------------------------
-- onUseAbility
-----------------------------------

function onUseAbility(player,target,ability)
    
	local lspower = player:getVar("LastResortLevelMod");
	local mppower = (lspower / 15 + 1);

	player:PrintToPlayer(mppower);
	


    player:addStatusEffect(EFFECT_LAST_RESORT,player:getMerit(MERIT_DESPERATE_BLOWS),3,180);
	
end;