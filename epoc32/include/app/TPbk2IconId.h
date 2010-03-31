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
* Description:  Phonebook 2 icon identification.
*
*/


#ifndef TPBK2ICONID_H
#define TPBK2ICONID_H

// INCLUDE FILES
#include <e32std.h>

// FORWARD DECLARATIONS
class TResourceReader;

/**
 * Phonebook 2 icon identification. This class is responsible for
 * implementing a unique identifier for icons in the Phonebook
 * context.
 */
class TPbk2IconId
    {
    public: // Construction
        /**
         * Default C++ constructor.
         * Constructs a null icon id.
         */
        IMPORT_C TPbk2IconId();

        /**
         * Constructor that takes the owner uid and icon id.
         *
         * @param aOwnerUid     The UID that specifies whose icon this is.
         *                      It's used the identify icons from different
         *                      components that are used in the same data
         *                      structure. The UID could be e.g a
         *                      Phonebook 2 UID for application defined
         *                      icons and ECom implementation UID for UI
         *                      extension icons.
         * @param aIconId       The id of the icon under the owner.
         */
        IMPORT_C TPbk2IconId(
                const TUid& aOwnerUid,
                TInt aIconId );

        /**
         * Constructor that takes a resource reader that points to a
         * PHONEBOOK2_ICON_ID structure.
         *
         * @param aReader   Resource reader to a PHONEBOOK2_ICON_ID
         *                  resource structure.
         */
        IMPORT_C TPbk2IconId(
                    TResourceReader& aReader );

    public: // Interface

        /**
         * Comparison that returns ETrue if the icon ids are the same.
         *
         * @param aRhs      An icon id to compare.
         * @return  ETrue if the icon ids are the same.
         */
        IMPORT_C TBool operator==(
                const TPbk2IconId& aRhs ) const;

        /**
         * Checks if passed uid is owner of this structure
         *
         * @param aUid Owner UID to check.
         * @return ETrue if UID is owner UID, EFalse otherwise.
         */
        inline TBool IsOwner( const TUid& aUid ) const
                { return aUid == iOwnersUid; }

    private: // Data
        /// Own: The UID of icon owner
        TUid iOwnersUid;
        /// Own: The id of the icon under the owner
        TInt iIconId;
        /// Own: Spare data
        TInt32 iSpare1;
        /// Own: Spare data
        TInt32 iSpare2;
    };

#endif // TPBK2ICONID_H

// End of File
