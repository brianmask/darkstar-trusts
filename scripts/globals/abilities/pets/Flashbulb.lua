---------------------------------------------------
-- Flashbulb
-- Uses Flash to blind the target temporarily
---------------------------------------------------

require("/scripts/globals/settings");
require("/scripts/globals/status");
require("/scripts/globals/monstertpmoves");

---------------------------------------------------

function onMobSkillCheck(target,mob,skill)
    return 0;
end;

function onPetAbility(target, pet, skill)
local duration = 0;
local lvldif = pet:getMainLvl() - target:getMainLvl();

if (lvldif < -8) then
duration = 3;
else if (lvldif < -5) then
duration = 4;
else if (lvldif == 0) then
duration = 6;
else if (lvldif < 5) then
duration = 7;
else if (lvldif > 5) then
duration = 8;
else 
duration = 0;
end
end
end
end
end


if (duration ~= 0) then
  target:addStatusEffect(EFFECT_FLASH,200,0,duration);
   skill:setMsg(MSG_ENFEEB_IS);
   else
   skill:setMsg(MSG_NO_EFFECT);
   
   
   
   end
   return EFFECT_FLASH;

end;
