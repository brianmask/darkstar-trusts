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
	local mat = (power * 0.11) + 5;



    target:addMod(MOD_ICEACC,bonus);
    target:addMod(MOD_ICEATT,bonus);
    target:addMod(MOD_ICEDEF,bonus);
    target:addMod(MOD_ICERES,res);
    target:addMod(MOD_MATT,mat);
    target:addMod(MOD_INT,bonus);
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
            member:addStatusEffect(EFFECT_SHIVA_S_FAVOR, effect:getPower(), 0, 3);
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
	local mat = (power * 0.11) + 5;


    target:delMod(MOD_ICEACC,bonus);
    target:delMod(MOD_ICEATT,bonus);
    target:delMod(MOD_ICEDEF,bonus);
    target:delMod(MOD_ICERES,res);
    target:delMod(MOD_MATT,mat);
    target:delMod(MOD_INT,bonus);
end;