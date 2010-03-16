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
*       Generic Phonebook address selection dialog. Used for selecting recipient
*       address from a contact for Call, Send SMS, email and MMS.
*
*/


#ifndef __CPbkAddressSelect_H__
#define __CPbkAddressSelect_H__

//  INCLUDES
#include <e32base.h>
#include <coedef.h> // TKeyResponse
#include <w32std.h> // TKeyEvent, TEventCode


// FORWARD DECLARATIONS
class CPbkContactItem;
class TPbkContactItemField;
class CPbkSelectFieldDlg;
class CPbkFieldArray;


// CLASS DECLARATION

/**
 * This class is the abstrack base class for Phonebook address selection
 * dialogs. Address selection dialogs are used for selecting recipient
 * address from a contact for Call, Send SMS, email and MMS. Select one 
 * of the derived classes for a particular concrete dialog implementation.
 */
class CPbkAddressSelect : public CBase
    {
    public:  // Interface
        /**
         * Parameters for ExecuteLD(TBaseParams&).
         * @see ExecuteLD(TBaseParams&)
         */
        class TBaseParams
            {
            public:  // Interface
                /**
                 * Returns the contact supplied to constructor.
                 * @return Contact item.
                 */
                IMPORT_C const CPbkContactItem& ContactItem();

                /**
                 * Sets the focused field of the contact item. If focused field
                 * is a non-empty address field it is returned directly by
                 * ExecuteLD. The default value is NULL.
				 * @param aFocusedField The focused field to set
                 */
                IMPORT_C void SetFocusedField(const TPbkContactItemField* aFocusedField);
        
                /**
                 * Set to ETrue to use default address of the contact directly.
                 * Focused field overrides default address if both are
                 * available. The default value is EFalse.
				 * @param aUseDefaultDirectly   Defines whether the default address
				 *                              should be used directly
                 */
                IMPORT_C void SetUseDefaultDirectly(TBool aUseDefaultDirectly);

                /**
                 * Returns the selected field or NULL if no selection was made.
                 * @return  Selected contact item field.
                 */
                IMPORT_C const TPbkContactItemField* SelectedField() const;

                /**
                 * Returns the focused field or NULL if there was no field
                 * level focus.
                 * @return  Focused contact item field.
                 */
                IMPORT_C const TPbkContactItemField* FocusedField() const;

            protected:  // Derived class interface
                /**
                 * Constructor.
                 *
                 * @param aContact      Contact from which to select an address.
                 * @param aDefaultField The field to use as the default. NULL if 
                 *                      no default is set for aContact.
                 */
                IMPORT_C TBaseParams
                    (const CPbkContactItem& aContact, 
                    const TPbkContactItemField* aDefaultField);

            private:  // Data
				/// Ref: the contact where to select an address
                const CPbkContactItem& iContact;
				/// Ref: the default field of the contact
                const TPbkContactItemField* iDefaultField;
				/// Ref: the focused field of the contact
                const TPbkContactItemField* iFocusedField;
				/// Own: is the default address to be used directly
                TBool iUseDefaultDirectly;
				/// Own: the selected field of the contact
                const TPbkContactItemField* iSelectedField;
				/// Spare data
                TInt32 iSpare1;
				/// Spare data
                TInt32 iSpare2;

            private:  // friends
                friend class CPbkAddressSelect;
            };

        /**
         * Destructor. Cancels address selection query if active.
         */
        IMPORT_C ~CPbkAddressSelect();

    protected:  // Base class interface
        /**
         * Constructor.
         */
        IMPORT_C CPbkAddressSelect();

        /**
         * Runs an address selection query (if necessary).
         *
         * @param aParams   see TBaseParams.
         * @return ETrue if query was accepted, EFalse if canceled.
         */
        IMPORT_C TBool ExecuteLD(TBaseParams& aParams);

        /**
         * Returns aItem passed to ExecuteLD.
         * @return  Contact item.
         */
        IMPORT_C const CPbkContactItem& ContactItem() const;

        /**
         * Exit any address selection query. Makes ExecuteLD return which means
         * this object is destroyed after this function returns!
         * @param aAccept   ETrue means the query selection is accepted and
         *                  EFalse that query is canceled.
         */ 
	    IMPORT_C void AttemptExitL(TBool aAccept);

    private:    // Base class interface. Private because these functions are
                // only to be called from this classes implementation.
        /**
         * Returns ETrue if aField is an applicable address field.
         * @param aField    Contact item field.
         * @return  ETrue if the contact item field is an applicable address field.
         */
        virtual TBool AddressField(const TPbkContactItemField& aField) const = 0;

        /**
         * Called if there are no applicable address fields in aItem passed
         * to ExecuteLD.
         */
        virtual void NoAddressesL() = 0;

        /**
         * Returns title to use for the address selection list query.
         * @return Title used for the address selection list query.
         */
        virtual const TDesC& QueryTitleL() = 0;

        /**
         * Returns a softkey resource id to use for the address 
         * selection list query.
         * @return  Softkey resource if that is used for the address 
         *          selection list query.
         */
        virtual TInt QuerySoftkeysResource() const = 0;

        /**
         * Override to handle key events in the list query.
         * The default implementation is empty.
         * @param aKeyEvent The key event.
         * @param aType The key event type.
         */
        IMPORT_C virtual TKeyResponse PbkControlKeyEventL
            (const TKeyEvent& aKeyEvent,TEventCode aType);

        // Spare virtual functions
        IMPORT_C virtual void Reserved_1();
        IMPORT_C virtual void Reserved_2();

    private: // data members
        /// Ref: aItem passed to ExecuteLD
        const CPbkContactItem* iContactItem;
        /// Field selection dialog for this class
        class CSelectFieldDlg;
        friend class CSelectFieldDlg;
        /// Own: field selection dialog
        CPbkSelectFieldDlg* iFieldDlg;
        /// Own: field array for iFieldDlg
        CPbkFieldArray* iFields;
        /// Ref: set to ETrue when exeuction enters destructor
        TBool* iDestroyedPtr;
        // Spare data
        TInt32 iSpare1;
    }; 


#endif // __CPbkAddressSelect_H__
            
// End of File
