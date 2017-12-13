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
	local rac = (power * 0.07) + 5;

    target:addMod(MOD_WINDACC,bonus); -- +21 @417 SMN Skill
    target:addMod(MOD_WINDATT,bonus); -- +21 @417 SMN Skill
    target:addMod(MOD_WINDDEF,bonus); -- +21 @417 SMN Skill
    target:addMod(MOD_WINDRES,res); -- +48 @417 SMN Skill
    target:addMod(MOD_EVA,bonus); -- +21 @417 SMN Skill
    target:addMod(MOD_RACCP,rac);  -- + 11% RACC @417 SMN Skill
	target:addMod(MOD_AGI,bonus); -- +21 @417 SMN Skill
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
            member:addStatusEffect(EFFECT_GARUDA_S_FAVOR, effect:getPower(), 0, 3);
			
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
    local rac = (power * 0.07) + 5;

    target:delMod(MOD_WINDACC,bonus);
    target:delMod(MOD_WINDATT,bonus);
    target:delMod(MOD_WINDDEF,bonus);
    target:delMod(MOD_WINDRES,res);
    target:delMod(MOD_EVA,bonus);
    target:delMod(MOD_RACCP,12);
	target:delMod(MOD_AGI,bonus);
end;