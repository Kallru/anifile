// EditDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AniFileEx.h"
#include "EditDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// EditDlg dialog


EditDlg::EditDlg(CWnd* pParent /*=NULL*/)
	: CDialog(EditDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(EditDlg)
	m_strName = _T("");
	m_nCount = 1;
	m_bFile = 1;
	m_bEdit = 0;
	//}}AFX_DATA_INIT
}


void EditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(EditDlg)
	DDX_Text(pDX, IDC_EDIT1, m_strName);
	DDX_Text(pDX, IDC_EDIT2, m_nCount);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(EditDlg, CDialog)
	//{{AFX_MSG_MAP(EditDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// EditDlg message handlers

BOOL EditDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	HICON hIcon = AfxGetApp()->LoadIcon(IDI_ICON_MAIN);
	SetIcon(hIcon, TRUE);			// Set big icon
	SetIcon(hIcon, FALSE);		// Set small icon

	if( m_bEdit )
	{
		SetWindowText("Edit");
	}
	
	if( !m_bFile )
	{
		((CEdit*)GetDlgItem(IDC_EDIT2))->EnableWindow(FALSE);
		m_nCount=0;
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
