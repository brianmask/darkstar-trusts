-----------------------------------
-- Attachment: Mana Jammer II
-- Water Based Maneuver 
-- Increases Magic Defense Bonus
--
-- 0x Maneuver - +20 Magic Defense Bonus
-- 1x Maneuver - +30 Magic Defense Bonus
-- 2x Maneuver - +40 Magic Defense Bonus
-- 3x Maneuver - +50 Magic Defense Bonus
-----------------------------------

require("scripts/globals/status");

-----------------------------------
-- onUseAbility
-----------------------------------

function onManeuverGain(player,maneuvers)
local pet = player:getPet();
pet:addMod(MOD_MDEF, 10);
end

function onManeuverLose(player,maneuvers)
local pet = player:getPet();

pet:delMod(MOD_MDEF, 10);
end
