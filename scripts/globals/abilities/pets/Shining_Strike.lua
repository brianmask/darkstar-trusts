---------------------------------------------------
-- Shining STrike
-- Skillchain Properties: Impaction
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
	local attmod = 1.0;
    local accmod = 1;
	local str_wsc = 0.40;
	local dex_wsc = 0;
	local agi_wsc = 0;
	local vit_wsc = 0;
	local mnd_wsc = 0.40;
    skill:setSkillchain(1);
	
	
	
	


	
	local info = AutoPhysicalMove(pet,target,skill,basemod,numhits,attmod,accmod,str_wsc,dex_wsc,agi_wsc,vit_wsc,mnd_wsc,TP_DMG_BONUS,1.6,3.0,4.65);
 
    local dmg = MobFinalAdjustments(info.dmg,pet,skill,target,MOBSKILL_PHYSICAL,MOBPARAM_BLUNT,info.hitslanded);
	
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




