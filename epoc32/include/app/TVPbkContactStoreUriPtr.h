/*
* Copyright (c) 2004-2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  A class for using contact store URIs
*
*/


#ifndef TVPBKCONTACTSTOREURIPTR_H
#define TVPBKCONTACTSTOREURIPTR_H


// INCLUDES
#include <e32std.h>
#include <mvpbkstreamable.h>


// CLASS DECLARATIONS

/**
 * A class for using contact store URIs (Uniform Resource Identifier).
 *
 * A URI identifies a contact store. This class is a helper for
 * accessing URI data. It can be used to separate the different parts
 * of the URI and compare URIs.
 *
 * E.g. A URI of the store could be cntdb://c:contacts.cdb.
 * This URI have three components:
 * 1) cntdb is a scheme - EContactStoreUriStoreType
 * 2) c is a drive of the database - EContactStoreUriStoreDrive
 * 3) c:contacts.cdb is the location - EContactStoreUriStoreLocation
 *
 * @lib VPbkEng.lib
 */
class TVPbkContactStoreUriPtr : public MVPbkStreamable
    {
    public: // Types
        /**
         * URI component types.
         */
        enum TVPbkContactStoreUriComponent
            {
            /// the whole URI
            EContactStoreUriAllComponents,
            /// the stores type, the URI's scheme 
            EContactStoreUriStoreType,
            /// the stores drive letter
            EContactStoreUriStoreDrive,
            /// the stores file/host location
            EContactStoreUriStoreLocation
            };

    public:  // constructor and destructor
        /**
         * Constructs a URI pointer to aStoreUri.
         *
         * @param aStoreUri A reference to the contact store URI.
         */
        IMPORT_C TVPbkContactStoreUriPtr(const TDesC& aStoreUri);

        /**
         * Constructor.
         */
        IMPORT_C TVPbkContactStoreUriPtr();

    public: // interface
        /**
         * Returns a descriptor that holds the whole Uri.
         *
         * @return A descriptor that holds the whole Uri.
         */
        IMPORT_C const TDesC& UriDes() const;

        /**
         * Compares this URI's component to aUri's component.
         *
         * @param aUri The URI whose component is compared.
         * @param aComponent Defines the component that are compared.
         * @return Zero if the URIs are the same.
         */
        IMPORT_C TInt Compare(const TVPbkContactStoreUriPtr& aUri, 
                TVPbkContactStoreUriComponent aComponent) const;

        /**
         * Compares this URI's component to aUriComponent.
         *
         * @param aUriComponent A descriptor that contains the component data.
         * @param aComponent Defines the component of this URI that is compared
         *                   to aUriComponent.
         * @return Zero if components matched.
         */
        IMPORT_C TInt Compare(const TDesC& aUriComponent, 
                TVPbkContactStoreUriComponent aComponent) const;

        /**
         * Returns a pointer to the aComponent part of URI.
         *
         * @param aComponent Defines the component that is returned.
         * @return a pointer to the aComponent part of URI.
         */
        IMPORT_C const TPtrC Component(
                TVPbkContactStoreUriComponent aComponent) const;

        /**
         * Sets this URI pointer to point to the same URI as aUri.
         *
         * @param aUri The URI that will be pointed to.
         */
        IMPORT_C void Set(const TVPbkContactStoreUriPtr& aUri);

        /**
         * Returns the length of the URI.
         *
         * @return The length of the URI.
         */
        IMPORT_C TInt Length() const;

    public: // from MVPbkStreamable
        IMPORT_C void ExternalizeL(RWriteStream& aStream) const;
        IMPORT_C TInt ExternalizedSize() const;

    private: // implementation
        TInt Compare(const TDesC& aLhsUri, const TDesC& aRhsUri) const;

    private: // Data
        /// Own: Pointer to the URI 
        TPtrC iUriBufferPointer;
        ///Own: Extension reserve
        TAny* iSpare;
    };

#endif  // TVPBKCONTACTSTOREURIPTR_H

//End of file
