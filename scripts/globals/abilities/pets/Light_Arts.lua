-----------------------------------
-- Ability: Light Arts
-- 
-- Duration: Instant
-----------------------------------

require("scripts/globals/settings");
require("scripts/globals/status");

-----------------------------------
-- onAbilityCheck
-----------------------------------

function onAbilityCheck(pet,target,ability)
    
end;

-----------------------------------
-- onUseAbility
-----------------------------------

function onPetAbility(target, pet, skill)

    pet:delStatusEffect(EFFECT_TRUST_DARK_ARTS);

    pet:addStatusEffectEx(EFFECT_TRUST_LIGHT_ARTS,EFFECT_LIGHT_ARTS,1,0,7200);

    return EFFECT_LIGHT_ARTS;
end;