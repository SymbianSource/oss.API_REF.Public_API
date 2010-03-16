// Copyright (c) 1997-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// This file contains the definition of
// the CImplementationInformation class.
// 
//



#ifndef __IMPLEMENTATIONINFORMATION_H__
#define __IMPLEMENTATIONINFORMATION_H__

#include <s32std.h>
#include <f32file.h>

// ____________________________________________________________________________________
// 
/**
CImplementationInformation

This class acts as the container for the registration data 
relating to a particular Interface Implementation.
Note that this class is used in both the ECOM client and server side,
For the client side only the API used to extract the registration data
should be used.
	
It is available to the client to allow access to the
registered characteristics of the implementation.
These characteristics are:

ImplementationUid() The Uid of this implementation.

Version()			The version number of this implementation.

DisplayName()		The human readable name for this implementation returned 
					as a 16 bit descriptor.

DataType()			The data type which this implementation supports, returned
					as an 8 bit descriptor.

OpaqueData()		The opaque data which is registered for this implementation,
					returned as an 8 bit descriptor.

RomOnly()			The flag indicating whether this implementation is to be loaded
					from ROM only.

RomBased()			The flag recording whether this implementation is on ROM or is
					a later version of one on ROM.
					
VendorId()  		The Vendor ID of the plug-in which this implementation belongs to

@publishedAll
@released
*/

NONSHARABLE_CLASS(CImplementationInformation) : public CBase
	{
public:
	
	static CImplementationInformation* NewLC(TBool aClientSide,RReadStream& aStream);
	
	static CImplementationInformation* NewL(TUid	aUid, 
											TInt	aVersion, 
											HBufC*  aName,
											HBufC8* aDataType,
											HBufC8* aOpaqueData,
											TDriveUnit aDrive,
											TBool aRomOnly,
											TBool aRomBased);
	
	~CImplementationInformation();
	
	inline const TDesC& DisplayName() const;
	
	inline const TDesC8& DataType() const;
	
	inline const TDesC8& OpaqueData() const;
	
	inline TUid ImplementationUid() const;
	
	inline TInt Version() const;
	
	inline TBool Disabled() const;
	
	//This function should not be used by any ECOM client as it will have no effect 
	//at all on the implementation information stored in the server side.
	inline void SetDisabled(TBool aDisabled);
	
	void ExternalizeL(TBool aClientSide,RWriteStream& aStream) const;
	
	void InternalizeL(TBool aClientSide,RReadStream& aStream);
	inline TDriveUnit Drive() const;
	inline TBool RomOnly() const;
	inline TBool RomBased() const;
	void SetRomBased(TBool aRomBased);
	inline TVendorId VendorId() const;
	void SetDrive(TDriveUnit aDrive);
	
public:
	// The following function is categorised as @internalComponent 
	//and should not be used by ECOM clients.
 	inline void SetVendorId(const TVendorId aVid);
 	
private:
	
	CImplementationInformation();
	
	CImplementationInformation(TUid aUid, 
							   TInt aVersion, 
							   HBufC*  aName, 
							   HBufC8* aDataType,
							   HBufC8* aOpaqueData,
							   TDriveUnit aDrive,
							   TBool aRomOnly,
							   TBool aRomBased);

private:
	/** The implementation UID */
	
	TUid		iImplementationUid;
	/** The implementation version */
	
	TInt		iVersion;
	/** This implementations human readable name intended for display in UI implementations */
	
	HBufC*		iDisplayName;
	/** 
		The type of data this implementation is registered to handle : 
		Used for matching against the run-time cue provided by the client
		during default interface implementation resolution.
	*/
	
	HBufC8*		iData;
	/** 
		Data registered for this implementation which can be used by the client
		during non-default resolution operations but is ignored by the framework. 
	*/
	
	HBufC8*		iOpaqueData;
	/** The flag recording if this implementation is disabled or enabled */ 
	
	TBool		iDisabled;
	/** The drive that this plug-in resides on */ 
	TDriveUnit		iDrive;
	/** The flag recording whether this implementation may only be loaded 
	from read-only internal media */
	TBool iRomOnly;
	/** This flag records whether this implementation was discovered on 
	read-only internal media or that it is a later version of one that was */
	TBool iRomBased;
	/** The Vendor ID of the plug-in which this implementation belongs to*/
	TVendorId iVid;
	};	// End CImplementationInformation

/** 
Simplifies the definition of functions which return registry information 

@publishedAll
@released
*/
typedef RArray<CImplementationInformation*> RImplInfoArray;

/** 
Simplifies the definition of functions which return registry information 

@publishedAll
@released
*/
typedef RPointerArray<CImplementationInformation> RImplInfoPtrArray;


#include <ecom/implementationinformation.inl>

#endif		// __IMPLEMENTATIONINFORMATION_H__
