-----------------------------------
-- Attachment: Economizer
-- Consumes all Dark Maneuvers to restore MP
-- 3 Min recast

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
local maxmp = pet:getMaxMP();
local petint = pet:getStat(MOD_INT);
local dark = player:getEffectsCount(EFFECT_DARK_MANEUVER);
local mp = petint((maxmp * 0.20) * dark)

pet:addMP(mp);


-- Remove Manuvers
	if (dark == 1) then
	player:delStatusEffect(EFFECT_DARK_MANEUVER);
	elseif (dark == 2) then
	player:delStatusEffect(EFFECT_DARK_MANEUVER);
	player:delStatusEffect(EFFECT_WIND_MANEUVER);
    elseif (dark == 3) then
	player:delStatusEffect(EFFECT_DARK_MANEUVER);
	player:delStatusEffect(EFFECT_DARK_MANEUVER);
	player:delStatusEffect(EFFECT_DARK_MANEUVER);
    end

return 0; 
end;
