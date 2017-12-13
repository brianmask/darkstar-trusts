---------------------------------------------------
-- Wheeling Thrust
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
    local numhits = 1;
	local attmod = 2;
    local accmod = 1;
	local str_wsc = 0.50;
	local dex_wsc = 0;
	local agi_wsc = 0;
	local vit_wsc = 0;
	local mnd_wsc = 0;
    skill:setSkillchain(198); -- Fusion
	

	


	
	local info = AutoPhysicalMove(pet,target,skill,basemod,numhits,attmod,accmod,str_wsc,dex_wsc,agi_wsc,vit_wsc,mnd_wsc,TP_DMG_VARIES,4.25,4.25,4.25);
 
    local dmg = MobFinalAdjustments(info.dmg,pet,skill,target,MOBSKILL_PHYSICAL,MOBPARAM_PIERCE,info.hitslanded);
	
	local hits = automatonhitslanded;
	local firsthit = 0;
	local remaining = 0;
	local finaltp = 0;
	local duration = 90;
	
	-- if (target:hasStatusEffect(EFFECT_POISON) == false) then
       --  target:addStatusEffect(EFFECT_POISON, 1, 0, duration);
       -- end
	
	

	 
    

    target:delHP(dmg);

    return dmg;

end;




