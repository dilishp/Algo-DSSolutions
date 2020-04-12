
// StateAbbreviationMFCView.cpp : implementation of the CStateAbbreviationMFCView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "StateAbbreviationMFC.h"
#endif

#include "StateAbbreviationMFCDoc.h"
#include "StateAbbreviationMFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStateAbbreviationMFCView

IMPLEMENT_DYNCREATE(CStateAbbreviationMFCView, CView)

BEGIN_MESSAGE_MAP(CStateAbbreviationMFCView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CStateAbbreviationMFCView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CStateAbbreviationMFCView construction/destruction

CStateAbbreviationMFCView::CStateAbbreviationMFCView() noexcept
{
	// TODO: add construction code here

}

CStateAbbreviationMFCView::~CStateAbbreviationMFCView()
{
}

BOOL CStateAbbreviationMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CStateAbbreviationMFCView drawing

void CStateAbbreviationMFCView::OnDraw(CDC* /*pDC*/)
{
	CStateAbbreviationMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CStateAbbreviationMFCView printing


void CStateAbbreviationMFCView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CStateAbbreviationMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CStateAbbreviationMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CStateAbbreviationMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CStateAbbreviationMFCView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CStateAbbreviationMFCView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CStateAbbreviationMFCView diagnostics

#ifdef _DEBUG
void CStateAbbreviationMFCView::AssertValid() const
{
	CView::AssertValid();
}

void CStateAbbreviationMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStateAbbreviationMFCDoc* CStateAbbreviationMFCView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStateAbbreviationMFCDoc)));
	return (CStateAbbreviationMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CStateAbbreviationMFCView message handlers
