-----------------------------------------
-- Spell: Indi-Refresh
-- Gradually restores target party member's MP
-- Composure increases duration 3x
-----------------------------------------

require("scripts/globals/status");
require("scripts/globals/pets");
require("scripts/globals/summon");

-----------------------------------------
-- OnSpellCast
-----------------------------------------

function onMagicCastingCheck(caster,target,spell)
	local result = 0;
	if(caster:hasPet()) then
      result = 1;
   elseif (not caster:canUsePet()) then
		result = MSGBASIC_CANT_BE_USED_IN_AREA;
    end

return 0;
end;

function onSpellCast(caster,target,spell)
    
	
--	local skill = caster:getSkillLevel(GEOMANCY_SKILL);
--	local mp = (skill / 93) + 1;

 --   target:addStatusEffectEx(EFFECT_GEO_REFRESH,EFFECT_REFRESH, mp, 3, 300);
    
--   return EFFECT_GEO_REFRESH;

caster:spawnPet(80);
-- caster:addMod(MOD_AVATAR_PERPETUATION, -7);
local skill = caster:getSkillLevel(GEOMANCY_SKILL);
local mp = (skill / 93) + 1;

local pet = caster:getPet();
local dot = caster:getMainLvl() / (-4);  
local luopanhp = caster:getMainLvl() * 0.60; 
local petlvl = caster:getMainLvl();
local disphp = pet:getHP();
local pos = target:getPos();

--if (pet ~= nill) then

-- pet:setModelId(2856);
pet:setPos(pos.x, pos.y, pos.z);
-- pet:addStatusEffectEx(EFFECT_GEO_REFRESH,EFFECT_REFRESH, mp, 3, 3000);
pet:addStatusEffect(EFFECT_BIND, 1, 0, 3000);
-- pet:addStatusEffect(EFFECT_MAX_HP_BOOST,luopanhp,0,0);
pet:addHP(5000);
-- pet:addMod(MOD_REGEN, dot);

 -- end	
--	caster:PrintToPlayer(disphp);	

	return 0;
	
end;