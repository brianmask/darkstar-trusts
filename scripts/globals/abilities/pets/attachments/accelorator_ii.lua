-----------------------------------
-- Attachment: Accelorator II
-- Wind Based Maneuver 
-- Increases Evasion
--
-- 0x Maneuver - +10 Evasion
-- 1x Maneuver - +15 Evasion
-- 2x Maneuver - +20 Evasion
-- 3x Maneuver - +25 Evasion
-----------------------------------

require("scripts/globals/status");

-----------------------------------
-- onUseAbility
-----------------------------------

function onManeuverGain(player,maneuvers)
local pet = player:getPet();
pet:addMod(MOD_EVA, 5);
end

function onManeuverLose(player,maneuvers)
local pet = player:getPet();

pet:delMod(MOD_EVA, 5);
end
