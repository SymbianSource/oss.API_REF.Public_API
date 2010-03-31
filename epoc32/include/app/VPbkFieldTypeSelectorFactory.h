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
* Description:  Selector factory for a set of predefined selectors.
*
*/


#ifndef VPBKFIELDTYPESELECTORFACTORY_H
#define VPBKFIELDTYPESELECTORFACTORY_H

//  INCLUDES
#include <e32base.h>

//  FORWARD DECLARATIONS
class CVPbkFieldTypeSelector;
class MVPbkFieldTypeList;

/**
 * Factory for creating selectors based on field type or contact action type.
 */
class VPbkFieldTypeSelectorFactory
    {
    public: // Types
        
        /**
         * Defines predefined field type selectors.
         */
        enum TVPbkFieldTypeSelector
            {
            /// Phone number selector
            EPhoneNumberSelector = 0x00,
            /// Mobile number selector
            EMobileNumberSelector,
            /// Fax number selector
            EFaxNumberSelector,
            /// Video number selector
            EVideoNumberSelector,
            /// Pager number selector
            EPagerNumberSelector,
            /// Email address selector
            EEmailAddressSelector,
            /// Email over SMS selector
            EEmailOverSmsSelector,
            /// MMS address selector
            EMmsAddressSelector,
            /// VoIP address selector
            EVoipAddressSelector,
            /// PTT (push-to-talk) address selector
            EPttAddressSelector,
            /// SIP address selector
            ESipAddressSelector,
            /// SIP & MSISDN address selector
            ESipMsisdnAddressSelector,
            /// Thumbnail image selector
            EThumbnailImageSelector,
            /// Caller object image selector
            ECodImageSelector,
            /// Generic image selector
            EImageSelector,
            /// Caller object text selector
            ECodTextSelector,
            /// Ringing tone selector
            ERingingToneSelector,
            /// URL address selector
            EUrlAddressSelector,
            /// Last name selector
            ELastNameSelector,
            /// First name selector
            EFirstNameSelector,
            /// Last name pronounciation selector
            ELastNamePronunciationSelector,
            /// First name pronounciation selector
            EFirstNamePronunciationSelector,
            /// Synchronization selector
            ESynchronizationSelector,
            /// DTMF number selector
            EDtmfNumberSelector,
            /// Top contact selector
            ETopcontactSelector,
            // IMPP selector
            EImppSelector,
            // Pager Fax Selector
            EPagerfaxSelector
            }; 
        
        /**
         * Defines predefined contact action type selectors.
         */
        enum TVPbkContactActionTypeSelector
            {
            /// VoiceCall selector
            EEmptySelector = 0x50,
            EVoiceCallSelector,
            EUniEditorSelector,
            EEmailEditorSelector,
            EInstantMessagingSelector,
            EVOIPCallSelector,
            EURLSelector,
            EVideoCallSelector,
            EPocSelector,
            EFindOnMapSelector,
            EAssignFromMapSelector            
            }; 
        
    public: // New Functions
    
        /**
         * Build a predefined field type selector.
         *
         * @param aType Id of the predefined selector.
         * @param aFieldTypeList Field type list used to search
         *                       for the field.
         * @return A new instance of CVPbkFieldTypeSelector
         */
        IMPORT_C static CVPbkFieldTypeSelector* BuildFieldTypeSelectorL(
                TVPbkFieldTypeSelector aType,
                const MVPbkFieldTypeList& aFieldTypeList);

        /**
         * Build a predefined contact action type selector.
         *
         * @param aType Id of the predefined selector.
         * @param aFieldTypeList Field type list used to search
         *                       for the field.
         * @return A new instance of CVPbkFieldTypeSelector
         */
        IMPORT_C static CVPbkFieldTypeSelector* BuildContactActionTypeSelectorL(
                TVPbkContactActionTypeSelector aType,
                const MVPbkFieldTypeList& aFieldTypeList);

       /**
        * Creates selector id based on an integer value. The function
        * leaves with KErrNotFound if the integer doesnt fit any
        * selector id.
        *
        * @param aSelectorID     An integer selector id.
        * @return                Created TVPbkContactActionTypeSelector.
        */
        IMPORT_C static TVPbkContactActionTypeSelector CreateActionTypeSelectorIdL( const TInt aID );
    private: // Implementation
     
        static VPbkFieldTypeSelectorFactory::TVPbkFieldTypeSelector 
            MapContactActionTypeL
                ( VPbkFieldTypeSelectorFactory::TVPbkContactActionTypeSelector
                    aType );
    };


#endif // VPBKFIELDTYPESELECTORFACTORY_H

// End of file

