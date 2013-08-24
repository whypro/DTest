// DTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DTest.h"
#include "DTestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
// CDTestDlg dialog

CDTestDlg::CDTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDTestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDTestDlg)
	m_choice = -1;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDTestDlg)
	DDX_Radio(pDX, IDC_AA, m_choice);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDTestDlg, CDialog)
	//{{AFX_MSG_MAP(CDTestDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_NEXT, OnNext)
	ON_BN_CLICKED(IDC_PRE, OnPre)
	ON_BN_CLICKED(IDC_SUMMIT, OnSummit)
	ON_BN_CLICKED(IDC_QUIT, OnQuit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDTestDlg message handlers

BOOL CDTestDlg::OnInitDialog()
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

        questionSet.m_pDatabase = &database; 
        questionSet.Open();
        
        // 获得题目的总个数
        if (!questionSet.IsBOF())
        {
                questionSet.MoveFirst();
        }
        while (!questionSet.IsEOF())
        {
                questionSet.MoveNext();
        }
        totalQuestion = questionSet.GetRecordCount(); 

        InitData();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDTestDlg::OnPaint() 
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
HCURSOR CDTestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


BOOL CDTestDlg::InitData()
{
        score = 0;
        currentQuestion = 1;
        // 保存每道题的答案
        answer = new int[totalQuestion + 1];
        memset(answer, -1, totalQuestion + 1);
        questionSet.MoveFirst();
        InitQuestion();
        return TRUE;
}

BOOL CDTestDlg::InitQuestion()
{
        CString str;
        CString strAA;
        CString strAB;
        CString strAC;
        CString strAD;
        
        
        str.Format("%d / %d", currentQuestion, totalQuestion);
        SetDlgItemText(IDC_QNO, str);
        
        SetDlgItemText(IDC_QTITLE, questionSet.m_QTitle);
        SetDlgItemText(IDC_AA, "A. " + questionSet.m_AA);
        SetDlgItemText(IDC_AB, "B. " + questionSet.m_AB);
        SetDlgItemText(IDC_AC, "C. " + questionSet.m_AC);
        SetDlgItemText(IDC_AD, "D. " + questionSet.m_AD);
        m_choice = answer[currentQuestion];
        UpdateData(FALSE);
        
        return TRUE;
}


void CDTestDlg::OnNext() 
{
        
        // TODO: Add your control notification handler code here
        UpdateData(TRUE);
        answer[currentQuestion] = m_choice;

        if (currentQuestion < totalQuestion) 
        {
                questionSet.MoveNext();
                currentQuestion++;
                InitQuestion();
        }
        else 
        {
                MessageBox("这是最后一题了！", "小提示：", MB_OK | MB_ICONINFORMATION);
        }
        
}


void CDTestDlg::OnPre() 
{
	// TODO: Add your control notification handler code here

        
        UpdateData(TRUE);
        answer[currentQuestion] = m_choice;

        if (currentQuestion > 1) 
        {
                questionSet.MovePrev();
                currentQuestion--;
                InitQuestion();
        }
        else 
        {
                MessageBox("这是第一题了！", "小提示：", MB_OK | MB_ICONINFORMATION);
        }	
}

void CDTestDlg::OnSummit() 
{
	// TODO: Add your control notification handler code here
        UpdateData(TRUE);
        answer[currentQuestion] = m_choice;

        questionSet.MoveFirst();
        for (int i = 1; i <= totalQuestion; i++) 
        {
                bool isCorrect = (questionSet.m_RAnswer == answer[i] + 'A') ? true : false;
                if (isCorrect) 
                {
                        score += 1;
                }
                questionSet.MoveNext();

        }
        CString strScore;
        strScore.Format("您的得分：%d ", score);
        MessageBox(strScore, "小提示", MB_OK | MB_ICONINFORMATION);


        delete []answer;
        answer = NULL;
        InitData();	
}

void CDTestDlg::OnQuit() 
{
	// TODO: Add your control notification handler code here
        MessageBox("谢谢使用，再见！", "小提示", MB_OK | MB_ICONINFORMATION);
        CDialog::OnCancel();            
	
}



