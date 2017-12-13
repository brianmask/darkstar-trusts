-----------------------------------
--
-- 	EFFECT_DIVINE_SEAL
--
-----------------------------------

require("scripts/globals/settings");
require("scripts/globals/status");
require("scripts/globals/common");

-----------------------------------
-- onEffectGain Action
-----------------------------------

function onEffectGain(target,effect)
  target:addMod(MOD_CURE_POTENCY, 10);
end;

-----------------------------------
-- onEffectTick Action
-----------------------------------

function onEffectTick(target,effect)
  target:addMod(MOD_CURE_POTENCY, -6);
end;

-----------------------------------
-- onEffectLose Action
-----------------------------------

function onEffectLose(target,effect)
  target:addMod(MOD_CURE_POTENCY, 50);
end;


