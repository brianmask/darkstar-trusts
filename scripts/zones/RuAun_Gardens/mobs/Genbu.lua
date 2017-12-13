-----------------------------------
-- Area: Ru'Aun Gardens
--  NPC: Genbu
-----------------------------------

require("scripts/zones/RuAun_Gardens/TextIDs");
require("scripts/globals/status");

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

    -- local dmg = math.random(140,160)
    local params = {};
    params.bonusmab = 0;
    params.includemab = false;
    
    dmg = addBonusesAbility(mob, ELE_WATER, target, dmg, params);
    dmg = dmg * applyResistanceAddEffect(mob,target,ELE_WATER,0);
    dmg = adjustForTarget(target,dmg,ELE_WATER);
    dmg = finalMagicNonSpellAdjustments(mob,target,ELE_WATER,dmg);

    return SUBEFFECT_WATER_DAMAGE, MSGBASIC_ADD_EFFECT_DMG, dmg;
end;


function onMobFight(mob,target)
   -- local size = target:getPartySize();
    -- printf("Total Size: %s",size);	
	mobScaler(mob,target);
	

	
	-- printf("Attack is: %s",att);
	-- printf("Defense is: %s",def);
	-- printf("Evasion is: %s",eva);
	-- printf("Accuray is: %s",acc);
end

-----------------------------------
-- onMobDeath
-----------------------------------

function onMobDeath(mob, killer, player)
	player:setVar("Genbu_Win",1);
	player:addCurrency('jetton',175);
	player:PrintToPlayer("Your obtain 50 Jettons.", 0x15);	
    player:showText(mob,SKY_GOD_OFFSET + 6);
end;

-----------------------------------
-- onMobDespawn
-----------------------------------

function onMobDespawn(mob)
    GetNPCByID(17310099):updateNPCHideTime(FORCE_SPAWN_QM_RESET_TIME);
end;