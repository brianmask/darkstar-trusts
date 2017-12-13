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

#include "ai_automaton_dummy.h"

#include "../mobskill.h"

#include "../entities/automatonentity.h"
#include "../entities/mobentity.h"
#include "../entities/petentity.h"

#include "../lua/luautils.h"

#include "../packets/pet_sync.h"

#include "../utils/battleutils.h"
#include "../utils/charutils.h"
#include "../utils/puppetutils.h"
#include "states/magic_state.h"
#include <stdio.h>
#include <string>     // std::string, std::stoi

CAIAutomatonDummy::CAIAutomatonDummy(CPetEntity* PPet)
    : CAIPetDummy(PPet)
{
    DSP_DEBUG_BREAK_IF(PPet->getPetType() != PETTYPE_AUTOMATON);

    CAutomatonEntity* PAutomaton = (CAutomatonEntity*)PPet;

    m_PPet = PAutomaton;
	m_PTargetFind = new CTargetFind(PAutomaton);
	m_PMagicState = new CMagicState(PAutomaton, m_PTargetFind);

    m_magicRecast = 4000;
    m_magicEnfeebleRecast = 18000;
	m_magicEnfeebCast = 0;
	m_magicDrain = 0;
	m_magicAspir = 0;

    
    m_magicHealRecast = 20000;
	m_magicHealCast = 0;
    m_magicEnhanceRecast = 0;
	m_magicEnhanceCast = 0;
	
	
    m_magicStatusRecast = 8000;
	m_magicStatusCast = 0;

	m_magicElementalRecast = 18000;
	m_magicElementCast = 0;
	
	m_rangedRecast = 2000;
	m_attachmentRecast = 5000;
	 
	m_damageGauge = 0;
	
    m_strobeRecast = 30000;
	m_bashRecast = 240000;
	m_barrageRecast = 180000;
	m_flashRecast = 50000;
	m_convertRecast = 180000;
	m_stoneskinRecast = 180000;
	
	
	
    
}

void CAIAutomatonDummy::CheckCurrentAction(uint32 tick)
{
    m_Tick = tick;

    CBattleEntity* PSelf = m_PPet;

    switch (m_ActionType)
    {
    case ACTION_NONE:							                    break;
    case ACTION_ROAMING:	            ActionRoaming();	        break;
    case ACTION_DEATH:		            ActionDeath();		        break;
    case ACTION_SPAWN:		            ActionSpawn();		        break;
	case ACTION_FALL:		            ActionFall();		        break;
    case ACTION_ENGAGE:		            ActionEngage();		        break;
    case ACTION_ATTACK:		            ActionAttack();		        break;
    case ACTION_SLEEP:		            ActionSleep();		        break;
    case ACTION_DISENGAGE:	            ActionDisengage();	        break;
    case ACTION_MOBABILITY_START:	    ActionAbilityStart();	    break;
    case ACTION_MOBABILITY_USING:       ActionAbilityUsing();       break;
    case ACTION_MOBABILITY_FINISH:      ActionAbilityFinish();      break;
    case ACTION_MOBABILITY_INTERRUPT:   ActionAbilityInterrupt();   break;
    case ACTION_MAGIC_START:            ActionMagicStart();         break;
    case ACTION_MAGIC_CASTING:          ActionMagicCasting();       break;
    case ACTION_MAGIC_FINISH:           ActionMagicFinish();        break;
	case ACTION_MAGIC_INTERRUPT:		ActionMagicInterrupt();     break;

    default: DSP_DEBUG_BREAK_IF(true);
    }

    //check if this AI was replaced (the new AI will update if this is the case)
    if (m_PPet && PSelf->PBattleAI == this)
    {
        m_PPet->UpdateEntity();
    }
}

void CAIAutomatonDummy::ActionFall()
{
   
    m_PPet->PMaster->StatusEffectContainer->RemoveAllManeuvers();

	// Remove modifiers from attachments when desummoned or all maneuvers are lost
	   m_PPet->setModifier(MOD_EVA, 0);
	   m_PPet->setModifier(MOD_DEFP, 0);
	   m_PPet->setModifier(MOD_HPP, 0);
	   m_PPet->setModifier(MOD_DOUBLE_ATTACK, 0);
	   m_PPet->setModifier(MOD_CRITHITRATE, 0);	
	   m_PPet->setModifier(MOD_MATT, 0);
	   m_PPet->setModifier(MOD_MDEF, 0);
	   m_PPet->setModifier(MOD_MPP, 0);
	   m_PPet->setModifier(MOD_RACC, 0);
	   m_PPet->setModifier(MOD_ACC, 0);
	   m_PPet->setModifier(MOD_ATTP, 0);
	   m_PPet->setModifier(MOD_RATTP, 0);
       m_PPet->setModifier(MOD_HASTE_GEAR, 0);	
	   m_PPet->setModifier(MOD_REFRESH, 0);	
	   m_PPet->setModifier(MOD_REGEN, 0);	
      	   
			
    CAIPetDummy::ActionFall();
}







void CAIAutomatonDummy::ActionSpawn()
{

    uint8 accelorator = 0;
	uint8 acceloratori = 0;
	uint8 acceloratorii = 0;
	uint8 armorplate = 0;
	uint8 armorplatei = 0;
	uint8 armorplateii = 0;
	uint8 ark = 0;
	uint8 arki = 0;
	uint8 arkii = 0; 
	uint8 coiler = 0;
	uint8 dynamo = 0;
	uint8 dynamoi = 0;
	uint8 lspeaker = 0;
	uint8 lspeakeri = 0;
	uint8 lspeakerii = 0;
	uint8 manajam = 0;
	uint8 manajami = 0;
	uint8 manajamii = 0;
	uint8 manatank = 0;
	uint8 manatanki = 0;
	uint8 manatankii = 0;
	uint8 scope = 0;
	uint8 scopei = 0;
	uint8 stab = 0;
	uint8 stabi = 0;
	uint8 stabii = 0;
	uint8 tensh = 0;
	uint8 tenshi = 0;
	uint8 tenshii = 0;
	uint8 turbo = 0;
	uint8 turboi = 0;
	uint16 strfix = 0;

	
// Attack Fix for missing calculations for STR which isn't added to battleutils.cpp

    // strfix = ((m_PPet->getModifier(MOD_STR) * 3) / 4);


//Attachment Stats are built into the core for now TODO move to lua script on activate
	if (m_PPet->hasAttachment(8513)) // Accelorator I
		{
		acceloratori = 5;		
        }
	else
	    {
		acceloratorii = 0;
		}
	if (m_PPet->hasAttachment(8516)) // Accelorator II
		{
		armorplateii = 10;		
        }
	else
	    {
		armorplateii = 0;
		}		
    if (m_PPet->hasAttachment(8546)) // Armor Plate I
		{
		armorplatei = 10;		
        }
	else
	    {
		armorplatei = 0;
		}
	if (m_PPet->hasAttachment(8548)) // Armor Plate II
		{
		armorplateii = 20;		
        }
	else
	    {
		armorplateii = 0;
		}		
	if (m_PPet->hasAttachment(8641)) // Auto Repair Kit I
		{
		arki = 4;		
        }
	else
	    {
		arki = 0;
		}
	if (m_PPet->hasAttachment(8644)) // Auto Repair Kit II
		{
		arkii = 8;		
        }
	else
	    {
		arkii = 0;
		}	
    if (m_PPet->hasAttachment(8583)) // Coiler
		{
		coiler = 3;		
        }
	else
	    {
		coiler = 0;
		}
    if (m_PPet->hasAttachment(8582)) // Dynamo
		{
		dynamoi = 3;		
        }
	else
	    {
		dynamoi = 0;
		}			
	if (m_PPet->hasAttachment(8482)) // Loudspeaker I
		{
		lspeakeri = 5;		
        }
	else
	    {
		lspeakeri = 0;
		}	
	if (m_PPet->hasAttachment(8484)) // Loudspeaker II
		{
		lspeakerii = 10;		
        }
	else
	    {
		lspeakerii = 0;
		}
	if (m_PPet->hasAttachment(8609)) // Mana Jammer I
		{
		manajami= 10;		
        }
	else
	    {
		manajami = 0;
		}	
	if (m_PPet->hasAttachment(8612)) // Mana Jammer II
		{
		manajamii = 20;		
        }
	else
	    {
		manajamii = 0;
		}		

	if (m_PPet->hasAttachment(8673)) // Mana Tank I
		{
		manatanki = 4;		
        }
	else
	    {
		manatanki = 0;
		}	
	if (m_PPet->hasAttachment(8676)) // Mana Tank II
		{
		manatankii = 8;		
        }
	else
	    {
		manatankii = 0;
		}
	if (m_PPet->hasAttachment(8514)) // Scope
		{
		stabi= 10;		
        }
	else
	    {
		stabi = 0;
		}			
	if (m_PPet->hasAttachment(8577)) // Stabilizer I
		{
		stabi= 5;		
        }
	else
	    {
		stabi = 0;
		}	
	if (m_PPet->hasAttachment(8580)) // Stabilizer II
		{
		stabii = 10;		
        }
	else
	    {
		stabii = 0;
		}
	if (m_PPet->hasAttachment(8450)) // Tension Spring I
		{
		tenshi= 3;		
        }
	else
	    {
		tenshi = 0;
		}	
	if (m_PPet->hasAttachment(8452)) // Tenshion Spring II
		{
		tenshii = 6;		
        }
	else
	    {
		tenshii = 0;
		}	
	if (m_PPet->hasAttachment(8518)) // Turbo Charger I
		{
		turboi = 5;		
        }
	else
	    {
		turboi = 0;
		}			


		
		
		
	   // Add attachment Bonuses together to provide the total before setting modifier
       accelorator = acceloratori + acceloratorii;
       armorplate = armorplatei + armorplateii;
	   //ark = arki + arkii;
	   dynamo = dynamoi;
	   lspeaker = lspeakeri + lspeakerii + 15; // Default MAB 15 on Automaton
	   manajam = manajami + manajamii;
	   manatank = manatanki + manatankii;
	   scope = scopei;
	   stab = stabi + stabii;
	   tensh = tenshi + tenshii + strfix;
		
		
		
		

	   // Sets Modifier on Activate.  If Attachment is not present, modifier is 0
	   m_PPet->setModifier(MOD_EVA, accelorator);
	   m_PPet->setModifier(MOD_DEFP, armorplate);
	   //m_PPet->setModifier(MOD_HPP, ark);
	   m_PPet->setModifier(MOD_DOUBLE_ATTACK, coiler);
	   m_PPet->setModifier(MOD_CRITHITRATE, dynamo);
	   m_PPet->setModifier(MOD_MATT, lspeaker);
	   m_PPet->setModifier(MOD_MDEF, manajam);
	   m_PPet->setModifier(MOD_MPP, manatank);
	   m_PPet->setModifier(MOD_RACC, scope);   
	   m_PPet->setModifier(MOD_ACC, stab);
	   m_PPet->setModifier(MOD_ATTP, tensh);
	   m_PPet->setModifier(MOD_RATTP, tensh);
	   m_PPet->setModifier(MOD_HASTE_GEAR, turbo);
	   m_PPet->UpdateHealth();	
			
	
      CAIPetDummy::ActionSpawn();
	 
}



void CAIAutomatonDummy::ActionAttack()
{
    if (m_PPet->PMaster == nullptr || m_PPet->PMaster->isDead() || m_PPet->isDead()){
        m_ActionType = ACTION_FALL;
        ActionFall();
        return;
    }

    //disengage a target that is dead or charmed
    if ((m_PBattleTarget == nullptr || m_PBattleTarget->isDead() ||
        m_PBattleTarget->animation == ANIMATION_CHOCOBO) ||
        (m_PBattleTarget != nullptr && m_PBattleTarget->objtype == TYPE_MOB && 
        m_PBattleTarget->PMaster != nullptr && m_PBattleTarget->PMaster->objtype == TYPE_PC))
    {
        m_ActionType = ACTION_DISENGAGE;
        ActionDisengage();
        return;
    }

	float currentDistance = distance(m_PPet->loc.p, m_PBattleTarget->loc.p);
	
	
    if (m_PPet->getFrame() == FRAME_SHARPSHOT)
        {
			if (m_Tick >= m_LastRangedTime + m_rangedRecast)
			   {
			    //m_queueSic = false;
                //m_PBattleSubTarget = m_PBattleTarget;
			  
			 for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                    
                        if (PMobSkill->getID() == 1693) { //Ranged Attack
                            SetCurrentMobSkill(PMobSkill);
                            break;
                        }
                                            
					}
				preparePetAbility(m_PBattleSubTarget);
				if (m_PPet->PMaster && m_PPet->PMaster->objtype == TYPE_PC && m_PPet->PMaster->GetMJob() == JOB_PUP)
                    {   
                        puppetutils::TrySkillUP((CAutomatonEntity*)m_PPet, SKILL_ARA, m_PBattleTarget->GetMLevel());
                    }
				m_LastRangedTime = m_Tick;
				m_rangedRecast = 18000;
                return;	
				}
				


		}
	
	

	
   	// Drum Magazine
	if (m_PPet->PMaster->StatusEffectContainer->GetEffectsCount(EFFECT_WIND_MANEUVER) == 0 && m_PPet->hasAttachment(8517)) 
		{
		m_rangedRecast = 18000;
		}
	if (m_PPet->PMaster->StatusEffectContainer->GetEffectsCount(EFFECT_WIND_MANEUVER) == 1 && m_PPet->hasAttachment(8517)) 
		{
		m_rangedRecast = 14000;
		}	
	if (m_PPet->PMaster->StatusEffectContainer->GetEffectsCount(EFFECT_WIND_MANEUVER) == 2 && m_PPet->hasAttachment(8517)) 
		{
		m_rangedRecast = 12000;
		}	
	if (m_PPet->PMaster->StatusEffectContainer->GetEffectsCount(EFFECT_WIND_MANEUVER) == 3 && m_PPet->hasAttachment(8517)) 
		{
		m_rangedRecast = 5000;
		}



	
		
        // Attachments and WS
	if (m_Tick >= m_LastAttachmentTime + m_attachmentRecast)  // 5 second check for both Attachments and TP
		{
		//First check for TP
		
		if (m_PPet->health.tp > 1000)
	        {
	         if (m_PPet->hasAttachment(8451))
		        {
			    if (m_PPet->PMaster->health.tp > 1000)
			    {
                  // now use my tp move
                  m_queueSic = false;
		          m_PBattleSubTarget = m_PBattleTarget;
                  m_ActionType = ACTION_MOBABILITY_START;
                  ActionAbilityStart();
                  return;
				}
			else
			    {
				m_LastAttachmentTime = m_Tick;
				m_LastMagicTime = m_Tick;
				}
			}
		else
            {
             // now use my tp move
             m_queueSic = false;
		     m_PBattleSubTarget = m_PBattleTarget;
             m_ActionType = ACTION_MOBABILITY_START;
             ActionAbilityStart();
             return;
            }			
				
    }	
		
		
		// Check for Attachment Abilities

		if (m_PPet->PMaster->StatusEffectContainer->GetEffectsCount(EFFECT_FIRE_MANEUVER) > 0 && m_PPet->hasAttachment(8449))   // Strobe
		{
		 if (m_Tick >= m_LastStrobeTime + m_strobeRecast)
			{
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                    
                        if (PMobSkill->getID() == 1689) { //Provoke
                            SetCurrentMobSkill(PMobSkill);
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				m_LastStrobeTime = m_Tick;
				m_LastAttachmentTime = m_Tick;
				m_LastMagicTime = m_Tick;
				return;	
				}
				
				
			}
			
	if (m_PPet->PMaster->StatusEffectContainer->GetEffectsCount(EFFECT_EARTH_MANEUVER) > 0 && m_PPet->getFrame() == FRAME_VALOREDGE && m_PPet->hasAttachment(8551))   // Hammermill
		{
		 if (m_Tick >= m_LastBashTime + m_bashRecast)
			{
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                    
                        if (PMobSkill->getID() == 1688) { //shield bash
                            SetCurrentMobSkill(PMobSkill);
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				m_LastBashTime = m_Tick;
				m_LastAttachmentTime = m_Tick;
				m_LastMagicTime = m_Tick;
				return;	
				}
				
				
			}
		if (m_PPet->PMaster->StatusEffectContainer->GetEffectsCount(EFFECT_WIND_MANEUVER) > 0 && m_PPet->getFrame() == FRAME_SHARPSHOT && m_PPet->hasAttachment(8520))   // Barrage Turbine
		{
		 if (m_Tick >= m_LastBarrageTime + m_barrageRecast)
			{
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                    
                        if (PMobSkill->getID() == 1178) { //BarrageTurbine
                            SetCurrentMobSkill(PMobSkill);
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				if (m_PPet->PMaster && m_PPet->PMaster->objtype == TYPE_PC && m_PPet->PMaster->GetMJob() == JOB_PUP)
                    {
                        puppetutils::TrySkillUP((CAutomatonEntity*)m_PPet, SKILL_ARA, m_PBattleTarget->GetMLevel());
                    }
				m_LastBarrageTime = m_Tick;
				m_LastAttachmentTime = m_Tick;
				m_LastMagicTime = m_Tick;
				return;	
				}
				
				
			}
			
		if (m_PPet->PMaster->StatusEffectContainer->GetEffectsCount(EFFECT_LIGHT_MANEUVER) > 0 && m_PPet->hasAttachment(8642))   // Flashbulb
		{
		 if (m_Tick >= m_LastFlashTime + m_flashRecast)
			{
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                    
                        if (PMobSkill->getID() == 1691) { //Flash
                            SetCurrentMobSkill(PMobSkill);
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				m_LastFlashTime = m_Tick;
				m_LastAttachmentTime = m_Tick;
				m_LastMagicTime = m_Tick;
				return;	
				}
				
				
			}
			
			
				
		if (m_PPet->PMaster->StatusEffectContainer->GetEffectsCount(EFFECT_DARK_MANEUVER) > 0 && m_PPet->hasAttachment(8674))   // Mana Converter
		{
		 if (m_Tick >= m_LastConvertTime + m_convertRecast)
			{
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                    
                        if (PMobSkill->getID() == 1692) { //Convert
                            SetCurrentMobSkill(PMobSkill);
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				m_LastConvertTime = m_Tick;
				m_LastAttachmentTime = m_Tick;
				m_LastMagicTime = m_Tick;
				return;	
				}
				
				
			}
			
		if (m_PPet->PMaster->StatusEffectContainer->GetEffectsCount(EFFECT_EARTH_MANEUVER) > 0 && m_PPet->hasAttachment(8545))   // Shock Abosrber
		{
		 if (m_Tick >= m_LastStoneskinTime + m_stoneskinRecast)
			{
			for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                    
                        if (PMobSkill->getID() == 1690) { //Stoneskin
                            SetCurrentMobSkill(PMobSkill);
							break;
                        }
			        }
				preparePetAbility(m_PBattleSubTarget);
				m_LastStoneskinTime = m_Tick;
				m_LastAttachmentTime = m_Tick;
				m_LastMagicTime = m_Tick;
				return;	
				}	
			}			
		}
		
	

		
	if (m_PPet->getFrame() == FRAME_HARLEQUIN)
        {
			int16 spellID = -1;
			if (m_Tick >= m_LastMagicTime + m_magicRecast) // Check Every 4 Seconds as universal check
			{
				uint16 family = m_PPet->m_Family;
				uint16 petID = m_PPet->m_PetID;
        
		
				spellID = HarleAttack();
		
				if (spellID != -1)
				{
				SetCurrentSpell(spellID);
				m_ActionType = ACTION_MAGIC_START;
				ActionMagicStart();
				return;
			}
		}

		   
		}	
		

//Stormwaker Frame and Soulsoother Head		
    if (m_PPet->getFrame() == FRAME_STORMWAKER && m_PPet->getHead() == HEAD_SOULSOOTHER)
        {
			int16 spellID = -1;
			if (m_Tick >= m_LastMagicTime + m_magicRecast) // Check Every 4 Seconds as universal check
			{
				uint16 family = m_PPet->m_Family;
				uint16 petID = m_PPet->m_PetID;
        
		
				spellID = StormFrameSoulAttack();
		
				if (spellID != -1)
				{
				SetCurrentSpell(spellID);
				m_ActionType = ACTION_MAGIC_START;
				ActionMagicStart();
				return;
			}
		}

		   
		}	

//Stormwaker Frame and Stormwaker Head		
    if (m_PPet->getFrame() == FRAME_STORMWAKER && m_PPet->getHead() == HEAD_STORMWAKER)
        {
			int16 spellID = -1;
			if (m_Tick >= m_LastMagicTime + m_magicRecast) // Check Every 4 Seconds as universal check
			{
				uint16 family = m_PPet->m_Family;
				uint16 petID = m_PPet->m_PetID;
        
		
				spellID = StormFrameStormAttack();
		
				if (spellID != -1)
				{
				SetCurrentSpell(spellID);
				m_ActionType = ACTION_MAGIC_START;
				ActionMagicStart();
				return;
			}
		}

		   
		}			
		
		

//Stormwaker Frame and Spiritreaver Head		
    if (m_PPet->getFrame() == FRAME_STORMWAKER && m_PPet->getHead() == HEAD_SPIRITREAVER)
        {
			int16 spellID = -1;
			if (m_Tick >= m_LastMagicTime + m_magicRecast) // Check Every 4 Seconds as universal check
			{
				uint16 family = m_PPet->m_Family;
				uint16 petID = m_PPet->m_PetID;
        
		
				spellID = StormFrameSpiritAttack();
		
				if (spellID != -1)
				{
				SetCurrentSpell(spellID);
				m_ActionType = ACTION_MAGIC_START;
				ActionMagicStart();
				return;
			}
		}

		   
		}			
				
	
	
	
		
	
	
	
		
	
    m_PPathFind->LookAt(m_PBattleTarget->loc.p);


   // if (CheckSpellcast())
   // {
   //     m_ActionType = ACTION_MAGIC_START;
   //     ActionMagicStart();
   //     return;
  //  }
  
   // if (CheckTPMove())
   // {
        //TODO: check if automaton WS have activation times (don't think so)
   //     m_ActionType = ACTION_MOBABILITY_FINISH;
    //    ActionAbilityFinish();
   //     return;
  //  }
   // else if (CheckRangedAttack())
  //  {
        //TODO: set ID to ranged attack
   //     m_ActionType = ACTION_MOBABILITY_FINISH;
   //     ActionAbilityFinish();
   //     m_LastRangedTime = m_Tick;
     //   return;
   // }

   
   
    // Create temporary distance calculation to keep specific Automatons at a distance.  
	// This Hack is only temporary so Sharpshot and Harlequin stay where they are deployed		
    //go to target if its too far away
	if (currentDistance > 15 && m_PPet->speed != 0 && m_PPet->getHead() == HEAD_SHARPSHOT)
    {
        if (m_PPathFind->PathAround(m_PBattleTarget->loc.p, 2.0f, PATHFLAG_RUN | PATHFLAG_WALLHACK))
        {
            m_PPathFind->FollowPath();

            // recalculate
            currentDistance = distance(m_PPet->loc.p, m_PBattleTarget->loc.p);
        }
    }
	
    if (currentDistance > 15 && m_PPet->speed != 0 && m_PPet->getHead() == HEAD_HARLEQUIN)
    {
        if (m_PPathFind->PathAround(m_PBattleTarget->loc.p, 2.0f, PATHFLAG_RUN | PATHFLAG_WALLHACK))
        {
            m_PPathFind->FollowPath();

            // recalculate
            currentDistance = distance(m_PPet->loc.p, m_PBattleTarget->loc.p);
        }
    }
	
	
	if (currentDistance > m_PBattleTarget->m_ModelSize && m_PPet->speed != 0 && m_PPet->getHead() == HEAD_HARLEQUIN && m_PPet->health.mp < 8)
    {
        if (m_PPathFind->PathAround(m_PBattleTarget->loc.p, 2.0f, PATHFLAG_RUN | PATHFLAG_WALLHACK))
        {
            m_PPathFind->FollowPath();

            // recalculate
            currentDistance = distance(m_PPet->loc.p, m_PBattleTarget->loc.p);
        }
    }
	
	
	
	
	if (currentDistance > m_PBattleTarget->m_ModelSize && m_PPet->speed != 0 && m_PPet->getHead() == HEAD_VALOREDGE)
    {
        if (m_PPathFind->PathAround(m_PBattleTarget->loc.p, 2.0f, PATHFLAG_RUN | PATHFLAG_WALLHACK))
        {
            m_PPathFind->FollowPath();

            // recalculate
            currentDistance = distance(m_PPet->loc.p, m_PBattleTarget->loc.p);
        }
    }
	
	
    if (currentDistance <= m_PBattleTarget->m_ModelSize)
    {
        int32 WeaponDelay = m_PPet->m_Weapons[SLOT_MAIN]->getDelay();
        //try to attack
        if (m_Tick > m_LastActionTime + WeaponDelay){
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

                for (uint8 i = 0; i<numAttacks; i++){
                    Action.reaction = REACTION_EVADE;
                    Action.speceffect = SPECEFFECT_NONE;
                    Action.animation = 0;
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

                            damage = (int32)((m_PPet->GetMainWeaponDmg() + battleutils::GetFSTR(m_PPet, m_PBattleTarget, SLOT_MAIN)) * DamageRatio);
                        }
                    }
                    else
                    {
                        // create enmity even on misses
                        if (m_PBattleTarget->objtype == TYPE_MOB){
                            CMobEntity* PMob = (CMobEntity*)m_PBattleTarget;
                            PMob->PEnmityContainer->UpdateEnmity(m_PPet, 0, 0);
                        }
                    }

                    if (m_PBattleTarget->objtype == TYPE_PC)
                    {
                        charutils::TrySkillUP((CCharEntity*)m_PBattleTarget, SKILL_EVA, m_PPet->GetMLevel());
                    }

                    if (m_PPet->PMaster && m_PPet->PMaster->objtype == TYPE_PC && m_PPet->PMaster->GetMJob() == JOB_PUP)
                    {
                        puppetutils::TrySkillUP((CAutomatonEntity*)m_PPet, SKILL_AME, m_PBattleTarget->GetMLevel());
                    }
					

                    bool isBlocked = (dsprand::GetRandomNumber(100) < battleutils::GetBlockRate(m_PPet, m_PBattleTarget));
                    if (isBlocked){ Action.reaction = REACTION_BLOCK; }


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

                if (m_PPet->PMaster != nullptr && m_PPet->PMaster->objtype == TYPE_PC && m_PPet->PMaster->PPet != nullptr){
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



void CAIAutomatonDummy::ActionAbilityStart()
{
	DSP_DEBUG_BREAK_IF(m_PBattleSubTarget == nullptr);
    m_LastActionTime = m_Tick;
	uint16 raskill = m_PPet->PMaster->GetSkill(SKILL_ARA);
	uint16 hskill = m_PPet->PMaster->GetSkill(SKILL_AME);

	
	//Needs Distance Checks for non Range
	
	
	if (m_PPet->health.tp >= 1000 && m_PBattleTarget != nullptr) { //Choose TP Move if Inhibitor is not present
	
	 if (m_PPet->getFrame() == FRAME_STORMWAKER || m_PPet->getFrame() == FRAME_HARLEQUIN){
			 for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                    
					    if (PMobSkill->getID() == 1687 &&
                            hskill < 145 && distance(m_PBattleTarget->loc.p,m_PPet->loc.p) < PMobSkill->getDistance()) { //Slapstick
                            SetCurrentMobSkill(PMobSkill);
                            break;
                        } 
						else if (PMobSkill->getID() == 1811 &&
                            hskill < 225 && distance(m_PBattleTarget->loc.p,m_PPet->loc.p) < PMobSkill->getDistance()) {  //Knockout
                            SetCurrentMobSkill(PMobSkill);
                            break;
                        }
                        else if (PMobSkill->getID() == 2045 &&
                            hskill >= 224 && distance(m_PBattleTarget->loc.p,m_PPet->loc.p) < PMobSkill->getDistance()) {  //Magic Mortar
                            SetCurrentMobSkill(PMobSkill);
                            break;
                        }
                    
					}
					if (m_PPet->PMaster && m_PPet->PMaster->objtype == TYPE_PC && m_PPet->PMaster->GetMJob() == JOB_PUP)
                    {
                        puppetutils::TrySkillUP((CAutomatonEntity*)m_PPet, SKILL_AME, m_PBattleTarget->GetMLevel());
                    }
				}
				
				
	
	
	
	
             
			 if (m_PPet->getFrame() == FRAME_SHARPSHOT){
			 
			 for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                    
						if (PMobSkill->getID() == 1686 &&
                            raskill < 150) { //Acruballista
                            SetCurrentMobSkill(PMobSkill);
                            break;
                        }
						else if (PMobSkill->getID() == 1810 &&
                            raskill < 245) { //Daze
                            SetCurrentMobSkill(PMobSkill);
                            break;
                        }	
						else if (PMobSkill->getID() == 2044 &&
                            raskill >= 245) { //Armor Piercer
                            SetCurrentMobSkill(PMobSkill);
							PMobSkill->setSkillchain(13);
                            break;
                        }
					}
					if (m_PPet->PMaster && m_PPet->PMaster->objtype == TYPE_PC && m_PPet->PMaster->GetMJob() == JOB_PUP)
                    {
                    puppetutils::TrySkillUP((CAutomatonEntity*)m_PPet, SKILL_ARA, m_PBattleTarget->GetMLevel());
                    }	
				}
				
			else if (m_PPet->getFrame() == FRAME_VALOREDGE){
			 for (int i = 0; i < m_PPet->PetSkills.size(); i++) {
                    auto PMobSkill = battleutils::GetMobSkill(m_PPet->PetSkills.at(i));
                    
                                              if (PMobSkill->getID() == 1685 &&
                            hskill < 150) { //String Clipper
                            SetCurrentMobSkill(PMobSkill);
                            break;
                        }
						else if (PMobSkill->getID() == 1684 &&
                            hskill < 150 &&
							m_PPet->PMaster->StatusEffectContainer->HasStatusEffect(EFFECT_FIRE_MANEUVER)) { //Force Chimera Ripper
                            SetCurrentMobSkill(PMobSkill);
                            break;
                        }
                        else if (PMobSkill->getID() == 1809 &&
                            hskill < 244) { //Cannibal Blade
                            SetCurrentMobSkill(PMobSkill);
                            break;
                        }
                        else if (PMobSkill->getID() == 2043 &&
                            hskill >= 245) { //Bone Crusher
                            SetCurrentMobSkill(PMobSkill);
                            break;
                        }
                    
					}
					if (m_PPet->PMaster && m_PPet->PMaster->objtype == TYPE_PC && m_PPet->PMaster->GetMJob() == JOB_PUP)
                    {
                        puppetutils::TrySkillUP((CAutomatonEntity*)m_PPet, SKILL_AME, m_PBattleTarget->GetMLevel());
                    }
				}
				
				
				
                preparePetAbility(m_PBattleSubTarget);
                return;
            }

			
		
		   TransitionBack(true);
}





void CAIAutomatonDummy::ActionAbilityFinish() {
    DSP_DEBUG_BREAK_IF(m_PMobSkill == nullptr);
    DSP_DEBUG_BREAK_IF(m_PBattleSubTarget == nullptr);

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
    m_PMobSkill->setTP(m_skillTP);

    uint16 animationId;
    if (m_PPet->getPetType() == PETTYPE_AVATAR)
    {
        // TODO: this is totally a hack
        // override mob animation ids with valid pet animation id
        // pets need their own skills
       // animationId = m_PMobSkill->getAvatarAnimationID();
    }
    else
    {
        animationId = m_PMobSkill->getAnimationID();
    }
    

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

  

    m_PBattleSubTarget = nullptr;
    m_ActionType = ACTION_ATTACK;
}



void CAIAutomatonDummy::ActionMagicStart()
{
    // disabled
    // DSP_DEBUG_BREAK_IF(m_PSpell == nullptr);
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

void CAIAutomatonDummy::ActionMagicCasting()
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

void CAIAutomatonDummy::ActionMagicFinish()
{
    m_LastActionTime = m_Tick;
    m_LastMagicTime = m_Tick;
	if (m_magicHealCast == 1)
	{
	m_LastMagicTimeHeal = m_Tick;  // set cast attempt to mtick because it finished the spell
	m_magicHealCast = 0;
	}
	
	if (m_magicEnfeebCast == 1)
	{
	m_LastMagicTimeEnf = m_Tick;
	m_magicEnfeebCast = 0;
	}
	
	if (m_magicStatusCast == 1)
	{
	m_LastMagicTimeStatus = m_Tick;
	m_magicStatusCast = 0;
	}

	if (m_magicElementCast == 1)
	{
	m_LastMagicTimeEle = m_Tick;
	m_magicElementCast = 0;
	}
	
    m_PMagicState->FinishSpell();

    m_PSpell = nullptr;
    m_PBattleSubTarget = nullptr;

		if (m_PPet->PMaster && m_PPet->PMaster->objtype == TYPE_PC && m_PPet->PMaster->GetMJob() == JOB_PUP)
		
		{
         puppetutils::TrySkillUP((CAutomatonEntity*)m_PPet, SKILL_AMA, m_PBattleTarget->GetMLevel());
        }	
		

    TransitionBack();
}

void CAIAutomatonDummy::ActionMagicInterrupt()
{
    m_LastActionTime = m_Tick;
    m_LastMagicTime = m_Tick;

    m_PMagicState->InterruptSpell();

    m_PSpell = nullptr;
    m_PBattleSubTarget = nullptr;

    TransitionBack();
}



bool CAIAutomatonDummy::CheckSpellcast()
{
    return false;
}

bool CAIAutomatonDummy::CheckTPMove()
{
    //TODO: range checks
    if (m_PPet->health.tp > 1000)
    {
        const std::vector<uint16>& FamilySkills = battleutils::GetMobSkillList(m_PPet->m_Family);

        std::map<uint16, CMobSkill*> validSkills;

        //load the skills that the automaton has access to with it's skill
        SKILLTYPE skilltype = SKILL_AME;

        if (m_PPet->getFrame() == FRAME_SHARPSHOT)
        {
            skilltype = SKILL_ARA;
        }

        for (auto skillid : FamilySkills)
        {
            auto PSkill = battleutils::GetMobSkill(skillid);
            if (PSkill && m_PPet->PMaster && m_PPet->PMaster->GetSkill(skilltype) > PSkill->getParam() && PSkill->getParam() != -1)
            {
                validSkills.insert(std::make_pair(m_PPet->PMaster->GetSkill(skilltype), PSkill));
            }
        }

        uint16 currentSkill = 0;
        int8 currentManeuvers = -1;
        for (auto PSkill : validSkills)
        {
            int8 maneuvers = luautils::OnMobAutomatonSkillCheck(m_PBattleSubTarget, m_PPet, PSkill.second);
            if ( maneuvers > -1 && (maneuvers > currentManeuvers || (maneuvers == currentManeuvers && PSkill.first > currentSkill)))
            {
                SetCurrentMobSkill(PSkill.second);
                m_PBattleSubTarget = m_PBattleTarget;
                currentManeuvers = maneuvers;
                currentSkill = PSkill.first;
            }
        }

        // No WS was chosen (waiting on master's TP to skillchain probably)
        if (currentManeuvers == -1)
        {
            return false;
        }
        m_LastActionTime = m_Tick;
        m_PPathFind->LookAt(m_PBattleSubTarget->loc.p);
        m_skillTP = m_PPet->health.tp;
        m_PPet->health.tp = 0;

        return true;
    }
    return false;
}

bool CAIAutomatonDummy::CheckRangedAttack()
{
    return false;
}

void CAIAutomatonDummy::TransitionBack(bool skipWait /*= false*/)
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


void CAIAutomatonDummy::ActionRoaming()
{
    if (m_PPet->PMaster == nullptr || m_PPet->PMaster->isDead()) {
        m_ActionType = ACTION_FALL;
        ActionFall();
        return;
    }

    //automaton, wyvern
    if (m_PPet->getPetType() == PETTYPE_WYVERN || m_PPet->getPetType() == PETTYPE_AUTOMATON) {
        if (PetIsHealing()) {
            return;
        }
    }
	charutils::UpdateHealth((CCharEntity*)m_PPet->PMaster);
	
	
    if (m_PBattleTarget != nullptr) {
        m_ActionType = ACTION_ENGAGE;
        ActionEngage();
        return;
    }
	//ShowWarning(CL_RED"PET IS ACTION ROAMING\n" CL_RESET);
    //((CCharEntity*)m_PPet->PMaster)->pushPacket(new CCharHealthPacket((CCharEntity*)m_PPet->PMaster));
    float currentDistance = distance(m_PPet->loc.p, m_PPet->PMaster->loc.p);



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

}




// Harlequin Automaton AI


int16 CAIAutomatonDummy::HarleAttack()
{
	uint8 requiredHPP = 75;
	uint8 lowHPP = 31;
	uint8 level = m_PPet->GetMLevel();
	uint8 trigger = 30;
	uint16 mskill = m_PPet->PMaster->GetSkill(SKILL_AMA);
	uint16 maskill = m_PPet->PMaster->GetSkill(SKILL_AMA);
	
    int16 spellID = -1;
    CBattleEntity* master = m_PPet->PMaster;  
	//calculate curing threshold based on Light Maneuvers
	if (m_PPet->PMaster->StatusEffectContainer->GetEffectsCount(EFFECT_LIGHT_MANEUVER) == 1) 
		{
		trigger = 40;
		}
	else if (m_PPet->PMaster->StatusEffectContainer->GetEffectsCount(EFFECT_LIGHT_MANEUVER) == 2) 
		{
		trigger = 50;
		}
	else if (m_PPet->PMaster->StatusEffectContainer->GetEffectsCount(EFFECT_LIGHT_MANEUVER) == 3) 
		{
		trigger = 75;
		}
	else if (m_PPet->hasAttachment(8643))
		{
		trigger = 50;
		}	
	else
		{
		trigger = 30;
	    }
	//calculate attachments
	
	if (m_PPet->hasAttachment(8643))
		{
		 m_damageGauge = 6000;
		}
	else
		{
		 m_damageGauge = 0;
		}
	
	
    CBattleEntity* mostWounded = getWounded(trigger);
    //CBattleEntity* mostWounded = m_PPet;
	// Enhancing Spells
	

	if (m_Tick >= m_LastMagicTimeHeal + m_magicHealRecast)  // Look for last magic healing spell time 
	{
		if (mostWounded != nullptr)
		{
        m_PBattleSubTarget = mostWounded;
		 if (mskill > 146)
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
		else if (mskill > 80)
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
		else if (mskill > 44)
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
		else if (mskill > 11)
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
		
        m_magicHealRecast = 25000 - m_damageGauge;
		m_magicHealCast = 1; // 1 means casting a spell
		}
		else
		{
		m_LastMagicTimeHeal = m_Tick; // reset mtick
		m_magicHealRecast = 18000;		
       }
	}
	
	
	
	else if (m_Tick >= m_LastMagicTimeEnf + m_magicEnfeebleRecast)  // Look for last enfeeble spell time 
	{
	  if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_DIA) == false && m_PBattleTarget->GetHPP() >= requiredHPP)
	{
		m_PBattleSubTarget = m_PBattleTarget;
        if (mskill >= 96)
		    if (m_PPet->health.mp > 30)  	
			    {
				 spellID = 24;
				}
		    else if (m_PPet->health.mp >= 7)  	
			    {
				 spellID = 23;
				}
            else
			    {
				 spellID = -1;
				}
        else if (mskill >= 0)
		    if (m_PPet->health.mp >= 7)  	
			    {
				 spellID = 23;
				}
            else 
			    {
				 spellID = -1;
				}
		m_magicEnfeebCast = 1;
		m_magicEnfeebleRecast = 18000;
        
	}
	    else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_POISON) == false && m_PBattleTarget->GetHPP() >= requiredHPP) 
	{
	   m_PBattleSubTarget = m_PBattleTarget;
		// m_magicRecast = 5000;
        if (mskill > 17)
		    if (m_PPet->health.mp >= 5)  	
			    {
				 spellID = 220;
				}
            else
			    {
				 spellID = -1;
				} 
        m_magicEnfeebCast = 1;
		m_magicEnfeebleRecast = 18000;
	
	}
	    else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_PARALYSIS) == false && m_PBattleTarget->GetHPP() >= requiredHPP) 
	{
	   m_PBattleSubTarget = m_PBattleTarget;
		// m_magicRecast = 5000;
        if (mskill > 20)
		    if (m_PPet->health.mp >= 6)  	
			    {
				 spellID = 58;
				}
             else
			    {
				 spellID = -1;
				} 
        m_magicEnfeebCast = 1;
		m_magicEnfeebleRecast = 18000;
	
	}
	    else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_BLINDNESS) == false && m_PBattleTarget->GetHPP() >= requiredHPP) 
	{
	   m_PBattleSubTarget = m_PBattleTarget;
		// m_magicRecast = 5000;
        if (mskill > 41)
		    if (m_PPet->health.mp >= 5)  	
			    {
				 spellID = 254;
				}
            else
			    {
				 spellID = -1;
				} 
        m_magicEnfeebCast = 1;
		m_magicEnfeebleRecast = 18000;
	
	}
	

    else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_SLOW) == false && m_PBattleTarget->GetHPP() >= requiredHPP) 
	{
	   m_PBattleSubTarget = m_PBattleTarget;
		// m_magicRecast = 5000;
        if (mskill > 41)
		    if (m_PPet->health.mp >= 15)  	
			    {
				 spellID = 56;
				}
             else
			    {
				 spellID = -1;
				} 
        m_magicEnfeebCast = 1;
		m_magicEnfeebleRecast = 18000;
	
	}
	
	  else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == false && m_PBattleTarget->GetHPP() >= requiredHPP) 
	{
	   m_PBattleSubTarget = m_PBattleTarget;
		// m_magicRecast = 5000;
        if (mskill > 56)
		    if (m_PPet->health.mp >= 16)  	
			    {
				 spellID = 59;
				}
            else
			    {
				 spellID = -1;
				} 
        m_magicEnfeebCast = 1;
		m_magicEnfeebleRecast = 18000;
	
	}
	
	else
	{
		m_LastMagicTimeEnf = m_Tick; // reset mtick
		m_magicEnfeebleRecast = 30000; // No eligible Debuffs
	}	
	}

	
	return spellID;
}


// Stormwaker Frame/Soulsoother Head Automaton AI (WHM)


int16 CAIAutomatonDummy::StormFrameSoulAttack()
{
	uint8 requiredHPP = 75;  // Enfeebling Threshold
	uint8 lowHPP = 31;
	uint8 level = m_PPet->GetMLevel();
	uint8 trigger = 40;
	uint8 lowtrigger = 30;
	uint16 mskill = m_PPet->PMaster->GetSkill(SKILL_AMA);
	uint16 maskill = m_PPet->PMaster->GetSkill(SKILL_AMA);
	
    int16 spellID = -1;
    CBattleEntity* master = m_PPet->PMaster;  
	//calculate curing threshold based on Light Maneuvers
	if (m_PPet->PMaster->StatusEffectContainer->GetEffectsCount(EFFECT_LIGHT_MANEUVER) == 1) 
		{
		trigger = 40;
		}
	else if (m_PPet->PMaster->StatusEffectContainer->GetEffectsCount(EFFECT_LIGHT_MANEUVER) == 2) 
		{
		trigger = 50;
		}
	else if (m_PPet->PMaster->StatusEffectContainer->GetEffectsCount(EFFECT_LIGHT_MANEUVER) == 3) 
		{
		trigger = 75;
		}
	else if (m_PPet->hasAttachment(8643))
		{
		trigger = 50;
		}	
	else if (m_PPet->hasAttachment(8643) && m_PPet->PMaster->StatusEffectContainer->GetEffectsCount(EFFECT_LIGHT_MANEUVER) == 1)
		{
		trigger = 60;
		}
	else if (m_PPet->hasAttachment(8643) && m_PPet->PMaster->StatusEffectContainer->GetEffectsCount(EFFECT_LIGHT_MANEUVER) == 2)
		{
		trigger = 70;
		}	
	else if (m_PPet->hasAttachment(8643) && m_PPet->PMaster->StatusEffectContainer->GetEffectsCount(EFFECT_LIGHT_MANEUVER) == 3)
		{
		trigger = 80;
		}		
	else
		{
		trigger = 30;
	    }
	//calculate attachments
	
	if (m_PPet->hasAttachment(8643))
		{
		 m_damageGauge = 2000; // Prioritiezes Cures by making its counter 2 seconds faster 
		}
	else
		{
		 m_damageGauge = 0;
		}
	
	
    CBattleEntity* mostWounded = getWounded(trigger);
	CBattleEntity* mostWoundedLow = getWounded(lowtrigger);
    //CBattleEntity* mostWounded = m_PPet;
	// Enhancing Spells
	// Order is Protect > Shell > Haste (if Wind Maneuver is up)
	
	if (m_Tick >= m_LastMagicTimeEnhance + m_magicEnhanceRecast) 
		{
		if (m_PPet->PMaster->StatusEffectContainer->HasStatusEffect(EFFECT_PROTECT) == false) 
			{
			m_PBattleSubTarget = m_PPet->PMaster;
			if (mskill > 280)
				if (m_PPet->health.mp > 83)
					{
					 spellID = 47;
					}
				else if (m_PPet->health.mp > 64)
					{
					 spellID = 46;
					}
				else if (m_PPet->health.mp > 45)
					{
					 spellID = 45;
					}
				else if (m_PPet->health.mp > 27)
					{
					 spellID = 44;
					}
				else if (m_PPet->health.mp > 8)
					{
					 spellID = 43;
					}
				else 
			        {
				     spellID = -1;
				    }
			else if (mskill > 216)
				if (m_PPet->health.mp > 64)
					{
					 spellID = 46;
					}
				else if (m_PPet->health.mp > 45)
					{
					 spellID = 45;
					}
				else if (m_PPet->health.mp > 27)
					{
					 spellID = 44;
					}
				else if (m_PPet->health.mp > 8)
					{
					 spellID = 43;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else if (mskill > 143)
				if (m_PPet->health.mp > 45)
					{
					 spellID = 45;
					}
				else if (m_PPet->health.mp > 27)
					{
					 spellID = 44;
					}
				else if (m_PPet->health.mp > 8)
					{
					 spellID = 43;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else if (mskill > 83)
				if (m_PPet->health.mp > 27)
					{
					 spellID = 44;
					}
				else if (m_PPet->health.mp > 8)
					{
					 spellID = 43;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else if (mskill > 23)
				if (m_PPet->health.mp > 8)
					{
					 spellID = 43;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else
		        {
				 spellID = -1;
				} 
			m_magicEnhanceCast = 1;
			m_magicEnhanceRecast = 15000;
			}
		else if (m_PPet->PMaster->StatusEffectContainer->HasStatusEffect(EFFECT_SHELL) == false) 
			{
			m_PBattleSubTarget = m_PPet->PMaster;
			if (mskill > 240)
				if (m_PPet->health.mp > 74)
					{
					 spellID = 51;
					}
				else if (m_PPet->health.mp > 55)
					{
					 spellID = 50;
					}
				else if (m_PPet->health.mp > 36)
					{
					 spellID = 49;
					}
				else if (m_PPet->health.mp > 17)
					{
					 spellID = 48;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else if (mskill > 187)
				if (m_PPet->health.mp > 55)
					{
					 spellID = 50;
					}
				else if (m_PPet->health.mp > 36)
					{
					 spellID = 49;
					}
				else if (m_PPet->health.mp > 17)
					{
					 spellID = 48;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else if (mskill > 113)
				if (m_PPet->health.mp > 36)
					{
					 spellID = 49;
					}
				else if (m_PPet->health.mp > 17)
					{
					 spellID = 48;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else if (mskill > 53)
				if (m_PPet->health.mp > 17)
					{
					 spellID = 48;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else
		        {
				 spellID = -1;
				} 
			m_magicEnhanceCast = 1;
			m_magicEnhanceRecast = 15000;
			}
		else if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_PROTECT) == false) //cast pro on self
			{
			ShowWarning(CL_RED"AUTO: PET doesn't have protect!!! \n", CL_RESET);
			m_PBattleSubTarget = m_PPet;
			if (mskill > 280)
				if (m_PPet->health.mp > 83)
					{
					 spellID = 47;
					}
				else if (m_PPet->health.mp > 64)
					{
					 spellID = 46;
					}
				else if (m_PPet->health.mp > 45)
					{
					 spellID = 45;
					}
				else if (m_PPet->health.mp > 27)
					{
					 spellID = 44;
					}
				else if (m_PPet->health.mp > 8)
					{
					 spellID = 43;
					}
				else 
			        {
				     spellID = -1;
				    }
			else if (mskill > 216)
				if (m_PPet->health.mp > 64)
					{
					 spellID = 46;
					}
				else if (m_PPet->health.mp > 45)
					{
					 spellID = 45;
					}
				else if (m_PPet->health.mp > 27)
					{
					 spellID = 44;
					}
				else if (m_PPet->health.mp > 8)
					{
					 spellID = 43;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else if (mskill > 143)
				if (m_PPet->health.mp > 45)
					{
					 spellID = 45;
					}
				else if (m_PPet->health.mp > 27)
					{
					 spellID = 44;
					}
				else if (m_PPet->health.mp > 8)
					{
					 spellID = 43;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else if (mskill > 83)
				if (m_PPet->health.mp > 27)
					{
					 spellID = 44;
					}
				else if (m_PPet->health.mp > 8)
					{
					 spellID = 43;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else if (mskill > 23)
				if (m_PPet->health.mp > 8)
					{
					 spellID = 43;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else
		        {
				 spellID = -1;
				} 
			m_magicEnhanceCast = 1;
			m_magicEnhanceRecast = 15000;
			}
		else if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SHELL) == false) // Cast Shell on Self
			{
			m_PBattleSubTarget = m_PPet;
			if (mskill > 240)
				if (m_PPet->health.mp > 74)
					{
					 spellID = 51;
					}
				else if (m_PPet->health.mp > 55)
					{
					 spellID = 50;
					}
				else if (m_PPet->health.mp > 36)
					{
					 spellID = 49;
					}
				else if (m_PPet->health.mp > 17)
					{
					 spellID = 48;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else if (mskill > 187)
				if (m_PPet->health.mp > 55)
					{
					 spellID = 50;
					}
				else if (m_PPet->health.mp > 36)
					{
					 spellID = 49;
					}
				else if (m_PPet->health.mp > 17)
					{
					 spellID = 48;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else if (mskill > 113)
				if (m_PPet->health.mp > 36)
					{
					 spellID = 49;
					}
				else if (m_PPet->health.mp > 17)
					{
					 spellID = 48;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else if (mskill > 53)
				if (m_PPet->health.mp > 17)
					{
					 spellID = 48;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else
		        {
				 spellID = -1;
				} 
			m_magicEnhanceCast = 1;
			m_magicEnhanceRecast = 15000;
			}	
		else if (m_PPet->PMaster->GetHPP() > 65 && m_PPet->PMaster->GetHPP() < 95 && m_PPet->PMaster->StatusEffectContainer->HasStatusEffect(EFFECT_REGEN) == false)   //Regen 
			{
			m_PBattleSubTarget = m_PPet->PMaster;
			if (mskill >= 232)
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
					 spellID = 109;
					}					
				else 
			        {
				     spellID = -1;
				    } 
			else if (mskill >= 135)
                if (m_PPet->health.mp >= 36)
					{
					 spellID = 110;
					}
                else if (m_PPet->health.mp >= 15)
					{
					 spellID = 109;
					}					
				else 
			        {
				     spellID = -1;
				    }
			else if (mskill >= 66)
                if (m_PPet->health.mp >= 15)
					{
					 spellID = 109;
					}					
				else 
			        {
				     spellID = -1;
				    }					
			else
		        {
				 spellID = -1;
				} 
			m_magicEnhanceCast = 1;
			m_magicEnhanceRecast = 15000;
			}				
		else if (m_PPet->PMaster->StatusEffectContainer->HasStatusEffect(EFFECT_WIND_MANEUVER) == true && m_PPet->PMaster->StatusEffectContainer->HasStatusEffect(EFFECT_HASTE) == false)   //Haste 
			{
			m_PBattleSubTarget = m_PPet->PMaster;
			if (mskill > 146)
                if (m_PPet->health.mp > 39)
					{
					 spellID = 57;
					}
				else 
			        {
				     spellID = -1;
				    } 				
			else
		        {
				 spellID = -1;
				} 
			m_magicEnhanceCast = 1;
			m_magicEnhanceRecast = 15000;
			}			
			else
			{
			m_LastMagicTimeEnhance = m_Tick; // reset mtick
			m_magicEnhanceRecast = 15000; // No eligible Enhance Spell to Cast
			}
        }
	
	
	
	// Healing AI
	// TODO Add calculation that looks at most wounded HP percentage vs their full HP amount to determine level of cure
	// TODO Add a way to calculate proper regen

	if (m_Tick >= m_LastMagicTimeHeal + m_magicHealRecast)  // Look for last magic healing spell time 
	{
	    //This will only fire if the targets are 30% or lower so it uses the highest cure possible
		if (mostWoundedLow != nullptr)
		{
        m_PBattleSubTarget = mostWoundedLow;
		if (mskill > 206)
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
        else if (mskill > 146)
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
		else if (mskill > 80)
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
		else if (mskill > 44)
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
		else if (mskill > 11)
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
		}
		
		else if (mostWounded != nullptr)
		{
        m_PBattleSubTarget = mostWounded;
		/*if (mskill > 206)
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
		else*/ if (mskill > 146)
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
		else if (mskill > 80)
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
		else if (mskill > 44)
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
		else if (mskill > 11)
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
		
        m_magicHealRecast = 15000 - m_damageGauge;
		m_magicHealCast = 1; // 1 means casting a spell
		}
		else
		{
		m_LastMagicTimeHeal = m_Tick; // reset mtick no eligible healing spell to cast
		m_magicHealRecast = 15000;		
       }
	}
	
	
	
	else if (m_Tick >= m_LastMagicTimeEnf + m_magicEnfeebleRecast)  // Look for last enfeeble spell time 
	{
	  if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_DIA) == false && m_PBattleTarget->GetHPP() >= requiredHPP)
	{
		m_PBattleSubTarget = m_PBattleTarget;
        if (mskill >= 96)
		    if (m_PPet->health.mp > 30)  	
			    {
				 spellID = 24;
				}
		    else if (m_PPet->health.mp >= 7)  	
			    {
				 spellID = 23;
				}
            else
			    {
				 spellID = -1;
				}
        else if (mskill >= 0)
		    if (m_PPet->health.mp >= 7)  	
			    {
				 spellID = 23;
				}
            else 
			    {
				 spellID = -1;
				}
		m_magicEnfeebCast = 1;
		m_magicEnfeebleRecast = 8000;
        
	}
	    else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_POISON) == false && m_PBattleTarget->GetHPP() >= requiredHPP) 
	{
	   m_PBattleSubTarget = m_PBattleTarget;
		// m_magicRecast = 5000;
        if (mskill > 17)
		    if (m_PPet->health.mp >= 5)  	
			    {
				 spellID = 220;
				}
            else
			    {
				 spellID = -1;
				} 
        m_magicEnfeebCast = 1;
		m_magicEnfeebleRecast = 8000;
	
	}
	    else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_PARALYSIS) == false && m_PBattleTarget->GetHPP() >= requiredHPP) 
	{
	   m_PBattleSubTarget = m_PBattleTarget;
		// m_magicRecast = 5000;
        if (mskill > 20)
		    if (m_PPet->health.mp >= 6)  	
			    {
				 spellID = 58;
				}
             else
			    {
				 spellID = -1;
				} 
        m_magicEnfeebCast = 1;
		m_magicEnfeebleRecast = 8000;
	
	}
	    else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_BLINDNESS) == false && m_PBattleTarget->GetHPP() >= requiredHPP) 
	{
	   m_PBattleSubTarget = m_PBattleTarget;
		// m_magicRecast = 5000;
        if (mskill > 41)
		    if (m_PPet->health.mp >= 5)  	
			    {
				 spellID = 254;
				}
            else
			    {
				 spellID = -1;
				} 
        m_magicEnfeebCast = 1;
		m_magicEnfeebleRecast = 8000;
	
	}
	

    else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_SLOW) == false && m_PBattleTarget->GetHPP() >= requiredHPP) 
	{
	   m_PBattleSubTarget = m_PBattleTarget;
		// m_magicRecast = 5000;
        if (mskill > 41)
		    if (m_PPet->health.mp >= 15)  	
			    {
				 spellID = 56;
				}
             else
			    {
				 spellID = -1;
				} 
        m_magicEnfeebCast = 1;
		m_magicEnfeebleRecast = 8000;
	
	}
	
	  else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == false && m_PBattleTarget->GetHPP() >= requiredHPP) 
	{
	   m_PBattleSubTarget = m_PBattleTarget;
		// m_magicRecast = 5000;
        if (mskill > 56)
		    if (m_PPet->health.mp >= 16)  	
			    {
				 spellID = 59;
				}
            else
			    {
				 spellID = -1;
				} 
        m_magicEnfeebCast = 1;
		m_magicEnfeebleRecast = 8000;
	
	}
	
	else
	{
		m_LastMagicTimeEnf = m_Tick; // reset mtick
		m_magicEnfeebleRecast = 15000; // No eligible Debuffs
	}	
	}

	
	return spellID;
}

//------------------------------------------------------//
// Stormwaker Frame/Stormwaker Head Automaton AI (RDM)  //
//------------------------------------------------------//


int16 CAIAutomatonDummy::StormFrameStormAttack()
{
	uint8 requiredHPP = 75; // Enfeebling Threshold
	uint8 nukeHPP = 74; // Mob HP threshold to begin nuking for RDM Head less than or equal to
	uint8 lowHPP = 31;
	uint8 level = m_PPet->GetMLevel();
	uint8 trigger = 40;
	uint16 mskill = m_PPet->PMaster->GetSkill(SKILL_AMA);
	uint16 maskill = m_PPet->PMaster->GetSkill(SKILL_AMA);
	
    int16 spellID = -1;
    CBattleEntity* master = m_PPet->PMaster;  
	//calculate curing threshold based on Light Maneuvers
	if (m_PPet->PMaster->StatusEffectContainer->GetEffectsCount(EFFECT_LIGHT_MANEUVER) == 1) 
		{
		trigger = 40;
		}
	else if (m_PPet->PMaster->StatusEffectContainer->GetEffectsCount(EFFECT_LIGHT_MANEUVER) == 2) 
		{
		trigger = 50;
		}
	else if (m_PPet->PMaster->StatusEffectContainer->GetEffectsCount(EFFECT_LIGHT_MANEUVER) == 3) 
		{
		trigger = 75;
		}
	else if (m_PPet->hasAttachment(8643))
		{
		trigger = 80;
		}	
	else
		{
		trigger = 40;
	    }
	//calculate attachments
	
	if (m_PPet->hasAttachment(8643))
		{
		 m_damageGauge = 2000; // Prioritiezes Cures by making its counter 2 seconds faster 
		}
	else
		{
		 m_damageGauge = 0;
		}
	
	
    CBattleEntity* mostWounded = getWounded(trigger);

	// Healing AI
	// TODO Add calculation that looks at most wounded HP percentage vs their full HP amount to determine level of cure
	// TODO Add a way to calculate proper regen

	if (m_Tick >= m_LastMagicTimeHeal + m_magicHealRecast)  // Look for last magic healing spell time 
	{
		if (mostWounded != nullptr)
		{
        m_PBattleSubTarget = mostWounded;
		if (mskill > 146)
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
		else if (mskill > 80)
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
		else if (mskill > 44)
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
		else if (mskill > 11)
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
		
        m_magicHealRecast = 25000 - m_damageGauge;
		m_magicHealCast = 1; // 1 means casting a spell
		}
		else
		{
		m_LastMagicTimeHeal = m_Tick; // reset mtick no eligible healing spell to cast
		m_magicHealRecast = 15000;		
       }
	}	
	
	
	
    //CBattleEntity* mostWounded = m_PPet;
	// Enhancing Spells
	// Order is Protect > Shell > Haste (if Wind Maneuver is up) > Stoneskin (if Earth Maneuver is up) > Phalanx 
	
	else if (m_Tick >= m_LastMagicTimeEnhance + m_magicEnhanceRecast) 
		{
		if (m_PPet->PMaster->StatusEffectContainer->HasStatusEffect(EFFECT_PROTECT) == false) 
			{
			m_PBattleSubTarget = m_PPet->PMaster;
			if (mskill > 216)
				if (m_PPet->health.mp > 64)
					{
					 spellID = 46;
					}
				else if (m_PPet->health.mp > 45)
					{
					 spellID = 45;
					}
				else if (m_PPet->health.mp > 27)
					{
					 spellID = 44;
					}
				else if (m_PPet->health.mp > 8)
					{
					 spellID = 43;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else if (mskill > 143)
				if (m_PPet->health.mp > 45)
					{
					 spellID = 45;
					}
				else if (m_PPet->health.mp > 27)
					{
					 spellID = 44;
					}
				else if (m_PPet->health.mp > 8)
					{
					 spellID = 43;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else if (mskill > 83)
				if (m_PPet->health.mp > 27)
					{
					 spellID = 44;
					}
				else if (m_PPet->health.mp > 8)
					{
					 spellID = 43;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else if (mskill > 23)
				if (m_PPet->health.mp > 8)
					{
					 spellID = 43;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else
		        {
				 spellID = -1;
				} 
			m_magicEnhanceCast = 1;
			m_magicEnhanceRecast = 15000;
			}
		else if (m_PPet->PMaster->StatusEffectContainer->HasStatusEffect(EFFECT_SHELL) == false) 
			{
			m_PBattleSubTarget = m_PPet->PMaster;
			if (mskill > 240)
				if (m_PPet->health.mp > 74)
					{
					 spellID = 51;
					}
				else if (m_PPet->health.mp > 55)
					{
					 spellID = 50;
					}
				else if (m_PPet->health.mp > 36)
					{
					 spellID = 49;
					}
				else if (m_PPet->health.mp > 17)
					{
					 spellID = 48;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else if (mskill > 187)
				if (m_PPet->health.mp > 55)
					{
					 spellID = 50;
					}
				else if (m_PPet->health.mp > 36)
					{
					 spellID = 49;
					}
				else if (m_PPet->health.mp > 17)
					{
					 spellID = 48;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else if (mskill > 113)
				if (m_PPet->health.mp > 36)
					{
					 spellID = 49;
					}
				else if (m_PPet->health.mp > 17)
					{
					 spellID = 48;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else if (mskill > 53)
				if (m_PPet->health.mp > 17)
					{
					 spellID = 48;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else
		        {
				 spellID = -1;
				} 
			m_magicEnhanceCast = 1;
			m_magicEnhanceRecast = 15000;
			}
		else if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_PROTECT) == false) //cast protect on self
			{
			m_PBattleSubTarget = m_PPet;
			if (mskill > 216)
				if (m_PPet->health.mp > 64)
					{
					 spellID = 46;
					}
				else if (m_PPet->health.mp > 45)
					{
					 spellID = 45;
					}
				else if (m_PPet->health.mp > 27)
					{
					 spellID = 44;
					}
				else if (m_PPet->health.mp > 8)
					{
					 spellID = 43;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else if (mskill > 143)
				if (m_PPet->health.mp > 45)
					{
					 spellID = 45;
					}
				else if (m_PPet->health.mp > 27)
					{
					 spellID = 44;
					}
				else if (m_PPet->health.mp > 8)
					{
					 spellID = 43;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else if (mskill > 83)
				if (m_PPet->health.mp > 27)
					{
					 spellID = 44;
					}
				else if (m_PPet->health.mp > 8)
					{
					 spellID = 43;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else if (mskill > 23)
				if (m_PPet->health.mp > 8)
					{
					 spellID = 43;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else
		        {
				 spellID = -1;
				} 
			m_magicEnhanceCast = 1;
			m_magicEnhanceRecast = 15000;
			}
		else if (m_PPet->StatusEffectContainer->HasStatusEffect(EFFECT_SHELL) == false)  //Cast shell on self
			{
			m_PBattleSubTarget = m_PPet;
			if (mskill > 240)
				if (m_PPet->health.mp > 74)
					{
					 spellID = 51;
					}
				else if (m_PPet->health.mp > 55)
					{
					 spellID = 50;
					}
				else if (m_PPet->health.mp > 36)
					{
					 spellID = 49;
					}
				else if (m_PPet->health.mp > 17)
					{
					 spellID = 48;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else if (mskill > 187)
				if (m_PPet->health.mp > 55)
					{
					 spellID = 50;
					}
				else if (m_PPet->health.mp > 36)
					{
					 spellID = 49;
					}
				else if (m_PPet->health.mp > 17)
					{
					 spellID = 48;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else if (mskill > 113)
				if (m_PPet->health.mp > 36)
					{
					 spellID = 49;
					}
				else if (m_PPet->health.mp > 17)
					{
					 spellID = 48;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else if (mskill > 53)
				if (m_PPet->health.mp > 17)
					{
					 spellID = 48;
					}
				else 
			        {
				     spellID = -1;
				    } 	
			else
		        {
				 spellID = -1;
				} 
			m_magicEnhanceCast = 1;
			m_magicEnhanceRecast = 15000;
			}				
		else if (m_PPet->PMaster->StatusEffectContainer->HasStatusEffect(EFFECT_WIND_MANEUVER) == true && m_PPet->PMaster->StatusEffectContainer->HasStatusEffect(EFFECT_HASTE) == false)   //Haste 
			{
			m_PBattleSubTarget = m_PPet->PMaster;
			if (mskill > 146)
                if (m_PPet->health.mp > 39)
					{
					 spellID = 57;
					}
				else 
			        {
				     spellID = -1;
				    } 				
			else
		        {
				 spellID = -1;
				} 
			m_magicEnhanceCast = 1;
			m_magicEnhanceRecast = 15000;
			}			
		else if (m_PPet->PMaster->StatusEffectContainer->HasStatusEffect(EFFECT_EARTH_MANEUVER) == true && m_PPet->PMaster->StatusEffectContainer->HasStatusEffect(EFFECT_STONESKIN) == false)   //Stoneskin 
			{
			m_PBattleSubTarget = m_PPet->PMaster;
			if (mskill > 105)
                if (m_PPet->health.mp > 29)
					{
					 spellID = 54;
					}
				else 
			        {
				     spellID = -1;
				    } 				
			else
		        {
				 spellID = -1;
				} 
			m_magicEnhanceCast = 1;
			m_magicEnhanceRecast = 15000;
			}
        else if (m_PPet->PMaster->StatusEffectContainer->HasStatusEffect(EFFECT_PHALANX) == false && m_PBattleTarget->GetHPP() >= requiredHPP && m_PBattleTarget->GetMLevel() >= m_PPet->PMaster->GetMLevel())   //Phalanx only if mob level is EM or higher
			{
			m_PBattleSubTarget = m_PPet->PMaster;
			if (mskill > 98)
                if (m_PPet->health.mp > 20)
					{
					 spellID = 106;
					}
				else 
			        {
				     spellID = -1;
				    } 				
			else
		        {
				 spellID = -1;
				} 
			m_magicEnhanceCast = 1;
			m_magicEnhanceRecast = 15000;
			}						
			else
			{
			m_LastMagicTimeEnhance = m_Tick; // reset mtick
			m_magicEnhanceRecast = 15000; // No eligible Enhance Spell to Cast
			}
        }	
	
	
	else if (m_Tick >= m_LastMagicTimeEnf + m_magicEnfeebleRecast)  // Look for last enfeeble spell time 
	{
	    //Dispel List
	    if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_BLAZE_SPIKES) ||
		m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_ICE_SPIKES) || m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_SHOCK_SPIKES) ||
		m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_BLINK) || m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_STONESKIN) ||
		m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_PROTECT) || m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_SHELL) ||
		m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_REGEN) || m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_BERSERK) ||
		m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_DEFENDER) || m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_COUNTERSTANCE) ||
		m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_ENSTONE) || m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_ENTHUNDER) ||
		m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_ENWATER) || m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_ENFIRE) ||
		m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_ENAERO) || m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_ENBLIZZARD))
	{
	   m_PBattleSubTarget = m_PBattleTarget;
		// m_magicRecast = 5000;
        if (mskill > 105)
		    if (m_PPet->health.mp >= 25)  	
			    {
				 spellID = 260;
				}
            else
			    {
				 spellID = -1;
				} 
        m_magicEnfeebCast = 1;
		m_magicEnfeebleRecast = 11000;
	}	
	  else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_DIA) == false && m_PBattleTarget->GetHPP() >= requiredHPP)
	{
		m_PBattleSubTarget = m_PBattleTarget;
        if (mskill >= 96)
		    if (m_PPet->health.mp > 30)  	
			    {
				 spellID = 24;
				}
		    else if (m_PPet->health.mp >= 7)  	
			    {
				 spellID = 23;
				}
            else
			    {
				 spellID = -1;
				}
        else if (mskill >= 0)
		    if (m_PPet->health.mp >= 7)  	
			    {
				 spellID = 23;
				}
            else 
			    {
				 spellID = -1;
				}
		m_magicEnfeebCast = 1;
		m_magicEnfeebleRecast = 11000;
        
	}
	    else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_POISON) == false && m_PBattleTarget->GetHPP() >= requiredHPP) 
	{
	   m_PBattleSubTarget = m_PBattleTarget;
		// m_magicRecast = 5000;
        if (mskill > 17)
		    if (m_PPet->health.mp >= 5)  	
			    {
				 spellID = 220;
				}
            else
			    {
				 spellID = -1;
				} 
        m_magicEnfeebCast = 1;
		m_magicEnfeebleRecast = 11000;
	
	}
	    else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_PARALYSIS) == false && m_PBattleTarget->GetHPP() >= requiredHPP) 
	{
	   m_PBattleSubTarget = m_PBattleTarget;
		// m_magicRecast = 5000;
        if (mskill > 20)
		    if (m_PPet->health.mp >= 6)  	
			    {
				 spellID = 58;
				}
             else
			    {
				 spellID = -1;
				} 
        m_magicEnfeebCast = 1;
		m_magicEnfeebleRecast = 11000;
	
	}
	    else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_BLINDNESS) == false && m_PBattleTarget->GetHPP() >= requiredHPP) 
	{
	   m_PBattleSubTarget = m_PBattleTarget;
		// m_magicRecast = 5000;
        if (mskill > 41)
		    if (m_PPet->health.mp >= 5)  	
			    {
				 spellID = 254;
				}
            else
			    {
				 spellID = -1;
				} 
        m_magicEnfeebCast = 1;
		m_magicEnfeebleRecast = 11000;
	
	}
	

    else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_SLOW) == false && m_PBattleTarget->GetHPP() >= requiredHPP) 
	{
	   m_PBattleSubTarget = m_PBattleTarget;
		// m_magicRecast = 5000;
        if (mskill > 41)
		    if (m_PPet->health.mp >= 15)  	
			    {
				 spellID = 56;
				}
             else
			    {
				 spellID = -1;
				} 
        m_magicEnfeebCast = 1;
		m_magicEnfeebleRecast = 11000;
	
	}
	
	  else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == false && m_PBattleTarget->GetHPP() >= requiredHPP) 
	{
	   m_PBattleSubTarget = m_PBattleTarget;
		// m_magicRecast = 5000;
        if (mskill > 56)
		    if (m_PPet->health.mp >= 16)  	
			    {
				 spellID = 59;
				}
            else
			    {
				 spellID = -1;
				} 
        m_magicEnfeebCast = 1;
		m_magicEnfeebleRecast = 11000;
	
	}
	}
	
	//--------------------------------------------//
	//   Elemental Magic Weakness Targeting       //
	//   TODO Ice element forcing Ele Magic       //
	//--------------------------------------------//
	else if (m_Tick >= m_LastMagicTimeEle + m_magicElementalRecast)  // Look for last ele spell time and force magic casting if ice maneuver is up
	{
	 if (m_PBattleTarget != nullptr && m_PBattleTarget->getMod(MOD_THUNDERRES) < 0 && m_PBattleTarget->GetHPP() <= nukeHPP && m_PBattleTarget->objtype == TYPE_MOB && m_PPet->hasAttachment(8483) && mskill >= 90)  // Weak to Thunder
	 {
	 ShowDebug("Monster is Weak to Thunder");
	 m_PBattleSubTarget = m_PBattleTarget;
		if (mskill > 290)
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
		else if (mskill > 260)
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
		else if (mskill > 202)
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
		else if (mskill > 89)
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
		m_magicElementCast = 1;
		m_magicElementalRecast = 18000;
    }
	 else if (m_PBattleTarget != nullptr && m_PBattleTarget->getMod(MOD_ICERES) < 0 && m_PBattleTarget->GetHPP() <= nukeHPP && m_PBattleTarget->objtype == TYPE_MOB && m_PPet->hasAttachment(8483) && mskill >= 90)  // Weak to Ice
	{
	    ShowDebug("Monster is Weak to Ice");
		m_PBattleSubTarget = m_PBattleTarget;
		if (mskill > 286)
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
		else if (mskill > 260)
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
        else if (mskill > 177)
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
        else if (mskill > 74)
			if (m_PPet->health.mp > 7)	
                {
				 spellID = 149;
			    }
            else
				{
				 spellID = -1;
				}	
    m_magicElementCast = 1;
	m_magicElementalRecast = 18000;	
    }
	 else if (m_PBattleTarget != nullptr && m_PBattleTarget->getMod(MOD_FIRERES) < 0 && m_PBattleTarget->GetHPP() <= nukeHPP && m_PBattleTarget->objtype == TYPE_MOB && m_PPet->hasAttachment(8483) && mskill >= 90)  // Weak to Fire
	{
	    ShowDebug("Monster is Weak to Fire");
		m_PBattleSubTarget = m_PBattleTarget;
		if (mskill > 280)
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
		else if (mskill > 250)
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
        else if (mskill > 152)
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
        else if (mskill > 59)
			if (m_PPet->health.mp > 6)	
                {
				 spellID = 144;
			    }
            else
				{
				 spellID = -1;
				}	
    m_magicElementCast = 1;
	m_magicElementalRecast = 18000;	
    }
	 else if (m_PBattleTarget != nullptr && m_PBattleTarget->getMod(MOD_WINDRES) < 0 && m_PBattleTarget->GetHPP() <= nukeHPP && m_PBattleTarget->objtype == TYPE_MOB && m_PPet->hasAttachment(8483) && mskill >= 90)  // Weak to Wind
	{
	    ShowDebug("Monster is Weak to Wind");
		m_PBattleSubTarget = m_PBattleTarget;
		if (mskill > 275)
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
		else if (mskill > 245)
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
        else if (mskill > 137)
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
        else if (mskill > 44)
			if (m_PPet->health.mp > 5)	
                {
				 spellID = 154;
			    }
            else
				{
				 spellID = -1;
				}	
    m_magicElementCast = 1;
	m_magicElementalRecast = 18000;	
    }
	 else if (m_PBattleTarget != nullptr && m_PBattleTarget->getMod(MOD_WATERRES) < 0 && m_PBattleTarget->GetHPP() <= nukeHPP && m_PBattleTarget->objtype == TYPE_MOB && m_PPet->hasAttachment(8483) && mskill >= 90)  // Weak to Water
	{
	    ShowDebug("Monster is Weak to Water");
		m_PBattleSubTarget = m_PBattleTarget;
		if (mskill > 270)
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
		else if (mskill > 235)
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
        else if (mskill > 122)
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
        else if (mskill > 30)
			if (m_PPet->health.mp > 4)	
                {
				 spellID = 169;
			    }
            else
				{
				 spellID = -1;
				}	
    m_magicElementCast = 1;
	m_magicElementalRecast = 18000;	
    }
    else if (m_PBattleTarget != nullptr && m_PBattleTarget->getMod(MOD_EARTHRES) < 0 && m_PBattleTarget->GetHPP() <= nukeHPP && m_PBattleTarget->objtype == TYPE_MOB && m_PPet->hasAttachment(8483) && mskill >= 90)  // Weak to Earth
	{
	    ShowDebug("Monster is Weak to Earth");
		m_PBattleSubTarget = m_PBattleTarget;
		if (mskill > 265)
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
		else if (mskill > 226)
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
        else if (mskill > 107)
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
        else if (mskill > 14)
			if (m_PPet->health.mp > 3)	
                {
				 spellID = 159;
			    }
            else
				{
				 spellID = -1;
				}	
    m_magicElementCast = 1;
	m_magicElementalRecast = 18000;	
    }
	// No elemental magic weakness found - Cast highest Nuke learned
	// TODO: Add check for Ice maneuver to force casting at any time.
	else if (m_PBattleTarget != nullptr && m_PBattleTarget->GetHPP() <= nukeHPP && m_PBattleTarget->objtype == TYPE_MOB)
	{
	    ShowDebug("No Weakness Casting Highest Spell \n");
        m_PBattleSubTarget = m_PBattleTarget;
		if (mskill > 290)
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
		else if (mskill > 285)
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
		else if (mskill > 280)
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
		else if (mskill > 275)
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
		else if (mskill > 270)
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
        else if (mskill > 265)
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
        else if (mskill > 260)
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
		else if (mskill > 255)
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
		else if (mskill > 250)
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
		else if (mskill > 245)
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
		else if (mskill > 235)
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
		else if (mskill > 226)
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
		else if (mskill > 202)
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
		else if (mskill > 177)
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
		else if (mskill > 152)
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
		else if (mskill > 137)
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
		else if (mskill > 122)
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
		else if (mskill > 107)
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
		else if (mskill > 89)
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
		else if (mskill > 74)
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
		else if (mskill > 59)
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
		else if (mskill > 44)
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
		else if (mskill > 30)
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
		else if (mskill > 14)
		   if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}	
		m_magicElementCast = 1;
		m_magicElementalRecast = 25000;        
    }	
	else
	{
		m_LastMagicTimeEle = m_Tick; // reset mtick
		m_magicElementalRecast = 15000; // No eligible Elemental Spell to cast
		}	
	}

	return spellID;
}





//--------------------------------------------------------//
// Stormwaker Frame/Spiritreaver Head Automaton AI (BLM) //
//------------------------------------------------------//


int16 CAIAutomatonDummy::StormFrameSpiritAttack()
{
	uint8 requiredHPP = 75; // Enfeebling Threshold
	uint8 nukeHPP = 74; // Mob HP threshold to begin nuking for BLM Head less than or equal to
	uint8 lowHPP = 31;
	uint8 level = m_PPet->GetMLevel();
	uint16 mskill = m_PPet->PMaster->GetSkill(SKILL_AMA);
	uint16 maskill = m_PPet->PMaster->GetSkill(SKILL_AMA);
	
    int16 spellID = -1;
    CBattleEntity* master = m_PPet->PMaster;  
	//calculate curing threshold based on Light Maneuvers

	
	
    
    //CBattleEntity* mostWounded = m_PPet;
	// Enhancing Spells
	//On enfeebs first check if maneuver up is no dark 
	// then check if it is dark but no ice to do Aspir > Drain > Absorb INT > Blind > Bio > Poison 2
	// check if dark and ice are up and do no enfeebs
	

	if (m_Tick >= m_LastMagicTimeEnf + m_magicEnfeebleRecast)  // Look for last enfeeble spell time 
	{
	  if (m_PPet->PMaster->StatusEffectContainer->HasStatusEffect(EFFECT_DARK_MANEUVER) == false) //No Dark Maneuvers use only Drain Aspir then nuke
	  {
	    if (m_PBattleTarget != nullptr && m_magicAspir == 0 && m_PPet->GetMPP() < 95)
	    {
		m_PBattleSubTarget = m_PBattleTarget;
        if (mskill >= 77)
		    if (m_PPet->health.mp > 9)  	
			    {
				 spellID = 247;  //Aspir
				}
            else
			    {
				 spellID = -1;
				}
		m_magicEnfeebCast = 1;
		m_magicAspir = 1;
		m_magicEnfeebleRecast = 11000;    
	    }
	    else if (m_PBattleTarget != nullptr && m_magicDrain == 0 && m_PPet->GetHPP() < 85) 
	    {
	    m_PBattleSubTarget = m_PBattleTarget;
        if (mskill > 44)
		    if (m_PPet->health.mp >= 20)  	
			    {
				 spellID = 245;  // Drain
				}
            else
			    {
				 spellID = -1;
				} 
        m_magicEnfeebCast = 1;
		m_magicAspir = 0;
		m_magicDrain = 0;
		m_magicEnfeebleRecast = 45000;
	    }
	   }
	   else if (m_PBattleTarget != nullptr && (m_PPet->PMaster->StatusEffectContainer->HasStatusEffect(EFFECT_DARK_MANEUVER) == true && 
	   m_PPet->PMaster->StatusEffectContainer->HasStatusEffect(EFFECT_ICE_MANEUVER) == false))
	{
	  if (m_PBattleTarget != nullptr && m_PPet->GetHPP() < 65) // Dread Spikes
	  {
	   m_PBattleSubTarget = m_PPet;
        if (mskill >= 256)
		    if (m_PPet->health.mp >= 78)  	
			    {
				 spellID = 277;
				}
            else
			    {
				 spellID = -1;
				} 
        m_magicEnfeebCast = 1;
		m_magicEnfeebleRecast = 11000;
	    }
  else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_INT_DOWN) == false && m_PPet->PMaster->StatusEffectContainer->HasStatusEffect(EFFECT_DARK_MANEUVER) == true) //Absorb INT
	{
	   m_PBattleSubTarget = m_PBattleTarget;
		// m_magicRecast = 5000;
        if (mskill >= 120)
		    if (m_PPet->health.mp >= 33)  	
			    {
				 spellID = 270;
				}
             else
			    {
				 spellID = -1;
				} 
        m_magicEnfeebCast = 1;
		m_magicEnfeebleRecast = 11000;
	
	}
	    else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_BLINDNESS) == false && m_PPet->PMaster->StatusEffectContainer->HasStatusEffect(EFFECT_DARK_MANEUVER) == true && m_PBattleTarget->GetHPP() >= requiredHPP) //Blind
	{
	   m_PBattleSubTarget = m_PBattleTarget;
		// m_magicRecast = 5000;
        if (mskill > 26)
		    if (m_PPet->health.mp >= 5)  	
			    {
				 spellID = 254;
				}
            else
			    {
				 spellID = -1;
				} 
        m_magicEnfeebCast = 1;
		m_magicEnfeebleRecast = 11000;
	
	}	
	    else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_BIO) == false && m_PBattleTarget->GetHPP() >= requiredHPP) // Bio
	{
	   m_PBattleSubTarget = m_PBattleTarget;
		// m_magicRecast = 5000;
        if (mskill >= 111)
		    if (m_PPet->health.mp >= 36)  	
			    {
				 spellID = 231;
				}
			else if (m_PPet->health.mp >= 15) 	
			    {
				 spellID = 230;
				}
             else
			    {
				 spellID = -1;
				} 
		else if (mskill >= 33)
		    if (m_PPet->health.mp >= 15) 	
			    {
				 spellID = 230;
				}
             else
			    {
				 spellID = -1;
				} 
        m_magicEnfeebCast = 1;
		m_magicEnfeebleRecast = 11000;
	
	}	
		else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_SILENCE) == false && m_PBattleTarget->GetHPP() >= requiredHPP) // Silence
	{
	   m_PBattleSubTarget = m_PBattleTarget;
		// m_magicRecast = 5000;
        if (mskill > 56)
		    if (m_PPet->health.mp >= 16)  	
			    {
				 spellID = 59;
				}
             else
			    {
				 spellID = -1;
				} 
        m_magicEnfeebCast = 1;
		m_magicEnfeebleRecast = 11000;
	
	}
		else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_SLOW) == false && m_PBattleTarget->GetHPP() >= requiredHPP) // Slow
	{
	   m_PBattleSubTarget = m_PBattleTarget;
		// m_magicRecast = 5000;
        if (mskill > 42)
		    if (m_PPet->health.mp >= 15)  	
			    {
				 spellID = 56;
				}
             else
			    {
				 spellID = -1;
				} 
        m_magicEnfeebCast = 1;
		m_magicEnfeebleRecast = 11000;
	
	}
	    else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_PARALYSIS) == false && m_PBattleTarget->GetHPP() >= requiredHPP) // Para
	{
	   m_PBattleSubTarget = m_PBattleTarget;
		// m_magicRecast = 5000;
        if (mskill > 20)
		    if (m_PPet->health.mp >= 6)  	
			    {
				 spellID = 58;
				}
             else
			    {
				 spellID = -1;
				} 
        m_magicEnfeebCast = 1;
		m_magicEnfeebleRecast = 11000;
	
	}
	    else if (m_PBattleTarget != nullptr && m_PBattleTarget->StatusEffectContainer->HasStatusEffect(EFFECT_BIO) == false && m_PBattleTarget->GetHPP() >= requiredHPP) // Poison
	{
	   m_PBattleSubTarget = m_PBattleTarget;
		// m_magicRecast = 5000;
        if (mskill >= 141)
		    if (m_PPet->health.mp >= 38)  	
			    {
				 spellID = 221;
				}
			else if (m_PPet->health.mp >= 5) 	
			    {
				 spellID = 220;
				}
             else
			    {
				 spellID = -1;
				} 
		else if (mskill >= 18)
		    if (m_PPet->health.mp >= 5) 	
			    {
				 spellID = 220;
				}
             else
			    {
				 spellID = -1;
				} 
        m_magicEnfeebCast = 1;
		m_magicEnfeebleRecast = 11000;
	
	}			
		
	}	
	  
	}
	
	//--------------------------------------------//
	//   Elemental Magic Weakness Targeting       //
	//   TODO Ice element forcing Ele Magic       //
	//--------------------------------------------//
	else if (m_Tick >= m_LastMagicTimeEle + m_magicElementalRecast)  // Look for last ele spell time and force magic casting if ice maneuver is up
	{
	 if (m_PBattleTarget != nullptr && m_PBattleTarget->getMod(MOD_THUNDERRES) < 0 && m_PBattleTarget->GetHPP() <= nukeHPP)  // Weak to Thunder
	 {
	 m_PBattleSubTarget = m_PBattleTarget;
		if (mskill > 290)
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
		else if (mskill > 260)
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
		else if (mskill > 202)
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
		else if (mskill > 89)
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
		m_magicElementCast = 1;
		m_magicElementalRecast = 18000;
    }
	 else if (m_PBattleTarget != nullptr && m_PBattleTarget->getMod(MOD_ICERES) < 0 && m_PBattleTarget->GetHPP() <= nukeHPP)  // Weak to Ice
	{
		m_PBattleSubTarget = m_PBattleTarget;
		if (mskill > 286)
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
		else if (mskill > 260)
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
        else if (mskill > 177)
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
        else if (mskill > 74)
			if (m_PPet->health.mp > 7)	
                {
				 spellID = 149;
			    }
            else
				{
				 spellID = -1;
				}	
    m_magicElementCast = 1;
	m_magicElementalRecast = 18000;	
    }
	 else if (m_PBattleTarget != nullptr && m_PBattleTarget->getMod(MOD_FIRERES) < 0 && m_PBattleTarget->GetHPP() <= nukeHPP)  // Weak to Fire
	{
		m_PBattleSubTarget = m_PBattleTarget;
		if (mskill > 280)
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
		else if (mskill > 250)
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
        else if (mskill > 152)
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
        else if (mskill > 59)
			if (m_PPet->health.mp > 6)	
                {
				 spellID = 144;
			    }
            else
				{
				 spellID = -1;
				}	
    m_magicElementCast = 1;
	m_magicElementalRecast = 18000;	
    }
	 else if (m_PBattleTarget != nullptr && m_PBattleTarget->getMod(MOD_WINDRES) < 0 && m_PBattleTarget->GetHPP() <= nukeHPP)  // Weak to Wind
	{
		m_PBattleSubTarget = m_PBattleTarget;
		if (mskill > 275)
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
		else if (mskill > 245)
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
        else if (mskill > 137)
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
        else if (mskill > 44)
			if (m_PPet->health.mp > 5)	
                {
				 spellID = 154;
			    }
            else
				{
				 spellID = -1;
				}	
    m_magicElementCast = 1;
	m_magicElementalRecast = 18000;	
    }
	 else if (m_PBattleTarget != nullptr && m_PBattleTarget->getMod(MOD_WATERRES) < 0 && m_PBattleTarget->GetHPP() <= nukeHPP)  // Weak to Water
	{
		m_PBattleSubTarget = m_PBattleTarget;
		if (mskill > 270)
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
		else if (mskill > 235)
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
        else if (mskill > 122)
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
        else if (mskill > 30)
			if (m_PPet->health.mp > 4)	
                {
				 spellID = 169;
			    }
            else
				{
				 spellID = -1;
				}	
    m_magicElementCast = 1;
	m_magicElementalRecast = 18000;	
    }
    else if (m_PBattleTarget != nullptr && m_PBattleTarget->getMod(MOD_EARTHRES) < 0 && m_PBattleTarget->GetHPP() <= nukeHPP)  // Weak to Earth
	{
		m_PBattleSubTarget = m_PBattleTarget;
		if (mskill > 265)
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
		else if (mskill > 226)
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
        else if (mskill > 107)
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
        else if (mskill > 14)
			if (m_PPet->health.mp > 3)	
                {
				 spellID = 159;
			    }
            else
				{
				 spellID = -1;
				}	
    m_magicElementCast = 1;
	m_magicElementalRecast = 18000;	
    }
	// No elemental magic weakness found - Cast highest Nuke learned
	// TODO: Add check for Ice maneuver to force casting at any time.
	else if (m_PBattleTarget != nullptr && m_PBattleTarget->GetHPP() <= nukeHPP)
	{
        m_PBattleSubTarget = m_PBattleTarget;
		if (mskill > 290)
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
		else if (mskill > 285)
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
		else if (mskill > 280)
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
		else if (mskill > 275)
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
		else if (mskill > 270)
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
        else if (mskill > 265)
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
        else if (mskill > 260)
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
		else if (mskill > 255)
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
		else if (mskill > 250)
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
		else if (mskill > 245)
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
		else if (mskill > 235)
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
		else if (mskill > 226)
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
		else if (mskill > 202)
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
		else if (mskill > 177)
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
		else if (mskill > 152)
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
		else if (mskill > 137)
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
		else if (mskill > 122)
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
		else if (mskill > 107)
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
		else if (mskill > 89)
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
		else if (mskill > 74)
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
		else if (mskill > 59)
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
		else if (mskill > 44)
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
		else if (mskill > 30)
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
		else if (mskill > 14)
		   if (m_PPet->health.mp > 3)
			{
			 spellID = 159; //STONE I
			}
        else
			{
		     spellID = -1;
			}	
		m_magicElementCast = 1;
		m_magicElementalRecast = 25000;        
    }	
	else
	{
		m_LastMagicTimeEle = m_Tick; // reset mtick
		m_magicElementalRecast = 15000; // No eligible Elemental Spell to cast
		}	
	}

	return spellID;
}







CBattleEntity* CAIAutomatonDummy::getWounded(uint8 threshold)
{
    uint8 lowest = 100;
    CBattleEntity* mostWounded = nullptr;
    if (m_PPet->PMaster == nullptr)
        return nullptr;
    if (m_PPet->PMaster->GetHPP() < lowest){
        lowest = m_PPet->PMaster->GetHPP();
        mostWounded = m_PPet->PMaster;
		ShowWarning(CL_GREEN"AUTO: Most wounded is Master \n", CL_RESET);
    }
    if (m_PPet->PMaster->PPet != nullptr && m_PPet->PMaster->PPet->GetHPP() < lowest)
    {
        lowest = m_PPet->PMaster->PPet->GetHPP();
        mostWounded = m_PPet->PMaster->PPet;
    }
    if (m_PPet->PMaster->PParty != nullptr && m_PPet->getHead() == HEAD_SOULSOOTHER)  //Only Soulsoother Head can cure other Party Members
    {
        for (auto member : m_PPet->PMaster->PParty->members)
        {
            if ( member->GetHPP() < lowest)
            {
                lowest = member->GetHPP();
                mostWounded = member;
				ShowWarning(CL_GREEN"AUTO: Most wounded is Party \n", CL_RESET);
            }
        }
    }
    if (m_PPet->PMaster->PAlly.size() > 0 && m_PPet->getHead() == HEAD_SOULSOOTHER)  //Only Soulsoother Head can cure other Allies add Soulsoother Head
    {
        for (auto ally : m_PPet->PMaster->PAlly)
        {
            if ( ally->GetHPP() < lowest)
            {
                lowest = ally->GetHPP();
                mostWounded = ally;
				ShowWarning(CL_GREEN"AUTO: Most wounded is Trust \n", CL_RESET);
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


CBattleEntity* CAIAutomatonDummy::getWoundedLow(uint8 threshold)
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


