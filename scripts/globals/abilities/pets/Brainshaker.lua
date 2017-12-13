---------------------------------------------------
-- Brain Shaker
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
	local str_wsc = 1.0;
	local dex_wsc = 0;
	local agi_wsc = 0;
	local vit_wsc = 0;
	local mnd_wsc = 0;
    skill:setSkillchain(52);
	

	
	


	
	local info = AutoPhysicalMove(pet,target,skill,basemod,numhits,attmod,accmod,str_wsc,dex_wsc,agi_wsc,vit_wsc,mnd_wsc,TP_DMG_BONUS,1.5,1.5,1.5);
 
    local dmg = MobFinalAdjustments(info.dmg,pet,skill,target,MOBSKILL_PHYSICAL,MOBPARAM_BLUNT,info.hitslanded);
	

	
	   if (dmg > 0) then
	   local duration = (1000/500);
        if (target:hasStatusEffect(EFFECT_STUN) == false) then
            target:addStatusEffect(EFFECT_STUN, 1, 0, duration);
        end
		end
	   
	 
    

    target:delHP(dmg);
    return dmg;
end;




