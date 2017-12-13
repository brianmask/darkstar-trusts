---------------------------------------------------
-- Barrage Turbine
-- Deals multiple ranged attacks at once based
-- on maneuvers present
---------------------------------------------------

require("/scripts/globals/settings");
require("/scripts/globals/status");
require("/scripts/globals/automatonweaponskills");

---------------------------------------------------

function onMobSkillCheck(target,mob,skill)
    return 0;
end;

function onPetAbility(target, pet, skill)
local barrage = 0;
local player = pet:getMaster();
local wind = player:getEffectsCount(EFFECT_WIND_MANEUVER);
if (wind == 1) then
barrage = 3;
elseif (wind == 2) then
barrage = 4;
elseif (wind == 3) then
barrage = 5;
else
barrage = 1;
end
player:PrintToPlayer(barrage);



    local basemod = 1;
    local numhits = 1;
	local attmod = 1;
    local accmod = 0;
	local defignore = 1;
	local str_wsc = 0;
	local dex_wsc = 0.75;
	local agi_wsc = 0;
	local vit_wsc = 0;
	local mnd_wsc = 0;

	
	local info = AutoRangedMove(pet,target,skill,basemod,numhits,attmod,accmod,defignore,str_wsc,dex_wsc,agi_wsc,vit_wsc,mnd_wsc,TP_NO_EFFECT,1,1,1);
 
    local dmg = MobFinalAdjustments(info.dmg,pet,skill,target,MOBSKILL_RANGED,MOBPARAM_PIERCE,info.hitslanded);
    
	local hits = barrage;
	local finaltp = 0;
	local mobtp = hits * 2;
	
	   if (dmg > 0) then
	   if (hits > 1) then
	   finaltp = (hits * 16);
       pet:setTP(finaltp);
	   target:addTP(mobtp);
	   elseif (hits == 1) then
	   pet:setTP(16);
	   target:addTP(2);
	   end
	   end
	
	dmg = dmg * barrage;
	
	if (wind == 1) then
	player:delStatusEffect(EFFECT_WIND_MANEUVER);
	elseif (wind == 2) then
	player:delStatusEffect(EFFECT_WIND_MANEUVER);
	player:delStatusEffect(EFFECT_WIND_MANEUVER);
    elseif (wind == 3) then
	player:delStatusEffect(EFFECT_WIND_MANEUVER);
	player:delStatusEffect(EFFECT_WIND_MANEUVER);
	player:delStatusEffect(EFFECT_WIND_MANEUVER);
    end
	
    target:delHP(dmg);
    return dmg;
end;
