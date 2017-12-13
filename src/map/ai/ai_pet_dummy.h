/*
===========================================================================

  Copyright (c) 2010-2015 Darkstar Dev Teams

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see http://www.gnu.org/licenses/

  This file is part of DarkStar-server source code.

===========================================================================
*/

#ifndef _CAIPETDUMMY_H
#define _CAIPETDUMMY_H

#include "../../common/cbasetypes.h"

#include "ai_general.h"
#include <map>

/************************************************************************
*																		*
*																		*
*																		*
************************************************************************/

#define PET_ROAM_DISTANCE 2.1f

class CPetEntity;

class CAIPetDummy : public CAIGeneral
{
public:

	virtual void CheckCurrentAction(uint32 tick);
	virtual void WeatherChange(WEATHER weather, uint8 element);

	CAIPetDummy(CPetEntity* PPet);

	uint16	m_MasterCommand; //used for avatars/wyverns atm
	std::map<char,int> timers;
    bool  m_queueSic;
	
protected:
	virtual void TransitionBack(bool skipWait = false);

	CPetEntity* m_PPet;
    int16 m_skillTP;
	//individual universal recast timers
	uint32 m_magicRecast;
	uint32 m_magicKupipiRecast;
	uint32 m_magicShantottoRecast;
	uint32 m_blueCheck;
	uint32 m_schCheck;
	
	//individual spell timers
	uint32 m_magicHealRecast;
	uint32 m_curillaVokeRecast;
    uint32 m_magicHealCast;
	uint32 m_curillaFlashRecast;
	uint32 m_curillaBashRecast;
	uint32 m_curillaReprisalRecast;
	uint32 m_curillaChivalryRecast;
	uint32 m_kupipiHealCast;
	uint32 m_kupipiHealRecast;
	uint32 m_kupipiSolaceRecast;
	uint32 m_kupipiEnhanceRecast;
	uint32 m_nanaacheck;
	uint32 m_nanaaSneakAttackRecast;
	uint32 m_ayameMeditateRecast;
	uint32 m_najiBerserkRecast;
	uint32 m_najiWarcryRecast;
	uint32 m_exeJumpRecast;
	uint32 m_exeHjumpRecast;
	uint32 m_exeSjumpRecast;
	uint32 m_exeAngonRecast;
	
	uint32 m_ayameThirdEyeRecast;
	uint32 m_ayameSekkaRecast;
	uint32 m_blueChainAffinityRecast;
    uint32 m_blueMagicRecast;
	uint32 m_blueMagicHealRecast;
	uint32 m_schEleRecast;
	uint32 m_schEnhRecast;
	uint32 m_adelhiedHealRecast;
	uint32 m_adelhiedSub;
	uint32 m_schHealing;
	uint32 m_luzafQuickRecast;
	uint32 m_luzafRollCheck;
	uint32 m_luzafFirstRollRecast;
	uint32 m_luzafSecondRollRecast;
	uint32 m_magicUlmiaRecast;
	uint32 m_minuetStrongRecast;
	uint32 m_minuetWeakRecast;
	uint32 m_madrigalStrongRecast;
	uint32 m_madrigalWeakRecast;
	uint32 m_marchStrongRecast;
	uint32 m_marchWeakRecast;
	uint32 m_balladStrongRecast;
	uint32 m_balladWeakRecast;
	uint32 m_songEnfeeble;
	uint32 m_songFront;
	
	uint32 m_firstMeleeSongRecast;
	uint32 m_secondMeleeSongRecast;
	uint32 m_firstMageSongRecast;
	uint32 m_secondMageSongRecast;
	
	uint32 m_gesshoMagicRecast;
	uint32 m_gesshoUtsuCheck;
	uint32 m_gesshoVokeRecast;
	uint32 m_gesshoUtsuNiRecast;
	uint32 m_gesshoUtsuIchiRecast;
	uint32 m_gesshoEnfeeblingRecast;
	uint32 m_skillchainTrust;
	uint32 m_magicPrisheRecast;
	uint32 m_prisheHealRecast;
	
	uint32 m_zeidArcaneCircleRecast;
	uint32 m_zeidWeaponBashRecast;
	uint32 m_zeidLastResortRecast;
	uint32 m_zeidMagicRecast;
	uint32 m_zeidAbsorbRecast;
	uint32 m_zeidAbsTPRecast;
	uint32 m_zeidAbsACCRecast;
	uint32 m_zeidAbsSTRRecast;
	uint32 m_zeidDrainRecast;
	uint32 m_zeidEnfeebRecast;
	uint32 m_lionCheck;
	uint32 m_lionTrickAttackRecast;
	uint32 m_zeidSCReady;
	uint32 m_skillchainTimer;
	
	uint32 m_najelithBerserkRecast;
	uint32 m_najelithRangedRecast;
	uint32 m_najelithSharpshotRecast;
	uint32 m_najelithBarrageRecast;
	
    uint32 m_shantottoEleRecast;
	uint32 m_shantottoDebuffRecast;
	
	int8 m_magicburst;
	int8 m_sekkaStatus;
	int8 m_chainAffinityStatus;
	

	



	void preparePetAbility(CBattleEntity* PTarg);
	void ActionRoaming();
	void ActionDisengage();
	void ActionEngage();
	void ActionAttack();
	void ActionSleep();
	void ActionFall();
	void ActionDeath();
	void ActionSpawn();
	void ActionAbilityStart();
	void ActionAbilityUsing();
	void ActionAbilityInterrupt();
	void ActionAbilityFinish();
	void ActionWeaponSkillFinish();
	void ActionJobAbilityFinish(); 
	bool PetIsHealing(); //true if wyvern is healing

	void ActionMagicStart();
	void ActionMagicCasting();
	void ActionMagicFinish();
	void ActionMagicInterrupt();
	
	int16 CurillaSpell();
	int16 KupipiSpell();
	int16 BlueSpell();
	int16 AdelhiedSpell();
	int16 UlmiaSpell();
	int16 PrisheSpell();
	int16 GesshoSpell();
	int16 ZeidSpell();
	int16 ShantottoSpell();
	int16 ShantottoSpellLowTier();	
	int16 ShantottoSpellDebuff();
	int16 skillchainTimer();
	uint32 ZeidSkillchain();
	CBattleEntity* getWounded(uint8 threshold);
	CBattleEntity* getWoundedLow(uint8 threshold);	
	CBattleEntity* getWoundedAga(uint8 threshold);
	CBattleEntity* getTrickAttackPartner();
	CBattleEntity* getLionSCPartnerZeid();	
	CBattleEntity* getZeidSCPartner();	
	CBattleEntity* getSleptMage();	
	

    void SendTooFarInterruptMessage(CBattleEntity* PTarg);


private:

};

#endif
