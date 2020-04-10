{�ͻ���Socket�̣߳�
 �̵߳��¼�һ����Ҫ����ʹ��ͬ��������������ɵĴ��������Է��ֵġ�
 @author(���鲨)
 @created(2004-3-16)
 @lastmod(GMT:$Date: 2012/11/26 06:34:56 $) <BR>
 ��������:$Author: ls $  <BR>
 ��ǰ�汾:$Revision: 1.1.1.1 $  <BR>}
unit ClientThreadUnit;

interface

uses
  windows,
  scktcomp,
  
  TcpThreadUnit;

const
  {��������}
  MAX_CMDLEN=1024;

type

  TOnprocessCmd=procedure(Sender:TObject;PCmd:PByte;CmdLen:integer) of object;

  TClientThread=class(TTcpThread)
  private
    {�ͻ������������ͨѶЭ��汾ֵ��
    >0����ͨѶЭ��汾��֤ͨ��
    =0δͨ��}
    FClientCommVerAuth:word;
    {���һ�η�������ʱ��}
    //FLastCmdTimeStamp:longword;
    FOnProcessCmd: TOnprocessCmd;
    FUserID: integer;
    FLogonTime: TDateTime;

    FBuffer:array[0..MAX_CMDLEN-1] of byte;
    FBufferLen:word;

    procedure SetOnProcessCmd(const Value: TOnprocessCmd);
    {����ͨѶ��ʽΪ Ver=$0200�����ݰ�������
    @ver(���鲨,2003-9-16,
    ����޸�:NULL,2003-9-16)}
    procedure ProcessBuff_H0100;
    procedure SetUserID(const Value: integer);
    procedure SetLogonTime(const Value: TDateTime);
    procedure SynchrOnDoCmd;

    {��������͵������
     ����������в����������Ӧ��������������Ӧ���ظ��ͻ���
     [������а� ��ʱ û�б����������Ƴ�]

    @param
    @parem
    @ver(���鲨,2002-x-x,
    ����޸�:NULL,2002-y-y)}
  protected
    procedure ProcessBuff();override;
  public
    {�������ͻ����Ƿ���ָ����MobileID��Ȩ��}
    function CheckMobileID(AMobileID:integer):boolean;
    {�û�ID}
    property UserID:integer read FUserID write SetUserID;
    {�ͻ��˵�¼ʱ��}
    property LogonTime:TDateTime read FLogonTime write SetLogonTime;
    {�׳����������߳�������}
    property OnProcessCmd:TOnProcessCmd read FOnProcessCmd write SetOnProcessCmd;

  end;


implementation
uses
  Sysutils,
  {CmdStructUnit,
  ConstDefineUnit, }
  EventLogUnit, Classes;
{ TClientThread }

function TClientThread.CheckMobileID(AMobileID:integer): boolean;
begin
  Result:=True;
end;

procedure TClientThread.ProcessBuff;
begin
  ProcessBuff_H0100;
end;

procedure TClientThread.ProcessBuff_H0100;
begin
  //�ּ�ÿһ�����ݣ�����������.��������쳣���ݣ��ͶϿ����ӡ�
  //while RecBuffDataLen>=2 do
  //begin
    FBufferLen:=ReadWord;
    if (FBufferLen=0) or (FBufferLen>MAX_CMDLEN) then
    begin
      NetServerLog.WriteEventlog('���������쳣,�Ͽ��ͻ���['+
        ClientSocket.RemoteAddress+','+Inttostr(ClientSocket.RemotePort)+']');

      ClientSocket.Close;
      Exit;
    end;
    if RecBuffDataLen>=FBufferLen then
    begin
      ReadAndDel(@FBuffer[0],FBufferLen);
      Synchronize(SynchrOnDoCmd);
    end;
  //end;
end;

procedure TClientThread.SynchrOnDoCmd;
begin
  if Assigned(FOnProcessCmd) then
    FOnProcessCmd(self,@FBuffer[0],FBufferLen);
end;

procedure TClientThread.SetLogonTime(const Value: TDateTime);
begin
  FLogonTime := Value;
end;

procedure TClientThread.SetOnProcessCmd(const Value: TOnprocessCmd);
begin
  FOnProcessCmd := Value;
end;

procedure TClientThread.SetUserID(const Value: integer);
begin
  FUserID := Value;
end;



end.
