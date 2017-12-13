-----------------------------------
-- Ability: Ebullience
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
      pet:addStatusEffectEx(EFFECT_TRUST_EBULLIENCE,EFFECT_EBULLIENCE,1,0,60);
   return EFFECT_EBULLIENCE;
end;