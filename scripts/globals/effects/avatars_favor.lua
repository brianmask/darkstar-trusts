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
local pet = target:getPet();
local buff = power * 1.5;
local magic = power * 3;
pet:addMod(MOD_MATT, magic); -- +30 MAB
pet:addMod(MOD_MACC, magic); -- +30 Magic Accuracy
pet:addMod(MOD_ATTP, buff);  -- +15% Attack
pet:addMod(MOD_ACCP, buff);  -- +15% Accuracy
pet:addMod(MOD_STR, magic); -- +30 STR
target:addMod(MOD_AVATAR_PERPETUATION, power);




end;

-----------------------------------
-- onEffectTick Action
-----------------------------------

function onEffectTick(target,effect)
end;

-----------------------------------
-- onEffectLose Action
-----------------------------------

function onEffectLose(target,effect)
local power = effect:getPower();
local pet = target:getPet();
local buff = power * 1.5;
local magic = power * 3;
pet:delMod(MOD_MATT, magic); -- +30 MAB
pet:delMod(MOD_MACC, magic); -- +30 Magic Accuracy
pet:delMod(MOD_ATTP, buff);  -- +15% Attack
pet:delMod(MOD_ACCP, buff);  -- +15% Accuracy
pet:delMod(MOD_STR, magic); -- +30 STR
target:delMod(MOD_AVATAR_PERPETUATION, power);
end;