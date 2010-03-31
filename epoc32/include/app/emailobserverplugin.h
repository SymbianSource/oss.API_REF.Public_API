/*
* Copyright (c) 2009 - 2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Interface header for Email Observer Plugin API.
*
*/

#ifndef EMAILOBSERVERPLUGIN_H
#define EMAILOBSERVERPLUGIN_H

// System includes
#include <ecom/ecom.h>

namespace EmailInterface {

// Forward declarations
class MEmailObserverListener;
class MEmailData;

/**
 *  Class that client of this interface user instantiates
 */
class CEmailObserverPlugin : public CBase
    {
public:
    /**
     * Contructor
     * @param aImplUid implementation identifier used by the ECOM framework
     * @param aListener callback interface provided by the client/instantiator.
     *        Plugin should call this when it wants the widget data to be updated
     * @return plugin instance
     */
    inline static CEmailObserverPlugin* NewL(
        TUid aImplUid,
        MEmailObserverListener* aListener );

    /** destructor */
    inline virtual ~CEmailObserverPlugin();

    /**
     * Accessor for data that needs to be published
     * Plugin must implement this.
     * When client calls this, plugin must ensure that all necessary data is accessible/updated
     * @return interface to email data
     */
    virtual MEmailData& EmailDataL() = 0;

private:
    /**
     * Unique instance identifier key
     */
    TUid iDtor_ID_Key;
    };

// Inline functions
#include "emailobserverplugin.inl"

} // namespace

#endif // EMAILOBSERVERPLUGIN_H
