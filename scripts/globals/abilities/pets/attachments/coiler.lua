-----------------------------------
-- Attachment: Coiler
-- Thunder based Attachment
-- 
-- 0x Maneuver = 3% Double Attack
-- 1x Maneuver = 10% Double Attack
-- 2x Maneuver = 20% Double Attack
-- 3x Maneuver = 30% Double Attack
-----------------------------------

require("scripts/globals/status");

-----------------------------------
-- onUseAbility
-----------------------------------

function onManeuverGain(player,maneuvers)
local pet = player:getPet();
local power = 0;
local thunder = player:getEffectsCount(EFFECT_THUNDER_MANEUVER);
if (thunder == 1) then
power = 7;
if (thunder == 2) then
power = 10;
if (thunder == 3) then
power = 10;
end
end
end

local pet = player:getPet();
local datt = pet:getMod(MOD_DOUBLE_ATTACK);
pet:addMod(MOD_DOUBLE_ATTACK, power);
end

function onManeuverLose(player,maneuvers)
local pet = player:getPet();
local power = 0;
local thunder = player:getEffectsCount(EFFECT_THUNDER_MANEUVER);
local newthunder = thunder - 1;
if (newthunder == 0) then
power = 7;
if (newthunder == 1) then
power = 10;
if (newthunder == 2) then
power = 10;
end
end
end

local pet = player:getPet();
pet:delMod(MOD_DOUBLE_ATTACK, power);
end
