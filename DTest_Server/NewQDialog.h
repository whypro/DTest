#if !defined(AFX_NEWQDIALOG_H__9A682F94_621C_477E_880E_ACCACFABC172__INCLUDED_)
#define AFX_NEWQDIALOG_H__9A682F94_621C_477E_880E_ACCACFABC172__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewQDialog.h : header file
//
#ifndef CDATABASE
#define CDATABASE
#include "afxdb.h"
#endif

#include "QuestionSet.h"
/////////////////////////////////////////////////////////////////////////////
// CNewQDialog dialog

class CNewQDialog : public CDialog
{
// Construction
public:
	BOOL OnInitDialog();
	CNewQDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNewQDialog)
	enum { IDD = IDD_NEWQ_DIALOG };
	CString	m_title;
	int		m_rightChoice;
	CString	m_answerA;
	CString	m_answerB;
	CString	m_answerC;
	CString	m_answerD;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewQDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewQDialog)
	afx_msg void OnNq();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
        CDatabase database;
        CQuestionSet questionSet;        
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWQDIALOG_H__9A682F94_621C_477E_880E_ACCACFABC172__INCLUDED_)
