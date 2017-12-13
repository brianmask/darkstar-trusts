---------------------------------------------------
-- Armor Piercer
-- Deals a ranged attack to a single target that ignores Defense
-- 100% TP - 1.0
-- 200% TP - 1.5
-- 300% TP - 3.0

-- TP Mods: DEX: 60%
---------------------------------------------------

require("/scripts/globals/settings");
require("/scripts/globals/status");
require("/scripts/globals/automatonweaponskills");

---------------------------------------------------

function onMobSkillCheck(target,mob,skill)
    return 0;
end;

function onPetAbility(target, pet, skill)
    local basemod = 1.2;
    local numhits = 1;
	local attmod = 1.5; -- Temporary Ignore defense by adding 50% attack
    local accmod = 100;
	local defignore = 0.50;
	local str_wsc = 0;
	local dex_wsc = 0.6;
	local agi_wsc = 0;
	local vit_wsc = 0;
	local mnd_wsc = 0;
	skill:setSkillchain(135);




	
    local info = AutoRangedMove(pet,target,skill,basemod,numhits,attmod,accmod,defignore,str_wsc,dex_wsc,agi_wsc,vit_wsc,mnd_wsc,TP_DMG_BONUS,4,5.5,7);
 
    local dmg = MobFinalAdjustments(info.dmg,pet,skill,target,MOBSKILL_RANGED,MOBPARAM_PIERCE,info.hitslanded);
	
	   if (dmg > 0) then
       target:addTP(2);
       pet:setTP(16);
    end
	

	
	
	

    target:delHP(dmg);
    return dmg;
end;
