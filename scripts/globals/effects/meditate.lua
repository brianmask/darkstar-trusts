-----------------------------------
-- Meditate
-----------------------------------

require("scripts/globals/status");

-----------------------------------
-- onEffectGain Action
-----------------------------------

function onEffectGain(target,effect)
	target:addMod(MOD_REGAIN, effect:getPower() * 10);
end;

-----------------------------------
-- onEffectTick Action
-----------------------------------

function onEffectTick(target,effect)
-- caster:isUniqueAlly(79))
target:updateHealth();
end;

-----------------------------------
-- onEffectLose Action
-----------------------------------

function onEffectLose(target,effect)
	target:delMod(MOD_REGAIN, effect:getPower() * 10);
end;