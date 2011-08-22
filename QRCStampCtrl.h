#pragma once

// QRCStampCtrl.h : CQRCStampCtrl ActiveX �R���g���[�� �N���X�̐錾�ł��B

typedef enum tagSizeModeEnum {
	SizeModeCenter = 0,
	SizeModeStretch = 1,
	SizeModeZoom = 2,
} SizeModeEnum;

typedef enum tagQRErrorCorrectLevel {
	ErrorCorrectLevelL = 1,
	ErrorCorrectLevelM = 0,
	ErrorCorrectLevelQ = 3,
	ErrorCorrectLevelH = 2,
} QRErrorCorrectLevelEnum;

typedef enum tagEncodeMode {
	EncodeModeShiftJIS = 0,
	EncodeModeAlphaNum,
	EncodeModeNum,
} EncodeModeEnum;

// CQRCStampCtrl : �����Ɋւ��Ă� QRCStampCtrl.cpp ���Q�Ƃ��Ă��������B

class CQRCStampCtrl : public COleControl
{
	DECLARE_DYNCREATE(CQRCStampCtrl)

// �R���X�g���N�^
public:
	CQRCStampCtrl();

// �I�[�o�[���C�h
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	virtual DWORD GetControlFlags();

// ����
protected:
	~CQRCStampCtrl();

	DECLARE_OLECREATE_EX(CQRCStampCtrl)    // �N���X �t�@�N�g�� �� guid
	DECLARE_OLETYPELIB(CQRCStampCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CQRCStampCtrl)     // �v���p�e�B �y�[�W ID
	DECLARE_OLECTLTYPE(CQRCStampCtrl)		// �^�C�v���Ƃ��̑��̃X�e�[�^�X

// ���b�Z�[�W �}�b�v
	DECLARE_MESSAGE_MAP()

// �f�B�X�p�b�` �}�b�v
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// �C�x���g �}�b�v
	DECLARE_EVENT_MAP()

// �f�B�X�p�b�` �� �C�x���g ID
public:
	enum {
		eventidEncodeModeChange = 1006L,
		dispidEncodeMode = 1006,

		eventidErrorCorrectLevelChange = 1005L,
		dispidErrorCorrectLevel = 1005,

		eventidSizeModeChange = 1004L,
		dispidSizeMode = 1004,

		eventidPictureChange = 1003L,
		dispidPicture = 1003,

		eventidPelsPerMeterChange = 1002L,
		dispidPelsPerMeter = 1002,

		eventidValueChange = 1001L,
		dispidValue = 1001
	};
protected:
	VARIANT GetValue(void);
	void SetValue(VARIANT *newVal);
	CString m_strValue;
	void UpdateBarcode();
	double m_PelsPerMeter;
	CComPtr<IPictureDisp> m_Picture;
	LONG m_sizeMode;
	LONG m_ErrorCorrectLevel;

	void ValueChange() {
		FireEvent(eventidValueChange, EVENT_PARAM(VTS_NONE)
			);
	}

	void PelsPerMeterChange() {
		FireEvent(eventidPelsPerMeterChange, EVENT_PARAM(VTS_NONE)
			);
	}

	void PictureChange() {
		FireEvent(eventidPictureChange, EVENT_PARAM(VTS_NONE)
			);
	}
	DOUBLE GetPelsPerMeter(void);
	void SetPelsPerMeter(DOUBLE newVal);
	IPictureDisp* GetPicture(void);
	void SetPicture(IPictureDisp* pVal);
	LONG GetSizeMode(void);
	void SetSizeMode(LONG newVal);
	LONG GetErrorCorrectLevel(void);
	void SetErrorCorrectLevel(LONG newVal);

	void SizeModeChange(void) {
		FireEvent(eventidSizeModeChange, EVENT_PARAM(VTS_NONE));
	}

	void ErrorCorrectLevelChange(void) {
		FireEvent(eventidErrorCorrectLevelChange, EVENT_PARAM(VTS_NONE));
	}
	LONG GetEncodeMode(void);
	void SetEncodeMode(LONG newVal);
	LONG m_EncodeMode;

	void EncodeModeChange(void)
	{
		FireEvent(eventidEncodeModeChange, EVENT_PARAM(VTS_NONE));
	}

public:
	virtual void OnFontChanged();
	virtual void OnBackColorChanged();
	virtual void OnForeColorChanged();
};
