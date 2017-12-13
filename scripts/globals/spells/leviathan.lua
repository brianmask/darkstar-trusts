-----------------------------------------
-- Spell: Leviathan
-- Summons Leviathan to fight by your side
-----------------------------------------

require("scripts/globals/pets");
require("scripts/globals/summon");

-----------------------------------------
-- OnSpellCast
-----------------------------------------

function onMagicCastingCheck(caster,target,spell)
	if (not caster:canUsePet()) then
		return MSGBASIC_CANT_BE_USED_IN_AREA;
    elseif(caster:getObjType() == TYPE_PC) then
		return avatarMiniFightCheck(caster);
	end
	return 0;
end;

function onSpellCast(caster,target,spell)
	caster:spawnPet(PET_LEVIATHAN);
	local skill = caster:getSkillLevel(SKILL_SUM);
    local pet = caster:getPet();
	local enspellPower = 1 + caster:getMainLvl() / 3;
	 local favpower = (skill / 4.9 ) + 1;
	
    if (pet ~= nill) then
        pet:addStatusEffect(EFFECT_LEVIATHAN_S_FAVOR, favpower, 3, 3000);
		pet:addStatusEffect(EFFECT_ENWATER,enspellPower,0,3000);
    end

	return 0;
end;