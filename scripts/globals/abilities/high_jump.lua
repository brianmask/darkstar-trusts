-----------------------------------
-- Ability: High Jump
-- Performs a high jumping attack on enemy.
-- Obtained: Dragoon Level 35
-- Recast Time: 2:00
-- Duration: Instant
-----------------------------------

require("scripts/globals/settings");
require("scripts/globals/status");

-----------------------------------
-- onAbilityCheck
-----------------------------------

function onAbilityCheck(player,target,ability)
	return 0,0;
end;

-----------------------------------
-- onUseAbility
-----------------------------------

function onUseAbility(player,target,ability)
local level = player:getMainLvl()
local vitdown = lvl / 2.5;
local magicdown = level / 3;

target:addStatusEffect(EFFECT_VIT_DOWN, vitdown, 0, 15);
target:addStatusEffect(EFFECT_MAGIC_DEF_DOWN, magicdown, 0, 15);
if (not target:hasStatusEffect(EFFECT_CHAINBOUND, 0) and not target:hasStatusEffect(EFFECT_SKILLCHAIN, 0)) then
target:addStatusEffectEx(EFFECT_CHAINBOUND, 0, 1, 0, 5, 0, 1);
end

end;