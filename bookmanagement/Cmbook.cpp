// Cmbook.cpp: 구현 파일
//

#include "pch.h"
#include "bookmanagement.h"
#include "bookmanagementDlg.h"
#include "afxdialogex.h"
#include "Cbookadd.h"

// Cmbook 대화 상자

IMPLEMENT_DYNAMIC(Cmbook, CDialog)

Cmbook::Cmbook(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_MBOOK, pParent)
{

}

Cmbook::~Cmbook()
{
}

void Cmbook::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cmbook, CDialog)
	ON_BN_CLICKED(IDC_ADD, &Cmbook::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_DELETE, &Cmbook::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_SEARCH, &Cmbook::OnBnClickedSearch)
END_MESSAGE_MAP()


// Cmbook 메시지 처리기

void Cmbook::OnBnClickedAdd()
{
	m_bookadd = new Cbookadd;
	m_bookadd->Create(IDD_BOOKADD, this);
	m_bookadd->ShowWindow(SW_SHOW);
}


void Cmbook::OnBnClickedDelete()
{
	m_bookdelete = new Cbookdelete;
	m_bookdelete->Create(IDD_DELETE, this);
	m_bookdelete->ShowWindow(SW_SHOW);
}


void Cmbook::OnBnClickedSearch()
{
	m_booksearch = new Cbooksearch;
	m_booksearch->Create(IDD_SEARCH, this);
	m_booksearch->ShowWindow(SW_SHOW);
}
