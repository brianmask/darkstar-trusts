-----------------------------------
-- Attachment: Power Cooler
-- Ice Based Maneuver 
-- Reduces MP Cost
--
-- 0x Maneuver - -10% MP Cost
-- 1x Maneuver - -20% MP Cost
-- 2x Maneuver - -35% MP Cost
-- 3x Maneuver - -50% MP Cost
-----------------------------------

require("scripts/globals/status");

-----------------------------------
-- onUseAbility
-----------------------------------

function onManeuverGain(player,maneuvers)
local power = -10;
local ice = player:getEffectsCount(EFFECT_ICE_MANEUVER);
if (ice == 1) then
power = -20;
elseif (ice == 2) then
power = -35; 
elseif (ice == 3) then 
power = -50;
end

local pet = player:getPet();
pet:setMod(MOD_BLACK_MAGIC_COST, power);
pet:setMod(MOD_WHITE_MAGIC_COST, power);



end


function onManeuverLose(player,maneuvers)
local ice = player:getEffectsCount(EFFECT_ICE_MANEUVER);
if (ice == 1) then
power = -20;
elseif (ice == 2) then
power = -35; 
elseif (ice == 0) then 
power = -10;
end

local pet = player:getPet();
pet:setMod(MOD_BLACK_MAGIC_COST, power);
pet:setMod(MOD_WHITE_MAGIC_COST, power);
end
