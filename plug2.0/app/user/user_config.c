/*
 * user_config.c
 *
 *  Created on: 2018年11月2日
 *      Author: lenovo
 */

#include "user_common.h"
#include "esp_common.h"


UINT CONFIG_TimerDataCheck( PLUG_TIMER_S *pstData )
{
	UINT iRet = OK;

	if ( NULL == pstData )
	{
	    LOG_OUT(LOGOUT_ERROR, "CONFIG_DelayDataCheck. pstData:0x%p.", pstData);
		return FAIL;
	}

	if (pstData->uiNum == 0 || pstData->uiNum > PLUG_TIMER_MAX )
	{
		LOG_OUT(LOGOUT_ERROR, "CONFIG_TimerDataCheck. uiNum:%d.", pstData->uiNum);
		iRet = FAIL;
	}

	if ( TRUE != pstData->bEnable && FALSE != pstData->bEnable )
	{
		LOG_OUT(LOGOUT_ERROR, "CONFIG_TimerDataCheck. bEnable:%d.", pstData->bEnable);
		iRet = FAIL;
	}
	if ( TRUE != pstData->bOnEnable && FALSE != pstData->bOnEnable )
	{
		LOG_OUT(LOGOUT_ERROR, "CONFIG_TimerDataCheck. bOnEnable:%d.", pstData->bOnEnable);
		iRet = FAIL;
	}
	if ( TRUE != pstData->bOffEnable && FALSE!= pstData->bOffEnable )
	{
		LOG_OUT(LOGOUT_ERROR, "CONFIG_TimerDataCheck. bOffEnable:%d.", pstData->bOffEnable);
		iRet = FAIL;
	}
	if ( (INT8)23 < pstData->stOnTime.iHour || (INT8)59 < pstData->stOnTime.iMinute)
	{
		LOG_OUT(LOGOUT_ERROR, "CONFIG_TimerDataCheck. stOnTime:%02d:%02d.",
				pstData->stOnTime.iHour, pstData->stOnTime.iMinute);
		iRet = FAIL;
	}
	if ( (INT8)23 < pstData->stOffTime.iHour || (INT8)59 < pstData->stOffTime.iMinute )
	{
		LOG_OUT(LOGOUT_ERROR, "CONFIG_TimerDataCheck. stOffTime:%02d:%02d.",
				pstData->stOffTime.iHour, pstData->stOffTime.iMinute);
		iRet = FAIL;
	}
	if ( REPET_BUFF <= pstData->eWeek )
	{
		LOG_OUT(LOGOUT_ERROR, "CONFIG_TimerDataCheck. eWeek:%d.", pstData->eWeek);
		iRet = FAIL;
	}
	if ( 0 == pstData->szName[0] || 255 == pstData->szName[0])
	{
		LOG_OUT(LOGOUT_ERROR, "CONFIG_TimerDataCheck. szName:%d.", pstData->szName);
		iRet = FAIL;
	}
	if ( TRUE != pstData->bCascode && FALSE != pstData->bCascode)
	{
		LOG_OUT(LOGOUT_ERROR, "CONFIG_TimerDataCheck. bCascode:%d.", pstData->bCascode);
		iRet = FAIL;
	}
	if ( PLUG_DELAY_MAX < pstData->uiCascodeNum )
	{
		LOG_OUT(LOGOUT_ERROR, "CONFIG_TimerDataCheck. uiCascodeNum:%d.", pstData->uiCascodeNum);
		iRet = FAIL;
	}

	return iRet;
}

UINT CONFIG_DelayDataCheck( PLUG_DELAY_S *pstData )
{
	UINT iRet = OK;

	if ( NULL == pstData )
	{
	    LOG_OUT(LOGOUT_ERROR, "CONFIG_DelayDataCheck. pstData = 0x%p.", pstData);
	    iRet = FAIL;
	}

	if (pstData->uiNum == 0 || pstData->uiNum > PLUG_TIMER_MAX )
	{
		LOG_OUT(LOGOUT_ERROR, "CONFIG_DelayDataCheck. uiNum:%d.", pstData->uiNum);
		iRet = FAIL;
	}

	if ( TRUE != pstData->bEnable && FALSE!= pstData->bEnable )
	{
		LOG_OUT(LOGOUT_ERROR, "CONFIG_DelayDataCheck. bEnable:%d.", pstData->bEnable);
		iRet = FAIL;
	}
	if ( TRUE != pstData->bOnEnable && FALSE!= pstData->bOnEnable )
	{
		LOG_OUT(LOGOUT_ERROR, "CONFIG_DelayDataCheck. bOnEnable:%d.", pstData->bOnEnable);
		iRet = FAIL;
	}
	if ( TRUE != pstData->bOffEnable && FALSE != pstData->bOffEnable )
	{
		LOG_OUT(LOGOUT_ERROR, "CONFIG_DelayDataCheck. bOffEnable:%d.", pstData->bOffEnable);
		iRet = FAIL;
	}
	if ( (INT8)23 < pstData->stOnInterval.iHour || (INT8)59 < pstData->stOnInterval.iMinute )
	{
		LOG_OUT(LOGOUT_ERROR, "CONFIG_DelayDataCheck. stOnInterval:%02d:%02d.",
				pstData->stOnInterval.iHour, pstData->stOnInterval.iMinute);
		iRet = FAIL;
	}
	if ( (INT8)23 < pstData->stOffInterval.iHour || (INT8)59 < pstData->stOffInterval.iMinute )
	{
		LOG_OUT(LOGOUT_ERROR, "CONFIG_DelayDataCheck. stOffInterval:%02d:%02d.",
				pstData->stOffInterval.iHour, pstData->stOffInterval.iMinute);
		iRet = FAIL;
	}
	if ( 9999 < pstData->uiCycleTimes )
	{
		LOG_OUT(LOGOUT_ERROR, "CONFIG_DelayDataCheck. uiCycleTimes:%d.", pstData->uiCycleTimes);
		iRet = FAIL;
	}
	if ( 9999 < pstData->uiTmpCycleTimes )
	{
		LOG_OUT(LOGOUT_ERROR, "CONFIG_DelayDataCheck. uiTmpCycleTimes:%d.", pstData->uiTmpCycleTimes);
		iRet = FAIL;
	}
	if ( 0 == pstData->szName[0] || 255 == pstData->szName[0])
	{
		LOG_OUT(LOGOUT_ERROR, "CONFIG_DelayDataCheck. szName:%d.", pstData->szName);
		iRet = FAIL;
	}
	if ( TRUE != pstData->bCascode && FALSE != pstData->bCascode)
	{
		LOG_OUT(LOGOUT_ERROR, "CONFIG_DelayDataCheck. bCascode:%d.", pstData->bCascode);
		iRet = FAIL;
	}
	if ( PLUG_DELAY_MAX < pstData->uiCascodeNum )
	{
		LOG_OUT(LOGOUT_ERROR, "CONFIG_DelayDataCheck. uiCascodeNum:%d.", pstData->uiCascodeNum);
		iRet = FAIL;
	}

	return iRet;
}

UINT CONFIG_SysSetDataCheck( PLUG_SYSSET_S *pstData )
{
	if ( NULL == pstData )
	{
	    LOG_OUT(LOGOUT_ERROR, "CONFIG_SysSetDataCheck. pstData = 0x%p.", pstData);
		return FAIL;
	}

	if ( pstData->bRelayStatus != 0 && pstData->bRelayStatus != 1 )
	{
	    LOG_OUT(LOGOUT_ERROR, "bRelayStatus:%d.", pstData->bRelayStatus);
		return FAIL;
	}

	if ( pstData->ucWifiMode != WIFI_MODE_STATION &&
			pstData->ucWifiMode != WIFI_MODE_SOFTAP )
	{
	    LOG_OUT(LOGOUT_ERROR, "ucWifiMode:%d.", pstData->ucWifiMode);
		return FAIL;
	}

	if ( pstData->szPlugName[0] == 0 || pstData->szPlugName[0] == 0xFF )
	{
	    LOG_OUT(LOGOUT_ERROR, "szPlugName is NULL");
		return FAIL;
	}

	return OK;
}
/*
static UINT CONFIG_HtmlDataCheck( HTTP_FILE_LIST_S *pstData )
{
	UINT uiLoopi = 0;

	if ( NULL == pstData )
	{
	    LOG_OUT(LOGOUT_ERROR, "CONFIG_HtmlDataCheck. pstData = 0x%p.", pstData);
		return FAIL;
	}

	for ( uiLoopi = 0 ; uiLoopi < HTTP_FILE_NUM_MAX; uiLoopi++, pstData++ )
	{
		if ( pstData->szName[0] == 0 )
		{
			LOG_OUT(LOGOUT_ERROR, "CONFIG_HtmlDataCheck. szName is NULL.");
		    break;
		}

		//if ( pstData->uiAddr == 0 )
		//{
		//	LOG_OUT(LOGOUT_ERROR, "CONFIG_HtmlDataCheck. uiAddr = %d.", pstData->uiAddr);
		//    break;
		//}

		if ( pstData->uiLength == 0xFFFFFFFF )
		{
			LOG_OUT(LOGOUT_ERROR, "CONFIG_HtmlDataCheck. uiLength = %d.", pstData->uiLength);
		    break;
		}
	}

	if ( HTTP_FILE_NUM_MAX > uiLoopi )
	{
		LOG_OUT(LOGOUT_ERROR, "CONFIG_HtmlDataCheck. pstData[%d] check failed.", uiLoopi);
		return FAIL;
	}
	return OK;
}
*/

UINT CONFIG_ReadConfig( PLUG_MOUDLE_E uiMoudle )
{
	UINT uiFlashId = 0;
	UINT uiRet = 0;
	UINT uiLoop = 0;

	/* 判断FLASH是否可正常读取 */
	uiFlashId = spi_flash_get_id();
	if ( 0 == uiFlashId )
	{
		/* 读取配置失败,使用默认配置 */
		PLUG_TimerDataDeInit();
		PLUG_DelayDataDeInit();
		PLUG_SystemSetDataDeInit();
		HTTP_FileListInit();
		CONFIG_SaveConfig(PLUG_MOUDLE_BUFF);
	    LOG_OUT(LOGOUT_INFO, "Flash check failed, Loaded Default Config.");
		return FAIL;
	}
	//LOG_OUT(LOGOUT_DEBUG, "uiFlashId:0x%X.", uiFlashId);

	if ( uiMoudle & PLUG_MOUDLE_TIMER )
	{
	    LOG_OUT(LOGOUT_INFO, "Read timer data...");
		uiRet = FlASH_Read((UINT32)FLASH_TIMER_ADDR, (CHAR*)PLUG_GetTimerData(0), PLUG_GetTimerDataSize());
		if ( OK != uiRet )
		{
		    LOG_OUT(LOGOUT_ERROR, "FlASH_Read timer data failed, uiRet:%d", uiRet);
			uiRet |= FAIL;
		}
		else
		{
			for ( uiLoop = 0; uiLoop < PLUG_TIMER_MAX; uiLoop++ )
			{
				uiRet = CONFIG_TimerDataCheck( PLUG_GetTimerData(uiLoop) );
				if ( OK != uiRet )
				{
					/* 读取配置失败,使用默认配置 */
					PLUG_TimerDataDeInit();
					CONFIG_SaveConfig(PLUG_MOUDLE_TIMER);
					LOG_OUT(LOGOUT_ERROR, "TimerDataCheck failed, Loaded Default Config.");
					break;
				}
			}
		}
	}


	if ( uiMoudle & PLUG_MOUDLE_DELAY )
	{
	    LOG_OUT(LOGOUT_INFO, "Read delay data...");
	    uiRet = FlASH_Read((UINT32)FLASH_DELAY_ADDR, (CHAR*)PLUG_GetDelayData(0), PLUG_GetDelayDataSize());
		if ( OK != uiRet )
		{
		    LOG_OUT(LOGOUT_ERROR, "FlASH_Read delay data failed.");
			uiRet |= FAIL;
		}
		else
		{
			for ( uiLoop = 0; uiLoop < PLUG_TIMER_MAX; uiLoop++ )
			{
				uiRet = CONFIG_DelayDataCheck( PLUG_GetDelayData(uiLoop) );
				if ( OK != uiRet )
				{
					/* 读取配置失败,使用默认配置 */
					PLUG_DelayDataDeInit();
					CONFIG_SaveConfig(PLUG_MOUDLE_DELAY);
					LOG_OUT(LOGOUT_ERROR, "DelayDataCheck failed, Loaded Default Config.");
					break;
				}
			}
		}
	}

	if ( uiMoudle & PLUG_MOUDLE_SYSSET )
	{
	    LOG_OUT(LOGOUT_INFO, "Read system set data...");
	    uiRet = FlASH_Read((UINT32)FLASH_SYSSET_ADDR, (CHAR*)PLUG_GetSystemSetData(), PLUG_GetSystemSetDataSize());
		if ( OK != uiRet )
		{
		    LOG_OUT(LOGOUT_ERROR, "FlASH_Read sysset data failed.");
			uiRet |= FAIL;
		}
		else
		{
			uiRet = CONFIG_SysSetDataCheck( PLUG_GetSystemSetData() );
			if ( OK != uiRet )
			{
				/* 读取配置失败,使用默认配置 */
				PLUG_SystemSetDataDeInit();
				CONFIG_SaveConfig(PLUG_MOUDLE_SYSSET);
				LOG_OUT(LOGOUT_ERROR, "DelayDataCheck failed, Loaded Default Config.");
				uiRet |= FAIL;

			}
		}
	}

	if ( uiMoudle & PLUG_MOUDLE_FILELIST )
	{
	    LOG_OUT(LOGOUT_INFO, "Read html data...");
		uiRet = FlASH_Read((UINT32)FLASH_HTML_ADDR, (VOID*)HTTP_GetFileList(NULL), HTTP_GetFileListLength());
		if ( OK != uiRet )
		{
		    LOG_OUT(LOGOUT_ERROR, "FlASH_Read html data failed.");
			uiRet |= FAIL;
		}
	}

	/* 上电时关闭所有延时任务 */
	PLUG_SetDelayTurnOff(PLUG_DELAY_MAX);
	PLUG_SetRelayByStatus( PLUG_GetRelayStatus(), FALSE );

	return uiRet;
}


UINT CONFIG_SaveConfig( PLUG_MOUDLE_E uiMoudle )
{
	UINT uiRet = 0;

	if ( uiMoudle & PLUG_MOUDLE_TIMER )
	{
		uiRet = FlASH_Write(FLASH_TIMER_ADDR, (CHAR*)PLUG_GetTimerData(0), PLUG_GetTimerDataSize());
		if ( OK != uiRet )
		{
			LOG_OUT(LOGOUT_ERROR, "FlASH_Write timer data failed.");
			uiRet |= FAIL;
		}
	}

	if ( uiMoudle & PLUG_MOUDLE_DELAY )
	{
		uiRet = FlASH_Write(FLASH_DELAY_ADDR, (CHAR*)PLUG_GetDelayData(0), PLUG_GetDelayDataSize());
		if ( OK != uiRet )
		{
			LOG_OUT(LOGOUT_ERROR, "FlASH_Write delay data failed.");
			uiRet |= FAIL;
		}
	}

	if ( uiMoudle & PLUG_MOUDLE_SYSSET )
	{
		uiRet = FlASH_Write(FLASH_SYSSET_ADDR, (CHAR*)PLUG_GetSystemSetData(), PLUG_GetSystemSetDataSize());
		if ( OK != uiRet )
		{
			LOG_OUT(LOGOUT_ERROR, "FlASH_Write SystemSet data failed.");
			uiRet |= FAIL;
		}
	}

	if ( uiMoudle & PLUG_MOUDLE_FILELIST )
	{
		uiRet = FlASH_Write(FLASH_HTML_ADDR, (CHAR*)HTTP_GetFileList(NULL), HTTP_GetFileListLength());
		if ( OK != uiRet )
		{
			LOG_OUT(LOGOUT_ERROR, "FlASH_Write html data failed.");
			uiRet |= FAIL;
		}
	}

	return uiRet;
}
