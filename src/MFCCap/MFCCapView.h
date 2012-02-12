// MFCCapView.h : CMFCCapView ��Ľӿ�
//
#include <cxcore.h>
#include <highgui.h>

#pragma once


class CMFCCapView : public CFormView
{
protected: // �������л�����
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
// ����
public:
	CMFCCapDoc* GetDocument() const;
	static DWORD WINAPI ThreadPorc(LPVOID lpParam);
// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	void DrawPicToHDC(IplImage *img, UINT ID);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���
	
// ʵ��
public:
	virtual ~CMFCCapView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // MFCCapView.cpp �еĵ��԰汾
inline CMFCCapDoc* CMFCCapView::GetDocument() const
   { return reinterpret_cast<CMFCCapDoc*>(m_pDocument); }
#endif

