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
* Description:  Declaration of the CApSelect class.
*
*/


#ifndef CAPSELECT_H
#define CAPSELECT_H

// Deprecation warning
#warning This header file has been deprecated. Will be removed in one of the next SDK releases.
 
 
//  INCLUDES
#include <commdb.h>
#include <ApEngineVer.h>
#include <ApEngineConsts.h>


// FORWARD DECLARATIONS
class CApListItem;
class CApListItemList;
class CApUtils;



enum TVpnFilterType
    {
    EVpnFilterVpnOnly,          ///< Shows only VPN access points
    EVpnFilterNoVpn,            ///< Shows only non-VPN access points
    EVpnFilterBoth              ///< Shows both normal and VPN access points
    };


// CLASS DECLARATION
// Extra data holder
typedef struct
    {
        TInt                iMaxIndex;
        TInt                iReqIpvType;
        TInt                iIsIpv6Supported;
        TInt                iExtra;
        TBool               iIsFeatureManagerInitialised;
        TBool               iCdma;
        TInt                iVpnFilterType; // TVpnFilterType values !!
        TBool               iWlanSupported;
        TBool               iIncludeEasyWlan;
    }TSelectExtra;



typedef struct
    {
    TUint32     iVpnIapId;
    TUint32     iHomeIapId;
    HBufC *     iName;
    }TVpnData;


/**
*  This class is used to help client's access point selection.
*  Selection can be tailored with specific filters, rules and sort order.
*  Provides methods for setting and getting filters and sort order.
*
*/
class CApSelect :public CBase
    {
    public:  // Constructors and destructor

        /**
        * Two-phased constructor. Leaves on failure, places instance
        * on cleanup stack.
        * @param aDb a pointer to a CCommsDataBase.
        * @param aIspTypeFilter Filtering criteria on ISP type
        * Possible values are:
        * KEApIspTypeInternetOnly, KEApIspTypeWAPOnly,
        * KEApIspTypeInternetAndWAP, KEApIspTypeWAPMandatory
        * KEApIspTypeAll and their combinations.
        * @param aBearerFilter Filtering criteria on bearer type
        * Possible values are the TApBearer enums and
        * their combinations (or-ed).
        * @param aSortType Specifies the sort order to use.
        * Possible values are:
        * KEApSortUidAscending, KEApSortUidDescending,
        * KEApSortNameAscending, KEApSortNameDescending
        * @return The constructed CApSelect.
        *
        * @deprecated
        */
        IMPORT_C static CApSelect* NewLC(
                                        CCommsDatabase& aDb,
                                        TInt aIspFilter,
                                        TInt aBearerFilter,
                                        TInt aSortType
                                        );


        /**
        * Two-phased constructor. Leaves on failure, places instance
        * on cleanup stack.
        * @param aDb a pointer to a CCommsDataBase.
        * @param aIspTypeFilter Filtering criteria on ISP type
        * Possible values are:
        * KEApIspTypeInternetOnly, KEApIspTypeWAPOnly,
        * KEApIspTypeInternetAndWAP, KEApIspTypeWAPMandatory
        * KEApIspTypeAll and their combinations.
        * @param aBearerFilter Filtering criteria on bearer type
        * Possible values are the TApBearer enums and
        * their combinations (or-ed).
        * @param aSortType Specifies the sort order to use.
        * Possible values are:
        * KEApSortUidAscending, KEApSortUidDescending,
        * KEApSortNameAscending, KEApSortNameDescending
        * @param aReqIpvType Filtering criteria on the IPv type of the 
        * access point. In case of GPRS, GPRS_PDP_TYPE holds it, while
        * in case of CSD, all CSD access points are 
        * considered to be IPv4 & IPv6 (both)
        * @return The constructed CApSelect.
        *
        * @deprecated
        */
        IMPORT_C static CApSelect* NewLC(
                                        CCommsDatabase& aDb,
                                        TInt aIspFilter,
                                        TInt aBearerFilter,
                                        TInt aSortType,
                                        TInt aReqIpvType
                                        );



        /**
        * Two-phased constructor. Leaves on failure, places instance
        * on cleanup stack.
        * @param aDb a pointer to a CCommsDataBase.
        * @param aIspTypeFilter Filtering criteria on ISP type
        * Possible values are:
        * KEApIspTypeInternetOnly, KEApIspTypeWAPOnly,
        * KEApIspTypeInternetAndWAP, KEApIspTypeWAPMandatory
        * KEApIspTypeAll and their combinations.
        * @param aBearerFilter Filtering criteria on bearer type
        * Possible values are the TApBearer enums and
        * their combinations (or-ed).
        * @param aSortType Specifies the sort order to use.
        * Possible values are:
        * KEApSortUidAscending, KEApSortUidDescending,
        * KEApSortNameAscending, KEApSortNameDescending
        * @param aReqIpvType Filtering criteria on the IPv type of the 
        * access point. In case of GPRS, GPRS_PDP_TYPE holds it, while
        * in case of CSD, all CSD access points are 
        * considered to be IPv4 & IPv6 (both)
        * @param aVpnFilterType a TVpnFilterType enum specifying the 
        * vpn filtering.
        * @return The constructed CApSelect.
        *
        * @deprecated
        */
        IMPORT_C static CApSelect* NewLC(
                                        CCommsDatabase& aDb,
                                        TInt aIspFilter,
                                        TInt aBearerFilter,
                                        TInt aSortType,
                                        TInt aReqIpvType,
                                        TVpnFilterType aVpnFilterType );


        /**
        * Two-phased constructor. Leaves on failure, places instance
        * on cleanup stack.
        * @param aDb a pointer to a CCommsDataBase.
        * @param aIspTypeFilter Filtering criteria on ISP type
        * Possible values are:
        * KEApIspTypeInternetOnly, KEApIspTypeWAPOnly,
        * KEApIspTypeInternetAndWAP, KEApIspTypeWAPMandatory
        * KEApIspTypeAll and their combinations.
        * @param aBearerFilter Filtering criteria on bearer type
        * Possible values are the TApBearer enums and
        * their combinations (or-ed).
        * @param aSortType Specifies the sort order to use.
        * Possible values are:
        * KEApSortUidAscending, KEApSortUidDescending,
        * KEApSortNameAscending, KEApSortNameDescending
        * @param aReqIpvType Filtering criteria on the IPv type of the 
        * access point. In case of GPRS, GPRS_PDP_TYPE holds it, while
        * in case of CSD, all CSD access points are 
        * considered to be IPv4 & IPv6 (both)
        * @param aVpnFilterType a TVpnFilterType enum specifying the 
        * vpn filtering.
        * @param aIncludeEasyWlan TBool specifying whther to include
        * EasyWlan access point in the list or not...
        * @return The constructed CApSelect.
        *
        * @deprecated
        */
        IMPORT_C static CApSelect* NewLC(
                                        CCommsDatabase& aDb,
                                        TInt aIspFilter,
                                        TInt aBearerFilter,
                                        TInt aSortType,
                                        TInt aReqIpvType,
                                        TVpnFilterType aVpnFilterType,
                                        TBool aIncludeEasyWlan );


        /**
        * Destructor.
        *
        * @deprecated
        */
        IMPORT_C virtual ~CApSelect();


    protected:      // Constructors

        /**
        * C++ default constructor.
        *
        * @deprecated
        */
        IMPORT_C CApSelect();


        /**
        * Second-phase constructor.
        * @param aDb a pointer to a CCommsDataBase.
        * @param aIspTypeFilter Filtering criteria on ISP type
        * Possible values are:
        * KEApIspTypeInternetOnly, KEApIspTypeWAPOnly,
        * KEApIspTypeInternetAndWAP, KEApIspTypeWAPMandatory
        * KEApIspTypeAll and their combinations.
        * @param aBearerFilter Filtering criteria on bearer type
        * Possible values are the TApBearer enums and
        * their combinations (or-ed).
        * @param aSortType Specifies the sort order to use.
        * Possible values are:
        * KEApSortUidAscending, KEApSortUidDescending,
        * KEApSortNameAscending, KEApSortNameDescending
        *
        * @deprecated
        */
        IMPORT_C void ConstructL(
                                CCommsDatabase& aDb,
                                TInt aIspFilter,
                                TInt aBearerFilter,
                                TInt aSortType
                                );


        /**
        * Second-phase constructor.
        * @param aDb a pointer to a CCommsDataBase.
        * @param aIspTypeFilter Filtering criteria on ISP type
        * Possible values are:
        * KEApIspTypeInternetOnly, KEApIspTypeWAPOnly,
        * KEApIspTypeInternetAndWAP, KEApIspTypeWAPMandatory
        * KEApIspTypeAll and their combinations.
        * @param aBearerFilter Filtering criteria on bearer type
        * Possible values are the TApBearer enums and
        * their combinations (or-ed).
        * @param aSortType Specifies the sort order to use.
        * Possible values are:
        * KEApSortUidAscending, KEApSortUidDescending,
        * KEApSortNameAscending, KEApSortNameDescending
        * @param aReqIpvType Filtering criteria on the IPv type of the 
        * access point. In case of GPRS, GPRS_PDP_TYPE holds it, while
        * in case of CSD, all CSD access points are 
        * considered to be IPv4 & IPv6 (both)
        *
        * @deprecated
        */
        IMPORT_C void ConstructL(
                                CCommsDatabase& aDb,
                                TInt aIspFilter,
                                TInt aBearerFilter,
                                TInt aSortType,
                                TInt aReqIpvType
                                );


        /**
        * Second-phase constructor.
        * @param aDb a pointer to a CCommsDataBase.
        * @param aIspTypeFilter Filtering criteria on ISP type
        * Possible values are:
        * KEApIspTypeInternetOnly, KEApIspTypeWAPOnly,
        * KEApIspTypeInternetAndWAP, KEApIspTypeWAPMandatory
        * KEApIspTypeAll and their combinations.
        * @param aBearerFilter Filtering criteria on bearer type
        * Possible values are the TApBearer enums and
        * their combinations (or-ed).
        * @param aSortType Specifies the sort order to use.
        * Possible values are:
        * KEApSortUidAscending, KEApSortUidDescending,
        * KEApSortNameAscending, KEApSortNameDescending
        * @param aReqIpvType Filtering criteria on the IPv type of the 
        * access point. In case of GPRS, GPRS_PDP_TYPE holds it, while
        * in case of CSD, all CSD access points are 
        * considered to be IPv4 & IPv6 (both)
        * @param aVpnFilterType a TVpnFilterType enum specifying the 
        * vpn filtering.
        *
        * @deprecated
        */
        IMPORT_C void ConstructL( CCommsDatabase& aDb,
                                 TInt aIspFilter,
                                 TInt aBearerFilter,
                                 TInt aSortType,
                                 TInt aReqIpvType,
                                 TVpnFilterType aVpnFilterType 
                                 );
                                 
        /**
        * Second-phase constructor.
        * @param aDb a pointer to a CCommsDataBase.
        * @param aIspTypeFilter Filtering criteria on ISP type
        * Possible values are:
        * KEApIspTypeInternetOnly, KEApIspTypeWAPOnly,
        * KEApIspTypeInternetAndWAP, KEApIspTypeWAPMandatory
        * KEApIspTypeAll and their combinations.
        * @param aBearerFilter Filtering criteria on bearer type
        * Possible values are the TApBearer enums and
        * their combinations (or-ed).
        * @param aSortType Specifies the sort order to use.
        * Possible values are:
        * KEApSortUidAscending, KEApSortUidDescending,
        * KEApSortNameAscending, KEApSortNameDescending
        * @param aReqIpvType Filtering criteria on the IPv type of the 
        * access point. In case of GPRS, GPRS_PDP_TYPE holds it, while
        * in case of CSD, all CSD access points are 
        * considered to be IPv4 & IPv6 (both)
        * @param aVpnFilterType a TVpnFilterType enum specifying the 
        * vpn filtering.
        * @param aIncludeEasyWlan TBool specifying whther to include
        * EasyWlan access point in the list or not...
        *
        * @deprecated
        */                                 
        IMPORT_C void ConstructL( CCommsDatabase& aDb,
                                 TInt aIspFilter,
                                 TInt aBearerFilter,
                                 TInt aSortType,
                                 TInt aReqIpvType,
                                 TVpnFilterType aVpnFilterType,
                                 TBool aIncludeEasyWlan );
                                 
    public: // New functions
        /**
        * Sets filters and sorting order for the list of available
        * access points
        * @param aIspTypeFilter Filtering criteria on ISP type
        * Possible values are:
        * KEApIspTypeInternetOnly, KEApIspTypeWAPOnly,
        * KEApIspTypeInternetAndWAP,
        * KEApIspTypeWAPMandatory, KEApIspTypeAll and their combinations.
        * @param aBearerFilter Filtering criteria on bearer type
        * Possible values are the TApBearer enums and
        * their combinations (or-ed).
        * @param aSortType Specifies the sort order to use.
        * Possible values are:
        * KEApSortUidAscending, KEApSortUidDescending,
        * KEApSortNameAscending, KEApSortNameDescending
        *
        * @deprecated
        */
        IMPORT_C void SetFiltersL(
                                 TInt aIspFilter,
                                 TInt aBearerFilter,
                                 TInt aSortType
                                 );



        /**
        * Gets the current ISP-type filter
        * @return The current ISP-type filter
        *
        * @deprecated
        */
        IMPORT_C TInt IspTypeFilter();


        /**
        * Gets the current bearer-type filter
        * @return The current bearer-type filter
        *
        * @deprecated
        */
        IMPORT_C TInt BearerFilter();


        /**
        * Gets the current sorting order
        * @return The current sorting order
        *
        * @deprecated
        */
        IMPORT_C TInt SortOrder();


        /**
        * Navigates to the first access point in the list.
        * @return Boolean indicating the success of the operation.
        *
        * @deprecated
        */
        IMPORT_C TBool  MoveToFirst();


        /**
        * Navigates to the next access point in the list.
        * @return Boolean indicating the success of the operation.
        *
        * @deprecated
        */
        IMPORT_C TBool  MoveNext();


        /**
        * Navigates to the last access point in the list.
        * @return Boolean indicating the success of the operation.
        *
        * @deprecated
        */
        IMPORT_C TBool  MoveLast();


        /**
        * Navigates to the previous access point in the list.
        * @return Boolean indicating the success of the operation.
        *
        * @deprecated
        */
        IMPORT_C TBool  MovePrev();


        /**
        * Counts the items in the list
        * @return The number of items in the list.
        *
        * @deprecated
        */
        IMPORT_C TUint32 Count();


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
        * Provides all data in a CApListItemList array.
        * @param aList A reference to a CApListItemList object
        * to hold the values.
        * @return The number of items in the list.
        * All elements in the aList array and their memory
        * will be freed inside the routine.
        * The routine expands or shrinks the array as necessary
        * to minimize memory consumption.
        *
        * @deprecated
        */
        IMPORT_C TInt AllListItemDataL( CApListItemList& aList );

        /**
        * Returns whether the current item is read-only or not.
        * @return Returns whether the current item is read-only or not.
        *
        * @deprecated
        */
        IMPORT_C TBool IsReadOnly() const;

    private:
        /**
        * This function updates the member data according to the
        * current filter settings.
        * @return Error code.
        */
        TInt DoUpdateL();


        /**
        * Gets the filtered and sorted wap table
        * and places it on the Cleanupstack
        */
        CCommsDbTableView* GetFilteredSortedWapTableViewLC();


        /**
        * Gets the filtered and sorted IP bearer table
        * and places it on the Cleanupstack
        */
        CCommsDbTableView* GetFilteredSortedIpBearerTableViewLC();


        /**
        * Gets the filtered and sorted ISP table
        * and places it on the Cleanupstack
        */
        CCommsDbTableView* GetFilteredSortedIspOutTableViewLC();


        /**
        * Gets the filtered and sorted GPRS table
        * and places it on the Cleanupstack
        */
        CCommsDbTableView* GetFilteredSortedGprsTableViewLC( TBool aIn );

        /**
        * Reads up the specified columns TUint32 values stored
        * in the table and returns it in the passed array
        */
        void GetUintValuesL
                (
                CCommsDbTableView* aTable,
                const TDesC& aField,
                CArrayFixFlat<TUint32>& aArray
                );


        /**
        * Reads up the protection values stored
        * in the table and returns it in the passed array
        */
        void GetProtValuesL( CCommsDbTableView* aTable,
                             CArrayFixFlat<TUint32>& aArray );

        /**
        * Reads up the specified columns text values stored
        * in the table and returns it in the passed array
        */
        void GetTextValuesL
                (
                CCommsDbTableView* aTable,
                const TDesC& aField,
                CArrayPtrFlat<HBufC>& aArray
                );


        /**
        * Reads up the specified columns long text values stored
        * in the table and returns it in the passed array
        */
        void GetLongTextValuesL
                (
                CCommsDbTableView* aTable,
                const TDesC& aField,
                CArrayPtrFlat<HBufC>& aArray
                );


        /**
        * Returns whether a given value is in the given array or not
        */
        TBool IsInArray( CArrayFixFlat<TUint32>* aArray, TUint32 aValue );


        /**
        * Returns the position of a given value in the given array.
        */
        TInt PosInArray( CArrayFixFlat<TUint32>* aArray, TUint32 aValue );


        /**
        * Returns the position of an item with a given UID in the given list.
        */
        TInt GetItemPos( CApListItemList* aTmpApList, TUint32 aId );


        /**
        * Opens a view on the given table where a given text coloumn has
        * a given value
        * @return the opened view on the table
        */
        CCommsDbTableView* OpenViewMatchingTextL
                                (
                                const TDesC& aTableName,
                                const TDesC& aColumnToMatch,
                                const TDesC16& aValueToMatch
                                );

        /**
        * Gets the ISP values (ISP UID, ISP type, ISP bearer type)
        * from a given table
        * @param aTable the table to go through (already filtered & ordered)
        * @param aArray An array to hold the readed values
        * @param aColName Column name (different column names are used for
        * CSD/GPRS/CDMA.
        */
        void GetIspValuesL
                (
                CCommsDbTableView* aTable,
                CArrayFixFlat<TUint32[3]>* aArray,
                const TDesC& aColName
                );

        /**
        * Gets the position of an element with a given IAP UID
        */
        TInt GetIapPos
                (
                CArrayFixFlat<TUint32[3]>* aArray,
                TUint32 aValue
                );

        /**
        * Sorts the data according to localised sorting on the 
        * access point names, using CompareC
        */
        void SortLocalisedNameL( TBool aAscending = ETrue );


        /**
        * Sorts the data according to Uids
        */
        void SortUidL( TBool aAscending = ETrue );



    private:    // New functions
        /**
        * Sets filters and sorting order for the list of available
        * access points
        * @param aIspTypeFilter Filtering criteria on ISP type
        * Possible values are:
        * KEApIspTypeInternetOnly, KEApIspTypeWAPOnly,
        * KEApIspTypeInternetAndWAP,
        * KEApIspTypeWAPMandatory, KEApIspTypeAll and their combinations.
        * @param aBearerFilter Filtering criteria on bearer type
        * Possible values are the TApBearer enums and
        * their combinations (or-ed).
        * @param aSortType Specifies the sort order to use.
        * Possible values are:
        * KEApSortUidAscending, KEApSortUidDescending,
        * KEApSortNameAscending, KEApSortNameDescending
        * @param aReqIpvType The filtering criteria for IPv type
        * @param aVpnFilterType The Vpn filtering type, TVpnFilterType values
        */
        void SetFiltersL( TInt aIspFilter,
                          TInt aBearerFilter,
                          TInt aSortType,
                          TInt aReqIpvType,
                          TInt aVpnFilterType
                         );


        /**
        * Returns a pointer to the opened VPN_SERVICE table
        */
        CCommsDbTableView* GetVpnTableViewLC();


        /**
        * Gets the VPN values (VPN IAP UID, VPN HOME IAP UID, VPN Name )
        * from the given VPN table
        * @param aTable the table to go through (already filtered & ordered)
        * @param aVpnArray An array to hold the readed vpn data values
        */
        void GetVpnValuesL( CCommsDbTableView* aTable, 
                            CArrayFixFlat<TVpnData>* aVpnArray );


        /**
        * Returns the supported bearer set from the passed requested bearer set
        * @param aBearerFilter The requested bearer set
        * return The supported subset of the requested bearers.
        */
        TInt GetSupportedBearerSet( TInt aBearerFilter );


        /**
        * Adding WLAN or LAN access points to existing list.
        * aWlan a TBool specifying whether WLAN or LAN
        */
        void AddLanL( TBool aWlan );




    private:    // Data
        CCommsDatabase*             iDb;    // Does not own it!
        TInt                        iIsp;
        TInt                        iBearer;
        TInt                        iSort;
        CApListItemList*            iApList;
        TInt                        iCursor;
        TInt                        iCount;
        TSelectExtra*               iExt;

    };

#endif      // CAPSELECT_H

// End of File
