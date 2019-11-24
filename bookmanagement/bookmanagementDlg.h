
// bookmanagementDlg.h: 헤더 파일
//
#include "CMember.h"
#include "Cbook.h"
#include"Cmbook.h"
#include"Cbookadd.h"
#pragma once


// CbookmanagementDlg 대화 상자
class CbookmanagementDlg : public CDialog
{
//변수
private:
	CStdioFile Memfile;
	CStdioFile porsion;
	CString sid;
	CString spassword, ipaw;

// 생성입니다.
public:
	CbookmanagementDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	CMember *m_member;
	Cbook* m_book;
	Cbookadd* m_bookadd;
	Cmbook* c_book;

	CString id;
	CString password;
	CString name;

	

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BOOKMANAGEMENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.



// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMember();
	afx_msg void OnBnClickedLogin();
	CEdit user_id;
	CEdit user_password;
	afx_msg void OnBnClickedMlogin();
};
