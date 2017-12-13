-----------------------------------------
-- Spell: ThunderSpirit
-- Summons ThunderSpirit to fight by your side
-----------------------------------------

require("scripts/globals/pets");
require("scripts/globals/summon");
require("scripts/globals/bcnm");

-----------------------------------------
-- OnSpellCast
-----------------------------------------

function onMagicCastingCheck(caster,target,spell)
	local result = 0;
	if (target:getObjType() == TYPE_PC) and (caster:hasStatusEffect(EFFECT_ASTRAL_FLOW)) then
	    result = MSGBASIC_CANNOT_ATTACK_TARGET;
    else if (caster:getObjType() == TYPE_PC) then
		result = avatarMiniFightCheck(caster);
	elseif (caster:hasPet()) then
        result = 1;
    elseif (not caster:canUsePet()) then
		result = MSGBASIC_CANT_BE_USED_IN_AREA;
        end
		end
	return result;
end;



function onSpellCast(caster,target,spell)
if (caster:getObjType() == TYPE_PC) then
local ixion = caster:getVar("DarkIxionWin");
    
	if (caster:hasStatusEffect(EFFECT_ASTRAL_FLOW) == true) and (ixion == 1) then
	caster:PrintToPlayer("Dark Ixion: You dare summon me...?  I shall honor thy pact at a price...",0x0D);
	caster:spawnPet(84);
	caster:petAttack(target);
	else
	caster:spawnPet(PET_THUNDER_SPIRIT);

    end
else
	caster:spawnPet(PET_THUNDER_SPIRIT);
end



	return 0;
end;
