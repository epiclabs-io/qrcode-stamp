// QRCStamp.cpp : CQRCStampApp ����� DLL �o�^�̎���

#include "stdafx.h"
#include "QRCStamp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CQRCStampApp theApp;

const GUID CDECL BASED_CODE _tlid =
		{ 0x60028474, 0x1671, 0x4F2D, { 0x94, 0xCF, 0x86, 0x63, 0x87, 0x96, 0x99, 0x7F } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CQRCStampApp::InitInstance - DLL ������

BOOL CQRCStampApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: ���̈ʒu�Ƀ��W���[���̏����������R�[�h��ǉ����Ă��������B
	}

	return bInit;
}



// CQRCStampApp::ExitInstance - DLL �I��

int CQRCStampApp::ExitInstance()
{
	// TODO: ���̈ʒu�Ƀ��W���[���̏I��������ǉ����Ă��������B

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - �G���g�����V�X�e�� ���W�X�g���ɒǉ����܂��B

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - �G���g�������W�X�g������폜���܂��B

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
