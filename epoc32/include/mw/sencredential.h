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
* Description:        Class implements (web) service credential functionality
*
*/








#ifndef SEN_CREDENTIAL_H
#define SEN_CREDENTIAL_H

//  INCLUDES
#include <e32base.h>
#include <s32strm.h>
#include <SenBaseFragment.h>

// CONSTANTS
_LIT8(KCredentialsName,     "Credentials");
_LIT8(KEndpointName,        "Endpoint");
_LIT8(KSecurityMechIdName,  "SecurityMechID");
_LIT8(KNotOnOrAfterName,    "NotOnOrAfter");
_LIT8(KConditionsName,      "Conditions");

// FORWARD DECLARATIONS
class SenDateUtils;

// CLASS DECLARATION

/**
* Class implements (web) service credential functionality
*  @lib SenServDesc.lib
*  @since Series60 3.0
*/
class CSenCredential : public CSenBaseFragment
    {
    public:  // Constructors and destructor
        
        /**
        * Two-phase constructor.
        * @since Series60 3.0
        * @param aNsUri     The namespace URI of the new element
        * @param aLocalName The local name of the new element
        * @param aQName     The qualified name of the new element
        * @param aAttributes    The attributes of the new element
        * @return new CSenCredential instance pointer
        * Leave codes:  
        *       KErrSenInvalidCharacters if aLocalName or aQName contains
        *       illegal characters.     
        *       KErrSenZeroLengthDescriptor if aLocalName or aQName is zero length.
        */
        IMPORT_C static CSenCredential* NewL(const TDesC8& aNsUri,
                                             const TDesC8& aLocalName,
                                             const TDesC8& aQName,
                                             const RAttributeArray& aAttributes);
            
        /**
        * Two-phase constructor.
        * @since Series60 3.0
        * @param aNsUri     The namespace URI of the new element
        * @param aLocalName The local name of the new element
        * @param aQName     The qualified name of the new element
        * @param aAttributes    The attributes of the new element
        * @return new CSenCredential instance pointer, which is left on
        *         cleanup stack.
        * Leave codes:  
        *       KErrSenInvalidCharacters if aLocalName or aQName contains
        *       illegal characters.     
        *       KErrSenZeroLengthDescriptor if aLocalName or aQName is zero length.
        */
        IMPORT_C static CSenCredential* NewLC(const TDesC8& aNsUri,
                                              const TDesC8& aLocalName,
                                              const TDesC8& aQName,
                                              const RAttributeArray& aAttributes);

        /**
        * Constructor with a possibility to set a parent.
        * @since Series60 3.0
        * @param aNsUri     The namespace URI of the new element
        * @param aLocalName The local name of the new element
        * @param aQName     The qualified name of the new element
        * @param aAttributes    The attributes of the new element
        * @param aParent        The parent element of the new element
        * @return new CSenCredential instance pointer
        * Leave codes:  
        *       KErrSenInvalidCharacters if aLocalName or aQName contains
        *       illegal characters.     
        *       KErrSenZeroLengthDescriptor if aLocalName or aQName is zero length.
        */
        IMPORT_C static CSenCredential* NewL(const TDesC8& aNsUri,
                                             const TDesC8& aLocalName,
                                             const TDesC8& aQName,
                                             const RAttributeArray& aAttributes,
                                             CSenElement& aParent);

        /**
        * Constructor with a possibility to set a parent.
        * @since Series60 3.0
        * @param aNsUri     The namespace URI of the new element
        * @param aLocalName The local name of the new element
        * @param aQName     The qualified name of the new element
        * @param aAttributes    The attributes of the new element
        * @param aParent        The parent element of the new element
        * @return new CSenCredential instance pointer, which is left on
        *         cleanup stack.
        * Leave codes:  
        *       KErrSenInvalidCharacters if aLocalName or aQName contains
        *       illegal characters.     
        *       KErrSenZeroLengthDescriptor if aLocalName or aQName is zero length.
        */
        IMPORT_C static CSenCredential* NewLC(const TDesC8& aNsUri,
                                              const TDesC8& aLocalName,
                                              const TDesC8& aQName,
                                              const RAttributeArray& aAttributes,
                                              CSenElement& aParent);

        /**
        * Constructor which copies itself from another credential.
        * @since Series60 3.0
        * @param    aCredential     credential to copy from.
        * @return new CSenCredential instance pointer
        */
        IMPORT_C static CSenCredential* NewL(const CSenCredential& aCredential);

        /**
        * Constructor which copies itself from another credential.
        * @since Series60 3.0
        * @param    aCredential     credential to copy from.
        * @return new CSenCredential instance pointer, which is left on
        *         cleanup stack.
        */
        IMPORT_C static CSenCredential* NewLC(const CSenCredential& aCredential);

        /**
        * Destructor.
        */
        IMPORT_C virtual ~CSenCredential();        

        // New functions
        
        /**
        * Getter for the credential ID.
        * @since Series60 3.0
        * @return the ID
        */
        IMPORT_C const TDesC8& Id();

        /**
        * Getter for the credential expiration time.
        * @since Series60 3.0
        * @return the the expiration time
        */
        IMPORT_C TTime& ValidUntil();

        /**
        * Setter for the credential expiration time.
        * @since Series60 3.0
        * @param aTime  The new expiration time
        */
        IMPORT_C void SetValidUntil(TTime& aTime);

    protected:  // Functions from base classes

        /**
        * From CSenDomFragment Callback function which implement the XML content handler interface.
        * @since Series60 3.0
        * @param aNsUri     The namespace URI of the new element
        * @param aLocalName The local name of the new element
        * @param aQName     The qualified name of the new element
        * @param aAttributes    The attributes of the new element
        */
        IMPORT_C virtual void StartElementL(const TDesC8& aNsUri,
                                            const TDesC8& aLocalName,
                                            const TDesC8& aQName,
                                            const RAttributeArray& aAttributes);
        
    private:
        
        /**
        * C++ default constructor.
        */
        IMPORT_C CSenCredential();

        /**
        * By default Symbian 2nd phase constructor is private.
        * @since Series60 3.0
        * @param aNsUri is the XML namespace as UTF-8 descriptor
        * @param aLocalName is the XML localname as UTF-8 descriptor
        * @param aQName is the XML qualifiedname as UTF-8 descriptor
        * @param aAttributes is the list of XML attributes
        */
        IMPORT_C void ConstructL(const TDesC8& aNsUri,
                                 const TDesC8& aLocalName,
                                 const TDesC8& aQName,
                                 const RAttributeArray& aAttributes);

        /**
        * By default Symbian 2nd phase constructor is private.
        * @since Series60 3.0
        * @param aNsUri is the XML namespace as UTF-8 descriptor
        * @param aLocalName is the XML localname as UTF-8 descriptor
        * @param aQName is the XML qualifiedname as UTF-8 descriptor
        * @param aAttributes is the list of XML attributes
        * @param aParent is the parent element, which may declare other
        *        namespaces.
        */
        IMPORT_C void ConstructL(const TDesC8& aNsUri,
                                 const TDesC8&  aLocalName,
                                 const TDesC8& aQName,
                                 const RAttributeArray& aAttributes,
                                 CSenElement& aParent);

        /**
        * By default Symbian 2nd phase constructor is private.
        * @since Series60 3.0
        * @param aCredential is the source credential to be copied.
        */
        IMPORT_C void ConstructL(CSenCredential& aCredential);

        // New functions

        /**
        * Setter for Credential ID
        * @since Series60 3.0
        * @param aId is the unique ID for this Credential
        */
        void SetIdL(const TDesC8& aId);

    private: // Data
        // Unique ID for this credential. Owned.
        HBufC8* iId;
        // One may use SenDateUtils to convert from XML date descrtor to TTime
        TTime iNotOnOrAfter;    
    };

#endif // SEN_CREDENTIAL_H

// End of File


