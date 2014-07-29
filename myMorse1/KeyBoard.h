#pragma once
#include "afxwin.h"
#include "MorseTrans.h"

// CKeyBoard 对话框

class CKeyBoard : public CDialogEx
{
	DECLARE_DYNAMIC(CKeyBoard)

public:
	CKeyBoard(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CKeyBoard();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CMorseTrans m_mt;
	int downtime;
	bool   hasvalue;
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
