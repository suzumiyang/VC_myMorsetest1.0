#pragma once
#include "afxwin.h"
#include "MorseTrans.h"

// CKeyBoard �Ի���

class CKeyBoard : public CDialogEx
{
	DECLARE_DYNAMIC(CKeyBoard)

public:
	CKeyBoard(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CKeyBoard();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CMorseTrans m_mt;
	int downtime;
	bool   hasvalue;
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
