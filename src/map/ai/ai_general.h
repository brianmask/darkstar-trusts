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

#ifndef _CAIGENERAL_H
#define _CAIGENERAL_H

#include <queue>
#include <memory>

#include "../../common/cbasetypes.h"
#include "../packets/weather.h"
#include "helpers/targetfind.h"
#include "helpers/pathfind.h"
#include "states/magic_state.h"

enum MASTERCOMMAND //master as in pet's master
{
	MASTERCOMMAND_NONE = 0,
	MASTERCOMMAND_ELEMENTAL_BREATH = 1,
	MASTERCOMMAND_HEALING_BREATH = 2,
	MASTERCOMMAND_SIC = 3,
	MASTERCOMMAND_SUPER_JUMP = 4
};

enum ACTIONTYPE : uint8
{
	ACTION_NONE					= 0,
	ACTION_ATTACK				= 1,
	ACTION_RANGED_FINISH		= 2,
	ACTION_WEAPONSKILL_FINISH	= 3,
	ACTION_MAGIC_FINISH			= 4,
	ACTION_ITEM_FINISH			= 5,
	ACTION_JOBABILITY_FINISH	= 6,
	ACTION_WEAPONSKILL_START	= 7,
	ACTION_MAGIC_START			= 8,
	ACTION_ITEM_START			= 9,
	ACTION_JOBABILITY_START		= 10,
	ACTION_MOBABILITY_FINISH	= 11,
	ACTION_RANGED_START			= 12,
	ACTION_RAISE_MENU_SELECTION	= 13,
	ACTION_DANCE				= 14,
	ACTION_UNKNOWN_15			= 15,
	//everything after this is not from the client - server side actions only!
	// they must be enumerated for the lua scripts, but can be safely changed as
	// long as status.lua is also updated
	ACTION_ROAMING				= 16,
	ACTION_ENGAGE				= 17,
	ACTION_DISENGAGE			= 18,
	ACTION_CHANGE_TARGET		= 19,
	ACTION_FALL					= 20,
	ACTION_DROPITEMS			= 21,
	ACTION_DEATH				= 22,
	ACTION_FADE_OUT				= 23,
	ACTION_DESPAWN				= 24,
	ACTION_SPAWN				= 25,
    ACTION_STUN					= 26,
    ACTION_SLEEP				= 27,
	ACTION_ITEM_USING			= 28,
	ACTION_ITEM_INTERRUPT		= 29,
	ACTION_MAGIC_CASTING		= 30,
	ACTION_MAGIC_INTERRUPT		= 31,
    ACTION_RANGED_INTERRUPT		= 32,
    ACTION_MOBABILITY_START		= 33,
    ACTION_MOBABILITY_USING		= 34,
    ACTION_MOBABILITY_INTERRUPT = 35,
    ACTION_LEAVE				= 36
};

struct quAction_t
{
    ACTIONTYPE action;
    uint16 param;
    CBattleEntity* target;
};

typedef std::queue<quAction_t> ActionQueue_t;

/************************************************************************
*																		*
*  Данную конструкцию нельзя использовать напрямую, только из потомков	*
*																		*
************************************************************************/

class CSpell;
class CItemUsable;
class CBattleEntity;
class CAbility;
class CWeaponSkill;
class CMobSkill;

class CAIGeneral
{
public:

    void            Reset();

	ACTIONTYPE		GetCurrentAction();
	CSpell*			GetCurrentSpell();
	CBattleEntity*	GetBattleTarget();
	CBattleEntity*  GetBattleSubTarget();
	CAbility*		GetCurrentJobAbility();
	CWeaponSkill*	GetCurrentWeaponSkill();
	CMobSkill*		GetCurrentMobSkill();
	uint16			GetLastCorsairRoll();
	bool			GetAutoAttackEnabled();
	bool			GetMagicCastingEnabled();
        bool                    IsInSleepableAction();
    bool            GetMobAbilityEnabled();
    bool            MoveTo(position_t* pos); // move entity to position. Doesn't pathfind
    void			Wait(int32 waitTime);
	void            Engage(uint32 targid);	

    bool            CanSeePoint(position_t point);
    uint32          GetBattleTime();

	void			SetBattleTarget(CBattleEntity* PEntity); //used for pets mainly
	void			SetBattleSubTarget(CBattleEntity* PEntity); //used for pets mainly
	void			SetCurrentSpell(uint16 SpellID);
	void			SetCurrentWeaponSkill(uint16 WSkillID);
	void			SetCurrentJobAbility(uint16 JobAbilityID);
	void			SetCurrentMobSkill(CMobSkill* skill); // DEBUG
    void            SetLastActionTime(uint32 time);
	void			SetLastMagicTime(uint32 time);
    void			SetLastStrobeTime(uint32 time);
	void			SetLastRangedTime(uint32 time);	
	void			SetLastAttachmentTime(uint32 time);	
	void			SetLastBashTime(uint32 time);
	void			SetLastFlashTime(uint32 time);	
	void			SetLastConvertTime(uint32 time);	
	void			SetLastStoneskinTime(uint32 time);
	void			SetLastBarrageTime(uint32 time);
	void			SetLastMagicTimeHeal(uint32 time);
	void			SetLastMagicTimeEnf(uint32 time);	
	void			SetLastMagicTimeStatus(uint32 time);
	void			SetLastMagicTimeEle(uint32 time);	
	void			SetLastMagicTimeEnhance(uint32 time);
	void			SetLastCurillaVokeTime(uint32 time);
    void            SetLastCurillaFlash(uint32 time);
    void            SetLastCurillaBashTime(uint32 time);
    void            SetLastCurillaChivalryTime(uint32 time);	
    void            SetLastCurillaReprisalTime(uint32 time);	
	void            SetLastKupipiMagicTime(uint32 time);
	void            SetLastKupipiEnhanceTime(uint32 time);
	void            SetLastKupipiSolaceTime(uint32 time);	
	void			SetLastNanaaCheckTime(uint32 time);
	void			SetLastNanaaSneakAttackTime(uint32 time);
	void			SetLastAyameMeditateTime(uint32 time);
	void			SetLastAyameThirdEyeTime(uint32 time);
	void			SetLastAyameSekkaTime(uint32 time);	
	void			SetLastNajiBerserkTime(uint32 time);
	void			SetLastNajiWarcryTime(uint32 time);			
	void			SetLastExeJumpTime(uint32 time);	
	void			SetLastExeHjumpTime(uint32 time);	
	void			SetLastExeSjumpTime(uint32 time);
	void			SetLastExeAngonTime(uint32 time);	
    void			SetLastEngageStart(uint32 time);
    void			SetLastSkillchainStart(uint32 time);
	void 			SetLastChainTime(uint32 time);
	void            SetLastBlueCheck(uint32 time);
	void			SetLastBlueMagicCast(uint32 time);
	void			SetLastBlueMagicHealCast(uint32 time);
	void 			SetLastSchEleCast(uint32 time);
	void			SetLastSchCheck(uint32 time);
	void			SetLastSchEnh(uint32 time);
	void			SetLastAdelhiedHeal(uint32 time);
	void            SetLastAdelhiedSub(uint32 time);
	void			SetLastLuzafQuickTime(uint32 time);
	void			SetLastLuzafRollCheck(uint32 time);
	void			SetLastLuzafFirstRollRecast(uint32 time);
	void			SetLastLuzafSecondRollRecast(uint32 time);
	void			SetLastUlmiaSongTime(uint32 time);
	void			SetLastMinuetStrongTime(uint32 time);
	void			SetLastMinuetWeakTime(uint32 time);
	void			SetLastMadrigalStrongTime(uint32 time);
	void			SetLastMadrigalWeakTime(uint32 time);
	void			SetLastMarchStrongTime(uint32 time);
	void			SetLastMarchWeakTime(uint32 time);
	void			SetLastBalladStrongTime(uint32 time);
	void			SetLastBalladWeakTime(uint32 time);
	void			SetLastSongEnfeebleTime(uint32 time);
	void			SetLastSongFrontTime(uint32 time);
	
	void			SetLastFirstMeleeSongTime(uint32 time);
	void			SetLastSecondMeleeSongTime(uint32 time);
	void			SetLastFirstMageSongTime(uint32 time);
	void			SetLastSecondMageSongTime(uint32 time);
	
	
	void			SetLastGesshoMagicTime(uint32 time);
	void			SetLastGesshoUtsuCheck(uint32 time);
	void			SetLastGesshoVokeTime(uint32 time);
	void			SetLastGesshoUtsuNiTime(uint32 time);
	void			SetLastGesshoUtsuIchiTime(uint32 time);
	void			SetLastGesshoEnfeeblingTime(uint32 time);
	void			SetLastPrisheSCTime(uint32 time);
	void			SetLastPrisheMagicTime(uint32 time);
	void 	        SetLastZeidArcaneCircleTime(uint32 time);
	void 			SetLastZeidWeaponBashTime(uint32 time);
	void			SetLastZeidLastResortTime(uint32 time);
	void			SetLastZeidMagicTime(uint32 time);
	void 			SetLastZeidAbsorbTime(uint32 time);
	void 			SetLastZeidAbsTPTime(uint32 time);
	void			SetLastZeidAbsACCRecast(uint32 time);
	void			SetLastZeidAbsSTRRecast(uint32 time);
	void			SetLastZeidEnfeebRecast(uint32 time);
	void			SetLastZeidDrainRecast(uint32 time);
	void			SetLastLionTrickAttackRecast(uint32 time);
	void			SetLastLionCheckRecast(uint32 time);
	void			SetLastZeidSCTime(uint32 time);
	void			SetLastUniversalSCTime(uint32 time);
	
	void			SetLastShantottoEleCast(uint32 time);
	void			SetLastShantottoMagicTime(uint32 time);
	void			SetLastShantottoCheck(uint32 time);
	void            SetLastShantottoDebuffRecast(uint32 time);
	void            SetLastNajelithBerserkTime(uint32 time);
	void            SetLastNajelithRangeTime(uint32 time);
	void            SetLastNajelithSharpshotTime(uint32 time);
	void            SetLastNajelithBarrageTime(uint32 time);
	void			SetLastNajelithWSTime(uint32 time);
	
    void			SetLastShantottoEleTime(uint32 time);	
	
	void			SetCurrentAction(ACTIONTYPE Action, uint16 TargetID = 0);
	void			SetLastCorsairRoll(uint16 ability);
	void			SetAutoAttackEnabled(bool enabled);
	void			SetMagicCastingEnabled(bool enabled);
	void			SetMobAbilityEnabled(bool enabled);

	virtual void	CheckCurrentAction(uint32 tick) = 0;
	virtual void	WeatherChange(WEATHER weather, uint8 element) = 0;

    CAIGeneral();
	virtual ~CAIGeneral();

    CPathFind*       m_PPathFind; // finds paths
    bool			 m_interruptSpell; // forces interrupt of current spell being cast

    // states
    CMagicState*     m_PMagicState;
    ActionQueue_t    m_actionQueue;


private:

    //uint32			m_StartBattle;			// Battle start time

protected:

	virtual void			TransitionBack(bool skipWait) = 0; // transition back to correct state (usually attack or roaming)

	ACTIONTYPE		m_ActionType;			// текущее действие (состояние)
	uint16			m_ActionTargetID;		// дополнительная цель, участвующая в действии
	uint32			m_LastActionTime;		// время начала любого действия
	uint32			m_LastMeleeTime;		// Last time melee hit occurred
	uint32			m_LastMagicTime;		// Last time magic spell was -attempted-
	uint32			m_LastStrobeTime;       // Last time strobe was attempted
	uint32			m_LastRangedTime;       // Last time a ranged attack was attempted
	uint32			m_LastAttachmentTime;   // Last time an attachment was attempted to be used
	uint32			m_LastBashTime;         // Last time Shield bash was used
	uint32			m_LastFlashTime;
	uint32			m_LastConvertTime;
	uint32			m_LastStoneskinTime;
	uint32			m_LastBarrageTime;
	uint32			m_LastMagicTimeHeal;
	uint32			m_LastMagicTimeEnf;
	uint32			m_LastMagicTimeStatus;
	uint32			m_LastMagicTimeEle;
	uint32			m_LastMagicTimeEnhance;	
	uint32          m_LastCurillaVokeTime;
	uint32          m_LastCurillaFlash;
	uint32          m_LastCurillaBashTime;
	uint32          m_LastCurillaChivalryTime;
	uint32          m_LastCurillaReprisalTime;	
	uint32          m_LastKupipiMagicTime;
	uint32			m_LastKupipiEnhanceTime;
	uint32			m_LastKupipiSolaceTime;	
	uint32          m_LastNanaaCheckTime;  //Last time Nanaa Mihgo checked if facing target
	uint32			m_LastNanaaSneakAttackTime;
	uint32			m_LastAyameMeditateTime;
	uint32			m_LastAyameThirdEyeTime;
	uint32			m_LastAyameSekkaTime;	
	uint32			m_LastNajiBerserkTime;
	uint32			m_LastNajiWarcryTime;
	uint32          m_LastExeJumpTime;
	uint32			m_LastExeHjumpTime;
	uint32			m_LastExeSjumpTime;
	uint32  		m_LastExeAngonTime;
	uint32			m_LastChainTime;
    uint32          m_LastBlueCheck;
    uint32          m_LastBlueMagicCast;
	uint32          m_LastBlueMagicHealCast;
	uint32			m_LastSchEleCast;
	uint32          m_LastSchCheck;
	uint32			m_LastAdelhiedHeal;
	uint32          m_LastAdelhiedSub;
	uint32			m_LastSchEnh;
	uint32          m_LastLuzafQuickTime;
	uint32			m_LastLuzafRollCheck;
	uint32			m_LastLuzafFirstRollRecast;
	uint32			m_LastLuzafSecondRollRecast;
	uint32			m_LastUlmiaSongTime;
	uint32			m_LastMinuetStrongTime;
	uint32			m_LastMinuetWeakTime;
	uint32			m_LastMadrigalStrongTime;
	uint32			m_LastMadrigalWeakTime;
	uint32			m_LastMarchStrongTime;
	uint32			m_LastMarchWeakTime;
	uint32          m_LastBalladStrongTime;
	uint32			m_LastBalladWeakTime;
	uint32			m_LastSongEnfeebleTime;
	uint32			m_LastSongFrontTime;
	
	uint32			m_LastFirstMeleeSongTime;
	uint32			m_LastSecondMeleeSongTime;
	uint32			m_LastFirstMageSongTime;
	uint32			m_LastSecondMageSongTime;
	
	
	
	uint32          m_LastGesshoMagicTime;
	uint32			m_LastGesshoUtsuCheck;
	uint32			m_LastGesshoVokeTime;
	uint32			m_LastGesshoUtsuNiTime;
	uint32			m_LastGesshoUtsuIchiTime;
	uint32			m_LastGesshoEnfeeblingTime;
	uint32			m_LastPrisheSCTime;
	uint32          m_LastPrisheMagicTime;
    
    uint32          m_LastZeidArcaneCircleTime;
	uint32 			m_LastZeidWeaponBashTime;
	uint32			m_LastZeidLastResortTime;
    uint32          m_LastZeidMagicTime;
    uint32			m_LastZeidAbsorbTime;
	uint32			m_LastZeidDrainTime;
	uint32			m_LastZeidAbsTPTime;
	uint32			m_LastZeidAbsACCTime;
	uint32			m_LastZeidAbsSTRTime;
	uint32			m_LastZeidEnfeebTime;
	uint32          m_LastLionTrickAttackTime;
	uint32			m_LastLionCheckTime;
	uint32			m_LastZeidSCTime;
	uint32			m_LastZeidTrigger;
	uint32 			m_LastUniversalSCTime;

    uint32          m_LastShantottoEleCast;	
    uint32          m_LastShantottoMagicTime;
    uint32          m_LastShantottoCheck;	
	uint32          m_LastShantottoDebuffRecast;
    uint32          m_LastNajelithBerserkTime;	
    uint32          m_LastNajelithRangeTime;	
    uint32          m_LastNajelithSharpshotTime;		
    uint32          m_LastNajelithBarrageTime;
	uint32			m_LastNajelithWSTime;

    uint32          m_LastShantottoEleTime;	
	
	uint32			m_LastEngageStart;
	uint32 			m_LastSkillchainStart;


    uint32			m_Tick;					// текущее значение времени
    uint32			m_StartBattle;			// Battle start time
	uint16			m_CorsairDoubleUp;		// Last used corsair roll eligible for DU
	bool			m_AutoAttackEnabled;    // Flag to enable/disable auto attack
	bool			m_MobAbilityEnabled;		// Flag to enable/disable mob skills
    CTargetFind*    m_PTargetFind;          // finds targets for AoEs

	std::unique_ptr<CSpell>	        m_PSpell;				// читаемое заклинание
    std::unique_ptr<CWeaponSkill>   m_PWeaponSkill;
    std::unique_ptr<CAbility>		m_PJobAbility;
    std::unique_ptr<CMobSkill>		m_PMobSkill;
	CItemUsable*	                m_PItemUsable;			// используемый предмет
	CBattleEntity*	                m_PBattleTarget;		// боевая цель - основная
	CBattleEntity*	                m_PBattleSubTarget;		// боевая цель - дополнительная

	uint32 m_WaitTime;
	uint32 m_LastWaitTime;

};

#endif
