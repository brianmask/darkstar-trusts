-----------------------------------------
-- Spell: LightSpirit
-- Summons LightSpirit to fight by your side
-----------------------------------------

require("scripts/globals/pets");
require("scripts/globals/summon");
require("scripts/globals/bcnm");

-----------------------------------------
-- OnSpellCast
-----------------------------------------

function onMagicCastingCheck(caster,target,spell)
	local result = 0;
	if (target:getObjType() == TYPE_MOB) and (caster:hasStatusEffect(EFFECT_ASTRAL_FLOW)) then
	    result = MSGBASIC_CANNOT_ATTACK_TARGET;	
    elseif (caster:getObjType() == TYPE_PC) then
		result = avatarMiniFightCheck(caster);
	elseif (caster:hasPet()) then
        result = 1;
    elseif (not caster:canUsePet()) then
		result = MSGBASIC_CANT_BE_USED_IN_AREA;
	else if (target:getObjType() == TYPE_PC) and (caster:hasStatusEffect(EFFECT_ASTRAL_FLOW) == true) then
	    result = 1;
		end
		end
	return result;
end;

function onSpellCast(caster,target,spell)
if (caster:getObjType() == TYPE_PC) then
local ixion = caster:getVar("IxionWin");

if (caster:hasStatusEffect(EFFECT_ASTRAL_FLOW) == true) and (ixion == 1) then
	caster:spawnPet(85);
	caster:petAttack(target);
	caster:PrintToPlayer("Ixion: I shall honor thy Light Spirit Pact.",0x0D);
	else
	caster:spawnPet(PET_LIGHT_SPIRIT);

    end
else
    caster:spawnPet(PET_LIGHT_SPIRIT);
end		
    
	

	
	return 0;
end;