-----------------------------------
-- Ability: Deus Ex Automata
-- Calls forth your automaton with limited hp/mp
-- Obtained: Puppetmaster Level 5
-- Recast Time: 0:05:00 
-- Duration: Instant
-----------------------------------

require("scripts/globals/settings");
require("scripts/globals/status");
require("scripts/globals/pets");

-----------------------------------
-- onAbilityCheck
-----------------------------------

function onAbilityCheck(player,target,ability)
    if (player:getPet() ~= nil) then
        return MSGBASIC_ALREADY_HAS_A_PET,0;
    elseif (not player:canUsePet()) then
        return MSGBASIC_CANT_BE_USED_IN_AREA,0;
    else
        return 0,0;
    end
end;

-----------------------------------
-- onUseAbility
-----------------------------------

function onUseAbility(player,target,ability)
    local level = player:getMainLvl();
	local hp = (((level * 85) / 256) / 100);
	local mp = (((level * 85) / 256) / 100);
	
    player:spawnPet(PET_AUTOMATON);

    local oldhp = player:getPet():getHP();
    local oldmp = player:getPet():getMP();

    local newhp = oldhp * hp;
    local newmp = oldmp * mp;
	
	player:getPet():setHP(newhp);
	player:getPet():setMP(newmp);

	
end;