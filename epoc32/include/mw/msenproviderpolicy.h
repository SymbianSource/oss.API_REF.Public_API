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
* Description:        This abstract class defines provider policy interface.
*
*/








#ifndef M_SEN_PROVIDER_POLICY_H
#define M_SEN_PROVIDER_POLICY_H

//  INCLUDES
#include <e32base.h> // for CActive
#include <badesca.h>
#include <SenDomFragment.h>

// FORWARD DECLARATIONS
class CSenIdentityProviderIdArray8;

// CLASS DECLARATION

/**
*  This abstract class defines provider policy interface.
*  The provider policy sets the conditions in which some service provider 
*  is capable to operate in. It is defining context, through which these
*  (possibly remote) services may be contacted and used.
*  The actual properties may include transport layer settings, like 
*  predefined Internet Access Point (IAP) ID. In addition, provider policy
*  may declare, that certain service should only be contacted using certain
*  identity provider (in ID-WSF). This can be achieved by mapping certain 
*  list of IDP IDs to a provider policy. 
*  Provider Policies are WSF wide settings, which are stored in WSF
*  databases, and thus they are shared with all the actual Web Service
*  Consumers (WSCs) accessing same services.
*
*   Example structure of ProviderPolicy XML fragment:
*
*   <ProviderPolicy>
*       <Transport>
*           <IapId>
*               1
*           </IapId>
*       </Transport>
*       <IdentityProviderIDs strict="true">
*           <IdentityProviderID>
*             urn:first.id.example.com
*           </IdentityProviderID>
*           <IdentityProviderID>
*             urn:second.id.example.com
*           </IdentityProviderID>
*       </IdentityProviderIDs>
*   </ProviderPolicy>
*  @lib SenServDesc.lib
*  @since Series60 3.0
*/
class MSenProviderPolicy
    {
    public: // New functions
        /**
        * Setter for Internet Access Point (IAP) ID.
        * Method is used to define default access point
        * to avoid IAP selection dialog prompt.
        * @since Series60 3.0
        * @param aIapId is the ID found from CommDB.
        */ 
        virtual void SetIapIdL(TUint32 aIapId) = 0;

        /**
        * Getter for IAP ID
        * @since Series60 3.0
        * @param aCurrentIapId will contain the current 
        *        Internet Access Point ID
        * @return
        *  - KErrNone if <IapId> element is found and has valid content
        *  - KErrNotFound if no <IapId> element has been found or it has
        *       no content
        *  - TLex error codes, if <IapId> element has non-numeric value,
        *    which cannot be resolved
        */ 
        virtual TInt IapId(TUint32& aCurrentIapId) = 0;

        /**
        * Setter for IdentityProvider IDs. Overrides 
        * current values with the given values from the array.
        * When initiating a new service connection, this list of
        * ProviderIDs define, which IdentityProviders are preferred
        * OR which are strictly acceptable ones.
        * @since Series60 3.0
        * @param aList  list of IdentityProvider IDs.
        */ 
        virtual void SetIdentityProviderIdsL(
                                        CSenIdentityProviderIdArray8& aList) = 0;

        /**
        * Adds a new IdentityProviderID value at the end of the current list 
        * values.
        * @since Series60 3.0
        * @param aProviderID defines, which IdentityProvider is preferred
        * OR which is strictly acceptable one, when initiating a new 
        * service connection.
        * @return   KErrAlreadyExists, if a duplicate is tried to add
        *           KErrArgument if a zero-length descriptor is tried to add
        *           (aProviderId.Length() == 0)
        */
        virtual TInt AddIdentityProviderIdL(TDesC8& aProviderId) = 0;

        /**
        * Method reads provider policy class instance values from given
        * template. Values may include an IAP ID, preferred IdentityProvider
        * IDs etc.
        * @since Series60 3.0
        * @param aTemplate from which the values are read.
        * @return       KErrNone            Everything went ok.
        *               KErrAlreadyExists   Duplicates were found
        *               KErrArgument        Invalid providerIds were found
        *               Other error codes are system-wide Symbian error codes.
        */ 
        virtual TInt RebuildFrom(MSenProviderPolicy& aTemplate) = 0;

        /**
        * Getter for IdentityProvider IDs.
        * @since Series60 3.0
        * @return a list of IDP arrays if such value(s) have been set
        *           or an empty array if no IDP:s have been specified.
        */ 
        virtual const CSenIdentityProviderIdArray8& IdentityProviderIds8L() = 0;

        /**
        * Checks if some policy is accepted by current policy.
        * @since    Series60 3.0
        * @param    aPolicyPattern is the policy being compared 
        *           with this instance.
        * @return   ETrue if policy candidate is accepted by current policy
        *           definition, EFalse if not.
        */
        virtual TBool Accepts(MSenProviderPolicy& aPolicyPattern) = 0;
        
        void SetSnapIdL(TUint32 /*aSnapId*/)
        {
        }
        TInt SnapId(TUint32& /*aCurrentSnapId*/)
        {
        	return KErrNotFound;
        }
    };

#endif //M_SEN_PROVIDER_POLICY_H

// End of File