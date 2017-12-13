---------------------------------------------------
-- Cannibal Blade
-- Deciding Maneuver: Fire
-- Recover HP equal to damage dealth.  Damage varries with TP.  
-- HP recovery ineffective against undead
-- Skillchain Properties: Compression/Reverberation
---------------------------------------------------

require("/scripts/globals/settings");
require("/scripts/globals/status");
require("/scripts/globals/automatonweaponskills");

---------------------------------------------------

function onMobSkillCheck(target,mob,skill)
    return 0;
end;

function onPetAbility(target, pet, skill)
    local basemod = 15
    local numhits = 1;
	local attmod = 1;
    local accmod = 0;
	local str_wsc = 0;
	local dex_wsc = 0;
	local agi_wsc = 0;
	local vit_wsc = 0;
	local mnd_wsc = 1;
    skill:setSkillchain(179);
    
	
	
    local info = AutoPhysicalMove(pet,target,skill,basemod,numhits,attmod,accmod,str_wsc,dex_wsc,agi_wsc,vit_wsc,mnd_wsc,TP_DMG_BONUS,0.75,1,1.25);
 
    local dmg = MobFinalAdjustments(info.dmg,pet,skill,target,MOBSKILL_PHYSICAL,MOBPARAM_SLASH,info.hitslanded);
	
    if (dmg > 0) then
    target:addTP(2);
    pet:setTP(10);
	end
    
    if (target:isUndead() == false) then
        target:delHP(dmg);
        pet:addHP(dmg);
        skill:setMsg(MSG_DRAIN_HP);
    else
        skill:setMsg(MSG_NO_EFFECT);
    end
    return dmg;
end;




