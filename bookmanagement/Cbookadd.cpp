// Cbookadd.cpp: 구현 파일
//

#include "pch.h"
#include "bookmanagement.h"
#include "Cbookadd.h"
#include "afxdialogex.h"
#include <Imm.h>
#include <locale.h>

#pragma comment(lib, "imm32.lib")

// Cbookadd 대화 상자

IMPLEMENT_DYNAMIC(Cbookadd, CDialog)

Cbookadd::Cbookadd(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_BOOKADD, pParent)
{

}

Cbookadd::~Cbookadd()
{
}

void Cbookadd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, bookname);
	DDX_Control(pDX, IDC_EDIT2, publisher);
	DDX_Control(pDX, IDC_EDIT4, booknumber);
}


BEGIN_MESSAGE_MAP(Cbookadd, CDialog)
	ON_BN_CLICKED(IDC_ADD, &Cbookadd::OnBnClickedAdd)
	ON_EN_SETFOCUS(IDC_EDIT1, &Cbookadd::OnEnSetfocusEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &Cbookadd::OnEnChangeEdit2)
END_MESSAGE_MAP()


// Cbookadd 메시지 처리기


void Cbookadd::OnBnClickedAdd()
{
	bool tf = true;
	int count = 0;
	setlocale(LC_ALL, "korean");
	bookname.GetWindowText(sbookname);
	publisher.GetWindowText(spublisher);
	booknumber.GetWindowText(sbooknumber);

	if (bookfile.Open(L"book.txt", CFile::modeCreate | CFile::modeNoTruncate | CFile::modeRead))
	{
		count %= 4;
		while (bookfile.ReadString(ibooknumber))
		{
			if (count == 0)
			{
				if (sbooknumber == ibooknumber)
				{
					tf = false;
					break;
				}
			}
		}
		bookfile.Close();
	}
	else
	{
		MessageBox(L"파일을 열지 못했습니다.", L"경고!", MB_OK | MB_ICONHAND);
		return;
	}

	if (tf)
	{
	    if (bookfile.Open(L"book.txt", CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite))
		{
			bookfile.SeekToEnd();
			bookfile.WriteString(sbooknumber + "\n" + sbookname + "\n" + spublisher + "\n" + "o" + "\n");
			bookfile.Close();
			MessageBox(L"저장 되었습니다.");
		}
		else
		{
			MessageBox(L"파일을 열지 못했습니다.", L"경고!", MB_OK | MB_ICONHAND);
			return;
		}
	}
	else
	{
		MessageBox(L"같은 책이 존재합니다.");
	}
	count = 0;
}


void Cbookadd::OnEnSetfocusEdit1()
{
	HIMC himc = ImmGetContext(GetDlgItem(IDC_EDIT1)->GetSafeHwnd());
	ImmSetConversionStatus(himc, IME_CMODE_NATIVE, IME_SMODE_CONVERSATION);
	ImmReleaseContext(GetDlgItem(IDC_EDIT1)->GetSafeHwnd(), himc);

}


void Cbookadd::OnEnChangeEdit2()
{
	HIMC himc = ImmGetContext(GetDlgItem(IDC_EDIT2)->GetSafeHwnd());
	ImmSetConversionStatus(himc, IME_CMODE_NATIVE, IME_SMODE_CONVERSATION);
	ImmReleaseContext(GetDlgItem(IDC_EDIT1)->GetSafeHwnd(), himc);
}
