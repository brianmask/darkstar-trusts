-----------------------------------
-- Area: Ferretory
-- NPC: Sageen
-- Unlocks Achievements for reducing Weakness Timer
-----------------------------------

-----------------------------------
require("scripts/globals/missions");
require("scripts/globals/keyitems");
require("scripts/globals/conquest");


-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)

local balance = 0;
local questweakness = 175000; 
local pinfamy = player:getCurrency("infamy");

if (trade:hasItemQty(4104,1)) and (player:getVar("FerretoryQuest75noaura") >= 11) then 
    if (pinfamy >= questweakness) then   
    player:delCurrency("infamy", questweakness);
    player:tradeComplete();
	player:PrintToPlayer("You may now check your Achievements through this NPC!", 0x15);
	player:setVar("AchievementWeakness",1); -- Achievements Unlocked
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
if (player:getSkillLevel(SKILL_WOODWORKING) >= 10) then
a1 = 1;
end

local a2 = 0;
if (player:hasCompletedMission(COP,ANCIENT_VOWS) == true) then
a2 = 1;
end
 
local a3 = 0;
if (player:hasSpell(12) == true) then
a3 = 1;
end

local a4 = 0; -- Dynamis Windurst Boss need KI
if (player:hasKeyItem(HYDRA_CORPS_LANTERN)) then
a4 = 1;
end

local a5 = 0; -- Level 75 Nin, create a list in the player.lua table that checks for all jobs and give them a playervar
if (player:getVar("NIN75") == 1) then
a5 = 1;
end

local a6 = 0;
if (player:hasSpell(13) == true) then
a6 = 1;
end

local a7 = 0;
if (player:getQuestStatus(OUTLANDS,BUGI_SODEN) == QUEST_COMPLETED) then
a7 = 1;
end

local a8 = 0;
if (player:getQuestStatus(OUTLANDS,TRUE_WILL) == QUEST_COMPLETED) then
a8 = 1;
end

local a9 = 0;
if (player:hasSpell(140) == true) then
a9 = 1;
end

local a10 = 0;

local plvl = player:getMainLvl();


local currentachievement = a1+a2+a3+a4+a5+a6+a7+a8+a9+a10;
local wktimer = currentachievement * 15;

player:setVar("WeakTimer",wktimer);









if (player:getVar("AchievementWeakness") == 1) then
    player:PrintToPlayer("Sageen : Weakness Timer is currently -"..wktimer.." seconds.  Current Achievements ["..currentachievement.."/10]", 0xD);
else if (player:getVar("FerretoryQuest75") >= 11) and (plvl > 74) then
    player:PrintToPlayer("Sageen : Weakness Timer? Give me 175,000 Infamy and 1 fire cluster to unlock these achievements", 0xD);	
else
	 player:PrintToPlayer("Sageen : Sorry, Maccus said I can't talk to you about Achievements yet...", 0xD);
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



