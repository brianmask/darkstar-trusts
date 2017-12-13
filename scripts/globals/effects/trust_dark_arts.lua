-----------------------------------
--
-- 	EFFECT_TRUST_DARK_ARTS
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
target:addMod(MOD_ELEM, addition);
target:addMod(MOD_ENFEEBLE, addition);
print("Dark Arts Active");
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
target:delMod(MOD_ELEM, deletion);
target:delMod(MOD_ENFEEBLE, deletion);
end;