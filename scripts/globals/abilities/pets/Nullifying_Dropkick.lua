---------------------------------------------------
-- Nullifying Dropkick
-- Skillchain Properties: Fragmentation/Scission
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
	local str_wsc = 0.75;
	local dex_wsc = 0;
	local agi_wsc = 0;
	local vit_wsc = 0;
	local mnd_wsc = 0;
    skill:setSkillchain(42);
	local player = pet:getMaster();
    local lion = player:getVar("LionPT");
    local lionsc = player:getVar("LionSC");	
	
	


	
	local info = AutoPhysicalMove(pet,target,skill,basemod,numhits,attmod,accmod,str_wsc,dex_wsc,agi_wsc,vit_wsc,mnd_wsc,TP_DMG_BONUS,2.25,2.75,3.0);
 
    local dmg = MobFinalAdjustments(info.dmg,pet,skill,target,MOBSKILL_PHYSICAL,MOBPARAM_BLUNT,info.hitslanded);
	
	local hits = automatonhitslanded;
	local firsthit = 0;
	local remaining = 0;
	local finaltp = 0;
    if ((lion == 1) and (lionsc == 1)) then
	player:PrintToPlayer("(Prishe) Prepare yourself for the Nullyfying Grapeshot!!", 0xF);
    player:setVar("PrisheSC",2);	
	else
	player:PrintToPlayer("(Prishe) This is going to hurt you more than me!", 0xF);
    end		
	  
    

    target:delHP(dmg);
    return dmg;
end;




