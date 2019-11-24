#pragma once


// Cbooklent 대화 상자

class Cbooklent : public CDialog
{
	DECLARE_DYNAMIC(Cbooklent)

public:
	Cbooklent(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Cbooklent();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RENT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEdit bookrent;
	afx_msg void OnBnClickedRent();
};
