-----------------------------------
-- Area: Ru'Aun Gardens
--  NPC: Byakko 
-----------------------------------

require("scripts/zones/RuAun_Gardens/TextIDs");
require("scripts/globals/status");
require("scripts/globals/mobscaler");

-----------------------------------
-- onMobInitialize
-----------------------------------

function onMobInitialize(mob)
    mob:setMobMod(MOBMOD_ADD_EFFECT,mob:getShortID());

end;

-----------------------------------
-- onMobSpawn Action
-----------------------------------

function onMobSpawn(mob)
 	mob:setLocalVar("PartySize",6);  -- Large Party of 75's can defeat Byakko
end;

-----------------------------------
-- onAdditionalEffect
-----------------------------------

function onAdditionalEffect(mob, target, damage)
    local size = mob:getLocalVar("PartySize");
	
	local dmg = math.random(size*5,size*9);
	
		-- local dmg = math.random(35,50);
    local params = {};
    params.bonusmab = 0;
    params.includemab = false;
    
    dmg = addBonusesAbility(mob, ELE_LIGHT, target, dmg, params);
    dmg = dmg * applyResistanceAddEffect(mob,target,ELE_LIGHT,0);
    dmg = adjustForTarget(target,dmg,ELE_LIGHT);
    dmg = finalMagicNonSpellAdjustments(mob,target,ELE_LIGHT,dmg);

    return SUBEFFECT_LIGHT_DAMAGE, MSGBASIC_ADD_EFFECT_DMG, dmg;
end;


function onMobFight(mob,target)
    local size = target:getPartySize();
    -- printf("Total Size: %s",size);	
    mobScaler(mob,target);
	
	local att = mob:getStat(MOD_ATT);
	local def = mob:getStat(MOD_DEF);
	local eva = mob:getStat(MOD_EVA);
	local acc = mob:getStat(MOD_ACC);
	local patt = target:getStat(MOD_ATT);
	local pdef = target:getStat(MOD_DEF);
	local pdif = patt / def;
	local mobpdif = att / pdef;
    printf("Attack is: %s",att);
	printf("Defense is: %s",def);
	printf("Player PDIF is: %s",pdif);
	printf("MOB PDIF is: %s",mobpdif);	
	-- printf("Evasion is: %s",eva);
	-- printf("Accuray is: %s",acc);
end

-----------------------------------
-- onMobDeath
-----------------------------------

function onMobDeath(mob, killer, player)
    player:showText(mob,SKY_GOD_OFFSET + 12);
    player:setVar("Byakko_Win",1);
	player:addCurrency('jetton',225);
	player:PrintToPlayer("Your obtain 50 Jettons.", 0x15);		
end;

-----------------------------------
-- onMobDespawn
-----------------------------------

function onMobDespawn(mob)
    GetNPCByID(17310052):updateNPCHideTime(FORCE_SPAWN_QM_RESET_TIME);
end;