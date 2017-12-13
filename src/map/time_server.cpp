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

#include "../common/showmsg.h"

#include "utils/guildutils.h"
#include "utils/instanceutils.h"
#include "time_server.h"
#include "transport.h"
#include "vana_time.h"
#include "utils/zoneutils.h"
#include "conquest_system.h"
#include "lua/luautils.h"
#include "entities/charentity.h"


int32 time_server(uint32 tick,CTaskMgr::CTask* PTask)
{
    TIMETYPE VanadielTOTD = CVanaTime::getInstance()->SyncTime();
    uint8 WeekDay = (uint8)CVanaTime::getInstance()->getWeekday();

    // weekly update for conquest (sunday at midnight)
    if (CVanaTime::getInstance()->getSysWeekDay() == 0  && CVanaTime::getInstance()->getSysHour() == 0 && CVanaTime::getInstance()->getSysMinute() == 0)
    {
		int32 ahfees = 100;
		const int8* Query = "SELECT SUM(quantity), bazaar, itemID  FROM `char_inventory` WHERE itemID = '65535'";
		int32 ret = Sql_Query(SqlHandle, Query);
		if (ret != SQL_ERROR && Sql_NumRows(SqlHandle) != 0 && Sql_NextRow(SqlHandle) == SQL_SUCCESS)
		{
			ahfees = (int32)Sql_GetIntData(SqlHandle, 0);
			//ahfees = ahfees / 1000000;
			ShowWarning(CL_CYAN"Running daily Gil analytics.  Total Gil is: %i \n" CL_RESET, ahfees);
			uint32 calltime = time(nullptr);
			Sql_Query(SqlHandle, "INSERT INTO server_gil (call_date, gil_value) VALUES (%u, %u);",calltime, ahfees);
		}	
        if (tick > (CVanaTime::getInstance()->lastConquestTally + 60000))
        {
            conquest::UpdateWeekConquest();
            CVanaTime::getInstance()->lastConquestTally = tick;
        }
    }

   	
    // hourly conquest update
    else if (CVanaTime::getInstance()->getSysMinute() == 0)
    {
        if (tick > (CVanaTime::getInstance()->lastConquestUpdate + 60000))
        {
            conquest::UpdateConquestSystem();
            CVanaTime::getInstance()->lastConquestUpdate = tick;
        }
    }
	


    if (CVanaTime::getInstance()->getMinute() == 0)
    {
        if (tick > (CVanaTime::getInstance()->lastVHourlyUpdate + 4800))
        {
			zoneutils::ForEachZone([](CZone* PZone)
            {
                luautils::OnGameHour(PZone);
				PZone->ForEachChar([](CCharEntity* PChar)
				{
					PChar->PLatentEffectContainer->CheckLatentsHours();
					PChar->PLatentEffectContainer->CheckLatentsMoonPhase();
				});
			});

            CVanaTime::getInstance()->lastVHourlyUpdate = tick;
        }

    }

    //Midnight
    if (CVanaTime::getInstance()->getSysHour() == 0 && CVanaTime::getInstance()->getSysMinute() == 0 && CVanaTime::getInstance()->getSysSecond() == 0)
    {
		int32 ahfees = 100;
		const int8* Query = "SELECT SUM(quantity), bazaar, itemID  FROM `char_inventory` WHERE itemID = '65535'";
		int32 ret = Sql_Query(SqlHandle, Query);
		if (ret != SQL_ERROR && Sql_NumRows(SqlHandle) != 0 && Sql_NextRow(SqlHandle) == SQL_SUCCESS)
		{
			ahfees = (int32)Sql_GetIntData(SqlHandle, 0);
			//ahfees = ahfees / 1000000;
			ShowWarning(CL_GREEN"Running daily Gil analytics.  Total Gil is: %i \n" CL_RESET, ahfees);
			uint32 calltime = time(nullptr);
			Sql_Query(SqlHandle, "INSERT INTO server_gil (call_date, gil_value) VALUES (%u, %u);",calltime, ahfees);
		}	
        if (tick > (CVanaTime::getInstance()->lastMidnight + 60000))
        {
            guildutils::UpdateGuildPointsPattern();
            CVanaTime::getInstance()->lastMidnight = tick;
        }
    }
	
	//Midnight Online
    if (CVanaTime::getInstance()->getSysHour() == 0 && CVanaTime::getInstance()->getSysMinute() == 0 && CVanaTime::getInstance()->getSysSecond() == 0)
	//if (CVanaTime::getInstance()->getSysSecond() == 30)
    {
		int32 online = 100;
		const int8* Query = "SELECT COUNT(accid), charid FROM `accounts_sessions`";
		int32 ret = Sql_Query(SqlHandle, Query);
		if (ret != SQL_ERROR && Sql_NumRows(SqlHandle) != 0 && Sql_NextRow(SqlHandle) == SQL_SUCCESS)
		{
			online = (int32)Sql_GetIntData(SqlHandle, 0);
			//ahfees = ahfees / 1000000;
			ShowWarning(CL_CYAN"Running 3 Hour player analytics.  Total Online is: %i \n" CL_RESET, online);
			uint32 calltime = time(nullptr);
			Sql_Query(SqlHandle, "INSERT INTO total_online (call_date, players_online) VALUES (%u, %u);",calltime, online);
		}	
        if (tick > (CVanaTime::getInstance()->lastMidnight + 60000))
        {
            guildutils::UpdateGuildPointsPattern();
            CVanaTime::getInstance()->lastMidnight = tick;
        }
    }	
	
	
    if (CVanaTime::getInstance()->getSysHour() == 3 && CVanaTime::getInstance()->getSysMinute() == 0 && CVanaTime::getInstance()->getSysSecond() == 0)
	//if (CVanaTime::getInstance()->getSysSecond() == 30)
    {
		int32 online = 100;
		const int8* Query = "SELECT COUNT(accid), charid FROM `accounts_sessions`";
		int32 ret = Sql_Query(SqlHandle, Query);
		if (ret != SQL_ERROR && Sql_NumRows(SqlHandle) != 0 && Sql_NextRow(SqlHandle) == SQL_SUCCESS)
		{
			online = (int32)Sql_GetIntData(SqlHandle, 0);
			//ahfees = ahfees / 1000000;
			ShowWarning(CL_CYAN"Running 3 Hour player analytics.  Total Online is: %i \n" CL_RESET, online);
			uint32 calltime = time(nullptr);
			Sql_Query(SqlHandle, "INSERT INTO total_online (call_date, players_online) VALUES (%u, %u);",calltime, online);
		}	
        if (tick > (CVanaTime::getInstance()->lastMidnight + 60000))
        {
            guildutils::UpdateGuildPointsPattern();
            CVanaTime::getInstance()->lastMidnight = tick;
        }
    }
	
    if (CVanaTime::getInstance()->getSysHour() == 6 && CVanaTime::getInstance()->getSysMinute() == 0 && CVanaTime::getInstance()->getSysSecond() == 0)
	//if (CVanaTime::getInstance()->getSysSecond() == 30)
    {
		int32 online = 100;
		const int8* Query = "SELECT COUNT(accid), charid FROM `accounts_sessions`";
		int32 ret = Sql_Query(SqlHandle, Query);
		if (ret != SQL_ERROR && Sql_NumRows(SqlHandle) != 0 && Sql_NextRow(SqlHandle) == SQL_SUCCESS)
		{
			online = (int32)Sql_GetIntData(SqlHandle, 0);
			//ahfees = ahfees / 1000000;
			ShowWarning(CL_CYAN"Running 3 Hour player analytics.  Total Online is: %i \n" CL_RESET, online);
			uint32 calltime = time(nullptr);
			Sql_Query(SqlHandle, "INSERT INTO total_online (call_date, players_online) VALUES (%u, %u);",calltime, online);
		}	
        if (tick > (CVanaTime::getInstance()->lastMidnight + 60000))
        {
            guildutils::UpdateGuildPointsPattern();
            CVanaTime::getInstance()->lastMidnight = tick;
        }
    }

    if (CVanaTime::getInstance()->getSysHour() == 9 && CVanaTime::getInstance()->getSysMinute() == 0 && CVanaTime::getInstance()->getSysSecond() == 0)
	//if (CVanaTime::getInstance()->getSysSecond() == 30)
    {
		int32 online = 100;
		const int8* Query = "SELECT COUNT(accid), charid FROM `accounts_sessions`";
		int32 ret = Sql_Query(SqlHandle, Query);
		if (ret != SQL_ERROR && Sql_NumRows(SqlHandle) != 0 && Sql_NextRow(SqlHandle) == SQL_SUCCESS)
		{
			online = (int32)Sql_GetIntData(SqlHandle, 0);
			//ahfees = ahfees / 1000000;
			ShowWarning(CL_CYAN"Running 3 Hour player analytics.  Total Online is: %i \n" CL_RESET, online);
			uint32 calltime = time(nullptr);
			Sql_Query(SqlHandle, "INSERT INTO total_online (call_date, players_online) VALUES (%u, %u);",calltime, online);
		}	
        if (tick > (CVanaTime::getInstance()->lastMidnight + 60000))
        {
            guildutils::UpdateGuildPointsPattern();
            CVanaTime::getInstance()->lastMidnight = tick;
        }
    }

    if (CVanaTime::getInstance()->getSysHour() == 12 && CVanaTime::getInstance()->getSysMinute() == 0 && CVanaTime::getInstance()->getSysSecond() == 0)
	//if (CVanaTime::getInstance()->getSysSecond() == 30)
    {
		int32 online = 100;
		const int8* Query = "SELECT COUNT(accid), charid FROM `accounts_sessions`";
		int32 ret = Sql_Query(SqlHandle, Query);
		if (ret != SQL_ERROR && Sql_NumRows(SqlHandle) != 0 && Sql_NextRow(SqlHandle) == SQL_SUCCESS)
		{
			online = (int32)Sql_GetIntData(SqlHandle, 0);
			//ahfees = ahfees / 1000000;
			ShowWarning(CL_CYAN"Running 3 Hour player analytics.  Total Online is: %i \n" CL_RESET, online);
			uint32 calltime = time(nullptr);
			Sql_Query(SqlHandle, "INSERT INTO total_online (call_date, players_online) VALUES (%u, %u);",calltime, online);
		}	
        if (tick > (CVanaTime::getInstance()->lastMidnight + 60000))
        {
            guildutils::UpdateGuildPointsPattern();
            CVanaTime::getInstance()->lastMidnight = tick;
        }
    }

    if (CVanaTime::getInstance()->getSysHour() == 15 && CVanaTime::getInstance()->getSysMinute() == 0 && CVanaTime::getInstance()->getSysSecond() == 0)
	//if (CVanaTime::getInstance()->getSysSecond() == 30)
    {
		int32 online = 100;
		const int8* Query = "SELECT COUNT(accid), charid FROM `accounts_sessions`";
		int32 ret = Sql_Query(SqlHandle, Query);
		if (ret != SQL_ERROR && Sql_NumRows(SqlHandle) != 0 && Sql_NextRow(SqlHandle) == SQL_SUCCESS)
		{
			online = (int32)Sql_GetIntData(SqlHandle, 0);
			//ahfees = ahfees / 1000000;
			ShowWarning(CL_CYAN"Running 3 Hour player analytics.  Total Online is: %i \n" CL_RESET, online);
			uint32 calltime = time(nullptr);
			Sql_Query(SqlHandle, "INSERT INTO total_online (call_date, players_online) VALUES (%u, %u);",calltime, online);
		}	
        if (tick > (CVanaTime::getInstance()->lastMidnight + 60000))
        {
            guildutils::UpdateGuildPointsPattern();
            CVanaTime::getInstance()->lastMidnight = tick;
        }
    }

    if (CVanaTime::getInstance()->getSysHour() == 18 && CVanaTime::getInstance()->getSysMinute() == 0 && CVanaTime::getInstance()->getSysSecond() == 0)
	//if (CVanaTime::getInstance()->getSysSecond() == 30)
    {
		int32 online = 100;
		const int8* Query = "SELECT COUNT(accid), charid FROM `accounts_sessions`";
		int32 ret = Sql_Query(SqlHandle, Query);
		if (ret != SQL_ERROR && Sql_NumRows(SqlHandle) != 0 && Sql_NextRow(SqlHandle) == SQL_SUCCESS)
		{
			online = (int32)Sql_GetIntData(SqlHandle, 0);
			//ahfees = ahfees / 1000000;
			ShowWarning(CL_CYAN"Running 3 Hour player analytics.  Total Online is: %i \n" CL_RESET, online);
			uint32 calltime = time(nullptr);
			Sql_Query(SqlHandle, "INSERT INTO total_online (call_date, players_online) VALUES (%u, %u);",calltime, online);
		}	
        if (tick > (CVanaTime::getInstance()->lastMidnight + 60000))
        {
            guildutils::UpdateGuildPointsPattern();
            CVanaTime::getInstance()->lastMidnight = tick;
        }
    }

    if (CVanaTime::getInstance()->getSysHour() == 21 && CVanaTime::getInstance()->getSysMinute() == 0 && CVanaTime::getInstance()->getSysSecond() == 0)
	//if (CVanaTime::getInstance()->getSysSecond() == 30)
    {
		int32 online = 100;
		const int8* Query = "SELECT COUNT(accid), charid FROM `accounts_sessions`";
		int32 ret = Sql_Query(SqlHandle, Query);
		if (ret != SQL_ERROR && Sql_NumRows(SqlHandle) != 0 && Sql_NextRow(SqlHandle) == SQL_SUCCESS)
		{
			online = (int32)Sql_GetIntData(SqlHandle, 0);
			//ahfees = ahfees / 1000000;
			ShowWarning(CL_CYAN"Running 3 Hour player analytics.  Total Online is: %i \n" CL_RESET, online);
			uint32 calltime = time(nullptr);
			Sql_Query(SqlHandle, "INSERT INTO total_online (call_date, players_online) VALUES (%u, %u);",calltime, online);
		}	
        if (tick > (CVanaTime::getInstance()->lastMidnight + 60000))
        {
            guildutils::UpdateGuildPointsPattern();
            CVanaTime::getInstance()->lastMidnight = tick;
        }
    }	
	

    if (CVanaTime::getInstance()->getHour() == 0 && CVanaTime::getInstance()->getMinute() == 0)
    {
        if (tick > (CVanaTime::getInstance()->lastVDailyUpdate + 4800))
        {
			zoneutils::ForEachZone([](CZone* PZone)
			{
                luautils::OnGameDay(PZone);
				PZone->ForEachChar([](CCharEntity* PChar)
				{
					PChar->PLatentEffectContainer->CheckLatentsWeekDay();
				});
			});

            guildutils::UpdateGuildsStock();
            zoneutils::SavePlayTime();

            CVanaTime::getInstance()->lastVDailyUpdate = tick;
        }
    }

    if (VanadielTOTD != TIME_NONE)
    {
        zoneutils::TOTDChange(VanadielTOTD);

        if ((VanadielTOTD == TIME_DAY) || (VanadielTOTD == TIME_DUSK) || (VanadielTOTD == TIME_NIGHT))
        {
			zoneutils::ForEachZone([](CZone* PZone)
			{
				PZone->ForEachChar([](CCharEntity* PChar)
				{
					PChar->PLatentEffectContainer->CheckLatentsDay();
					PChar->PLatentEffectContainer->CheckLatentsJobLevel();
				});
			});
        }
    }

    CTransportHandler::getInstance()->TransportTimer();
	instanceutils::CheckInstance();
    return 0;
}