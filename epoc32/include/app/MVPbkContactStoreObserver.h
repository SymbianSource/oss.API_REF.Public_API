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
* Description:  An observer interface for contact store events
*
*/


#ifndef MVPBKCONTACTSTOREOBSERVER_H
#define MVPBKCONTACTSTOREOBSERVER_H


// INCLUDES
#include <e32std.h>

// FORWARD DECLARATIONS
class MVPbkContactStore;
class MVPbkContactLink;

// CLASS DECLARATIONS

/**
 * A class for a contact store event.
 *
 * The contact store event contains the type of the event and
 * possibly a contact link to a changed contact.
 */
class TVPbkContactStoreEvent
    {
    public: // Types
        /**
         * The type of the event
         */
        enum TVPbkContactStoreEventType
            {
            /// No event occured
            ENullEvent,
            /// A contact has been added to the contact store
            EContactAdded,
            /// A contact has been deleted from the contact store
            EContactDeleted,
            /// An existing contact in the contact store has been changed
            EContactChanged,
            /// A contact group has been added to the contact store
            EGroupAdded,
            /// A contact group has been deleted from the contact store
            EGroupDeleted,
            /// An existing contact group in the contact store has been changed
            EGroupChanged,
            /// Contact store backup is beginning
            EStoreBackupBeginning,
            /// Contact store restore is beginning
            EStoreRestoreBeginning,
            /// Contact store backup or restore is completed
            EStoreBackupRestoreCompleted,
            /// There has been some unknown changes in the contact store
            EUnknownChanges
            };

    public: // Interface
        /**
         * Constructor
         *
         * @param aEventType The type of the contact store event
         * @param aContactLink The identifier of the changed contact or NULL.
         *                     The link is not owned by this class.
         */
        TVPbkContactStoreEvent(
                TVPbkContactStoreEventType aEventType, 
                MVPbkContactLink* aContactLink);

    public: // Contact store event data
        /// Own: Type of the event that has happened
        TVPbkContactStoreEventType iEventType;
        /// Ref: Link to the contact that is accociated with the event or NULL. 
        ///      The link is valid only during HandleStoreEventL function call
        ///      and client can not take the ownership of the instance.
        //       Client must clone the link if it needs it later.
        MVPbkContactLink* iContactLink;
        ///Own: Spare for future extension
        TAny* iSpare;
        ///Own: Spare for future extension
        TAny* iSpare2;
    };

inline TVPbkContactStoreEvent::TVPbkContactStoreEvent(
        TVPbkContactStoreEventType aEventType, 
        MVPbkContactLink* aContactLink) :
    iEventType(aEventType),
    iContactLink(aContactLink)
    {
    }

/**
 * An observer interface for contact store events
 *
 * The client of the contact store must implement this interface. The contact
 * store informs client about its state using this interface. The client is
 * also able to get store events about changes in the store content.
 */
class MVPbkContactStoreObserver
    {
    public:  // New functions
        /**
         * Called when a contact store is ready to use.
         *
         * @param aContactStore The store that is ready.
         */
        virtual void StoreReady(MVPbkContactStore& aContactStore) =0;

        /**
         * Called when a contact store becomes unavailable.
         *
         * Client may inspect the reason of the unavailability and decide
         * whether or not it will keep the store opened (ie. listen to 
         * the store events).
         *
         * @param aContactStore The store that became unavailable.
         * @param aReason The reason why the store is unavailable.
         *                This is one of the system wide error codes.
         */
        virtual void StoreUnavailable(MVPbkContactStore& aContactStore, 
                TInt aReason) =0;

        /**
         * Called when changes occur in the contact store.
         *
         * @see TVPbkContactStoreEvent
         * @param aContactStore A store whose event it is.
         * @param aStoreEvent The event that has occurred.
         */
        virtual void HandleStoreEventL(
                MVPbkContactStore& aContactStore, 
                TVPbkContactStoreEvent aStoreEvent) =0;

        /**
         * Returns an extension point for this interface or NULL.
         *
         * @param aExtensionUid no extensions defined currently.
         * @return an extension point for this interface or NULL.
         */
        virtual TAny* ContactStoreObserverExtension(TUid /*aExtensionUid*/) 
                { return NULL; }

    protected:  // Destructor
        virtual ~MVPbkContactStoreObserver() { }

    };


#endif  // MVPBKCONTACTSTOREOBSERVER_H

//End of file
