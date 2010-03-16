/*
* Copyright (c) 2004 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:  Open IM API errors
*
*/


#ifndef OPENAPI_IM_ERRORS_H
#define OPENAPI_IM_ERRORS_H

const TInt KImErrorBase = -30130;

enum TImErrors   // SDK API errors
    {
    /**
    * General Error
    */
    KImApiGeneralError = KImErrorBase - 1,

    /**
    * Error not registered
    */
    KImApiErrNotRegistered = KImErrorBase - 2,

    /**
    * Error already registered
    */
    KImApiErrAlreadyRegistered = KImErrorBase - 3,

    /**
    * Error not logged
    */
    KImApiErrNotLogged = KImErrorBase - 4,

    /**
    * Login is already ongoing
    */
    KImApiErrLoginInProgress = KImErrorBase - 5,

    /**
    * The contact ID provided in SendPToPMessage is invalid
    */
    KImApiErrInvalidContactId = KImErrorBase - 6,

    /**
    * The user ID provided in SendPToPMessage is invalid
    */
    KImApiErrInvalidUserId = KImErrorBase - 7,

    /**
    * Not all the users have a valid User ID when sending message
    */
    KImApiErrPartialSuccess = KImErrorBase - 8,

    /**
    * Special IM error code: the sender is blocked by the recipient
    */
    KImApiErrSenderBlocked = KImErrorBase - 9,

    /**
    * Special IM error code: the recipient is not logged in
    */
    KImApiErrRecipientNotLogged = KImErrorBase - 10,

    /**
    * Logout is already in progress
    */
    KImApiErrLogoutInProgress = KImErrorBase - 11,

    /**
    * CancelLogin is already in progress
    */
    KImApiErrCancelLoginInProgress = KImErrorBase - 12,

    /**
    * Already logged in
    */
    KImApiErrAlreadyLoggedIn = KImErrorBase - 13,

    /**
    * Wrong Password
    */
    KImApiErrWrongPassword = KImErrorBase - 14
    };


#endif // OPENAPI_IM_ERRORS_H

//  End of File
