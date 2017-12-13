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

#ifndef _CCHATMESSAGEPACKET_H
#define _CCHATMESSAGEPACKET_H

#include "../../common/cbasetypes.h"

#include "basic.h"

enum CHAT_MESSAGE_TYPE
{
    MESSAGE_SAY         = 0x00,
    MESSAGE_SHOUT       = 0x01,
    MESSAGE_UNKNOWN     = 0x02,
    MESSAGE_TELL        = 0x03,
    MESSAGE_PARTY       = 0x04,
    MESSAGE_LINKSHELL   = 0x05,
    MESSAGE_SYSTEM_1    = 0x06,
    MESSAGE_SYSTEM_2    = 0x07,
    MESSAGE_EMOTION     = 0x08,
	
    MESSAGE_NS_SAY        = 0x0D, // Same as MESSAGESAY but has no speaker object displayed
    MESSAGE_NS_SHOUT      = 0x0E, // Same as MESSAGESHOUT but has no speaker object displayed
    MESSAGE_NS_PARTY      = 0x0F, // Same as MESSAGEPARTY but has no speaker object displayed
    MESSAGE_NS_LINKSHELL  = 0x10, // Same as MESSAGELINKSHELL but has no speaker object displayed
    MESSAGE_UNKNOWN_17    = 0x11, // 17 through 25 appear to repeat the effects of other values	
	
	
	
    MESSAGE_YELL        = 0x1A,
    MESSAGE_LINKSHELL2  = 0x1B,
	MESSAGE_LOGON       = 0x1C,
	MESSAGE_UNITY       = 0x21,
};

/************************************************************************
*																		*
*  																		*
*																		*
************************************************************************/

class CCharEntity;

class CChatMessagePacket : public CBasicPacket
{
public:
    static const uint16 id {0x17};
	CChatMessagePacket(CCharEntity* PChar, CHAT_MESSAGE_TYPE MessageType, int8* buff);
};

#endif