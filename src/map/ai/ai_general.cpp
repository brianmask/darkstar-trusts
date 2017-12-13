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

#include "../spell.h"
#include "../weapon_skill.h"
#include "../ability.h"
#include "../mobskill.h"
#include "../utils/battleutils.h"
#include "helpers/targetfind.h"
#include "helpers/pathfind.h"
#include "states/magic_state.h"

#include "ai_general.h"


/************************************************************************
*																		*
*  В конструкторе присваиваем переменным значения по умолчанию			*
*																		*
************************************************************************/

CAIGeneral::CAIGeneral()
{
    m_PTargetFind = nullptr;
    m_PPathFind = nullptr;
    m_PMagicState = nullptr;
	Reset();
}

CAIGeneral::~CAIGeneral()
{
	if(m_PTargetFind != nullptr)
	{
	    delete m_PTargetFind;
	}

	if(m_PPathFind != nullptr)
	{
	    delete m_PPathFind;
	}

	if(m_PMagicState != nullptr)
	{
		delete m_PMagicState;
	}
}

/************************************************************************
*                                                                       *
*  Сбрасываем AI в исходное состояние                                   *
*                                                                       *
************************************************************************/

void CAIGeneral::Reset()
{
    m_Tick = 0;
	m_StartBattle = 0;
	m_ActionType = ACTION_NONE;
	m_ActionTargetID = 0;
	m_LastActionTime = 0;
    m_LastMeleeTime = 0;
    m_LastMagicTime = 0;
	
	m_LastStrobeTime = 0;
	m_LastRangedTime = 0;
	m_LastAttachmentTime = 0;
	m_LastBashTime = 0;
	m_LastFlashTime = 0;
	m_LastConvertTime = 0;
	m_LastStoneskinTime = 0;
	m_LastBarrageTime = 0;
	m_LastMagicTimeHeal = 0;
	m_LastMagicTimeEnf = 0;
	m_LastMagicTimeStatus = 0;
	m_LastMagicTimeEle = 0;
	m_LastMagicTimeEnhance = 0;
	m_LastEngageStart = 0;
	m_LastSkillchainStart = 0;
	
	m_LastCurillaVokeTime = 0;
	m_LastCurillaFlash = 0;
	m_LastCurillaBashTime = 0;
	m_LastCurillaReprisalTime = 0;	
	m_LastCurillaChivalryTime = 0;
	m_LastKupipiMagicTime = 0;
	m_LastKupipiEnhanceTime = 0;
	m_LastKupipiSolaceTime = 0;	
    m_LastNanaaCheckTime = 0;
	m_LastNanaaSneakAttackTime = 0;
	m_LastBlueCheck = 0;
	m_LastBlueMagicHealCast = 0;
	m_LastBlueMagicCast = 0;
	m_LastSchCheck = 0;
	m_LastSchEleCast = 0;
	m_LastAdelhiedHeal = 0;
	m_LastAdelhiedSub = 0;
	m_LastSchEnh = 0;
	m_LastLuzafQuickTime = 0;
	m_LastLuzafRollCheck = 0;
	m_LastLuzafFirstRollRecast = 0;
	m_LastLuzafSecondRollRecast = 0;
	m_LastUlmiaSongTime = 0;
	m_LastMinuetStrongTime = 0;
	m_LastMinuetWeakTime = 0;
	m_LastMadrigalStrongTime = 0;
	m_LastMadrigalWeakTime = 0;
	m_LastMarchStrongTime = 0;
	m_LastMarchWeakTime	= 0;
	m_LastBalladStrongTime = 0;
	m_LastBalladWeakTime = 0;
	m_LastSongEnfeebleTime = 0;
	m_LastSongFrontTime = 0;
	
	m_LastFirstMeleeSongTime = 0;
	m_LastSecondMeleeSongTime = 0;
	m_LastFirstMageSongTime = 0;
	m_LastSecondMageSongTime = 0;
	
	
	m_LastGesshoMagicTime = 0;
	m_LastGesshoUtsuCheck = 0;
	m_LastGesshoVokeTime = 0;
	m_LastGesshoUtsuNiTime = 0;
	m_LastGesshoUtsuIchiTime = 0;
	m_LastGesshoEnfeeblingTime = 0;
	m_LastPrisheSCTime = 0;
	m_LastPrisheMagicTime = 0;
	
    m_LastZeidArcaneCircleTime = 0;
	m_LastZeidWeaponBashTime = 0;
	m_LastZeidLastResortTime = 0;		
	m_LastZeidMagicTime = 0;
    m_LastZeidAbsorbTime = 0;
	m_LastZeidDrainTime = 0;
	m_LastZeidAbsTPTime = 0;
	m_LastZeidAbsACCTime = 0;
	m_LastZeidAbsSTRTime = 0;
	m_LastZeidEnfeebTime = 0;

    m_LastLionTrickAttackTime = 0;	
	m_LastLionCheckTime = 0;
	m_LastZeidSCTime = 0;
	m_LastZeidTrigger = 0;
	m_LastUniversalSCTime = 0;
	
	m_LastAyameMeditateTime = 0;
	m_LastAyameThirdEyeTime = 0;
	m_LastAyameSekkaTime = 0;	
	m_LastNajiBerserkTime = 0;
	m_LastNajiWarcryTime = 0;
	m_LastExeJumpTime = 0;
	m_LastExeHjumpTime = 0;
	m_LastExeSjumpTime = 0;
	m_LastExeAngonTime = 0;
	m_LastChainTime = 0;
	
    m_LastShantottoEleCast = 0;	
    m_LastNajelithBerserkTime = 0;	
    m_LastNajelithRangeTime = 0;	
    m_LastNajelithSharpshotTime = 0;		
    m_LastNajelithBarrageTime = 0;

    m_LastShantottoEleTime = 0;	
	m_LastShantottoMagicTime = 0;
	m_LastShantottoCheck = 0;
	m_LastShantottoDebuffRecast = 0;
	
    m_WaitTime = 0;
    m_LastWaitTime = 0;
    m_interruptSpell = false;
	m_PSpell = nullptr;
	m_PWeaponSkill = nullptr;
	m_PItemUsable = nullptr;
	m_PBattleTarget = nullptr;
	m_PBattleSubTarget = nullptr;
	m_PJobAbility = nullptr;
	m_PMobSkill = nullptr;
	m_AutoAttackEnabled = true;
	m_MobAbilityEnabled = true;
}

/************************************************************************
*																		*
*  Узнаем текущее действие (состояние) интеллекта						*
*																		*
************************************************************************/

ACTIONTYPE CAIGeneral::GetCurrentAction()
{
	return m_ActionType;
}

/************************************************************************
*                                                                       *
*  Get the time of the battle                                           *
*                                                                       *
************************************************************************/

uint32 CAIGeneral::GetBattleTime()
{
	return ((m_Tick - m_StartBattle) / 1000);
}

/************************************************************************
*																		*
*  Принудительно переводим интеллект в какое-либо состояние				*
*																		*
************************************************************************/

void CAIGeneral::SetCurrentAction(ACTIONTYPE Action, uint16 TargetID)
{
	if (m_ActionTargetID != 0)
		return;

	switch (Action)
	{
		case ACTION_ITEM_START:
        case ACTION_MAGIC_START:
        case ACTION_RANGED_START:
        case ACTION_JOBABILITY_START:
		case ACTION_DISENGAGE:
		{
			if (m_ActionType == ACTION_NONE ||
				m_ActionType == ACTION_ATTACK)
			{
				m_ActionType = Action;
				m_ActionTargetID = TargetID;
			}
		}
	    break;
		case ACTION_WEAPONSKILL_START:
		{
			if (m_ActionType == ACTION_ATTACK)
			{
				m_ActionType = Action;
				m_ActionTargetID = TargetID;
			}
		}
		break;
		case ACTION_ITEM_INTERRUPT:
		{
			if (m_ActionType == ACTION_ITEM_USING)
			{
				m_ActionType = Action;
				m_ActionTargetID = TargetID;
			}
		}
		break;
		case ACTION_MAGIC_INTERRUPT:
		{
			if (m_ActionType == ACTION_MAGIC_CASTING)
			{
				m_ActionType = Action;
				m_ActionTargetID = TargetID;
			}
		}
		break;
		case ACTION_RANGED_INTERRUPT:
		{
			if (m_ActionType == ACTION_RANGED_FINISH)
			{
				m_ActionType = Action;
				m_ActionTargetID = TargetID;
			}
		}
		break;
		case ACTION_ENGAGE:
		{
			if (m_ActionType == ACTION_NONE)
			{
                m_StartBattle = m_Tick;

				m_ActionType = Action;
				m_ActionTargetID = TargetID;
			}
		}
		break;
		case ACTION_SPAWN:
		{
			if (m_ActionType == ACTION_NONE)
			{
				m_ActionType = Action;
				m_ActionTargetID = TargetID;
			}
		}
		break;
		case ACTION_CHANGE_TARGET:
		{
			if (m_ActionType == ACTION_ATTACK)
			{
				m_ActionType = Action;
				m_ActionTargetID = TargetID;
			}
		}
		break;
        case ACTION_FALL:
        {
            switch (m_ActionType)
            {
                case ACTION_ITEM_USING:    m_ActionType = ACTION_ITEM_INTERRUPT;  CheckCurrentAction(m_Tick); break;
                case ACTION_MAGIC_CASTING: m_ActionType = ACTION_MAGIC_INTERRUPT; CheckCurrentAction(m_Tick); break;
            }
            m_ActionType = Action;
			m_ActionTargetID = TargetID;
        }
        break;
		case ACTION_SLEEP:
        {
            switch (m_ActionType)
            {
                case ACTION_ITEM_USING:    m_ActionType = ACTION_ITEM_INTERRUPT;  CheckCurrentAction(m_Tick); break;
                case ACTION_MAGIC_CASTING: m_ActionType = ACTION_MAGIC_INTERRUPT; CheckCurrentAction(m_Tick); break;
				case ACTION_MOBABILITY_START: m_ActionType = ACTION_MOBABILITY_INTERRUPT; CheckCurrentAction(m_Tick); break;
                case ACTION_MOBABILITY_USING: m_ActionType = ACTION_MOBABILITY_INTERRUPT; CheckCurrentAction(m_Tick); break;
            }
            m_ActionType = Action;
			m_ActionTargetID = TargetID;
        }
		break;
		default:
		{
			m_ActionType = Action;
			m_ActionTargetID = TargetID;
		}
	}
}

/************************************************************************
*																		*
*  Устанавливаем время последнего действия в обход системы AI			*
*  (использовать с осторожностью и при полной уверенности в результате)	*
*																		*
************************************************************************/

void CAIGeneral::SetLastActionTime(uint32 time)
{
	m_LastActionTime = time;
}


void CAIGeneral::SetLastMagicTime(uint32 time)
{
	m_LastMagicTime = time;
}

void CAIGeneral::SetLastStrobeTime(uint32 time)
{
	m_LastStrobeTime = time;
}

void CAIGeneral::SetLastRangedTime(uint32 time)
{
	m_LastRangedTime = time;
}

void CAIGeneral::SetLastAttachmentTime(uint32 time)
{
	m_LastAttachmentTime = time;
}

void CAIGeneral::SetLastBashTime(uint32 time)
{
	m_LastBashTime = time;
}

void CAIGeneral::SetLastFlashTime(uint32 time)
{
	m_LastFlashTime = time;
}

void CAIGeneral::SetLastConvertTime(uint32 time)
{
	m_LastConvertTime = time;
}

void CAIGeneral::SetLastStoneskinTime(uint32 time)
{
	m_LastStoneskinTime = time;
}

void CAIGeneral::SetLastBarrageTime(uint32 time)
{
	m_LastBarrageTime = time;
}

void CAIGeneral::SetLastMagicTimeHeal(uint32 time)
{
	m_LastMagicTimeHeal = time;
}

void CAIGeneral::SetLastMagicTimeEnf(uint32 time)
{
	m_LastMagicTimeEnf = time;
}

void CAIGeneral::SetLastMagicTimeStatus(uint32 time)
{
	m_LastMagicTimeStatus = time;
}

void CAIGeneral::SetLastMagicTimeEle(uint32 time)
{
	m_LastMagicTimeEle = time;
}

void CAIGeneral::SetLastMagicTimeEnhance(uint32 time)
{
	m_LastMagicTimeEnhance = time;
}

void CAIGeneral::SetLastCurillaVokeTime(uint32 time)
{
	m_LastCurillaVokeTime = time;
}

void CAIGeneral::SetLastCurillaFlash(uint32 time)
{
	m_LastCurillaFlash = time;
}

void CAIGeneral::SetLastCurillaBashTime(uint32 time)
{
	m_LastCurillaBashTime = time;
}

void CAIGeneral::SetLastCurillaChivalryTime(uint32 time)
{
	m_LastCurillaChivalryTime = time;
}

void CAIGeneral::SetLastCurillaReprisalTime(uint32 time)
{
	m_LastCurillaReprisalTime = time;
}

void CAIGeneral::SetLastKupipiMagicTime(uint32 time)
{
	m_LastKupipiMagicTime = time;
}

void CAIGeneral::SetLastKupipiEnhanceTime(uint32 time)
{
	m_LastKupipiEnhanceTime = time;
}

void CAIGeneral::SetLastKupipiSolaceTime(uint32 time)
{
	m_LastKupipiSolaceTime = time;
}

void CAIGeneral::SetLastNanaaCheckTime(uint32 time)
{
	m_LastNanaaCheckTime = time;
}

void CAIGeneral::SetLastNanaaSneakAttackTime(uint32 time)
{
	m_LastNanaaSneakAttackTime = time;
} 

void CAIGeneral::SetLastAyameMeditateTime(uint32 time)
{
	m_LastAyameMeditateTime = time;
} 

void CAIGeneral::SetLastAyameThirdEyeTime(uint32 time)
{
	m_LastAyameThirdEyeTime = time;
}

void CAIGeneral::SetLastAyameSekkaTime(uint32 time)
{
	m_LastAyameSekkaTime = time;
} 

void CAIGeneral::SetLastNajiBerserkTime(uint32 time)
{
	m_LastNajiBerserkTime = time;
} 

void CAIGeneral::SetLastNajiWarcryTime(uint32 time)
{
	m_LastNajiWarcryTime = time;
} 

void CAIGeneral::SetLastExeJumpTime(uint32 time)
{
	m_LastExeJumpTime = time;
} 

void CAIGeneral::SetLastExeHjumpTime(uint32 time)
{
	m_LastExeHjumpTime = time;
} 

void CAIGeneral::SetLastExeSjumpTime(uint32 time)
{
	m_LastExeSjumpTime = time;
} 

void CAIGeneral::SetLastExeAngonTime(uint32 time)
{
	m_LastExeAngonTime = time;
} 

void CAIGeneral::SetLastEngageStart(uint32 time)
{
	m_LastEngageStart = time;
} 

void CAIGeneral::SetLastSkillchainStart(uint32 time)
{
	m_LastSkillchainStart = time;
}

void CAIGeneral::SetLastChainTime(uint32 time)
{
	m_LastChainTime = time;
}

void CAIGeneral::SetLastBlueCheck(uint32 time)
{
	m_LastBlueCheck = time;
} 

void CAIGeneral::SetLastBlueMagicCast(uint32 time)
{
	m_LastBlueMagicCast = time;
}  

void CAIGeneral::SetLastBlueMagicHealCast(uint32 time)
{
    m_LastBlueMagicHealCast = time;
}	

void CAIGeneral::SetLastSchCheck(uint32 time)
{
    m_LastSchCheck = time;
}

void CAIGeneral::SetLastSchEleCast(uint32 time)
{
    m_LastSchEleCast = time;
}

void CAIGeneral::SetLastSchEnh(uint32 time)
{
    m_LastSchEnh = time;
}

void CAIGeneral::SetLastAdelhiedHeal(uint32 time)
{
    m_LastAdelhiedHeal = time;
}

void CAIGeneral::SetLastAdelhiedSub(uint32 time)
{
    m_LastAdelhiedSub = time;
}

void CAIGeneral::SetLastLuzafQuickTime(uint32 time)
{
    m_LastLuzafQuickTime = time;
}

void CAIGeneral::SetLastLuzafRollCheck(uint32 time)
{
    m_LastLuzafRollCheck = time;
}

void CAIGeneral::SetLastLuzafFirstRollRecast(uint32 time)
{
    m_LastLuzafFirstRollRecast = time;
}

void CAIGeneral::SetLastLuzafSecondRollRecast(uint32 time)
{
    m_LastLuzafSecondRollRecast = time;
}

void CAIGeneral::SetLastUlmiaSongTime(uint32 time)
{
	m_LastUlmiaSongTime = time;
}

void CAIGeneral::SetLastMinuetStrongTime(uint32 time)
{
	m_LastMinuetStrongTime = time;
}

void CAIGeneral::SetLastMinuetWeakTime(uint32 time)
{
	m_LastMinuetWeakTime = time;
}

void CAIGeneral::SetLastMadrigalStrongTime(uint32 time)
{
	m_LastMadrigalStrongTime = time;
}

void CAIGeneral::SetLastMadrigalWeakTime(uint32 time)
{
	m_LastMadrigalWeakTime = time;
}	

void CAIGeneral::SetLastMarchStrongTime(uint32 time)
{
	m_LastMarchStrongTime = time;
}

void CAIGeneral::SetLastMarchWeakTime(uint32 time)
{
	m_LastMarchWeakTime = time;
}

void CAIGeneral::SetLastBalladStrongTime(uint32 time)
{
	m_LastBalladStrongTime = time;
}

void CAIGeneral::SetLastBalladWeakTime(uint32 time)
{
	m_LastBalladWeakTime = time;
}

void CAIGeneral::SetLastSongEnfeebleTime(uint32 time)
{
	m_LastSongEnfeebleTime = time;
}

void CAIGeneral::SetLastSongFrontTime(uint32 time)
{
	m_LastSongFrontTime = time;
}

void CAIGeneral::SetLastFirstMeleeSongTime(uint32 time)
{
	m_LastFirstMeleeSongTime = time;
}

void CAIGeneral::SetLastSecondMeleeSongTime(uint32 time)
{
	m_LastSecondMeleeSongTime = time;
}

void CAIGeneral::SetLastFirstMageSongTime(uint32 time)
{
	m_LastFirstMageSongTime = time;
}

void CAIGeneral::SetLastSecondMageSongTime(uint32 time)
{
	m_LastSecondMageSongTime = time;
}


void CAIGeneral::SetLastGesshoMagicTime(uint32 time)
{
	m_LastGesshoMagicTime = time;
}

void CAIGeneral::SetLastGesshoUtsuCheck(uint32 time)
{
	m_LastGesshoUtsuCheck = time;
}

void CAIGeneral::SetLastGesshoVokeTime(uint32 time)
{
	m_LastGesshoVokeTime = time;
}

void CAIGeneral::SetLastGesshoUtsuNiTime(uint32 time)
{
	m_LastGesshoUtsuNiTime = time;
}

void CAIGeneral::SetLastGesshoUtsuIchiTime(uint32 time)
{
	m_LastGesshoUtsuIchiTime = time;
}

void CAIGeneral::SetLastGesshoEnfeeblingTime(uint32 time)
{
	m_LastGesshoEnfeeblingTime = time;
}

void CAIGeneral::SetLastPrisheSCTime(uint32 time)
{
	m_LastPrisheSCTime = time;
}

void CAIGeneral::SetLastPrisheMagicTime(uint32 time) //
{
	m_LastPrisheMagicTime = time;
}

void CAIGeneral::SetLastZeidArcaneCircleTime(uint32 time)
{
	m_LastZeidArcaneCircleTime = time;
}

void CAIGeneral::SetLastZeidWeaponBashTime(uint32 time)
{
	m_LastZeidWeaponBashTime = time;
}

void CAIGeneral::SetLastZeidLastResortTime(uint32 time)
{
	m_LastZeidLastResortTime = time;
}

void CAIGeneral::SetLastZeidMagicTime(uint32 time)
{
	m_LastZeidMagicTime = time;
}

void CAIGeneral::SetLastZeidAbsorbTime(uint32 time)
{
	m_LastZeidAbsorbTime = time;
}

void CAIGeneral::SetLastZeidAbsTPTime(uint32 time)
{
	m_LastZeidAbsTPTime = time;
}

void CAIGeneral::SetLastZeidAbsACCRecast(uint32 time)
{
	m_LastZeidAbsACCTime = time;
}

void CAIGeneral::SetLastZeidAbsSTRRecast(uint32 time)
{
	m_LastZeidAbsSTRTime = time;
}

void CAIGeneral::SetLastZeidEnfeebRecast(uint32 time)
{
	m_LastZeidEnfeebTime = time;
}

void CAIGeneral::SetLastZeidDrainRecast(uint32 time)
{
	m_LastZeidDrainTime = time;
}

void CAIGeneral::SetLastLionTrickAttackRecast(uint32 time)
{
   m_LastLionTrickAttackTime = time;
}

void CAIGeneral::SetLastLionCheckRecast(uint32 time)
{
    m_LastLionCheckTime = time;
}

void CAIGeneral::SetLastZeidSCTime(uint32 time)
{
    m_LastZeidSCTime = time;
}

void CAIGeneral::SetLastUniversalSCTime(uint32 time)
{
    m_LastUniversalSCTime = time;
}


void CAIGeneral::SetLastNajelithBerserkTime(uint32 time)
{
    m_LastNajelithBerserkTime = time;
}

void CAIGeneral::SetLastNajelithRangeTime(uint32 time)
{
    m_LastNajelithRangeTime = time;
}

void CAIGeneral::SetLastNajelithSharpshotTime(uint32 time)
{
    m_LastNajelithSharpshotTime = time;
}

void CAIGeneral::SetLastNajelithBarrageTime(uint32 time)
{
    m_LastNajelithBarrageTime = time;
}

void CAIGeneral::SetLastNajelithWSTime(uint32 time)
{
    m_LastNajelithWSTime = time;
}

void CAIGeneral::SetLastShantottoEleTime(uint32 time)
{
    m_LastShantottoEleTime = time;
}

void CAIGeneral::SetLastShantottoMagicTime(uint32 time)
{
    m_LastShantottoMagicTime = time;
}

void CAIGeneral::SetLastShantottoCheck(uint32 time)
{
    m_LastShantottoCheck = time;
}

void CAIGeneral::SetLastShantottoDebuffRecast(uint32 time)
{
    m_LastShantottoDebuffRecast = time;
}



void CAIGeneral::SetBattleTarget(CBattleEntity* PEntity)
{
	m_PBattleTarget = PEntity;
}

void CAIGeneral::SetBattleSubTarget(CBattleEntity* PEntity)
{
	m_PBattleSubTarget = PEntity;
}

/************************************************************************
*																		*
*																		*
*																		*
************************************************************************/

void CAIGeneral::SetCurrentSpell(uint16 SpellID)
{
	if (m_ActionType != ACTION_MAGIC_START   &&
		m_ActionType != ACTION_MAGIC_CASTING &&
		m_ActionType != ACTION_MAGIC_FINISH  &&
		m_ActionType != ACTION_MAGIC_INTERRUPT)
	{
        CSpell* spell = spell::GetSpell(SpellID);
        if (spell)
        {
            if (spell->getSpellGroup() == SPELLGROUP_BLUE)
            {
                m_PSpell = std::make_unique<CBlueSpell>(*static_cast<CBlueSpell*>(spell));
            }
            else
            {
                m_PSpell = std::make_unique<CSpell>(*spell);
            }
        }
        else
        {
            m_PSpell = nullptr;
        }
	}
}

/************************************************************************
*																		*
*	Gets Current Spell													*
*																		*
************************************************************************/

CSpell* CAIGeneral::GetCurrentSpell()
{
    // TODO: refactor this to only need magic state
	/*if (m_PMagicState != nullptr && m_PMagicState->GetSpell() != nullptr)
    {
        return m_PMagicState->GetSpell();
    }*/

	DSP_DEBUG_BREAK_IF(m_PSpell == nullptr);

	return m_PSpell.get();
}

/************************************************************************
*																		*
*	Set Weapon Skill													*
*																		*
************************************************************************/

void CAIGeneral::SetCurrentWeaponSkill(uint16 WSkillID)
{
	if (m_ActionType != ACTION_WEAPONSKILL_START   &&
		m_ActionType != ACTION_WEAPONSKILL_FINISH)
	{
		m_PWeaponSkill = std::unique_ptr<CWeaponSkill>(new CWeaponSkill(*battleutils::GetWeaponSkill(WSkillID)));
	}
}

/************************************************************************
*																		*
*	Gets Current Weapon Skill											*
*																		*
************************************************************************/

CWeaponSkill* CAIGeneral::GetCurrentWeaponSkill()
{
	DSP_DEBUG_BREAK_IF(m_PWeaponSkill == nullptr);

	return m_PWeaponSkill.get();
}

/************************************************************************
*																		*
*	Set Job Ability														*
*																		*
************************************************************************/

void CAIGeneral::SetCurrentJobAbility(uint16 JobAbilityID)
{
	if (m_ActionType != ACTION_JOBABILITY_START   &&
		m_ActionType != ACTION_JOBABILITY_FINISH)
	{
		m_PJobAbility = std::unique_ptr<CAbility>(new CAbility(*ability::GetAbility(JobAbilityID)));
	}
}

/************************************************************************
*																		*
*	Gets Current Job Ability											*
*																		*
************************************************************************/

CAbility* CAIGeneral::GetCurrentJobAbility()
{
	DSP_DEBUG_BREAK_IF(m_PJobAbility == nullptr);

	return m_PJobAbility.get();
}

/************************************************************************
*																		*
*  Получаем текущую цель физической атаки								*
*																		*
************************************************************************/

CBattleEntity* CAIGeneral::GetBattleTarget()
{
	//DSP_DEBUG_BREAK_IF(m_PBattleTarget == nullptr);

	return m_PBattleTarget;
}


/************************************************************************
*																		*
*  get battle sub target												*
*																		*
************************************************************************/

CBattleEntity* CAIGeneral::GetBattleSubTarget()
{
	return m_PBattleSubTarget;
}

/************************************************************************
*                                                                       *
*	Gets Mob Skill														*
*                                                                       *
************************************************************************/

CMobSkill* CAIGeneral::GetCurrentMobSkill()
{
	return m_PMobSkill.get();
}

/************************************************************************
*                                                                       *
*	Sets Mob Skill														*
*                                                                       *
************************************************************************/

void CAIGeneral::SetCurrentMobSkill(CMobSkill* skill)
{
    if (skill == nullptr)
    {
        m_PMobSkill = nullptr;
    }
    else
    {
        m_PMobSkill = std::unique_ptr<CMobSkill>(new CMobSkill(*skill));
    }
}

/************************************************************************
*                                                                       *
*	Gets/sets last used corsair roll									*
*                                                                       *
************************************************************************/

uint16 CAIGeneral::GetLastCorsairRoll()
{
	return m_CorsairDoubleUp;
}

void CAIGeneral::SetLastCorsairRoll(uint16 ability)
{
	m_CorsairDoubleUp = ability;
}

/************************************************************************
*                                                                       *
*	Gets/sets ability/attack behaviour									*
*                                                                       *
************************************************************************/

void CAIGeneral::SetAutoAttackEnabled(bool enabled)
{
	m_AutoAttackEnabled = enabled;
}
void CAIGeneral::SetMagicCastingEnabled(bool enabled)
{
    if(m_PMagicState != nullptr)
    {
        m_PMagicState->m_enableCasting = enabled;
    }
}
void CAIGeneral::SetMobAbilityEnabled(bool enabled)
{
	m_MobAbilityEnabled = enabled;
}

bool CAIGeneral::GetAutoAttackEnabled()
{
    return m_AutoAttackEnabled;
}

bool CAIGeneral::GetMagicCastingEnabled()
{
    if (m_PMagicState)
    {
        return m_PMagicState->m_enableCasting; 
    }
    return false;
}

bool CAIGeneral::GetMobAbilityEnabled()
{
    return m_MobAbilityEnabled;
}

bool CAIGeneral::IsInSleepableAction()
{
    switch(GetCurrentAction())
    {
        case ACTION_FALL:
        case ACTION_DROPITEMS:
        case ACTION_DEATH:
        case ACTION_FADE_OUT:
        case ACTION_DESPAWN:
            return false;
        default:
            return true;
    }
}

bool CAIGeneral::MoveTo(position_t* pos)
{
    if(m_PPathFind != nullptr && m_ActionType == ACTION_ROAMING){
        m_PPathFind->StepTo(pos);
        return true;
    }
    return false;
}

bool CAIGeneral::CanSeePoint(position_t pos)
{
    if(m_PPathFind != nullptr){
      return m_PPathFind->CanSeePoint(pos);
    }

    return true;
}

void CAIGeneral::Wait(int32 waitTime)
{
	if(waitTime == -1)
	{
		// wait forever
		m_WaitTime = 99999999;
	}
	else
	{
		m_WaitTime = waitTime;
	}

    m_LastWaitTime = m_Tick;
}


