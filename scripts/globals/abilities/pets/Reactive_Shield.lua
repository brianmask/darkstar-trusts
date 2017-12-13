---------------------------------------------------
-- Reactive Shield
-- Fire Based Attachment
-- Causes pet to use Blaze Spikes
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
 power = (pet:getMainLvl() / 10) + 5;
 pet:addStatusEffect(EFFECT_BLAZE_SPIKES,power,0,duration
 return EFFECT_BLAZE_SPIKES;

end;
