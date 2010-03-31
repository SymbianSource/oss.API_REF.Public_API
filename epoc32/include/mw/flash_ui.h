/*
* Copyright (c) 2005 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  Loads the UI library and creates the instance of the document class.
*
*/

#ifndef __FLASH_UI_H__
#define __FLASH_UI_H__

#include <eikapp.h>
#include <apparc.h>
#include <apgcli.h>


/** @file flash_ui.h
 * The API to start Viewer UI for playing Flash content file from a Viewer or a stub 
 * application.
 *
 * The point here is to offer easy-of-use API for stubs applications which has 
 * dedicated set of platform security capabilities for rendering private SWF content. 
 * However, also standard Flash Viewer can utilize the same API as well. 
 *
 * Example usage of the API:
 *
 * @code
 * LOCAL_C CApaApplication* NewApplication( )
 *     {
 *	   return new(ELeave) CFlashStubApplication;
 *	   }
 *
 * GLDEF_C TInt E32Main()
 *     {
 *     return EikStart::RunApplication(NewApplication);
 *     }
 * 
 * CFlashStubApplication::~CFlashStubApplication()
 *     {
 *     if (iFlashLibrary.Handle())
 *         {
 *         iFlashLibrary.Close();
 *         }
 *     }
 * 
 * const TUid KUidFlashStubApp = { 0x1027367B };
 * 
 * TUid CFlashStubApplication::AppDllUid() const
 *     {
 *     return KUidFlashStubApp;
 *     }
 * 
 * 
 * _LIT(KStubFlashContent, "C:\\Data\\Others\\example.swf");
 * 
 * const TUint32 KContentChecksum = 0;
 * 
 * CApaDocument* CFlashStubApplication::CreateDocumentL()
 *     {
 *     FlashUIConfig config;
 *     config.iIsMMI = EFalse;
 *     config.iIsStubApp = ETrue;
 *     config.iContentFileName.Copy(KStubFlashContent);
 *     config.iContentChecksum = KContentChecksum;
 *     config.iExtensions = NULL;
 * 
 *     if(!FlashStubsSupported())
 *	       {
 *	       User::Leave(KErrNotSupported); 	
 *         } 
 *     return CreateFlashDocumentL(iFlashLibrary, this, config);
 *    }
 * @endcode
 */

/** 
 Structure containing configuration information for UI.
 */
struct FlashUIConfig
{
	/** 
	* ETrue if MMI is supported. 
	*/
	TBool iIsMMI;	 
	
	/** 
	* ETrue if is a stub application.
	*/
	TBool iIsStubApp;
	
	/** 
	* The swf file which accesses the MMI features. 
	*/
	TFileName iContentFileName;

	/** 
	* Check sum for security. 
	*/
	TUint32 iContentChecksum;

	/** 
	* Name of the ECom plug-in
	*/
	const TDesC8* iExtensions;

	/** 
	* Reserved for future use 
	*/
	const TDesC8* iReserved1;

	/** 
	* Reserved for future use 
	*/
	TUint32 iReserved2;
};

/**
* The Flash UI dll name. 
*/
_LIT(KFlashUILibraryName, "flash2ui.dll");

/** 
* The ordinal of the exported function in the Flash UI dll.
*/
const TInt KFlashCreateDocumentOrdinal = 1;

/** 
* Pointer to a function that creates the document class. 
*/
typedef void*	(*PFNC_CreateFlashDocumentL)(CEikApplication* aApp, const FlashUIConfig& aUIConfig);

class CEikApplication;
/**
 *  CreateFlashDocumentL creates a Flash document for an application and
 *  starts playing the given SWF file. If there is no S60 Flash Lite
 *  Viewer Framework DLL installed in the device, the function leaves with error
 *  code returned from the RLibrary::Load. 
 *
 * @since S60 v3.1
 *
 * @param aLibrary Handle to the flash UI dll.
 * @param aApp Instance of the application class.
 * @param aUIConfig Instance of the class that contains the configuration for the UI.
 * @return The new document object.
 * @leave KErrGeneral Error in using the successfully loaded Flash Viewer Framework DLL 
 */
inline CApaDocument* CreateFlashDocumentL(RLibrary& aLibrary, CEikApplication* aApp, const FlashUIConfig& aUIConfig)
{
	CApaDocument* doc = NULL;
	User::LeaveIfError(aLibrary.Load(KFlashUILibraryName));
	PFNC_CreateFlashDocumentL pFncCreateFlashDocumentL = (PFNC_CreateFlashDocumentL)aLibrary.Lookup(KFlashCreateDocumentOrdinal);
	if (pFncCreateFlashDocumentL == NULL)
	{
		User::Leave(KErrGeneral);
	}
	doc = (CApaDocument*)pFncCreateFlashDocumentL(aApp, aUIConfig);
	return doc;
}

/**
 * Checks whether S60 Flash Lite Viewer Framework DLL exists in the device for stub
 * applications.
 * @return ETrue if Flash Lite stub applications is suppported, EFalse otherwise.
 */
inline TBool FlashStubsSupported() 
{

	RLibrary library;
	TInt err = library.Load(KFlashUILibraryName);
	if(err == KErrNone)
	{
		library.Close();
		return ETrue;
	}
	else
	{
		return EFalse;
	}
}
#endif // __FLASH_UI_H__