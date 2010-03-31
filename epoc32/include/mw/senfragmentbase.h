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
* Description:        Class implements XML base fragment using libxml2 classes
*
*/









#ifndef SEN_FRAGMENT_BASE_H
#define SEN_FRAGMENT_BASE_H

// INCLUDES
#include <s32mem.h>

#include <xml/contenthandler.h>
#include <RSenDocument.h>
#include <SenParser.h>
#include <xmlengelement.h>

using namespace Xml;

// CONSTANTS

// Fragment's internal states.
const TInt KSenStateNotSet      = -1;
const TInt KSenStateIgnore      =  0;
const TInt KSenStateSave        =  1;
const TInt KSenStateResume      =  2;
const TInt KSenStateDelegate    =  3;

// FORWARD DECLARATIONS
class RWriteStream;
//class CSenParser;
class CSenNamespaceData;

// CLASS DECLARATION

/**
* Class implements basic functionality of an XML fragment
* Typically base fragment is used to parse certain part of some XML document.
* The element is identified by local name (or qualified name) and namespace.
* All child elements between start tag and and end tag defined this fragment
* will become content of this BaseFragment. In other words, BaseFragment has
* all data inside a single element.
* BaseFragment will parse only namespace (xmlns) attributes from a document
* and rest of the attributes are to be handled by subclasses, which should
* overwrite SetAttributesL() method to achieve this.
* The CSenFragmentReader class will do the actual parsing and this class will
* act as content handler for XML parser SAX events.
* @lib SenFragment.dll
* @since Series60 4.0
*/
class CSenFragmentBase : public CBase, public MContentHandler
    {
    friend class CSenParserImpl;
    
    public:  // Constructors and destructor
        
        /**
         *  Standard 2 phase constructor.
         *  @since Series60 4.0
         *  @param aElement is the element where construction 
         *                  data will be copied from.
         */
        IMPORT_C static CSenFragmentBase* NewL(const TXmlEngElement& aElement);

        /**
         *  Standard 2 phase constructor.
         *  @since Series60 4.0
         *  @param aLocalName: is the XML localname for this fragment
         */
        IMPORT_C static CSenFragmentBase* NewL(const TDesC8& aLocalName);

        /**
         *  Standard 2 phase constructor.
         *  @since Series60 4.0
         *  @param aNsUri:  XML namespace URI
         *  @param aLocalName:  XML localname
         */
        IMPORT_C static CSenFragmentBase* NewL(const TDesC8& aNsUri,
                                               const TDesC8& aLocalName);

        /**
         *  Standard 2 phase constructor.
         *  @since Series60 4.0
         *  @param aNsUri       XML namespace URI
         *  @param aLocalName   XML localname
         *  @param aPrefix      XML prefix
         */
        IMPORT_C static CSenFragmentBase* NewL(const TDesC8& aNsUri,
                                               const TDesC8& aLocalName,
                                               const TDesC8& aPrefix);

        /**
         * Standard 2 phase constructor.
         * @since Series60 4.0
         * @param aNsUri        XML namespace URI
         * @param aLocalName    XML localname
         * @param aPrefix       XML prefix
         * @param apAttrs       XML attributes
         */
         IMPORT_C static CSenFragmentBase* NewL(const TDesC8& aNsUri,
                                                const TDesC8& aLocalName,
                                                const TDesC8& aPrefix,
                                                const RAttributeArray& apAttrs);

        /**
         *  Standard 2 phase constructor.
         *  @param aParent  Element to be set as fragment's parent element.
         *  @since Series60 4.0
         *  @param aNsUri       XML namespace URI
         *  @param aLocalName   XML localname
         *  @param aPrefix      XML prefix
         *  @param apAttrs      XML attributes
         *  @param aParent      Parent element
         */
        IMPORT_C static CSenFragmentBase* NewL(const TDesC8& aNsUri,
                                               const TDesC8& aLocalName,
                                               const TDesC8& aPrefix,
                                               const RAttributeArray& apAttrs,
                                               TXmlEngElement& aParent);

        /**
         *  Standard 2 phase constructor.
         *  @param aParent  Element to be set as fragment's parent element.
         *  @since Series60 4.0
         *  @param aNsUri           XML namespace URI
         *  @param aLocalName       XML localname
         *  @param aPrefix          XML prefix
         *  @param apAttrs          XML attributes
         *  @param aParent          Parent element
         *  @param aOwnerDocument   The document which will be the owner of
         *                          the elements of this fragment
         */
        IMPORT_C static CSenFragmentBase* NewL(const TDesC8& aNsUri,
                                               const TDesC8& aLocalName,
                                               const TDesC8& aPrefix,
                                               const RAttributeArray& apAttrs,
                                               TXmlEngElement& aParent,
                                               RSenDocument& aOwnerDocument);

        /**
         *  Standard 2 phase constructor.
         *  @param aParent  Element to be set as fragment's parent element.
         *  @since Series60 4.0
         *  @param aRootElement     The element which will be the root element
         *                          of this fragment.
         *  @param aOwnerDocument   The document which will be the owner of
         *                          the elements of this fragment
         */
        IMPORT_C static CSenFragmentBase* NewL(TXmlEngElement& aRootElement,
                                               RSenDocument& aOwnerDocument);

        /**
         * Destructor.
         */
        IMPORT_C virtual ~CSenFragmentBase();

        // Functions from base classes
        
        // From MContentHandler:
        
        /**
         * Callback function implementing the XML content handler interface.
         * Inheriting classes can override these.
         * @since Series60 3.1
         * @see MContentHandler
         */
    	IMPORT_C virtual void OnStartElementL(const RTagInfo& aElement, const RAttributeArray& aAttributes, TInt aErrorCode);

        /**
         * Callback function implementing the XML content handler interface.
         * Inheriting classes can override these.
         * @since Series60 3.1
         * @see MContentHandler
         */
        IMPORT_C virtual void OnEndElementL(const RTagInfo& aElement, TInt aErrorCode);

        /**
         * Callback function implementing the XML content handler interface.
         * Inheriting classes can override these.
         * @since Series60 3.1
         * @see MContentHandler
         */
    	IMPORT_C virtual void OnStartDocumentL(const RDocumentParameters& aDocParam, TInt aErrorCode);

        /**
         * Callback function implementing the XML content handler interface.
         * Inheriting classes can override these.
         * @since Series60 3.1
         * @see MContentHandler
         */
    	IMPORT_C virtual void OnEndDocumentL(TInt aErrorCode);

        /**
         * Callback function implementing the XML content handler interface.
         * Inheriting classes can override these.
         * @since Series60 3.1
         * @see MContentHandler
         */
    	IMPORT_C virtual void OnContentL(const TDesC8& aBytes, TInt aErrorCode);

        /**
         * Callback function implementing the XML content handler interface.
         * Inheriting classes can override these.
         * @since Series60 3.1
         * @see MContentHandler
         */
    	IMPORT_C virtual void OnStartPrefixMappingL(const RString& aPrefix, const RString& aUri, TInt aErrorCode);

        /**
         * Callback function implementing the XML content handler interface.
         * Inheriting classes can override these.
         * @since Series60 3.1
         * @see MContentHandler
         */
    	IMPORT_C virtual void OnEndPrefixMappingL(const RString& aPrefix, TInt aErrorCode);

        /**
         * Callback function implementing the XML content handler interface.
         * Inheriting classes can override these.
         * @since Series60 3.1
         * @see MContentHandler
         */
    	IMPORT_C virtual void OnIgnorableWhiteSpaceL(const TDesC8& aBytes, TInt ErrorCode);

        /**
         * Callback function implementing the XML content handler interface.
         * Inheriting classes can override these.
         * @since Series60 3.1
         * @see MContentHandler
         */
    	IMPORT_C virtual void OnSkippedEntityL(const RString& aName, TInt aErrorCode);

        /**
         * Callback function implementing the XML content handler interface.
         * Inheriting classes can override these.
         * @since Series60 3.1
         * @see MContentHandler
         */
    	IMPORT_C virtual void OnProcessingInstructionL(const TDesC8& aTarget, const TDesC8& aData, TInt aErrorCode);

        /**
         * Callback function implementing the XML content handler interface.
         * Inheriting classes can override these.
         * @since Series60 3.1
         * @see MContentHandler
         */
    	IMPORT_C virtual void OnError(TInt aErrorCode);

        /**
         * Callback function implementing the XML content handler interface.
         * Inheriting classes can override these.
         * @since Series60 3.1
         * @see MContentHandler
         */
    	IMPORT_C virtual TAny* GetExtendedInterface(const TInt32 aUid);

        // New functions
    
        /**
         * Getter for the content,which is returned as UTF-8 form XML.
         * @since Series60 4.0
         * @return content as UTF-8 form XML.
         */
        IMPORT_C virtual TPtrC8 ContentL();
        
        /**
         * Gets the namespace object with a given prefix.
         * @since Series60 4.0
         * @param   aPrefix:    prefix that wanted namespace should have.
         * @return namespace with the given prefix. If not found or given prefix
         * is zero length, will return NULL.
         */
        IMPORT_C virtual TXmlEngNamespace Namespace(const TDesC8& aPrefix);
        
        /**
         * @since Series60 4.0
         * @return Detaches this fragment from its owner. All namespace
         * references from possible parent fragments are declared in
         * the scope of this fragment prior detaching.
         */
//        IMPORT_C virtual void DetachL();
        
        /**
         * Resets the content of the fragment, and resets the namespaces.
         * @since Series60 4.0
         */
        IMPORT_C virtual void ResetContentL();

        /** 
         * @since Series60 4.0
         * @return the localname of this fragment as UTF-8 form descriptor
         */
        IMPORT_C virtual TPtrC8 LocalName() const;
        
        /**
         * Getter for Fragment's namespace URI..
         * @since Series60 4.0
         * @return Namespace URI or KNullDesC if not set.
         */
        IMPORT_C virtual TPtrC8 NsUri() const;

        /**
         * Getter for namespace prefix of this fragment.
         * @since Series60 4.0
         * @return namespace prefix or KNullDesC if not set.
         */
        IMPORT_C virtual TPtrC8 NsPrefix() const;    

        /**
        * Returns the current XML element of this fragment. If element
        * has not been set, this method will initialize new, un-initialized
        * element.
        * Method leaves with if there is not enough memory (OOM)
        * @return reference to the element of this fragment
        */
        IMPORT_C virtual TXmlEngElement AsElementL();

        /**
        * Returns the current XML element of this fragment. If element
        * has not been set, this method will initialize new, un-initialized
        * element.
        * Method leaves with if there is not enough memory (OOM)
        * @return reference to the element of this fragment
        */
        IMPORT_C virtual RSenDocument& AsDocumentL();

        /**
         * Etracts the XML element from the fragment, leaving the fragment empty.
         * Note(!): the return value (CSenElement) STRONGLY suggests that
         * subclasses INHERIT CSenFragment in order properly comply the
         * requirement of the ExtractElement() implementation.
         * @since Series60 4.0
         * @return the current object as element. May return NULL.
         * Ownership IS TRANSFERRED to the caller.
         */
        IMPORT_C virtual TXmlEngElement ExtractElement();
        
        /**
         * Let the delegate MSenFragment handle the following SAX events.
         * This fragment is made the owner of the delegate and the delegate
         * is expected to make this MSenFragment the receiver of SAX events
         * once it has seen the end element for itself.
         * @since Series60 4.0
         * @param aDelegate is the fragment to start handling the SAX events.
         */
        IMPORT_C virtual void OnDelegateParsingL(CSenFragmentBase& aDelegate);

        /**
         * Creates a new fragment and lets the created MSenFragment handle the 
         * following SAX events. This fragment is made the owner of the delegate
         * and the delegate is expected to make this MSenFragment act as receiver
         * for SAX events (callbacks) once it has seen the end element for itself.
         * @since Series60 4.0
         * @param aElement      The RTagInfo class holding information that
         *                      describes the element.
         * @param aAttributes   The attributes of the new element
         * @param aErrorCode    Error code
         */
        IMPORT_C virtual void OnDelegateParsingL(const RTagInfo& aElement, 
                                                 const RAttributeArray& aAttributes, 
                                                 TInt aErrorCode);
        
        /**
         * Sets a new parent for this fragment.
         * @since Series60 4.0
         * @param aFragment:    the new parent.
         */
        IMPORT_C virtual void SetOwner(CSenFragmentBase& aFragment);

        /**
         * Leave codes: 
         * Resumes parsing to be handled by this fragment. Usually called by some
         * delegate fragment which was set to be content handler because this
         * fragment called DelegateParsingL().
         * @since Series60 4.0
         * @param aElement      The RTagInfo class holding information that
         *                      describes the element.
         * @param aErrorCode    Error code
         */
        IMPORT_C virtual void OnResumeParsingFromL(const RTagInfo& aElement, TInt aErrorCode);

        /**
         * Sets the attributes for the fragment. BaseFragment parses only
         * namespace (xmlns) attributes from the document.
         * Subclasses should override this method if they are intrested
         * of handling any other XML attributes and their corresponding
         * values.
         * @since Series60 4.0
         * @param aAttrs:   the array of attributes.
         */
//        IMPORT_C virtual void SetAttributesL(const RAttributeArray& aAttrs);
        
        /**
         * Writes the start element tag to the content stream. 
         * Derivants can override the basic usage used in BaseFragment.
         * @since Series60 4.0
         * @param aElement      The RTagInfo class holding information that
         *                      describes the element.
         * @param aAttributes   The attributes of the new element
         */
        IMPORT_C void OnWriteStartElementL(const RTagInfo& aElement, 
                                           const RAttributeArray& aAttributes);
        
        /**
         * Writes the end element tag to the content stream. 
         * Derivants can override the basic usage used in BaseFragment.
         * @since Series60 4.0
         * @param aElement      The RTagInfo class holding information that
         *                      describes the element.
         */
        IMPORT_C void OnWriteEndElementL(const RTagInfo& aElement);

        /**
         * Gets the fragment data as an unicode XML.
         * @since Series60 4.0
         * @return  fragment as XML. Caller takes ownership.
         */ 
        IMPORT_C virtual HBufC* AsXmlUnicodeL();

        /**
         * Gets the fragment data as an UTF-8 form XML.
         * @since Series60 4.0
         * @return  fragment as XML. Caller takes ownership.
         */ 
        IMPORT_C virtual HBufC8* AsXmlL();

        /**
         * Invokes AsElement().WriteAsXMLToL(aWs);
         * @since Series60 4.0
         * @param aWs is the stream into which the UTF-8 form XML will
         *            be written.
         */
        IMPORT_C virtual void WriteAsXMLToL(RWriteStream& aWs);

        /**
         * Checks if fragment matches to another fragment 
         * by its content and child elements. 
         * Fragment can contain more data than the given candidate.
         * @since Series60 4.0
         * @param aCandidate    The pattern to be matched. Must contain same or 
         *                      less data for match to come true.
         * @return ETrue if content and possible children match exactly 
         *               to given pattern. EFalse otherwise.
         */
        IMPORT_C virtual TBool ConsistsOfL(CSenFragmentBase& aCandidate);
        
        //From SenParserImpl.h
        IMPORT_C void SetContentHandler(CSenFragmentBase& aContentHandler);
        
        /**
        * Sets the RSenDocument
        * @param aDocument
        */
        IMPORT_C void SetDocument(RSenDocument& aDocument);

    protected:  
        
        /**
        * C++ default constructor.
        */
        IMPORT_C CSenFragmentBase();        
        
        /**
         * Following BaseConstructL methods should be called from ConstructL() 
         * methods of some deriving (fragment) class.
         */

        /**
        * BaseConstructL, where an element is given as initializer.
        * @since Series60 4.0
        * @param aElement from which this fragment will be constructed from.
        */
        IMPORT_C void BaseConstructL(const TXmlEngElement& aSrc);
        
        /**
        * BaseConstructL setting XML localname for this fragment.
        * @since Series60 4.0
        * @param aLocalName XML localname for this fragment
        */
        IMPORT_C void BaseConstructL(const TDesC8& aLocalName);

        /**
        * BaseConstructL offering possibility to set XML namespace and localname.
        * @since Series60 4.0
        * @param aNsUri XML namespace URI for this fragment
        * @param aLocalName XML localname for this fragment
        */
        IMPORT_C void BaseConstructL(const TDesC8& aNsUri,
                                     const TDesC8& aLocalName);

        /**
        * Base constructor
        * @since Series60 4.0
        * @param aNsUri XML namespace URI for this fragment
        * @param aLocalName XML localname for this fragment
        * @param aQName XML qualifiedname for this fragment
        */
        IMPORT_C void BaseConstructL(const TDesC8& aNsUri,
                                     const TDesC8& aLocalName,
                                     const TDesC8& aPrefix);
        /**
        * Base constructor
        * @since Series60 4.0
        * @param aNsUri XML namespace URI for this fragment
        * @param aLocalName XML localname for this fragment
        * @param aQName XML qualifiedname for this fragment
        * @param aAttrs XML attributes for this fragment
        */
        IMPORT_C void BaseConstructL(const TDesC8& aNsUri,
                                     const TDesC8& aLocalName,
                                     const TDesC8& aPrefix,
                                     const RAttributeArray& aAttrs);

        /**
        * Base constructor
        * @since Series60 4.0
        * @param aNsUri XML namespace URI for this fragment
        * @param aLocalName XML localname for this fragment
        * @param aQName XML qualifiedname for this fragment
        * @param aAttrs XML attributes for this fragment
        * @param aParent parent to be set for this fragmemt
        */
        IMPORT_C void BaseConstructL(const TDesC8& aNsUri,
                                     const TDesC8& aLocalName,
                                     const TDesC8& aPrefix,
                                     const RAttributeArray& aAttrs,
                                     TXmlEngElement& aParent);

        /**
        * Base constructor
        * @since Series60 4.0
        * @param aNsUri         XML namespace URI for this fragment
        * @param aLocalName     XML localname for this fragment
        * @param aQName         XML qualifiedname for this fragment
        * @param aAttrs         XML attributes for this fragment
        * @param aParent        Parent to be set for this fragmemt
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
        * Base constructor
        * @since Series60 4.0
        * @param aRootElement   The element which will be the root element
        *                       of this fragment
        * @param aOwnerDocument The document which will be the owner of
        *                       the elements of this fragment
        */
        IMPORT_C void BaseConstructL(TXmlEngElement& aRootElement,
                                     RSenDocument& aOwnerDocument);
        
        // New functions

        /**
        *  Adds new XML attributes to this fragment.
        *  Can be overridden to replace old attributes.
        *  @param  aAttrs: the array of attributes.
        */
        IMPORT_C virtual void AddAttributesL(const RAttributeArray& apAttrs);

        /**
        *  Adds new XML attributes to specified element.
        *  Can be overridden to replace old attributes.
        *  @param  aAttrs: the array of attributes.
        */
        IMPORT_C virtual void AddAttributesToElementL(TXmlEngElement element,
                                         const RAttributeArray& apAttrs);
        
        /** 
        * Method renames the XML properties of this fragment.
        * @param aLocalName XML localname for this fragment
        * @param aPrefix XML namespace prefix for this fragment
        * @param aNamespace XML namespace URI for this fragment
        * Method leaves with if there is not enough memory (OOM)
        */
        void RenameL(const TDesC8& aLocalName, const TDesC8& aPrefix, const TDesC8& aNamespace);

        /** 
        * Method renames the XML properties of this fragment.
        * @param aLocalName XML localname for this fragment
        * @param aNamespace XML namespace URI for this fragment
        * Method leaves with if there is not enough memory (OOM)
        */
        void RenameL(const TDesC8& aLocalName, const TDesC8& aNamespace);

        /** 
        * Renames local name for this XML fragment.
        * @param aLocalName XML localname for this fragment
        * Method leaves with if there is not enough memory (OOM)
        */
        void RenameLocalNameL(const TDesC8& aLocalName);

        /** 
        * Renames namespace URI for this XML fragment.
        * @param aNamespace XML namespace URI for this fragment
        * Method leaves with if there is not enough memory(OOM)
        */
        void RenameNamespaceL(const TDesC8& aNamespace);

        /** 
        * Renames namespace prefix for this XML fragment.
        * @param aPrefix XML namespace prefix for this fragment
        * Method leaves with if there is not enough memory (OOM)
        */
        void RenamePrefixL(const TDesC8& aPrefix);

        /** 
        * Renames namespace prefix and namespace URI for this XML fragment.
        * @param aPrefix XML namespace prefix for this fragment
        * @param aNamespace XML namespace URI for this fragment
        * Method leaves with if there is not enough memory (OOM)
        */
        void RenameNamespaceL(const TDesC8& aPrefix, const TDesC8& aNamespace);
         
        /**
         * Sets content to a child element. If no element with given local name
         * is not found, new one is added and content is set to that one.
         * @since Series60 4.0
         * @param aLocalName    The local name of element which content
         *                      is about to be set
         * @param aContent      Content to be set.
         * @return              the element where content was set.
         * Leave codes: 
         *      KErrSenInvalidCharacters if aLocalName contains illegal characters.     
         *      KErrSenZeroLengthDescriptor if aLocalName is zero length.
         */
        IMPORT_C TXmlEngElement SetContentOfL(const TDesC8& aLocalName,
                                              const TDesC8& aContent);
        /**
         * Gets the content of a given element.
         * @since Series60 4.0
         * @param aLocalName    The local name of the element which content is 
         *                      asked
         * @return  the content which was asked
         */
        IMPORT_C TPtrC8 ContentOf(const TDesC8& aLocalName);        

        IMPORT_C virtual TBool ConsistsOfL(TXmlEngElement& aElement, TXmlEngElement& aCandidate);
        
        /**
        * Adds namespaces from internal array for the fragment.
        * @since Series60 4.0
        */
        IMPORT_C virtual void AddNamespacesL();
        
        /**
         * Sets content to a child element. If no element with given local name
         * is not found, new one is added and content is set to that one.
         * @since Series60 4.0
         * @param aContent      Content to be set.
         */        
        IMPORT_C virtual void SetContentL(const TDesC8& aContent);
        
        /**
         * Adds the content. 
         * @since Series60 4.0
         * @param aContent      Content to be set.
         */                
        IMPORT_C virtual void AddContentL(const TDesC8& aContent);        
        
        /**
        * StartSavingContent changes the internal SAX parsing state of
        * this fragment to KSenStateSave, which means that next call
        * to OnStartElementL is treated as data, and not ignored
        * (in DOM fragment implementation, it would be "extended"
        * into a DOM object).
        */        
        IMPORT_C void StartSavingContent();

        
    private: // New functions
    
        /**
         * Sets the XML parser to be used for parsing for the fragment.
         * @since Series60 4.0
         * @param aReader:      the reader to be used. 
         *                      Ownership is NOT transferred.
         */ 
        IMPORT_C virtual void SetParser(CSenParser& aParser);

    protected: // Data

        // State variable indicating what this fragment
        // is currently parsing. Even states (like 0)
        // mean that this fragment is ignoring the
        // data, and odd states indicate, that fragment
        // is storing the data into itself.
        TInt                                iState;

        // Owned element containing this XML fragment data.
        TXmlEngElement                      iElement;
        
        // Owned document representing this XML fragment
        RSenDocument                        iDocument;
        
        // Pointer to XML parser. Not owned.
        CSenParser*                         ipParser;               // Not owned

        // Possible owner fragment, if such exists. Not owned.
        CSenFragmentBase*                   ipOwner;                // Not owned
        CSenFragmentBase*                   ipDelegate;             // Owned
        
        RPointerArray<CSenNamespaceData>*   ipNamespaceArray;       // Owned
        
        CBufFlat*                           ipContentBuf;           // Owned
        RBufWriteStream*                    ipContentWriteStream;   // Owned
    };
    
class CSenNamespaceData : public CBase
    {
    public:
        virtual ~CSenNamespaceData();
    
    public:
        HBufC8* ipLocalName;
        HBufC8* ipNamespaceUri;
        HBufC8* ipPrefix;
    };

#endif //SEN_FRAGMENT_BASE_H

// End of File



