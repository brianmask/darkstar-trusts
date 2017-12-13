-----------------------------------
-- Attachment: Auto-Repair Kit II
-----------------------------------

require("scripts/globals/status");

-----------------------------------
-- onUseAbility
-----------------------------------

function onManeuverGain(player,maneuvers)
local power = 0;
local light = player:getEffectsCount(EFFECT_LIGHT_MANEUVER);
if (light == 1) then
power = 4;
elseif (light == 2) then
power = 4;
elseif (light == 3) then
power = 5;
end


local pet = player:getPet();
pet:addMod(MOD_REGEN, power);
end

function onManeuverLose(player,maneuvers)
local power = 0;
local light = player:getEffectsCount(EFFECT_LIGHT_MANEUVER);
if (light == 3) then
power = 5;
elseif (light == 2) then
power = 4;
elseif (light == 1) then
power = 4;
end


local pet = player:getPet();
pet:delMod(MOD_REGEN, power);
end
