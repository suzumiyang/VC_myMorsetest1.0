#pragma once
#include "afxwin.h"


// CPlset �Ի���

class CPlset : public CDialogEx
{
	DECLARE_DYNAMIC(CPlset)

public:
	CPlset(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPlset();

	COLORREF m_color;
	int		 m_soundpl;
	int		 m_drawpl;

// �Ի�������
	enum { IDD = IDD_DLGSET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_editcolor;
	CEdit m_editsound;
};
