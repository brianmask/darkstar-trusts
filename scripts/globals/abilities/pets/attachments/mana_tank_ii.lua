-----------------------------------
-- Attachment: Mana Tank II
-----------------------------------

require("scripts/globals/status");

-----------------------------------
-- onUseAbility
-----------------------------------

function onManeuverGain(player,maneuvers)
local power = 0;
local dark = player:getEffectsCount(EFFECT_DARK_MANEUVER);
if (dark == 1) then
power = 2;
elseif (dark == 2) then
power = 2;
elseif (dark == 3) then
power = 1;
end


local pet = player:getPet();
pet:addMod(MOD_REFRESH, power);
end

function onManeuverLose(player,maneuvers)
local power = 0;
local dark = player:getEffectsCount(EFFECT_DARK_MANEUVER);

if (dark == 3) then
power = 2;
elseif (dark == 2) then
power = 2;
elseif (dark == 1) then
power = 1;
end


local pet = player:getPet();
pet:delMod(MOD_REFRESH, power);
end
