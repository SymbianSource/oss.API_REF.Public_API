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
// apadef.h
//

#ifndef __APADEF_H__
#define __APADEF_H__

#include <e32base.h>

/** Defines the command codes used to indicate the way an application is to be 
launched.

@publishedAll 
@released
@see CApaCommandLine */
enum TApaCommand
	{
	/** The application is to open the document specified on the command line. */
	EApaCommandOpen,
	/** The application is to create the document specified on the command line. */
	EApaCommandCreate,
	/** The application is to run and open the last used document. */
	EApaCommandRun,
	/** The application is to open the last used document and to run in the background. */
	EApaCommandBackground,
	/** Reserved for future use. */
	EApaCommandViewActivate,
	/** The application is to run without views.
	
	This should NOT be used for view based applications. */
	EApaCommandRunWithoutViews,
	/** The application is to run in the background and viewless mode */
	EApaCommandBackgroundAndWithoutViews
	};

/**
@publishedAll 
@released
*/
const TInt KApaMaxAppCaption=0x100;	// Default name is a file name, so the same limit is used

// TApaAppCaption is the current language name of the app (for task lists, dialogs etc)

/** Defines a modifiable buffer descriptor to contain the caption or the short caption 
for an application. 

@publishedAll 
@released */
typedef TBuf<KApaMaxAppCaption> TApaAppCaption; 

#ifndef SYMBIAN_ENABLE_SPLIT_HEADERS
/**
@internalComponent
*/
const TInt KApaMaxCommandLine=0x100;	

/**
@internalComponent
*/
typedef TBuf<KApaMaxCommandLine> TApaCommandLine;

#endif //SYMBIAN_ENABLE_SPLIT_HEADERS

/** Maximum length of an application group name.

@publishedAll 
@released
@see TApaAppGroupName */
const TInt KApaMaxAppGroupName=0x10; // Length of App's logical groupname

/** An application group name.

This is a name that allows applications to be categorized, for instance "Games" 
or "Utilities". 

@publishedAll 
@released */
typedef TBuf<KApaMaxAppGroupName> TApaAppGroupName;

/** The hexadecimal value of the 2nd UID that defines a DLL as being a Unicode 
UI application. In .mmp files, the hexadecimal number is explicitly inserted 
as the first value following the UID keyword.

@publishedAll 
@released
@see KAppUidValue */
const TInt KAppUidValue16 = 0x100039CE;

/** The 2nd UID that defines a DLL as being a Unicode UI application.

@publishedAll 
@released
@see KUidApp */
const TUid KUidApp16={KAppUidValue16};

//
// 2nd Uid for app doc files
/**
@publishedAll 
@released
*/
const TUid KUidAppDllDoc16={0x10003A12};

/** The UID encoded in a TPictureHeader that identifies a picture as a door (for 
Unicode builds).

@publishedAll 
@released
@see KUidPictureTypeDoor */
const TUid KUidPictureTypeDoor16={0x10003A33};

//
// Uid's for streams in stream dictionaries

/**
@publishedAll 
@released
*/
const TUid KUidSecurityStream16={0x10003A40};

/**
@publishedAll 
@released
*/
const TUid KUidAppIdentifierStream16={0x10003A34};

/** The type-independent 2nd UID that identifies a DLL as being a UI application.

@publishedAll 
@released
@see KUidApp16 */
#define KUidApp KUidApp16

/** The type-independent hexadecimal value of the 2nd UID that identifies a DLL as 
being a UI application.

@publishedAll 
@released
@see KAppUidValue16 */
#define KAppUidValue KAppUidValue16 //lint !e1923 supress could become const variable

/**
@publishedAll 
@released
*/
#define KUidAppDllDoc KUidAppDllDoc16

/** The type independent UID encoded in a TPictureHeader that identifies a picture 
as a door.

@publishedAll 
@released
@see KUidPictureTypeDoor16
@see TPictureHeader
@see TApaModelDoorFactory::NewPictureL() */
#define KUidPictureTypeDoor KUidPictureTypeDoor16

/**
@publishedAll 
@released
*/
#define KUidAppIdentifierStream KUidAppIdentifierStream16

/**
@publishedAll 
@released
*/
#define KUidSecurityStream KUidSecurityStream16


const TUid KUidFileEmbeddedApplicationInterfaceUid={0x101f8c96};

#endif	// __APADEF_H__
