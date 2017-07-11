// AniFileExDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AniFileEx.h"
#include "AniFileExDlg.h"

#include "EditDlg.h"
#include <ASSERT.H>
#include <fstream>

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
// CAniFileExDlg dialog

CAniFileExDlg::CAniFileExDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAniFileExDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAniFileExDlg)
	m_nCount = 0;
	m_strName = _T("");
	m_strSearch = _T("");
	m_pDrop = NULL;
	m_pWorkItem = NULL;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAniFileExDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAniFileExDlg)
	DDX_Control(pDX, IDC_LIST_SEARCH, m_ctrSearch);
	DDX_Control(pDX, IDC_TREE_VIEW, m_ctrTree);
	DDX_Text(pDX, IDC_EDIT_COUNT, m_nCount);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_SEARCH, m_strSearch);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAniFileExDlg, CDialog)
	//{{AFX_MSG_MAP(CAniFileExDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_NEW, OnButtonNew)
	ON_COMMAND(ID_MENU_DELETE, OnMenuDelete)
	ON_COMMAND(ID_MENU_EDIT, OnMenuEdit)
	ON_COMMAND(ID_MENU_NEW, OnMenuNew)
	ON_COMMAND(ID_MENU_NEWFOLDER, OnMenuNewfolder)
	ON_BN_CLICKED(IDC_BUTTON_ABOUT, OnButtonAbout)
	ON_BN_CLICKED(IDC_BUTTON_COUNT, OnButtonCount)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_EDIT, OnButtonEdit)
	ON_BN_CLICKED(IDC_BUTTON_LOAD, OnButtonLoad)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, OnButtonSearch)
	ON_NOTIFY(NM_RCLICK, IDC_TREE_VIEW, OnRclickTreeView)
	ON_NOTIFY(TVN_BEGINDRAG, IDC_TREE_VIEW, OnBegindragTreeView)
	ON_NOTIFY(TVN_ENDLABELEDIT, IDC_TREE_VIEW, OnEndlabeleditTreeView)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_VIEW, OnSelchangedTreeView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
	ON_WM_CLOSE()
	ON_LBN_SELCHANGE(IDC_LIST_SEARCH, &CAniFileExDlg::OnLbnSelchangeListSearch)
	ON_EN_CHANGE(IDC_EDIT_NAME, &CAniFileExDlg::OnEnChangeEditName)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAniFileExDlg message handlers

BOOL CAniFileExDlg::OnInitDialog()
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

	//m_ctrTree.EnableMultiSelect();
	
	// TODO: Add extra initialization here
	// ������ ����
	m_pImageList = new CImageList;
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_TREE_ICON);

	m_pImageList->Create(16,16, ILC_COLOR24|ILC_MASK, 3, 1);
	m_pImageList->Add(&bitmap, RGB(0,255,0));
	m_ctrTree.SetImageList(m_pImageList,TVSIL_NORMAL);

	CString saveFile( this->GetPaths() + "SaveEx.sav" );
	std::ifstream exist( saveFile.GetBuffer() );
	if( exist.good() )
	{
		exist.close();
		this->LoadFile( saveFile );
	}
	else
	{
		exist.close();
		this->InsertItem( "��ü", NULL, false );
	}
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAniFileExDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAniFileExDlg::OnPaint() 
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
HCURSOR CAniFileExDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAniFileExDlg::OnButtonNew() 
{
	// TODO: Add your control notification handler code here
	this->NewFile();
}

void CAniFileExDlg::OnMenuDelete() 
{
	// TODO: Add your command handler code here
	this->DeleteTree();
}

void CAniFileExDlg::OnMenuEdit() 
{
	// TODO: Add your command handler code here
	this->EditInfo();
}

void CAniFileExDlg::OnMenuNew() 
{
	// TODO: Add your command handler code here
	this->NewFile();
}

void CAniFileExDlg::OnMenuNewfolder() 
{
	// TODO: Add your command handler code here
	HTREEITEM Item = m_ctrTree.GetSelectedItem();
	TREEITEM *pTreeItem = this->FindTreeItem(Item);

	if( NULL!= pTreeItem && pTreeItem->bFile )
	{
		Item = this->FindTreeString(pTreeItem->strParent)->pTreeItem;
	}
	else if( Item == NULL )
	{
		auto it = m_listTreeItem.begin();
		Item = (*it)->pTreeItem;
	}

	// �̸��� ��ġ�°� ���ϱ� ���ؼ�...
	DWORD dwCnt=0;
	while(1)
	{
		char szMsg[256] = {NULL,};
		sprintf(&szMsg[0],"������%2d",dwCnt++);	// ������ ���ư������� ++

		TREEITEM *pTree = this->FindTreeString(&szMsg[0]);
		if(NULL == pTree )
		{
			this->InsertItem(&szMsg[0],Item,false);
			break;
		}
	}
}

void CAniFileExDlg::OnButtonAbout() 
{
	// TODO: Add your control notification handler code here
	CDialog dlg(IDD_ABOUTBOX);
	dlg.DoModal();
}

void CAniFileExDlg::OnButtonCount() 
{
	// TODO: Add your control notification handler code here
	HTREEITEM Item = m_ctrTree.GetSelectedItem();
	TREEITEM *pTreeItem = this->FindTreeItem(Item);

	if( pTreeItem->bFile )
	{
		m_nCount = ++pTreeItem->dwCount;
		UpdateData(FALSE);
	}
}

void CAniFileExDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	this->DeleteTree();
}

void CAniFileExDlg::OnButtonEdit() 
{
	// TODO: Add your control notification handler code here
	this->EditInfo();
}

void CAniFileExDlg::OnButtonLoad() 
{
	// TODO: Add your control notification handler code here
	char szFilters[]= "Save Files (*.sav)|*.sav|All Files (*.*)|*.*||";
	CFileDialog FileDlg(TRUE, "ite", NULL, OFN_FILEMUSTEXIST, szFilters, this);
	
	if(FileDlg.DoModal()==IDOK) 
    {
		this->LoadFile( FileDlg.GetPathName() );
	}
}

void CAniFileExDlg::Search()
{
	UpdateData( TRUE );

	m_ctrSearch.ResetContent();

	auto it = m_listTreeItem.begin();
	for ( ; it != m_listTreeItem.end(); ++it )
	{
		if( (*it)->strMessage.Find( m_strSearch.GetBuffer() ) >= 0 )
		{
			int i = m_ctrSearch.AddString( (*it)->strMessage.GetBuffer() );
			m_ctrSearch.SetItemDataPtr( i, (*it)->pTreeItem );
		}
	}

	m_strSearch.Empty();
	UpdateData( FALSE );
}

void CAniFileExDlg::OnButtonSearch() 
{
	// TODO: Add your control notification handler code here
	Search();
}

void CAniFileExDlg::OnRclickTreeView(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	POINT pt;
	GetCursorPos(&pt);
	m_ctrTree.ScreenToClient(&pt);	// ���콺 ��ǥ�� Ʈ�� �������� �ٲ�

	CPoint cPt(pt.x,pt.y);
	HTREEITEM Item = m_ctrTree.HitTest(cPt);
	m_ctrTree.SelectItem(Item);

	m_ctrTree.ClientToScreen(&pt);	// ���콺 ��ǥ�� �ٽ� �����Ƿ� ������
	
	CMenu meTemp, *pPopup;
	meTemp.LoadMenu(IDR_MENU_POPUP);
	
	pPopup = meTemp.GetSubMenu(0);

	TREEITEM* pItem = FindTreeItem( Item );
	if( pItem != NULL
		&& pItem->bRoot )
	{
		pPopup->EnableMenuItem( ID_MENU_DELETE, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED );
	}
	
	pPopup->TrackPopupMenu( TPM_LEFTALIGN | TPM_RIGHTBUTTON, pt.x, pt.y, this);
	
	
	*pResult = 0;
}

void CAniFileExDlg::OnBegindragTreeView(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	*pResult = 0;

	m_pWorkItem = this->FindTreeItem(pNMTreeView->itemNew.hItem);

	if( NULL == m_pWorkItem ) assert(false);	// Error!!	

	m_ctrTree.SelectItem(m_pWorkItem->pTreeItem);
	m_ctrTree.SetItemState(m_pWorkItem->pTreeItem, LVIS_CUT, LVIS_CUT);

	// �巡�� �̹��� ����
	m_pDrop = m_ctrTree.CreateDragImage(m_pWorkItem->pTreeItem);

	// �� ���� ���
	CPoint pt(pNMTreeView->ptDrag);
	CRect rtTree;
	m_ctrTree.GetItemRect(m_pWorkItem->pTreeItem, rtTree, LVIR_BOUNDS);
	m_pDrop->BeginDrag(0,CPoint(pt.x - rtTree.left, pt.y - rtTree.bottom));

	m_ctrTree.ClientToScreen(&pt);
	ScreenToClient(&pt);

	m_pDrop->DragEnter(this, pt);
	SetCapture();
}

void CAniFileExDlg::OnEndlabeleditTreeView(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TV_DISPINFO* pTVDispInfo = (TV_DISPINFO*)pNMHDR;
	// TODO: Add your control notification handler code here
	if( pTVDispInfo->item.pszText == NULL )
	{ return ; }

	// �ߺ� �̸� �˻�
	TREEITEM *pCheck= this->FindTreeString( LPSTR(LPCTSTR(pTVDispInfo->item.pszText)) );
	if( NULL != pCheck) 
	{
		MessageBox("���� �̸��� �����մϴ�.",NULL,MB_OK|MB_ICONWARNING);
		return;
	}
		
	// Ʈ�� ��Ʈ���� �����͸� ����
	m_ctrTree.SetItemText(pTVDispInfo->item.hItem,pTVDispInfo->item.pszText);

	TREEITEM *pTreeItem = this->FindTreeItem(pTVDispInfo->item.hItem);
	pTreeItem->strMessage = pTVDispInfo->item.pszText;

	m_strName = pTreeItem->strMessage;
	UpdateData(false);
	*pResult = 0;
}

void CAniFileExDlg::OnSelchangedTreeView(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	HTREEITEM Item = m_ctrTree.GetSelectedItem();
	TREEITEM *pTreeItem = this->FindTreeItem(Item);

	if( NULL != pTreeItem )
	{
		m_strName = pTreeItem->strMessage;
		m_nCount= pTreeItem->dwCount;
		UpdateData(false);
	}
	*pResult = 0;
}

void CAniFileExDlg::OnOK() 
{
	// TODO: Add extra validation here
	this->SaveFile( this->GetPaths() + "SaveEx.sav" );
	
	CDialog::OnOK();
}

void CAniFileExDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if( m_pDrop )
	{
		m_pDrop->DragShowNolock(true);
		m_pDrop->DragMove(point);
		
		CPoint pt(point);
		ClientToScreen(&pt);
		m_ctrTree.ScreenToClient(&pt);

		// ��Ʈ �׽�Ʈ
		UINT iFlag;
		HTREEITEM pItem = m_ctrTree.HitTest(pt,&iFlag);

		bool bDrop = false;

		if( NULL != pItem )
		{
			m_pDropItem = this->FindTreeItem(pItem);	// ��� ���� ����
			if( m_pDropItem != NULL )
			{
				auto checkSome = [=]()->bool
				{
					if( m_pWorkItem->bFile
						&& m_pDropItem->bFile )
					{
						return m_pWorkItem->strParent != m_pDropItem->strParent;
					}
					else if( m_pWorkItem->strMessage != m_pDropItem->strMessage )
					{
						HTREEITEM child = TreeView_GetChild( m_ctrTree.GetSafeHwnd(), m_pWorkItem->pTreeItem );
						while( child )
						{
							if( child == m_pDropItem->pTreeItem )
							{
								return false;
							}

							child = TreeView_GetNextSibling( m_ctrTree.GetSafeHwnd(), child );
						}
						return true;
					}
					return false;
				};

				bDrop = checkSome();
			}

			if( !bDrop )
			{
				m_pDropItem = NULL;
			}

			m_pDrop->DragShowNolock(false);

			m_ctrTree.SelectDropTarget(pItem);
			m_ctrTree.UpdateWindow();

			m_pDrop->DragShowNolock(true);
		}

		if (bDrop)		SetCursor(LoadCursor(NULL, IDC_ARROW));
		else			SetCursor(LoadCursor(NULL, IDC_NO));
	}

	CDialog::OnMouseMove(nFlags, point);
}

void CAniFileExDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if( m_pDrop && NULL != m_pWorkItem )
	{
		m_pDrop->DragLeave(NULL);
		m_pDrop->EndDrag();
		m_ctrTree.SelectDropTarget(NULL);
		ReleaseCapture();
		m_pDrop->DeleteImageList();

		SAFE_DELETE( m_pDrop );

		m_ctrTree.SetItemState(m_pWorkItem->pTreeItem, 0, LVIS_CUT);

		if( NULL == m_pDropItem ) return;

		TREEITEM Temp(*m_pWorkItem);

		// ��� �Ǵ� ���� �θ�� �д�. (��ӵǴ� ���� ������ ��� ó���� �ʿ���)

		TREEITEM *pNode = NULL;
		HTREEITEM pParent = NULL;

		if( m_pDropItem->bFile )	// ��� �������� �����̸�
		{
			// ��������� �θ� �����Ѵ�
			pNode = this->FindTreeString(m_pDropItem->strParent);
		}
		else	// ��� ������ �������
		{
			// ��������� �θ� �ȴ�.
			pNode = this->FindTreeItem(m_pDropItem->pTreeItem);
		}

		// �� �˻�
		if( NULL != pNode ) pParent = pNode->pTreeItem;
						
		// ������ ������ ����
		if( m_pWorkItem->bFile )
		{
			this->DeleteItem(m_pWorkItem->pTreeItem);
			this->InsertItem(Temp.strMessage,pParent,true,TVE_EXPAND,Temp.dwCount);
		}
		else
		{
			CopyFolder( pParent, m_pWorkItem->pTreeItem );
			{
				m_ctrTree.DeleteItem( m_pWorkItem->pTreeItem );

				auto iter =m_listTreeItem.begin();
				for( ; iter!= m_listTreeItem.end(); ++iter )
				{
					if( (*iter)->pTreeItem == m_pWorkItem->pTreeItem )
					{
						SAFE_DELETE(m_pWorkItem);
						m_listTreeItem.erase(iter);
						break;
					}
				}
			}
		}
	
		m_pWorkItem = NULL;
		m_pDropItem = NULL;
	}
	CDialog::OnLButtonUp(nFlags, point);
}

BOOL CAniFileExDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (m_ctrTree.GetEditControl() && (pMsg->message == WM_KEYDOWN))
    {
        BOOL bHandledHere = FALSE;
        switch(pMsg->wParam)
        {
        case VK_RETURN:
            {
                CString oldtext, newtext;
				HTREEITEM Item = m_ctrTree.GetSelectedItem();
                oldtext = m_ctrTree.GetItemText(Item);
                m_ctrTree.GetEditControl()->GetWindowText(newtext);
                bHandledHere = TRUE;
            }
            break;
        case VK_DELETE:
            m_ctrTree.GetEditControl()->SetWindowText("");
            bHandledHere = TRUE;
            break;
        case VK_ESCAPE:
            bHandledHere = TRUE;
            break;
        }
        
        if (bHandledHere)
        {
            ::TranslateMessage(pMsg);
            ::DispatchMessage(pMsg);
        }

        return bHandledHere ? TRUE : CDialog::PreTranslateMessage(pMsg);
	}

	if(pMsg->message == WM_KEYDOWN)
	{
		switch(pMsg->wParam)
		{
		case VK_DELETE:		this->DeleteTree();		break;
		case VK_RETURN:
			if( GetFocus()->GetDlgCtrlID() == GetDlgItem( IDC_EDIT_SEARCH )->GetDlgCtrlID() )
			{	
				Search();
			}
			break;
		}
	}

	return CDialog::PreTranslateMessage(pMsg);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//

bool CAniFileExDlg::NewFile()
{
	HTREEITEM Item = m_ctrTree.GetSelectedItem();
	TREEITEM *pTreeItem = this->FindTreeItem(Item);

	if( NULL == pTreeItem )
	{
		MessageBox("������ �������ּ���",NULL,MB_OK|MB_ICONASTERISK);
		return false;
	}

	if( pTreeItem->bFile )
	{
		Item = this->FindTreeString(pTreeItem->strParent)->pTreeItem;
	}

	EditDlg NewFileDlg;

	while(1)
	{
		if( IDCANCEL == NewFileDlg.DoModal() ) return true;	// ĵ���� �����ٸ�, �Լ��� �׳� ����
		
		// �ߺ� �̸� �˻�
		TREEITEM *pCheck= this->FindTreeString( NewFileDlg.m_strName );		
		if( NULL == pCheck)	break;	// ������ �극�̳�

		MessageBox("���� �̸��� �����մϴ�.",NULL,MB_OK|MB_ICONWARNING);
	}

	HTREEITEM pSelect = this->InsertItem(NewFileDlg.m_strName,Item,true,TVE_EXPAND,NewFileDlg.m_nCount);
	m_strName = NewFileDlg.m_strName;
	m_nCount= NewFileDlg.m_nCount;

	m_ctrTree.SelectItem(pSelect);
	UpdateData(false);

	return true;
}

HTREEITEM CAniFileExDlg::InsertItem(CString strName, HTREEITEM ParentItem, bool bFile, 
									DWORD dwExPand/*=TVE_EXPAND*/, DWORD dwCount/*=0*/)
{
	HTREEITEM Item;

	if(bFile)
	{	Item = m_ctrTree.InsertItem(strName,2,2,ParentItem);	}
	else
	{	Item = m_ctrTree.InsertItem(strName,0,1,ParentItem);	}
	m_ctrTree.Expand(ParentItem,dwExPand);					// Ʈ���� ��ġ�� TVE_EXPAND

	TREEITEM *pParent = this->FindTreeItem(ParentItem);			// �θ� ����

	// Ʈ�� ����Ʈ�� �� �����͸� �����.
	TREEITEM *ptagItem = new TREEITEM;

	ptagItem->dwIndex	= this->GetIndex();
	ptagItem->bFile		= bFile;
	ptagItem->dwCount	= dwCount;
	ptagItem->strMessage= strName;
	ptagItem->pTreeItem = Item;

	if(NULL != pParent)
	{	
		ptagItem->strParent = pParent->strMessage;	
	}
	else
	{
		ptagItem->bRoot = true;
	}

	m_listTreeItem.push_back(ptagItem);
	return Item;
}

bool CAniFileExDlg::EditInfo()
{
	HTREEITEM Item = m_ctrTree.GetSelectedItem();
	TREEITEM *pTreeItem = this->FindTreeItem(Item);

	if( NULL == pTreeItem ) return false;

	EditDlg EditDlg;

	EditDlg.m_bFile = pTreeItem->bFile;
	EditDlg.m_bEdit = true;

	EditDlg.m_strName = pTreeItem->strMessage;
	EditDlg.m_nCount= pTreeItem->dwCount;

	if( IDOK == EditDlg.DoModal() ) 
	{
		pTreeItem->strMessage = EditDlg.m_strName;
		m_strName = pTreeItem->strMessage;

		if( pTreeItem->bFile )	// �����϶��� Count
		{
			pTreeItem->dwCount = EditDlg.m_nCount;
			m_nCount= pTreeItem->dwCount;
		}

		UpdateData(false);

		// Ʈ�� ��Ʈ���� �����͸� ����
		m_ctrTree.SetItemText(pTreeItem->pTreeItem,pTreeItem->strMessage);
	}

	return true;
}

TREEITEM * CAniFileExDlg::FindTreeItem(HTREEITEM Item)
{
	if( NULL == Item ) return NULL;
	
	list<TREEITEM*>::iterator iter;
	for(iter=m_listTreeItem.begin(); iter!= m_listTreeItem.end(); ++iter)
	{
		if( (*iter)->pTreeItem == Item )
		{
			return (*iter);
		}
	}

	return NULL;
}

TREEITEM * CAniFileExDlg::FindTreeString(CString strName)
{
	list<TREEITEM*>::iterator iter;
	for(iter = m_listTreeItem.begin(); iter != m_listTreeItem.end(); ++iter)
	{
		TREEITEM *pTreeItem = (*iter);

		if( pTreeItem->strMessage == strName )
		{
			return pTreeItem;
		}
	}

	return NULL;
}

bool CAniFileExDlg::FindTreeRoot(CString strRoot,vector<TREEITEM> &listTree)
{
	list<TREEITEM*>::iterator iter;
	for(iter = m_listTreeItem.begin(); iter != m_listTreeItem.end(); ++iter)
	{
		TREEITEM *pTreeItem = (*iter);

		if( pTreeItem->strParent == strRoot )
		{
			listTree.push_back(*pTreeItem);
		}
	}
	return true;
}


bool CAniFileExDlg::DeleteTree()
{
	int nResult = MessageBox("������ ������ ��� ���ԵǾ��ִ� �͵� ��� �����˴ϴ�. \n���� �Ͻðڽ��ϱ�?",NULL,MB_YESNO|MB_ICONQUESTION);
	if( IDNO == nResult )	{		return false;		}
	
	HTREEITEM Item = m_ctrTree.GetSelectedItem();
	return this->DeleteItem(Item);
}

bool CAniFileExDlg::DeleteItem(HTREEITEM Item)
{
	TREEITEM *pChackItem = this->FindTreeItem(Item);

	list<TREEITEM*>::iterator iter;
	for(iter=m_listTreeItem.begin(); iter!= m_listTreeItem.end(); ++iter)
	{
		TREEITEM* pTreeItem = (*iter);
		if( pTreeItem->pTreeItem == Item
			&& !pTreeItem->bRoot )
		{
			if( !pTreeItem->bFile )	// �����̸�, �����ִ� �ֵ� �� ��������� ��.
			{
				// �θ�� �� �༮(pTreeItem)�� ���� �ڽĵ��� �� ã�Ƽ� ���� �ؾߵ�
				this->DeleteFolder( pTreeItem->strMessage );
			}

			SAFE_DELETE(pTreeItem);

			m_listTreeItem.erase(iter);

			m_ctrTree.DeleteItem(Item);
			break;
		}
	}

	return true;
}

bool CAniFileExDlg::DeleteFolder(CString strName)
{
	list<TREEITEM*>::iterator iter;
	for(iter = m_listTreeItem.begin(); iter != m_listTreeItem.end(); ++iter)
	{
		TREEITEM *pChildItem = (*iter);
		if( pChildItem->strParent == strName )
		{
			SAFE_DELETE(pChildItem);

			m_listTreeItem.erase(iter);

			this->DeleteFolder(strName);	// ��� ȣ��!! ���� -_-;;
			break;
		}
	}

	return true;
}

bool CAniFileExDlg::LoadFile(CString strFileName)
{
	// ������ Ŭ����
	list<TREEITEM*>::iterator iter;
	for(iter = m_listTreeItem.begin(); iter != m_listTreeItem.end(); ++iter)
	{	SAFE_DELETE( (*iter) );		}
	
	m_listTreeItem.clear();
	m_ctrTree.DeleteAllItems();
	
	HANDLE FileHandle = CreateFile(strFileName,GENERIC_READ,FILE_SHARE_READ,NULL,
		OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
	
	DWORD dwFileSize = 0;
	DWORD dwSize =0;
	
	// ������ ���
	char szHeader[54] = {NULL,};
	ReadFile(FileHandle, &szHeader[0], sizeof(szHeader), &dwFileSize, NULL);

	CString strHeader = szHeader;
	// ����� �ٸ��ٸ�, �����ÿ� ����.
	if( "CopyRight(c) 2006 by Programming Shin Hwi Jae" != strHeader )
	{	
		strHeader.Empty();
		CloseHandle(FileHandle);

		this->Convert(strFileName);
		return false;
	}

	// MaxCount
	ReadFile(FileHandle,&dwSize, sizeof(DWORD),&dwFileSize,NULL);
	
	int i;
	for(i=0; i<dwSize; i++)
	{
		bool bFile(0);
		DWORD dwCount(0);
		char szParent[256] = {NULL,};
		char szMsg[256] = {NULL,};
		
		// Folder Info
		ReadFile(FileHandle,&bFile, sizeof(bool),&dwFileSize,NULL);
		ReadFile(FileHandle,&szParent[0], 256,&dwFileSize,NULL);
		ReadFile(FileHandle,&szMsg[0], 256,&dwFileSize,NULL);
		
		if( bFile )
		{
			// Data
			ReadFile(FileHandle,&dwCount, sizeof(DWORD),&dwFileSize,NULL);
		}

		TREEITEM *pPraent = this->FindTreeString(&szParent[0]);
		HTREEITEM pPraentItem = NULL;
		if( NULL != pPraent ) 
		{
			pPraentItem = pPraent->pTreeItem;
		}

		this->InsertItem(&szMsg[0], pPraentItem, bFile, TVE_COLLAPSE, dwCount);
	}
	
	CloseHandle(FileHandle);

	return true;
}

bool CAniFileExDlg::SaveFile(CString strFileName)
{
	//------------------------------//
	//			File ����			//
	//------------------------------//
	//			��� ����			//
	//			MaxCount			//
	//   ��������,��������(bFile)	//
	//	 �ڱ� �̸�(���϶Ǵ�����)    //
	//	 �θ������� �̸�			//
	//          ������ ����			//
	// ............................	//
	//------------------------------//
	
	HANDLE Wfpt = CreateFile(strFileName,GENERIC_WRITE,0,NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL,NULL);
	DWORD dwFileSize = 0;
	DWORD dwSize = m_listTreeItem.size();
	
	// ������ ���
	char szHeader[54] = {"CopyRight(c) 2006 by Programming Shin Hwi Jae"};
	WriteFile( Wfpt, &szHeader[0], sizeof(szHeader), &dwFileSize, NULL);
	// MaxCount
	WriteFile( Wfpt, &dwSize, sizeof(DWORD), &dwFileSize, NULL);
	
	list<TREEITEM*>::iterator iter;
	// ���⼭���� ������ ����
	for(iter = m_listTreeItem.begin(); iter != m_listTreeItem.end(); ++iter)
	{
		TREEITEM *pTreeItem = (*iter);
		char szParent[256] = {NULL,};
		char szMsg[256] = {NULL,};

		strcpy(&szParent[0],LPSTR(LPCTSTR(pTreeItem->strParent)) );
		strcpy(&szMsg[0],LPSTR(LPCTSTR(pTreeItem->strMessage)) );

		WriteFile( Wfpt,&pTreeItem->bFile, sizeof(bool), &dwFileSize, NULL);
		WriteFile( Wfpt,&szParent[0], 256, &dwFileSize, NULL);
		WriteFile( Wfpt,&szMsg[0], 256, &dwFileSize, NULL);
		
		if( pTreeItem->bFile )	// �����̶��
		{
			WriteFile( Wfpt,&pTreeItem->dwCount, sizeof(DWORD), &dwFileSize, NULL);
		}
	}
	
	CloseHandle(Wfpt);

	return true;
}

bool CAniFileExDlg::Convert(CString strFileName)
{
	HTREEITEM pPraent = this->InsertItem("��ü",NULL,false);

	// ���⼭���� ������ ����.
	DWORD ReSize;
	char Data[2048]={NULL,};
	char Name[256]={NULL,};
	WORD Loop=0;
	WORD Len,Vol;
	
	HANDLE Rfpt;
		
	Rfpt = CreateFile(strFileName,
		GENERIC_READ,0,NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL,NULL);

	// ������ �д´�.
	ReadFile( Rfpt, &Data, sizeof(Data), &ReSize, NULL);

	if(ReSize != 0)
	{
		for(WORD i=0; i<ReSize;i++)
		{
			if(Data[i] == 13)
			{
				strncpy(&Name[0],&Data[Loop],i-Loop);
				Len=strlen(&Name[0]);

				char szTempName[256] = {NULL,};

				strncpy(&szTempName[0],&Name[0],Len-4);	//���� �κи� �����Ѵ�
				Vol=atoi(&Name[Len-3]);	//ȭ�� �κи� ���������� �̾Ƴ���

				this->InsertItem(&szTempName[0],pPraent,true,TVE_COLLAPSE,Vol);
			
				ZeroMemory(&Name[0],256);
				Loop=i+2;
			}
		}
	}
	CloseHandle(Rfpt);


	return true;
}


CString CAniFileExDlg::GetPaths()
{
	HMODULE hModule = ::GetModuleHandle(NULL);
    ASSERT(hModule != 0);	
    CString strExeFileName;	
    VERIFY(::GetModuleFileName(hModule, strExeFileName.GetBuffer(_MAX_PATH), _MAX_PATH));	
    
	strExeFileName.ReleaseBuffer();
	
	int nCount = strExeFileName.ReverseFind('\\');

	CString strResult;
	strResult.Format("%s\\",strExeFileName.Left(nCount));

	strExeFileName.Empty();
	return strResult;
}

int CAniFileExDlg::GetIndex()
{
	int nIndex = 0;

	list<TREEITEM*>::iterator iter;
	for(iter = m_listTreeItem.begin(); iter != m_listTreeItem.end(); ++iter)
	{
		TREEITEM *pChildItem = (*iter);
		if( pChildItem->dwIndex == nIndex )
		{
			++nIndex;
		}
	}

	return nIndex;
}

bool CAniFileExDlg::CopyFolder(HTREEITEM SrcItem, HTREEITEM DestItem)
{
	bool bHappendCopy = false;

	TREEITEM *pPraent = this->FindTreeItem(SrcItem); 
	TREEITEM *pDest = this->FindTreeItem(DestItem);

	if(NULL == pPraent || NULL == pDest ) return false;

	HTREEITEM RootItem = this->InsertItem(pDest->strMessage, SrcItem, pDest->bFile, TVE_EXPAND, pDest->dwCount );// Dest�� ���� ����

	HTREEITEM pChild = TreeView_GetChild( m_ctrTree.GetSafeHwnd(),DestItem );

	std::vector<HTREEITEM> removeList;

	while( pChild )
	{
		TREEITEM *pFindItem = FindTreeItem( pChild );
		if( pFindItem != NULL )
		{
			if( pFindItem->bFile )
			{
				InsertItem( pFindItem->strMessage, RootItem, pFindItem->bFile, TVE_COLLAPSE, pFindItem->dwCount );
				bHappendCopy = true;
				removeList.push_back( pFindItem->pTreeItem );
			}
			else
			{
				CopyFolder( RootItem, pFindItem->pTreeItem );
			}
		}

		pChild = TreeView_GetNextSibling( m_ctrTree.GetSafeHwnd(), pChild );
	}

	// ����
	auto it = removeList.begin();
	auto endIt = removeList.end();
	for ( ; it != endIt; ++it )
	{
		DeleteItem( *it );
	}

	return bHappendCopy;
}

bool CAniFileExDlg::CopyFile(HTREEITEM SrcItem, HTREEITEM DestItem)
{
	TREEITEM *pPraent = this->FindTreeItem(SrcItem); 
	TREEITEM *pDest = this->FindTreeItem(DestItem);

	if(NULL == pPraent || NULL == pDest ) return false;

	return true;
}

void CAniFileExDlg::OnClose()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	
	CDialog::OnClose();
}


void CAniFileExDlg::OnLbnSelchangeListSearch()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int i = m_ctrSearch.GetCurSel();
	HTREEITEM item = (HTREEITEM)m_ctrSearch.GetItemDataPtr( i );

	m_ctrTree.SelectItem( item );
}


void CAniFileExDlg::OnEnChangeEditName()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialog::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
