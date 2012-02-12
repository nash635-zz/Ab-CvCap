// MFCCapView.h : CMFCCapView 类的接口
//
#include <cxcore.h>
#include <highgui.h>

#pragma once


class CMFCCapView : public CFormView
{
protected: // 仅从序列化创建
	CMFCCapView();
	DECLARE_DYNCREATE(CMFCCapView)

public:
	enum{ IDD = IDD_MFCCAP_FORM };
	CvCapture* capture; 
	IplImage *current_frame_rgb;
	DWORD ThreadID;
	bool m_bRun,m_brec;
	HANDLE hThread;
	CvVideoWriter *writer;
// 属性
public:
	CMFCCapDoc* GetDocument() const;
	static DWORD WINAPI ThreadPorc(LPVOID lpParam);
// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	void DrawPicToHDC(IplImage *img, UINT ID);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
	
// 实现
public:
	virtual ~CMFCCapView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedGetimg();
public:
	afx_msg void OnBnClickedRecord();
public:
	afx_msg void OnBnClickedStoprec();
public:
	afx_msg void OnBnClickedDebug();
public:
	afx_msg void OnBnClickedButton5();
public:
	afx_msg void OnBnClickedOpen();
public:
	afx_msg void OnBnClickedPlay();
};

#ifndef _DEBUG  // MFCCapView.cpp 中的调试版本
inline CMFCCapDoc* CMFCCapView::GetDocument() const
   { return reinterpret_cast<CMFCCapDoc*>(m_pDocument); }
#endif

