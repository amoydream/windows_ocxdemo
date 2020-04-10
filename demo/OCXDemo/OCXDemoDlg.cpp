// OCXDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "OCXDemo.h"
#include "OCXDemoDlg.h"
#include "AlarmTypeParse.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#define AVDEC_STREAM_MODE_REAL			2
#define AVDEC_STREAM_MODE_SMOOTH			3

#define GPS_FILE_TYPE_NORMAL					0
#define GPS_FILE_TYPE_ALARM						1
#define GPS_FILE_TYPE_ALL						-1

#define GPS_FILE_LOCATION_DEVICE			1
#define GPS_FILE_LOCATION_STOSVR			2
//�ͻ���3������������������������ظ���3�Ȳ���
#define GPS_FILE_LOCATION_DOWNSVR			4		//���ط�����¼������

#define GPS_FILE_ATTRIBUTE_JPEG				1
#define GPS_FILE_ATTRIBUTE_RECORD			2


#define VIEW_SIZE_UNDEFINE			-1
#define VIEW_SIZE_FULL				0
#define VIEW_SIZE_4_3				1
#define VIEW_SIZE_16_9				2

#define CLIENT_LAYOUT_COUNT			4

#define VIEW_WND_TETRIS				0		//�Ź���
#define VIEW_WND_VERTICAL			1		//����
#define VIEW_WND_HORIZONTAL			2		//����

const int DEV_CHANNEL_ALL = -1;

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COCXDemoDlg dialog

COCXDemoDlg::COCXDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COCXDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COCXDemoDlg)
	m_strDevIDNO = _T("3001");
	m_strSearchDevIDNO = _T("2001");
	m_strIP = _T("127.0.0.1");
	m_strPort = _T("6605");
	m_strSavePicturePath = _T("");
	m_strAutoCloseTime = _T("0");
	m_strRecordSplitTime = _T("60");
	m_strReservedSpace = _T("2048");
	m_bOpenSound = FALSE;
	m_bTalkBack = FALSE;
	m_bMonitor = FALSE;
	m_strTitle = _T("");
	m_DataBeg = COleDateTime::GetCurrentTime();
	m_nDownTotalLen = 0;
	m_bBroadcast = FALSE;
//	m_pOCX = NULL;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bSubscribeGps = FALSE;
}

void COCXDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COCXDemoDlg)
	DDX_Control(pDX, IDC_SLIDER_SPEED, m_sliSpeed);
	DDX_Control(pDX, IDC_COMBO_VIDEO_MODE, m_cmbVideoMode);
	DDX_Control(pDX, IDC_COMBO_DISK_NO_SPACE_OPERATE_TYPE, m_cmbNoSpaceOperateType);
	DDX_Control(pDX, IDC_COMBO_WND_LAYOUT, m_cmbWndLayout);
	DDX_Control(pDX, IDC_COMBO_WND, m_cmbWnd);
	DDX_Control(pDX, IDC_COMBO_CHANNEL, m_cmbChannel);
	DDX_Control(pDX, IDC_COMBO_VIEW_SIZE, m_cmbViewSize);
	DDX_Control(pDX, IDC_COMBO_VIEW_ARRANGE, m_cmbViewArrangge);

	DDX_Text(pDX, IDC_EDIT_DEV_ID, m_strDevIDNO);
	DDV_MaxChars(pDX, m_strDevIDNO, 15);
	DDX_Text(pDX, IDC_EDIT_SERVER_IP, m_strIP);
	DDV_MaxChars(pDX, m_strIP, 32);
	DDX_Text(pDX, IDC_EDIT_SERVER_PORT, m_strPort);
	DDV_MaxChars(pDX, m_strPort, 6);
	DDX_Text(pDX, IDC_EDIT_PICTURE_SAVE_PATH, m_strSavePicturePath);
	DDX_Text(pDX, IDC_EDIT_AUTO_CLOSE_TIME, m_strAutoCloseTime);
	DDV_MaxChars(pDX, m_strAutoCloseTime, 6);
	DDX_Text(pDX, IDC_EDIT_RECORD_SPLIT_TIME, m_strRecordSplitTime);
	DDV_MaxChars(pDX, m_strRecordSplitTime, 6);
	DDX_Text(pDX, IDC_EDIT_RESERVED_SPACE, m_strReservedSpace);
	DDV_MaxChars(pDX, m_strReservedSpace, 6);
	DDX_Control(pDX, IDC_OCXCTRL, m_OCX);
	DDX_Text(pDX, IDC_EDIT_TITLE, m_strTitle);

	DDX_Control(pDX, IDC_BTN_LIGHT, m_btnLight);
	DDX_Control(pDX, IDC_BTN_WIPER, m_btnWiper);
	DDX_Control(pDX, IDC_BTN_CRUISE, m_btnAutoCruise);
	DDX_Control(pDX, IDC_BTN_ZOOM_DEL, m_btnZoomDel);
	DDX_Control(pDX, IDC_BTN_ZOOM_ADD, m_btnZoomAdd);
	DDX_Control(pDX, IDC_BTN_LIGHT_DEL, m_btnLightDel);
	DDX_Control(pDX, IDC_BTN_LIGHT_ADD, m_btnLightAdd);
	DDX_Control(pDX, IDC_BTN_FOCUS_DEL, m_btnFocusDel);
	DDX_Control(pDX, IDC_BTN_FOCUS_ADD, m_btnFocusAdd);
	DDX_Control(pDX, IDC_BTN_RIGHT_DOWN, m_btnRightDown);
	DDX_Control(pDX, IDC_BTN_LEFT_DOWN, m_btnLeftDown);
	DDX_Control(pDX, IDC_BTN_DOWN, m_btnDown);
	DDX_Control(pDX, IDC_BTN_LEFT, m_btnLeft);
	DDX_Control(pDX, IDC_BTN_RIGHT, m_btnRight);
	DDX_Control(pDX, IDC_BTN_RIGHT_UP, m_btnRightUp);
	DDX_Control(pDX, IDC_BTN_LEFT_UP, m_btnLeftUp);
	DDX_Control(pDX, IDC_BTN_UP, m_btnUp);
	DDX_Control(pDX, IDC_COMBO_WND_SHOW, m_cmbWndShow);

	DDX_Text(pDX, IDC_EDIT_DEV_IDNO, m_strSearchDevIDNO);
	DDX_Control(pDX, IDC_COMBO_SEARCH_CHANNEL, m_cmbSearchChannel);
	DDX_Control(pDX, IDC_COMBO_LOCATION, m_cmbLocation);
	DDX_Control(pDX, IDC_COMBO_FILE_TYPE, m_cmbFileType);
	DDX_Control(pDX, IDC_COMBO_FILE_ATTRIBUTE, m_cmbFileAttribute);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_SEARCH_TIME, m_DataBeg);
	DDX_Control(pDX, IDC_LIST_FILE, m_lstSearch);
	
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(COCXDemoDlg, CDialog)
	//{{AFX_MSG_MAP(COCXDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_FULL, OnButtonFull)
	ON_BN_CLICKED(IDC_BUTTON_STOP, OnButtonStop)
	ON_BN_CLICKED(IDC_BUTTON_PIC, OnButtonPic)
	ON_BN_CLICKED(IDC_BUTTON_PIC_ALL, OnButtonPicAll)
	ON_BN_CLICKED(IDC_BUTTON_PIC_DEV, OnButtonPicDev)
	ON_BN_CLICKED(IDC_BUTTON_OPEN_SOUND, OnButtonOpenSound)
	ON_BN_CLICKED(IDC_BUTTON_TALK_BACK, OnButtonTalkBack)
	ON_BN_CLICKED(IDC_BUTTON_MONITOR, OnButtonMonitor)
	ON_BN_CLICKED(IDC_BUTTON_START_RECORD, OnButtonStartRecord)
	ON_BN_CLICKED(IDC_BUTTON_STOP_RECORD, OnButtonStopRecord)
	ON_BN_CLICKED(IDC_BUTTON_ALL_PIC, OnButtonAllPic)
	ON_CBN_SELCHANGE(IDC_COMBO_WND_LAYOUT, OnSelchangeComboWndLayout)
	ON_BN_CLICKED(IDC_BUTTON_SELECT_PATH, OnButtonSelectPath)
	ON_BN_CLICKED(IDC_BUTTON_AUTO_CLOSE_TIME, OnButtonAutoCloseTime)
	ON_BN_CLICKED(IDC_BUTTON_REC_SPLIT_TIME, OnButtonRecSplitTime)
	ON_BN_CLICKED(IDC_BUTTON_RESERVED_SPACE, OnButtonReservedSpace)
	ON_BN_CLICKED(IDC_BUTTON_DISK_NO_SPACE, OnButtonDiskNoSpace)
	ON_BN_CLICKED(IDC_BUTTON_SAVE_PICTURE_PATH, OnButtonSavePicturePath)
	ON_BN_CLICKED(IDC_BUTTON_OCX_BK, OnButtonOCXBK)
	ON_BN_CLICKED(IDC_BUTTON_SET_TITLE, OnButtonSetTitle)
	ON_BN_CLICKED(IDC_BUTTON_SET_ACTIVE_WND, OnButtonSetActiveWnd)
	ON_BN_CLICKED(IDC_BUTTON_GET_ACTIVE_WND, OnButtonGetActiveWnd)

	ON_CBN_SELCHANGE(IDC_COMBO_VIDEO_MODE, OnSelchangeComboVideoMode)
	ON_CBN_SELCHANGE(IDC_COMBO_WND_SHOW, OnSelchangeComboWndShow)
	ON_CBN_SELCHANGE(IDC_COMBO_VIEW_SIZE, OnSelchangeComboViewSize)
	ON_CBN_SELCHANGE(IDC_COMBO_VIEW_ARRANGE, OnSelchangeComboArrange)

	ON_BN_CLICKED(IDC_BUTTON_SEARCH, OnBtnSearch)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_FILE, OnRclickListFile)

	ON_COMMAND(ID_MENU_RECSEARCH_DOWN, OnMenuRecsearchDown)
	ON_COMMAND(ID_MENU_RECSEARCH_PLAY, OnMenuRecsearchPlay)

	ON_BN_CLICKED(IDC_BTN_GPS, OnBtnGps)

	ON_EN_CHANGE(IDC_EDIT_SERVER_IP, OnChangeEdServer)
	ON_EN_CHANGE(IDC_EDIT_SERVER_PORT, OnChangeEdServer)

	ON_BN_CLICKED(IDC_BTN_ONLINE, OnBtnOnline)
	ON_BN_CLICKED(IDC_BUTTON_3G_NET, OnGet3GInfo)
	ON_BN_CLICKED(IDC_BUTTON_3G_NET_SET, OnSet3GInfo)
	ON_MESSAGE(WM_MSG_PTZ_BTN, OnPTZLButton)
	ON_BN_CLICKED(IDC_BTN_BROADCAST, OnBroadcast)

	
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_EVENTSINK_MAP(COCXDemoDlg, CDialog)
//{{AFX_EVENTSINK_MAP(CTestocxDlg)
	ON_EVENT(COCXDemoDlg, IDC_OCXCTRL, 1, OnClickViewWndctrl, VTS_I4 VTS_BSTR)
	ON_EVENT(COCXDemoDlg, IDC_OCXCTRL, 2, OnDBClickViewWndctrl, VTS_I4 VTS_BSTR)
	ON_EVENT(COCXDemoDlg, IDC_OCXCTRL, 3, OnRClickViewWndctrl, VTS_I4 VTS_BSTR)
	ON_EVENT(COCXDemoDlg, IDC_OCXCTRL, 4, OnRecSearchEvent, VTS_BSTR  VTS_DATE  VTS_DATE  VTS_I4  VTS_I4  VTS_I4  VTS_I4  VTS_I4)
	ON_EVENT(COCXDemoDlg, IDC_OCXCTRL, 5, OnRecSearchMsgEvent, VTS_I4  VTS_I4)
	ON_EVENT(COCXDemoDlg, IDC_OCXCTRL, 6, OnDownFileEvent, VTS_I4  VTS_I4)
	ON_EVENT(COCXDemoDlg, IDC_OCXCTRL, 7, OnGpsStateEvent, VTS_BSTR  VTS_DATE  VTS_I4  VTS_I4  VTS_I4  VTS_I4  VTS_I4  VTS_I4  VTS_I4  VTS_I4  VTS_I4  VTS_I4 VTS_BSTR)
	ON_EVENT(COCXDemoDlg, IDC_OCXCTRL, 8, OnSnapshotDevEvent, VTS_BSTR  VTS_I4  VTS_BSTR  VTS_I4)
	ON_EVENT(COCXDemoDlg, IDC_OCXCTRL, 9, OnGetDevNetFlowStatisticsEvent, VTS_BSTR  VTS_I4  VTS_R4  VTS_R4  VTS_I4  VTS_I4  VTS_I4  VTS_I4  VTS_R4  VTS_R4  VTS_I4  VTS_I4  VTS_I4)
	ON_EVENT(COCXDemoDlg, IDC_OCXCTRL, 10, OnSetDevNetFlowStatisticsEvent, VTS_BSTR  VTS_I4)
	ON_EVENT(COCXDemoDlg, IDC_OCXCTRL, 11, OnDevAlarmEvent, VTS_BSTR  VTS_BSTR VTS_BSTR)
	ON_EVENT(COCXDemoDlg, IDC_OCXCTRL, 12, OnGpsStateEventEx, VTS_BSTR  VTS_BSTR)

//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()


/////////////////////////////////////////////////////////////////////////////
// COCXDemoDlg message handlers

BOOL COCXDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	CString str;
	int i;
	for (i = 0; i < 4; ++i)
	{
		str.Format("ͨ��-%d", i+1);
		m_cmbChannel.AddString(str);
		m_cmbSearchChannel.AddString(str);
		m_cmbSearchChannel.SetItemData(i, i);
		str.Format("����-%d", i+1);
		m_cmbWnd.AddString(str);
	}
	int nIndex = m_cmbSearchChannel.AddString("����ͨ��");
	m_cmbSearchChannel.SetItemData(nIndex, DEV_CHANNEL_ALL);
	m_cmbSearchChannel.SetCurSel(0);
	
	m_cmbChannel.SetCurSel(0);
	m_cmbWnd.SetCurSel(0);

	for (i = 1; i < 6; ++i)
	{
		str.Format("%d", i);
		m_cmbWndLayout.AddString(str);
	}
	m_cmbWndLayout.SetCurSel(m_OCX.GetLayout()-1);

	//�Զ��ر���Ƶ
	m_strAutoCloseTime.Format("%d", m_OCX.GetAutoCloseVideoTime());

	//ץ��·��
	m_strSavePicturePath = m_OCX.GetCaptureSavePath();

	//¼��
	m_cmbNoSpaceOperateType.AddString("����");
	m_cmbNoSpaceOperateType.AddString("ֹͣ");
	m_cmbNoSpaceOperateType.SetCurSel(m_OCX.GetDiskNoSpaceOperateType());

	m_strRecordSplitTime.Format("%d", m_OCX.GetRecordPackTime());
	m_strReservedSpace.Format("%d", m_OCX.GetDiskReservedSpace());

	//��Ƶģʽ����
	m_cmbVideoMode.AddString("ʵʱ�Ժ�");
	m_cmbVideoMode.AddString("�����Ժ�");
	m_cmbVideoMode.SetCurSel(0);
	OnSelchangeComboVideoMode();

	m_cmbWndShow.AddString("ʵʱԤ��");
	m_cmbWndShow.AddString("Զ�̻ط�");
	m_cmbWndShow.SetCurSel(0);

	//����
///////////////////ע�Ͳ���Ϊ�޸Ŀռ�Ĭ����۽ӿ�////////////////////////////////
// 	m_OCX.SetColorBK(RGB(255,0,0));
// 	m_OCX.SetColorVideoBK(RGB(0,255,0));
// 	m_OCX.SetColorVideoTitleBK(RGB(0,0,255));
// 	m_OCX.SetColorVideoBKActive(RGB(255,255,0));
// 	m_OCX.SetStrVideoBKPicturePath("dlg_voip_sound.jpg");
//////////////////////////////////////////////////////////////////////////

	DWORD styles = m_lstSearch.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES;
	m_lstSearch.SetExtendedStyle(styles );
	m_lstSearch.InsertColumn(0, "ʱ��", LVCFMT_LEFT, 120);
	m_lstSearch.InsertColumn(1, "����", LVCFMT_LEFT, 70);
	m_lstSearch.InsertColumn(2, "�豸", LVCFMT_LEFT, 90);
	m_lstSearch.InsertColumn(3, "ͨ��", LVCFMT_LEFT, 90);
	m_lstSearch.InsertColumn(4, "λ��", LVCFMT_LEFT, 90);
	m_lstSearch.InsertColumn(5, "��С(MB)", LVCFMT_LEFT, 90);
	m_lstSearch.InsertColumn(6, "�ļ�", LVCFMT_LEFT, 240);

	nIndex = 0;
	nIndex = m_cmbLocation.AddString("�豸");
	m_cmbLocation.SetItemData(nIndex, GPS_FILE_LOCATION_DEVICE);
	nIndex = m_cmbLocation.AddString("�洢������");
	m_cmbLocation.SetItemData(nIndex, GPS_FILE_LOCATION_STOSVR);
	nIndex = m_cmbLocation.AddString("���ط�����");
	m_cmbLocation.SetItemData(nIndex, GPS_FILE_LOCATION_DOWNSVR);
	nIndex = m_cmbLocation.AddString("����");
	m_cmbLocation.SetItemData(nIndex, 3);
	m_cmbLocation.SetCurSel(1);

	nIndex = m_cmbFileType.AddString("¼��");
	m_cmbFileType.SetItemData(nIndex, GPS_FILE_ATTRIBUTE_RECORD);
// 	nIndex = m_cmbFileType.AddString("ͼƬ");
// 	m_cmbFileType.SetItemData(nIndex, GPS_FILE_ATTRIBUTE_JPEG);
	m_cmbFileType.SetCurSel(0);

	nIndex = m_cmbFileAttribute.AddString("����");
	m_cmbFileAttribute.SetItemData(nIndex, GPS_FILE_TYPE_NORMAL);
	nIndex = m_cmbFileAttribute.AddString("����");
	m_cmbFileAttribute.SetItemData(nIndex, GPS_FILE_TYPE_ALARM);
	nIndex = m_cmbFileAttribute.AddString("����");
	m_cmbFileAttribute.SetItemData(nIndex, GPS_FILE_TYPE_ALL);
	m_cmbFileAttribute.SetCurSel(0);

	nIndex = m_cmbViewSize.AddString("����");
	m_cmbViewSize.SetItemData(nIndex, VIEW_SIZE_FULL);
	nIndex = m_cmbViewSize.AddString("4:3");
	m_cmbViewSize.SetItemData(nIndex, VIEW_SIZE_4_3);
	nIndex = m_cmbViewSize.AddString("16:9");
	m_cmbViewSize.SetItemData(nIndex, VIEW_SIZE_16_9);
	m_cmbViewSize.SetCurSel(0);

	nIndex = m_cmbViewArrangge.AddString("����");
	m_cmbViewArrangge.SetItemData(nIndex, VIEW_WND_TETRIS);
	nIndex = m_cmbViewArrangge.AddString("����");
	m_cmbViewArrangge.SetItemData(nIndex, VIEW_WND_VERTICAL);
	nIndex = m_cmbViewArrangge.AddString("����");
	m_cmbViewArrangge.SetItemData(nIndex, VIEW_WND_HORIZONTAL);
	m_cmbViewArrangge.SetCurSel(0);

	UpdateData(FALSE);
	
	m_OCX.SetServerIP(m_strIP);
	m_OCX.SetServerPort(atoi(m_strPort));


// 	m_pOCX = new CCMSV6OCX;
// 	m_pOCX->SetServerIP(m_strIP);
// 	m_pOCX->SetServerPort(atoi(m_strPort));


// 	char m_szModuleFile[MAX_PATH] = {0};
// 	strncpy(m_szModuleFile, szModule, sizeof(m_szModuleFile) - 1);
	str = "Z:\\project\\1010gps\\Bin\\Client\\CMSV6OCX\\bin\\client.dll";
// 
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void COCXDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void COCXDemoDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR COCXDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void COCXDemoDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	if (m_strIP.IsEmpty() || m_strPort.IsEmpty() || m_strDevIDNO.IsEmpty() 
		|| m_cmbChannel.GetCurSel() == CB_ERR || m_cmbWnd.GetCurSel() == CB_ERR)
	{
		AfxMessageBox("�������.");
		return;
	}

	m_OCX.SetServerIP(m_strIP);
	m_OCX.SetServerPort(atoi(m_strPort));

	long nErr = m_OCX.StartVideo(m_strDevIDNO.GetBuffer(0), m_cmbChannel.GetCurSel(), m_cmbWnd.GetCurSel());

//	CDialog::OnOK();
}

void COCXDemoDlg::OnButtonFull() 
{
	// TODO: Add your control notification handler code here
	m_OCX.FullScreen();
	
}
BOOL COCXDemoDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	if ( (WM_KEYDOWN == pMsg->message) && (VK_ESCAPE == pMsg->wParam || VK_RETURN == pMsg->wParam))
	{
		if (m_OCX.IsFullScreen())
		{
			m_OCX.ExitFullScreen();
		}
		return FALSE;
	}
	
	return CDialog::PreTranslateMessage(pMsg);
}

void COCXDemoDlg::OnButtonStop() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_cmbWnd.GetCurSel() != CB_ERR)
	{
		m_OCX.StopVideo(m_cmbWnd.GetCurSel());
	}
}

void COCXDemoDlg::OnButtonPic() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_cmbWnd.GetCurSel() != CB_ERR)
	{
		m_OCX.CapturePicture(m_cmbWnd.GetCurSel());
	}
}

void COCXDemoDlg::OnButtonPicAll() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_OCX.CaptureAllWindowPicture();
}

void COCXDemoDlg::OnButtonPicDev() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_cmbChannel.GetCurSel() != CB_ERR && m_strDevIDNO.IsEmpty() == FALSE)
	{
		m_OCX.SnapshotDev(m_strDevIDNO, m_cmbChannel.GetCurSel());
	}
}

void COCXDemoDlg::OnButtonOpenSound() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_bOpenSound)
	{
		m_OCX.CloseSound();
		m_bOpenSound = FALSE;
		GetDlgItem(IDC_BUTTON_OPEN_SOUND)->SetWindowText("������");
	}
	else
	{
		if (m_cmbWnd.GetCurSel() != CB_ERR)
		{
			if(m_OCX.OpenSound(m_cmbWnd.GetCurSel()) == S_OK)
			{
				m_bOpenSound = TRUE;
				GetDlgItem(IDC_BUTTON_OPEN_SOUND)->SetWindowText("�ر�����");
			}
		}
	}
}

void COCXDemoDlg::OnButtonTalkBack() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_bTalkBack)
	{
		m_OCX.StopTalkBack();
		m_bTalkBack = FALSE;
		GetDlgItem(IDC_BUTTON_TALK_BACK)->SetWindowText("�����Խ�");
	}
	else
	{
		if (!m_strDevIDNO.IsEmpty())
		{
			m_OCX.StartTalkBack(m_strDevIDNO);
			m_bTalkBack = TRUE;
			GetDlgItem(IDC_BUTTON_TALK_BACK)->SetWindowText("�رնԽ�");
		}
	}
}

void COCXDemoDlg::OnButtonMonitor() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_bMonitor)
	{
		m_OCX.StopMonitor();
		m_bMonitor = FALSE;
		GetDlgItem(IDC_BUTTON_MONITOR)->SetWindowText("��������");
	}
	else
	{
		if (!m_strDevIDNO.IsEmpty() && m_cmbChannel.GetCurSel() != CB_ERR)
		{
			long nErr = m_OCX.StartMonitor(m_strDevIDNO, m_cmbChannel.GetCurSel());
			m_bMonitor = TRUE;
			GetDlgItem(IDC_BUTTON_MONITOR)->SetWindowText("�رռ���");
		}
	}
}

void COCXDemoDlg::OnButtonStartRecord() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (!m_strDevIDNO.IsEmpty() && m_cmbChannel.GetCurSel() != CB_ERR)
	{
		m_OCX.StartRecord(m_strDevIDNO, m_cmbChannel.GetCurSel());
	}
}

void COCXDemoDlg::OnButtonStopRecord() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (!m_strDevIDNO.IsEmpty() && m_cmbChannel.GetCurSel() != CB_ERR)
	{
		m_OCX.StopRecord(m_strDevIDNO, m_cmbChannel.GetCurSel());
	}
}

void COCXDemoDlg::OnButtonAllPic() 
{
	// TODO: Add your control notification handler code here
	m_OCX.CaptureAllWindowPicture();
}

void COCXDemoDlg::OnSelchangeComboWndLayout() 
{
	// TODO: Add your control notification handler code here
	if (m_cmbWndLayout.GetCurSel() != CB_ERR)
	{
		m_OCX.SetLayout(m_cmbWndLayout.GetCurSel()+1);
	}
}

void COCXDemoDlg::OnButtonSelectPath() 
{
	// TODO: Add your control notification handler code here
	m_strSavePicturePath = ChangeDownPath(m_strSavePicturePath);
	UpdateData(FALSE);
}

void COCXDemoDlg::OnButtonAutoCloseTime() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (!m_strAutoCloseTime.IsEmpty())
	{
		m_OCX.SetAutoCloseVideoTime(atoi(m_strAutoCloseTime));
		AfxMessageBox("���óɹ�");
	}
	else
	{
		AfxMessageBox("����Ϊ��");
	}
}

void COCXDemoDlg::OnButtonRecSplitTime() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (!m_strRecordSplitTime.IsEmpty())
	{
		m_OCX.SetRecordPackTime(atoi(m_strRecordSplitTime));
		AfxMessageBox("���óɹ�");
	}
	else
	{
		AfxMessageBox("����Ϊ��");
	}
}

void COCXDemoDlg::OnButtonReservedSpace() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (!m_strReservedSpace.IsEmpty())
	{
		m_OCX.SetDiskReservedSpace(atoi(m_strReservedSpace));
		AfxMessageBox("���óɹ�");
	}
	else
	{
		AfxMessageBox("����Ϊ��");
	}
}

void COCXDemoDlg::OnButtonDiskNoSpace() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_cmbNoSpaceOperateType.GetCurSel() != CB_ERR)
	{
		m_OCX.SetDiskNoSpaceOperateType(m_cmbNoSpaceOperateType.GetCurSel());
		AfxMessageBox("���óɹ�");
	}
	else
	{
		AfxMessageBox("ѡ�����");
	}
}

INT CALLBACK COCXDemoDlg::BrowseCallbackProc(HWND hwnd, 
											  UINT uMsg,
											  LPARAM lp, 
											  LPARAM pData) 
{
	COCXDemoDlg* pThis = (COCXDemoDlg*)pData;
	
	TCHAR szDir[MAX_PATH];
	switch(uMsg) 
	{
	case BFFM_INITIALIZED: 
		pThis->DoBrowseInitialize(hwnd);
		break;
		
	case BFFM_SELCHANGED: 
		// Set the status window to the currently selected path.
		if (SHGetPathFromIDList((LPITEMIDLIST) lp ,szDir))
		{
			::SendMessage(hwnd,BFFM_SETSTATUSTEXT,0,(LPARAM)szDir);
		}
		break;
	}
	return 0;
}

void COCXDemoDlg::DoBrowseInitialize(HWND hwnd)
{
	::SendMessage(hwnd, BFFM_SETSELECTION, TRUE, (LPARAM) ((LPCTSTR)m_strSavePicturePath));
}

CString COCXDemoDlg::ChangeDownPath(CString& strOldPath)
{
	m_strSavePicturePath = strOldPath;
	
	CString strFolder;
	LPMALLOC lpMalloc;
	if (::SHGetMalloc(&lpMalloc) != NOERROR) 
	{
		return strFolder;
	}
	
	CString strName = "cmsv6";
	CString strTitle = "ѡ��·��";
	TCHAR szDisplayName[_MAX_PATH] = {0};
	TCHAR szBuffer[_MAX_PATH] = {0};
	BROWSEINFO browseInfo;
	browseInfo.hwndOwner = GetSafeHwnd();
	browseInfo.pidlRoot = NULL; // set root at Desktop
	browseInfo.pszDisplayName = szDisplayName;
	browseInfo.lpszTitle = strTitle;
	browseInfo.ulFlags = BIF_RETURNFSANCESTORS|BIF_RETURNONLYFSDIRS;
	browseInfo.lpfn = BrowseCallbackProc;
	browseInfo.lParam = (LPARAM)this;
	
	LPITEMIDLIST lpItemIDList;
	if ((lpItemIDList = ::SHBrowseForFolder(&browseInfo)) != NULL) 
	{
		// Get the path of the selected folder from the item ID list.
		if (::SHGetPathFromIDList(lpItemIDList, szBuffer))
		{
			strFolder = szBuffer;
			if (strFolder.Right(1) != "\\")
			{
				strFolder += _T("\\");
			}
		}
		
		lpMalloc->Free(lpItemIDList);
		lpMalloc->Release(); lpMalloc = NULL;
	}
	return strFolder;
}

void COCXDemoDlg::OnButtonSavePicturePath() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (!m_strSavePicturePath.IsEmpty())
	{
		m_OCX.SetCaptureSavePath(m_strSavePicturePath);
	}
}

void COCXDemoDlg::OnButtonOCXBK()
{
	m_OCX.SetColorBK(RGB(255,0,0));
	m_OCX.SetColorVideoBK(RGB(0,255,0));
	m_OCX.SetColorVideoTitleBK(RGB(0,0,255));
	m_OCX.SetColorVideoBKActive(RGB(255,255,0));
	m_OCX.SetStrVideoBKPicturePath("dlg_voip_sound.jpg");
}


void COCXDemoDlg::OnClickViewWndctrl(long nWindow, LPCTSTR strTitle) 
{
	// TODO: Add your control notification handler code here
	CString str;
	str.Format("�����������Ƶ�����¼� %d--%s\n", nWindow, strTitle);
	TRACE(str);
//	AfxMessageBox(str);
}

void COCXDemoDlg::OnDBClickViewWndctrl(long nWindow, LPCTSTR strTitle) 
{
	// TODO: Add your control notification handler code here
	CString str;
	str.Format("˫����Ƶ�����¼� %d--%s\n", nWindow, strTitle);
	TRACE(str);
//	AfxMessageBox(str);
	
}

void COCXDemoDlg::OnRClickViewWndctrl(long nWindow, LPCTSTR strTitle) 
{
	// TODO: Add your control notification handler code here
	CString str;
	str.Format("�Ҽ���Ƶ�����¼� %d--%s\n", nWindow, strTitle);
	TRACE(str);
//	AfxMessageBox(str);

}

void COCXDemoDlg::OnButtonSetTitle() 
{
	// TODO: Add your control notification handler code here
	UpdateData(FALSE);
	int nIndex = m_cmbWnd.GetCurSel();
	if (nIndex != CB_ERR)
	{
		m_OCX.SetViewTitle(nIndex, "123");
	}
}
void COCXDemoDlg::OnButtonSetActiveWnd()
{
	m_OCX.SetNActiveWndIndex(m_cmbChannel.GetCurSel());
}
void COCXDemoDlg::OnButtonGetActiveWnd()
{
	CString str;
	str.Format("active windows is  %d", m_OCX.GetNActiveWndIndex()+1);
	AfxMessageBox(str);
}
void COCXDemoDlg::OnSelchangeComboVideoMode() 
{
	// TODO: Add your control notification handler code here
	int nIndex = m_cmbVideoMode.GetCurSel();
	if (nIndex != -1)
	{
		if (nIndex == 0)
		{
			nIndex = AVDEC_STREAM_MODE_REAL;
		}
		else
		{
			nIndex = AVDEC_STREAM_MODE_SMOOTH;
		}
		m_OCX.SetVideoControl(nIndex);
	}
}

void COCXDemoDlg::OnSelchangeComboWndShow()
{
	m_OCX.SetShowWnd(m_cmbWndShow.GetCurSel());
}
void COCXDemoDlg::OnSelchangeComboViewSize()
{
	m_OCX.SetPaneType(m_cmbViewSize.GetItemData(m_cmbViewSize.GetCurSel()));
}
void COCXDemoDlg::OnSelchangeComboArrange()
{
	m_OCX.SetWndArrange(m_cmbViewArrangge.GetItemData(m_cmbViewArrangge.GetCurSel()));
}
void COCXDemoDlg::OnPTZLButton(WPARAM wParam, LPARAM lParam)
{
	if (lParam == WM_LBUTTONDOWN)
	{
		switch(wParam)
		{
		case IDC_BTN_DOWN:
			PtzControl(GPS_PTZ_MOVE_BOTTOM);
			break;
		case IDC_BTN_LEFT_DOWN:
			PtzControl(GPS_PTZ_MOVE_LEFT_BOTTOM);
			break;
		case IDC_BTN_LEFT:
			PtzControl(GPS_PTZ_MOVE_LEFT);
			break;
		case IDC_BTN_LEFT_UP:
			PtzControl(GPS_PTZ_MOVE_LEFT_TOP);
			break;
		case IDC_BTN_UP:
			PtzControl(GPS_PTZ_MOVE_TOP);
			break;
		case IDC_BTN_RIGHT_UP:
			PtzControl(GPS_PTZ_MOVE_RIGHT_TOP);
			break;
		case IDC_BTN_RIGHT:
			PtzControl(GPS_PTZ_MOVE_RIGHT);
			break;
		case IDC_BTN_RIGHT_DOWN:
			PtzControl(GPS_PTZ_MOVE_RIGHT_BOTTOM);
			break;
		case IDC_BTN_FOCUS_DEL:
			PtzControl(GPS_PTZ_FOCUS_DEL);
			break;
		case IDC_BTN_FOCUS_ADD:
			PtzControl(GPS_PTZ_FOCUS_ADD);
			break;
		case IDC_BTN_LIGHT_DEL:
			PtzControl(GPS_PTZ_LIGHT_DEL);
			break;
		case IDC_BTN_LIGHT_ADD:
			PtzControl(GPS_PTZ_LIGHT_ADD);
			break;
		case IDC_BTN_ZOOM_DEL:
			PtzControl(GPS_PTZ_ZOOM_DEL);
			break;
		case IDC_BTN_ZOOM_ADD:
			PtzControl(GPS_PTZ_ZOOM_ADD);
			break;
		default:
			break;
		}
	}
	else if(lParam == WM_LBUTTONUP)
	{
		switch(wParam)
		{
		case IDC_BTN_DOWN:
		case IDC_BTN_LEFT_DOWN:
		case IDC_BTN_LEFT:
		case IDC_BTN_LEFT_UP:
		case IDC_BTN_UP:
		case IDC_BTN_RIGHT_UP:
		case IDC_BTN_RIGHT:
		case IDC_BTN_RIGHT_DOWN:
		case IDC_BTN_FOCUS_DEL:
		case IDC_BTN_FOCUS_ADD:
		case IDC_BTN_LIGHT_DEL:
		case IDC_BTN_LIGHT_ADD:
		case IDC_BTN_ZOOM_DEL:
		case IDC_BTN_ZOOM_ADD:
			PtzControl(GPS_PTZ_MOVE_STOP);
			break;
		default:
			break;
		}
	}
}

void COCXDemoDlg::PtzControl(int nCommand, int nParam/* = 0*/)
{
	int nWindow = m_cmbWnd.GetCurSel();
	if (nWindow != CB_ERR)
	{
		m_OCX.PtzControl(nWindow, nCommand, nParam, m_sliSpeed.GetPos());
	}
}
void COCXDemoDlg::DelAllRecItem()
{
	for (int i = 0; i < m_lstSearch.GetItemCount(); ++i)
	{
		GPSFile_S* pNewFile = (GPSFile_S*)m_lstSearch.GetItemData(i);
		delete pNewFile;
		pNewFile = NULL;
	}
	m_lstSearch.DeleteAllItems();
	
}
void COCXDemoDlg::OnBtnSearch()
{
	UpdateData();
	DelAllRecItem();

	if (m_strSearchDevIDNO.IsEmpty() 
		|| m_cmbSearchChannel.GetCurSel() == CB_ERR
		|| m_cmbFileType.GetCurSel() == CB_ERR
		|| m_cmbLocation.GetCurSel() == CB_ERR
		|| m_cmbFileAttribute.GetCurSel() == CB_ERR)
	{
		AfxMessageBox("������������");
		return;
	}

	m_OCX.SetServerIP(m_strIP);
	m_OCX.SetServerPort(atoi(m_strPort));
	
	m_DataBeg.SetDateTime(m_DataBeg.GetYear(), m_DataBeg.GetMonth(), m_DataBeg.GetDay(), 0, 0, 0);
	DATE dBeg = m_DataBeg.m_dt;
	m_DataBeg.SetDateTime(m_DataBeg.GetYear(), m_DataBeg.GetMonth(), m_DataBeg.GetDay(), 23, 59, 59);
	DATE dEnd = m_DataBeg.m_dt;
	m_OCX.StartRecSearch(m_strSearchDevIDNO.GetBuffer(0), 
						m_cmbSearchChannel.GetItemData(m_cmbSearchChannel.GetCurSel()),
						m_cmbFileAttribute.GetItemData(m_cmbFileAttribute.GetCurSel()),
						dBeg, dEnd, m_cmbLocation.GetItemData(m_cmbLocation.GetCurSel()), 
						m_cmbFileType.GetItemData(m_cmbFileType.GetCurSel()));

}
int COCXDemoDlg::GetFileListIndex(GPSFile_S* pNewFile)
{
	int nCount = m_lstSearch.GetItemCount();
	int nInsertIndex = nCount;
	for (int i = 0; i < nCount; ++ i)
	{
		GPSFile_S* pFile = (GPSFile_S*)m_lstSearch.GetItemData(i);
		if (pNewFile->uiBegintime < pFile->uiBegintime)
		{
			nInsertIndex = i;
			break;
		}
	}
	return nInsertIndex;
}
CString	FormatSecond(int nSecond)
{
	CString str;
	str.Format("%02d:%02d:%02d", nSecond / 3600, nSecond % 3600 / 60, nSecond % 60);
	return str;
}
CString	GetFileType(int nFileType)
{
	CString str= _T("");
	switch (nFileType)
	{
	case GPS_FILE_TYPE_NORMAL:
		str = "����";
		break;
	case GPS_FILE_TYPE_ALARM:
		str = "����";
		break;
	}
	return str;
}

CString	GetFileSize(int nFileSize)
{
	double dMB = nFileSize * 1.0 / 1024 / 1024;
	CString str;
	str.Format("%.3fMB", dMB);
	return str;
}
// char* CheckFileName(const char* szRecFile)
// {
// 	char* p = strrchr(szRecFile, '/');
// 	if(NULL == p)
// 	{
// 		p = strrchr(szRecFile, '\\');
// 	}
// 	
// 	if (p)
// 	{
// 		p = p + 1;
// 	}
// 	
// 	if(!p || p[0] != 'H' || /*static_cast<int> (strlen(p)) != 26 ||*/ p[9] != '-')
// 	{
// 		return NULL;
// 	}
// 	else
// 	{
// 		int length = strlen(szRecFile);
// 		if (stricmp(szRecFile + length - 4, ".mdv") == 0)
// 		{
// 			return p;
// 		}
// 		else
// 		{
// 			return NULL;
// 		}
// 	}
// }
// BOOL GetFileChn(const char* szRecFile, std::list<int>& lstChn)
// {
// 	char *Tempch = CheckFileName(szRecFile);
// 	if (Tempch != NULL)
// 	{
// 		Tempch += 20;
// 		unsigned char c = Net2Hex2Char((unsigned char*)Tempch);
// 		for (int i = 0; i < 16; ++ i)
// 			//for (int i = 0; i < 1; ++ i)
// 		{
// 			if( (c >> i) & 0x1 )
// 			{
// 				lstChn.push_back(i);
// 			}
// 		}
// 		return TRUE;
// 	}
// 	else
// 	{
// 		return FALSE;
// 	}
// }
// 
// //�� 'FA' = 15*16 + 10
// unsigned char Net2Hex2Char(unsigned char* pBuf)
// {
// 	return NetHex2Char(pBuf[0]) * 16 + NetHex2Char(pBuf[1]);
// }
// 
// //��16����ת����char
// unsigned char NetHex2Char(unsigned char ch)
// {
// 	if (ch >= 'A' && ch <= 'F')
// 	{
// 		ch = ch - 'A' + 10;
// 	}
// 	else if ( ch >= '0' && ch <= '9')
// 	{
// 		ch = ch - '0';
// 	}
// 	else
// 	{
// 		ch = 0;
// 	}
// 	return ch;
// }
// typedef std::list<int> lstChn;
// typedef lstChn::iterator lstChnIter;
// CString	GetChannelName(GPSFile_S* pNewFile)
// {
// 	CString strChannelAll;
// 	CString strID, strChannel, strDev;
// 	if (pNewFile->nChn == 98)
// 	{
// 		lstChn chn;
// 		if (GetFileChn(pNewFile->szFile, chn))
// 		{
// 			CDevBase* pDev = CVMgrDevice::GetInstance()->FindDvsDeviceByIDNO(pNewFile->szDevIDNO);
// 			if (pDev)
// 			{
// 				if (chn.size() >= pDev->GetChannelNum())
// 				{
// 					strChannelAll = LOADSTRINGEX(ID_STR_DLG_REC_ALL_CHANNEL);
// 				}
// 				else
// 				{
// 					lstChnIter iter = chn.begin();
// 					while(iter != chn.end())
// 					{
// 						if(GetDevAndChnName(pNewFile->szDevIDNO, (*iter), strID, strDev, strChannel))
// 						{
// 							strChannelAll += strChannel;
// 						}
// 						++iter;
// 					}
// 				}
// 			}
// 		}
// 	}
// 	else
// 	{
// 		if(GetDevAndChnName(pNewFile->szDevIDNO, pNewFile->nChn, strID, strDev, strChannel))
// 		{
// 			strChannelAll += strChannel;
// 		}
// 	}
// 	return strChannelAll;
// }
void COCXDemoDlg::OnRecSearchEvent(LPCTSTR strFile, DATE nStartTime, DATE nEndTime, long nFileLen, long nFileType, long nSvrID, long nLocation, long nChannel)
{
	GPSFile_S* pNewFile  = new GPSFile_S;
	memset(pNewFile, 0, sizeof(GPSFile_S));
	COleDateTime DataB(nStartTime);
	COleDateTime DataE(nEndTime);
	pNewFile->nYear = DataB.GetYear();
	pNewFile->nDay = DataB.GetDay();
	pNewFile->nMonth = DataB.GetMonth();

	pNewFile->uiBegintime = DataB.GetHour()*3600+DataB.GetMinute()*60+DataB.GetSecond();
	pNewFile->uiEndtime = DataE.GetHour()*3600+DataE.GetMinute()*60+DataE.GetSecond();
	pNewFile->nFileLen = nFileLen;
	pNewFile->nChn = nChannel;

	pNewFile->nLocation = nLocation;
	pNewFile->nFileType = nFileType;
	pNewFile->nSvrID = nSvrID;

	strncpy(pNewFile->szDevIDNO, m_strSearchDevIDNO.GetBuffer(0), sizeof(pNewFile->szDevIDNO)-1);
	strncpy(pNewFile->szFile, strFile, sizeof(pNewFile->szFile));
	
	int nIndex = GetFileListIndex(pNewFile);
	m_lstSearch.InsertItem(nIndex, NULL);
	CString str;
	if (GPS_FILE_ATTRIBUTE_JPEG == m_cmbFileAttribute.GetItemData(m_cmbFileAttribute.GetCurSel()))
	{
		str = FormatSecond(pNewFile->uiBegintime);
	}
	else
	{
		str = FormatSecond(pNewFile->uiBegintime);
		str += " - ";
		str += FormatSecond(pNewFile->uiEndtime);
	}
	m_lstSearch.SetItemText(nIndex, 0, str);
	m_lstSearch.SetItemText(nIndex, 1, GetFileType(pNewFile->nFileType));

	CString strChn;
	CString strDev;
	CString strID;
//	GetDevAndChnName(pNewFile->szDevIDNO, pNewFile->nChn, strID, strDev, strChn);
	m_lstSearch.SetItemText(nIndex, 2, m_strSearchDevIDNO);
	
//	strChn = GetChannelName(pNewFile);
	strChn.Format("Channel-%d", pNewFile->nChn+1);
//	m_cmbSearchChannel.GetLBText(m_cmbSearchChannel.GetCurSel(), strChn);
	m_lstSearch.SetItemText(nIndex, 3, strChn);
	m_cmbLocation.GetLBText(m_cmbLocation.GetCurSel(), strChn);
	m_lstSearch.SetItemText(nIndex, 4, strChn);
	m_lstSearch.SetItemText(nIndex, 5, GetFileSize(pNewFile->nFileLen));
	m_lstSearch.SetItemText(nIndex, 6, pNewFile->szFile);
	m_lstSearch.SetItemData(nIndex, (DWORD)pNewFile);
}
void COCXDemoDlg::OnRecSearchMsgEvent(long nMsg, long nParam)
{
//	if (NULL != m_pFileSearch && NULL != m_pFileSearch->GetHandle())
	{
		switch(nMsg)
		{
		case 1://GPS_DOWNLOAD_MSG_FAILED:
			{
				AfxMessageBox("ʧ��");
			//	MSG_BOX_STR(LOADSTRINGEX(ID_STR_DLG_REC_SEARCH_FAILED) + GETErrorString(lParam));
			//	StopSearch();
			}
			break;
		case 3://GPS_DOWNLOAD_MSG_FINISHED:
			{
				AfxMessageBox("���");
			//	StopSearch();
			}
			break;
		}
	}
//	return 0;
}
#define GPS_DOWNLOAD_MSG_FAILED				1
#define GPS_DOWNLOAD_MSG_BEGIN				2
#define GPS_DOWNLOAD_MSG_FINISHED			3
#define GPS_DOWNLOAD_MSG_PROCESS			4

#define GPS_ERR_FILE_EXT_ERR			61	//�ļ���ʽ����
#define GPS_ERR_FILE_NO_EXIST			62	//�������ϲ����ڴ��ļ�
#define GPS_ERR_FILE_DOWN_OK			63	//�ļ���ȫ���������
#define GPS_ERR_FILE_DOWN_ING			64	//�ļ���������
#define GPS_ERR_FILE_EMPTY				65	//û��������¼���ļ�
#define GPS_ERR_FILE_USED				66	//�ļ����ڱ�ʹ��

void COCXDemoDlg::OnDownFileEvent(long nMsg, long nParam)
{
	switch(nMsg)
	{
	case GPS_DOWNLOAD_MSG_BEGIN:
		{
			
		}
		break;
	case GPS_DOWNLOAD_MSG_FAILED:
		{
			if (GPS_ERR_FILE_DOWN_OK == nParam)
			{
				TRACE("���سɹ�");
// 				DoDownFinished();
// 				StartDownNextFile();
			}
			else
			{
				AfxMessageBox("����ʧ��");
			}
		}
		break;
	case GPS_DOWNLOAD_MSG_FINISHED:
		{
			TRACE("���سɹ�");
// 			DoDownFinished();
// 			StartDownNextFile();
		}
		break;
	case GPS_DOWNLOAD_MSG_PROCESS:
		{
			double fPer = (nParam * 100.0) / m_nDownTotalLen;
			CString str;
			str.Format("%0.2f%%", fPer);
		//	m_lstDown.SetItemText(GetDownIndex(), DOWN_PROCESS_SUB_ITEM, str);
			TRACE("���ؽ��� %s\n", str);
		}
		break;
	default :
		ASSERT(FALSE);
	}
}

void COCXDemoDlg::OnRclickListFile(NMHDR* pNMHDR, LRESULT* pResult) 
{	
	// TODO: Add your control notification handler code here
	*pResult = 0;
	POSITION pos = m_lstSearch.GetFirstSelectedItemPosition();
	if (pos)
	{
		int index = m_lstSearch.GetNextSelectedItem(pos);
		GPSFile_S* pFile = (GPSFile_S*)m_lstSearch.GetItemData(index);
		if (3 == pFile->nLocation)
		{
			return;
		}
		
		CMenu menu;
		menu.LoadMenu(IDR_MENU_POP);
		
		CMenu* pPopup = menu.GetSubMenu(0);
		if (pPopup)
		{
			POINT pt;
			GetCursorPos(&pt);
			pPopup->TrackPopupMenu(TPM_RIGHTBUTTON, pt.x, pt.y, this);
		}
	}
}
void COCXDemoDlg::OnMenuRecsearchDown() 
{
	// TODO: Add your command handler code here
	POSITION pos = m_lstSearch.GetFirstSelectedItemPosition();
	while (pos)
	{
		int nIndex = m_lstSearch.GetNextSelectedItem(pos);
		GPSFile_S* pFile = (GPSFile_S*)m_lstSearch.GetItemData(nIndex);
		DATE dateB = 0;
		DATE dateE = 0;
		SecondToDate(pFile, dateB, dateE);
		SYSTEMTIME st;
		GetLocalTime(&st);
		CString strFile;
		strFile.Format("c:/%d%d%d%d%d%d.tmp", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);

		long nErr = m_OCX.StartDownFile(pFile->szDevIDNO, pFile->nChn, pFile->szFile, pFile->nFileLen,
			dateB, dateE, pFile->nLocation, pFile->nSvrID, pFile->nFileType, 
			m_cmbFileType.GetItemData(m_cmbFileType.GetCurSel()), strFile.GetBuffer(0));
		if (nErr == -1)
		{
			AfxMessageBox("ʧ��");
		}
		else if (nErr == -2)
		{
			AfxMessageBox("��������,��ֹͣ����");
		}
		else
		{
			m_nDownTotalLen = pFile->nFileLen;
		}
	}
}

void COCXDemoDlg::OnMenuRecsearchPlay() 
{
	// TODO: Add your command handler code here
	POSITION pos = m_lstSearch.GetFirstSelectedItemPosition();
	while (pos)
	{
		int nIndex = m_lstSearch.GetNextSelectedItem(pos);
		GPSFile_S* pFile = (GPSFile_S*)m_lstSearch.GetItemData(nIndex);
	//	PlayBackRecord(pFile, pFile->File.nChn, 0, FALSE);
		DATE dateB = 0;
		DATE dateE = 0;
		SecondToDate(pFile, dateB, dateE);
		m_OCX.StartPlaybackRec(pFile->szFile, dateB, dateE, pFile->szDevIDNO, pFile->nChn, pFile->nFileLen, pFile->nFileType, pFile->nLocation, pFile->nSvrID, 0, 0, FALSE);
	}
}
void COCXDemoDlg::SecondToDate(GPSFile_S* pFile, DATE& dateB, DATE& dateE)
{
	COleDateTime oleDateStart, oleDateEnd;
	DWORD dwH, dwM, dwS;
	dwH = pFile->uiBegintime/3600;
	dwM = (pFile->uiBegintime%3600)/60;
	dwS = pFile->uiBegintime%60;
	oleDateStart.SetDateTime(pFile->nYear, pFile->nMonth, pFile->nDay, dwH, dwM, dwS);
	dateB = oleDateStart.m_dt;
	dwH = pFile->uiEndtime/3600;
	dwM = (pFile->uiEndtime%3600)/60;
	dwS = pFile->uiEndtime%60;
	oleDateEnd.SetDateTime(pFile->nYear, pFile->nMonth, pFile->nDay, dwH, dwM, dwS);
	dateE = oleDateEnd.m_dt;
}

// int	GetGpsDirection(int nDirection)
// {
// 	return ((nDirection + 22) / 45 ) & 0x7;
// }
// 
// CString FormatGpsDirection(int nDirection)
// {
// 	CString str;
// 	switch( GetGpsDirection(nDirection) )
// 	{
// 	case 0:
// 		str = LOADSTRINGEX(ID_STR_NORTH);
// 		break;
// 	case 1:
// 		str = LOADSTRINGEX(ID_STR_NORTH_EAST);
// 		break;
// 	case 2:
// 		str = LOADSTRINGEX(ID_STR_EAST);
// 		break;
// 	case 3:
// 		str = LOADSTRINGEX(ID_STR_SOUTH_EAST);
// 		break;
// 	case 4:
// 		str = LOADSTRINGEX(ID_STR_SOUTH);
// 		break;
// 	case 5:
// 		str = LOADSTRINGEX(ID_STR_SOUTH_WEST);
// 		break;
// 	case 6:
// 		str = LOADSTRINGEX(ID_STR_WEST);
// 		break;
// 	case 7:
// 		str = LOADSTRINGEX(ID_STR_NORTH_WEST);
// 		break;
// 	default:
// 		break;
// 	}
// 	return str;
// }

//�ַ����ָ�
typedef std::vector<CString> vecString;
void ParseString(LPCTSTR szSrc, TCHAR cSplit, vecString& vecStr)
{
	const TCHAR* pTemp = szSrc;
	TCHAR* pFind = (TCHAR*)_tcschr(szSrc, cSplit);
	while(pFind != NULL)
	{
		CString str(pTemp, pFind - pTemp);
		vecStr.push_back(str);
		pTemp = pFind + 1;
		pFind = (TCHAR*)_tcschr(pTemp, cSplit);
	}
	if (*pTemp != '\0')
	{
		CString str = pTemp;
		vecStr.push_back(str);
	}
}

void COCXDemoDlg::OnGpsStateEvent(BSTR devIDNO, DATE gpsTime, long speed, long youLiang, long huangXiang
								  , long status1, long status2, long status3, long status4
								  , long jingDu, long weiDu, long parkTime, BSTR reserve)
{
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
	//16λδʹ��
	//17λ��ʾ���������Ѿ�����		1��ʾ����
	//18λ��ʾ���������Ѿ�����90%����	1��ʾ����
	//19λ��ʾ���������Ѿ�����		1��ʾ����
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
	
// 	typedef struct _tagGPSVehicleGps
// 	{
// 		GPSTime_S Time;
// 		unsigned int uiSpeed:14;	//�ٶ�ֵ KM/S	9999 = 999.9 	��Χ(0-16384)
// 		unsigned int uiYouLiang:18;	//����   ��	9999 = 99.99 	��Χ(0-262100)
// 		unsigned int uiLiCheng;		//���   ����	9999 = 9.999 	
// 		unsigned int uiHangXiang:9;	//���溽��(0-360) ��Χ(0-512)
// 		unsigned int uiMapType:3;	//��ͼ����		1��ʾGOOGLE��2��ʾ�ٶȣ�0��ʾ��Ч
// 		unsigned int uiReserve:20;  //����λ
// 		unsigned int uiStatus[4];		//Ŀǰֻʹ�ã�ÿ1��״̬	0λ��ʾGPS��λ״̬��0��Ч��1��Ч��
// 		short sTempSensor[4];	//�¶ȴ�������״̬
// 		int	nJingDu;		//����	4�ֽ� ��������	9999999 = 9.999999 
// 		int nWeiDu;			//γ��	4�ֽ� ��������	9999999 = 9.999999
// 		int	nGaoDu;			//�߶ȣ���ʱδʹ��
// 		int	nParkTime;		//ͣ��ʱ�� ��	�ھ�ֹ״̬ʱ��Ч
// 		int	nMapJingDu;		//ͨ����ͼģ���ȡ�ľ��Ⱥ�γ��
// 		int	nMapWeiDu;		//ͨ����ͼģ���ȡ�ľ��Ⱥ�γ��
// 		int	nReserve[2];		//��������
// 	}GPSVehicleGps_S;

	COleDateTime dt(gpsTime);

	CString str;
	str.Format(" devIdno:%s, time:%04d%02d%02d %02d:%02d:%02d gps:%d,%d", devIDNO
		, dt.GetYear(), dt.GetMonth(), dt.GetDay(), dt.GetHour(), dt.GetMinute(), dt.GetSecond()
		, jingDu, weiDu);
	GetDlgItem(IDC_ST_GPS)->SetWindowText(str);
//	CString str;
//	str.Format("%d,%d",jingDu,weiDu);
//	AfxMessageBox(str);
}

void COCXDemoDlg::OnGpsStateEventEx(LPCTSTR szDevIDNO, LPCTSTR lpGPSInfo)
{
	TRACE("GPS��Ϣ------IDNO[%s]\n", szDevIDNO);
	TRACE("GPS��Ϣ[%s]\n", lpGPSInfo);
}

//������Ϣ��ʽ
//GPSʱ��,�ٶ�,����,���,����,��ͼ����,����,״̬1,״̬2,״̬3,״̬4,�¶ȴ�����1��״̬,�¶ȴ�����2��״̬,�¶ȴ�����3��״̬,�¶ȴ�����4��״̬
//����,γ��,�߶�,ͣ��ʱ��,ͨ����ͼģ���ȡ�ľ���,ͨ����ͼģ���ȡ��γ��,��������1,��������2
//GPS��Ϣ��ʽ
//guid,����ʱ��,��������,������Ϣ,��������1,��������2,��������3,��������4,��������,Դ��������,��������,Դ����ʱ��,ͼƬ�ļ���Ϣ,szReserve
void COCXDemoDlg::OnDevAlarmEvent(LPCTSTR szDevIDNO, LPCTSTR lpAlarmInfo, LPCTSTR lpGPSInfo)
{
	TRACE("������Ϣ------IDNO[%s]\n", szDevIDNO);
	TRACE("������Ϣ[%s]\n", lpAlarmInfo);
	TRACE("GPS��Ϣ[%s]\n", lpGPSInfo);

	//1.�ָ��ַ���
	vecString vecStr;
	ParseString(lpAlarmInfo, ',', vecStr);

	//2.���ַ���ת����GPSAlarmInfo_S�ṹ��
	GPSAlarmInfo_S ArmInfo = {0};
	//do something

	//3.����������Ϣ
	CString strType, strDesc;
	FormatAlarm2String(ArmInfo, strType, strDesc);
	
}

void COCXDemoDlg::OnBtnGps()
{
	if (!m_bSubscribeGps)
	{
		if (!UpdateData())
		{
			return ;
		}

		CString str;
		GetDlgItem(IDC_ED_GPSDEV)->GetWindowText(str);
		str.TrimLeft(); str.TrimRight();
		if (str.IsEmpty())
		{
			AfxMessageBox("�豸��Ų���Ϊ��");
			return ;
		}

		m_OCX.StartSubscribeGps(str);
		m_OCX.StartSubscribeAlarm(str);
		m_bSubscribeGps = TRUE;
		GetDlgItem(IDC_BTN_GPS)->SetWindowText("ֹͣ����");
	}
	else
	{
		m_OCX.StopSubscribeGps();
		m_OCX.StopSubscribeAlarm();
		m_bSubscribeGps = FALSE;
		GetDlgItem(IDC_BTN_GPS)->SetWindowText("����GPS�ͱ�����Ϣ");
	}
}

void COCXDemoDlg::OnChangeEdServer() 
{
	UpdateData(TRUE);	

	m_OCX.SetServerIP(m_strIP);
	m_OCX.SetServerPort(atoi(m_strPort));

}

void COCXDemoDlg::OnBtnOnline()
{
	UpdateData(TRUE);
	if (!m_strDevIDNO.IsEmpty())
	{
		if (0 == m_OCX.CheckOnline(m_strDevIDNO))
		{
			AfxMessageBox("Online");
		}
		else
		{
			AfxMessageBox("Offline");
		}
	}
}


void COCXDemoDlg::OnSnapshotDevEvent(LPCTSTR strDevIDNO, long nChannel, LPCTSTR strFilePath, long nError)
{
	CString str;
	if (nError == 0)
	{
		str.Format("snapshot success! %s-%d-%s", strDevIDNO, nChannel+1, strFilePath);
	}
	else
	{
		str.Format("snapshot falied! %s-%d-%d", strDevIDNO, nChannel+1, nError);
	}
	AfxMessageBox(str);
}


void COCXDemoDlg::OnGet3GInfo()
{
	UpdateData(TRUE);
	if(m_strDevIDNO.IsEmpty())
	{
		AfxMessageBox("please input device IDNO.");
	}
	else
	{
		m_OCX.GetDevNetFlowStatistics(m_strDevIDNO);
	}
}

void COCXDemoDlg::OnSet3GInfo()
{
	UpdateData(TRUE);
	if(m_strDevIDNO.IsEmpty())
	{
		AfxMessageBox("please input device IDNO.");
	}
	else
	{
		float fFlowUsedToday = 10.1;
		float fFlowUsedMonth = 100.2;
		long nIsOpenFlowCount = 1;
		long nIsOpenDayFlowRemind = 1;
		long nIsOpenMonthFlwRemind = 1;
		float fDayLimit = 20.3;
		float fMonthLimit = 200.4;
		long nDayRemind = 15;
		long nMonthRemind = 150;
		long nMonthTotleDay = 25;
		m_OCX.SetDevNetFlowStatistics(m_strDevIDNO, fFlowUsedToday, fFlowUsedMonth,
			nIsOpenFlowCount, nIsOpenDayFlowRemind, nIsOpenMonthFlwRemind,
			fDayLimit, fMonthLimit, nDayRemind, nMonthRemind, nMonthTotleDay);
	}
}

void COCXDemoDlg::OnGetDevNetFlowStatisticsEvent(LPCTSTR szDevIDNO, long nResult, float fFlowUsedToday
												 , float fFlowUsedMonth, long nStatisticsTime
												 , long nIsOpenFlowCount, long nIsOpenDayFlowRemind
												 , long nIsOpenMonthFlwRemind, float fDayLimit
												 , float fMonthLimit, long nDayRemind
												 , long nMonthRemind, long nMonthTotleDay)
{
	TRACE("�豸IDNO:%s \n", szDevIDNO);
	TRACE("���:%d \n", nResult);	// 0�ɹ�,����ʧ��
	if (nResult == 0)
	{
		TRACE("��������:%f \n", fFlowUsedToday);
		TRACE("������ʹ������:%f \n", fFlowUsedMonth);
		TRACE("ͳ��ʱ��:%d \n", nStatisticsTime);
		TRACE("����ͳ�ƿ��� 0-�رգ�1-����:%d \n", nIsOpenFlowCount);
		TRACE("���������� 0-������ 1-����:%d \n", nIsOpenDayFlowRemind);
		TRACE("���������� 0-������ 1-����:%d \n", nIsOpenMonthFlwRemind);
		TRACE("����������(MB):%f \n", fDayLimit);
		TRACE("����������(MB):%f", fMonthLimit);
		TRACE("ÿ���������ѣ��ٷֱȣ���20%��20:%d \n", nDayRemind);
		TRACE("ÿ���������ѣ��ٷֱȣ���20%��20:%d \n", nMonthRemind);
		TRACE("�½���:%d", nMonthTotleDay);
	}
}
void COCXDemoDlg::OnSetDevNetFlowStatisticsEvent(LPCTSTR szDevIDNO, long nResult)
{
	TRACE("�豸IDNO:%s \n", szDevIDNO);
	TRACE("���:%d \n", nResult);	// 0�ɹ�,����ʧ��
}


void COCXDemoDlg::OnBroadcast()
{
	if (!m_bBroadcast)
	{
		if (!UpdateData())
		{
			return ;
		}
		
		CString str;
		GetDlgItem(IDC_ED_GPSDEV_BROADCAST)->GetWindowText(str);
		str.TrimLeft(); str.TrimRight();
		if (str.IsEmpty())
		{
			AfxMessageBox("�豸��Ų���Ϊ��");
			return ;
		}
		
		m_OCX.StartVoiceBroadcast(str);
		m_bBroadcast = TRUE;
		GetDlgItem(IDC_BTN_BROADCAST)->SetWindowText("ֹͣ�㲥");
	}
	else
	{
		m_OCX.StopVoiceBroadcast();
		m_bBroadcast = FALSE;
		GetDlgItem(IDC_BTN_BROADCAST)->SetWindowText("��ʼ�㲥");
	}
}