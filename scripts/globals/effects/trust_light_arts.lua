-----------------------------------
--
-- 	EFFECT_TRUST_LIGHT_ARTS
--
-----------------------------------

require("scripts/globals/status");

-----------------------------------
-- onEffectGain Action
-----------------------------------

function onEffectGain(target,effect)
local level = target:getMainLvl();
local player = target:getMaster();
player:setVar("AdelhiedLevel",level);
local addition = math.floor(level * 0.22);
target:addMod(MOD_HEALING, addition);
target:addMod(MOD_ENHANCE, addition);
target:addMod(MOD_WHITE_MAGIC_COST, -10);
target:addMod(MOD_BLACK_MAGIC_COST, 20);
--todo store this as a variable for the player due to level up casing issues when removed

end;

-----------------------------------
-- onEffectTick Action
-----------------------------------

function onEffectTick(target,effect)


end;

-----------------------------------
-- onEffectLose Action
-----------------------------------

function onEffectLose(target,effect)
local player = target:getMaster();
local level = player:getVar("AdelhiedLevel");
local deletion = math.floor(level * 0.22);
target:delMod(MOD_HEALING, deletion);
target:delMod(MOD_ENHANCE, deletion);
target:delMod(MOD_WHITE_MAGIC_COST, -10);
target:delMod(MOD_BLACK_MAGIC_COST, 20);
end;