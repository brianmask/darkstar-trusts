-----------------------------------
-- Attachment: Auto-Repair Kit
-----------------------------------

require("scripts/globals/status");

-----------------------------------
-- onUseAbility
-----------------------------------

function onManeuverGain(player,maneuvers)
local power = 0;
local light = player:getEffectsCount(EFFECT_LIGHT_MANEUVER);
if (light == 1) then
power = 2;
elseif (light == 2) then
power = 1; 
elseif (light == 3) then 
power = 1;
end



local pet = player:getPet();
pet:addMod(MOD_REGEN, power);

end

function onManeuverLose(player,maneuvers)
local power = 0;
local light = player:getEffectsCount(EFFECT_LIGHT_MANEUVER);
if (light == 3) then 
power = 1;
elseif (light == 2) then
power = 1;
elseif (light == 1) then
power = 2;
end
local pet = player:getPet();
pet:delMod(MOD_REGEN, power);
end
