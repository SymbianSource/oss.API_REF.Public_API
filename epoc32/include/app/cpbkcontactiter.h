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
*    Phonebook contact iterator
*
*/


#ifndef __CPbkContactIter_H__
#define __CPbkContactIter_H__

//  INCLUDES
#include    <e32base.h>     // CBase
#include    <cntdb.h>       // TContactIter

// FORWARD DECLARATIONS
class CPbkContactEngine;
class CPbkContactItem;
class CContactItem;

// CLASS DECLARATION

/**
 * Phonebook contact iterator. Only iterates through recognised Phonebook
 * contact cards, not groups or templates. NextL jumps over any other contacts. 
 */
class CPbkContactIter : public CBase
	{
    public:  // Constructors and destructor
        /**
         * Creates a new instace of this class.
         *
         * @param aEngine   Phonebook engine whose contacts to iterate.
         * @param aUseMinimalRead   Use ReadMinimalContactL instead of 
         *                          ReadContactL to read the contacts.
         * @return Contact iterator instance.
         */
        IMPORT_C static CPbkContactIter* NewL
            (CPbkContactEngine& aEngine, TBool aUseMinimalRead=EFalse);

        /**
         * Same as NewL but leaves the created object on the cleanup stack.
         * Creates a new instace of this class.
         *
         * @param aEngine   Phonebook engine whose contacts to iterate.
         * @param aUseMinimalRead   Use ReadMinimalContactL instead of 
         *                          ReadContactL to read the contacts.
         * @return Contact iterator instance.
         */
        IMPORT_C static CPbkContactIter* NewLC
            (CPbkContactEngine& aEngine, TBool aUseMinimalRead=EFalse);

	    /**
         * Destructor.
         */
        ~CPbkContactIter();

    public:  // interface
        /**
         * Intializes the iterator to the first Phonebook contact.
         * @return Id of the first Phonebook contact, KNullContactId if none found.
         */
	    IMPORT_C TContactItemId FirstL();

        /**
         * Advances the iterator to the next Phonebook contact.
         * @return Id of the next Phonebook contact, KNullContactId if none found.
         */
	    IMPORT_C TContactItemId NextL();

        /**
         * Resets the iterator to null state.
         */
	    IMPORT_C void Reset();

        /**
         * Returns the current Phonebook contact, NULL if none.
         * @return  The contact item the iterator is currently pointing at.
         */
        IMPORT_C CPbkContactItem* CurrentL() const;

        /**
         * Returns the current Phonebook contact, NULL if none.
         * Caller is responsible for deleting the contact, thus ownership of the
         * contact item is passed to the client.
         * @return  The contact item the iterator is currently pointing at.
         */
        IMPORT_C CPbkContactItem* GetCurrentL() const;

        __DECLARE_TEST;

    private:  // Implementation
	    CPbkContactIter(CPbkContactEngine& aEngine, TBool aUseMinimalRead);
        CContactItem* ReadPhonebookContactL(TContactItemId aId);

    private:  // Data
		/// Ref: phonebook engine
        CPbkContactEngine& iEngine;
		/// Own: contact iterator
        TContactIter iCmIter;
		/// Own: current item
        mutable CContactItem* iCurrentItem;
		/// Own: current pbk-item
        mutable CPbkContactItem* iCurrentPbkItem;
		/// Own: minimal read flag
        const TBool iUseMinimalRead;
	};


#endif // __CPbkContactIter_H__

// End of File
