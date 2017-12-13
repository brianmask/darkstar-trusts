-----------------------------------
-- Area: Ferretory
-- NPC: Jaryn
-- Unlocks Achievements for increased attack/ranged attack
-----------------------------------

-----------------------------------
require("scripts/globals/missions");
require("scripts/globals/quests");
require("scripts/globals/conquest");
require("scripts/globals/keyitems");


-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)

local balance = 0;
local questweakness = 100000; 
local pinfamy = player:getCurrency("infamy");

if (trade:hasItemQty( 4104, 1 )) and (player:getVar("FerretoryLv75Complete") >= 11) then 
    if (pinfamy >= questweakness) then   
    player:delCurrency("infamy", questweakness);
    player:tradeComplete();
	player:PrintToPlayer("You may now check your Achievements through this NPC!", 0x15);
	player:setVar("AchievementAttack",1); -- Achievements Unlocked
	else
    balance = questweakness - pinfamy; 
    player:PrintToPlayer( "Sageen : I'm sorry, you need "..balance.." more infamy.", 0xD);
    end
	end

	
end; 

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)

-- Start Adding together Achievements
local a1 = 0;
if (player:getNationRank(BASTOK) >= 5) then
a1 = 1;
end

local a2 = 0;
if (player:getSkillLevel(SKILL_ALCHEMY) >= 30) then
a2 = 1;
end

local a3 = 0; 
if (player:hasKeyItem(CHOCOBO_LICENSE)) then
a3 = 1;
end

local a4 = 0;
if (player:getQuestStatus(BASTOK,BRYGID_THE_STYLIST_RETURNS) == QUEST_COMPLETED) then
a4 = 1;
end

local a5 = 0;
if (player:getNationRank(BASTOK) == 10) then
a5 = 1;
end
 
local a6 = 0; -- Level 75 on six jobs, create a list in the player.lua table that checks for all jobs and give them a playervar
local a6 = 0;
local a7 = 0;
local a8 = 0;
local a9 = 0;
local a10 = 0;




local currentachievement = a1+a2+a3+a4+a5+a6;
local atk = currentachievement * 3;







if (player:getVar("FeretoryQuest75") >= 11) and player:getVar("AchievementAttack") < 1 and (plvl > 74) then
    player:PrintToPlayer("Sageen : Att/R.Attack? Give me 100,000 Infamy and 1 fire cluster to unlock these achievements", 0xD);
else if (player:getVar("AchievementAttack") == 1) then
    player:PrintToPlayer("Sageen : Attack/R.Attack bonus is +"..atk..".  Current Achievements unlocked ["..currentachievement.."/10]", 0xD);
end
end	
	
	
	
end;
-----------------------------------
-- onEventUpdate
-----------------------------------

function onEventUpdate(player,csid,option)
--printf("CSID: %u",csid);
--printf("RESULT: %u",option);
end;

-----------------------------------
-- onEventFinish
-----------------------------------

function onEventFinish(player,csid,option)
--printf("CSID: %u",csid);
--printf("RESULT: %u",option);
end;



