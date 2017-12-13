-----------------------------------
--
-- 	EFFECT_ARCANE_CIRCLE
--
-----------------------------------

require("scripts/globals/status");

-----------------------------------
-- onEffectGain Action
-----------------------------------

function onEffectGain(target,effect)
   target:addMod(MOD_ARCANA_KILLER, effect:getPower());
   target:addMod(MOD_REGEN,3);
   target:addMod(MOD_DARKDEF,30);
   target:addMod(MOD_DARKRES,30);
   target:addMod(MOD_DARKACC,30);
   target:addMod(MOD_MAGIC_DAMAGE,10);
   target:addMod(MOD_FASTCAST,10);
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
   target:delMod(MOD_ARCANA_KILLER, effect:getPower());
   target:delMod(MOD_REGEN,3);
   target:delMod(MOD_DARKDEF,30);
   target:delMod(MOD_DARKRES,30);
   target:delMod(MOD_DARKACC,30);
   target:delMod(MOD_MAGIC_DAMAGE,10);
   target:delMod(MOD_FASTCAST,10);
end;
