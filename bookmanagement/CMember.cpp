// CMember.cpp: 구현 파일
//

#include "pch.h"
#include "bookmanagement.h"
#include "CMember.h"
#include "afxdialogex.h"


// CMember 대화 상자

IMPLEMENT_DYNAMIC(CMember, CDialogEx)

CMember::CMember(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MEMBER, pParent)
{

}

CMember::~CMember()
{
}

void CMember::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_NAME, name);
	DDX_Control(pDX, IDC_ID, user_id);
	DDX_Control(pDX, IDC_PASSWORD, user_password);
}


BEGIN_MESSAGE_MAP(CMember, CDialogEx)
	
	ON_EN_CHANGE(IDC_NAME, &CMember::OnEnChangeName)
	ON_BN_CLICKED(IDOK, &CMember::OnBnClickedOk)
END_MESSAGE_MAP()




void CMember::OnEnChangeName()
{

}


void CMember::OnBnClickedOk()
{
	CStdioFile Memfile;
	CString sname;
	CString sid;
	CString spassword;
	CString iid;
	int count = 0;

	user_id.GetWindowText(sid);
	user_password.GetWindowText(spassword);
	name.GetWindowText(sname);

	if (Memfile.Open(L"member.txt", CFile::modeCreate |CFile::modeNoTruncate |CFile::modeReadWrite))
	{
		while (Memfile.ReadString(iid))
		{
			TRACE(iid);
			if (count == 0)
			{
				if (iid == sid)
				{
					MessageBox(L"아이디를 다시 입력하시오!", L"아이디 중복", MB_OK | MB_ICONHAND);
					return;
				}
			}
			else if (count == 2)
			{
				count = 0;
			}else
			{
				count++;
			}
		}
		Memfile.SeekToEnd();
		Memfile.WriteString( sid + "\n"+ spassword + "\n" + sname + "\n");
		Memfile.Close();
		count = 0;
	}
	else
	{
		MessageBox(L"파일을 열지 못했습니다.", L"경고!", MB_OK | MB_ICONHAND);
		return;
	}

	CDialogEx::OnOK();
}
