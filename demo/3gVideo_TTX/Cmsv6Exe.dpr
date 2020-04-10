program Cmsv6Exe;

uses
  Forms,
  SysUtils,
  Controls,
  Windows,
  MainVideo in 'MainVideo.pas' {FrmMain},
  ParamDlgFrmUnit in 'ParamDlgFrmUnit.pas' {ParamDlgFrm},
  selectDirPathUnit in 'selectDirPathUnit.pas' {selectDirPathFrm},
  TcpThreadUnit in 'TcpThreadUnit.pas',
  EventLogUnit in 'EventLogUnit.pas',
  SystemLog in 'SystemLog.pas',
  ClientThreadUnit in 'ClientThreadUnit.pas',
  ZipLibUnit in 'ZipLibUnit.pas',
  base64 in 'base64.pas',
  CarUnit in 'CarUnit.pas',
  IntegerListUnit in 'IntegerListUnit.pas',
  UDownLoadByTime in 'UDownLoadByTime.pas' {FrmDownLoadByTime};

{$R *.res}

var
  hAppMutex: THandle;
  sMutexName: string;
begin
  Application.Initialize;
  sMutexName := StringReplace(ExtractFilePath(Application.ExeName) + 'RoomManage', '\', #29, [rfReplaceAll]);
  hAppMutex := CreateMutex(nil, false, PChar(sMutexName));
  if hAppMutex = 0 then
  begin
    Application.MessageBox('�����������ʧ�ܣ������쳣��ֹ��', '��ʾ', MB_OK +
      MB_ICONINFORMATION);
    Exit;
  end;
  if ((hAppMutex <> 0) and (GetLastError = ERROR_ALREADY_EXISTS)) then
  begin
    Application.MessageBox(PAnsiChar('����������һ��' + ExtractFileName(Application.ExeName)
      + 'ʵ����'), '��ʾ', MB_OK + MB_ICONINFORMATION);
    CloseHandle(hAppMutex);
    //ShowWindow(Application.Handle, SW_SHOWNORMAL);
    Exit;
  end;

  Application.Title := '�Ͼ�ͨ�õ���-4G��Ƶ';
  Application.CreateForm(TFrmMain, FrmMain);
  Application.Run;
end.
