-----------------------------------
--
-- 	EFFECT_LAST_RESORT
-- 	
-----------------------------------

require("scripts/globals/status");

-----------------------------------
-- onEffectGain Action
-----------------------------------

function onEffectGain(target,effect)
    local level = target:getMainLvl();
	if (target:getObjType() == TYPE_PC) then
	local lsmp = target:getVar("LastResortLevelMod");
	local mppower = (math.floor(lsmp / 18) + 1);
	end
	-- local mppower = (level / 18) + 1;
	lastresortpercentage = 0;
	target:addMod(MOD_ATTP,25 + target:getMerit(MERIT_LAST_RESORT_EFFECT));
	target:addMod(MOD_DEFP,-5);
	target:addMod(MOD_HASTE_ABILITY, 156+effect:getPower())
	target:addMod(MOD_FASTCAST, 10);
	lastresortpercentage = target:getMP() / target:getMaxMP();

	
end;

-----------------------------------
-- onEffectTick Action
-----------------------------------

function onEffectTick(target,effect)
local currentmp = target:getMP();
local maxmp = target:getMaxMP();
local percent = (currentmp / maxmp);
local diffnum = percent - lastresortpercentage;  -- difference between activated mp and current on tick 
local removedef = (1 - lastresortpercentage);
local removebuff = 25 * removedef;
local newdecay = 0;



local multiplier = (1 - percent);
local defbuff = 25 * multiplier;
if (diffnum == 0) then
newdecay = 0;
else
newdecay = defbuff;
end

if (diffnum ~= 0) or (newdecay ~= 0) then
target:delMod(MOD_DEFP, -removebuff);
target:addMod(MOD_DEFP, -newdecay);
end
-- target:PrintToPlayer(removebuff);
-- target:PrintToPlayer(newdecay);
lastresortpercentage = percent; -- Store current percent on the tick to a new number
end;

-----------------------------------
-- onEffectLose Action
-----------------------------------

function onEffectLose(target,effect)
	if (target:getObjType() == TYPE_PC) then
	local lsmp = target:getVar("LastResortLevelMod");
	local mppower = math.floor(lsmp / 18) + 1;
	end

	local currentmp = target:getMP();
    local maxmp = target:getMaxMP();
    local percent = (currentmp / maxmp);
    local multiplier = (1 - percent);
    local defbuff = 20 * multiplier;
    local newdecay = (-5 - defbuff);
	target:delMod(MOD_ATTP,25 + target:getMerit(MERIT_LAST_RESORT_EFFECT));
	target:delMod(MOD_DEFP,newdecay);
	target:delMod(MOD_HASTE_ABILITY, 156+effect:getPower())
	target:delMod(MOD_FASTCAST, 10);

	
end;