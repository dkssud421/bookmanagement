#pragma once


// Cbookadd 대화 상자

class Cbookadd : public CDialog
{
	DECLARE_DYNAMIC(Cbookadd)

public:
	Cbookadd(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Cbookadd();

	CStdioFile bookfile;
	CString ibooknumber;
	CString sbooknumber;
	CString sbookname;
	CString spublisher;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BOOKADD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEdit bookname;
	CEdit publisher;
	afx_msg void OnBnClickedAdd();
	afx_msg void OnEnSetfocusEdit1();
	CEdit booknumber;
	afx_msg void OnEnChangeEdit2();
};
