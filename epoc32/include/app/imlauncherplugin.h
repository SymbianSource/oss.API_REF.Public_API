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
* Description:  Interface for the IM application launching
*
*/



#ifndef IMLAUNCHERPLUGIN_H
#define IMLAUNCHERPLUGIN_H

//  INCLUDES
#include <ecom/ecom.h>

// UID of this interface
const TUid KImLauncherPluginUid = {0x101FB0CC};

/**
*  Interface class for application launching
*
*  @since 2.6
*/
class CImLauncherPlugin : public CBase
    {
    public:  // Constructors and destructor

        /**
        * Two-phased constructor.
        * @param aApplicationId the Application ID of the application to be launched
        * @return CImLauncherPlugin instance
        */
        static CImLauncherPlugin* NewL( const TDesC8& aApplicationId );

        /**
        * Destructor.
        */
        virtual ~CImLauncherPlugin();

    public: // New functions

        /**
        * Method for starting an application which can receive instant messages.
        * Asynchronous function.
        * @since 3.0
        * @param aStatus Request status
        * @param aSAP the remote SAP server from where the pending IM came
        * @param aUserId the user ID who received the IM
        */
        virtual void StartApplicationL(
            TRequestStatus& aStatus,
            const TDesC& aSap,
            const TDesC& aUserId ) = 0;

        /**
        * Method for canceling the application start.
        * @since 2.6
        */
        virtual void CancelStartApplication() = 0;

    protected:
        //Default c'tor
        inline CImLauncherPlugin();

    private:    // Data
        /** iDtor_ID_Key Instance identifier key. When instance of an
         *               implementation is created by ECOM framework, the
         *               framework will assign UID for it. The UID is used in
         *               destructor to notify framework that this instance is
         *               being destroyed and resources can be released.
         */
        TUid iDtor_ID_Key;

    };

// This includes the implementation of the instantiation functions and
// destructor
#include "imlauncherplugin.inl"

#endif      // IMLAUNCHERPLUGIN_H   

// End of File
