---------------------------------------------------
-- Jump
-- Trust: Excenmille
-- 
---------------------------------------------------

require("/scripts/globals/settings");
require("/scripts/globals/status");
--require("/scripts/globals/monstertpmoves");

---------------------------------------------------

function onMobSkillCheck(target,mob,skill)
    return 0, 0;
end;

function onPetAbility(target, pet, skill, action)

    local typeEffect = EFFECT_DEFENSE_DOWN;
    local duration = 30; 

    if (target:addStatusEffect(typeEffect,20,0,duration) == false) then
        ability:setMsg(75);
    end

    target:updateClaim(pet);
    return typeEffect;

end;
