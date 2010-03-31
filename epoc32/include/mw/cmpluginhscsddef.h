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
* Description:  Resource headers for HSCSD Plugin.
*
*/

#ifndef CMPLUGINHSCSDDEF_H
#define CMPLUGINHSCSDDEF_H

/**  ECOM interface UID */
const TUint KUidHSCSDBearerType = 0x10281BB8;

namespace CMManager
    {
    /**
    * Enumeration for the HSCSD specific attributes.
    */
    enum TConnectionMethodHscsdSpecificAttributes
        {
        EPluginHSCSDAttribStart = 20000,    /**<
                                            * Marks the beginning of HSCSD
                                            * attributes.
                                            */
        
        EHscsdChannelCoding = 20100,        /**<
                                            * Enum value specifying HSCSD channel
                                            * coding. Selected from 
                                            * RMobileCall::TMobileCallTchCoding.
                                            * (TUint32 - default: none - read only)
                                            */
                                            
        EHscsdAiur = 20101,                 /**<
                                            * Enum value specifying AIUR for HSCSD. 
                                            * Selected from 
                                            * RMobileCall::TMobileCallAiur.
                                            * (TUint32 - default: none - read only)
                                            */
        
        EHscsdRequestedTimeSlots = 20102,   /**<
                                            * Requested number of time slots 
                                            * for HSCSD.
                                            * (TUint32 - default: none - read only)
                                            */

        EHscsdMaximumTimeSlots = 20103,     /**<
                                            * Maximum number of time slots for 
                                            * HSCSD which could be requested during this connection.
                                            * (TUint32 - default: none - read only)
                                            */
        
        EHscsdAsymmetry = 20104,            /**<
                                            * Enum of type TMobileCallAsymmetry for 
                                            * HSCSD.
                                            * (TUint32 - default: none)
                                            */
        
        EHscsdUserInitUpgrade = 20105,      /**<
                                            * HSCSD parameter - user init upgrade.
                                            * (TBool - default: none)
                                            */

        EPluginHSCSDAttribRangeMax = 29999  /**<
                                            * Marks the end of HSCSD attributes.
                                            */
        };
    } // namespace CMManager
    
#endif // CMPLUGINHSCSDDEF_H
