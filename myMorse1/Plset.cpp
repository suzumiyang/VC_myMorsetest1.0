// Plset.cpp : 实现文件
//

#include "stdafx.h"
#include "myMorse1.h"
#include "Plset.h"
#include "afxdialogex.h"


// CPlset 对话框

IMPLEMENT_DYNAMIC(CPlset, CDialogEx)

CPlset::CPlset(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPlset::IDD, pParent)
{

}

CPlset::~CPlset()
{
}

void CPlset::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COLORPL, m_editcolor);
	DDX_Control(pDX, IDC_SOUNDPL, m_editsound);
}


BEGIN_MESSAGE_MAP(CPlset, CDialogEx)
END_MESSAGE_MAP()


// CPlset 消息处理程序
