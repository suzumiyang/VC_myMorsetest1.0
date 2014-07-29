// KeyBoard.cpp : 实现文件
//

#include "stdafx.h"
#include "myMorse1.h"
#include "KeyBoard.h"
#include "afxdialogex.h"


// CKeyBoard 对话框

IMPLEMENT_DYNAMIC(CKeyBoard, CDialogEx)

CKeyBoard::CKeyBoard(CWnd* pParent /*=NULL*/)
	: CDialogEx(CKeyBoard::IDD, pParent)
{
	hasvalue = true;
	m_mt.m_btnd = _T(".");
	m_mt.m_btnh = _T("-");
	m_mt.m_btnx = _T("/");
}

CKeyBoard::~CKeyBoard()
{
}

void CKeyBoard::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CKeyBoard, CDialogEx)
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CKeyBoard 消息处理程序


void CKeyBoard::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if(hasvalue == true)
	{
		this->SetWindowTextW(_T(""));
		hasvalue = false;
	}

	downtime = 0;
	SetTimer(0,1,NULL);

	CString tstr;
	tstr.Format(_T("KEY DOWN\n"));
	OutputDebugString(tstr);

	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CKeyBoard::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CString tstra;
	tstra.Format(_T("KEY UP\n"));
	OutputDebugString(tstra);

	KillTimer(0);
	CString tstr;
	this->GetWindowTextW(tstr);

	if (downtime > 30)
	{
		tstr = tstr + m_mt.m_btnh;
	}
	else
	{
		tstr = tstr + m_mt.m_btnd;
	}
	this->SetWindowTextW(tstr);
	downtime = 0;

	SetTimer(1,1,NULL);


	CDialogEx::OnKeyUp(nChar, nRepCnt, nFlags);
}


void CKeyBoard::OnTimer(UINT_PTR nIDEvent)
{
	CString tstr;
	switch(nIDEvent)
	{
	case 0:
		tstr.Format(_T("0 + 1:%d\n"),downtime + 1);
		OutputDebugString(tstr);
		downtime++;//计数+1
		break;
	case 1:
		tstr.Format(_T("1 + 1:%d\n"),downtime + 1);
		OutputDebugString(tstr);
		downtime++;
		if(downtime > 100)
		{
			KillTimer(1);
			CString tstr;
			this->GetWindowTextW(tstr);

			m_mt.m_mode = MODE_NORMAL;
			m_mt.fx     = FX_CODE2C;
	
			CString strout;
			strout = tstr + _T(" = ") + m_mt.TransStr(tstr);
			this->SetWindowTextW(strout);
			hasvalue = true;
			
		}
		break;
	}
	

	CDialogEx::OnTimer(nIDEvent);
}
