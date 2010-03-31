/*
* Copyright (c) 2005-2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Phonebook 2 sort order manager.
*
*/


#ifndef CPBK2SORTORDERMANAGER_H
#define CPBK2SORTORDERMANAGER_H

// INCLUDE FILES
#include <e32base.h>

// FORWARD DECLARATIONS
class MVPbkContactViewBase;
class MVPbkFieldTypeList;
class RFs;
class CPbk2SortOrderManagerImpl;

/**
 * Observer interface for receiving notifications of
 * view sort order changes.
 */
class MPbk2SortOrderObserver
    {
    public: // Interface

        /**
         * Called when sort order has changed.
         */
        virtual void SortOrderChanged() =  0;

    protected: // Disabled functions
        ~MPbk2SortOrderObserver()
            {}
    };

/**
 * Phonebook 2 sort order manager.
 * Responsible for managing the sort order of the contacts in
 * a contact view.
 */
class CPbk2SortOrderManager : public CBase
    {
    public: // Enumerations

        /// Name display orders
        enum TPbk2NameDisplayOrder
            {
            /// Last name First name
            EPbk2NameDisplayOrderLastNameFirstName,
            /// First name Last name
            EPbk2NameDisplayOrderFirstNameLastName,
            /// Last name<separator> First Name
            EPbk2NameDisplayOrderLastNameSeparatorFirstName
            };

    public: // Construction and destruction

        /**
         * Creates a new instance of this class.
         *
         * @param aMasterFieldTypeList      Master field type list.
         *                                  Can be retrieved from Virtual
         *                                  Phonebook contact manager.
         * @param aFs                       A file system session
         *                                  reference for resource file
         *                                  handling. If NULL then
         *                                  an own session is created.
         * @return  A new instance of this class.
         */
        IMPORT_C static CPbk2SortOrderManager* NewL(
                const MVPbkFieldTypeList& aMasterFieldTypeList,
                RFs* aFs = NULL );

        /**
         * Destructor.
         */
        ~CPbk2SortOrderManager();

    public: // Interface

        /**
         * Sets the contact view that this manager manages.
         * Takes in use the sort order from the given view.
         *
         * @param aContactView  The contact view to manage.
         */
        IMPORT_C void SetContactViewL(
                MVPbkContactViewBase& aContactView );

        /**
         * Adds an observer.
         *
         * @param aObserver     The observer to add.
         */
        IMPORT_C void AddObserverL(
                MPbk2SortOrderObserver& aObserver );

        /**
         * Removes an observer.
         *
         * @param aObserver     The observer to remove.
         */
        IMPORT_C void RemoveObserver(
                MPbk2SortOrderObserver& aObserver );

        /**
         * Sets the name displaying order for the managed contact view.
         *
         * @param aNameDisplayOrder     New name display order for
         *                              the managed contact view.
         * @param aSeparator            Custom separator to be used between
         *                              lastname and firstname if it exists.
         *                              If KNullDesC is given, space is used
         *                              as separator.
         */
        IMPORT_C void SetNameDisplayOrderL(
                TPbk2NameDisplayOrder aNameDisplayOrder,
                const TDesC& aSeparator = KNullDesC );

        /**
         * Returns the current name display order.
         *
         * @return  Current name display order.
         */
        IMPORT_C TPbk2NameDisplayOrder NameDisplayOrder() const;

        /**
         * Returns the current sort order.
         *
         * @return  Current sort order.
         */
        IMPORT_C const MVPbkFieldTypeList& SortOrder() const;

        /**
         * Returns the language specific default separator.
         * This can not be changed run time.
         *
         * @return the language specific default separator.
         */
        IMPORT_C const TDesC& DefaultSeparator();

        /**
         * Returns the current separator. This the separator that
         * can be changed run time and saved to Central Repository.
         *
         * @return A current separator.
         */
        IMPORT_C const TDesC& CurrentSeparator() const;

    private: // Implementation
        void ConstructL(
                const MVPbkFieldTypeList& aMasterFieldTypeList,
                RFs* aFs );

    private: // Data
        /// Own: Implementation object
        CPbk2SortOrderManagerImpl* iImpl;
    };

#endif // CPBK2SORTORDERMANAGER_H

// End of File
