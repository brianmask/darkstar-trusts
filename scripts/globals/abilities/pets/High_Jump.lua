---------------------------------------------------
-- Jump
-- Trust: Excenmille
-- 
---------------------------------------------------

require("/scripts/globals/settings");
require("/scripts/globals/status");
--require("/scripts/globals/monstertpmoves");

---------------------------------------------------

function onMobSkillCheck(target,mob,skill)
    return 0, 0;
end;

function onPetAbility(target, pet, skill, action)

    local dstr = pet:getStat(MOD_STR) - target:getStat(MOD_VIT);
    local weaponbase = pet:getWeaponDmg();
	local fstr1 = 0;
	local vit = pet:getStat(MOD_VIT);
	local da = 0;

	local level = pet:getMainLvl();
	local doubleatt = math.random(1,100);
	if (doubleatt <=10) then
	da = 1;
	end
	
	-- Give Jump a high Double Attack chance. Special for Trust
	

    if (dstr >= 12) then
		fstr1 = ((dstr+4)/4);
	elseif (dstr >= 6) then
		fstr1 = ((dstr+6)/4);
	elseif (dstr >= 1) then
		fstr1 = ((dstr+7)/4);
	elseif (dstr >= -2) then
		fstr1 = ((dstr+8)/4);
	elseif (dstr >= -7) then
		fstr1 = ((dstr+9)/4);
	elseif (dstr >= -15) then
		fstr1 = ((dstr+10)/4);
	elseif (dstr >= -21) then
		fstr1 = ((dstr+12)/4);
	else
		fstr1 = ((dstr+13)/4);
	end	
	
	-- Apply the fstr1 caps
	if (fstr1<((weaponbase/9)*(-1))) then
		fstr1 = (weaponbase/9)*(-1);
	elseif (fstr1>((weaponbase/9)+8)) then
		fstr1 = (weaponbase/9)+8;
	end
	
	local basedmg = weaponbase + fstr1;
	
	local ftp = (1 + (vit/256));
	
	local crit = math.random(1,100);
	
	if (crit < 20) then
	ftp = (2 + (vit/256));
	end

	
	if (da == 1) then
    dmg = 2 * (basedmg * ftp);
	pet:addTP(26.8);
	else
	dmg = basedmg * ftp;
	pet:addTP(13.4);
	end
	
	target:lowerEnmity(pet, 50);
 

 target:delHP(dmg);

 return dmg;

end;
