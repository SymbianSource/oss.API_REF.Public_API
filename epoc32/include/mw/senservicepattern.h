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
* Description:        Class derives the XML service description and further extends
*                it by adding consumer policy interface implementation.
*
*/








#ifndef SEN_SERVICE_PATTERN_H
#define SEN_SERVICE_PATTERN_H

//  INCLUDES
#include <e32base.h>
#include <s32strm.h>
#include <SenXmlServiceDescription.h>
#include <MSenConsumerPolicy.h>

// FORWARD DECLARATIONS
class CSenConsumerPolicy;

// CLASS DECLARATION

/**
* Class derives the XML service description and further extends
* it by implementing consumer policy interface.
*
* Service pattern is typically used by Basic Web Service consumers,
* which often know, which policy to use in the communication with 
* certain Web Service Provider (WSP). 
*
* For example, a Basic Web Service consumer application might want 
* strictly define certain Internet Access Point (IAP) to be used when
* initializing new service connection. Such an application can simply
* instantiate new ServicePattern and set pre-known IAP ID into it.
*
* The main purpose of this class is to simplify the initialization
* of service connections for Basic Web Services.
*
* It is important to note, that all the consumer policy information entered
* via ServicePattern extending the MSenConsumerPolicy is treated
* in "policy-per-client" terms. In other words, any consumer
* policy information will not be stored for latter use of other
* applications (even they might happen to use same WSP and contract!).
*
* This is due the nature of Service Pattern: it acts as a consumer
* originated filter, after which a service will be resolved.
*
* Any service which "meets" the Service Pattern "constraints", is
* considered as a "match", because such service accepts this
* (search) pattern.
*
*  @lib SenServDesc.lib
*  @since Series60 3.0
*/
class CSenServicePattern : public CSenXmlServiceDescription, public MSenConsumerPolicy

    {
    public:  // Constructors and destructor
        
        /**
         *  Standard 2 phase constructors
         */
        IMPORT_C static CSenServicePattern* NewL();

        /**
         *  Standard 2 phase constructors
         */
        IMPORT_C static CSenServicePattern* NewLC();

        /**
         *  Standard 2 phase constructor
         *  @param aNamespaceURI    namespace URI for the service pattern.
         */
        IMPORT_C static CSenServicePattern* NewL(const TDesC8& aNamespaceURI);

        /**
         *  Standard 2 phase constructor
         *  @param aNamespaceURI    namespace URI for the service pattern.
         */
        IMPORT_C static CSenServicePattern* NewLC(const TDesC8& aNamespaceURI);

        /**
         *  Standard 2 phase constructor.
         *  @param aEndPoint    service pattern endpoint.
         *  @param aContract    service pattern contract.
         */
        IMPORT_C static CSenServicePattern* NewL(   const TDesC8& aEndPoint,
                                                    const TDesC8& aContract );

        /**
         *  Standard 2 phase constructor.
         *  @param aEndPoint    service pattern endpoint.
         *  @param aContract    service pattern contract.
         */
        IMPORT_C static CSenServicePattern* NewLC(  const TDesC8& aEndPoint,
                                                    const TDesC8& aContract );
        
        /**
        * Destructor.
        */
        IMPORT_C virtual ~CSenServicePattern();

        // New functions
        
        /**
        * Convenience method for writing out the consumer policy as XML
        * in UTF-8 form.
        * @since Series60 3.0
        * @return consumer policy as UTF-8 form XML.
        */ 
        IMPORT_C HBufC8* ConsumerPolicyAsXmlL();
        
        // Functions from base classes
        
        // From CSenXmlServiceDescription 
        
        /**
        * Compares that both service description and possible
        * policy inside of it matches with this instance.
        * @since Series60 3.0
        * @param aPattern   the service description to compare to
        * @return ETrue both service description and policy information
        *         matches, otherwise EFalse. If some value is not set 
        *         in current instance, it is not compared.
        */
        IMPORT_C TBool Matches(MSenServiceDescription& aServicePattern);
        
        /**
        * Callback function which implements the XML content handler interface.
        * Parses the consumer policies independently.
        * @since Series60 3.0
        * @param aNsUri         The namespace URI of the new element
        * @param aLocalName     The local name of the new element
        * @param aQName         The qualified name of the new element
        * @param aAttributes    The attributes of the new element
        */
        IMPORT_C void StartElementL(const TDesC8& aNsUri,
                                    const TDesC8& aLocalName,
                                    const TDesC8& aQName,
                                    const RAttributeArray& aAttributes);
                                
        // From MSenConsumerPolicy 
        IMPORT_C virtual void SetConsumerIapIdL(TUint32 aIapId);
        IMPORT_C virtual TInt ConsumerIapId(TUint32& aCurrentIapId);
        IMPORT_C virtual void SetConsumerIdentityProviderIdsL(
                                    CSenIdentityProviderIdArray8& aList);
    
        IMPORT_C virtual TInt AddConsumerIdentityProviderIdL(
                                                        const TDesC8& aProviderId);

        IMPORT_C virtual const CSenIdentityProviderIdArray8&
                                                ConsumerIdentityProviderIds8L();

        IMPORT_C virtual TBool AcceptsConsumerPolicy(
                                            MSenConsumerPolicy& aPolicyPattern);

        IMPORT_C virtual TInt RebuildFromConsumerPolicy(
                                                    MSenConsumerPolicy& aTemplate);
        
    protected:  // New functions
        
        /**
        * C++ constructor.
        * @since Series60 3.0
        * @param aType enumeration defininng the type of this class.
        */
        IMPORT_C CSenServicePattern(
                            MSenServiceDescription::TDescriptionClassType aType);
        
        /**
        * Base constructor offered to sub class implementations.
        * @since Series60 3.0
        */
        IMPORT_C void BaseConstructL();

        /**
        * Base constructor offered to sub class implementations.
        * @since Series60 3.0
        * @param aNamespaceURI the localname for XML element representation
        *        of this class.
        */
        IMPORT_C void BaseConstructL(const TDesC8& aNamespaceURI);

        /**
        * Base constructor offered to sub class implementations.
        * @since Series60 3.0
        * @param aEndPoint is the actual endpoint to the service
        * @param aContract of the service, typically some URI
        */
        IMPORT_C void BaseConstructL(const TDesC8& aEndPoint, const TDesC8& aContract);
        
	public:
		/**
        * Sets the Consumer SNAP ID.
        * @param aSnapId  A TUint32 Snap ID
        */
        IMPORT_C void SetConsumerSnapIdL(TUint32 aSnapId);
		/**
        * Gets the Consumer SNAP ID.
        * @param aCurrentSnapId  A TUint32 reference to be filled in with the
        *                       value of the SNAP ID.
        * @return               KErrNone if no error, or some of the system
        *                       wide error codes.
        */
        IMPORT_C TInt ConsumerSnapId(TUint32& aCurrentSnapId);
		
    protected:  // Data
    
        // Consumer policy class instance, used as a delegate in parsing
        CSenConsumerPolicy* iConsumerPolicy;
    };

#endif SEN_SERVICE_PATTERN_H

// End of File