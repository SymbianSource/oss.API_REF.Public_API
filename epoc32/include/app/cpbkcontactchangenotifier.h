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
*       Class for registering CPbkContactEngine observers.
*
*/


#ifndef __CPbkContactChangeNotifier_H__
#define __CPbkContactChangeNotifier_H__

//  INCLUDES
#include <e32base.h>  // CBase

// FORWARD DECLARATIONS
class CPbkContactEngine;
class MPbkContactDbObserver;


// CLASS DECLARATION

/**
 * A class used for registering as an observer for contact database
 * change events. 
 */
class CPbkContactChangeNotifier : public CBase
    {
    public:  // Constructors and destructor
        /**
         * Creates a new instance of this class and registers aObserver as an
         * observer of aEngine.
         *
         * @param aEngine   The observed object.
         * @param aObserver The observer to call when database changes occur.
         * @return  A contact change notifier instance.
         */
        IMPORT_C static CPbkContactChangeNotifier* NewL
            (CPbkContactEngine& aEngine, MPbkContactDbObserver* aObserver);

        /**
         * Removes the aObserver from aEngine given as paramters to NewL and
         * destructs this object.
         */
        ~CPbkContactChangeNotifier();

    private:  // Implementation
        CPbkContactChangeNotifier
            (MPbkContactDbObserver* aObserver);
        void ConstructL(CPbkContactEngine& aEngine);

    private:  // data
        /// Ref: Phonebook engine
        CPbkContactEngine* iEngine;
        /// Ref: the observer
        MPbkContactDbObserver* iObserver;
    };


#endif // __CPbkContactChangeNotifier_H__

// End of File
