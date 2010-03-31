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
//

#ifndef __APGCTL_H__
#define __APGCTL_H__

#if !defined(__E32STD_H__)
#include <e32std.h>
#endif
#if !defined(__E32BASE_H__)
#include <e32base.h>
#endif

// classes defined:
class CApaSystemControl;
#ifndef SYMBIAN_ENABLE_SPLIT_HEADERS
class CApaSystemControlList;
#endif //SYMBIAN_ENABLE_SPLIT_HEADERS

// classes referenced:
class RFs;
class CApaMaskedBitmap;
//

/**
Calls the control DLL's first ordinal function to create and run the control.

The function leaves with KErrBadLibraryEntryPoint if the ordinal 1 function 
cannot be found.

@publishedAll 
@released
*/
typedef TInt (*ApaRunSystemControl)(const TDesC&);

/**
@publishedAll 
@released
*/
#ifdef _UNICODE
#define KUidSystemControlDll KUidSystemControlDll16
#else
#define KUidSystemControlDll KUidSystemControlDll8
#endif

/**
@publishedAll 
@deprecated
*/
const TInt KSystemControlDllUidValue8=0x10000297;

/**
@publishedAll
@deprecated
*/
const TUid KUidSystemControlDll8={KSystemControlDllUidValue8};

/**
@publishedAll
@released
*/
const TUid KUidSystemControlDll16={0x10003A34};


class CApaSystemControl : public CBase
/** Wrapper to a control panel application.

An instance of the class represents a control panel application. It is also a cache for the control's icon and caption.

An instance of the wrapper can only be constructed by the control panel application list, which 
is a CApaSystemControlList object. 

@publishedAll
@released */
	{
public:
	IMPORT_C void CreateL();
	IMPORT_C TUid Type()const;
	IMPORT_C TFileName FileName()const;
	IMPORT_C CApaMaskedBitmap* Icon()const; // one size of icon, 48x48?
	IMPORT_C TPtrC Caption()const;
	IMPORT_C TPtrC ShortCaption()const;
private:
	static CApaSystemControl* NewL(RFs& aFs,const TDesC& aFullPath,const TUidType aUidType);
	~CApaSystemControl();
	
	CApaSystemControl(RFs& aFs);
	void ConstructL(const TDesC& aFullPath,const TUidType aUidType);
private:
	CApaSystemControl* iNext;
	HBufC* iCaption;
	HBufC* iShortCaption;
	CApaMaskedBitmap* iIcon;
	TBool iExists; // used during updating
	TFileName iFullPath;
	TUidType iUidType;
	RFs& iFs;
	
	friend class CApaSystemControlList;
	};


#ifndef SYMBIAN_ENABLE_SPLIT_HEADERS
class CApaSystemControlList : public CBase
/** Provides a list of all available control panel applications present on the phone. 
This class is implemented as a linked list of CApaSystemControl. Updates the control panel application list by removing 
control panels that no longer exist, adding new control panels found to the control panel application list and replacing 
a control panel if found in an earlier drive.

@see CApaSystemControl
@publishedPartner
@released
*/
	{
public:
	IMPORT_C static CApaSystemControlList* NewL(RFs& aFs);
	IMPORT_C ~CApaSystemControlList();
	
	IMPORT_C TInt Count()const;
	IMPORT_C TInt Index(TUid aType)const;
	IMPORT_C CApaSystemControl* Control(TInt aIndex)const;
	IMPORT_C CApaSystemControl* Control(TUid aType)const;
	
	IMPORT_C void UpdateL();
	inline TInt UpdateCount()const;
private:
	CApaSystemControlList(RFs& aFs);
	CApaSystemControl* PreviousControl(const CApaSystemControl* aControl) const;
private:
	TInt iUpdateCount;
	RFs& iFs;
	CApaSystemControl* iControl;
	};


//
// inlines
//


inline TInt CApaSystemControlList::UpdateCount()const
/** Gets the number of times the control panel application list has been 
updated (by calling UpdateL()). It returns 1 for a newly created list.

@return The number of times the control panel application list has been changed. */
	{ return iUpdateCount; }

#endif //SYMBIAN_ENABLE_SPLIT_HEADERS

#endif
