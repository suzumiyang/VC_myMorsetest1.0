#include "StdAfx.h"
#include "MorseTrans.h"


CMorseTrans::CMorseTrans(void)
{
	//��ʼ��

	//26���ַ�
	m_cnt_def = 26;
	m_in_def[0]	= _T("A");	m_out_def[0] = _T(".-");
	m_in_def[1] = _T("B");	m_out_def[1] = _T("-...");
	m_in_def[2] = _T("C");	m_out_def[2] = _T("-.-.");
	m_in_def[3] = _T("D");	m_out_def[3] = _T("-..");
	m_in_def[4] = _T("E");	m_out_def[4] = _T(".");
	m_in_def[5] = _T("F");	m_out_def[5] = _T("..-.");
	m_in_def[6] = _T("G");	m_out_def[6] = _T("--.");
	m_in_def[7] = _T("H");	m_out_def[7] = _T("....");
	m_in_def[8] = _T("I");	m_out_def[8] = _T("..");
	m_in_def[9] = _T("J");	m_out_def[9] = _T(".---");
	m_in_def[10]= _T("K");	m_out_def[10]= _T("-.-");
	m_in_def[11]= _T("L");	m_out_def[11]= _T(".-..");
	m_in_def[12]= _T("M");	m_out_def[12]= _T("--");
	m_in_def[13]= _T("N");	m_out_def[13]= _T("-.");
	m_in_def[14]= _T("O");	m_out_def[14]= _T("---");
	m_in_def[15]= _T("P");	m_out_def[15]= _T(".--.");
	m_in_def[16]= _T("Q");	m_out_def[16]= _T("--.-");
	m_in_def[17]= _T("R");	m_out_def[17]= _T(".-.");
	m_in_def[18]= _T("S");	m_out_def[18]= _T("...");
	m_in_def[19]= _T("T");	m_out_def[19]= _T("-");
	m_in_def[20]= _T("U");	m_out_def[20]= _T("..-");
	m_in_def[21]= _T("V");	m_out_def[21]= _T("...-");
	m_in_def[22]= _T("W");	m_out_def[22]= _T(".--");
	m_in_def[23]= _T("X");	m_out_def[23]= _T("-..-");
	m_in_def[24]= _T("Y");	m_out_def[24]= _T("-.--");
	m_in_def[25]= _T("Z");	m_out_def[25]= _T("--..");



	//10�����֣�����
	m_cnt_numl = 10;	
	m_in_numl[0] = _T("1");	m_out_numl[0] =  _T(".----");
	m_in_numl[1] = _T("2");	m_out_numl[1] =  _T("..---");
	m_in_numl[2] = _T("3");	m_out_numl[2] =  _T("...--");
	m_in_numl[3] = _T("4");	m_out_numl[3] =  _T("....-");
	m_in_numl[4] = _T("5");	m_out_numl[4] =  _T(".....");
	m_in_numl[5] = _T("6");	m_out_numl[5] =  _T("-....");
	m_in_numl[6] = _T("7");	m_out_numl[6] =  _T("--...");
	m_in_numl[7] = _T("8");	m_out_numl[7] =  _T("---..");
	m_in_numl[8] = _T("9");	m_out_numl[8] =  _T("----.");
	m_in_numl[9] = _T("0");	m_out_numl[9] =  _T("-----");
	

	//10�����֣��̣�
	m_cnt_nums = 10;		
	m_in_nums[0] = _T("1");	m_out_nums[0] = _T(".-");	
	m_in_nums[1] = _T("2");	m_out_nums[1] = _T("..-");	
	m_in_nums[2] = _T("3");	m_out_nums[2] = _T("...-");	
	m_in_nums[3] = _T("4");	m_out_nums[3] = _T("....-");	
	m_in_nums[4] = _T("5");	m_out_nums[4] = _T(".");	
	m_in_nums[5] = _T("6");	m_out_nums[5] = _T("-....");	
	m_in_nums[6] = _T("7");	m_out_nums[6] = _T("-...");	
	m_in_nums[7] = _T("8");	m_out_nums[7] = _T("-..");	
	m_in_nums[8] = _T("9");	m_out_nums[8] = _T("-.");	
	m_in_nums[9] = _T("0");	m_out_nums[9] = _T("-");	


	//����
	m_cnt_fh = 17;	
	m_in_fh[0] = _T(".");  m_out_fh[0] = _T(".-.-.-");		//���
	m_in_fh[1] = _T(":");  m_out_fh[1] = _T("---...");		//ð��
	m_in_fh[2] = _T(",");  m_out_fh[2] = _T("--..--");		//����
	m_in_fh[3] = _T(";");  m_out_fh[3] = _T("-.-.-.");		//�ֺ�
	m_in_fh[4] = _T("?");  m_out_fh[4] = _T("..--..");		//�ʺ�
	m_in_fh[5] = _T("=");  m_out_fh[5] = _T("-...-");		//�Ⱥ�
	m_in_fh[6] = _T("'");  m_out_fh[6] = _T(".----.");		//������
	m_in_fh[7] = _T("/");  m_out_fh[7] = _T("-..-.");		//б��
	m_in_fh[8] = _T("!");  m_out_fh[8] = _T("-.-.--");		//��̾��
	m_in_fh[9] = _T("-");  m_out_fh[9] = _T("-....-");		//���ֺ�
	m_in_fh[10]= _T("_");  m_out_fh[10]= _T("..--.-");		//�»���
	m_in_fh[11]= _T("\""); m_out_fh[11]= _T(".-..-.");		//˫����
	m_in_fh[12]= _T("(");  m_out_fh[12]= _T("-.--.");		//ǰ����
	m_in_fh[13]= _T(")");  m_out_fh[13]= _T("-.--.-");		//������
	m_in_fh[14]= _T("$");  m_out_fh[14]= _T("...-..-");	//��Ԫ
	m_in_fh[15]= _T("&");  m_out_fh[15]= _T(".-...");		//AND
	m_in_fh[16]= _T("@");  m_out_fh[16]= _T(".--.-.");		//AT
}


CMorseTrans::~CMorseTrans(void)
{
}


CString CMorseTrans::TransStr(CString strin)
{
	CString strout;
	switch(m_mode)
	{
	case MODE_NORMAL:
		strout = TransStrNormal(strin);
		break;
	}
	return strout;
}

CString CMorseTrans::TransStrNormal(CString strin)
{
	CString strout = _T("");
	int strlen = strin.GetLength();
	if(strlen <=0)
		return strout;
	int pos = 0;
	int oldpos = 0;
	CString tmp;
	while(pos < strlen)
	{
		bool isfind = false;

		if(fx == FX_C2CODE)//char to code
		{
			//����ַ�
			tmp = strin.Mid(pos,1);//���ÿ���ַ�����
			pos++;


			//��ĸ
			for(int i = 0;i < m_cnt_def;i++)
			{
				if(0 == tmp.CompareNoCase(m_in_def[i]))
				{
					isfind = true;
					strout = strout + m_out_def[i] + m_btnx;
					break;
				}
			}

			//������
			if(isfind == false)//û�ҵ�
			{
				for(int i = 0;i < m_cnt_numl;i++)
				{
					if(0 == tmp.CompareNoCase(m_in_numl[i]))
					{
						isfind = true;
						strout = strout + m_out_numl[i] + m_btnx;
						break;
					}
				}
			}

			//����
			if(isfind == false)//û�ҵ�
			{
				for(int i = 0;i < m_cnt_fh;i++)
				{
					if(0 == tmp.CompareNoCase(m_in_fh[i]))
					{
						isfind = true;
						strout = strout + m_out_fh[i] + m_btnx;
						break;
					}
				}
			}
		}
		else//code to char
		{
			//����ַ���
			pos = strin.Find(m_btnx,pos);
			if(pos == -1)
				pos = strlen;//���û�зָ�������Ϊ�����ַ�������
			tmp = strin.Mid(oldpos,pos-oldpos);//���ÿ������
			oldpos = pos;


			//��ĸ
			for(int i = 0;i < m_cnt_def;i++)
			{
				if(0 == tmp.CompareNoCase(m_out_def[i]))
				{
					isfind = true;
					strout = strout + m_in_def[i];
					break;
				}
			}

			//������
			if(isfind == false)//û�ҵ�
			{
				for(int i = 0;i < m_cnt_numl;i++)
				{
					if(0 == tmp.CompareNoCase(m_out_numl[i]))
					{
						isfind = true;
						strout = strout + m_in_numl[i];
						break;
					}
				}
			}

			//����
			if(isfind == false)//û�ҵ�
			{
				for(int i = 0;i < m_cnt_fh;i++)
				{
					if(0 == tmp.CompareNoCase(m_out_fh[i]))
					{
						isfind = true;
						strout = strout + m_in_fh[i] + m_btnx;
						break;
					}
				}
			}
		}
	}

	if(fx == FX_C2CODE)//�û���ָ������
	{
		strout.Replace(_T("."),m_btnd);
		strout.Replace(_T("-"),m_btnh);
		strout.Replace(_T("/"),m_btnx);
	}
	

	return strout;
}