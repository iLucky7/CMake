// CMakeSetupDialogDlg.h : header file
//

#if !defined(AFX_CMakeSetupDialogDLG_H__AC17A6F6_4634_11D4_8F21_00A0CC33FCD3__INCLUDED_)
#define AFX_CMakeSetupDialogDLG_H__AC17A6F6_4634_11D4_8F21_00A0CC33FCD3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "PropertyList.h"
/////////////////////////////////////////////////////////////////////////////
// CMakeSetupDialog dialog

class CMakeSetupDialog : public CDialog
{
// Construction
public:
  CMakeSetupDialog(CWnd* pParent = NULL);	// standard constructor
protected:
  //! Load cache file from m_WhereBuild and display in GUI editor
  void LoadCacheFromDiskToGUI();
  //! Save GUI values to cmCacheManager and then save to disk.
  void SaveCacheFromGUI();
  void SaveToRegistry();
  void LoadFromRegistry();
  bool Browse(CString&, const char* title);
  void ReadRegistryValue(HKEY hKey,
			 CString *val,
			 const char *key,
			 const char *aadefault);
// Dialog Data
  //{{AFX_DATA(CMakeSetupDialog)
  enum { IDD = IDD_CMakeSetupDialog_DIALOG };
  CString	m_WhereSource;
  CString	m_WhereBuild;
  CButton	m_ListFrame;
  bool          m_BuildPathChanged;
  CComboBox     m_WhereSourceControl;
  CComboBox     m_WhereBuildControl;
  CPropertyList m_CacheEntriesList;
  CStatic       m_MouseHelp;
  CStatic       m_VersionDisplay;
  CButton       m_BuildProjects;
  CButton       m_CancelButton;
  //}}AFX_DATA
  
  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CMakeSetupDialog)
protected:
  virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
  //}}AFX_VIRTUAL
  
// Implementation
protected:
  
  // copy from the cache manager to the cache edit list box
  void FillCacheGUIFromCacheManager();
  // copy from the list box to the cache manager
  void FillCacheManagerFromCacheGUI();
  
  
  HICON m_hIcon;
  CString m_RegistryKey;
  CString m_PathToExecutable;
  // Generated message map functions
  //{{AFX_MSG(CMakeSetupDialog)
  virtual BOOL OnInitDialog();
  afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
  afx_msg void OnPaint();
  afx_msg HCURSOR OnQueryDragIcon();
  afx_msg void OnBrowseWhereSource();
  virtual void OnBuildProjects();
  afx_msg void OnBrowseWhereBuild();
  afx_msg void OnChangeWhereBuild();
  afx_msg void OnSelendokWhereBuild();
  afx_msg void OnChangeWhereSource();
  afx_msg void OnSelendokWhereSource();
  afx_msg void OnSize(UINT nType, int cx, int cy);
  afx_msg void OnGetMinMaxInfo( MINMAXINFO FAR* lpMMI );
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()

    int m_oldCX;
    int m_oldCY;
  float m_deltaXRemainder;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMakeSetupDialogDLG_H__AC17A6F6_4634_11D4_8F21_00A0CC33FCD3__INCLUDED_)
