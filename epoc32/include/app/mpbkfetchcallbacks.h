/*
* Copyright (c) 2002 Nokia Corporation and/or its subsidiary(-ies).
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
* Description: 
*     Fetch dialog MPbkFetchKeyCallback for Phonebook.
*
*/


#ifndef __MPbkFetchCallbacks_H__
#define __MPbkFetchCallbacks_H__

//  INCLUDES
#include <e32def.h>
#include <cntdef.h> // TContactItemId
#include <w32std.h> // TKeyEvent, TEventCode

//  FORWARD DECLARATIONS
class CContactIdArray;

// CLASS DECLARATION

/**
 * Phonebook fetch dialog key event callback. 
 */
class MPbkFetchKeyCallback
    {
    public:
        /// Callback result code
        enum TResult
            {
            /// Ignores the key event and lets the fetch dialog process it
            EKeyWasNotConsumed,
            /// Hides the key event from the fetch dialog
            EKeyWasConsumed,
            /// Close the fetch dialog as if it was accepted
            EAccept,
            /// Close the fetch dialog as if it was canceled
            ECancel
            };

        /**
         * Callback function for key presses in fetch.
         * @param aKeyEvent The key event.
         * @param aType The type of event. 
         * @return  Callback result.
         */
        virtual TResult PbkFetchKeyCallbackL
            (const TKeyEvent& aKeyEvent, TEventCode aType)=0;

    protected:
        /**
         * Protected destructor. Derived class instances are not
         * destroyed through this interface.
         */
        virtual ~MPbkFetchKeyCallback() { }
    };


/**
 * Accept callback interface for fetch dialogs.
 */
class MPbkFetchDlgAccept
    {
    public:
        /**
         * Result code whether fetch should be accepted, rejected or canceled.
         */
        enum TPbkFetchAccepted
            {
            /// Fetch result is accepted and the fetch dialog is closed
            KFetchYes = 0,
            /// Fetch result is rejected and the fetch dialog remains open
            KFetchNo,
            /// Fetch result is rejected and the fetch dialog is canceled
            KFetchCanceled
            };

        /**
         * Called by a fetch dialog when user makes a selection.
         *
         * @param aId  Focused contact item
         * @param aMarkedEntries  Selected contact items array
         * @return @see TPbkFetchAccepted
         * @see TPbkFetchAccepted
         */
        virtual TPbkFetchAccepted PbkFetchAcceptedL
            (TContactItemId aId, CContactIdArray* aMarkedEntries) = 0;

    protected:
        /**
         * Protected destructor. Derived class instances are not destroyed 
         * through this interface.
         */
        virtual ~MPbkFetchDlgAccept() { }
    };

#endif // __MPbkFetchCallbacks_H__

// End of File
