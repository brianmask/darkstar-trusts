-----------------------------------
-- Attachment: Stabalizer
-- Thunder Based Maneuver 
-- Increases Accuracy
--
-- 0x Maneuver - +5 Accuracy
-- 1x Maneuver - +10 Accuracy
-- 2x Maneuver - +15 Accuracy
-- 3x Maneuver - +20 Accuracy
-----------------------------------

require("scripts/globals/status");

-----------------------------------
-- onUseAbility
-----------------------------------

function onManeuverGain(player,maneuvers)
local pet = player:getPet();
pet:addMod(MOD_ACC, 5);
end

function onManeuverLose(player,maneuvers)
local pet = player:getPet();
pet:delMod(MOD_ACC, 5);
end
