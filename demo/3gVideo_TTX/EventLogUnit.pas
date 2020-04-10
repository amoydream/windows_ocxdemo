{��¼NetServer��������־���.
@author(���鲨)
@created(2001-12-4)
@lastmod(2003-9-5)}
unit EventLogUnit;

interface
uses
  SystemLog;
const
  LOGDIR = 'c:\logs';

type
  TLogType=(ltErr,ltEvent);
  TOnWritelog=procedure (ALogType:TLogType;ALogMsg:string) of object;
  {��־������һ��ָ�����ļ����У�
  ��·��������ע����С���־�ļ������֣�
  <li>������־
  <li>�¼���־
  ��־���ļ�����������ϵ��ַ���Ϊ��׺��ÿ��������ļ�}
  TNetServerLog=class
  private
    FCurrentPostfix:string;
    ErrLog:TSystemLog;
    EventLog:TSystemLog;
    {�Ƿ��ʼ���ɹ�}
    FInit:boolean;
    FOnWritelog: TOnWritelog;
    {������ڵĺ�׺�ַ�������ʽΪ20021204}
    function GetDatePostfix:string;
    procedure SetOnWritelog(const Value: TOnWritelog);
    procedure CreateLogObject(APostfix:string);
  public
    constructor Create;
    destructor Destroy;override;
    {д������־
    @param AErrMsg:string Ҫ��¼�Ĵ�����Ϣ
    @ver(���鲨,2002-12-4,
    ����޸�:NULL,2002-12-4)}
    procedure WriteErrlog(AErrMsg:string);
    {д�¼���־
    @parem AEventMsg:string �¼���Ϣ
    @ver(���鲨,2002-12-4,
    ����޸�:NULL,2002-12-4)}
    procedure WriteEventlog(AEventMsg:string);
    property OnWritelog:TOnWritelog read FOnWritelog write SetOnWritelog;
  end;

  function NetServerLog():TNetServerLog;
implementation
uses
  Sysutils,
  FileCtrl;
var
  FNetserverLog:TNetServerLog;
{ NetServerLog }

constructor TNetServerLog.Create;
begin

  if not DirectoryExists(LOGDIR) then
    if not CreateDir(LOGDIR) then
    begin
      FInit:=False;
      Exit;
    end;

  FCurrentPostfix:=GetDatePostfix;
  CreateLogObject(FCurrentPostfix);
  FInit:=True;
end;

procedure TNetServerLog.CreateLogObject(APostfix: string);
begin
  ErrLog.Free;
  ErrLog:=TSystemLog.Create;
  ErrLog.WriteImmediate:=False;
  ErrLog.LogFile:=LOGDIR+'\Err'+APostfix+'.log';

  EventLog.Free;
  EventLog:=TSystemLog.Create;
  EventLog.WriteImmediate:=False;

  EventLog.LogFile:=LOGDIR+'\Event'+APostfix+'.log';
end;

destructor TNetServerLog.Destroy;
begin
  ErrLog.Free;
  EventLog.Free;
  inherited;
end;

function TNetServerLog.GetDatePostfix: string;
begin
  Result:=FormatDateTime('yyyymmdd',now);
end;

procedure TNetServerLog.SetOnWritelog(const Value: TOnWritelog);
begin
  FOnWritelog := Value;
end;

procedure TNetServerLog.WriteErrlog(AErrMsg: string);
begin
  AErrMsg:=FormatDateTime('yyyy-mm-dd hh:mm:ss',Now)+' '+AErrMsg;
  if Assigned(FOnWritelog) then FOnWritelog(ltErr,AErrMsg);

  if not FInit then
  begin
    if Assigned(FOnWritelog) then FOnWritelog(ltErr,'δָ����־Ŀ¼��');
    Exit;
  end;

  if GetDatePostfix<>FCurrentPostfix then
  begin
    FCurrentPostfix:=GetDatePostfix;
    CreateLogObject(FCurrentPostfix);
  end;
  ErrLog.AddLog(AErrMsg);
end;

procedure TNetServerLog.WriteEventlog(AEventMsg: string);
begin
  AEventMsg:=FormatDateTime('yyyy-mm-dd hh:mm:ss',Now)+' '+AEventMsg;
  if Assigned(FOnWritelog) then FOnWritelog(ltEvent,AEventMsg);
  if not FInit then
  begin
    if Assigned(FOnWritelog) then FOnWritelog(ltEvent,'δָ����־Ŀ¼��');
    Exit;
  end;
  if GetDatePostfix<>FCurrentPostfix then
  begin
    FCurrentPostfix:=GetDatePostfix;
    CreateLogObject(FCurrentPostfix);
  end;
  EventLog.AddLog(AEventMsg);
end;


function NetServerLog():TNetServerLog;
begin
  if FNetserverLog=nil then
    FNetserverLog:=TNetserverLog.Create;
  Result:=FNetserverLog;  
end;

initialization
  FNetserverLog:=nil;


finalization
  FNetserverLog.Free;
end.
