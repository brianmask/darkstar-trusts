---------------------------------------------------
-- True Strike
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
    local basemod = 2;
    local numhits = 1;
	local attmod = 2;
    local accmod = 1;
	local str_wsc = 1;
	local dex_wsc = 0;
	local agi_wsc = 0;
	local vit_wsc = 0;
	local mnd_wsc = 0;
    skill:setSkillchain(166);
	
	
	
	


	
	local info = AutoPhysicalMove(pet,target,skill,basemod,numhits,attmod,accmod,str_wsc,dex_wsc,agi_wsc,vit_wsc,mnd_wsc,TP_ACC_VARIES,0,40,80);
 
    local dmg = MobFinalAdjustments(info.dmg,pet,skill,target,MOBSKILL_PHYSICAL,MOBPARAM_PIERCE,info.hitslanded);
	
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




