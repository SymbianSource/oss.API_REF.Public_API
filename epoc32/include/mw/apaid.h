// Copyright (c) 1997-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
// apaid.h
//

#ifndef __APAID_H__
#define __APAID_H__

#include <e32base.h>
#include <apadef.h>
#include <apmstd.h>		// class TDataTypeWithPriority

// classes referenced
class RReadStream;
class RWriteStream;
class RFs;

/** The identity of an application.

An object of this type contains two pieces of information:

The application specific UID

The file name and extension of the application DLL

All persisted documents associated with this application have a stream containing 
this information.

@publishedAll 
@released
@see CApaProcess::ReadRootStreamLC()
@see CApaProcess::WriteRootStreamL()
@see CApaProcess::ReadAppIdentifierL()
@see CApaProcess::WriteAppIdentifierL() */
class TApaAppIdentifier
	{
public:
	IMPORT_C TApaAppIdentifier();
	IMPORT_C TApaAppIdentifier(TUid aAppUidType,const TFileName& aDllName);
	IMPORT_C void ExternalizeL(RWriteStream& aStream)const;
	IMPORT_C void InternalizeL(RReadStream& aStream);
public:
	/** The application-specific UID. */
	TUid iAppUid;
	/** The full path name of the application DLL. */
	TFileName iFullName;
private:
	TInt iTApaAppIdentifier_Reserved1;
	};


/** Application information.

An object of this type contains four pieces of information:

the application specific UID

the full path name of the application DLL

the application's caption

a short caption; how this is used is up to the UI 

@publishedAll
@released */
class TApaAppInfo
	{
public:
	IMPORT_C TApaAppInfo();
	IMPORT_C TApaAppInfo(TUid aAppUid,const TFileName& aDllName,const TApaAppCaption& aCaption);
	IMPORT_C TApaAppInfo(TUid aAppUid,const TFileName& aDllName,const TApaAppCaption& aCaption,const TApaAppCaption& aShortCaption);
	IMPORT_C void ExternalizeL(RWriteStream& aStream)const;
	IMPORT_C void InternalizeL(RReadStream& aStream);
public:
	/** The application specific UID. */
	TUid iUid;
	/** The full path name of the application DLL. */
	TFileName iFullName;
	/** The caption for the application. */
	TApaAppCaption iCaption;
	/** The short caption for the application. */
	TApaAppCaption iShortCaption;
private:
	TInt iTApaAppInfo_Reserved1;
	};


/** Contains the basic information about an application view.

An object of this type contains two pieces of information:

The UID that identifies the view

The application's caption.

Objects of this type are returned in an array populated by a call to RApaLsSession::GetAppViews().

@publishedAll 
@released
@see CApaAppViewArray
@see TUid */
class TApaAppViewInfo
	{
public:
	IMPORT_C TApaAppViewInfo();
	IMPORT_C TApaAppViewInfo(TUid aViewUid,const TApaAppCaption& aViewCaption,TInt aScreenMode);
	IMPORT_C void ExternalizeL(RWriteStream& aStream)const;
	IMPORT_C void InternalizeL(RReadStream& aStream);
public:
	/** The UID identifying the view. */
	TUid iUid;
	/** The application caption. */
	TApaAppCaption iViewCaption;
	TInt iScreenMode;
private:
	TInt iTApaAppViewInfo_Reserved1;
	};


/** Defines an array of TApaAppViewInfo objects contained within a flat dynamic 
buffer.

An array of this type is populated with TApaAppViewInfo objects in a call 
to RApaLsSession::GetAppViews().

@publishedAll 
@released */
typedef CArrayFixFlat<TApaAppViewInfo> CApaAppViewArray;


/** Application capabilities. 

@publishedAll
@released */
class TApaAppCapability
	{
public:
	IMPORT_C static void CopyCapability(TDes8& aDest,const TDesC8& aSource);
	IMPORT_C void InternalizeL(RReadStream& aStream);
	IMPORT_C void ExternalizeL(RWriteStream& aStream) const;
private:
	void DoInternalizeL(RReadStream& aStream, TBool& aLaunchInBackground, TApaAppGroupName& aGroupName);
public:
	//
	/** Defines an application's support for embeddability. */
	enum TEmbeddability {
		/** An application cannot be embedded. */
		ENotEmbeddable=0,
		/** An application can be run embedded or standalone and can read/write embedded document-content. */
		EEmbeddable=1,
		/** An application can only be run embedded and can read/write embedded document-content. */
		EEmbeddableOnly=2,
		/** An application can be run embedded or standalone and cannot read/write embedded document-content. */
		EEmbeddableUiOrStandAlone=5,
		/** An application can only be run embedded and cannot read/write embedded document-content. */
		EEmbeddableUiNotStandAlone=6 };
	/** Defines an application's attributes as a set of bit flags. */
	enum TCapabilityAttribute
		{
		/** This functionality is deprecated from v9.5 onwards.
		@deprecated
		*/
		EBuiltAsDll			= 0x00000001,
		/** If set, the application provides control panel functionality. */
		EControlPanelItem	= 0x00000002,
		/** If set, the application is not a native executable, and hence the "path" and "extension" (as well as the "name") must be provided in the app_file field of the APP_REGISTRATION_INFO resource. */
		ENonNative			= 0x00000004
		};
public:
	/** Indicates the extent to which the application can be embedded. */
	TEmbeddability iEmbeddability;
	/** Indicates whether the application is document-based and supports being asked 
	to create a new file. */
	TBool iSupportsNewFile;
	/** Indicates whether the existence of the application should be advertised to the 
	user. If this is set to ETrue, the application does not appear on the Extras 
	Bar (or equivalent). */
	TBool iAppIsHidden; // not shown in the Shell etc.
	/** Allows the application to be launched in the foreground (when set to EFalse) 
	or in the background (when set to ETrue). */
	TBool iLaunchInBackground;	// Series 60 extension to allow apps to be launched in the background	
	/** Stores the application's logical group name. */
	TApaAppGroupName iGroupName; // Series 60 extension to allow apps to be categorized according a logical group name, e.g. 'games'
	/** Indicates the application attributes. One or more values from TCapabilityAttribute may be specified. */
	TUint iAttributes;
private:
	// expandable class - add new members to the end, add them to the end of int/ext also, and increment the version no.
	// default value for all data members must be 0
	enum { EVersion=4 };
private:
	TInt iTApaAppCapability_Reserved1;
	};

/** Packages the TApaAppCapability class. 

@publishedAll
@released */
typedef TPckgBuf<TApaAppCapability> TApaAppCapabilityBuf;


/** Filter used to define the subset of applications returned by RApaLsSession::GetNextApp()

@publishedAll
@released
*/
class TApaEmbeddabilityFilter
	{
public:
	IMPORT_C TApaEmbeddabilityFilter();
	IMPORT_C void AddEmbeddability(TApaAppCapability::TEmbeddability aEmbeddability);
	IMPORT_C TBool MatchesEmbeddability(TApaAppCapability::TEmbeddability aEmbeddability) const;
private:
	TUint iEmbeddabilityFlags;
private:
	TInt iTApaEmbeddabilityFilter_Reserved1;
	};

#ifndef SYMBIAN_ENABLE_SPLIT_HEADERS
/** 
The uid for the Open service.

@publishedPartner
@released
*/
const TUid KOpenServiceUid = { 0x10208DCA };

/** Application service information.

Encapsulates a service UID and associated opaque data.

An instance of this class provides information about
a specific implementation of the service identified by
the encapsulated service UID.

@publishedPartner
@released
*/
class TApaAppServiceInfo
	{
public:
	IMPORT_C TApaAppServiceInfo();
	IMPORT_C TApaAppServiceInfo(TUid aUid, CArrayFixFlat<TDataTypeWithPriority>* aDataTypes, HBufC8* aOpaqueData);
	IMPORT_C void ExternalizeL(RWriteStream& aStream) const;
	IMPORT_C void InternalizeL(RReadStream& aStream);
	IMPORT_C void Release();
	IMPORT_C CArrayFixFlat<TDataTypeWithPriority>& DataTypes();
	IMPORT_C TUid Uid() const;
	IMPORT_C const CArrayFixFlat<TDataTypeWithPriority>& DataTypes() const;
	IMPORT_C const TDesC8& OpaqueData() const;
private:
	TUid iUid;
	CArrayFixFlat<TDataTypeWithPriority>* iDataTypes;
	HBufC8* iOpaqueData;
	TInt iTApaAppServiceInfo;
	};

/** Application service information array.

Owns an array of TApaAppServiceInfo objects.

@see TApaAppServiceInfo
@publishedPartner
@released
*/
class CApaAppServiceInfoArray : public CBase
	{
protected:
	IMPORT_C CApaAppServiceInfoArray();
public:
	/** Provides access to the encapsulated array of
	TApaAppServiceInfo objects.

	@return A generic array of TApaAppServiceInfo objects. */
	virtual TArray<TApaAppServiceInfo> Array()=0;
private:
	IMPORT_C virtual void CApaAppServiceInfoArray_Reserved1();
	IMPORT_C virtual void CApaAppServiceInfoArray_Reserved2();
private:
	TInt iCApaAppServiceInfoArray_Reserved1;
	};

#endif //SYMBIAN_ENABLE_SPLIT_HEADERS

#endif
