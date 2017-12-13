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

#include "../../common/utils.h"

#include "../utils/battleutils.h"
#include "../utils/attackutils.h"
#include "../utils/charutils.h"
#include "../entities/charentity.h"
#include "../entities/petentity.h"
#include "../entities/mobentity.h"
#include "../entities/battleentity.h"
#include "../zone.h"
#include "../weapon_skill.h"
#include "../attack.h"
#include "../attackround.h"
#include "../mobskill.h"
#include "../utils/petutils.h"
#include "../utils/mobutils.h"
#include "../ability.h"
#include "../packets/char_health.h"

#include "../party.h"

#include "../lua/luautils.h"

#include "../packets/entity_update.h"
#include "../packets/action.h"
#include "../packets/char_update.h"
#include "../packets/pet_sync.h"
#include "../packets/message_basic.h"
#include "../entities/mobentity.h"

#include "states/magic_state.h"

#include "../alliance.h"
#include "ai_pet_dummy.h"
#include "ai_general.h"

/************************************************************************
*																		*
*																		*
*																		*
************************************************************************/


CAIPetDummy::CAIPetDummy(CPetEntity* PPet)
{
    m_PPet = PPet;
    m_queueSic = false;
    m_PTargetFind = new CTargetFind(PPet);
    m_PPathFind = new CPathFind(PPet);

    m_PMagicState = new CMagicState(PPet, m_PTargetFind);
	
	m_curillaVokeRecast = 30000;
	m_magicRecast = 6000;
	m_magicHealRecast = 25000;
	m_magicHealCast = 0;
	m_kupipiHealRecast = 12000;
	m_adelhiedHealRecast = 20000;
	m_adelhiedSub = 180000; // 3 minutes between using Sublimation if its completed
	m_kupipiEnhanceRecast = 10000;  // Enhancing such as Haste Pro/Shell and ~na's will share the same cast timer
	m_kupipiHealCast = 0;
	m_kupipiSolaceRecast = 7200000; // two hour duraton
	m_curillaFlashRecast = 50000;
	m_curillaBashRecast = 180000;
	m_curillaReprisalRecast = 180000;
	m_curillaChivalryRecast = 300000; 
	m_magicKupipiRecast = 4000;
	m_magicShantottoRecast = 7000;
	m_nanaacheck = 5000;  //For Nanaa Mihgo to check every 5 seconds if she is facing target or not
	m_nanaaSneakAttackRecast = 50000;
	
	m_ayameMeditateRecast = 180000;
	m_najiBerserkRecast = 300000;
	m_najiWarcryRecast = 300000;
	m_exeJumpRecast = 60000;
	m_exeHjumpRecast = 120000;
	m_exeSjumpRecast = 180000;
	m_exeAngonRecast = 120000;  // Angon 2 min
	m_ayameThirdEyeRecast = 45000;
	m_ayameSekkaRecast = 300000;  //300000;
	m_blueMagicRecast = 20000; //20 seconds Blue Magic Casting
	m_schEleRecast = 18000;
	m_schEnhRecast = 8000;
	m_sekkaStatus = 0; //Sekka off 0; Sekka Closing WS 1; Sekka Opening SC 2;
	
	m_blueCheck = 4000;  //Blue magic cast Check
	m_schCheck = 4000; //SCH Magic Cast Check
	m_blueChainAffinityRecast = 120000;
	m_blueMagicHealRecast = 12000;
	m_chainAffinityStatus = 0;  //CA off 0; CA closing 1; CA open with WS 2;
	m_magicburst = 0;
	m_luzafQuickRecast = 60000;
	m_luzafRollCheck = 20000;
	m_luzafFirstRollRecast = 300000;
	m_luzafSecondRollRecast = 300000;
	
	m_magicUlmiaRecast = 4000; //Song and Spell Check for Ulmia
	m_firstMeleeSongRecast = 140000;
    m_secondMeleeSongRecast = 140000;
    m_firstMageSongRecast = 130000;
    m_secondMageSongRecast = 130000;
	m_minuetStrongRecast = 130000;
    m_minuetWeakRecast = 130000; 
    m_madrigalStrongRecast = 130000; 
    m_madrigalWeakRecast = 130000; 
    m_marchStrongRecast = 130000; 
    m_marchWeakRecast = 130000; 
	m_balladStrongRecast = 130000; 
	m_balladWeakRecast = 130000; 
	m_songEnfeeble = 15000;
	m_songFront = 95000; // 1 min 35 seconds after ballad is cast move to front
	
	m_gesshoMagicRecast = 5000;
	m_gesshoVokeRecast = 30000;
	m_gesshoUtsuCheck = 15000;
	m_gesshoUtsuNiRecast = 45000;
	m_gesshoUtsuIchiRecast = 30000;
    m_gesshoEnfeeblingRecast = 25000;
	m_skillchainTrust = 10000;
	m_magicPrisheRecast = 4000;
	m_prisheHealRecast = 15000;
	
	m_zeidArcaneCircleRecast = 300000;
	m_zeidWeaponBashRecast = 180000;
	m_zeidLastResortRecast = 300000;
    m_zeidMagicRecast = 4000;
	m_zeidAbsorbRecast = 35000;
	m_zeidAbsTPRecast = 60000;
	m_zeidAbsACCRecast = 60000;
	m_zeidAbsSTRRecast = 60000;
	m_zeidEnfeebRecast = 45000;	
	m_zeidDrainRecast = 180000;
	m_lionTrickAttackRecast = 30000;  //change back to 60
	m_skillchainTimer = 10000;
	m_lionCheck = 10000;
	m_zeidSCReady = 0;
	
	m_najelithBerserkRecast = 300000;
	m_najelithRangedRecast = 15000;  // Ranged Attack every 11 seconds
	m_najelithSharpshotRecast = 300000;
	m_najelithBarrageRecast = 300000;

    m_shantottoEleRecast = 21000; // 18 second recast on Shantotto Spells	
	m_shantottoDebuffRecast = 8000;
	

	
	
}

/************************************************************************
*																		*
*  Основная часть интеллекта - главный цикл								*
*																		*
************************************************************************/

void CAIPetDummy::CheckCurrentAction(uint32 tick)
{
    m_Tick = tick;

    CBattleEntity* PSelf = m_PPet;

    //uncharm any pets if time is up
    if (tick > m_PPet->charmTime && m_PPet->isCharmed)
    {
        petutils::DespawnPet(m_PPet->PMaster);
        return;
    }

    switch (m_ActionType)
    {
        case ACTION_NONE:							                     break;
        case ACTION_ROAMING:	             ActionRoaming();	         break;
        case ACTION_DEATH:		             ActionDeath();		         break;
        case ACTION_SPAWN:		             ActionSpawn();		         break;
        case ACTION_FALL:		             ActionFall();		         break;
        case ACTION_ENGAGE:		             ActionEngage();	         break;
        case ACTION_ATTACK:		             ActionAttack();	         break;
        case ACTION_SLEEP:		             ActionSleep();		         break;
        case ACTION_DISENGAGE:	             ActionDisengage();	         break;
        case ACTION_MOBABILITY_START:	     ActionAbilityStart();	     break;
        case ACTION_MOBABILITY_USING:        ActionAbilityUsing();       break;
        case ACTION_MOBABILITY_FINISH:       ActionAbilityFinish();      break;
        case ACTION_MOBABILITY_INTERRUPT:    ActionAbilityInterrupt();   break;
        case ACTION_MAGIC_START:             ActionMagicStart();         break;
        case ACTION_MAGIC_CASTING:           ActionMagicCasting();       break;
        case ACTION_MAGIC_FINISH:            ActionMagicFinish();        break;
	    case ACTION_MAGIC_INTERRUPT:         ActionMagicInterrupt();     break;	
		case ACTION_WEAPONSKILL_FINISH:      ActionWeaponSkillFinish();  break;
		case ACTION_JOBABILITY_FINISH:       ActionJobAbilityFinish();   break;

        //default: DSP_DEBUG_BREAK_IF(true);
    }

    //check if this AI was replaced (the new AI will update if this is the case)
    if (m_PPet && PSelf->PBattleAI == this)
    {
        m_PPet->UpdateEntity();
    }
}

void CAIPetDummy::WeatherChange(WEATHER weather, uint8 element)
{

}

void CAIPetDummy::ActionAbilityStart()
{
    uint16 petID = m_PPet->m_PetID;
	uint8 lvl = m_PPet->PMaster->GetMLevel();
	uint8 wsrandom = 0;
    if (m_PPet->StatusEffectContainer->HasPreventActionEffect())
    {
        return;
    }
	
     //********************************************************//
	//   For Ayame to SC with.  Looks for your SC used       //
	//   element and decides on which SC to use             //
	//*****************************************************//
    
	uint32 masterscID = 0;
    if (m_PPet->m_PetID == PETID_AYAME)
    {
    	masterscID = charutils::GetVar((CCharEntity*)m_PPet->PMaster,"AyameSCElement");
		ShowWarning(CL_RED"AYAME SC NUMBER IS %u! \n" CL_RESET, masterscID);
	}	
		
	//uint32 lion = charutils::GetVar((CCharEntity*)m_PPet->PMaster,"LionPT");
	//uint32 prishe = charutils::GetVar((CCharEntity*)m_PPet->PMaster,"PrishePT");


    //For Trusts to SC with each other
	// 1 = TP Is ready
	// 2 = SC just performed
    //uint32 prishesc = charutils::GetVar((CCharEntity*)m_PPet->PMaster,"PrisheSC");
    //uint32 lionsc = charutils::GetVar((CCharEntity*)m_PPet->PMaster,"LionSC");
    //m_LastZeidSCTime = m_Tick;
   	

	

    
	

	 //Choose TP Move based on Trust Type
	 // This is essentially a hack to get this to work
	 //It iterates through blank skill ID's and then sets the current mob skill to the blank unused mob ability and also assigns the correct WS number via setcurrentws
	 //On prepare pet ability it then sends the information to actionweaponskillfinish and then plays the WS animation based on the WS number
	 //The mobskill is called via the fake blank skill which is named in the mob_skill.sql file with the damage modifiers
	 
	 //This section below is for nanaa to only use WS if SA timer is greater than 15 seconds	
	 if (m_PPet->m_PetID == PETID_NANAA_MIHGO && m_PPet->health.tp >= 1000 && m_PBattleTarget != nullptr) { 	
	        //ShowWarning("SA WS Active \n");
			int16 mobwsID = -1;
			uint8 wsrandom = dsprand::GetRandomNumber(1, 3);
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
		        //printf("Random Number: %d \n", wsrandom);
				if (lvl > 71){ // Set up so Nanaa can use either King Cobra Clamp or Dancing Edge at 71 or higher
				auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 2212 && wsrandom >= 2) { //King Kobra Clamp
                    SetCurrentMobSkill(PMobSkill);
			        //ShowWarning("KING KOBRA CLAMP \n");
                    break;
                    }
					//else if (PMobSkill->getID() == 2213) { //WASP STING
                    //SetCurrentMobSkill(PMobSkill);
			        //ShowWarning("WASP STING \n");
                    //break;
                    //}
					else if (PMobSkill->getID() == 2214 && wsrandom < 2) { //DANCING EDGE
                    SetCurrentMobSkill(PMobSkill);
			        //ShowWarning("DANCING EDGE \n");
                    break;
                    } 	

                } 
				else if (lvl > 59){ // Set up so Nanaa can only use Dancing Edge
				auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                    if (PMobSkill->getID() == 2214) { //DANCING EDGE
                    SetCurrentMobSkill(PMobSkill);
			        //ShowWarning("DANCING EDGE \n");
                    break;
                    } 	

                }
				else if (lvl > 32){ // Set up so Nanaa can only use Dancing Edge
				auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                    if (PMobSkill->getID() == 3800) { //Viper Bite
                    mobwsID = 17;
					SetCurrentMobSkill(PMobSkill);
			        SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Viper Bite \n");
                    break;
                    } 	

                }				
				else if (lvl > 5){ // Set up so Nanaa can only use wasp sting
				auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                    if (PMobSkill->getID() == 2213) { //Wasp Sting
                    SetCurrentMobSkill(PMobSkill);
			        //ShowWarning("WASP STING \n");
                    break;
                    } 	

                }			
			}	
            preparePetAbility(m_PBattleSubTarget);
            return;
        }	 
	 if (m_PPet->m_PetID == PETID_KUPIPI && m_PPet->health.tp >= 1000 && m_PBattleTarget != nullptr){
			int16 mobwsID = -1;
			if (lvl > 71) {
			uint8 wsrandom = dsprand::GetRandomNumber(1, 3); // Black Halo or Hexa Strike
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3774 && wsrandom >= 2) { //Hexa Strike
					mobwsID = 168;
					SetCurrentMobSkill(PMobSkill);
			        SetCurrentWeaponSkill(mobwsID);
                    break;
                    }
                    else if (PMobSkill->getID() == 3775 && wsrandom < 2) { //Black Halo
					mobwsID = 169;
					SetCurrentMobSkill(PMobSkill);
			        SetCurrentWeaponSkill(mobwsID);
                    break;
                    } 						

                }
            }
            else if (lvl > 64) {
			uint8 wsrandom = dsprand::GetRandomNumber(1, 3); //Hexa Strike or Judgement
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3774 && wsrandom >= 2) { //Hexa Strike
					mobwsID = 168;
					SetCurrentMobSkill(PMobSkill);
			        SetCurrentWeaponSkill(mobwsID);
                    break;
                    }
                    else if (PMobSkill->getID() == 3773 && wsrandom < 2) { //Judgement
					mobwsID = 167;
					SetCurrentMobSkill(PMobSkill);
			        SetCurrentWeaponSkill(mobwsID);
                    break;
                    } 						

                }
            }
            else if (lvl > 59) {
			uint8 wsrandom = dsprand::GetRandomNumber(1, 3); //Judgement or True STrike
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3773 && wsrandom >= 2) { //Judgement
					mobwsID = 167;
					SetCurrentMobSkill(PMobSkill);
			        SetCurrentWeaponSkill(mobwsID);
                    break;
                    }
                    else if (PMobSkill->getID() == 3772 && wsrandom < 2) { //True Strike
					mobwsID = 166;
					SetCurrentMobSkill(PMobSkill);
			        SetCurrentWeaponSkill(mobwsID);
                    break;
                    } 						

                }
            }
           else if (lvl > 54) {
			uint8 wsrandom = dsprand::GetRandomNumber(1, 3); //True Strike or Brainshaker
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3772 && wsrandom >= 2) { //True Strike
					mobwsID = 166;
					SetCurrentMobSkill(PMobSkill);
			        SetCurrentWeaponSkill(mobwsID);
                    break;
                    }
                    else if (PMobSkill->getID() == 3771 && wsrandom < 2) { //Brainshaker
					mobwsID = 162;
					SetCurrentMobSkill(PMobSkill);
			        SetCurrentWeaponSkill(mobwsID);
                    break;
                    } 						

                }
            }
          else if (lvl > 24) {
			uint8 wsrandom = dsprand::GetRandomNumber(1, 3); //True Strike or Brainshaker
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3771 && wsrandom >= 2) { //Brain Shaker
					mobwsID = 162;
					SetCurrentMobSkill(PMobSkill);
			        SetCurrentWeaponSkill(mobwsID);
                    break;
                    }
                    else if (PMobSkill->getID() == 3770 && wsrandom < 2) { //Shining Strike
					mobwsID = 160;
					SetCurrentMobSkill(PMobSkill);
			        SetCurrentWeaponSkill(mobwsID);
                    break;
                    } 						

                }
            }	
         else if (lvl > 4) {
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3770) { //Shinning Strike
					mobwsID = 160;
					SetCurrentMobSkill(PMobSkill);
			        SetCurrentWeaponSkill(mobwsID);
                    break;
					}

                }
            }			
            preparePetAbility(m_PBattleSubTarget);
			return;	
            }			
				
//Ayame Self Skillchain Decisions based on what element the player has used.  She will try to two step with player to close based on the WS they used most recently
//TODO set something if no element has been decided
	 if (m_PPet->m_PetID == PETID_AYAME && m_PPet->health.tp >= 2000 && m_PBattleTarget != nullptr && m_sekkaStatus == 2){  //start self sc
			int16 mobwsID = -1;		
			if (lvl > 71) {
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3784 && masterscID == 4) { //Tachi Kasha
                    mobwsID = 152;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Kasha \n");
                    break;
                    } 
  					else if (PMobSkill->getID() == 3783 && (masterscID == 2 || masterscID == 5 || masterscID == 12)) { //Tachi Gekko
                    mobwsID = 151;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Gekko \n");
                    break;
                    } 
  					else if (PMobSkill->getID() == 3782 && (masterscID == 1 || masterscID == 6 || masterscID == 11)) { //Tachi Yuki
                    mobwsID = 150;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Yuki \n");
                    break;
                    }
  					else if (PMobSkill->getID() == 3781 && (masterscID == 3 || masterscID == 10)) { //Tachi Jinpu
                    mobwsID = 148;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Jinpu \n");
                    break;
                    }
  					else if (PMobSkill->getID() == 3779 && (masterscID == 7 || masterscID == 8 || masterscID == 9)) { //Tachi Enpi
                    mobwsID = 144;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Enpi \n");
                    break;
                    }
                    else if (PMobSkill->getID() == 3783 && (masterscID == 0 || masterscID == 4)) { //Tachi Gekko
                    mobwsID = 151;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("No matching element Self SC Tachi: Geko to Tachi: Kasha \n");
                    break;					
                    } 
                }
			}
			else if (lvl >= 65) {
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3783 && (masterscID == 2 || masterscID == 5 || masterscID == 12)) { //Tachi Gekko
                    mobwsID = 151;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Gekko \n");
                    break;
                    } 
  					else if (PMobSkill->getID() == 3782 && (masterscID == 1 || masterscID == 6 || masterscID == 11)) { //Tachi Yuki
                    mobwsID = 150;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Yuki \n");
                    break;
                    }
  					else if (PMobSkill->getID() == 3781 && (masterscID == 3 || masterscID == 10)) { //Tachi Jinpu
                    mobwsID = 148;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Jinpu \n");
                    break;
                    }
  					else if (PMobSkill->getID() == 3779 && (masterscID == 7 || masterscID == 8 || masterscID == 9)) { //Tachi Enpi
                    mobwsID = 144;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Enpi \n");
                    break;
                    }
                    else if (PMobSkill->getID() == 3779 && (masterscID == 0 || masterscID == 4)) { //Tachi Yuki
                    mobwsID = 150;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("No matching element Self SC Tachi: Yuki to Tachi: Gekko \n");
                    break;
                    }						

                }
			}
			else if (lvl >= 60) {
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3782 && (masterscID == 1 || masterscID == 6 || masterscID == 11)) { //Tachi Yuki
                    mobwsID = 150;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Yuki \n");
                    break;
                    }
  					else if (PMobSkill->getID() == 3781 && (masterscID == 3 || masterscID == 10)) { //Tachi Jinpu
                    mobwsID = 148;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Jinpu \n");
                    break;
                    }
  					else if (PMobSkill->getID() == 3779 && (masterscID == 7 || masterscID == 8 || masterscID == 9)) { //Tachi Enpi
                    mobwsID = 144;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Starting Skillchain, Element 7, 8, or 9, Tachi: Enpi \n");
                    break;
                    }
                    else if(PMobSkill->getID() == 3779 & (masterscID == 0 || masterscID == 2 || masterscID == 4 || masterscID == 5 || masterscID == 12)) { //Tachi Enpi
                    mobwsID = 144;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("No matching element Self SC Tachi: Enpi to Tachi: Enpi \n");
                    break;
                    }						

                }
			}	
			else if (lvl >= 55) {
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3781 && (masterscID == 3 || masterscID == 10)) { //Tachi Jinpu
                    mobwsID = 148;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Jinpu \n");
                    break;
                    }
  					else if (PMobSkill->getID() == 3779 && (masterscID == 7 || masterscID == 8 || masterscID == 9)) { //Tachi Enpi
                    mobwsID = 144;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Enpi \n");
                    break;
                    }
                    else if (PMobSkill->getID() == 3779 & (masterscID == 0 || masterscID == 1 || masterscID == 2 || masterscID == 4 || masterscID == 5 || masterscID == 6 || masterscID == 11 || masterscID == 12)) { //Tachi Enpi
                    mobwsID = 144;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("No matching element Self SC Tachi: Enpi to Tachi: Enpi \n");
                    break;
                    }						

                }
			}
			else if (lvl >= 40) {
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3779 && (masterscID == 7 || masterscID == 8 || masterscID == 9)) { //Tachi Enpi
                    mobwsID = 144;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Enpi \n");
                    break;
                    }
                    else if (PMobSkill->getID() == 3779 && (masterscID == 0 || masterscID == 1 || masterscID == 2 || masterscID == 3 || masterscID == 4 || masterscID == 5 
					 || masterscID == 6 || masterscID == 10 || masterscID == 11 || masterscID == 12)) { //Tachi Enpi
                    mobwsID = 144;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("No matching element Self SC Tachi: Enpi to Tachi: Enpi \n");
                    break;
                    }						

                }
			}				
			m_sekkaStatus = 1; //set for closing sekka skillchain
			preparePetAbility(m_PBattleSubTarget);
            return;
        }	
//Ayame closing self SC		
	 if (m_PPet->m_PetID == PETID_AYAME && m_PPet->health.tp >= 1000 && m_PBattleTarget != nullptr && m_sekkaStatus == 1){  //end self sc
			int16 mobwsID = -1;		
			if (lvl > 71) {
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3784 && (masterscID == 1 || masterscID == 6 || masterscID == 10 || masterscID == 12)) { //Tachi Kasha
                    mobwsID = 152;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Kasha \n");
                    break;
                    } 
  					else if (PMobSkill->getID() == 3783 && (masterscID == 7 || masterscID == 8 || masterscID == 11)) { //Tachi Gekko
                    mobwsID = 151;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Gekko \n");
                    break;
                    } 
  					else if (PMobSkill->getID() == 3782 && (masterscID == 2 || masterscID == 5)) { //Tachi Yuki
                    mobwsID = 150;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Yuki \n");
                    break;
                    }
  					else if (PMobSkill->getID() == 3779 && (masterscID == 3 || masterscID == 4 || masterscID == 9)) { //Tachi Enpi
                    mobwsID = 144;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Enpi \n");
                    break;
                    }
                    else if (PMobSkill->getID() == 3784 && (masterscID == 0)) { //Tachi Kasha
                    mobwsID = 152;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Enpi \n");
                    break;
                    }					

                }
			}
			else if (lvl >= 65) {
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                    if (PMobSkill->getID() == 3783 && (masterscID == 7 || masterscID == 8 || masterscID == 11)) { //Tachi Gekko
                    mobwsID = 151;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Gekko \n");
                    break;
                    } 
  					else if (PMobSkill->getID() == 3782 && (masterscID == 2 || masterscID == 5)) { //Tachi Yuki
                    mobwsID = 150;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Yuki \n");
                    break;
                    }
  					else if (PMobSkill->getID() == 3779 && (masterscID == 3 || masterscID == 4 || masterscID == 9)) { //Tachi Enpi
                    mobwsID = 144;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Enpi \n");
                    break;
                    }
                    else if (PMobSkill->getID() == 3779 && (masterscID == 1 || masterscID == 6 || masterscID == 10 || masterscID == 12)) { //Tachi Enpi
                    mobwsID = 144;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Enpi \n");
                    break;
                    }
                    else if (PMobSkill->getID() == 3783 && (masterscID == 0)) { //Tachi Gekko
                    mobwsID = 151;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Enpi \n");
                    break;
                    }					

                }
			}	
			else if (lvl >= 60) {
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                    if (PMobSkill->getID() == 3782 && (masterscID == 2 || masterscID == 5)) { //Tachi Yuki
                    mobwsID = 150;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Yuki \n");
                    break;
                    }
  					else if (PMobSkill->getID() == 3779 && (masterscID == 3 || masterscID == 4 || masterscID == 9)) { //Tachi Enpi
                    mobwsID = 144;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Enpi with Element 3,4, or 9 \n");
                    break;
                    }
                    else if (PMobSkill->getID() == 3779 && (masterscID == 1 || masterscID == 6 || masterscID == 7 || masterscID == 8 || masterscID == 10 || masterscID == 11 || masterscID == 12)) { //Tachi Enpi
                    mobwsID = 144;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Enpi nothing else found \n");
                    break;
                    }					

                }
			}
			else if (lvl >= 5) {
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                    if (PMobSkill->getID() == 3779 && (masterscID == 3 || masterscID == 4 || masterscID == 9)) { //Tachi Enpi
                    mobwsID = 144;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Enpi \n");
                    break;
                    }
                    else if (PMobSkill->getID() == 3779 && (masterscID == 1 || masterscID == 2 || masterscID == 5 || masterscID == 6 || masterscID == 7 || masterscID == 8 || 
					masterscID == 10 || masterscID == 11 || masterscID == 12)) { //Tachi Enpi
                    mobwsID = 144;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Enpi \n");
                    break;
                    }					

                }
			}			
			m_sekkaStatus = 0; //Set Sekka status to 0 or off
			preparePetAbility(m_PBattleSubTarget);
            return;
        }	






           
        
	 if (m_PPet->m_PetID == PETID_AYAME && m_PPet->health.tp >= 1000 && m_PBattleTarget != nullptr && (masterscID == 0 || masterscID == 10 || masterscID > 12)){  //no sc element detected from user or usable sc
			int16 mobwsID = -1;		
			if (lvl > 71) {
			uint8 wsrandom = dsprand::GetRandomNumber(1, 3); //Gekko or Kasha only 70+ for right now
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3784 && wsrandom >= 2) { //Tachi Kasha
                    mobwsID = 152;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Kasha \n");
                    break;
                    } 
  					else if (PMobSkill->getID() == 3783 && wsrandom < 2) { //Tachi Gekko
                    mobwsID = 151;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Gekko \n");
                    break;
                    } 					

                }
			}
			else if (lvl > 64) {
			uint8 wsrandom = dsprand::GetRandomNumber(1, 3); //Gekko or Kasha only 70+ for right now
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3783 && wsrandom >= 2) { //Tachi Gekko
                    mobwsID = 151;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Gekko \n");
                    break;
                    } 
  					else if (PMobSkill->getID() == 3782 && wsrandom < 2) { //Tachi Yuki
                    mobwsID = 150;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Yuki \n");
                    break;
                    } 					

                }
			}				
			else if (lvl > 59) {
			uint8 wsrandom = dsprand::GetRandomNumber(1, 3); //Yuki or Jinpu only 
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3782 && wsrandom >= 2) { //Tachi Yuki
                    mobwsID = 150;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Yuki \n");
                    break;
                    } 
  					else if (PMobSkill->getID() == 3781 && wsrandom < 2) { //Tachi Jinpu
                    mobwsID = 148;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Jinpu \n");
                    break;
                    } 					

                }
			}
			else if (lvl > 54) {
			uint8 wsrandom = dsprand::GetRandomNumber(1, 4); //Jinpu or goten or Enpi
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3779 && wsrandom <= 2) { //Tachi Enpi
                    mobwsID = 144;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Enpi \n");
                    break;
                    }
  					else if (PMobSkill->getID() == 3780 && wsrandom == 3) { //Tachi Goten
                    mobwsID = 146;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Goten \n");
                    break;
                    } 								
  					else if (PMobSkill->getID() == 3781 && wsrandom == 4) { //Tachi Jinpu
                    mobwsID = 148;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Jinpu \n");
                    break;
                    } 					

                }
			}			
			else if (lvl > 23) {
			uint8 wsrandom = dsprand::GetRandomNumber(1, 3); //Jinpu or goten or Enpi
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3779 && wsrandom >= 2) { //Tachi Enpi
                    mobwsID = 144;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Enpi \n");
                    break;
                    }
  					else if (PMobSkill->getID() == 3780 && wsrandom < 2) { //Tachi Goten
                    mobwsID = 146;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Goten \n");
                    break;
                    } 													

                }
			}
			else if (lvl > 4) {
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3779) { //Tachi Enpi
                    mobwsID = 144;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Enpi \n");
                    break;
					}						

                }
			}			
			preparePetAbility(m_PBattleSubTarget);
            return;
        }		
	 if (m_PPet->m_PetID == PETID_AYAME && m_PPet->health.tp >= 1000 && m_PBattleTarget != nullptr && masterscID > 0){  //sc element detected from user
			int16 mobwsID = -1;		
			if (lvl > 71) {
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3784 && (masterscID == 1 || masterscID == 2 || masterscID == 6 || masterscID == 12)) { //Tachi Kasha
                    mobwsID = 152;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Kasha \n");
                    break;
                    } 
  					else if (PMobSkill->getID() == 3783 && (masterscID == 7 || masterscID == 8 || masterscID == 9 || masterscID == 11)) { //Tachi Gekko
                    mobwsID = 151;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Gekko \n");
                    break;
					}
  					else if (PMobSkill->getID() == 3782 && (masterscID == 4 || masterscID == 5)) { //Tachi Yukki
                    mobwsID = 150;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Yukki \n");
                    break;					
                    } 
  					else if (PMobSkill->getID() == 3779 && (masterscID == 3 )) { //Tachi Enpi
                    mobwsID = 144;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Enpi \n");
                    break;					
                    }					

                }
			}
			else if (lvl > 64) {
			uint8 wsrandom = dsprand::GetRandomNumber(1, 3); //Gekko or Kasha only 70+ for right now
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3783 && wsrandom >= 2) { //Tachi Gekko
                    mobwsID = 151;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Gekko \n");
                    break;
                    } 
  					else if (PMobSkill->getID() == 3782 && wsrandom < 2) { //Tachi Yuki
                    mobwsID = 150;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Yuki \n");
                    break;
                    } 					

                }
			}				
			else if (lvl > 59) {
			uint8 wsrandom = dsprand::GetRandomNumber(1, 3); //Yuki or Jinpu only 
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3782 && wsrandom >= 2) { //Tachi Yuki
                    mobwsID = 150;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Yuki \n");
                    break;
                    } 
  					else if (PMobSkill->getID() == 3781 && wsrandom < 2) { //Tachi Jinpu
                    mobwsID = 148;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Jinpu \n");
                    break;
                    } 					

                }
			}
			else if (lvl > 54) {
			uint8 wsrandom = dsprand::GetRandomNumber(1, 4); //Jinpu or goten or Enpi
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3779 && wsrandom <= 2) { //Tachi Enpi
                    mobwsID = 144;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Enpi \n");
                    break;
                    }
  					else if (PMobSkill->getID() == 3780 && wsrandom == 3) { //Tachi Goten
                    mobwsID = 146;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Goten \n");
                    break;
                    } 								
  					else if (PMobSkill->getID() == 3781 && wsrandom == 4) { //Tachi Jinpu
                    mobwsID = 148;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Jinpu \n");
                    break;
                    } 					

                }
			}			
			else if (lvl > 23) {
			uint8 wsrandom = dsprand::GetRandomNumber(1, 3); //Jinpu or goten or Enpi
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3779 && wsrandom >= 2) { //Tachi Enpi
                    mobwsID = 144;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Enpi \n");
                    break;
                    }
  					else if (PMobSkill->getID() == 3780 && wsrandom < 2) { //Tachi Goten
                    mobwsID = 146;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Goten \n");
                    break;
                    } 													

                }
			}
			else if (lvl > 4) {
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3779) { //Tachi Enpi
                    mobwsID = 144;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Tachi: Enpi \n");
                    break;
					}						

                }
			}			
			preparePetAbility(m_PBattleSubTarget);
            return;
        }				
		
		
		
		
	 if (m_PPet->m_PetID == PETID_NAJI && m_PPet->health.tp >= 1000 && m_PBattleTarget != nullptr){
			int16 mobwsID = -1;		
			if (lvl > 59) {
			m_PJobAbility = nullptr;
			uint8 wsrandom = dsprand::GetRandomNumber(1, 10); //Vorpal
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                    if (PMobSkill->getID() == 3742) { //Vorpal Blade Exclusively for now
                    mobwsID = 40;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Vorpal Blade \n");
                    break;
                    } 					

                }
			}
			else if (lvl > 25) {
			m_PJobAbility = nullptr;
			uint8 wsrandom = dsprand::GetRandomNumber(1, 30); //Red Lotus, Fast Blade, or Flat Blade
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                    if (PMobSkill->getID() == 3741 && wsrandom >= 20) { //Flat Blade
                    mobwsID = 35;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);			    
                    break;
                    }  
                    else if (PMobSkill->getID() == 3740 && wsrandom >= 10 && wsrandom < 20) { //Red Lotus Blade
                    mobwsID = 34;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
                    break;
                    } 
  					else if (PMobSkill->getID() == 3739 && wsrandom < 10) { //Fast Blade
                    mobwsID = 32;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
                    break;
                    } 					

                }
			}			
			else if (lvl > 16) {
			m_PJobAbility = nullptr;
			uint8 wsrandom = dsprand::GetRandomNumber(1, 10); //Red Lotus or Fast Blade
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3740 && wsrandom >= 6) { //Red Lotus Blade
                    mobwsID = 34;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Red Lotus Blade \n");
                    break;
                    } 
  					else if (PMobSkill->getID() == 3739 && wsrandom < 6) { //Fast Blade
                    mobwsID = 32;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Vorpal Blade \n");
                    break;
                    } 					

                }
			}			
			else if (lvl > 4) {
			m_PJobAbility = nullptr;
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3739) { //Fast Blade
                    mobwsID = 32;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
                    break;
                    } 					

                }
			}			
            preparePetAbility(m_PBattleSubTarget);
            return;
        }

	if (m_PPet->m_PetID == PETID_CURILLA && m_PPet->health.tp >= 1000 && m_PBattleTarget != nullptr){
			int16 mobwsID = -1;		
			if (lvl > 64) {
			m_PJobAbility = nullptr;
			uint8 wsrandom = dsprand::GetRandomNumber(1, 10); //Swift Blade or Vorpal
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3743 && wsrandom >= 6) { //Swift Blade
                    mobwsID = 41;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Swift Blade \n");
                    break;
                    } 
  					else if (PMobSkill->getID() == 3742 && wsrandom < 6) { //Vorpal Blade
                    mobwsID = 40;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Vorpal Blade \n");
                    break;
                    } 					

                }
			}
			else if (lvl > 59) {
			m_PJobAbility = nullptr;
			uint8 wsrandom = dsprand::GetRandomNumber(1, 10); //Vorpal or Fast Blade
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3739 && wsrandom >= 6) { //Fast Blade
                    mobwsID = 32;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
                    break;
                    } 
  					else if (PMobSkill->getID() == 3742 && wsrandom < 6) { //Vorpal Blade
                    mobwsID = 40;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
                    break;
                    } 					

                }
			}
			else if (lvl > 4) {
			m_PJobAbility = nullptr;
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3739) { //Fast Blade
                    mobwsID = 32;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Red Lotus Blade \n");
                    break;
                    } 					

                }
			}			
            preparePetAbility(m_PBattleSubTarget);
            return;
        }	
		
		if (m_PPet->m_PetID == PETID_EXCENMILLE && m_PPet->health.tp >= 1000 && m_PBattleTarget != nullptr && (m_Tick >= m_LastExeJumpTime + 4000 || m_Tick >= m_LastExeHjumpTime + 4000 )){  //If jumped recently WS after 5 sec
			int16 mobwsID = -1;		
			if (lvl > 64) {
			m_PJobAbility = nullptr;
			uint8 wsrandom = dsprand::GetRandomNumber(1, 10); //Wheeling Thrust or Penta
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3792 && wsrandom >= 6) { //Wheeling Thrust
                    mobwsID = 119;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
                    break;
                    } 
  					else if (PMobSkill->getID() == 3791 && wsrandom < 6) { //Penta Thrust
                    mobwsID = 116;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
                    break;
                    } 					

                }
			}
			else if (lvl > 48) {
			m_PJobAbility = nullptr;
			uint8 wsrandom = dsprand::GetRandomNumber(1, 10); //Penta or Leg sweep
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3791 && wsrandom >= 6) { //Penta Thrust
                    mobwsID = 116;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Red Lotus Blade \n");
                    break;
                    } 
  					else if (PMobSkill->getID() == 3790 && wsrandom < 6) { //Leg Sweep
                    mobwsID = 115;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Vorpal Blade \n");
                    break;
                    } 					

                }
			}
			else if (lvl > 32) {
			m_PJobAbility = nullptr;
			uint8 wsrandom = dsprand::GetRandomNumber(1, 10); //Double or Leg Sweep
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3790 && wsrandom >= 6) { //Leg sweep
                    mobwsID = 115;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Red Lotus Blade \n");
                    break;
                    } 
  					else if (PMobSkill->getID() == 3789 && wsrandom < 6) { //Double Thrust
                    mobwsID = 112;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Vorpal Blade \n");
                    break;
                    } 					

                }
			}
			else if (lvl > 4) {
			m_PJobAbility = nullptr;
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3789) { //Double Thrust
                    mobwsID = 112;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Red Lotus Blade \n");
                    break;
                    } 					
                }
			}			
            preparePetAbility(m_PBattleSubTarget);
            return;
        }
		
    //If BLUE MAGE has Chain Affinity Active
	if (m_PPet->m_PetID == PETID_BLUE && m_PPet->health.tp >= 1000 && m_PBattleTarget != nullptr && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_CHAIN_AFFINITY) == true && m_chainAffinityStatus == 2){
			int16 mobwsID = -1;		
			if (lvl > 71) {
			m_PJobAbility = nullptr;
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3744) { //Savage Blade
                    mobwsID = 42;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
                    break;
                    } 					

                }
			}
			else if (lvl > 39) {
			m_PJobAbility = nullptr;
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3740) { //Red Lotus
                    mobwsID = 34;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Red Lotus Blade \n");
                    break;					
                    } 					

                }
			}	
            m_LastBlueCheck = m_Tick + 1000;
            m_chainAffinityStatus = 1;			
            preparePetAbility(m_PBattleSubTarget);
            return;
        }



		

		if (m_PPet->m_PetID == PETID_BLUE && m_PPet->health.tp >= 1000 && m_PBattleTarget != nullptr){
			int16 mobwsID = -1;		
			if (lvl > 59) {
			m_PJobAbility = nullptr;
			uint8 wsrandom = dsprand::GetRandomNumber(1, 10); //Swift Blade or Vorpal
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3740 && wsrandom >= 6) { //Red Lotus Blade
                    mobwsID = 34;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
                    break;
                    } 
  					else if (PMobSkill->getID() == 3742 && wsrandom < 6) { //Vorpal Blade
                    mobwsID = 40;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
                    break;
                    } 					

                }
			}
			else if (lvl > 16) {
			m_PJobAbility = nullptr;
			uint8 wsrandom = dsprand::GetRandomNumber(1, 10);
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3740 && wsrandom >= 6) { //Red Lotus
                    mobwsID = 34;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Red Lotus Blade \n");
                    break;
                    } 
  					else if (PMobSkill->getID() == 3739 && wsrandom < 6) { //Fast
                    mobwsID = 32;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
                    break;					
                    } 					

                }
			}				
			else if (lvl > 4) {
			m_PJobAbility = nullptr;
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3739) { //Fast Blade
                    mobwsID = 32;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Red Lotus Blade \n");
                    break;
                    } 					

                }
			}			
            preparePetAbility(m_PBattleSubTarget);
            return;
        }

	 if (m_PPet->m_PetID == PETID_ADELHIED && m_PPet->health.tp >= 1000 && m_PBattleTarget != nullptr){
			int16 mobwsID = -1;		
			if (lvl > 4) {
			m_PJobAbility = nullptr;
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3770) { //Shinning Strike
					mobwsID = 162;
					SetCurrentMobSkill(PMobSkill);
			        SetCurrentWeaponSkill(mobwsID);
                    break;
                    } 					

                }
			}		
            preparePetAbility(m_PBattleSubTarget);
            return;
        }
		
		
		CBattleEntity* lionSCPartner = getLionSCPartnerZeid();
		CBattleEntity* zeidSCPartner = getZeidSCPartner();
		
		if (m_PPet->m_PetID == PETID_LION && m_PPet->health.tp >= 1000 && lionSCPartner != nullptr) //KITTY
		{
		    if (lionSCPartner->health.tp >= 1000)
			{
			    if (lvl >= 71 && m_PPet->m_PetID == PETID_LION) 
				{  
                    //ShowWarning(CL_RED"LION ATTEMPTING WS\n" CL_RESET);			
			        uint8 wsrandom = dsprand::GetRandomNumber(1, 3); 
                    for (int i = 0; i < m_PPet->PetSkills.size(); i++) 
					{
                        auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  			            if (PMobSkill->getID() == 2636 && wsrandom < 2) //Pirate Pummel
						{ 
                         	//Write the SC to a variable for the player
			                int32 value = 1;  //Dark SC
			                std::string varname;
			                const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'ZeidSCReady', value = '1' ON DUPLICATE KEY UPDATE value = '1';";
                            Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);	
				            //End Write of SC to variable for player   
							SetCurrentMobSkill(PMobSkill);
                            break;
                        }
  			            else if (PMobSkill->getID() == 2638 && wsrandom >= 2) //Walk the Plank
						{ 
                         	//Write the SC to a variable for the player
			                int32 value = 2;  //Light SC
			                std::string varname;
			                const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'ZeidSCReady', value = '2' ON DUPLICATE KEY UPDATE value = '2';";
                            Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);	
				            //End Write of SC to variable for player   
							SetCurrentMobSkill(PMobSkill);
                            break;
                        }						
                    }
			    }
			    else if (lvl >= 65 && m_PPet->m_PetID == PETID_LION) 
				{      
                    for (int i = 0; i < m_PPet->PetSkills.size(); i++) 
					{
                        auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  			            if (PMobSkill->getID() == 2636) //Pirate Pummel
						{ 
                         	//Write the SC to a variable for the player
			                int32 value = 2;  //Fragmentation Skillchain With Zeid Close with SS
			                std::string varname;
			                const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'ZeidSCReady', value = '2' ON DUPLICATE KEY UPDATE value = '2';";
                            Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);	
				            //End Write of SC to variable for player   
							SetCurrentMobSkill(PMobSkill);
                            break;
                        }						
                    }
			    }
			    else if (lvl >= 60 && m_PPet->m_PetID == PETID_LION) 
				{      
                    for (int i = 0; i < m_PPet->PetSkills.size(); i++) 
					{
                        auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  			            if (PMobSkill->getID() == 2637) //Powder Keg
						{ 
                         	//Write the SC to a variable for the player
			                int32 value = 3;  //Fusion Skillchain With Zeid Close with Siclkle Moon
			                std::string varname;
			                const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'ZeidSCReady', value = '3' ON DUPLICATE KEY UPDATE value = '3';";
                            Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);	
				            //End Write of SC to variable for player   
							SetCurrentMobSkill(PMobSkill);
                            break;
                        }						
                    }
			    }
			    else if (lvl >= 33 && m_PPet->m_PetID == PETID_LION) 
				{      
                    for (int i = 0; i < m_PPet->PetSkills.size(); i++) 
					{
                        auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  			            if (PMobSkill->getID() == 2635) //Grape Shot
						{ 
                         	//Write the SC to a variable for the player
			                int32 value = 4;  //Induration Skillchain With Zeid Close with Freezebite
			                std::string varname;
			                const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'ZeidSCReady', value = '4' ON DUPLICATE KEY UPDATE value = '4';";
                            Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);	
				            //End Write of SC to variable for player   
							SetCurrentMobSkill(PMobSkill);
                            break;
                        }						
                    }
			    }
			    else if (lvl >= 5 && m_PPet->m_PetID == PETID_LION) 
				{      
                    for (int i = 0; i < m_PPet->PetSkills.size(); i++) 
					{
                        auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  			            if (PMobSkill->getID() == 2637) //Powder Keg
						{ 
                         	//Write the SC to a variable for the player
			                int32 value = 5;  //Scission Skillchain With Zeid Close with Hard Slash
			                std::string varname;
			                const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'ZeidSCReady', value = '5' ON DUPLICATE KEY UPDATE value = '5';";
                            Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);	
				            //End Write of SC to variable for player   
							SetCurrentMobSkill(PMobSkill);
                            break;
                        }						
                    }
			    }				
			}
            preparePetAbility(m_PBattleSubTarget);
            return;				
		}
		else if (m_PPet->m_PetID == PETID_LION && m_PPet->health.tp >= 1000 && lionSCPartner == nullptr)
		{
		
		
		
		
		
		/*
        if (m_Tick >= m_LastPrisheSCTime && m_PPet->m_PetID == PETID_LION && m_PPet->health.tp >= 1000 && m_PBattleTarget != nullptr && prishe == 1 &&
		lionSCPartner == nullptr)
		{   
		    printf("Pre Check time is: %u \n", m_LastPrisheSCTime);
		    //uint32 finaltime = (m_LastPrisheSCTime + 8000);
		    ShowWarning(CL_GREEN"LION HAS TP, Check Time: %u \n" CL_RESET, m_LastPrisheSCTime);
		    if (prishesc == 5) //If Prishe is in pt and Prishe just used a sc
			{
                if (lvl >= 71) {
			        for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  				        if (PMobSkill->getID() == 2638) { //Walk the Plank
                        SetCurrentMobSkill(PMobSkill);
						lionsc = 0;
						prishesc = 0;
                        break;
                        }				
                    }
                }
                else if (lvl >= 5) {
			        for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  				        if (PMobSkill->getID() == 2635) { //Grape Shot
                        SetCurrentMobSkill(PMobSkill);
						lionsc = 0;
						prishesc = 0;
                        break;
                        }				
                    }
                }				
            }
            else
            {
			    //Lion has TP and is now ready to SC.  Set Variable as such.
			    int32 value = 1;
			    std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'LionSC', value = '1' ON DUPLICATE KEY UPDATE value = '1';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);	
            }
            preparePetAbility(m_PBattleSubTarget);
            return;		
		} */    		
		
		
		if ((m_PPet->m_PetID == PETID_LION && m_PPet->health.tp >= 1000 && m_PBattleTarget != nullptr)){
		    ShowWarning(CL_GREEN"PRISHE OR ZEID IS NOT IN PT AT THE MOMENT!! \n" CL_RESET);
            if (lvl >= 71) {      
			uint8 wsrandom = dsprand::GetRandomNumber(1, 5); 
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 2638 && wsrandom == 4) { //Walk the Plank
                    SetCurrentMobSkill(PMobSkill);
                    break;
                    }
  					else if (PMobSkill->getID() == 2636 && wsrandom == 3) { //Pirate Pummel
                    SetCurrentMobSkill(PMobSkill);
                    break;
                    }
  					else if (PMobSkill->getID() == 2635 && wsrandom == 2) { //Grape Shot
                    SetCurrentMobSkill(PMobSkill);
                    break;
                    }
  					else if (PMobSkill->getID() == 2637 && wsrandom == 1) { //Powder Keg
                    SetCurrentMobSkill(PMobSkill);
                    break;
                    } 					
                }
			}
           else if (lvl >= 60) {      
			uint8 wsrandom = dsprand::GetRandomNumber(1, 4); 
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 2636 && wsrandom == 3) { //Pirate Pummel
                    SetCurrentMobSkill(PMobSkill);
                    break;
                    }
  					else if (PMobSkill->getID() == 2635 && wsrandom == 2) { //Grape Shot
                    SetCurrentMobSkill(PMobSkill);
                    break;
                    }
  					else if (PMobSkill->getID() == 2637 && wsrandom == 1) { //Powder Keg
                    SetCurrentMobSkill(PMobSkill);
                    break;
                    } 					
                }
			}
           else if (lvl >= 5) {      
			uint8 wsrandom = dsprand::GetRandomNumber(1, 3); 
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 2635 && wsrandom == 2) { //Grape Shot
                    SetCurrentMobSkill(PMobSkill);
                    break;
                    }
  					else if (PMobSkill->getID() == 2637 && wsrandom == 1) { //Powder Keg
                    SetCurrentMobSkill(PMobSkill);
                    break;
                    } 					
                }
			}			
            preparePetAbility(m_PBattleSubTarget);
            return;		
		    }
		}
		
		// TODO REDO PRISHE SC STUFF BASED on SC PARTNER
		
		
	    /*
		if (m_PPet->m_PetID == PETID_PRISHE && m_PPet->health.tp >= 1000 && m_PBattleTarget != nullptr && lion == 1) 
		{
            m_LastPrisheSCTime = m_Tick + 8000; 
			ShowWarning(CL_GREEN"PRISHE SKILLCHAIN INITIATE m_Tick is: %u \n" CL_RESET, m_Tick);			
			ShowWarning(CL_GREEN"Skillchain timer set to: %u \n" CL_RESET, m_LastPrisheSCTime);
            if (lionsc == 1) //Lion has TP and is ready for a sc    
			{	
			    if (lvl >= 71) 
			    {
				    //Forcibly Open with a specific WS when Lion is at 1000% TP
			        for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					    if (PMobSkill->getID() == 2639) { //Knuckle Sandwhich
                        SetCurrentMobSkill(PMobSkill);
						//m_LastPrisheSCTime = m_Tick;
                        break;
                        }					
                    }
			    }
			    else if (lvl >= 5) 
			    {
				    //Forcibly Open with a specific WS when Lion is at 1000% TP
			        for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					    if (PMobSkill->getID() == 1233) { //Nullyfying Dropkick
                        SetCurrentMobSkill(PMobSkill);
						//m_LastPrisheSCTime = m_Tick;
                        break;
                        }					
                    }
			    }	
            }				
            preparePetAbility(m_PBattleSubTarget); 
			return;                
		}		
        
		
		
		if (m_PPet->m_PetID == PETID_PRISHE && m_PPet->health.tp >= 1000 && m_PBattleTarget != nullptr && lion != 1){
			if (lvl >= 71) 
			{		
				uint8 wsrandom = dsprand::GetRandomNumber(1, 4); 
                for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  				    if (PMobSkill->getID() == 2639 && wsrandom == 3) { //Knuckle Sandwhich
                    SetCurrentMobSkill(PMobSkill);
                    break;
                    }
  				    else if (PMobSkill->getID() == 1234 && wsrandom == 2) { //Auruoral Uppercut
                    SetCurrentMobSkill(PMobSkill);
                    break;
                    }
  				    else if (PMobSkill->getID() == 1233 && wsrandom == 1) { //Nullyfying Dropkick
                    SetCurrentMobSkill(PMobSkill);
                    break;
                    } 					
                }
			}
            else if (lvl >= 5) {      
			uint8 wsrandom = dsprand::GetRandomNumber(1, 3); 
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 1234 && wsrandom == 2) { //Knuckle Sandwhich
                    SetCurrentMobSkill(PMobSkill);
                    break;
                    }
  					else if (PMobSkill->getID() == 1233 && wsrandom == 1) { //Nullyfying Dropkick
                    SetCurrentMobSkill(PMobSkill);
                    break;
                    } 					
                }
			}			
            preparePetAbility(m_PBattleSubTarget);
            return;		
		}	
        */			
		
		
		
		
		
		
        if (m_PPet->m_PetID == PETID_LUZAF && m_PPet->health.tp >= 1000 && m_PBattleTarget != nullptr){
			int16 mobwsID = -1;	
			if (lvl > 74 && m_PBattleTarget->getMod(MOD_PIERCERES) < 0) {      //Exclusively Use Slugshot if the mob is weak to piercing
			m_PJobAbility = nullptr;
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3732) { //Slugshot
                    mobwsID = 212;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
                    break;
                    } 				
                }
			}
			else if (lvl > 74) {
			m_PJobAbility = nullptr;
			uint8 wsrandom = dsprand::GetRandomNumber(1, 10); //Leaden Salute or Slugshot
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3732 && wsrandom >= 6) { //Slugshot
                    mobwsID = 212;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Swift Blade \n");
                    break;
                    } 
  					else if (PMobSkill->getID() == 3733 && wsrandom < 6) { //Leaden Salute
                    mobwsID = 218;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Vorpal Blade \n");
                    break;
                    } 					

                }
			}
			else if (lvl > 59 && m_PBattleTarget->getMod(MOD_PIERCERES) < 0) {      //Exclusively Use Slugshot if the mob is weak to piercing
			m_PJobAbility = nullptr;
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3732) { //Slugshot
                    mobwsID = 212;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
                    break;
                    } 				
                }
			}			
			else if (lvl > 59) {
			m_PJobAbility = nullptr;
			uint8 wsrandom = dsprand::GetRandomNumber(1, 10); // If mob is not weak to Piercing, randomize Vorpal or Slugshot
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3732 && wsrandom >= 6) { //Slugshot
                    mobwsID = 212;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
                    break;
                    } 
  					else if (PMobSkill->getID() == 3742 && wsrandom < 6) { //Vorpal Blade
                    mobwsID = 40;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
                    break;
                    } 					

                }
			}
			else if (lvl > 4) {
			m_PJobAbility = nullptr;
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3739) { //Fast Blade
                    mobwsID = 32;
					SetCurrentMobSkill(PMobSkill);
					SetCurrentWeaponSkill(mobwsID);
			        //ShowWarning("Red Lotus Blade \n");
                    break;
                    } 					

                }
			}			
            preparePetAbility(m_PBattleSubTarget);
            return;
        }

        if (m_PPet->m_PetID == PETID_GESSHO && m_PPet->health.tp >= 1000 && m_PBattleTarget != nullptr){
			if (lvl > 71) {      
			uint8 wsrandom = dsprand::GetRandomNumber(1, 10); 
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3001 && wsrandom > 7) { //Shibaraku Spin Attack Stronger than Sweep
                    SetCurrentMobSkill(PMobSkill);
                    break;
                    }
  					else if (PMobSkill->getID() == 1742 && wsrandom > 4) { //Hane Fubuki
                    SetCurrentMobSkill(PMobSkill);
                    break;
                    }
  					else if (PMobSkill->getID() == 3003 && wsrandom > 0) { //Happobarai
                    SetCurrentMobSkill(PMobSkill);
                    break;
                    } 					
                }
			}
			else if (lvl > 49) {      
			uint8 wsrandom = dsprand::GetRandomNumber(1, 10); 
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                    if (PMobSkill->getID() == 1742 && wsrandom > 6) { //Hane Fubuki
                    SetCurrentMobSkill(PMobSkill);
                    break;
                    }
  					else if (PMobSkill->getID() == 3003 && wsrandom > 0) { //Happobarai
                    SetCurrentMobSkill(PMobSkill);
                    break;
                    } 					
                }
			}
			else if (lvl > 4) {      
			uint8 wsrandom = dsprand::GetRandomNumber(1, 10); 
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                    if (PMobSkill->getID() == 362 && wsrandom > 6) { //Double Kick
                    SetCurrentMobSkill(PMobSkill);
                    break;
                    }
  					else if (PMobSkill->getID() == 361 && wsrandom > 0) { //Feather STorm
                    SetCurrentMobSkill(PMobSkill);
                    break;
                    } 					
                }
			}
            preparePetAbility(m_PBattleSubTarget);
            return;
        }
		
	 	

	 if (m_PPet->m_PetID == PETID_ZEID && m_PPet->health.tp >= 1000 && m_PBattleTarget != nullptr){  
			int16 mobwsID = -1;
			uint32 zeidSCReady = charutils::GetVar((CCharEntity*)m_PPet->PMaster,"ZeidSCReady");
			if (zeidSCPartner != nullptr)
			{	
		        if (zeidSCPartner->health.tp < 500)
			    {
					if (m_PPet->m_PetID == PETID_ZEID)
				    {										        
						if (lvl > 71 && m_PPet->m_PetID == PETID_ZEID)
					    {							
							for (int i = 0; i < m_PPet->PetSkills.size(); i++) 
							{
                                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
								if (PMobSkill->getID() == 3754 && zeidSCReady == 1) //Ground Strike
							    {
								    ShowWarning(CL_GREEN"GROUND STRIKE SCREADY is: %u \n" CL_RESET, zeidSCReady);
									mobwsID = 56;
                                    SetCurrentMobSkill(PMobSkill);
							    	SetCurrentWeaponSkill(mobwsID);
                                    break;
								}
								else if (PMobSkill->getID() == 3753 && zeidSCReady == 2) //Spinning Slash
							    {
								    ShowWarning(CL_GREEN"SPINNING SLASH SCREADY is: %u \n" CL_RESET, zeidSCReady);
									mobwsID = 55;
                                    SetCurrentMobSkill(PMobSkill);
							    	SetCurrentWeaponSkill(mobwsID);
                                    break;
								}								
                            }					
                        }
						else if (lvl >= 65 && m_PPet->m_PetID == PETID_ZEID)
					    {							
							for (int i = 0; i < m_PPet->PetSkills.size(); i++) 
							{
                                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                                if (PMobSkill->getID() == 3753 && zeidSCReady == 2) //Spinning Slash
							    {
								    ShowWarning(CL_GREEN"SPINNING SLASH SCREADY is: %u \n" CL_RESET, zeidSCReady);
									mobwsID = 55;
                                    SetCurrentMobSkill(PMobSkill);
							    	SetCurrentWeaponSkill(mobwsID);
                                    break;
								}								
                            }					
                        }
						else if (lvl >= 60 && m_PPet->m_PetID == PETID_ZEID)
					    {							
							for (int i = 0; i < m_PPet->PetSkills.size(); i++) 
							{
                                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                                if (PMobSkill->getID() == 3752 && zeidSCReady == 3) //Sickle Moon
							    {
								    ShowWarning(CL_GREEN"Sickle Moon SCREADY is: %u \n" CL_RESET, zeidSCReady);
									mobwsID = 54;
                                    SetCurrentMobSkill(PMobSkill);
							    	SetCurrentWeaponSkill(mobwsID);
                                    break;
								}								
                            }					
                        }
						else if (lvl >= 32 && m_PPet->m_PetID == PETID_ZEID)
					    {							
							for (int i = 0; i < m_PPet->PetSkills.size(); i++) 
							{
                                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                                if (PMobSkill->getID() == 3750 && zeidSCReady == 4) //Freeze Bite
							    {
								    ShowWarning(CL_GREEN"Sickle Moon SCREADY is: %u \n" CL_RESET, zeidSCReady);
									mobwsID = 51;
                                    SetCurrentMobSkill(PMobSkill);
							    	SetCurrentWeaponSkill(mobwsID);
                                    break;
								}								
                            }					
                        }
						else if (lvl >= 5 && m_PPet->m_PetID == PETID_ZEID)
					    {							
							for (int i = 0; i < m_PPet->PetSkills.size(); i++) 
							{
                                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                                if (PMobSkill->getID() == 3752 && zeidSCReady == 5) //Hard Slash
							    {
								    ShowWarning(CL_GREEN"Hard Slash SCREADY is: %u \n" CL_RESET, zeidSCReady);
									mobwsID = 48;
                                    SetCurrentMobSkill(PMobSkill);
							    	SetCurrentWeaponSkill(mobwsID);
                                    break;
								}								
                            }					
                        }						
			        }
			    }
				//Write the SC to a variable for the player
			    int32 value = 0;
			    std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'ZeidSCReady', value = '0' ON DUPLICATE KEY UPDATE value = '0';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);	
				//End Write of SC to variable for player							
				preparePetAbility(m_PBattleSubTarget);
			    return;
			}
			else if (zeidSCPartner == nullptr)
			{
			    //ShowWarning("ZEID HAS NO SC PARTNER USE RANDOMIZED WS \n");
			    if (lvl > 71) {
			    uint8 wsrandom = dsprand::GetRandomNumber(1, 3); // Spiral Hell, Cross Reeper or Guillotine
                for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 3754 && wsrandom >= 2) { //Ground Strike
					mobwsID = 56;
					SetCurrentMobSkill(PMobSkill);
			        SetCurrentWeaponSkill(mobwsID);
                    break;
                    }
                    else if (PMobSkill->getID() == 3753 && wsrandom < 2) { //Spinning Slash
					mobwsID = 55;
					SetCurrentMobSkill(PMobSkill);
			        SetCurrentWeaponSkill(mobwsID);
					break;
                        }
                    }
                }
                else if (lvl > 64) {
			    uint8 wsrandom = dsprand::GetRandomNumber(1, 3); //Spinning Slash or Sickle Moon
                for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					    if (PMobSkill->getID() == 3753 && wsrandom >= 2) { //Spinning Slash
					    mobwsID = 55;
					    SetCurrentMobSkill(PMobSkill);
			            SetCurrentWeaponSkill(mobwsID);
                        break;
                        }
                        else if (PMobSkill->getID() == 3752 && wsrandom < 2) { //Sickle Moon
					    mobwsID = 54;
					    SetCurrentMobSkill(PMobSkill);
			            SetCurrentWeaponSkill(mobwsID);
                        break;
                        } 						
                    }
                }
                else if (lvl > 59) {
			    uint8 wsrandom = dsprand::GetRandomNumber(1, 3); //Guillotine or Vorpal Scythe
                for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					    if (PMobSkill->getID() == 3752 && wsrandom >= 2) { //Sickle Moon
					    mobwsID = 54;
					    SetCurrentMobSkill(PMobSkill);
			            SetCurrentWeaponSkill(mobwsID);
                        break;
                        }
                        else if (PMobSkill->getID() == 3751 && wsrandom < 2) { //Crescent Moon
					    mobwsID = 53;
					    SetCurrentMobSkill(PMobSkill);
			            SetCurrentWeaponSkill(mobwsID);
                        break;
                        } 						
                    }
                }
                else if (lvl > 54) {
			    uint8 wsrandom = dsprand::GetRandomNumber(1, 3); //Vorpal Scythe or Nightmare Scythe
                for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					    if (PMobSkill->getID() == 3751 && wsrandom >= 2) { //Crescent Moon
					    mobwsID = 53;
					    SetCurrentMobSkill(PMobSkill);
			            SetCurrentWeaponSkill(mobwsID);
                        break;
                        }
                        else if (PMobSkill->getID() == 3750 && wsrandom < 2) { //Freezebite
					    mobwsID = 51;
					    SetCurrentMobSkill(PMobSkill);
			            SetCurrentWeaponSkill(mobwsID);
                        break;
                        } 						
                    }
                }
                else if (lvl > 32) {
			    uint8 wsrandom = dsprand::GetRandomNumber(1, 3); //Nightmare Scythe or Slice
                for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					    if (PMobSkill->getID() == 3750 && wsrandom >= 2) { //Freezebite
					    mobwsID = 51;
					    SetCurrentMobSkill(PMobSkill);
			            SetCurrentWeaponSkill(mobwsID);
                        break;
                        }
                        else if (PMobSkill->getID() == 3749 && wsrandom < 2) { //Hard Slash
					    mobwsID = 48;
					    SetCurrentMobSkill(PMobSkill);
			            SetCurrentWeaponSkill(mobwsID);
                        break;
                        } 						
                    }
                }	
                else if (lvl > 4) {
                for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					    if (PMobSkill->getID() == 3749) { //Slice
					    mobwsID = 96;
					    SetCurrentMobSkill(PMobSkill);
			            SetCurrentWeaponSkill(mobwsID);
                        break;
					    }
                    }
                }			
                preparePetAbility(m_PBattleSubTarget);
			    return;	
            }		
		}


		
	 if (m_PPet->m_PetID == PETID_NAJELITH && m_PPet->health.tp >= 1000 && m_Tick >= m_LastNajelithWSTime + 7000 && m_PBattleTarget != nullptr){
			int16 mobwsID = -1;
			if (lvl > 71) {
			uint8 wsrandom = dsprand::GetRandomNumber(1, 3); // Empyreal Arrow or Typhonic Arrow
            for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
  					if (PMobSkill->getID() == 1834 && wsrandom >= 2) { //Typhonic Arrow
					SetCurrentMobSkill(PMobSkill);
                    break;
                    }
                    else if (PMobSkill->getID() == 3764 && wsrandom < 2) { //Empyreal Arrow
					mobwsID = 199;
					SetCurrentMobSkill(PMobSkill);
			        SetCurrentWeaponSkill(mobwsID);
                    break;
                    } 						

                }
            }			
            preparePetAbility(m_PBattleSubTarget);
			return;	
            }		
		
		
		
		

		

    if (m_PPet->objtype == TYPE_MOB && m_PPet->PMaster->objtype == TYPE_PC)
    {
        if (m_MasterCommand == MASTERCOMMAND_SIC && m_PPet->health.tp >= 1000 && m_PBattleTarget != nullptr)
        {
            m_MasterCommand = MASTERCOMMAND_NONE;
            CMobEntity* PMob = (CMobEntity*)m_PPet->PMaster->PPet;
            std::vector<uint16> MobSkills = battleutils::GetMobSkillList(PMob->getMobMod(MOBMOD_SKILL_LIST));

            if (MobSkills.size() > 0)
            {
                std::shuffle(MobSkills.begin(), MobSkills.end(), dsprand::mt());

                for (auto&& skillid : MobSkills)
                {
                    auto PMobSkill = battleutils::GetMobSkill(skillid);
                    if (PMobSkill && luautils::OnMobSkillCheck(m_PBattleTarget, m_PPet, PMobSkill) == 0)
                    {
                        SetCurrentMobSkill(PMobSkill);
                        break;
                    }
                }

                // could not find skill
                if (!GetCurrentMobSkill())
                {
                    TransitionBack(true);
                    return;
                }

                preparePetAbility(m_PBattleTarget);
                return;
            }
            return;
        }
    }


    if (m_PPet->getPetType() == PETTYPE_JUG_PET) {
        if (m_MasterCommand == MASTERCOMMAND_SIC && m_PPet->health.tp >= 1000 && m_PBattleTarget != nullptr) { //choose random tp move
            m_MasterCommand = MASTERCOMMAND_NONE;
            if (m_PPet->PetSkills.size() > 0) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(dsprand::GetRandomNumber(m_PPet->PetSkills.size())));
                if (PMobSkill)
                {
                    SetCurrentMobSkill(PMobSkill);
                    preparePetAbility(m_PBattleTarget);
                    return;
                }
            }
        }
    }
	
	
	
	
    else if (m_PPet->getPetType() == PETTYPE_AVATAR) {
        for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
            auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
            if (PMobSkill && PMobSkill->getAnimationTime() == m_MasterCommand) {
                SetCurrentMobSkill(PMobSkill);
                m_MasterCommand = MASTERCOMMAND_NONE;
                preparePetAbility(m_PPet);
                return;
            }
        }
        m_MasterCommand = MASTERCOMMAND_NONE;
    }
    else if (m_PPet->getPetType() == PETTYPE_WYVERN) {

        WYVERNTYPE wyverntype = m_PPet->getWyvernType();

        if (m_MasterCommand == MASTERCOMMAND_ELEMENTAL_BREATH && (wyverntype == WYVERNTYPE_MULTIPURPOSE || wyverntype == WYVERNTYPE_OFFENSIVE)) {
            m_MasterCommand = MASTERCOMMAND_NONE;

            //offensive or multipurpose wyvern
            if (m_PBattleTarget != nullptr) { //prepare elemental breaths
                int skip = dsprand::GetRandomNumber(6);
                int hasSkipped = 0;

                for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                    if (PMobSkill && PMobSkill->getValidTargets() == TARGET_ENEMY) {
                        if (hasSkipped == skip) {
                            SetCurrentMobSkill(PMobSkill);
                            break;
                        }
                        else {
                            hasSkipped++;
                        }
                    }
                }

                preparePetAbility(m_PBattleTarget);
                return;
            }

        }
		//Handle Super Jump
		else if (m_MasterCommand == MASTERCOMMAND_SUPER_JUMP)
	    {
		    m_MasterCommand = MASTERCOMMAND_NONE;
			ShowWarning(CL_RED"Super Climb Initiated\n" CL_RESET);
			m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                    if (PMobSkill->getID() == 3708) { //Super Climb
			        mobjaID = 52;
                    SetCurrentMobSkill(PMobSkill);
				    SetCurrentJobAbility(mobjaID);
					m_PBattleSubTarget = m_PPet;
					break;
                    }
			    }			
		    preparePetAbility(m_PBattleSubTarget);
			m_LastLuzafQuickTime = m_Tick;
			return;	
		}
		
        else if (m_MasterCommand == MASTERCOMMAND_HEALING_BREATH && (wyverntype == WYVERNTYPE_DEFENSIVE || wyverntype == WYVERNTYPE_MULTIPURPOSE))
        {

            m_MasterCommand = MASTERCOMMAND_NONE;
            m_PBattleSubTarget = nullptr;
            //TODO: CHECK FOR STATUS EFFECTS FOR REMOVE- BREATH (higher priority than healing breaths)

            //	if(m_PPet->PMaster->PParty==nullptr){//solo with master-kun
            CItemArmor* masterHeadItem = ((CCharEntity*)(m_PPet->PMaster))->getEquip(SLOT_HEAD);

            uint16 masterHead = masterHeadItem ? masterHeadItem->getID() : 0;

            // Determine what the required HP percentage will need to be 
            // at or under in order for healing breath to activate.
            uint8 requiredHPP = 0;
            if (((CCharEntity*)(m_PPet->PMaster))->objtype == TYPE_PC && (masterHead == 12519 || masterHead == 15238)) { //Check for player & AF head, or +1
                if (wyverntype == WYVERNTYPE_DEFENSIVE) { //healer wyvern
                    requiredHPP = 50;
                }
                else if (wyverntype == WYVERNTYPE_MULTIPURPOSE) { //hybrid wyvern
                    requiredHPP = 33;
                }
            }
            else {
                if (wyverntype == WYVERNTYPE_DEFENSIVE) { //healer wyvern
                    requiredHPP = 33;
                }
                else if (wyverntype == WYVERNTYPE_MULTIPURPOSE) { //hybrid wyvern
                    requiredHPP = 25;
                }
            }

            // Only attempt to find a target if there is an HP percentage to calculate.
            if (requiredHPP) {
                CBattleEntity* master = m_PPet->PMaster;
                // Check the master first.
                if (master->GetHPP() <= requiredHPP) {
                    m_PBattleSubTarget = master;
                }

                // Otherwise if this is a healer wyvern, and the member is in a party 
                // check all of the party members who qualify.
                else if (wyverntype == WYVERNTYPE_DEFENSIVE && master->PParty != nullptr) {
                    master->ForParty([this, requiredHPP](CBattleEntity* PTarget) {
                        if (PTarget->GetHPP() <= requiredHPP) {
                            m_PBattleSubTarget = PTarget;
                        }
                    });
                }
            }

            if (m_PBattleSubTarget != nullptr) { //target to heal
                //get highest breath for wyverns level
                m_PMobSkill = nullptr;
                for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                    if (PMobSkill && PMobSkill->getValidTargets() == TARGET_PLAYER_PARTY) {
                        if (PMobSkill->getID() == 638 &&
                            m_PPet->PMaster->GetMLevel() < 20) { //can only using hb1
                            SetCurrentMobSkill(PMobSkill);
                            break;
                        }
                        else if (PMobSkill->getID() == 639 &&
                            m_PPet->PMaster->GetMLevel() < 40) { //can only using hb2
                            SetCurrentMobSkill(PMobSkill);
                            break;
                        }
                        else if (PMobSkill->getID() == 640 &&
                            m_PPet->PMaster->GetMLevel() >= 40) { //can only using hb3
                            SetCurrentMobSkill(PMobSkill);
                            break;
                        }
                    }
                }
                preparePetAbility(m_PBattleSubTarget);
                return;
            }
        }
    }

    TransitionBack(true);
}

void CAIPetDummy::preparePetAbility(CBattleEntity* PTarg) {

	if (m_PJobAbility != nullptr || m_PJobAbility > 0) {
        //ShowWarning(CL_GREEN"Alternate preparepet triggered for JA /n" CL_RESET);
        apAction_t Action;
        m_PPet->m_ActionList.clear();

       		
		/* // find correct targe
         if (m_PMobSkill->getValidTargets() == TARGET_SELF)
        { //self
            m_PBattleSubTarget = m_PPet;
        } */
		
		//for weaponskill end
		
	
        // OK for here set specific section below based on job ability number so that certain ja's give the reaction hit message
       /* Action.ActionTarget = m_PBattleSubTarget;
        Action.reaction = REACTION_HIT;
        Action.speceffect = SPECEFFECT_HIT; //SPECEFFECT_NONE;
        Action.animation = 0;
        Action.param = m_PJobAbility->getID();
        //Action.messageID = 100; //<player> uses message
        Action.knockback = 0; */
        m_skillTP = m_PPet->health.tp;
		
	
		
		
		
        //m_PPet->health.tp = 0;
        m_PPet->m_ActionList.push_back(Action);
        m_PPet->loc.zone->PushPacket(m_PPet, CHAR_INRANGE, new CActionPacket(m_PPet));
		
		
        m_LastActionTime = m_Tick;
		//ShowWarning(CL_RED"PreparePetAbility for JOB ABILITY Fired!!!\n" CL_RESET);
        m_LastActionTime = m_Tick;
		       
        m_ActionType = ACTION_JOBABILITY_FINISH;
        ActionJobAbilityFinish();
		
    }


	else if (m_PWeaponSkill != nullptr || m_PWeaponSkill > 0) {
        //ShowWarning(CL_GREEN"Alternate preparepet triggered" CL_RESET);
        apAction_t Action;
        m_PPet->m_ActionList.clear();

       		
		// find correct targe
        
		
		//for weaponskill end
		
	

        Action.ActionTarget = m_PBattleSubTarget;
        Action.reaction = REACTION_HIT;
        Action.speceffect = SPECEFFECT_HIT;
        Action.animation = 0;
        Action.param = m_PWeaponSkill->getID();
        Action.messageID = 43; //readies message
        Action.knockback = 0;
        m_skillTP = m_PPet->health.tp;
		
	
		
		
		
        //m_PPet->health.tp = 0;
        m_PPet->m_ActionList.push_back(Action);
        m_PPet->loc.zone->PushPacket(m_PPet, CHAR_INRANGE, new CActionPacket(m_PPet));
		
		Action.ActionTarget = m_PBattleSubTarget;
        m_LastActionTime = m_Tick;
		//ShowWarning(CL_RED"PreparePetAbility Fired!!!\n" CL_RESET);
        m_LastActionTime = m_Tick;
        m_ActionType = ACTION_WEAPONSKILL_FINISH;
        ActionWeaponSkillFinish();
		
    }



    else if (m_PMobSkill != nullptr) {
        //ShowWarning(CL_RED"Normal preparepet triggered \n" CL_RESET);
        apAction_t Action;
        m_PPet->m_ActionList.clear();

        // find correct targe
        if (m_PMobSkill->getValidTargets() & TARGET_SELF)
        { //self
            m_PBattleSubTarget = m_PPet;
        }
        else if (m_PMobSkill->getValidTargets() & TARGET_PLAYER_PARTY)
        {
            // Only overwrite the sub target if it it not specified or
            // the input target doesn't match the sub target.
            if (m_PBattleSubTarget == nullptr || PTarg != m_PBattleSubTarget) {
                m_PBattleSubTarget = m_PPet->PMaster;
            }
        }
        else
        {
            if (m_PBattleTarget != nullptr)
            {
                m_PBattleSubTarget = m_PBattleTarget;
            }
            DSP_DEBUG_BREAK_IF(m_PBattleSubTarget == nullptr);
        }


            Action.ActionTarget = m_PBattleSubTarget;
            Action.reaction = REACTION_HIT;
            Action.speceffect = SPECEFFECT_HIT;
            Action.animation = 0;

        Action.param = m_PMobSkill->getMsgForAction();
        if (m_PMobSkill->getID() != 1688 && m_PMobSkill->getID() != 1689 && m_PMobSkill->getID() != 1690 && 
		m_PMobSkill->getID() != 1691 && m_PMobSkill->getID() != 1692 && m_PMobSkill->getID() != 1693 &&
        m_PMobSkill->getID() != 1178 && m_PMobSkill->getID() != 946)  //Prevents readies message on Ranged Attacks
		{
        Action.messageID = 43; //readies message
		}
        Action.knockback = 0;
        m_skillTP = m_PPet->health.tp;
		if (m_PMobSkill->getID() != 1693 && m_PMobSkill->getID() != 1684 && m_PMobSkill->getID() != 1685 &&
        m_PMobSkill->getID() != 1686 && m_PMobSkill->getID() != 1687 && m_PMobSkill->getID() != 1688 &&
        m_PMobSkill->getID() != 1689 && m_PMobSkill->getID() != 1690 && m_PMobSkill->getID() != 1691 &&
		m_PMobSkill->getID() != 1811 && m_PMobSkill->getID() != 2488 && m_PMobSkill->getID() != 1692 &&
		m_PMobSkill->getID() != 2044 && m_PMobSkill->getID() != 1810 && m_PMobSkill->getID() != 1809 && 
		m_PMobSkill->getID() != 3711 && m_PMobSkill->getID() != 3801 && m_PMobSkill->getID() != 3712 &&
		m_PMobSkill->getID() != 946)  //Prevents Ranged Attacks and WS's from resetting TP since they are considered an ability
		{
        m_PPet->health.tp = 0;
        }
        m_PPet->m_ActionList.push_back(Action);
        m_PPet->loc.zone->PushPacket(m_PPet, CHAR_INRANGE, new CActionPacket(m_PPet));

        m_LastActionTime = m_Tick;


		
        m_ActionType = ACTION_MOBABILITY_USING;

		
		
    }
	
	
	

	
	
    else {
        //ShowWarning("ai_pet_dummy::ActionAbilityFinish Pet skill is NULL \n");
        TransitionBack(true);
    }
}

void CAIPetDummy::ActionAbilityUsing()
{
    DSP_DEBUG_BREAK_IF(m_PMobSkill == nullptr);
    DSP_DEBUG_BREAK_IF(m_PBattleSubTarget == nullptr && m_PMobSkill->getValidTargets() == TARGET_ENEMY && m_PPet->getPetType() != PETTYPE_AVATAR);

    if (m_PPet->objtype == TYPE_MOB)
    {
        if (m_PMobSkill->getValidTargets() == TARGET_ENEMY && m_PBattleSubTarget->isDead() ||
            m_PMobSkill->getValidTargets() == TARGET_ENEMY && m_PBattleSubTarget->getZone() != m_PPet->getZone()) {
            m_ActionType = ACTION_MOBABILITY_INTERRUPT;
            ActionAbilityInterrupt();
            return;
        }
    }
    else
    {
        if (m_PPet->getPetType() != PETTYPE_AVATAR && m_PMobSkill->getValidTargets() == TARGET_ENEMY && m_PBattleSubTarget->isDead() ||
            m_PPet->getPetType() != PETTYPE_AVATAR && m_PMobSkill->getValidTargets() == TARGET_ENEMY && m_PBattleSubTarget->getZone() != m_PPet->getZone()) {
            m_ActionType = ACTION_MOBABILITY_INTERRUPT;
            ActionAbilityInterrupt();
            return;
        }
        else if (m_PPet->getPetType() == PETTYPE_AVATAR && m_PMobSkill->getValidTargets() == TARGET_ENEMY && m_PBattleSubTarget->isDead() ||
            m_PPet->getPetType() == PETTYPE_AVATAR && m_PMobSkill->getValidTargets() == TARGET_ENEMY && m_PBattleSubTarget->getZone() != m_PPet->getZone()) {
            m_ActionType = ACTION_MOBABILITY_INTERRUPT;
            ActionAbilityInterrupt();
            return;
        }
        else if (m_PMobSkill->getValidTargets() == TARGET_PLAYER_PARTY && m_PBattleSubTarget->isDead() ||
            m_PMobSkill->getValidTargets() == TARGET_PLAYER_PARTY && m_PBattleSubTarget->getZone() != m_PPet->getZone()) {
            m_ActionType = ACTION_MOBABILITY_INTERRUPT;
            ActionAbilityInterrupt();
            return;
        }
    }

    if (m_PPet != m_PBattleSubTarget)
    {

        // move towards target if i'm too far away
        float currentDistance = distance(m_PPet->loc.p, m_PBattleSubTarget->loc.p);

        //go to target if its too far away
        if (currentDistance > m_PMobSkill->getDistance() && m_PPathFind->PathTo(m_PBattleSubTarget->loc.p, PATHFLAG_RUN | PATHFLAG_WALLHACK))
        {
            m_PPathFind->FollowPath();
        }
        else
        {
            m_PPathFind->LookAt(m_PBattleSubTarget->loc.p);
        }
    }

    //TODO: Any checks whilst the pet is preparing.
    //NOTE: RANGE CHECKS ETC ONLY ARE DONE AFTER THE ABILITY HAS FINISHED PREPARING.
    //      THE ONLY CHECK IN HERE SHOULD BE WITH STUN/SLEEP/TERROR/ETC

    if (m_Tick > m_LastActionTime + m_PMobSkill->getActivationTime())
    {

        if (!battleutils::HasClaim(m_PPet, m_PBattleSubTarget)) {
            m_ActionType = ACTION_MOBABILITY_INTERRUPT;
            // already claimed - 12
            m_PPet->loc.zone->PushPacket(m_PPet, CHAR_INRANGE, new CMessageBasicPacket(m_PBattleSubTarget, m_PBattleSubTarget, 0, 0, 12));
            ActionAbilityInterrupt();
            return;
        }

        //Range check
        if (m_PPet->objtype == TYPE_MOB)
        {
            if (m_PMobSkill->getValidTargets() == TARGET_ENEMY && m_PBattleSubTarget != m_PPet &&
                distance(m_PBattleSubTarget->loc.p, m_PPet->loc.p) > m_PMobSkill->getDistance()) {

                // Pet's target is too far away (and isn't itself)
                SendTooFarInterruptMessage(m_PBattleSubTarget);
                return;
            }
        }
        else
        {
            if (m_PPet->getPetType() != PETTYPE_AVATAR && m_PMobSkill->getValidTargets() == TARGET_ENEMY &&
                m_PBattleSubTarget != m_PPet &&
                distance(m_PBattleSubTarget->loc.p, m_PPet->loc.p) > m_PMobSkill->getDistance()) {

                // Avatar's target is too far away (and isn't the avatar itself)
                SendTooFarInterruptMessage(m_PBattleSubTarget);
                return;
            }
            else if (m_PPet->getPetType() == PETTYPE_AVATAR && m_PMobSkill->getValidTargets() == TARGET_ENEMY &&
                m_PBattleSubTarget != m_PPet &&
                distance(m_PBattleSubTarget->loc.p, m_PPet->loc.p) > m_PMobSkill->getDistance()) {

                // Avatar's sub target is too far away (and isn't the avatar itself)
                SendTooFarInterruptMessage(m_PBattleSubTarget);
                return;
            }
            else if (m_PMobSkill->getValidTargets() == TARGET_PLAYER_PARTY &&
                distance(m_PBattleSubTarget->loc.p, m_PPet->loc.p) > m_PMobSkill->getDistance()) {

                // Player in the pet's party is too far away
                SendTooFarInterruptMessage(m_PBattleSubTarget);
                return;
            }
        }

        m_LastActionTime = m_Tick;
        m_ActionType = ACTION_MOBABILITY_FINISH;
        ActionAbilityFinish();
    }
}

void CAIPetDummy::ActionAbilityFinish() {

	
    //DSP_DEBUG_BREAK_IF(m_PMobSkill == nullptr);
    DSP_DEBUG_BREAK_IF(m_PBattleSubTarget == nullptr);
        //ShowWarning(CL_GREEN"MOBSKILL ABILITY FIRED!!! \n" CL_RESET);
	

    // reset AoE finder
    m_PTargetFind->reset();
    m_PPet->m_ActionList.clear();

    float distance = m_PMobSkill->getDistance();

    if (m_PTargetFind->isWithinRange(&m_PBattleSubTarget->loc.p, distance))
    {
        if (m_PMobSkill->isAoE())
        {
            float radius = m_PMobSkill->getDistance();

            m_PTargetFind->findWithinArea(m_PBattleSubTarget, (AOERADIUS)m_PMobSkill->getAoe(), distance);
        }
        else if (m_PMobSkill->isConal())
        {
            float angle = 45.0f;
            m_PTargetFind->findWithinCone(m_PBattleSubTarget, distance, angle);
        }
        else
        {
            m_PTargetFind->findSingleTarget(m_PBattleSubTarget);
        }
    }

    uint16 totalTargets = m_PTargetFind->m_targets.size();
    //call the script for each monster hit
    m_PMobSkill->setTotalTargets(totalTargets);

    float bonusTP = m_PPet->getMod(MOD_TP_BONUS);

    if( bonusTP + m_skillTP > 300 )
       m_skillTP = 300;
    else
       m_skillTP += bonusTP;

    m_PMobSkill->setTP(m_skillTP);
    m_PMobSkill->setHPP(m_PPet->GetHPP());

    // TODO: this is totally a hack
    // override mob animation ids with valid pet animation id
    // pets need their own skills
    uint16 animationId = m_PMobSkill->getPetAnimationID();

    apAction_t Action;
    Action.ActionTarget = nullptr;
    Action.reaction = REACTION_HIT;
    Action.speceffect = SPECEFFECT_HIT;
    Action.animation = animationId;
    Action.knockback = 0;
   
    uint16 msg = 0;
    for (std::vector<CBattleEntity*>::iterator it = m_PTargetFind->m_targets.begin(); it != m_PTargetFind->m_targets.end(); ++it)
    {
       
        CBattleEntity* PTarget = *it;

        Action.ActionTarget = PTarget;
        if (m_PPet->isBstPet()) {
            Action.param = luautils::OnMobWeaponSkill(PTarget, m_PPet, GetCurrentMobSkill());
        }
        else {
            Action.param = luautils::OnPetAbility(PTarget, m_PPet, GetCurrentMobSkill(), m_PPet->PMaster);
        }

        if (msg == 0) {
            msg = m_PMobSkill->getMsg();
        }
        else {
            msg = m_PMobSkill->getAoEMsg();
        }

        Action.messageID = msg;
		
		//Test Begin for SC
		
		        if (m_PMobSkill->hasMissMsg())
        {
            Action.reaction   = REACTION_MISS;
            Action.speceffect = SPECEFFECT_NONE;
            if (msg = m_PMobSkill->getAoEMsg())
                msg = 282;
        }
        else
        {
            Action.reaction   = REACTION_HIT;
        }

        if (Action.speceffect & SPECEFFECT_HIT)
        {
            Action.speceffect = SPECEFFECT_RECOIL;
            Action.knockback = m_PMobSkill->getKnockback();
            if (it == m_PTargetFind->m_targets.begin() && (m_PMobSkill->getSkillchain() != 0))
            {
                CWeaponSkill* PWeaponSkill = battleutils::GetWeaponSkill(m_PMobSkill->getSkillchain());
                if (PWeaponSkill)
                {
                    SUBEFFECT effect = battleutils::GetSkillChainEffect(m_PBattleSubTarget, PWeaponSkill);
                    if (effect != SUBEFFECT_NONE)
                    {
                        int32 skillChainDamage = battleutils::TakeSkillchainDamage(m_PPet, PTarget, Action.param);
						
                        if (skillChainDamage < 0)
                        {
                            Action.addEffectParam = -skillChainDamage;
                            Action.addEffectMessage = 384 + effect;
                        }
                        else
                        {
                            Action.addEffectParam = skillChainDamage;
                            Action.addEffectMessage = 287 + effect;
                        }
                        Action.additionalEffect = effect;
                    }
                }
            }
        }
		
		//Test End for SC

		
		
		

        battleutils::ClaimMob(m_PBattleSubTarget, m_PPet);

        if (PTarget->objtype == TYPE_MOB && !m_PTargetFind->checkIsPlayer(PTarget) && m_PMobSkill->isDamageMsg())
        {
            ((CMobEntity*)PTarget)->PEnmityContainer->UpdateEnmityFromDamage(m_PPet, Action.param);
        }

        if (m_PBattleSubTarget->objtype == TYPE_MOB)
        {
            uint16 PWeaponskill = m_PMobSkill->getID();
            luautils::OnWeaponskillHit(m_PBattleSubTarget, m_PPet, PWeaponskill);
        }

        // If we dealt damage.. we should wake up our target..
        if (m_PMobSkill->isDamageMsg() && Action.param > 0 && PTarget->StatusEffectContainer != nullptr)
            PTarget->StatusEffectContainer->WakeUp();

        m_PPet->m_ActionList.push_back(Action);
    }
	

    m_PPet->loc.zone->PushPacket(m_PPet, CHAR_INRANGE, new CActionPacket(m_PPet));

    if (Action.ActionTarget != nullptr && m_PPet->getPetType() == PETTYPE_AVATAR) { //todo: remove pet type avatar maybe
        Action.ActionTarget->loc.zone->PushPacket(Action.ActionTarget, CHAR_INRANGE, new CEntityUpdatePacket(Action.ActionTarget, ENTITY_UPDATE, UPDATE_COMBAT));
    } 

    m_PBattleSubTarget = nullptr;
    m_ActionType = ACTION_ATTACK;
}

    int16 CalculateBaseTP(int delay) {
        int16 x = 1;
        if (delay <= 180) {
            x = 50 + (((float)delay - 180)*1.5f) / 18;
        }
        else if (delay <= 450) {
            x = 50 + (((float)delay - 180)*6.5f) / 27;
        }
        else if (delay <= 480) {
            x = 115 + (((float)delay - 450)*1.5f) / 3;
        }
        else if (delay <= 530) {
            x = 130 + (((float)delay - 480)*1.5f) / 5;
        }
        else {
            x = 145 + (((float)delay - 530)*3.5f) / 47;
        }
        return x;
    }
	
/*
void CAIPetDummy::ActionRangedFinish() {
	
    uint16 animationId = m_PMobSkill->getPetAnimationID();
	apAction_t Action;
	Action.ActionTarget = m_PBattleSubTarget;
	Action.reaction = REACTION_HIT;
	Action.speceffect = SPECEFFECT_HIT;
	Action.animation = animationId;
	Action.knockback = 0;

    TransitionBack();
}	*/
	
	
	
	
	
void CAIPetDummy::ActionWeaponSkillFinish() 
{
 
    //ShowWarning(CL_GREEN"WEAPONSKILL ABILITY FINISH!!! \n" CL_RESET);
    //DSP_DEBUG_BREAK_IF(m_PMobSkill == nullptr);
    DSP_DEBUG_BREAK_IF(m_PWeaponSkill == nullptr);
    DSP_DEBUG_BREAK_IF(m_PBattleSubTarget == nullptr);

	m_PTargetFind->reset();
    m_PPet->m_ActionList.clear();

    float distance = m_PMobSkill->getDistance();

    if (m_PTargetFind->isWithinRange(&m_PBattleSubTarget->loc.p, distance))
    {
        if (m_PMobSkill->isAoE())
        {
            float radius = m_PMobSkill->getDistance();

            m_PTargetFind->findWithinArea(m_PBattleSubTarget, (AOERADIUS)m_PMobSkill->getAoe(), distance);
        }
        else if (m_PMobSkill->isConal())
        {
            float angle = 45.0f;
            m_PTargetFind->findWithinCone(m_PBattleSubTarget, distance, angle);
        }
        else
        {
            m_PTargetFind->findSingleTarget(m_PBattleSubTarget);
        }
    }

    uint16 totalTargets = m_PTargetFind->m_targets.size();
    //call the script for each monster hit
    m_PMobSkill->setTotalTargets(totalTargets);

    float bonusTP = m_PPet->getMod(MOD_TP_BONUS);

    if( bonusTP + m_skillTP > 300 )
       m_skillTP = 300;
    else
       m_skillTP += bonusTP;

    m_PMobSkill->setTP(m_skillTP);
    m_PMobSkill->setHPP(m_PPet->GetHPP());

	

	uint16 animationId = m_PWeaponSkill->getAnimationId();

	//printf("Mob Weaponskill Animation ID Should be: %d \n", animationId);
	apAction_t Action;
	Action.ActionTarget = m_PBattleSubTarget;
	Action.reaction = REACTION_HIT;
	Action.speceffect = SPECEFFECT_HIT;
	Action.animation = animationId;
	Action.knockback = 0;
	

		
	//m_PPet->m_ActionList.push_back(Action);

    	
	   uint16 msg = 0;
	 for (std::vector<CBattleEntity*>::iterator it = m_PTargetFind->m_targets.begin(); it != m_PTargetFind->m_targets.end(); ++it)
        {
            CBattleEntity* PTarget = *it;

        Action.ActionTarget = PTarget;
        if (m_PPet->isBstPet()) {
            Action.param = luautils::OnMobWeaponSkill(PTarget, m_PPet, GetCurrentMobSkill());
        }
        else {
            Action.param = luautils::OnPetAbility(PTarget, m_PPet, GetCurrentMobSkill(), m_PPet->PMaster);
        }

        if (msg == 0) {
            msg = m_PMobSkill->getMsg();
        }
        else {
            msg = m_PMobSkill->getAoEMsg();
        }

        Action.messageID = msg;
		
		//Test Begin for SC
		
		        if (m_PMobSkill->hasMissMsg())
        {
            Action.reaction   = REACTION_MISS;
            Action.speceffect = SPECEFFECT_NONE;
            if (msg = m_PMobSkill->getAoEMsg())
                msg = 282;
        }
        else
        {
            Action.reaction   = REACTION_HIT;
        }

        if (Action.speceffect & SPECEFFECT_HIT)
        {
            Action.speceffect = SPECEFFECT_RECOIL;
            Action.knockback = m_PMobSkill->getKnockback();
            if (it == m_PTargetFind->m_targets.begin() && (m_PMobSkill->getSkillchain() != 0))
            {
                CWeaponSkill* PWeaponSkill = battleutils::GetWeaponSkill(m_PMobSkill->getSkillchain());
                if (PWeaponSkill)
                {
                    SUBEFFECT effect = battleutils::GetSkillChainEffect(m_PBattleSubTarget, PWeaponSkill);
                    if (effect != SUBEFFECT_NONE)
                    {
					    //Set Magic Burst Pattern if trust closes WS (mostly for Ayame)
						int32 value = 10;
						std::string varname;
						const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'TrustMB', value = '10' ON DUPLICATE KEY UPDATE value = '10';";
                        Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);	
						if (effect == SUBEFFECT_COMPRESSION){
						value = 8;
						std::string varname;
						const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'TrustMB', value = '8' ON DUPLICATE KEY UPDATE value = '8';";
                        Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);	
					    //printf("Setting Magic Burst to: %d \n", value);
						//ShowWarning(CL_GREEN"Dark Based Magic Burst.  Start Casting \n" CL_RESET);						
						}
						else if (effect == SUBEFFECT_TRANSFIXION){
						value = 7;
						std::string varname;
						const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'TrustMB', value = '7' ON DUPLICATE KEY UPDATE value = '7';";
                        Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);	
					    //printf("Setting Magic Burst to: %d \n", value);
						//ShowWarning(CL_GREEN"Light Based Magic Burst.  Start Casting \n" CL_RESET);						
						}
						else if (effect == SUBEFFECT_LIGHT || effect == SUBEFFECT_FRAGMENTATION || effect == SUBEFFECT_IMPACTION){
						value = 6;
						std::string varname;
						const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'TrustMB', value = '6' ON DUPLICATE KEY UPDATE value = '6';";
                        Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);	
					    //printf("Setting Magic Burst to: %d \n", value);
						//ShowWarning(CL_GREEN"Thunder Based Magic Burst.  Start Casting \n" CL_RESET);						
						}
						else if (effect == SUBEFFECT_DARKNESS || effect == SUBEFFECT_DISTORTION || effect == SUBEFFECT_INDURATION){
						value = 5;  //Blizzard
						std::string varname;
						const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'TrustMB', value = '5' ON DUPLICATE KEY UPDATE value = '5';";
                        Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);	
						//printf("Setting Magic Burst to: %d \n", value);
						//ShowWarning(CL_GREEN"Ice Based Magic Burst.  Start Casting \n" CL_RESET);
						}
						else if (effect == SUBEFFECT_LIGHT || effect == SUBEFFECT_FUSION || effect == SUBEFFECT_LIQUEFACATION){
						value = 4;  //Fire
						std::string varname;
						const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'TrustMB', value = '4' ON DUPLICATE KEY UPDATE value = '4';";
                        Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);	
						//printf("Setting Magic Burst to: %d \n", value);
						//ShowWarning(CL_GREEN"Fire Based Magic Burst.  Start Casting \n" CL_RESET);						
						}
						else if (effect == SUBEFFECT_LIGHT || effect == SUBEFFECT_FRAGMENTATION || effect == SUBEFFECT_DETONATION){
						value = 3;  //Aero
						std::string varname;
						const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'TrustMB', value = '3' ON DUPLICATE KEY UPDATE value = '3';";
                        Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);	
						//printf("Setting Magic Burst to: %d \n", value);
						//ShowWarning(CL_GREEN"Wind Based Magic Burst.  Start Casting \n" CL_RESET);							
						}
						else if (effect == SUBEFFECT_DARKNESS || effect == SUBEFFECT_DISTORTION || effect == SUBEFFECT_REVERBERATION){
						value = 2;  //Water
						std::string varname;
						const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'TrustMB', value = '2' ON DUPLICATE KEY UPDATE value = '2';";
                        Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);	
						//printf("Setting Magic Burst to: %d \n", value);
						//ShowWarning(CL_GREEN"Water Based Magic Burst.  Start Casting \n" CL_RESET);							
						}
						else if (effect == SUBEFFECT_DARKNESS || effect == SUBEFFECT_GRAVITATION || effect == SUBEFFECT_SCISSION){
						value = 1;  //Stone
						std::string varname;
						const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'TrustMB', value = '1' ON DUPLICATE KEY UPDATE value = '1';";
                        Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);	
						//printf("Setting Magic Burst to: %d \n", value);
						//ShowWarning(CL_GREEN"Stone Based Magic Burst.  Start Casting \n" CL_RESET);							
						}
					

                        //Write Magic Burst Number to player Variable called TrustMB
                        
						
						//SetVar 11
						

						
                        int32 skillChainDamage = battleutils::TakeSkillchainDamage(m_PPet, PTarget, Action.param);
                        if (skillChainDamage < 0)
                        {
                            Action.addEffectParam = -skillChainDamage;
                            Action.addEffectMessage = 384 + effect;
                        }
                        else
                        {
                            //ShowWarning(CL_GREEN"DAMAGE IS GREATER THAN 0 \n" CL_RESET);
   						    Action.addEffectParam = skillChainDamage;
                            Action.addEffectMessage = 287 + effect;
                        }
                        Action.additionalEffect = effect;
                    }
                }
            }
        }
		
		//Test End for SC
		
		
		

        battleutils::ClaimMob(m_PBattleSubTarget, m_PPet);

        if (PTarget->objtype == TYPE_MOB && !m_PTargetFind->checkIsPlayer(PTarget) && m_PMobSkill->isDamageMsg())
        {
            ((CMobEntity*)PTarget)->PEnmityContainer->UpdateEnmityFromDamage(m_PPet, Action.param);
        }

        if (m_PBattleSubTarget->objtype == TYPE_MOB)
        {
            uint16 PWeaponskill = m_PMobSkill->getID();
            luautils::OnWeaponskillHit(m_PBattleSubTarget, m_PPet, PWeaponskill);
        }

        // If we dealt damage.. we should wake up our target..
        if (m_PMobSkill->isDamageMsg() && Action.param > 0 && PTarget->StatusEffectContainer != nullptr)
            PTarget->StatusEffectContainer->WakeUp();

        m_PPet->m_ActionList.push_back(Action);
    }
	

    m_PPet->loc.zone->PushPacket(m_PPet, CHAR_INRANGE, new CActionPacket(m_PPet));

    if (Action.ActionTarget != nullptr && m_PPet->getPetType() == PETTYPE_AVATAR) { //todo: remove pet type avatar maybe
        Action.ActionTarget->loc.zone->PushPacket(Action.ActionTarget, CHAR_INRANGE, new CEntityUpdatePacket(Action.ActionTarget, ENTITY_UPDATE, UPDATE_COMBAT));
    } 

	int16 baseTp = 0;
	int16 delay = m_PPet->GetWeaponDelay(true);
	float ratio = 1.0f;
	
    
	baseTp = CalculateBaseTP((delay * 60) / 1000) / ratio;

	if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SEKKANOKI) == true){
    m_PPet->health.tp = 1000;
	m_PPet->StatusEffectContainer->DelStatusEffect(EFFECT_SEKKANOKI);
	m_LastSkillchainStart = m_Tick;
	charutils::UpdateHealth((CCharEntity*)m_PPet->PMaster);
	//TODO set a new timer here
	}
    else {	
	m_PPet->health.tp = ((baseTp)* (1.0f + 0.01f * (float)(m_PPet->getMod(MOD_STORETP))));
	charutils::UpdateHealth((CCharEntity*)m_PPet->PMaster);
	}
	
	m_PBattleSubTarget = nullptr;
    m_ActionType = ACTION_ATTACK;
 

}


void CAIPetDummy::ActionJobAbilityFinish()
{
 
    //ShowWarning(CL_GREEN"JOB ABILITY FINISH!!! \n" CL_RESET);
    //DSP_DEBUG_BREAK_IF(m_PMobSkill == nullptr);
    //DSP_DEBUG_BREAK_IF(m_PWeaponSkill == nullptr);
    //DSP_DEBUG_BREAK_IF(m_PBattleSubTarget == nullptr);

	m_PTargetFind->reset();
    m_PPet->m_ActionList.clear();
	
	


	uint16 animationId = m_PJobAbility->getAnimationID();

	//printf("Mob Job Ability Animation ID Should be: %d \n", animationId);
	apAction_t Action;
	Action.ActionTarget = m_PBattleSubTarget;
	Action.param = m_PJobAbility->getID();
	
	
	//Corsair Rolls Start
	
        if (m_PJobAbility->getID() >= ABILITY_FIGHTERS_ROLL && m_PJobAbility->getID() <= ABILITY_SCHOLARS_ROLL)
        {
            m_PPet->StatusEffectContainer->DelStatusEffectSilent(EFFECT_DOUBLE_UP_CHANCE);
            uint8 roll = dsprand::GetRandomNumber(1,7);
            m_PPet->StatusEffectContainer->AddStatusEffect(new CStatusEffect(
                EFFECT_DOUBLE_UP_CHANCE,
                EFFECT_DOUBLE_UP_CHANCE,
                roll,
                0,
                45,
                m_PJobAbility->getID(),
                m_PJobAbility->getAnimationID(),
                battleutils::getCorsairRollEffect(m_PJobAbility->getID())
                ), true);

            m_CorsairDoubleUp = m_PJobAbility->getID();

            Action.reaction = REACTION_NONE;
            Action.speceffect = (SPECEFFECT)roll;
            Action.animation = m_PJobAbility->getAnimationID();
            Action.param = roll;
            Action.knockback = 0;

			if (m_PPet->PMaster->PAlly.size() != 0)
            {
                 for (auto ally : m_PPet->PMaster->PAlly)
                 {
                    CCharEntity* PTarget = (CCharEntity*)ally;
 
                    if (!PTarget->isDead() &&
                        PTarget->getZone() == m_PPet->PMaster->getZone() &&
                        distance(m_PPet->loc.p, PTarget->loc.p) <= m_PJobAbility->getRange())
                    {
                        Action.ActionTarget = PTarget;
                        luautils::OnUseAbilityRoll(PTarget, Action.ActionTarget, GetCurrentJobAbility(), roll);
                        if (PTarget->id == m_PPet->id){
                            if (m_PJobAbility->getMessage() == MSGBASIC_ROLL_SUB_FAIL){
                                Action.messageID = MSGBASIC_ROLL_MAIN_FAIL;
                            }
                            else {
                                Action.messageID = m_PJobAbility->getMessage();
                            }
                        }
                        else if (m_PJobAbility->getMessage() == MSGBASIC_ROLL_SUB_FAIL){
                            Action.messageID = MSGBASIC_ROLL_SUB_FAIL;
                        }
                        else {
                            Action.messageID = MSGBASIC_ROLL_SUB;
                        }
                        m_PPet->m_ActionList.push_back(Action);
                    }
                }
            }
		}	
	
	
	//Corsair Roll end	
	
    float distance = m_PMobSkill->getDistance();

    if (m_PTargetFind->isWithinRange(&m_PBattleSubTarget->loc.p, distance))
    {
        if (m_PMobSkill->isAoE())
        {
            float radius = m_PMobSkill->getDistance();

            m_PTargetFind->findWithinArea(m_PBattleSubTarget, (AOERADIUS)m_PMobSkill->getAoe(), distance);
        }
        else if (m_PMobSkill->isConal())
        {
            float angle = 45.0f;
            m_PTargetFind->findWithinCone(m_PBattleSubTarget, distance, angle);
        }
        else
        {
            m_PTargetFind->findSingleTarget(m_PBattleSubTarget);
        }
    }

    uint16 totalTargets = m_PTargetFind->m_targets.size();
    //call the script for each monster hit
    m_PMobSkill->setTotalTargets(totalTargets);	
	
	
	
	
	
	
	//Job abilities that do damage (Jump, Shield Bash, Weapon Bash, Card Shots, etc) need to be placed below so it sends the proper message
        if (m_PJobAbility->getID() == 30 || m_PJobAbility->getID() == 50 || m_PJobAbility->getID() == 51 ||
		m_PJobAbility->getID() == 109 || m_PJobAbility->getID() == 110 || m_PJobAbility->getID() == 111 ||
		m_PJobAbility->getID() == 112 || m_PJobAbility->getID() == 113 || m_PJobAbility->getID() == 114 ||
		m_PJobAbility->getID() == 115 || m_PJobAbility->getID() == 116 || m_PJobAbility->getID() == 61) 
	    {	
		Action.reaction = REACTION_HIT; //   SPECEFFECT_NONE;
		Action.speceffect = SPECEFFECT_HIT;
		Action.animation = animationId;
		Action.knockback = 0;
		Action.messageID = 110;
		}
	    else
	    {
		Action.reaction = REACTION_NONE; //   SPECEFFECT_NONE;
		Action.speceffect = SPECEFFECT_NONE;
		Action.animation = animationId;
		Action.knockback = 0;
		Action.messageID = 100;
	    }

		
	//m_PPet->m_ActionList.push_back(Action);

    	
	   //uint16 msg = 0;
	 for (std::vector<CBattleEntity*>::iterator it = m_PTargetFind->m_targets.begin(); it != m_PTargetFind->m_targets.end(); ++it)
        {
            CBattleEntity* PTarget = *it;

        Action.ActionTarget = PTarget;
        if (m_PPet->isBstPet()) {
            Action.param = luautils::OnMobWeaponSkill(PTarget, m_PPet, GetCurrentMobSkill());
        }
        else {
            Action.param = luautils::OnPetAbility(PTarget, m_PPet, GetCurrentMobSkill(), m_PPet->PMaster);
        }

       /* if (msg == 0) {
            msg = m_PMobSkill->getMsg();
        }
        else {
            msg = m_PMobSkill->getAoEMsg();
        }

        //Action.messageID = msg; */
		
        battleutils::ClaimMob(m_PBattleSubTarget, m_PPet);

        if (PTarget->objtype == TYPE_MOB && !m_PTargetFind->checkIsPlayer(PTarget) && m_PMobSkill->isDamageMsg())
        {
            ((CMobEntity*)PTarget)->PEnmityContainer->UpdateEnmityFromDamage(m_PPet, Action.param);
        }

        if (m_PBattleSubTarget->objtype == TYPE_MOB)
        {
            uint16 PWeaponskill = m_PMobSkill->getID();
            luautils::OnWeaponskillHit(m_PBattleSubTarget, m_PPet, PWeaponskill);
        }

        // If we dealt damage.. we should wake up our target..
        if (m_PMobSkill->isDamageMsg() && Action.param > 0 && PTarget->StatusEffectContainer != nullptr)
            PTarget->StatusEffectContainer->WakeUp();

        m_PPet->m_ActionList.push_back(Action);
    }
	

    m_PPet->loc.zone->PushPacket(m_PPet, CHAR_INRANGE, new CActionPacket(m_PPet));

    if (Action.ActionTarget != nullptr && m_PPet->getPetType() == PETTYPE_AVATAR) { //todo: remove pet type avatar maybe
        Action.ActionTarget->loc.zone->PushPacket(Action.ActionTarget, CHAR_INRANGE, new CEntityUpdatePacket(Action.ActionTarget, ENTITY_UPDATE, UPDATE_COMBAT));
    } 

		
    m_PJobAbility = nullptr;
    
	m_PBattleSubTarget = nullptr;
    m_ActionType = ACTION_ATTACK;
 

}



void CAIPetDummy::ActionAbilityInterrupt() {
    m_LastActionTime = m_Tick;
    //cancel the whole readying animation
    apAction_t Action;
    m_PPet->m_ActionList.clear();

    Action.ActionTarget = m_PPet;
    Action.reaction = REACTION_NONE;
    Action.speceffect = SPECEFFECT_NONE;
    Action.animation = 0;
    Action.param = 0;
    Action.messageID = 0;
    Action.knockback = 0;

    m_PPet->m_ActionList.push_back(Action);
    m_PPet->loc.zone->PushPacket(m_PPet, CHAR_INRANGE, new CActionPacket(m_PPet));

    m_PMobSkill = nullptr;
    m_ActionType = ACTION_ATTACK;
}

bool CAIPetDummy::PetIsHealing() {

    bool isMasterHealing = (m_PPet->PMaster->animation == ANIMATION_HEALING);
    bool isPetHealing = (m_PPet->animation == ANIMATION_HEALING);

    if (isMasterHealing && !isPetHealing && !m_PPet->StatusEffectContainer->HasPreventActionEffect()) {
        //animation down
        m_PPet->animation = ANIMATION_HEALING;
        m_PPet->StatusEffectContainer->AddStatusEffect(new CStatusEffect(EFFECT_HEALING, 0, 0, 10, 0));
        m_PPet->updatemask |= UPDATE_HP;
        return true;
    }
    else if (!isMasterHealing && isPetHealing) {
        //animation up
        m_PPet->animation = ANIMATION_NONE;
        m_PPet->StatusEffectContainer->DelStatusEffect(EFFECT_HEALING);
        m_PPet->updatemask |= UPDATE_HP;
        return false;
    }
	
	
	if (m_PPet->getZone() == m_PPet->PMaster->getZone()){
	m_PPet->updatemask |= UPDATE_HP;
	//charutils::UpdateHealth((CCharEntity*)m_PPet->PMaster);
	}

 
    return isMasterHealing;
}

/************************************************************************
*																		*
*																		*
*																		*
************************************************************************/

void CAIPetDummy::ActionRoaming()
{
    uint32 trustassist = charutils::GetVar((CCharEntity*)m_PPet->PMaster,"TrustAssist");
    if (m_PPet->PMaster == nullptr || m_PPet->PMaster->isDead()) { // || m_PPet->PMaster->getZone() != m_PPet->getZone()) {
        m_ActionType = ACTION_FALL;
        /*
		if (m_PPet->m_PetID == PETID_LION && m_PPet->isDead())
		{
		    int32 value = 0;
			std::string varname;
			const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'LionPT', value = '0' ON DUPLICATE KEY UPDATE value = '0';";
            Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);
		}
        if (m_PPet->m_PetID == PETID_PRISHE && m_PPet->isDead())
		{
		    int32 value = 0;
			std::string varname;
			const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'PrisePT', value = '0' ON DUPLICATE KEY UPDATE value = '0';";
            Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);
		}	*/		
        ActionFall();
        return;
    }

    //automaton, wyvern
    if (m_PPet->getPetType() == PETTYPE_WYVERN || m_PPet->getPetType() == PETTYPE_AUTOMATON) {
        if (PetIsHealing()) {
            return;
        }
    }
	//if (m_PPet->getZone() == m_PPet->PMaster->getZone()){
	//m_PPet->updatemask |= UPDATE_HP;
	//charutils::UpdateHealth((CCharEntity*)m_PPet->PMaster);
	//}

 	if (m_PPet->PMaster->PAlly.size() > 0)
	{
		//ShowWarning(CL_RED"Pushing Packet on Roaming!!!\n" CL_RESET);
		m_PPet->PMaster->PParty->PushPacket(m_PPet->id, m_PPet->getZone(), new CCharHealthPacket(m_PPet));
		// for (auto ally : m_PPet->PMaster->PAlly)
		// {
		// 	ShowWarning(CL_RED"Pushing Packet on Roaming\n" CL_RESET);
		// 	m_PPet->PMaster->PParty->PushPacket(ally->id, ally->getZone(), new CCharHealthPacket(ally));
		// }
	}


	
	
    if (m_PBattleTarget != nullptr) {
	   if (m_PPet->getPetType() == PETTYPE_TRUST && battleutils::HasClaim(m_PPet, m_PBattleTarget)) {
        m_ActionType = ACTION_ENGAGE;
        ActionEngage();
        return;
		}
		else if (m_PPet->getPetType() != PETTYPE_TRUST || trustassist == 1 ) { // put or variable turned on for toggle
        m_ActionType = ACTION_ENGAGE;
        ActionEngage();
        return;	
        }		
    }
	//ShowWarning(CL_RED"PET IS ACTION ROAMING\n" CL_RESET);
    ((CCharEntity*)m_PPet->PMaster)->pushPacket(new CCharHealthPacket((CCharEntity*)m_PPet->PMaster));
    float currentDistance = distance(m_PPet->loc.p, m_PPet->PMaster->loc.p);


    // this is broken until pet / mob relationship gets fixed
    // pets need to extend mob or be a mob because pet has no spell list!
    if (m_PPet->getPetType() == PETTYPE_AVATAR && m_PPet->m_Family == 104 && m_Tick >= m_LastActionTime + 30000 && currentDistance < PET_ROAM_DISTANCE * 2)
    {
        int16 spellID = 108;
        // define this so action picks it up
        SetCurrentSpell(spellID);
        m_PBattleSubTarget = m_PPet->PMaster;

        m_ActionType = ACTION_MAGIC_START;
        ActionMagicStart();
        return;
    }

    if (currentDistance > PET_ROAM_DISTANCE)
    {
        if (currentDistance < 35.0f && m_PPathFind->PathAround(m_PPet->PMaster->loc.p, 2.0f, PATHFLAG_RUN | PATHFLAG_WALLHACK))
        {
            m_PPathFind->FollowPath();
        }
        else if (m_PPet->GetSpeed() > 0)
        {
            m_PPathFind->WarpTo(m_PPet->PMaster->loc.p, PET_ROAM_DISTANCE);
        }
    }
	
		//Trusts
    if (m_PPet->getPetType() == PETTYPE_TRUST) {
        if (PetIsHealing()) {
            return;
        }
		if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_HEALING) == false)
		{
		m_PPet->StatusEffectContainer->AddStatusEffect(new CStatusEffect(EFFECT_HEALING, 0, 0, 5, 0));
		m_PPet->animation = ANIMATION_NONE;
		}
    }

}

void CAIPetDummy::ActionEngage()
{
    DSP_DEBUG_BREAK_IF(m_PBattleTarget == nullptr);

	m_LastEngageStart = m_Tick; //For WS timers so trusts don't WS at the start unless they are tanks
	
	uint8 trustlvl = m_PPet->GetMLevel();
	if (m_PPet->getPetType() == PETTYPE_TRUST){
	m_PPet->StatusEffectContainer->DelStatusEffect(EFFECT_HEALING);
	m_PPet->updatemask |= UPDATE_HP;
	}
	
    if (m_PPet->PMaster == nullptr || m_PPet->PMaster->isDead())
    {
        m_ActionType = ACTION_FALL;
        ActionFall();
        return;
    }

    if (battleutils::HasClaim(m_PPet, m_PBattleTarget))
    {
        m_PPet->animation = ANIMATION_ATTACK;
        m_PPet->updatemask |= UPDATE_HP;
        m_LastActionTime = m_Tick - 1000;
        TransitionBack(true);
    }
    else
    {
        m_PPet->animation = ANIMATION_NONE;
        m_PPet->updatemask |= UPDATE_HP;
        if (m_PPet->PMaster->objtype == TYPE_PC)
        {
            ((CCharEntity*)m_PPet->PMaster)->pushPacket(new CMessageBasicPacket(((CCharEntity*)m_PPet->PMaster),
                ((CCharEntity*)m_PPet->PMaster), 0, 0, 12));
            m_ActionType = ACTION_DISENGAGE;
            return;
        }
    }
}


void CAIPetDummy::ActionAttack()
{
    if (m_PPet->PMaster == nullptr || m_PPet->PMaster->isDead() || m_PPet->isDead()) {
        m_ActionType = ACTION_FALL;
		
		/*
        if (m_PPet->m_PetID == PETID_LION && m_PPet->isDead())
		{
		    int32 value = 0;
			std::string varname;
			const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'LionPT', value = '0' ON DUPLICATE KEY UPDATE value = '0';";
            Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);
		}
        if (m_PPet->m_PetID == PETID_PRISHE && m_PPet->isDead())
		{
		    int32 value = 0;
			std::string varname;
			const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'PrisePT', value = '0' ON DUPLICATE KEY UPDATE value = '0';";
            Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);
		}*/		
		ActionFall();
		
		
		
		
        return;
    }
	
	uint8 moblevel = 0;
	uint8 trustlevel = m_PPet->GetMLevel();
	if (m_PPet->getPetType() == PETTYPE_TRUST){
	moblevel = m_PBattleTarget->GetMLevel();
	}
	if (m_PPet->getZone() == m_PPet->PMaster->getZone()){
	m_PPet->updatemask |= UPDATE_HP;
    //charutils::UpdateHealth((CCharEntity*)m_PPet->PMaster); // To update pet health at all time if pet and master are in the same zone; this is for zoning purposes
	}
	
	

    //uint32 lion = charutils::GetVar((CCharEntity*)m_PPet->PMaster,"LionPT");
	//uint32 prishe = charutils::GetVar((CCharEntity*)m_PPet->PMaster,"PrishePT");
    //For Trusts to SC with each other
	// 1 = TP Is ready
	// 2 = SC just performed
    //uint32 prishesc = charutils::GetVar((CCharEntity*)m_PPet->PMaster,"PrisheSC");
    //uint32 lionsc = charutils::GetVar((CCharEntity*)m_PPet->PMaster,"LionSC");
	
	//Trust Tokens
	uint32 curillaChivalry = 0;
	uint32 excenAngon = charutils::GetVar((CCharEntity*)m_PPet->PMaster, "TrustJA_Excen");

	CMobEntity* PMob = (CMobEntity*)m_PBattleTarget;
	apAction_t Action;
	m_PPet->m_ActionList.clear();

	Action.ActionTarget = m_PBattleTarget;
	
	int8 checklevel = moblevel - trustlevel;	
	//****************************************************************//
	//   TRUST ABILITIES BY TRUST NAME                               //
	//**************************************************************//
	if (m_PPet->m_PetID == PETID_LUZAF)
		{
		if (m_Tick >= m_LastLuzafRollCheck + m_luzafRollCheck) //Check for roll timer
		{
		    if (trustlevel >= 11 && m_Tick >= m_LastLuzafFirstRollRecast + m_luzafFirstRollRecast)
		    {
				ShowWarning(CL_RED"Hunters Roll\n" CL_RESET);
			    m_PWeaponSkill = nullptr;
                int16 mobjaID = -1;			
			    for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3734) { //Hunters Roll
						    mobjaID = 92;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;
							break;
                        }
			        }			
				preparePetAbility(m_PBattleSubTarget);
				m_LastLuzafFirstRollRecast = m_Tick;
				return;	
			}
		    else if (trustlevel >= 14 && m_Tick >= m_LastLuzafSecondRollRecast + m_luzafSecondRollRecast)
		    {
				ShowWarning(CL_RED"Chaos Roll\n" CL_RESET);
			    m_PWeaponSkill = nullptr;
                int16 mobjaID = -1;			
			    for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3735) { //Chaos Roll
						    mobjaID = 89;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;
							break;
                        }
			        }			
				preparePetAbility(m_PBattleSubTarget);
				m_LastLuzafSecondRollRecast = m_Tick;
				return;	
			}			
		
		
		
		
		
		}
         //ShowWarning(CL_GREEN"LUZAF!!!\n" CL_RESET);		
		else if (trustlevel >= 40 && m_Tick >= m_LastLuzafQuickTime + m_luzafQuickRecast) // Decide which Quickdraw to Use
			{
			//ShowWarning(CL_RED"Authorized for Quick Draw!!!\n" CL_RESET);
			if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_BURN))	// Fire Shot
			    {
				ShowWarning(CL_RED"FIRE SHOT\n" CL_RESET);
			    m_PWeaponSkill = nullptr;
                int16 mobjaID = -1;			
			    for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3724) { //Fire Shot
						    mobjaID = 109;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PBattleTarget;
							break;
                        }
			        }			
				preparePetAbility(m_PBattleSubTarget);
				m_LastLuzafQuickTime = m_Tick;
				return;	
				}
			else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_FROST) || 
			m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_PARALYSIS))	// Ice Shot
			    {
				ShowWarning(CL_RED"ICE SHOT\n" CL_RESET);
			    m_PWeaponSkill = nullptr;
                int16 mobjaID = -1;			
			    for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3725) { //Ice Shot
						    mobjaID = 110;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PBattleTarget;
							break;
                        }
			        }			
				preparePetAbility(m_PBattleSubTarget);
				m_LastLuzafQuickTime = m_Tick;
				return;	
				}
			else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_CHOKE) || 
			m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE))	// Wind Shot
			    {
				ShowWarning(CL_RED"WIND SHOT\n" CL_RESET);
			    m_PWeaponSkill = nullptr;
                int16 mobjaID = -1;			
			    for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3726) { //Wind Shot
						    mobjaID = 111;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PBattleTarget;
							break;
                        }
			        }			
				preparePetAbility(m_PBattleSubTarget);
				m_LastLuzafQuickTime = m_Tick;
				return;	
				}
			else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_RASP) || 
			m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_SLOW))	// Earth Shot
			    {
				ShowWarning(CL_RED"EARTH SHOT\n" CL_RESET);
			    m_PWeaponSkill = nullptr;
                int16 mobjaID = -1;			
			    for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3727) { //Earth Shot
						    mobjaID = 112;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PBattleTarget;
							break;
                        }
			        }			
				preparePetAbility(m_PBattleSubTarget);
				m_LastLuzafQuickTime = m_Tick;
				return;	
				}
			else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_SHOCK))	// Thunder Shot
			    {
				ShowWarning(CL_RED"THUNDER SHOT\n" CL_RESET);
			    m_PWeaponSkill = nullptr;
                int16 mobjaID = -1;			
			    for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3728) { //Thunder Shot
						    mobjaID = 113;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PBattleTarget;
							break;
                        }
			        }			
				preparePetAbility(m_PBattleSubTarget);
				m_LastLuzafQuickTime = m_Tick;
				return;	
				}
			else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_DROWN) || 
			m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_POISON))	// Water Shot
			    {
				ShowWarning(CL_RED"WATER SHOT\n" CL_RESET);
			    m_PWeaponSkill = nullptr;
                int16 mobjaID = -1;			
			    for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3729) { //Water Shot
						    mobjaID = 114;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PBattleTarget;
							break;
                        }
			        }			
				preparePetAbility(m_PBattleSubTarget);
				m_LastLuzafQuickTime = m_Tick;
				return;	
				}
			else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_DIA))	// Light Shot
			    {
			    ShowWarning(CL_RED"LIGHT SHOT\n" CL_RESET);
			    m_PWeaponSkill = nullptr;
                int16 mobjaID = -1;			
			    for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3730) { //Light Shot
						    mobjaID = 115;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PBattleTarget;
							break;
                        }
			        }			
				preparePetAbility(m_PBattleSubTarget);
				m_LastLuzafQuickTime = m_Tick;
				return;	
				}				
			else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_BIO) || 
			m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_BLINDNESS))	// Dark Shot
			    {
				ShowWarning(CL_RED"DARK SHOT\n" CL_RESET);
			    m_PWeaponSkill = nullptr;
                int16 mobjaID = -1;			
			    for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3731) { //Dark Shot
						    mobjaID = 116;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PBattleTarget;
							break;
                        }
			        }			
				preparePetAbility(m_PBattleSubTarget);
				m_LastLuzafQuickTime = m_Tick;
				return;	
				}							
	        }
		}			
	
	
	
	
	
	
	
	
	
	
	  if (m_PPet->m_PetID == PETID_KUPIPI)
		{
		 //ShowDebug("KUPIPI Check \n");
		 if (m_Tick >= m_LastKupipiMagicTime + m_magicKupipiRecast) // Check Every 4 Seconds as universal check
			{
			    int16 spellID = -1;
				uint16 family = m_PPet->m_Family;
				uint16 petID = m_PPet->m_PetID;
        
		
				spellID = KupipiSpell();
		        //printf("Kupipi Spell is: %d \n", spellID);
				if (spellID != -1)
				{
				SetCurrentSpell(spellID);
				m_ActionType = ACTION_MAGIC_START;
				ActionMagicStart();
				return;
			    }
		    }
		 if (m_Tick >= m_LastKupipiSolaceTime + m_kupipiSolaceRecast && trustlevel >= 40)
			{
			m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3767) { //Solace
						    mobjaID = 229;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				m_LastKupipiSolaceTime = m_Tick;
				return;	
				}						
		}
		
		
	// Shantotto is handled differently.  She will cast a tier below her highest until the mob reaches 80%
	  if (m_PPet->m_PetID == PETID_SHANTOTTO)
		{
		 if (m_Tick >= m_LastShantottoMagicTime + m_magicShantottoRecast) // Check Every 4 Seconds as universal check
			{
			    int16 spellID = -1;
				uint16 family = m_PPet->m_Family;
				uint16 petID = m_PPet->m_PetID;
        
		        if (checklevel < 7 && m_PBattleTarget->GetHPP() > 80) //If the mob HP is greater than 80% and isn't a high level mob use lower tier nukes to start
				{
				    ShowWarning(CL_GREEN"Shantotto SpellCast Check \n" CL_RESET);
				    spellID = ShantottoSpellDebuff();
				}
				else if (checklevel < 7) //Start using normal nukes
				{
				    spellID = ShantottoSpell();
				}
				else
				{
				    spellID = ShantottoSpell();
				}					
				if (spellID != -1)
				{
				SetCurrentSpell(spellID);
				m_ActionType = ACTION_MAGIC_START;
				ActionMagicStart();
				return;
			    }
		    }					
		}
		
		
	
	
	
	 if (m_PPet->m_PetID == PETID_CURILLA)
		{
		 if (m_Tick >= m_LastMagicTime + m_magicRecast) // Check Every 4 Seconds as universal check
			{
			    int16 spellID = -1;
				uint16 family = m_PPet->m_Family;
				uint16 petID = m_PPet->m_PetID;
        
		
				spellID = CurillaSpell();
		
				if (spellID != -1)
				{
				SetCurrentSpell(spellID);
				m_ActionType = ACTION_MAGIC_START;
				ActionMagicStart();
				return;
			    }
		    }		
		 if (m_Tick >= m_LastCurillaVokeTime + m_curillaVokeRecast)
			{
			m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3711) { //Provoke
						    mobjaID = 19;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PBattleTarget;
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				m_LastCurillaVokeTime = m_Tick;
				return;	
			}				
				
		}
        // uint32 adelhiedMB = charutils::GetVar((CCharEntity*)m_PPet->PMaster,"TrustMB"); WHy is this here??
		 if (m_PPet->m_PetID == PETID_CURILLA && trustlevel >=15)
		{		
		 if ((m_Tick >= m_LastCurillaBashTime + m_curillaBashRecast) && (m_Tick >= m_LastEngageStart + 7000)) // Only use shield bash if mob is casting??  actionTarget.messageID = 327
			{
			m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3709) { //Shieldbash
						    mobjaID = 30;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PBattleTarget;  
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				m_LastCurillaBashTime = m_Tick;
				return;	
				}		
	     }

		 if (m_PPet->m_PetID == PETID_CURILLA && trustlevel >= 75 && m_PPet->GetMPP() < 20)  //Chivalry
		{
         uint32 curillaChivalry = charutils::GetVar((CCharEntity*)m_PPet->PMaster,"CurillaChivalry");		
		 if (m_Tick >= m_LastCurillaChivalryTime + m_curillaChivalryRecast && curillaChivalry > 0)
			{
			m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3736) { //Chivalry
						    mobjaID = 142;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;  
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				m_LastCurillaChivalryTime = m_Tick;
				return;	
				}		
	     }		 
		 
		/*
		if (m_PPet->m_PetID == PETID_LION && trustlevel >= 60 && (m_Tick >= m_LastEngageStart + 7000))
		{
		    CBattleEntity* trickAttackPartner = getTrickAttackPartner();
		    if ((m_Tick >= m_LastLionTrickAttackTime + m_lionTrickAttackRecast) && trickAttackPartner != nullptr)
			{
			    if (((abs(trickAttackPartner->loc.p.rotation - m_PPet->loc.p.rotation))) < 23)// Only use Trick Attack if behind partner
				{
			    ShowWarning(CL_YELLOW"LION TA Posittion Requiremnts have been met!! \n" CL_RESET);
			    m_PWeaponSkill = nullptr;
                int16 mobjaID = -1;				    
			    for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3802) { //Trick Atack
						    mobjaID = 60;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;  //Target Self
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				m_LastLionTrickAttackTime = m_Tick;
				return;	
				}				
			}
		} */
		
		
		 if (m_PPet->m_PetID == PETID_NANAA_MIHGO && trustlevel >=15)
		{		
		 if ((m_Tick >= m_LastNanaaSneakAttackTime + m_nanaaSneakAttackRecast) && m_PPet->health.tp < 800 &&
		 (abs(m_PBattleTarget->loc.p.rotation - m_PPet->loc.p.rotation) < 23)) // Only use SA when timer is up less than 500 tp and behind the mob
			{
			m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3801) { //Sneak Atack
						    mobjaID = 28;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;  //Target Self
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				m_LastNanaaSneakAttackTime = m_Tick;
				return;	
				}
		 if ((m_Tick >= m_LastNanaaSneakAttackTime + m_nanaaSneakAttackRecast) && m_PPet->health.tp >= 1000 &&
		 (abs(m_PBattleTarget->loc.p.rotation - m_PPet->loc.p.rotation) < 23)) // For SA WS only attempt SA when TP is 100%
			{
			m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3801) { //Sneak Atack
						    mobjaID = 28;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;  //Target Self
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				m_LastNanaaSneakAttackTime = m_Tick;
				return;	
				}
				
				
		}
		 if (m_PPet->m_PetID == PETID_AYAME && trustlevel >=40)
		{		
		 if ((m_Tick >= m_LastAyameSekkaTime + m_ayameSekkaRecast) && m_PPet->health.tp > 700) // Only use Sekka when higher than 75% TP
			{
			m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3717) { //Sekkanoki
						    mobjaID = 214;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;  //Target Self
							break;
                        }
			        }
				m_sekkaStatus = 2; //turn on sekkanoki check				
				preparePetAbility(m_PBattleSubTarget);
				m_LastAyameSekkaTime = m_Tick;
				return;	
				}		
	     }		
		
		 if (m_PPet->m_PetID == PETID_AYAME && trustlevel >=30)
		{		
		 if ((m_Tick >= m_LastAyameMeditateTime + m_ayameMeditateRecast) && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SEKKANOKI) == true) // If meditate is available use it if Sekkanoki is up
			{
			m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3715) { //Meditate
						    mobjaID = 47;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;  //Target Self
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				m_LastAyameMeditateTime = m_Tick;
				return;	
				}
		 else if ((m_Tick >= m_LastAyameMeditateTime + m_ayameMeditateRecast) && m_PPet->health.tp < 250 && (m_Tick < m_LastAyameMeditateTime + m_ayameMeditateRecast)) // use Meditate when TP is less than 25% and Sekkanoki is not up
			{
			m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3715) { //Meditate
						    mobjaID = 47;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;  //Target Self
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				m_LastAyameMeditateTime = m_Tick;
				return;	
				}				
	     }
		 if (m_PPet->m_PetID == PETID_AYAME && trustlevel >=15)
		{		
		 if ((m_Tick >= m_LastAyameThirdEyeTime + m_ayameThirdEyeRecast) && m_PPet->GetHPP() < 85) // Use Third eye when HP is lower than 85% or tp is less than 20% to activate after WS
			{
			m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3716) { //Third Eye
						    mobjaID = 46;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;  //Target Self
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				m_LastAyameThirdEyeTime = m_Tick;
				return;	
				}		
	     }		 

		 if (m_PPet->m_PetID == PETID_EXCENMILLE)
		{
		 if (m_Tick >= m_LastExeAngonTime + m_exeAngonRecast && trustlevel >= 75 && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_DIA) && excenAngon == 1) //ANGON
			{
			m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3707) { //Angon
						    mobjaID = 154;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PBattleTarget;
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				m_LastExeJumpTime = m_Tick;
				return;	
				}

		
		 if (m_Tick >= m_LastExeJumpTime + m_exeJumpRecast && trustlevel >=10)
			{
			m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3712) { //Jump
						    mobjaID = 50;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PBattleTarget;
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				m_LastExeJumpTime = m_Tick;
				return;	
				}
		 if (m_Tick >= m_LastExeHjumpTime + m_exeHjumpRecast && m_Tick >= m_LastExeJumpTime + 3500 && trustlevel >=35) // Puts a small delay between jumps
			{
			m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3713) { //High Jump
						    mobjaID = 51;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PBattleTarget;  
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				m_LastExeHjumpTime = m_Tick;
				return;	
				}
		 			
	     }	

		if (m_PPet->m_PetID == PETID_EXCENMILLE && m_PPet->GetHPP() < 40 && trustlevel >= 50 )
		{	
         if (m_Tick >= m_LastExeSjumpTime + m_exeSjumpRecast) // Uses Super Jump when HP is less than 30%
			{
			m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3714) { //Super Jump
						    mobjaID = 52;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PBattleTarget;  
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				m_LastExeSjumpTime = m_Tick;
				return;	
				}
        }

        if (m_PPet->m_PetID == PETID_NAJI)
		{		
		 if (m_Tick >= m_LastNajiBerserkTime + m_najiBerserkRecast && trustlevel >=25 && m_PPet->health.tp > 900)  //Uses berserk when TP is over 90% so before weaponskill
			{
			m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 441) { //Berserk
						    mobjaID = 15;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				m_LastNajiBerserkTime = m_Tick;
				return;	
				}
		 if (m_Tick >= m_LastNajiWarcryTime + m_najiWarcryRecast && trustlevel >=35) // Puts a small delay between jumps
			{
			m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 1172) { //Warcry
						    mobjaID = 16;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PBattleTarget;  
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				m_LastNajiWarcryTime = m_Tick;
				return;	
				}
		 			
	     }

	  if (m_PPet->m_PetID == PETID_BLUE)
		{
		 //BLUE MAGE CHECK
		 if (m_Tick >= m_LastBlueCheck + m_blueCheck) // Check Every 4 Seconds as universal check for blu spells
			{
			    int16 spellID = -1;
				uint16 family = m_PPet->m_Family;
				uint16 petID = m_PPet->m_PetID;
        
		
				spellID = BlueSpell();
				if (spellID != -1)
				{
				SetCurrentSpell(spellID);
				m_ActionType = ACTION_MAGIC_START;
				ActionMagicStart();
				return;
			    }
		    }
		 if (m_Tick >= m_LastChainTime + m_blueChainAffinityRecast && trustlevel >= 40 && m_PPet->health.tp > 920)  //Only use CA when above 92% TP
			{
			m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3760) { //Chain Affinity
						    mobjaID = 78;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;
							break;
                        }
			        }
				m_chainAffinityStatus = 2;	
				preparePetAbility(m_PBattleSubTarget);
				m_LastChainTime = m_Tick;
				return;	
				}						
		}

	  if (m_PPet->m_PetID == PETID_ADELHIED)
		{
		 if (trustlevel >= 35 && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_TRUST_SUBLIMATION_COMPLETE) == true && m_PPet->GetMPP() < 25 &&
		 m_Tick >= m_LastAdelhiedSub + m_adelhiedSub)
		    {
			//ShowWarning(CL_RED"SUBLIMATION COMPLETED\n" CL_RESET);
			m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3723) { //Sublimation
						    mobjaID = 217;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				m_LastAdelhiedSub = m_Tick;
				return;	
				}		
		 if (trustlevel >= 35 && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_TRUST_SUBLIMATION_ACTIVATED) == false && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_TRUST_SUBLIMATION_COMPLETE) == false)
		    {
			m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3723) { //Sublimation
						    mobjaID = 217;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				m_LastChainTime = m_Tick;
				return;	
				}
		 if (m_Tick >= m_LastSchCheck + m_schCheck) // Check Every 4 Seconds as universal check for sch spells
			{
			    int16 spellID = -1;
				uint16 family = m_PPet->m_Family;
				uint16 petID = m_PPet->m_PetID;
     
				spellID = AdelhiedSpell();
				if (spellID != -1)
				{
				SetCurrentSpell(spellID);
				m_ActionType = ACTION_MAGIC_START;
				ActionMagicStart();
				return;
			    }
		    }
        
		
			
			
		/* if (m_Tick >= m_LastChainTime + m_blueChainAffinityRecast && trustlevel >= 40 && m_PPet->health.tp > 850)  //Only use CA when above 85% TP
			{
			m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3760) { //Chain Affinity
						    mobjaID = 78;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;
							break;
                        }
			        }
				m_chainAffinityStatus = 2;	
				preparePetAbility(m_PBattleSubTarget);
				m_LastChainTime = m_Tick;
				return;	
				}	*/					
		}

	 
	  
      // this is to only start the loop if pet is in battle for more than 8 seconds
	  // This lets the player make the decision on front or backline
	 // ShowWarning(CL_RED"Current Fight Time: %u \n" CL_RESET, fighttime);
	  if (m_PPet->m_PetID == PETID_ULMIA) 
		{
		 //ShowDebug("Ulmia Check \n");
		 if (m_Tick >= m_LastUlmiaSongTime + m_magicUlmiaRecast) // Check Every 4 Seconds as universal check
			{
			    int16 spellID = -1;
				uint16 family = m_PPet->m_Family;
				uint16 petID = m_PPet->m_PetID;
        
		        //printf("Ulmia Spell Check Triggered \n", spellID);
				spellID = UlmiaSpell();
		        //printf("Ulmia Spell is: %d \n", spellID);
				if (spellID != -1)
				{
				SetCurrentSpell(spellID);
				m_ActionType = ACTION_MAGIC_START;
				ActionMagicStart();
				return;
			    }
		    }
        }

	 if (m_PPet->m_PetID == PETID_GESSHO)
		{
		 if (m_Tick >= m_LastGesshoVokeTime + m_gesshoVokeRecast)  // Provoke is Priority over Spell Check
			{
			m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3711) { //Provoke
						    mobjaID = 19;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PBattleTarget;
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				m_LastGesshoVokeTime = m_Tick;
				return;	
			}		
		 if (m_Tick >= m_LastGesshoMagicTime + m_gesshoMagicRecast) // Check Every 4 Seconds as universal check
			{
			    int16 spellID = -1;
				uint16 family = m_PPet->m_Family;
				uint16 petID = m_PPet->m_PetID;
        
		
				spellID = GesshoSpell();
		
				if (spellID != -1)
				{
				SetCurrentSpell(spellID);
				m_ActionType = ACTION_MAGIC_START;
				ActionMagicStart();
				return;
			    }
		    }				
		}		


	  if (m_PPet->m_PetID == PETID_PRISHE)
		{
		 //ShowDebug("KUPIPI Check \n");
		 if (m_Tick >= m_LastPrisheMagicTime + m_magicPrisheRecast) // Check Every 4 Seconds as universal check
			{
			    int16 spellID = -1;
				uint16 family = m_PPet->m_Family;
				uint16 petID = m_PPet->m_PetID;
        
		
				spellID = PrisheSpell();
		        //printf("Kupipi Spell is: %d \n", spellID);
				if (spellID != -1)
				{
				SetCurrentSpell(spellID);
				m_ActionType = ACTION_MAGIC_START;
				ActionMagicStart();
				return;
			    }
		    }
        }
		


	 if (m_PPet->m_PetID == PETID_ZEID)
		{
		 if (m_Tick >= m_LastZeidMagicTime + m_zeidMagicRecast) // Check Every 4 Seconds as universal check 
			{
			    int16 spellID = -1;
				uint16 family = m_PPet->m_Family;
				uint16 petID = m_PPet->m_PetID;
        
		
				spellID = ZeidSpell();
		
				if (spellID != -1)
				{
				SetCurrentSpell(spellID);
				m_ActionType = ACTION_MAGIC_START;
				ActionMagicStart();
				return;
			    }
		    }		
		 if (m_Tick >= m_LastZeidArcaneCircleTime + m_zeidArcaneCircleRecast && m_PBattleTarget->m_EcoSystem == SYSTEM_ARCANA) // Only use Arcane Circle against Arcana
			{
			m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3755) { //Arcane Circle
						    mobjaID = 34;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				m_LastZeidArcaneCircleTime = m_Tick;
				return;	
			}
		 if (m_Tick >= m_LastZeidWeaponBashTime + m_zeidWeaponBashRecast && Action.messageID == 327)
			{
			m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3756) { //Weapon Bash
						    mobjaID = 61;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PBattleTarget;
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				m_LastZeidWeaponBashTime = m_Tick;
				return;	
			}	
		 if (m_Tick >= m_LastZeidLastResortTime + m_zeidLastResortRecast)
			{
			m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3757) { //Last Resort
						    mobjaID = 35;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				m_LastZeidLastResortTime = m_Tick;
				return;	
			}			
				
		}		

		
		 if (m_PPet->m_PetID == PETID_NAJELITH)
		{
		    if (m_Tick >= m_LastNajelithRangeTime + m_najelithRangedRecast) //Ranged Attack
			{
			    m_PWeaponSkill = nullptr;
			    int16 mobwsID = -1;
				m_LastNajelithWSTime = m_Tick; // Creates a wait time that is referenced in the WS.  Wait 7 seconds between shots before WS
			    for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                        if (PMobSkill->getID() == 946) { //Ranged Attack
                            SetCurrentMobSkill(PMobSkill);
                            break;
                        }
					}	
				preparePetAbility(m_PBattleSubTarget);
				m_LastNajelithRangeTime = m_Tick;
				return;	
			}
		    else if (m_Tick >= m_LastNajelithBerserkTime + m_najelithBerserkRecast && trustlevel >= 50)
			{
			   m_PWeaponSkill = nullptr;
               int16 mobjaID = -1;			
			   for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 441) { //Berserk
						    mobjaID = 15;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				m_LastNajelithBerserkTime = m_Tick;
				return;	
			}
		    else if (m_Tick >= m_LastNajelithSharpshotTime + m_najelithSharpshotRecast && trustlevel >= 5)
			{
			   m_PWeaponSkill = nullptr;
               int16 mobjaID = -1;			
			   for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3765) { //Sharpshot
						    mobjaID = 43;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				m_LastNajelithSharpshotTime = m_Tick;
				return;	
			}
		    else if (m_Tick >= m_LastNajelithBarrageTime + m_najelithBarrageRecast && trustlevel >= 30 && (m_Tick >= m_LastEngageStart + 15000)) // Won't use barrage until 15 seconds into the fight
			{
			   m_PWeaponSkill = nullptr;
               int16 mobjaID = -1;			
			   for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3766) { //Barrage
						    mobjaID = 44;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				m_LastNajelithBarrageTime = m_Tick;
				return;	
			}			
		 			
	     }			
	

    //if 2 bsts are in party, make sure their pets cannot fight eachother
    if (m_PBattleTarget != nullptr && m_PBattleTarget->objtype == TYPE_MOB && m_PBattleTarget->PMaster != nullptr && m_PBattleTarget->PMaster->objtype == TYPE_PC)
    {
        m_ActionType = ACTION_DISENGAGE;
        ActionDisengage();
        return;
    }


    //wyvern behaviour
    if (m_PPet->getPetType() == PETTYPE_WYVERN && m_PPet->PMaster->PBattleAI->GetBattleTarget() == nullptr) {
        m_PBattleTarget = nullptr;
    }

    //handle death of target
    if (m_PBattleTarget == nullptr ||
        m_PBattleTarget->isDead() ||
        m_PBattleTarget->animation == ANIMATION_CHOCOBO ||
        !battleutils::HasClaim(m_PPet, m_PBattleTarget))
    {
        m_ActionType = ACTION_DISENGAGE;
        ActionDisengage();
        return;
    }

    if (m_queueSic && m_PPet->health.tp >= 1000)
    {
        // now use my tp move
        m_queueSic = false;
        m_MasterCommand = MASTERCOMMAND_SIC;
        m_ActionType = ACTION_MOBABILITY_START;
        ActionAbilityStart();
        return;
    }
	
	//Skill List Check
    /*if (m_PPet->getPetType() == PETTYPE_TRUST && m_PPet->PetSkills.size() > 0)
	{
    ShowWarning(CL_GREEN"SKILL LIST HAS A SIZE!!!!!!\n" CL_RESET);	
	}
	
	if (m_PPet->getPetType() == PETTYPE_TRUST && m_PPet->PetSkills.size() == 0)
	{
    ShowWarning(CL_RED"SKILL LIST DOES NOT HAVE A SIZE!!!!!!\n" CL_RESET);	
	}*/
	//The bottom determines when Trusts will use WS.
	//Nanaa will use WS based on if SA is active, or won't be available for a certain period of time
	//Ayame will use WS if the players TP is less than 80%.  If the player's TP is 80% she will hold TP until the player get 100%.
	
	int8 petleveldiff = 0;
	uint32 tpWait = charutils::GetVar((CCharEntity*)m_PPet->PMaster,"tpWait");
	if (m_PPet->getPetType() == PETTYPE_TRUST){
	petleveldiff = (moblevel - trustlevel);  // Find level difference
	}
	
		if (m_PPet->getPetType() == PETTYPE_TRUST && m_PPet->m_PetID != PETID_NAJI && m_PPet->m_PetID != PETID_NANAA_MIHGO && m_PPet->m_PetID != PETID_AYAME && m_PPet->m_PetID != PETID_LION 
		&& m_PPet->m_PetID != PETID_PRISHE && m_PPet->m_PetID != PETID_CURILLA && m_PPet->m_PetID != PETID_ZEID && m_PPet->m_PetID != PETID_NAJELITH && m_PPet->health.tp >= 1000 && m_PPet->PetSkills.size() > 0)
    {
	    ShowWarning(CL_RED"Other Trust Triggered WS \n" CL_RESET);
		m_PBattleSubTarget = m_PBattleTarget;
        m_ActionType = ACTION_MOBABILITY_START;
        ActionAbilityStart();
        return;
	}
		if (m_PPet->getPetType() == PETTYPE_TRUST && m_Tick >= m_LastEngageStart + 3000 && m_PPet->m_PetID == PETID_CURILLA && m_PPet->health.tp >= 1000 && m_PPet->PetSkills.size() > 0
		&& m_Tick <= m_LastCurillaChivalryTime + 240000 && m_PPet->GetMPP() >= 20)  //Chivalry countdown 5 min down to 1 min and mp greater than 30% use WS
    {
	    ShowWarning(CL_RED"Other Trust Triggered WS \n" CL_RESET);
		m_PBattleSubTarget = m_PBattleTarget;
        m_ActionType = ACTION_MOBABILITY_START;
        ActionAbilityStart();
        return;
	}
		if (m_PPet->getPetType() == PETTYPE_TRUST && m_Tick >= m_LastEngageStart + 3000 && m_PPet->m_PetID == PETID_CURILLA && m_PPet->health.tp >= 1000 && m_PPet->PetSkills.size() > 0
		&& m_Tick >= m_LastCurillaChivalryTime + 300000 && m_PPet->GetMPP() >= 20)  //Chivalry countdown has ended but still WS
    {
	    ShowWarning(CL_RED"Other Trust Triggered WS \n" CL_RESET);
		m_PBattleSubTarget = m_PBattleTarget;
        m_ActionType = ACTION_MOBABILITY_START;
        ActionAbilityStart();
        return;
	}		
	
	    //Ayame will wait until 200% if sekkanoki is active
		if (m_PPet->getPetType() == PETTYPE_TRUST && m_Tick >= m_LastEngageStart + 7000 + tpWait && m_PPet->m_PetID == PETID_AYAME && m_PPet->health.tp >= 2000 && m_PPet->PetSkills.size() > 0
		&& m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SEKKANOKI) == true && m_sekkaStatus == 2)
    {
		m_PBattleSubTarget = m_PBattleTarget;
        m_ActionType = ACTION_MOBABILITY_START;
        ActionAbilityStart();
        return;
	}
	    //Ayame will use WS right after using Sekkanoki	
		if (m_PPet->getPetType() == PETTYPE_TRUST && m_Tick >= m_LastEngageStart + 7000 + tpWait && m_PPet->m_PetID == PETID_AYAME && m_PPet->health.tp >= 1000 && m_PPet->PetSkills.size() > 0 && 
		(m_Tick >= m_LastSkillchainStart + 6000) && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SEKKANOKI) == false && m_sekkaStatus == 1)
    {
		m_PBattleSubTarget = m_PBattleTarget;
        m_ActionType = ACTION_MOBABILITY_START;
        ActionAbilityStart();
        return;
	}	
	    //Ayame will use WS if player TP is less than 80%  //TODO sekka off = 0	
		if (m_PPet->getPetType() == PETTYPE_TRUST && m_Tick >= m_LastEngageStart + 7000 + tpWait && m_PPet->m_PetID == PETID_AYAME && m_PPet->health.tp >= 1000 && m_PPet->PetSkills.size() > 0 && m_PPet->PMaster->health.tp < 800
		&& m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SEKKANOKI) == false && m_sekkaStatus == 0)
    {
		m_PBattleSubTarget = m_PBattleTarget;
        m_ActionType = ACTION_MOBABILITY_START;
        ActionAbilityStart();
        return;
	}
	    //Ayame will use WS Once player has 100%		
		if (m_PPet->getPetType() == PETTYPE_TRUST && m_Tick >= m_LastEngageStart + 7000 + tpWait && m_PPet->m_PetID == PETID_AYAME && m_PPet->health.tp >= 1000 && m_PPet->PetSkills.size() > 0 && m_PPet->PMaster->health.tp >= 1000
		&& m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SEKKANOKI) == false && m_sekkaStatus == 0)
    {
		m_PBattleSubTarget = m_PBattleTarget;
        m_ActionType = ACTION_MOBABILITY_START;
        ActionAbilityStart();
        return;
	}
	/*
		//Ayame will wait for player to get 100% Tp if they are at 80%
		if (m_PPet->getPetType() == PETTYPE_TRUST && m_PPet->m_PetID == PETID_AYAME && m_PPet->health.tp >= 1000 && m_PPet->PetSkills.size() > 0
		&& m_PPet->PMaster->health.tp > 1000)
    {
		m_PBattleSubTarget = m_PBattleTarget;
        m_ActionType = ACTION_MOBABILITY_START;
        ActionAbilityStart();
        return;
	} */
	    //Use WS if SA is active
		if (m_PPet->getPetType() == PETTYPE_TRUST && m_Tick >= m_LastEngageStart + 7000 + tpWait && m_PPet->m_PetID == PETID_NANAA_MIHGO && m_PPet->health.tp >= 1000 && m_PPet->PetSkills.size() > 0
		&& m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_TRUST_SNEAK_ATTACK))
    {
		m_PBattleSubTarget = m_PBattleTarget;
        m_ActionType = ACTION_MOBABILITY_START;
        ActionAbilityStart();
        return;
	}
	    //Use WS if SA timer has more than 25 seconds left
		if (m_PPet->getPetType() == PETTYPE_TRUST && m_Tick >= m_LastEngageStart + 7000 + tpWait && m_PPet->m_PetID == PETID_NANAA_MIHGO && m_PPet->health.tp >= 1000 && m_PPet->PetSkills.size() > 0
		&& m_Tick < m_LastNanaaSneakAttackTime + 20000)
    {
		m_PBattleSubTarget = m_PBattleTarget;
        m_ActionType = ACTION_MOBABILITY_START;
        ActionAbilityStart();
        return;
	}
	    //No SA available for Nanaa Yet
		if (m_PPet->getPetType() == PETTYPE_TRUST && m_Tick >= m_LastEngageStart + 7000 + tpWait && m_PPet->m_PetID == PETID_NANAA_MIHGO && m_PPet->health.tp >= 1000 && m_PPet->PetSkills.size() > 0
		&& trustlevel < 15)
    {
		m_PBattleSubTarget = m_PBattleTarget;
        m_ActionType = ACTION_MOBABILITY_START;
        ActionAbilityStart();
        return;
	}
		if (m_PPet->getPetType() == PETTYPE_TRUST && m_Tick >= m_LastEngageStart + 7000 + tpWait && m_PPet->m_PetID == PETID_NAJI && m_PPet->health.tp >= 1000 && m_PPet->PetSkills.size() > 0)
    {
		m_PBattleSubTarget = m_PBattleTarget;
        m_ActionType = ACTION_MOBABILITY_START;
        ActionAbilityStart();
        return;
	} 
		if (m_PPet->getPetType() == PETTYPE_TRUST && m_Tick >= m_LastEngageStart + 7000 + tpWait && m_PPet->m_PetID == PETID_BLUE && m_PPet->health.tp >= 1000 && m_PPet->PetSkills.size() > 0)
    {
		m_PBattleSubTarget = m_PBattleTarget;
        m_ActionType = ACTION_MOBABILITY_START;
        ActionAbilityStart();
        return;
	} 	
		if (m_PPet->getPetType() == PETTYPE_TRUST && m_Tick >= m_LastEngageStart + 7000 + tpWait && m_PPet->m_PetID == PETID_ADELHIED && m_PPet->health.tp >= 1000 && m_PPet->PetSkills.size() > 0)
    {
		m_PBattleSubTarget = m_PBattleTarget;
        m_ActionType = ACTION_MOBABILITY_START;
        ActionAbilityStart();
        return;
	}
		if (m_PPet->getPetType() == PETTYPE_TRUST && m_Tick >= m_LastEngageStart + 7000 + tpWait && m_PPet->m_PetID == PETID_EXCENMILLE && m_PPet->health.tp >= 1000 && m_PPet->PetSkills.size() > 0)
    {
		m_PBattleSubTarget = m_PBattleTarget;
        m_ActionType = ACTION_MOBABILITY_START;
        ActionAbilityStart();
        return;
	}
		if (m_PPet->getPetType() == PETTYPE_TRUST && m_Tick >= m_LastEngageStart + 7000 + tpWait && m_Tick >= m_LastNajelithWSTime + 7000 && m_PPet->m_PetID == PETID_NAJELITH && m_PPet->health.tp >= 1000 && m_PPet->PetSkills.size() > 0)
    {
		m_PBattleSubTarget = m_PBattleTarget;
        m_ActionType = ACTION_MOBABILITY_START;
        ActionAbilityStart();
        return;
	}	
	
	
	CBattleEntity* lionSCPartner = getLionSCPartnerZeid();
	CBattleEntity* zeidSCPartner = getZeidSCPartner();
	
	// First check if Lion has TP
	if (m_PPet->getPetType() == PETTYPE_TRUST && m_Tick >= m_LastEngageStart + 7000 + tpWait && m_PPet->m_PetID == PETID_LION && m_PPet->health.tp >= 1000 && m_PPet->PetSkills.size() > 0)
	{
	   //Now check if Zeid is in the party
	    if (m_PPet->m_PetID == PETID_LION && lionSCPartner != nullptr) //Zeid is in the party
	    {
	        if (m_PPet->m_PetID == PETID_LION && lionSCPartner->health.tp >= 1000)
			{
				
                //int16 wsReady = skillchainTimer();//starts the timer
				ShowWarning(CL_GREEN"LION and ZEID have TP!! LION START SC!! APPLY EFFECT TO MOB \n" CL_RESET);
		        m_PBattleSubTarget = m_PBattleTarget;
				m_PBattleTarget->StatusEffectContainer->AddStatusEffect(new CStatusEffect(EFFECT_TRUST_SKILLCHAIN_TIMER, EFFECT_TRUST_SKILLCHAIN_TIMER, 1, 0, 9),true);
                m_ActionType = ACTION_MOBABILITY_START;
                ActionAbilityStart();
                return;
			}
			else
			{
			    //ShowWarning(CL_CYAN"LION TP BUT ZEID DOESNT!!! \n" CL_RESET);	
			}
	    }
		//Add Else IF for Prishe 
		else if (m_PPet->m_PetID == PETID_LION && lionSCPartner == nullptr) //Zeid is not in the party
	    {
		    //ShowWarning(CL_CYAN"ZEID IS NOT IN THE PARTY SO SC WHENEVER!!! \n" CL_RESET);
		    m_PBattleSubTarget = m_PBattleTarget;
            m_ActionType = ACTION_MOBABILITY_START;
            ActionAbilityStart();
            return;
	    }
	}

	//TODO ADD PRISHE DETERMINATION

	if (m_PPet->getPetType() == PETTYPE_TRUST && m_Tick >= m_LastEngageStart + 7000 + tpWait && m_PPet->m_PetID == PETID_ZEID && m_PPet->health.tp >= 1000 && m_PPet->PetSkills.size() > 0)
    {
	    //ShowWarning(CL_CYAN"ZEID Checking to see if approrpiate for Skillchain!! \n" CL_RESET);
		uint32 zeidSCReady = charutils::GetVar((CCharEntity*)m_PPet->PMaster,"ZeidSCReady");	
		if (m_PPet->m_PetID == PETID_ZEID && zeidSCPartner != nullptr && (m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_TRUST_SKILLCHAIN_TIMER) == false) && zeidSCReady > 0) 
		{
		    //int16 zeidSCReady = skillchainTimer();
			//zeidSCReady = ZeidSkillchain();
			//ShowWarning(CL_GREEN"EFFECT IS OFF THE MOB!! \n" CL_RESET);
		    if (m_PPet->m_PetID == PETID_ZEID)
			{
			    //ShowWarning(CL_GREEN"START ZEID SKILLCHAIN LION HAS Melee'd enough!! \n" CL_RESET);
				m_PBattleSubTarget = m_PBattleTarget;
                m_ActionType = ACTION_MOBABILITY_START;
                ActionAbilityStart();
                return;
			}
			else
			{
			    //ShowWarning(CL_CYAN"ZEID HAS TP WAITING FOR LION TO WS!!! \n" CL_RESET);
			}
		}
		else if (m_PPet->m_PetID == PETID_ZEID && zeidSCPartner == nullptr)
		{
		    ShowWarning(CL_CYAN"LION NOT PRESENT GOING TO WS ANYWAYS!!! \n" CL_RESET);
		    m_PBattleSubTarget = m_PBattleTarget;
            m_ActionType = ACTION_MOBABILITY_START;
            ActionAbilityStart();
            return;
		}	
	}  	

    m_PPathFind->LookAt(m_PBattleTarget->loc.p);

    float currentDistance = distance(m_PPet->loc.p, m_PBattleTarget->loc.p);
	
	float currentPlayerDistance = distance(m_PPet->PMaster->loc.p, m_PBattleTarget->loc.p);

    //go to target if its too far away
	/*
    if (currentDistance > m_PBattleTarget->m_ModelSize && m_PPet->m_PetID == PETID_NANAA_MIHGO || m_PPet->m_PetID == PETID_KUPIPI && m_PPet->speed != 0)
    {
        if (m_PPathFind->PathBehind(m_PBattleTarget->loc.p, 2.0f, PATHFLAG_RUN | PATHFLAG_WALLHACK))
        {
            m_PPathFind->FollowPath();

            // recalculate
            currentDistance = distance(m_PPet->loc.p, m_PBattleTarget->loc.p);
			
        }
		
	/*	if (!m_PPathFind->IsFollowingPath())
		{
			//Trust has arrived at the target
			printf("I am not following /n");
			auto angle = getangle(m_PPet->loc.p, m_PBattleTarget->loc.p) + 150;
			position_t new_pos{ 0, m_PPet->loc.p.x - (cosf(rotationToRadian(angle)) * 1.5f),
				m_PBattleTarget->loc.p.y, m_PPet->loc.p.z + (sinf(rotationToRadian(angle)) * 2.5f), 0 };

				m_PPathFind->PathTo(new_pos, PATHFLAG_WALLHACK | PATHFLAG_RUN);
			
		} 
		
    }   */
	
	
	    //go to target if its too far away
		
	/*	
		if (currentDistance < 10 && m_PPet->m_PetID == PETID_ADELHIED)
    {
	    position_t* pos = &m_PBattleTarget->loc.p;
		position_t nearEntity = nearPosition(*pos, 8.0f, M_PI);
        if (m_PPathFind->PathTo(nearEntity, PATHFLAG_RUN | PATHFLAG_WALLHACK))
        {
            m_PPathFind->FollowPath();

            // recalculate
            currentDistance = distance(m_PPet->loc.p, m_PBattleTarget->loc.p);
        }
    } */
    	
	
	//if (currentDistance < 8 && m_PPet->m_PetID == PETID_ADELHIED && m_PPet->speed != 0)
	
	//**************************************************//
	// Distance Determinator for Ulmia                 //
	// She changes distance based on the song she will //
	//cast                                             //
	//*************************************************//
	
    uint32 songcombo = charutils::GetVar((CCharEntity*)m_PPet->PMaster,"UlmiaSong");   
	
	//------------- Ulmia Move to the back if master has Correct Songs ------------//
	//TODO Certain Levels this will work but not all due to song availablity
	if ((songcombo == 10 && m_PPet->m_PetID == PETID_ULMIA && (currentDistance < 12 || currentDistance > 13) && m_PPet->speed !=0) || 
	((currentDistance < 12 || currentDistance > 13) && m_PPet->m_PetID == PETID_ULMIA && m_PPet->speed != 0
    && (m_PPet->PMaster->StatusEffectContainer->HasStatusEffectByFlag(EFFECTFLAG_SONG))) && 
	((m_PPet->PMaster->StatusEffectContainer->GetEffectsCount(EFFECT_MINUET) > 1) ||
	 (m_PPet->PMaster->StatusEffectContainer->GetEffectsCount(EFFECT_MARCH) > 1) ||
	 (m_PPet->PMaster->StatusEffectContainer->GetEffectsCount(EFFECT_MADRIGAL) > 1) ||
	 (m_PPet->PMaster->StatusEffectContainer->GetEffectsCount(EFFECT_MINUET) == 1 && (m_PPet->PMaster->StatusEffectContainer->GetEffectsCount(EFFECT_MADRIGAL) == 1)) ||
	 (m_PPet->PMaster->StatusEffectContainer->GetEffectsCount(EFFECT_MINUET) == 1 && (m_PPet->PMaster->StatusEffectContainer->GetEffectsCount(EFFECT_MARCH) == 1))))
    {
	    ShowWarning(CL_RED"Ulma Move to Back Line triggered \n" CL_RESET);
	    position_t* pos = &m_PBattleTarget->loc.p;
		position_t nearEntity = nearPosition(*pos, 13.0f, M_PI); // add decimal to pi maybe.  
        if (m_PPathFind->PathAround(nearEntity, PATHFLAG_RUN | PATHFLAG_WALLHACK))
        {
            m_PPathFind->FollowPath();		
        }
    }
	//------------- Ulmia Move to the Front Line to cast songs at the start of a fight ------------//
	else if (((currentDistance > m_PBattleTarget->m_ModelSize) && (m_PPet->m_PetID == PETID_ULMIA) && (m_PPet->speed != 0)) &&
	(m_Tick >= m_LastSongFrontTime + m_songFront))
    {
	    ShowWarning(CL_RED"Ulma Move to Front Line triggered \n" CL_RESET);
        if (m_PPathFind->PathAround(m_PBattleTarget->loc.p, 2.0f, PATHFLAG_RUN | PATHFLAG_WALLHACK))
        {
            m_PPathFind->FollowPath();

            // recalculate
            currentDistance = distance(m_PPet->loc.p, m_PBattleTarget->loc.p);
			
        }
    }	

	//------------- Ulmia Move to the Front Line if Ballad Is on Self ------------//
	//TODO Certain Levels this will work but not all due to song availablity
    // MOVE TO FRONT IF NO SONGS PRESENT ON MASTER OR ONE SONG PRESENT ON PETS

    /* else if (((m_PPet->m_PetID != PETID_ULMIA) && (m_PPet->StatusEffectContainer->HasStatusEffectByFlag(EFFECTFLAG_SONG) == false)))  //TEST IF TRUSTS HAVE NO SONGS
	{
	    ShowWarning(CL_GREEN"Only One Song on other Trusts is Active \n" CL_RESET);
		if ((currentDistance > m_PBattleTarget->m_ModelSize) && (m_PPet->m_PetID == PETID_ULMIA) && (m_PPet->speed != 0))
		{
	        ShowWarning(CL_GREEN"Ulma Move to Front Line triggered because other trusts have 1 song \n" CL_RESET);
            if (m_PPathFind->PathAround(m_PBattleTarget->loc.p, 2.0f, PATHFLAG_RUN | PATHFLAG_WALLHACK))
            {
                m_PPathFind->FollowPath();
                currentDistance = distance(m_PPet->loc.p, m_PBattleTarget->loc.p);
			}
        }		
	} 	*/	
 	
	
	
	
	
    if ((currentDistance < 12 || currentDistance > 13) && m_PPet->m_PetID == PETID_ADELHIED && m_PPet->speed != 0)
    {
	    position_t* pos = &m_PBattleTarget->loc.p;
		position_t nearEntity = nearPosition(*pos, 13.0f, M_PI - 0.08);
        if (m_PPathFind->PathAround(nearEntity, PATHFLAG_RUN | PATHFLAG_WALLHACK))
        {
            m_PPathFind->FollowPath();

            // recalculate
            //currentDistance = distance(m_PPet->loc.p, m_PBattleTarget->loc.p);
			
        }
    }
	

    //Move Kupipi to the backline if the mob is 5 levels higher than you
 /*   if ((currentDistance < 12 || currentDistance > 13) && checklevel >= 5 && m_PPet->m_PetID == PETID_KUPIPI && m_PPet->speed != 0)
    {
	    position_t* pos = &m_PBattleTarget->loc.p;
		position_t nearEntity = nearPosition(*pos, 13.0f, M_PI);
        if (m_PPathFind->PathAround(nearEntity, PATHFLAG_RUN | PATHFLAG_WALLHACK))
        {
            m_PPathFind->FollowPath();

            // recalculate
            //currentDistance = distance(m_PPet->loc.p, m_PBattleTarget->loc.p);
			
        }
    } */
	
	
	 /*  if (currentDistance < 9 && m_PPet->m_PetID == PETID_ADELHIED && m_PPet->speed != 0)
    {
	    ShowWarning(CL_GREEN"Adelhied Distance is less than 9\n" CL_RESET);
	    position_t nearEntity = {m_PBattleTarget->loc.p.x + 10, m_PBattleTarget->loc.p.y, m_PBattleTarget->loc.p.z};
		
		
        if (m_PPathFind->PathTo(nearEntity, PATHFLAG_RUN | PATHFLAG_WALLHACK))
        {
            m_PPathFind->FollowPath();

            // recalculate
           // currentDistance = distance(m_PPet->loc.p, m_PBattleTarget->loc.p);
			
        }
    }	*/
	
	
	
	
	/*
    if (currentDistance < 8 && m_PPet->m_PetID == PETID_ADELHIED && m_PPet->speed != 0)
    {
        if (m_PPathFind->PathAround(m_PBattleTarget->loc.p, 11.0f, PATHFLAG_RUN | PATHFLAG_WALLHACK))
        {
            m_PPathFind->FollowPath();

            // recalculate
            currentDistance = distance(m_PPet->loc.p, m_PBattleTarget->loc.p);
			
        }
    }	*/
	
		
	int32 fighttime = ((CBattleEntity*)m_PPet->PMaster)->PBattleAI->GetBattleTime();
		
    if (currentDistance > m_PBattleTarget->m_ModelSize && (m_PPet->m_PetID != PETID_ULMIA && m_PPet->m_PetID != PETID_KUPIPI &&
	m_PPet->m_PetID != PETID_NANAA_MIHGO && m_PPet->m_PetID != PETID_ADELHIED && m_PPet->m_PetID != PETID_CURILLA && m_PPet->m_PetID != PETID_SHANTOTTO) // Add Lion back to this when working on Trick Attack
	&& m_PPet->speed != 0)
    {
	    //ShowWarning(CL_RED"Wrong Distance triggered\n" CL_RESET);
        if (m_PPathFind->PathAround(m_PBattleTarget->loc.p, 2.0f, PATHFLAG_RUN | PATHFLAG_WALLHACK))
        {
            m_PPathFind->FollowPath();

            // recalculate
            currentDistance = distance(m_PPet->loc.p, m_PBattleTarget->loc.p);
			
        }
    }
	
	 if (currentDistance > m_PBattleTarget->m_ModelSize && (m_PPet->m_PetID == PETID_CURILLA) && m_PPet->speed != 0)
    {
	    //ShowWarning(CL_RED"Wrong Distance triggered\n" CL_RESET);
        if (m_PPathFind->PathAround(m_PBattleTarget->loc.p, 2.0f, PATHFLAG_RUN | PATHFLAG_WALLHACK))  //Put Curilla Close
        {
            m_PPathFind->FollowPath();

            // recalculate
            currentDistance = distance(m_PPet->loc.p, m_PBattleTarget->loc.p);
			
        }
    }

	
	// Disabled Lion Distance
	/*
	
	//LION Set her always 45 degrees from the mob if Trick Attack is not available
	if (m_PPet->m_PetID == PETID_LION){
		CMobEntity* PMob = (CMobEntity*)m_PBattleTarget;
		CBattleEntity* trickAttackPartner = getTrickAttackPartner();
		//m_PBattleSubTarget = trickAttackPartner;
		//int8 rotation = m_PBattleTarget->loc.p.rotation - m_PPet->loc.p.rotation;
		uint32 engaging = m_Tick - m_LastEngageStart + 7000;
		//int8 tahp = trickAttackPartner->health.hp;
		
		//if (trickAttackPartner == m_PPet->getPetType() == PETTYPE_TRUST)
		//{
		//   ShowWarning(CL_GREEN"TRICK ATTACK PARTNER IS A TRUST \n", CL_RESET);
		//}


	    if (m_Tick >= m_LastLionCheckTime + m_lionCheck) // Every 10 seconds to see to decide if Lion needs to move
	    {
		    //ShowWarning(CL_GREEN"LION TA CHECK!! \n" CL_RESET);
			
	        // SUPER EXPERIMENTAL - First check to see if there is a valid TA partner which is Trust PLD or NIN
			// Then set that object/trust as the object to move around and get behind
			//ShowWarning(CL_GREEN"LION Fight Time is: %i \n", CL_RESET, fighttime);
			//Check to see if Lion is 45 degrees to the target or not and used TA recently
			
	       // if ((abs(m_PBattleTarget->loc.p.rotation - m_PPet->loc.p.rotation) > 34) &&
		   // (abs(m_PBattleTarget->loc.p.rotation - m_PPet->loc.p.rotation) < 152) && PMob->PEnmityContainer->GetHighestEnmity() != m_PPet &&
		//	m_Tick >= m_LastLionTrickAttackTime + 8000 && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_TRUST_TRICK_ATTACK) == false) // used Trick Attack wait for hit then move change to not having the status effect
		

           



		
		    //if (((((abs(m_PBattleTarget->loc.p.rotation - m_PPet->loc.p.rotation) - 64) < 120) && ((abs(m_PBattleTarget->loc.p.rotation - m_PPet->loc.p.rotation)) > 64)) 
			//|| ((abs(m_PBattleTarget->loc.p.rotation - m_PPet->loc.p.rotation) - 64) > 136)) && PMob->PEnmityContainer->GetHighestEnmity() != m_PPet &&
			//m_Tick >= m_LastLionTrickAttackTime + 8000 && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_TRUST_TRICK_ATTACK) == false) // used Trick Attack wait for hit then move change to not having the status effect
			//Not 45 degrees so send Lion 45 degrees to the target

			/*
		    else if (((abs(m_PBattleTarget->loc.p.rotation - m_PPet->loc.p.rotation) + 64) > 160) && PMob->PEnmityContainer->GetHighestEnmity() != m_PPet &&
			m_Tick >= m_LastLionTrickAttackTime + 8000 && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_TRUST_TRICK_ATTACK) == false) // used Trick Attack wait for hit then move change to not having the status effect
			//Not 45 degrees so send Lion 45 degrees to the target
		    {	
			    ShowWarning(CL_RED"LION DOESNT HAVE HATE SO MOVING 45 DEGREES second\n" CL_RESET);
			    position_t* pos = &m_PBattleTarget->loc.p;
			    position_t nearEntity = nearPosition(*pos, 2.0f, 0.5f * M_PI); 
			    m_PPathFind->PathTo(nearEntity, PATHFLAG_WALLHACK | PATHFLAG_RUN);
			    {
			        m_PPathFind->FollowPath();
			    }
		        m_LastLionCheckTime = m_Tick;  
            }*/
			
			
			//***********************************************************************//
			//Last known Trick Attack Placement I was Working on.  Needs more work  //
			//**********************************************************************//
			
			/*
		    if ((abs(m_PBattleTarget->loc.p.rotation - m_PPet->loc.p.rotation) > 23) && m_PPet->m_PetID == PETID_LION && PMob->PEnmityContainer->GetHighestEnmity() != m_PPet) //Send Lion to the back 
		    {	
			    ShowWarning(CL_RED"LION DOESNT HAVE HATE SO MOVING TO BACKLINE\n" CL_RESET);
			    position_t* pos = &m_PBattleTarget->loc.p;
			    position_t nearEntity = nearPosition(*pos, 4.0f, M_PI);  
			    m_PPathFind->PathTo(nearEntity, PATHFLAG_WALLHACK | PATHFLAG_RUN);
			    {
				    m_PPathFind->FollowPath();
			    }
			    m_LastLionCheckTime = m_Tick;  
            }			
			else if (m_Tick >= m_LastLionTrickAttackTime + m_lionTrickAttackRecast && trickAttackPartner != nullptr) //If TA is up and there is a TA Partner
			{
			    //Do Distance
				ShowWarning(CL_RED"LION HAS A TRICK ATTACK PARTNER MOVING BEHIND TANK\n" CL_RESET);
				//ShowWarning(CL_GREEN"LION difference is: %i \n", CL_RESET, rotation);
				
				if (abs(trickAttackPartner->loc.p.rotation - m_PPet->loc.p.rotation) > 23) 
				//&& currentDistance <= m_PBattleTarget->m_ModelSize)
				
				//if ((abs(trickAttackPartner->loc.p.rotation - m_PPet->loc.p.rotation) > 20) && currentDistance <= m_PBattleTarget->m_ModelSize)
				//(abs(trickAttackPartner->loc.p.rotation - m_PPet->loc.p.rotation) < 118)) // This should mean not facing the tanks target
				{
				ShowWarning(CL_RED"LION triggered 1st condition and is attempting to move in front of target\n" CL_RESET);
				    position_t* pos = &trickAttackPartner->loc.p;
			        position_t nearEntity = nearPosition(*pos, 3.0f, M_PI);
			        m_PPathFind->PathTo(nearEntity, PATHFLAG_WALLHACK | PATHFLAG_RUN);
			        {
				        m_PPathFind->FollowPath();
			        }
					m_LastLionCheckTime = m_Tick;
				}
			
				else if ((abs(trickAttackPartner->loc.p.rotation - m_PPet->loc.p.rotation) > 135) && 
				(abs(trickAttackPartner->loc.p.rotation - m_PPet->loc.p.rotation) < 250)) // This should mean not facing the tanks target
				{
				ShowWarning(CL_RED"LION triggered SECOND condition\n" CL_RESET);
				    position_t* pos = &trickAttackPartner->loc.p;
			        position_t nearEntity = nearPosition(*pos, 3.6f, M_PI + 0.09);
			        m_PPathFind->PathTo(nearEntity, PATHFLAG_WALLHACK | PATHFLAG_RUN);
			        {
				        m_PPathFind->FollowPath();
			        }
					m_LastLionCheckTime = m_Tick;
				} */	

          /* Remove This				
			}			
		    else
			{	
			    //Already 45 degrees
			    //m_nanaacheck = 5000;
                m_LastLionCheckTime = m_Tick;
			}
	    }
	} */	
	
	
	
	if (m_PPet->m_PetID == PETID_NANAA_MIHGO){
	if (m_Tick >= m_LastNanaaCheckTime + m_nanaacheck) // Every 5 seconds to see if nanaa or kupipi is not facing target
	{
	    //Check to see if facing target
		//ShowDebug("NANAA FACING CHECK  \n");
	    if ((abs(m_PBattleTarget->loc.p.rotation - m_PPet->loc.p.rotation) > 5) &&
		(abs(m_PBattleTarget->loc.p.rotation - m_PPet->loc.p.rotation) < 118)) 
		//Not facing target have Nanaa Mihgo Behind the Target
		{	
		    //ShowWarning(CL_GREEN"Nanaa is moving behind the target\n" CL_RESET);
			//ShowDebug("Greater than 10 and less than 118  \n");
			position_t* pos = &m_PBattleTarget->loc.p;
			position_t nearEntity = nearPosition(*pos, 2.0f, M_PI);
			m_PPathFind->PathTo(nearEntity, PATHFLAG_WALLHACK | PATHFLAG_RUN);
			{
				m_PPathFind->FollowPath();
			}
			m_nanaacheck = 0;
		
            
        }
		else if (((abs(m_PBattleTarget->loc.p.rotation - m_PPet->loc.p.rotation) > 135) &&
		(abs(m_PBattleTarget->loc.p.rotation - m_PPet->loc.p.rotation) < 250)) && m_PPet->m_PetID == PETID_NANAA_MIHGO) 
		//Not facing target have Nanaa Mihgo Behind the Target
		{	
		    //ShowWarning(CL_GREEN"Nanaa is moving behind the target\n" CL_RESET);
			//ShowDebug("Greater than 135 and less than 245  \n");
			position_t* pos = &m_PBattleTarget->loc.p;
			position_t nearEntity = nearPosition(*pos, 2.0f, M_PI);
			m_PPathFind->PathTo(nearEntity, PATHFLAG_WALLHACK | PATHFLAG_RUN);
			{
			m_PPathFind->FollowPath();
			}
		    m_nanaacheck = 0;
            
        }

		
		else
			{	
             //ShowWarning(CL_RED"NANAA IS IN FRONT OR BEHIND THE MOB.  DONT MOVE!!\n" CL_RESET);
			 m_nanaacheck = 5000;
             m_LastNanaaCheckTime = m_Tick;
			}
		
	}
	}
	
	
	if (m_PPet->m_PetID == PETID_KUPIPI && (checklevel < 5 && !(PMob->m_Type & MOBTYPE_NOTORIOUS))){
	if (m_Tick >= m_LastNanaaCheckTime + m_nanaacheck) // Every 5 seconds to see if nanaa or kupipi is not facing target
	{
	    //Check to see if facing target
		//ShowDebug("NANAA FACING CHECK  \n");
	    if ((abs(m_PBattleTarget->loc.p.rotation - m_PPet->loc.p.rotation) > 5) &&
		(abs(m_PBattleTarget->loc.p.rotation - m_PPet->loc.p.rotation) < 118)) 
		//Not facing target have Nanaa Mihgo Behind the Target
		{	
		    //ShowWarning(CL_GREEN"Nanaa is moving behind the target\n" CL_RESET);
			//ShowDebug("Greater than 10 and less than 118  \n");
			position_t* pos = &m_PBattleTarget->loc.p;
			position_t nearEntity = nearPosition(*pos, 2.0f, M_PI);
			m_PPathFind->PathTo(nearEntity, PATHFLAG_WALLHACK | PATHFLAG_RUN);
			{
				m_PPathFind->FollowPath();
			}
			m_nanaacheck = 0;
		
            
        }
		else if (((abs(m_PBattleTarget->loc.p.rotation - m_PPet->loc.p.rotation) > 135) &&
		(abs(m_PBattleTarget->loc.p.rotation - m_PPet->loc.p.rotation) < 250)) &&  m_PPet->m_PetID == PETID_KUPIPI) 
		//Not facing target have Nanaa Mihgo Behind the Target
		{	
		    //ShowWarning(CL_GREEN"Nanaa is moving behind the target\n" CL_RESET);
			//ShowDebug("Greater than 135 and less than 245  \n");
			position_t* pos = &m_PBattleTarget->loc.p;
			position_t nearEntity = nearPosition(*pos, 2.0f, M_PI);
			m_PPathFind->PathTo(nearEntity, PATHFLAG_WALLHACK | PATHFLAG_RUN);
			{
			m_PPathFind->FollowPath();
			}
		    m_nanaacheck = 0;
            
        }

		
		else
			{	
             //ShowWarning(CL_RED"NANAA IS IN FRONT OR BEHIND THE MOB.  DONT MOVE!!\n" CL_RESET);
			 m_nanaacheck = 5000;
             m_LastNanaaCheckTime = m_Tick;
			}
		
	}
	}
	
	
	if (m_PPet->m_PetID == PETID_SHANTOTTO)  //Shantotto always stays back
	{
        if ((currentDistance < 12 || currentDistance > 13) && m_PPet->speed != 0)
        {
	        position_t* pos = &m_PBattleTarget->loc.p;
		    position_t nearEntity = nearPosition(*pos, 13.0f, M_PI + 0.08);  //This will offset Kupipi to the right by 10 degrees
            if (m_PPathFind->PathAround(nearEntity, PATHFLAG_RUN | PATHFLAG_WALLHACK))
            {
                m_PPathFind->FollowPath();

            // recalculate
            //currentDistance = distance(m_PPet->loc.p, m_PBattleTarget->loc.p);	
            }
        }    
	}	
	
	
	
	// Below is for Kupipi 3.0 to move to the backline
	

	if (m_PPet->m_PetID == PETID_KUPIPI && (checklevel >= 5 || PMob->m_Type & MOBTYPE_NOTORIOUS))
	{
        if ((currentDistance < 12 || currentDistance > 13) && m_PPet->speed != 0)
        {
	        position_t* pos = &m_PBattleTarget->loc.p;
		    position_t nearEntity = nearPosition(*pos, 13.0f, M_PI + 0.08);  //This will offset Kupipi to the right by 10 degrees
            if (m_PPathFind->PathAround(nearEntity, PATHFLAG_RUN | PATHFLAG_WALLHACK))
            {
                m_PPathFind->FollowPath();

            // recalculate
            //currentDistance = distance(m_PPet->loc.p, m_PBattleTarget->loc.p);	
            }
        }
        else
        {
	        position_t* pos = &m_PBattleTarget->loc.p;
		    position_t nearEntity = nearPosition(*pos, 13.0f, M_PI + 0.08);  //This will offset Kupipi to the right by 10 degrees
            if (m_PPathFind->PathAround(nearEntity, PATHFLAG_RUN | PATHFLAG_WALLHACK))
            {
                m_PPathFind->FollowPath();

            // recalculate
            //currentDistance = distance(m_PPet->loc.p, m_PBattleTarget->loc.p);	
            }
        } 


		
	}
	else if (m_PPet->m_PetID == PETID_KUPIPI)
	{
	    if (m_Tick >= m_LastNanaaCheckTime + m_nanaacheck) // Every 5 seconds to see if nanaa or kupipi is not facing target
	    {
	        //Check to see if facing target
		    //ShowDebug("NANAA FACING CHECK  \n");
	        if ((abs(m_PBattleTarget->loc.p.rotation - m_PPet->loc.p.rotation) > 5) &&
		    (abs(m_PBattleTarget->loc.p.rotation - m_PPet->loc.p.rotation) < 118)) 
		    //Not facing target have Nanaa Mihgo Behind the Target
	    	{	
		        //ShowWarning(CL_GREEN"Nanaa is moving behind the target\n" CL_RESET);
			    //ShowDebug("Greater than 10 and less than 118  \n");
			    position_t* pos = &m_PBattleTarget->loc.p;
			    position_t nearEntity = nearPosition(*pos, 13.0f, M_PI);
			    m_PPathFind->PathTo(nearEntity, PATHFLAG_WALLHACK | PATHFLAG_RUN);
			    {
				    m_PPathFind->FollowPath();
		    	}
			    m_nanaacheck = 0;
            }
	    	else if (((abs(m_PBattleTarget->loc.p.rotation - m_PPet->loc.p.rotation) > 135) &&
		    (abs(m_PBattleTarget->loc.p.rotation - m_PPet->loc.p.rotation) < 250)) &&  m_PPet->m_PetID == PETID_KUPIPI) 
		    //Not facing target have Nanaa Mihgo Behind the Target
		    {	
		        //ShowWarning(CL_GREEN"Nanaa is moving behind the target\n" CL_RESET);
			    //ShowDebug("Greater than 135 and less than 245  \n");
			    position_t* pos = &m_PBattleTarget->loc.p;
			    position_t nearEntity = nearPosition(*pos, 13.0f, M_PI);
		    	m_PPathFind->PathTo(nearEntity, PATHFLAG_WALLHACK | PATHFLAG_RUN);
			    {
			        m_PPathFind->FollowPath();
			    }
		        m_nanaacheck = 0;    
            }
	    	else
			{	
             //ShowWarning(CL_RED"NANAA IS IN FRONT OR BEHIND THE MOB.  DONT MOVE!!\n" CL_RESET);
		 	    m_nanaacheck = 5000;
                m_LastNanaaCheckTime = m_Tick;
			}	
	    }
	} 

	
	
	

	
    if (currentDistance <= m_PBattleTarget->m_ModelSize && m_PPet->m_PetID != PETID_ULMIA)
    {
        int32 WeaponDelay = m_PPet->m_Weapons[SLOT_MAIN]->getDelay();
        //try to attack
		CAttackRound attackRound(m_PPet);
        if (m_Tick > m_LastActionTime + WeaponDelay) {
            if (battleutils::IsParalyzed(m_PPet))
            {
                m_PPet->loc.zone->PushPacket(m_PPet, CHAR_INRANGE, new CMessageBasicPacket(m_PPet, m_PBattleTarget, 0, 0, 29));
            }
            else if (battleutils::IsIntimidated(m_PPet, m_PBattleTarget))
            {
                m_PPet->loc.zone->PushPacket(m_PPet, CHAR_INRANGE, new CMessageBasicPacket(m_PPet, m_PBattleTarget, 0, 0, 106));
            }
            else
            {
                apAction_t Action;
                m_PPet->m_ActionList.clear();

                Action.ActionTarget = m_PBattleTarget;

                uint8 numAttacks = battleutils::CheckMultiHits(m_PPet, m_PPet->m_Weapons[SLOT_MAIN]);
				uint8 offAttacks = m_PPet->getMod(MOD_DUAL_WIELD) > 0 ? battleutils::CheckMultiHits(m_PPet, m_PPet->m_Weapons[SLOT_SUB]) : 0;

				

                for (uint8 i = 0; i < (numAttacks + offAttacks); i++) {
                    Action.reaction = REACTION_EVADE;
                    Action.speceffect = SPECEFFECT_NONE;
					Action.animation = i >= numAttacks ? 1 : 0;
                    Action.param = 0;
                    Action.messageID = 15;
                    Action.knockback = 0;
                    //ShowDebug("pet hp %i and atk %i def %i eva is %i \n",m_PPet->health.hp,m_PPet->ATT(),m_PPet->DEF(),m_PPet->getMod(MOD_EVA));
                    int32 damage = 0;

                    if (m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_PERFECT_DODGE))
                    {
                        Action.messageID = 32;
                    }
                    else if ((dsprand::GetRandomNumber(100) < battleutils::GetHitRate(m_PPet, m_PBattleTarget)) &&
                        !m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_ALL_MISS))
                    {
                        if (battleutils::IsAbsorbByShadow(m_PBattleTarget))
                        {
                            Action.messageID = 31;
                            Action.param = 1;
                            Action.reaction = REACTION_EVADE;
                        }
                        else
                        {
                            Action.reaction = REACTION_HIT;
                            Action.speceffect = SPECEFFECT_HIT;
                            Action.messageID = 1;

                            bool isCritical = (dsprand::GetRandomNumber(100) < battleutils::GetCritHitRate(m_PPet, m_PBattleTarget, false));
                            float DamageRatio = battleutils::GetDamageRatio(m_PPet, m_PBattleTarget, isCritical, 0);

                            if (isCritical)
                            {

                                Action.speceffect = SPECEFFECT_CRITICAL_HIT;
                                Action.messageID = 67;
                            }
                            int16 naturalh2hDMG = 0;
                            if (m_PPet->m_Weapons[SLOT_MAIN]->getSkillType() == SKILL_H2H)
                            {
                                naturalh2hDMG = (float)(m_PPet->getMod(MOD_HTH) * 0.11f) + 3;
                            }							
						    if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_TRUST_SNEAK_ATTACK))
			                {					
                                damage = (int32)((m_PPet->GetMainWeaponDmg() + m_PPet->DEX() + battleutils::GetFSTR(m_PPet, m_PBattleTarget, SLOT_MAIN)) * DamageRatio);
                            }
						    else if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_TRUST_TRICK_ATTACK))
			                {					
                                damage = (int32)((m_PPet->GetMainWeaponDmg() + m_PPet->AGI() + battleutils::GetFSTR(m_PPet, m_PBattleTarget, SLOT_MAIN)) * DamageRatio);
                            }							
							else
							{
							    damage = (int32)((m_PPet->GetMainWeaponDmg() + + naturalh2hDMG + battleutils::GetFSTR(m_PPet, m_PBattleTarget, SLOT_MAIN)) * DamageRatio);
						    }
							if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_TRUST_SNEAK_ATTACK))
			                {
					            //ShowWarning(CL_GREEN"HIT OCCURED REMOVING SA in AI PET DUMMY \n" CL_RESET);
						        m_PPet->StatusEffectContainer->DelStatusEffect(EFFECT_TRUST_SNEAK_ATTACK);
					        }
							if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_TRUST_TRICK_ATTACK))
			                {
					            ShowWarning(CL_GREEN"HIT OCCURED REMOVING TRICK ATTACK FROM LION \n" CL_RESET);
						        m_PPet->StatusEffectContainer->DelStatusEffect(EFFECT_TRUST_TRICK_ATTACK);
					        }							
			
                        }
                    }
                    else {
                        // create enmity even on misses
                        if (m_PBattleTarget->objtype == TYPE_MOB) {
                            CMobEntity* PMob = (CMobEntity*)m_PBattleTarget;
                            PMob->PEnmityContainer->UpdateEnmity(m_PPet, 0, 0);
                        }
                    }
                    if (m_PBattleTarget->objtype == TYPE_PC)
                    {
                        charutils::TrySkillUP((CCharEntity*)m_PBattleTarget, SKILL_EVA, m_PPet->GetMLevel());
                    }

                    bool isBlocked = (dsprand::GetRandomNumber(100) < battleutils::GetBlockRate(m_PPet, m_PBattleTarget));
                    if (isBlocked) { Action.reaction = REACTION_BLOCK; }


                    Action.param = battleutils::TakePhysicalDamage(m_PPet, m_PBattleTarget, damage, isBlocked, SLOT_MAIN, 1, nullptr, true, true);
                    if (Action.param < 0)
                    {
                        Action.param = -(Action.param);
                        Action.messageID = 373;
                    }

                    // spike effect
                    if (Action.reaction != REACTION_EVADE && Action.reaction != REACTION_PARRY)
                    {

                        battleutils::HandleEnspell(m_PPet, m_PBattleTarget, &Action, i, m_PPet->m_Weapons[SLOT_MAIN], damage);
                        battleutils::HandleSpikesDamage(m_PPet, m_PBattleTarget, &Action, damage);
                    }

                    m_PPet->m_ActionList.push_back(Action);
                }

                m_PPet->loc.zone->PushPacket(m_PPet, CHAR_INRANGE, new CActionPacket(m_PPet));

                if (m_PPet->PMaster != nullptr && m_PPet->PMaster->objtype == TYPE_PC && m_PPet->PMaster->PPet != nullptr) {
                    ((CCharEntity*)m_PPet->PMaster)->pushPacket(new CPetSyncPacket((CCharEntity*)m_PPet->PMaster));
                }
            }
            m_LastActionTime = m_Tick;

            // Update the targets attacker level..
            CMobEntity* Monster = (CMobEntity*)m_PBattleTarget;
            if (Monster->m_HiPCLvl < ((CCharEntity*)m_PPet->PMaster)->GetMLevel())
                Monster->m_HiPCLvl = ((CCharEntity*)m_PPet->PMaster)->GetMLevel();
        }
    }
}

void CAIPetDummy::ActionSleep()
{
    if (!m_PPet->StatusEffectContainer->HasPreventActionEffect())
    {
        TransitionBack();
    }
}

void CAIPetDummy::ActionDisengage()
{
    uint8 trustlvl = m_PPet->GetMLevel();
	

    if (m_PPet->PMaster == nullptr || m_PPet->PMaster->isDead()) {
        m_ActionType = ACTION_FALL;
        ActionFall();
        return;
    }
	
	//Add Regen and Refresh to Trusts
	if (m_PPet->getPetType() == PETTYPE_TRUST){
	m_PPet->StatusEffectContainer->AddStatusEffect(new CStatusEffect(EFFECT_HEALING, 0, 0, 5, 0));
	 ((CCharEntity*)m_PPet->PMaster)->pushPacket(new CCharHealthPacket((CCharEntity*)m_PPet->PMaster));
	}
    m_queueSic = false;
    m_PPet->animation = ANIMATION_NONE;
    m_PPet->updatemask |= UPDATE_HP;
    m_LastActionTime = m_Tick;
    m_PBattleTarget = nullptr;
    TransitionBack();
}

/************************************************************************
*																		*
*																		*
*																		*
************************************************************************/

void CAIPetDummy::ActionFall()
{
    bool isMob = m_PPet->objtype == TYPE_MOB;
    // remove master from pet
    if (m_PPet->PMaster != nullptr && m_PPet->PMaster->PPet == m_PPet) {
        petutils::DetachPet(m_PPet->PMaster);
	}
	uint8 counter = 0;
	if (m_PPet->PMaster != nullptr && m_PPet->PMaster->PAlly.size() != 0) {
		for (auto ally : m_PPet->PMaster->PAlly)
		{
			if (ally == m_PPet)
			{
				m_PPet->PMaster->PAlly.erase(m_PPet->PMaster->PAlly.begin() + counter);
				m_PPet->PMaster->PParty->ReloadParty();
				
				break;
			}
			counter++;
		}
	}

    // detach pet just deleted this
    // so break out of here
    if (isMob) {
        return;
    }

    m_PPet->updatemask |= UPDATE_HP;
    m_PPet->UpdateEntity();

    m_LastActionTime = m_Tick;
    m_ActionType = ACTION_DEATH;
}

void CAIPetDummy::ActionDeath()
{
    if (m_PPet->getPetType() == PETTYPE_WYVERN || m_PPet->getPetType() == PETTYPE_AUTOMATON)
	{
	    if (m_Tick - m_LastActionTime > 3000) {
        m_PPet->status = STATUS_DISAPPEAR;
        m_PPet->StatusEffectContainer->DelStatusEffectsByFlag(EFFECTFLAG_DEATH, true);

        m_PPet->loc.zone->PushPacket(m_PPet, CHAR_INRANGE, new CEntityUpdatePacket(m_PPet, ENTITY_DESPAWN, UPDATE_NONE));

        m_ActionType = ACTION_NONE;
        }
	}
    else
    {
	    //if (m_PPet->getZone() == m_PPet->PMaster->getZone()){	
        //ShowWarning(CL_GREEN"Trust in Same Zone, Disappear in 3 seconds \n" CL_RESET);
	    if (m_Tick - m_LastActionTime > 4500) {
            m_PPet->status = STATUS_DISAPPEAR;
            m_PPet->StatusEffectContainer->DelStatusEffectsByFlag(EFFECTFLAG_DEATH, true);

            m_PPet->loc.zone->PushPacket(m_PPet, CHAR_INRANGE, new CEntityUpdatePacket(m_PPet, ENTITY_DESPAWN, UPDATE_NONE));

            m_ActionType = ACTION_NONE;
        }
    }
}

void CAIPetDummy::ActionMagicStart()
{
    // disabled
    //DSP_DEBUG_BREAK_IF(m_PSpell == nullptr);
    DSP_DEBUG_BREAK_IF(m_PBattleSubTarget == nullptr);

    m_LastActionTime = m_Tick;
    m_LastMagicTime = m_Tick;

    STATESTATUS status = m_PMagicState->CastSpell(GetCurrentSpell(), m_PBattleSubTarget);

    if (status == STATESTATUS_START)
    {
        m_ActionType = ACTION_MAGIC_CASTING;
    }
    else
    {
        TransitionBack(true);
    }

}

void CAIPetDummy::ActionMagicCasting()
{
    m_PPathFind->LookAt(m_PMagicState->GetTarget()->loc.p);

    STATESTATUS status = m_PMagicState->Update(m_Tick);

    if (status == STATESTATUS_INTERRUPT)
    {
        m_ActionType = ACTION_MAGIC_INTERRUPT;
        ActionMagicInterrupt();
    }
    else if (status == STATESTATUS_ERROR)
    {
        TransitionBack(true);
    }
    else if (status == STATESTATUS_FINISH)
    {
        m_ActionType = ACTION_MAGIC_FINISH;
        ActionMagicFinish();
    }
}

void CAIPetDummy::ActionMagicFinish()
{
    m_LastActionTime = m_Tick;
    m_LastMagicTime = m_Tick;

    m_PMagicState->FinishSpell();

    m_PSpell = nullptr;
    m_PBattleSubTarget = nullptr;

    TransitionBack();
}

void CAIPetDummy::ActionMagicInterrupt()
{
    m_LastActionTime = m_Tick;
    m_LastMagicTime = m_Tick;

    m_PMagicState->InterruptSpell();

    m_PSpell = nullptr;
    m_PBattleSubTarget = nullptr;

    TransitionBack();
}

/************************************************************************
*																		*
*  При появлении питомца задержка в 4.5 секунды перед началом			*
*  следования за персонажем. Состояние может быть перезаписано.			*
*																		*
************************************************************************/

void CAIPetDummy::ActionSpawn()
{
    if (m_PPet->PMaster == nullptr || m_PPet->PMaster->isDead()) {
        m_ActionType = ACTION_FALL;
        ActionFall();
        return;
    }
	
	
    if (m_Tick > m_LastActionTime + 4000)
    {
        m_ActionType = ACTION_ROAMING;
    }

}

/************************************************************************
*																		*
*  Sends the too far away message and interrupts the pet from			*
*  performing its action. Changes to the interrupt state.				*
*																		*
************************************************************************/

void CAIPetDummy::SendTooFarInterruptMessage(CBattleEntity* PTarg)
{
    m_ActionType = ACTION_MOBABILITY_INTERRUPT;
    //too far away message = 78
    m_PPet->loc.zone->PushPacket(m_PPet, CHAR_INRANGE, new CMessageBasicPacket(PTarg, PTarg, 0, 0, 78));
    ActionAbilityInterrupt();
}

void CAIPetDummy::TransitionBack(bool skipWait)
{

    if (m_PPet->animation == ANIMATION_ATTACK)
    {
        m_ActionType = ACTION_ATTACK;
        if (skipWait)
        {
            ActionAttack();
        }
    }
    else
    {
        m_ActionType = ACTION_ROAMING;
        if (skipWait)
        {
            ActionRoaming();
        }
    }
}

int16 CAIPetDummy::KupipiSpell()
{

	uint8 trigger = 60; // HP Trigger Threshold
	uint8 lowHPP = 31;
	uint8 lowtrigger = 35;	
	uint8 lowtriggercuraga = 25;
	uint8 level = m_PPet->GetMLevel();
    int16 spellID = -1;
    uint32 kupipiPro = charutils::GetVar((CCharEntity*)m_PPet->PMaster,"TrustPro_Kup");
    uint32 kupipiShell = charutils::GetVar((CCharEntity*)m_PPet->PMaster,"TrustShell_Kup");	
	
 CBattleEntity* master = m_PPet->PMaster;  
 CBattleEntity* mostWounded = getWounded(trigger);
 CBattleEntity* mostWoundedLow = getWounded(lowtrigger);
 CBattleEntity* mostWoundedAga = getWounded(lowtriggercuraga);
 if (m_Tick >= m_LastKupipiMagicTime + m_kupipiHealRecast)  // Look for last magic healing spell time 
	{
	    //Prioritize wake up for Sleep
		if (m_PPet->PMaster->StatusEffectContainer->HasStatusEffect(EFFECT_SLEEP) || m_PPet->PMaster->StatusEffectContainer->HasStatusEffect(EFFECT_LULLABY))
		{
		ShowWarning(CL_RED"PLAYER IS ASLEEP WAKE THEM UP!!!\n" CL_RESET);
		m_PBattleSubTarget = m_PPet->PMaster;
		if (level > 15)
			if (m_PPet->health.mp > 59)  // Curaga
			    {
				 spellID = 7;
				}
			else 
			    {
				 spellID = -1;
				}
		else
		        {
				 spellID = -1;
				} 				
        m_LastKupipiMagicTime = m_Tick; // reset mtick no eligible healing spell to cast
		m_kupipiHealRecast = 12000;					
	    }		
	    // Curaga
 		else if (mostWoundedAga != nullptr)
		{
        m_PBattleSubTarget = mostWoundedAga;
		if (level > 50)
			if (m_PPet->health.mp > 179)  // Curaga III
				{
				 spellID = 9;
				}		
			else if (m_PPet->health.mp > 119)  // Curaga II
				{
				 spellID = 8;
				}
			else if (m_PPet->health.mp > 59)  // Curaga
			    {
				 spellID = 7;
				}
			else 
			    {
				 spellID = -1;
				}
		else if (level > 30)
			if (m_PPet->health.mp > 119)  // Curaga II
				{
				 spellID = 8;
				}
			else if (m_PPet->health.mp > 59)  // Curaga
			    {
				 spellID = 7;
				}
			else 
			    {
				 spellID = -1;
				}
		else if (level > 15)
			if (m_PPet->health.mp > 59)  // Curaga
			    {
				 spellID = 7;
				}
			else 
			    {
				 spellID = -1;
				}
		else if (level > 10)
			if (m_PPet->health.mp > 24)  	
			    {
				 spellID = 2;
				}				
			else if (m_PPet->health.mp > 7)  	
			    {
				 spellID = 1;
				}
			else
			    {
				 spellID = -1;
				}
		else if (level > 4)
			if (m_PPet->health.mp > 7)  	
			    {
				 spellID = 1;
				}
			else
			    {
				 spellID = -1;
				} 
		else
		        {
				 spellID = -1;
				} 
        m_LastKupipiMagicTime = m_Tick; // reset mtick no eligible healing spell to cast
		m_kupipiHealRecast = 12000;					
	    }	
 		else if (mostWoundedLow != nullptr)
		{
        m_PBattleSubTarget = mostWounded;
		if (level > 60)
			if (m_PPet->health.mp > 134)
				{
				 spellID = 5;
				}		
			else if (m_PPet->health.mp > 88)
				{
				 spellID = 4;
				}
			else if (m_PPet->health.mp > 46)  	
			    {
				 spellID = 3;
				}
			else if (m_PPet->health.mp > 24)  	
			    {
				 spellID = 2;
				}				
			else if (m_PPet->health.mp > 7)  	
			    {
				 spellID = 1;
				}
			else 
			    {
				 spellID = -1;
				} 	
	    }
		else if (mostWounded != nullptr)
		{
        m_PBattleSubTarget = mostWounded;
		if (level > 40)
			if (m_PPet->health.mp > 88)
				{
				 spellID = 4;
				}
			else if (m_PPet->health.mp > 46)  	
			    {
				 spellID = 3;
				}
			else if (m_PPet->health.mp > 24)  	
			    {
				 spellID = 2;
				}				
			else if (m_PPet->health.mp > 7)  	
			    {
				 spellID = 1;
				}
			else 
			    {
				 spellID = -1;
				} 
		else if (level > 20)
			if (m_PPet->health.mp > 46)  	
			    {
				 spellID = 3;
				}
			else if (m_PPet->health.mp > 24)  	
			    {
				 spellID = 2;
				}				
			else if (m_PPet->health.mp > 7)  	
			    {
				 spellID = 1;
				}
			else
			    {
				 spellID = -1;
				}
		else if (level > 10)
			if (m_PPet->health.mp > 24)  	
			    {
				 spellID = 2;
				}				
			else if (m_PPet->health.mp > 7)  	
			    {
				 spellID = 1;
				}
			else
			    {
				 spellID = -1;
				}
		else if (level > 4)
			if (m_PPet->health.mp > 7)  	
			    {
				 spellID = 1;
				}
			else
			    {
				 spellID = -1;
				} 
		else
		        {
				 spellID = -1;
				} 
		m_LastKupipiMagicTime = m_Tick;	
        m_kupipiHealRecast = 12000; 		
		if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		{
	    spellID = -1;
		} 
        m_kupipiHealRecast = 12000; 
		m_kupipiHealCast = 1; // 1 means casting a spell
		}
		else
		{
		m_LastKupipiMagicTime = m_Tick; // reset mtick no eligible healing spell to cast
		m_kupipiHealRecast = 8000;		
       }
	}
	
    if (m_Tick >= m_LastKupipiEnhanceTime + m_kupipiEnhanceRecast)  // Look for last magic enhancing/na spell time.  ~na will take precidence over enhancing buffs Poisina, blindna, paralyna, erase
	{
	    if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		{
	    spellID = -1;
		} 	
		else if (m_PPet->PMaster->StatusEffectContainer->HasStatusEffect(EFFECT_POISON) == true) 
		{	
		m_PBattleSubTarget = m_PPet->PMaster;
		if (level >= 5)
		    if (m_PPet->health.mp >= 8)
			    {
				 spellID = 14;
				}
		    else
			    {
				 spellID = -1;
				}
			m_LastKupipiEnhanceTime = m_Tick;	
		    m_kupipiEnhanceRecast = 10000;
		}
	    else if (m_PPet->PMaster->StatusEffectContainer->HasStatusEffect(EFFECT_BLINDNESS) == true) 
		{	
		m_PBattleSubTarget = m_PPet->PMaster;
		if (level >= 14)
		    if (m_PPet->health.mp >= 16)
			    {
				 spellID = 16;
				}
		    else
			    {
				 spellID = -1;
				}
			m_LastKupipiEnhanceTime = m_Tick;	
		    m_kupipiEnhanceRecast = 10000;
		}
	    else if (m_PPet->PMaster->StatusEffectContainer->HasStatusEffect(EFFECT_PARALYSIS) == true) 
		{	
		m_PBattleSubTarget = m_PPet->PMaster;
		if (level >= 9)
		    if (m_PPet->health.mp >= 12)
			    {
				 spellID = 15;
				}
		    else
			    {
				 spellID = -1;
				}
			m_LastKupipiEnhanceTime = m_Tick;	
		    m_kupipiEnhanceRecast = 10000;
		}	
	    else if (m_PPet->PMaster->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true) 
		{	
		m_PBattleSubTarget = m_PPet->PMaster;
		if (level >= 19)
		    if (m_PPet->health.mp >= 24)
			    {
				 spellID = 17;
				}
		    else
			    {
				 spellID = -1;
				}
			m_LastKupipiEnhanceTime = m_Tick;	
		    m_kupipiEnhanceRecast = 10000;
		}		
	    else if (m_PPet->PMaster->StatusEffectContainer->HasStatusEffect(EFFECT_PETRIFICATION) == true) 
		{	
		m_PBattleSubTarget = m_PPet->PMaster;
		if (level >= 39)
		    if (m_PPet->health.mp >= 40)
			    {
				 spellID = 18;
				}
		    else
			    {
				 spellID = -1;
				}
			m_LastKupipiEnhanceTime = m_Tick;	
		    m_kupipiEnhanceRecast = 10000;
		}
	    else if (m_PPet->PMaster->StatusEffectContainer->HasStatusEffect(EFFECT_DISEASE) == true) 
		{	
		m_PBattleSubTarget = m_PPet->PMaster;
		if (level >= 34)
		    if (m_PPet->health.mp >= 34)
			    {
				 spellID = 19;
				}
		    else
			    {
				 spellID = -1;
				}
			m_LastKupipiEnhanceTime = m_Tick;	
		    m_kupipiEnhanceRecast = 10000;
		}		
	    else if (m_PPet->PMaster->StatusEffectContainer->HasStatusEffect(EFFECT_CURSE) == true) 
		{	
		m_PBattleSubTarget = m_PPet->PMaster;
		if (level >= 29)
		    if (m_PPet->health.mp >= 30)
			    {
				 spellID = 20;
				}
		    else
			    {
				 spellID = -1;
				}
			m_LastKupipiEnhanceTime = m_Tick;	
		    m_kupipiEnhanceRecast = 10000;
		}
	    else if (m_PPet->PMaster->StatusEffectContainer->HasStatusEffect(EFFECT_DIA) == true) 
		{	
		m_PBattleSubTarget = m_PPet->PMaster;
		if (level >= 32)
		    if (m_PPet->health.mp >= 18)
			    {
				 spellID = 143;
				}
		    else
			    {
				 spellID = -1;
				}
			m_LastKupipiEnhanceTime = m_Tick;	
		    m_kupipiEnhanceRecast = 10000;
		}
	    else if (m_PPet->PMaster->StatusEffectContainer->HasStatusEffect(EFFECT_BIO) == true) 
		{	
		m_PBattleSubTarget = m_PPet->PMaster;
		if (level >= 32)
		    if (m_PPet->health.mp >= 18)
			    {
				 spellID = 143;
				}
		    else
			    {
				 spellID = -1;
				}
			m_LastKupipiEnhanceTime = m_Tick;	
		    m_kupipiEnhanceRecast = 10000;
		}
	    else if (m_PPet->PMaster->StatusEffectContainer->HasStatusEffect(EFFECT_WEIGHT) == true) 
		{	
		m_PBattleSubTarget = m_PPet->PMaster;
		if (level >= 32)
		    if (m_PPet->health.mp >= 18)
			    {
				 spellID = 143;
				}
		    else
			    {
				 spellID = -1;
				}
			m_LastKupipiEnhanceTime = m_Tick;	
		    m_kupipiEnhanceRecast = 10000;
		}
		else if (m_PPet->PMaster->StatusEffectContainer->HasStatusEffect(EFFECT_PROTECT) == false) 
			{
			m_PBattleSubTarget = m_PPet->PMaster; //Target master to hit all members
			if (kupipiPro == 1) // Cast Pro 5 if user has Trust Tribute for it
			    if (m_PPet->health.mp > 83)
				    {
					 spellID = 129;
					}
                else if (m_PPet->health.mp > 64)
					{
					 spellID = 128;
					}
				else if (m_PPet->health.mp > 45)
					{
					 spellID = 127;
					}
				else if (m_PPet->health.mp > 27)
					{
					 spellID = 126;
					}
				else if (m_PPet->health.mp > 8)
					{
					 spellID = 125;
					}
				else 
			        {
				     spellID = -1;
				    } 	    					
			else if (level >= 63)
				if (m_PPet->health.mp > 64)
					{
					 spellID = 128;
					}
				else if (m_PPet->health.mp > 45)
					{
					 spellID = 127;
					}
				else if (m_PPet->health.mp > 27)
					{
					 spellID = 126;
					}
				else if (m_PPet->health.mp > 8)
					{
					 spellID = 125;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else if (level > 47)
				if (m_PPet->health.mp > 45)
					{
					 spellID = 127;
					}
				else if (m_PPet->health.mp > 27)
					{
					 spellID = 126;
					}
				else if (m_PPet->health.mp > 8)
					{
					 spellID = 125;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else if (level > 27)
				if (m_PPet->health.mp > 27)
					{
					 spellID = 126;
					}
				else if (m_PPet->health.mp > 8)
					{
					 spellID = 125;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else if (level > 6)
				if (m_PPet->health.mp > 8)
					{
					 spellID = 125;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else
		        {
				 spellID = -1;
				} 
			m_LastKupipiEnhanceTime = m_Tick;	
			m_kupipiEnhanceRecast = 10000;
			}
		else if (m_PPet->PMaster->StatusEffectContainer->HasStatusEffect(EFFECT_SHELL) == false) 
			{
			m_PBattleSubTarget = m_PPet->PMaster;
			if (kupipiShell == 1)  // Check if user has Shellra V Tribute
				if (m_PPet->health.mp > 92)
					{
					 spellID = 134;
					}			
				else if (m_PPet->health.mp > 74)
					{
					 spellID = 133;
					}
				else if (m_PPet->health.mp > 55)
					{
					 spellID = 132;
					}
				else if (m_PPet->health.mp > 36)
					{
					 spellID = 131;
					}
				else if (m_PPet->health.mp > 17)
					{
					 spellID = 130;
					}
				else 
			        {
				     spellID = -1;
				    } 			
			else if (level >= 68)
				if (m_PPet->health.mp > 74)
					{
					 spellID = 133;
					}
				else if (m_PPet->health.mp > 55)
					{
					 spellID = 132;
					}
				else if (m_PPet->health.mp > 36)
					{
					 spellID = 131;
					}
				else if (m_PPet->health.mp > 17)
					{
					 spellID = 130;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else if (level >= 57)
				if (m_PPet->health.mp > 55)
					{
					 spellID = 132;
					}
				else if (m_PPet->health.mp > 36)
					{
					 spellID = 131;
					}
				else if (m_PPet->health.mp > 17)
					{
					 spellID = 130;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else if (level > 37)
				if (m_PPet->health.mp > 36)
					{
					 spellID = 131;
					}
				else if (m_PPet->health.mp > 17)
					{
					 spellID = 130;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else if (level > 17)
				if (m_PPet->health.mp > 17)
					{
					 spellID = 130;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else
		        {
				 spellID = -1;
				} 			
			m_LastKupipiEnhanceTime = m_Tick;	
			m_kupipiEnhanceRecast = 10000;
			}

			
	}	
    return spellID;
}	
	

	
	





int16 CAIPetDummy::CurillaSpell()
{

	uint8 trigger = 45; // HP Trigger Threshold
	uint8 lowHPP = 31;
	uint8 level = m_PPet->GetMLevel();
    int16 spellID = -1;
	
 CBattleEntity* master = m_PPet->PMaster;  
 CBattleEntity* mostWounded = getWounded(trigger);
 CBattleEntity* sleptMage = getSleptMage();
if (m_Tick >= m_LastMagicTimeHeal + m_magicHealRecast)  // Look for last magic healing spell time 
	{
	    // Cure White Mage Trust if slept
		if (sleptMage != nullptr && (sleptMage->StatusEffectContainer->HasStatusEffect(EFFECT_SLEEP) == true || sleptMage->StatusEffectContainer->HasStatusEffect(EFFECT_LULLABY) == true))
		{
		ShowWarning(CL_RED"KUPIPI IS SLEPT!! WAKE HER UP\n" CL_RESET);
		m_PBattleSubTarget = sleptMage;
            if (level > 4)
			    if (m_PPet->health.mp > 7)  	
			    {
				 spellID = 1;
				}
			    else
			    {
				 spellID = -1;
				} 
		}
		else if (mostWounded != nullptr)
		{
        m_PBattleSubTarget = mostWounded;
		if (level > 54)
			if (m_PPet->health.mp > 88)
				{
				 spellID = 4;
				}
			else if (m_PPet->health.mp > 46)  	
			    {
				 spellID = 3;
				}
			else if (m_PPet->health.mp > 24)  	
			    {
				 spellID = 2;
				}				
			else if (m_PPet->health.mp > 7)  	
			    {
				 spellID = 1;
				}
			else 
			    {
				 spellID = -1;
				} 
		else if (level > 29)
			if (m_PPet->health.mp > 46)  	
			    {
				 spellID = 3;
				}
			else if (m_PPet->health.mp > 24)  	
			    {
				 spellID = 2;
				}				
			else if (m_PPet->health.mp > 7)  	
			    {
				 spellID = 1;
				}
			else
			    {
				 spellID = -1;
				}
		else if (level > 16)
			if (m_PPet->health.mp > 24)  	
			    {
				 spellID = 2;
				}				
			else if (m_PPet->health.mp > 7)  	
			    {
				 spellID = 1;
				}
			else
			    {
				 spellID = -1;
				}
		else if (level > 4)
			if (m_PPet->health.mp > 7)  	
			    {
				 spellID = 1;
				}
			else
			    {
				 spellID = -1;
				} 
		else
		        {
				 spellID = -1;
				} 
		if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		{
	    spellID = -1;
		} 
		
        m_magicHealRecast = 25000; 
		m_magicHealCast = 1; // 1 means casting a spell
		}
		else
		{
		m_LastMagicTimeHeal = m_Tick; // reset mtick no eligible healing spell to cast
		m_magicHealRecast = 14000;		
       }
	} 
	else if (m_Tick >= m_LastCurillaFlash + m_curillaFlashRecast)  // Look for last flash spell time 
	{
	    m_PBattleSubTarget = m_PBattleTarget;
        if (level >= 37)
		    if (m_PPet->health.mp > 25)  	
			    {
				 spellID = 112;
				}
			else
			    {
				 spellID = -1;
				}	
		m_curillaFlashRecast = 50000;
        m_LastCurillaFlash = m_Tick;
    }
	else if (m_Tick >= m_LastCurillaReprisalTime + m_curillaReprisalRecast)  // Look for last time Reprisal was used
	{
	    m_PBattleSubTarget = m_PPet;
        if (level >= 61)
		    if (m_PPet->health.mp > 23)  	
			    {
				 spellID = 97;
				}
			else
			    {
				 spellID = -1;
				}	
		m_curillaReprisalRecast = 180000;
        m_LastCurillaReprisalTime = m_Tick;
    }		
	
	return spellID;
 
 

}


int16 CAIPetDummy::BlueSpell()
{
    uint8 trustlvl = m_PPet->GetMLevel();
	uint8 trigger = 35; // HP Trigger Threshold
	uint8 lowHPP = 31;
	uint8 level = m_PPet->GetMLevel();
    int16 spellID = -1;
	uint16 randtimer = dsprand::GetRandomNumber(1, 10);
	randtimer = randtimer * 100;
	
	
 CBattleEntity* master = m_PPet->PMaster;  
 CBattleEntity* mostWounded = getWounded(trigger);
if (m_Tick >= m_LastBlueMagicHealCast + m_blueMagicHealRecast)  // Look for last time blue magic was used
	{
		if (mostWounded != nullptr)
		{
        m_PBattleSubTarget = mostWounded;
		if (level > 57)
			if (m_PPet->health.mp > 71)
				{
				 spellID = 593; //Magic Fruit
				}
			else if (m_PPet->health.mp > 36)  	
			    {
				 spellID = 578;  // Wild Carrot
				}
			else 
			    {
				 spellID = -1;
				} 
		else if (level > 29)
			if (m_PPet->health.mp > 36)  	
			    {
				 spellID = 578;
				}
			else
			    {
				 spellID = -1;
				}
		if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		{
	    spellID = -1;
		} 
        m_blueMagicHealRecast = 8000; 
		}
		else
		{
		m_LastBlueMagicHealCast = m_Tick; // reset mtick no eligible healing spell to cast
		m_blueMagicHealRecast = 8000;		
       }
	} 
	//TODO Check for Chain Affinity here
	else if (m_Tick >= m_LastBlueMagicCast + m_blueMagicRecast && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_CHAIN_AFFINITY) == true && m_chainAffinityStatus == 1)  //Chain Affinity Spell Closer
	{
	    m_PBattleSubTarget = m_PBattleTarget;
		uint8 blurandom = dsprand::GetRandomNumber(1, 40); //Randomizes Blu Spells for skillchain setup later?
	    if (level >= 72)
			if (m_PPet->health.mp > 73)  	
			    {
				 spellID = 611;  //Savage Blade -> Disseverment
				}
		else if (level >= 60)
            if (m_PPet->health.mp > 60)  	
			    {
				 spellID = 560;  //RLB -> Death Scissors
				}
		else if (level >= 60)
            if (m_PPet->health.mp > 40)  	
			    {
				 spellID = 545;  //RLB -> Sickle Slash
				}
		else if (level >= 40)
            if (m_PPet->health.mp > 46)  	
			    {
				 spellID = 569;  //RLB -> Jet Stream
				}	
        m_blueMagicRecast = 20000 + randtimer;
		m_chainAffinityStatus = 0;
        m_LastBlueMagicCast = m_Tick;
        }		
	else if (m_Tick >= m_LastBlueMagicCast + m_blueMagicRecast && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_CHAIN_AFFINITY) == false && 
	m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_HASTE) == false && m_PBattleTarget->GetHPP() > 80 && trustlvl >= 48)  // See if haste should be cast
	{
	    m_PBattleSubTarget = m_PPet;
	    if (m_PPet->health.mp > 28)  	
			    {
				 spellID = 530;
				}
	    else  	
			    {
				 spellID = -1;
				}
        m_blueMagicRecast = 20000 + randtimer;
        m_LastBlueMagicCast = m_Tick;
        }		
	
	else if (m_Tick >= m_LastBlueMagicCast + m_blueMagicRecast && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_CHAIN_AFFINITY) == false && m_PBattleTarget->GetHPP() < 93)  // Look for last time offensive blue magic was cast
	{
	    m_PBattleSubTarget = m_PBattleTarget;
		uint8 blurandom = dsprand::GetRandomNumber(1, 40); //Randomizes Blu Spells
		//printf("Setting Blue Random Number to %d \n", blurandom);
        if (level >= 72){
			if (blurandom >= 30) //Disseverment
				if (m_PPet->health.mp > 73)  	
			    {
				 spellID = 611;
				}
				else if (m_PPet->health.mp > 60)  	
			    {
				 spellID = 641;
				}
				else if (m_PPet->health.mp > 50)  	
			    {
				 spellID = 554;
				}
				else  	
			    {
				 spellID = -1;
				}
			else if (blurandom >= 20 && blurandom < 30)//Hysteric Barrage
				if (m_PPet->health.mp > 60)  	
			    {
				 spellID = 641;
				}
				else if (m_PPet->health.mp > 50)  	
			    {
				 spellID = 554;
				}
				else  	
			    {
				 spellID = -1;
				}
			else if (blurandom >= 10 && blurandom < 20)//Frenetic Rip
				if (m_PPet->health.mp > 60)  	
			    {
				 spellID = 560;
				}
				else if (m_PPet->health.mp > 50)  	
			    {
				 spellID = 554;
				}
				else  	
			    {
				 spellID = -1;
				}
			else if (blurandom >= 0 && blurandom < 10)//Death Scissors
                if (m_PPet->health.mp > 50)  	
			    {
				 spellID = 554;
				}
				else  	
			    {
				 spellID = -1;
				}
            }				
        else if (level >= 69){
		//printf("BLU LVL >= 69");
			if (blurandom >= 30)
				if (m_PPet->health.mp > 60)  	
			    {
				 spellID = 641;  //HB
				}
				else if (m_PPet->health.mp > 60)  	
			    {
				 spellID = 560;  //FR
				}
				else if (m_PPet->health.mp > 50)  	
			    {
				 spellID = 554; //DS
				}
				else if (m_PPet->health.mp > 40)  	
			    {
				 spellID = 545; //SS
				}				
				else  	
			    {
				 spellID = -1;
				}
			else if (blurandom >= 20 && blurandom < 30)//Frenetic Rip
				if (m_PPet->health.mp > 60)  	
			    {
				 spellID = 560;  //FR
				}
				else if (m_PPet->health.mp > 50)  	
			    {
				 spellID = 554; //DS
				}
				else if (m_PPet->health.mp > 40)  	
			    {
				 spellID = 545; //SS
				}				
				else  	
			    {
				 spellID = -1;
				}
			else if (blurandom >= 10 && blurandom < 20)//Death Scissors
                if (m_PPet->health.mp > 50)  	
			    {
				 spellID = 554; //DS
				}
				else if (m_PPet->health.mp > 40)  	
			    {
				 spellID = 545; //SS
				}				
				else  	
			    {
				 spellID = -1;
				}
			else if (blurandom < 10)//Sickle Slash
                if (m_PPet->health.mp > 40)  	
			    {
				 spellID = 545; //SS
				}				
				else  	
			    {
				 spellID = -1;
				}
            }				
		else if (level >= 63){
		//printf("BLU LVL >= 63");
		    if (blurandom >= 30)
			    if (m_PPet->health.mp > 61)  	
			    {
				 spellID = 560;  //Frentic Rip
				}
				else if (m_PPet->health.mp > 50)  	
			    {
				 spellID = 554;  //Death Scissors
				}
			    else if (m_PPet->health.mp > 46)  	
			    {
				 spellID = 569;  //Jet Stream
				}
			    else if (m_PPet->health.mp > 40)  	
			    {
				 spellID = 545;  //Sickle Slash
				}					
				else  	
			    {
				 spellID = -1;
				}				
		   else if (blurandom >= 20 && blurandom < 30)
			    if (m_PPet->health.mp > 50)  	
			    {
				 spellID = 554;  //Death Scissors
				}
			    else if (m_PPet->health.mp > 46)  	
			    {
				 spellID = 569;  //Jet Stream
				}
			    else if (m_PPet->health.mp > 40)  	
			    {
				 spellID = 545;  //Sickle Slash
				}					
				else  	
			    {
				 spellID = -1;
				}				
		   else if (blurandom >= 10 && blurandom < 20)
			    if (m_PPet->health.mp > 46)  	
			    {
				 spellID = 569;  //Jet Stream
				}
			    else if (m_PPet->health.mp > 40)  	
			    {
				 spellID = 545;  //Sickle Slash
				}					
				else  	
			    {
				 spellID = -1;
				}
		   else if (blurandom < 10)
			    if (m_PPet->health.mp > 40)  	
			    {
				 spellID = 545;  //Sickle Slash
				}					
				else  	
			    {
				 spellID = -1;
				}	
            }				
		else if (level >= 60){
		//printf("BLU LVL >= 60");
		    if (blurandom >= 30)
			    if (m_PPet->health.mp > 50)  	
			    {
				 spellID = 554;  //Death Scissors
				}
			    else if (m_PPet->health.mp > 46)  	
			    {
				 spellID = 569;  //Jet Stream
				}
			    else if (m_PPet->health.mp > 40)  	
			    {
				 spellID = 545;  //Sickle Slash
				}
			    else if (m_PPet->health.mp > 20)  	
			    {
				 spellID = 519;  //Screwdriver
				}					
				else  	
			    {
				 spellID = -1;
				}				
		  else if (blurandom >= 20 && blurandom < 30)
                if (m_PPet->health.mp > 46)  	
			    {
				 spellID = 569;  //Jet Stream
				}
			    else if (m_PPet->health.mp > 40)  	
			    {
				 spellID = 545;  //Sickle Slash
				}
			    else if (m_PPet->health.mp > 20)  	
			    {
				 spellID = 519;  //Screwdriver
				}					
				else  	
			    {
				 spellID = -1;
				}				
		  else if (blurandom >= 10 && blurandom < 20)
                if (m_PPet->health.mp > 40)  	
			    {
				 spellID = 545;  //Sickle Slash
				}
			    else if (m_PPet->health.mp > 20)  	
			    {
				 spellID = 519;  //Screwdriver
				}					
				else  	
			    {
				 spellID = -1;
				}				
		  else if (blurandom < 10)
                if (m_PPet->health.mp > 20)  	
			    {
				 spellID = 519;  //Screwdriver
				}					
				else  	
			    {
				 spellID = -1;
				}	
            }				
		else if (level >= 48){
		//printf("BLU LVL >= 48");
		    if (blurandom >= 30)
			    if (m_PPet->health.mp > 46)  	
			    {
				 spellID = 569;  //Jet Stream
				}
			    else if (m_PPet->health.mp > 40)  	
			    {
				 spellID = 545;  //Sickle Slash
				}
			    else if (m_PPet->health.mp > 20)  	
			    {
				 spellID = 519;  //Screwdriver
				}
			    else if (m_PPet->health.mp > 15)  	
			    {
				 spellID = 529;  //Bludgeon
				}					
				else  	
			    {
				 spellID = -1;
				}					
		 else if (blurandom >= 20 && blurandom < 30)
			    if (m_PPet->health.mp > 40)  	
			    {
				 spellID = 545;  //Sickle Slash
				}
			    else if (m_PPet->health.mp > 20)  	
			    {
				 spellID = 519;  //Screwdriver
				}
			    else if (m_PPet->health.mp > 15)  	
			    {
				 spellID = 529;  //Bludgeon
				}					
				else  	
			    {
				 spellID = -1;
				}				
		   else if (blurandom >= 10 && blurandom < 20)
			    if (m_PPet->health.mp > 20)  	
			    {
				 spellID = 519;  //Screwdriver
				}
			    else if (m_PPet->health.mp > 15)  	
			    {
				 spellID = 529;  //Bludgeon
				}					
				else  	
			    {
				 spellID = -1;
				}	
		   else if (blurandom < 10)
                if (m_PPet->health.mp > 15)  	
			    {
				 spellID = 529;  //Bludgeon
				}					
				else  	
			    {
				 spellID = -1;
				}				
			}	
		else if (level >= 38){
		//printf("BLU LVL >= 38");
		    if (blurandom >= 30)
			    if (m_PPet->health.mp > 46)  	
			    {
				 spellID = 569;  //Jet Stream
				}
			    else if (m_PPet->health.mp > 20)  	
			    {
				 spellID = 519;  //Screwdriver
				}
			    else if (m_PPet->health.mp > 15)  	
			    {
				 spellID = 529;  //Bludgeon
				}
			    else if (m_PPet->health.mp > 11)  	
			    {
				 spellID = 623;  //Head Butt
				}					
				else  	
			    {
				 spellID = -1;
				}				
		   else if (blurandom >= 20 && blurandom < 30)
			    if (m_PPet->health.mp > 20)  	
			    {
				 spellID = 519;  //Screwdriver
				}
			    else if (m_PPet->health.mp > 15)  	
			    {
				 spellID = 529;  //Bludgeon
				}
			    else if (m_PPet->health.mp > 11)  	
			    {
				 spellID = 623;  //Head Butt
				}					
				else  	
			    {
				 spellID = -1;
				}
           else if (blurandom >= 10 && blurandom < 20)
			    if (m_PPet->health.mp > 15)  	
			    {
				 spellID = 529;  //Bludgeon
				}
			    else if (m_PPet->health.mp > 11)  	
			    {
				 spellID = 623;  //Head Butt
				}					
				else  	
			    {
				 spellID = -1;
				}				
           else if (blurandom < 10)
			    if (m_PPet->health.mp > 11)  	
			    {
				 spellID = 623;  //Head Butt
				}					
				else  	
			    {
				 spellID = -1;
				}
            }				
		else if (level >= 26){
		//printf("BLU LVL >= 60");
		    if (blurandom >= 30)
			    if (m_PPet->health.mp > 20)  	
			    {
				 spellID = 519;  //Screwdriver
				}
			    else if (m_PPet->health.mp > 15)  	
			    {
				 spellID = 529;  //Bludgeon
				}
			    else if (m_PPet->health.mp > 11)  	
			    {
				 spellID = 623;  //Head Butt
				}			
				else if (m_PPet->health.mp > 4)  	
			    {
				 spellID = 551;  //Power Attack
				}			
				else  	
			    {
				 spellID = -1;
				}
		   else if (blurandom >= 20 && blurandom < 30)
                if (m_PPet->health.mp > 15)  	
			    {
				 spellID = 529;  //Bludgeon
				}
			    else if (m_PPet->health.mp > 11)  	
			    {
				 spellID = 623;  //Head Butt
				}			
				else if (m_PPet->health.mp > 4)  	
			    {
				 spellID = 551;  //Power Attack
				}			
				else  	
			    {
				 spellID = -1;
				}
		   else if (blurandom >= 10 && blurandom < 20)
                if (m_PPet->health.mp > 11)  	
			    {
				 spellID = 623;  //Head Butt
				}			
				else if (m_PPet->health.mp > 4)  	
			    {
				 spellID = 551;  //Power Attack
				}			
				else  	
			    {
				 spellID = -1;
				}
		   else if (blurandom < 10)
                if (m_PPet->health.mp > 4)  	
			    {
				 spellID = 551;  //Power Attack
				}			
				else  	
			    {
				 spellID = -1;
				}
			}	
		else if (level >= 18){
		//printf("BLU LVL >= 18");
		    if (blurandom >= 25)
			    if (m_PPet->health.mp > 15)  	
			    {
				 spellID = 529;  //Bludgeon
				}
			    else if (m_PPet->health.mp > 11)  	
			    {
				 spellID = 623;  //Head Butt
				}			
				else if (m_PPet->health.mp > 4)  	
			    {
				 spellID = 551;  //Power Attack
				}			
				else  	
			    {
				 spellID = -1;
				}	
          else if (blurandom < 25 && blurandom >=10)
                if (m_PPet->health.mp > 11)  	
			    {
				 spellID = 623;  //Head Butt
				}			
				else if (m_PPet->health.mp > 4)  	
			    {
				 spellID = 551;  //Power Attack
				}			
				else  	
			    {
				 spellID = -1;
				}
           else if (blurandom < 10)
                if (m_PPet->health.mp > 4)  	
			    {
				 spellID = 551;  //Power Attack
				}			
				else  	
			    {
				 spellID = -1;
				}
            }				
		else if (level >= 12){
		//printf("BLU LVL >= 12");
		    if (blurandom >= 20)
			    if (m_PPet->health.mp > 11)  	
			    {
				 spellID = 623;  //Head Butt
				}			
				else if (m_PPet->health.mp > 4)  	
			    {
				 spellID = 551;  //Power Attack
				}
				else  	
			    {
				 spellID = -1;
				}	
		   else if (blurandom < 20)
                if (m_PPet->health.mp > 4)  	
			    {
				 spellID = 551;  //Power Attack
				}			
				else  	
			    {
				 spellID = -1;
				}					
		else if (level >= 5)
		//printf("BLU LVL >= 5");
				if (m_PPet->health.mp > 4)  	
			    {
				 spellID = 551;  //Power Attack
				}			
				else  	
			    {
				 spellID = -1;
				}
		}		
				
        m_blueMagicRecast = 20000 + randtimer;
        m_LastBlueMagicCast = m_Tick;
    }	
	return spellID;
}


int16 CAIPetDummy::AdelhiedSpell()
{
	uint8 level = m_PPet->GetMLevel();
	uint8 moblvl = m_PBattleTarget->GetMLevel();
	uint8 lvldif = moblvl - level;
    uint32 adelhiedMB = charutils::GetVar((CCharEntity*)m_PPet->PMaster,"TrustMB");
    int16 spellID = -1;
	uint8 nukeHPP = 75;
	uint8 trigger = 50;
	CBattleEntity* mostWounded = getWounded(trigger);
    //printf("Variable Obtained: %d \n", adelhiedMB);
	m_PBattleSubTarget = m_PBattleTarget;
	if (adelhiedMB < 9){
		if (level >= 10 && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_TRUST_DARK_ARTS) == false){
	        m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3719) { //Dark Arts
						    mobjaID = 196;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;  //Target Self
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				//printf("Using Dark Arts");
				//return;	
	}
	if (level >= 55 && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_EBULLIENCE) == false){
	        m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3722) { //Ebullience
						    mobjaID = 205;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;  //Target Self
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
			    //printf("Using Ebullience");
				//return;	
	}
if (adelhiedMB == 8){
    //Dark Arts then Ebullience if possible
    m_PBattleSubTarget = m_PBattleTarget;	
		if (level >= 32)
			if (m_PPet->health.mp > 25)
				{
				 spellID = 284;
				}
            else
				{
				spellID = -1;
				}	
		else
                {
                 spellID = -1;
                }			 
		m_schEleRecast = 20000;
		m_LastSchCheck = m_Tick;
		//Resets Magic Burst Value to 10
		int32 value = 10;
        std::string varname;
	    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'TrustMB', value = '10' ON DUPLICATE KEY UPDATE value = '10';";
        Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);
		//m_burstElement = 0;
		}
else if (adelhiedMB == 7){
    //Dark Arts then Ebullience if possible
    m_PBattleSubTarget = m_PBattleTarget;	
		if (level >= 32)
			if (m_PPet->health.mp > 25)
				{
				 spellID = 285;
				}
            else
				{
				spellID = -1;
				}	
		else
                {
                 spellID = -1;
                }			 
		m_schEleRecast = 20000;
		m_LastSchCheck = m_Tick;
		//Resets Magic Burst Value to 10
		int32 value = 10;
        std::string varname;
	    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'TrustMB', value = '10' ON DUPLICATE KEY UPDATE value = '10';";
        Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);
		//m_burstElement = 0;
		}		
	else if (adelhiedMB == 6){
    //Dark Arts then Ebullience if possible
    m_PBattleSubTarget = m_PBattleTarget;	
		if (level >= 75)
			if (m_PPet->health.mp > 195)
				{
				 spellID = 167;
				}
			else if (m_PPet->health.mp > 90)	
                {
				 spellID = 166;
			    }
			else if (m_PPet->health.mp > 36)	
                {
				 spellID = 165;
			    }
			else if (m_PPet->health.mp > 8)	
                {
				 spellID = 164;
			    }
            else
				{
				spellID = -1;
				}	
		else if (level >= 69)
			if (m_PPet->health.mp > 90)	
                {
				 spellID = 166;
			    }
			else if (m_PPet->health.mp > 36)	
                {
				 spellID = 165;
			    }
			else if (m_PPet->health.mp > 8)	
                {
				 spellID = 164;
			    }
            else
				{
				 spellID = -1;
				}
		else if (level >= 51)
			if (m_PPet->health.mp > 36)	
                {
				 spellID = 165;
			    }
			else if (m_PPet->health.mp > 8)	
                {
				 spellID = 164;
			    }
            else
				{
				 spellID = -1;
				}
		else if (level >= 24)
			if (m_PPet->health.mp > 8)	
                {
				 spellID = 164;
			    }
            else
				{
				 spellID = -1;
				}
		else
                {
                 spellID = -1;
                }			 

		m_schEleRecast = 20000;
		m_LastSchCheck = m_Tick;
		//Resets Magic Burst Value to 10
		int32 value = 10;
        std::string varname;
	    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'TrustMB', value = '10' ON DUPLICATE KEY UPDATE value = '10';";
        Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);
		//m_burstElement = 0;
		}
       else if (adelhiedMB == 5){
    m_PBattleSubTarget = m_PBattleTarget;	   
		      if (level >= 74)
			if (m_PPet->health.mp > 161)
				{
				 spellID = 152;
				}
			else if (m_PPet->health.mp > 74)	
                {
				 spellID = 151;
			    }
			else if (m_PPet->health.mp > 30)	
                {
				 spellID = 150;
			    }
			else if (m_PPet->health.mp > 7)	
                {
				 spellID = 149;
			    }
            else
				{
				 spellID = -1;
				}
		else if (level >= 66)
			if (m_PPet->health.mp > 74)	
                {
				 spellID = 151;
			    }
			else if (m_PPet->health.mp > 30)	
                {
				 spellID = 150;
			    }
			else if (m_PPet->health.mp > 7)	
                {
				 spellID = 149;
			    }
            else
				{
				 spellID = -1;
				}
        else if (level >= 46)
			if (m_PPet->health.mp > 30)	
                {
				 spellID = 150;
			    }
			else if (m_PPet->health.mp > 7)	
                {
				 spellID = 149;
			    }
            else
				{
				 spellID = -1;
				}
        else if (level >= 20)
			if (m_PPet->health.mp > 7)	
                {
				 spellID = 149;
			    }
            else
				{
				 spellID = -1;
				}
        m_schEleRecast = 10000;
		m_LastSchCheck = m_Tick;
		//Resets Magic Burst Value to 10
		int32 value = 10;
        std::string varname;
	    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'TrustMB', value = '10' ON DUPLICATE KEY UPDATE value = '10';";
        Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);
		//m_burstElement = 0;		
        }		
    else if (adelhiedMB == 4){
    m_PBattleSubTarget = m_PBattleTarget;	
		if (level >= 73)
			if (m_PPet->health.mp > 134)
				{
				 spellID = 147;
				}
			else if (m_PPet->health.mp > 62)	
                {
				 spellID = 146;
			    }
			else if (m_PPet->health.mp > 25)	
                {
				 spellID = 145;
			    }
			else if (m_PPet->health.mp > 6)	
                {
				 spellID = 144;
			    }
            else
				{
				 spellID = -1;
				}
		else if (level >= 63)
			if (m_PPet->health.mp > 62)	
                {
				 spellID = 146;
			    }
			else if (m_PPet->health.mp > 25)	
                {
				 spellID = 145;
			    }
			else if (m_PPet->health.mp > 6)	
                {
				 spellID = 144;
			    }
            else
				{
				 spellID = -1;
				}
        else if (level >= 42)
			if (m_PPet->health.mp > 25)	
                {
				 spellID = 145;
			    }
			else if (m_PPet->health.mp > 6)	
                {
				 spellID = 144;
			    }
            else
				{
				 spellID = -1;
				}
        else if (level >= 16)
			if (m_PPet->health.mp > 6)	
                {
				 spellID = 144;
			    }
            else
				{
				 spellID = -1;
				}	    
    m_schEleRecast = 20000;
	m_LastSchCheck = m_Tick;
	//Resets Magic Burst Value to 10
	int32 value = 10;
    std::string varname;
	const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'TrustMB', value = '10' ON DUPLICATE KEY UPDATE value = '10';";
    Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);
	//m_burstElement = 0;	
    }
    else if (adelhiedMB == 3){
    m_PBattleSubTarget = m_PBattleTarget;	
		if (level >= 72)
			if (m_PPet->health.mp > 114)
				{
				 spellID = 157;
				}
			else if (m_PPet->health.mp > 53)	
                {
				 spellID = 156;
			    }
			else if (m_PPet->health.mp > 21)	
                {
				 spellID = 155;
			    }
			else if (m_PPet->health.mp > 5)	
                {
				 spellID = 154;
			    }
            else
				{
				 spellID = -1;
				}
		else if (level >= 60)
			if (m_PPet->health.mp > 53)	
                {
				 spellID = 156;
			    }
			else if (m_PPet->health.mp > 21)	
                {
				 spellID = 155;
			    }
			else if (m_PPet->health.mp > 5)	
                {
				 spellID = 144;
			    }
            else
				{
				 spellID = -1;
				}
        else if (level >= 38)
			if (m_PPet->health.mp > 21)	
                {
				 spellID = 155;
			    }
			else if (m_PPet->health.mp > 5)	
                {
				 spellID = 154;
			    }
            else
				{
				 spellID = -1;
				}
        else if (level >= 12)
			if (m_PPet->health.mp > 5)	
                {
				 spellID = 154;
			    }
            else
				{
				 spellID = -1;
				}	
    m_schEleRecast = 20000;
	m_LastSchCheck = m_Tick;
		//Resets Magic Burst Value to 10
		int32 value = 10;
        std::string varname;
	    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'TrustMB', value = '10' ON DUPLICATE KEY UPDATE value = '10';";
        Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);
		//m_burstElement = 0;	
    }
    else if (adelhiedMB == 2){
    m_PBattleSubTarget = m_PBattleTarget;	
		if (level >= 71)
			if (m_PPet->health.mp > 98)
				{
				 spellID = 172;
				}
			else if (m_PPet->health.mp > 45)	
                {
				 spellID = 171;
			    }
			else if (m_PPet->health.mp > 18)	
                {
				 spellID = 170;
			    }
			else if (m_PPet->health.mp > 4)	
                {
				 spellID = 169;
			    }
            else
				{
				 spellID = -1;
				}
		else if (level >= 57)
			if (m_PPet->health.mp > 45)	
                {
				 spellID = 171;
			    }
			else if (m_PPet->health.mp > 18)	
                {
				 spellID = 170;
			    }
			else if (m_PPet->health.mp > 4)	
                {
				 spellID = 169;
			    }
            else
				{
				 spellID = -1;
				}
        else if (level >= 34)
			if (m_PPet->health.mp > 18)	
                {
				 spellID = 170;
			    }
			else if (m_PPet->health.mp > 4)	
                {
				 spellID = 169;
			    }
            else
				{
				 spellID = -1;
				}
        else if (level >= 8)
			if (m_PPet->health.mp > 4)	
                {
				 spellID = 169;
			    }
            else
				{
				 spellID = -1;
				}	
    m_schEleRecast = 20000;
	m_LastSchCheck = m_Tick;
		//Resets Magic Burst Value to 10
		int32 value = 10;
        std::string varname;
	    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'TrustMB', value = '10' ON DUPLICATE KEY UPDATE value = '10';";
        Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);
		//m_burstElement = 0;	
    }
    else if (adelhiedMB == 1){
    m_PBattleSubTarget = m_PBattleTarget;	
		if (level >= 70)
			if (m_PPet->health.mp > 87)
				{
				 spellID = 162;
				}
			else if (m_PPet->health.mp > 39)	
                {
				 spellID = 161;
			    }
			else if (m_PPet->health.mp > 15)	
                {
				 spellID = 160;
			    }
			else if (m_PPet->health.mp > 3)	
                {
				 spellID = 159;
			    }
            else
				{
				 spellID = -1;
				}
		else if (level >= 54)
			if (m_PPet->health.mp > 39)	
                {
				 spellID = 161;
			    }
			else if (m_PPet->health.mp > 15)	
                {
				 spellID = 160;
			    }
			else if (m_PPet->health.mp > 3)	
                {
				 spellID = 159;
			    }
            else
				{
				 spellID = -1;
				}
        else if (level >= 30)
			if (m_PPet->health.mp > 15)	
                {
				 spellID = 160;
			    }
			else if (m_PPet->health.mp > 3)	
                {
				 spellID = 159;
			    }
            else
				{
				 spellID = -1;
				}
        else if (level >= 4)
			if (m_PPet->health.mp > 3)	
                {
				 spellID = 159;
			    }
            else
				{
				 spellID = -1;
				}
    m_schEleRecast = 20000;
	m_LastSchCheck = m_Tick;
		//Resets Magic Burst Value to 10
		int32 value = 10;
        std::string varname;
	    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'TrustMB', value = '10' ON DUPLICATE KEY UPDATE value = '10';";
        Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);
		//m_burstElement = 0;	
    }
	}
//MB END Check for normal Spells

//Now do Healing -> Enhancing -> Nuking
//Cures
  else if (adelhiedMB == 10){
  //ShowWarning(CL_RED"NO MB FOUND CYCLING THROUGH OTHER SPELLS OPTIONS\n" CL_RESET);
  if (m_Tick >= m_LastAdelhiedHeal + m_adelhiedHealRecast && m_ActionType != ACTION_MAGIC_CASTING)
    {
	 if (mostWounded != nullptr)
	    {
        m_PBattleSubTarget = mostWounded;
		if (level >= 10 && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_TRUST_LIGHT_ARTS) == false){
	        m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3718) { //Light Arts
						    mobjaID = 195;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;  //Target Self
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				//printf("Using Light Arts");
				//return;	
	    }
        m_PBattleSubTarget = mostWounded;		
		if (level > 54)
			if (m_PPet->health.mp > 88)
				{
				 spellID = 4;
				}
			else if (m_PPet->health.mp > 46)  	
			    {
				 spellID = 3;
				}
			else if (m_PPet->health.mp > 24)  	
			    {
				 spellID = 2;
				}				
			else if (m_PPet->health.mp > 7)  	
			    {
				 spellID = 1;
				}
			else 
			    {
				 spellID = -1;
				} 
		else if (level > 29)
			if (m_PPet->health.mp > 46)  	
			    {
				 spellID = 3;
				}
			else if (m_PPet->health.mp > 24)  	
			    {
				 spellID = 2;
				}				
			else if (m_PPet->health.mp > 7)  	
			    {
				 spellID = 1;
				}
			else
			    {
				 spellID = -1;
				}
		else if (level > 16)
			if (m_PPet->health.mp > 24)  	
			    {
				 spellID = 2;
				}				
			else if (m_PPet->health.mp > 7)  	
			    {
				 spellID = 1;
				}
			else
			    {
				 spellID = -1;
				}
		else if (level > 4)
			if (m_PPet->health.mp > 7)  	
			    {
				 spellID = 1;
				}
			else
			    {
				 spellID = -1;
				} 
		else
		        {
				 spellID = -1;
				} 
		m_LastAdelhiedHeal = m_Tick;		
     }
	 else
	 { 
	   m_LastAdelhiedHeal = m_Tick;
	   m_adelhiedHealRecast = 12000; //No eligible Healing Spell set new recast to 12 seconds
	 }
	 }

  else if (m_Tick >= m_LastSchEnh + m_schEnhRecast && m_ActionType != ACTION_MAGIC_CASTING) // Look for last time Sscholar used enhancing... will do Regen on Master.  If level is 40 and above will use Acession to AoE 
    {
	 //ShowWarning("ENHANCING CHECK TRIGGERED\n");
	 m_PBattleSubTarget = m_PBattleTarget;
	 if (m_PPet->PMaster->GetHPP() > 65 && m_PPet->PMaster->GetHPP() < 95 && m_PPet->PMaster->StatusEffectContainer->HasStatusEffect(EFFECT_REGEN) == false)
     {
	    //printf("REGEN TRIGGERED\n!!");
		if (level >= 10 && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_TRUST_LIGHT_ARTS) == false){
	        m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3718) { //Light Arts
						    mobjaID = 195;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;  //Target Self
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				//printf("Using Light Arts\n");
				//return;	
	}
	if (level >= 40 && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_TRUST_ACCESSION) == false){
	        m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3720) { //Accession
						    mobjaID = 202;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;  //Target Self
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
			    //printf("Using Accession");
				//return;	
	}	 
	 m_PBattleSubTarget = m_PPet->PMaster;
	 if (level >= 59)
             if (m_PPet->health.mp >= 64)
		            {
				     spellID = 111;
					}
                else if (m_PPet->health.mp >= 36)
					{
					 spellID = 110;
					}
                else if (m_PPet->health.mp >= 15)
					{
					 spellID = 108;
					}					
				else 
			        {
				     spellID = -1;
				    } 
			else if (level >= 37)
                if (m_PPet->health.mp >= 36)
					{
					 spellID = 110;
					}
                else if (m_PPet->health.mp >= 15)
					{
					 spellID = 108;
					}					
				else 
			        {
				     spellID = -1;
				    }
			else if (level >= 18)
                if (m_PPet->health.mp >= 15)
					{
					 spellID = 108;
					}					
				else 
			        {
				     spellID = -1;
				    }					
			else
		        {
				 spellID = -1;
				} 
	  m_LastSchEnh = m_Tick;	
	 }
	 else
	 {
	  m_LastSchEnh = m_Tick;
      m_schEnhRecast = 11000; //No Eligible Enhancing Spell to cast, set check to 11 seconds
	 }
	 }
  else if (m_Tick >= m_LastSchEleCast + m_schEleRecast && m_ActionType != ACTION_MAGIC_CASTING)  // Look for last time Scholar Casted
	{
	 //Helix Spells First if mob HP is above 75%
     if (m_PBattleTarget != nullptr && m_PBattleTarget->getMod(MOD_THUNDERRES) < 0 && m_PBattleTarget->GetHPP() >= nukeHPP && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_HELIX) == false)  // Weak to Thunder use Ionohelix
	 {
	 m_PBattleSubTarget = m_PBattleTarget;
		if (level >= 28)
			if (m_PPet->health.mp > 25)
				{
				 spellID = 283;
				}
            else
				{
				 spellID = -1;
				}			 
		m_schEleRecast = 10000;
    }
	 else if (m_PBattleTarget != nullptr && m_PBattleTarget->getMod(MOD_ICERES) < 0 && m_PBattleTarget->GetHPP() >= nukeHPP && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_HELIX) == false)  // Weak to Ice use Cryohelix
	{
	 	if (level >= 10 && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_TRUST_DARK_ARTS) == false){
	        m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3719) { //Dark Arts
						    mobjaID = 196;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;  //Target Self
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				//printf("Using Dark Arts");
				//return;	
	    }
	 m_PBattleSubTarget = m_PBattleTarget;
		if (level >= 26)
			if (m_PPet->health.mp > 25)
				{
				 spellID = 282;
				}
            else
				{
				 spellID = -1;
				}			 
		m_schEleRecast = 10000;			
    }
	 else if (m_PBattleTarget != nullptr && m_PBattleTarget->getMod(MOD_FIRERES) < 0 && m_PBattleTarget->GetHPP() >= nukeHPP && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_HELIX) == false)  // Weak to Fire use Pyrohelix
	{
	 	if (level >= 10 && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_TRUST_DARK_ARTS) == false){
	        m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3719) { //Dark Arts
						    mobjaID = 196;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;  //Target Self
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				//printf("Using Dark Arts");
				//return;	
	    }	
	 m_PBattleSubTarget = m_PBattleTarget;
		if (level >= 24)
			if (m_PPet->health.mp > 25)
				{
				 spellID = 281;
				}
            else
				{
				 spellID = -1;
				}			 
		m_schEleRecast = 10000;	
    }
	 else if (m_PBattleTarget != nullptr && m_PBattleTarget->getMod(MOD_WINDRES) < 0 && m_PBattleTarget->GetHPP() >= nukeHPP && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_HELIX) == false)  // Weak to Wind use Amenohelix
	{
	 	if (level >= 10 && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_TRUST_DARK_ARTS) == false){
	        m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3719) { //Dark Arts
						    mobjaID = 196;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;  //Target Self
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				//printf("Using Dark Arts");
				//return;	
	    }	
	 m_PBattleSubTarget = m_PBattleTarget;
		if (level >= 22)
			if (m_PPet->health.mp > 25)
				{
				 spellID = 280;
				}
            else
				{
				 spellID = -1;
				}			 
		m_schEleRecast = 10000;
    }
	 else if (m_PBattleTarget != nullptr && m_PBattleTarget->getMod(MOD_WATERRES) < 0 && m_PBattleTarget->GetHPP() >= nukeHPP && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_HELIX) == false)  // Weak to Water use Hydrohelix
	{
	 	if (level >= 10 && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_TRUST_DARK_ARTS) == false){
	        m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3719) { //Dark Arts
						    mobjaID = 196;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;  //Target Self
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				//printf("Using Dark Arts");
				//return;	
	    }	
	 m_PBattleSubTarget = m_PBattleTarget;
		if (level >= 20)
			if (m_PPet->health.mp > 25)
				{
				 spellID = 279;
				}
            else
				{
				 spellID = -1;
				}			 
		m_schEleRecast = 10000;
    }
    else if (m_PBattleTarget != nullptr && m_PBattleTarget->getMod(MOD_EARTHRES) < 0 && m_PBattleTarget->GetHPP() >= nukeHPP && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_HELIX) == false)  // Weak to Earth use Geohelix
	{
	 	if (level >= 10 && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_TRUST_DARK_ARTS) == false){
	        m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3719) { //Dark Arts
						    mobjaID = 196;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;  //Target Self
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				//printf("Using Dark Arts");
				//return;	
	    }	
	 m_PBattleSubTarget = m_PBattleTarget;
		if (level >= 18)
			if (m_PPet->health.mp > 25)
				{
				 spellID = 278;
				}
            else
				{
				 spellID = -1;
				}			 
		m_schEleRecast = 10000;
    }
	//Start looking for weakness if the mobs HP is below 75% for regular nukes
	else if (m_PBattleTarget != nullptr && m_PBattleTarget->getMod(MOD_THUNDERRES) < 0 && m_PBattleTarget->GetHPP() <= nukeHPP){
	 	if (level >= 10 && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_TRUST_DARK_ARTS) == false){
	        m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3719) { //Dark Arts
						    mobjaID = 196;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;  //Target Self
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				//printf("Using Dark Arts");
				//return;	
	    }	
		m_PBattleSubTarget = m_PBattleTarget;
		if (level >= 75)
			if (m_PPet->health.mp > 195)
				{
				 spellID = 167;
				 //printf("Spell Should Be: %d \n", spellID);
				}
			else if (m_PPet->health.mp > 90)	
                {
				 spellID = 166;
			    }
			else if (m_PPet->health.mp > 36)	
                {
				 spellID = 165;
			    }
			else if (m_PPet->health.mp > 8)	
                {
				 spellID = 164;
			    }
            else
				{
				spellID = -1;
				}	
		else if (level >= 69)
			if (m_PPet->health.mp > 90)	
                {
				 spellID = 166;
			    }
			else if (m_PPet->health.mp > 36)	
                {
				 spellID = 165;
			    }
			else if (m_PPet->health.mp > 8)	
                {
				 spellID = 164;
			    }
            else
				{
				 spellID = -1;
				}
		else if (level >= 51)
			if (m_PPet->health.mp > 36)	
                {
				 spellID = 165;
			    }
			else if (m_PPet->health.mp > 8)	
                {
				 spellID = 164;
			    }
            else
				{
				 spellID = -1;
				}
		else if (level >= 24)
			if (m_PPet->health.mp > 8)	
                {
				 spellID = 164;
			    }
            else
				{
				 spellID = -1;
				}
		else
                {
                 spellID = -1;
                }			 

		m_schEleRecast = 18000;
		m_LastSchCheck = m_Tick;
		//m_burstElement = 0;
		}
       else if (m_PBattleTarget != nullptr && m_PBattleTarget->getMod(MOD_ICERES) < 0 && m_PBattleTarget->GetHPP() <= nukeHPP){
	 	if (level >= 10 && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_TRUST_DARK_ARTS) == false){
	        m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3719) { //Dark Arts
						    mobjaID = 196;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;  //Target Self
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				//printf("Using Dark Arts");
				//return;	
	    }	
        m_PBattleSubTarget = m_PBattleTarget;		
	    if (level >= 74)
			if (m_PPet->health.mp > 161)
				{
				 spellID = 152;
				}
			else if (m_PPet->health.mp > 74)	
                {
				 spellID = 151;
			    }
			else if (m_PPet->health.mp > 30)	
                {
				 spellID = 150;
			    }
			else if (m_PPet->health.mp > 7)	
                {
				 spellID = 149;
			    }
            else
				{
				 spellID = -1;
				}
		else if (level >= 66)
			if (m_PPet->health.mp > 74)	
                {
				 spellID = 151;
			    }
			else if (m_PPet->health.mp > 30)	
                {
				 spellID = 150;
			    }
			else if (m_PPet->health.mp > 7)	
                {
				 spellID = 149;
			    }
            else
				{
				 spellID = -1;
				}
        else if (level >= 46)
			if (m_PPet->health.mp > 30)	
                {
				 spellID = 150;
			    }
			else if (m_PPet->health.mp > 7)	
                {
				 spellID = 149;
			    }
            else
				{
				 spellID = -1;
				}
        else if (level >= 20)
			if (m_PPet->health.mp > 7)	
                {
				 spellID = 149;
			    }
            else
				{
				 spellID = -1;
				}
        m_schEleRecast = 18000;
		m_LastSchCheck = m_Tick;
        }		
    else if (m_PBattleTarget != nullptr && m_PBattleTarget->getMod(MOD_FIRERES) < 0 && m_PBattleTarget->GetHPP() <= nukeHPP){
	 	if (level >= 10 && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_TRUST_DARK_ARTS) == false){
	        m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3719) { //Dark Arts
						    mobjaID = 196;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;  //Target Self
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				//printf("Using Dark Arts");
				//return;	
	    }	
		m_PBattleSubTarget = m_PBattleTarget;
		if (level >= 73)
			if (m_PPet->health.mp > 134)
				{
				 spellID = 147;
				}
			else if (m_PPet->health.mp > 62)	
                {
				 spellID = 146;
			    }
			else if (m_PPet->health.mp > 25)	
                {
				 spellID = 145;
			    }
			else if (m_PPet->health.mp > 6)	
                {
				 spellID = 144;
			    }
            else
				{
				 spellID = -1;
				}
		else if (level >= 63)
			if (m_PPet->health.mp > 62)	
                {
				 spellID = 146;
			    }
			else if (m_PPet->health.mp > 25)	
                {
				 spellID = 145;
			    }
			else if (m_PPet->health.mp > 6)	
                {
				 spellID = 144;
			    }
            else
				{
				 spellID = -1;
				}
        else if (level >= 42)
			if (m_PPet->health.mp > 25)	
                {
				 spellID = 145;
			    }
			else if (m_PPet->health.mp > 6)	
                {
				 spellID = 144;
			    }
            else
				{
				 spellID = -1;
				}
        else if (level >= 16)
			if (m_PPet->health.mp > 6)	
                {
				 spellID = 144;
			    }
            else
				{
				 spellID = -1;
				}	    
    m_schEleRecast = 18000;
	m_LastSchCheck = m_Tick;
    }
    else if (m_PBattleTarget != nullptr && m_PBattleTarget->getMod(MOD_WINDRES) < 0 && m_PBattleTarget->GetHPP() <= nukeHPP){
	 	if (level >= 10 && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_TRUST_DARK_ARTS) == false){
	        m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3719) { //Dark Arts
						    mobjaID = 196;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;  //Target Self
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				//printf("Using Dark Arts");
				//return;	
	    }	
		m_PBattleSubTarget = m_PBattleTarget;
		if (level >= 72)
			if (m_PPet->health.mp > 114)
				{
				 spellID = 157;
				}
			else if (m_PPet->health.mp > 53)	
                {
				 spellID = 156;
			    }
			else if (m_PPet->health.mp > 21)	
                {
				 spellID = 155;
			    }
			else if (m_PPet->health.mp > 5)	
                {
				 spellID = 154;
			    }
            else
				{
				 spellID = -1;
				}
		else if (level >= 60)
			if (m_PPet->health.mp > 53)	
                {
				 spellID = 156;
			    }
			else if (m_PPet->health.mp > 21)	
                {
				 spellID = 155;
			    }
			else if (m_PPet->health.mp > 5)	
                {
				 spellID = 144;
			    }
            else
				{
				 spellID = -1;
				}
        else if (level >= 38)
			if (m_PPet->health.mp > 21)	
                {
				 spellID = 155;
			    }
			else if (m_PPet->health.mp > 5)	
                {
				 spellID = 154;
			    }
            else
				{
				 spellID = -1;
				}
        else if (level >= 12)
			if (m_PPet->health.mp > 5)	
                {
				 spellID = 154;
			    }
            else
				{
				 spellID = -1;
				}	
    m_schEleRecast = 18000;
	m_LastSchCheck = m_Tick;
    }
    else if (m_PBattleTarget != nullptr && m_PBattleTarget->getMod(MOD_WATERRES) < 0 && m_PBattleTarget->GetHPP() <= nukeHPP){
	 	if (level >= 10 && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_TRUST_DARK_ARTS) == false){
	        m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3719) { //Dark Arts
						    mobjaID = 196;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;  //Target Self
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				//printf("Using Dark Arts");
				//return;	
	    }	
		m_PBattleSubTarget = m_PBattleTarget;
		if (level >= 71)
			if (m_PPet->health.mp > 98)
				{
				 spellID = 172;
				}
			else if (m_PPet->health.mp > 45)	
                {
				 spellID = 171;
			    }
			else if (m_PPet->health.mp > 18)	
                {
				 spellID = 170;
			    }
			else if (m_PPet->health.mp > 4)	
                {
				 spellID = 169;
			    }
            else
				{
				 spellID = -1;
				}
		else if (level >= 57)
			if (m_PPet->health.mp > 45)	
                {
				 spellID = 171;
			    }
			else if (m_PPet->health.mp > 18)	
                {
				 spellID = 170;
			    }
			else if (m_PPet->health.mp > 4)	
                {
				 spellID = 169;
			    }
            else
				{
				 spellID = -1;
				}
        else if (level >= 34)
			if (m_PPet->health.mp > 18)	
                {
				 spellID = 170;
			    }
			else if (m_PPet->health.mp > 4)	
                {
				 spellID = 169;
			    }
            else
				{
				 spellID = -1;
				}
        else if (level >= 8)
			if (m_PPet->health.mp > 4)	
                {
				 spellID = 169;
			    }
            else
				{
				 spellID = -1;
				}	
    m_schEleRecast = 18000;
	m_LastSchCheck = m_Tick;
    }
    else if (m_PBattleTarget != nullptr && m_PBattleTarget->getMod(MOD_EARTHRES) < 0 && m_PBattleTarget->GetHPP() <= nukeHPP){
	 	if (level >= 10 && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_TRUST_DARK_ARTS) == false){
	        m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3719) { //Dark Arts
						    mobjaID = 196;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;  //Target Self
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				//printf("Using Dark Arts");
				//return;	
	    }
        m_PBattleSubTarget = m_PBattleTarget;		
		if (level >= 70)
			if (m_PPet->health.mp > 87)
				{
				 spellID = 162;
				}
			else if (m_PPet->health.mp > 39)	
                {
				 spellID = 161;
			    }
			else if (m_PPet->health.mp > 15)	
                {
				 spellID = 160;
			    }
			else if (m_PPet->health.mp > 3)	
                {
				 spellID = 159;
			    }
            else
				{
				 spellID = -1;
				}
		else if (level >= 54)
			if (m_PPet->health.mp > 39)	
                {
				 spellID = 161;
			    }
			else if (m_PPet->health.mp > 15)	
                {
				 spellID = 160;
			    }
			else if (m_PPet->health.mp > 3)	
                {
				 spellID = 159;
			    }
            else
				{
				 spellID = -1;
				}
        else if (level >= 30)
			if (m_PPet->health.mp > 15)	
                {
				 spellID = 160;
			    }
			else if (m_PPet->health.mp > 3)	
                {
				 spellID = 159;
			    }
            else
				{
				 spellID = -1;
				}
        else if (level >= 4)
			if (m_PPet->health.mp > 3)	
                {
				 spellID = 159;
			    }
            else
				{
				 spellID = -1;
				}
    m_schEleRecast = 18000;
	m_LastSchCheck = m_Tick;
    }
    else if (m_PBattleTarget != nullptr && m_PBattleTarget->GetHPP() <= nukeHPP){ //No Eligible Weakness Found
	 	if (level >= 10 && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_TRUST_DARK_ARTS) == false){
	        m_PWeaponSkill = nullptr;
            int16 mobjaID = -1;			
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                            
                        if (PMobSkill->getID() == 3719) { //Dark Arts
						    mobjaID = 196;
                            SetCurrentMobSkill(PMobSkill);
							SetCurrentJobAbility(mobjaID);
							m_PBattleSubTarget = m_PPet;  //Target Self
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				//printf("Using Dark Arts");
				//return;	
	    }	
		m_PBattleSubTarget = m_PBattleTarget;
		if (level >= 75)
		    if (m_PPet->health.mp > 194)
			{
			 spellID = 167; //THUNDER IV
			}
        else if (m_PPet->health.mp > 161)
			{
			 spellID = 152; //BLIZZARD IV
			}
        else if (m_PPet->health.mp > 134)
			{
			 spellID = 147; //FIRE IV
			}
        else if (m_PPet->health.mp > 114)
			{
			 spellID = 157; //AERO IV
			}
        else if (m_PPet->health.mp > 98)
			{
			 spellID = 172; //WATER IV
			}
        else if (m_PPet->health.mp > 87)
			{
			 spellID = 162; //STONE IV
			}
        else if (m_PPet->health.mp > 90)
			{
			 spellID = 166; //THUNDER III
			}
        else if (m_PPet->health.mp > 74)
			{
			 spellID = 151; //BLIZZARD III
			}
        else if (m_PPet->health.mp > 62)
			{
			 spellID = 146; //FIRE III
			}
        else if (m_PPet->health.mp > 53)
			{
			 spellID = 156; //AERO III
			}
        else if (m_PPet->health.mp > 45)
			{
			 spellID = 171; //WATER III
			}
        else if (m_PPet->health.mp > 39)
			{
			 spellID = 161; //STONE III
			}
        else if (m_PPet->health.mp > 36)
			{
			 spellID = 165; //THUNDER II
			}
        else if (m_PPet->health.mp > 30)
			{
			 spellID = 150; //BLIZZARD II
			}
        else if (m_PPet->health.mp > 25)
			{
			 spellID = 145; //FIRE II
			}
        else if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 74)
		    if (m_PPet->health.mp > 161)
			{
			 spellID = 152; //BLIZZARD IV
			}
        else if (m_PPet->health.mp > 134)
			{
			 spellID = 147; //FIRE IV
			}
        else if (m_PPet->health.mp > 114)
			{
			 spellID = 157; //AERO IV
			}
        else if (m_PPet->health.mp > 98)
			{
			 spellID = 172; //WATER IV
			}
        else if (m_PPet->health.mp > 87)
			{
			 spellID = 162; //STONE IV
			}
        else if (m_PPet->health.mp > 90)
			{
			 spellID = 166; //THUNDER III
			}
        else if (m_PPet->health.mp > 74)
			{
			 spellID = 151; //BLIZZARD III
			}
        else if (m_PPet->health.mp > 62)
			{
			 spellID = 146; //FIRE III
			}
        else if (m_PPet->health.mp > 53)
			{
			 spellID = 156; //AERO III
			}
        else if (m_PPet->health.mp > 45)
			{
			 spellID = 171; //WATER III
			}
        else if (m_PPet->health.mp > 39)
			{
			 spellID = 161; //STONE III
			}
        else if (m_PPet->health.mp > 36)
			{
			 spellID = 165; //THUNDER II
			}
        else if (m_PPet->health.mp > 30)
			{
			 spellID = 150; //BLIZZARD II
			}
        else if (m_PPet->health.mp > 25)
			{
			 spellID = 145; //FIRE II
			}
        else if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}	
		else if (level >= 73)
		    if (m_PPet->health.mp > 134)
			{
			 spellID = 147; //FIRE IV
			}
        else if (m_PPet->health.mp > 114)
			{
			 spellID = 157; //AERO IV
			}
        else if (m_PPet->health.mp > 98)
			{
			 spellID = 172; //WATER IV
			}
        else if (m_PPet->health.mp > 87)
			{
			 spellID = 162; //STONE IV
			}
        else if (m_PPet->health.mp > 90)
			{
			 spellID = 166; //THUNDER III
			}
        else if (m_PPet->health.mp > 74)
			{
			 spellID = 151; //BLIZZARD III
			}
        else if (m_PPet->health.mp > 62)
			{
			 spellID = 146; //FIRE III
			}
        else if (m_PPet->health.mp > 53)
			{
			 spellID = 156; //AERO III
			}
        else if (m_PPet->health.mp > 45)
			{
			 spellID = 171; //WATER III
			}
        else if (m_PPet->health.mp > 39)
			{
			 spellID = 161; //STONE III
			}
        else if (m_PPet->health.mp > 36)
			{
			 spellID = 165; //THUNDER II
			}
        else if (m_PPet->health.mp > 30)
			{
			 spellID = 150; //BLIZZARD II
			}
        else if (m_PPet->health.mp > 25)
			{
			 spellID = 145; //FIRE II
			}
        else if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}	
		else if (level >= 72)
		    if (m_PPet->health.mp > 114)
			{
			 spellID = 157; //AERO IV
			}
        else if (m_PPet->health.mp > 98)
			{
			 spellID = 172; //WATER IV
			}
        else if (m_PPet->health.mp > 87)
			{
			 spellID = 162; //STONE IV
			}
        else if (m_PPet->health.mp > 90)
			{
			 spellID = 166; //THUNDER III
			}
        else if (m_PPet->health.mp > 74)
			{
			 spellID = 151; //BLIZZARD III
			}
        else if (m_PPet->health.mp > 62)
			{
			 spellID = 146; //FIRE III
			}
        else if (m_PPet->health.mp > 53)
			{
			 spellID = 156; //AERO III
			}
        else if (m_PPet->health.mp > 45)
			{
			 spellID = 171; //WATER III
			}
        else if (m_PPet->health.mp > 39)
			{
			 spellID = 161; //STONE III
			}
        else if (m_PPet->health.mp > 36)
			{
			 spellID = 165; //THUNDER II
			}
        else if (m_PPet->health.mp > 30)
			{
			 spellID = 150; //BLIZZARD II
			}
        else if (m_PPet->health.mp > 25)
			{
			 spellID = 145; //FIRE II
			}
        else if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}	
		else if (level >= 71)
		   if (m_PPet->health.mp > 98)
			{
			 spellID = 172; //WATER IV
			}
        else if (m_PPet->health.mp > 87)
			{
			 spellID = 162; //STONE IV
			}
        else if (m_PPet->health.mp > 90)
			{
			 spellID = 166; //THUNDER III
			}
        else if (m_PPet->health.mp > 74)
			{
			 spellID = 151; //BLIZZARD III
			}
        else if (m_PPet->health.mp > 62)
			{
			 spellID = 146; //FIRE III
			}
        else if (m_PPet->health.mp > 53)
			{
			 spellID = 156; //AERO III
			}
        else if (m_PPet->health.mp > 45)
			{
			 spellID = 171; //WATER III
			}
        else if (m_PPet->health.mp > 39)
			{
			 spellID = 161; //STONE III
			}
        else if (m_PPet->health.mp > 36)
			{
			 spellID = 165; //THUNDER II
			}
        else if (m_PPet->health.mp > 30)
			{
			 spellID = 150; //BLIZZARD II
			}
        else if (m_PPet->health.mp > 25)
			{
			 spellID = 145; //FIRE II
			}
        else if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}		
        else if (level >= 70)
		  if (m_PPet->health.mp > 87)
			{
			 spellID = 162; //STONE IV
			}
        else if (m_PPet->health.mp > 90)
			{
			 spellID = 166; //THUNDER III
			}
        else if (m_PPet->health.mp > 74)
			{
			 spellID = 151; //BLIZZARD III
			}
        else if (m_PPet->health.mp > 62)
			{
			 spellID = 146; //FIRE III
			}
        else if (m_PPet->health.mp > 53)
			{
			 spellID = 156; //AERO III
			}
        else if (m_PPet->health.mp > 45)
			{
			 spellID = 171; //WATER III
			}
        else if (m_PPet->health.mp > 39)
			{
			 spellID = 161; //STONE III
			}
        else if (m_PPet->health.mp > 36)
			{
			 spellID = 165; //THUNDER II
			}
        else if (m_PPet->health.mp > 30)
			{
			 spellID = 150; //BLIZZARD II
			}
        else if (m_PPet->health.mp > 25)
			{
			 spellID = 145; //FIRE II
			}
        else if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}		
        else if (level >= 69)
		   if (m_PPet->health.mp > 90)
			{
			 spellID = 166; //THUNDER III
			}
        else if (m_PPet->health.mp > 74)
			{
			 spellID = 151; //BLIZZARD III
			}
        else if (m_PPet->health.mp > 62)
			{
			 spellID = 146; //FIRE III
			}
        else if (m_PPet->health.mp > 53)
			{
			 spellID = 156; //AERO III
			}
        else if (m_PPet->health.mp > 45)
			{
			 spellID = 171; //WATER III
			}
        else if (m_PPet->health.mp > 39)
			{
			 spellID = 161; //STONE III
			}
        else if (m_PPet->health.mp > 36)
			{
			 spellID = 165; //THUNDER II
			}
        else if (m_PPet->health.mp > 30)
			{
			 spellID = 150; //BLIZZARD II
			}
        else if (m_PPet->health.mp > 25)
			{
			 spellID = 145; //FIRE II
			}
        else if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 66)
		   if (m_PPet->health.mp > 74)
			{
			 spellID = 151; //BLIZZARD III
			}
        else if (m_PPet->health.mp > 62)
			{
			 spellID = 146; //FIRE III
			}
        else if (m_PPet->health.mp > 53)
			{
			 spellID = 156; //AERO III
			}
        else if (m_PPet->health.mp > 45)
			{
			 spellID = 171; //WATER III
			}
        else if (m_PPet->health.mp > 39)
			{
			 spellID = 161; //STONE III
			}
        else if (m_PPet->health.mp > 36)
			{
			 spellID = 165; //THUNDER II
			}
        else if (m_PPet->health.mp > 30)
			{
			 spellID = 150; //BLIZZARD II
			}
        else if (m_PPet->health.mp > 25)
			{
			 spellID = 145; //FIRE II
			}
        else if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 63)
		    if (m_PPet->health.mp > 62)
			{
			 spellID = 146; //FIRE III
			}
        else if (m_PPet->health.mp > 53)
			{
			 spellID = 156; //AERO III
			}
        else if (m_PPet->health.mp > 45)
			{
			 spellID = 171; //WATER III
			}
        else if (m_PPet->health.mp > 39)
			{
			 spellID = 161; //STONE III
			}
        else if (m_PPet->health.mp > 36)
			{
			 spellID = 165; //THUNDER II
			}
        else if (m_PPet->health.mp > 30)
			{
			 spellID = 150; //BLIZZARD II
			}
        else if (m_PPet->health.mp > 25)
			{
			 spellID = 145; //FIRE II
			}
        else if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 60)
		    if (m_PPet->health.mp > 53)
			{
			 spellID = 156; //AERO III
			}
        else if (m_PPet->health.mp > 45)
			{
			 spellID = 171; //WATER III
			}
        else if (m_PPet->health.mp > 39)
			{
			 spellID = 161; //STONE III
			}
        else if (m_PPet->health.mp > 36)
			{
			 spellID = 165; //THUNDER II
			}
        else if (m_PPet->health.mp > 30)
			{
			 spellID = 150; //BLIZZARD II
			}
        else if (m_PPet->health.mp > 25)
			{
			 spellID = 145; //FIRE II
			}
        else if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 57)
		   if (m_PPet->health.mp > 45)
			{
			 spellID = 171; //WATER III
			}
        else if (m_PPet->health.mp > 39)
			{
			 spellID = 161; //STONE III
			}
        else if (m_PPet->health.mp > 36)
			{
			 spellID = 165; //THUNDER II
			}
        else if (m_PPet->health.mp > 30)
			{
			 spellID = 150; //BLIZZARD II
			}
        else if (m_PPet->health.mp > 25)
			{
			 spellID = 145; //FIRE II
			}
        else if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 54)
		   if (m_PPet->health.mp > 39)
			{
			 spellID = 161; //STONE III
			}
        else if (m_PPet->health.mp > 36)
			{
			 spellID = 165; //THUNDER II
			}
        else if (m_PPet->health.mp > 30)
			{
			 spellID = 150; //BLIZZARD II
			}
        else if (m_PPet->health.mp > 25)
			{
			 spellID = 145; //FIRE II
			}
        else if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 51)
		   if (m_PPet->health.mp > 36)
			{
			 spellID = 165; //THUNDER II
			}
        else if (m_PPet->health.mp > 30)
			{
			 spellID = 150; //BLIZZARD II
			}
        else if (m_PPet->health.mp > 25)
			{
			 spellID = 145; //FIRE II
			}
        else if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 46)
		   if (m_PPet->health.mp > 30)
			{
			 spellID = 150; //BLIZZARD II
			}
        else if (m_PPet->health.mp > 25)
			{
			 spellID = 145; //FIRE II
			}
        else if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 42)
		  if (m_PPet->health.mp > 25)
			{
			 spellID = 145; //FIRE II
			}
        else if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 38)
		   if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 34)
		   if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 30)
		   if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 24)
		   if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 20)
		   if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 16)
		  if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}	
		else if (level >= 12)
		   if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 8)
		   if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}	
		else if (level >= 4)
		   if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}	
    m_schEleRecast = 18000;
	m_LastSchCheck = m_Tick;
    }

	else {
    m_schEleRecast = 10000; //No Eligible Spell to cast
	}
	m_LastSchEleCast = m_Tick;

	}
	}

	


	m_LastSchCheck = m_Tick;
	return spellID;
}

int16 CAIPetDummy::UlmiaSpell()
{	
    int16 spellID = -1;
	uint8 lvl = m_PPet->PMaster->GetMLevel();
	//bool crit = battleutils::GetCritHitRate(m_PPet->PMaster, m_PBattleTarget, true) > dsprand::GetRandomNumber(100);
	float currentDistance = distance(m_PPet->loc.p, m_PBattleTarget->loc.p);
	float currentPlayerDistance = distance(m_PPet->PMaster->loc.p, m_PBattleTarget->loc.p);
	uint8 hitrate;
	float charAtt;
	float mobDef;
	float pdif;
	int32 value;
	
     printf("Ulmia is trying to determine  a spell \n");
	//Decide which spell combo to cast.  Always prioritieze accuracy!
    // Song Combo List
	// #1 [DONE!] Madrigal x2                if hitrate is < 60 
	// #2 [DONE!] Minuet + Madrigal          if hitrate is < 80 and Pdif < 1.25 Neutral Eva or higher and Neutral Defense or Higher
	// #3 [DONE!] Minuet x 2                 if hitrate is > 79 and pdif < 1 Neutral Defense or higher, and low evasion		
	// #4 [DONE!] March + Madrigal           if hitrate is < 79 and pdif > 1.25 Neutral Evasion, Low Defense
    // #5 March + Minuet                     if hitrate is > 79 and pdif < 1.26 Low evasion, Neutral Defense
	// #6 March x2                           if hitrate is > 79 and pdif > 1.25  Low Defense, Low Evasion
	
	
	//First Check to see if the recast of the first melee song is up
	//This will determine when to do the calculations for Hitrate and pdif
	//so that Ulmia doesn't calculate when songs are up
	
	
	if (m_Tick >= m_LastFirstMeleeSongTime + m_firstMeleeSongRecast)  //Ten Seconds added to allow time for both songs to be down before making decision
	{
	    //Decide who the pdif and acc is based off of due to distances and then determine song combo
	    if (currentPlayerDistance < 10)
	    {
	        ShowWarning(CL_GREEN"Melee Distance, using Player Stats \n" CL_RESET);
	        hitrate = battleutils::GetHitRate(m_PPet->PMaster, m_PBattleTarget, 0);
	        charAtt = m_PPet->PMaster->ATT();
	        mobDef = m_PBattleTarget->DEF();
	        pdif = (charAtt / mobDef);
			
			//Determine Song Combo and write to PlayerVar in SQL
			if (hitrate < 60)
			{
			    int32 value = 1;
		        std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '1' ON DUPLICATE KEY UPDATE value = '1';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);	
			}
			else if (hitrate < 80 && hitrate > 59 && pdif < 1.25)
			{
			    int32 value = 2;
		        std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '2' ON DUPLICATE KEY UPDATE value = '2';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);	
			}	
            else if (hitrate > 79 && pdif < 1)
			{
			    int32 value = 3;
		        std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '3' ON DUPLICATE KEY UPDATE value = '3';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);	
			}	
			else if (hitrate < 80 && pdif > 1.25) // Neutral Evasion Low Defense
			{
			    int32 value = 4;
		        std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '4' ON DUPLICATE KEY UPDATE value = '4';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);	
			}
			else if (hitrate > 79 && pdif < 1.26) // Low Evasion Neutral to high def
			{
			    int32 value = 5;
		        std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '5' ON DUPLICATE KEY UPDATE value = '5';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);	
			}
			else if (hitrate > 79 && pdif > 1.25) // Low Evasion Low Defense
			{
			    int32 value = 6;
		        std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '6' ON DUPLICATE KEY UPDATE value = '6';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);	
			}					
	    }
        else
        {
	        if (m_PPet->m_PetID == PETID_ULMIA)
            {		
	            ShowWarning(CL_GREEN"Mage Distance, using Pet Stats \n" CL_RESET);
	            hitrate = battleutils::GetHitRate(m_PPet, m_PBattleTarget, 0);
	            charAtt = m_PPet->ATT();
	            mobDef = m_PBattleTarget->DEF();
	            pdif = (charAtt / mobDef);
				
			//Determine Song Combo and write to PlayerVar in SQL
			if (hitrate < 60)
			{
			    int32 value = 1;
		        std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '1' ON DUPLICATE KEY UPDATE value = '1';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);	
			}
			else if (hitrate < 80 && hitrate > 59 && pdif < 1.25)
			{
			    int32 value = 2;
		        std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '2' ON DUPLICATE KEY UPDATE value = '2';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);	
			}	
            else if (hitrate > 79 && pdif < 1)
			{
			    int32 value = 3;
		        std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '3' ON DUPLICATE KEY UPDATE value = '3';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);	
			}	
			else if (hitrate < 80 && pdif > 1.25) // Neutral Evasion Low Defense
			{
			    int32 value = 4;
		        std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '4' ON DUPLICATE KEY UPDATE value = '4';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);	
			}
			else if (hitrate > 79 && pdif < 1.26) // Low Evasion Neutral to high def
			{
			    int32 value = 5;
		        std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '5' ON DUPLICATE KEY UPDATE value = '5';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);	
			}
			else if (hitrate > 79 && pdif > 1.25) // Low Evasion Low Defense
			{
			    int32 value = 6;
		        std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '6' ON DUPLICATE KEY UPDATE value = '6';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);	
			}				
		    }	
        }
		//printf("Player Hitrate is: %u \n", hitrate);
	    //printf("Player PDIF: %f \n", pdif);		
	    //printf("Song Combo Received: %u \n", songcombo);
    }
	
	
	
	//float pdif = battleutils::GetDamageRatio(m_PPet->PMaster, m_PBattleTarget, 0, 0); NOT NEEDED

	uint32 songcombo = charutils::GetVar((CCharEntity*)m_PPet->PMaster,"UlmiaSong");
	
	

	
	

	
	
	//Frontline Spells.  Cast the first song based on Song Combo if Ulmia's Distance is less than 2 yalms from the battle target
	
	
    if (currentDistance <= m_PBattleTarget->m_ModelSize && m_PPet->speed != 0)
    {
	    if (m_Tick >= m_LastFirstMeleeSongTime + m_firstMeleeSongRecast && m_ActionType != ACTION_MAGIC_CASTING)
	    {
	        if (songcombo == 1) // Madrigal x2 (> 51)-> Madrigal + Minuet ( > 11) -> Minuet + Minne (< 11)
			{
		        ShowWarning(CL_RED"Casting First Song Madrigal x2 / Madrigal + Minuet / Minuet + Minne \n" CL_RESET);
                m_PBattleSubTarget = m_PPet;
		        if (lvl >= 51)
			    {    
                    spellID = 400; // Blade Madrigal
				    m_LastFirstMeleeSongTime = m_Tick;					
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 			
			    }
		        else if (lvl >= 11)
			    {    
                    spellID = 399; // Sword Madrigal
				    m_LastFirstMeleeSongTime = m_Tick;					
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 				
			    }			
			    else   // Minuet since low level
			    {
                    spellID = 394; // Valor Minuet
				    m_LastFirstMeleeSongTime = m_Tick;					
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 				
			    }			
		    }			
			else if (songcombo == 2) // Minuet + Madrigal
			{
		        ShowWarning(CL_GREEN"Minuet + Madrigal - Casting First Song \n" CL_RESET);			
		        m_PBattleSubTarget = m_PPet;
		        if (lvl >= 63)
			    {
				    spellID = 397; // Valor Minuet IV
				    m_LastFirstMeleeSongTime = m_Tick;				
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 	
				}
				else if (lvl >= 43)
				{
				    spellID = 396; // Valor Minuet III
				    m_LastFirstMeleeSongTime = m_Tick;				
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 					
				}
				else if (lvl >= 23)
				{
				    spellID = 395; // Valor Minuet II
				    m_LastFirstMeleeSongTime = m_Tick;				
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                }  					
				}					
				else
				{
				    spellID = 394; // Valor Minuet I
				    m_LastFirstMeleeSongTime = m_Tick;				
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 				
				}					
			}
			else if (songcombo == 3) // Minuet x2
			{
		        ShowWarning(CL_GREEN"Minuet x2 - Casting First Song \n" CL_RESET);			
		        m_PBattleSubTarget = m_PPet;
		        if (lvl >= 63)
			    {
				    spellID = 397; // Valor Minuet IV
				    m_LastFirstMeleeSongTime = m_Tick;				
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 	
				}
				else if (lvl >= 43)
				{
				    spellID = 396; // Valor Minuet III
				    m_LastFirstMeleeSongTime = m_Tick;				
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 					
				}
				else if (lvl >= 23)
				{
				    spellID = 395; // Valor Minuet II
				    m_LastFirstMeleeSongTime = m_Tick;				
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                }  					
				}					
				else
				{
				    spellID = 394; // Valor Minuet I
				    m_LastFirstMeleeSongTime = m_Tick;				
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 				
				}		
			}
			else if (songcombo == 4) // March + Madrigal
			{
		        ShowWarning(CL_GREEN"March +  Madrigal - Casting First Song \n" CL_RESET);			
			    m_PBattleSubTarget = m_PPet;		
		        if (lvl >= 60)
			    {
				    spellID = 420; // Victory March
				    m_LastFirstMeleeSongTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 					
				}
				else if (lvl >= 29)
				{
				    spellID = 419; // Advancing March
				    m_LastFirstMeleeSongTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 	 					
				}					
				else
				{
				    spellID = 394; // Valor Minuet
				    m_LastFirstMeleeSongTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 						
				}				
			}
			else if (songcombo == 5) // March + Minuet
			{
		        ShowWarning(CL_GREEN"March + Minuet - Casting First Song \n" CL_RESET);			
			    m_PBattleSubTarget = m_PPet;		
		        if (lvl >= 60)
			    {
				    spellID = 420; // Victory March
				    m_LastFirstMeleeSongTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 					
				}
				else if (lvl >= 29)
				{
				    spellID = 419; // Advancing March
				    m_LastFirstMeleeSongTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 	 					
				}					
				else
				{
				    spellID = 394; // Valor Minuet
				    m_LastFirstMeleeSongTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 						
				}				
			}
			else if (songcombo == 6) // March x2
			{
		        ShowWarning(CL_GREEN"March x2 - Casting First Song \n" CL_RESET);			
			    m_PBattleSubTarget = m_PPet;		
		        if (lvl >= 60)
			    {
				    spellID = 420; // Victory March
				    m_LastFirstMeleeSongTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 					
				}
				else if (lvl >= 29)
				{
				    spellID = 419; // Advancing March
				    m_LastFirstMeleeSongTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 	 					
				}					
				else
				{
				    spellID = 394; // Valor Minuet
				    m_LastFirstMeleeSongTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 						
				}							
			}
	    }
	    else if (m_Tick >= m_LastSecondMeleeSongTime + m_secondMeleeSongRecast)
	    {
	        if (songcombo == 1) // Madrigal x2 (> 51)-> Madrigal + Minuet ( > 11) -> Minuet + Minne (< 11)
			{
		        ShowWarning(CL_RED"Casting First Song Madrigal x2 / Madrigal + Minuet / Minuet + Minne \n" CL_RESET);
                m_PBattleSubTarget = m_PPet;
		        if (lvl >= 51)
			    {    
                    spellID = 399; // Sword Madrigal
				    m_LastSecondMeleeSongTime = m_Tick;					
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 			
			    }
		        else if (lvl >= 43)
			    {    
                    spellID = 396; // Valor Minuet III
				    m_LastSecondMeleeSongTime = m_Tick;					
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 				
			    }	
		        else if (lvl >= 23)
			    {    
                    spellID = 395; // Valor Minuet II
				    m_LastSecondMeleeSongTime = m_Tick;					
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 				
			    }				
			    else if (lvl >= 11)   
			    {
                    spellID = 394; // Valor Minuet I
				    m_LastSecondMeleeSongTime = m_Tick;					
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 				
			    }
			    else    // Minne
			    {
                    spellID = 389; // Knights Minne
				    m_LastSecondMeleeSongTime = m_Tick;					
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 				
			    }				
		    }
			else if (songcombo == 2) // Minuet + Madrigal
			{
			    ShowWarning(CL_GREEN"Minuet + Madrigal - Casting Second Song \n" CL_RESET);		
                m_PBattleSubTarget = m_PPet;
		        if (lvl >= 51)
			    {    
                    spellID = 400; // Blade Madrigal
				    m_LastSecondMeleeSongTime = m_Tick;					
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 			
			    }
		        else if (lvl >= 11)
			    {    
                    spellID = 399; // Sword Madrigal
				    m_LastSecondMeleeSongTime = m_Tick;					
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 				
			    }			
			    else   // Minuet since low level
			    {
                    spellID = 394; // Valor Minuet
				    m_LastSecondMeleeSongTime = m_Tick;					
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 				
			    }			
			}
			else if (songcombo == 3) // Minuet x2
			{
		        ShowWarning(CL_GREEN"Minuet x2 - Casting Second Song \n" CL_RESET);			
		        m_PBattleSubTarget = m_PPet;
		        if (lvl >= 63)
			    {
				    spellID = 396; // Valor Minuet III
				    m_LastSecondMeleeSongTime = m_Tick;				
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 	
				}
				else if (lvl >= 43)
				{
				    spellID = 395; // Valor Minuet II
				    m_LastSecondMeleeSongTime = m_Tick;				
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 					
				}
				else if (lvl >= 23)
				{
				    spellID = 394; // Valor Minuet I
				    m_LastSecondMeleeSongTime = m_Tick;				
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                }  					
				}					
				else
				{
				    spellID = 389; // Knights Minne
				    m_LastSecondMeleeSongTime = m_Tick;				
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 				
				}			
			}
			else if (songcombo == 4) // March + Madrigal
			{
		        ShowWarning(CL_RED"Casting Second Song March + Madrigal \n" CL_RESET);
                m_PBattleSubTarget = m_PPet;
		        if (lvl >= 51)
			    {    
                    spellID = 400; // Blade Madrigal
				    m_LastSecondMeleeSongTime = m_Tick;					
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 			
			    }
		        else if (lvl >= 11)
			    {    
                    spellID = 399; // Sword Madrigal
				    m_LastSecondMeleeSongTime = m_Tick;					
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 				
			    }			
			    else   // Minuet since low level
			    {
                    spellID = 394; // Valor Minuet
				    m_LastSecondMeleeSongTime = m_Tick;					
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 				
			    }			
			}
			else if (songcombo == 5) // March + Minuet
			{
		        ShowWarning(CL_GREEN"March + Minuet - Casting Second Song \n" CL_RESET);			
		        m_PBattleSubTarget = m_PPet;
		        if (lvl >= 63)
			    {
				    spellID = 397; // Valor Minuet IV
				    m_LastSecondMeleeSongTime = m_Tick;				
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 	
				}
				else if (lvl >= 43)
				{
				    spellID = 396; // Valor Minuet III
				    m_LastSecondMeleeSongTime = m_Tick;				
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 					
				}
				else if (lvl >= 23)
				{
				    spellID = 395; // Valor Minuet II
				    m_LastSecondMeleeSongTime = m_Tick;				
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                }  					
				}					
				else
				{
				    spellID = 394; // Valor Minuet I
				    m_LastSecondMeleeSongTime = m_Tick;				
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 				
				}								
			}
			else if (songcombo == 6) // March x2
			{
		        ShowWarning(CL_GREEN"March x2 - Casting Second Song \n" CL_RESET);			
			    m_PBattleSubTarget = m_PPet;		
		        if (lvl >= 60)
			    {
				    spellID = 419; // Advancing March
				    m_LastSecondMeleeSongTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 					
				}
				else if (lvl >= 23)
				{
				    spellID = 395; // Valor Minuet II
				    m_LastSecondMeleeSongTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 	 					
				}					
				else
				{
				    spellID = 389; // Knights Minne
				    m_LastSecondMeleeSongTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 						
				}			
			}	
	    }		
	}	
	
	
	
	
	
	// Frontline Spell Casting Based on Distance needing to be < 2 yalms from the battle target.
	
	
	//OLD IMPLEMENTATION BELOW!
	/*  
    if (currentDistance <= m_PBattleTarget->m_ModelSize && m_PPet->speed != 0)
    {

        // Second Song to Cast
        m_LastSongFrontTime = m_Tick;		
        if (songcombo == 1) // Madrigal x2 
		{
		    ShowWarning(CL_RED"Casting Second Song Madrigal - Madrigal x2 \n" CL_RESET);
            m_PBattleSubTarget = m_PPet;
		    if (lvl >= 51)
			{    
				if (m_Tick >= m_LastMadrigalWeakTime + m_madrigalWeakRecast && m_ActionType != ACTION_MAGIC_CASTING)
				{
				    spellID = 399; // Sword Madrigal
				    m_LastMadrigalWeakTime = m_Tick;
                    m_LastMarchStrongTime = m_Tick;
                    m_LastMadrigalStrongTime = m_Tick;
                    m_LastMinuetStrongTime = m_Tick;					
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	            	} 
				}
            	int32 value = 10;
			    std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '10' ON DUPLICATE KEY UPDATE value = '10';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);				
			}
		    else if (lvl >= 11)
			{    
				if (m_Tick >= m_LastMadrigalWeakTime + m_madrigalWeakRecast && m_ActionType != ACTION_MAGIC_CASTING)
				{
				    spellID = 394; // Valor Minuet
				    m_LastMadrigalWeakTime = m_Tick;
                    m_LastMarchStrongTime = m_Tick;
                    m_LastMadrigalStrongTime = m_Tick;
                    m_LastMinuetStrongTime = m_Tick;					
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	            	} 
				}
            	int32 value = 10;
			    std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '10' ON DUPLICATE KEY UPDATE value = '10';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);				
			}			
			else   // Minuet since low level
			{
				if (m_Tick >= m_LastMadrigalWeakTime + m_madrigalWeakRecast && m_ActionType != ACTION_MAGIC_CASTING)
			    {
				    spellID = 394; // Valor Minuet I
				    m_LastMadrigalWeakTime = m_Tick;
                    m_LastMarchStrongTime = m_Tick;
                    m_LastMadrigalStrongTime = m_Tick;
                    m_LastMinuetStrongTime = m_Tick;					
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	            	} 
				}
            	int32 value = 10;
			    std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '10' ON DUPLICATE KEY UPDATE value = '10';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);				
			}			
		}
        else if ((songcombo == 2) || (songcombo == 4)) // Minuet + Madrigal or March + Madrigal
		{
		    ShowWarning(CL_RED"Casting Second Song Madrigal - March + Madrigal or Minuet + Madrigal \n" CL_RESET);
            m_PBattleSubTarget = m_PPet;
		    if (lvl >= 51)
			{    
				if (m_Tick >= m_LastMadrigalWeakTime + m_madrigalWeakRecast && m_ActionType != ACTION_MAGIC_CASTING)
				{
				    spellID = 400; // Blade Madrigal
				    m_LastMadrigalWeakTime = m_Tick;
                    m_LastMarchStrongTime = m_Tick;
                    m_LastMadrigalStrongTime = m_Tick;
                    m_LastMinuetStrongTime = m_Tick;					
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	            	} 
				}
            	int32 value = 10;
			    std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '10' ON DUPLICATE KEY UPDATE value = '10';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);				
			}
		    else if (lvl >= 11)
			{    
				if (m_Tick >= m_LastMadrigalWeakTime + m_madrigalWeakRecast && m_ActionType != ACTION_MAGIC_CASTING)
				{
				    spellID = 399; // Sword Madrigal
				    m_LastMadrigalWeakTime = m_Tick;
                    m_LastMarchStrongTime = m_Tick;
                    m_LastMadrigalStrongTime = m_Tick;
                    m_LastMinuetStrongTime = m_Tick;					
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	            	} 
				}
            	int32 value = 10;
			    std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '10' ON DUPLICATE KEY UPDATE value = '10';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);				
			}			
			else   // Minuet since low level
			{
				if (m_Tick >= m_LastMadrigalWeakTime + m_madrigalWeakRecast && m_ActionType != ACTION_MAGIC_CASTING)
			    {
				    spellID = 394; // Valor Minuet I
				    m_LastMadrigalWeakTime = m_Tick;
                    m_LastMarchStrongTime = m_Tick;
                    m_LastMadrigalStrongTime = m_Tick;
                    m_LastMinuetStrongTime = m_Tick;					
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	            	} 
				}
            	int32 value = 10;
			    std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '10' ON DUPLICATE KEY UPDATE value = '10';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);				
			}			
		}
		else if (songcombo == 3) // Minuet x2
		{
		    ShowWarning(CL_RED"Casting Second Song as Minuet! \n" CL_RESET);
            m_PBattleSubTarget = m_PPet;
		    if (lvl >= 63)
			{    
				if (m_Tick >= m_LastMinuetWeakTime + m_minuetWeakRecast && m_ActionType != ACTION_MAGIC_CASTING)
				{
				    spellID = 396; // Valor Minuet III
				    m_LastMinuetWeakTime = m_Tick;
                    m_LastMarchStrongTime = m_Tick;
                    m_LastMadrigalStrongTime = m_Tick;
                    m_LastMinuetStrongTime = m_Tick;					
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	            	} 
				}
            	int32 value = 10;
			    std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '10' ON DUPLICATE KEY UPDATE value = '10';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);				
			}
		    else if (lvl >= 43)
			{    
				if (m_Tick >= m_LastMinuetWeakTime + m_minuetWeakRecast && m_ActionType != ACTION_MAGIC_CASTING)
				{
				    spellID = 395; // Valor Minuet II
				    m_LastMinuetWeakTime = m_Tick;	
                    m_LastMarchStrongTime = m_Tick;
                    m_LastMadrigalStrongTime = m_Tick;
                    m_LastMinuetStrongTime = m_Tick;					
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	            	} 
				}
            	int32 value = 10;
			    std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '10' ON DUPLICATE KEY UPDATE value = '10';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);				
			}
		    else if (lvl >= 23)
			{    
				if (m_Tick >= m_LastMinuetWeakTime + m_minuetWeakRecast && m_ActionType != ACTION_MAGIC_CASTING)
				{
				    spellID = 394; // Valor Minuet I
				    m_LastMinuetWeakTime = m_Tick;	
                    m_LastMarchStrongTime = m_Tick;
                    m_LastMadrigalStrongTime = m_Tick;
                    m_LastMinuetStrongTime = m_Tick;					
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	            	} 
				}
            	int32 value = 10;
			    std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '10' ON DUPLICATE KEY UPDATE value = '10';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);				
			}			
			else   // Paeon low level
			{
				if (m_Tick >= m_LastMinuetWeakTime + m_minuetWeakRecast && m_ActionType != ACTION_MAGIC_CASTING)
			    {
				    spellID = 378; // Paeon
				    m_LastMinuetWeakTime = m_Tick;	
                    m_LastMarchStrongTime = m_Tick;
                    m_LastMadrigalStrongTime = m_Tick;
                    m_LastMinuetStrongTime = m_Tick;					
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	            	} 
				}
			int32 value = 10;
			std::string varname;
			const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '10' ON DUPLICATE KEY UPDATE value = '10';";
            Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);					
			}		
		}
		else if (songcombo == 5) // March + Minuet
		{
		    ShowWarning(CL_RED"Casting Second Song as Minuet! \n" CL_RESET);
            m_PBattleSubTarget = m_PPet;
		    if (lvl >= 63)
			{    
				if (m_Tick >= m_LastMinuetWeakTime + m_minuetWeakRecast && m_ActionType != ACTION_MAGIC_CASTING)
				{
				    spellID = 397; // Valor Minuet IV
				    m_LastMinuetWeakTime = m_Tick;
                    m_LastMarchStrongTime = m_Tick;
                    m_LastMadrigalStrongTime = m_Tick;
                    m_LastMinuetStrongTime = m_Tick;					
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	            	} 
				}
            	int32 value = 10;
			    std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '10' ON DUPLICATE KEY UPDATE value = '10';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);				
			}
		    else if (lvl >= 43)
			{    
				if (m_Tick >= m_LastMinuetWeakTime + m_minuetWeakRecast && m_ActionType != ACTION_MAGIC_CASTING)
				{
				    spellID = 396; // Valor Minuet III
				    m_LastMinuetWeakTime = m_Tick;	
                    m_LastMarchStrongTime = m_Tick;
                    m_LastMadrigalStrongTime = m_Tick;
                    m_LastMinuetStrongTime = m_Tick;					
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	            	} 
				}
            	int32 value = 10;
			    std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '10' ON DUPLICATE KEY UPDATE value = '10';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);				
			}
		    else if (lvl >= 23)
			{    
				if (m_Tick >= m_LastMinuetWeakTime + m_minuetWeakRecast && m_ActionType != ACTION_MAGIC_CASTING)
				{
				    spellID = 395; // Valor Minuet II
				    m_LastMinuetWeakTime = m_Tick;	
                    m_LastMarchStrongTime = m_Tick;
                    m_LastMadrigalStrongTime = m_Tick;
                    m_LastMinuetStrongTime = m_Tick;					
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	            	} 
				}
            	int32 value = 10;
			    std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '10' ON DUPLICATE KEY UPDATE value = '10';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);				
			}			
			else   // Valor Minuet I
			{
				if (m_Tick >= m_LastMinuetWeakTime + m_minuetWeakRecast && m_ActionType != ACTION_MAGIC_CASTING)
			    {
				    spellID = 394; // Valor Minuet I
				    m_LastMinuetWeakTime = m_Tick;	
                    m_LastMarchStrongTime = m_Tick;
                    m_LastMadrigalStrongTime = m_Tick;
                    m_LastMinuetStrongTime = m_Tick;					
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	            	} 
				}
			int32 value = 10;
			std::string varname;
			const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '10' ON DUPLICATE KEY UPDATE value = '10';";
            Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);					
			}		
		}		
		else if (songcombo == 6) // March x 2
		{
		    ShowWarning(CL_RED"Casting Second Song March for Haste! \n" CL_RESET);
            m_PBattleSubTarget = m_PPet;
		    if (lvl >= 60)
			{    
				if (m_Tick >= m_LastMarchWeakTime + m_marchWeakRecast && m_ActionType != ACTION_MAGIC_CASTING)
				{
				    spellID = 419; // Advancing March
				    m_LastMarchWeakTime = m_Tick;
                    m_LastMarchStrongTime = m_Tick;
                    m_LastMadrigalStrongTime = m_Tick;
                    m_LastMinuetStrongTime = m_Tick;					
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	            	} 
				}
			    int32 value = 10;
			    std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '10' ON DUPLICATE KEY UPDATE value = '10';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);					
			}
		    else if (lvl >= 29)
			{    
				if (m_Tick >= m_LastMarchWeakTime + m_marchWeakRecast && m_ActionType != ACTION_MAGIC_CASTING)
				{
				    spellID = 395; // Valor Minuet II
				    m_LastMarchWeakTime = m_Tick;
                    m_LastMarchStrongTime = m_Tick;
                    m_LastMadrigalStrongTime = m_Tick;
                    m_LastMinuetStrongTime = m_Tick;					
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	            	} 
				}
			    int32 value = 10;
			    std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '10' ON DUPLICATE KEY UPDATE value = '10';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);					
			}
		    else if (lvl >= 23)
			{    
				if (m_Tick >= m_LastMarchWeakTime + m_marchWeakRecast && m_ActionType != ACTION_MAGIC_CASTING)
				{
				    spellID = 395; // Valor Minuet II
				    m_LastMarchWeakTime = m_Tick;
                    m_LastMarchStrongTime = m_Tick;
                    m_LastMadrigalStrongTime = m_Tick;
                    m_LastMinuetStrongTime = m_Tick;					
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	            	} 
				}
			    int32 value = 10;
			    std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '10' ON DUPLICATE KEY UPDATE value = '10';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);					
			}			
			else   
			{
				if (m_Tick >= m_LastMarchWeakTime + m_marchWeakRecast && m_ActionType != ACTION_MAGIC_CASTING)
			    {
				    spellID = 394; // Valor Minuet I
				    m_LastMarchWeakTime = m_Tick;
                    m_LastMarchStrongTime = m_Tick;
                    m_LastMadrigalStrongTime = m_Tick;
                    m_LastMinuetStrongTime = m_Tick;					
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	            	} 
				}
			    int32 value = 10;
			    std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '10' ON DUPLICATE KEY UPDATE value = '10';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);					
			}		
		}
		
		// First Songs to Cast
        if (hitrate < 60)
		{
		    //Madrigal x2
		    ShowWarning(CL_GREEN"Madrigal x2 - Casting First Song \n" CL_RESET);			
		    m_PBattleSubTarget = m_PPet;
		    if (lvl >= 51) //Double Madrigal Level
			{
			    if (m_Tick >= m_LastMadrigalStrongTime + m_madrigalStrongRecast && m_ActionType != ACTION_MAGIC_CASTING)
				{
				    spellID = 400; // Blade Madrigal
					m_LastMadrigalStrongTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	            	} 
				}
				ShowWarning(CL_GREEN"Casting Spell should be 400.  It is: %u \n" CL_RESET, spellID);
			    int32 value = 1;
		        std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '1' ON DUPLICATE KEY UPDATE value = '1';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);					
		    }
		    else if (lvl >= 11) //Madrigal + Highest Minuet
			{
			    if (m_Tick >= m_LastMadrigalStrongTime + m_madrigalStrongRecast && m_ActionType != ACTION_MAGIC_CASTING)
				{
				    spellID = 399; // Sword Madrigal
					m_LastMadrigalStrongTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	            	} 
				}
			    int32 value = 1;
		        std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '1' ON DUPLICATE KEY UPDATE value = '1';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);							
		    }
		    else //Paeon
			{
			    if (m_Tick >= m_LastMadrigalStrongTime + m_madrigalStrongRecast && m_ActionType != ACTION_MAGIC_CASTING)
				{
				    spellID = 378; // Paeon
					m_LastMadrigalStrongTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	            	} 
				}
			    int32 value = 1;
		        std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '1' ON DUPLICATE KEY UPDATE value = '1';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);					
					
		    }
		}
		else if (hitrate < 80 && hitrate > 59 && pdif < 1.25)
		{
		    //Minuet + Madrigal
		    ShowWarning(CL_GREEN"Minuet + Madrigal - Casting First Song \n" CL_RESET);
		    m_PBattleSubTarget = m_PPet;
			if (m_Tick >= m_LastMinuetStrongTime + m_minuetStrongRecast && m_ActionType != ACTION_MAGIC_CASTING)
		    {
		        if (lvl >= 63)
				{
				    spellID = 397; // Minuet IV
				    m_LastMinuetStrongTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                }
			        int32 value = 2;
		            std::string varname;
			        const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '2' ON DUPLICATE KEY UPDATE value = '2';";
                    Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);	 					
				}
				else if (lvl >= 43)
				{
				    spellID = 396; // Minuet III
					m_LastMinuetStrongTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 
			        int32 value = 2;
		            std::string varname;
			        const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '2' ON DUPLICATE KEY UPDATE value = '2';";
                    Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);							
				}
				else if (lvl >= 23)
				{
				    spellID = 395; // Minuet II
					m_LastMinuetStrongTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 
			        int32 value = 2;
		            std::string varname;
			        const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '2' ON DUPLICATE KEY UPDATE value = '2';";
                    Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);							
				}				
				else
				{
				    spellID = 394; // Minuet I
				    m_LastMinuetStrongTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 
			        int32 value = 2;
		            std::string varname;
			        const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '2' ON DUPLICATE KEY UPDATE value = '2';";
                    Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);						
				}
			}				
		}
		else if (hitrate > 79 && pdif < 1)
		{
		    //Minuet x2
		    ShowWarning(CL_GREEN"Minuet x2 - Casting First Song \n" CL_RESET);			
		    m_PBattleSubTarget = m_PPet;
			if (m_Tick >= m_LastMinuetStrongTime + m_minuetStrongRecast && m_ActionType != ACTION_MAGIC_CASTING)
			{
		        if (lvl >= 63)
			    {
				    spellID = 397; // Valor Minuet IV
				    m_LastMinuetStrongTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 
			        int32 value = 3;
		            std::string varname;
			        const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '3' ON DUPLICATE KEY UPDATE value = '3';";
                    Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);						
				}
				else if (lvl >= 43)
				{
				    spellID = 396; // Valor Minuet III
				    m_LastMinuetStrongTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 
			        int32 value = 3;
		            std::string varname;
			        const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '3' ON DUPLICATE KEY UPDATE value = '3';";
                    Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);						
				}
				else if (lvl >= 23)
				{
				    spellID = 395; // Valor Minuet II
					m_LastMinuetStrongTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	            	}
			        int32 value = 3;
		            std::string varname;
			        const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '3' ON DUPLICATE KEY UPDATE value = '3';";
                    Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);	 					
				}					
				else
				{
				    spellID = 394; // Valor Minuet I
				    m_LastMinuetStrongTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 
			        int32 value = 3;
		            std::string varname;
			        const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '3' ON DUPLICATE KEY UPDATE value = '3';";
                    Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);					
				}
			}								
		}	
		else if (hitrate < 80 && pdif > 1.25) // Neutral Evasion Low Defese
		{
		    //March + Madrigal
		    ShowWarning(CL_GREEN"March + Madrigal - Casting First Song \n" CL_RESET);
			m_PBattleSubTarget = m_PPet;		
			if (m_Tick >= m_LastMarchStrongTime + m_marchStrongRecast && m_ActionType != ACTION_MAGIC_CASTING)
			{
		        if (lvl >= 60)
			    {
				    spellID = 420; // Victory March
				    m_LastMarchStrongTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 
			        int32 value = 4;
		            std::string varname;
			        const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '4' ON DUPLICATE KEY UPDATE value = '4';";
                    Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);					
				}
				else if (lvl >= 29)
				{
				    spellID = 419; // Advancing March
				    m_LastMarchStrongTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 
			        int32 value = 4;
		            std::string varname;
			        const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '4' ON DUPLICATE KEY UPDATE value = '4';";
                    Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);					
				}					
				else
				{
				    spellID = 394; // Valor Minuet I
				    m_LastMarchStrongTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 
			        int32 value = 4;
		            std::string varname;
			        const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '4' ON DUPLICATE KEY UPDATE value = '4';";
                    Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);							
				}
			}				
		}
        else if (hitrate > 79 && pdif < 1.26) // Low Evasion Neutral to high def
		{
		    //March + Minuet
		    ShowWarning(CL_GREEN"March + Minuet - Casting First Song \n" CL_RESET);			
			m_PBattleSubTarget = m_PPet;		
			if (m_Tick >= m_LastMarchStrongTime + m_marchStrongRecast && m_ActionType != ACTION_MAGIC_CASTING)
			{
		        if (lvl >= 60)
			    {
				    spellID = 420; // Victory March
				    m_LastMarchStrongTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 	
			        int32 value = 5;
			        std::string varname;
			        const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '5' ON DUPLICATE KEY UPDATE value = '5';";
                    Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);					
				}
				else if (lvl >= 29)
				{
				    spellID = 419; // Advancing March
				    m_LastMarchStrongTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 
			        int32 value = 5;
			        std::string varname;
			        const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '5' ON DUPLICATE KEY UPDATE value = '5';";
                    Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);					
				}					
				else
				{
				    spellID = 394; // Valor Minuet I
				    m_LastMarchStrongTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 
			        int32 value = 5;
			        std::string varname;
			        const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '5' ON DUPLICATE KEY UPDATE value = '5';";
                    Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);						
				}
			}				
		}	
		else if (hitrate > 79 && pdif > 1.25) // Low Evasion Low Defese
		{
		    //March x2
		    ShowWarning(CL_GREEN"March x2 - Casting First Song \n" CL_RESET);			
			m_PBattleSubTarget = m_PPet;		
			if (m_Tick >= m_LastMarchStrongTime + m_marchStrongRecast && m_ActionType != ACTION_MAGIC_CASTING)
			{
		        if (lvl >= 60)
			    {
				    spellID = 420; // Victory March
				    m_LastMarchStrongTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                }
			        int32 value = 6;
			        std::string varname;
			        const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '6' ON DUPLICATE KEY UPDATE value = '6';";
                    Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);	 					
				}
				else if (lvl >= 29)
				{
				    spellID = 419; // Advancing March
				    m_LastMarchStrongTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                }
			        int32 value = 6;
			        std::string varname;
			        const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '6' ON DUPLICATE KEY UPDATE value = '6';";
                    Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);	 					
				}					
				else
				{
				    spellID = 394; // Valor Minuet I
				    m_LastMarchStrongTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 
			        int32 value = 6;
			        std::string varname;
			        const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '6' ON DUPLICATE KEY UPDATE value = '6';";
                    Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);						
				}
			}				
		}	
	
	}	

    */	
		

    // Backline Spells
    else if (currentDistance >= 11 && m_PPet->speed != 0)
    {
	    //printf("Ulmia is Far Away and will start Backline Spells \n");
        //Decide which spell combo to cast.  Always Double Ballad
        m_PBattleSubTarget = m_PPet;
		if (m_Tick >= m_LastFirstMageSongTime + m_firstMageSongRecast && m_ActionType != ACTION_MAGIC_CASTING)
		{
			if (lvl >= 55) //Double Ballad
			{
			    ShowWarning(CL_GREEN"Double Ballad First Song \n" CL_RESET);	
		        spellID = 387; // Mages Ballad II
			    m_LastFirstMageSongTime = m_Tick;			
		        if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		        {
	                spellID = -1;
	       	    } 
		    }
			else if (lvl >= 25) // Single Ballad
		    {
		        spellID = 386; // Mages Ballad I
			    m_LastFirstMageSongTime = m_Tick;
		        if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		        {
	                spellID = -1;
	          	} 
			    int32 value = 11;
			    std::string varname;
			    const int8* fmtQuery = "INSERT INTO char_vars SET charid = %u, varname = 'UlmiaSong', value = '11' ON DUPLICATE KEY UPDATE value = '11';";
                Sql_Query(SqlHandle, fmtQuery, m_PPet->PMaster->id, varname, value, value);					
			}
		}	
       	else if (m_Tick >= m_LastSecondMageSongTime + m_secondMageSongRecast && m_ActionType != ACTION_MAGIC_CASTING)
		{
		    ShowWarning(CL_GREEN"Single Ballad Song \n" CL_RESET);
			if (lvl >= 55) //Double Ballad
			{
			    ShowWarning(CL_GREEN"Double Ballad First Song \n" CL_RESET);	
		        spellID = 386; // Mages Ballad I
			    m_LastSecondMageSongTime = m_Tick;			
		        if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		        {
	                spellID = -1;
	       	    } 
		    }
			else //don't cast a second song if not above 54
			{
			    ShowWarning(CL_GREEN"No song to cast \n" CL_RESET);	
		        spellID = -1; 
			    m_LastSecondMageSongTime = m_Tick;			 
		    }			
        			
	    }
       	else if (m_Tick >= m_LastSongEnfeebleTime + m_songEnfeeble && m_ActionType != ACTION_MAGIC_CASTING)
		{
		    m_PBattleSubTarget = m_PBattleTarget;
		    if (m_PBattleTarget != nullptr && ((m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_ATTACK_BOOST)) || 
                (m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_ACCURACY_BOOST)) || 
                (m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_ATTACK_BOOST)) || 
				(m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_EVASION_BOOST)) || 
				(m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_DEFENSE_BOOST)) || 
				(m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_ENFIRE)) || 
				(m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_ENBLIZZARD)) || 
				(m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_ENAERO)) ||
				(m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_ENSTONE)) ||
				(m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_ENTHUNDER)) ||
				(m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_ENWATER)) || 
				(m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_SHOCK_SPIKES)) ||
				(m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_ICE_SPIKES)) ||
				(m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_BLAZE_SPIKES)) ||
				(m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_REGEN)) ||
				(m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_STONESKIN)) ||
				(m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_BLINK))))
            {
		        if (lvl >= 33)
			    {
				    ShowWarning(CL_RED"Casting Finale \n" CL_RESET);
		            spellID = 462; // Magic Finale
			        m_LastSongEnfeebleTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	              	} 
		     	}
                else
	    		{
    		        spellID = -1;
    			    m_LastSongEnfeebleTime = m_Tick;			
    		        if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
    		        {
    	                spellID = -1;
    	          	} 
    			}
    		}				
			else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_ELEGY) == false)
            {
			    ShowWarning(CL_RED"Casting Elegy \n" CL_RESET);
			    if (lvl >= 59)
			    {
		            spellID = 422; // Carnage Elegy
			        m_LastSongEnfeebleTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 
                }
			    else if (lvl >= 39)
			    {
		            spellID = 421; // Battlefield Elegy
			        m_LastSongEnfeebleTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 
                }
            }				
		    //Foe Requiem Before Finale
		    else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_REQUIEM) == false)
            {
				ShowWarning(CL_RED"Casting Require \n" CL_RESET);
			    if (lvl >= 67)
		        {
		            spellID = 373; // Requiem VI
			        m_LastSongEnfeebleTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 
                }
		        else if (lvl >= 57)
	            {
		            spellID = 372; // Requiem V
		            m_LastSongEnfeebleTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 
                }
	    		else if (lvl >= 47)
	    		{
		            spellID = 371; // Requiem IV
		    	    m_LastSongEnfeebleTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 
                }				
		    	else if (lvl >= 37)
		    	{
		            spellID = 370; // Requiem III
			        m_LastSongEnfeebleTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 
                }
			    else if (lvl >= 17)
		    	{
		            spellID = 369; // Requiem II
			        m_LastSongEnfeebleTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 
                }	
			    else if (lvl >= 7)
	    		{
	    	        spellID = 368; // Requiem I
	    		    m_LastSongEnfeebleTime = m_Tick;			
	    	        if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
	    	        {
	                    spellID = -1;
	                } 
                }	
			    else
			    {
		            spellID = -1;
			        m_LastSongEnfeebleTime = m_Tick;			
		            if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		            {
	                    spellID = -1;
	                } 
                }				
	        }	
        }		
		
	}	
    m_LastUlmiaSongTime = m_Tick;
	return spellID;
}


int16 CAIPetDummy::GesshoSpell()
{
    //Gessho Checks to cast magic ever 5 seconds, checks utsu timers every 15 seconds.
    int16 spellID = -1;
	uint8 lvl = m_PPet->GetMLevel();
	uint32 gesshoMB = charutils::GetVar((CCharEntity*)m_PPet->PMaster,"TrustMB");
    //Check for all Utsusemi Shadows
	if (m_Tick >= m_LastGesshoUtsuCheck + m_gesshoUtsuCheck && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_COPY_IMAGE) == false)
	{
		m_PBattleSubTarget = m_PPet;
		if (lvl >= 37)
		{
	        if (m_Tick >= m_LastGesshoUtsuNiTime + m_gesshoUtsuNiRecast && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == false)		
		    {
			    spellID = 339;
				m_LastGesshoUtsuNiTime = m_Tick;
		    }
	        else if (m_Tick >= m_LastGesshoUtsuIchiTime + m_gesshoUtsuIchiRecast && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == false)		
		    {
			    spellID = 338;
				m_LastGesshoUtsuIchiTime = m_Tick;
		    }
            else
			{
				spellID = -1;
			}		
        }			
		else
		{
	        if (m_Tick >= m_LastGesshoUtsuIchiTime + m_gesshoUtsuIchiRecast && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == false)		
		    {
			    spellID = 338;
				m_LastGesshoUtsuIchiTime = m_Tick;
		    }
            else
			{
				spellID = -1;
			}				
		}
        m_LastGesshoUtsuCheck = m_Tick;		
	}
	// Handle Enfeebling Magic
	else if (m_Tick >= m_LastGesshoEnfeeblingTime + m_gesshoEnfeeblingRecast && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == false)
	{
		m_PBattleSubTarget = m_PBattleTarget;
		if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_SLOW) == false)
		{
			if (lvl >= 48)
			{
				spellID = 345;  //Hojo Ni
				m_LastGesshoEnfeeblingTime = m_Tick;		
			}	
			else if (lvl >= 23)
			{
				spellID = 344;  //Hojo Ni
				m_LastGesshoEnfeeblingTime = m_Tick;		
			}
            else
			{
				spellID = -1;
			}				
		}
		else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_PARALYSIS) == false)
		{
			if (lvl >= 30)
			{
				spellID = 341;  //Jubaku Ichi
				m_LastGesshoEnfeeblingTime = m_Tick;		
			}	
            else
			{
				spellID = -1;
			}				
		}
		else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_BLINDNESS) == false)
		{
			if (lvl >= 44)
			{
				spellID = 348;  //Kurayami: Ni
				m_LastGesshoEnfeeblingTime = m_Tick;		
			}	
			else if (lvl >= 19)
			{
				spellID = 347;  //Kurayami: Ichi
				m_LastGesshoEnfeeblingTime = m_Tick;		
			}			
            else
			{
				spellID = -1;
			}				
		}
		else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_POISON) == false)
		{
			if (lvl >= 27)
			{
				spellID = 350;  //Dokumori: Ichi
				m_LastGesshoEnfeeblingTime = m_Tick;		
			}				
            else
			{
				spellID = -1;
			}				
		}		
	}	
	// Handle Magic Bursts with Elemental Jutsu
	/*
	if (gesshoMB == 6)
	{
		if (lvl >= 40)
		{
			spellID = 333;	// Raiton Ni		
		}
		else if (lvl >= 15)
		{
			spellID = 332;	// Raiton Ichi		
		}
        else
		{
			spellID = -1;
		}				
	}	
	else if (gesshoMB == 5)
	{
		if (lvl >= 40)
		{
			spellID = 324;	// Hyoton Ni		
		}
		else if (lvl >= 15)
		{
			spellID = 323;	// Hyoton Ichi		
		}
        else
		{
			spellID = -1;
		}				
	}	
	else if (gesshoMB == 4)
	{
		if (lvl >= 40)
		{
			spellID = 321;	// Katon Ni		
		}
		else if (lvl >= 15)
		{
			spellID = 320;	// Katon Ichi		
		}
        else
		{
			spellID = -1;
		}				
	}	
	else if (gesshoMB == 3)
	{
		if (lvl >= 40)
		{
			spellID = 327;	// Huton Ni		
		}
		else if (lvl >= 15)
		{
			spellID = 326;	// Huton Ichi		
		}
        else
		{
			spellID = -1;
		}				
	}
	else if (gesshoMB == 2)
	{
		if (lvl >= 40)
		{
			spellID = 336;	// Suiton Ni		
		}
		else if (lvl >= 15)
		{
			spellID = 335;	// Suiton Ichi		
		}
        else
		{
			spellID = -1;
		}				
	}
	else if (gesshoMB == 1)
	{
		if (lvl >= 40)
		{
			spellID = 330;	// Doton Ni		
		}
		else if (lvl >= 15)
		{
			spellID = 329;	// Doton Ichi		
		}
        else
		{
			spellID = -1;
		}				
	}
	else
	{
		spellID = -1;
	}*/
    m_LastGesshoMagicTime = m_Tick;
	return spellID;	
}


int16 CAIPetDummy::PrisheSpell()
{

	uint8 trigger = 25; // HP Trigger Threshold
	uint8 lowHPP = 31;
	uint8 level = m_PPet->GetMLevel();
    int16 spellID = -1;
	
 CBattleEntity* master = m_PPet->PMaster;  
 CBattleEntity* mostWounded = getWounded(trigger);
 if (m_Tick >= m_LastPrisheMagicTime + m_prisheHealRecast)  // Look for last magic healing spell time 
	{
        if (mostWounded != nullptr)
		{
        m_PBattleSubTarget = mostWounded;
		if (level > 40)
			if (m_PPet->health.mp > 88)
				{
				 spellID = 4;
				}
			else if (m_PPet->health.mp > 46)  	
			    {
				 spellID = 3;
				}
			else if (m_PPet->health.mp > 24)  	
			    {
				 spellID = 2;
				}				
			else if (m_PPet->health.mp > 7)  	
			    {
				 spellID = 1;
				}
			else 
			    {
				 spellID = -1;
				} 
		else if (level > 20)
			if (m_PPet->health.mp > 46)  	
			    {
				 spellID = 3;
				}
			else if (m_PPet->health.mp > 24)  	
			    {
				 spellID = 2;
				}				
			else if (m_PPet->health.mp > 7)  	
			    {
				 spellID = 1;
				}
			else
			    {
				 spellID = -1;
				}
		else if (level > 10)
			if (m_PPet->health.mp > 24)  	
			    {
				 spellID = 2;
				}				
			else if (m_PPet->health.mp > 7)  	
			    {
				 spellID = 1;
				}
			else
			    {
				 spellID = -1;
				}
		else if (level > 4)
			if (m_PPet->health.mp > 7)  	
			    {
				 spellID = 1;
				}
			else
			    {
				 spellID = -1;
				} 
		else
		        {
				 spellID = -1;
				} 
		m_LastPrisheMagicTime = m_Tick;	
        m_prisheHealRecast = 15000; 		
		if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == true)
		{
	    spellID = -1;
		} 
        m_prisheHealRecast = 12000; 
		//m_prisheHealCast = 1; // 1 means casting a spell
		}
		else
		{
		m_LastPrisheMagicTime = m_Tick; // reset mtick no eligible healing spell to cast
		m_prisheHealRecast = 8000;		
       }
	}
    return spellID;
}



int16 CAIPetDummy::ZeidSpell()
{	
    int16 spellID = -1;
	uint8 lvl = m_PPet->PMaster->GetMLevel();
    uint8 hitrate = battleutils::GetHitRate(m_PPet, m_PBattleTarget, 0);	
	
	if (m_Tick >= m_LastZeidAbsorbTime + m_zeidAbsorbRecast && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == false)  //Check Absorb Timers if NOT silenced
	{
	    if (m_Tick >= m_LastZeidDrainTime + m_zeidDrainRecast && m_ActionType != ACTION_MAGIC_CASTING && m_PPet->GetHPP() == 100)
	    {      
            m_PBattleSubTarget = m_PBattleTarget;
	        if (lvl >= 62 && m_PPet->health.mp > 36)
		    {  
                spellID = 246; // Drain II
		    }
            else
            {
                spellID = -1;
            }
            m_LastZeidDrainTime = m_Tick;				
	    }	
	    else if (m_Tick >= m_LastZeidAbsTPTime + m_zeidAbsTPRecast && m_ActionType != ACTION_MAGIC_CASTING && m_PPet->health.tp >= 400)
	    {      
            m_PBattleSubTarget = m_PBattleTarget;
	        if (lvl >= 45 && m_PPet->health.mp > 32)
		    {  
                spellID = 275; // Absorb TP
		    }
            else
            {
                spellID = -1;
            }
            m_LastZeidAbsTPTime = m_Tick;				
	    }
	    else if (m_Tick >= m_LastZeidAbsACCTime + m_zeidAbsACCRecast && m_ActionType != ACTION_MAGIC_CASTING && hitrate < 85)
	    {      
            m_PBattleSubTarget = m_PBattleTarget;
	        if (lvl >= 61 && m_PPet->health.mp > 32)
		    {  
                spellID = 242; // Absorb ACC
		    }
            else
            {
                spellID = -1;
            }
            m_LastZeidAbsACCTime = m_Tick;				
	    }
	    else if (m_Tick >= m_LastZeidAbsSTRTime + m_zeidAbsSTRRecast && m_ActionType != ACTION_MAGIC_CASTING)
	    {      
            m_PBattleSubTarget = m_PBattleTarget;
	        if (lvl >= 43 && m_PPet->health.mp > 32)
		    {  
                spellID = 266; // Absorb STR
		    }
            else
            {
                spellID = -1;
            }
            m_LastZeidAbsSTRTime = m_Tick;				
	    }	
        m_LastZeidAbsorbTime = m_Tick;
	}
	else if (m_Tick >= m_LastZeidEnfeebTime +  m_zeidEnfeebRecast)  //Check Enfeeble Timers
    {
        if (m_PPet->GetHPP() < 60 && m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_DREAD_SPIKES) == false)
        {
		    m_PBattleSubTarget = m_PPet;
			if (lvl >= 71 && m_PPet->health.mp > 77)
			{
			    spellID = 277;
			}
			else
			{
			    spellID = -1;
			}
        }   // Can Add Bio Here later? 	
	}
	
	
	
	
	//Input Spells here mostly Absorb and spikes and possibly stun
	return spellID;
}


int16 CAIPetDummy::ShantottoSpellDebuff()
{	
    int16 spellID = -1;
	float charAtt;
	float mobDef;
	float pdif;
	uint8 level = m_PPet->PMaster->GetMLevel();
    charAtt = m_PPet->ATT();
	mobDef = m_PBattleTarget->DEF();
    pdif = (charAtt / mobDef);
    if (m_Tick >= m_LastShantottoDebuffRecast + m_shantottoDebuffRecast && m_ActionType != ACTION_MAGIC_CASTING)	
    {
		m_PBattleSubTarget = m_PBattleTarget;
		ShowWarning(CL_GREEN"Shantotto CHecking Which Spell to use \n" CL_RESET);
		if (pdif < 1) // Trust has Low Attack use Frost Drown Rasp to help with melee
		{
		    ShowWarning(CL_GREEN"Shantotto FDR \n" CL_RESET);
		    if (level >= 22 && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_FROST) == false)
			  if (m_PPet->health.mp > 24)
			  {
			    spellID = 236;
			  }	
			  else
			  {
		        spellID = -1;
			  }
		    else if (level >= 27 && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_DROWN) == false)
			  if (m_PPet->health.mp > 24)
			  {				
				spellID = 240;
		      }
			  else
			  {
		        spellID = -1;
			  }			  
		    else if (level >= 18 && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_RASP) == false)
			  if (m_PPet->health.mp > 24)
			  {			  
		        spellID = 238;
		      }
		      else
			  {
		        spellID = -1;
			  }
			else
			{
			  spellID = -1;
			}
            m_LastShantottoDebuffRecast = m_Tick;			
		}
		else // Trusts have high Attack value switch to SCB
		{
		    ShowWarning(CL_GREEN"Shantotto SCB \n" CL_RESET);
		    if (level >= 16 && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_SHOCK) == false)
			  if (m_PPet->health.mp > 24)
			  {
			    spellID = 239;
			  }	
			  else
			  {
		        spellID = -1;
			  }
		    else if (level >= 20 && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_CHOKE) == false)
			  if (m_PPet->health.mp > 24)
			  {				
				spellID = 237;
		      }
			  else
			  {
		        spellID = -1;
			  }			  
		    else if (level >= 24 && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_BURN) == false)
			  if (m_PPet->health.mp > 24)
			  {			  
		        spellID = 235;
		      }
		      else
			  {
		        spellID = -1;
			  }
			else
			{
			  spellID = -1;
			}
            m_LastShantottoDebuffRecast = m_Tick;			
		}		
		
	}
	m_LastShantottoMagicTime = m_Tick;
	return spellID;
}



int16 CAIPetDummy::ShantottoSpellLowTier()
{	
    int16 spellID = -1;
	uint8 level = m_PPet->PMaster->GetMLevel();
    if (m_Tick >= m_LastShantottoEleCast + m_shantottoEleRecast && m_ActionType != ACTION_MAGIC_CASTING)	
    {
		m_PBattleSubTarget = m_PBattleTarget;
		if (level >= 75)
		    if (m_PPet->health.mp > 90)
			{
			 spellID = 166; //THUNDER III
			}
        else if (m_PPet->health.mp > 74)
			{
			 spellID = 151; //BLIZZARD III
			}
        else if (m_PPet->health.mp > 62)
			{
			 spellID = 146; //FIRE III
			}
        else if (m_PPet->health.mp > 53)
			{
			 spellID = 156; //AERO III
			}
        else if (m_PPet->health.mp > 45)
			{
			 spellID = 171; //WATER III
			}
        else if (m_PPet->health.mp > 39)
			{
			 spellID = 161; //STONE III
			}
        else if (m_PPet->health.mp > 36)
			{
			 spellID = 165; //THUNDER II
			}
        else if (m_PPet->health.mp > 30)
			{
			 spellID = 150; //BLIZZARD II
			}
        else if (m_PPet->health.mp > 25)
			{
			 spellID = 145; //FIRE II
			}
        else if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 66)
		   if (m_PPet->health.mp > 36)
			{
			 spellID = 165; //THUNDER II
			}
        else if (m_PPet->health.mp > 30)
			{
			 spellID = 150; //BLIZZARD II
			}
        else if (m_PPet->health.mp > 25)
			{
			 spellID = 145; //FIRE II
			}
        else if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}		
		else if (level >= 21)
		   if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 17)
		   if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 13)
		  if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}	
		else if (level >= 9)
		   if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 4)
		   if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}	
	    m_LastShantottoEleCast = m_Tick;
    }			
	else 
	   {
          m_shantottoEleRecast = 20000; //ShantCast
	   }
	   m_LastShantottoMagicTime = m_Tick;
	  return spellID;	
}

int16 CAIPetDummy::ShantottoSpell()
{	
    int16 spellID = -1;
	uint8 level = m_PPet->PMaster->GetMLevel();
    if (m_Tick >= m_LastShantottoEleCast + m_shantottoEleRecast && m_ActionType != ACTION_MAGIC_CASTING)	
    {
		m_PBattleSubTarget = m_PBattleTarget;
		if (level >= 75)
		    if (m_PPet->health.mp > 194)
			{
			 spellID = 167; //THUNDER IV
			}
        else if (m_PPet->health.mp > 161)
			{
			 spellID = 152; //BLIZZARD IV
			}
        else if (m_PPet->health.mp > 134)
			{
			 spellID = 147; //FIRE IV
			}
        else if (m_PPet->health.mp > 114)
			{
			 spellID = 157; //AERO IV
			}
        else if (m_PPet->health.mp > 98)
			{
			 spellID = 172; //WATER IV
			}
        else if (m_PPet->health.mp > 87)
			{
			 spellID = 162; //STONE IV
			}
        else if (m_PPet->health.mp > 90)
			{
			 spellID = 166; //THUNDER III
			}
        else if (m_PPet->health.mp > 74)
			{
			 spellID = 151; //BLIZZARD III
			}
        else if (m_PPet->health.mp > 62)
			{
			 spellID = 146; //FIRE III
			}
        else if (m_PPet->health.mp > 53)
			{
			 spellID = 156; //AERO III
			}
        else if (m_PPet->health.mp > 45)
			{
			 spellID = 171; //WATER III
			}
        else if (m_PPet->health.mp > 39)
			{
			 spellID = 161; //STONE III
			}
        else if (m_PPet->health.mp > 36)
			{
			 spellID = 165; //THUNDER II
			}
        else if (m_PPet->health.mp > 30)
			{
			 spellID = 150; //BLIZZARD II
			}
        else if (m_PPet->health.mp > 25)
			{
			 spellID = 145; //FIRE II
			}
        else if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 74)
		    if (m_PPet->health.mp > 161)
			{
			 spellID = 152; //BLIZZARD IV
			}
        else if (m_PPet->health.mp > 134)
			{
			 spellID = 147; //FIRE IV
			}
        else if (m_PPet->health.mp > 114)
			{
			 spellID = 157; //AERO IV
			}
        else if (m_PPet->health.mp > 98)
			{
			 spellID = 172; //WATER IV
			}
        else if (m_PPet->health.mp > 87)
			{
			 spellID = 162; //STONE IV
			}
        else if (m_PPet->health.mp > 90)
			{
			 spellID = 166; //THUNDER III
			}
        else if (m_PPet->health.mp > 74)
			{
			 spellID = 151; //BLIZZARD III
			}
        else if (m_PPet->health.mp > 62)
			{
			 spellID = 146; //FIRE III
			}
        else if (m_PPet->health.mp > 53)
			{
			 spellID = 156; //AERO III
			}
        else if (m_PPet->health.mp > 45)
			{
			 spellID = 171; //WATER III
			}
        else if (m_PPet->health.mp > 39)
			{
			 spellID = 161; //STONE III
			}
        else if (m_PPet->health.mp > 36)
			{
			 spellID = 165; //THUNDER II
			}
        else if (m_PPet->health.mp > 30)
			{
			 spellID = 150; //BLIZZARD II
			}
        else if (m_PPet->health.mp > 25)
			{
			 spellID = 145; //FIRE II
			}
        else if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}	
		else if (level >= 73)
		    if (m_PPet->health.mp > 134)
			{
			 spellID = 147; //FIRE IV
			}
        else if (m_PPet->health.mp > 114)
			{
			 spellID = 157; //AERO IV
			}
        else if (m_PPet->health.mp > 98)
			{
			 spellID = 172; //WATER IV
			}
        else if (m_PPet->health.mp > 87)
			{
			 spellID = 162; //STONE IV
			}
        else if (m_PPet->health.mp > 90)
			{
			 spellID = 166; //THUNDER III
			}
        else if (m_PPet->health.mp > 74)
			{
			 spellID = 151; //BLIZZARD III
			}
        else if (m_PPet->health.mp > 62)
			{
			 spellID = 146; //FIRE III
			}
        else if (m_PPet->health.mp > 53)
			{
			 spellID = 156; //AERO III
			}
        else if (m_PPet->health.mp > 45)
			{
			 spellID = 171; //WATER III
			}
        else if (m_PPet->health.mp > 39)
			{
			 spellID = 161; //STONE III
			}
        else if (m_PPet->health.mp > 36)
			{
			 spellID = 165; //THUNDER II
			}
        else if (m_PPet->health.mp > 30)
			{
			 spellID = 150; //BLIZZARD II
			}
        else if (m_PPet->health.mp > 25)
			{
			 spellID = 145; //FIRE II
			}
        else if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}	
		else if (level >= 72)
		    if (m_PPet->health.mp > 114)
			{
			 spellID = 157; //AERO IV
			}
        else if (m_PPet->health.mp > 98)
			{
			 spellID = 172; //WATER IV
			}
        else if (m_PPet->health.mp > 87)
			{
			 spellID = 162; //STONE IV
			}
        else if (m_PPet->health.mp > 90)
			{
			 spellID = 166; //THUNDER III
			}
        else if (m_PPet->health.mp > 74)
			{
			 spellID = 151; //BLIZZARD III
			}
        else if (m_PPet->health.mp > 62)
			{
			 spellID = 146; //FIRE III
			}
        else if (m_PPet->health.mp > 53)
			{
			 spellID = 156; //AERO III
			}
        else if (m_PPet->health.mp > 45)
			{
			 spellID = 171; //WATER III
			}
        else if (m_PPet->health.mp > 39)
			{
			 spellID = 161; //STONE III
			}
        else if (m_PPet->health.mp > 36)
			{
			 spellID = 165; //THUNDER II
			}
        else if (m_PPet->health.mp > 30)
			{
			 spellID = 150; //BLIZZARD II
			}
        else if (m_PPet->health.mp > 25)
			{
			 spellID = 145; //FIRE II
			}
        else if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}	
		else if (level >= 70)
		   if (m_PPet->health.mp > 98)
			{
			 spellID = 172; //WATER IV
			}
        else if (m_PPet->health.mp > 87)
			{
			 spellID = 162; //STONE IV
			}
        else if (m_PPet->health.mp > 90)
			{
			 spellID = 166; //THUNDER III
			}
        else if (m_PPet->health.mp > 74)
			{
			 spellID = 151; //BLIZZARD III
			}
        else if (m_PPet->health.mp > 62)
			{
			 spellID = 146; //FIRE III
			}
        else if (m_PPet->health.mp > 53)
			{
			 spellID = 156; //AERO III
			}
        else if (m_PPet->health.mp > 45)
			{
			 spellID = 171; //WATER III
			}
        else if (m_PPet->health.mp > 39)
			{
			 spellID = 161; //STONE III
			}
        else if (m_PPet->health.mp > 36)
			{
			 spellID = 165; //THUNDER II
			}
        else if (m_PPet->health.mp > 30)
			{
			 spellID = 150; //BLIZZARD II
			}
        else if (m_PPet->health.mp > 25)
			{
			 spellID = 145; //FIRE II
			}
        else if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}		
        else if (level >= 68)
		  if (m_PPet->health.mp > 87)
			{
			 spellID = 162; //STONE IV
			}
        else if (m_PPet->health.mp > 90)
			{
			 spellID = 166; //THUNDER III
			}
        else if (m_PPet->health.mp > 74)
			{
			 spellID = 151; //BLIZZARD III
			}
        else if (m_PPet->health.mp > 62)
			{
			 spellID = 146; //FIRE III
			}
        else if (m_PPet->health.mp > 53)
			{
			 spellID = 156; //AERO III
			}
        else if (m_PPet->health.mp > 45)
			{
			 spellID = 171; //WATER III
			}
        else if (m_PPet->health.mp > 39)
			{
			 spellID = 161; //STONE III
			}
        else if (m_PPet->health.mp > 36)
			{
			 spellID = 165; //THUNDER II
			}
        else if (m_PPet->health.mp > 30)
			{
			 spellID = 150; //BLIZZARD II
			}
        else if (m_PPet->health.mp > 25)
			{
			 spellID = 145; //FIRE II
			}
        else if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}		
        else if (level >= 66)
		   if (m_PPet->health.mp > 90)
			{
			 spellID = 166; //THUNDER III
			}
        else if (m_PPet->health.mp > 74)
			{
			 spellID = 151; //BLIZZARD III
			}
        else if (m_PPet->health.mp > 62)
			{
			 spellID = 146; //FIRE III
			}
        else if (m_PPet->health.mp > 53)
			{
			 spellID = 156; //AERO III
			}
        else if (m_PPet->health.mp > 45)
			{
			 spellID = 171; //WATER III
			}
        else if (m_PPet->health.mp > 39)
			{
			 spellID = 161; //STONE III
			}
        else if (m_PPet->health.mp > 36)
			{
			 spellID = 165; //THUNDER II
			}
        else if (m_PPet->health.mp > 30)
			{
			 spellID = 150; //BLIZZARD II
			}
        else if (m_PPet->health.mp > 25)
			{
			 spellID = 145; //FIRE II
			}
        else if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 64)
		   if (m_PPet->health.mp > 74)
			{
			 spellID = 151; //BLIZZARD III
			}
        else if (m_PPet->health.mp > 62)
			{
			 spellID = 146; //FIRE III
			}
        else if (m_PPet->health.mp > 53)
			{
			 spellID = 156; //AERO III
			}
        else if (m_PPet->health.mp > 45)
			{
			 spellID = 171; //WATER III
			}
        else if (m_PPet->health.mp > 39)
			{
			 spellID = 161; //STONE III
			}
        else if (m_PPet->health.mp > 36)
			{
			 spellID = 165; //THUNDER II
			}
        else if (m_PPet->health.mp > 30)
			{
			 spellID = 150; //BLIZZARD II
			}
        else if (m_PPet->health.mp > 25)
			{
			 spellID = 145; //FIRE II
			}
        else if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 62)
		    if (m_PPet->health.mp > 62)
			{
			 spellID = 146; //FIRE III
			}
        else if (m_PPet->health.mp > 53)
			{
			 spellID = 156; //AERO III
			}
        else if (m_PPet->health.mp > 45)
			{
			 spellID = 171; //WATER III
			}
        else if (m_PPet->health.mp > 39)
			{
			 spellID = 161; //STONE III
			}
        else if (m_PPet->health.mp > 36)
			{
			 spellID = 165; //THUNDER II
			}
        else if (m_PPet->health.mp > 30)
			{
			 spellID = 150; //BLIZZARD II
			}
        else if (m_PPet->health.mp > 25)
			{
			 spellID = 145; //FIRE II
			}
        else if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 59)
		    if (m_PPet->health.mp > 53)
			{
			 spellID = 156; //AERO III
			}
        else if (m_PPet->health.mp > 45)
			{
			 spellID = 171; //WATER III
			}
        else if (m_PPet->health.mp > 39)
			{
			 spellID = 161; //STONE III
			}
        else if (m_PPet->health.mp > 36)
			{
			 spellID = 165; //THUNDER II
			}
        else if (m_PPet->health.mp > 30)
			{
			 spellID = 150; //BLIZZARD II
			}
        else if (m_PPet->health.mp > 25)
			{
			 spellID = 145; //FIRE II
			}
        else if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 55)
		   if (m_PPet->health.mp > 45)
			{
			 spellID = 171; //WATER III
			}
        else if (m_PPet->health.mp > 39)
			{
			 spellID = 161; //STONE III
			}
        else if (m_PPet->health.mp > 36)
			{
			 spellID = 165; //THUNDER II
			}
        else if (m_PPet->health.mp > 30)
			{
			 spellID = 150; //BLIZZARD II
			}
        else if (m_PPet->health.mp > 25)
			{
			 spellID = 145; //FIRE II
			}
        else if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 51)
		   if (m_PPet->health.mp > 39)
			{
			 spellID = 161; //STONE III
			}
        else if (m_PPet->health.mp > 36)
			{
			 spellID = 165; //THUNDER II
			}
        else if (m_PPet->health.mp > 30)
			{
			 spellID = 150; //BLIZZARD II
			}
        else if (m_PPet->health.mp > 25)
			{
			 spellID = 145; //FIRE II
			}
        else if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 46)
		   if (m_PPet->health.mp > 36)
			{
			 spellID = 165; //THUNDER II
			}
        else if (m_PPet->health.mp > 30)
			{
			 spellID = 150; //BLIZZARD II
			}
        else if (m_PPet->health.mp > 25)
			{
			 spellID = 145; //FIRE II
			}
        else if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 42)
		   if (m_PPet->health.mp > 30)
			{
			 spellID = 150; //BLIZZARD II
			}
        else if (m_PPet->health.mp > 25)
			{
			 spellID = 145; //FIRE II
			}
        else if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 38)
		  if (m_PPet->health.mp > 25)
			{
			 spellID = 145; //FIRE II
			}
        else if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 34)
		   if (m_PPet->health.mp > 21)
			{
			 spellID = 155; //AERO II
			}
        else if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 30)
		   if (m_PPet->health.mp > 18)
			{
			 spellID = 170; //WATER II
			}
        else if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 26)
		   if (m_PPet->health.mp > 15)
			{
			 spellID = 160; //STONE II
			}
        else if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 21)
		   if (m_PPet->health.mp > 8)
			{
			 spellID = 164; //THUNDER I
			}
        else if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 17)
		   if (m_PPet->health.mp > 7)
			{
			 spellID = 149; //BLIZZARD I
			}
        else if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 13)
		  if (m_PPet->health.mp > 6)
			{
			 spellID = 144; //FIRE I
			}
        else if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}	
		else if (level >= 9)
		   if (m_PPet->health.mp > 5)
			{
			 spellID = 154; //AERO I
			}
        else if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}
		else if (level >= 4)
		   if (m_PPet->health.mp > 4)
			{
			 spellID = 169; //WATER I
			}
        else if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}	
	    m_LastShantottoEleCast = m_Tick;
    }			
	else 
	   {
          m_shantottoEleRecast = 20000; //ShantCast
	   }
	   m_LastShantottoMagicTime = m_Tick;
	return spellID;	
}

uint32 CAIPetDummy::ZeidSkillchain()
{
    uint32 zeidSCReady = charutils::GetVar((CCharEntity*)m_PPet->PMaster,"ZeidSCReady");	
    return zeidSCReady;
}




CBattleEntity* CAIPetDummy::getWounded(uint8 threshold)
{
    uint8 lowest = 100;
    CBattleEntity* mostWounded = nullptr;
    if (m_PPet->PMaster == nullptr)
        return nullptr;
    if (m_PPet->PMaster->GetHPP() < lowest){
        lowest = m_PPet->PMaster->GetHPP();
        mostWounded = m_PPet->PMaster;
    }
    if (m_PPet->PMaster->PPet != nullptr && m_PPet->PMaster->PPet->GetHPP() < lowest)
    {
        lowest = m_PPet->PMaster->PPet->GetHPP();
        mostWounded = m_PPet->PMaster->PPet;
    }
    if (m_PPet->PMaster->PParty != nullptr)  //Certain Trusts can't heal other members
    {
        for (auto member : m_PPet->PMaster->PParty->members)
        {
            if ( member->GetHPP() < lowest)
            {
                lowest = member->GetHPP();
                mostWounded = member;
            }
        }
    }
    if (m_PPet->PMaster->PAlly.size() > 0)  //Certain Trusts can't heal other members
    {
        for (auto ally : m_PPet->PMaster->PAlly)
        {
            if ( ally->GetHPP() < lowest)
            {
                lowest = ally->GetHPP();
                mostWounded = ally;
            }
        }
    }
    
    if (lowest <= threshold)
    {
        return mostWounded;
    }
    else
    {
        return nullptr;
    }

}

CBattleEntity* CAIPetDummy::getWoundedLow(uint8 threshold)
{
    uint8 lowest = 100;
    CBattleEntity* mostWoundedLow = nullptr;
    if (m_PPet->PMaster == nullptr)
        return nullptr;
    if (m_PPet->PMaster->GetHPP() < lowest){
        lowest = m_PPet->PMaster->GetHPP();
        mostWoundedLow = m_PPet->PMaster;
    }
    if (m_PPet->PMaster->PPet != nullptr && m_PPet->PMaster->PPet->GetHPP() < lowest)
    {
        lowest = m_PPet->PMaster->PPet->GetHPP();
        mostWoundedLow = m_PPet->PMaster->PPet;
    }
    if (m_PPet->PMaster->PParty != nullptr)  //Only Soulsoother Head can cure other Party Members
    {
        for (auto member : m_PPet->PMaster->PParty->members)
        {
            if ( member->GetHPP() < lowest)
            {
                lowest = member->GetHPP();
                mostWoundedLow = member;
            }
        }
    }
    if (m_PPet->PMaster->PAlly.size() > 0)  //Only Soulsoother Head can cure other Allies add Soulsoother Head
    {
        for (auto ally : m_PPet->PMaster->PAlly)
        {
            if ( ally->GetHPP() < lowest)
            {
                lowest = ally->GetHPP();
                mostWoundedLow = ally;
            }
        }
    }
    
    if (lowest <= threshold)
    {
        return mostWoundedLow;
    }
    else
    {
        return nullptr;
    }

}


CBattleEntity* CAIPetDummy::getWoundedAga(uint8 threshold)
{
    uint8 lowest = 31;
	uint8 allies = 0;
    CBattleEntity* mostWoundedAga = nullptr;
    if (m_PPet->PMaster == nullptr)
        return nullptr;

    if (m_PPet->PMaster->PParty != nullptr)  //For Party Members
    {
        for (auto member : m_PPet->PMaster->PParty->members)
        {
            if (member->GetHPP() < lowest)
            {
                allies += 1;
            }
        }
		if (allies >= 2)
		{
		 for (auto member : m_PPet->PMaster->PParty->members)
            {
              if ( member->GetHPP() < lowest)
               {
                lowest = member->GetHPP();
                mostWoundedAga = member;
                }
			}	
        }	
    }
    if (m_PPet->PMaster->PAlly.size() > 0)  //For Trusts
    {
        for (auto ally : m_PPet->PMaster->PAlly)
        {
            if ( ally->GetHPP() < lowest)
            {
             allies += 1;
            }
        }
	    if (allies >= 2)
        {
          for (auto ally : m_PPet->PMaster->PAlly)
            {
              if ( ally->GetHPP() < lowest)
              {
				lowest = ally->GetHPP();
                mostWoundedAga = ally;
			  }
            }
        }		
		
		
		
    }
    
    if (lowest <= threshold)
    {
        return mostWoundedAga;
    }
    else
    {
        return nullptr;
    }

}

CBattleEntity* CAIPetDummy::getTrickAttackPartner()
{
    CBattleEntity* lionTAPartner = nullptr;
	uint8 allyhp = 0;
    if (m_PPet->PMaster->PAlly.size() > 0)  // If there are other trusts in the party look for their job
    {
        for (auto ally : m_PPet->PMaster->PAlly)
        {
            if (ally->getMod(MOD_ENMITY) > 0) //This will cycle thru the trust list to see if Curilla or Gessho is in the pt
            {    
                lionTAPartner = ally;
				//allyhp = ally->GetHPP();
				//ShowWarning(CL_GREEN"CURILLA OR GESHO HP Percent is: %u \n" CL_RESET, allyhp);
				//ShowWarning(CL_GREEN"CURILLA OR GESHO IS PRESET!!!!!! \n" CL_RESET);
				break;
            }
        }
    }
    return lionTAPartner;
}


CBattleEntity* CAIPetDummy::getLionSCPartnerZeid()
{
    CBattleEntity* lionSCPartner = nullptr;
	uint8 allyhp = 0;
    if (m_PPet->PMaster->PAlly.size() > 0)  // If there are other trusts in the party look for their job
    {
        for (auto ally : m_PPet->PMaster->PAlly)
        {
            if (ally->getMod(MOD_PARALYZERES) > 0) //This will cycle thru the trust list to see if Zeid
            {    
                lionSCPartner = ally;
				allyhp = ally->GetHPP();
				//ShowWarning(CL_GREEN"ZEID IS PRESENT HP is %u \n" CL_RESET, allyhp);
				//ShowWarning(CL_GREEN"CURILLA OR GESHO IS PRESET!!!!!! \n" CL_RESET);
				break;
            }
        }
    }
    return lionSCPartner;
}


CBattleEntity* CAIPetDummy::getSleptMage()
{
    CBattleEntity* sleptMage = nullptr;
	uint8 allyhp = 0;
    if (m_PPet->PMaster->PAlly.size() > 0)  // If there are other trusts in the party look for their job
    {
        for (auto ally : m_PPet->PMaster->PAlly)
        {
            if (ally->GetMJob() == JOB_WHM) //This will cycle thru the trust list to see if a WHM is in the party and then target them
            {    
			    //ShowWarning(CL_GREEN"FOUND A WHM\n" CL_RESET);
                sleptMage = ally;
				//allyhp = ally->GetHPP();
				//ShowWarning(CL_GREEN"LION IS PRESENT HP is %u \n" CL_RESET, allyhp);
				//ShowWarning(CL_GREEN"LION IS PRESENT!!!!!! \n" CL_RESET);
				break;
            }
        }
    }
    return sleptMage;
}



CBattleEntity* CAIPetDummy::getZeidSCPartner()
{
    CBattleEntity* zeidSCPartner = nullptr;
	uint8 allyhp = 0;
    if (m_PPet->PMaster->PAlly.size() > 0)  // If there are other trusts in the party look for their job
    {
        for (auto ally : m_PPet->PMaster->PAlly)
        {
            if (ally->getMod(MOD_GRAVITYRES) > 0) //This will cycle thru the trust list to see if Lion is in the party
            {    
                zeidSCPartner = ally;
				//allyhp = ally->GetHPP();
				//ShowWarning(CL_GREEN"LION IS PRESENT HP is %u \n" CL_RESET, allyhp);
				//ShowWarning(CL_GREEN"LION IS PRESENT!!!!!! \n" CL_RESET);
				break;
            }
        }
    }
    return zeidSCPartner;
}

int16 CAIPetDummy::skillchainTimer()
{
    ShowWarning(CL_GREEN"M TICK FOR SC TIMER IS %u \n" CL_RESET, m_Tick);
	ShowWarning(CL_GREEN"Last Universal SC TIme is %u \n" CL_RESET, m_LastUniversalSCTime);
    int16 wsReady = -1;
    if (m_Tick >= m_LastUniversalSCTime + m_skillchainTimer)
	{
       wsReady = 1;
	   m_LastUniversalSCTime = m_Tick;
	   ShowWarning(CL_YELLOW"M TICK FOR SC TIMER IS %u \n" CL_RESET, m_Tick);
	   ShowWarning(CL_YELLOW"Last Universal SC TIme is %u \n" CL_RESET, m_LastUniversalSCTime);

	}


    return wsReady;
}	
	
	
	

