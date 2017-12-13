-----------------------------------
--
--	EFFECT_SHARPSHOT
--
-----------------------------------

require("scripts/globals/status");

-----------------------------------
-- onEffectGain Action
-----------------------------------

function onEffectGain(target,effect)
    target:addMod(MOD_ENMITY, -10);
	target:addMod(MOD_RATTP, 5);
	target:addMod(MOD_CRITHITRATE, 5);
	target:addMod(MOD_RACC,effect:getPower());
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
    target:delMod(MOD_ENMITY, -10);
	target:delMod(MOD_RATTP, 5);
	target:delMod(MOD_CRITHITRATE, 5);	
	target:delMod(MOD_RACC,effect:getPower());
end;