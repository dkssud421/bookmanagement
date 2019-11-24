// Cbooklent.cpp: 구현 파일
//

#include "pch.h"
#include "bookmanagement.h"
#include "Cbooklent.h"
#include "afxdialogex.h"


// Cbooklent 대화 상자

IMPLEMENT_DYNAMIC(Cbooklent, CDialog)

Cbooklent::Cbooklent(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_RENT, pParent)
{

}

Cbooklent::~Cbooklent()
{
}

void Cbooklent::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, bookrent);
}


BEGIN_MESSAGE_MAP(Cbooklent, CDialog)
	ON_BN_CLICKED(IDC_RENT, &Cbooklent::OnBnClickedRent)
END_MESSAGE_MAP()


// Cbooklent 메시지 처리기


void Cbooklent::OnBnClickedRent()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
