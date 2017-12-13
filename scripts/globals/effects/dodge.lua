-----------------------------------
--
-- 	EFFECT_DODGE
-- 	
-----------------------------------

require("scripts/globals/status");

-----------------------------------
-- onEffectGain Action
-----------------------------------

function onEffectGain(target,effect)
	target:addMod(MOD_EVA,effect:getPower());
	local activeboost = target:getVar("MNKBoostNumberDodge");
    if (activeboost >= 1) then
    local gboost = activeboost * 4;
    local cboost = activeboost * 3;
	target:addMod(MOD_COUNTER,cboost);
	target:addMod(MOD_GUARD,gboost);
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
	target:delMod(MOD_EVA,effect:getPower());
	local activeboost = target:getVar("MNKBoostNumberDodge");
    if (activeboost >= 1) then
    local gboost = activeboost * 4;
    local cboost = activeboost * 3;
	target:delMod(MOD_COUNTER,cboost);
	target:delMod(MOD_GUARD,gboost);
    end
	target:setVar("MNKBoostNumberDodge",0);
end;