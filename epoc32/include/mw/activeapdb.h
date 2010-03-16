/*
* Copyright (c) 2002 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:  Declaration of classes CActiveApDb
*               and MActiveApDbObserver.
*
*/


#ifndef ACTIVE_APDB_H
#define ACTIVE_APDB_H

// Deprecation warning
#warning This header file has been deprecated. Will be removed in one of the next SDK releases.


//  INCLUDES
#include <commdb.h>
#include <ApEngineVer.h>

/*
// Enum for DATABASE_TYPE field
// Will be deprecated in 7.0
enum TCommDbDatabaseType
    {
    EUnspecified = 0,   // not specifying which type it is - any type of 
                        // database can be opened with this parameter
    EIAP,
    EISP
    };
*/

// CONSTANTS
const TInt KErrActiveApDbObserverNotFound = -500;

// FORWARD DECLARATION
class CActiveApDbNotifier;

// CLASS DECLARATION

/**
* Mixin protocol for handling events from a CCommsDatabase.
* Events are related to database changes and availability.
*/
class MActiveApDbObserver
    {
    public:     // types
        enum TEvent       /// Events reported to the database observer.
            {
            EDbChanged,   ///< Database has changed.
            EDbClosing,   ///< Database is about to close.
            EDbAvailable  ///< Database is available again.(E.g. after unlock)
            };

    public:     // new methods

        /**
        * Derived classes should implement this method, and act accordingly
        * to database events.
        * @param anEvent Database-related event.
        *
        * @deprecated
        */
        IMPORT_C virtual void HandleApDbEventL( TEvent anEvent ) = 0;

    };

/**
* This class manages and guards database integrity
* by handling all events that are related to the database. These events
* may originate from the system (Shutdown, Backup/Restore) and from the
* database itself. The events are transformed into a simple protocol,
* defined by MActiveApDbObserver.
* Expects an active scheduler to be installed and running.
*/
NONSHARABLE_CLASS( CActiveApDb ) : public CBase
    {

    public:     // Constructors and destructor
        /**
        * Two-phased constructor. Leaves on failure.
        * @param aType The desired type of the CCommsDatabase object.
        * Defaults to EDatabaseTypeIAP.
        * @return The constructed CActiveApDb object.
        *
        * @deprecated
        */
        IMPORT_C static CActiveApDb* NewL
            ( TCommDbDatabaseType aType = EDatabaseTypeIAP );



        /**
        * Destructor.
        *
        * @deprecated
        */
        IMPORT_C virtual ~CActiveApDb();

    protected:  // Constructors

        /**
        * Second phase constructor. Leaves on failure.
        * @param aType The desired type of the CCommsDatabase object.
        * events.
        */
        void ConstructL();

    public:     // new methods
        /**
        * Adds an observer to the list of observers to be notified
        * about the DB events.
        * Also automatically starts observation and notification.
        * The order of notification will be exactly the order of registration.
        * @param anObserver Observer to be notified about database-related
        * events.
        *
        * @deprecated
        */
        IMPORT_C void AddObserverL( MActiveApDbObserver* anObserver );


        /**
        * Removes an observer. If not added, silently ignores.
        * @param anObserver The observer.
        *
        * @deprecated
        */
        IMPORT_C void RemoveObserver( MActiveApDbObserver* anObserver );


        /**
        * Returns the CCommsDatabase.
        * Required because we can not derive from CCommsDatabase...
        *
        * @deprecated
        */
        IMPORT_C CCommsDatabase*  Database();

    private:
        /**
        * Handle events from the database (DBMS).
        * The order of notification is the order of registration.
        * @param anEvent Event generated by DBMS. Values from
        * RDbNotifier::TEvent, or KErrCancel.
        */
        void HandleDbEventL( TInt anEvent );


        /**
        * Notify all observers about an event.
        * @param anEvent Event to be sent to observers.
        */
        void NotifyObserversL( MActiveApDbObserver::TEvent anEvent );

    friend class CActiveApDbNotifier;

    private:    // types
        /**
        * Default constructor. Can not leave.
        */
        CActiveApDb();


        enum TState             /// State of the finite state machine.
            {
            EClosed,            ///< Closed and idle.
            EReady,             ///< Open and ready for use.
            EWaitClose,         ///< Closed, waiting for other users to close.
            EWaitBackupRestore, ///< Closed, waiting Backup/Restore to finish.
            EWaitShutdown       ///< Closed, waiting to die.
            };

    private:        // Data
        CArrayPtrFlat<MActiveApDbObserver>* iObservers;   ///< Observers.

        CCommsDatabase*     iDb;    // Creates & owns it !
        // CommsDb has its own RDbNotifier...
        TState iState;  ///< Current state of the database.
        CActiveApDbNotifier*    iDbNotifier;
    };

#endif

// End of File
