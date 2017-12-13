-----------------------------------
--
-- 	EFFECT_REFRESH_DOWN
--
-----------------------------------

require("scripts/globals/status");

-----------------------------------
-- onEffectGain Action
-----------------------------------

function onEffectGain(target,effect)
    local level = target:getMainLvl();
	target:setVar("LastResortLevelMod",level);
	local lsmp = target:getVar("LastResortLevelMod");
	local mppower = (math.floor(lsmp / 15) + 1);
	target:addMod(MOD_REFRESH_DOWN, mppower);
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
    local level = target:getMainLvl();
	
	local lsmp = target:getVar("LastResortLevelMod");
	local mppower = (math.floor(lsmp / 15) + 1);

	target:delMod(MOD_REFRESH_DOWN, mppower);

end;