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

#ifndef _CAIAUTODUMMY_H
#define _CAIAUTODUMMY_H

#include "../../common/cbasetypes.h"

#include "ai_general.h"
#include "ai_pet_dummy.h"

/************************************************************************
*																		*
*																		*
*																		*
************************************************************************/

class CPetEntity;
class CAutomatonEntity;

class CAIAutomatonDummy : public CAIPetDummy
{
public:
    virtual void CheckCurrentAction(uint32 tick);

    CAIAutomatonDummy(CPetEntity* PPet);

protected:


private:
    CAutomatonEntity* m_PPet;

    uint32 m_magicRecast;
    uint32 m_magicEnfeebleRecast;
	uint32 m_magicEnfeebCast;
    uint32 m_magicElementalRecast;
	uint32 m_magicElementCast;
    uint32 m_magicHealRecast;
	uint32 m_magicHealCast;
    uint32 m_magicEnhanceRecast;
	uint32 m_magicEnhanceCast;
    uint32 m_magicStatusRecast;
	uint32 m_rangedRecast;
	uint32 m_magicAspir;
	uint32 m_magicDrain;
	
	
	uint32 m_magicStatusCast;
	uint32 m_attachmentRecast;

	uint32 m_damageGauge;
	
	uint32 m_strobeRecast;
	uint32 m_bashRecast;
	uint32 m_flashRecast;
	uint32 m_barrageRecast;
	uint32 m_convertRecast;
	uint32 m_stoneskinRecast;
	
	
	

    void ActionFall();
    void ActionAttack();
	void ActionSpawn();
	void ActionRoaming();
	void ActionAbilityStart();
	void ActionAbilityFinish();
	void ActionMagicStart();
	void ActionMagicCasting();
	void ActionMagicFinish();
	void ActionMagicInterrupt();
	

    bool CheckSpellcast();
    bool CheckTPMove();
    bool CheckRangedAttack();

	int16 StormFrameStormAttack();	
	int16 StormFrameSoulAttack();
	int16 StormFrameSpiritAttack();
	int16 LightEnfeeb();
	int16 SharpshotAttack();
	int16 HarleAttack();
	CBattleEntity* getWounded(uint8 threshold);
	CBattleEntity* getWoundedLow(uint8 threshold);
	

    virtual void TransitionBack(bool skipWait = false) override;

};

#endif
