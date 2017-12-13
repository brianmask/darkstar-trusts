-----------------------------------
-- Attachment: Arcanic Cell
-- Light Based Maneuver 
-- Increases Occult Acumen
--
-- 0x Maneuver - +10
-- 1x Maneuver - +20
-- 2x Maneuver - +35
-- 3x Maneuver - +50
-----------------------------------

require("scripts/globals/status");

-----------------------------------
-- onUseAbility
-----------------------------------

function onManeuverGain(player,maneuvers)
local power = 10;
local light = player:getEffectsCount(EFFECT_LIGHT_MANEUVER);
if (light == 1) then
power = 20;
elseif (light == 2) then
power = 35; 
elseif (light == 3) then 
power = 50;
end

local pet = player:getPet();
pet:setMod(MOD_OCCULT_ACUMEN, power);




end


function onManeuverLose(player,maneuvers)
local ice = player:getEffectsCount(EFFECT_LIGHT_MANEUVER);
if (light == 1) then
power = 20;
elseif (light == 2) then
power = 35; 
elseif (light == 0) then 
power = 10;
end

local pet = player:getPet();
pet:setMod(MOD_OCCULT_ACUMEN, power);
end
