---------------------------------------------------
-- Provoke
-- Fire Based Attachment
-- Goads an enemy to attack Pet
---------------------------------------------------

require("/scripts/globals/settings");
require("/scripts/globals/status");
--require("/scripts/globals/monstertpmoves");

---------------------------------------------------

function onMobSkillCheck(target,mob,skill)
    return 0;
end;

function onPetAbility(target, pet, skill)
 skill:setMsg(0);
 target:addEnmity(pet, 500, 3600);
 return EFFECT_PROVOKE;

end;
