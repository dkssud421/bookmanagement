// Cbookdelete.cpp: 구현 파일
//

#include "pch.h"
#include "bookmanagement.h"
#include "Cbookdelete.h"
#include "afxdialogex.h"
#include <locale.h>
// Cbookdelete 대화 상자

IMPLEMENT_DYNAMIC(Cbookdelete, CDialog)

Cbookdelete::Cbookdelete(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DELETE, pParent)
{

}

Cbookdelete::~Cbookdelete()
{
}

void Cbookdelete::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, booknumber);
}


BEGIN_MESSAGE_MAP(Cbookdelete, CDialog)
	ON_BN_CLICKED(IDC_DELETE, &Cbookdelete::OnBnClickedDelete)
END_MESSAGE_MAP()


// Cbookdelete 메시지 처리기


void Cbookdelete::OnBnClickedDelete()
{
	bool tf = true;
	setlocale(LC_ALL, "korean");
	booknumber.GetWindowText(sbooknumber);

	/*탐색*/
	if (bookfile.Open(L"book.txt", CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite))
	{
		while (bookfile.ReadString(number))
		{
			bookfile.ReadString(name);
			bookfile.ReadString(publisher);
			bookfile.ReadString(rent);
			if (sbooknumber == number)
			{
				tf = false;
				break;
			}
		}
		bookfile.Close();
	}
	else
	{
		MessageBox(L"파일을 열지 못했습니다.", L"경고!", MB_OK | MB_ICONHAND);
		return;
	}
	
	if (!tf)
	{
		/*도서 임시저장*/
		if (bookfile.Open(L"book.txt", CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite))
		{
			if (bookfile_D.Open(L"book_D.txt", CFile::modeCreate | CFile::modeReadWrite))
			{
				while (bookfile.ReadString(number))
				{
					bookfile.ReadString(name);
					bookfile.ReadString(publisher);
					bookfile.ReadString(rent);
					bookfile_D.WriteString(number + "\n" + name + "\n" + publisher + "\n" + rent + "\n");
				}
				bookfile.Close();
				bookfile_D.Close();
			}
			else
			{
				MessageBox(L"파일을 열지 못했습니다.", L"경고!", MB_OK | MB_ICONHAND);
				return;
			}
		}
		else
		{
			MessageBox(L"파일을 열지 못했습니다.", L"경고!", MB_OK | MB_ICONHAND);
			return;
		}

		/*도서 삭제*/
		if (bookfile.Open(L"book.txt", CFile::modeCreate | CFile::modeReadWrite))
		{
			if (bookfile_D.Open(L"book_D.txt", CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite))
			{
				while (bookfile_D.ReadString(number))
				{
					bookfile_D.ReadString(name);
					bookfile_D.ReadString(publisher);
					bookfile_D.ReadString(rent);
					if (number != sbooknumber)
					{
						bookfile.WriteString(number + "\n" + name + "\n" + publisher + "\n" + rent + "\n");
					}
				}
				bookfile.Close();
				bookfile_D.Close();
				MessageBox(L"삭제가 완료됬습니다.");
			}
			else
			{
				MessageBox(L"파일을 열지 못했습니다.", L"경고!", MB_OK | MB_ICONHAND);
				return;
			}
		}
		else
		{
			MessageBox(L"파일을 열지 못했습니다.", L"경고!", MB_OK | MB_ICONHAND);
			return;
		}
	}
	else
	{
		MessageBox(L"삭제할 도서가 없습니다.");
	}
}
