---------------------------------------------------
-- Knockout
-- Single Hit Damage that Varies with TP
-- Additional Effect - Evasion Down (-10 for 30 seconds)
-- Damage Bonus - 500%
-- 100% TP - 1.0
-- 200% TP - 2.5
-- 300% TP - 5.0

-- TP Mods unknown
-- AGI: 100%
-- Source: http://www.bluegartr.com/threads/112776-Dev-Tracker-Findings-Posts-(NO-DISCUSSION)?p=6503970&viewfull=1#post6503970

---------------------------------------------------

require("/scripts/globals/settings");
require("/scripts/globals/status");
require("/scripts/globals/automatonweaponskills");

---------------------------------------------------

function onMobSkillCheck(target,mob,skill)
    return 0;
end;

function onPetAbility(target, pet, skill)
    local basemod = 5;
    local numhits = 1;
	local attmod = 1;
    local accmod = 50;
	local str_wsc = 0;
	local dex_wsc = 0;
	local agi_wsc = 1;
	local vit_wsc = 0;
	local mnd_wsc = 0;	
	skill:setSkillchain(148);
	
	
	
	


	
	local info = AutoPhysicalMove(pet,target,skill,basemod,numhits,attmod,accmod,str_wsc,dex_wsc,agi_wsc,vit_wsc,mnd_wsc,TP_DMG_BONUS,1,2.5,5);
 
    local dmg = MobFinalAdjustments(info.dmg,pet,skill,target,scattr,MOBSKILL_PHYSICAL,MOBPARAM_BLUNT,info.hitslanded);
	
	
	
	   if (dmg > 0) then
       target:addTP(2);
	   pet:setTP(8);
	   end

	 
    
    target:addStatusEffect(EFFECT_EVASION_DOWN, 10, 0, 30);
    target:delHP(dmg);
    return dmg;
end;
