ALLY_ASSIST_PLAYER = 1;
ALLY_ASSIST_RANDOM = 2;

function startAllyAssist(entity, assistMode)
    -- print("Ally Assist Initiated");

    if (assistMode == nil) then
        assistMode = ALLY_ASSIST_PLAYER;
    end

    local mobs;
    local players;
    local allies = {}

    if (entity:getBattlefield() ~= nil) then
        mobs = entity:getBattlefield():getEnemies();
        players = entity:getBattlefield():getPlayers();
    elseif (entity:getInstance() ~= nil) then
        mobs = entity:getInstance():getMobs();
        players = entity:getInstance():getChars();
    end

    print("start inserting mob")
    local targetMobs = {}
    for j,mob in pairs(mobs) do
        if (mob:getStatus() ~= STATUS_DISAPPEAR and mob:getHP() > 0) then
            if (mob:isAlly()) then
                table.insert(allies, mob)
            else
                table.insert(targetMobs, mob)
                print("inserting mob")
            end
        end
    end

    -- In this mode, find a player with a battle target, and assist that player
    if (assistMode == ALLY_ASSIST_PLAYER) then
       local assistTarget = 0;

        -- Loop players and find someone who is engaged in battle
        for i,player in pairs(players) do
            local battleTarget = player:getTarget();

            if (battleTarget ~= nil) then
                assistTarget = battleTarget:getShortID();
                break;
            end
        end

        printf("startAllyAssist: target = %u (ALLY_ASSIST_PLAYER)", assistTarget);

        -- Attack their target if found. If none found, we'll fall to ALLY_ASSIST_RANDOM.
        -- A variety of reasons could cause this - players have hate but are not engaged is one.
        -- Being aggroed when not engaged is another.
        if (assistTarget > 0) then
		    printf("Assist Target is: %u", assistTarget);
            for _,ally in ipairs(allies) do
                ally:engage(assistTarget);
            end
            return;
        end
    end

    -- ALLY_ASSIST RANDOM - also a fallback for ALLY_ASSIST_PLAYER
    -- Pick an enemy to attack. Some allies do this intentionally. Some allies start to attack on their own if
    -- a player stalls too long. This can be used to set a target in both cases.


    local target = targetMobs[math.random(#targetMobs)]
	-- local newtarget = player:getMobByID();
	local showid = target:getShortID();
    
    for _,ally in ipairs(allies) do
	    printf("LOOKING FOR TARGET!!!");
	    ally:engage(target:getShortID());	
    end
end