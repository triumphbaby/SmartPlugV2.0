/*
 * user_plug.h
 *
 *  Created on: 2018年11月2日
 *      Author: lenovo
 */

#ifndef __USER_PLUG_H__
#define __USER_PLUG_H__



#define PLUG_NAME_MAX_LEN 		32
#define PLUG_WIFI_SSID_LEN 		32
#define PLUG_WIFI_PASSWD_LEN 	64

#define PLUG_TIMER_MAX    		10
#define PLUG_DELAY_MAX    		10

#define PLUG_TIMER_ALL    		(PLUG_TIMER_MAX + 1)
#define PLUG_DELAY_ALL    		(PLUG_DELAY_MAX + 1)


#define PLUG_NAME  	"SmartPlug"



typedef struct tagPLUG_DATE
{
	INT32 	iYear;						/*  年    */
	INT8 	iMonth;						/*  月    */
	INT8 	iDay;						/*  日    */
	INT8    iWeek;						/*  星期  */
	INT8 	iHour;						/*  时    */
	INT8 	iMinute;					/*  分    */
	INT8 	iSecond;					/*  秒    */

}PLUG_DATE_S;

typedef struct tagPLUG_TIME_POINT
{
	INT8 	iDay;						/*  第二天    */
	INT8 	iHour;						/*  时    */
	INT8 	iMinute;					/*  分    */

}PLUG_TIME_POINT_S;


typedef enum
{
	REPET_ONCE		= 0x00,		/* 执行一次 */
	REPET_MON		= 0x01,		/* 每周一 */
	REPET_TUE		= 0x02,		/* 每周二 */
	REPET_WED		= 0x04,		/* 每周三 */
	REPET_THU		= 0x08,		/* 每周四 */
	REPET_FRI		= 0x10,		/* 每周五 */
	REPET_SAT		= 0x20,		/* 每周六 */
	REPET_SUN		= 0x40,		/* 每周日 */
	REPET_ALL		= 0x7F,		/* 每天 */

	REPET_BUFF
}PLUG_REPETITION_E;


typedef struct tagPLUG_TIMER							/*  定时模块    */
{
	UINT				uiNum;							/* 定时器编号 */
	CHAR    			szName[PLUG_NAME_MAX_LEN];		/* 名字 		*/
	BOOL				bEnable;						/* 使能 		*/
	BOOL				bOnEnable;						/* 开启时间使能	*/
	BOOL				bOffEnable;						/* 关闭时间使能	*/
	PLUG_TIME_POINT_S 	stOnTime;						/* 开启时间		*/
	PLUG_TIME_POINT_S 	stOffTime;						/* 关闭时间		*/
	PLUG_REPETITION_E	eWeek;							/* 重复设置		*/
	BOOL				bCascode;						/* 级联使能 	*/
	UINT				uiCascodeNum;					/* 与那个延时级联 */

}PLUG_TIMER_S;



typedef struct tagPLUG_DELAY							/*  延时模块    */
{
	UINT				uiNum;							/* 延时编号 */
	CHAR    			szName[PLUG_NAME_MAX_LEN];		/* 名字 		*/
	BOOL				bEnable;						/* 使能 		*/
	BOOL				bOnEnable;						/* 开启时间使能	*/
	BOOL				bOffEnable;						/* 关闭时间使能	*/
	PLUG_TIME_POINT_S	stOnInterval;					/* 开启时间间隔 */
	PLUG_TIME_POINT_S	stOffInterval;					/* 关闭时间间隔 */
	UINT				uiCycleTimes;					/* 循环次数     */
	UINT				uiTmpCycleTimes;				/* 存放临时循环次数     */
	BOOL				bCascode;						/* 级联使能 	*/
	UINT				uiCascodeNum;					/* 与那个延时级联 */
	UINT8				ucSwFlag;						/* 当前需要计算开启时间还是关闭时间，2:off,1:on,0:都不 */
	PLUG_TIME_POINT_S stTimePoint;						/* 开启还是关闭时间点 */

}PLUG_DELAY_S;


typedef struct tagPLUG_SYSSET							/*  系统模块    */
{
	BOOL 	bRelayStatus;								/*  继电器状态    */
	BOOL 	bSmartConfigFlag;							/*  smart config是否配置    */
	UINT8 	ucWifiMode;									/* esp8266工作模式  1:station 2:ap */
	CHAR 	szPlugName[PLUG_NAME_MAX_LEN+1];			/* hostname  */
	CHAR    szWifiSSID[PLUG_WIFI_SSID_LEN+1];
	CHAR    szWifiPasswd[PLUG_WIFI_PASSWD_LEN+1];
}PLUG_SYSSET_S;

typedef enum
{
	ACTION_REBOOT		= 0,		/* 重启 */
	ACTION_RESET		= 1,		/* 恢复出厂设置 */

	ACTION_BUFF
}PLUG_ACTION_E;


typedef struct tagPLUG_DevCtl							/* 控制设备动作     */
{
	UINT8 	ucAction;									/* 控制设备动作 */

}PLUG_DEVCTL_S;

typedef enum
{
	TIME_SYNC_NONE		= 0,		/* 未同步 */
	TIME_SYNC_NET		= 1,		/* 已同步络时间 */
	TIME_SYNC_MAN		= 2,		/* 已通过手工同步 */

	TIME_SYNC_BUFF
}PLUG_TIME_SYNC_E;


UINT8 PLUG_GetWifiMode( VOID );
VOID PLUG_SetWifiMode( UINT8 ucWifiMode );
CHAR* PLUG_GetWifiSsid( VOID );
UINT PLUG_GetWifiSsidLenth( VOID );
VOID PLUG_SetWifiSsid( CHAR* pcWifiSsid );
CHAR* PLUG_GetWifiPasswd( VOID );
VOID PLUG_SetWifiPasswd( CHAR* pcWifiPasswd );
UINT PLUG_GetWifiPasswdLenth( VOID );

CHAR* PLUG_GetPlugName( VOID );
VOID PLUG_SetPlugName( CHAR* pcPlugName );
UINT PLUG_GetPlugNameLenth( VOID );

VOID PLUG_SetRelayReversal( UINT uiSaveFlag );
VOID PLUG_SetRelayOff( UINT uiSaveFlag );
VOID PLUG_SetRelayOn( UINT uiSaveFlag );
UINT8 PLUG_GetRelayStatus( VOID );
//BOOL PLUG_GetSmartConfig( VOID );
//VOID PLUG_SetSmartConfig( BOOL bStatus );


PLUG_TIMER_S* PLUG_GetTimerData( UINT8 ucNum );
PLUG_DELAY_S* PLUG_GetDelayData( UINT8 ucNum );
PLUG_SYSSET_S* PLUG_GetSystemSetData( VOID );
UINT32 PLUG_GetTimerDataSize();
UINT32 PLUG_GetDelayDataSize();
UINT32 PLUG_GetSystemSetDataSize();

VOID PLUG_TimerDataDeInit( VOID );
VOID PLUG_DelayDataDeInit( VOID );
VOID PLUG_SystemSetDataDeInit( VOID );

UINT PLUG_MarshalJsonTimer( CHAR* pcBuf, UINT uiBufLen, UINT uiTimerNum );
UINT PLUG_MarshalJsonDelay( CHAR* pcBuf, UINT uiBufLen, UINT uiTimerNum);
UINT PLUG_MarshalJsonSystemSet( CHAR* pcBuf, UINT uiBufLen );
UINT PLUG_MarshalJsonHtmlData( CHAR* pcBuf, UINT uiBufLen );
UINT PLUG_MarshalJsonRelayStatus( CHAR* pcBuf, UINT uiBufLen );
UINT PLUG_MarshalJsonDate( CHAR* pcBuf, UINT uiBufLen );


INT32 PLUG_GetTimeFromInternet();
VOID PLUG_GetDate(PLUG_DATE_S * pstDate );
UINT PLUG_ParseDate( CHAR* pDateStr);
VOID PLUG_SetDate(PLUG_DATE_S * pstDate );

UINT PLUG_ParseTimerData( CHAR* pData );
UINT PLUG_ParseRelayStatus( CHAR* pDataStr);

VOID PLUG_StartJudgeTimeHanderTimer( VOID );

VOID SetDelay( VOID );

UINT PLUG_GetRunTime( VOID );



#endif /* __USER_PLUG_H__ */
