/*
* Copyright (c) 2002 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:  Declaration of the CApNetworks class.
*
*/


#ifndef CAPNETWORKS_H
#define CAPNETWORKS_H

// Deprecation warning
#warning This header file has been deprecated. Will be removed in one of the next SDK releases.
 
 
//  INCLUDES
#include <commdb.h>
#include <ApEngineVer.h>
#include <ApEngineConsts.h>

// FORWARD DECLARATIONS
class CApNetworkItem;
class CApNetworkItemList;

// CLASS DECLARATION

/**
*  This class is used to help client's network selection.
*
*/
NONSHARABLE_CLASS( CApNetworks ) :public CBase
    {
    public:  // Constructors and destructor

        /**
        * Two-phased constructor. Leaves on failure, places instance
        * on cleanup stack.
        * @param aDb a reference to a CCommsDataBase.
        * @return The constructed CApNetworks.
        *
        * @deprecated
        */
        IMPORT_C static CApNetworks* NewLC( CCommsDatabase& aDb );


        /**
        * Destructor.
        *
        * @deprecated
        */
        IMPORT_C virtual ~CApNetworks();


    private:      // Constructors

        /**
        * C++ default constructor.
        *
        * @deprecated
        */
        IMPORT_C CApNetworks();

        /**
        * Second-phase constructor.
        * @param aDb The database
        *
        * @deprecated
        */
        IMPORT_C void ConstructL( CCommsDatabase& aDb );



    public: // New functions

        /**
        * Counts the items in the list
        * @return The number of items in the list.
        *
        * @deprecated
        */
        IMPORT_C TUint32 Count() const;


        /**
        * Gets the name of the network group with the given UID
        * Ownership of the returned text is not passed.
        * @param aUid The uid of the network item 
        * @return The name of the network group
        *
        * @deprecated
        */
        IMPORT_C const TDesC& NameL( TUint32 aUid ) const;



        /**
        * Provides all data in a CApNetworkItemList array.
        * @param aList A reference to a CApNetworkItemList object
        * to hold the values.
        * @return The number of items in the list.
        * All elements in the aList array and their memory
        * will be freed inside the routine.
        * The routine expands or shrinks the array as necessary
        * to minimize memory consumption.
        *
        * @deprecated
        */
        IMPORT_C TInt AllListItemDataL( CApNetworkItemList& aList );


    private:
        /**
        * This function updates the member data according to the
        * current filter settings.
        * @return Error code.
        */
        TInt DoUpdateL();



    private:    // Data
        CCommsDatabase*             iDb;    // Does not own it!
        CApNetworkItemList*         iApList;
        TInt                        iCount;
    };

#endif      // CAPNETWORKS_H

// End of File
