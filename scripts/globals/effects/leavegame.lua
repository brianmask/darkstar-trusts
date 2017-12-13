-----------------------------------
--
-- 	EFFECT_LEAVEGAME
-- 	
-----------------------------------

-----------------------------------
-- onEffectGain Action
-----------------------------------

function onEffectGain(target,effect)
	target:setAnimation(33);
	target:messageSystem(effect:getPower(),30);
	target:PrintToPlayer("Any Trusts that are summoned will be automatically disbanded within 5 seconds", 0x1F);
end;

-----------------------------------
-- onEffectTick Action
-----------------------------------

function onEffectTick(target,effect)
    

	
	

	if (effect:getTickCount() > 5) then
	    target:setVar("logoutRestStart", os.time());  -- sets variable for resting bonus
		target:setVar("logoutOK", 1); -- sets variable saying the user logged out properly
		target:leavegame();
	else
		target:messageSystem(effect:getPower(),30-effect:getTickCount()*5);
		
	end
	
	local hp = 0;
	local ally = target:getRecentAlly();
    if (effect:getTickCount() > 1) then
    ally:injectActionPacket(4, 261);
	ally:setHP( hp );
	end
	
	
end;

-----------------------------------
-- onEffectLose Action
-----------------------------------

function onEffectLose(target,effect)
	target:setAnimation(0);
end;