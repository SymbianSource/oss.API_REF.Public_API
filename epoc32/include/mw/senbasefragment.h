/*
* Copyright (c) 2002-2005 Nokia Corporation and/or its subsidiary(-ies). 
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
* which accompanies this distribution, and is available
* at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:        Class implements basic functionality of an XML fragment
*
*/








#ifndef SEN_BASE_FRAGMENT_H
#define SEN_BASE_FRAGMENT_H

//  INCLUDES
#include <MSenContentHandlerClient.h>
#include <SenElement.h>
#include <SenFragment.h>

// CONSTANTS

// Fragment's internal states.
const TInt KStateNotSet = -1;
const TInt KStateIgnore =  0;
const TInt KStateSave   =  1;
const TInt KStateResume =  2;

// FORWARD DECLARATIONS
class CSenXmlReader;

// CLASS DECLARATION

/**
* Class implements basic functionality of an XML fragment
* Typically BaseFragment is used to parse certain part of some XML document.
* The element is identified by localname (or qualifiedname) and namespace.
* All child elements between start tag and and end tag defined this fragment
* will become content of this BaseFragment. In other words, BaseFragment has
* all data inside a single element.
* BaseFragment will parse only namespace (xmlns) attributes from a document
* and rest of the attributes are to be handled by subclasses, which should
* overwrite SetAttributesL() method to achieve this.
* The CSenXmlReader class will do the actual parsing and this class will
* act as content handler for XML parser SAX events.
* @lib SenXML.dll
* @since Series60 3.0
*/
class CSenBaseFragment : public CSenFragment, public MSenContentHandlerClient 
    {
    public:  // Constructors and destructor
        
        /**
         *  Standard 2 phase constructor.
         *  @since Series60 3.0
         *  @param aElement is the element where construction 
         *                  data will be copied from.
         */
        IMPORT_C static CSenBaseFragment* NewL(const CSenElement& aElement);

        /**
         *  Standard 2 phase constructor.
         *  Leave codes:    
         *      KErrSenInvalidCharacters if aLocalName contains
         *      illegal characters.     
         *      KErrSenZeroLengthDescriptor if aLocalName is zero length.
         *  @since Series60 3.0
         *  @param aLocalName: is the XML localname for this fragment
         */
        IMPORT_C static CSenBaseFragment* NewL(const TDesC8& aLocalName);

        /**
         *  Standard 2 phase constructor.
         *  Leave codes:    
         *      KErrSenInvalidCharacters if aLocalName contains
         *      illegal characters.     
         *      KErrSenZeroLengthDescriptor if aLocalName is zero length.
         *  @since Series60 3.0
         *  @param aNsUri:  XML namespace URI
         *  @param aLocalName:  XML localname
         */
        IMPORT_C static CSenBaseFragment* NewL(const TDesC8& aNsUri,
                                               const TDesC8& aLocalName);

        /**
         *  Standard 2 phase constructor.
         *  Leave codes:    
         *      KErrSenInvalidCharacters if aLocalName or aQName contains
         *      illegal characters.     
         *      KErrSenZeroLengthDescriptor if aLocalName or aQName is zero length.
         *  @since Series60 3.0
         *  @param aNsUri:  XML namespace URI
         *  @param aLocalName:  XML localname
         *  @param aQName:  XML qualifiedname
         */
        IMPORT_C static CSenBaseFragment* NewL(const TDesC8& aNsUri,
                                               const TDesC8& aLocalName,
                                               const TDesC8& aQName);

        /**
         * Standard 2 phase constructor.
         * Leave codes: 
         *      KErrSenInvalidCharacters if aLocalName or aQName contains
         *      illegal characters.     
         *      KErrSenZeroLengthDescriptor if aLocalName or aQName is zero length.
         * @since Series60 3.0
         * @param aNsUri:   XML namespace URI
         * @param aLocalName:   XML localname
         * @param aQName:   XML qualifiedname
         * @param apAttrs:  XML attributes
         */
         IMPORT_C static CSenBaseFragment* NewL(const TDesC8& aNsUri,
                                                const TDesC8& aLocalName,
                                                const TDesC8& aQName,
                                                const RAttributeArray& apAttrs);

        /**
         *  Standard 2 phase constructor.
         *  @param aParent  Element to be set as fragment's parent element.
         *    Leave codes:  
         *          KErrSenInvalidCharacters if aLocalName or aQName contains
         *          illegal characters.     
         *          KErrSenZeroLengthDescriptor if aLocalName or aQName is of
         *      zero length.
         *  @since Series60 3.0
         *  @param aNsUri:  XML namespace URI
         *  @param aLocalName:  XML localname
         *  @param aQName:  XML qualifiedname
         *  @param apAttrs: XML attributes
         *  @param aParent: Parent element
         */
        IMPORT_C static CSenBaseFragment* NewL(const TDesC8& aNsUri,
                                               const TDesC8& aLocalName,
                                               const TDesC8& aQName,
                                               const RAttributeArray& apAttrs,
                                               CSenElement& aParent);

        /**
         * Destructor.
         */
        IMPORT_C virtual ~CSenBaseFragment();


        // New functions
    
        /**
         * Getter for the content,which is returned as UTF-8 form XML.
         * @since Series60 3.0
         * @return content as UTF-8 form XML.
         */
        IMPORT_C virtual TPtrC8 Content();
        /**
         * Gets the namespace object with a given prefix.
         * @since Series60 3.0
         * @param   aPrefix:    prefix that wanted namespace should have.
         * @return namespace with the given prefix. If not found or given prefix
         * is zero length, will return NULL.
         */
        IMPORT_C virtual CSenNamespace* Namespace(const TDesC8& aPrefix);
        
        /**
         * @since Series60 3.0
         * @param aPrefix is the XML namespace prefix
         */
        IMPORT_C virtual void EnsureNamespace(const TDesC8& aPrefix);
        
        /**
         * @since Series60 3.0
         * @return Detaches this fragment from its owner. All namespace
         * references from possible parent fragments are declared in
         * the scope of this fragment prior detaching.
         */
        IMPORT_C virtual void DetachL();
        
        /**
         * @since Series60 3.0
         * @param aAttrs are the attributes from which the namespaces
         *        are searched from.
         * @param aEnsure if set to TRUE, the namespaces are copied into
         *         this fragment. If FALSE, then the namespaces are only
         *         referenced, but not copied and owned by this class.
         */
        IMPORT_C virtual void SaveNamespacesL(const RAttributeArray& aAttrs,
                                              TBool aEnsure);

        /**
         * Resets the content of the fragment, and resets the namespaces.
         * @since Series60 3.0
         */
        IMPORT_C virtual void ResetContentL();

        // Functions from base classes

        // From CSenFragment 
        
        /** 
         * @since Series60 3.0
         * @return the localname of this fragment as UTF-8 form descriptor
         */
        IMPORT_C virtual const TDesC8& LocalName() const;
        
        /**
         * Getter for Fragment's namespace URI..
         * @since Series60 3.0
         * @return Namespace URI or KNullDesC if not set.
         */
        IMPORT_C virtual const TDesC8& NsUri() const;

        /**
         * Getter for namespace prefix of this fragment.
         * @since Series60 3.0
         * @return namespace prefix or KNullDesC if not set.
         */
        IMPORT_C virtual const TDesC8& NsPrefix() const;    

        /**
         * Getting the fragment as an XML element. This method will panic if 
         * element has not been initialized for any reason.
         * @since Series60 3.0
         * @return the current object as element. Ownership is not transferred.
         */
        IMPORT_C virtual CSenElement& AsElement();

        /**
         * Etracts the XML element from the fragment, leaving the fragment empty.
         * Note(!): the return value (CSenElement) STRONGLY suggests that
         * subclasses INHERIT CSenFragment in order properly comply the
         * requirement of the ExtractElement() implementation.
         * @since Series60 3.0
         * @return the current object as element. May return NULL.
         * Ownership IS TRANSFERRED to the caller.
         */
        IMPORT_C virtual CSenElement* ExtractElement();
        
        /**
         * Gets the XML reader which this fragment uses for parsing.
         * @since Series60 3.0
         * @return the XML reader. Ownerships is not transferred,
         * due even this class does not own the XML reader instance.
         */
        IMPORT_C virtual CSenXmlReader* Reader();

        /**
         * Sets the XML reader to be used for parsing for the fragment.
         * @since Series60 3.0
         * @param aReader:      the reader to be used. 
         *                      Ownership is NOT transferred.
         */ 
        IMPORT_C virtual void SetReader(CSenXmlReader& aReader);

        /**
         *  Leave codes:    
         *  KErrSenXmlReaderNotSet  if XML reader has not been set.
         *  Method to invoke parsing of a XML data.
         *  Note that SetReader() must be called before this method can be used.
         *  Note that CSenBaseFragment does not parse any other
         *  attributes, but XML namespace attributes only. This
         *  is due to allow subclasses to process only those attributes
         *  they are interested in, and not others.
         *  @since Series60 3.0
         *  @param aXml:    The data to be parsed.
         */ 
        IMPORT_C virtual void ParseL(const TDesC8& aXml);

        /**
         * Same as ParseL() except that it doesn't leave in case of an error. 
         * Instead errors are trapped and error is returned.
         * SetReader() must be called before this method can be used.
         * @since Series60 3.0
         * @param aXml: The data to be parsed.
         * @return KErrNone or other system-wide Symbian error codes.
         */ 
        IMPORT_C virtual TInt BuildFrom(const TDesC8& aXml);

        /**
         * Leave codes: 
         * KErrSenXmlReaderNotSet   if XML reader has not been set.
         * Let the delegate MSenFragment handle the following SAX events.
         * This fragment is made the owner of the delegate and the delegate
         * is expected to make this MSenFragment the receiver of SAX events
         * once it has seen the end element for itself.
         * @since Series60 3.0
         * @param aDelegate is the fragment to start handling the SAX events.
         */
        IMPORT_C virtual void DelegateParsingL(MSenFragment& aDelegate);

        /**
         * Leave codes: 
         * KErrSenXmlReaderNotSet   if XML reader has not been set.
         * Creates a new fragment and lets the created MSenFragment handle the 
         * following SAX events. This fragment is made the owner of the delegate
         * and the delegate is expected to make this MSenFragment act as receiver
         * for SAX events (callbacks) once it has seen the end element for itself.
         * @since Series60 3.0
         * @param aNsUri    The XML namespace URI for the delegate to be created
         * @param aLocalName    The XML localname for the delegate to be created
         * @param aQName    The XML qualifiedname for the delegate to be created
         * @param aAttrs:   The XML attributes for the delegate to be created
         */
        IMPORT_C virtual void DelegateParsingL(const TDesC8& aNsUri,
                                               const TDesC8& aLocalName,
                                               const TDesC8& aQName,
                                               const RAttributeArray& aAttrs);
        
        /**
         * Sets the reader for this fragment and sets this to be the 
         * content handler of the following SAX events.
         * @since Series60 3.0
         * @param aReader is the XML parser to be used.
         */ 
        IMPORT_C virtual void ParseWithL(CSenXmlReader& aReader);

        /**
         * Sets a new parent for this fragment.
         * @since Series60 3.0
         * @param aFragment:    the new parent.
         */
        IMPORT_C virtual void SetOwner(MSenFragment& aFragment);

        /**
         * Leave codes: 
         * KErrSenXmlReaderNotSet   if XML reader has not been set.  Resumes 
         *     parsing to be handled by this fragment. Usually called by some
         *     delegate fragment which was set to be content handler because this
         *     fragment called DelegateParsingL().
         * @since Series60 3.0
         * @param aNsUri    The namespace URI of the current element
         * @param aLocalName    The local name of the current element
         * @param aQName    The qualified name of the current element
         */ 
        IMPORT_C virtual void ResumeParsingFromL(const TDesC8& aNsUri,
                                                 const TDesC8& aLocalName,
                                                 const TDesC8& aQName);

        /**
         * Sets the attributes for the fragment. BaseFragment parses only
         * namespace (xmlns) attributes from the document.
         * Subclasses should override this method if they are intrested
         * of handling any other XML attributes and their corresponding
         * values.
         * @since Series60 3.0
         * @param aAttrs:   the array of attributes.
         */
        IMPORT_C virtual void SetAttributesL(const RAttributeArray& aAttrs);
        
        /**
         * Writes the start element tag to the content stream. 
         * Derivants can override the basic usage used in BaseFragment.
         * @since Series60 3.0
         * @param aNsUri        The namespace URI of the current element
         * @param aLocalName        The local name of the current element
         * @param aQName        The qualified name of the current element
         * @param aAttrs        is the array of attributes.
         */
        IMPORT_C void WriteStartElementL(const TDesC8& aNsUri,
                                         const TDesC8& aLocalName,
                                         const TDesC8& aQName,
                                         const RAttributeArray& aAttrs);
        
        /**
         * Writes the end element tag to the content stream. 
         * Derivants can override the basic usage used in BaseFragment.
         * @since Series60 3.0
         * @param aNsUri        The namespace URI of the current element
         * @param aLocalName    The local name of the current element
         * @param aQName        The qualified name of the current element
         */
        IMPORT_C void WriteEndElementL(const TDesC8& aNsUri,
                                       const TDesC8& aLocalName,
                                       const TDesC8& aQName);

        /**
         * Gets the fragment data as an unicode XML.
         * @since Series60 3.0
         * @return  fragment as XML. Caller takes ownership.
         */ 
        IMPORT_C virtual HBufC* AsXmlUnicodeL();

        /**
         * Gets the fragment data as an UTF-8 form XML.
         * @since Series60 3.0
         * @return  fragment as XML. Caller takes ownership.
         */ 
        IMPORT_C virtual HBufC8* AsXmlL();

        /**
         * Invokes AsElement()->WriteAsXMLToL(aWs);
         * @since Series60 3.0
         * @param aWs is the stream into which the UTF-8 form XML will
         *            be written.
         */
        IMPORT_C virtual void WriteAsXMLToL(RWriteStream& aWs);

        /**
         * Checks if fragment matches to another fragment 
         * by its content and child elements. 
         * Fragment can contain more data than the given candidate.
         * @since Series60 3.0
         * @param aCandidate    The pattern to be matched. Must contain same or 
         *                      less data for match to come true.
         * @return ETrue if content and possible children match exactly 
         *               to given pattern. EFalse otherwise.
         */
        IMPORT_C virtual TBool ConsistsOfL(MSenFragment& aCandidate);

    protected:  
        
        /**
        * C++ default constructor.
        */
        IMPORT_C CSenBaseFragment();        
        
        /**
         * Following BaseConstructL methods should be called from ConstructL() 
         * methods of some deriving (fragment) class.
         */

        /**
        * BaseConstructL, where an element is given as initializer.
        * @since Series60 3.0
        * @param aElement from which this fragment will be constructed from.
        */
        IMPORT_C void BaseConstructL(const CSenElement& aElement);
        
        /**
        * BaseConstructL setting XML localname for this fragment.
        * @since Series60 3.0
        * @param aLocalName XML localname for this fragment
        */
        IMPORT_C void BaseConstructL(const TDesC8& aLocalName);

        /**
        * BaseConstructL offering possibility to set XML namespace and localname.
        * @since Series60 3.0
        * @param aNsUri XML namespace URI for this fragment
        * @param aLocalName XML localname for this fragment
        */
        IMPORT_C void BaseConstructL(const TDesC8& aNsUri,
                                     const TDesC8& aLocalName);

        /**
        * Base constructor
        * @since Series60 3.0
        * @param aNsUri XML namespace URI for this fragment
        * @param aLocalName XML localname for this fragment
        * @param aQName XML qualifiedname for this fragment
        */
        IMPORT_C void BaseConstructL(const TDesC8& aNsUri,
                                     const TDesC8& aLocalName,
                                     const TDesC8& aQName);
        /**
        * Base constructor
        * @since Series60 3.0
        * @param aNsUri XML namespace URI for this fragment
        * @param aLocalName XML localname for this fragment
        * @param aQName XML qualifiedname for this fragment
        * @param aAttrs XML attributes for this fragment
        */
        IMPORT_C void BaseConstructL(const TDesC8& aNsUri,
                                     const TDesC8& aLocalName,
                                     const TDesC8& aQName,
                                     const RAttributeArray& aAttrs);

        /**
        * Base constructor
        * @since Series60 3.0
        * @param aNsUri XML namespace URI for this fragment
        * @param aLocalName XML localname for this fragment
        * @param aQName XML qualifiedname for this fragment
        * @param aAttrs XML attributes for this fragment
        * @param aParent parent to be set for this fragmemt
        */
        IMPORT_C void BaseConstructL(const TDesC8& aNsUri,
                                     const TDesC8& aLocalName,
                                     const TDesC8& aQName,
                                     const RAttributeArray& aAttrs,
                                     CSenElement& aParent);

        /**
        * BaseConstructL() setting the XML reader for this fragment
        * @since Series60 3.0
        * @param aReader is the XML reader for this fragment
        */
        IMPORT_C void BaseConstructL(CSenXmlReader& aReader);
        
        // New functions
         
        /**
        * Makes the content internal stream for content saving available.
        * @since Series60 3.0
        */
        IMPORT_C virtual void AllocContentSaverL();     

        /**
         * Callback function implementing the XML content handler interface.
         * Inheriting classes can override these.
         * @since Series60 3.0
         * @param aNsUri        The namespace URI of the new element
         * @param aLocalName    The local name of the new element
         * @param aQName        The qualified name of the new element
         * @param aAttrs        The attributes of the new element
         */
        IMPORT_C virtual void StartElementL(const TDesC8& aNsUri,
                                            const TDesC8& aLocalName,
                                            const TDesC8& aQName,
                                            const RAttributeArray& aAttrs);

        /**
        * Callback function which implement the XML content handler interface.
        * Inheriting classes can override these.
        * @since Series60 3.0
        * @param aNsUri     The namespace URI of the new element
        * @param aLocalName     The local name of the new element
        * @param aQName     The qualified name of the new element
        */
        IMPORT_C virtual void EndElementL(const TDesC8& aNsUri,
                                          const TDesC8& aLocalName,
                                          const TDesC8& aQName);

        /**
        * Function which implement the XML content handler interface.
        * Inheriting classes can override these.
        * This one is called when content is starting.
        * @since Series60 3.0
        * @param aChars     The content characters.
        * @param aStart     The starting index
        * @param aLength        The length of the characters.
        */
        IMPORT_C virtual void CharactersL(const TDesC8& aChars,
                                          TInt aStart,
                                          TInt aLength);

        /**
        *  Callback function which implement the XML content handler interface.
        *  Inheriting classes can override these. Note that overrides should
        *  return TRUE (1) on success and FALSE (0) on failure to parser.
        *
        *  @since Series60 3.0
        *  @param aName     The entity name
        *
        */
        IMPORT_C TInt StartEntity(TDesC8& aName);

        /**
         * Sets content to a child element. If no element with given local name
         * is not found, new one is added and content is set to that one.
         * @since Series60 3.0
         * @param aLocalName    The local name of element which content
         *                      is about to be set
         * @param aContent      Content to be set.
         * @return              the element where content was set.
         * Leave codes: 
         *      KErrSenInvalidCharacters if aLocalName contains illegal characters.     
         *      KErrSenZeroLengthDescriptor if aLocalName is zero length.
         */
        IMPORT_C MSenElement& SetContentOfL(const TDesC8& aLocalName,
                                            const TDesC8& aContent);
        /**
         * Gets the content of a given element.
         * @since Series60 3.0
         * @param aLocalName    The local name of the element which content is 
         *                      asked
         * @return  the content which was asked
         */
        IMPORT_C TPtrC8 ContentOf(const TDesC8& aLocalName);        

    private: // New functions
        
        /**
         * Leaving variant which is then trapped in the non-leaving function.
         */
        TPtrC8 ContentL();
    
        // Functions from base classes

        // From MSenContentHandlerClient
        
        IMPORT_C virtual TInt StartDocument();
        IMPORT_C virtual TInt EndDocument();
        IMPORT_C virtual TInt StartElement(const TDesC8& aNsUri,
                                           const TDesC8& aLocalName,
                                           const TDesC8& aQName,
                                           const RAttributeArray& aAttrs);
        
        IMPORT_C virtual TInt EndElement(const TDesC8& aNsUri,
                                         const TDesC8& aLocalName,
                                         const TDesC8& aQName);

        IMPORT_C virtual TInt Characters(const TDesC8& aChars,
                                         const TInt aStart,
                                         const TInt aLength);

        IMPORT_C virtual TInt Error(TInt aErrorCode);

        //IMPORT_C TInt StartEntityL(const TDesC8& aName);


    protected: // Data

        // State variable indicating what this fragment
        // is currently parsing. Even states (like 0)
        // mean that this fragment is ignoring the
        // data, and odd states indicate, that fragment
        // is storing the data into itself.
        TInt iState;
        // Owned element containing this XML fragment data.
        CSenElement* ipElement;
        // Pointer to XML parser. Not owned.
        CSenXmlReader* iXmlReader;      
        // Possible owner fragment, if such exists. Not owned.
        MSenFragment* ipOwner;
        // Internal write stream, into which UTF-8 form XML is stored
        RWriteStream iWs;

    private: // Data
         
        // Owned pointer to delegate fragment
        CSenFragment* ipDelegate;
        // Not owned. Holds namespaces that are referred to from 
        // within the content but were not declared within this 
        // BaseFragment.
        RPointerArray<CSenNamespace> iNamespaces;
        // Owned. Holds prefixes that have been declared within the 
        // scope of this BaseFragment
        RPointerArray<HBufC8> iPrefixes;
        // Actual flat buffer to content which includes namespaces.
        CBufFlat* ipContentWithNamespaces;
        // Indicating that content writing stream is initialized.
        TBool hasContentWriteStream;
        // Indicates whether or not ipElement member is an owned
        TBool iElementOwned;
    };

#endif //SEN_BASE_FRAGMENT_H

// End of File



