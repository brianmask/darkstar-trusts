-----------------------------------
-- Attachment: Replicator
-- Consumes Maneuvers to give shadows
-- Triggered <= 50% HP
-- 3 Min recast
-- 1x Wind Maneuver 3 Shadows
-- 2x Wind Maneuver 7 Shadows
-- 3x Wind Maneuver 10 Shadows
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

local wind = player:getEffectsCount(EFFECT_WIND_MANEUVER)
    if (wind == 1) then
	amount = 3;
    elseif (wind == 2) then
    amount = 7
    elseif (wind == 3) then
	amount = 10;
    end

pet:addStatusEffect(EFFECT_BLINK, amount, 0, 120);

-- Remove Manuvers
	if (wind == 1) then
	player:delStatusEffect(EFFECT_WIND_MANEUVER);
	elseif (wind == 2) then
	player:delStatusEffect(EFFECT_WIND_MANEUVER);
	player:delStatusEffect(EFFECT_WIND_MANEUVER);
    elseif (wind == 3) then
	player:delStatusEffect(EFFECT_WIND_MANEUVER);
	player:delStatusEffect(EFFECT_WIND_MANEUVER);
	player:delStatusEffect(EFFECT_WIND_MANEUVER);
    end

return 0; 
end;
