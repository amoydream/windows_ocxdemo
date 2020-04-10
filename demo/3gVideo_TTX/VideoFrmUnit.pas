unit VideoFrmUnit;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, OleCtrls, ShellAPI, MyCommAgentCTL_TLB, Menus, ScktComp,
  TcpThreadUnit, ClientThreadUnit, ComCtrls, XPMan, Buttons, ActnList,
  ExtActns, ExtCtrls, IdHashMessageDigest, IdBaseComponent, IdComponent,
  IdTCPConnection, IdTCPClient, IdHTTP, wpCTIOcx_TLB, PPVSGUARDLib_TLB, DB,
  DBClient, TLMDVRAXLib_TLB, ImgList;

const
  VERSION = '(20130604.0900)';

  MY_APP_NAME           = '3G_VIDEO';
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
  

type
  TMD5 = class(TIdHashMessageDigest5);

  TVideoMainFrm = class(TForm)
    PopupMenu1: TPopupMenu;
    N1: TMenuItem;
    N2: TMenuItem;
    StatusBar1: TStatusBar;
    XPManifest1: TXPManifest;
    Timer1: TTimer;
    Timer2: TTimer;
    FTemp: TClientDataSet;
    Panel2: TPanel;
    Label1: TLabel;
    lblState: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    ComboBox1: TComboBox;
    editDeviceID: TEdit;
    Label2: TLabel;
    ComboBox2: TComboBox;
    btncut: TSpeedButton;
    btnsound: TSpeedButton;
    btnLogin: TSpeedButton;
    btnplay: TSpeedButton;
    btnstop: TSpeedButton;
    btnLogout: TSpeedButton;
    btnReload: TSpeedButton;
    SpeedButton1: TSpeedButton;
    PageControl1: TPageControl;
    TabSheet1: TTabSheet;
    TabSheet2: TTabSheet;
    Panel1: TPanel;
    Panel3: TPanel;
    Panel4: TPanel;
    Label3: TLabel;
    DateTimePicker1: TDateTimePicker;
    DateTimePicker2: TDateTimePicker;
    Label6: TLabel;
    DateTimePicker3: TDateTimePicker;
    DateTimePicker4: TDateTimePicker;
    BitBtn1: TBitBtn;
    VideoListView: TListView;
    BitBtn2: TBitBtn;
    BitBtn3: TBitBtn;
    BitBtn4: TBitBtn;
    TLMDVRAx1: TTLMDVRAx;
    Button1: TButton;
    Video3G: TTLMDVRAx;
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure MSPevtQueueChanged(Sender: TObject);
    procedure N1Click(Sender: TObject);
    procedure N2Click(Sender: TObject);
    procedure FormCloseQuery(Sender: TObject; var CanClose: Boolean);
    procedure Timer1Timer(Sender: TObject);
    procedure Timer2Timer(Sender: TObject);
    procedure editDeviceIDChange(Sender: TObject);
    procedure ComboBox1KeyPress(Sender: TObject; var Key: Char);
    procedure BitBtn7Click(Sender: TObject);
    procedure ComboBox1Change(Sender: TObject);
    procedure ComboBox2Change(Sender: TObject);
    procedure btncutClick(Sender: TObject);
    procedure btnsoundClick(Sender: TObject);
    procedure btnLoginClick(Sender: TObject);
    procedure btnplayClick(Sender: TObject);
    procedure btnstopClick(Sender: TObject);
    procedure btnLogoutClick(Sender: TObject);
    procedure SpeedButton1Click(Sender: TObject);
    procedure BitBtn1Click(Sender: TObject);
    procedure BitBtn2Click(Sender: TObject);
    procedure BitBtn3Click(Sender: TObject);
    procedure BitBtn4Click(Sender: TObject);
    procedure VideoListViewCustomDrawItem(Sender: TCustomListView;
      Item: TListItem; State: TCustomDrawState; var DefaultDraw: Boolean);
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
    FNid: NOTIFYICONDATA;


    FChannelID: Integer;    // �豸ͨ����(��1��ʼ)
    FDeviceID: String;      // �豸���к�



    procedure addVideoRecordInfoToList(info: string);

    function GetFormNameAt(const Pos: TPoint): string;

    function AddIcon(hwnd: HWND): Boolean; //��״̬�����ͼ��
    function RemoveIcon(hwnd: HWND): Boolean; //��״̬����ȥͼ��
    function ModifyIcon(hwnd: HWND; Title: String): Boolean; // ����������ʾ��Ϣ
    procedure minimize(sender: Tobject); //������С�����̣�����Application.OnMinimize;
    procedure Notify(var Msg: TMessage); message WM_MAINNOTIFY; //�Զ�����Ϣ������
    procedure CreateParams(var Params: TCreateParams);override;

    // ���ռ�ض˷��͹�������Ϣ
    // ��Ϣ�ַ�����ɸ�ʽ �Լ�ֵ�Ե���ʽ���м���"|"������  KEY1=VALUE1|KEY2=VALUE2
    // ����(FLAG)=VALUE|��ˮ��(CMDID)=VALUE|����
    procedure WMCopyData(var Message: TWMCopyData); message WM_COPYDATA;
    // ���ؼ�ض���Ϣ
    // ��Ϣ�ַ�����ɸ�ʽ �Լ�ֵ�Ե���ʽ���м���"|"������  KEY1=VALUE1|KEY2=VALUE2
    // ����(FLAG)=VALUE|��ˮ��(CMDID)=VALUE|����
    procedure SendCopyData(Msg: string);

    // ���س�����Ϣ
    procedure LoadCarInfo;
    Function GetDllPath:string;

    function LoginServer: boolean;
    function Logout: boolean;
    function PlayVideo: boolean;
    function StopVideo: boolean;
  public
    { Public declarations }
    FServerIP: String;      // ע����Ƶ������
    FPort: Integer;         // ע����Ƶ�������˿ں�
    FUserName: String;      // ע��������û���
    FPassWord: String;      // ע�����������

    FStreamServerIP: String;  // ��ý�������IP
    FStreamPort: Integer;     // ��ý��������˿ں�
    FStreamType: Integer;		  // �������� (0-������; 1-������)
    FStreamMode: Integer;     // ��ý�����������ǰ����Ƶ��ģʽ 0:UDP;1:TCP
    FCutPicFilePath: string;  // ��Ƶ��ͼ·��
    procedure InitParam;
    procedure Set3GConfig(IP: string; PORT: Integer; USER: string; Password: string; CutPicFilePath: string);
  end;

var
  VideoMainFrm: TVideoMainFrm;

implementation
uses IniFiles, DateUtils, ZipLibUnit, ParamDlgFrmUnit;
{$R *.dfm}

{ TLXZC_CallCenterFrm }

Function TVideoMainFrm.GetDllPath:string;
var
  ModuleName:string;
  FilePath: string;
  index: integer;
begin
  SetLength(ModuleName, 255);  //ȡ��Dll����·��
  GetModuleFileName(HInstance, PChar(ModuleName), Length(ModuleName));
  FilePath := ExtractFilePath(ModuleName);
  result := FilePath;
end;

procedure TVideoMainFrm.WMCopyData(var Message: TWMCopyData);
var
  Msg: string;
begin
  try
    Msg := PChar(Message.CopyDataStruct.lpData);
  except
  end;
end;

procedure TVideoMainFrm.FormClose(Sender: TObject;
  var Action: TCloseAction);
begin
  try
    Logout;

    RemoveIcon(handle);
  except
  end;
end;

procedure TVideoMainFrm.MSPevtQueueChanged(
  Sender: TObject);
begin
  // �绰�Ŷ�
    
end;

procedure TVideoMainFrm.SendCopyData(Msg: string);
var
  h: HWND;
  Size: Integer;
  CopyDataStruct: TCopyDataStruct;
begin
  h := FindWindow(nil, '���ָ��-3G��Ƶ');           { ���������Ŀ�괰�� }
  if h > 0 then
  begin
    Size := Length(Msg) + 2;                                  { ����������ֽ����ں���� #0 }
    CopyDataStruct.lpData := PChar(Msg + #10);                { Ҫ���͵��ַ���, #0 ��ʾ PChar ����}
    CopyDataStruct.dwData := WM_COPYDATA;                     { ָ����Ϣ���� }
    CopyDataStruct.cbData := Size;                            { ָ��Ҫ���͵����ݵĴ�С }
    SendMessage(h, WM_COPYDATA, 0, Integer(@CopyDataStruct)); { ���� }
  end;
end;

procedure TVideoMainFrm.minimize(sender: Tobject);
begin
  ShowWindow(Handle, SW_HIDE);
end;

function TVideoMainFrm.AddIcon(hwnd: HWND): Boolean;
begin
  FNid.cbSize := sizeof(NOTIFYICONDATA);
  FNid.Wnd := hwnd;
  FNid.uID := ID_MAIN;
  FNid.uFlags := NIF_MESSAGE or NIF_ICON or NIF_TIP;
  FNid.uCallbackMessage := WM_MAINNOTIFY;
  FNid.hIcon := LoadIcon(HInstance, 'MAINICON');
  strCopy(FNid.szTip, '�Ͼ�ͨ��-3G��Ƶ');
  AddIcon := Shell_NotifyIcon(NIM_ADD, @FNid);      
end;

function TVideoMainFrm.RemoveIcon(hwnd: HWND): Boolean;
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

function TVideoMainFrm.ModifyIcon(hwnd: HWND; Title: String): Boolean;
begin
  try
//    FNid.cbSize := sizeof(NOTIFYICONDATA);
//    FNid.Wnd := hwnd;
//    FNid.uID := ID_MAIN;
//    FNid.uFlags := NIF_MESSAGE or NIF_ICON or NIF_TIP;
//    FNid.uCallbackMessage := WM_MAINNOTIFY;
//    FNid.hIcon := LoadIcon(hInstance, 'MAINICON');
//    strCopy(FNid.szTip, Pchar(Title));
//    ModifyIcon := Shell_NotifyIcon(NIM_ADD, @FNid);
  except
  end;
end;

procedure TVideoMainFrm.CreateParams(var Params: TCreateParams);
begin
  inherited CreateParams(Params);
  Params.WinClassName := MY_APP_NAME;
end;

procedure TVideoMainFrm.Notify(var Msg: TMessage);
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

procedure TVideoMainFrm.N1Click(Sender: TObject);
begin
  //RemoveIcon(handle);
  ShowWindow(Self.Handle, SW_SHOWNORMAL);
end;

procedure TVideoMainFrm.N2Click(Sender: TObject);
begin
  CLOSE;
end;


procedure TVideoMainFrm.FormCloseQuery(Sender: TObject;
  var CanClose: Boolean);
begin
  if messagebox(handle, '��ȷ��Ҫ�˳�3G��Ƶ��������', '�˳�ѡ��', MB_OKCANCEL + MB_ICONQUESTION) = ID_CANCEL then
    CanClose := false;
end;

procedure TVideoMainFrm.Timer1Timer(Sender: TObject);
var
  winPos: TPoint;
  t: integer;
  b: boolean;
begin
  try
    b:= false;
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
      //�õ���ǰ���ָ�������Ļ�ϵ�����
      GetCursorPos(winPos);
      //�����ָ���µĴ����Name����frmMain.nameʱ
      if self.Name = GetFormNameAt(winPos) then
      {�ڴ����ǿ���ΪfrmMainȡһ���ر�����ƣ��Է��б�Ĵ�������������ͬ}
      begin
        //ͣ��Timer2
        timer2.Enabled:= false;
        //frmMain��Top����Ļ����
        self.Top:= t;
        if t <> 0 then
          self.Left:= Screen.Width - self.Width;
      end
      else begin
        Timer2.Enabled:= true;
      end;
    end;
  except
  end;
end;

procedure TVideoMainFrm.Timer2Timer(Sender: TObject);
begin
  try
    // �� top ����Ļ�ϲ� 20 ����ʱ,�Զ�����
    if self.Top <= 20 then
    begin
      //��frmMain�����ƣ�����Ļ�Ϸ�¶��3����
      self.Top:= -(self.Height - 3);
      if (self.Left + self.Width > Screen.Width) then
        self.Left:= Screen.Width - self.Width;
    end
    // �� left ����Ļ�²� 20 ����ʱ,�Զ�����
    else if self.Left + self.Width - Screen.Width >= -20 then
      //��frmMain�����ƣ�����Ļ�ҷ�¶��4����
      self.Left:= Screen.Width - 4;
  except
  end;
end;

function TVideoMainFrm.GetFormNameAt(const Pos: TPoint): string;
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

procedure TVideoMainFrm.LoadCarInfo;
var
  Info, ZIP: string;
  fs: TFileStream;
  FileName: string;
  I, fileLen: Integer;
  ft: TextFile;
begin
  try
    FileName := ExtractFilePath(Application.ExeName) + 'DBINFO\CARINFO';
    if not FileExists(FileName) then
    begin
      MessageBox(Handle, 'û�г����������ݣ����ȵ�½��ؿͻ��ˣ�', '��ʾ', MB_OK + MB_ICONWARNING);
      exit;
    end;

    fs := TFileStream.Create(FileName,fmOpenRead);
    try
      //fileLen := fs.Seek(0,2);
      //fs.Seek(0,0);
      SetLength(ZIP, fs.size);
      fs.Read(ZIP[1],fs.size);
    finally
      fs.Free;
    end;


//      try
//        // ��ȡ�ļ��е�����
//        AssignFile(ft, FileName);
//        Reset(ft);
//        repeat Readln(ft,info);
//          zip := zip + Trim(info);
//        until eof(ft) = true;
//      finally
//        CloseFile(ft);
//      end;

    Info := DeCompress(ZIP);
    FTemp.XMLData := info;
    FTemp.Open;
    ComboBox1.Clear;
    FTemp.First;
    while not FTemp.Eof do
    begin
      ComboBox1.Items.Add(FTemp.FieldByName('CAR_NO').AsString);
      FTemp.Next;
    end;
  except
  end;      
end;

procedure TVideoMainFrm.editDeviceIDChange(Sender: TObject);
begin
  FDeviceID := Trim(editDeviceID.Text);
end;

procedure TVideoMainFrm.ComboBox1KeyPress(Sender: TObject; var Key: Char);
begin
  if (Key = #13) then
  begin
    editDeviceID.Text := ComboBox1.Text;
    exit;
  end;
end;

procedure TVideoMainFrm.BitBtn7Click(Sender: TObject);
begin
  LoadCarInfo;
end;

procedure TVideoMainFrm.ComboBox1Change(Sender: TObject);
begin
  editDeviceID.Text := ComboBox1.Text;
end;

procedure TVideoMainFrm.ComboBox2Change(Sender: TObject);
begin
  FChannelID := ComboBox2.ItemIndex;
end;

procedure TVideoMainFrm.btncutClick(Sender: TObject);
var
  FileName: string;
begin
  try
    FileName := FDeviceID + '_' + FormatDateTime('YYYYMMDDHHNNSSSSS', now)+'.JPG';
    Video3G.SnapPicture(FCutPicFilePath +  '\' + FileName);
    messagebox(handle, '��Ƶ��ͼ��ɣ�', '��ʾ', mb_ok + MB_ICONWARNING);
  except
  end;
end;

procedure TVideoMainFrm.btnsoundClick(Sender: TObject);
begin
  if Video3G.PlayAudio < 0 then
  begin
    messagebox(handle, '����Ƶ����ʧ�ܣ�', '��ʾ', mb_ok + MB_ICONWARNING);
  end;
end;

procedure TVideoMainFrm.InitParam;
var
  IniFile: TIniFile;
  FilePath: string;
  Index: integer;
  image: TIcon;
begin
  try
    FChannelID := 0;


    FilePath := GetDllPath;
    //FilePath := StringReplace(FilePath, 'Video_3G.dll', '', [rfReplaceAll]);
    IniFile := TIniFile.Create(FilePath + 'CMSV_4G.ini');

    try
      FServerIP := IniFile.ReadString('ini', 'IP', '');      // 218.2.75.219

      FPort := IniFile.ReadInteger('ini', 'PORT', 0);        // 10000

      FUserName := IniFile.ReadString('ini', 'USERNAME', '');   // user
      FPassWord := IniFile.ReadString('ini', 'PASSWORD', '');   // jycz

      FStreamServerIP := IniFile.ReadString('ini', 'STREAMIP', '');
      FStreamPort := IniFile.ReadInteger('ini', 'STREAMPORT', 7554);

      FStreamType:= IniFile.ReadInteger('ini', 'STREAMTYPE', 0);
      FStreamMode := IniFile.ReadInteger('ini', 'STREAMMODE', 1);

      FCutPicFilePath := IniFile.ReadString('ini', 'CUTPICFILEPATH', '');

    finally
      IniFile.Free;
    end;

//    FServerIP := '218.94.158.108';
//    FPort := 10000;
//    FUserName := 'user';
//    FPassWord := '123';


    LoadCarInfo;


//    Application.OnMinimize := minimize;
//    AddIcon(Handle);
//    SetWindowLong(HInstance, GWL_EXSTYLE, WS_EX_TOOLWINDOW);

    Self.Caption := Self.Caption + ' ' + VERSION;
    Application.Title := Self.Caption;
  except
    on e: exception do
    begin
      messagebox(handle, pchar('Create:' + e.Message), '��ʾ', mb_ok + MB_ICONWARNING);
    end;
  end;
end;

procedure TVideoMainFrm.btnLoginClick(Sender: TObject);
begin
  if LoginServer then
  begin
    lblState.Caption := '������Ƶ�ն˷���ɹ�';
  end else
  begin
    lblState.Caption := '������Ƶ�ն˷���ʧ��';
  end;
end;

procedure TVideoMainFrm.btnplayClick(Sender: TObject);
begin         
  if PlayVideo then
  begin
    lblState.Caption := '����Ƶ���ųɹ�';
  end else
  begin
    lblState.Caption := '����Ƶ����ʧ��';
  end;
end;

procedure TVideoMainFrm.btnstopClick(Sender: TObject);
begin
  try
    StopVideo;
    lblState.Caption := '�ر���Ƶ���ųɹ�';
  except
    messagebox(handle, '�ر���Ƶ����ʧ�ܣ�', '��ʾ', mb_ok + MB_ICONWARNING);
  end;
end;

procedure TVideoMainFrm.btnLogoutClick(Sender: TObject);
begin
  try
    Logout;
    lblState.Caption := '�Ͽ���Ƶ�ն˷���ɹ�';
  except
    messagebox(handle, '�Ͽ���Ƶ�ն˷���ʧ�ܣ�', '��ʾ', mb_ok + MB_ICONWARNING);
  end;
end;

procedure TVideoMainFrm.SpeedButton1Click(Sender: TObject);
var
  dlg: TParamDlgFrm;
  IniFile: TIniFile;
  FilePath: string;
begin
  dlg := TParamDlgFrm.Create(self);
  try
    with dlg do
    begin
      LabeledEditIP.Text := FServerIP;
      LabeledEditPort.Text := IntToStr(FPort); 
      LabeledEditStreamIP.Text := FStreamServerIP;
      LabeledEditStreamPort.Text := IntToStr(FStreamPort);
      cbxStreamType.ItemIndex := FStreamType;
      cbxStreamMode.ItemIndex := FStreamMode;
      LabeledEditCutPicFilePath.Text := FCutPicFilePath;
    end;
    dlg.ShowModal;
    if dlg.ModalResult = mrOk then
    begin
      with dlg do
      begin
        FServerIP := LabeledEditIP.Text;
        FPort := StrToIntDef(LabeledEditPort.Text, 7660); 
        FStreamServerIP := LabeledEditStreamIP.Text;
        FStreamPort := StrToIntDef(LabeledEditStreamPort.Text, 7554);
        FStreamType := cbxStreamType.ItemIndex;
        FStreamMode := cbxStreamMode.ItemIndex;
        FCutPicFilePath := LabeledEditCutPicFilePath.Text;
      end;

      FilePath := GetDllPath; 
      IniFile := TIniFile.Create(FilePath + 'CMSV_4G.ini');
      try
        try
          IniFile.WriteString('ini', 'IP', FServerIP);
          IniFile.WriteString('ini', 'PORT', IntToStr(FPort));
          IniFile.WriteString('ini', 'USERNAME', FUserName);
          IniFile.WriteString('ini', 'PASSWORD', FPassWord);
          IniFile.WriteString('ini', 'STREAMIP', FStreamServerIP);
          IniFile.WriteString('ini', 'STREAMPORT', IntToStr(FStreamPort));
          IniFile.WriteInteger('ini', 'STREAMTYPE', FStreamType);
          IniFile.WriteInteger('ini', 'STREAMMODE', FStreamMode);
          IniFile.WriteString('ini', 'CUTPICFILEPATH', FCutPicFilePath);

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

function TVideoMainFrm.LoginServer: boolean;
begin
  try
    result := Video3G.LoginServer(FServerIP, FPort, FUserName, FPassWord);
  except
    result := false;
  end;
end;

function TVideoMainFrm.Logout: boolean;
begin
  try
    Video3G.Logout;
    result := true;
  except
    result := false;
  end;
end;

function TVideoMainFrm.PlayVideo: boolean;
begin
  try
    result := false;
    if Video3G.PlayVideo(FDeviceID, FChannelID) = 0 then
    begin
      result := true;
    end;
  except
    result := false;
  end;
end;

function TVideoMainFrm.StopVideo: boolean;
begin
  try
    Video3G.StopVideo;
    result := true;
  except
    result := false;
  end;
end;

procedure TVideoMainFrm.BitBtn1Click(Sender: TObject);
var
  dtTemp: TDateTime;
  startDateTime, endDateTime: Tdatetime;
  recCount: Integer;
  i: Integer;
  s: string;
begin
  try
    VideoListView.Clear;
    dtTemp := StrToDateTime('1970-01-01 00:00:00');

    startDateTime := DateTimePicker1.DateTime;
    ReplaceTime(startDateTime, DateTimePicker2.Time);
    
    endDateTime := DateTimePicker3.DateTime;
    ReplaceTime(endDateTime, DateTimePicker4.Time);

    recCount := Video3G.StartRemoteFileSearch(FDeviceID, $0F, $ff, SecondsBetween(dtTemp, startDateTime), SecondsBetween(dtTemp, endDateTime));
    if recCount = 0 then
    begin
      ShowMessage('��������Ƶ��');
    end;
    for i := 0 to recCount - 1 do
    begin
      s := Video3G.GetNextRemoteFileInfo(FDeviceID);
      addVideoRecordInfoToList(s);
    end;
  except
    ON E: EXCEPTION DO
    begin
      //ShowMessage(E.Message);
    end;
  end;
end;

procedure TVideoMainFrm.addVideoRecordInfoToList(info: string);
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
    ExtractStrings([';'], [' '], PChar(strRec), sList);
    //DEVICEID:ԥG62172 CH:2 TYPE:8 STARTTIME:1370068928 ENDTIME:1370069160 IMGFORMAT:3 STREAMFLAG:1
    //FILESIZE:16411798 FILEOFFSET:20918784 FILENAME:rec/b1/fly00009.ifv
    sTemp := sList.Strings[0];
    sDevId := Copy(sTemp, 10, Length(sTemp) - 9);

    sTemp := sList.Strings[1];
    sChannelNo := Copy(sTemp, 4, Length(sTemp) - 3);

    sTemp := sList.Strings[2];
    sRecType := Copy(sTemp, 6, Length(sTemp) - 5);

    dtOrg := StrToDateTime('1970-01-01 00:00:00');
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

    with VideoListView.Items.Add do
    begin
      Caption := sDevId;
      //SubItems.Add(sChannelNo);
      //SubItems.Add(sRecType);
      SubItems.Add(FormatDateTime('yy-MM-dd hh:nn', dtS));
      SubItems.Add(FormatDateTime('yy-MM-dd hh:nn', dtE));
      SubItems.Add(sFileSize);
      SubItems.Add(sFileName);
      SubItems.Add(sFileOffset);

    end;  
  finally
    sList.Free;
  end;
end;

procedure TVideoMainFrm.BitBtn2Click(Sender: TObject);
var
  FileName: string;
  FileOffset, RES: longword;

begin
  if VideoListView.Selected = nil then exit;
  FileName := VideoListView.Selected.SubItems[3];
  FileOffset := StrToInt64Def(VideoListView.Selected.SubItems[4], 0);
  
  RES := TLMDVRAx1.StartRemoteRecFilePlay(FDeviceID, FileName, FileOffset);
//  SHOWMESSAGE(FILENAME + ',' + INTTOSTR(FILEOFFSET) + ',' + INTTOSTR(RES));
end;

procedure TVideoMainFrm.BitBtn3Click(Sender: TObject);
begin
  TLMDVRAx1.LoginServer(FServerIP, FPort, FUserName, FPassWord);
end;

procedure TVideoMainFrm.BitBtn4Click(Sender: TObject);
begin
  TLMDVRAx1.StopRemoteRecPlay;
end;

procedure TVideoMainFrm.VideoListViewCustomDrawItem(
  Sender: TCustomListView; Item: TListItem; State: TCustomDrawState;
  var DefaultDraw: Boolean);
var
  i: integer;
begin
  try
    i:= (Sender as TListView).Items.IndexOf(Item);

    if odd(i) then
      sender.Canvas.Brush.Color:= $eeeeee//$e0dfd8
    else
      sender.Canvas.Brush.Color:= clWhite;//$ffeeee;
  except
  end;
end;

procedure TVideoMainFrm.Button1Click(Sender: TObject);
begin
  InitParam;
end;

procedure TVideoMainFrm.Set3GConfig(IP: string; PORT: Integer; USER,
  Password: string; CutPicFilePath: string);
begin
  try
    FServerIP := IP;      // 218.2.75.219
    FPort := PORT;        // 10000
    FUserName := USER;   // user
    FPassWord := Password;   // jycz
    FCutPicFilePath := CutPicFilePath;
  except
    on e: Exception do
    begin
      ShowMessage(e.Message);
    end;
  end;
end;

end.
