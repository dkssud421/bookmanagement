// Cbooksearch.cpp: 구현 파일
//

#include "pch.h"
#include "bookmanagement.h"
#include "Cbooksearch.h"
#include "afxdialogex.h"
#include <locale.h>

// Cbooksearch 대화 상자

IMPLEMENT_DYNAMIC(Cbooksearch, CDialog)

Cbooksearch::Cbooksearch(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_SEARCH, pParent)
{

}

Cbooksearch::~Cbooksearch()
{
}

void Cbooksearch::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, bookname);
	DDX_Control(pDX, IDC_EDIT2, book);
}


BEGIN_MESSAGE_MAP(Cbooksearch, CDialog)
	ON_BN_CLICKED(IDC_SEARCH, &Cbooksearch::OnBnClickedSearch)
END_MESSAGE_MAP()


// Cbooksearch 메시지 처리기


void Cbooksearch::OnBnClickedSearch()
{
	CStdioFile bookfile;
	CString name;
	CString id;
	CString sbook;
	CString number;
	CString publisher;
	CString rent;

	int count = 0;

	bookname.GetWindowText(sbook);
	setlocale(LC_ALL, "korean");
	if (bookfile.Open(L"book.txt", CFile::modeRead, NULL))
	{
		while (bookfile.ReadString(id))
		{
			bookfile.ReadString(name);
			bookfile.ReadString(publisher);
			bookfile.ReadString(rent);
			if (name == sbook)
			{
				if(rent == "o")
					book.SetWindowText(id + "		" + name + "		 " + publisher+"		" + "o");
				else
					book.SetWindowText(id + "		" + name + "		 " + publisher + "		" + "x");
				count++;
			}
		}
		if (count == 0)
		{
			MessageBox(L"찾는 책이 없습니다.");
		}
		count = 0;
	}
}
