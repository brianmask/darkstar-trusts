-----------------------------------------
-- Spell: Abienzo NIN

-----------------------------------------

require("scripts/globals/pets");
require("scripts/globals/summon");

-----------------------------------------
-- OnSpellCast
-----------------------------------------

function onMagicCastingCheck(caster,target,spell)
    local zone = caster:getZoneID();
	if (zone == 185) or (zone == 186) or (zone == 187) then
	caster:PrintToPlayer("You cannot summon a trust in this area",0xD);
	else if(not caster:canUsePet()) then
		return MSGBASIC_CANT_BE_USED_IN_AREA;
	else if (not caster:isUniqueAlly(82)) then
       	caster:PrintToPlayer("Abienzo is already summoned.",0xD);
    else
	return 0;
	end
	end
	end
end;

function onSpellCast(caster,target,spell)
	caster:spawnAlly(82);
	caster:PrintToPlayer(string.format("(Abienzo) My shadows and I are ready for combat.", caster:getName()),0xF);    
	return 0;
end;