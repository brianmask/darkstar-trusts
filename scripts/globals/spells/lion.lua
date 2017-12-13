-----------------------------------------
-- Spell: Lion

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
	if (((zone == 185) or (zone == 186) or (zone == 187)) and (dynamis ~= 1)) then
	caster:PrintToPlayer("You cannot summon a trust in this area",0xD);
	elseif ((bf ~= nil) and (((bf:getBcnmID() > 1385) and (bf:getBcnmID() < 1387)) or ((bf:getBcnmID() > 1376) and (bf:getBcnmID() < 1385)))) then
	    caster:PrintToPlayer("Lion is unavailable for this fight.  Please try another Trust.",0xD);		
	    return MSGBASIC_CANT_BE_USED_IN_AREA;
	elseif (bf == nil and (zone == 139 or zone == 144 or zone == 146 or zone == 206)) then
	  caster:PrintToPlayer("Lion cannot be summoned outside a BC fight.",0xD);
	  return MSGBASIC_CANT_BE_USED_IN_AREA;		
	elseif(not caster:canUsePet()) then
		return MSGBASIC_CANT_BE_USED_IN_AREA;
	elseif (not caster:isUniqueAlly(86)) then
       	caster:PrintToPlayer("Lion is already summoned.",0xD);
    else
	return 0;
	end


end;

function onSpellCast(caster,target,spell)
	caster:spawnAlly(86);
   if (caster:getObjType() == TYPE_PC) then
   caster:PrintToPlayer("(Lion) Let's put an end to the years of trouble and discord!", 0xF); 
   caster:setVar("LionPT",1);
   end

    
	return 0;
end;