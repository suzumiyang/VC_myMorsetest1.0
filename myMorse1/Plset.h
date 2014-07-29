#pragma once
#include "afxwin.h"


// CPlset 对话框

class CPlset : public CDialogEx
{
	DECLARE_DYNAMIC(CPlset)

public:
	CPlset(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPlset();

	COLORREF m_color;
	int		 m_soundpl;
	int		 m_drawpl;

// 对话框数据
	enum { IDD = IDD_DLGSET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_editcolor;
	CEdit m_editsound;
};
