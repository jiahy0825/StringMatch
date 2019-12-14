
// StringMatchDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "StringMatch.h"
#include "StringMatchDlg.h"
#include "afxdialogex.h"

#include "BM.h"
#include "BruteForce.h"
#include "KMP.h"

#include <vector>
#include <string>
#include <time.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CStringMatchDlg 对话框



CStringMatchDlg::CStringMatchDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStringMatchDlg::IDD, pParent)
	, str_P(_T(""))
	, str_T(_T(""))
	, str_BF(_T(""))
	, str_KMP(_T(""))
	, str_BM(_T(""))
	, P_length(0)
	, T_length(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStringMatchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_P, str_P);
	DDX_Text(pDX, IDC_T, str_T);
	DDX_Text(pDX, IDC_BF, str_BF);
	DDX_Text(pDX, IDC_KMP, str_KMP);
	DDX_Text(pDX, IDC_BM, str_BM);
	DDX_Text(pDX, IDC_P_length, P_length);
	DDV_MinMaxInt(pDX, P_length, 0, 5000000);
	DDX_Text(pDX, IDC_T_length, T_length);
	DDV_MinMaxInt(pDX, T_length, 0, 5000000);
}

BEGIN_MESSAGE_MAP(CStringMatchDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_GENE_P, &CStringMatchDlg::OnBnClickedGeneP)
	ON_BN_CLICKED(IDC_GENE_T, &CStringMatchDlg::OnBnClickedGeneT)
	//ON_BN_CLICKED(IDC_BUTTON3, &CStringMatchDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_BF, &CStringMatchDlg::OnBnClickedButtonBf)
	ON_BN_CLICKED(IDC_BUTTON_KMP, &CStringMatchDlg::OnBnClickedButtonKmp)
	ON_BN_CLICKED(IDC_BUTTON_BM, &CStringMatchDlg::OnBnClickedButtonBm)
	ON_BN_CLICKED(IDC_BUTTON_READ_P, &CStringMatchDlg::OnBnClickedButtonReadP)
	ON_BN_CLICKED(IDC_BUTTON_READ_T, &CStringMatchDlg::OnBnClickedButtonReadT)
END_MESSAGE_MAP()


// CStringMatchDlg 消息处理程序

BOOL CStringMatchDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CStringMatchDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CStringMatchDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CStringMatchDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


vector<char> get_sigma(){
	char ch[28] = {',', '.', '<', '>', '?', ';', ':', '[', ']', '{', '}', 
		'-', '+', '_', '=', '|', '(', ')', '*', '&', '^', '%', '$', '#', '@', '!', '~', '`'};
	vector<char> sigma = vector<char>(ch, ch + 28);
	for (char c = 'a'; c <= 'z'; c++){
		sigma.push_back(c);
	}
	for (char c = 'A'; c <= 'Z'; c++){
		sigma.push_back(c);
	}
	for (char c = '0'; c <= '9'; c++){
		sigma.push_back(c);
	}
	return sigma;
}

string generatr(int len){
	vector<char> getSigma = get_sigma();
	int n = getSigma.size();
	string res = "";
	while (len-- > 0){
		res += getSigma[rand() % n];
	}
	return res;
}


void CStringMatchDlg::OnBnClickedGeneP()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	string p = generatr(P_length);
	str_P = p.c_str();
	UpdateData(FALSE);
}


void CStringMatchDlg::OnBnClickedGeneT()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	string t = generatr(T_length);
	str_T = t.c_str();
	UpdateData(FALSE);
}

string encodeRES(vector<int>& vec){
	if (vec.empty())
		return "";
	string res = to_string(vec[0]);
	for (int i = 1;i < vec.size();i++){
		res += ", " + to_string(vec[i]);
	}
	return res;
}

void CStringMatchDlg::OnBnClickedButtonBf()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	string p = CT2A(str_P.GetBuffer());
	string t = CT2A(str_T.GetBuffer());

	clock_t start = clock();
	BruteForce strMatch;
	vector<int> res = strMatch.match(p, t);
	clock_t end = clock();

	string str = "Brute Force Runtime : " + to_string((double)(end - start) / 1000) + "s";
	str += " result length : " + to_string(res.size()) + " res index : ";
	str += encodeRES(res);
	str_BF = str.c_str();

	UpdateData(FALSE);
}


void CStringMatchDlg::OnBnClickedButtonKmp()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	string p = CT2A(str_P.GetBuffer());
	string t = CT2A(str_T.GetBuffer());

	clock_t start = clock();
	KMP strMatch;
	vector<int> res = strMatch.match(p, t);
	clock_t end = clock();

	string str = "KMP Runtime : " + to_string((double)(end - start) / 1000) + "s";
	str += " result length : " + to_string(res.size()) + " res index : ";
	str += encodeRES(res);
	str_KMP = str.c_str();

	UpdateData(FALSE);
}


void CStringMatchDlg::OnBnClickedButtonBm()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	string p = CT2A(str_P.GetBuffer());
	string t = CT2A(str_T.GetBuffer());

	clock_t start = clock();
	BM strMatch;
	vector<int> res = strMatch.match(p, t);
	clock_t end = clock();

	string str = "BM Runtime : " + to_string((double)(end - start) / 1000) + "s";
	str += " result length : " + to_string(res.size()) + " res index : ";
	str += encodeRES(res);
	str_BM = str.c_str();

	UpdateData(FALSE);
}


void CStringMatchDlg::OnBnClickedButtonReadP()
{
	// TODO: 在此添加控件通知处理程序代码
    char szFilters[] = 
        "Text File(*.txt)\0*.txt\0"\
		"C++ source file(*.h;*,hpp;*.cpp)\0*.h;*.hpp;*.cpp\0"\
        "All Typle(*.*)\0*.*\0" \
        "Lua source file(*.lua)\0*.lua\0"\
        "\0";
 
    CFileDialog OpenDlg(TRUE);
    OpenDlg.m_ofn.lpstrTitle = "Open File";
    OpenDlg.m_ofn.lpstrFilter = szFilters;
 
    if (IDOK == OpenDlg.DoModal())
    {
        CFile File;
        CFileException e;
        //构造文件，同时增加异常处理
        if(!File.Open(OpenDlg.GetPathName(), CFile::modeRead,&e))
        {
            CString strErr;
            strErr.Format(_T("File could not be opened %d\n"), e.m_cause);
            MessageBox(strErr);
        }
        //创建指定大小的Buffer
        DWORD  dwFileLenth = (DWORD)File.GetLength();
        //初始化buffer， 增加一个/0空间
        char *pBuf = new char[dwFileLenth + 1];
        memset(pBuf, 0, dwFileLenth + 1);
 
        if (pBuf != NULL)
        {
            //读取文件内容
            File.Read(pBuf,dwFileLenth);
            File.Close();
            //显示文件内容
			str_P = pBuf;
            //MessageBox(pBuf);
            //删除bufer，避免内存泄漏
            delete[] pBuf;
            pBuf = NULL;
        }
    }
	UpdateData(FALSE);
}

void CStringMatchDlg::OnBnClickedButtonReadT()
{
	// TODO: 在此添加控件通知处理程序代码
	char szFilters[] = 
        "Text File(*.txt)\0*.txt\0"\
		"C++ source file(*.h;*,hpp;*.cpp)\0*.h;*.hpp;*.cpp\0"\
        "All Typle(*.*)\0*.*\0" \
        "Lua source file(*.lua)\0*.lua\0"\
        "\0";
 
    CFileDialog OpenDlg(TRUE);
    OpenDlg.m_ofn.lpstrTitle = "Open File";
    OpenDlg.m_ofn.lpstrFilter = szFilters;
 
    if (IDOK == OpenDlg.DoModal())
    {
        CFile File;
        CFileException e;
        //构造文件，同时增加异常处理
        if(!File.Open(OpenDlg.GetPathName(), CFile::modeRead,&e))
        {
            CString strErr;
            strErr.Format(_T("File could not be opened %d\n"), e.m_cause);
            MessageBox(strErr);
        }
        //创建指定大小的Buffer
        DWORD  dwFileLenth = (DWORD)File.GetLength();
        //初始化buffer， 增加一个/0空间
        char *pBuf = new char[dwFileLenth + 1];
        memset(pBuf, 0, dwFileLenth + 1);
 
        if (pBuf != NULL)
        {
            //读取文件内容
            File.Read(pBuf,dwFileLenth);
            File.Close();
            //显示文件内容T
			str_T = pBuf;
            //MessageBox(pBuf);
            //删除bufer，避免内存泄漏
            delete[] pBuf;
            pBuf = NULL;
        }
    }
	UpdateData(FALSE);
}
