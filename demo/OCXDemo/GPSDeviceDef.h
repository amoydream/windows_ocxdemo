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

#define GPS_ALARM_TYPE_ALL						0		//���б���

#define GPS_ALARM_TYPE_USEDEFINE				1		//�Զ��屨��
#define GPS_ALARM_TYPE_URGENCY_BUTTON			2		//������ť����
#define GPS_ALARM_TYPE_SHAKE					3		//�񶯱���
#define GPS_ALARM_TYPE_VIDEO_LOST				4		//����ͷ���źű���
#define GPS_ALARM_TYPE_VIDEO_MASK				5		//����ͷ�ڵ�����
#define GPS_ALARM_TYPE_DOOR_OPEN_LAWLESS		6		//�Ƿ����ű���
#define GPS_ALARM_TYPE_WRONG_PWD				7		//����������󱨾�
#define GPS_ALARM_TYPE_FIRE_LOWLESS				8		//�Ƿ���𱨾�
#define GPS_ALARM_TYPE_TEMPERATOR				9		//�¶ȱ���
#define GPS_ALARM_TYPE_DISK_ERROR				10		//Ӳ�̴��󱨾�
#define GPS_ALARM_TYPE_OVERSPEED				11		//���ٱ���
#define GPS_ALARM_TYPE_BEYOND_BOUNDS			12		//Խ�籨��
#define GPS_ALARM_TYPE_DOOR_ABNORMAL			13		//�쳣���س��ű���
#define GPS_ALARM_TYPE_PARK_TOO_LONG			14		//ͣ����������
#define GPS_ALARM_TYPE_MOTION					15		//�ƶ���ⱨ��
#define GPS_ALARM_TYPE_ACC_ON					16		//ACC��������
#define GPS_ALARM_TYPE_DEV_ONLINE				17		//�豸����
#define GPS_ALARM_TYPE_GPS_SIGNAL_LOSS          18      //GPSѶ�Ŷ�ʧ��ʼ
#define GPS_ALARM_TYPE_IO_1                     19      //IO_1����
#define GPS_ALARM_TYPE_IO_2                     20      //IO_2����
#define GPS_ALARM_TYPE_IO_3                     21      //IO_3����
#define GPS_ALARM_TYPE_IO_4                     22      //IO_4����
#define GPS_ALARM_TYPE_IO_5                     23      //IO_5����
#define GPS_ALARM_TYPE_IO_6                     24      //IO_6����
#define GPS_ALARM_TYPE_IO_7                     25		//IO_7����
#define GPS_ALARM_TYPE_IO_8                     26      //IO_8����
#define GPS_ALARM_TYPE_IN_FENCE		            27      //�������򱨾�
#define GPS_ALARM_TYPE_OUT_FENCE		        28      //�����򱨾�
#define GPS_ALARM_TYPE_IN_FENCE_OVER_SPEED      29      //�����ڸ��ٱ���
#define GPS_ALARM_TYPE_OUT_FENCE_OVER_SPEED     30      //��������ٱ���
#define GPS_ALARM_TYPE_IN_FENCE_LOW_SPEED       31      //�����ڵ��ٱ���
#define GPS_ALARM_TYPE_OUT_FENCE_LOW_SPEED      32      //��������ٱ���
#define GPS_ALARM_TYPE_IN_FENCE_STOP			33      //������ͣ������
#define GPS_ALARM_TYPE_OUT_FENCE_STOP			34      //������ͣ������
#define GPS_ALARM_TYPE_FIRE                     35      //��
#define GPS_ALARM_TYPE_PANIC                    36      //�پ�
#define GPS_ALARM_TYPE_TASK_FINISHED			37		//�����������
#define GPS_ALARM_TYPE_IMAGE_UPLOAD				38		//ͼƬ�ϴ����
#define GPS_ALARM_TYPE_DISK1_NO_EXIST			39		//Ӳ��1������
#define GPS_ALARM_TYPE_DISK2_NO_EXIST			40		//Ӳ��2������

#define GPS_ALARM_TYPE_IO_9                     41      //IO_9����
#define GPS_ALARM_TYPE_IO_10                    42      //IO_10����
#define GPS_ALARM_TYPE_IO_11                    43      //IO_11����
#define GPS_ALARM_TYPE_IO_12                    44      //IO_12����

#define GPS_ALARM_TYPE_GPS_UNENABLE				45		//GPS��Ч
#define GPS_ALARM_TYPE_REFUEL					46		//����	AlarmInfoΪ���͵�����(9999=99.99��)��Param[0]Ϊ����ǰ�ͺ�
#define GPS_ALARM_TYPE_STILL_FUEL				47		//͵��	AlarmInfoΪ͵�͵�����(9999=99.99��)��Param[0]Ϊ͵��ǰ�ͺ�

//hw2013/7/29
#define GPS_ALARM_TYPE_URGENCY_BUTTON_5			48		//������ť����(5��)
#define GPS_ALARM_TYPE_FATIGUE					49		//ƣ�ͼ�ʻ	AlarmInfo��ʾ��������	0 , û�У� 1  һ������ 2 ��������, 3 ��������, 4 ��ע�ȱ���


#define GPS_ALARM_TYPE_END_USEDEFINE			51		//�Զ��屨��
#define GPS_ALARM_TYPE_END_URGENCY_BUTTON		52		//������ť����
#define GPS_ALARM_TYPE_END_SHAKE				53		//�񶯱���
#define GPS_ALARM_TYPE_END_VIDEO_LOST			54		//����ͷ���źű���
#define GPS_ALARM_TYPE_END_VIDEO_MASK			55		//����ͷ�ڵ�����
#define GPS_ALARM_TYPE_END_DOOR_OPEN_LAWLESS	56		//�Ƿ����ű���
#define GPS_ALARM_TYPE_END_WRONG_PWD			57		//����������󱨾�
#define GPS_ALARM_TYPE_END_FIRE_LOWLESS			58		//�Ƿ���𱨾�
#define GPS_ALARM_TYPE_END_TEMPERATOR			59		//�¶ȱ���
#define GPS_ALARM_TYPE_END_DISK_ERROR			60		//Ӳ�̴��󱨾�
#define GPS_ALARM_TYPE_END_OVERSPEED			61		//���ٱ���
#define GPS_ALARM_TYPE_END_BEYOND_BOUNDS		62		//Խ�籨��
#define GPS_ALARM_TYPE_END_DOOR_ABNORMAL		63		//�쳣���س��ű���
#define GPS_ALARM_TYPE_END_PARK_TOO_LONG		64		//ͣ����������
#define GPS_ALARM_TYPE_END_MOTION				65		//�ƶ���ⱨ��
#define GPS_ALARM_TYPE_ACC_OFF					66		//ACC�رձ���
#define GPS_ALARM_TYPE_DEV_DISONLINE			67		//�豸����
#define GPS_ALARM_TYPE_END_GPS_SIGNAL_LOSS      68      //GPSѶ�Ŷ�ʧ����
#define GPS_ALARM_TYPE_END_IO_1                 69      //IO_1����
#define GPS_ALARM_TYPE_END_IO_2                 70      //IO_2����
#define GPS_ALARM_TYPE_END_IO_3                 71      //IO_3����
#define GPS_ALARM_TYPE_END_IO_4                 72      //IO_4����
#define GPS_ALARM_TYPE_END_IO_5                 73      //IO_5����
#define GPS_ALARM_TYPE_END_IO_6                 74      //IO_6����
#define GPS_ALARM_TYPE_END_IO_7                 75      //IO_7����
#define GPS_ALARM_TYPE_END_IO_8                 76      //IO_8����
#define GPS_ALARM_TYPE_END_IN_FENCE		            77      //�������򱨾�
#define GPS_ALARM_TYPE_END_OUT_FENCE		        78      //�����򱨾�
#define GPS_ALARM_TYPE_END_IN_FENCE_OVER_SPEED      79      //�����ڸ��ٱ���
#define GPS_ALARM_TYPE_END_OUT_FENCE_OVER_SPEED     80      //��������ٱ���
#define GPS_ALARM_TYPE_END_IN_FENCE_LOW_SPEED       81      //�����ڵ��ٱ���
#define GPS_ALARM_TYPE_END_OUT_FENCE_LOW_SPEED		82      //��������ٱ���
#define GPS_ALARM_TYPE_END_IN_FENCE_STOP			83      //������ͣ������
#define GPS_ALARM_TYPE_END_OUT_FENCE_STOP			84      //������ͣ������
#define GPS_ALARM_TYPE_END_GPS_UNENABLE				85		//GPS��Ч

//���ͺ�͵��û�н���
#define GPS_ALARM_TYPE_END_REFUEL					86		//����	AlarmInfoΪ���͵�����(9999=99.99��)��Param[0]Ϊ����ǰ�ͺ�
#define GPS_ALARM_TYPE_END_STILL_FUEL				87		//͵��	AlarmInfoΪ͵�͵�����(9999=99.99��)��Param[0]Ϊ͵��ǰ�ͺ�

#define GPS_ALARM_TYPE_END_IO_9				        91      //IO_9����
#define GPS_ALARM_TYPE_END_IO_10			        92      //IO_10����
#define GPS_ALARM_TYPE_END_IO_11					93      //IO_11����
#define GPS_ALARM_TYPE_END_IO_12					94      //IO_12��.

#define GPS_ALARM_TYPE_END_FATIGUE					99		//ƣ�ͼ�ʻ	AlarmInfo��ʾ��������	0 , û�У� 1  һ������ 2 ��������, 3 ��������, 4 ��ע�ȱ���

//#define GPS_ALARM_TYPE_END_FIRE                 85      //��	δʹ��
//#define GPS_ALARM_TYPE_END_PANIC                86      //�پ�  δʹ��
//#define GPS_ALARM_TYPE_END_TASK_FINISHED		87		//�����������	δʹ��
//#define GPS_ALARM_TYPE_END_IMAGE_UPLOAD			88		//ͼƬ�ϴ����	δʹ��

#define GPS_EVENT_TYPE_PARK						101		//ͣ���¼�			Param[0]Ϊͣ��������Param[1]Ϊͣ��ǰ�ͺ�(9999=99.99��)��Param[2]Ϊͣ�����ͺ�
#define GPS_EVENT_TYPE_PARK_ACCON				102		//ͣ��δϨ���¼�	Param[0]Ϊͣ��������Param[1]Ϊͣ��ǰ�ͺ�(9999=99.99��)��Param[2]Ϊͣ�����ͺ�
														//ͣ��δϨ���¼�һ�㴦��ͣ���¼������һ��ʱ���ڣ�11:00 - 11:20����ͣ����11:00 - 11:05 ����ͣ��δϨ��
#define GPS_EVENT_TYPE_NET_FLOW					103		//����	Param[0]Ϊ��ǰʱ�䣨��λ�룬�磺7206 = ����02:06ʱ ����Param[1]Ϊ����������Param[2]Ϊ��������
#define GPS_EVENT_TYPE_REFUEL					104		//����	AlarmInfoΪ���͵�����(9999=99.99��)��Param[0]Ϊ����ǰ�ͺ�
#define GPS_EVENT_TYPE_STILL_FUEL				105		//͵��	AlarmInfoΪ͵�͵�����(9999=99.99��)��Param[0]Ϊ͵��ǰ�ͺ�
#define GPS_EVENT_TYPE_OVERSPEED				106		//�����¼�	AlarmInfoΪ�ٶ�(999=99.9KM/H)��Param[0]���ٵ�ʱ�䣬Param[1]Ϊ�������ͣ������ٻ��߳����١���ʱ��Ч��
#define GPS_EVENT_TYPE_FENCE_ACCESS				107		//���������¼�	 Param[0]�����ţ�Param[1]�����򾭶ȣ�Param[2]������γ�ȣ�Param[3]����ͣ��ʱ��(�룩
#define GPS_EVENT_TYPE_FENCE_PARK				108		//����ͣ���¼�	 Param[0]�����ţ�Param[3]����ͣ��ʱ�䣨�룩
#define GPS_EVENT_TYPE_FILE_UPLOAD				109		//ͼƬ�ļ�����¼���ļ��ϴ�
#define GPS_EVENT_TYPE_STATION_INFO				110		//��վ��Ϣ
#define GPS_EVENT_TYPE_SEA_STATUS				111		//����״̬���� 1������ 2������ 3���⺣�������� 4���⺣������������
//#define GPS_EVENT_TYPE_LOCK_STATUS				112		//������״̬					
#define GPS_ALARM_TYPE_CUSTOM					113		//�Զ��屨��, AlarmInfo��ʾ����
										// param[0]��ʾ����1��param[1]��ʾ����2��param[2]��ʾ����3, param[3]��ʾ����4, 
										//szDesc��ʾ���ݣ�Ϊ�ַ�����ʽ���м䲻�������'\0'���Ϊ256���ֽ�
#define GPS_EVENT_TYPE_OVERSPEED_WARNING		114		//����Ԥ��
#define GPS_EVENT_TYPE_LOWSPEED_WARNING			115		//����Ԥ��
#define GPS_EVENT_TYPE_DRIVER					116		//��ʻԱ��Ϣ�ɼ��ϱ� AlarmInfo��1��ʾ��¼��0��ʾ��ǩ��
														//szReserve ��ʾ˾�����ƣ�szDesc ��ʾ��֤���أ�szImgFile���� ';' �ָ� ������֤��;��ҵ�ʸ�֤����

#define GPS_EVENT_TYPE_TASK_READ				121		//guidΪ��Ӧ������guid,��Ա�Ѿ��鿴�˵�������
#define GPS_EVENT_TYPE_TASK_REPLY				122		//guidΪ��Ӧ������guid,��Ա�Ե�����������˻ظ���szDesc��Ϊ�ظ�����
#define GPS_ALARM_TYPE_MOBILE_USEDEFINE			123		//�Զ��屨��

#define GPS_ALARM_TYPE_TALK_BACK_REQ			127		//���������Խ������Ա�����ʽ����
#define GPS_ALARM_TYPE_DEVICE_INFO_CHANGE		128		//������Ϣ�����仯�����û��޸��豸��Ϣ
#define GPS_ALARM_TYPE_SNAPSHOT_FINISH			129		//�洢������ץ����ɣ��Ա�����ʽ���͸��ͻ���
#define GPS_ALARM_TYPE_DOWN_FINISH				130		//�洢�������ļ�����������ɣ��Ա�����ʽ���͸��ͻ���
#define GPS_ALARM_TYPE_DEVICE_INFO_CHANGE_EX	131		//������Ϣ�����仯�����û��޸��豸��Ϣ
#define GPS_ALARM_TYPE_TRANS_PORT				132		//͸������

#define GPS_ALARM_TYPE_NIGHT_DRIVING 			151		//ҹ����ʻ����
#define GPS_ALARM_TYPE_END_NIGHT_DRIVING		152
#define GPS_ALARM_TYPE_GATHERING				153		//���ڱ���
#define GPS_ALARM_TYPE_END_GATHERING			154

//�Զ��屨�����������Ͷ��� GPS_ALARM_TYPE_CUSTOM(113)
#define CUSTOM_ALARM_TYPE_PLATE					1	//����ͼƬץ��
#define CUSTOM_ALARM_TYPE_PRESON				2	//����ʶ��
#define CUSTOM_ALARM_TYPE_EMPTY_PASSENGER		3	//����
#define CUSTOM_ALARM_TYPE_LOAD_PASSENGER		4	//����
#define CUSTOM_ALARM_TYPE_FENCE_ACC_SPPED		5	//����Χ����,AAC��,�ٶ�0,����



#define GPS_CNT_MSG_SUCCESS				0
#define GPS_CNT_MSG_FAILED				-1
#define GPS_CNT_MSG_DISCONNECT			-2
#define GPS_CNT_MSG_FINISHED			-3
#define GPS_CNT_MSG_USR_FULL_ERROR		-4
#define GPS_CNT_MSG_USR_ERROR			-5

#define GPS_NOTIFY_TYPE_AUDIO_COM		1

#define GPS_AUDIO_TYPE_HEAD				1
#define GPS_AUDIO_TYPE_DATA				2

#define GPS_SETUP_MODE_SEND_ONLY		1	//ֻ����ָ����ȴ�����
#define GPS_SETUP_MODE_WAIT_RET			2	//����ָ����ȴ�����
#define GPS_SETUP_MODE_WAIT_ASYN		3	//����ָ��ϲ��鷵��

#define GPS_GPS_VALID					1

#define GPS_DEV_TYPE_MDVR				1 //�����ն�
#define GPS_DEV_TYPE_MOBILE				2 //�ֻ��ն�
#define GPS_DEV_TYPE_DVR				3 //��ͨDVR

#define GPS_MOBILE_TYPE_ANDROID			1 //�ֻ��ն�-Android
#define GPS_MOBILE_TYPE_IPHONE			2 //�ֻ��ն�-Iphone

#define GPS_MDVR_TYPE_HI3512_4			1 //�����ն�-3512
#define GPS_MDVR_TYPE_HI3515_4			2 //�����ն�-3515-4
#define GPS_MDVR_TYPE_HI3515_8			3 //�����ն�-3515-8

#define GPS_MOBILE_USER_POST_TEAM_MEMBER	1	//��Ա
#define GPS_MOBILE_USER_POST_TEAM_LEADER	2	//�ӳ�

#define GPS_MOBILE_USER_SEX_MAN				1	//��
#define GPS_MOBLIE_USER_SEX_WOMAN			2	//Ů

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

#define GPS_GPSINTERVAL_TYPE_DISTANCE	1	//�������ϱ�
#define GPS_GPSINTERVAL_TYPE_TIME		2	//��ʱ���ϱ�

//�ͻ��˲�ѯ�����켣��ѡ��
#define GPS_QUERY_TRACK_TYPE_GPS		1  //��ѯGPS����
#define GPS_QUERY_TRACK_TYPE_GPSARLMR	2  //��ѯGPS�ͱ���
#define GPS_QUERY_TRACK_TYPE_ALARM		3  //��ѯ��������

//����
#define GPS_TRACK_DATA_TYPE_GPS			1  //GPS����
#define GPS_TRACK_DATA_TYPE_ALARM		2  //��������

//��������
#define GPS_NETWOKR_TYPE_3G				0	//3G����
#define GPS_NETWOKR_TYPE_WIFI			1	//WIFI����
#define GPS_NETWORK_TYPE_NET			2	//���������¼
#define GPS_NETWORK_TYPE_4G				3	//4G�����¼


//��������
#define GPS_DISK_TYPE_UNKOWN			0	//SD��
#define GPS_DISK_TYPE_SD				1	//SD��
#define GPS_DISK_TYPE_HDD				2	//Ӳ��
#define GPS_DISK_TYPE_SSD				3	//SSD

//�ļ���������
#define GPS_DOWN_TYPE_OFFSET			1		//���ļ�ƫ������
#define GPS_DOWN_TYPE_TIME				2		//��ʱ��ƫ������
#define GPS_DOWN_TYPE_SOURCE_SERVER		3		//�ӷ������������أ�������ɺ󣬻�������ɾ����Ӧ���ļ�

//Э������cProtocol��1-15��ͨ�ð汾
#define MDVR_PROTOCOL_TYPE_WKP			1
#define MDVR_PROTOCOL_TYPE_TTX			2
#define MDVR_PROTOCOL_TYPE_TQ			3
#define MDVR_PROTOCOL_TYPE_HANV			4
#define MDVR_PROTOCOL_TYPE_GOOME		5
#define MDVR_PROTOCOL_TYPE_JT808		6
#define MDVR_PROTOCOL_TYPE_RM			7
#define MDVR_PROTOCOL_TYPE_YD			8
#define MDVR_PROTOCOL_TYPE_UNIMV		9

//�˺����Ƕ��ư汾��ͨ�ð汾���ܽ��붨�ư汾���豸
#define MDVR_PROTOCOL_TYPE_YJW			16

//�����豸����(WKPЭ���µ�������)cFactoryType
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
	char szDevIDNO[32];			///�������  		
	short sDevType;				///�豸����
	char cFactoryType;			//��������	
	char cFactoryDevType;		//�����豸����
	char cDiskNum;///Ӳ����Ŀ	
	char cChanNum;///ͨ����Ŀ
	char cProtocol;				//Э������
	unsigned char cAudioCodec:5;//��Ƶ����������
	unsigned char cDiskType:3;	//0��SD��1��Ӳ�̣�2��SSD
	char cPlateNumber[34];		//���ƺ�
	char cPlateUnicode;			//0��ʾ��unicode��1��ʾunicode
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
	char	szFile[256]; 	/*��·�����ļ���*/
	int		nYear;
	int		nMonth;
	int		nDay;
	unsigned int uiBegintime;
	unsigned int uiEndtime;
	char	szDevIDNO[32];			//�豸ID
	int		nChn;
	unsigned int nFileLen;
	int		nFileType;
	int		nLocation;		//λ�ã��豸�ϵ�¼���ļ������Ǵ洢�����ϵ�¼���ļ�
	int		nSvrID;			//�洢������ID����Ϊ�洢�������ϵ��ļ�ʱ��Ч
}GPSFile_S, *LPGPSFile_S;

typedef struct _tagGPSRecFile
{
	char	szFile[256]; 	/*��·�����ļ���*/
	unsigned int uiBegintime;
	unsigned int uiEndtime;
	int		nChn;
	unsigned int nFileLen;
	int		nRecType;
}GPSRecFile_S, *LPGPSRecFile_S;

//ʱ��
typedef struct _tagGPSTime
{
	unsigned int ucYear:6;		//��(2000+ucYear) ��Χ(0-64)
	unsigned int ucMonth:4;		//��(1-12)	��Χ(0-16)
	unsigned int ucDay:5;		//��(1-31)  ��Χ(0-32)
	unsigned int ucHour:5;		//ʱ(0-23)	��Χ(0-32)
	unsigned int ucMinute:6;	//��(0-59)  ��Χ(0-64)
	unsigned int ucSecond:6;	//��(0-59)  ��Χ(0-64)
}GPSTime_S;

//����״̬,ÿλ��ʾ���������״̬
//uiStatus[0]����32λ
//0λ��ʾGPS��λ״̬		0��Ч1��Ч
//1λ��ʾACC״̬		0��ʾACC�ر�1��ʾACC����
//2λ��ʾ��ת״̬		0��Ч1��ת
//3λ��ʾ��ת״̬		0��Ч1��ת
//4λ��ʾɲ��״̬		0��Ч1ɲ��
//5λ��ʾ��ת״̬		0��Ч1��ת
//6λ��ʾ��ת״̬		0��Ч1��ת
//7λ��ʾGPS����״̬		0������1����
//8,9λΪ��ʾӲ��״̬		0�����ڣ�1���ڣ�2�ϵ�
//10,11,12λ��ʾ3Gģ��״̬  0ģ�鲻���ڣ�1���źţ�2�źŲ3�ź�һ�㣬4�źźã�5�ź���
//13λ��ʾ��ֹ״̬		1��ʾ��ֹ
//14λ��ʾ����״̬		1��ʾ����
//15λ��ʾ����״̬		1��ʾGPS����
//16λ����״̬
//17λ
//18λ
//19λ
//����ͣ��δϨ���������ֹ״̬�����Ҵ���ACC����״̬�����ʾͣ��δϨ��
//20λ��ʾIO1״̬	1��ʾ����
//21λ��ʾIO2״̬	1��ʾ����
//22λ��ʾIO3״̬	1��ʾ����
//23λ��ʾIO4״̬	1��ʾ����
//24λ��ʾIO5״̬	1��ʾ����
//25λ��ʾIO6״̬	1��ʾ����
//26λ��ʾIO7״̬	1��ʾ����
//27λ��ʾIO8״̬	1��ʾ����
//28λ��ʾ�̷�2״̬	1��ʾ��Ч
//29��30λ��ʾ��Ӳ��2��״̬		0�����ڣ�1���ڣ�2�ϵ�
//31δʹ��
//uiStatus[1]
//0λ��ʾ�����򱨾�	
//1λ��ʾ�����򱨾�	

//2λ��ʾ�����ڸ��ٱ���	
//3λ��ʾ�����ڵ��ٱ���	

//4λ��ʾ��������ٱ���
//5λ��ʾ��������ٱ���	

//6λ��ʾ������ͣ������	
//7λ��ʾ������ͣ������	
	
//8λ��ʾ������Ԥ��
//9λ��ʾ����������
//10λ��ʾ������Ԥ��
//11λ��ʾ����������

//12λ--���������ɺ󱸵�ع���
//13λ--���ſ�
//14λ--�������
//15λ--��ص�ѹ����
//16λ--��ػ�
//17λ--������

//18λ--Ϊ���һ����Ч��GPS��Ϣ��״̬��ʾ�ɶ�λ��Ч����GPS�����ڵ�ͼ�϶�λ
//19λ--0-����״̬ 1-����״̬

//uiStatus[2]
//0-7��ʾͨ����Ƶ��ʧ״̬
//8-15��ʾͨ��¼��״̬
//16-23��ʾIO����9-16 ״̬
//24-27��ʾIO���1-4 ״̬
//28-29 0��ʾGPS��λ��1��ʾ��վ��λ��2��ʾWifi��λ��  �ֻ���λҪ��ʾ�����λ��Ϣ

typedef struct _tagGPSVehicleGps
{
	GPSTime_S Time;
	unsigned int uiSpeed:14;	//�ٶ�ֵ KM/S	9999 = 999.9 	��Χ(0-16384)
	unsigned int uiYouLiang:18;	//����   ��	9999 = 99.99 	��Χ(0-262100)
	unsigned int uiLiCheng;		//���   ����	9999 = 9.999 	
	unsigned int uiHangXiang:9;	//���溽��(0-360) ��Χ(0-512)
	unsigned int uiMapType:3;	//��ͼ����		1��ʾGOOGLE��2��ʾ�ٶȣ�0��ʾ��Ч
	unsigned int uiReserve:20;  //����λ
	unsigned int uiStatus[4];		//Ŀǰֻʹ�ã�ÿ1��״̬	0λ��ʾGPS��λ״̬��0��Ч��1��Ч��
	short sTempSensor[4];	//�¶ȴ�������״̬
	int	nJingDu;		//����	4�ֽ� ��������	9999999 = 9.999999 
	int nWeiDu;			//γ��	4�ֽ� ��������	9999999 = 9.999999
	int	nGaoDu;			//�߶ȣ���ʱδʹ��
	int	nParkTime;		//ͣ��ʱ�� ��	�ھ�ֹ״̬ʱ��Ч
	int	nMapJingDu;		//ͨ����ͼģ���ȡ�ľ��Ⱥ�γ��
	int	nMapWeiDu;		//ͨ����ͼģ���ȡ�ľ��Ⱥ�γ��
	int	nReserve[2];		//��������
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
	char	guid[36];			//��ʶΨһ�ı�����Ϣ
	GPSVehicleGps_S Gps;		//����ʱ���GPS��Ϣ
	GPSTime_S Time;				//����ʱ��
	short 	AlarmType;			//��������
	short 	AlarmInfo;			//������Ϣ
	int	Param[4];				//��������
	char szDesc[256];			//��������
	//˵��srcAlarmType��srcTime������������Ϊ����ͼƬ�ϴ����ʱ��Ч����ʾ��Ӧ�ı���������Ϣ��ͼƬ�ϴ���ɱ�������
	//��������ΪͼƬ�ϴ�����ʱ��ֻʹ��AlarmType��szImgFile����������������ʾ��Ӧ��������
	short srcAlarmType;			//Դ��������
	short sReserve;				//��������
	GPSTime_S srcTime;			//Դ����ʱ��
	char szImgFile[256];		//ͼƬ�ļ���Ϣ����;�ָ���Ϊhttp��ַ·��������Ϊ���ͼƬ��Ϣ
	char szReserve[64];			//�����ֶ�
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
	char	guid[36];			//��ʶΨһ�ı�����Ϣ
	GPSVehicleGps_S Gps;		//����ʱ���GPS��Ϣ
	GPSTime_S Time;				//����ʱ��
	short 	AlarmType;			//��������
}GPSAlarmInfoEx_S, *LPGPSAlarmInfoEx_S;

typedef struct _tagGPSConfigData
{
	int nLength;		//���ݻ��泤��
	char cBuffer[1024];	//��������
}GPSConfigData_S, *LPGPSConfigData_S;

typedef struct _tagGPSTransPortData
{
	int nType;					//����
	GPSConfigData_S	Data;		//͸������
}GPSTransPortData_S, *LPGPSTransPortData_S;

//͸��ת������
typedef struct tagGPSAlarmTPD 
{
	char	szDevIDNO[32];
	GPSAlarmInfoEx_S VehiAlarm;
	GPSTransPortData_S TPD;	
}GPSAlarmTPD_S, *LPGPSAlarmTPD_S;
//-- end

//������־��Ŀ
typedef struct _tagGPSAlarmCount
{
	int nCount;
	char szReserve[8];
}GPSAlarmCount_S, *LPGPSAlarmCount_S;

//�����켣(����GPS�ͱ���)
typedef struct _tagGPSVehicleTrack
{
	int nType;					//��ʶ����������(GPS���ݻ��߱�������)
	GPSVehicleAlarm_S Alarm;	//��������(�������ΪGPS���� ��ֻ��GPS�ֶ�������Ч)
}GPSVehicleTrack_S, *LPGPSVehicleTrack_S;

//�켣����Ŀ
typedef struct _tagGPSTrackCount
{
	int nCount;
	char szReserve[8];
}GPSTrackCount_S, *LPGPSTrackCount_S;


typedef struct _tagGPSTrackInFenceInfo
{
	int		nDevID;				//����ID
	GPSTime_S BeginTime;		//��ʼʱ��
	GPSTime_S EndTime;			//����ʱ��
	int		nStartJingDu;		//�������򾭶�	4�ֽ� ��������	9999999 = 9.999999 
	int		nStartWeiDu;		//��������γ��	4�ֽ� ��������	9999999 = 9.999999
	int		nEndJingDu;			//�뿪���򾭶�	4�ֽ� ��������	9999999 = 9.999999 
	int		nEndWeiDu;			//�뿪����γ��	4�ֽ� ��������	9999999 = 9.999999
	char szRes[32];				//����32
}GPSTrackInFenceInfo_S, *LPGPSTrackInFenceInfo_S;

const int GPS_VEHICLE_ALARM_LENGTH = sizeof(GPSVehicleAlarm_S);
const int GPS_ALARM_INFO_LENGTH = sizeof(GPSAlarmInfo_S);
const int GPS_VHIECLE_GPS_LENGTH = sizeof(GPSVehicleGps_S);
const int GPS_VHIECLE_RUN_LENGTH = sizeof(GPSVehicleState_S);
const int GPS_VEHICLE_STATUS_LENGTH = sizeof(GPSVehicleStatus_S);
const int GPS_VEHICLE_TRACK_LENGTH = sizeof(GPSVehicleTrack_S);

//͸����������
typedef struct _tagGPSTranPortData
{
	int nID;
	char szDevIDNO[32];	//�������
	int nType;			//����
	SYSTEMTIME Time;		//ʱ��
	int	nLength;		//����
	char cData[1280];	//���ݳ���
}GPSTranPortData_S, *LPGPSTranPortData_S;

//͸������������Ŀ
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
	int	nWLanType;		////0����ʾ2G;1����ʾ3G-EVDO; 2����ʾ3G-WCDMA 
	int nWLanQuantity;	//�ź�ֵ	����ʾ
	char szWLanAddr[32];//�����ַ
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
	int nAllVolume;		//15923	��ʾ159.23	G //������
	int nLeftVolume;	//ͬ��  ///ʣ������
}GPSDiskInfo_S, *LPGPSDiskInfo_S;

const int GPS_DISK_INFO_COUNT			= 8;	//���Ӳ����ĿΪ8��

typedef struct _tagGPSDeviceStatus
{
	GPSDeviceInfo_S	DevInfo;	//�豸��Ϣ
	GPSWLanStatus_S	WLanInfo;	//3G״̬
	GPSWifiStatus_S	WifiInfo;	//WIFI��Ϣ
	GPSDiskInfo_S	DiskInfo[GPS_DISK_INFO_COUNT];	//Ӳ����Ϣ
	int	nVideoLost;		//��Ƶ��ʧ״̬  1��ʾ����Ƶ��ʧ
	int nRecord;		//¼��״̬ 0��û��¼��1¼��
	int nVideoTran;		//��Ƶ������Ŀ
	long l3GFlow;		//KBΪ��λ�����½��տ�ʼ�㣬�ۼ�
	long l4GFlow;		//KBΪ��λ�����½��տ�ʼ�㣬�ۼ�
	int nReserve[2];	//��������
}GPSDeviceStatus_S, *LPGPSDeviceStatus_S;

const int GPS_MOTION_MASK = 9;

typedef struct _tagGPSMotionParam
{
	int	nMask[GPS_MOTION_MASK];	//��11λ��ʾ�ƶ����
	BOOL bEnable;	//�Ƿ�����
	int	nSensitive;	//������
}GPSMotionParam_S, *LPGPSMotionParam_S;

typedef struct _tagGPSVideoColor
{
	int nExposure;		//�����
	int	nBrightness;	
	int	nConstract;	
	int	nHue;				
	int	nSaturate;			 
}GPSVideoColor_S, *LPGPSVideoColor_S;

//////////////////////////////////////////////////////////////////////////
//hw 2012-11-07
//������������
typedef struct _tagGPSNetFlowParam
{
	int nIsOpenFlowCount;		//����ͳ�ƿ��� 0-�رգ�1-����
	int nIsOpenDayFlowRemind;	//���������� 0-������ 1-����
	int nIsOpenMonthFlwRemind;	//���������� 0-������ 1-����
	float fDayLimit;			//����������(MB)
	float fMonthLimit;			//����������(MB)
	int nDayRemind;				//ÿ���������ѣ��ٷֱȣ���20%��20
	int nMonthRemind;			//ÿ���������ѣ��ٷֱȣ���20%��20
	int nMonthTotleDay;			//�½���
	char szRes[32];				//����32
}GPSNetFlowParam_S, *LPGPSNetFlowParam_S;

//��������ͳ��
typedef struct _tagGPSNetFlowStatistics
{
	GPSNetFlowParam_S	FlowParam;	//��������
	float fFlowUsedToday;			//��������
	float fFlowUsedMonth;			//������ʹ������
	int nStatisticsTime;			//ͳ��ʱ��
	char szRes[32];					//����32
}GPSNetFlowStatistics_S, *LPGPSNetFlowStatistics_S;	
//end
//////////////////////////////////////////////////////////////////////////

//����ָ��
typedef struct _tabGPSDispatchCommand
{
	char szGuid[40];		//ָ��GUID
	int nMapType;			//Ŀ�ĵأ���ͼ���ͣ�1��ʾGOOGLE��2��ʾ�ٶ�
	int nJingDu;			//����
	int nWeiDu;				//γ��
	char szCommand[256];	//������
}GPSDispatchCommand_S, *LPGPSDispatchCommand_S;


typedef union _tagUNCfg
{
// 	HI_S_Video cfgVideo;				/* ��Ƶ���� */
// 	HI_S_Audio cfgAudio;				/* ��Ƶ���� */
// 	HI_E_AudioInput cfgAudioInput;		/* ��Ƶ������� */
// 	HI_S_PTZ cfgPTZ;					/* ��̨���� */
}GPSCfg, *LPGPSCfg;

//�ļ���Ϣ
typedef struct _tagGPSRecHead_S
{
	int	nYear;			//��	2013
	int	nMonth;			//��	5
	int nDay;			//��	29
	int nBegHour;		//��ʼʱ��
	int nBegMinute;		
	int nBegSecond;
	unsigned __int64 u64BegPts;	//�ļ���ʼ��ʱ���
	unsigned int uiTotalMinSecond;	//�ļ���ʱ��������
	unsigned int uiAudioCodec;		//��Ƶ����������	TTX_AUDIO_CODEC_G726_40KBPS
	unsigned int uiAudioChannel;		//��Ƶͨ��
	unsigned int uiAudioSamplesPerSec;	//��Ƶ������
	unsigned int uiAudioBitPerSamples;	//��Ƶÿ��ȡ�������λԪ��
	unsigned int uiInfoCodec;		//��Ϣ֡������	TTX_INFO_CODEC_WKP
	char szReserve[64];		//�����ֶ�
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

//�û�������Ϣ
typedef struct _tagUserBasicInfo
{
	int nUserID;				//�û�ID		
	char szUserName[32];		//�û�����
	char szReserve[32];			//����32
}UserBasicInfo_S, *LPUserBasicInfo_S;


//�û���־��Ŀ
typedef struct _tagGPSUsrLogCount
{
	int nCount;
	char szReserve[8];
}GPSUsrLogCount_S, *LPGPSUsrLogCount_S;


//��ϵ��
typedef struct _tagContactInfo
{
	char szName[32];			//����
	char szPhone[16];			//�ֻ�
	char szTel[16];				//�绰
	char szReserve[16];			//����16
}ContactInfo_S, *LPContactInfo_S;

//ѧ����Ϣ
typedef struct _tagStudentInfo
{
	char szCarNum[32];			//����
	char szName[32];			//ѧ������
	int nStudySection;			//0-δ֪ 1-�׶�԰ 2-Сѧ 3-���� 4-���� 5-��ѧ
	int nGrade;					//0-δ֪��1-1�꼶��2-2�꼶
	int nClass;					//0-δ֪��1-1�� 2-2��
	ContactInfo_S Contact1;		//��ϵ��1
	ContactInfo_S Contact2;		//��ϵ��2
	char szEmail[64];			//email
	char szAddress[256];		//��ַ
	char szRemark[256];			//��ע
	char szReserve[256];		//����256
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
