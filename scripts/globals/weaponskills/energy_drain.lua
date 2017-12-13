------------------------
--    Energy Drain    --
------------------------

function onUseWeaponSkill(player, target, wsID)
   local params = {};
	params.ftp100 = 1.25; params.ftp200 = 2; params.ftp300 = 2.5;
	params.str_wsc = 0.0; params.dex_wsc = 0.0; params.vit_wsc = 0.0; params.agi_wsc = 0.0; params.int_wsc = 0.0; params.mnd_wsc = 1.0; params.chr_wsc = 0.0;
	params.ele = ELE_DARK;
	params.skill = SKILL_DAG;
	params.includemab = true;


	local damage, criticalHit, tpHits, extraHits = doMagicWeaponskill(player, target, params);
	damage = damage * WEAPON_SKILL_POWER
	player:addMP(damage);
	return tpHits, extraHits, criticalHit, damage;
end
