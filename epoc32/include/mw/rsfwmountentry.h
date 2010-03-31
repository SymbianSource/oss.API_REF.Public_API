/*
* Copyright (c) 2002-2004 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Mount configuration entry
*
*/


#ifndef CRSFWMOUNTENTRY_H
#define CRSFWMOUNTENTRY_H

// INCLUDES
#include <e32base.h>
#include <f32file.h>
#include <rsfwmountentryitem.h>


// Drive entry constants
// these come from UI specification
const TInt KMaxMountNameLength = 20;
const TInt KMaxMountUriLength = 200;
const TInt KMaxMountUserNameLength = 50;
const TInt KMaxMountPasswordLength = 50;
const TInt KMaxMountAuxDataLength  = 64;
const TInt KMaxMountConfItemLength = 200; // Longest possible conf item value.
const TInt KMaxMountConfLength     = 512; // Buffer for sending all drive 
                                          // configuration values
const TInt KIndexAsStringLength = 4; // how wide string for index


// CLASS DECLARATION
/**
*  Remote drive (configuration) entry
*
*  Drive configuration entry consists of the following values:
*  - Index of the entry. Optional.
*  - Friendly name. Mandatory.
*  - Drive letter. Optional.
*  - Drive URL. Mandatory.
*  - User name. Optional.
*  - Password. Optional
*  - Internet Access point. Optional.
*
*  Maximum lengths for the strings:
*   - Friendly name 20 characters
*   - Drive URL 200 characters
*   - User name 50 characters
*   - Password 50 characters
*  Setter functions leave with KErrArgument, if longer values are attempted
*
*  Drive Letter must be between J: and Y:
*  (see also RFs::DriveList() documentation)¨
*
*  Drive Url must begin with a valid scheme (e.g. https:// or upnp://)
*
*  @lib mountstore.dll
*  @since Series 60 3.1
*/
class CRsfwMountEntry: public CBase
    {
public: // Constructors and destructor
    /**
     * Two-phased constructor.
     */
    IMPORT_C static CRsfwMountEntry* NewL();

    /**
     * Two-phased constructor
     */
    IMPORT_C static CRsfwMountEntry* NewLC();

    /**
     * Destructor.
     */
    IMPORT_C virtual ~CRsfwMountEntry();

    /**
     * Sets an item value
     * @param aIndex item index
     * @param aValue string value
     * @leave KErrArgument, incorrect index or value
     */
    IMPORT_C void SetItemL(TInt aIndex, const TDesC8& aValue);

    /**
     * Sets an item value
     * @param aIndex item index
     * @param aValue string value
     * @leave KErrArgument, incorrect index or value
     */
    IMPORT_C void SetItemL(TInt aIndex, const TDesC& aValue);

    /**
     * Sets all item values 
     * @param aIndex index (only used for positioning the entry - not stored)
     * @param aName name
     * @param aDriveLetter drive letter
     * @param aUri URI
     * @param aUserName user name
     * @param aPassword password
     * @param aIap IAP name
     * @leave KErrArgument, one or more parameters incorrect
     */
    IMPORT_C void SetEntryL(TInt aIndex,
                            const TDesC& aName,
                            TChar aDriveLetter,
                            const TDesC& aUrl,
                            const TDesC& aUserName,
                            const TDesC& aPassword,
                            const TDesC& aIap);

    /**
     * Returns an item value
     * An empty value may be an empty string or NULL
     */
    IMPORT_C const HBufC* Item(TInt aIndex) const;
    
    /**
     * Clear the entry - the items are set to NULL
     */
    IMPORT_C void Clear();

    /**
     * Clone the entry - the items are are copied to the newly created entry
     * @return cloned entry
     */
    IMPORT_C CRsfwMountEntry* CloneL() const;

private:
    CRsfwMountEntry();
    void ConstructL();

private: // Data
    RFs iFs;
    HBufC* iMountEntryItems[EMountEntryItemCount];
    };

#endif // CRSFWMOUNTENTRY_H

// End of File
