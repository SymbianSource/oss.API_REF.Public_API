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
* Description: 
*       Interface class declaration for Phonebook contact database observers.
*
*/


#ifndef __MPbkContactDbObserver_H__
#define __MPbkContactDbObserver_H__

//  INCLUDES
#include <cntdef.h>     // cntdbobs.h requires TContactItemId from this header
#include <cntdbobs.h>   // MContactDbObserver

// FORWARD DECLARATIONS
class CPbkContactEngine;

// CLASS DECLARATION

/**
 * Interface class for Phonebook contact database observers.
 *
 * @see MContactDbObserver
 * @see CPbkContactChangeNotifier
 */
class MPbkContactDbObserver : public MContactDbObserver
    {
    protected:  // Derived class interface
        /**
         * Called by CPbkContactEngine when it receives a database 
         * change event. From MContactDbObserver.
		 * @param aEvent The database event.
         */
        virtual void HandleDatabaseEventL(TContactDbObserverEvent aEvent) = 0;

        /**
         * Called by CPbkContactEngine after HandleDatabaseEventL has been 
         * called for all observers.
         * In other words: CPbkContactEngine calls first HandleDatabaseEventL
         * for all its observers and then this function again for all 
         * observers. You can think of it as an "all observers have seen 
         * aEvent" -notification. This used in Phonebook view activation for 
         * now. Default implementation does nothing.
         *
         * @param aEvent The database event
         */
        virtual void DatabaseEventHandledL(TContactDbObserverEvent /*aEvent*/)
            {
            // Empty default implementation
            }

        /**
         * Protected destructor. 
         * Observers are not destroyed via this interface.
         */
        virtual ~MPbkContactDbObserver() { }

    private:  // friend declarations
        /// CPbkContactEngine calls protected functions of this class.
        friend class CPbkContactEngine;
    };


#endif // __MPbkContactDbObserver_H__

// End of File
