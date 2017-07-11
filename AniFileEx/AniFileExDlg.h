// AniFileExDlg.h : header file
//

#if !defined(AFX_ANIFILEEXDLG_H__4928DF5A_CD87_4391_A29E_1E7FAA679029__INCLUDED_)
#define AFX_ANIFILEEXDLG_H__4928DF5A_CD87_4391_A29E_1E7FAA679029__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAniFileExDlg dialog

typedef struct TREEITEM
{
	DWORD		dwIndex;
	bool		bFile;		// 1이면 File, 0이면 Folder

	CString		strParent;	// 부모 폴더 이름
	CString		strMessage;	// 자기 이름
	DWORD		dwCount;	// 화수

	HTREEITEM	pTreeItem;	// 트리 위치

	bool bRoot;

	TREEITEM():bRoot(0),bFile(0),dwCount(0),pTreeItem(NULL),dwIndex(0){}
}TREEITEM;

class CAniFileExDlg : public CDialog
{
// Construction
public:
	CAniFileExDlg(CWnd* pParent = NULL);	// standard constructor

	HTREEITEM InsertItem(CString strName, HTREEITEM ParentItem, bool bFile, DWORD dwExPand=TVE_EXPAND, DWORD dwCount=0);

	bool CopyFolder(HTREEITEM SrcItem, HTREEITEM DestItem);
	bool CopyFile(HTREEITEM SrcItem, HTREEITEM DestItem);

	int GetIndex();

	// New & delete
	bool NewFile();
	bool EditInfo();

	bool DeleteTree();
	bool DeleteItem(HTREEITEM Item);
	bool DeleteFolder(CString strName);

	// File Control
	bool SaveFile(CString strFileName);
	bool LoadFile(CString strFileName);
	bool Convert(CString strFileName);

	// Find
	TREEITEM * FindTreeItem(HTREEITEM Item);
	TREEITEM * FindTreeString(CString strName);
	bool FindTreeRoot(CString strRoot, vector<TREEITEM> &listTree);	// (폴더이름, 그폴더에 속한 노드들)

	CString GetPaths();

	void Search();
	
	TREEITEM	*	m_pWorkItem;	
	TREEITEM	*	m_pDropItem;
	CImageList	*	m_pImageList;
	CImageList	*	m_pDrop;
	list<TREEITEM*> m_listTreeItem;	// 트리 리스트


// Dialog Data
	//{{AFX_DATA(CAniFileExDlg)
	enum { IDD = IDD_ANIFILEEX_DIALOG };
	CListBox	m_ctrSearch;
	CTreeCtrl	m_ctrTree;
	int		m_nCount;
	CString	m_strName;
	CString	m_strSearch;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAniFileExDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAniFileExDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonNew();
	afx_msg void OnMenuDelete();
	afx_msg void OnMenuEdit();
	afx_msg void OnMenuNew();
	afx_msg void OnMenuNewfolder();
	afx_msg void OnButtonAbout();
	afx_msg void OnButtonCount();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonEdit();
	afx_msg void OnButtonLoad();
	afx_msg void OnButtonSearch();
	afx_msg void OnRclickTreeView(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBegindragTreeView(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEndlabeleditTreeView(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchangedTreeView(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
	afx_msg void OnLbnSelchangeListSearch();
	afx_msg void OnEnChangeEditName();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANIFILEEXDLG_H__4928DF5A_CD87_4391_A29E_1E7FAA679029__INCLUDED_)
