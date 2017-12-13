-------------------------------------------
-- Mob Scaler
-- This Function scales Notorious Monsters
-- level based on the amount of players present
-- in the party.  Set local variable
-- based on what the expected full level
-- of players needed to fight naturally
-- would be
-------------------------------------------

-------------------------------------------
-- Scale Chart
-- 1 = 1-3 Players
-- 2 = 4-6 Players
-- 3 = 7-9 Players
-- 4 = 10-12 Players
-- 5 = 13-15 Players
-- 6 = 16-18 Players
-------------------------------------------


-----------------------------------
-- mobScaler
-----------------------------------

function mobScaler(mob,target)

	local storedsize = mob:getLocalVar("PartySize");
	local currentsize = target:getPartySize();
	local partycalc = math.ceil(target:getPartySize()/3);
	local sizecalc = math.ceil(currentsize/3);
	local sizediff = 0;
	local newsize = 0;
	
	if (partycalc ~= storedsize) then -- the two party sizes don't match; adjust
	    sizediff = partycalc - storedsize; -- Find differences between stored and partycalc size
	 -- Apply Difference to mob calculations	
	    mob:addMod(MOD_ATT,7*sizediff);
	    mob:addMod(MOD_DEF,20*sizediff);
	    mob:addMod(MOD_ACC,5*sizediff);
	    mob:addMod(MOD_MACC,10*sizediff);		
	    mob:addMod(MOD_EVA,10*sizediff);
	    mob:addMod(MOD_INT,10*sizediff);
	    mob:addMod(MOD_CHR,30*sizediff);
	    mob:addMod(MOD_MND,30*sizediff);
	    mob:addMod(MOD_STR,10*sizediff);
		mob:addMod(MOD_UDMGPHYS,-15*sizediff);
		
     -- set Mob dmg
	    local mobdmg = mob:getWeaponDmg();
		mob:setDamage(mobdmg + (6*sizediff));
		local newdmg = (mobdmg + (6*sizediff));
		printf("Mob damage is: %s",newdmg);

		
	 -- Store the Party Size		
		if (sizecalc == 1) then -- 1-3 Players
		    mob:setLocalVar("PartySize",partycalc);
			printf("Changing Party Size to: %s",partycalc);
		elseif (sizecalc == 2) then -- 4-6 Players	
		    mob:setLocalVar("PartySize",partycalc);	
			printf("Changing Party Size to: %s",partycalc);			
		elseif (sizecalc == 3) then -- 7-9 Players	
		    mob:setLocalVar("PartySize",partycalc);		
			printf("Changing Party Size to: %s",partycalc);			
		elseif (sizecalc == 4) then -- 10-12 Players
		    mob:setLocalVar("PartySize",partycalc);		
			printf("Changing Party Size to: %s",partycalc);			
		elseif (sizecalc == 5) then -- 13-15 Players
		    mob:setLocalVar("PartySize",partycalc);		
			printf("Changing Party Size to: %s",partycalc);			
		elseif (sizecalc == 6) then -- 16-18 Players	
		    mob:setLocalVar("PartySize",partycalc);	
			printf("Changing Party Size to: %s",partycalc);			
        end
	end	
end
