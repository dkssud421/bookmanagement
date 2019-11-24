// Cbook.cpp: 구현 파일
//

#include "pch.h"
#include "bookmanagement.h"
#include "Cbook.h"
#include "afxdialogex.h"


// Cbook 대화 상자

IMPLEMENT_DYNAMIC(Cbook, CDialog)

Cbook::Cbook(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_BOOK, pParent)
{

}

Cbook::~Cbook()
{
}

void Cbook::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cbook, CDialog)
	ON_BN_CLICKED(IDC_SEARCH, &Cbook::OnBnClickedSearch)
	ON_BN_CLICKED(IDC_RENT, &Cbook::OnBnClickedRent)
	ON_BN_CLICKED(IDC_RETURN, &Cbook::OnBnClickedReturn)
END_MESSAGE_MAP()


// Cbook 메시지 처리기


void Cbook::OnBnClickedSearch()
{
	m_booksearch = new Cbooksearch;
	m_booksearch->Create(IDD_SEARCH, this);
	m_booksearch->ShowWindow(SW_SHOW);
}


void Cbook::OnBnClickedRent()
{
	m_bookrent = new Cbookrent;
	m_bookrent->Create(IDD_RENT, this);
	m_bookrent->ShowWindow(SW_SHOW);
}


void Cbook::OnBnClickedReturn()
{
	m_bookreturn = new Cbookreturn;
	m_bookreturn->Create(IDD_RETURN, this);
	m_bookreturn->ShowWindow(SW_SHOW);
}
