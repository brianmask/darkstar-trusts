---------------------------------------------------
-- Hexa Strike
-- Trust: Kupipi
-- Deals sixfold damage.  Doesn't deal criticals yet 
-- Using Random in order to boost criticals.
-- Skillchain Properties: Fusion
---------------------------------------------------

require("/scripts/globals/settings");
require("/scripts/globals/status");
require("/scripts/globals/trustweaponskills");

---------------------------------------------------

function onMobSkillCheck(target,mob,skill)
    return 0;
end;

function onPetAbility(target, pet, skill)
    local basemod = 1;
    local numhits = 6;
	local attmod = 1;
    local accmod = 1;
	local str_wsc = 0.30;
	local dex_wsc = 0.30;
	local agi_wsc = 0;
	local vit_wsc = 0;
	local mnd_wsc = 0;
    skill:setSkillchain(168);
	
	local randcrit = math.random(1,4);
	local crit = (1 + (randcrit/100));
	


	
	local info = AutoPhysicalMove(pet,target,skill,basemod,numhits,attmod,accmod,str_wsc,dex_wsc,agi_wsc,vit_wsc,mnd_wsc,TP_ACC_VARIES,0,40,80);
 
    local dmg = MobFinalAdjustments(info.dmg,pet,skill,target,MOBSKILL_PHYSICAL,MOBPARAM_PIERCE,info.hitslanded);
	
	local hits = automatonhitslanded;
	local firsthit = 0;
	local remaining = 0;
	local finaltp = 0;
	
    dmg = dmg * crit;
	 
    

    target:delHP(dmg);
    return dmg;
end;




