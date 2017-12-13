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
	local def = (power * 0.07) + 5;



    target:addMod(MOD_EARTHACC,bonus);
    target:addMod(MOD_EARTHATT,bonus);
    target:addMod(MOD_EARTHDEF,bonus);
    target:addMod(MOD_EARTHRES,res);
    target:addMod(MOD_DEFP,def);
	target:addMod(MOD_VIT,bonus);

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
            member:addStatusEffect(EFFECT_TITAN_S_FAVOR, effect:getPower(), 0, 3);
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
	local def = (power * 0.07) + 5;


    target:delMod(MOD_EARTHACC,bonus);
    target:delMod(MOD_EARTHATT,bonus);
    target:delMod(MOD_EARTHDEF,bonus);
    target:delMod(MOD_EARTHRES,res);
    target:delMod(MOD_DEFP,def);
	target:delMod(MOD_VIT,bonus);
end;