-----------------------------------
-- Area: Ferretory
-- NPC: Aengus
-- Standard Info NPC
-----------------------------------
package.loaded["scripts/zones/Heavens_Tower/TextIDs"] = nil;
-----------------------------------

require("scripts/zones/Heavens_Tower/TextIDs");

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)
end; 

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)
if (player:getVar("FerretoryAura") == 0)  then
player:PrintToPlayer("Aengus : I don't sense an Aura on you.  I don't think my coffers will do you any good.", 0xD);
else
player:PrintToPlayer("Aengus senses your Aura", 0x15);
player:PrintToPlayer("Aengus : I can beef up your equipment with certain items. Deposit items in the left chest.", 0xD);
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



