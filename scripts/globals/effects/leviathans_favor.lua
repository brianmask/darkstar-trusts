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
	local curepot = (power * 0.07) + 5;


    target:addMod(MOD_WATERACC,bonus);
    target:addMod(MOD_WATERATT,bonus);
    target:addMod(MOD_WATERDEF,bonus);
    target:addMod(MOD_WATERRES,res);
    target:addMod(MOD_MACC,bonus);
	target:addMod(MOD_CURE_POTENCY,curepot);
	target:addMod(MOD_MND,bonus);
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
            member:addStatusEffect(EFFECT_LEVIATHAN_S_FAVOR, effect:getPower(), 0, 3);
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
	local curepot = (power * 0.07) + 5;


    target:delMod(MOD_WATERACC,bonus);
    target:delMod(MOD_WATERATT,bonus);
    target:delMod(MOD_WATERDEF,bonus);
    target:delMod(MOD_WATERRES,res);
    target:delMod(MOD_MACC,bonus);
	target:delMod(MOD_CURE_POTENCY,curepot);
	target:delMod(MOD_MND,bonus);
end;