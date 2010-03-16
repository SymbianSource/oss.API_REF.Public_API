// Copyright (c) 2001-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
// which accompanies this distribution, and is available
// at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
// The definitions required for the use
// of the ECOM framework by a client are contained / defined here.
// 
//



#ifndef __ECOM_H__
#define __ECOM_H__

//////////////////////////////////////////////////////////////////////////////
// Include Files

#include <e32base.h>
#include <s32std.h>
#include <f32file.h>

#include <ecom/ecomerrorcodes.h>
#include <ecom/ecomresolverparams.h>
#include <ecom/implementationinformation.h>


//////////////////////////////////////////////////////////////////////////////
// Forward declarations

class CGlobalData;


//////////////////////////////////////////////////////////////////////////////
// Global Constants

/** 
The UID identifying the ROM-Only CResolver Interface Implementation. 
This resolver only returns implementations present on R/O internal media
(built-in) or upgrades of such implementations on R/W media. It does not 
return implementations that solely reside on R/W media. 

@publishedAll
@released
*/
const TUid KRomOnlyResolverUid = {0x10009D92};


//////////////////////////////////////////////////////////////////////////////
// REComSession class

/**
The REComSession singleton class provides an API to identify (resolution), 
instantiate, and destroy interface class implementations requested by 
ECOM clients. It manages the session connection to the ECOM Server itself so 
that typically only one connection is made to the ECOM Server per thread.
It provides an un-initialise function where it releases memory and handles
of unused plug-ins, see the FinalClose() function. It also ensures that all
necessary clean-up is performed in the event of a Leave by any of the
ListImplementationsL() or CreateImplementationL() methods.

Note: Although a public default constructor is provided in this class
it is strongly recommended this object is never created by users of this
API on the stack or heap by value. To access the non-static methods of this
API use the static OpenL() method to obtain a pointer or a 
reference to the single reference counted session in use. Close() must be 
called when finished with.

Special care must be taken when using aDtorIDKey. It is a 32-bit instance key
that is returned from a call to one of the CreateImplementationL() methods. 
This instance key must only be used with DestroyedImplementation() to identify
the implementation instance for destruction, or GetImplementationUidL() to
retrieve the Implementation Uid of the instance it refers to.
No meaning must be attached to this instance key by ECOM clients 
and it must not be used for any other purpose.


@see REComSession::FinalClose()
@publishedAll
@released
*/
class REComSession  : public RSessionBase
	{
	friend class CGlobalData;
public:

	IMPORT_C REComSession();
	IMPORT_C static REComSession& OpenL();
	IMPORT_C void Close();
	
	// Notification API declarations
     
	IMPORT_C void NotifyOnChange(TRequestStatus& aStatus);
	IMPORT_C void CancelNotifyOnChange(TRequestStatus& aStatus);
	
	// List implementations API declarations
	//
	// Use LI1 to list all implementations, unfiltered.
	// Use LI2 when default resolving required on the returned list.
	// Use LI3 when custom resolving required on the returned list.
	
	// ListImplementationsL - LI1
	IMPORT_C static void ListImplementationsL(
                            TUid aInterfaceUid,
							RImplInfoPtrArray& aImplInfoArray);
							
	// ListImplementationsL - LI2
	IMPORT_C static void ListImplementationsL(
                            TUid aInterfaceUid, 
							const TEComResolverParams& aResolutionParameters,
							RImplInfoPtrArray& aImplInfoArray);
							
	// ListImplementationsL - LI3
	IMPORT_C static void ListImplementationsL(
                            TUid aInterfaceUid, 
							const TEComResolverParams& aResolutionParameters, 
							TUid aResolverUid,
							RImplInfoPtrArray& aImplInfoArray);

	// Create implementations API declarations
    //
    // When Implementation UID is known: 
    // Use CI1, CI2. 
    // Use CI3, CI4 when you have construction parameters.
    //
    // When the Interface UID is known and default resolving is required:
    // Use CI5, CI6. 
    // Use CI7, CI8 when you have construction parameters.
    // 
    // When the Interface UID is known and custom resolving is required:
    // Use CI9, CI10.
    // Use CI11, CI12 when you have construction parameters.
	
	// CreateImplementationL - CI1
	IMPORT_C static TAny* CreateImplementationL(
                            TUid aImplementationUid, 
                            TUid& aDtorIDKey);
                            
	// CreateImplementationL - CI2
	IMPORT_C static TAny* CreateImplementationL(
                            TUid aImplementationUid, 
							TInt32 aKeyOffset);
							
	// CreateImplementationL - CI3
	IMPORT_C static TAny* CreateImplementationL(
                            TUid aImplementationUid, 
							TUid& aDtorIDKey, 
							TAny* aConstructionParameters);
							
	// CreateImplementationL - CI4
	IMPORT_C static TAny* CreateImplementationL(
                            TUid aImplementationUid, 
							TInt32 aKeyOffset,
							TAny* aConstructionParameters);
							
	// CreateImplementationL - CI5
	IMPORT_C static TAny* CreateImplementationL(
                            TUid aInterfaceUid, 
							TUid& aDtorIDKey,
							const TEComResolverParams& aResolutionParameters);
							
	// CreateImplementationL - CI6
	IMPORT_C static TAny* CreateImplementationL(
                            TUid aInterfaceUid, 
							TInt32 aKeyOffset, 
							const TEComResolverParams& aResolutionParameters);
							
	// CreateImplementationL - CI7
	IMPORT_C static TAny* CreateImplementationL(
                            TUid aInterfaceUid, 
							TUid& aDtorIDKey, 
							TAny* aConstructionParameters, 
							const TEComResolverParams& aResolutionParameters);
							
	// CreateImplementationL - CI8
	IMPORT_C static TAny* CreateImplementationL(
                            TUid aInterfaceUid, 
							TInt32 aKeyOffset, 
							TAny* aConstructionParameters, 
							const TEComResolverParams& aResolutionParameters);
							
	// CreateImplementationL - CI9
	IMPORT_C static TAny* CreateImplementationL(
                            TUid aInterfaceUid, 
							TUid& aDtorIDKey, 
							const TEComResolverParams& aResolutionParameters,
							TUid aResolverUid);
												
	// CreateImplementationL - CI10
	IMPORT_C static TAny* CreateImplementationL(
                            TUid aInterfaceUid, 
							TInt32 aKeyOffset,
							const TEComResolverParams& aResolutionParameters, 
							TUid aResolverUid);
												
	// CreateImplementationL - CI11
	IMPORT_C static TAny* CreateImplementationL(
                            TUid aInterfaceUid, 
							TUid& aDtorIDKey, 
							TAny* aConstructionParameters,
							const TEComResolverParams& aResolutionParameters, 
							TUid aResolverUid);
												
	// CreateImplementationL - CI12
	IMPORT_C static TAny* CreateImplementationL(
                            TUid aInterfaceUid, 
							TInt32 aKeyOffset, 
							TAny* aConstructionParameters,
							const TEComResolverParams& aResolutionParameters,
							TUid aResolverUid);
	
	// Get Implementation Uid from a Destructor Id Key
	IMPORT_C static TUid GetImplementationUidL(
							TUid aDtorIDKey);
	
    // Destroy Implementation API declaration											
	IMPORT_C static void DestroyedImplementation(
                            TUid aDtorIDKey);


	// See developer documentation for use of FinalClose.
	IMPORT_C static void FinalClose();

private:
	
	static REComSession& OpenLC();
	
	void ConstructL();
	void ReallyClose();
	
	void ListImplementationsL(
            TInt aServiceId, 
			TUid aInterfaceUid, 
			const TEComResolverParams& aResolutionParameters, 
			TUid aResolverUid,
			RImplInfoPtrArray& aImplInfoArray);
			
	TAny* ResolveAndCreateImplL(
            TUid aImplementationUid, 
			TUid& aDtorIDKey, 
			TAny* aCreationParameters, 
            TBool aCreationParamsFlag);
                                     
	TAny* ResolveAndCreateImplL(
            TUid aInterfaceUid, 
			const TEComResolverParams& aResolutionParameters, 
			TUid& aDtorIDKey, 
			TAny* aCreationParameters, 
            TBool aCreationParamsFlag);
                                     
	TAny* ResolveAndCreateImplL(
            TUid aInterfaceUid, 
			const TEComResolverParams& aResolutionParameters, 
			TUid aResolverUid, 
			TUid& aDtorIDKey, 
			TAny* aCreationParameters, 
            TBool aCreationParamsFlag);
                                     
	TAny* ResolveAndCreateImplL(
            TInt aServiceId,
			TUid aInterfaceUid, 
			const TEComResolverParams& aResolutionParameters, 
			TUid aResolverUid, 
			TUid& aDtorIDKey, 
			TAny* aCreationParameters, 
            TBool aCreationParamsFlag);

public:
    //This API is for internal use only and for testing purposes.
	IMPORT_C static void SetGetParametersL(const TIpcArgs &aArgs);
												
private:
    /** Not used */
	TInt iReserved1;

	/** Not used */
	TBool iReserved3;

    /** not used */
	TInt iReserved2;
	};


#endif	// __ECOM_H__
