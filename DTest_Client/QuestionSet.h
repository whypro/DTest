#if !defined(AFX_QUESTIONSET_H__07A8BF1D_6F20_437A_BE68_990ABCA43464__INCLUDED_)
#define AFX_QUESTIONSET_H__07A8BF1D_6F20_437A_BE68_990ABCA43464__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// QuestionSet.h : header file
//
#ifndef CDATABASE
#define CDATABASE
#include "afxdb.h"
#endif
/////////////////////////////////////////////////////////////////////////////
// CQuestionSet recordset

class CQuestionSet : public CRecordset
{
public:
	CQuestionSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CQuestionSet)

// Field/Param Data
	//{{AFX_FIELD(CQuestionSet, CRecordset)
	long	m_QID;
	CString	m_QTitle;
	CString	m_AA;
	CString	m_AB;
	CString	m_AC;
	CString	m_AD;
	CString	m_RAnswer;
	CString	m_QCatalog;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQuestionSet)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUESTIONSET_H__07A8BF1D_6F20_437A_BE68_990ABCA43464__INCLUDED_)
