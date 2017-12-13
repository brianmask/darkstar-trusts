-----------------------------------
--
-- EFFECT_AFTERMATH_LV1
--
-----------------------------------
require("scripts/globals/status");
-----------------------------------
-- onEffectGain Action
-----------------------------------

function onEffectGain(target,effect)
	local power = effect:getPower(); 
	if (effect:getSubPower() == 1) then
		target:addMod(MOD_ACC,power);
	elseif (effect:getSubPower() == 2) then
		target:addMod(MOD_MACC,power)
	elseif (effect:getSubPower() == 3) then
		target:addMod(MOD_RACC,power) 
	elseif (effect:getSubPower() == 13) then -- High Artifacts
		target:addMod(MOD_ALL_WSDMG_ALL_HITS,power)
		target:addMod(MOD_REGAIN,15)		
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
	local power = effect:getPower(); 
	if (effect:getSubPower() == 1) then
		target:delMod(MOD_ACC,power);
	elseif (effect:getSubPower() == 2) then
		target:delMod(MOD_MACC,power)
	elseif (effect:getSubPower() == 3) then
		target:delMod(MOD_RACC,power) 
	elseif (effect:getSubPower() == 13) then  -- High Artifact 
		target:delMod(MOD_ALL_WSDMG_ALL_HITS,power)
        target:delMod(MOD_REGAIN, 15)			
	end
end;