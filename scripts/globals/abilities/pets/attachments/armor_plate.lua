-----------------------------------
-- Attachment: Armor Plate
-- Earth Based Maneuver 
-- Increases Defense 
--
-- 0x Maneuver - +10% Defense
-- 1x Maneuver - +15% Defense
-- 2x Maneuver - +20% Defense
-- 3x Maneuver - +25% Defense
-----------------------------------

require("scripts/globals/status");

-----------------------------------
-- onUseAbility
-----------------------------------

function onManeuverGain(player,maneuvers)
local pet = player:getPet();
pet:addMod(MOD_DEFP, 5);
end

function onManeuverLose(player,maneuvers)
local pet = player:getPet();

pet:delMod(MOD_DEFP, 5);
end
