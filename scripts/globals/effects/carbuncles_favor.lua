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

target:addMod(MOD_REGEN, bonus);
target:addMod(MOD_CHR, bonus);


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
            member:addStatusEffect(EFFECT_CARBUNCLE_S_FAVOR, effect:getPower(), 0, 3);
			
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

target:delMod(MOD_REGEN, bonus);
target:delMod(MOD_CHR, bonus);


end;