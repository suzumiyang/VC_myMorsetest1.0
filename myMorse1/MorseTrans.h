#pragma once

#define MODE_NORMAL 0


#define FX_C2CODE	0
#define FX_CODE2C	1

class CMorseTrans
{
public:
	CMorseTrans(void);
	~CMorseTrans(void);
	/////////����
	CString TransStr(CString strin);		//����������
	CString TransStrNormal(CString strin);	//�����Ӻ�����������26��ĸ+���֣�����+���ţ�


	/////////����

	//�ַ���
	CString m_strfrom;	//����
	CString m_strto;	//���
	CString m_strtobtn;	//���

	//�����ַ���
	CString m_btnd;		//�ַ���.  (Ĭ�� .)
	CString m_btnh;		//�ַ���-  (Ĭ�� -)
	CString m_btnx;		//�ַ���/  (Ĭ�� /)

	//����
	int m_mode;			//����ģʽ
	int fx;				//���뷽��0:�ַ������� 1:���뵽�ַ���
private:
	//�ַ���
	int		m_cnt_def;		//����
	CString m_in_def[26];	//26���ַ�
	CString m_out_def[26];	//26���ַ�

	int		m_cnt_numl;		//����
	CString m_in_numl[10];	//10�����֣�����
	CString m_out_numl[10];	//10�����֣�����

	int		m_cnt_nums;		//����
	CString m_in_nums[10];	//10�����֣��̣�
	CString m_out_nums[10];	//10�����֣��̣�

	int		m_cnt_fh;		//����
	CString m_in_fh[50];	//����
	CString m_out_fh[50];	//����

	//����

};

