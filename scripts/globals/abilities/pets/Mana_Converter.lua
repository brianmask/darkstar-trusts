-----------------------------------
-- Attachment: Mana Converter
-- Consumes HP to gradually restore MP
-- 3 Min recast
-- 1x Dark Maneuver 40% MP
-- 2x Dark Maneuver 60% MP
-- 3x Dark Maneuver 65% MP
-----------------------------------

require("scripts/globals/status");

-----------------------------------
-- onUseAbility
-----------------------------------

function onMobSkillCheck(target,mob,skill)
    return 0;
end;

function onPetAbility(target, pet, skill)
local player = pet:getMaster();
local amount = 0;
local hp = pet:getHP() / 2;
local dark = player:getEffectsCount(EFFECT_DARK_MANEUVER);
    if (dark == 1) then
	amount = 0.4;
    end
	 if (dark == 2) then
    amount = 0.6;
    end
	 if (dark == 3) then
	amount = 0.65;
    end
local finalmp = hp * amount;
local power = math.floor(finalmp / 10);
pet:setHP(hp);
pet:addStatusEffect(EFFECT_REFRESH, power, 3, 30);  



return 0; 
end;
