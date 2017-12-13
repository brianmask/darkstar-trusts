-----------------------------------
--
-- 	EFFECT_SIGNET
--
--   Signet is a a beneficial Status Effect that allows the acquisition of Conquest Points and Crystals 
--   from defeated enemies that grant Experience Points.

--   Increased Healing HP
--   No TP loss while resting
--   Bonus experience earned in smaller parties
-- X Increased defense and evasion against attacks from your auto-attack target 
-----------------------------------

require("scripts/globals/status");

-----------------------------------
-- onEffectGain Action
-----------------------------------

function onEffectGain(target,effect)
    if (target:getObjType() == TYPE_PC) then
    local level = target:getMainLvl();
	if (level < 49) then
	target:setVar("SignetBoost",2);
	else if (level < 99) then
	target:setVar("SignetBoost",5);
	end
	end
	local modboost = target:getVar("SignetBoost");
	local regain = modboost * 1;
	target:addMod(MOD_DEF,15);
	target:addMod(MOD_EVA,15);
	target:addMod(MOD_REFRESH,modboost);
	target:addMod(MOD_REGEN,modboost);
	target:addMod(MOD_REGAIN,regain);
	end
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
    if (target:getObjType() == TYPE_PC) then
    local modboost = target:getVar("SignetBoost");
	local regain = modboost * 1;
	target:delMod(MOD_DEF,15);
	target:delMod(MOD_EVA,15);
	target:addMod(MOD_REFRESH,modboost);
	target:addMod(MOD_REGEN,modboost);
	target:addMod(MOD_REGAIN,regain);
	end
end;