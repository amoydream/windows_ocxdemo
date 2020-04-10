unit MainVideo;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, OleCtrls, ShellAPI,  Menus, ScktComp,
  TcpThreadUnit, ClientThreadUnit, ComCtrls, XPMan, Buttons, ActnList,
  ExtActns, ExtCtrls, IdHashMessageDigest, IdBaseComponent, IdComponent,
  IdTCPConnection, IdTCPClient, IdHTTP, DB,MATH, DBClient, ImgList, cxControls, cxSplitter,
  CMSV6OCXLib_TLB,CarUnit;

const
  VERSION = '(20180605.1000)';

  MY_APP_NAME           = '4G_CMSV';
  ID_MAIN = 100; // ����ͼ���ID
  WM_MAINNOTIFY = WM_USER + 100;  //�Զ�����Ϣ


  CLIENTTAGENT_0 = 0;    // ����
  CLIENTTAGENT_1 = 1;    // ǩ��ϵͳ
  CLIENTTAGENT_2 = 2;    // ǩ��ϵͳ


  // �������ͻ��ˣ���������50����
  AGENTTCLIENT_50 = 50;    // ͨ��Ӧ��
  AGENTTCLIENT_51 = 51;    // �绰���
  AGENTTCLIENT_52 = 52;    // �绰��ͨ
  AGENTTCLIENT_53 = 53;    // �绰����

  //����߶�700   ���880

type
  TMD5 = class(TIdHashMessageDigest5);
  TFrmMain = class(TForm)
    StatusBar1: TStatusBar;
    Panel2: TPanel;
    Label1: TLabel;
    lblState: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    Label2: TLabel;
    BtnCut: TSpeedButton;
    BtnSound: TSpeedButton;
    BtnPlay: TSpeedButton;
    btnstop: TSpeedButton;
    btnReload: TSpeedButton;
    BtnCanSPZ: TSpeedButton;
    cmbCPHM: TComboBox;
    editDeviceID: TEdit;
    cmbTongD: TComboBox;
    PageControl1: TPageControl;
    TabSheet1: TTabSheet;
    TabSheet2: TTabSheet;
    Panel3: TPanel;
    Label3: TLabel;
    Label6: TLabel;
    DT1: TDateTimePicker;
    Tm1: TDateTimePicker;
    DT2: TDateTimePicker;
    Tm2: TDateTimePicker;
    BtnJianSSP: TBitBtn;
    BtnYuanCHF: TBitBtn;
    Panel4: TPanel;
    m_lstSearch: TListView;
    PopupMenu1: TPopupMenu;
    N1: TMenuItem;
    N2: TMenuItem;
    XPManifest1: TXPManifest;
    Timer1: TTimer;
    Timer2: TTimer;
    FTemp: TClientDataSet;
    PopupMenu2: TPopupMenu;
    mnuDownLoad: TMenuItem;
    mmo1: TMemo;
    Label7: TLabel;
    cmbWJWZ: TComboBox;
    Panel1: TPanel;
    pnlTop: TPanel;
    pnlTop_Right: TPanel;
    Panel6: TPanel;
    CxSpltrTop: TcxSplitter;
    pnlTop_Left: TPanel;
    Panel5: TPanel;
    pnlBottom: TPanel;
    pnlBottom_Right: TPanel;
    Panel8: TPanel;
    CxSpltrBottom: TcxSplitter;
    pnlBottom_Left: TPanel;
    Panel7: TPanel;
    CxSpltrCenter: TcxSplitter;
    Label8: TLabel;
    cmbLXLX: TComboBox;
    BtnStopRecSearch: TBitBtn;
    Label9: TLabel;
    cmbWJLX: TComboBox;
    CMSV_1: TCMSV6OCX;
    CMSV_2: TCMSV6OCX;
    CMSV_3: TCMSV6OCX;
    CMSV_4: TCMSV6OCX;
    CMSV6OCX_Request: TCMSV6OCX;
    cmbDevID: TComboBox;
    N3: TMenuItem;
    ProgressBar1: TProgressBar;
    LabTip: TLabel;
    mnuDownLoadByTime: TMenuItem;
    procedure BtnPlayClick(Sender: TObject);
    procedure btnstopClick(Sender: TObject);
    procedure BtnCutClick(Sender: TObject);
    procedure BtnSoundClick(Sender: TObject);
    procedure BtnCanSPZClick(Sender: TObject);
    procedure cmbCPHMChange(Sender: TObject);
    procedure cmbCPHMKeyPress(Sender: TObject; var Key: Char);
    procedure editDeviceIDChange(Sender: TObject);
    procedure cmbTongDChange(Sender: TObject);
    procedure Timer2Timer(Sender: TObject);
    procedure Timer1Timer(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure FormCloseQuery(Sender: TObject; var CanClose: Boolean);
    procedure FormShow(Sender: TObject);
    procedure BtnJianSSPClick(Sender: TObject);
    procedure BtnYuanCHFClick(Sender: TObject);
    procedure mnuDownLoadClick(Sender: TObject);
    procedure PageControl1Change(Sender: TObject);
    procedure BtnStopRecSearchClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure N3Click(Sender: TObject);
    procedure CMSV6OCX_RequestRecSearchEventEx(ASender: TObject;
      const strFile: WideString; nStartTime, nEndTime: TDateTime; nFileLen,
      nFileType, nSvrID, nLocation, nChannel, bStream, bRecording,
      nFileOffset, nChnMask, nAlarmInfo: Integer);
    procedure CMSV6OCX_RequestDownFileExEvent(ASender: TObject; nMsg,
      nParam: Integer);
    procedure mnuDownLoadByTimeClick(Sender: TObject);
  private
    { Private declarations }
    ACarManage:TCarManage;
    FSearch: Boolean;
    FNid: NOTIFYICONDATA;
    FChannelID: Integer;    // �豸ͨ����(��1��ʼ)
    FDeviceID: String;      // �豸���к�
    settings : TFormatSettings;
    procedure addVideoRecordInfoToList(info: string);
    function GetFormNameAt(const Pos: TPoint): string;
    function AddIcon(hwnd: HWND): Boolean; //��״̬�����ͼ��
    function RemoveIcon(hwnd: HWND): Boolean; //��״̬����ȥͼ��
    function ModifyIcon(hwnd: HWND; Title: String): Boolean; // ����������ʾ��Ϣ
    procedure minimize(sender: Tobject); //������С�����̣�����Application.OnMinimize;
    procedure Notify(var Msg: TMessage); message WM_MAINNOTIFY; //�Զ�����Ϣ������
    procedure CreateParams(var Params: TCreateParams);override;
    procedure WMCopyData(var Message: TWMCopyData); message WM_COPYDATA;
    procedure SendCopyData(Msg: string);
    procedure SetCmsv;
    // ���س�����Ϣ
    procedure LoadCarInfo;
    Function GetDllPath:string;
 
    function Logout: boolean;
    function PlayVideo: boolean;
    function StopVideo: boolean;

  public
    { Public declarations }
    FServerIP: String;      // ע����Ƶ������
    FPort: Integer;         // ע����Ƶ�������˿ں� 

    FStreamServerIP: String;  // ��ý�������IP
    FStreamPort: Integer;     // ��ý��������˿ں�
    FStreamType: Integer;		  // �������� (0-������; 1-������)
    FStreamMode: Integer;     // ��ý�����������ǰ����Ƶ��ģʽ 0:UDP;1:TCP

    FCloseTime:Integer;//�Զ��ر�ʱ��(��)
    FCutPicFilePath: string;  // ��Ƶ��ͼ·��

    FCmsv1:Integer; ////
    FCmsv2:Integer;
    FCmsv3:Integer;
    FCmsv4:Integer;
    FCmsv_Req:Integer;
    strPathDir: string;
    {StartVideo            StopVideo          1
    StartTalkBack         StopTalkBack        2
    StartMonitor          StopMonitor         3
    StartRecord           StopRecord          4
    StartRecSearch        StopRecSearch       5
    StartPlaybackRec
    StartDownFile         StopDownFile         6
    StartSubscribeGps     StopSubscribeGps    7
    StartSubscribeAlarm   StopSubscribeAlarm   8
    StartVoiceBroadcast   StopVoiceBroadcast   9
    StartDownFileEx       StopDownFileEx       10     }
    procedure InitParam;
    procedure Set3GConfig(IP: string; PORT: Integer; USER: string; Password: string; CutPicFilePath: string);
  end;

type
  TGPSFileDef = record       {����ṹ TRec}

    iYear:word;
    iMonth:word;
    iDay:word;
    sDevIDNO:WideString;
    iChannel:Integer;
    sFileName: WideString;
    iFileLen:integer;
    dtBTime:TDateTime;
    dtETime:TDateTime;
    iLocation:Integer;
    iSvrID:integer;
    iFileType:integer;
    iFileAttr:integer;
    sSave:WideString;
  end;
  PGpsFile = ^TGPSFileDef;
  //procedure TFrmMain.CMSV6OCX_RequestRecSearchEvent(ASender: TObject;
  //const strFile: WideString; nStartTime, nEndTime: TDateTime; nFileLen,
  //nFileType, nSvrID, nLocation, nChannel: Integer);
//typedef struct _tagGPSFile
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
}//GPSFile_S, *LPGPSFile_S;

var
  FrmMain: TFrmMain;

implementation

uses IniFiles, DateUtils, ZipLibUnit, ParamDlgFrmUnit,UDownLoadByTime;

{$R *.dfm}


function TFrmMain.Logout: boolean;
  procedure stopSvr(iCmsv:Integer;pCmsv:TCMSV6OCX);
  begin
    if iCmsv = 1  then
        pCmsv.StopVideo(0)
    else if iCmsv = 2  then
        pCmsv.StopTalkBack
    else if iCmsv = 3  then
        pCmsv.StopMonitor
    else if iCmsv = 4  then
        pCmsv.StopRecord(FDeviceID,0)
    else if iCmsv = 5  then
        pCmsv.StopRecSearch
    else if iCmsv = 6  then
        pCmsv.StopDownFile
    else if iCmsv = 7  then
        pCmsv.StopSubscribeGps
    else if iCmsv = 8  then
        pCmsv.StopSubscribeAlarm
    else if iCmsv = 9  then
        pCmsv.StopVoiceBroadcast
    else if iCmsv = 10  then
        pCmsv.StopDownFileEx;
  end;
begin
  {  {StartVideo             StopVideo            1
    StartTalkBack         StopTalkBack        2
    StartMonitor          StopMonitor         3
    StartRecord           StopRecord          4
    StartRecSearch        StopRecSearch       5
    StartPlaybackRec
    StartDownFile         StopDownFile         6
    StartSubscribeGps     StopSubscribeGps    7
    StartSubscribeAlarm   StopSubscribeAlarm   8
    StartVoiceBroadcast   StopVoiceBroadcast   9
    StartDownFileEx       StopDownFileEx       10     }
  try
    stopSvr(FCmsv1,CMSV_1);
    Sleep(100);
    stopSvr(FCmsv2,CMSV_2);
    Sleep(100);
    stopSvr(FCmsv3,CMSV_3);
    Sleep(100);
    stopSvr(FCmsv4,CMSV_4);
    Sleep(100);
    stopSvr(FCmsv_Req,CMSV6OCX_Request);
    result := true;
  except
    result := false;
  end;
end;

function TFrmMain.PlayVideo: boolean;
begin 
  try
    result := False;
    if cmbTongD.ItemIndex = 0 then
    begin
        if  CMSV_1.CheckOnline(trim(editDeviceID.Text))<>0 then
        begin
            showmessage('�豸1 ������!');
            exit;
        end
        else
        begin
            if  CMSV_1.StartVideo(FDeviceID,0,0) = 0 then
            begin
              FCmsv1 := 1;
              result := True;
            end;
        end;
    end
    else if cmbTongD.ItemIndex = 1 then
    begin
        if  CMSV_1.CheckOnline(trim(editDeviceID.Text))<>0 then
        begin
            showmessage('�豸1 ������!');
            exit;
        end;
        if  CMSV_2.CheckOnline(trim(editDeviceID.Text))<>0 then
        begin
            showmessage('�豸2 ������!');
            exit;
        end;
        if  CMSV_1.StartVideo(FDeviceID,0,0) = 0  then
        begin
            FCmsv1 := 1;
            Sleep(100);
            if CMSV_2.StartVideo(FDeviceID,1,0) = 0 then
            begin
              FCmsv2 := 1;
              result := True;
            end;
        end;
    end
    else if cmbTongD.ItemIndex = 2 then
    begin
        if  CMSV_1.CheckOnline(trim(editDeviceID.Text))<>0 then
        begin
            showmessage('�豸1 ������!');
            exit;
        end;
        if  CMSV_2.CheckOnline(trim(editDeviceID.Text))<>0 then
        begin
            showmessage('�豸2 ������!');
            exit;
        end;
        if  CMSV_3.CheckOnline(trim(editDeviceID.Text))<>0 then
        begin
            showmessage('�豸3 ������!');
            exit;
        end;
        if  CMSV_1.StartVideo(FDeviceID,0,0) = 0 then
        begin
          FCmsv1 := 1;
          Sleep(100);
          if CMSV_2.StartVideo(FDeviceID,1,0) = 0 then
          begin
              FCmsv2 := 1;
              Sleep(100);
              if CMSV_3.StartVideo(FDeviceID,2,0) = 0 then
              begin
                  FCmsv3 := 1;
                  result := True;
              end;
          end;
        end;
    end
    else
    begin
        if  CMSV_1.CheckOnline(trim(editDeviceID.Text))<>0 then
        begin
            showmessage('�豸1 ������!');
            exit;
        end;
        if  CMSV_2.CheckOnline(trim(editDeviceID.Text))<>0 then
        begin
            showmessage('�豸2 ������!');
            exit;
        end;
        if  CMSV_3.CheckOnline(trim(editDeviceID.Text))<>0 then
        begin
            showmessage('�豸3 ������!');
            exit;
        end;
        if  CMSV_4.CheckOnline(trim(editDeviceID.Text))<>0 then
        begin
            showmessage('�豸4 ������!');
            exit;
        end;
        if CMSV_1.StartVideo(FDeviceID,0,0) = 0 then
        begin
          FCmsv1 := 1;
          Sleep(100);
          if CMSV_2.StartVideo(FDeviceID,1,0) = 0 then
          begin
            FCmsv2 := 1;
            Sleep(100);
            if CMSV_3.StartVideo(FDeviceID,2,0) = 0 then
            begin
              FCmsv3 := 1;
              Sleep(100);
              if CMSV_4.StartVideo(FDeviceID,3,0) = 0 then
              begin
                FCmsv4 := 1;
                result := True;
              end;
            end;
          end;
        end;
    end;
  except
    result := false;
  end;
end;

function TFrmMain.StopVideo: boolean;
begin
  try
    CMSV_1.StopVideo(0);
    Sleep(100);
    CMSV_2.StopVideo(0);

    Sleep(100);
    CMSV_3.StopVideo(0);

    Sleep(100);
    CMSV_4.StopVideo(0);

    result := True;
  except
    result := False;
  end;
end;

procedure TFrmMain.InitParam;
var
    strDevID:string;
    IniFile: TIniFile;
    FilePath: string;
begin
  try
    FChannelID := 0; 
    FilePath := ExtractFilePath(Application.ExeName);
    IniFile := TIniFile.Create(FilePath + 'CMSV_4G.ini');

    try
      FServerIP := IniFile.ReadString('ini', 'IP', '120.26.98.110');      // 218.2.75.219
      //FServerIP := IniFile.ReadString('ini', 'IP', '');   
      FPort := IniFile.ReadInteger('ini', 'PORT', 6605);        // 10000


      FStreamServerIP := IniFile.ReadString('ini', 'STREAMIP', '');
      FStreamPort := IniFile.ReadInteger('ini', 'STREAMPORT', 7554);

      FStreamType:= IniFile.ReadInteger('ini', 'STREAMTYPE', 0);
      FStreamMode := IniFile.ReadInteger('ini', 'STREAMMODE', 1);

      FCutPicFilePath := IniFile.ReadString('ini', 'CUTPICFILEPATH', '');
      FCloseTime :=   IniFile.ReadInteger('ini', 'CloseTime', 0);
    finally
      IniFile.Free;
    end;

    LoadCarInfo;

    cmbTongDChange(Self);
    cmbCPHM.Text := ParamStr(2);


    if  Length(Trim(cmbCPHM.Text))>=8  then
        strDevID := ACarManage.FindDevIdByCarNo(Copy(Trim(cmbCPHM.Text),3,50))
    else
        strDevID := ACarManage.FindDevIdByCarNo(Trim(cmbCPHM.Text));
    while Length(strDevID)<10 do
        strDevID := '0'+strDevID;
    editDeviceID.Text := strDevID;
    
    //Label1.Visible  := False;
    //lblState.Visible:= False;

    Self.Caption := '�Ͼ�ͨ�õ���4G��Ƶ ' + VERSION+'  ͨ�ð汾';
  except
    on e: exception do
    begin
      messagebox(handle, pchar('Create:' + e.Message), '��ʾ', mb_ok + MB_ICONWARNING);
    end;
  end;
end;

procedure TFrmMain.Set3GConfig(IP: string; PORT: Integer; USER, Password,
  CutPicFilePath: string);
begin
  try
    FServerIP := IP;      //  
    FPort := PORT;        // 10000 
    FCutPicFilePath := CutPicFilePath;
  except
    on e: Exception do
    begin
      ShowMessage(e.Message);
    end;
  end;
end;

function TFrmMain.AddIcon(hwnd: HWND): Boolean;
begin
  FNid.cbSize := sizeof(NOTIFYICONDATA);
  FNid.Wnd := hwnd;
  FNid.uID := ID_MAIN;
  FNid.uFlags := NIF_MESSAGE or NIF_ICON or NIF_TIP;
  FNid.uCallbackMessage := WM_MAINNOTIFY;
  FNid.hIcon := LoadIcon(HInstance, 'MAINICON');
  strCopy(FNid.szTip, '�Ͼ�ͨ��-4G��Ƶ');
  AddIcon := Shell_NotifyIcon(NIM_ADD, @FNid);
end;

procedure TFrmMain.addVideoRecordInfoToList(info: string);
var
  i: Integer;
  sList: TStringList;
  strRec: string;
  sTemp: string;
  sDevId, sFileName: string;
  sChannelNo, sRecType: string;
  dtOrg,dtS, dtE: TDateTime;
  sFileSize, sFileOffset: string;
begin
  strRec := StringReplace(info, ' ', ';', [rfReplaceAll]);
  sList := TStringList.Create;
  try
    try
      ExtractStrings([';'], [' '], PChar(strRec), sList); 
      sTemp := sList.Strings[0];
      sDevId := Copy(sTemp, 10, Length(sTemp) - 9);

      sTemp := sList.Strings[1];
      sChannelNo := Copy(sTemp, 4, Length(sTemp) - 3);

      sTemp := sList.Strings[2];
      sRecType := Copy(sTemp, 6, Length(sTemp) - 5);

      dtOrg := StrToDateTime('1970-01-01 00:00:00', settings);
      sTemp := sList.Strings[3];
      i := StrToInt(Copy(sTemp, 11, Length(sTemp) - 10));
      dtS := IncSecond(dtOrg, i);

      sTemp := sList.Strings[4];
      i := StrToInt(Copy(sTemp, 9, Length(sTemp) - 8));
      dtE := IncSecond(dtOrg, i);

      sTemp := sList.Strings[7];
      sFileSize := Copy(sTemp, 10, Length(sTemp) - 9);

      sTemp := sList.Strings[8];
      sFileOffset := Copy(sTemp, 12, Length(sTemp) - 11);

      sTemp := sList.Strings[9];
      sFileName := Copy(sTemp, 10, Length(sTemp) - 9);

      with m_lstSearch.Items.Add do
      begin
        Caption := sDevId; 
        SubItems.Add(FormatDateTime('yy-MM-dd hh:nn', dtS));
        SubItems.Add(FormatDateTime('yy-MM-dd hh:nn', dtE));
        SubItems.Add(sFileSize);
        SubItems.Add(sFileName);
        SubItems.Add(sFileOffset);
      end;
    except
      on e: Exception do ShowMessage(e.Message);
    end;
  finally
    sList.Free;
  end;
end;

procedure TFrmMain.CreateParams(var Params: TCreateParams);
begin
  inherited CreateParams(Params);
  Params.WinClassName := MY_APP_NAME;
end;

function TFrmMain.GetDllPath: string;
var
  ModuleName:string;
  FilePath: string;
begin
  SetLength(ModuleName, 255);  //ȡ��Dll����·��
  GetModuleFileName(HInstance, PChar(ModuleName), Length(ModuleName));
  FilePath := ExtractFilePath(ModuleName);
  result := FilePath;
end;

function TFrmMain.GetFormNameAt(const Pos: TPoint): string;
var
  w: TWinControl;
begin
  try
    //�õ����ָ���µ�VCL�������
    w:= FindVclWindow(Pos);
    if (w <> nil) then
    begin
      //��W���ϼ�Parent��Ϊ��ʱ�ͼ���������
      while w.Parent <> nil do
        w:= w.Parent;
      //��󷵻ش��������Name
      Result:= w.Name;
    end
    else
      Result:= '';
  except
  end;
end;


procedure TFrmMain.LoadCarInfo;
var
  Info, ZIP: string;
  fs: TFileStream;
  FileName: string;
  FilePath: string;
  TmpCar: TCar; 
begin
  try
    FilePath := ExtractFileDir(ExtractFilePath(Application.ExeName));

    FilePath := ExtractFileDir(FilePath);
                //E:\project_njty\19-���ָ��\bin\DBINFO   E:\project_njty\19-���ָ��\bin\3G_Viedo
    FileName := FilePath + '\DBINFO\CARINFO';                  //ExtractFilePath(Application.ExeName) +
    if not FileExists(FileName) then
    begin
      MessageBox(Handle, 'û�г����������ݣ����ȵ�½��ؿͻ��ˣ�', '��ʾ', MB_OK + MB_ICONWARNING);
      exit;
    end;

    fs := TFileStream.Create(FileName,fmOpenRead);
    try
      SetLength(ZIP, fs.size);
      fs.Read(ZIP[1],fs.size);
    finally
      fs.Free;
    end;

    Info := DeCompress(ZIP);
    FTemp.XMLData := info;
    FTemp.Open;
    cmbCPHM.Clear;

    FTemp.First;
    while not FTemp.Eof do
    begin  
        TmpCar := ACarManage.AddNewCar(FTemp.FieldByName('CAR_ID').AsInteger);
        TmpCar.CarNo :=  FTemp.FieldByName('CAR_NO').AsString;
        TmpCar.DevID :=  FTemp.FieldByName('DEV_ID').AsString;
        cmbCPHM.Items.Add(FTemp.FieldByName('CAR_NO').AsString); 
        FTemp.Next;
    end;
  except
  end;      
end;

procedure TFrmMain.minimize(sender: Tobject);
begin
  ShowWindow(Handle, SW_HIDE);
end;

function TFrmMain.ModifyIcon(hwnd: HWND; Title: String): Boolean;
begin
  try 
  except
  end;
end;

procedure TFrmMain.Notify(var Msg: TMessage);
var
  Pt: TPoint;
begin
  case msg.LParam of
    WM_RBUTTONDOWN,WM_LBUTTONDOWN,WM_LBUTTONDBLCLK:    //������Ҽ�ʱ,������ݲ˵�
      begin
        SetForeGroundWindow(FNid.wnd);
        GetCursorPos(Pt);
        Popupmenu1.Popup(pt.x, pt.y);
      end;
  end;
end;

function TFrmMain.RemoveIcon(hwnd: HWND): Boolean;
var
  nid: NOTIFYICONDATA;
begin
  try
    nid.cbSize := sizeof(NOTIFYICONDATA);
    nid.Wnd := hwnd;
    nid.uID := ID_MAIN;
    nid.uFlags := 0;
    RemoveIcon := Shell_NotifyIcon(NIM_DELETE, @nid);
  except
  end;
end;

procedure TFrmMain.SendCopyData(Msg: string);
var
  h: HWND;
  Size: Integer;
  CopyDataStruct: TCopyDataStruct;
begin
  h := FindWindow(nil, '���ָ��-4G��Ƶ');           { ���������Ŀ�괰�� }
  if h > 0 then
  begin
    Size := Length(Msg) + 2;                                  { ����������ֽ����ں���� #0 }
    CopyDataStruct.lpData := PChar(Msg + #10);                { Ҫ���͵��ַ���, #0 ��ʾ PChar ����}
    CopyDataStruct.dwData := WM_COPYDATA;                     { ָ����Ϣ���� }
    CopyDataStruct.cbData := Size;                            { ָ��Ҫ���͵����ݵĴ�С }
    SendMessage(h, WM_COPYDATA, 0, Integer(@CopyDataStruct)); { ���� }
  end;
end;

procedure TFrmMain.WMCopyData(var Message: TWMCopyData);
var
  Msg: string;
begin
  try
    Msg := PChar(Message.CopyDataStruct.lpData);
  except
  end;
end;

procedure TFrmMain.BtnPlayClick(Sender: TObject);
begin
  if trim(editDeviceID.Text)='' then
  begin
      showmessage('���ն�!');
      exit;
  end;
 
  if PlayVideo then
  begin
    lblState.Caption := '����Ƶ���ųɹ�';
  end else
  begin
    lblState.Caption := '����Ƶ����ʧ��';
  end;
end;

procedure TFrmMain.btnstopClick(Sender: TObject);
begin
  try
    StopVideo;
    lblState.Caption := '�ر���Ƶ���ųɹ�';
  except
    messagebox(handle, '�ر���Ƶ����ʧ�ܣ�', '��ʾ', mb_ok + MB_ICONWARNING);
  end;
end;

procedure TFrmMain.BtnCutClick(Sender: TObject);

begin
  try
    if  CMSV_1.CheckOnline(trim(editDeviceID.Text))<>0 then
    begin
        showmessage('�豸1 ������!');
        exit;
    end;
    if  CMSV_2.CheckOnline(trim(editDeviceID.Text))<>0 then
    begin
        showmessage('�豸2 ������!');
        exit;
    end;
    if  CMSV_3.CheckOnline(trim(editDeviceID.Text))<>0 then
    begin
        showmessage('�豸3 ������!');
        exit;
    end;
    if  CMSV_4.CheckOnline(trim(editDeviceID.Text))<>0 then
    begin
        showmessage('�豸4 ������!');
        exit;
    end;
    CMSV_1.CapturePicture(0);
    Sleep(100);
    CMSV_2.CapturePicture(0);
    Sleep(100);
    CMSV_3.CapturePicture(0); 
    Sleep(100);
    CMSV_4.CapturePicture(0);
    MessageBox(handle, '��Ƶ��ͼ��ɣ�', '��ʾ', mb_ok + MB_ICONWARNING);
  except
  end;
end;

procedure TFrmMain.BtnSoundClick(Sender: TObject);
begin
  if cmbTongD.ItemIndex = 0 then
  begin
      if  CMSV_1.CheckOnline(trim(editDeviceID.Text))<>0 then
      begin
          showmessage('�豸1 ������!');
          exit;
      end;
      if CMSV_1.OpenSound(0) = 0 then
          Fcmsv1 := 3
      else
          messagebox(handle, '����Ƶ����ʧ�ܣ�', '��ʾ', mb_ok + MB_ICONWARNING);
  end
  else if cmbTongD.ItemIndex = 1 then
  begin
      if  CMSV_2.CheckOnline(trim(editDeviceID.Text))<>0 then
      begin
          showmessage('�豸2 ������!');
          exit;
      end;
      if CMSV_2.OpenSound(0) = 0 then
          Fcmsv2 := 3
      else
          messagebox(handle, '����Ƶ����ʧ�ܣ�', '��ʾ', mb_ok + MB_ICONWARNING);
  end
  else if cmbTongD.ItemIndex = 2 then
  begin
      if  CMSV_3.CheckOnline(trim(editDeviceID.Text))<>0 then
      begin
          showmessage('�豸3 ������!');
          exit;
      end;
      if CMSV_3.OpenSound(0) = 0 then
          Fcmsv3 := 3
      else
          messagebox(handle, '����Ƶ����ʧ�ܣ�', '��ʾ', mb_ok + MB_ICONWARNING);
  end
  else if cmbTongD.ItemIndex = 3 then
  begin
      if  CMSV_4.CheckOnline(trim(editDeviceID.Text))<>0 then
      begin
          showmessage('�豸4 ������!');
          exit;
      end;
      if CMSV_4.OpenSound(0) = 0 then
          Fcmsv4 := 3
      else
          messagebox(handle, '����Ƶ����ʧ�ܣ�', '��ʾ', mb_ok + MB_ICONWARNING);
  end;
end;

procedure TFrmMain.BtnCanSPZClick(Sender: TObject);
var
  dlg: TParamDlgFrm;
  IniFile: TIniFile;
  FilePath: string;
begin
  dlg := TParamDlgFrm.Create(self);
  try
    with dlg do
    begin
      LabeledEditIP.Text             := FServerIP;
      LabeledEditPort.Text           := IntToStr(FPort);
      LabeledEditStreamIP.Text       := FStreamServerIP;
      LabeledEditStreamPort.Text     := IntToStr(FStreamPort);
      cbxStreamType.ItemIndex        := FStreamType;
      cbxStreamMode.ItemIndex        := FStreamMode;
      LabeledEditCutPicFilePath.Text := FCutPicFilePath;
      lbledtCloseTime.Text           := IntToStr(FCloseTime);
    end;
    dlg.ShowModal;
    if dlg.ModalResult = mrOk then
    begin
      with dlg do
      begin
        FServerIP := LabeledEditIP.Text;
        FPort := StrToIntDef(LabeledEditPort.Text, 6605);
        FStreamServerIP := LabeledEditStreamIP.Text;
        FStreamPort     := StrToIntDef(LabeledEditStreamPort.Text, 7554);
        FStreamType     := cbxStreamType.ItemIndex;
        FStreamMode     := cbxStreamMode.ItemIndex;
        FCutPicFilePath := LabeledEditCutPicFilePath.Text;
        FCloseTime      := StrToIntDef(lbledtCloseTime.Text, 0);
      end;

      FilePath := GetDllPath; 
      IniFile := TIniFile.Create(FilePath + 'CMSV_4G.ini');
      try
        try
          IniFile.WriteString('ini', 'IP', FServerIP);
          IniFile.WriteString('ini', 'PORT', IntToStr(FPort)); 
          IniFile.WriteString('ini', 'STREAMIP', FStreamServerIP);
          IniFile.WriteString('ini', 'STREAMPORT', IntToStr(FStreamPort));
          IniFile.WriteInteger('ini', 'STREAMTYPE', FStreamType);
          IniFile.WriteInteger('ini', 'STREAMMODE', FStreamMode);
          IniFile.WriteString('ini', 'CUTPICFILEPATH', FCutPicFilePath);

          IniFile.WriteInteger('ini', 'CloseTime', FCloseTime);
 
          messagebox(handle, '����ɹ���', '��ʾ', mb_ok + mb_iconinformation);
        except
        end;
      finally
        IniFile.Free;
      end;
    end;
  finally
    dlg.Free;
  end;
end;

procedure TFrmMain.cmbCPHMChange(Sender: TObject);
var
    strDevID:string;
begin
    if  Length(Trim(cmbCPHM.Text))>=8  then
        strDevID := ACarManage.FindDevIdByCarNo(Copy(Trim(cmbCPHM.Text),3,50))
    else
        strDevID := ACarManage.FindDevIdByCarNo(Trim(cmbCPHM.Text));
    while Length(strDevID)<10 do
        strDevID := '0'+strDevID;
    editDeviceID.Text := strDevID;
    if   Copy(Trim(cmbCPHM.Text),1,2)='��' then
    begin
        Label1.Visible  := False;
        lblState.Visible:= False;
    end; 
end;

procedure TFrmMain.cmbCPHMKeyPress(Sender: TObject; var Key: Char);
var
  strDevID:string;
begin
  if (Key = #13) then
  begin
    if  Length(Trim(cmbCPHM.Text))>=8  then
        strDevID := ACarManage.FindDevIdByCarNo(Copy(Trim(cmbCPHM.Text),3,50))
    else
        strDevID := ACarManage.FindDevIdByCarNo(Trim(cmbCPHM.Text));
    while Length(strDevID)<10 do
        strDevID := '0'+strDevID;
    editDeviceID.Text := strDevID;

  end;
end;

procedure TFrmMain.editDeviceIDChange(Sender: TObject);
begin
  FDeviceID := StringReplace(Trim(editDeviceID.Text), '��', '',  [rfReplaceAll]) ;
  FDeviceID := StringReplace(Trim(editDeviceID.Text), '��', '',  [rfReplaceAll]);
  FDeviceID := StringReplace(Trim(editDeviceID.Text), '��', '',  [rfReplaceAll]);
  if   Copy(Trim(editDeviceID.Text),1,2)='��' then
  begin
      Label1.Visible  := False;
      lblState.Visible:= False;
  end;
  FDeviceID := StringReplace(Trim(editDeviceID.Text), '��', '',  [rfReplaceAll]);
end;

procedure TFrmMain.cmbTongDChange(Sender: TObject);
begin
  FChannelID := cmbTongD.ItemIndex;

 if cmbTongD.ItemIndex = 0 then
  begin
    CxSpltrTop.CloseSplitter;
    CxSpltrTop.Visible := False;

    CxSpltrCenter.CloseSplitter;
    CxSpltrCenter.Visible := False;
 
    FrmMain.SetBounds(286, 17, 800, 700);
    //FrmMain.Position := poDesktopCenter;
  end
  else if cmbTongD.ItemIndex = 1 then
  begin
    CxSpltrTop.Visible := True;
    CxSpltrTop.OpenSplitter;

    CxSpltrCenter.CloseSplitter;
    CxSpltrCenter.Visible := False;


    pnlTop_Right.Width := 500;

    FrmMain.SetBounds(186, 34, 1000, 600);
  end
  else if cmbTongD.ItemIndex = 2 then
  begin
    CxSpltrTop.Visible := True;
    CxSpltrTop.OpenSplitter;

    CxSpltrCenter.Visible := True;
    CxSpltrCenter.OpenSplitter;

    CxSpltrBottom.CloseSplitter;
    CxSpltrBottom.Visible := False;


    pnlTop_Right.Width := 400;

    FrmMain.SetBounds(286, 17, 800, 700);
  end
  else
  begin
    CxSpltrTop.Visible := True;
    CxSpltrTop.OpenSplitter;

    CxSpltrCenter.Visible := True;
    CxSpltrCenter.OpenSplitter;

    CxSpltrBottom.OpenSplitter;
    CxSpltrBottom.Visible := True;

    pnlBottom_Right.Width := pnlBottom_Right.Width+1;
    CMSV_4.Visible := True;


    pnlTop_Right.Width := 400;

    FrmMain.SetBounds(286, 17, 800, 700);
  end;
end;

procedure TFrmMain.Timer2Timer(Sender: TObject);
begin
  try 
    if self.Top <= 20 then
    begin
      self.Top:= -(self.Height - 3);
      if (self.Left + self.Width > Screen.Width) then
        self.Left:= Screen.Width - self.Width;
    end
    else if self.Left + self.Width - Screen.Width >= -20 then
      self.Left:= Screen.Width - 4;
  except
  end;
end;

procedure TFrmMain.Timer1Timer(Sender: TObject);
var
  winPos: TPoint;
  t: integer;
  b: boolean;
begin
  try
    b:= False;
    if (self.Top <= 3) then
    begin
      b:= true;
      t:= 0;
    end
    else if self.Left + self.Width - Screen.Width >= 0 then
    begin
      b:= true;
      t:= self.Top;
    end
    else
      t:= self.Top;
    if b then
    begin
      GetCursorPos(winPos);
      if self.Name = GetFormNameAt(winPos) then
      begin
        timer2.Enabled:= false;
        self.Top:= t;
        if t <> 0 then
          self.Left:= Screen.Width - self.Width;
      end
      else
      begin
        Timer2.Enabled:= true;
      end;
    end;
  except
  end;
end;

procedure TFrmMain.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  ACarManage.Free;
  try
    Logout;
    RemoveIcon(handle);
  except
  end;
end;

procedure TFrmMain.FormCloseQuery(Sender: TObject; var CanClose: Boolean);
begin
  if messagebox(handle, '��ȷ��Ҫ�˳�4G��Ƶ��������', '�˳�ѡ��', MB_OKCANCEL + MB_ICONQUESTION) = ID_CANCEL then
    CanClose := false;
end;

procedure TFrmMain.FormShow(Sender: TObject);
begin
  PageControl1.ActivePageIndex := 0;
 
  InitParam;
  SetCmsv;
  FCmsv1 := 0;
  FCmsv2 := 0;
  FCmsv3 := 0;
  FCmsv4 := 0;
  FCmsv_Req := 0;
end;
 
procedure TFrmMain.BtnJianSSPClick(Sender: TObject);
var
  dtTemp: TDateTime;
  startDateTime, endDateTime: Tdatetime;
  recCount: Integer;
  i,iLXLX: Integer;
  s: string;
begin

  if FDeviceID='' then
  begin
      ShowMessage('����д�豸�ţ�');
      exit;
  end;  

  try
      CMSV6OCX_Request.ServerIP   := FServerIP;
      CMSV6OCX_Request.ServerPort := FPort;
      if  CMSV6OCX_Request.CheckOnline(trim(editDeviceID.Text))<>0 then
      begin
          showmessage('��Ƶ�㲥�豸������!');
          exit;
      end;
      m_lstSearch.Clear;
      GetLocaleFormatSettings(GetUserDefaultLCID, settings);
      settings.DateSeparator := '-';
      settings.TimeSeparator := ':';
      settings.ShortDateFormat := 'YYYY-MM-DD';
      settings.ShortTimeFormat := 'hh:nn:ss';
      dtTemp := StrToDateTime('1970-01-01 00:00:00', settings);

      startDateTime := DT1.DateTime;
      ReplaceTime(startDateTime, Tm1.Time);

      endDateTime := DT2.DateTime;
      ReplaceTime(endDateTime, Tm2.Time);
      if  cmbLXLX.ItemIndex =  0  then
          iLXLX := 0;    //¼������
      if  cmbLXLX.ItemIndex =  1  then
          iLXLX := 1;
      if  cmbLXLX.ItemIndex =  2  then
          iLXLX := -1;

      
      recCount := CMSV6OCX_Request.StartRecSearch(FDeviceID,cmbTongD.ItemIndex,  //ͨ��
                                iLXLX,startDateTime, endDateTime,  // 	0 //����¼�� 	1 //����¼�� 		-1 //ȫ��
                                cmbWJWZ.ItemIndex+1,cmbWJLX.ItemIndex+1);     ///1-�豸 2-�洢������ 3-���� 4-���ط�����  //1ͼƬ 	2¼��
              
      if recCount <> 0 then
      begin
        ShowMessage('����ʧ�ܣ�');
        exit;
      end;
      //ShowMessage('������ɣ�');
  except
    ON E: EXCEPTION DO
    begin
      ShowMessage(E.Message);
    end;
  end;
end;

procedure TFrmMain.BtnYuanCHFClick(Sender: TObject);
var
  FileName: string;
  FileOffset, RES: longword;

begin
  if m_lstSearch.Selected = nil then exit;
  if  CMSV6OCX_Request.CheckOnline(trim(editDeviceID.Text))<>0 then
  begin
      showmessage('��Ƶ�㲥�豸������!');
      exit;
  end;
  FileName := m_lstSearch.Selected.SubItems[5];
  FileOffset := StrToInt64Def(m_lstSearch.Selected.SubItems[4], 0);
  RES :=CMSV6OCX_Request.StartPlaybackRec(
     FileName, StrToDateTime(m_lstSearch.Selected.SubItems[8]),
     StrToDateTime(m_lstSearch.Selected.SubItems[9]),m_lstSearch.Selected.SubItems[2], //BSTR strFile, DATE nFileStartTime, DATE nFileEndTime, BSTR strDevIDNO,
     StrToInt(m_lstSearch.Selected.SubItems[3]),StrToInt(m_lstSearch.Selected.SubItems[7]),
     StrToInt(m_lstSearch.Selected.SubItems[12]),  
     StrToInt(m_lstSearch.Selected.SubItems[11]), //nChannel: Integer; nFileLen: Integer; nFileType: Integer;  //nLocation: Integer;
     StrToInt(m_lstSearch.Selected.SubItems[10]),0,0,false);
 {StartPlaybackRec(BSTR strFile, DATE nFileStartTime, DATE nFileEndTime, BSTR strDevIDNO,
                    long nChannel, long nFileLen, long nFileType, long nLocation,
                    long nSvrID, DATE nPlayStartTime, DATE nPlayEndTime, boolean bPlayOnlyIFrame)
������BSTR strFile-�ļ�·��
DATE nFileStartTime-�ļ���ʼʱ��(COleDateTime::m_dt)
DATE nFileEndTime-�ļ�����ʱ��(COleDateTime::m_dt)
BSTR strDevIDNO-�豸IDNO
long nChannel-¼��ͨ����
long nFileLen-�ļ�����
long nFileType�ļ�����
#define GPS_FILE_ATTRIBUTE_JPEG		1//ͼƬ
#define GPS_FILE_ATTRIBUTE_RECORD	2//¼��
long nLocation-�ļ��洢λ��
#define GPS_FILE_LOCATION_DEVICE			1	//�豸
#define GPS_FILE_LOCATION_STOSVR			2	//�洢������
//�ͻ���3������������������������ظ���3�Ȳ���
#define GPS_FILE_LOCATION_DOWNSVR			4		//���ط�����¼������
long nSvrID-������ID
DATE nPlayStartTime-��ʼ����ʱ��(COleDateTime::m_dt)
DATE nPlayEndTime-��������ʱ��(COleDateTime::m_dt)
boolean bPlayOnlyIFrame-�Ƿ�ֻ����I֡
}
end;

procedure TFrmMain.mnuDownLoadClick(Sender: TObject);
var
  iRes: Integer;

  ListItem: TListItem;
  Nian,Yue,Ri,Shi,Fen,Miao,HaoM:Word;
  strTmp:string;
  newGpsFile :PGpsFile;
  startDateTime,endDateTime:TDateTime;
  StrDownFileName:string;
begin
  ProgressBar1.Visible := false;
  if m_lstSearch.Items.Count = 0 then Exit;

  ListItem := m_lstSearch.Selected;
  if ListItem = nil then Exit;
     {BSTR MakeRecNameEx(LPCTSTR szPlate, LPCTSTR szAlarmString, DATE BegDate
      , DATE EndDate, LONG nChn, LONG nRecType, LONG nFileFormat);
      ������szPlate�����ƺ�(ʾ��=a1)  //
      szAlarmString����������(ʾ��=alarm)  ///����  ����  ����
      BegDate����ʼʱ��(ʾ��=2018-06-25 00:00:00)
      EndDate������ʱ��(ʾ��=2018-06-25 23:00:00)
      nChn��ͨ����(ʾ��=1)
      nRecType��¼�����Ͳο�:¼�����Ͷ���ͨ����(ʾ��=1)     IntToStr(cmbWJLX.ItemIndex+1)
      nFileFormat���ο����ļ���ʽ����ͨ����(ʾ��=0)
      ����ֵ�����֮����ļ���,ʾ������a1_alarm-180625-000000-230000-20020200.grec
      ��ע��}
  try ///  IntToStr(cmbWJLX.ItemIndex+1)
     { StrDownFileName := CMSV6OCX_Request.MakeRecNameEx(trim(cmbCPHM.Text),ListItem.SubItems[1],
                         StrToDateTime(ListItem.SubItems[8]),StrToDateTime(ListItem.SubItems[9]),
                         StrToInt(ListItem.SubItems[3]),StrToInt(ListItem.SubItems[1]),) }
      iRes := CMSV6OCX_Request.StartDownFileEx(ListItem.SubItems[5],    // // ¼���ļ�·��
                             StrToDateTime(ListItem.SubItems[8]),StrToDateTime(ListItem.SubItems[9]),
                             ListItem.SubItems[2],///�豸IDNO  BSTR strDevIDNO,
                             StrToInt(ListItem.SubItems[3]),StrToInt(ListItem.SubItems[7]), ///�豸ͨ���� long nChannel, //long nFileLen, �ļ�����
                             StrToInt(ListItem.SubItems[12]),StrToInt(ListItem.SubItems[11]), //�ļ����� 0 //����¼�� 1 //����¼�� ������λ�� 1-�豸 2-�洢������ 3-���� 4-���ط�����
                             StrToInt(ListItem.SubItems[10]),StrToDateTime(ListItem.SubItems[8]),
                             StrToDateTime(ListItem.SubItems[9]),
                             FALSE,ExtractFilePath(Application.ExeName)+'DownloadFile\'+ListItem.SubItems[5]+'.mp4',FALSE);
 
    if iRes = 0 then
        ShowMessage('��ʼ���أ�')
    else
        ShowMessage('����ʧ�ܣ�');
  except
    on e: Exception do ShowMessage(e.Message);
  end;
end;

procedure TFrmMain.SetCmsv;
begin 
  CMSV_1.ServerIP   := FServerIP;
  CMSV_1.ServerPort := FPort;
  CMSV_2.ServerIP   := FServerIP;
  CMSV_3.ServerPort := FPort;
  CMSV_3.ServerIP   := FServerIP;
  CMSV_3.ServerPort := FPort;
  CMSV_4.ServerIP   := FServerIP;
  CMSV_4.ServerPort := FPort; 

 
  CMSV_1.Layout := 1;
  CMSV_1.AutoCloseVideoTime := FCloseTime;
  CMSV_2.Layout := 1;
  CMSV_2.AutoCloseVideoTime := FCloseTime;
  CMSV_3.Layout := 1;
  CMSV_3.AutoCloseVideoTime := FCloseTime;
  CMSV_4.Layout := 1;
  CMSV_4.AutoCloseVideoTime := FCloseTime;
 
  CMSV_1.CaptureSavePath  := FCutPicFilePath;
  CMSV_2.CaptureSavePath  := FCutPicFilePath;
  CMSV_3.CaptureSavePath  := FCutPicFilePath;
  CMSV_4.CaptureSavePath  := FCutPicFilePath; 
end;


procedure TFrmMain.PageControl1Change(Sender: TObject);
begin
  if  pageControl1.ActivePageIndex = 0 then
  begin
      cmbTongD.Enabled := True;
  end;
  if  pageControl1.ActivePageIndex = 1 then
  begin
      if CMSV6OCX_Request.Layout<>1 then
          CMSV6OCX_Request.Layout:=1;
 
  end;
end;

procedure TFrmMain.BtnStopRecSearchClick(Sender: TObject);
begin
  try
      CMSV6OCX_Request.StopRecSearch;
  except

  end;
end;

procedure TFrmMain.FormCreate(Sender: TObject);
begin
  ACarManage:=TCarManage.Create; 
  strPathDir := ExtractFilePath(Application.ExeName) + 'DownloadFile';
  if not DirectoryExists(strPathDir) then
      CreateDir(strPathDir);
  DT1.Date :=date;
  DT2.Date := date;
  tm2.Time := time;
end;

procedure TFrmMain.N3Click(Sender: TObject);
begin
  if CMSV6OCX_Request.StopDownFileEx()=0 then
  begin
      ShowMessage('�Ѿ�ֹͣ��');
  end
  else
  begin
      ShowMessage('ֹͣʧ�ܣ�');
  end
end;

procedure TFrmMain.CMSV6OCX_RequestRecSearchEventEx(ASender: TObject;
  const strFile: WideString; nStartTime, nEndTime: TDateTime; nFileLen,
  nFileType, nSvrID, nLocation, nChannel, bStream, bRecording, nFileOffset,
  nChnMask, nAlarmInfo: Integer);
var
  newGpsFile :PGpsFile;
  node : TListItem;
  iLstCnt:Integer;
  strRQ1,strRQ2,strRQ,strLX:string;
begin
  try
      iLstCnt := m_lstSearch.Items.Count;
      with m_lstSearch.Items.Add do
      begin 
          caption :=  copy(DateTimeToStr(nStartTime),12,8);      //��ʼʱ��
          SubItems.Add(copy(DateTimeToStr(nEndTime),12,8));   //0 ����ʱ��

          if  nFileType=0  then
              SubItems.Add('����')   //����
          else if  nFileType=1  then
              SubItems.Add('����')     //1����
          else if   nFileType=	-1  then
              SubItems.Add('ȫ��');    //1����

          SubItems.Add(FDeviceID);     //2   �豸��

          SubItems.Add(IntToStr(nChannel));   //3 ͨ��

          if  nLocation=1  then
              SubItems.Add('�豸')           //4λ��
          else if  nLocation=2  then
              SubItems.Add('�洢������')      //4 λ��
          else if  nLocation=	3  then
              SubItems.Add('����')            //4 λ��
          else if  nLocation=	4  then
              SubItems.Add('���ط�����'); // 4 λ��
          //
          SubItems.Add(strFile);          ///�ļ�
          SubItems.Add(FormatFloat('0.000',nFileLen/(1024*1024))+'MB');  //��С(MB)
          SubItems.Add(IntToStr(nFileLen)); //��С(B)

          SubItems.Add(DateTimeToStr(nStartTime)); //��ʼ����
          SubItems.Add(DateTimeToStr(nEndTime));   //��������

          SubItems.Add(IntToStr(nSvrID));
   
          SubItems.Add(IntToStr(nLocation)); //�ļ�λ��ID
          SubItems.Add(IntToStr(nFileType)); //¼������ID
          SubItems.Add(IntToStr(cmbWJLX.ItemIndex+1)); //¼����������
          SubItems.Add(strPathDir);
          //SubItems.Add(strPathDir+'\'+copy(trim(strFile),2,250)+'.grec');
      end;
  finally 
  end;
end;

procedure TFrmMain.CMSV6OCX_RequestDownFileExEvent(ASender: TObject; nMsg,
  nParam: Integer);
begin
  case nMsg  of
      1:	//����ʧ��
      begin
          LabTip.Caption := '����ʧ��';
          ProgressBar1.Position := 0;
      end;

      2:	//�����ٶȣ���λKB/S //nParam Ϊ�����ٶ�
      begin
          //LabTip2.Caption := '�������'+IntToStr(nParam)+' (KB/s)';
          //ProgressBar1.Position := nParam;
      end;

      3:	//�������
      begin
          LabTip.Caption := '�������';
          ProgressBar1.Position := 100;
          sleep(1500);
          ProgressBar1.Visible := false;
      end;

      4:	//���ؽ���  //nParam Ϊ���ؽ���(0-100)
      begin
          LabTip.Caption := '���ؽ���'+IntToStr(nParam)+'%';
          ProgressBar1.Position := nParam;
      end;
	end;
end;

procedure TFrmMain.mnuDownLoadByTimeClick(Sender: TObject);
var
  dlg: TFrmDownLoadByTime; 
  ListItem: TListItem;
  iRes:Integer;
begin 
  if m_lstSearch.Items.Count = 0 then Exit;

  ListItem := m_lstSearch.Selected;
  if ListItem = nil then Exit;

  dlg := TFrmDownLoadByTime.Create(Self);
  try
    try
        dlg.StrInitBegDate := ListItem.SubItems[8];
        dlg.StrInitEndDate := ListItem.SubItems[9];
        dlg.ShowModal;
        if  dlg.ModalResult <> mrOk  then   Exit;      
        iRes := CMSV6OCX_Request.StartDownFileEx(ListItem.SubItems[5],    // // ¼���ļ�·��
                               StrToDateTime(ListItem.SubItems[8]),StrToDateTime(ListItem.SubItems[9]),
                               ListItem.SubItems[2],///�豸IDNO  BSTR strDevIDNO,
                               StrToInt(ListItem.SubItems[3]),StrToInt(ListItem.SubItems[7]), ///�豸ͨ���� long nChannel, //long nFileLen, �ļ�����
                               StrToInt(ListItem.SubItems[12]),StrToInt(ListItem.SubItems[11]), //�ļ����� 0 //����¼�� 1 //����¼�� ������λ�� 1-�豸 2-�洢������ 3-���� 4-���ط�����
                               StrToInt(ListItem.SubItems[10]),StrToDateTime(dlg.StrOKTimeBeg),
                               StrToDateTime(dlg.StrOKTimeEnd),
                               true,ExtractFilePath(Application.ExeName)+'DownloadFile\'+ListItem.SubItems[5]+'.mp4',FALSE);

        
        if iRes = 0 then
            ShowMessage('��ʼ���أ�')
        else
            ShowMessage('����ʧ�ܣ�');
    except
        on e:Exception do
            ShowMessage('ѡ��ʱ���ʧ�ܣ�'+E.Message);
    end;
  finally
    dlg.Free;
  end;
end;

end.
