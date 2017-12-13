-----------------------------------
-- Ability: Avatar's Favor
-- Enhances Avatar's Attack Power at the cost of avatar perpetuation

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

local main = player:getMainLvl();
local power = (main / 11) + 1;

    player:addStatusEffect(EFFECT_AVATAR_S_FAVOR,power,0,180);

    return EFFECT_AVATAR_S_FAVOR;
end;