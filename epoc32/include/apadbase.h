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

#ifndef __APADBASE_H__
#define __APADBASE_H__

#if !defined(__E32STD_H__)
#include <e32std.h>
#endif
#if !defined(__S32STD_H__)
#include <s32std.h>
#endif
#if !defined(__GDI_H__)
#include <gdi.h>
#endif


class CApaDoorBase : public CPicture
// Base class for a wrapper for embedded CApaDocuments
/** The base class for the graphic representation of an embedded document.

An embedded document can be represented either as an icon or as a glass picture. 
Such a graphic representation is known as a door.

The class is intended for derivation.

@publishedAll 
@released
@see CApaDoor
@see CApaModelDoor */
	{
public:
	
	/** Defines the possible formats for the graphical representation of the embedded 
	document. */
	enum TFormat {
		/** The representation is an icon. */
		EIconic,
		/** The representation is a glass door. */
		EGlassDoor,
		/** The representation is a glass door but has been temporarily switched to an icon. */
		ETemporarilyIconic
		};
public:
	inline TFormat Format()const;
	inline TUid Source()const;
	inline void SetSource(TUid aSource);
	// Virtuals from CPicture
	IMPORT_C virtual TStreamId StoreL(CStreamStore& aStore) const;
	IMPORT_C virtual void SetScaleFactor(TInt aScaleFactorWidth,TInt aScaleFactorHeight); 
	IMPORT_C virtual void SetCropInTwips(const TMargins& aMargins); 
	IMPORT_C virtual TPictureCapability Capability() const;
	IMPORT_C virtual void GetCropInTwips(TMargins& aMargins) const; 
	IMPORT_C virtual TInt ScaleFactorWidth() const; 
	IMPORT_C virtual TInt ScaleFactorHeight() const; 
	IMPORT_C virtual TBool LineBreakPossible(TUint aClass,TBool aBeforePicture,TBool aHaveSpaces) const;
	IMPORT_C virtual TBool NativePixelSize(TSize& aPixelSize);
protected:
	IMPORT_C CApaDoorBase();
	IMPORT_C void ExternalizeBaseStreamL(CStreamStore& aStore,CStreamDictionary& aStreamDict)const;
	IMPORT_C TSize InternalizeBaseStreamL(const CStreamStore& aStore,const CStreamDictionary& aStreamDict); // returns current size in twips

private:
	IMPORT_C virtual void CApaDoorBase_Reserved1();
	IMPORT_C virtual void CApaDoorBase_Reserved2();
protected:

	/** Returns the size of the glass door, in twips.
	
	A concrete implementation of this function is provided by derived classes.
	
	@return The size of the glass door, in twips. 
	
	@publishedAll 
	@released */
	virtual TSize GlassDoorSize()const=0;
protected:
	TFormat iFormat;
	TUid iSource; // foreign representation of a translated door (eg MS Word doc)

private:
	TInt iCApaDoorBase_Reserved1;
	};

//
// inlines
//

inline CApaDoorBase::TFormat CApaDoorBase::Format()const
	/** Gets the current format of the representation of the embedded document.
	
	@return The format for the representation of the embedded document. */
	{ return iFormat; }

inline TUid CApaDoorBase::Source()const
	/** Gets the UID that identifies this door when the source originates on a non-Symbian 
	OS device.
	
	This is used by converters.
	
	@return The UID for the non-Symbian OS source. For a source that originates 
	on a Symbian OS phone, this is KNullUid. */
	{ return iSource; }

inline void CApaDoorBase::SetSource(TUid aSource)
	/** Sets the UID that identifies this door when the source originates on a non-Symbian 
	OS device.
	
	This is used by converters.
	
	@param aSource The UID for the non-Symbian OS source. For a source that originates 
	on a Symbian OS phone, this is KNullUid. */
	{ iSource=aSource; }

#endif
