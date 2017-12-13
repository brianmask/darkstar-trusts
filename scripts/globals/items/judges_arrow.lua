-----------------------------------------
--	ID: 17326
--	Equip: Judges arrow
--	Creates Powerful -Status effects for Non Bards
-----------------------------------------

require("scripts/globals/status");
require("scripts/globals/magic");

-----------------------------------
-- onAdditionalEffect Action
-----------------------------------

function onAdditionalEffect(player,target,damage)
    local chance = 95;

  --  if (target:getMainLvl() > player:getMainLvl()) then
    --    chance = chance - 5 * (target:getMainLvl() - player:getMainLvl())
      --  chance = utils.clamp(chance, 5, 95);
    -- end
	local plvl = player:getMainLvl();
	local mlvl = target:getMainLvl();
	local ldif = mlvl - plvl;
	if (ldif < 0) then
	ldif = 0;
	end
	
	local lower = 1 + (plvl / 11);
	local higher = (plvl / 3) - ldif;
	
	if (higher >= lower) then
	higher = higher + 2;
	end
	

	
    if (math.random(0,99) >= chance) then
        return 0,0,0;
    else
  	    local dmg = (math.random(lower,higher));
        local params = {};
        params.bonusmab = 0;
        params.includemab = false;
		
		local threnody = target:getStatusEffect(EFFECT_THRENODY);
		print("Earth Threnody");
        if (threnody ~= nil and threnody:getSubPower() == MOD_EARTHRES) then		
        dmg = addBonusesAbility(player, ELE_EARTH, target, dmg, params);
        dmg = adjustForTarget(target,dmg,ELE_EARTH);
        dmg = finalMagicNonSpellAdjustments(player,target,ELE_EARTH,dmg);
        return SUBEFFECT_EARTH_DAMAGE, MSGBASIC_ADD_EFFECT_DMG, dmg;
	
		
		elseif (threnody ~= nil and threnody:getSubPower() == MOD_FIRERES) then		
        dmg = addBonusesAbility(player, ELE_FIRE, target, dmg, params);
        dmg = adjustForTarget(target,dmg,ELE_FIRE);
        dmg = finalMagicNonSpellAdjustments(player,target,ELE_FIRE,dmg);
        return SUBEFFECT_FIRE_DAMAGE, MSGBASIC_ADD_EFFECT_DMG, dmg;
		
		elseif (threnody ~= nil and threnody:getSubPower() == MOD_WINDRES) then		
        dmg = addBonusesAbility(player, ELE_WIND, target, dmg, params);
        dmg = adjustForTarget(target,dmg,ELE_WIND);
        dmg = finalMagicNonSpellAdjustments(player,target,ELE_WIND,dmg);
        return SUBEFFECT_WIND_DAMAGE, MSGBASIC_ADD_EFFECT_DMG, dmg;
		
		
		elseif (threnody ~= nil and threnody:getSubPower() == MOD_WATERRES) then		
        dmg = addBonusesAbility(player, ELE_WATER, target, dmg, params);
        dmg = adjustForTarget(target,dmg,ELE_WATER);
        dmg = finalMagicNonSpellAdjustments(player,target,ELE_WATER,dmg);
        return SUBEFFECT_WATER_DAMAGE, MSGBASIC_ADD_EFFECT_DMG, dmg;
		
		elseif (threnody ~= nil and threnody:getSubPower() == MOD_ICERES) then		
        dmg = addBonusesAbility(player, ELE_ICE, target, dmg, params);
        dmg = adjustForTarget(target,dmg,ELE_ICE);
        dmg = finalMagicNonSpellAdjustments(player,target,ELE_ICE,dmg);
        return SUBEFFECT_ICE_DAMAGE, MSGBASIC_ADD_EFFECT_DMG, dmg;
		
		elseif (threnody ~= nil and threnody:getSubPower() == MOD_THUNDERRES) then		
        dmg = addBonusesAbility(player, ELE_THUNDER, target, dmg, params);
        dmg = adjustForTarget(target,dmg,ELE_THUNDER);
        dmg = finalMagicNonSpellAdjustments(player,target,ELE_THUNDER,dmg);
        return SUBEFFECT_LIGHTNING_DAMAGE, MSGBASIC_ADD_EFFECT_DMG, dmg;
	
		
		elseif (threnody ~= nil and threnody:getSubPower() == MOD_DARKRES) then		
        dmg = addBonusesAbility(player, ELE_DARK, target, dmg, params);
        dmg = adjustForTarget(target,dmg,ELE_DARK);
        dmg = finalMagicNonSpellAdjustments(player,target,ELE_DARK,dmg);
        return SUBEFFECT_DARK_DAMAGE, MSGBASIC_ADD_EFFECT_DMG, dmg;

		
		elseif (threnody ~= nil and threnody:getSubPower() == MOD_LIGHTRES) then		
        dmg = addBonusesAbility(player, ELE_LIGHT, target, dmg, params);
        dmg = adjustForTarget(target,dmg,ELE_LIGHT);
        dmg = finalMagicNonSpellAdjustments(player,target,ELE_LIGHT,dmg);
        return SUBEFFECT_LIGHT_DAMAGE, MSGBASIC_ADD_EFFECT_DMG, dmg;
		end
		
		
    end
end;