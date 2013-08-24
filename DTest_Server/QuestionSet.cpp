// QuestionSet.cpp : implementation file
//

#include "stdafx.h"
#include "DTest.h"
#include "QuestionSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQuestionSet

IMPLEMENT_DYNAMIC(CQuestionSet, CRecordset)

CQuestionSet::CQuestionSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CQuestionSet)
	m_QID = 0;
	m_QTitle = _T("");
	m_AA = _T("");
	m_AB = _T("");
	m_AC = _T("");
	m_AD = _T("");
	m_RAnswer = _T("");
	m_QCatalog = _T("");
	m_nFields = 8;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CQuestionSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=DTest");
}

CString CQuestionSet::GetDefaultSQL()
{
	return _T("[dbo].[Question]");
}

void CQuestionSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CQuestionSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[QID]"), m_QID);
	RFX_Text(pFX, _T("[QTitle]"), m_QTitle, 512);
	RFX_Text(pFX, _T("[AA]"), m_AA, 256);
	RFX_Text(pFX, _T("[AB]"), m_AB, 256);
	RFX_Text(pFX, _T("[AC]"), m_AC, 256);
	RFX_Text(pFX, _T("[AD]"), m_AD, 256);
	RFX_Text(pFX, _T("[RAnswer]"), m_RAnswer);
	RFX_Text(pFX, _T("[QCatalog]"), m_QCatalog);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CQuestionSet diagnostics

#ifdef _DEBUG
void CQuestionSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CQuestionSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
