// MFCCapDoc.cpp : CMFCCapDoc ���ʵ��
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


// CMFCCapDoc ����/����

CMFCCapDoc::CMFCCapDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CMFCCapDoc::~CMFCCapDoc()
{
}

BOOL CMFCCapDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CMFCCapDoc ���л�

void CMFCCapDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CMFCCapDoc ���

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


// CMFCCapDoc ����
