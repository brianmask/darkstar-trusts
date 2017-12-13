-----------------------------------------
-- Spell: Kupipi

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
	elseif ((bf ~= nil) and (((bf:getBcnmID() > 1381) and (bf:getBcnmID() < 1387)) or ((bf:getBcnmID() > 1376) and (bf:getBcnmID() < 1381)))) then
        caster:PrintToPlayer("Kupipi is unavailable for this fight.  Please try another Trust.",0xD);	
        return MSGBASIC_CANT_BE_USED_IN_AREA;
	elseif (bf == nil and (zone == 139 or zone == 144 or zone == 146 or zone == 206)) then
	    caster:PrintToPlayer("Kupipi cannot be summoned outside a BC fight.",0xD);
	    return MSGBASIC_CANT_BE_USED_IN_AREA;
	elseif(not caster:canUsePet()) then
		return MSGBASIC_CANT_BE_USED_IN_AREA;
	elseif (not caster:isUniqueAlly(76)) then
       	caster:PrintToPlayer("Kupipi is already summoned.",0xD);
    else
	    return 0;
	end
	
	

end;

function onSpellCast(caster,target,spell)
	caster:spawnAlly(76);
   if (caster:getObjType() == TYPE_PC) then
   caster:PrintToPlayer("(Kupipi) Heaven's Tower has sent me to ensure the safety of this party.", 0xF); 
   end

    
	return 0;
end;