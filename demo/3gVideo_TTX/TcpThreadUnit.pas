{ ������TCP�����̶߳���ʵ���˻��������ݵĽ��ܺͷ���
  @author(���鲨)
  @created(2002-11-04)
  @lastmod(GMT:$Date: 2012/11/26 06:34:56 $) <BR>
  ��������:$Author: ls $  <BR>
  ��ǰ�汾:$Revision: 1.1.1.1 $  <BR>}
unit TcpThreadUnit;

interface
uses
  classes,
  windows,
  winsock,
  scktcomp,
  EventLogUnit;

const
  WAITFORDATA_TIMEOUT=60000; //���Ӻ�60���ӿͻ��˲������ݾͶϿ�

type
  {���ݵ�����¼�}
  TOnDataReceived=procedure(AClient:TObject;ABuff:PByte;ALen:integer);

  TTcpThread=class(TServerClientThread)
  private
    FLockRecv: TRTLCriticalSection;   //�������������������������ڴ����ʱ���ܹ���ȡ��д��.
    FLockSend: TRTLCriticalSection;   //�������������������������ڴ����ʱ���ܹ���ȡ��д��.
    {���ܻ�����}
    FRecBuff:array of Byte;
    {���ܻ����������ݳ���}
    FRecBuffDataLen:integer;
    FSendBuff:array of Byte;
    {���ͻ����������ݳ���}
    FSendBuffDataLen:integer;
    FDirectSend: boolean;
    FQueryBuffInterVal: integer;
    FReceiveBuffSize: integer;
    FSendBuffSize: integer;
    FOnDataReceived: TOnDataReceived;
    FSendBytesCount: integer;
    FRecvBytesCount: integer;
    FOnDisconnect: TNotifyEvent;
    {�Ի��������ݽ��д����ʱ���ܹ����������Ĵ����������Ҫ������ס��}
    procedure LockRecvData;
    {@see Lock}
    procedure UnLockRecvData;

    procedure LockSendData;
    procedure UnLockSendData;

    function WaitForData(ATimeOut:integer):boolean;
    procedure SetDirectSend(const Value: boolean);
    procedure SetQueryBuffInterVal(const Value: integer);
    procedure SetReceiveBuffSize(const Value: integer);
    procedure SetSendBuffSize(const Value: integer);
    procedure SetOnDataReceived(const Value: TOnDataReceived);
    procedure SetRecvBytesCount(const Value: integer);
    procedure SetSendBytesCount(const Value: integer);
    procedure SynchrOnDataReceiv;
    procedure SetOnDisconnect(const Value: TNotifyEvent);
    procedure SynchOnDisconnect;   //
  protected
    //
    {�ӻ�������ʼλ�ö���һ��word}
    function ReadWord:integer;
    {���ܻ������ж���ָ�����ȵ�����
    @param ABuff:Pointer; ���ݶ����Ļ�����
    @parem Len:integer  ָ���Ķ����ݳ���
    @return ����ʵ�ʶ��������ݳ��ȣ�-1��ʾ����.
    @ver(���鲨,2003-9-11,
    ����޸�:NULL,2002-9-11)}
    function Read(ABuff:Pointer;Len:integer):integer;
    {�ӻ������ж���һ�����ݣ����Ұ�������ݴӻ����������,
    @return ����ʵ�ʶ��������ݳ���}
    function ReadAndDel(ABuff:Pointer;Len:integer):integer;
    {�����������ݣ������������ݷּ�ɵ��������ݰ���[����][����]��}
    procedure ProcessBuff(); virtual;
    procedure ClientExecute();override;
    {���ܻ������е����ݳ���
    DataLen���<0���������쳣}
    property RecBuffDataLen:integer read FRecBuffDataLen;
  public
    constructor Create(CreateSuspended: Boolean;
      ASocket: TServerClientWinSocket);
    destructor Destroy;override;
    {��DirectSend��True������£�ֱ�ӷ������ݡ�
    ������Ҫ���͵�������ӵ����ͻ�����ֱ����һ��������ѭ�з��͡�
    @param
    @parem
    @ver(���鲨,2002-x-x,
    ����޸�:NULL,2002-y-y)}
    procedure SendBuff(APoint:pointer;ALen:integer);
    {ֱ�ӷ������ݣ��������ݷ��ڷ��ͻ������У��˺������������߳�}
    procedure DSendBuff(APoint:pointer;ALen:integer);

    //
    {�ر�������ӣ��ڶϿ�����֮ǰ�����ͻ������е������ͳ�ȥ}
    procedure Close;

    //property SocketHandle:
    property DirectSend:boolean read FDirectSend write SetDirectSend;
    property SendBuffSize:integer read FSendBuffSize write SetSendBuffSize;
    property ReceiveBuffSize:integer read FReceiveBuffSize write SetReceiveBuffSize;
    {��DirectSend��False�������,
    ��ѯ������SendBuff�����ݵ�ʱ�����ĺ�����}
    property QueryBuffInterVal:integer read FQueryBuffInterVal write SetQueryBuffInterVal;
    {���ܵ����ݺ������׳��¼�}
    property OnDataReceived:TOnDataReceived read FOnDataReceived write SetOnDataReceived;
    {һ�����ܵ��ֽ���}
    property RecvBytesCount:integer read FRecvBytesCount write SetRecvBytesCount;
    {һ�����͵��ֽ���}
    property SendBytesCount:integer read FSendBytesCount write SetSendBytesCount;
    {�ͻ��˶Ͽ�ʱ���¼�}
    property OnDisconnect:TNotifyEvent read FOnDisconnect write SetOnDisconnect;
  end;

implementation
uses
  SysUtils
  ;
{ TcpThread }

procedure TTcpThread.ClientExecute;
var
  ret:integer;
  buf:array[0..1023] of Byte;
begin
  {//���Ӻ�60���ӿͻ��˲������ݾͶϿ�
  if not WaitForData(WAITFORDATA_TIMEOUT) then
  begin
    NetServerLog.WriteEventlog('�Ͽ���Ĭ����['+ClientSocket.RemoteAddress+']');
    ClientSocket.Close;
  end;   } 
  while (not Terminated) and ClientSocket.Connected do
  begin
    if WaitForData(FQueryBuffInterVal) then
    begin
      ret:=recv(ClientSocket.SocketHandle,buf,1024,0); 
      if (ret>0) then
      begin
        LockRecvData;
        inc(FRecvBytesCount,ret);
        try
          if length(FRecBuff)-FRecBuffDataLen<ret then
            setlength(FRecBuff,FRecBuffDataLen+ret);
          CopyMemory(@FRecBuff[FRecBuffDataLen],@buf[0],ret);
          FRecBuffDataLen:=FRecBuffDataLen+ret;
        finally
          UnLockRecvData;
        end;
       (* {$IFopt d+}
          NetServerLog.WriteEventlog('�յ��ͻ�������[��'+ MemFormatUnit.BuffToHex(@FRecBuff[0],FRecBuffDataLen) +']');
        {$ENDIF}  *)
        Synchronize(SynchrOnDataReceiv);
        ProcessBuff;
      end
      else
      begin
        //socket���� Ӧ�öϿ����Ӳ������߳�.
        //��������������Ͽ��ͻ���ʱ��ClientSocket.RemoteAddress=''
        ret:=WSAGetLastError;
        NetServerLog.WriteEventlog('['+ClientSocket.RemoteAddress+
         ']�Ͽ����ӣ�ErrorCode:'+IntToStr(ret));
        break;
      end;    
    end else
    begin  //������ͻ������������ݾͷ��͵��ͻ���
      if FSendBuffDataLen>0 then
      begin
        LockSendData;
        try
          DSendBuff(@FSendBuff[0],FSendBuffDataLen);
          FSendBuffDataLen:=0;
        finally
          UnLockSendData;
        end;
      end;

    end;//else begin

  end;   //while


  //do on disconn...
  if (ClientSocket.Connected) then
  begin
    ClientSocket.Close;
  end;

  Synchronize(SynchOnDisconnect);
  NetServerLog.WriteEventlog('�߳���ֹ,threadId='+IntToStr(ThreadID));
end;

procedure TTcpThread.Close;
begin
  if (ClientSocket<>nil) then
    ClientSocket.Close;
  self.Terminate;
  Exit;

  //�ٽ������ݲ�ͬ�������߳ɵ�ʱ�������˻������������߳��п����ٵ���Close������
  //��ʱ�Ͳ��ܵ���Lockdata�������������
  LockSendData;
  try
    DSendBuff(@FSendBuff[0],FSendBuffDataLen);
    FSendBuffDataLen:=0;
    SetLength(FSendBuff,FSendBuffDataLen);
    if (ClientSocket<>nil) and (ClientSocket.Connected) then
      ClientSocket.Close;
    self.Terminate;
  finally
    UnLockSendData;
  end;
end;

constructor TTcpThread.Create(CreateSuspended: Boolean;ASocket: TServerClientWinSocket);
begin
  inherited;
  InitializeCriticalSection(FLockRecv);
  InitializeCriticalSection(FLockSend);
  FDirectSend       :=True;
  FQueryBuffInterVal:=100;        //Ĭ�ϲ�ѯ���ͻ���������ʱ���� 100ms
  FReceiveBuffSize  :=100*1024;   //���ܻ����� 100K Byte
  FSendBuffSize     :=1024*1024;  //���ͻ����� 1M   Byte
end;


destructor TTcpThread.Destroy;
begin
  DeleteCriticalSection(FLockSend);
  DeleteCriticalSection(FLockRecv);
  inherited;
end;

procedure TTcpThread.DSendBuff(APoint: pointer; ALen: integer);
var
  ret:integer;
begin
  if ClientSocket<>nil then
  begin
    ret:=winsock.send(ClientSocket.SocketHandle,APoint^,ALen,0);
    if ret < 0 then
    begin
      ret:=WSAGetLastError;
      NetServerLog.WriteErrlog('�������ݵ�ʱ��������code='+IntToStr(ret));
    end;
  end;
    //else
    //NetServerLog.WriteErrlog('�������ݵ�ʱ��������Sock�ѹر�');
end;

procedure TTcpThread.LockRecvData;
begin
  EnterCriticalSection(FLockRecv);
end;

procedure TTcpThread.LockSendData;
begin
  EnterCriticalSection(FLockSend);
end;


procedure TTcpThread.SynchrOnDataReceiv;
begin
  if Assigned(FOnDataReceived) then
    FOnDataReceived(self,@FRecBuff[0],FRecBuffDataLen);
end;

procedure TTcpThread.SynchOnDisconnect;
begin
  if Assigned(FOnDisconnect) then
    FOnDisconnect(self);
end;

procedure TTcpThread.ProcessBuff;
begin
  //override;
end;

function TTcpThread.Read(ABuff: Pointer; Len: integer): integer;
begin
  LockRecvData;
  try
    if Len>FRecBuffDataLen then
      Result:=FRecBuffDataLen
    else
      Result:=Len;
    if Result>0 then
      CopyMemory(ABuff,@FRecBuff[0],Result);
  except
    UnLockRecvData;
    Result:=-1;
  end;
end;

function TTcpThread.ReadAndDel(ABuff: Pointer; Len: integer): integer;
begin
  LockRecvData;
  try
    if FRecBuffDataLen<len then len:=FRecBuffDataLen;
    CopyMemory(ABuff,@FRecBuff[0],len);
    FRecBuffDataLen:=FRecBuffDataLen-len;
    if FRecBuffDataLen>0 then
      CopyMemory(@FRecBuff[0],@FRecBuff[len],FRecBuffDataLen);
    Result:=len;
    setlength(FRecBuff,FRecBuffDataLen); // add by sha --ֻ�ڱ������� �� FRecBuff�� �Ѵ����� ���
  finally
    UnLockRecvData;
  end;
end;

function TTcpThread.ReadWord: integer;
begin
  if FRecBuffDataLen>=1 then
    Result := high(FRecBuff)+1
    //Result:=PWord(@FRecBuff[0])^  // ������:ԭ���س����У�����=���� (2Byte)��
  else
    Result:=0;
end;

procedure TTcpThread.SendBuff(APoint: pointer; ALen: integer);
begin
  inc(FSendBytesCount,ALen);
  if FDirectSend then
  begin
    if ClientSocket<>nil then
      winsock.send(ClientSocket.SocketHandle,APoint^,ALen,0)
  end else
  begin
    LockSendData;
    try
      //ֻҪ�������������Ĵ�С����ӵ����ͻ�����
      if FSendBuffDataLen+Alen>FSendBuffSize then Exit;

      if length(FSendBuff)-FSendBuffDataLen <Alen then
        Setlength(FSendBuff,FSendBuffDataLen+ALen);

       CopyMemory(@FSendBuff[FSendBuffDataLen],APoint,ALen);
       inc(FSendBuffDataLen,ALen);
    finally
      UnLockSendData;
    end;
  end;
end;

procedure TTcpThread.SetDirectSend(const Value: boolean);
begin
  FDirectSend := Value;
end;

procedure TTcpThread.SetOnDataReceived(const Value: TOnDataReceived);
begin
  FOnDataReceived := Value;
end;

procedure TTcpThread.SetQueryBuffInterVal(const Value: integer);
begin
  FQueryBuffInterVal := Value;
end;

procedure TTcpThread.SetReceiveBuffSize(const Value: integer);
begin
  FReceiveBuffSize := Value;
end;

procedure TTcpThread.SetRecvBytesCount(const Value: integer);
begin
  FRecvBytesCount := Value;
end;

procedure TTcpThread.SetSendBuffSize(const Value: integer);
begin
  FSendBuffSize := Value;
end;

procedure TTcpThread.SetSendBytesCount(const Value: integer);
begin
  FSendBytesCount := Value;
end;

procedure TTcpThread.UnLockRecvData;
begin
  LeaveCriticalSection(FLockRecv);
end;

procedure TTcpThread.UnLockSendData;
begin
  LeaveCriticalSection(FLockSend);
end;

function TTcpThread.WaitForData(ATimeOut: integer): boolean;
var
  FDSet: TFDSet;
  TimeVal: TTimeVal;
  re:integer;
begin
  TimeVal.tv_sec := ATimeOut div 1000;
  TimeVal.tv_usec := (ATimeOut mod 1000) * 1000;
  FD_ZERO(FDSet);
  FD_SET(ClientSocket.SocketHandle, FDSet);
  //re:=select(0, nil, nil,@FDSet,@TimeVal);
  re:=select(0, @FDSet, nil, nil, @TimeVal);

  if re>0 then
    Result:=True else
  if re=-1 then
    Result:=True else
  //if re=0 then
    Result:=False;
end;

procedure TTcpThread.SetOnDisconnect(const Value: TNotifyEvent);
begin
  FOnDisconnect := Value;
end;



end.
