-----------------------------------
--
-- 	EFFECT_HOLY_CIRCLE
--
-----------------------------------

require("scripts/globals/status");

-----------------------------------
-- onEffectGain Action
-----------------------------------

function onEffectGain(target,effect)
   target:addMod(MOD_UNDEAD_KILLER,8);
   target:addMod(MOD_REGEN,3);
   target:addMod(MOD_LIGHTDEF,30);
   target:addMod(MOD_LIGHTRES,30);
   target:addMod(MOD_LIGHTACC,30);
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
   target:delMod(MOD_UNDEAD_KILLER,8);
   target:delMod(MOD_REGEN,3);
   target:delMod(MOD_LIGHTDEF,30);
   target:delMod(MOD_LIGHTRES,30);
   target:delMod(MOD_LIGHTACC,30);
end;
