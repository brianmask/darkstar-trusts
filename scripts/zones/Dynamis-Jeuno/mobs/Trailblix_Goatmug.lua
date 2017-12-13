-----------------------------------
-- Area: Dynamis Jeuno
-- NPC:  Trailblix Goatmug
-- Boss Trigger for BST/WAR
-- Popped with Roving Bijou
-- Drops Tome 17
-----------------------------------

-----------------------------------
-- onMobSpawn Action
-----------------------------------

function onMobSpawn(mob)
mob:addMod(MOD_EVA,50);
mob:addMod(MOD_ACC,50);


end;


function onMobEngaged(mob,target)

    local hp = math.random(80,90)
    mob:setLocalVar("CallBeast", hp);

local weakener = target:getVar("DynaWeakener");
   if (weakener == 3) then
   mob:setMod(MOD_HPP,-75);
   mob:setMod(MOD_DEFP,-75);
   mob:setMod(MOD_ATTP,-75);
   mob:addMod(MOD_EVA,-30);
   mob:addMOd(MOD_ACC,-30);
   SetDropRate(5043,3420,300);
if (target:getObjType() == TYPE_PC) then  
target:PrintToPlayer("You have significantly weakened the monster!", 0xD);
end
elseif (weakener == 2) then
   mob:setMod(MOD_HPP,-50);
   mob:setMod(MOD_DEFP,-20);
   mob:setMod(MOD_ATTP,-20);
   mob:addMod(MOD_EVA,-20);
   mob:addMOd(MOD_ACC,-20);
   SetDropRate(5043,3420,500);
if (target:getObjType() == TYPE_PC) then  
target:PrintToPlayer("You have weakened the monster!", 0xD);
end
elseif (weakener == 1) then
   mob:setMod(MOD_HPP,-20);
   mob:setMod(MOD_DEFP,-10);
   mob:setMod(MOD_ATTP,-10);
   mob:addMod(MOD_EVA,-10);
   mob:addMOd(MOD_ACC,-10);
   SetDropRate(5043,3420,700);
if (target:getObjType() == TYPE_PC) then	
target:PrintToPlayer("You have weakened the monster ever so slightly", 0xD);
end
elseif (weakener == 0) then
 -- mob:setMod(MOD_ACC,100);
 -- mob:setMod(MOD_EVA,100);
if (target:getObjType() == TYPE_PC) then 
target:PrintToPlayer("You have summoned a Monster.", 0xD); 
end 
end   
end;


-----------------------------------
-- onMobFight Action
-----------------------------------
function onMobFight(mob,target)

    local battletime = mob:getBattleTime();
    local cbhp = mob:getLocalVar("CallBeast");

    if (mob:getHPP() < cbhp) then
        mob:useMobAbility(761);
		SpawnMob(17547269):updateClaim(target);
        mob:setLocalVar("CallBeast", 0);
    end

end;



-----------------------------------
-- onMobDeath
-----------------------------------

function onMobDeath(mob,killer)
killer:setVar("DynaWeakener",0);
local qm1 = GetNPCByID(17547510);
qm1:setStatus(STATUS_NORMAL);
	

end;


function onMobDespawn( mob )
local qm1 = GetNPCByID(17547510);

qm1:setStatus(STATUS_NORMAL);

end