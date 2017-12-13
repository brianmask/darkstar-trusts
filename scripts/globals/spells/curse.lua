-----------------------------------------
-- Spell: Curse
-----------------------------------------

require("scripts/globals/status");
require("scripts/globals/magic");

-----------------------------------------
-- OnSpellCast
-----------------------------------------

function onMagicCastingCheck(caster,target,spell)
    return 0;
end;

function onSpellCast(caster,target,spell)

    -- Pull base stats.
    dINT = (caster:getStat(MOD_INT) - target:getStat(MOD_INT));
    local plvl = caster:getMainLvl();
	local mlvl = target:getMainLvl();
	
	local diff = mlvl - plvl;
	
	if (caster:getObjType() == TYPE_PC) then
		if (diff > 7) then
		power = 1;
		elseif (diff > 3) then
		power = 3;
		elseif (diff == 0) then
		power = 5;
		elseif ((diff < 0) and (diff > -3)) then
		power = 7;
		else
		power = 10;
		end
	end	
	
	if (caster:getObjType() == TYPE_MOB) then
    power = 50;
	end

    -- Duration, including resistance.  Unconfirmed.
	if (caster:getObjType() == TYPE_MOB) then
    duration = 300 * applyResistanceEffect(caster,spell,target,dINT,35,0,EFFECT_CURSE_I);
    elseif (caster:getObjType() == TYPE_PC) then
	duration = 300 * applyResistanceEffect(caster,spell,target,dINT,35,0,EFFECT_CURSE_I);
	end
	
if (caster:getObjType() == TYPE_MOB) then
    if (duration >= 150) then --Do it!
        if (target:addStatusEffect(EFFECT_CURSE_I,power,0,duration)) then
            spell:setMsg(236);
        else
            spell:setMsg(75);
        end
    else
        spell:setMsg(85);
    end
elseif (caster:getObjType() == TYPE_PC) then
    if (duration >= 150) then --Do it!
        if (target:addStatusEffect(EFFECT_CURSE_I,power,0,10)) then
            spell:setMsg(236);
        else
            spell:setMsg(75);
        end
    else
        spell:setMsg(85);
    end	
end	

    return EFFECT_CURSE_I;
end;