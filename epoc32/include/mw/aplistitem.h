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
* Description: 
*     Declaration of the CApSelect class.
*
*/


#ifndef CAPLISTITEM_H
#define CAPLISTITEM_H

// Deprecation warning
#warning This header file has been deprecated. Will be removed in one of the next SDK releases.
 
 
//  INCLUDES
#include <commdb.h>
#include <ApEngineVer.h>
#include <ApEngineConsts.h>


typedef struct
    {
    TBool           iReadOnly;      ///< Is the AP protected or not
    TUint32         iIapId;         ///< The IAP UID of the item
    TBool           iIsVpn;         ///< Is it a VPN or not?
    }TApListItemExtra;


// CLASS DECLARATION
/**
*  Representation of a list item.
*/
class CApListItem :public CBase
                                         ///< This class is used to hold
                                         ///< the main information of an
                                         ///< access point.
                                         ///< It is used in CApSelect.
    {
    public:  // Constructors and destructor

        /**
        * Two-phased constructor. Leaves on failure, places instance
        * on cleanup stack.
        * @return The constructed CApListItem.
        *
        * @deprecated
        */
        IMPORT_C static CApListItem* NewLC();


        /**
        * NOTE: This function is deprecated, use the one with the additional
        * aStartPage parameter below.
        * Two-phased constructor. Leaves on failure, places instance
        * on cleanup stack.
        * @param aIspType The type of the access point
        * (Internet only, Wap only, Internet AND Wap)
        * @param aUid The ID of the access point
        * @param aName The name of the access point
        * @param aBearerType The bearer type of the access point
        * @return The constructed CApListItem.
        *
        * @deprecated
        */
        IMPORT_C static CApListItem* NewLC( TCommsDbIspType aIspType,
                                            TUint32 aUid,
                                            const TDesC& aName,
                                            TApBearerType aBearerType );


        /**
        * Two-phased constructor. Leaves on failure, places instance
        * on cleanup stack.
        * @param aIspType The type of the access point
        * (Internet only, Wap only, Internet AND Wap)
        * @param aUid The ID of the access point
        * @param aName The name of the access point
        * @param aBearerType The bearer type of the access point
        * @param aStartpage The starting page of the access point
        * @param aReadOnly Whether the given item is read-only or not
        * @return The constructed CApListItem.
        *
        * @deprecated
        */
        IMPORT_C static CApListItem* NewLC( TCommsDbIspType aIspType,
                                            TUint32 aUid,
                                            const TDesC& aName,
                                            TApBearerType aBearerType,
                                            const TDesC& aStartPage,
                                            TBool aReadOnly = ETrue
                                            );

        /**
        * Two-phased constructor. Leaves on failure, places instance
        * on cleanup stack.
        * @param aItem a pointer to a CApListItem.
        * @return The constructed CApListItem.
        *
        * @deprecated
        */
        IMPORT_C static CApListItem* NewLC( CApListItem* aItem );


        /**
        * Destructor.
        *
        * @deprecated
        */
        IMPORT_C virtual ~CApListItem();


        /**
        * Copies the data from another CApListItem
        * Substitutes the "Assignment operator."
        * @return No return value.
        *
        * @deprecated
        */
        IMPORT_C void CopyFromL( const CApListItem& aCopyFrom );



    protected:      // Constructors
        /**
        * C++ default constructor.
        *
        * @deprecated
        */
        IMPORT_C CApListItem();

        /**
        * NOTE: This function is deprecated, use the one with the additional
        * aStartPage parameter below.
        * Second-phase constructor.
        * @param aIspType The type of the access point
        * (Internet only, Wap only, Internet AND Wap)
        * @param aUid The ID of the access point
        * @param aName The name of the access point
        * @param aBearerType The bearer type of the access point
        *
        * @deprecated
        */
        IMPORT_C void ConstructL( TCommsDbIspType aIspType,
                                  TUint32 aUid,
                                  const TDesC& aName,
                                  TApBearerType aBearerType );

        /**
        * Second-phase constructor.
        * @param aIspType The type of the access point
        * (Internet only, Wap only, Internet AND Wap)
        * @param aUid The ID of the access point
        * @param aName The name of the access point
        * @param aBearerType The bearer type of the access point
        * @param aStartpage The starting page of the access point
        *
        * @deprecated
        */
        IMPORT_C void ConstructL( TCommsDbIspType aIspType,
                                  TUint32 aUid,
                                  const TDesC& aName,
                                  TApBearerType aBearerType,
                                  const TDesC& aStartPage
                                  );


        /**
        * Second-phase constructor.
        *
        * @deprecated
        */
        IMPORT_C void ConstructL();


    public: // New functions

        /**
        * NOTE: This function is deprecated, use the one with the additional
        * aStartPage parameter below.
        * Sets item values of the access point. Leaves on failure.
        * @param aIspType The type of the access point
        * (Internet only, Wap only, Internet AND Wap)
        * @param aUid The ID of the access point
        * @param aName The name of the access point
        * @param aBearerType The bearer type of the access point
        *
        * @deprecated
        */
        IMPORT_C void SetItemL( TCommsDbIspType aIspType,
                                TUint32 aUid,
                                const TDesC& aName,
                                TApBearerType aBearerType );

        /**
        * Sets item values of the access point. Leaves on failure.
        * @param aIspType The type of the access point
        * (Internet only, Wap only, Internet AND Wap)
        * @param aUid The ID of the access point
        * @param aName The name of the access point
        * @param aBearerType The bearer type of the access point
        * @param aStartpage The starting page of the access point
        *
        * @deprecated
        */
        IMPORT_C void SetItemL( TCommsDbIspType aIspType,
                                TUint32 aUid,
                                const TDesC& aName,
                                TApBearerType aBearerType,
                                const TDesC& aStartpage
                                );


        /**
        * Gets the name of the 'current' access point
        * Ownership of the returned text is not passed.
        * @return The name of the current access point
        *
        * @deprecated
        */
        IMPORT_C const TDesC& Name();


        /**
        * Gets the UID of the current access point
        * @return The UID of the current access point
        *
        * @deprecated
        */
        IMPORT_C TUint32 Uid();


        /**
        * Gets the ISP-type of the current access point
        * @return The ISP-type of the current access point.
        *
        * @deprecated
        */
        IMPORT_C TCommsDbIspType Type();


        /**
        * Gets the bearer-type of the current access point
        * @return The bearer-type of the current access point.
        *
        * @deprecated
        */
        IMPORT_C TApBearerType BearerType();


        /**
        * Returns the startpage of the current access point if any,
        * otherwise, an empty string is returned.
        * Ownership of the returned text is not passed.
        * @return The startpage of the current access point.
        *
        * @deprecated
        */
        IMPORT_C const TDesC& StartPage() const;


        /**
        * Returns whether the access point is read-only or not.
        * @return Whether the access point is read-only or not.
        *
        * @deprecated
        */
        IMPORT_C TBool IsReadOnly() const;


        /**
        * Returnes whether the given access point is a VPN ap or not.
        * @return whether the given access point is a VPN ap or not.
        */
        TBool IsVpnAp() const;

        /**
        * Sets whether the given access point is a VPN ap or not.
        */
        void SetVpnFlag( TBool aIsVpn );

    protected:
        void CreateExtraL();    ///< Construct the extra data

    private:    // Data
        TCommsDbIspType iIspType;       ///< The type of the access point
                                        ///< (Internet only, Wap only,
                                        ///< Internet AND Wap)
        TUint32         iUid;           ///< The ID of the access point
        HBufC*          iName;          ///< The name of the access point
        HBufC*          iStartPage;     ///< The startpage of the access point

        TApBearerType   iBearerType;    ///< Bearer type of the access point
        TApListItemExtra*   iExt;       ///< Extra data structure


    protected:  // Friend classes
        friend class CApSelect;
        friend class TApListItemUidKey;

    };



#endif      // CAPLISTITEM_H

// End of File
