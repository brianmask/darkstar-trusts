-----------------------------------
--
--
--
-----------------------------------
require("scripts/globals/status");
-----------------------------------
-- onEffectGain Action
-----------------------------------

function onEffectGain(target,effect) --power=30 initially
	target:addMod(MOD_DEFP,10);
	target:addMod(MOD_UDMGMAGIC,-10);
	target:addMod(MOD_ENMITY,15);
	target:addMod(MOD_NINJA_TOOL,50);
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
    target:delMod(MOD_DEFP,10);
	target:delMod(MOD_UDMGMAGIC,-10);
	target:delMod(MOD_ENMITY,15);
	target:delMod(MOD_NINJA_TOOL,50);
end;