// DTest.h : main header file for the DTEST application
//

#if !defined(AFX_DTEST_H__FDFF1D79_39CE_4F18_AF43_A00E060B9DAB__INCLUDED_)
#define AFX_DTEST_H__FDFF1D79_39CE_4F18_AF43_A00E060B9DAB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDTestApp:
// See DTest.cpp for the implementation of this class
//

class CDTestApp : public CWinApp
{
public:
	CDTestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDTestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDTestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DTEST_H__FDFF1D79_39CE_4F18_AF43_A00E060B9DAB__INCLUDED_)
