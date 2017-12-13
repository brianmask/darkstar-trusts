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
	local bf = caster:getBattlefield();		
	local dynamis = caster:getVar("TrustDynamis");
	if (((zone == 185) or (zone == 186) or (zone == 187) or (zone == 188) or (zone == 134) or (zone == 135)) and (dynamis ~= 1)) then
	caster:PrintToPlayer("You cannot summon a trust in this area",0xD);
	elseif (bf ~= nil) then
	    if (((bf:getBcnmID() > 1384) and (bf:getBcnmID() < 1387)) or ((bf:getBcnmID() > 1376) and (bf:getBcnmID() < 1384))) then
	    caster:PrintToPlayer("Adelheid is unavailable for this fight.  Please try another Trust.",0xD);		
	    end
	elseif(not caster:canUsePet()) then
		return MSGBASIC_CANT_BE_USED_IN_AREA;
	elseif (not caster:isUniqueAlly(82)) then
       	caster:PrintToPlayer("Adelheid is already summoned.",0xD);
    else
	return 0;
	end
end;

function onSpellCast(caster,target,spell)
	caster:spawnAlly(82);
	caster:PrintToPlayer(string.format("(Adelheid) The professor always said that books make the best weapon.", caster:getName()),0xF);    
	return 0;
end;