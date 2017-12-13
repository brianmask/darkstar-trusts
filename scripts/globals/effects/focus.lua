-----------------------------------
--
-- 	EFFECT_FOCUS
-- 	
-----------------------------------

require("scripts/globals/status");

-----------------------------------
-- onEffectGain Action
-----------------------------------

function onEffectGain(target,effect)
   target:addMod(MOD_ACC,effect:getPower());
   local activeboost = target:getVar("MNKBoostNumber");
   if (activeboost >= 1) then
   local maboost = activeboost * 7;
   local strboost = activeboost * 3.5;
   target:addMod(MOD_MARTIAL_ARTS,maboost);
   target:addMod(MOD_STR,strboost);
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
   target:delMod(MOD_ACC,effect:getPower());
   local activeboost = target:getVar("MNKBoostNumber");   
   if (activeboost >= 1) then
   local maboost = activeboost * 7;
   local strboost = activeboost * 3.5;
   target:delMod(MOD_MARTIAL_ARTS,maboost);
   target:delMod(MOD_STR,strboost);
   end
   target:setVar("MNKBoostNumber",0);

end;