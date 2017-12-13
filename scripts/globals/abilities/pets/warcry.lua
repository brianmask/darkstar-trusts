-----------------------------------
-- Ability: Warcry
-- Enhances attacks of party members within area of effect.
-- Obtained: Warrior Level 35
-- Recast Time: 5:00
-- Duration: 0:30
-----------------------------------

require("scripts/globals/status");

-----------------------------------
-- onAbilityCheck
-----------------------------------

function onMobSkillCheck(target,mob,skill)
    return 0;
end;

function onPetAbility(target, pet, skill)
   
    local power = 0;
    local duration = 30;

   
     power = math.floor((pet:getMainLvl()/4)+4.75)/256;
  

    power = power * 100;
    --duration = duration + player:getMod(MOD_WARCRY_DURATION);


    pet:addStatusEffect(EFFECT_WARCRY,power,0,duration,0,merit);
	return EFFECT_WARCRY;
end;