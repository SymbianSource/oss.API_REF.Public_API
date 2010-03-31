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
* Description:  An array for contact links.
*
*/


#ifndef CVPBKCONTACTLINKARRAY_H
#define CVPBKCONTACTLINKARRAY_H

// INCLUDES
#include <e32base.h>
#include <mvpbkcontactlinkarray.h>

// FORWARD DECLARATIONS
class MVPbkContactStoreList;
class RWriteStream;
class RReadStream;
class MVPbkContactStoreLoader;


// CLASS DECLARATIONS

/**
 * A read-only array of contact links.
 * @lib VPbkEng.lib
 */
class CVPbkContactLinkArray : 
        public CBase, 
        public MVPbkContactLinkArray
    {
    public: // Constructors and Destructor
        /**
         * Creates an empty link array.
         *
         * @return A new instance of this class
         */
        IMPORT_C static CVPbkContactLinkArray* NewL();

        /**
         * Creates an empty link array. Leaves the created array object on
         * the cleanup stack.
         *
         * @return A new instance of this class
         */
        IMPORT_C static CVPbkContactLinkArray* NewLC();

        /**
         * Creates a link array from a packed descriptor of links.
         *
         * @param aPackedLinks a buffer that was created using PackLC
         *        of MVPbkContactLinkArray or MVPbkContactLink
         * @param aStoreList the list of stores that contain the
         *        stores that links belong.
         * @return A new instance of this class
         */
        IMPORT_C static CVPbkContactLinkArray* NewLC(
                const TDesC8& aPackedLinks,
                const MVPbkContactStoreList& aStoreList);
        
        /**
         * Creates a link array from a stream of links.
         *
         * @param aStream a stream of contact link that was created
         *                using MVPbkStreamable interface of
         *                MVPbkContactLink
         * @param aStoreList the list of stores that contain the
         *                stores that links belong.
         * @return A new instance of this class
         */
        IMPORT_C static CVPbkContactLinkArray* NewLC(
                RReadStream& aStream,
                const MVPbkContactStoreList& aStoreList);
        
        /**
         * Creates a link array from a stream of links. Uses aLoader
         * to find and load stores.
         * aLoader must exist the life time of this object.
         *
         * @param aStream a stream of contact link that was created
         *                using MVPbkStreamable interface of
         *                MVPbkContactLink
         * @param aLoader the contact store loader for internalization.
         * @return A new instance of this class
         */
        static CVPbkContactLinkArray* NewLC(
                RReadStream& aStream,
                MVPbkContactStoreLoader& aLoader );
        
        /**
         * Destructor.
         */
        ~CVPbkContactLinkArray();

    public:  // interface
        /**
         * Appends a link to this array.
         *
         * @param aLink the link object to append. This array takes ownership
         *              of the link if append is succesful.
         * @pre aLink != NULL
         * @post Array count is increased by one and the link is in the last 
         * element of the array.
         */
        IMPORT_C void AppendL(MVPbkContactLink* aLink);

        /**
         * Inserts a link to this array.
         *
         * @param aLink the link object to insert. This array takes ownership
         *              of the link if insertion is succesful.
         * @param aIndex    position where to insert the link.
         * @exception KErrNoMemory  if out of memory.
         * @pre aLink != NULL
         * @pre aIndex >= 0 && aIndex <= Count()
         * @post Array count is increased by one and the link is in the position 
         * marked by the aIndex element of the array.
         */
        IMPORT_C void InsertL(MVPbkContactLink* aLink, TInt aIndex);

        /**
         * Removes a link at aIndex from this array.
         *  
         * @pre aIndex >= 0 && aIndex <= Count()
         * @post The array count is decreased by one.
         */
        IMPORT_C void Remove(TInt aIndex);
        
        /**
         * Removes and deletes a link at aIndex from this array.
         *
         * @pre aIndex >= 0 && aIndex <= Count()
         * @post The array count is decreased by one.
         */
        IMPORT_C void Delete(TInt aIndex);

        /**
         * Resets the array and destroys the links
         */
        IMPORT_C void ResetAndDestroy();
        
        /**
         * Resets this array but doesn't destroy links
         * 
         * @post Count() == 0
         */
        IMPORT_C void Reset();
        
        /**
         * Returns the size of the packed link array
         */
        IMPORT_C TInt PackedBufferSize() const;

    public: // from MVPbkContactLinkArray
        TInt Count() const;
        const MVPbkContactLink& At(TInt aIndex) const;
        TInt Find(const MVPbkContactLink& aLink) const;
        HBufC8* PackLC() const;
        const MVPbkStreamable* Streamable() const;
    
    private: // implementation
        CVPbkContactLinkArray();
        void ConstructL();
        void ConstructL(const TDesC8& aPackedLinks, 
                const MVPbkContactStoreList& aOperations);
        void ConstructL(RReadStream& aStream, 
                const MVPbkContactStoreList& aOperations);
        TInt DoCalculatePackedBufferSizeV2() const;
        void DoFillPackedBufferV2L(RWriteStream& aWriteStream) const;
        void InternalizeFromBufferL( RReadStream& aReadStream, 
                const MVPbkContactStoreList& aStoreList );
        void DoInternalizeFromBufferL( RReadStream& aReadStream, 
                const MVPbkContactStoreList& aStoreList);
        void DoInternalizeFromBufferV2L(RReadStream& aReadStream, 
                const MVPbkContactStoreList& aStoreList);

    private:  // Data
        ///Own: contained contact links
        RPointerArray<MVPbkContactLink> iLinks;
        class CStoreUris;
        /// Own: an internal class for saving link URIs
        CStoreUris* iStoreUris;
        /// Ref: a reference to the contact store loader
        MVPbkContactStoreLoader* iStoreLoader;
    };

#endif // CVPBKCONTACTLINKARRAY_H

// End of file
