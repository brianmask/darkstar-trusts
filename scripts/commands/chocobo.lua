---------------------------------------------------------------------------------------------------
-- func: @chocobo
-- auth: <Unknown> :: Modded by Tagban, Kyau
-- desc: Adds Chocobo 
---------------------------------------------------------------------------------------------------

cmdprops =
{
    permission = 0,
    parameters = "s"
};


function onTrigger(player)
    if (player:canUseChocobo() == 0) then
        if (player:hasKeyItem(CHOCOBO_LICENSE) == true) then
            player:addStatusEffect(EFFECT_CHOCOBO, 1, 0, 99999);   
            player:messagePublic(280, player, EFFECT_CHOCOBO, EFFECT_CHOCOBO);
        else
            player:PrintToPlayer("You do not possess a Chocobo License!", 0xE);
        end
    else
        player:PrintToPlayer("You cannot mount here.", 0xE);
    end
end;