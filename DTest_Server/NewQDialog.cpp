// NewQDialog.cpp : implementation file
//

#include "stdafx.h"
#include "DTest.h"
#include "NewQDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewQDialog dialog


CNewQDialog::CNewQDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CNewQDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewQDialog)
	m_title = _T("");
	m_rightChoice = -1;
	m_answerA = _T("");
	m_answerB = _T("");
	m_answerC = _T("");
	m_answerD = _T("");
	//}}AFX_DATA_INIT
}


void CNewQDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewQDialog)
	DDX_Text(pDX, IDC_NQTITLE, m_title);
	DDX_Radio(pDX, IDC_NAA, m_rightChoice);
	DDX_Text(pDX, IDC_NAAC, m_answerA);
	DDX_Text(pDX, IDC_NABC, m_answerB);
	DDX_Text(pDX, IDC_NACC, m_answerC);
	DDX_Text(pDX, IDC_NADC, m_answerD);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewQDialog, CDialog)
	//{{AFX_MSG_MAP(CNewQDialog)
	ON_BN_CLICKED(IDC_NQ, OnNq)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewQDialog message handlers

void CNewQDialog::OnNq() 
{
	// TODO: Add your control notification handler code here
        UpdateData(TRUE);
        if (m_title == "")
        {
                MessageBox("题目不能为空！", "小提示", MB_OK | MB_ICONINFORMATION);
                return;
        }
        else if (m_answerA == "" && m_answerB == "" && m_answerC == "" && m_answerD == "") 
        {
                MessageBox("请至少填写一个选项！", "小提示", MB_OK | MB_ICONINFORMATION);
                return;
        }
        else if (m_rightChoice == -1)
        {
                MessageBox("请选择一个正确答案！", "小提示", MB_OK | MB_ICONINFORMATION);
                return;
        }

        // 写入数据库
        questionSet.m_pDatabase = &database;
        questionSet.Open();

        questionSet.AddNew();
        questionSet.m_QTitle = m_title;
        questionSet.m_AA = m_answerA;
        questionSet.m_AB = m_answerB;
        questionSet.m_AC = m_answerC;
        questionSet.m_AD = m_answerD;
        questionSet.m_RAnswer = m_rightChoice + 'A';
        questionSet.Update(); 

        questionSet.Close();
        MessageBox("录入成功！", "小提示", MB_OK | MB_ICONINFORMATION);
        CDialog::OnOK();

        
}

BOOL CNewQDialog::OnInitDialog()
{
        CDialog::OnInitDialog();

        CStdioFile file; 
        if (!file.Open( "config.ini", CFile::modeRead)) 
        {
                MessageBox("配置文件(config.ini)打开失败！", "小提示", MB_OK | MB_ICONERROR);
                return FALSE;
        }
        
        CString strConnection;
        // DSN UID PWD
        CString strConfig[3];
        for (int i = 0; i < 3 && file.ReadString(strConfig[i]); i++) 
        {
        }
        strConnection.Format("ODBC;DSN=%s;UID=%s;PWD=%s", strConfig[0], strConfig[1], strConfig[2]);
        
        if (!database.Open(strConnection)) 
        {
                MessageBox("数据库打开失败，请检查数据库连接！", "小提示", MB_OK | MB_ICONERROR);
                return FALSE;
        }
        return TRUE;

}
