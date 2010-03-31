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
* Description:  Default store URIs offered by the Virtual Phonebook
*
*/



#ifndef VPBKCONTACTSTOREURIS_H
#define VPBKCONTACTSTOREURIS_H

//  INCLUDES
#include <e32std.h>

/**
 * Default store URIs offered by the Virtual Phonebook.
 *
 * The Virtual Phonebook doesn't offer dynamic URI configuration repository.
 * The repository of URIs is left to responsibility of a higher level component.
 * 
 * @lib VPbkEng.lib
 */
namespace VPbkContactStoreUris
    {
    /**
     * Returns the default Contacts Model database store URI.
     *
     * @return The default Contacts Model database store URI.
     */
    IMPORT_C const TDesC& DefaultCntDbUri();

    /**
     * Returns the global ADN SIM store URI.
     * 
     * Global means the ADN store that can be accessed by both GSM and 3G phone.
     * 
     * @return The global ADN SIM store URI
     */
    IMPORT_C const TDesC& SimGlobalAdnUri();

    /**
     * Returns the global FDN SIM store URI.
     *
     * Global means the FDN store that can be accessed by both GSM and 3G phone.
     *
     * @return The global FDN SIM store URI
     */
    IMPORT_C const TDesC& SimGlobalFdnUri();

    /**
     * Returns the global SDN SIM store URI. 
     *
     * Global means the SDN store that can be accessed by both GSM and 3G phone.
     * 
     * @return The global SDN SIM store URI
     */
    IMPORT_C const TDesC& SimGlobalSdnUri();

    /**
     * Returns the MSISDN SIM store URI.
     *
     * Global means the MSISDN store that can be accessed by both GSM and
     * 3G phone.
     *
     * NOTE: Though the name of the store suggests that the store will contain
     *       the caller's own phone number it's not exactly the case. It can
     *       contain the number but only if it has been set.
     *
     * @return The MSISDN SIM store URI.
     */
    IMPORT_C const TDesC& SimGlobalOwnNumberUri();
    }

#endif      // VPBKCONTACTSTOREURIS_H
            
// End of File
