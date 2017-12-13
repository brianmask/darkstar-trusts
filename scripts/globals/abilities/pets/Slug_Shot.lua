---------------------------------------------------
-- Armor Piercer
-- Deals a ranged attack to a single target that ignores Defense
-- 100% TP - 1.0
-- 200% TP - 1.5
-- 300% TP - 3.0

-- TP Mods: DEX: 60%
---------------------------------------------------

require("/scripts/globals/settings");
require("/scripts/globals/status");
require("/scripts/globals/automatonweaponskills");

---------------------------------------------------

function onMobSkillCheck(target,mob,skill)
    return 0;
end;

function onPetAbility(target, pet, skill)
    local basemod = 1;
    local numhits = 1;
	local attmod = 1; -- Temporary Ignore defense by adding 50% attack
    local accmod = 1;
	local defignore = 0;
	local str_wsc = 0;
	local dex_wsc = 0;
	local agi_wsc = 0.70;
	local vit_wsc = 0;
	local mnd_wsc = 0;
	skill:setSkillchain(135);




	
    local info = AutoRangedMove(pet,target,skill,basemod,numhits,attmod,accmod,defignore,str_wsc,dex_wsc,agi_wsc,vit_wsc,mnd_wsc,TP_DMG_BONUS,1,1,1);
 
    local dmg = MobFinalAdjustments(info.dmg,pet,skill,target,MOBSKILL_RANGED,MOBPARAM_PIERCE,info.hitslanded);
	

	

	
	
	

    target:delHP(dmg);
    return dmg;
end;
