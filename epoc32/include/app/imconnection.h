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
* Description:  IM Connection interface
*
*/


#ifndef IMCONNECTION_H
#define IMCONNECTION_H

// INCLUDES
#include <e32base.h>
#include <ecom/ecom.h>

// DATA TYPES
enum TImConnectionStatus
    {
    ELoggedIn = 0,
    ENotLoggedIn
    };

// FORWARD DECLARATIONS
class MImClient;
class MImConnectionObserver;

// CLASS DECLARATION

/**
*  Instant Messaging API class
*  By creating this class the user automatically connects to the Symbian server
*  but to do something reasonable the IM interface has to be created using
*  this class. The following order of calling the methods is one possibility to
*  use this class:
*  1. NewL() - instantiate the object
*  2. RegisterObserverL() - register the observer methods
*  3. LoginL() - connect to the protocol stack and login to remote IM server
*  4. CreateImClientL() - get the IM interface
*
*  All the error codes are returned using the leave mechanism.
*
*  @lib imclient.dll
*  @since S60 3.0
*/
class CImConnection : public CBase
    {
    public:

        /**
        * Factory method for creating the class instance.
        * @since S60 3.0
        * @param aApplicationId the ApplicationId of the application
        * @return CImConnection
        */
        static CImConnection* NewL(
            const TDesC& aApplicationId );

        // Destructor
        virtual ~CImConnection( );


    public: // New functions

        /**
        * Creates the IM interface to sending and receiving IMs
        * @since S60 3.0
        * @return MImClient
        */
        virtual MImClient* CreateImClientL( ) = 0;

        /**
        * Method for registering the IM Connection observer to the API.
        * This method is synchronous.
        * @since S60 3.0
        * @param aObserver observer object which receives the notification
        * @leave KImApiErrAlreadyRegistered if it was registered already or other system wide error code
        */
        virtual void RegisterObserverL(
            MImConnectionObserver* aObserver ) = 0;

        /**
        * Method for unregistering the IM Connection observer.
        * This method is synchronous.
        * @since S60 2.6
        */
        virtual void UnregisterObserver( ) = 0;

        /**
        * Method for getting the connection status.
        * This method is synchronous.
        * @since S60 3.0
        * @return connection status enum
        */
        virtual TImConnectionStatus ImConnectionStatus( ) = 0;

        /**
        * Connects the application to the protocol stack and logs in to the
        * remote SAP server using the given login info.
        * This method is asynchronous and the completion is signaled by
        * HandleLoginL() observer method.
        * @since S60 3.0
        * @return connection status enum
        * @leave KImApiErrLoginInProgress already logging in
        * @leave KImApiErrLogoutInProgress logout is ongoing
        * @leave KImApiErrCancelLoginInProgress cancel login is ongoing
        * @leave KImApiErrAlreadyLoggedIn already logged in
        */
        virtual void LoginL(
            const TDesC&  aServer,
            const TDesC&  aUserID,
            const TDesC&  aPassword,
            const TUint32 aAP ) = 0;

        /**
        * Cancels the ongoing login operation.
        * This method is asynchronous and the completion is signaled by
        * HandleCancelLoginL() observer method.
        * @since S60 3.0
        * @leave KImApiErrNotLogged not logged in
        * @leave KImApiErrLogoutInProgress logout is ongoing
        * @leave KImApiErrCancelLoginInProgress cancel login is ongoing
        * @leave KImApiErrAlreadyLoggedIn already logged in
        */
        virtual void CancelLoginL( ) = 0;

        /**
        * Logs out from current session.
        * This method is asynchronous and the completion is signaled by
        * HandleLogoutL() observer method.
        * Possible leave reasons:
        * @since S60 3.0
        * @leave KImApiErrNotLogged not logged in
        * @leave KImApiErrLogoutInProgress logout is ongoing
        * @leave KImApiErrCancelLoginInProgress cancel login is ongoing
        */
        virtual void LogoutL( ) = 0;

    protected:
        // C++ constructor
        inline CImConnection( );

    private:
        // Unique instance identifier key (needed for ECom)
        TUid iDtor_ID_Key;

    };

/**
*  Connection Observer interface
*
*  @lib imclient.dll
*  @since S60 3.0
*/
class MImConnectionObserver
    {
    public:

        /**
        * Method is called when the LoginL() is completed.
        * @since S60 3.0
        * @param aErrorCode status code
        */
        virtual void HandleLoginL(
            const TInt aErrorCode ) = 0;

        /**
        * Method is called when the CancelLoginL() is completed.
        * @since S60 3.0
        * @param aErrorCode status code
        */
        virtual void HandleCancelLoginL(
            const TInt aErrorCode ) = 0;

        /**
        * Method is called when the LogoutL() is completed.
        * Also called in situations when the Logout was initiated by the server
        * or another client which was using the same connection
        * @since S60 3.0
        * @param aErrorCode status code
        */
        virtual void HandleLogoutL(
            const TInt aErrorCode ) = 0;

    };

#include "imconnection.inl"

#endif
