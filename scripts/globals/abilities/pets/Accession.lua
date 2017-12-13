-----------------------------------
-- Ability: Accession
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
   pet:addStatusEffectEx(EFFECT_TRUST_ACCESSION,EFFECT_ACCESSION,1,0,6);
   return EFFECT_ACCESSION;
end;