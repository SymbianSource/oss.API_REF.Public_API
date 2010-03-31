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
* Description:  An ECOM interface for the virtual phonebook converter for
*                contact IDs of the Symbian's Contacts Model and
*                Virtual Phonebook contact links.
*                NOTE: Must be used only with contact model stores.
*
*/


#ifndef CVPBKCONTACTIDCONVERTER_H
#define CVPBKCONTACTIDCONVERTER_H

// INCLUDE FILES
#include <e32base.h>
#include <vpbkpublicuid.h>
#include <ecom/ecom.h>

// FORWARD DECLARATIONS
class MVPbkContactStore;
class MVPbkContactLink;
class MVPbkStoreContactField;
class CPbkContactItem;

/**
 * An ECOM interface for the virtual phonebook converter for contact IDs
 * of the Symbian's Contacts Model and Virtual Phonebook contact links.
 *
 * A client has a TContactItemId that needs to be converted
 * to MVPbkContactLink or vice versa. 
 */
class CVPbkContactIdConverter : public CBase
    {
    public:
        /**
         * Creates a new conversion utility object for given contact store.
         *
         * The given contact store must be from the cntdb domain,
         * otherwise this function leaves with KErrNotSupported.
         *
         * @exception KErrNotSupported if aContactStore is not from cntdb domain.
         * @param aContactStore Contact store that is used for conversion.
         *                      Links and IDs are converted for this store only.
         *                      Trying to convert links or IDs from different stores
         *                      provides unspecified results.
         * @return A new conversion utility object.
         */
        static CVPbkContactIdConverter* NewL(MVPbkContactStore& aContactStore);
        
        /**
         * Destructor.
         */
        ~CVPbkContactIdConverter();
        
    public: // Interface
        /**
         * Converts the given link to an Id in the contact store defined in
         * NewL function.
         * 
         * Returned value is KNullContactId if the link
         * is from any other store than the one given in NewL.
         * 
         * @param aLink A link to convert.
         * @return A contact item id (TContactItemId) corresponding the aLink
         *         in the contact store given as construction parameter in 
         *         NewL.
         */
        virtual TInt32 LinkToIdentifier(
                const MVPbkContactLink& aLink) const =0;
        
        /**
         * Converts the given identifier (TContactItemId) to a contact link 
         * in the contact store defined in NewL function.
         * 
         * Created link is left to cleanup stack and ownership is transferred
         * to caller.
         * 
         * @param aIdentifier The contact id to convert.
         * @return Contact link corresponding the aIdentifier in the contact
         *         store given as construction parameter in NewL.
         */
        virtual MVPbkContactLink* IdentifierToLinkLC(
                TInt32 aIdentifier) const =0;
            
        /**
         * Returns a PbkEng field index for a Virtual Phonebook field.
         *
         * @param aField A Virtual Phonebook field to be converted.
         * @return A PbkEng field index or KErrNotFound.
         */
        virtual TInt PbkEngFieldIndexL(
                const MVPbkStoreContactField& aField) const =0;
        
        /**
         * Converts the given link to an new CPbkContactItem.
         * 
         * Created contact item is left to cleanup stack and
         * ownership is transferred to caller. Returns NULL if the
         * link is from any other store than the one given in NewL.
         *
         * @param aLink A link to convert.
         * @return A PbkEng contact item corresponding the aLink in
         *         the contact store given as construction parameter in NewL.
         */
        virtual CPbkContactItem* LinkToPbkContactItemLC(
                const MVPbkContactLink& aLink) const =0;
        
        /**
         * Converts the given link to an new CPbkContactItem and locks
         * it for modification.
         * 
         * Created contact item is left to cleanup stack and
         * ownership is transferred to caller. Returns NULL if the
         * link is from any other store than the one given in NewL.
         *
         * @see CPbkContactEngine::OpenContactLCX
         * @param aLink A link to convert
         * @return A PbkEng contact item corresponding the aLink in
         *         the contact store given as construction parameter
         *         in NewL.
         */
        virtual CPbkContactItem* LinkToOpenPbkContactItemLCX(
                const MVPbkContactLink& aLink) const =0; 
        
        /**
         * Commits the openned contact item.
         * 
         * @param aContactItem contact item to commit
         */       
        virtual void CommitOpenContactItemL(CPbkContactItem& aContactItem) =0;
        
        /**
         * Returns an extension point for this interface or NULL.
         *
         * @param aExtensionUid no extensions defined currently.
         * @return An extension point for this interface or NULL.
         */
        virtual TAny* ContactIdConverterExtension( TUid /*aExtensionUid*/ )
                { return NULL; }
            
    private: // Data
        ///Own: Destructor ID key
        TUid iDtorIDKey;
    };

    
// INLINE FUNCTIONS

inline CVPbkContactIdConverter* CVPbkContactIdConverter::NewL(
        MVPbkContactStore& aContactStore)
    {
    TAny* ptr = NULL;
    ptr = REComSession::CreateImplementationL(
            TUid::Uid(KVPbkContactIdConverterImplementationUid), 
            _FOFF(CVPbkContactIdConverter, iDtorIDKey),
            static_cast<TAny*>(&aContactStore));

    return reinterpret_cast<CVPbkContactIdConverter*>(ptr);
    }
    
inline CVPbkContactIdConverter::~CVPbkContactIdConverter()
    {
    REComSession::DestroyedImplementation(iDtorIDKey);
    }
    
#endif // CVPBKCONTACTIDCONVERTER_H

// End of File
