/*
* Copyright (c) 2004-2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Virtual Phonebook observer interface for contact copying.
*
*/


#ifndef MVPBKCONTACTCOPYOBSERVER_H
#define MVPBKCONTACTCOPYOBSERVER_H

// INCLUDES
#include <e32cmn.h>
#include <e32def.h>

// FORWARD DECLARATIONS
class MVPbkContactOperationBase;
class MVPbkContactLinkArray;

/**
 * Virtual Phonebook contact copy observer interface.
 * This interface is used to signal the client of the copying
 * operations events. 
 */
class MVPbkContactCopyObserver
    {
    public: // Interface
        /**
         * Called when the contact has been successfully commited or
         * copied. Caller takes the ownership of results.
         *
         * @param aOperation    The operation that this observer monitors.
         * @param aResults  An array of links to copied contacts.
         *                  Caller takes the ownership of the 
         *                  object immediately.
         */
        virtual void ContactsSaved( MVPbkContactOperationBase& aOperation,
            MVPbkContactLinkArray* aResults ) = 0;
        
        /**
         * Called when there was en error while saving contact(s).
         * @param aOperation    The operation that this observer monitors.
         * @param aError an error that occured.
         */
        virtual void ContactsSavingFailed( 
                MVPbkContactOperationBase& aOperation, TInt aError ) = 0;

        /**
         * Returns an extension point for this interface or NULL.
         * @param aExtensionUid Uid of extension
         * @return Extension point or NULL
         */
        virtual TAny* ContactCopyObserverExtension( 
                TUid /*aExtensionUid*/ ) { return NULL; }

    protected:  // Destructor
        /**
         * Destructor.
         */
        virtual ~MVPbkContactCopyObserver() { }

    };
    
#endif // MVPBKCONTACTCOPYOBSERVER_H

// End of File
