-----------------------------------------
-- Spell: Curilla

-----------------------------------------

require("scripts/globals/pets");
require("scripts/globals/summon");
--require("scripts/globals/bfcheck");

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
    if ((bf:getBcnmID() > 1377) and (bf:getBcnmID() < 1387)) then
	  caster:PrintToPlayer("Curilla is unavailable for this fight.  Please try another Trust.",0xD);	
    elseif (not caster:isUniqueAlly(79)) then
       	caster:PrintToPlayer("Curilla is already summoned.",0xD);
    else
	    return 0;
  end
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
	local instance = caster:getInstance();
	if (zone == 60) then
	caster:spawnAlly(79, instance);
	caster:PrintToPlayer("INSTANCE CAST");
	else
	caster:spawnAlly(79);
	end
   caster:PrintToPlayer("(Curilla) This should prove to be a good training exercise to hone my skills as a Knight.", 0xF); 

    
	return 0;
end;