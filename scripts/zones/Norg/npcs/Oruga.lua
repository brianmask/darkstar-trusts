-----------------------------------
-- Area: Norg
-- NPC: Oruga
-- Standard Info NPC
-----------------------------------

require("scripts/globals/pathfind");

local path = {
-0.016294, -1.251156, -30.703135,
1.135162, -1.295192, -30.737705,
2.267773, -1.620833, -30.756174,
3.344393, -1.879029, -30.778761,
5.049327, -2.361731, -30.823250,
6.117022, -2.563100, -30.886162,
7.181621, -2.772666, -30.972755,
8.245983, -2.954788, -31.051538,
9.328338, -3.061133, -31.039093,
10.409624, -3.143949, -30.961086,
11.492971, -3.171996, -30.865526,
15.815061, -3.447035, -30.455658,
16.874792, -3.526491, -30.227465,
17.896387, -3.708385, -29.895599,
18.898493, -3.908274, -29.532429,
19.895685, -4.079228, -29.134384,
20.737349, -4.216307, -28.413183,
21.407436, -4.330055, -27.513542,
22.016415, -4.434795, -26.589983,
22.619663, -4.506055, -25.649052,
23.082552, -4.733766, -24.577311,
23.317366, -4.843967, -23.488529,
23.503233, -4.784823, -22.336891,
23.579830, -4.873768, -21.227167,
23.595615, -4.955327, -20.067602,
23.604248, -4.673836, -15.539319,
23.576544, -4.747251, -14.438788,
23.589468, -4.701037, -15.602610,
23.583118, -4.819503, -16.757050,
23.603765, -4.955882, -20.001656,
23.589598, -4.852837, -21.216965,
23.512104, -4.780120, -22.266308,
23.371975, -4.846354, -23.286993,
23.154896, -4.779443, -24.363916,
22.713276, -4.551100, -25.401381,
22.164385, -4.452671, -26.342907,
21.586670, -4.363403, -27.264763,
21.003744, -4.252445, -28.176605,
20.161383, -4.131409, -28.924875,
19.176140, -3.957754, -29.401279,
18.169416, -3.773172, -29.799803,
17.226116, -3.551686, -30.132439,
16.238331, -3.480612, -30.356184,
15.180473, -3.392950, -30.503290,
14.115976, -3.279427, -30.617214,
9.767619, -3.120346, -31.023869,
8.737691, -3.001644, -31.048111,
7.659624, -2.875193, -30.995384,
6.561257, -2.650589, -30.911077,
5.400178, -2.428268, -30.843111,
4.195887, -2.202940, -30.804506,
1.013752, -1.273776, -30.729916,
-0.022560, -1.251507, -30.706329,
-2.217780, -1.106099, -30.654016,
-1.043870, -1.248653, -30.678118
};

function onSpawn(npc)
    npc:initNpcAi();
	npc:setPos(pathfind.first(path));
	-- onPath(npc);
end;

function onPath(npc)
	pathfind.patrol(npc, path);
end;

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)
end; 

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)
player:startEvent(0x0057);
npc:wait(-1);
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

function onEventFinish(player,csid,option,npc)
--printf("CSID: %u",csid);
--printf("RESULT: %u",option);
	npc:wait(0);
end;



