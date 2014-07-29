
// myMorse1Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "MorseTrans.h"
#include "KeyBoard.h"
#include "Plset.h"

// CmyMorse1Dlg 对话框
class CmyMorse1Dlg : public CDialogEx
{
// 构造
public:
	CmyMorse1Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MYMORSE1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

//变量
	CMorseTrans m_mt;
	float  downtime;
	bool   hasvalue;
	CButton m_btnclear;
	int    m_drawpl;
	int    m_soundpl;
	//绘图
	COLORREF	m_color;
	CRect		m_rect;         // 存储绘图控件的绘图区域
    CDC			*m_pDC;         // 控件的屏幕绘图设备指针

//自定义函数
	void UpdataInput();

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_codelist;
	CEdit m_editd;
	CEdit m_edith;
	CEdit m_editx;
	CEdit m_editpush;
	CEdit m_input;
	CEdit m_output;
	afx_msg void OnEnChangeInput();
	afx_msg void OnEnChangeEditd();
	afx_msg void OnEnChangeEdith();
	afx_msg void OnEnChangeEditx();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedBtnclear();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnBnClickedBtnkey();
	afx_msg void OnBnClickedButtonColor();
	afx_msg void OnBnClickedBtnset();
	afx_msg void OnBnClickedBtnsound();
};
