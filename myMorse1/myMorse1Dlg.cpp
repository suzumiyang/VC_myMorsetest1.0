
// myMorse1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "myMorse1.h"
#include "myMorse1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmyMorse1Dlg 对话框




CmyMorse1Dlg::CmyMorse1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CmyMorse1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmyMorse1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CODELIST, m_codelist);
	DDX_Control(pDX, IDC_EDITD, m_editd);
	DDX_Control(pDX, IDC_EDITH, m_edith);
	DDX_Control(pDX, IDC_EDITX, m_editx);
	DDX_Control(pDX, IDC_PUSHEDIT, m_editpush);
	DDX_Control(pDX, IDC_INPUT, m_input);
	DDX_Control(pDX, IDC_OUTPUT, m_output);
	DDX_Control(pDX, IDC_BTNCLEAR, m_btnclear);
}

BEGIN_MESSAGE_MAP(CmyMorse1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_INPUT, &CmyMorse1Dlg::OnEnChangeInput)
	ON_EN_CHANGE(IDC_EDITD, &CmyMorse1Dlg::OnEnChangeEditd)
	ON_EN_CHANGE(IDC_EDITH, &CmyMorse1Dlg::OnEnChangeEdith)
	ON_EN_CHANGE(IDC_EDITX, &CmyMorse1Dlg::OnEnChangeEditx)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BTNCLEAR, &CmyMorse1Dlg::OnBnClickedBtnclear)
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_BN_CLICKED(IDC_BTNKEY, &CmyMorse1Dlg::OnBnClickedBtnkey)
	ON_BN_CLICKED(IDC_BTNCOLOR, &CmyMorse1Dlg::OnBnClickedButtonColor)
	ON_BN_CLICKED(IDC_BTNSET, &CmyMorse1Dlg::OnBnClickedBtnset)
	ON_BN_CLICKED(IDC_BTNSOUND, &CmyMorse1Dlg::OnBnClickedBtnsound)
END_MESSAGE_MAP()


// CmyMorse1Dlg 消息处理程序

BOOL CmyMorse1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//初始化list
	m_codelist.AddString(_T("默认（长数字）"));
	m_codelist.AddString(_T("默认（短数字）"));

	//表示符
	m_editd.SetWindowTextW(_T("."));
	m_edith.SetWindowTextW(_T("-"));
	m_editx.SetWindowTextW(_T("/"));
	m_mt.m_btnd = _T(".");
	m_mt.m_btnh = _T("-");
	m_mt.m_btnx = _T("/");

	//默认字符
	m_input.SetWindowTextW(_T("Hello"));
	m_output.SetWindowTextW(_T("...././.-../.-../---"));

	//变量
	hasvalue = false;

	
	//绘图用变量初始化
	m_pDC = GetDC();
	m_color = RGB(255,255,255);
	m_drawpl = 100;
	m_soundpl = 100;

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CmyMorse1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CmyMorse1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CmyMorse1Dlg::OnEnChangeInput()
{
	UpdataInput();
}

void CmyMorse1Dlg::UpdataInput()
{
	CString strin;
	CString strout;
	m_input.GetWindowTextW(strin);
	//MessageBox(strin);

	//临时
	m_mt.m_mode = MODE_NORMAL;
	m_mt.fx     = FX_C2CODE;
	
	strout = m_mt.TransStr(strin);
	m_output.SetWindowTextW(strout);
}


void CmyMorse1Dlg::OnEnChangeEditd()
{
	int strlen = m_editd.GetWindowTextLengthW();
	CString tmp;
	m_editd.GetWindowTextW(tmp);
	if(strlen > 1)
	{
		tmp = tmp.Mid(0,1);//取第一个字符
	}
	if(strlen >0)
	{
		m_mt.m_btnd = tmp;
		UpdataInput();
	}
}


void CmyMorse1Dlg::OnEnChangeEdith()
{
	int strlen = m_edith.GetWindowTextLengthW();
	CString tmp;
	m_edith.GetWindowTextW(tmp);
	if(strlen > 1)
	{
		tmp = tmp.Mid(0,1);//取第一个字符
	}
	if(strlen >0)
	{
		m_mt.m_btnh = tmp;
		UpdataInput();
	}
}


void CmyMorse1Dlg::OnEnChangeEditx()
{
	int strlen = m_editx.GetWindowTextLengthW();
	CString tmp;
	m_editx.GetWindowTextW(tmp);
	if(strlen > 1)
	{
		tmp = tmp.Mid(0,1);//取第一个字符
	}
	if(strlen >0)
	{
		m_mt.m_btnx = tmp;
		UpdataInput();
	}
}


void CmyMorse1Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	if(hasvalue == true)
	{
		m_editpush.SetWindowTextW(_T(""));
		hasvalue = false;
	}
	

	downtime = 0;
	SetTimer(0,1,NULL);

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CmyMorse1Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	KillTimer(0);
	CString tstr;
	m_editpush.GetWindowTextW(tstr);

	if (downtime > 30)
	{
		tstr = tstr + m_mt.m_btnh;
	}
	else
	{
		tstr = tstr + m_mt.m_btnd;
	}
	m_editpush.SetWindowTextW(tstr);
	downtime = 0;

	SetTimer(1,1,NULL);


	CDialogEx::OnLButtonUp(nFlags, point);
}


void CmyMorse1Dlg::OnTimer(UINT_PTR nIDEvent)
{
	switch(nIDEvent)
	{
	case 0:
		downtime++;//计数+1
		break;
	case 1:
		downtime++;
		if(downtime > 100)
		{
			KillTimer(1);
			CString tstr;
			m_editpush.GetWindowTextW(tstr);

			m_mt.m_mode = MODE_NORMAL;
			m_mt.fx     = FX_CODE2C;
	
			CString strout;
			strout = tstr + _T(" = ") + m_mt.TransStr(tstr);
			m_editpush.SetWindowTextW(strout);
			hasvalue = true;
			
		}
		break;
	}
	


	CDialogEx::OnTimer(nIDEvent);
}


void CmyMorse1Dlg::OnBnClickedBtnclear()
{
	m_editpush.SetWindowTextW(_T(""));
	
}


void CmyMorse1Dlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)//not use
{

	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CmyMorse1Dlg::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)//not use
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnKeyUp(nChar, nRepCnt, nFlags);
}


void CmyMorse1Dlg::OnBnClickedBtnkey()
{
	CKeyBoard ckb;
	ckb.DoModal();
}


void CmyMorse1Dlg::OnBnClickedButtonColor()
{
	CBrush *oldbrush;
	CBrush blackbrush(RGB(0,0,0));
	CBrush whitebrush(m_color);
	oldbrush = m_pDC->SelectObject(&blackbrush);
	m_pDC->Rectangle(194,60,273,140);
	Sleep(3000);
	
	int strlen = m_output.GetWindowTextLengthW();
	if(strlen > 0)
	{
		CString tstr;
		m_output.GetWindowTextW(tstr);
		for(int i = 0;i < strlen;i++)
		{
			if(tstr.Mid(i,1) == _T("."))
			{
				m_pDC->SelectObject(&whitebrush);
				m_pDC->Rectangle(194,60,273,140);
				Sleep(m_drawpl);
			}
			else if(tstr.Mid(i,1) == _T("-"))
			{
				m_pDC->SelectObject(&whitebrush);
				m_pDC->Rectangle(194,60,273,140);
				Sleep(m_drawpl*2);
			}
			else
			{
				m_pDC->SelectObject(blackbrush);
				m_pDC->Rectangle(194,60,273,140);
				Sleep(m_drawpl*2);
			}

			m_pDC->SelectObject(blackbrush);
			m_pDC->Rectangle(194,60,273,140);
			Sleep(m_drawpl);
		}
	}
	
	
	
}


void CmyMorse1Dlg::OnBnClickedBtnset()
{
	CPlset cpl;
	cpl.m_soundpl = m_soundpl;
	cpl.m_drawpl  = m_drawpl;
	cpl.m_color   = m_color;

	cpl.DoModal();

	m_soundpl = cpl.m_soundpl;
	m_drawpl  = cpl.m_drawpl;
	m_color   = cpl.m_color;
}


void CmyMorse1Dlg::OnBnClickedBtnsound()
{

	int strlen = m_output.GetWindowTextLengthW();
	if(strlen > 0)
	{
		CString tstr;
		m_output.GetWindowTextW(tstr);
		for(int i = 0;i < strlen;i++)
		{
			if(tstr.Mid(i,1) == _T("."))
			{
				Beep(15000,m_drawpl);
				Sleep(m_drawpl);
			}
			else if(tstr.Mid(i,1) == _T("-"))
			{
				Beep(15000,m_drawpl);
				Sleep(m_drawpl*2);
			}
			else
			{
				Sleep(m_drawpl*2);
			}

			Sleep(m_drawpl);
		}
	}
	
}
