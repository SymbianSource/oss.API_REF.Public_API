/*
* Copyright (c) 2002-2006 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:        Class implements XML DOM fragment using libxml2 classes
*
*/









#ifndef SEN_DOM_FRAGMENT_BASE_H
#define SEN_DOM_FRAGMENT_BASE_H

//  INCLUDES
#include <SenFragmentBase.h>

// FORWARD DECLARATIONS
class RFileLogger;

// CLASS DECLARATION

/**
* Class implements DOM fragment functionality
* The implementation further extends CSenBaseFragment
* functionality. In DOM fragment, all child elements
* are parsed into separate element objects. This makes
* it possible to reference any child which offer methods
* declared in XML element interface. Any such element
* can also be easily extracted (detached) from this
* root DOM fragment.
* @lib SenFragment.dll
* @since Series60 4.0
*/
class CSenDomFragmentBase : public CSenFragmentBase
    {
    public:  // Constructors and destructor
        
        /**
        * Basic contructor. Should be used only for parsing new fragments etc. 
        * Constructing DomFragments for other use should be done with at least 
        * localname parameter.
        * @since Series60 4.0
        */
        IMPORT_C static CSenDomFragmentBase* NewL();

        /**
        * Basic constructor.
        * @since Series60 4.0
        * @param aElement Element to copy construction data from.
        */
        IMPORT_C static CSenDomFragmentBase* NewL(
            const TXmlEngElement& aElement);

        /**
        * Basic constructor.
        * @since Series60 4.0
        * @param aLocalName is the XML localname of this fragment
        */
        IMPORT_C static CSenDomFragmentBase* NewL(const TDesC8& aLocalName);

        /**
        * Basic constructor.
        * @since Series60 4.0
        * @param aNsUri     is the XML namespace user of this fragment
        * @param aLocalName is the XML localname of this fragment
        */
        IMPORT_C static CSenDomFragmentBase* NewL(const TDesC8& aNsUri,
                                              const TDesC8& aLocalName);

        /**
        * Basic constructor.
        * @since Series60 4.0
        * @param aNsUri     is the XML namespace user of this fragment
        * @param aLocalName is the XML localname of this fragment
        * @param aPrefix    is the XML prefix of this fragment
        */
        IMPORT_C static CSenDomFragmentBase* NewL(const TDesC8& aNsUri,
                                              const TDesC8& aLocalName,
                                              const TDesC8& aPrefix);

        /**
        * Basic constructor.
        * @since Series60 4.0
        * @param aNsUri     is the XML namespace of this fragment
        * @param aLocalName is the XML localname of this fragment
        * @param aPrefix    is the prefix of this fragment
        * @param aAttrs     are the XML attributes of this fragment
        */
        IMPORT_C static CSenDomFragmentBase* NewL(const TDesC8& aNsUri,
                                              const TDesC8& aLocalName,
                                              const TDesC8& aPrefix,
                                              const RAttributeArray& aAttrs);

        /**
        * Basic constructor.
        * @since Series60 4.0
        * @param aNsUri     is the XML namespace of this fragment
        * @param aLocalName is the XML localname of this fragment
        * @param aPrefix    is the prefix of this fragment
        * @param aAttrs     are the XML attributes of this fragment
        * @param aParent    is the parent XML element of this fragment
        */
        IMPORT_C static CSenDomFragmentBase* NewL(const TDesC8& aNsUri,
                                              const TDesC8& aLocalName,
                                              const TDesC8& aPrefix,
                                              const RAttributeArray& aAttrs,
                                              TXmlEngElement& aParent);

        /**
        * Basic constructor.
        * @since Series60 4.0
        * @param aNsUri         is the XML namespace of this fragment
        * @param aLocalName     is the XML localname of this fragment
        * @param aPrefix        is the prefix of this fragment
        * @param aAttrs         are the XML attributes of this fragment
        * @param aParent        is the parent XML element of this fragment
        * @param aOwnerDocument is the document which will be the owner of
        *                       the elements of this fragment
        */
        IMPORT_C static CSenDomFragmentBase* NewL(const TDesC8& aNsUri,
                                              const TDesC8& aLocalName,
                                              const TDesC8& aPrefix,
                                              const RAttributeArray& aAttrs,
                                              TXmlEngElement& aParent,
                                              RSenDocument& aOwnerDocument);
        /**
        * Destructor.
        */
        IMPORT_C virtual ~CSenDomFragmentBase();

        // New functions
    
        /**
        * Initiates the parsing chain where new delegate will be created with
        * given parameters and parsing will be delegated to it. Should not be
        * called externally.
        * @since Series60 4.0
        * @param aElement     The RTagInfo class holding information that describes
        *                     the element.
        * @param aAttributes  The attributes of the new element
        * @param aErrorCode   Error code
        */
        IMPORT_C virtual void ExpandL(const RTagInfo& aElement,
                                      const RAttributeArray& aAttributes,
                                      TInt aErrorCode);
                                      
        // Functions from base classes

        // From CSenBaseFragment
        
        /**
        * Resumes the parsing. Usually called by the delegate fragment which was
        *                      parsing itself after DelegateParsingL().
        * @since Series60 4.0
        * @param aElement     The RTagInfo class holding information that describes
        *                     the element.
        * @param aErrorCode   Error code
        */
        IMPORT_C virtual void OnResumeParsingFromL(const RTagInfo& aElement,
                                           TInt aErrorCode);

        /**
        * Sets the attributes for the fragment.
        * @since Series60 4.0
        * @param aAttributes    The array of attributes.
        */
        IMPORT_C virtual void AddAttributesL(const RAttributeArray& aAttrs);
        
        /**
         * Gets the fragment data as an UTF-8 form XML.
         * @since Series60 4.0
         * @return  fragment as XML. Caller takes ownership.
         */ 
        IMPORT_C virtual HBufC8* AsXmlL();
        
        /**
         * Callback function implementing the XML content handler interface.
         * Inheriting classes can override these.
         * @since Series60 4.0
         * @see MContentHandler
         */
    	IMPORT_C virtual void OnStartElementL(const RTagInfo& aElement,
    	                                      const RAttributeArray& aAttributes,
    	                                      TInt aErrorCode);

        /**
         * Callback function implementing the XML content handler interface.
         * Inheriting classes can override these.
         * @since Series60 4.0
         * @see MContentHandler
         */
        IMPORT_C virtual void OnContentL(const TDesC8& aBytes,
                                         TInt aErrorCode);
        
        /**
         * Overriding content writing from CSenBaseFragment to do nothing in
         * DOM fragment (because the tree is expanded).
         * @since Series60 4.0
         * @param aElement      The RTagInfo class holding information that
         *                      describes the element.
         * @param aAttributes   The attributes of the new element
         */
        IMPORT_C void OnWriteStartElementL(const RTagInfo& aElement, 
                                           const RAttributeArray& aAttributes);

        /**
         * Overriding content writing from CSenBaseFragment to do nothing in
         * DOM fragment (because the tree is expanded).
         * @since Series60 4.0
         * @param aElement      The RTagInfo class holding information that
         *                      describes the element.
         */
        IMPORT_C void OnWriteEndElementL(const RTagInfo& aElement);        
        /**
         * Callback function implementing the XML content handler interface.
         * Inheriting classes can override these.
         * @since Series60 4.0
         * @see MContentHandler
         */
        IMPORT_C virtual void OnEndElementL(const RTagInfo& aElement, TInt aErrorCode);

        /**
         * Callback function implementing the XML content handler interface.
         * Inheriting classes can override these.
         * @since Series60 4.0
         * @see MContentHandler
         */
    	IMPORT_C virtual void OnStartDocumentL(const RDocumentParameters& aDocParam, TInt aErrorCode);

        /**
         * Callback function implementing the XML content handler interface.
         * Inheriting classes can override these.
         * @since Series60 4.0
         * @see MContentHandler
         */
    	IMPORT_C virtual void OnEndDocumentL(TInt aErrorCode);

        /**
         * Callback function implementing the XML content handler interface.
         * Inheriting classes can override these.
         * @since Series60 4.0
         * @see MContentHandler
         */
    	IMPORT_C virtual void OnStartPrefixMappingL(const RString& aPrefix, const RString& aUri, TInt aErrorCode);

        /**
         * Callback function implementing the XML content handler interface.
         * Inheriting classes can override these.
         * @since Series60 4.0
         * @see MContentHandler
         */
    	IMPORT_C virtual void OnEndPrefixMappingL(const RString& aPrefix, TInt aErrorCode);

        /**
         * Callback function implementing the XML content handler interface.
         * Inheriting classes can override these.
         * @since Series60 4.0
         * @see MContentHandler
         */
    	IMPORT_C virtual void OnIgnorableWhiteSpaceL(const TDesC8& aBytes, TInt ErrorCode);

        /**
         * Callback function implementing the XML content handler interface.
         * Inheriting classes can override these.
         * @since Series60 4.0
         * @see MContentHandler
         */
    	IMPORT_C virtual void OnSkippedEntityL(const RString& aName, TInt aErrorCode);

        /**
         * Callback function implementing the XML content handler interface.
         * Inheriting classes can override these.
         * @since Series60 4.0
         * @see MContentHandler
         */
    	IMPORT_C virtual void OnProcessingInstructionL(const TDesC8& aTarget, const TDesC8& aData, TInt aErrorCode);

        /**
         * Callback function implementing the XML content handler interface.
         * Inheriting classes can override these.
         * @since Series60 4.0
         * @see MContentHandler
         */
    	IMPORT_C virtual void OnError(TInt aErrorCode);

        /**
         * Callback function implementing the XML content handler interface.
         * Inheriting classes can override these.
         * @since Series60 4.0
         * @see MContentHandler
         */
    	IMPORT_C virtual TAny* GetExtendedInterface(const TInt32 aUid);

        // From CSenBaseFragment
        IMPORT_C virtual TPtrC8 ContentL();
        
        IMPORT_C virtual TXmlEngNamespace Namespace(const TDesC8& aPrefix);
        
//        IMPORT_C virtual void DetachL();
        
        IMPORT_C virtual void ResetContentL();

        IMPORT_C virtual TPtrC8 LocalName() const;
        
        IMPORT_C virtual TPtrC8 NsUri() const;

        IMPORT_C virtual TPtrC8 NsPrefix() const;    

        IMPORT_C virtual TXmlEngElement AsElementL();

        IMPORT_C virtual RSenDocument& AsDocumentL();

        IMPORT_C virtual TXmlEngElement ExtractElement();
        
        IMPORT_C virtual void OnDelegateParsingL(CSenFragmentBase& aDelegate);

        IMPORT_C virtual void OnDelegateParsingL(const RTagInfo& aElement, 
                                                 const RAttributeArray& aAttributes, 
                                                 TInt aErrorCode);
        
        IMPORT_C virtual void SetOwner(CSenFragmentBase& aFragment);

        IMPORT_C virtual HBufC* AsXmlUnicodeL();

        IMPORT_C virtual void WriteAsXMLToL(RWriteStream& aWs);

        IMPORT_C virtual TBool ConsistsOfL(CSenFragmentBase& aCandidate);
        
        IMPORT_C void SetContentHandler(CSenFragmentBase& aContentHandler);
        
    protected: // From CSenBaseFragment
    
        void RenameL(const TDesC8& aLocalName, const TDesC8& aPrefix, const TDesC8& aNamespace);

        void RenameL(const TDesC8& aLocalName, const TDesC8& aNamespace);

        void RenameLocalNameL(const TDesC8& aLocalName);

        void RenameNamespaceL(const TDesC8& aNamespace);

        void RenamePrefixL(const TDesC8& aPrefix);

        void RenameNamespaceL(const TDesC8& aPrefix, const TDesC8& aNamespace);
         
        IMPORT_C TXmlEngElement SetContentOfL(const TDesC8& aLocalName,
                                        const TDesC8& aContent);

        IMPORT_C TPtrC8 ContentOf(const TDesC8& aLocalName);        

        IMPORT_C virtual TBool ConsistsOfL(TXmlEngElement& aElement, TXmlEngElement& aCandidate);

        IMPORT_C virtual void AddNamespacesL();

    protected:  
        
        /**
        * C++ default constructor.
        */
        IMPORT_C CSenDomFragmentBase();

        /**
        * "ConstructL" method for calling the base classes ones.
        * @since Series60 4.0
        */
        IMPORT_C void BaseConstructL();

        /**
        * "ConstructL" method for calling the base classes ones.
        * @since Series60 4.0
        * @param aElement is the XML element of this fragment.
        */
        IMPORT_C void BaseConstructL(const TXmlEngElement& aElement);

        /**
        * "ConstructL" method for calling the base classes ones.
        * @since Series60 4.0
        * @param aLocalName The local name of the element
        */
        IMPORT_C void BaseConstructL(const TDesC8& aLocalName);

        /**
        * "ConstructL" method for calling the base classes ones.
        * @since Series60 4.0
        * @param aNsUri     The namespace URI of the element
        * @param aLocalName The local name of the element
        */
        IMPORT_C void BaseConstructL(const TDesC8& aNsUri,
                                     const TDesC8& aLocalName);

        /**
        * "ConstructL" method for calling the base classes ones.
        * @since Series60 4.0
        * @param aNsUri     The namespace URI of the element
        * @param aLocalName The local name of the element
        * @param aPrefix    The prefix of the element
        */
        IMPORT_C void BaseConstructL(const TDesC8& aNsUri,
                                     const TDesC8& aLocalName,
                                     const TDesC8& aPrefix);

        /**
        * "ConstructL" method for calling the base classes ones.
        * @since Series60 4.0
        * @param aNsUri     The namespace URI of the element
        * @param aLocalName The local name of the element
        * @param aPrefix    The prefix of the element
        * @param aAttrs     The attributes of the element
        */
        IMPORT_C void BaseConstructL(const TDesC8& aNsUri,
                                     const TDesC8& aLocalName,
                                     const TDesC8& aPrefix,
                                     const RAttributeArray& aAttrs);

        /**
        * "ConstructL" method for calling the base classes ones.
        * @since Series60 4.0
        * @param aNsUri     The namespace URI of the element
        * @param aLocalName The local name of the element
        * @param aPrefix    The prefix of the element
        * @param aAttrs     The attributes of the element
        * @param aParent    The parent of the element
        */
        IMPORT_C void BaseConstructL(const TDesC8& aNsUri,
                                     const TDesC8& aLocalName,
                                     const TDesC8& aPrefix,
                                     const RAttributeArray& aAttrs,
                                     TXmlEngElement& aParent);
                                     
        /**
        * "ConstructL" method for calling the base classes ones.
        * @since Series60 4.0
        * @param aNsUri         The namespace URI of the element
        * @param aLocalName     The local name of the element
        * @param aPrefix        The prefix of the element
        * @param aAttrs         The attributes of the element
        * @param aParent        The parent of the element
        * @param aOwnerDocument The document which will be the owner of
        *                       the elements of this fragment
        */
        IMPORT_C void BaseConstructL(const TDesC8& aNsUri,
                                     const TDesC8& aLocalName,
                                     const TDesC8& aPrefix,
                                     const RAttributeArray& aAttrs,
                                     TXmlEngElement& aParent,
                                     RSenDocument& aOwnerDocument);

        /**
         *  Callback functions which implement the XML content handler interface.
         *  Inheriting classes can override these.
         */
         
        // From CSenBaseFragment 
                                       
    protected: // Data
        CSenDomFragmentBase* ipDomDelegate;
    };

#endif //SEN_DOM_FRAGMENT_BASE_H

// End of File



