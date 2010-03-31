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
* Description:  An array for store URIs.
*
*/


#ifndef CVPBKCONTACTSTOREURIARRAY_H
#define CVPBKCONTACTSTOREURIARRAY_H

// INCLUDES
#include <e32base.h>

// FORWARD DECLARATIONS
class TVPbkContactStoreUriPtr;
class CVPbkContactStoreUri;

// CLASS DECLARATIONS

/**
 * Virtual Phonebook contact store URI array. Responsible for
 * implementing a container for contact store URI's. In addition 
 * to common container behaviour the class can internalize and
 * externalize store URI's from and to descriptors.
 */
class CVPbkContactStoreUriArray : public CBase
    {
    public: // Construction and destruction
        /**
         * Creates a new instance of this class.
         * @return Newly created instance of this class.
         */
        IMPORT_C static CVPbkContactStoreUriArray* NewL();
        
        /**
         * Creates a new instance of this class. Leaves
         * the instance to the cleanup stack.
         * @return Newly created instance of this class.
         */
        IMPORT_C static CVPbkContactStoreUriArray* NewLC();
        
        /**
         * Creates a new instance of this class internalizing the
         * contents of the descriptor.
         * @param aPackedUris	Packed URIs created by using the 
         * 						PackLC functionality of this class.
         * @return Newly created instance of this class.
         */
        IMPORT_C static CVPbkContactStoreUriArray* NewLC(const TDesC8& aPackedUris);
        
        /**
         * Destructor.
         */
        ~CVPbkContactStoreUriArray();
        
    public: // Interface

        /**
         * Appends StoreUriPtr to this array.
         *
         * @param aStoreUri	Store URI to add array.
         */
        IMPORT_C void AppendL(const TVPbkContactStoreUriPtr& aStoreUri);

        /**
         * Appends array of StoreUriPtr to this array.
         *
         * @param aUriArray	Array of Store URIs to add array.
         */
        IMPORT_C void AppendAllL(const CVPbkContactStoreUriArray& aUriArray);

        /**
         * Removes StoreUriPtr from this array.
         *
         * @param aStoreUri Store Uri to add array.
         */
        IMPORT_C void Remove(const TVPbkContactStoreUriPtr& aStoreUri);

        /**
         * Returns the count of Store URIs in this array.
         *
         * @return Count of Store URIs in array.
         */
        IMPORT_C TInt Count() const;
        
        /**
         * Gets the URI pointer descriptor from this array at 
         * the given index.
         *
         * @param aIndex Index which URI Ptr is needed
         * @return URI pointer descriptor.
         */
        IMPORT_C TVPbkContactStoreUriPtr operator[](TInt aIndex) const;
        
        /**
         * Packs this URI array to a heap descriptor.
         *
         * @return Packed URI array in a heap descriptor.
         */        
        IMPORT_C HBufC8* PackLC() const;
        
        /**
         * Checks whether the given URI is already in this array.
         *
         * @param aStoreUri Store URI to check.
         * @return ETrue if Store URI is in this array, EFalse if not.
         */        
        IMPORT_C TBool IsIncluded(const TVPbkContactStoreUriPtr& aStoreUri) const;
        
    private: // Implementation
        CVPbkContactStoreUriArray();
        void ConstructL();
        void ConstructL(const TDesC8& aPackedUris);
        TInt CalculateExternalizedSize() const;
        
    private:
        ///Own: Array of contact store URI's
        RPointerArray<CVPbkContactStoreUri> iUris;
    };
    
#endif // CVPBKCONTACTSTOREURIARRAY_H

// End of File
