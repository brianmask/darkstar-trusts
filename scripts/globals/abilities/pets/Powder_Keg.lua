---------------------------------------------------
-- Powder Keg
-- Skillchain Properties: Fragmentation/Distortion
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
    local numhits = 1;
	local attmod = 1.5;
    local accmod = 1;
	local str_wsc = 0.60;
	local dex_wsc = 0;
	local agi_wsc = 0;
	local vit_wsc = 0;
	local mnd_wsc = 0;
    skill:setSkillchain(34);
	local player = pet:getMaster();
	
	
	

	local info = AutoPhysicalMove(pet,target,skill,basemod,numhits,attmod,accmod,str_wsc,dex_wsc,agi_wsc,vit_wsc,mnd_wsc,TP_DMG_BONUS,1.75,2.25,2.50);
 
    local dmg = MobFinalAdjustments(info.dmg,pet,skill,target,MOBSKILL_PHYSICAL,MOBPARAM_PIERCE,info.hitslanded);
	
	local hits = automatonhitslanded;
	local firsthit = 0;
	local remaining = 0;
	local finaltp = 0;
	target:addStatusEffect(EFFECT_DEFENSE_DOWN, 15, 0, 60);
	target:addStatusEffect(EFFECT_MAGIC_DEF_DOWN, 15, 0, 60);

    target:delHP(dmg);
    return dmg;
end;




