---------------------------------------------------
-- Judgment Bolt
---------------------------------------------------

require("/scripts/globals/settings");
require("/scripts/globals/status");
require("/scripts/globals/monstertpmoves");
require("/scripts/globals/magic");

---------------------------------------------------

function onAbilityCheck(player, target, ability)
    local level = player:getMainLvl() * 2;
    
    if(player:getMP()<level) then
       return 87,0;
    end
    
    return 0,0;
end;

function onPetAbility(target, pet, skill, master)
    local dINT = math.floor(pet:getStat(MOD_INT) - target:getStat(MOD_INT));
	local smnskill = master:getSkillLevel(SKILL_SUM);
    
    local level = pet:getMainLvl()
    local damage = (smnskill * 4) + (level * 10);
    damage = damage + (dINT * 1.5);
    damage = MobMagicalMove(pet,target,skill,damage,ELE_LIGHTNING,1,TP_NO_EFFECT,0);
    damage = mobAddBonuses(pet, nil, target, damage.dmg, ELE_LIGHTNING);
    damage = AvatarFinalAdjustments(damage,pet,skill,target,MOBSKILL_MAGICAL,MOBPARAM_NONE,1);

    master:setMP(0);
    target:delHP(damage);
    target:updateEnmityFromDamage(pet,damage);
    target:addStatusEffect(EFFECT_SILENCE, 1, 0, 60);
	--master:addStatusEffect(EFFECT_SILENCE, 1, 0, 60);
    master:addStatusEffect(EFFECT_WEAKNESS,1,0,180);
	
    return damage; 

end