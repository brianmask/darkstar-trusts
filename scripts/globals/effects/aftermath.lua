-----------------------------------
--
-- EFFECT_AFTERMATH
--
-----------------------------------
require("scripts/globals/status");
-----------------------------------
-- onEffectGain Action
-----------------------------------

-- 1. Spharai
-- 2. Mandau
-- 3. Excalibur



function onEffectGain(target,effect)
	local power = effect:getPower(); 
	if (effect:getSubPower() == 1) then -- H2H
		target:addMod(MOD_SUBTLE_BLOW,power);
		target:addMod(MOD_KICK_ATTACK,5)
	elseif (effect:getSubPower() == 2) then -- Dagger
		target:addMod(MOD_CRITHITRATE,power)
		target:addMod(MOD_CRIT_DMG_INCREASE,1)
	elseif (effect:getSubPower() == 3) then -- Sword
		target:addMod(MOD_REGEN,power) 
		target:addMod(MOD_REFRESH,1)
	elseif (effect:getSubPower() == 4) then -- Axe
		target:addMod(MOD_ATTP,power)
	elseif (effect:getSubPower() == 5) then -- Great Axe
		target:addMod(MOD_DMG,power)		
		target:addMod(MOD_REGEN,5) 
	elseif (effect:getSubPower() == 6) then -- Scythe
		target:addMod(MOD_HASTE_GEAR,power)
		target:addMod(MOD_ACC,5)
	elseif (effect:getSubPower() == 7) then -- DRG
		target:addMod(MOD_ATTP, 1)
		target:addMod(MOD_DOUBLE_ATTACK,1)
		target:addMod(MOD_SPIKES,5)
		target:addMod(MOD_SPIKES_DMG,power)
	elseif (effect:getSubPower() == 8) then -- GKTA
		target:addMod(MOD_STORETP,power)
		target:addMod(MOD_ZANSHIN,3)
	elseif (effect:getSubPower() == 9) then -- Club
		target:addMod(MOD_ACC,power)
		target:addMod(MOD_MACC,20)
		target:addMod(MOD_REFRESH,1)
	elseif (effect:getSubPower() == 10) then
		target:addMod(MOD_REFRESH,power) -- Staff
		target:addMod(MOD_DMG,-7)
	elseif (effect:getSubPower() == 11) then
		target:addMod(MOD_ENMITY,power)
	elseif (effect:getSubPower() == 12) then
		target:addMod(MOD_RACC,power)
	elseif (effect:getSubPower() == 13) then -- HA WAR
		-- Nothing
       
	elseif (effect:getSubPower() == 15) then -- HA WHM		
       -- Nothing
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
	if (effect:getSubPower() == 1) then -- H2H
		target:delMod(MOD_SUBTLE_BLOW,power);
		target:delMod(MOD_KICK_ATTACK,5)	
	elseif (effect:getSubPower() == 2) then -- Dagger
		target:delMod(MOD_CRITHITRATE,power)
		target:delMod(MOD_CRIT_DMG_INCREASE,1)
	elseif (effect:getSubPower() == 3) then -- Sword
		target:delMod(MOD_REGEN,power)
        target:delMod(MOD_REFRESH,1)		
	elseif (effect:getSubPower() == 4) then
		target:delMod(MOD_ATTP,power)
	elseif (effect:getSubPower() == 5) then
		target:delMod(MOD_DMG,power) -- Great Axe
        target:delMod(MOD_REGEN,5) 
	elseif (effect:getSubPower() == 6) then -- Scythe
		target:delMod(MOD_HASTE_GEAR,power)
	    target:delMod(MOD_ACC,5)
	elseif (effect:getSubPower() == 7) then  -- Polearm
		target:delMod(MOD_ATTP, 1);
		target:delMod(MOD_DOUBLE_ATTACK,1);
		target:delMod(MOD_SPIKES,5);
		target:delMod(MOD_SPIKES_DMG,power)
	elseif (effect:getSubPower() == 8) then -- GKTA
		target:delMod(MOD_STORETP,power)
		target:delMod(MOD_ZANSHIN,3)
	elseif (effect:getSubPower() == 9) then -- CLUB
		target:delMod(MOD_ACC,power)
		target:delMod(MOD_MACC,20)
		target:delMod(MOD_REFRESH,1)		
	elseif (effect:getSubPower() == 10) then -- Staff
		target:delMod(MOD_REFRESH,power)
		target:delMod(MOD_DMG,-7)		
	elseif (effect:getSubPower() == 11) then
		target:delMod(MOD_ENMITY,power)
	elseif (effect:getSubPower() == 12) then
		target:delMod(MOD_RACC,power)
	elseif (effect:getSubPower() == 13) then  -- HA WAR
		target:delMod(MOD_REGAIN,power)
        target:delMod(MOD_STR, 11);	
	elseif (effect:getSubPower() == 15) then -- HA WHM
		target:delMod(MOD_REGAIN,power)
        target:delMod(MOD_MND, 10);	
        target:delMod(MOD_MAIN_DMG_RATING, 6); 		
		target:delMod(MOD_CURE_CAST_TIME, 15);				
	end
end;