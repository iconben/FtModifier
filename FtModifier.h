// FtModifier.h : main header file for the FTMODIFIER application
//

#if !defined(AFX_FTMODIFIER_H__A28097DD_8532_443F_B0C5_439955109D29__INCLUDED_)
#define AFX_FTMODIFIER_H__A28097DD_8532_443F_B0C5_439955109D29__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFtModifierApp:
// See FtModifier.cpp for the implementation of this class
//

class CFtModifierApp : public CWinApp {
public:
	CFtModifierApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFtModifierApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFtModifierApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FTMODIFIER_H__A28097DD_8532_443F_B0C5_439955109D29__INCLUDED_)
