// FtModifierDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FtModifier.h"
#include "FtModifierDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog {
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

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD) {
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX) {
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
// CFtModifierDlg dialog

CFtModifierDlg::CFtModifierDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFtModifierDlg::IDD, pParent) {
	//{{AFX_DATA_INIT(CFtModifierDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFtModifierDlg::DoDataExchange(CDataExchange* pDX) {
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFtModifierDlg)
	DDX_Control(pDX, IDC_EDITFILE, m_TextFile);
	DDX_Control(pDX, IDC_TOTAL_FILE_NUMBER, m_TotalFileNumber);
	DDX_Control(pDX, IDC_GROUP_FILE_ACTION, m_groupFileAction);
	DDX_Control(pDX, IDC_ACTION_PROMPT, m_lblActionPrompt);
	DDX_Control(pDX, IDC_RADIO_CREATION, m_radioCreation);
	DDX_Control(pDX, IDC_RADIO_LAST_WRITE, m_radioLastWrite);
	DDX_Control(pDX, IDC_RADIO_LAST_ACCESS, m_radioLastAccess);
	DDX_Control(pDX, IDC_CREATION_TIME, m_lblCreationTime);
	DDX_Control(pDX, IDC_LAST_WRITE_TIME, m_lblLastWriteTime);
	DDX_Control(pDX, IDC_LAST_ACCESS_TIME, m_lblLastAccessTime);
	DDX_Control(pDX, IDC_GROUP_TIME_EDITOR, m_groupTimeEditor);
	DDX_Control(pDX, IDC_RADIOFIXED, m_radioDateFixed);
	DDX_Control(pDX, IDC_RADIORANDOM, m_radioDateRandom);
	DDX_Control(pDX, IDC_DATEFIXED, m_DateFixed);
	DDX_Control(pDX, IDC_TIMEFIXED, m_TimeFixed);
	DDX_Control(pDX, IDC_TIMEFROM_PROMPT, m_lblTimeFromPrompt);
	DDX_Control(pDX, IDC_TIMETO_PROMPT, m_lblTimeToPrompt);
	DDX_Control(pDX, IDC_DATEFROM, m_DateFrom);
	DDX_Control(pDX, IDC_DATETO, m_DateTo);
	DDX_Control(pDX, IDC_TIMEFROM, m_TimeFrom);
	DDX_Control(pDX, IDC_TIMETO, m_TimeTo);
	DDX_Control(pDX, IDOK, m_btnOk);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFtModifierDlg, CDialog)
	//{{AFX_MSG_MAP(CFtModifierDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTONFILE, OnButtonFile)
	ON_BN_CLICKED(IDC_BUTTONDIR, OnButtonDir)
	ON_BN_CLICKED(IDC_RADIO_CREATION, OnRadioCreation)
	ON_BN_CLICKED(IDC_RADIO_LAST_WRITE, OnRadioLastWrite)
	ON_BN_CLICKED(IDC_RADIO_LAST_ACCESS, OnRadioLastAccess)
	ON_BN_CLICKED(IDC_RADIOFIXED, OnRadioFixed)
	ON_BN_CLICKED(IDC_RADIORANDOM, OnRadioRandom)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFtModifierDlg message handlers

BOOL CFtModifierDlg::OnInitDialog() {
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
	
	// Disable the file action panel
	m_groupFileAction.EnableWindow(FALSE);

	// Not to show file times
	m_lblCreationTime.ShowWindow(FALSE);
	m_lblLastWriteTime.ShowWindow(FALSE);
	m_lblLastAccessTime.ShowWindow(FALSE);

	// Default to checking the fixed date
	m_radioDateFixed.SetCheck(BST_CHECKED);

	// Set the display format of DateTime Controls
	m_DateFixed.SendMessage(DTM_SETFORMAT, 0, (LPARAM)_T("yyyy-MM-dd"));
	m_DateFrom.SendMessage(DTM_SETFORMAT, 0, (LPARAM)_T("yyyy-MM-dd"));
	m_DateTo.SendMessage(DTM_SETFORMAT, 0, (LPARAM)_T("yyyy-MM-dd"));
	m_TimeFixed.SendMessage(DTM_SETFORMAT, 0, (LPARAM)_T("HH:mm:ss"));
	m_TimeFrom.SendMessage(DTM_SETFORMAT, 0, (LPARAM)_T("HH:mm:ss"));
	m_TimeTo.SendMessage(DTM_SETFORMAT, 0, (LPARAM)_T("HH:mm:ss"));
	
	m_FileDlg=new CFileDialog(
		TRUE,NULL,NULL,OFN_ALLOWMULTISELECT|OFN_EXPLORER);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFtModifierDlg::OnSysCommand(UINT nID, LPARAM lParam) {
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
void CFtModifierDlg::OnPaint() {
	// Enable all only when at least one file selected
	m_groupFileAction.EnableWindow(m_fileCount > 0);
	m_lblActionPrompt.EnableWindow(m_groupFileAction.IsWindowEnabled());
	m_radioCreation.EnableWindow(m_groupFileAction.IsWindowEnabled());
	m_radioLastWrite.EnableWindow(m_groupFileAction.IsWindowEnabled());
	m_radioLastAccess.EnableWindow(m_groupFileAction.IsWindowEnabled());

	// Show file times only when there is a single file selected
	m_lblCreationTime.ShowWindow(m_fileCount == 1);
	m_lblLastWriteTime.ShowWindow(m_fileCount == 1);
	m_lblLastAccessTime.ShowWindow(m_fileCount == 1);

	// Enable time editor 
	m_groupTimeEditor.EnableWindow(m_fileCount > 0 && (m_radioCreation.GetCheck() == BST_CHECKED || m_radioLastWrite.GetCheck() == BST_CHECKED || m_radioLastAccess.GetCheck() == BST_CHECKED));
	// Enable the fixed date time
	m_radioDateFixed.EnableWindow(m_fileCount > 0 && m_groupTimeEditor.IsWindowEnabled());
	m_radioDateRandom.EnableWindow(m_fileCount > 0 && m_groupTimeEditor.IsWindowEnabled());
	m_DateFixed.EnableWindow(m_groupTimeEditor.IsWindowEnabled() && m_radioDateFixed.GetCheck() == BST_CHECKED);
	m_TimeFixed.EnableWindow(m_groupTimeEditor.IsWindowEnabled() && m_radioDateFixed.GetCheck() == BST_CHECKED);
	// Enable the random date time
	m_lblTimeFromPrompt.EnableWindow(m_groupTimeEditor.IsWindowEnabled() && m_radioDateRandom.GetCheck() == BST_CHECKED);
	m_lblTimeToPrompt.EnableWindow(m_groupTimeEditor.IsWindowEnabled() && m_radioDateRandom.GetCheck() == BST_CHECKED);
	m_DateFrom.EnableWindow(m_groupTimeEditor.IsWindowEnabled() && m_radioDateRandom.GetCheck() == BST_CHECKED);
	m_TimeFrom.EnableWindow(m_groupTimeEditor.IsWindowEnabled() && m_radioDateRandom.GetCheck() == BST_CHECKED);
	m_DateTo.EnableWindow(m_groupTimeEditor.IsWindowEnabled() && m_radioDateRandom.GetCheck() == BST_CHECKED);
	m_TimeTo.EnableWindow(m_groupTimeEditor.IsWindowEnabled() && m_radioDateRandom.GetCheck() == BST_CHECKED);
	m_btnOk.EnableWindow(m_groupTimeEditor.IsWindowEnabled());

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
HCURSOR CFtModifierDlg::OnQueryDragIcon() {
	return (HCURSOR) m_hIcon;
}

void CFtModifierDlg::OnButtonDir() {
	BROWSEINFOA bInfo;
	LPITEMIDLIST lpItemList;
	bInfo.hwndOwner=this->m_hWnd;
	bInfo.pidlRoot=NULL;
	bInfo.lpszTitle="请选择要修改时间的目录：";
	char disName[MAX_PATH];
	bInfo.pszDisplayName=disName;
	bInfo.lpfn=NULL;
	bInfo.ulFlags=0;
	lpItemList=SHBrowseForFolder(&bInfo);
	char lpPath[MAX_PATH];
	SHGetPathFromIDList(lpItemList,lpPath);
	m_TextFile.SetWindowText(lpPath);
	// TODO: not implemented yet
}

void CFtModifierDlg::OnButtonFile() {
	if(m_FileDlg->DoModal()==IDOK)
	{
		CString str_FilePath = m_FileDlg->GetPathName();
		this->m_TextFile.SetWindowText(str_FilePath);
		POSITION ps = m_FileDlg->GetStartPosition();
		m_fileCount = 0;
		while(ps)
		{
			m_fileCount++;
			CString strFile = m_FileDlg->GetNextPathName(ps);
			HANDLE hFile = CreateFile(strFile, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
			FILETIME ftCreation, ftLastAccess, ftLastWrite;
			GetFileTime(hFile, &ftCreation, &ftLastAccess, &ftLastWrite);

			showFileTimes(ftCreation, ftLastAccess, ftLastWrite);

			CloseHandle(hFile);
		}
		CString fileNumbers;
		fileNumbers.Format(_T("选择了 %d 个文件"), m_fileCount);
		m_TotalFileNumber.SetWindowText(fileNumbers);
		RedrawWindow();
	}	
}

void CFtModifierDlg::OnRadioCreation() 
{
	if (m_fileCount == 1) {
		setDefaultValueOfTimeEditor();
	}
	RedrawWindow();
}

void CFtModifierDlg::OnRadioLastWrite() 
{
	if (m_fileCount == 1) {
		setDefaultValueOfTimeEditor();
	}
	RedrawWindow();
}

void CFtModifierDlg::OnRadioLastAccess() 
{
	if (m_fileCount == 1) {
		setDefaultValueOfTimeEditor();
	}
	RedrawWindow();
}

void CFtModifierDlg::OnRadioRandom() {
	RedrawWindow();
}

void CFtModifierDlg::OnRadioFixed() {
	RedrawWindow();
}

void CFtModifierDlg::OnOK() {
	// Declare the new edited value, which will be saved into file
	FILETIME localFileTime;

	// Fixed date time will be global, meaning it will apply to all files
	if(this->m_radioDateFixed.GetCheck() == BST_CHECKED)
	{
		// Get the input
		SYSTEMTIME localSysTime = getCombinedDateTime(&m_DateFixed, &m_TimeFixed);
		// Convert to local FILETIME
		SystemTimeToFileTime(&localSysTime, &localFileTime);
	}

	// Random date time range should be verified and prepared first, later will generate a random value for each file
	FILETIME localFtRandomFrom, localFtRandomTo;
	if(this->m_radioDateRandom.GetCheck() == BST_CHECKED)
	{
		// Get the input of the range
		SYSTEMTIME localFromTime = getCombinedDateTime(&m_DateFrom, &m_TimeFrom);
		SYSTEMTIME localToTime = getCombinedDateTime(&m_DateTo, &m_TimeTo);
		// Convert them to local FILETIME
		SystemTimeToFileTime(&localFromTime, &localFtRandomFrom);
		SystemTimeToFileTime(&localToTime, &localFtRandomTo);
		if (CompareFileTime(&localFtRandomFrom, &localFtRandomTo) >= 0) {
			AfxMessageBox(_T("开始时间必须早于结束时间！"));
			return;
		}
	}

	POSITION ps;
	ps=m_FileDlg->GetStartPosition();
	while(ps)
	{
		// Random date time should be generated for each file respectively
		if(this->m_radioDateRandom.GetCheck() == BST_CHECKED)
		{
			// Get a random FILETIME between the start and end times
			localFileTime = generateRandomFileTime(localFtRandomFrom, localFtRandomTo);
		}

		CString strFile;
		strFile=m_FileDlg->GetNextPathName(ps);
		HANDLE hFile = CreateFile(strFile, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		FILETIME ftCreation, ftLastAccess, ftLastWrite;
		GetFileTime(hFile, &ftCreation, &ftLastAccess, &ftLastWrite);
		// Convert to utc FILETIME
		if (m_radioCreation.GetCheck() == BST_CHECKED) {
			LocalFileTimeToFileTime(&localFileTime, &ftCreation);
		}
		if (m_radioLastWrite.GetCheck() == BST_CHECKED) {
			LocalFileTimeToFileTime(&localFileTime, &ftLastWrite);
		}
		if (m_radioLastAccess.GetCheck() == BST_CHECKED) {
			LocalFileTimeToFileTime(&localFileTime, &ftLastAccess);
		}
		// Set the utc FILETIME into file
		SetFileTime(hFile, &ftCreation, &ftLastAccess, &ftLastWrite);
		CloseHandle(hFile);
	}
	AfxMessageBox(_T("文件时间已经成功修改。"));
	showFileTimes(); // Refresh file time details
}

/**
 * Show the first file's time details.
 */
void CFtModifierDlg::showFileTimes() {
	POSITION ps = m_FileDlg->GetStartPosition();
	CString strFile = m_FileDlg->GetNextPathName(ps);
	HANDLE hFile = CreateFile(strFile, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	FILETIME ftCreation, ftLastAccess, ftLastWrite;
	GetFileTime(hFile, &ftCreation, &ftLastAccess, &ftLastWrite);
	showFileTimes(ftCreation, ftLastAccess, ftLastWrite);
	CloseHandle(hFile);
}

void CFtModifierDlg::showFileTimes(FILETIME ftCreation, FILETIME ftLastAccess, FILETIME ftLastWrite) {
	CString creationTime = getFormattedDateTimeString(ftCreation);
	CString lastWriteTime = getFormattedDateTimeString(ftLastWrite);
	CString lastAccessTime = getFormattedDateTimeString(ftLastAccess);
	m_lblCreationTime.SetWindowText(creationTime);
	m_lblLastWriteTime.SetWindowText(lastWriteTime);
	m_lblLastAccessTime.SetWindowText(lastAccessTime);

	setDefaultValueOfTimeEditor(ftCreation, ftLastAccess, ftLastWrite);
}

/**
 * Format a FILETIME to local time, in format of "2024-05-25 12:03:35"
 */
CString CFtModifierDlg::getFormattedDateTimeString(const FILETIME& fileTime) {
    SYSTEMTIME utcSystemTime, localSystemTime;
	if (!FileTimeToSystemTime(&fileTime, &utcSystemTime)) {
		return _T("Error converting time");
	}

	SystemTimeToTzSpecificLocalTime(NULL, &utcSystemTime, &localSystemTime);
	CString formattedDateTime;
	formattedDateTime.Format(
		_T("%04d-%02d-%02d %02d:%02d:%02d"),
		localSystemTime.wYear,
		localSystemTime.wMonth,
		localSystemTime.wDay,
		localSystemTime.wHour,
		localSystemTime.wMinute,
		localSystemTime.wSecond
	);

	return formattedDateTime;
}

/**
 * Get the first file's time details and show default value in the time editor
 */
void CFtModifierDlg::setDefaultValueOfTimeEditor() {
	POSITION ps;
	ps=m_FileDlg->GetStartPosition();
	CString strFile;
	strFile=m_FileDlg->GetNextPathName(ps);
	HANDLE hFile = CreateFile(strFile, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	FILETIME ftCreation, ftLastAccess, ftLastWrite;
	GetFileTime(hFile, &ftCreation, &ftLastAccess, &ftLastWrite);
	setDefaultValueOfTimeEditor(ftCreation, ftLastAccess, ftLastWrite);
	CloseHandle(hFile);
}

void CFtModifierDlg::setDefaultValueOfTimeEditor(FILETIME ftCreation, FILETIME ftLastAccess, FILETIME ftLastWrite) {
	if (m_radioCreation.GetCheck() == BST_UNCHECKED && m_radioLastWrite.GetCheck() == BST_UNCHECKED && m_radioLastAccess.GetCheck() == BST_UNCHECKED) {
		return;
	}
	// Set the default value of the time editor
	SYSTEMTIME utcTimeDefault, localTimeDefault;
	if (m_radioCreation.GetCheck() == BST_CHECKED) {
		FileTimeToSystemTime(&ftCreation, &utcTimeDefault);
	}
	if (m_radioLastWrite.GetCheck() == BST_CHECKED) {
		FileTimeToSystemTime(&ftLastWrite, &utcTimeDefault);
	}
	if (m_radioLastAccess.GetCheck() == BST_CHECKED) {
		FileTimeToSystemTime(&ftLastAccess, &utcTimeDefault);
	}

	SystemTimeToTzSpecificLocalTime(NULL, &utcTimeDefault, &localTimeDefault);

	m_DateFixed.SetTime(&localTimeDefault);
	m_TimeFixed.SetTime(&localTimeDefault);
	m_DateFrom.SetTime(&localTimeDefault);
	m_TimeFrom.SetTime(&localTimeDefault);
	m_DateTo.SetTime(&localTimeDefault);
	m_TimeTo.SetTime(&localTimeDefault);
}

/**
 * Get the local SYSTEMTIME combined from two DateTime Controls
 */
SYSTEMTIME CFtModifierDlg::getCombinedDateTime(CDateTimeCtrl* pDateCtrl, CDateTimeCtrl* pTimeCtrl) {
	SYSTEMTIME date, time, localCombined;
	pDateCtrl->GetTime(&date);
	pTimeCtrl->GetTime(&time);
	localCombined.wYear = date.wYear;
	localCombined.wMonth = date.wMonth;
	localCombined.wDay = date.wDay;
	localCombined.wHour = time.wHour;
	localCombined.wMinute = time.wMinute;
	localCombined.wSecond = time.wSecond;
	localCombined.wMilliseconds = time.wMilliseconds;
	return localCombined;
}

/**
 * Generate a random time between the range.
 * The caller should ensure that ftRandomFrom is earlier than the ftRandomTo.
 * If the ftRandomFrom is not earlier than the ftRandomTo, the function will return the ftRandomFrom.
 */
FILETIME CFtModifierDlg::generateRandomFileTime(const FILETIME& ftRandomFrom, const FILETIME& ftRandomTo) {
	if (CompareFileTime(&ftRandomFrom, &ftRandomTo) >= 0) {
		return ftRandomFrom;
	}
	// Generate random date time
	// Convert FILETIME to ULONGLONG
	ULARGE_INTEGER startTime, endTime;
	startTime.LowPart = ftRandomFrom.dwLowDateTime;
	startTime.HighPart = ftRandomFrom.dwHighDateTime;
	endTime.LowPart = ftRandomTo.dwLowDateTime;
	endTime.HighPart = ftRandomTo.dwHighDateTime;

	// Generate a random ULONGLONG between start and end
	ULONGLONG range = endTime.QuadPart - startTime.QuadPart + 1;  // Range size

	// Split the range into high and low parts to avoid conversion issues
	DWORD lowPart = (DWORD)(range & 0xFFFFFFFF);     // Lower 32 bits
	DWORD highPart = (DWORD)((range >> 32) & 0xFFFFFFFF);  // Upper 32 bits

	// Generate random high and low parts
	DWORD randomLow = rand() % (lowPart + 1);
	DWORD randomHigh = rand() % (highPart + 1);

	// Combine the high and low parts to get a random 64-bit number
	ULARGE_INTEGER randomValue;
	randomValue.LowPart = randomLow;
	randomValue.HighPart = randomHigh;

	ULONGLONG randomTime = startTime.QuadPart + randomValue.QuadPart;

	// Convert ULONGLONG back to FILETIME
	ULARGE_INTEGER randomFileTimeInt;
	randomFileTimeInt.QuadPart = randomTime;

	FILETIME ftRandom;
	ftRandom.dwLowDateTime = randomFileTimeInt.LowPart;
	ftRandom.dwHighDateTime = randomFileTimeInt.HighPart;
	return ftRandom;
}

CFtModifierDlg::~CFtModifierDlg() {
	delete m_FileDlg;
}
