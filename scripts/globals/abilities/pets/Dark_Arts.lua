-----------------------------------
-- Ability: Dark Arts
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

    pet:delStatusEffect(EFFECT_TRUST_LIGHT_ARTS);

    pet:addStatusEffectEx(EFFECT_TRUST_DARK_ARTS,EFFECT_DARK_ARTS,1,0,7200);

    return EFFECT_DARK_ARTS;
end;