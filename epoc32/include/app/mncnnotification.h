/*
* Copyright (c) 2006 Nokia Corporation and/or its subsidiary(-ies).
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
*       Public ECom notification API for NcnList.
*
*/



#ifndef __MNCNNOTIFICATION_H__
#define __MNCNNOTIFICATION_H__

//  INCLUDES
#include <e32base.h>
#include <msvstd.h>
#include <bamdesca.h>
#include <ecom/ECom.h>
#include <ecom/EComResolverParams.h>

// FORWARD DECLARATIONS

// UID of this interface
const TUid KNcnNotificationInterfaceUid = {0x101f8855};

// CLASS DECLARATION

/**
 * Public ECom notification API.
 * This API allows the notification of new message(s) to the NcnList.
 * It's main purpose is to provide a mechanism for an email MTM to broadcast the arrival of new messages
 * and give the user an opportunity to navigate to the email folder
 *
 * Example usage
 *
 * @code
 * #include <badesca.h>	// CDesCArray
 * #include <mncnnotification.h>	// ECOM interface to notification system
 *
 *  // Get an instance of the ECOM interface to the notification system.
 *  MNcnNotification* notifyNewMessageEcom = 0;
 *  TRAP(err, notifyNewMessageEcom = MNcnNotification::CreateMNcnNotificationL());
 *
 *  // Check for errors
 *  if(notifyNewMessageEcom && err == KErrNone)
 *      {
 *      // The interface is supported on this phone.
 *      CleanupDeletePushL(notifyNewMessageEcom);
 *
 *      // Now notify the framework that new messages have been received
 *      // First create a descriptor array for aInfo - even though it isn't used presently.
 *      CDesCArray* tempArray = new (ELeave) CDesCArrayFlat(3);
 *      CleanupStack::PushL(tempArray);
 *
 *      // Notify the framework that there are new messages.
 *		// This can return an error value.
 *      err = notifyNewMessageEcom->NewMessages(aServiceId, MNcnNotification::EIndicationNormal, *tempArray);
 *
 *      // Cleanup the descriptor array.
 *      CleanupStack::PopAndDestroy(tempArray);
 *
 *      // Clean up the ECOM interface now.
 *      CleanupStack::PopAndDestroy(notifyNewMessageEcom);
 *      }
 * @endcode
 *
 * The example above shows the interface object being created and then destroyed immediately after use.
 * However, it is not necessary to create a new interface object for every function call. It is done here to
 * demonstrate correct useage of the CleanupStack
 */
class MNcnNotification
    {
    private: // Enumerations
        /**
         * Indication type bit enumeration.
         */
        enum TIndicationTypeBits
            {
            /* Icon bit */
            EIndicationIconBit = 0x1,

            /* Tone bit */
            EIndicationToneBit = 0x2,

            /* Soft note bit */
            EIndicationSoftNoteBit = 0x4
            };

    public: // Enumerations
        /**
         * Indication type enumeration.
         */
        enum TIndicationType
            {
            /* Icon indication */
            EIndicationIcon = EIndicationIconBit,

            /* Normal indication */
            EIndicationNormal = EIndicationIconBit | EIndicationToneBit | EIndicationSoftNoteBit,

            /* Tone and icon indication */
            EIndicationToneAndIcon = EIndicationIconBit | EIndicationToneBit
            };

    public: // Constructor and destructor

       /**
        * ECom implementation class factory method.
        * Caller takes the ownership of the created object.
        * If interface needs to be pushed into CleanupStack,
        * remember to use the CleanupDeletePushL() function!
        * DO NOT USE CleanupStack::PushL()!!
        * @return ECom implementation instance
        *
        *
        */
        static MNcnNotification* CreateMNcnNotificationL();

       /**
        * Destructor.
        */
        virtual ~MNcnNotification();

    public: // Interface

		/**
         * Called by Messaging Server -compatible 3rd party Email plugins
         * to inform NcnList that there is a new message (or more than one message).
         * It should not (necessarily) be called for each new message but, say, at the
         * end of synchronisation when one or more new messages have been received.
         * It displays a 'New email' message with softkeys allowing direct
         * navigation to the email folder
         * Parameter aInfo is reserved for future use and is not handled in any way currently.
         * Implementation of aIndicationType may vary between devices
         *
         * @param aMailBox        The service id of the email MTM
         * @param aIndicationType Indication type for new messages. May be any combination
         *                        of enumeration TIndicationType values.
         * @param aInfo           Optional info about message (subject, sender etc.). Not supported
         *
         * @return                KErrNone for success, or system error code
         */
        virtual TInt NewMessages( const TMsvId& aMailBox,
                                  TIndicationType aIndicationType,
                                  const MDesCArray& aInfo ) = 0;

        /**
         * Called by Messaging Server -compatible 3rd party Email plugins
         * wanting to make a request to mark certain new messages as unread.<BR>
         * Essentially, it sets the new message counter to zero for the given mailbox <BR>
         * The new messages  become 'old' messages but they remain marked as 'unread'.
         * @param aMailBox The id identifying the mailbox or mail
         *                 folder containing the message(s) to be marked as unread.
         *
         * @return         KErrNone for success, or some error code
         */
        virtual TInt MarkUnread( const TMsvId& aMailBox ) = 0;

    private: // data

        // for ECom to identify plug-in instance
        TUid iDtor_ID_Key;
    };

#include <MNcnNotification.inl>

#endif // __MNCNNOTIFICATION_H__

// End of File
