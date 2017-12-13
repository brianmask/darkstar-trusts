-----------------------------------
-- Ability: Chivalry
-- Converts TP to MP.
-- Obtained: Paladin Level 75 (Must be Purchased with Merit Points)
-- Recast Time: 0:10:00 (+5% MP granted per additional upgrade)
-- Duration: Instant
-----------------------------------

require("scripts/globals/settings");
require("scripts/globals/status");

-----------------------------------
-- onAbilityCheck
-----------------------------------

function onMobSkillCheck(target,mob,skill)
    return 0, 0;
end;

function onPetAbility(target, pet, skill)
    
--(TP * .5) + ((0.015 * TP) * MND) = MP Gained
    local amount = ((pet:getTP())*((3 * pet:getStat(MOD_MND) / 100) + 1));
    pet:setTP(0);
	pet:addMP(amount);
	skill:setMsg(MSGBASIC_RECOVERS_MP);
    return amount;
end;