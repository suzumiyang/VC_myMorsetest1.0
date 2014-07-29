#pragma once

#define MODE_NORMAL 0


#define FX_C2CODE	0
#define FX_CODE2C	1

class CMorseTrans
{
public:
	CMorseTrans(void);
	~CMorseTrans(void);
	/////////函数
	CString TransStr(CString strin);		//翻译主函数
	CString TransStrNormal(CString strin);	//翻译子函数：正常（26字母+数字（长）+符号）


	/////////变量

	//字符串
	CString m_strfrom;	//输入
	CString m_strto;	//输出
	CString m_strtobtn;	//输出

	//控制字符串
	CString m_btnd;		//字符：.  (默认 .)
	CString m_btnh;		//字符：-  (默认 -)
	CString m_btnx;		//字符：/  (默认 /)

	//控制
	int m_mode;			//翻译模式
	int fx;				//翻译方向（0:字符到编码 1:编码到字符）
private:
	//字符集
	int		m_cnt_def;		//个数
	CString m_in_def[26];	//26个字符
	CString m_out_def[26];	//26个字符

	int		m_cnt_numl;		//个数
	CString m_in_numl[10];	//10个数字（长）
	CString m_out_numl[10];	//10个数字（长）

	int		m_cnt_nums;		//个数
	CString m_in_nums[10];	//10个数字（短）
	CString m_out_nums[10];	//10个数字（短）

	int		m_cnt_fh;		//个数
	CString m_in_fh[50];	//符号
	CString m_out_fh[50];	//符号

	//短语

};

