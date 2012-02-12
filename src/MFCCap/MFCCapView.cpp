// MFCCapView.cpp : CMFCCapView 类的实现
//

#include "stdafx.h"
#include "MFCCap.h"

#include "MFCCapDoc.h"
#include "MFCCapView.h"
#include <iostream>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCCapView

IMPLEMENT_DYNCREATE(CMFCCapView, CFormView)

BEGIN_MESSAGE_MAP(CMFCCapView, CFormView)
	ON_BN_CLICKED(IDC_GETIMG, &CMFCCapView::OnBnClickedGetimg)
	ON_BN_CLICKED(IDC_RECORD, &CMFCCapView::OnBnClickedRecord)
	ON_BN_CLICKED(IDC_STOPREC, &CMFCCapView::OnBnClickedStoprec)
	ON_BN_CLICKED(IDC_DEBUG, &CMFCCapView::OnBnClickedDebug)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCCapView::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_OPEN, &CMFCCapView::OnBnClickedOpen)
	ON_BN_CLICKED(IDC_PLAY, &CMFCCapView::OnBnClickedPlay)
END_MESSAGE_MAP()

// CMFCCapView 构造/析构

CMFCCapView::CMFCCapView()
: CFormView(CMFCCapView::IDD)
{
	// TODO: 在此处添加构造代码
	capture = 0;
	current_frame_rgb = 0;
	m_bRun = false;
	m_brec = false;
	writer = 0;
	writer = cvCreateVideoWriter("out.avi",CV_FOURCC('D','I','V','X'),15,cvSize(320,240),1);
}

CMFCCapView::~CMFCCapView()
{
	DWORD exitCode;
	GetExitCodeThread(hThread,&exitCode);
	if(exitCode == STILL_ACTIVE)
	{
		TerminateThread(hThread,exitCode);
//		AfxMessageBox("OK");
	}
	cvReleaseVideoWriter(&writer);
	m_bRun = false;
}

void CMFCCapView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CMFCCapView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CMFCCapView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CMFCCapView 诊断

#ifdef _DEBUG
void CMFCCapView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMFCCapView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMFCCapDoc* CMFCCapView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCCapDoc)));
	return (CMFCCapDoc*)m_pDocument;
}
#endif //_DEBUG

void CMFCCapView::DrawPicToHDC(IplImage *img, UINT ID)
{
	CDC *pDC = GetDlgItem(ID)->GetDC();
	HDC hDC= pDC->GetSafeHdc(); 
	CRect rect;
	GetDlgItem(ID)->GetClientRect(&rect);
	CvvImage cimg;
	cimg.CopyOf(img);
	cimg.DrawToHDC(hDC,&rect);
	ReleaseDC(pDC);
} 
// CMFCCapView 消息处理程序

DWORD WINAPI ThreadProc(LPVOID lpParam)
{
	IplImage *current_frame_rgb = cvCreateImage(cvSize(320, 240), IPL_DEPTH_16U, 3);
	//	cvNamedWindow("Window 0", 0); 
	CMFCCapView* lp = (CMFCCapView*)lpParam; 
	while(lp->capture && lp->m_bRun)
	{
		current_frame_rgb = cvQueryFrame(lp->capture);//获得一帧图象
		//		cvShowImage("Window 0",current_frame_rgb); 
		lp->DrawPicToHDC(current_frame_rgb,IDC_PICSHOW);		
		if(lp->m_brec)
		{
			if (current_frame_rgb != 0 && current_frame_rgb != 0)
				cout<<"OK!"<<endl;
			cvWriteFrame(lp->writer,current_frame_rgb);
		}
	}
	return 0;
}

void CMFCCapView::OnBnClickedGetimg()
{
	capture = cvCaptureFromCAM(0);
	if(!capture)
	{
		AfxMessageBox("获取文件失败！");
		return;
	}
	m_bRun = true;
	hThread=CreateThread(NULL,
		0,
		ThreadProc,
		(LPVOID)this,
		0,
		&ThreadID);
	if(hThread != NULL)
	{
		AfxMessageBox("工作线程已启动！");
	}
	else
	{
		m_bRun = false;
		AfxMessageBox("工作线程启动失败！");
		//		SetDlgItemText(IDC_STATE,"OFF");
	}
}
void CMFCCapView::OnBnClickedRecord()
{
	if(m_brec == true)
	{
		AfxMessageBox("请勿重复开始");
	}
	else
	{
		m_brec = true;
		AfxMessageBox("开始视频录制！");
	}
}

void CMFCCapView::OnBnClickedStoprec()
{
	if(m_brec = false)
	{
		AfxMessageBox("视频录制已经停止或尚未开启！");
	}
	else
	{
		m_brec = false;
		AfxMessageBox("视频录制已经停止！");
	}
}

void CMFCCapView::OnBnClickedDebug()
{
	AllocConsole();
	freopen( "CONOUT$", "w+t", stdout );// 申请写
	freopen( "CONIN$", "r+t", stdin );  // 申请读
}

void CMFCCapView::OnBnClickedButton5()
{
	FreeConsole();
}

void CMFCCapView::OnBnClickedOpen()
{
	CString FilePathName;
	CFileDialog dlg(TRUE);///TRUE为OPEN对话框，FALSE为SAVE AS对话框
	if(dlg.DoModal()==IDOK)
		FilePathName=dlg.GetPathName();
	SetDlgItemText(IDC_FILESTRING,FilePathName);
}

void CMFCCapView::OnBnClickedPlay()
{
	CvVideoWriter * writer1 = cvCreateVideoWriter("c:\\1.avi",CV_FOURCC('D','I','V','X'),20,cvSize(640,480));
	CString str;
	GetDlgItemText(IDC_FILESTRING,str);
	AfxMessageBox(str);
	CvCapture* capture = cvCreateFileCapture(str.GetBuffer());
	IplImage* frame;  
	while(1)
	{
		frame = cvQueryFrame( capture );
		if( !frame ) 
			break;
		cvWriteFrame(writer1,frame); //写入文件
		DrawPicToHDC(frame,IDC_PICSHOW);
		Sleep(33);
	}
}
