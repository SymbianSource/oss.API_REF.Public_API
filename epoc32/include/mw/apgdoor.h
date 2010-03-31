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
// apgdoor.h
//

#ifndef __APGDOOR_H__
#define __APGDOOR_H__

#include <e32std.h>
#include <e32base.h>
#include <s32std.h>
#include <gdi.h>
#include <apparc.h>
#include <apadbase.h>

#ifndef SYMBIAN_ENABLE_SPLIT_HEADERS
/**
@internalAll
*/
const TUid KUidApaDoorDocStream={0x10003A35};

#endif //SYMBIAN_ENABLE_SPLIT_HEADERS
// classes referenced
class CEmbeddedStore;

/** A wrapper for an embedded document that can be displayed in a user interface 
as an icon or a glass door. 

@publishedAll 
@released */
class CApaDoor : public CApaDoorBase
	{
public:
	IMPORT_C static CApaDoor* NewLC(RFs& aFs, CApaDocument& aDoc,const TSize& aDefaultIconSizeInTwips); // call to create a new door in iconic format - restoration is achieved with TApaPictureFactory
	IMPORT_C static CApaDoor* NewL(RFs& aFs, CApaDocument& aDoc,const TSize& aDefaultIconSizeInTwips); // call to create a new door in iconic format - restoration is achieved with TApaPictureFactory
	IMPORT_C static CApaDoor* NewL(RFs& aFs, const CStreamStore& aStore,TStreamId aStreamId,CApaProcess& aProcess); // restoring constructor called by TApaPictureFactory

	IMPORT_C void SetFormatToIconL();
	IMPORT_C void SetFormatToGlassL();
	IMPORT_C void SetFormatToTemporaryIconL(TBool aEnabled=ETrue);

	IMPORT_C CApaDocument* DocumentL(TBool aCheckPassword=EFalse); // returns a pointer to the doc, restoring it if necessary. Checks password if required.
	inline TDesC* Caption()const;
	IMPORT_C TUid AppUidL()const;
	// persistence methods
	IMPORT_C void RestoreL(const CStreamStore& aStore,TStreamId aHeadStreamId);
	TStreamId StoreL(CStreamStore& aStore) const;

	IMPORT_C ~CApaDoor();
public: // from CPicture
	void Draw(CGraphicsContext& aGc,const TPoint& aTopLeft,const TRect& aClipRect, MGraphicsDeviceMap* aMap)const; // draws according to current iPicFormat
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

	void SetIconSizeInTwips(TSize aSize); // for use of factory

	void StoreDocL(CPersistentStore& aStore)const;
	void RestoreDocL(const CPersistentStore& aStore);
	void RestoreDoorStateL(const CStreamStore& aStore,const CStreamDictionary& streamDic);
	static CStreamDictionary* ReadStreamDictionaryLC(const CStreamStore& aStore,TStreamId aStreamId);
	static void CopyStoreL(const CEmbeddedStore& aSourceStore,RWriteStream& aTargetStream);
	void ExternalizeStateStreamL(CStreamStore& aStore,CStreamDictionary& aStreamDict)const;
	void InternalizeStateStreamL(const CStreamStore& aStore,const CStreamDictionary& aStreamDict,TSize aDefaultIconSize);

	// required so CPicture's can be swizzled
	void ExternalizeL(RWriteStream& aStream)const;
private: // from CApaDoorBase
	TSize GlassDoorSize()const;
	TUid AppUidFromStreamL() const;
private:
	RFs& iFs;
	HBufC* iAppCaption; // name of the app used to create the embedded object
	CApaProcess* iApaProcess;
	CApaDocument* iApaDoc;
	CPicture* iPicture; // the current view of the door, either iconic or glass
	CEmbeddedStore* iStore; // store containing the doc
	CBufSeg* iStoreHost; // the host for the embedded store, if the door has been detached from its originating store
	mutable TSize iIconSizeInTwips;
private:	
	friend class TApaPictureFactory;
	};


/** A factory class for instantiating and restoring an application's door.

A door factory object is constructed by the UI environment and can be accessed 
by calling CEikonEnv::PictureFactory().

@publishedAll
@released 
@see CEikonEnv::PictureFactory()
@see CApaDoor */
class TApaPictureFactory : public MPictureFactory
// Recognizes KUidPictureTypeDoor and creates CApaDoor pictures
	{
public:
	IMPORT_C TApaPictureFactory(CApaProcess* aAppProcess);
	inline void SetIconSize(TSize aIconSizeInTwips);
public:	// from MPictureFactory
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

/** Gets the name of the application with which the embedded document is associated.
@return A pointer to a descriptor containing the name of the application. */
inline TDesC* CApaDoor::Caption()const 
	{ return iAppCaption; }

/** Sets the size of the icon.
@param aIconSizeInTwips The size of the icon, in twips. */
inline void TApaPictureFactory::SetIconSize(TSize aIconSizeInTwips)
	{ iIconSize = aIconSizeInTwips; }

#endif	// __APGDOOR_H__
