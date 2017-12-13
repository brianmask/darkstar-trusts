---------------------------------------------------
-- Shield Bash (Hammermill)
-- Occasionally uses Shield Bash 
-- Damage proprotionate to automaton level
-- Chance of stun on bash
---------------------------------------------------

require("/scripts/globals/settings");
require("/scripts/globals/status");
require("/scripts/globals/monstertpmoves");

---------------------------------------------------

function onMobSkillCheck(target,mob,skill)
    return 0;
end;

function onPetAbility(target, pet, skill)
local duration = 0;
local lvldif = pet:getMainLvl() - target:getMainLvl();
local shielddmg = pet:getMainLvl() + 38;

local chance = 90;
   chance = chance + (lvldiff)*5;

    if (math.random()*100 < chance) then
        target:addStatusEffect(EFFECT_STUN,1,0,6);
    end


-- create damage 224 against TW at level 75
local ratio = pet:getStat(MOD_ATT)/target:getStat(MOD_DEF);
if (ratio > 2) then
	ratio = 2;
end
if (ratio < 0.2) then
	ratio = 0.2;
end

damage = shielddmg * ratio;

target:delHP(damage);
return damage;

end;
