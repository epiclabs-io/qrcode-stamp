#pragma once

// QRCStampPropPage.h : CQRCStampPropPage �v���p�e�B �y�[�W �N���X�̐錾�ł��B


// CQRCStampPropPage : �����Ɋւ��Ă� QRCStampPropPage.cpp ���Q�Ƃ��Ă��������B

class CQRCStampPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CQRCStampPropPage)
	DECLARE_OLECREATE_EX(CQRCStampPropPage)

// �R���X�g���N�^
public:
	CQRCStampPropPage();

// �_�C�A���O �f�[�^
	enum { IDD = IDD_PROPPAGE_QRCSTAMP };

// ����
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

// ���b�Z�[�W �}�b�v
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString m_strValue;
	double m_dblPPM;
	int m_iSizeMode;
	int m_iECL;
};

