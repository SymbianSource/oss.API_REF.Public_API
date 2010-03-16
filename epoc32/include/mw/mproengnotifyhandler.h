/*
* Copyright (c) 2002-2004 Nokia Corporation and/or its subsidiary(-ies).
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
* Description: Abstract interface for handling profile change notification
*
*/



#ifndef MPROENGNOTIFYHANDLER_H
#define MPROENGNOTIFYHANDLER_H

//  INCLUDES
#include <e32def.h>

// FORWARD DECLARATIONS
class MProEngNotifyHandlerExt;
class MProEngProfileActivationObserver;
class MProEngActiveProfileObserver;
class MProEngProfileObserver;
class MProEngProfileNameArrayObserver;

// CLASS DECLARATION

/**
* Profiles change notification handler.
* This class is used for registration to get notifications about changes in
* Profiles data.
*
*  @lib ProfileEngine.lib
*  @since S60 3.1
*/
class MProEngNotifyHandler
    {
    public: // New functions

        /**
         * Request notifications of profile activations. The notifications are
         * received as long as CancelProfileActivationNotifications() or
         * CancelAll() is called. If the client wants to change the observer,
         * he should first cancel these notifications and then re-request them
         * with the new observer instance.
         * @since S60 3.1
         * @param aObserver Reference to the observer to be notified in the
         *        event of profile activation.
         * @return KErrNone if succesful, KErrAlreadyExists if this notification
         *         handler is already used for requesting profile activation
         *         notifications. In other cases another system wide error code.
         */
        virtual TInt RequestProfileActivationNotificationsL(
                MProEngProfileActivationObserver& aObserver ) = 0;

        /**
         * Request notifications of active profile modifications.
         * The notifications are received as long as
         * CancelActiveProfileNotifications() or CancelAll() is called. If the
         * client wants to change the observer, he should first cancel these
         * notifications and then re-request them with the new observer
         * instance.
         * @since S60 3.1
         * @param aObserver Reference to the observer to be notified in the
         *        event of active profile modification.
         * @return KErrNone if succesful, KErrAlreadyExists if this notification
         *         handler is already used for requesting active profile
         *         notifications. In other cases another system wide error code.
         */
        virtual TInt RequestActiveProfileNotificationsL(
                MProEngActiveProfileObserver& aObserver ) = 0;

        /**
         * Request notifications about changes in the given profile.
         * This is useful for cases when the client is interested about
         * changes in a specific profile no matter if the profile is active or
         * not. The notifications are received as long as
         * CancelProfileNotifications() or CancelAll() is called. If the
         * client wants to change the observer for the notifications about the
         * same profile, he should first cancel these notifications and then
         * re-request them with the new observer instance.
         * @since S60 3.1
         * @param aObserver Reference to the observer to be notified in the
         *        event of modification of the specified profile.
         * @param aProfileId the ID of the profile the changes of which has to
         *        be notified.
         * @return KErrNone if succesful, KErrAlreadyExists if this notification
         *         handler is already used for requesting notifications of
         *         changes in the given profile. KErrNotFound, if a profile with
         *         the given ID does not exist. In other cases another system
         *         wide error code.
         */
        virtual TInt RequestProfileNotificationsL(
                MProEngProfileObserver& aObserver,
                TInt aProfileId ) = 0;

        /**
         * Request notifications about changes in the profile name array. This
         * includes the cases when: a new profile has been created, a profile
         * has been deleted, the name of a profile has been changed.
         * The notifications are received as long as
         * CancelProfileNameArrayNotifications() or CancelAll() is called. If
         * the client wants to change the observer, he should first cancel these
         * notifications and then re-request them with the new observer
         * instance.
         * @since S60 3.1
         * @param aObserver Reference to the observer to be notified in the
         *        event of a profile name array modification.
         * @return KErrNone if succesful, KErrAlreadyExists if this notification
         *         handler is already used for requesting profile name array
         *         notifications. In other cases another system wide error code.
         */
        virtual TInt RequestProfileNameArrayNotificationsL(
                MProEngProfileNameArrayObserver& aObserver ) = 0;

        /**
         * Cancel the registration for receiving notifications about profile
         * activation events.
         * @since S60 3.1
         */
        virtual void CancelProfileActivationNotifications() = 0;

        /**
         * Cancel the registration for receiving notifications about the active
         * profile modification events.
         * @since S60 3.1
         */
        virtual void CancelActiveProfileNotifications() = 0;

        /**
         * Cancel the registration for receiving notifications about the given
         * profile modification events.
         * @since S60 3.1
         * @param aProfileId The ID of the profile for which the client wants
         *        to cancel the receiving of modification events.
         */
        virtual void CancelProfileNotifications( TInt aProfileId ) = 0;

        /**
         * Cancel the registration for receiving notifications about the changes
         * in the profile name array.
         * @since S60 3.1
         */
        virtual void CancelProfileNameArrayNotifications() = 0;

        /**
        * Cancel all the registrations for receiving notifications.
        * @since Series 60 3.1
        */
        virtual void CancelAll() = 0;

    public:

        /**
        * Destructor.
        */
        virtual ~MProEngNotifyHandler() {}

    private: // Extension interface

        /**
        * This member is internal and not intended for use.
        */
        virtual MProEngNotifyHandlerExt* Extension() { return NULL; }

    };

#endif      // MPROENGNOTIFYHANDLER_H

// End of File

