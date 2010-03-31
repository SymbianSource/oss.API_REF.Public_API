/*
* Copyright (c) 2002-2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
* which accompanies this distribution, and is available
* at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:
*
*/



#ifndef __TULPANICS_H__
#define __TULPANICS_H__

// ========== DATA TYPES ===================================

enum TTulPanic
	{
    ETulPanicDescriptorLength = 0x100,
    ETulPanicInvalidTokenizerSearchCase
	};


//Error codes
enum TStringLoaderPanic
    {
    ETooFewArguments        = 0, // Unsolved parameters in resource string.
    ETooManyArguments       = 1, // Already solved all parameters in  resource string.
    EKeyStringNotFound      = 2, // The key string wasn't found in formating.
    EInvalidIndex           = 3, // Invalid index in Format-method
    EDescriptorTooSmall     = 4, // Too small destination descriptor.
    ECCoeEnvNotInitialized  = 5, // CCoeEnv is not initialized
    EInvalidSubstitute      = 6  // Substituted string contains KSubStringSeparator
    };


// ========== FUNCTION PROTOTYPES ==========================

// ---------------------------------------------------------
// Panic
//
// ---------------------------------------------------------
//
GLREF_C void Panic (TTulPanic);

#endif // __TULPANICS_H__

