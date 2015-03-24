

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Wed Mar 25 00:09:48 2015
 */
/* Compiler settings for QRCStamp.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_QRCStampLib,0x60028474,0x1671,0x4F2D,0x94,0xCF,0x86,0x63,0x87,0x96,0x99,0x7F);


MIDL_DEFINE_GUID(IID, DIID__DQRCStamp,0xD94D9B2B,0xF60D,0x498B,0x8F,0x56,0x4D,0x06,0x76,0x80,0xE0,0x8B);


MIDL_DEFINE_GUID(IID, DIID__DQRCStampEvents,0x834C0E14,0x6FEE,0x484E,0xA8,0x26,0x45,0x07,0x01,0xDA,0x59,0x5B);


MIDL_DEFINE_GUID(CLSID, CLSID_QRCStamp,0xD6FEB896,0x8CB3,0x4B3A,0xB9,0x97,0x4E,0xD3,0x1B,0x76,0x70,0xEC);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



