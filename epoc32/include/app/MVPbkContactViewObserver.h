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
* Description:  An observer interface for contact views.
*
*/


#ifndef MVPBKCONTACTVIEWOBSERVER_H
#define MVPBKCONTACTVIEWOBSERVER_H

// INCLUDES
#include <e32std.h>

// FORWARD DECLARATIONS
class MVPbkContactViewBase;
class MVPbkContactLink;

// CLASS DECLARATIONS

/**
 * An observer interface for contact views.
 *
 * A client will receive events related to the view state and the view content
 * via this interface.
 * @see CVPbkContactManager::CreateContactViewLC
 */
class MVPbkContactViewObserver
    {
    public: // Interface
        /**
         * Called when a view is ready for use. 
         * 
         * This function may also be called if view is already ready. Then
         * it means that the view has been updated and the observer have
         * to take this into account.
         *
         * @param aView A contact view sending the event.
         */
        virtual void ContactViewReady(
                MVPbkContactViewBase& aView ) = 0;

        /**
         * Called when a view is unavailable for a while. 
         * 
         * When the view is again available ContactViewReady will be called.
         * The contents of the view may change completely while it is
         * unavailable.
         *
         * @param aView A contact view sending the event.
         */
        virtual void ContactViewUnavailable(
                MVPbkContactViewBase& aView ) = 0;

        /**
         * Called when a contact has been added to the view.
         *
         * @param aView A contact view sending the event.
         * @param aIndex An index of the contact in the view.
         * @param aContactLink A link to the added contact that is
         *                     valid only during the functio call.
         */
        virtual void ContactAddedToView(
                MVPbkContactViewBase& aView, 
                TInt aIndex, 
                const MVPbkContactLink& aContactLink ) = 0;

        /**
         * Called when a contact has been removed from a view.
         *
         * @param aView A contact view sending the event.
         * @param aIndex An index of the removed contact.
         * @param aContactLink A link to the removed contact that is
         *                      valid only during this function call.
         */
        virtual void ContactRemovedFromView(
                MVPbkContactViewBase& aView, 
                TInt aIndex, 
                const MVPbkContactLink& aContactLink ) = 0;

        /**
         * Called when an error occurs in the view.
         *
         * If client decides to destroy the view then it should do
         * it asynchronously because the view can access member data
         * after a call to this.
         *
         * @param aView A contact view sending the event.
         * @param aError An error code of the failure.
         * @param aErrorNotified  ETrue if the implementation has already 
         *                        notified user about the error using e.g
         *                        an ECOM plug-in, EFalse otherwise.
         */
        virtual void ContactViewError(
                MVPbkContactViewBase& aView, 
                TInt aError, 
                TBool aErrorNotified ) = 0;

        /**
         * Returns an extension point for this interface or NULL.
         *
         * @param aExtensionUid no extensions defined currently.
         * @return an extension point for this interface or NULL.
         */
        virtual TAny* ContactViewObserverExtension(TUid /*aExtensionUid*/) 
                { return NULL; }

    protected: // Destructor
        virtual ~MVPbkContactViewObserver() { }

    };

#endif  // MVPBKCONTACTVIEWOBSERVER_H

// End of File
