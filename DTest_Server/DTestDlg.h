// DTestDlg.h : header file
//

#if !defined(AFX_DTESTDLG_H__06FFFA11_B8D9_4425_9C02_0E6BF00AA194__INCLUDED_)
#define AFX_DTESTDLG_H__06FFFA11_B8D9_4425_9C02_0E6BF00AA194__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef CDATABASE
#define CDATABASE
#include "afxdb.h"
#endif

#include "QuestionSet.h"
/////////////////////////////////////////////////////////////////////////////
// CDTestDlg dialog

class CDTestDlg : public CDialog
{
// Construction
public:
	BOOL InitData();
	BOOL InitQuestion();
	CDTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDTestDlg)
	enum { IDD = IDD_DTEST_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnNext();
	afx_msg void OnPre();
	afx_msg void OnQuit();
	afx_msg void OnDel();
	afx_msg void OnNew();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
        CDatabase database;
        CQuestionSet questionSet;
        int currentQuestion;
        int totalQuestion;
        int score;
        int *answer;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DTESTDLG_H__06FFFA11_B8D9_4425_9C02_0E6BF00AA194__INCLUDED_)
