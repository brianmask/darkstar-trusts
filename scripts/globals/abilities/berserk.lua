-----------------------------------
-- Ability: Berserk
-- Enhances attacks but weakens defense.
-- Obtained: Warrior Level 15
-- Recast Time: 5:00
-- Duration: 3:00
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

    local dexboost = target:getMainLvl()/7;

    if (target:getMainJob()~=1) then --sjob war, use sub level
        dexboost = target:getSubLvl()/7;
    end
    player:addStatusEffect(EFFECT_BERSERK,dexboost,0,180);

    return EFFECT_BERSERK;
end;