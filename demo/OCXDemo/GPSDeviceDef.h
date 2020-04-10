#ifndef _NET_DEVICE_DEF_H_
#define _NET_DEVICE_DEF_H_


//#include "hi_dataType.h"

#define GPS_FRM_TYPE_HEAD						1
#define GPS_FRM_TYPE_I							0x63643000
#define GPS_FRM_TYPE_P							0x63643100
#define GPS_FRM_TYPE_A							0x63643230
#define GPS_FRM_TYPE_INFO						0x63643939
#define GPS_FRM_TYPE_REC_HDR					2

#define GPS_FILE_TYPE_NORMAL					0
#define GPS_FILE_TYPE_ALARM						1
#define GPS_FILE_TYPE_ALL						-1

#define GPS_CHANNEL_ALL							99

#define GPS_ALARM_TYPE_ALL						0		//所有报警

#define GPS_ALARM_TYPE_USEDEFINE				1		//自定义报警
#define GPS_ALARM_TYPE_URGENCY_BUTTON			2		//紧急按钮报警
#define GPS_ALARM_TYPE_SHAKE					3		//振动报警
#define GPS_ALARM_TYPE_VIDEO_LOST				4		//摄像头无信号报警
#define GPS_ALARM_TYPE_VIDEO_MASK				5		//摄像头遮挡报警
#define GPS_ALARM_TYPE_DOOR_OPEN_LAWLESS		6		//非法开门报警
#define GPS_ALARM_TYPE_WRONG_PWD				7		//三次密码错误报警
#define GPS_ALARM_TYPE_FIRE_LOWLESS				8		//非法点火报警
#define GPS_ALARM_TYPE_TEMPERATOR				9		//温度报警
#define GPS_ALARM_TYPE_DISK_ERROR				10		//硬盘错误报警
#define GPS_ALARM_TYPE_OVERSPEED				11		//超速报警
#define GPS_ALARM_TYPE_BEYOND_BOUNDS			12		//越界报警
#define GPS_ALARM_TYPE_DOOR_ABNORMAL			13		//异常开关车门报警
#define GPS_ALARM_TYPE_PARK_TOO_LONG			14		//停车过长报警
#define GPS_ALARM_TYPE_MOTION					15		//移动侦测报警
#define GPS_ALARM_TYPE_ACC_ON					16		//ACC开启报警
#define GPS_ALARM_TYPE_DEV_ONLINE				17		//设备在线
#define GPS_ALARM_TYPE_GPS_SIGNAL_LOSS          18      //GPS讯号丢失开始
#define GPS_ALARM_TYPE_IO_1                     19      //IO_1报警
#define GPS_ALARM_TYPE_IO_2                     20      //IO_2报警
#define GPS_ALARM_TYPE_IO_3                     21      //IO_3报警
#define GPS_ALARM_TYPE_IO_4                     22      //IO_4报警
#define GPS_ALARM_TYPE_IO_5                     23      //IO_5报警
#define GPS_ALARM_TYPE_IO_6                     24      //IO_6报警
#define GPS_ALARM_TYPE_IO_7                     25		//IO_7报警
#define GPS_ALARM_TYPE_IO_8                     26      //IO_8报警
#define GPS_ALARM_TYPE_IN_FENCE		            27      //进入区域报警
#define GPS_ALARM_TYPE_OUT_FENCE		        28      //出区域报警
#define GPS_ALARM_TYPE_IN_FENCE_OVER_SPEED      29      //区域内高速报警
#define GPS_ALARM_TYPE_OUT_FENCE_OVER_SPEED     30      //区域外高速报警
#define GPS_ALARM_TYPE_IN_FENCE_LOW_SPEED       31      //区域内低速报警
#define GPS_ALARM_TYPE_OUT_FENCE_LOW_SPEED      32      //区域外低速报警
#define GPS_ALARM_TYPE_IN_FENCE_STOP			33      //区域内停车报警
#define GPS_ALARM_TYPE_OUT_FENCE_STOP			34      //区域外停车报警
#define GPS_ALARM_TYPE_FIRE                     35      //火警
#define GPS_ALARM_TYPE_PANIC                    36      //劫警
#define GPS_ALARM_TYPE_TASK_FINISHED			37		//调度任务完成
#define GPS_ALARM_TYPE_IMAGE_UPLOAD				38		//图片上传完成
#define GPS_ALARM_TYPE_DISK1_NO_EXIST			39		//硬盘1不存在
#define GPS_ALARM_TYPE_DISK2_NO_EXIST			40		//硬盘2不存在

#define GPS_ALARM_TYPE_IO_9                     41      //IO_9报警
#define GPS_ALARM_TYPE_IO_10                    42      //IO_10报警
#define GPS_ALARM_TYPE_IO_11                    43      //IO_11报警
#define GPS_ALARM_TYPE_IO_12                    44      //IO_12报警

#define GPS_ALARM_TYPE_GPS_UNENABLE				45		//GPS无效
#define GPS_ALARM_TYPE_REFUEL					46		//加油	AlarmInfo为加油的油量(9999=99.99升)，Param[0]为加油前油耗
#define GPS_ALARM_TYPE_STILL_FUEL				47		//偷油	AlarmInfo为偷油的油量(9999=99.99升)，Param[0]为偷油前油耗

//hw2013/7/29
#define GPS_ALARM_TYPE_URGENCY_BUTTON_5			48		//紧急按钮报警(5秒)
#define GPS_ALARM_TYPE_FATIGUE					49		//疲劳驾驶	AlarmInfo表示报警级别	0 , 没有， 1  一级报警 2 二级报警, 3 三级报警, 4 关注度报警


#define GPS_ALARM_TYPE_END_USEDEFINE			51		//自定义报警
#define GPS_ALARM_TYPE_END_URGENCY_BUTTON		52		//紧急按钮报警
#define GPS_ALARM_TYPE_END_SHAKE				53		//振动报警
#define GPS_ALARM_TYPE_END_VIDEO_LOST			54		//摄像头无信号报警
#define GPS_ALARM_TYPE_END_VIDEO_MASK			55		//摄像头遮挡报警
#define GPS_ALARM_TYPE_END_DOOR_OPEN_LAWLESS	56		//非法开门报警
#define GPS_ALARM_TYPE_END_WRONG_PWD			57		//三次密码错误报警
#define GPS_ALARM_TYPE_END_FIRE_LOWLESS			58		//非法点火报警
#define GPS_ALARM_TYPE_END_TEMPERATOR			59		//温度报警
#define GPS_ALARM_TYPE_END_DISK_ERROR			60		//硬盘错误报警
#define GPS_ALARM_TYPE_END_OVERSPEED			61		//超速报警
#define GPS_ALARM_TYPE_END_BEYOND_BOUNDS		62		//越界报警
#define GPS_ALARM_TYPE_END_DOOR_ABNORMAL		63		//异常开关车门报警
#define GPS_ALARM_TYPE_END_PARK_TOO_LONG		64		//停车过长报警
#define GPS_ALARM_TYPE_END_MOTION				65		//移动侦测报警
#define GPS_ALARM_TYPE_ACC_OFF					66		//ACC关闭报警
#define GPS_ALARM_TYPE_DEV_DISONLINE			67		//设备断线
#define GPS_ALARM_TYPE_END_GPS_SIGNAL_LOSS      68      //GPS讯号丢失结束
#define GPS_ALARM_TYPE_END_IO_1                 69      //IO_1报警
#define GPS_ALARM_TYPE_END_IO_2                 70      //IO_2报警
#define GPS_ALARM_TYPE_END_IO_3                 71      //IO_3报警
#define GPS_ALARM_TYPE_END_IO_4                 72      //IO_4报警
#define GPS_ALARM_TYPE_END_IO_5                 73      //IO_5报警
#define GPS_ALARM_TYPE_END_IO_6                 74      //IO_6报警
#define GPS_ALARM_TYPE_END_IO_7                 75      //IO_7报警
#define GPS_ALARM_TYPE_END_IO_8                 76      //IO_8报警
#define GPS_ALARM_TYPE_END_IN_FENCE		            77      //进入区域报警
#define GPS_ALARM_TYPE_END_OUT_FENCE		        78      //出区域报警
#define GPS_ALARM_TYPE_END_IN_FENCE_OVER_SPEED      79      //区域内高速报警
#define GPS_ALARM_TYPE_END_OUT_FENCE_OVER_SPEED     80      //区域外高速报警
#define GPS_ALARM_TYPE_END_IN_FENCE_LOW_SPEED       81      //区域内低速报警
#define GPS_ALARM_TYPE_END_OUT_FENCE_LOW_SPEED		82      //区域外低速报警
#define GPS_ALARM_TYPE_END_IN_FENCE_STOP			83      //区域内停车报警
#define GPS_ALARM_TYPE_END_OUT_FENCE_STOP			84      //区域外停车报警
#define GPS_ALARM_TYPE_END_GPS_UNENABLE				85		//GPS无效

//加油和偷油没有结束
#define GPS_ALARM_TYPE_END_REFUEL					86		//加油	AlarmInfo为加油的油量(9999=99.99升)，Param[0]为加油前油耗
#define GPS_ALARM_TYPE_END_STILL_FUEL				87		//偷油	AlarmInfo为偷油的油量(9999=99.99升)，Param[0]为偷油前油耗

#define GPS_ALARM_TYPE_END_IO_9				        91      //IO_9报警
#define GPS_ALARM_TYPE_END_IO_10			        92      //IO_10报警
#define GPS_ALARM_TYPE_END_IO_11					93      //IO_11报警
#define GPS_ALARM_TYPE_END_IO_12					94      //IO_12报.

#define GPS_ALARM_TYPE_END_FATIGUE					99		//疲劳驾驶	AlarmInfo表示报警级别	0 , 没有， 1  一级报警 2 二级报警, 3 三级报警, 4 关注度报警

//#define GPS_ALARM_TYPE_END_FIRE                 85      //火警	未使用
//#define GPS_ALARM_TYPE_END_PANIC                86      //劫警  未使用
//#define GPS_ALARM_TYPE_END_TASK_FINISHED		87		//调度任务完成	未使用
//#define GPS_ALARM_TYPE_END_IMAGE_UPLOAD			88		//图片上传完成	未使用

#define GPS_EVENT_TYPE_PARK						101		//停车事件			Param[0]为停车秒数，Param[1]为停车前油耗(9999=99.99升)，Param[2]为停车后油耗
#define GPS_EVENT_TYPE_PARK_ACCON				102		//停车未熄火事件	Param[0]为停车秒数，Param[1]为停车前油耗(9999=99.99升)，Param[2]为停车后油耗
														//停车未熄火事件一般处于停车事件里面的一段时间内，11:00 - 11:20处于停车，11:00 - 11:05 处于停车未熄火
#define GPS_EVENT_TYPE_NET_FLOW					103		//流量	Param[0]为当前时间（单位秒，如：7206 = 当天02:06时 ），Param[1]为上行流量，Param[2]为下行流量
#define GPS_EVENT_TYPE_REFUEL					104		//加油	AlarmInfo为加油的油量(9999=99.99升)，Param[0]为加油前油耗
#define GPS_EVENT_TYPE_STILL_FUEL				105		//偷油	AlarmInfo为偷油的油量(9999=99.99升)，Param[0]为偷油前油耗
#define GPS_EVENT_TYPE_OVERSPEED				106		//超速事件	AlarmInfo为速度(999=99.9KM/H)，Param[0]超速的时间，Param[1]为超速类型（超高速或者超低速、暂时无效）
#define GPS_EVENT_TYPE_FENCE_ACCESS				107		//进出区域事件	 Param[0]区域编号，Param[1]出区域经度，Param[2]出区域纬度，Param[3]区域停留时间(秒）
#define GPS_EVENT_TYPE_FENCE_PARK				108		//区域停车事件	 Param[0]区域编号，Param[3]区域停车时间（秒）
#define GPS_EVENT_TYPE_FILE_UPLOAD				109		//图片文件或者录像文件上传
#define GPS_EVENT_TYPE_STATION_INFO				110		//报站信息
#define GPS_EVENT_TYPE_SEA_STATUS				111		//海船状态报警 1：出海 2：进港 3：外海滞留报警 4：外海滞留报警结束
//#define GPS_EVENT_TYPE_LOCK_STATUS				112		//电子锁状态					
#define GPS_ALARM_TYPE_CUSTOM					113		//自定义报警, AlarmInfo表示类型
										// param[0]表示参数1，param[1]表示参数2，param[2]表示参数3, param[3]表示参数4, 
										//szDesc表示内容，为字符串格式，中间不允许出现'\0'，最长为256个字节
#define GPS_EVENT_TYPE_OVERSPEED_WARNING		114		//超速预警
#define GPS_EVENT_TYPE_LOWSPEED_WARNING			115		//超速预警
#define GPS_EVENT_TYPE_DRIVER					116		//驾驶员信息采集上报 AlarmInfo：1表示登录，0表示退签，
														//szReserve 表示司机名称，szDesc 表示发证机关，szImgFile：用 ';' 分隔 ，身体证号;从业资格证编码

#define GPS_EVENT_TYPE_TASK_READ				121		//guid为对应的任务guid,人员已经查看了调度任务
#define GPS_EVENT_TYPE_TASK_REPLY				122		//guid为对应的任务guid,人员对调度任务进行了回复，szDesc，为回复内容
#define GPS_ALARM_TYPE_MOBILE_USEDEFINE			123		//自定义报警

#define GPS_ALARM_TYPE_TALK_BACK_REQ			127		//车辆主动对讲请求，以报警方式发送
#define GPS_ALARM_TYPE_DEVICE_INFO_CHANGE		128		//车辆信息发生变化，如用户修改设备信息
#define GPS_ALARM_TYPE_SNAPSHOT_FINISH			129		//存储服务器抓拍完成，以报警方式发送给客户端
#define GPS_ALARM_TYPE_DOWN_FINISH				130		//存储服务器文件任务下载完成，以报警方式发送给客户端
#define GPS_ALARM_TYPE_DEVICE_INFO_CHANGE_EX	131		//车辆信息发生变化，如用户修改设备信息
#define GPS_ALARM_TYPE_TRANS_PORT				132		//透传数据

#define GPS_ALARM_TYPE_NIGHT_DRIVING 			151		//夜间行驶报警
#define GPS_ALARM_TYPE_END_NIGHT_DRIVING		152
#define GPS_ALARM_TYPE_GATHERING				153		//聚众报警
#define GPS_ALARM_TYPE_END_GATHERING			154

//自定义报警类型子类型定义 GPS_ALARM_TYPE_CUSTOM(113)
#define CUSTOM_ALARM_TYPE_PLATE					1	//车牌图片抓拍
#define CUSTOM_ALARM_TYPE_PRESON				2	//人脸识别
#define CUSTOM_ALARM_TYPE_EMPTY_PASSENGER		3	//空载
#define CUSTOM_ALARM_TYPE_LOAD_PASSENGER		4	//负载
#define CUSTOM_ALARM_TYPE_FENCE_ACC_SPPED		5	//电子围栏外,AAC开,速度0,报警



#define GPS_CNT_MSG_SUCCESS				0
#define GPS_CNT_MSG_FAILED				-1
#define GPS_CNT_MSG_DISCONNECT			-2
#define GPS_CNT_MSG_FINISHED			-3
#define GPS_CNT_MSG_USR_FULL_ERROR		-4
#define GPS_CNT_MSG_USR_ERROR			-5

#define GPS_NOTIFY_TYPE_AUDIO_COM		1

#define GPS_AUDIO_TYPE_HEAD				1
#define GPS_AUDIO_TYPE_DATA				2

#define GPS_SETUP_MODE_SEND_ONLY		1	//只发送指令，不等待反馈
#define GPS_SETUP_MODE_WAIT_RET			2	//发送指令，并等待反馈
#define GPS_SETUP_MODE_WAIT_ASYN		3	//发送指令，上层检查返回

#define GPS_GPS_VALID					1

#define GPS_DEV_TYPE_MDVR				1 //车载终端
#define GPS_DEV_TYPE_MOBILE				2 //手机终端
#define GPS_DEV_TYPE_DVR				3 //普通DVR

#define GPS_MOBILE_TYPE_ANDROID			1 //手机终端-Android
#define GPS_MOBILE_TYPE_IPHONE			2 //手机终端-Iphone

#define GPS_MDVR_TYPE_HI3512_4			1 //车载终端-3512
#define GPS_MDVR_TYPE_HI3515_4			2 //车载终端-3515-4
#define GPS_MDVR_TYPE_HI3515_8			3 //车载终端-3515-8

#define GPS_MOBILE_USER_POST_TEAM_MEMBER	1	//队员
#define GPS_MOBILE_USER_POST_TEAM_LEADER	2	//队长

#define GPS_MOBILE_USER_SEX_MAN				1	//男
#define GPS_MOBLIE_USER_SEX_WOMAN			2	//女

#define GPS_PTZ_MOVE_LEFT				0
#define GPS_PTZ_MOVE_RIGHT				1
#define GPS_PTZ_MOVE_TOP				2
#define GPS_PTZ_MOVE_BOTTOM				3
#define GPS_PTZ_MOVE_LEFT_TOP			4
#define GPS_PTZ_MOVE_RIGHT_TOP			5
#define GPS_PTZ_MOVE_LEFT_BOTTOM		6
#define GPS_PTZ_MOVE_RIGHT_BOTTOM		7

#define GPS_PTZ_FOCUS_DEL				8
#define GPS_PTZ_FOCUS_ADD				9
#define GPS_PTZ_LIGHT_DEL				10
#define GPS_PTZ_LIGHT_ADD				11
#define GPS_PTZ_ZOOM_DEL				12
#define GPS_PTZ_ZOOM_ADD				13
#define GPS_PTZ_LIGHT_OPEN				14
#define GPS_PTZ_LIGHT_CLOSE				15
#define GPS_PTZ_WIPER_OPEN				16
#define GPS_PTZ_WIPER_CLOSE				17
#define GPS_PTZ_CRUISE					18
#define GPS_PTZ_MOVE_STOP				19

#define GPS_PTZ_PRESET_MOVE				21
#define GPS_PTZ_PRESET_SET				22
#define GPS_PTZ_PRESET_DEL				23

#define GPS_PTZ_SPEED_MIN				0
#define GPS_PTZ_SPEED_MAX				255

#define GPS_GPSINTERVAL_TYPE_DISTANCE	1	//按距离上报
#define GPS_GPSINTERVAL_TYPE_TIME		2	//按时间上报

//客户端查询车辆轨迹的选项
#define GPS_QUERY_TRACK_TYPE_GPS		1  //查询GPS数据
#define GPS_QUERY_TRACK_TYPE_GPSARLMR	2  //查询GPS和报警
#define GPS_QUERY_TRACK_TYPE_ALARM		3  //查询报警数据

//返回
#define GPS_TRACK_DATA_TYPE_GPS			1  //GPS数据
#define GPS_TRACK_DATA_TYPE_ALARM		2  //报警数据

//网络类型
#define GPS_NETWOKR_TYPE_3G				0	//3G类型
#define GPS_NETWOKR_TYPE_WIFI			1	//WIFI类型
#define GPS_NETWORK_TYPE_NET			2	//有线网络登录
#define GPS_NETWORK_TYPE_4G				3	//4G网络登录


//磁盘类型
#define GPS_DISK_TYPE_UNKOWN			0	//SD卡
#define GPS_DISK_TYPE_SD				1	//SD卡
#define GPS_DISK_TYPE_HDD				2	//硬盘
#define GPS_DISK_TYPE_SSD				3	//SSD

//文件下载类型
#define GPS_DOWN_TYPE_OFFSET			1		//按文件偏移下载
#define GPS_DOWN_TYPE_TIME				2		//按时间偏移下载
#define GPS_DOWN_TYPE_SOURCE_SERVER		3		//从服务器主动下载，下载完成后，机器可以删除相应的文件

//协议类型cProtocol，1-15是通用版本
#define MDVR_PROTOCOL_TYPE_WKP			1
#define MDVR_PROTOCOL_TYPE_TTX			2
#define MDVR_PROTOCOL_TYPE_TQ			3
#define MDVR_PROTOCOL_TYPE_HANV			4
#define MDVR_PROTOCOL_TYPE_GOOME		5
#define MDVR_PROTOCOL_TYPE_JT808		6
#define MDVR_PROTOCOL_TYPE_RM			7
#define MDVR_PROTOCOL_TYPE_YD			8
#define MDVR_PROTOCOL_TYPE_UNIMV		9

//此后面是定制版本，通用版本不能接入定制版本的设备
#define MDVR_PROTOCOL_TYPE_YJW			16

//厂家设备类型(WKP协议下的子类型)cFactoryType
#define WKP_FACTORY_TYPE_UNKOWN			0
#define WKP_FACTORY_TYPE_WKP			1		
#define WKP_FACTORY_TYPE_AUDS			2
#define WKP_FACTORY_TYPE_KX				3
#define WKP_FACTORY_TYPE_EST			4
#define WKP_FACTORY_TYPE_YXHD			5
#define WKP_FACTORY_TYPE_COOINT			6
#define WKP_FACTORY_TYPE_8				8
#define WKP_FACTORY_TYPE_9				9
#define WKP_FACTORY_TYPE_10				10	//


#pragma pack(4)

typedef struct _tagGPSDeviceInfo
{
	char sVersion[64];///
	char sSerialNumber[32];  		
	char szDevIDNO[32];			///车辆编号  		
	short sDevType;				///设备类型
	char cFactoryType;			//厂家类型	
	char cFactoryDevType;		//厂家设备类型
	char cDiskNum;///硬盘数目	
	char cChanNum;///通道数目
	char cProtocol;				//协议类型
	unsigned char cAudioCodec:5;//音频解码器类型
	unsigned char cDiskType:3;	//0：SD，1：硬盘，2：SSD
	char cPlateNumber[34];		//车牌号
	char cPlateUnicode;			//0表示非unicode，1表示unicode
	char cReserve;
}GPSDeviceInfo_S, *LPGPSDeviceInfo_S;

typedef struct _tagGPSDeviceIDNO
{
	char szDevIDNO[32];
}GPSDeviceIDNO_S, *LPGPSDeviceIDNO_S;

typedef struct _tagGPSSvrAddr
{
	char	IPAddr[80];
	unsigned short usPort;
	unsigned short Reserve;
}GPSSvrAddr_S;

typedef struct _tagGPSFile
{
	char	szFile[256]; 	/*带路径的文件名*/
	int		nYear;
	int		nMonth;
	int		nDay;
	unsigned int uiBegintime;
	unsigned int uiEndtime;
	char	szDevIDNO[32];			//设备ID
	int		nChn;
	unsigned int nFileLen;
	int		nFileType;
	int		nLocation;		//位置，设备上的录像文件，还是存储服务上的录像文件
	int		nSvrID;			//存储服务器ID，在为存储服务器上的文件时有效
}GPSFile_S, *LPGPSFile_S;

typedef struct _tagGPSRecFile
{
	char	szFile[256]; 	/*带路径的文件名*/
	unsigned int uiBegintime;
	unsigned int uiEndtime;
	int		nChn;
	unsigned int nFileLen;
	int		nRecType;
}GPSRecFile_S, *LPGPSRecFile_S;

//时间
typedef struct _tagGPSTime
{
	unsigned int ucYear:6;		//年(2000+ucYear) 范围(0-64)
	unsigned int ucMonth:4;		//月(1-12)	范围(0-16)
	unsigned int ucDay:5;		//日(1-31)  范围(0-32)
	unsigned int ucHour:5;		//时(0-23)	范围(0-32)
	unsigned int ucMinute:6;	//分(0-59)  范围(0-64)
	unsigned int ucSecond:6;	//秒(0-59)  范围(0-64)
}GPSTime_S;

//车辆状态,每位表示车辆的相关状态
//uiStatus[0]共有32位
//0位表示GPS定位状态		0无效1有效
//1位表示ACC状态		0表示ACC关闭1表示ACC开启
//2位表示左转状态		0无效1左转
//3位表示右转状态		0无效1右转
//4位表示刹车状态		0无效1刹车
//5位表示正转状态		0无效1正转
//6位表示反转状态		0无效1反转
//7位表示GPS天线状态		0不存在1存在
//8,9位为表示硬盘状态		0不存在，1存在，2断电
//10,11,12位表示3G模块状态  0模块不存在，1无信号，2信号差，3信号一般，4信号好，5信号优
//13位表示静止状态		1表示静止
//14位表示超速状态		1表示超速
//15位表示补传状态		1表示GPS补传
//16位低速状态
//17位
//18位
//19位
//关于停车未熄火，如果处理静止状态，并且处于ACC开启状态，则表示停车未熄火
//20位表示IO1状态	1表示报警
//21位表示IO2状态	1表示报警
//22位表示IO3状态	1表示报警
//23位表示IO4状态	1表示报警
//24位表示IO5状态	1表示报警
//25位表示IO6状态	1表示报警
//26位表示IO7状态	1表示报警
//27位表示IO8状态	1表示报警
//28位表示盘符2状态	1表示有效
//29、30位表示，硬盘2的状态		0不存在，1存在，2断电
//31未使用
//uiStatus[1]
//0位表示进区域报警	
//1位表示出区域报警	

//2位表示区域内高速报警	
//3位表示区域内低速报警	

//4位表示区域外高速报警
//5位表示区域外低速报警	

//6位表示区域内停车报警	
//7位表示区域外停车报警	
	
//8位表示日流量预警
//9位表示日流量超过
//10位表示月流量预警
//11位表示月流量超过

//12位--主机掉电由后备电池供电
//13位--车门开
//14位--车辆设防
//15位--电池电压过低
//16位--电池坏
//17位--发动机

//18位--为最后一个有效的GPS信息，状态显示成定位无效，但GPS可以在地图上定位
//19位--0-空载状态 1-重载状态

//uiStatus[2]
//0-7表示通道视频丢失状态
//8-15表示通道录像状态
//16-23表示IO输入9-16 状态
//24-27表示IO输出1-4 状态
//28-29 0表示GPS定位，1表示基站定位，2表示Wifi定位，  手机定位要显示这个定位信息

typedef struct _tagGPSVehicleGps
{
	GPSTime_S Time;
	unsigned int uiSpeed:14;	//速度值 KM/S	9999 = 999.9 	范围(0-16384)
	unsigned int uiYouLiang:18;	//油量   升	9999 = 99.99 	范围(0-262100)
	unsigned int uiLiCheng;		//里程   公里	9999 = 9.999 	
	unsigned int uiHangXiang:9;	//地面航向，(0-360) 范围(0-512)
	unsigned int uiMapType:3;	//地图类型		1表示GOOGLE，2表示百度，0表示无效
	unsigned int uiReserve:20;  //保留位
	unsigned int uiStatus[4];		//目前只使用，每1个状态	0位表示GPS定位状态（0无效，1有效）
	short sTempSensor[4];	//温度传感器的状态
	int	nJingDu;		//经度	4字节 整数部分	9999999 = 9.999999 
	int nWeiDu;			//纬度	4字节 整数部分	9999999 = 9.999999
	int	nGaoDu;			//高度，暂时未使用
	int	nParkTime;		//停车时长 秒	在静止状态时有效
	int	nMapJingDu;		//通过地图模块获取的经度和纬度
	int	nMapWeiDu;		//通过地图模块获取的经度和纬度
	int	nReserve[2];		//保留参数
}GPSVehicleGps_S;

typedef struct _GPSVehicleState
{
	char	szDevIDNO[32];
	GPSVehicleGps_S	Gps;
}GPSVehicleState_S;

typedef struct _GPSVehicleStatus
{
	char	szDevIDNO[32];
	BOOL	bOnline;
	int		nNetworkType;
	char	szNetworkName[32];
}GPSVehicleStatus_S;

typedef struct _tagGPSAlarmInfo
{
	char	guid[36];			//标识唯一的报警信息
	GPSVehicleGps_S Gps;		//报警时候的GPS信息
	GPSTime_S Time;				//报警时间
	short 	AlarmType;			//报警类型
	short 	AlarmInfo;			//报警信息
	int	Param[4];				//报警参数
	char szDesc[256];			//报警描述
	//说明srcAlarmType和srcTime，当报警类型为报警图片上传完成时有效，表示对应的报警参数信息，图片上传完成报警类型
	//报警类型为图片上传报警时，只使用AlarmType和szImgFile参数，其它参数表示对应报警参数
	short srcAlarmType;			//源报警类型
	short sReserve;				//保留参数
	GPSTime_S srcTime;			//源报警时间
	char szImgFile[256];		//图片文件信息，用;分隔，为http地址路径，可以为多个图片信息
	char szReserve[64];			//保留字段
}GPSAlarmInfo_S, *LPGPSAlarmInfo_S;

typedef struct _GPSVehicleAlarm
{
	char	szDevIDNO[32];
	GPSAlarmInfo_S	Alarm;
}GPSVehicleAlarm_S;

//hw 2014/1/23 
//-- begin
typedef struct _tagGPSAlarmInfoEx
{
	char	guid[36];			//标识唯一的报警信息
	GPSVehicleGps_S Gps;		//报警时候的GPS信息
	GPSTime_S Time;				//报警时间
	short 	AlarmType;			//报警类型
}GPSAlarmInfoEx_S, *LPGPSAlarmInfoEx_S;

typedef struct _tagGPSConfigData
{
	int nLength;		//数据缓存长度
	char cBuffer[1024];	//数据内容
}GPSConfigData_S, *LPGPSConfigData_S;

typedef struct _tagGPSTransPortData
{
	int nType;					//类型
	GPSConfigData_S	Data;		//透传数据
}GPSTransPortData_S, *LPGPSTransPortData_S;

//透传转换报警
typedef struct tagGPSAlarmTPD 
{
	char	szDevIDNO[32];
	GPSAlarmInfoEx_S VehiAlarm;
	GPSTransPortData_S TPD;	
}GPSAlarmTPD_S, *LPGPSAlarmTPD_S;
//-- end

//报警日志数目
typedef struct _tagGPSAlarmCount
{
	int nCount;
	char szReserve[8];
}GPSAlarmCount_S, *LPGPSAlarmCount_S;

//车辆轨迹(包含GPS和报警)
typedef struct _tagGPSVehicleTrack
{
	int nType;					//标识该数据类型(GPS数据或者报警数据)
	GPSVehicleAlarm_S Alarm;	//报警数据(如果类型为GPS数据 则只有GPS字段数据有效)
}GPSVehicleTrack_S, *LPGPSVehicleTrack_S;

//轨迹点数目
typedef struct _tagGPSTrackCount
{
	int nCount;
	char szReserve[8];
}GPSTrackCount_S, *LPGPSTrackCount_S;


typedef struct _tagGPSTrackInFenceInfo
{
	int		nDevID;				//车辆ID
	GPSTime_S BeginTime;		//开始时间
	GPSTime_S EndTime;			//结束时间
	int		nStartJingDu;		//进入区域经度	4字节 整数部分	9999999 = 9.999999 
	int		nStartWeiDu;		//进入区域纬度	4字节 整数部分	9999999 = 9.999999
	int		nEndJingDu;			//离开区域经度	4字节 整数部分	9999999 = 9.999999 
	int		nEndWeiDu;			//离开区域纬度	4字节 整数部分	9999999 = 9.999999
	char szRes[32];				//保留32
}GPSTrackInFenceInfo_S, *LPGPSTrackInFenceInfo_S;

const int GPS_VEHICLE_ALARM_LENGTH = sizeof(GPSVehicleAlarm_S);
const int GPS_ALARM_INFO_LENGTH = sizeof(GPSAlarmInfo_S);
const int GPS_VHIECLE_GPS_LENGTH = sizeof(GPSVehicleGps_S);
const int GPS_VHIECLE_RUN_LENGTH = sizeof(GPSVehicleState_S);
const int GPS_VEHICLE_STATUS_LENGTH = sizeof(GPSVehicleStatus_S);
const int GPS_VEHICLE_TRACK_LENGTH = sizeof(GPSVehicleTrack_S);

//透明串口数据
typedef struct _tagGPSTranPortData
{
	int nID;
	char szDevIDNO[32];	//车机编号
	int nType;			//类型
	SYSTEMTIME Time;		//时间
	int	nLength;		//长度
	char cData[1280];	//数据长度
}GPSTranPortData_S, *LPGPSTranPortData_S;

//透明串口数据数目
typedef struct _tagGPSTranPortDataCount
{
	int nCount;
	char szReserve[8];
}GPSTranPortDataCount_S, *LPGPSTranPortDataCount_S;

const int GPS_TRAN_PORT_DATA_LENGTH = sizeof(GPSTranPortData_S);

#define GPS_WLAN_TYPE_2G					0
#define GPS_WLAN_TYPE_3G_EVDO				1
#define GPS_WLAN_TYPE_3G_WCDMA				2

typedef struct _tagGPSWLanStatus
{
	int nWLanActive;	//
	int	nWLanType;		////0：表示2G;1：表示3G-EVDO; 2：表示3G-WCDMA 
	int nWLanQuantity;	//信号值	不显示
	char szWLanAddr[32];//网络地址
}GPSWLanStatus_S, *LPGPSWLanStatus_S;

typedef struct _tagGPSWifiStatus
{
	int nWifiActive;
	char szWifiAP[32];	//hide
	int nWifiQuantity;	//hide
	char szWifiAddr[32];//
}GPSWifiStatus_S, *LPGPSWifiStatus_S;

typedef struct _tagGPSDiskInfo
{
	int nAllVolume;		//15923	表示159.23	G //总容量
	int nLeftVolume;	//同上  ///剩余容量
}GPSDiskInfo_S, *LPGPSDiskInfo_S;

const int GPS_DISK_INFO_COUNT			= 8;	//最多硬盘数目为8个

typedef struct _tagGPSDeviceStatus
{
	GPSDeviceInfo_S	DevInfo;	//设备信息
	GPSWLanStatus_S	WLanInfo;	//3G状态
	GPSWifiStatus_S	WifiInfo;	//WIFI信息
	GPSDiskInfo_S	DiskInfo[GPS_DISK_INFO_COUNT];	//硬盘信息
	int	nVideoLost;		//视频丢失状态  1表示该视频丢失
	int nRecord;		//录像状态 0：没有录像，1录像
	int nVideoTran;		//视频传输数目
	long l3GFlow;		//KB为单位，从月结日开始算，累加
	long l4GFlow;		//KB为单位，从月结日开始算，累加
	int nReserve[2];	//保留参数
}GPSDeviceStatus_S, *LPGPSDeviceStatus_S;

const int GPS_MOTION_MASK = 9;

typedef struct _tagGPSMotionParam
{
	int	nMask[GPS_MOTION_MASK];	//低11位表示移动侦测
	BOOL bEnable;	//是否启用
	int	nSensitive;	//灵敏度
}GPSMotionParam_S, *LPGPSMotionParam_S;

typedef struct _tagGPSVideoColor
{
	int nExposure;		//爆光度
	int	nBrightness;	
	int	nConstract;	
	int	nHue;				
	int	nSaturate;			 
}GPSVideoColor_S, *LPGPSVideoColor_S;

//////////////////////////////////////////////////////////////////////////
//hw 2012-11-07
//网络流量参数
typedef struct _tagGPSNetFlowParam
{
	int nIsOpenFlowCount;		//流量统计开关 0-关闭，1-开启
	int nIsOpenDayFlowRemind;	//日流量提醒 0-不提醒 1-提醒
	int nIsOpenMonthFlwRemind;	//月流量提醒 0-不提醒 1-提醒
	float fDayLimit;			//日流量限制(MB)
	float fMonthLimit;			//月流量限制(MB)
	int nDayRemind;				//每天流量提醒（百分比），20%即20
	int nMonthRemind;			//每月流量提醒（百分比），20%即20
	int nMonthTotleDay;			//月结日
	char szRes[32];				//保留32
}GPSNetFlowParam_S, *LPGPSNetFlowParam_S;

//网络流量统计
typedef struct _tagGPSNetFlowStatistics
{
	GPSNetFlowParam_S	FlowParam;	//流量参数
	float fFlowUsedToday;			//今日流量
	float fFlowUsedMonth;			//本月已使用流量
	int nStatisticsTime;			//统计时间
	char szRes[32];					//保留32
}GPSNetFlowStatistics_S, *LPGPSNetFlowStatistics_S;	
//end
//////////////////////////////////////////////////////////////////////////

//调度指令
typedef struct _tabGPSDispatchCommand
{
	char szGuid[40];		//指令GUID
	int nMapType;			//目的地，地图类型，1表示GOOGLE，2表示百度
	int nJingDu;			//经度
	int nWeiDu;				//纬度
	char szCommand[256];	//命令字
}GPSDispatchCommand_S, *LPGPSDispatchCommand_S;


typedef union _tagUNCfg
{
// 	HI_S_Video cfgVideo;				/* 视频参数 */
// 	HI_S_Audio cfgAudio;				/* 音频参数 */
// 	HI_E_AudioInput cfgAudioInput;		/* 音频输入参数 */
// 	HI_S_PTZ cfgPTZ;					/* 云台参数 */
}GPSCfg, *LPGPSCfg;

//文件信息
typedef struct _tagGPSRecHead_S
{
	int	nYear;			//年	2013
	int	nMonth;			//月	5
	int nDay;			//日	29
	int nBegHour;		//开始时间
	int nBegMinute;		
	int nBegSecond;
	unsigned __int64 u64BegPts;	//文件起始的时间戳
	unsigned int uiTotalMinSecond;	//文件总时长，毫秒
	unsigned int uiAudioCodec;		//音频解码器类型	TTX_AUDIO_CODEC_G726_40KBPS
	unsigned int uiAudioChannel;		//音频通道
	unsigned int uiAudioSamplesPerSec;	//音频采样率
	unsigned int uiAudioBitPerSamples;	//音频每个取样所需的位元数
	unsigned int uiInfoCodec;		//信息帧解码器	TTX_INFO_CODEC_WKP
	char szReserve[64];		//保留字段
} GPSRecHead_S, *LPGPSRecHead_S;

typedef struct _tagGPSUsrLog
{
	int nUsrID;
	int nMainType;
	int nSubType;
	char szDevIDNO[40];
	char szParam1[256];
	char szParam2[256];
	char szParam3[256];
	char szParam4[256];
	GPSTime_S time;
	char szReserve[64];
}GPSUsrLog_S, *LPGPSUsrLog_S;

//用户基本信息
typedef struct _tagUserBasicInfo
{
	int nUserID;				//用户ID		
	char szUserName[32];		//用户名称
	char szReserve[32];			//保留32
}UserBasicInfo_S, *LPUserBasicInfo_S;


//用户日志数目
typedef struct _tagGPSUsrLogCount
{
	int nCount;
	char szReserve[8];
}GPSUsrLogCount_S, *LPGPSUsrLogCount_S;


//联系人
typedef struct _tagContactInfo
{
	char szName[32];			//姓名
	char szPhone[16];			//手机
	char szTel[16];				//电话
	char szReserve[16];			//保留16
}ContactInfo_S, *LPContactInfo_S;

//学生信息
typedef struct _tagStudentInfo
{
	char szCarNum[32];			//卡号
	char szName[32];			//学生姓名
	int nStudySection;			//0-未知 1-幼儿园 2-小学 3-初中 4-高中 5-大学
	int nGrade;					//0-未知，1-1年级，2-2年级
	int nClass;					//0-未知，1-1班 2-2班
	ContactInfo_S Contact1;		//联系人1
	ContactInfo_S Contact2;		//联系人2
	char szEmail[64];			//email
	char szAddress[256];		//地址
	char szRemark[256];			//备注
	char szReserve[256];		//保留256
}StudentInfo_S, *LPStudentInfo_S;


typedef struct _tagDeviceDevIPInfo
{
	GPSDeviceIDNO_S DevIDNO;
	int nPort;
	char szIP[16];
	char szReserve[16];
}DeviceDevIPInfo_S, *LPDeviceDevIPInfo_S;
#pragma pack()

#endif	
