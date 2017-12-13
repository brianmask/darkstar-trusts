-----------------------------------
-- Attachment: Tension Srping II
-- Fire Based Maneuver 
-- Increases Attack/Ranged Attack
--
-- 0x Maneuver - +6% Attack
-- 1x Maneuver - +9% Attack
-- 2x Maneuver - +12% Attack
-- 3x Maneuver - +15% Attack
-----------------------------------

require("scripts/globals/status");

-----------------------------------
-- onUseAbility
-----------------------------------

function onManeuverGain(player,maneuvers)
local pet = player:getPet();
pet:addMod(MOD_ATTP, 3);
pet:addMod(MOD_RATTP, 3);
end

function onManeuverLose(player,maneuvers)
local pet = player:getPet();

pet:delMod(MOD_RATTP, 3);
pet:delMod(MOD_RATTP, 3);
end
