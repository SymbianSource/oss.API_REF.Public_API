/*
* Copyright (c) 2002-2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  A high level class for matching phone numbers from stores.
*
*/


#ifndef CVPBKPHONENUMBERMATCHSTRATEGY_H
#define CVPBKPHONENUMBERMATCHSTRATEGY_H

// INCLUDE FILES
#include <e32base.h>
#include <mvpbkcontactfindobserver.h>
#include <mvpbkcontactstorelist.h>

// FORWARD DECLARATIONS
class CVPbkContactManager;
class MVPbkContactOperation;
class MVPbkContactStore;
class CVPbkPhoneNumberMatchStrategyImpl;
class CVPbkContactStoreUriArray;

/**
 * Phone number matching strategy. This is the base class of actual 
 * implementations, but instances of the strategies are created using
 * this classes NewL function. Actual implementation selection is done
 * based on the given configuration data.
 */
class CVPbkPhoneNumberMatchStrategy : public CBase
    {
    public: // Types
        /**
         * Phone number matching mode. The mode can be used to
         * configure the match algorithms operation mode.
         */
        enum TVPbkPhoneNumberMatchMode
            {
            /**
             * Performs the search sequentially for each store.
             */
            EVPbkSequentialMatch,
            /**
             * Performs the search concurrently for each store.
             */
            EVPbkParallelMatch
            };

        /**
         * Phone number matching flags. The flags can be used to 
         * configure the phone number matching strategy.
         */
        enum TVPbkPhoneNumberMatchFlags
            {
            /**
             * No additional matching flags.
             */
            EVPbkMatchFlagsNone         = 0x00000000,

            /**
             * Quarantees that only contacts with an exact match 
             * are included in the result set. The resulted contact 
             * links are also field links in this case. The link 
             * points to the first field in the contact with exact 
             * match. See RetrieveField in 
             * MVPbkStoreContactFieldCollection.
             */
            EVPbkExactMatchFlag         = 0x00000001,

            /**
             * Stops the search once at least one contact is found.
             */
            EVPbkStopOnFirstMatchFlag   = 0x00000002,
            
            /**
             * If all matched contacts have the same
             * first name and last name field values only first
             * one is returned.
             */
            EVPbkDuplicatedContactsMatchFlag   = 0x00000004
            };

        /**
         * CVPbkPhoneNumberMatchStrategy configuration parameter class.
         * This class can be used to configure the phone number find
         * strategy.
         */
        class TConfig
            {
            public:
                /**
                 * Constructor.
                 *
                 * @param aMaxMatchDigits   Maximum number of digits 
                 *                          used in matching.
                 * @param aUriPriorities    Array of contact store URIs 
                 *                          to define match priority.
                 * @param aMatchMode    Matching mode to be used when 
                 *                      searching for matching contacts. 
                 *                      See TVPbkPhoneNumberMatchMode.
                 * @param aMatchFlags   Match configuration flags. 
                 *                      See TVPbkPhoneNumberMatchFlags.
                 */
                inline TConfig(
                        TInt aMaxMatchDigits, 
                        const CVPbkContactStoreUriArray& aUriPriorities,
                        TVPbkPhoneNumberMatchMode aMatchMode,
                        TUint32 aMatchFlags);

            public: // data
                ///Own: Maximum number of digits used in matching
                TInt iMaxMatchDigits;
                ///Ref: Array of contact store URIs to define match priority
                const CVPbkContactStoreUriArray& iUriPriorities;
                ///Own: Matching mode to be used when searching for 
                ///     matching contacts
                TVPbkPhoneNumberMatchMode iMatchMode;
                ///Own: Flags to configure matching process, 
                ///     @see TVPbkPhoneNumberMatchFlags
                TUint32 iMatchFlags;
                ///Own: Reserved for future extension
                TAny* iSpare;
            };

    public: // Construction & destruction
        /**
         * Acts as a factory function for strategy implementation classes 
         * derived from this class. The actual implementation class is 
         * determined from the parameters of this function.
         *
         * @param aConfig Configuration data for phone number matching.
         * @param aContactManager Contact manager to be used in matching.
         * @param aObserver Observer for the matching operation.
         * @return Newly created instance of a class derived from this class.
         */
        IMPORT_C static CVPbkPhoneNumberMatchStrategy* NewL(
                const TConfig& aConfig,
                CVPbkContactManager& aContactManager, 
                MVPbkContactFindObserver& aObserver);

        /**
         * Destructor.
         */
        ~CVPbkPhoneNumberMatchStrategy();

    public: // Interface
        /**
         * Tries to find matches for given phone number from the stores 
         * that were specified in the configuration data. This is 
         * asynchronous operation and the observer will be called 
         * back when this operation completes.
         *
         * @param aPhoneNumber Phone number to match.
         */
        IMPORT_C void MatchL(const TDesC& aPhoneNumber);

    protected: // Interface for derived classes
        /**
         * Returns maximum number of digits used in matching.
         * @return Maximum number of digits used in matching.
         */
        TInt MaxMatchDigits() const;

        /**
         * Returns array of stores that are used in matching.
         * @return Array of stores that are used in matching.
         */
        TArray<MVPbkContactStore*> StoresToMatch() const;

    private: // Interface for derived classes to implement
        /**
         * Called from MatchL to indicate derived classes that 
         * matching is about to start.
         */
        virtual void InitMatchingL() =0;

        /**
         * Creates a new find operation for the next finding step.
         *
         * @param aPhoneNumber Phone number to match.
         * @return Find operation.
         */
        virtual MVPbkContactOperation* CreateFindOperationLC(
                const TDesC& aPhoneNumber) =0;

    protected: // Implementation
        /**
         * Constructor.
         */
        CVPbkPhoneNumberMatchStrategy();

        /**
         * Initializes the base class. Derived classes must call 
         * this in their ConstructL.
         * @param aConfig Configuration data for phone number matching.
         * @param aContactManager   Contact manager reference,
         * @param aObserver Contact find observer reference.
         */
        void BaseConstructL(
                const TConfig& aConfig,
                CVPbkContactManager& aContactManager,
                MVPbkContactFindObserver& aObserver);
        
        /**
         * Returns the find observer to be used for find operations 
         * created in CreateFindOperationLC.
         * @return Contact find observer
         */
        MVPbkContactFindObserver& FindObserver() const;
        
    private: // Data
        friend class CVPbkPhoneNumberMatchStrategyImpl;
        /// Own: Pointer to implementation
        CVPbkPhoneNumberMatchStrategyImpl* iImpl;
    };

// INLINE FUNCTIONS
inline CVPbkPhoneNumberMatchStrategy::TConfig::TConfig(
        TInt aMaxMatchDigits, 
        const CVPbkContactStoreUriArray& aUriPriorities,
        TVPbkPhoneNumberMatchMode aMatchMode,
        TUint32 aMatchFlags) :
    iMaxMatchDigits(aMaxMatchDigits),
    iUriPriorities(aUriPriorities),
    iMatchMode(aMatchMode),
    iMatchFlags(aMatchFlags)
    {
    }

#endif // CVPBKPHONENUMBERMATCHSTRATEGY_H

// End of File
