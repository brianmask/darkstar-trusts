---------------------------------------------------
-- Ranged Attack
-- Deals a ranged attack to a single target.
-- Dex causes extra damage as noted by using Thunder maneuver
-- 
---------------------------------------------------

require("/scripts/globals/settings");
require("/scripts/globals/status");
require("/scripts/globals/automatonweaponskills");

---------------------------------------------------

function onMobSkillCheck(target,mob,skill)
    return 0;
end;

function onPetAbility(target, pet, skill)
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
	
	   if (dmg > 0) then
       target:addTP(2);
       pet:addTP(16);
    end

    target:delHP(dmg);
    return dmg;

end;
