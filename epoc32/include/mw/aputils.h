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
* Description:  Declaration of the class CApUtils
*     Contains utility functions for access point handling
*
*/


#ifndef APUTILS_H
#define APUTILS_H

// Deprecation warning
#warning This header file has been deprecated. Will be removed in one of the next SDK releases.
 
 
//  INCLUDES
#include <commdb.h>
#include <ApEngineVer.h>
#include <ApEngineConsts.h>



// extra data holder.
typedef struct
    {
    TInt    iVariant;               /// Local variant value
    TBool   iWlanSupported;         /// WLAN feature supported or not
    TBool   iIsFeatureManagerInitialised;
    }TUtilsExtra;


// CLASS DECLARATION

/**
*  Representation of access point utilities.
*  Provides utilities to access points for clients.
*  Encapsulates database handling.
*  This class provides utility functions for clients that need some
*  specific information or parameters from (maybe more than one) AP.
*  It is provided for ease of use so clients do not have to work with
*  CApDataHandler's concept (one object-one Uid).
*/
class CApUtils :public CBase
    {
    public:  // Constructors and destructor

        /**
        * Two-phased constructor. Leaves on failure, places instance
        * on cleanup stack.
        * @param aDb a reference to a CCommsDataBase object.
        * @return The constructed CApUtils.
        *
        * @deprecated
        */
        IMPORT_C static CApUtils* NewLC( CCommsDatabase& aDb );


        /**
        * Destructor.
        *
        * @deprecated
        */
        IMPORT_C virtual ~CApUtils();


protected: // Constructors
        /**
        * C++ default constructor.
        *
        * @deprecated
        */
        IMPORT_C CApUtils();

        /**
        * Second-phase constructor.
        *
        * @deprecated
        */
        IMPORT_C void ConstructL( CCommsDatabase& aDb );




    public: // New functions

        /**
        * Indicates whether a given access point is in use or not.
        * If access point does not exists, return value is TRUE
        * @param aUid The UID of the access point.
        * @return Boolean indicating if it is in use (if used, TRUE)
        *
        * @deprecated
        */
        IMPORT_C TBool IsAPInUseL( TUint32 aUid );


        /**
        * Indicates the WAP bearer type of a given access point.
        * Passed descriptor MUST be large enough to hold the new data,
        * otherwise leaves with KErrDescOverflow.
        * The maximum length is the maximum length of a 'normal' text fields
        * length in Comms DB, KCommsDbSvrMaxFieldLength,
        * which is defined in cdblen.h.
        * @param aUid The UID of the access point.
        * @param aBearer A reference to a TBearer to hold the bearer
        * type of the access point.
        * @return no return value.
        *
        * @deprecated
        */
        IMPORT_C void WapBearerTypeL( TUint32 aUid, TDes& aBearer );


        /**
        * Gets the bearer type of a given access point. Leaves on error.
        * @param aUid The UID of the access point.
        * @return The type of the bearer.
        *
        * @deprecated
        */
        IMPORT_C TApBearerType BearerTypeL( TUint32 aUid );



        /**
        * Indicates the ISP type of a given access point.
        * @param aUid The UID of the access point.
        * @param aIspType A reference to a TCommsDbIspType to hold the value
        * @return No return value.
        *
        * @deprecated
        */
        IMPORT_C void ISPTypeL( TUint32 aUid, TCommsDbIspType& aIspType );

        /**
        * Indicates whether a given name is valid or not.
        * @param aNameText The name to check.
        * @return Boolean indicating if it is valid or not.
        *
        * @deprecated
        */
        IMPORT_C TBool IsValidNameL( const TDesC& aNameText );


        /**
        * TBool CApUtils::MakeValidNameL(TDes& aNameText);
        * Creates a valid name based on the given one.
        * @param aNameText The name to use for creating a valid name.
        * The new name is returned in it, too.
        * @return Whether the name was changed or not
        *
        * @deprecated
        */
        IMPORT_C TBool MakeValidNameL( TDes& aNameText );


        /**
        * Reads the Name of a given access point
        * @param aUid The UID of the access point.
        * @param A reference to hold the name of the access point.
        * @return no return value.
        * Passed descriptor MUST be large enough to hold the new data,
        * otherwise leaves with KErrDescOverflow.
        *
        * @deprecated
        */
        IMPORT_C void NameL( TUint32 aUid, TDes& aName );


        /**
        * Sets the Name of a given access point
        * Name is validated and modified if needed.
        * Passed aName buffer MUST be large enough to hold the modified name.
        * @param aName A reference to the name of the access point.
        * The given name is returned in it.
        * @param aUid The UID of the access point.
        * @return no return value.
        *
        * @deprecated
        */
        IMPORT_C void SetNameL( TDes& aName, TUint32 aUid );


        /**
        * Sets the ISP type for a given access point
        * @param aUid The UID of the access point
        * @param aIspType The desired Isp type of the access point
        * @return no return value.
        *
        * @deprecated
        */
        IMPORT_C void SetISPTypeL( TUint32 aUid, TCommsDbIspType aIspType );


        /**
        * Gets the Iap record ID for a given access point ID
        * @param aUid The UID of the access point
        * @return The Iap record ID.
        *
        * @deprecated
        */
        IMPORT_C TUint32 IapIdFromWapIdL( TUint32 aUid );


        /**
        * Gets the Wap record ID for a given Iap record ID
        * @param aUid The UID of the Iap
        * @return The Wap access point ID.
        *
        * @deprecated
        */
        IMPORT_C TUint32 WapIdFromIapIdL( TUint32 aUid );



        /**
        * Returns whether the access point has the WAP-mandatory
        * fields filled or not.
        * Starts a transaction which is 'internal' to ApEngine if
        * client not started one.
        * @param  aUid The UID of the access point
        * @return TBool Are the WAP-mandatory fields filled in the access point?
        *
        * @deprecated
        */
        IMPORT_C TBool HasMandatoryFieldsFilledL( TUint32 aUid );

        /**
        * Returns in a TBool whether the internet access point part
        * identified by the passed aUid exists or not.
        * param aUid the internet access point ID to check for
        * (NOT equals to Wap access point ID).
        * return TBool indicating whether an internet access point
        * with the given ID exists or not.
        *
        * @deprecated
        */
        IMPORT_C TBool IAPExistsL( TUint32 aUid );

        /**
        * Returns in a TBool whether the access point identified
        * by the passed aUid exists or not.
        * @param aUid the access point ID to check for.(Wap access point ID).
        * @return TBool indicating whether an access point with the
        * given ID exists or not.
        *
        * @deprecated
        */
        IMPORT_C TBool WapApExistsL( TUint32 aUid );

        /**
        * Returns whether the access point has the WAP-mandatory
        * fields filled or not.
        * @param  aUid The UID of the access point
        * @return TBool Are the WAP-mandatory fields filled in the access point?
        *
        * @deprecated
        */
        IMPORT_C TBool DoHasMandatoryFieldsFilledL(
                        TUint32 aUid,
                        CCommsDbTableView* aWapt = NULL,
                        TApBearerType aBearertype = EApBearerTypeAllBearers );


        /**
        * Indicates whether a given name is valid or not.
        * The name is valid if none, or only the aAcceptUid AP has it.
        * @param aNameText The name to check.
        * @param aAcceptUid A UID to accept with this name
        * @return Boolean indicating if it is valid or not.
        *
        * @deprecated
        */
        IMPORT_C TBool IsValidNameL( const TDesC& aNameText,
                                     TUint32 aAcceptUid );


        /**
        * Determines whether a given AP is read-only or not.
        * @param aUid A UID to look for
        * @return Boolean indicating if it is read-only or not.
        *
        * @deprecated
        */
        IMPORT_C TBool IsReadOnlyL( TUint32 aUid );



        /**
        * Determines whether a given LAN_SERVICE commsdb id 
        * is linked to a WLAN data (thus is it a WLAN) or not.
        * @param aUid A UID to look for
        * @return Boolean indicating if it is WLAN or not.
        */
        TBool IsWlanL( TUint32 aLanCommdbId );
        
        
        
        
        /**
        * Determines whether a given LAN_SERVICE commsdb id 
        * which is linked to a WLAN data (thus is it a WLAN) 
        * has a valid SSID or it is empty
        * @param aUid A UID to look for
        * @return Boolean indicating if it has WLAN SSID or not.
        */
        TBool HasWlanSSIDL( TUint32 aLanCommdbId );
        
    protected:


        /**
        * Indicates the WAP bearer type of a given access point.
        * Passed descriptor MUST be large enough to hold the new data,
        * otherwise leaves with KErrDescOverflow.
        * The maximum length is the maximum length of a 'normal' text fields
        * length in Comms DB, KCommsDbSvrMaxFieldLength,
        * which is defined in cdblen.h.
        * @param aUid The UID of the access point.
        * @param aBearer A reference to a TBearer to hold the bearer
        * type of the access point.
        * @return no return value.
        */
        void DoWapBearerTypeL( TUint32 aUid, TDes& aBearer );


        /**
        * Gets the bearer type of a given access point. Leaves on error.
        * @param aUid The UID of the access point.
        * @return The type of the bearer.
        */
        TApBearerType DoBearerTypeL( TUint32 aUid );


        /**
        * Indicates the ISP type of a given access point.
        * @param aUid The UID of the access point.
        * @param aIspType A reference to a TCommsDbIspType to hold the value
        * @return No return value.
        */
        void DoISPTypeL( TUint32 aUid, TCommsDbIspType& aIspType );


        /**
        * Reads the Name of a given access point
        * @param aUid The UID of the access point.
        * @param A reference to hold the name of the access point.
        * @return no return value.
        * Passed descriptor MUST be large enough to hold the new data,
        * otherwise leaves with KErrDescOverflow.
        */
        void DoNameL( TUint32 aUid, TDes& aName );


        /**
        * Sets the Name of a given access point
        * Name is validated and modified if needed.
        * Passed aName buffer MUST be large enough to hold the modified name.
        * @param aName A reference to the name of the access point.
        * The given name is returned in it.
        * @param aUid The UID of the access point.
        * @return no return value.
        */
        void DoSetNameL( TDes& aName, TUint32 aUid );


        /**
        * Sets the ISP type for a given access point
        * @param aUid The UID of the access point
        * @param aIspType The desired Isp type of the access point
        * @return no return value.
        */
        void DoSetISPTypeL( TUint32 aUid, TCommsDbIspType aIspType );


        /**
        * Returns in a TBool whether the record
        * identified by the passed aUid exists or not
        * in the table identified by the passed table name.
        * @param aTable The name of the table to check
        * @param aUid The UID to check for
        * @return TBool indicating whether the record
        * with the given ID exists in the given table or not.
        */
        TBool DoesExistsL( TPtrC aTable, TUint32 aUid );


        /**
        * Wrapper for public API.
        * Determines whether a given LAN_SERVICE commsdb id 
        * is linked to a WLAN data (thus is it a WLAN) or not.
        * @param aUid A UID to look for
        * @return Boolean indicating if it is WLAN or not.
        */
        TBool DoIsWlanL( TUint32 aLanCommdbId );
        
        
    private:    // Data
        CCommsDatabase* iDb;
        // TCommDbDatabaseType iDbType; // deprecated and not used but kept 
        // to maintain class size for BC
        // Added a new iExt for expansion instead of TCommDbDatabaseType 
        // same size, no BC problem...
        TUtilsExtra*  iExt;


    };

#endif      // APUTILS_H

// End of File
