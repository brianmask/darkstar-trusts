-----------------------------------
-- Area: Dynamis Windurst
-- NPC:  Tzee Xicu Idol
-----------------------------------

require("scripts/globals/titles");
require("scripts/globals/dynamis");

-----------------------------------
-- onMobSpawn Action
-----------------------------------

function onMobSpawn(mob)
mob:addMod(MOD_EVA,50);
mob:addMod(MOD_ACC,50);
mob:setMod(MOD_FASTCAST,50);

local weakener = target:getVar("DynaWeakener");
 if (weakener == 4) then
   mob:setMod(MOD_HPP,-75);
   mob:setMod(MOD_DEFP,-90);
   mob:setMod(MOD_ATTP,-90);
   mob:addMod(MOD_EVA,-40);
   mob:addMod(MOD_ACC,-40);
   mob:setMod(MOD_FASTCAST,-60);
   mob:setMod(MOD_SLASHRES,1500);
   mob:setMod(MOD_PIERCERES,1500);
   mob:setMod(MOD_HTHRES,1500);
   target:setVar("DynaWeakener",0);
  --  SetDropRate(5004,3415,300);
if (target:getObjType() == TYPE_PC) then 
target:PrintToPlayer("The Monster may not prove to be a challenge", 0xD); 
end
elseif (weakener == 3) then
   mob:setMod(MOD_HPP,-57);
   mob:setMod(MOD_DEFP,-57);
   mob:setMod(MOD_ATTP,-77);
   mob:addMod(MOD_EVA,-30);
   mob:addMod(MOD_ACC,-30);
   mob:setMod(MOD_FASTCAST,-40);
   mob:setMod(MOD_SLASHRES,1200);
   mob:setMod(MOD_PIERCERES,1200);
   mob:setMod(MOD_HTHRES,1200);   
   target:setVar("DynaWeakener",0);
  --  SetDropRate(5004,3415,300);
if (target:getObjType() == TYPE_PC) then  
target:PrintToPlayer("You have significantly weakened the monster!", 0xD);
end
elseif (weakener == 2) then
   mob:setMod(MOD_HPP,-38);
   mob:setMod(MOD_DEFP,-20);
   mob:setMod(MOD_ATTP,-20);
   mob:addMod(MOD_EVA,-20);
   mob:addMod(MOD_ACC,-20);
   mob:setMod(MOD_FASTCAST,-30);
   mob:setMod(MOD_SLASHRES,1000);
   mob:setMod(MOD_PIERCERES,1000);
   mob:setMod(MOD_HTHRES,1000);   
   target:setVar("DynaWeakener",0);
  --  SetDropRate(5004,3415,500);
if (target:getObjType() == TYPE_PC) then  
target:PrintToPlayer("You have weakened the monster!", 0xD);
end
elseif (weakener == 1) then
   mob:setMod(MOD_HPP,-20);
   mob:setMod(MOD_DEFP,-10);
   mob:setMod(MOD_ATTP,-10);
   mob:addMod(MOD_EVA,-10);
   mob:addMod(MOD_ACC,-10);
   mob:setMod(MOD_FASTCAST,-15);
   mob:setMod(MOD_SLASHRES,900);
   mob:setMod(MOD_PIERCERES,900);
   mob:setMod(MOD_HTHRES,900);   
   target:setVar("DynaWeakener",0);
    -- SetDropRate(5004,3415,700);
if (target:getObjType() == TYPE_PC) then	
target:PrintToPlayer("You have weakened the monster ever so slightly", 0xD);
end
elseif (weakener == 0) then
 -- mob:setMod(MOD_ACC,100);
 -- mob:setMod(MOD_EVA,100);
   target:setVar("DynaWeakener",0);
if (target:getObjType() == TYPE_PC) then
target:PrintToPlayer("You have summoned a Monster.", 0xD);  
end
end  



end;

-----------------------------------
-- onMobEngaged
-----------------------------------

function onMobEngaged(mob,target)


end;

-----------------------------------
-- onMobDeath
-----------------------------------

function onMobDeath(mob,killer)

	if (killer:hasKeyItem(HYDRA_CORPS_LANTERN) == false) then
		killer:setVar("DynaWindurst_Win",1);
		killer:addKeyItem(HYDRA_CORPS_LANTERN);
		killer:messageSpecial(KEYITEM_OBTAINED,HYDRA_CORPS_LANTERN);
		killer:addTitle(DYNAMISWINDURST_INTERLOPER); -- Add title
	end

end;