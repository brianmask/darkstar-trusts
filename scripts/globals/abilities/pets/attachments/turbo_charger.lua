-----------------------------------
-- Attachment: Turbo Charger
-- Wind Based Maneuver 
-- Increases Haste
--
-- 0x Maneuver - +5% Haste
-- 1x Maneuver - +15% Haste
-- 2x Maneuver - +20% Haste
-- 3x Maneuver - +25% Haste
-----------------------------------

require("scripts/globals/status");

-----------------------------------
-- onUseAbility
-----------------------------------

function onManeuverGain(player,maneuvers)
local pet = player:getPet();
local player = pet:getMaster();
local wind = player:getEffectsCount(EFFECT_WIND_MANEUVER);
if (wind == 1) then
pet:addMod(MOD_HASTE_GEAR, 10);
if (wind == 2) then
pet:addMod(MOD_HASTE_GEAR, 5);
if (wind == 3) then
pet:addMod(MOD_HASTE_GEAR, 5)
end
end
end
end;

function onManeuverLose(player,maneuvers)
local pet = player:getPet();
local player = pet:getMaster();
local wind = player:getEffectsCount(EFFECT_WIND_MANEUVER);
local newwind = wind - 1;
if (newwind == 1) then
pet:delMod(MOD_HASTE_GEAR, 10);
if (newwind == 2) then
pet:delMod(MOD_HASTE_GEAR, 5);
if (newwind == 3) then
pet:delMod(MOD_HASTE_GEAR, 5);
end
end
end


end;
