
// StringMatchDlg.h : ͷ�ļ�
//

#pragma once


// CStringMatchDlg �Ի���
class CStringMatchDlg : public CDialogEx
{
// ����
public:
	CStringMatchDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_STRINGMATCH_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString str_P;
	CString str_T;
	CString str_BF;
	CString str_KMP;
	CString str_BM;
	afx_msg void OnBnClickedGeneP();
	int P_length;
	int T_length;
	afx_msg void OnBnClickedGeneT();
	//afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButtonBf();
	afx_msg void OnBnClickedButtonKmp();
	afx_msg void OnBnClickedButtonBm();
	afx_msg void OnBnClickedButtonReadP();
	afx_msg void OnBnClickedButtonReadT();
};

