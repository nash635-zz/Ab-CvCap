// MFCCap.h : MFCCap Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCCapApp:
// �йش����ʵ�֣������ MFCCap.cpp
//

class CMFCCapApp : public CWinApp
{
public:
	CMFCCapApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCCapApp theApp;