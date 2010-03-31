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
//

#ifndef __APGDOOR_H__
#define __APGDOOR_H__

#if !defined(__E32STD_H__)
#include <e32std.h>
#endif
#if !defined(__E32BASE_H__)
#include <e32base.h>
#endif
#if !defined(__S32STD_H__)
#include <s32std.h>
#endif
#if !defined(__GDI_H__)
#include <gdi.h>
#endif
#if !defined(__APPARC_H__)
#include <apparc.h>
#endif
#if !defined(__APADBASE_H__)
#include <apadbase.h>
#endif

/**
@internalAll
*/
#ifdef _UNICODE
#define KUidApaDoorDocStream KUidApaDoorDocStream16
#else
#define KUidApaDoorDocStream KUidApaDoorDocStream8
#endif

/**
@internalComponent
@deprecated
*/
const TUid KUidApaDoorDocStream8={0x10000144};

/**
@internalComponent
*/
const TUid KUidApaDoorDocStream16={0x10003A35};

// classes defined:
class CApaDoor;
class TApaPictureFactory;
//
// classes referenced:
class CEmbeddedStore;
//

class CApaDoor : public CApaDoorBase
/** A wrapper for an embedded document that can be displayed in a user interface 
as an icon or a glass door. 

@publishedAll 
@released */
	{
public:
	IMPORT_C static CApaDoor* NewLC(RFs& aFs, CApaDocument& aDoc,const TSize& aDefaultIconSizeInTwips); // call to create a new door in iconic format - restoration is achieved with TApaPictureFactory
	IMPORT_C static CApaDoor* NewL(RFs& aFs, CApaDocument& aDoc,const TSize& aDefaultIconSizeInTwips); // call to create a new door in iconic format - restoration is achieved with TApaPictureFactory
	IMPORT_C static CApaDoor* NewL(RFs& aFs, const CStreamStore& aStore,TStreamId aStreamId,CApaProcess& aProcess); // restoring constructor called by TApaPictureFactory
	//
	IMPORT_C void SetFormatToIconL();
	IMPORT_C void SetFormatToGlassL();
	IMPORT_C void SetFormatToTemporaryIconL(TBool aEnabled=ETrue);
	//
	IMPORT_C CApaDocument* DocumentL(TBool aCheckPassword=EFalse); // returns a pointer to the doc, restoring it if necessary. Checks password if required.
	inline TDesC* Caption()const;
	IMPORT_C TUid AppUidL()const;
	//
	// persistence methods
	IMPORT_C void RestoreL(const CStreamStore& aStore,TStreamId aHeadStreamId);
	TStreamId StoreL(CStreamStore& aStore) const;
	//
	IMPORT_C ~CApaDoor();
	//
	// from CPicture
	void Draw(CGraphicsContext& aGc,const TPoint& aTopLeft,const TRect& aClipRect,
						MGraphicsDeviceMap* aMap)const; // draws according to current iPicFormat
	void DetachFromStoreL(TDetach aDegree=EDetachFull); //lint !e1735 Virtual function has default parameter - Must use the same default as declared by CPicture
	void GetOriginalSizeInTwips(TSize& aSize)const;
	void SetScaleFactor(TInt aScaleFactorWidth,TInt aScaleFactorHeight);
	void SetCropInTwips(const TMargins& aMargins);
	TPictureCapability Capability() const;
	void GetCropInTwips(TMargins& aMargins) const;
	TInt ScaleFactorWidth() const;
	TInt ScaleFactorHeight() const;
private:
	CApaDoor(RFs& aFs, CApaProcess& aProcess);
	CApaDoor(RFs& aFs, CApaDocument& aDoc,const TSize& aDefaultIconSizeInTwips);
	void ConstructL();
	//
	void SetIconSizeInTwips(TSize aSize); // for use of factory
	//
	void StoreDocL(CPersistentStore& aStore)const;
	void RestoreDocL(const CPersistentStore& aStore);
	void RestoreDoorStateL(const CStreamStore& aStore,const CStreamDictionary& streamDic);
	static CStreamDictionary* ReadStreamDictionaryLC(const CStreamStore& aStore,TStreamId aStreamId);
	static void CopyStoreL(const CEmbeddedStore& aSourceStore,RWriteStream& aTargetStream);
	void ExternalizeStateStreamL(CStreamStore& aStore,CStreamDictionary& aStreamDict)const;
	void InternalizeStateStreamL(const CStreamStore& aStore,const CStreamDictionary& aStreamDict,TSize aDefaultIconSize);
	//
	// required so CPicture's can be swizzled
	void ExternalizeL(RWriteStream& aStream)const;
	// from CApaDoorBase
	virtual TSize GlassDoorSize()const;
	TUid AppUidFromStreamL() const;
private:
	RFs& iFs;
	HBufC* iAppCaption; // name of the app used to create the embedded object
	CApaProcess* iApaProcess;
	CApaDocument* iApaDoc;
	CPicture* iPicture; // the current view of the door, either iconic or glass
	CEmbeddedStore* iStore; // store containing the doc
	CBufSeg* iStoreHost; // the host for the embedded store, if the door has been detached from its originating store
	__MUTABLE TSize iIconSizeInTwips;
	//
	friend class TApaPictureFactory;
	};


class TApaPictureFactory : public MPictureFactory
// Recognizes KUidPictureTypeDoor and creates CApaDoor pictures
/** A factory class for instantiating and restoring an application's door.

A door factory object is constructed by the UI environment and can be accessed 
by calling CEikonEnv::PictureFactory().

@publishedAll
@released 
@see CEikonEnv::PictureFactory()
@see CApaDoor */
	{
public:
	IMPORT_C TApaPictureFactory(CApaProcess* aAppProcess);
	inline void SetIconSize(TSize aIconSizeInTwips);
	//
	// from MPictureFactory
	IMPORT_C void NewPictureL(TPictureHeader& aPictureHeader,const CStreamStore& aPictureStore)const; // used to create CApaDoor's during document restore only 
protected:
	IMPORT_C TApaPictureFactory();
	
private:
	CApaProcess* iApaProcess;
	TSize iIconSize;
	TInt iSpare;
	};


//
// inlines
//

inline TDesC* CApaDoor::Caption()const 
	/** Gets the name of the application with which the embedded document is associated.
	
	@return A pointer to a descriptor containing the name of the application. */
	{ return iAppCaption; }

inline void TApaPictureFactory::SetIconSize(TSize aIconSizeInTwips)
	/** Sets the size of the icon.
	
	@param aIconSizeInTwips The size of the icon, in twips. */
	{ iIconSize = aIconSizeInTwips; }

#endif
