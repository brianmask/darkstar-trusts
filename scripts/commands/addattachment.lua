---------------------------------------------------------------------------------------------------
-- func: goto
-- desc: Goes to the target player.
---------------------------------------------------------------------------------------------------

cmdprops =
{
    permission = 1,
    parameters = "s"
};

function onTrigger(player, target)
   -- player:unlockAttachment(8196); -- stormwalker head
   -- player:unlockAttachment(8227);  -- Stormwaker Frame
   -- player:unlockAttachment(8197);  -- soulsoother head
   -- player:unlockAttachment(8449);  -- soulsoother head
      player:unlockAttachment(8193);  -- Harle Head
	  player:unlockAttachment(8224);  -- Harle Body
	  player:unlockAttachment(8451);  -- Inhibitor
	  player:unlockAttachment(8450);  -- Tension Spring I
	  player:unlockAttachment(8452);  -- Tension Spring II
	  player:unlockAttachment(8673); -- Mana Tank
   -- player:unlockAttachment(0x21C1)
end