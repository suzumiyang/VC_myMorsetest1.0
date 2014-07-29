
// myMorse1Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "MorseTrans.h"
#include "KeyBoard.h"
#include "Plset.h"

// CmyMorse1Dlg �Ի���
class CmyMorse1Dlg : public CDialogEx
{
// ����
public:
	CmyMorse1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MYMORSE1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

//����
	CMorseTrans m_mt;
	float  downtime;
	bool   hasvalue;
	CButton m_btnclear;
	int    m_drawpl;
	int    m_soundpl;
	//��ͼ
	COLORREF	m_color;
	CRect		m_rect;         // �洢��ͼ�ؼ��Ļ�ͼ����
    CDC			*m_pDC;         // �ؼ�����Ļ��ͼ�豸ָ��

//�Զ��庯��
	void UpdataInput();

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
