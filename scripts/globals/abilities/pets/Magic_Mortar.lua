---------------------------------------------------
-- Magic Mortar
-- Deciding Maneuver: Fire
-- Skillchain Properties: Fusion/Liquification
-- Set the SC properties to Fusion Only for the time being
---------------------------------------------------

require("/scripts/globals/settings");
require("/scripts/globals/status");
require("/scripts/globals/automatonweaponskills");

---------------------------------------------------

function onMobSkillCheck(target,mob,skill)
    return 0;
end;

function onPetAbility(target, pet, skill)

    skill:setSkillchain(119);
    local numhits = 1;
    local accmod = 1;
    local dmgmod = 0.5;
	local currenthp = pet:getHP();
	local maxhp = pet:getMaxHP();
    local totaltp = skill:getTP();
	

    
	local tpmod = (((totaltp / 4) + 25) / 100);
 
    
	

    
	local dmg = ((maxhp - currenthp) * tpmod);

	
    target:delHP(dmg);
    return dmg;
end;




