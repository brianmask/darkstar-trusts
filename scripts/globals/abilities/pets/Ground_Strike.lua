---------------------------------------------------
-- Ground Strike
-- Damage Varries with TP 
-- Skillchain Properties: Using Distortion 
---------------------------------------------------

require("/scripts/globals/settings");
require("/scripts/globals/status");
require("/scripts/globals/trustweaponskills");

---------------------------------------------------

function onMobSkillCheck(target,mob,skill)
    return 0;
end;

function onPetAbility(target, pet, skill)
    local basemod = 1.0;
    local numhits = 1;
	local attmod = 1.2;
    local accmod = 1;
	local str_wsc = 0.50;
	local dex_wsc = 0;
	local agi_wsc = 0;
	local vit_wsc = 0.50;
	local mnd_wsc = 0;
    skill:setSkillchain(151);
	
	
	
	


	
	local info = AutoPhysicalMove(pet,target,skill,basemod,numhits,attmod,accmod,str_wsc,dex_wsc,agi_wsc,vit_wsc,mnd_wsc,TP_DMG_BONUS,2.0,2.25,3.0);
 
    local dmg = MobFinalAdjustments(info.dmg,pet,skill,target,MOBSKILL_PHYSICAL,MOBPARAM_SLASH,info.hitslanded);
	
	local hits = automatonhitslanded;
	local firsthit = 0;
	local remaining = 0;
	local finaltp = 0;
	
	   if (dmg > 0) then
       target:addTP(2);
	   if (hits > 1) then
	   remaining = hits - 1;
	   finaltp = (8.3 + remaining);
       pet:setTP(finaltp);
	   elseif (hits == 1) then
	   pet:setTP(8);
	   end
	   end
	 
    

    target:delHP(dmg);
    return dmg;
end;




