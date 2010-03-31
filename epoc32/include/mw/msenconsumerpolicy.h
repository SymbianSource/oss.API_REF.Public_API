/*
* Copyright (c) 2002-2005 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:        This abstract class defines consumer policy interface.
*
*/








#ifndef M_SEN_CONSUMER_POLICY_H
#define M_SEN_CONSUMER_POLICY_H

//  INCLUDES
#include <e32base.h> // for CActive
#include <badesca.h>
#include <SenDomFragment.h>

// FORWARD DECLARATIONS
class CSenIdentityProviderIdArray8;

// CLASS DECLARATION

/**
*  This abstract class defines consumer policy interface.
*  The consumer policy sets the conditions in which some service provider 
*  is capable to operate in. It is defining context, through which these
*  (possibly remote) services may be contacted and used.
*  The actual properties may include transport layer settings, like 
*  predefined Internet Access Point (IAP) ID. In addition, consumer policy
*  may declare, that certain service should only be contacted using certain
*  identity provider (in ID-WSF). This can be achieved by mapping certain 
*  list of IDP IDs to a consumer policy. 
*  A consumer policy is effective only for a single session, and thus it
*  applies to one service connection only. This means, that this policy
*  information is "private", and not shared between different WSC applications
*  using WSF, event though they might be using the same (remote) service at the
*  same time. Consumer policy properties are not serialized in any WSF
*  database, but resides in memory only.
*
*   Example structure of ConsumerPolicy XML fragment:
*
*   <ConsumerPolicy>
*       <Transport>
*           <IapId>
*               2
*           </IapId>
*       </Transport>
*       <IdentityProviderIDs strict="false">
*           <IdentityProviderID>
*             urn:first.example.idp.com
*           </IdentityProviderID>
*           <IdentityProviderID>
*             urn:second.example.idp.com
*           </IdentityProviderID>
*       </IdentityProviderIDs>
*   </ConsumerPolicy>
*
*  @lib SenServDesc.lib
*  @since Series60 3.0
*/
class MSenConsumerPolicy
    {
    public: // New functions
        
        /**
        * Setter for Internet Access Point (IAP) ID existing in CommDB.
        * @since Series60 3.0
        * @param aIapId IAP ID
        */ 
        virtual void SetConsumerIapIdL(TUint32 aIapId) = 0;

        /**
        * Getter for IAP ID.
        * @since Series60 3.0
        * @param aCurrentIapId  will contain the current 
        *                       Internet Access Point ID
        * @return
        *  - KErrNone if <IapId> element is found and has valid content
        *  - KErrNotFound if no <IapId> element has been found or it has
        *       no content
        *  - TLex error codes, if <IapId> element has non-numeric value,
        *    which cannot be resolved
        */ 
        virtual TInt ConsumerIapId(TUint32& aCurrentIapId) = 0;

        /**
        * Setter for consumer identity provider IDs. Overrides current values 
        * with the given values from the array. If an ID does not exist, it
        * will be added. 
        * @since Series60 3.0
        * @param aList  list of identity provider IDs.
        */ 
        virtual void SetConsumerIdentityProviderIdsL(
                                        CSenIdentityProviderIdArray8& aList) = 0;

        /**
        * Adds a new Identity provider ID value at the end of the current list
        * values. 
        * @since Series60 3.0
        * @param aProviderId unique ProviderID as UTF-8 descriptor
        * @return   KErrAlreadyExists, if a duplicate is tried to add
        *           KErrArgument if a zero-length descriptor is tried to add
        *           (aProviderId.Length() == 0)
        */
        virtual TInt AddConsumerIdentityProviderIdL(const TDesC8& aProviderId) = 0;

        /**
        * Rebuilds the consumer policy of this service pattern from the given
        * consumer policy.
        * @since Series60 3.0
        * @param aTemplate  the consumer policy to rebuild from.
        * @return KErrNone or other system-wide Symbian error codes.
        */
        virtual TInt RebuildFromConsumerPolicy(MSenConsumerPolicy& aTemplate) = 0;

        /**
        * Getter for Identity provider IDs.
        * @since Series60 3.0
        * @return a list of IDP arrays if such value(s) have been set
        *         or an empty array if no IDP:s have been specified.
        */ 
        virtual const CSenIdentityProviderIdArray8& 
                                            ConsumerIdentityProviderIds8L() = 0;

        /**
        * Checks if the policy of this service pattern accepts given policy.
        * @since Series60 3.0
        * @param aPolicyPattern the consumer policy to check.
        * @return ETrue if accepts, EFalse if not
        */
        virtual TBool AcceptsConsumerPolicy(MSenConsumerPolicy& aPolicyPattern) = 0;        
    };

#endif //M_SEN_CONSUMER_POLICY_H

// End of File


