-----------------------------------
--
--
--
-----------------------------------

-----------------------------------
-- onEffectGain Action
-----------------------------------

function onEffectGain(target,effect)
   local power = effect:getPower();
	local bonus = (power * 0.25) + 1;
	local res =  (power * 0.55) + 1;
	local crit = (power * 0.07) + 5;
	local critpow = (power * 0.03) + 3;



    target:addMod(MOD_THUNDERACC,bonus);
    target:addMod(MOD_THUNDERATT,bonus);
    target:addMod(MOD_THUNDERDEF,bonus);
    target:addMod(MOD_THUNDERRES,res);
    target:addMod(MOD_ACCP,crit);
	target:addMod(MOD_DEX,bonus);
	target:addMod(MOD_CRITHITRATE,crit);
	target:addMod(MOD_CRIT_DMG_INCREASE,critpow);
end;

-----------------------------------
-- onEffectTick Action
-----------------------------------


function onEffectTick(target,effect)
    if (not target:isPet()) then
        return;
    end
    local owner = target:getMaster();

    local party = owner:getParty();
	local pet = owner:getPet();
    if (party ~= nil) then
        for i,member in ipairs(party) do
		  if (member:checkDistance(pet) < 10) then
            member:addStatusEffect(EFFECT_RAMUH_S_FAVOR, effect:getPower(), 0, 3);
			end
        end
    end
end;


-----------------------------------
-- onEffectLose Action
-----------------------------------

function onEffectLose(target,effect)
local power = effect:getPower();
	local bonus = (power * 0.25) + 1;
	local res =  (power * 0.55) + 1;
	local crit = (power * 0.07) + 5;
	local critpow = (power * 0.03) + 3;



    target:delMod(MOD_THUNDERACC,bonus);
    target:delMod(MOD_THUNDERATT,bonus);
    target:delMod(MOD_THUNDERDEF,bonus);
    target:delMod(MOD_THUNDERRES,res);
    target:delMod(MOD_ACCP,crit);
	target:delMod(MOD_DEX,bonus);
	target:delMod(MOD_CRITHITRATE,crit);
	target:delMod(MOD_CRIT_DMG_INCREASE,critpow);
end;