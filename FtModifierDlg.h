// FtModifierDlg.h : header file
//

#if !defined(AFX_FTMODIFIERDLG_H__5CD46EA8_1FAA_4054_9391_D55203C927AB__INCLUDED_)
#define AFX_FTMODIFIERDLG_H__5CD46EA8_1FAA_4054_9391_D55203C927AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFtModifierDlg dialog

class CFtModifierDlg : public CDialog {
// Construction
public:
	~CFtModifierDlg();
	CFtModifierDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFtModifierDlg)
	enum { IDD = IDD_FTMODIFIER_DIALOG };
	CEdit	m_TextFile;
	CStatic   m_TotalFileNumber;
	CStatic m_groupFileAction;
	CStatic   m_lblActionPrompt;
	CButton	m_radioLastWrite;
	CButton	m_radioLastAccess;
	CButton	m_radioCreation;
	CButton m_radioDateFixed;
	CButton m_radioDateRandom;
	CStatic m_lblCreationTime;
	CStatic m_lblLastWriteTime;
	CStatic m_lblLastAccessTime;
	CStatic m_groupTimeEditor;
	CDateTimeCtrl	m_DateFixed;
	CDateTimeCtrl	m_TimeFixed;
	CStatic	m_lblTimeFromPrompt;
	CStatic	m_lblTimeToPrompt;
	CDateTimeCtrl	m_DateFrom;
	CDateTimeCtrl	m_TimeFrom;
	CDateTimeCtrl	m_DateTo;
	CDateTimeCtrl	m_TimeTo;
	CButton m_btnOk;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFtModifierDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFtModifierDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnButtonFile();
	afx_msg void OnButtonDir();
	afx_msg void OnRadioCreation();
	afx_msg void OnRadioLastWrite();
	afx_msg void OnRadioLastAccess();
	afx_msg void OnRadioFixed();
	afx_msg void OnRadioRandom();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CFileDialog *m_FileDlg;
	int m_fileCount;
	void showFileTimes();
	void showFileTimes(FILETIME ftCreation, FILETIME ftLastAccess, FILETIME ftLastWrite);
	CString getFormattedDateTimeString(const FILETIME& fileTime);
	void setDefaultValueOfTimeEditor();
	void setDefaultValueOfTimeEditor(FILETIME ftCreation, FILETIME ftLastAccess, FILETIME ftLastWrite);
	SYSTEMTIME getCombinedDateTime(CDateTimeCtrl* pDateCtrl, CDateTimeCtrl* pTimeCtrl);
	FILETIME generateRandomFileTime(const FILETIME&, const FILETIME&);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FTMODIFIERDLG_H__5CD46EA8_1FAA_4054_9391_D55203C927AB__INCLUDED_)
