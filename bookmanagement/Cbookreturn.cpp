// Cbookreturn.cpp: 구현 파일
//

#include "pch.h"
#include "bookmanagement.h"
#include "Cbookreturn.h"
#include "afxdialogex.h"


// Cbookreturn 대화 상자

IMPLEMENT_DYNAMIC(Cbookreturn, CDialog)

Cbookreturn::Cbookreturn(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_RETURN, pParent)
{

}

Cbookreturn::~Cbookreturn()
{
}

void Cbookreturn::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, bookreturn);
}


BEGIN_MESSAGE_MAP(Cbookreturn, CDialog)
	ON_BN_CLICKED(IDC_RETURN, &Cbookreturn::OnBnClickedReturn)
END_MESSAGE_MAP()


// Cbookreturn 메시지 처리기


void Cbookreturn::OnBnClickedReturn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	bool tf = false;
	int count = 0;

	bookreturn.GetWindowText(sbooknumber);

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

		/*도서 반납*/
		if (bookfile.Open(L"book.txt", CFile::modeCreate | CFile::modeReadWrite))
		{
			if (bookfile_D.Open(L"book_D.txt", CFile::modeCreate | CFile::modeNoTruncate | CFile::modeRead))
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
							if (rent == user_id)
							{
								bookfile.WriteString(number + "\n" + name + "\n" + publisher + "\n" + "o"+ "\n");
								MessageBox(L"반납이 완료됬습니다");
							}
							else
							{
								bookfile.WriteString(number + "\n" + name + "\n" + publisher + "\n" + rent + "\n");
								MessageBox(L"대여한 책이 아닙니다.");
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
		MessageBox(L"반납할 책이 잘못됬습니다.");
	}
	count = 0; tf = false;
}
