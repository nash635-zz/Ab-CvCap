// MFCCapDoc.cpp : CMFCCapDoc 类的实现
//

#include "stdafx.h"
#include "MFCCap.h"

#include "MFCCapDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCCapDoc

IMPLEMENT_DYNCREATE(CMFCCapDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCCapDoc, CDocument)
END_MESSAGE_MAP()


// CMFCCapDoc 构造/析构

CMFCCapDoc::CMFCCapDoc()
{
	// TODO: 在此添加一次性构造代码

}

CMFCCapDoc::~CMFCCapDoc()
{
}

BOOL CMFCCapDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMFCCapDoc 序列化

void CMFCCapDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CMFCCapDoc 诊断

#ifdef _DEBUG
void CMFCCapDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCCapDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCCapDoc 命令
