#pragma once

// QRCStamp.h : QRCStamp.DLL �̃��C�� �w�b�_�[ �t�@�C��

#if !defined( __AFXCTL_H__ )
#error "���̃t�@�C�����C���N���[�h����O�� 'afxctl.h' ���C���N���[�h���Ă��������B"
#endif

#include "resource.h"       // ���C�� �V���{��


// CQRCStampApp : �����Ɋւ��Ă� QRCStamp.cpp ���Q�Ƃ��Ă��������B

class CQRCStampApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

