-----------------------------------
--
--
--
-----------------------------------

-----------------------------------
-- onEffectGain Action
-----------------------------------

function onEffectGain(target,effect)
	target:addMod(MOD_RATTP,-35);
	target:addMod(MOD_RAPID_SHOT,100);
	target:addMod(MOD_RACC,-30);
end;

-----------------------------------
-- onEffectTick Action
-----------------------------------

function onEffectTick(target,effect)
    target:addMod(MOD_RATTP, -2);
end;

-----------------------------------
-- onEffectLose Action
-----------------------------------

function onEffectLose(target,effect)
	target:delMod(MOD_RATTP,-75);
	target:delMod(MOD_RAPID_SHOT,100);
    target:delMod(MOD_RACC,-30);
end;