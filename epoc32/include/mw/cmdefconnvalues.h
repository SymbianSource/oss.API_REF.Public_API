/*
* Copyright (c) 2006 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:  Declaration of default connection values
*
*/

#ifndef C_CMDEFCONNVALUES_H
#define C_CMDEFCONNVALUES_H

enum TCmDefConnType
        {
        /**
         * Deprecated
         */
        ECmDefConnAlwaysAsk,

        /**
         * Deprecated
         */
        ECmDefConnAskOnce,

        /**
         * The user selected a destination
         */
        ECmDefConnDestination,

        /**
          * The user selected a connection method
          */
        ECmDefConnConnectionMethod
        };
        
struct TCmDefConnValue 
    {
    /**
    * Type of default connection
    */
    TCmDefConnType iType;
    
    /**
    * Id of the selected destination or connection method
    */
    TUint iId;
    // -----------------------------------------------------------------------------
    // TCmDefConnValue::operator==
    // -----------------------------------------------------------------------------
    //
    inline TBool TCmDefConnValue::operator==( TCmDefConnValue& aDCSettingSelection ) const
        {
        return ( (iType == aDCSettingSelection.iType) && ( iId == aDCSettingSelection.iId ) );
        };

    // -----------------------------------------------------------------------------
    // TCmDefConnValue::operator!=
    // -----------------------------------------------------------------------------
    //
    inline TBool TCmDefConnValue::operator!=( TCmDefConnValue& aDCSettingSelection ) const
        {
        return (!( (iType == aDCSettingSelection.iType) && ( iId == aDCSettingSelection.iId ) ));
        };     
    };    
#endif // C_CMDEFCONNVALUES_H
