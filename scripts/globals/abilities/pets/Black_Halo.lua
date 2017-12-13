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
    local numhits = 2;
	local attmod = 1;
    local accmod = 1;
	local str_wsc = 0.30;
	local dex_wsc = 0;
	local agi_wsc = 0;
	local vit_wsc = 0;
	local mnd_wsc = 0.70;
    skill:setSkillchain(198);
	

	


	
	local info = AutoPhysicalMove(pet,target,skill,basemod,numhits,attmod,accmod,str_wsc,dex_wsc,agi_wsc,vit_wsc,mnd_wsc,TP_DMG_BONUS,1.5,2,3);
 
    local dmg = MobFinalAdjustments(info.dmg,pet,skill,target,MOBSKILL_PHYSICAL,MOBPARAM_BLUNT,info.hitslanded);
	
	local hits = automatonhitslanded;
	local firsthit = 0;
	local remaining = 0;
	local finaltp = 0;
	
    dmg = dmg;
	 
    

    target:delHP(dmg);
    return dmg;
end;




