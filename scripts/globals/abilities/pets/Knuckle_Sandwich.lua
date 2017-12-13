---------------------------------------------------
-- Knucle Sandwhich
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
    local basemod = 1;
    local numhits = 1;
	local attmod = 2;
    local accmod = 1;
	local str_wsc = 0.50;
	local dex_wsc = .20;
	local agi_wsc = 0;
	local vit_wsc = 0;
	local mnd_wsc = 0;
    skill:setSkillchain(72);
	local player = pet:getMaster();
    local lion = player:getVar("LionPT");	
	
	


	
	local info = AutoPhysicalMove(pet,target,skill,basemod,numhits,attmod,accmod,str_wsc,dex_wsc,agi_wsc,vit_wsc,mnd_wsc,TP_DMG_BONUS,2.25,3.0,4.0);
 
    local dmg = MobFinalAdjustments(info.dmg,pet,skill,target,MOBSKILL_PHYSICAL,MOBPARAM_BLUNT,info.hitslanded);
	
	local hits = automatonhitslanded;
	local firsthit = 0;
	local remaining = 0;
	local finaltp = 0;
	
	
    if (lion == 1) then
	player:PrintToPlayer("(Prishe) Okay Lion, let's give them hell!", 0xF);
    player:setVar("PrisheSC",2);	
	else
	player:PrintToPlayer("(Prishe) Time for a taste of knuckle sandwhich a la Prishe!", 0xF);
    end	
    

    target:delHP(dmg);
    return dmg;
end;




