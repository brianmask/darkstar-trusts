-----------------------------------------
-- Spell: Curaga III
-- Restores HP of all party members within area of effect.
-----------------------------------------

require("scripts/globals/settings");
require("scripts/globals/status");
require("scripts/globals/magic");

-----------------------------------------
-- OnSpellCast
-----------------------------------------

function onMagicCastingCheck(caster,target,spell)
	return 0;
end;

function onSpellCast(caster,target,spell)
	local minCure = 270;

	local divisor = 0.6666;
	local constant = 165;
	local power = getCurePowerOld(caster);
	if (power > 460) then
		divisor = 6.5;
		constant = 354.6666;
	elseif (power > 220) then
		divisor = 2;
		constant = 275;
	end

	local final = getCureFinal(caster,spell,getBaseCureOld(power,divisor,constant),minCure,false);
	
		if (target:getAllegiance() == caster:getAllegiance() and (target:getObjType() == TYPE_PC or target:getObjType() == TYPE_MOB or ((target:getObjType() == TYPE_PET) and 
	((target:getSystem() ~= 5) or target:getSystem() ~=18)))) then

	final = final + (final * (target:getMod(MOD_CURE_POTENCY_RCVD)/100));
	end
	
	--Applying server mods....
	final = final * CURE_POWER;
	
	local diff = (target:getMaxHP() - target:getHP());
	if (final > diff) then
		final = diff;
	end
	target:addHP(final);

	target:wakeUp();
	caster:updateEnmityFromCure(target,final);
	
	spell:setMsg(367);	
	
	return final;
end;