---------------------------------------------------
-- Happobarai
-- Deciding Maneuver: Fire
-- Recover HP equal to damage dealth.  Damage varries with TP.  
-- HP recovery ineffective against undead
-- Skillchain Properties: Compression/Reverberation
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
    local numhits = 3;
	local attmod = 1.25;
    local accmod = 1;
	local str_wsc = 0.50;
	local dex_wsc = 0.50;
	local agi_wsc = 0;
	local vit_wsc = 0;
	local mnd_wsc = 0;
    skill:setSkillchain(152);
	
	
	
	


	
	local info = AutoPhysicalMove(pet,target,skill,basemod,numhits,attmod,accmod,str_wsc,dex_wsc,agi_wsc,vit_wsc,mnd_wsc,TP_DMG_BONUS,1.5,2.0,3.0);
 
    local dmg = MobFinalAdjustments(info.dmg,pet,skill,target,MOBSKILL_PHYSICAL,MOBPARAM_PIERCE,info.hitslanded);
	
	target:addStatusEffect(EFFECT_POISON, 10, 3, 30);
    

    target:delHP(dmg);
    return dmg;
end;




