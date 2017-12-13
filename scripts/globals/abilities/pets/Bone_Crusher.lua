---------------------------------------------------
-- Bone Crusher
-- Deals three hits to a single target
-- Damage Varries with TP
-- 100% TP - N/A
-- 200% TP - N/A
-- 300% TP - N/A

-- TP Mods unknown
-- VIT 60%
-- Skillchain Properties: Scission
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
    local numhits = 3;
	local attmod = 1;
    local accmod = 0;
	local str_wsc = 0;
	local dex_wsc = 0;
	local agi_wsc = 0;
	local vit_wsc = 0.60;
	local mnd_wsc = 0;
    skill:setSkillchain(24);
	


	
	local info = AutoPhysicalMove(pet,target,skill,basemod,numhits,attmod,accmod,str_wsc,dex_wsc,agi_wsc,vit_wsc,mnd_wsc,TP_DMG_BONUS,2.66,2.66,2.66);
 
    local dmg = MobFinalAdjustments(info.dmg,pet,skill,target,MOBSKILL_PHYSICAL,MOBPARAM_SLASH,info.hitslanded);
	
	   if (dmg > 0) then
       target:addTP(2);
       pet:setTP(10);
    end
	target:addStatusEffect(EFFECT_STUN, 1, 0, 4);

    target:delHP(dmg);
    return dmg;
end;
