// Cbookrent.cpp: 구현 파일
//

#include "pch.h"
#include "bookmanagement.h"
#include "Cbookrent.h"
#include "afxdialogex.h"
#include "Cbook.h"
#include "bookmanagementDlg.h"
#include <locale.h>
// Cbookrent 대화 상자

IMPLEMENT_DYNAMIC(Cbookrent, CDialog)

Cbookrent::Cbookrent(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_RENT, pParent)
{

}

Cbookrent::~Cbookrent()
{
}

void Cbookrent::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, bookrent);
}


BEGIN_MESSAGE_MAP(Cbookrent, CDialog)
	ON_BN_CLICKED(IDC_RENT, &Cbookrent::OnBnClickedRent)
END_MESSAGE_MAP()


// Cbookrent 메시지 처리기


void Cbookrent::OnBnClickedRent()
{
	bool tf = false;
	int count = 0;
	bookrent.GetWindowText(sbooknumber);

	/*탐색*/

	if (bookfile.Open(L"book.txt", CFile::modeCreate | CFile::modeNoTruncate | CFile::modeRead))
	{
		while (bookfile.ReadString(number))
		{
			count = count % 4;
			if (count == 0)
			{
				if (sbooknumber == number)
				{
					tf = true;
					break;
				}
			}
			count++;
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
		setlocale(LC_ALL, "korean");
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

		/*도서 대여*/
		if (bookfile.Open(L"book.txt", CFile::modeCreate | CFile::modeReadWrite))
		{
			if (bookfile_D.Open(L"book_D.txt", CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite))
			{
				if (porsion.Open(L"porsion.txt", CFile::modeCreate | CFile::modeNoTruncate | CFile::modeRead))
				{
					porsion.ReadString(user_id);
					porsion.ReadString(user_name);

					while (bookfile_D.ReadString(number))
					{
						bookfile_D.ReadString(name);
						bookfile_D.ReadString(publisher);
						bookfile_D.ReadString(rent);
						if (number != sbooknumber)
						{
							bookfile.WriteString(number + "\n" + name + "\n" + publisher + "\n" + rent + "\n");
						}
						else
						{
							if (rent == "o")
							{
								count++;
								bookfile.WriteString(number + "\n" + name + "\n" + publisher + "\n" + user_id + "\n");
								MessageBox(L"대출이 완료됬습니다");
							}
							else
							{
								bookfile.WriteString(number + "\n" + name + "\n" + publisher + "\n" + rent + "\n");
								MessageBox(L"도서가 대출된 상태입니다.");
							}
						}
					}
					bookfile.Close();
					bookfile_D.Close();
					porsion.Close();
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
			MessageBox(L"파일을 열지 못했습니다.", L"경고!", MB_OK | MB_ICONHAND);
			return;
		}
	}
	else
	{
		MessageBox(L"대여할 도서가 없습니다.");
	}

	tf = false;
}
