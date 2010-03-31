/*
* Copyright (c) 2005-2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Virtual Phonebook framework error codes
*
*/


#ifndef VPBKERROR_H
#define VPBKERROR_H


// INCLUDES
#include <e32std.h>


/**
 * Virtual Phonebook Engine API error codes and functions.
 *
 * These codes are used in Virtual Phonebook APIs and all store plugin 
 * implementations must use them as documented in the API header files.
 * @lib VPbkEng.lib
 */
namespace VPbkError
    {
    /// Panic category for Virtual Phonebook APIs.
    _LIT(KPanicCategory, "VPbkEng");

    /**
     * Panic codes for the Virtual Phonebook APIs.
     */
    enum TPanicCode
        {
        /// Invalid index was used
        EInvalidTypeParameter = 1,
        EInvalidTypeParameterResource,
        EFieldDataTypeMismatch,
        EInvalidFieldIndex,
        ENullContactField,
        EInvalidContactField,
        EInvalidContactIndex,
        EInvalidStoreIndex,
        EInvalidLength,
        EInvalidAccessToReadOnlyContact,
        EInvalidLinkArrayVersion,
        EAccessOfUnopenedStore
        };

    /**
     * Called if an unrecoverable error is detected.
     *
     * Stops the thread with User::Panic.
     *
     * @param aPanicCode One of the TPanicCode values.
     */
    IMPORT_C void Panic(TPanicCode aPanicCode);
    }


#endif  // VPBKERROR_H
