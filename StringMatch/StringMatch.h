
// StringMatch.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CStringMatchApp:
// �йش����ʵ�֣������ StringMatch.cpp
//

class CStringMatchApp : public CWinApp
{
public:
	CStringMatchApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CStringMatchApp theApp;