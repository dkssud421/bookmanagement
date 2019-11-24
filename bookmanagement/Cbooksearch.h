#pragma once


// Cbooksearch 대화 상자

class Cbooksearch : public CDialog
{
	DECLARE_DYNAMIC(Cbooksearch)

public:
	Cbooksearch(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Cbooksearch();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEARCH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEdit bookname;
	CEdit book;
	afx_msg void OnBnClickedSearch();
};
