-----------------------------------
--
-- 	EFFECT_ELEMENTAL_SEAL
--
-----------------------------------

require("scripts/globals/settings");
require("scripts/globals/status");

-----------------------------------
-- onEffectGain Action
-----------------------------------

function onEffectGain(target,effect)
   target:addMod(MOD_MACC,256);
   target:addMod(MOD_MAGIC_DAMAGE,30);
   target:addMod(MOD_CONSERVE_MP,30);


-----------------------------------
-- onEffectTick Action
-----------------------------------

function onEffectTick(target,effect)
   target:addMod(MOD_MAGIC_DAMAGE,-3);
   target:addMod(MOD_CONSERVE_MP,-3);
end;

-----------------------------------
-- onEffectLose Action
-----------------------------------

function onEffectLose(target,effect)
	target:delMod(MOD_MACC,256);
end;


