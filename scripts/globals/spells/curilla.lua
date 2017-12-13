-----------------------------------------
-- Spell: Curilla

-----------------------------------------

require("scripts/globals/pets");
require("scripts/globals/summon");
require("scripts/globals/bfcheck");

-----------------------------------------
-- OnSpellCast
-----------------------------------------

function onMagicCastingCheck(caster,target,spell)
    local zone = caster:getZoneID();
    local bf = caster:getBattlefield();
	local dynamis = caster:getVar("TrustDynamis");
	if (((zone == 185) or (zone == 186) or (zone == 187) or (zone == 188) or (zone == 134) or (zone == 135)) and (dynamis ~= 1)) then
	caster:PrintToPlayer("You cannot summon a trust in this area",0xD);
	elseif ((bf ~= nil) and ((bf:getBcnmID() > 1377) and (bf:getBcnmID() < 1387))) then
	    caster:PrintToPlayer("Curilla is unavailable for this fight.  Please try another Trust.",0xD);	
		return MSGBASIC_CANT_BE_USED_IN_AREA;	
	elseif (bf == nil and (zone == 139 or zone == 144 or zone == 146 or zone == 206)) then
	    caster:PrintToPlayer("Curilla cannot be summoned outside a BC fight.",0xD);	
		return MSGBASIC_CANT_BE_USED_IN_AREA;
	elseif(not caster:canUsePet()) then
		return MSGBASIC_CANT_BE_USED_IN_AREA;
	elseif (not caster:isUniqueAlly(79)) then
       	caster:PrintToPlayer("Curilla is already summoned.",0xD);
    else
	return 0;
	end

end;

function onSpellCast(caster,target,spell)
    local zone = caster:getZoneID();

	
	caster:spawnAlly(79);

   caster:PrintToPlayer("(Curilla) This should prove to be a good training exercise to hone my skills as a Knight.", 0xF); 

    
	return 0;
end;