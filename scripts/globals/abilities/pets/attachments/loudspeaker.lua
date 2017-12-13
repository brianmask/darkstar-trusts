-----------------------------------
-- Attachment: Loudspeaker I
-- Ice Based Maneuver 
-- Increases Magic Attack Bonus
--
-- 0x Maneuver - +5 Magic Attack Bonus
-- 1x Maneuver - +10 Magic Attack Bonus
-- 2x Maneuver - +15 Magic Attack Bonus
-- 3x Maneuver - +20 Magic Attack Bonus
-----------------------------------

require("scripts/globals/status");

-----------------------------------
-- onUseAbility
-----------------------------------

function onManeuverGain(player,maneuvers)
local pet = player:getPet();
pet:addMod(MOD_MATT, 5);
end

function onManeuverLose(player,maneuvers)
local pet = player:getPet();

pet:delMod(MOD_MATT, 5);
end
