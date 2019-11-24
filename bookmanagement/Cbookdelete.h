#pragma once


// Cbookdelete 대화 상자

class Cbookdelete : public CDialog
{
	DECLARE_DYNAMIC(Cbookdelete)

public:
	Cbookdelete(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Cbookdelete();

	CStdioFile bookfile;
	CStdioFile bookfile_D;

	CString number;
	CString name;
	CString publisher;
	CString sbooknumber;
	CString rent;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DELETE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEdit booknumber;
	afx_msg void OnBnClickedDelete();
};
