---------------------------------------------------
-- Grapeshot
-- Skillchain Properties: Distortion/Scission
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
    local numhits = 3;
	local attmod = 1;
    local accmod = 1;
	local str_wsc = 0.60;
	local dex_wsc = 0;
	local agi_wsc = 0;
	local vit_wsc = 0;
	local mnd_wsc = 0;
    skill:setSkillchain(104);
	local player = pet:getMaster();
    local prishe = player:getVar("PrishePT");
    local prishesc = player:getVar("PrisheSC");	
	
	
	


	
	local info = AutoPhysicalMove(pet,target,skill,basemod,numhits,attmod,accmod,str_wsc,dex_wsc,agi_wsc,vit_wsc,mnd_wsc,TP_DMG_BONUS,1.5,1.5,1.5);
 
    local dmg = MobFinalAdjustments(info.dmg,pet,skill,target,MOBSKILL_PHYSICAL,MOBPARAM_PIERCE,info.hitslanded);
	
	local hits = automatonhitslanded;
	local firsthit = 0;
	local remaining = 0;
	local finaltp = 0;
	target:addStatusEffect(EFFECT_STUN, 1, 0, 5);  
	
    if ((prishe == 1) and (prishesc == 5)) then
	player:PrintToPlayer("(Lion) This should do it!", 0xF); 
	player:setVar("PrisheSC",3);
	player:setVar("LionSC",0);
    end		

    target:delHP(dmg);
    return dmg;
end;




