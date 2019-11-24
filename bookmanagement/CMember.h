#pragma once


// CMember 대화 상자

class CMember : public CDialogEx
{
	DECLARE_DYNAMIC(CMember)

public:
	CMember(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CMember();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MEMBER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
//	CString NAME;
	afx_msg void OnEnChangeName();
	afx_msg void OnBnClickedOk();
	CEdit name;
	CEdit user_id;
	CEdit user_password;
};
