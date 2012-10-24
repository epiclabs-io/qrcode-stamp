// QRCStampCtrl.cpp :  CQRCStampCtrl ActiveX コントロール クラスの実装

#include "stdafx.h"
#include "QRCStamp.h"
#include "QRCStampCtrl.h"
#include "QRCStampPropPage.h"

#include <qrencode.h>

#pragma comment(lib, "version.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CQRCStampCtrl, COleControl)



// メッセージ マップ

BEGIN_MESSAGE_MAP(CQRCStampCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()



// ディスパッチ マップ

BEGIN_DISPATCH_MAP(CQRCStampCtrl, COleControl)
	DISP_FUNCTION_ID(CQRCStampCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)

	DISP_PROPERTY_EX_ID(CQRCStampCtrl, "Value", dispidValue, GetValue, SetValue, VT_VARIANT)
	DISP_PROPERTY_EX_ID(CQRCStampCtrl, "PelsPerMeter", dispidPelsPerMeter, GetPelsPerMeter, SetPelsPerMeter, VT_R8)
	DISP_PROPERTY_EX_ID(CQRCStampCtrl, "Picture", dispidPicture, GetPicture, SetPicture, VT_PICTURE)
	DISP_PROPERTY_EX_ID(CQRCStampCtrl, "SizeMode", dispidSizeMode, GetSizeMode, SetSizeMode, VT_I4)
	DISP_PROPERTY_EX_ID(CQRCStampCtrl, "ErrorCorrectLevel", dispidErrorCorrectLevel, GetErrorCorrectLevel, SetErrorCorrectLevel, VT_I4)
	DISP_PROPERTY_EX_ID(CQRCStampCtrl, "EncodeMode", dispidEncodeMode, GetEncodeMode, SetEncodeMode, VT_I4)
	DISP_PROPERTY_EX_ID(CQRCStampCtrl, "PixScale", dispidPixScale, GetPixScale, SetPixScale, VT_I4)

	DISP_STOCKPROP_BACKCOLOR()
	DISP_STOCKPROP_FORECOLOR()
	DISP_STOCKPROP_FONT()
END_DISPATCH_MAP()



// イベント マップ

BEGIN_EVENT_MAP(CQRCStampCtrl, COleControl)
	EVENT_CUSTOM_ID("ValueChange", eventidValueChange, ValueChange, VTS_UNKNOWN)
	EVENT_CUSTOM_ID("PelsPerMeterChange", eventidPelsPerMeterChange, PelsPerMeterChange, VTS_R8)
	EVENT_CUSTOM_ID("PictureChange", eventidPictureChange, PictureChange, VTS_PICTURE)
	EVENT_CUSTOM_ID("SizeModeChange", eventidSizeModeChange, SizeModeChange, VTS_NONE)
	EVENT_CUSTOM_ID("ErrorCorrectLevelChange", eventidErrorCorrectLevelChange, ErrorCorrectLevelChange, VTS_NONE)
	EVENT_CUSTOM_ID("EncodeModeChange", eventidEncodeModeChange, EncodeModeChange, VTS_NONE)
	EVENT_CUSTOM_ID("PixScaleChange", eventidPixScaleChange, PixScaleChange, VTS_NONE)
END_EVENT_MAP()



// プロパティ ページ

// TODO: プロパティ ページを追加して、BEGIN 行の最後にあるカウントを増やしてください。
BEGIN_PROPPAGEIDS(CQRCStampCtrl, 2)
	PROPPAGEID(CQRCStampPropPage::guid)
	PROPPAGEID(CLSID_CColorPropPage)
END_PROPPAGEIDS(CQRCStampCtrl)



// クラス ファクトリおよび GUID を初期化します。

IMPLEMENT_OLECREATE_EX(CQRCStampCtrl, "QRCSTAMP.QRCStampCtrl.1",
	0xd6feb896, 0x8cb3, 0x4b3a, 0xb9, 0x97, 0x4e, 0xd3, 0x1b, 0x76, 0x70, 0xec)



// タイプ ライブラリ ID およびバージョン

IMPLEMENT_OLETYPELIB(CQRCStampCtrl, _tlid, _wVerMajor, _wVerMinor)



// インターフェイス ID

const IID BASED_CODE IID_DQRCStamp =
		{ 0xD94D9B2B, 0xF60D, 0x498B, { 0x8F, 0x56, 0x4D, 0x6, 0x76, 0x80, 0xE0, 0x8B } };
const IID BASED_CODE IID_DQRCStampEvents =
		{ 0x834C0E14, 0x6FEE, 0x484E, { 0xA8, 0x26, 0x45, 0x7, 0x1, 0xDA, 0x59, 0x5B } };



// コントロールの種類の情報

static const DWORD BASED_CODE _dwQRCStampOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CQRCStampCtrl, IDS_QRCSTAMP, _dwQRCStampOleMisc)



// CQRCStampCtrl::CQRCStampCtrlFactory::UpdateRegistry -
// CQRCStampCtrl のシステム レジストリ エントリを追加または削除します。

BOOL CQRCStampCtrl::CQRCStampCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: コントロールが apartment モデルのスレッド処理の規則に従っていることを
	// 確認してください。詳細については MFC のテクニカル ノート 64 を参照してください。
	// アパートメント モデルのスレッド処理の規則に従わないコントロールの場合は、6 番目
	// のパラメータを以下のように変更してください。
	// afxRegApartmentThreading を 0 に設定します。

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_QRCSTAMP,
			IDB_QRCSTAMP,
			afxRegApartmentThreading,
			_dwQRCStampOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}



// CQRCStampCtrl::CQRCStampCtrl - コンストラクタ

CQRCStampCtrl::CQRCStampCtrl()
{
	InitializeIIDs(&IID_DQRCStamp, &IID_DQRCStampEvents);
}



// CQRCStampCtrl::~CQRCStampCtrl - デストラクタ

CQRCStampCtrl::~CQRCStampCtrl()
{
	// TODO: この位置にコントロールのインスタンス データの後処理用のコードを追加してください
}



// CQRCStampCtrl::OnDraw - 描画関数

void CQRCStampCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;

	CDC &dc = *pdc;

	CComQIPtr<IPicture> pict = m_Picture;

	CRect rc = rcBounds;

	CBrush br;
	COLORREF backclr = TranslateColor(GetBackColor());
	COLORREF foreclr = TranslateColor(GetForeColor());
	br.CreateSolidBrush(backclr);
	dc.FillRect(rcBounds, &br);

	if (pict == NULL) {
		rc.DeflateRect(2, 2);
		CFont *pfont = SelectStockFont(pdc);
		COLORREF priorFore = dc.SetTextColor(foreclr);
		COLORREF priorBack = dc.SetBkColor(backclr);
		dc.DrawText(_T("QRCode Stamp (libqrencode)"), rc, DT_LEFT|DT_TOP);
		dc.SetBkColor(priorBack);
		dc.SetTextColor(priorFore);
		pdc->SelectObject(pfont);
	}
	else {
		OLE_XSIZE_HIMETRIC cxSrc;
		OLE_YSIZE_HIMETRIC cySrc;

		pict->get_Width(&cxSrc);
		pict->get_Height(&cySrc);

		int xDst = rc.left;
		int yDst = rc.top;
		int cxDst = rc.right - rc.left;
		int cyDst = rc.bottom - rc.top;

		switch (m_sizeMode) {
			case SizeModeCenter:
				{
					SIZEL sizeHiM = {
						cxSrc,
						cySrc
					};
					SIZEL sizePix = sizeHiM;
					switch (dc.GetMapMode()) {
						case MM_ANISOTROPIC:
						case MM_ISOTROPIC:
							sizePix.cx = LONG(sizePix.cx / (float)m_cxExtent * m_rcBounds.Width());
							sizePix.cy = LONG(sizePix.cy / (float)m_cyExtent * m_rcBounds.Height());
							break;
						default:
							dc.HIMETRICtoDP(&sizePix);
							break;
					}
					xDst += (cxDst - sizePix.cx) / 2;
					yDst += (cyDst - sizePix.cy) / 2;
					cxDst = sizePix.cx;
					cyDst = sizePix.cy;
					break;
				}
			case SizeModeZoom:
				if (cyDst != 0 && cySrc != 0) {
					float fVwpt = cxDst / (float)cyDst;
					float fPic = cySrc / (float)cySrc;
					if (fVwpt >= fPic) {
						// ビューポートが横長
						int c = int(cxDst / fVwpt * fPic);
						xDst += (cxDst - c) / 2;
						cxDst = c;
					}
					else {
						// ビューポートが縦長
						int c = int(cyDst / fPic * fVwpt);
						yDst += (cyDst - c) / 2;
						cyDst = c;
					}
					break;
				}
		}

		int state = dc.SaveDC();
		dc.IntersectClipRect(rcBounds);

		CRect rcDst(xDst, yDst, xDst +yDst, yDst +cyDst);
		dc.LPtoDP(&rcDst);

		pict->Render(
			dc,
			xDst, yDst, cxDst, cyDst,
			0, cySrc -1,
			cxSrc, -cySrc,
			&rc
			);

		dc.RestoreDC(state);
	}
}



// CQRCStampCtrl::DoPropExchange - 永続性のサポート

void CQRCStampCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	PX_Double(pPX, _T("PelsPerMeter"), m_PelsPerMeter, 1000);
	PX_Long(pPX, _T("ErrorCorrectLevel"), m_ErrorCorrectLevel, ErrorCorrectLevelM);
	PX_Long(pPX, _T("EncodeMode"), m_EncodeMode, EncodeModeShiftJIS);
	PX_Long(pPX, _T("SizeMode"), m_sizeMode, SizeModeCenter);
	PX_String(pPX, _T("Value"), m_strValue);

	if (pPX->GetVersion() >= MAKELONG(1, 1)) {
		PX_Long(pPX, _T("PixScale"), m_PixScale, 1);
	}
	else {
		if (pPX->IsLoading())
			m_PixScale = 1;
	}

	if (pPX->IsLoading()) {
		UpdateBarcode();
	}
}



// CQRCStampCtrl::GetControlFlags -
// MFC の ActiveX コントロールの実装のカスタマイズ用フラグです。
//
DWORD CQRCStampCtrl::GetControlFlags()
{
	DWORD dwFlags = COleControl::GetControlFlags();


	// コントロールはウィンドウを作成せずにアクティベート可能です。
	// TODO: コントロールのメッセージ ハンドラを作成する場合、m_hWnd
	//		m_hWnd メンバ変数の値が NULL 以外であることを最初に確認
	//		してから使用してください。
	dwFlags |= windowlessActivate;
	return dwFlags;
}



// CQRCStampCtrl::OnResetState - コントロールを既定の状態にリセットします。

void CQRCStampCtrl::OnResetState()
{
	COleControl::OnResetState();  // DoPropExchange を呼び出して既定値にリセット
	ResetStockProps();

	m_Picture.Release();
	m_PelsPerMeter = 1000;
	m_strValue.Empty();
	m_sizeMode = SizeModeCenter;
	m_ErrorCorrectLevel = ErrorCorrectLevelM;
	m_EncodeMode = EncodeModeShiftJIS;
}



// CQRCStampCtrl::AboutBox - "バージョン情報" ボックスをユーザーに表示します。

class CAboutDlg : public CDialog {
public:
	CAboutDlg(): CDialog(IDD_ABOUTBOX_QRCSTAMP) {
	}

	BOOL OnInitDialog() {
		CWnd *pWnd = GetDlgItem(IDC_STATIC_VER);
		if (pWnd != NULL) {
			HMODULE hMod = AfxGetResourceHandle();
			HRSRC hVeri = FindResource(hMod, MAKEINTRESOURCE(VS_VERSION_INFO), RT_VERSION);
			PVOID pvVeri = LockResource(LoadResource(hMod, hVeri));
			DWORD cbVeri = SizeofResource(hMod, hVeri);
			if (pvVeri != NULL && cbVeri != 0) {
				VS_FIXEDFILEINFO *pffi = NULL;
				UINT cb = 0;
				if (VerQueryValue(pvVeri, _T("\\"), reinterpret_cast<LPVOID *>(&pffi), &cb)) {
					if (pffi->dwSignature == 0xFEEF04BD) {
						CString strText;
						pWnd->GetWindowText(strText);
						CString strVer;
						strVer.Format(_T("%u.%u.%u")
							, 0U +(WORD)(pffi->dwFileVersionMS >> 16)
							, 0U +(WORD)(pffi->dwFileVersionMS >> 0)
							, 0U +(WORD)(pffi->dwFileVersionLS >> 16)
							, 0U +(WORD)(pffi->dwFileVersionLS >> 0)
							);
						strText.Replace(_T("x.x.x"), strVer);
						pWnd->SetWindowText(strText);
					}
				}
			}
		}
		return true;
	}
};

void CQRCStampCtrl::AboutBox()
{
	CAboutDlg wndDlg;
	wndDlg.DoModal();
}



// CQRCStampCtrl メッセージ ハンドラ

VARIANT CQRCStampCtrl::GetValue(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	VARIANT vaResult;
	VariantInit(&vaResult);

	vaResult.vt = VT_BSTR;
	vaResult.bstrVal = m_strValue.AllocSysString();

	return vaResult;
}

void CQRCStampCtrl::SetValue(VARIANT *newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	COleVariant vt = *newVal;
	vt.ChangeType(VT_BSTR);

	m_strValue = vt.bstrVal;

	ValueChange();

	UpdateBarcode();

	SetModifiedFlag();
}

void CQRCStampCtrl::UpdateBarcode() {
	HRESULT hr;

	if (m_strValue.IsEmpty()) {
		SetPicture(NULL);
		return;
	}

	CStringA str = CW2A(CT2W(m_strValue), 932);

	class AR_QRcode {
		QRcode *pCode;
	public:
		AR_QRcode(QRcode *pCode): pCode(pCode) { }
		~AR_QRcode() { QRcode_free(pCode); }
	};

	QRecLevel level;
	switch (m_ErrorCorrectLevel) {
		default:
		case ErrorCorrectLevelL: level = QR_ECLEVEL_L; break;
		case ErrorCorrectLevelM: level = QR_ECLEVEL_M; break;
		case ErrorCorrectLevelQ: level = QR_ECLEVEL_Q; break;
		case ErrorCorrectLevelH: level = QR_ECLEVEL_H; break;
	}

	QRcode *pCode = NULL;
	switch (m_EncodeMode) {
		default:
		case EncodeModeShiftJIS:
			pCode = QRcode_encodeString(str, 0, level, QR_MODE_KANJI, 1);
			break;
		case EncodeModeAlphaNum:
			pCode = QRcode_encodeString(str, 0, level, QR_MODE_AN, 1);
			break;
		case EncodeModeNum:
			pCode = QRcode_encodeString(str, 0, level, QR_MODE_NUM, 1);
			break;
	}

	AR_QRcode ar(pCode);
	if (pCode == NULL)
		AfxThrowInvalidArgException();

	if (false) {
		int cx = pCode->width;
		int cy = pCode->width;

		const int f = int(100000.0 / m_PelsPerMeter);

		RECT rc = {0, 0, cx*f, cy*f};

		CMetaFileDC mf;
		if (!mf.CreateEnhanced(NULL, NULL, &rc, _T("QRCStamp\0QRCode\0")))
			AfxThrowResourceException();

		mf.SetMapMode(MM_HIMETRIC);
		CBrush br0(TranslateColor(GetBackColor()));
		CBrush br1(TranslateColor(GetForeColor()));

		for (int y=0; y<cy; y++) {
			for (int x=0; x<cx; x++) {
				bool fBlack = 1 == (pCode->data[cx*y + x] & 1);
				RECT rcFill = {
					(x  )*f   , -(y+1)*f -2,
					(x+1)*f +2, -(y  )*f,
				};
				if (fBlack)
					mf.FillRect(&rcFill, fBlack ? &br1 : &br0);
			}
		}
		HENHMETAFILE hEnhMeta = mf.CloseEnhanced();

		PICTDESC pd;
		pd.cbSizeofstruct = sizeof(pd);
		pd.picType = PICTYPE_ENHMETAFILE;
		pd.emf.hemf = hEnhMeta;

		CComPtr<IPictureDisp> pict;
		if (SUCCEEDED(hr = OleCreatePictureIndirect(&pd, IID_IPictureDisp, true, reinterpret_cast<void **>(&pict)))) {
			hEnhMeta = NULL;

			SetPicture(pict);
			return;
		}

		DeleteEnhMetaFile(hEnhMeta);
	}
	else {
		int cx = pCode->width;
		int cy = pCode->width;
		int vcx = cx * m_PixScale;
		int vcy = cy * m_PixScale;
		int stride = (vcx +3) & (~3);

		CByteArray bits;
		bits.SetSize(stride * vcy);

		for (int y=0; y<cy; y++) {
			for (int x=0; x<cx; x++) {
				BYTE b = pCode->data[cx * y + x];
				for (int vy=0; vy<m_PixScale; vy++) {
					for (int vx=0; vx<m_PixScale; vx++) {
						bits.SetAt(stride * (vcy - (y * m_PixScale + vy) - 1) + (x * m_PixScale + vx), b);
					}
				}
			}
		}

		char cBI[sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD)*256];
		PBITMAPINFO pBI = reinterpret_cast<PBITMAPINFO>(cBI);
		pBI->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		pBI->bmiHeader.biWidth = vcx;
		pBI->bmiHeader.biHeight = vcx;
		pBI->bmiHeader.biPlanes = 1;
		pBI->bmiHeader.biBitCount = 8;
		pBI->bmiHeader.biCompression = BI_RGB;
		pBI->bmiHeader.biXPelsPerMeter = int(m_PelsPerMeter);
		pBI->bmiHeader.biYPelsPerMeter = int(m_PelsPerMeter);
		pBI->bmiHeader.biClrUsed = 256;
		pBI->bmiHeader.biClrImportant = 256;
		for (int x=0; x<256; x++) {
			BYTE v = ((x & 1) == 1) ? 0 : 255;
			RGBQUAD q = {v, v, v, 0};
			pBI->bmiColors[x] = q;
		}

		void *pvBits = NULL;
		HBITMAP hbm = CreateDIBSection(NULL, pBI, DIB_RGB_COLORS, &pvBits, NULL, 0);
		if (hbm != NULL) {
			memcpy(pvBits, bits.GetData(), stride * vcy);
			PICTDESC pd;
			pd.cbSizeofstruct = sizeof(pd);
			pd.picType = PICTYPE_BITMAP;
			pd.bmp.hbitmap = hbm;
			pd.bmp.hpal = NULL;

			CComPtr<IPictureDisp> pict;
			if (SUCCEEDED(hr = OleCreatePictureIndirect(&pd, IID_IPictureDisp, true, reinterpret_cast<void **>(&pict)))) {
				hbm = NULL;
				SetPicture(pict);
				return;
			}

			DeleteObject(hbm);
		}
		else hr = E_FAIL;
	}

	SetPicture(NULL);

	AfxThrowOleException(hr);
}

DOUBLE CQRCStampCtrl::GetPelsPerMeter(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return m_PelsPerMeter;
}

void CQRCStampCtrl::SetPelsPerMeter(DOUBLE newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (m_PelsPerMeter != newVal) {
		m_PelsPerMeter = newVal;
		PelsPerMeterChange();
		UpdateBarcode();

		SetModifiedFlag();
	}
}

IPictureDisp* CQRCStampCtrl::GetPicture(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	IPictureDisp *pRes = NULL;
	m_Picture.CopyTo(&pRes);
	return pRes;
}

void CQRCStampCtrl::SetPicture(IPictureDisp* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (m_Picture != pVal) {
		m_Picture = pVal;
		PictureChange();
		InvalidateControl();

		SetModifiedFlag();
	}
}

LONG CQRCStampCtrl::GetSizeMode(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return m_sizeMode;
}

void CQRCStampCtrl::SetSizeMode(LONG newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	switch (newVal) {
		case SizeModeCenter:
		case SizeModeStretch:
		case SizeModeZoom:
			if (m_sizeMode != newVal) {
				m_sizeMode = static_cast<SizeModeEnum>(newVal);
				SizeModeChange();
				InvalidateControl();
				SetModifiedFlag();
			}
			break;
		default:
			AfxThrowInvalidArgException();
	}

}

LONG CQRCStampCtrl::GetErrorCorrectLevel(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return m_ErrorCorrectLevel;
}

void CQRCStampCtrl::SetErrorCorrectLevel(LONG newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	switch (newVal) {
		case ErrorCorrectLevelL:
		case ErrorCorrectLevelM:
		case ErrorCorrectLevelQ:
		case ErrorCorrectLevelH:
			if (m_ErrorCorrectLevel != newVal) {
				m_ErrorCorrectLevel = static_cast<QRErrorCorrectLevelEnum>(newVal);
				ErrorCorrectLevelChange();
				UpdateBarcode();
				SetModifiedFlag();
			}
			break;
		default:
			AfxThrowInvalidArgException();
	}
}

LONG CQRCStampCtrl::GetEncodeMode(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return m_EncodeMode;
}

void CQRCStampCtrl::SetEncodeMode(LONG newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	switch (newVal) {
		case EncodeModeShiftJIS:
		case EncodeModeAlphaNum:
		case EncodeModeNum:
			if (m_EncodeMode != newVal) {
				m_EncodeMode = static_cast<EncodeModeEnum>(newVal);
				EncodeModeChange();
				UpdateBarcode();
				SetModifiedFlag();
			}
			break;
		default:
			AfxThrowInvalidArgException();
	}
}

void CQRCStampCtrl::OnFontChanged() {
	InvalidateControl();
}

void CQRCStampCtrl::OnBackColorChanged() {
	UpdateBarcode();
	InvalidateControl();
}

void CQRCStampCtrl::OnForeColorChanged() {
	UpdateBarcode();
	InvalidateControl();
}

LONG CQRCStampCtrl::GetPixScale(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return m_PixScale;
}

void CQRCStampCtrl::SetPixScale(LONG newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (newVal < 1 || newVal > 100)
		AfxThrowInvalidArgException();

	m_PixScale = newVal;

	UpdateBarcode();

	SetModifiedFlag();
}
