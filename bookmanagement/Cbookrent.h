#pragma once


// Cbookrent 대화 상자

class Cbookrent : public CDialog
{
	DECLARE_DYNAMIC(Cbookrent)

private:
	CStdioFile bookfile;
	CStdioFile bookfile_D;
	CStdioFile porsion;

	CString id;
	CString number;
	CString name;
	CString publisher;
	CString sbooknumber;
	CString rent;
	CString user_id;
	CString user_name;
public:
	Cbookrent(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Cbookrent();





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
