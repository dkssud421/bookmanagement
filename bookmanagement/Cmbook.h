#include "Cbookadd.h"
#include"Cbookdelete.h"
#include"Cbooksearch.h"
#pragma once
// Cmbook 대화 상자

class Cmbook : public CDialog
{
	DECLARE_DYNAMIC(Cmbook)

public:
	Cmbook(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Cmbook();
	Cbookadd* m_bookadd;
	Cbookdelete* m_bookdelete;
	Cbooksearch* m_booksearch;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MBOOK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAdd();


	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedSearch();
};
