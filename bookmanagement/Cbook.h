#pragma once
#include "Cbooksearch.h"
#include "Cbookrent.h"
#include "Cbookreturn.h"
// Cbook 대화 상자

class Cbook : public CDialog
{
	DECLARE_DYNAMIC(Cbook)

public:
	Cbook(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Cbook();
	Cbooksearch* m_booksearch;
	Cbookrent* m_bookrent;
	Cbookreturn* m_bookreturn;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BOOK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSearch();
	afx_msg void OnBnClickedRent();
	afx_msg void OnBnClickedReturn();
};
