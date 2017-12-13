-----------------------------------
-- Attachment: Scope
-- Wind Based Maneuver 
-- Increases Ranged Accuracy
--
-- 0x Maneuver - +10 Accuracy
-- 1x Maneuver - +20 Accuracy
-- 2x Maneuver - +30 Accuracy
-- 3x Maneuver - +45 Accuracy
-----------------------------------

require("scripts/globals/status");

-----------------------------------
-- onUseAbility
-----------------------------------

function onManeuverGain(player,maneuvers)
local pet = player:getPet();
pet:addMod(MOD_RACC, 10);
end

function onManeuverLose(player,maneuvers)
local pet = player:getPet();
pet:delMod(MOD_RACC, 10);
end
