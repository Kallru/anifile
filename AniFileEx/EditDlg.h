#if !defined(AFX_EDITDLG_H__59D2F470_E994_4E2A_8C68_C239722A8316__INCLUDED_)
#define AFX_EDITDLG_H__59D2F470_E994_4E2A_8C68_C239722A8316__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EditDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// EditDlg dialog

class EditDlg : public CDialog
{
// Construction
public:
	EditDlg(CWnd* pParent = NULL);   // standard constructor

	bool m_bFile;
	bool m_bEdit;

// Dialog Data
	//{{AFX_DATA(EditDlg)
	enum { IDD = IDD_NEWFILE };
	CString	m_strName;
	int		m_nCount;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(EditDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(EditDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITDLG_H__59D2F470_E994_4E2A_8C68_C239722A8316__INCLUDED_)
