// MFCCapDoc.h : CMFCCapDoc ��Ľӿ�
//


#pragma once


class CMFCCapDoc : public CDocument
{
protected: // �������л�����
	CMFCCapDoc();
	DECLARE_DYNCREATE(CMFCCapDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CMFCCapDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


