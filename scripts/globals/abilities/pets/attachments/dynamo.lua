-----------------------------------
-- Attachment: Dynamo
-- Thunder Based Maneuver 
-- Increases Critical Hitrate 
--
-- 0x Maneuver - +3% Critical Hitrate
-- 1x Maneuver - +5% Critical Hitrate
-- 2x Maneuver - +7% Critical Hitrate
-- 3x Maneuver - +9% Critical Hitrate
-----------------------------------

require("scripts/globals/status");

-----------------------------------
-- onUseAbility
-----------------------------------

function onManeuverGain(player,maneuvers)
local pet = player:getPet();
pet:addMod(MOD_CRITHITRATE, 2);
end

function onManeuverLose(player,maneuvers)
local pet = player:getPet();

pet:delMod(MOD_CRITHITRATE, 2);
end
