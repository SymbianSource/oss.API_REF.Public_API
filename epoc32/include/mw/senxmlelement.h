/*
* Copyright (c) 2002-2006 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:        This is an optimized variant of XML element, which consumes
*                significantly less heap when compared to CSenBaseElement
*
*/








#ifndef SEN_XML_ELEMENT_H
#define SEN_XML_ELEMENT_H

//  INCLUDES
#include <s32mem.h>
#include <SenElement.h>
#include <SenNamespace.h>
#include <SenBaseAttribute.h>

// CLASS DECLARATION

/**
*  Implementation of an XML element functionality
*  Content is stored in UTF-8 form XML. Note, that
*  setting any 8-bit content into XML without encoding
*  it into form of legal is illegal. Instead, one
*  should use encoding methods, like ones introduced 
*  in SenXmlUtils class to encode basic entities, or
*  use use some other encoding like MD5 for binary 
*  data content.
*  @lib SenXML.dll
*  @since Series60 3.1
*/
class CSenXmlElement : public CSenElement
    {
    public:  // Constructors and destructor

        /**
         *  Standard constructor.
         *  @param aLocalName   the local name for this element.
         *  Leave codes:    
         *      KErrSenInvalidCharacters if aLocalName contains illegal characters.     
         *      KErrSenZeroLengthDescriptor if aLocalName is zero length.
         */

        IMPORT_C static CSenXmlElement* NewL(const TDesC8& aLocalName);
        /**
         *  Standard constructor.
         *  @param aNsUri       the namespace URI for this element.
         *  @param aLocalName   the local name for this element.
         *  Leave codes:    
         *      KErrSenInvalidCharacters if aLocalName contains illegal characters.     
         *      KErrSenZeroLengthDescriptor if aLocalName is zero length.
         */
        IMPORT_C static CSenXmlElement* NewL(const TDesC8& aNsUri,
                                             const TDesC8& aLocalName);

        /**
         *  Standard constructor.
         *  @param aNsUri       the namespace URI for this element.
         *  @param aLocalName   the local name for this element.
         *  @param aQName       the qualified name for this element.
         *  Leave codes:    
         *      KErrSenInvalidCharacters if aLocalName or aQName contains
         *      illegal characters.     
         *      KErrSenZeroLengthDescriptor if aLocalName or aQName is zero length.
         */
        IMPORT_C static CSenXmlElement* NewL(const TDesC8& aNsUri,
                                             const TDesC8& aLocalName,
                                             const TDesC8& aQName);

        /**
         *  Standard constructor.
         *  @param aNsUri       the namespace URI for this element.
         *  @param aLocalName   the local name for this element.
         *  @param aQName       the qualified name for this element.
         *  @param apAttrs      the attributes for this element.
         *  Leave codes:    
         *      KErrSenInvalidCharacters if aLocalName or aQName contains
         *      illegal characters.     
         *      KErrSenZeroLengthDescriptor if aLocalName or aQName is zero length.
         */
        IMPORT_C static CSenXmlElement* NewL(const TDesC8& aNsUri, 
                                             const TDesC8& aLocalName,
                                             const TDesC8& aQName,
                                             const RAttributeArray& apAttrs);

        /**
         *  Standard constructor.
         *  @param aNsUri       the namespace URI for this element.
         *  @param aLocalName   the local name for this element.
         *  @param aQName       the qualified name for this element.
         *  @param apAttrs      the attributes for this element.
         *  @param aParent: the parent element for the new element
         *  Leave codes:    
         *      KErrSenInvalidCharacters if aLocalName or aQName contains
         *      illegal characters.     
         *      KErrSenZeroLengthDescriptor if aLocalName or aQName is zero length.
         */
        IMPORT_C static CSenXmlElement* NewL(const TDesC8& aNsUri,
                                             const TDesC8& aLocalName,
                                             const TDesC8& aQName,
                                             const RAttributeArray& apAttrs,
                                             CSenElement& aParent);

        /**
        * Destructor.
        */
        IMPORT_C virtual ~CSenXmlElement();

    public: // New functions
    
        /**
         *  Adds attributes to the element. Calls internally AddAttributesL()
         *  Can be overridden to replace old attributes.
         *  @param  aAttrs: the array of attributes.
         */
        IMPORT_C virtual void SetAttributesL(const RAttributeArray& apAttrs);
    
        // Functions from base classes
    
        // From CSenElement
    
        /**
        *   Getter for Element's local name.
        *   @return Localname or KNullDesC if not set.
        */  
        IMPORT_C virtual const TDesC8& LocalName() const;

        /**
        *   Getter for Element's namespace URI.
        *   @return Namespace URI or KNullDesC if not set.
        */
        IMPORT_C virtual const TDesC8& NamespaceURI() const;

        /**
         *  Getter for namespace prefix of this element.
         *  @return namespace prefix or KNullDesC if not set.
         */
        IMPORT_C virtual const TDesC8& NsPrefix() const;

        /**
         *  Setter for namespace prefix of this element.
         *  @param aPrefix: new namespace prefix for the element.
         */
        IMPORT_C virtual void SetPrefixL(const TDesC8& aPrefix);

        /**
         *  Method for checking if the element has any content within.
         *  @return ETrue if has content, EFalse if not.
         */
        IMPORT_C virtual TBool HasContent() const;

        /**
         *  Getter for the content of the element.
         *  @return the content or KNullDesC if empty.
         */
        IMPORT_C virtual TPtrC8 Content() const;

        /**
         *  Getter for the content of the element, unicode version.
         *  @return content as unicode. Ownership IS TRANSFERRED to the caller.
         */
        IMPORT_C virtual HBufC* ContentUnicodeL() const;

        /**
         *  Sets the content to the element. Old content is overwritten.
         *  @param  aContent:   The content to be set. Can be KNullDesC8.
         *  @return The content of the element or KNullDesC8 if no content was set.
         */
        IMPORT_C virtual TPtrC8 SetContentL(const TDesC8& aContent);

        /**
         *  Gets the write stream for the content for easy appending.
         *  Writing 8-bit (UTF-8) string to the returned stream will be appended
         *  to the content.
         *  @return reference to the RWriteStream.
         */
        IMPORT_C virtual RWriteStream& ContentWriteStreamL();

        /**
         * Checks if element matches to another element
         * by its content and child elements. Element
         * can contain more data than the given pattern.
         * @since Series60 3.0
         * @param aCandidate    The pattern to be matched. Must contain same or 
         *                  less data for match to come true.
         * @return ETrue if content and possible children match exactly 
         *          to given pattern. EFalse otherwise.
         */
        IMPORT_C virtual TBool ConsistsOfL(MSenElement& aCandidate);

        /**
        *   Setter for Element's namespace URI.
        *   @param aNsUri:  Namespace URI
        */
        IMPORT_C virtual void SetNamespaceL(const TDesC8& aNsUri);

        /**
        *   Setter for Element's namespace URI.
        *   @param aNsPrefix:   Namespace prefix
        *   @param aNsUri:      Namespace URI
        */
        IMPORT_C virtual void SetNamespaceL(const TDesC8& aNsPrefix,
                                            const TDesC8& aNsUri);

        /**
         * Adds a namespace declaration.
         * If this element (or its parent if parameter aCheckInParent is ETrue) 
         * already has a Namespace with the same prefix and URI the given
         * Namespace is not added.
         * @param aNewNamespace
         * @param aCheckInParent
         * @return the added Namespace, or the equivalent pre-existing one.
         */ 
        IMPORT_C virtual const CSenNamespace* AddNamespaceL(CSenNamespace& aNewNamespace,
                                                            TBool aCheckInParent);
        /**
        *   Method for adding a namespace for the Element.
        *   @param aPrefix: Namespace prefix
        *   @param aUri:    Namespace URI
        *   @return the added Namespace, or the equivalent pre-existing one.
        */
        IMPORT_C virtual const CSenNamespace* AddNamespaceL(const TDesC8& aPrefix,
                                                            const TDesC8& aUri);
        /**
        *   Getter for Element's namespace.
        *   @return const pointer to the CSenNamespace object of this Element.
        *           NULL if not set.
        */ 
        IMPORT_C virtual const CSenNamespace* Namespace();

        /**
         * Getter for new namespace, using a namespace prefix as a search criteria.
         * @param aNsPrefix is the new namespace prefix for this element
         * @return the found Namespace that is declared for the given prefix
         * within the scope of this Element. If no such prefix is
         * declared return null.
         */     
        IMPORT_C virtual const CSenNamespace* Namespace(const TDesC8& aNsPrefix);

        /**
         * Getter for new namespace, using a namespace prefix as a search criteria,
         * supporting both normal and recursive search mode (checking the parent).
         * @param aNsPrefix:        The prefix used to search
         * @param aCheckInParent:   The flag indicating whether to check parent's
         *                          namespaces too if not found in the current 
         *                          element. 
         *                          ETrue to check, EFalse for not to check.
         * @return the found Namespace that is declared for the given prefix 
         *                   and namespace URI within the scope of this Element
         *                   or NULL if not found
         */ 
        IMPORT_C virtual const CSenNamespace* Namespace(const TDesC8& aNsPrefix,
                                                        const TBool aCheckInParent);

        /**
         * Getter for new namespace, using both namespace prefix and namespace URI as search criteria.
         * @param aNsPrefix:    The prefix used to search
         * @param aUri:         The namespace URI used to search.
         * @return the found Namespace that is declared for the given prefix 
         *                   and namespace URI within the scope of this Element
         *                   or NULL if not found.
         */     
        IMPORT_C virtual const CSenNamespace* Namespace(const TDesC8& aNsPrefix,
                                                        const TDesC8& aUri);

        /**
         *  Getting the child elements of this element matching the given criteria.
         *  @param aElementArray:   Array to be filled with the matching elements,
         *                          or empty array if no matching found. 
         *                          Any modifications made on the returned items
         *                          modify the real childs too.
         *  @param aNsUri:          namespace URI to be matched
         *  @param aLocalName:      local name to be matched
         *  @return KErrNone        ok
         *          KErrNotFound    No child elements exist.
         */     
        IMPORT_C virtual TInt ElementsL(RPointerArray<CSenElement>& aElementArray,
                                        const TDesC8& aNsUri,
                                        const TDesC8& aLocalName);
        
        /**
         *  Getting the child elements of this element matching the given criteria.
         *  @param aElementArray:   Array to be filled with the matching elements,
         *                          or empty array if no matching found. 
         *                          Any modifications made on the returned items
         *                          modify the real childs too.
         *  @param aNsUri:          namespace URI to be matched
         *  @param aLocalName:      local name to be matched
         *  @return KErrNone        ok
         *          KErrNotFound    No child elements exist.
         */     
        IMPORT_C virtual TInt ElementsL(RPointerArray<CSenElement>& aElementArray,
                                        const TDesC8& aLocalName);

        /**
         *  Getting the child elements of this element.
         *  @return an array of child elements. This is an empty array if there
         *          are no children. Any modifications made on the returned array
         *          modify the element object.
         */     
        IMPORT_C virtual RPointerArray<CSenElement>& ElementsL();

        /**
         *  Gets all the attributes of this element in an array.
         *  @return array of attributes. Array will be empty if element has 
         *          no attributes.
         */     
        IMPORT_C virtual RPointerArray<CSenBaseAttribute>& AttributesL();

        /**
         *  Gets all the namespaces of this element in an array.
         *  @return array of namespaces. Array will be empty if element has 
         *          no namespaces.
         */     
        IMPORT_C virtual RPointerArray<CSenNamespace>& NamespacesL();

        /**
         *  Gets the value of the given attribute.
         *  @param aName:   Name of the attribute in question.
         *  @return the value of the attribute, or NULL if not found. Ownership is
         *          NOT TRANSFERRED.
         */     
        IMPORT_C virtual const TDesC8* AttrValue(const TDesC8& aName);
        
        /**
         *  Adds an attribute. If attribute is already existing, 
         *  the value of the attribute will be replaced.
         */
        IMPORT_C virtual void AddAttrL(const TDesC8& aName, const TDesC8& aValue);

        /**
         *  Gets the parent element of this element.
         *  @return the parent element or NULL if no parent set. 
         *          Ownership is NOT transferred to the caller.
         */     
        IMPORT_C virtual CSenElement* Parent();

        /**
         *  Sets the parent element to this element. Notice that the element is not
         *  automatically added as a child of the parent. Parent's 
         *  AddElementL() should be called instead.
         *  @param apParent:    The wanted parent. Can be NULL.
         *  @return the parent element
         */ 
        IMPORT_C virtual CSenElement* SetParent(CSenElement* apParent);

        /**
         *  Gets the root element. If no parent element, returns this element.
         *  @return the root of the tree. Ownership is NOT transferred.
         */     
        IMPORT_C virtual MSenElement& Root();

        /**
         *  Gets the child element with the specified local name.
         *  Assumes that namespace is the same as this parent element.
         *  @return the child element or NULL if the child with the specified 
         *          local name is not found. Ownership is NOT transferred.
         */ 
        IMPORT_C virtual CSenElement* Element(const TDesC8& aLocalName);

        /**
         *  Gets the child element with the specified local name and namespace URI.
         *  @return the child element or NULL if the child with the specified 
         *          criterias is not found. Ownership is NOT transferred.
         */ 
        IMPORT_C virtual CSenElement* Element(const TDesC8& aNsUri,
                                              const TDesC8& aLocalName);

        /**
         * Create a new element ready for adding or insertion.
         * If the given namespace prefix is not declared yet
         * the element will not be created and NULL will be returned.
         * @param aNsPrefix:    The namespace prefix
         * @param aLocalName:   The new elements localname
         * @return  the new Element just created, or NULL if given prefix was not
         *          declared yet. Ownership is transferred to the caller.
         *  Leave codes:    
         *      KErrSenInvalidCharacters if aLocalName contains illegal characters.     
         *      KErrSenZeroLengthDescriptor if aLocalName or aQName is zero length.
         */     
        IMPORT_C virtual CSenElement* CreateElementL(const TDesC8& aNsPrefix,
                                                     const TDesC8& aLocalName);

        /**
         * Insert an Element into the list of children elements
         * so that the inserted Element is placed right before the aBeforeElement.
         * If aBeforeElement is not found, element will be appended to the last
         * position.
         * Function leaves if error occurs in inserting.
         * @param aInsertedElement: the element to be inserted. 
         *                          Ownership is transferred.
         * @param aBeforeElement:   the element which will be right next to the 
         *                          element just inserted.
         * @return the inserted Element
         */     
        IMPORT_C virtual CSenElement& InsertElementL(CSenElement& aElement,
                                                     const CSenElement& aBeforeElement);

        /**
         * Adds an Element to the children elements. 
         * Sets this element to be the new parent of the given element.
         * @param aElement: the element to be added. Ownership is transferred.
         * @return the added Element
         */ 
        IMPORT_C virtual CSenElement& AddElementL(CSenElement& aElement);

        /**
         * Constructs and adds a new element to the children elements. 
         * Sets this element to be the new parent of the given element.
         * @param aNsUri:       namespace URI of the new element
         * @param aLocalName:   local name of the new element
         * @return the added Element
         *  Leave codes:    
         *      KErrSenInvalidCharacters if aLocalName contains illegal characters.     
         *      KErrSenZeroLengthDescriptor if aLocalName is zero length.
         */     
        IMPORT_C virtual CSenElement& AddElementL(const TDesC8& aNsUri,
                                                  const TDesC8& aLocalName);

        /**
         * Constructs and adds a new element to the children elements. 
         * Sets this element to be the new parent of the given element.
         * @param aNsUri:       namespace URI of the new element
         * @param aLocalName:   local name of the new element
         * @param aQName:       qualified name of the new element
         * @return the added Element
         *  Leave codes:    
         *      KErrSenInvalidCharacters if aLocalName or aQName contain illegal 
         *      characters.     
         *      KErrSenZeroLengthDescriptor if aLocalName or aQName is zero length.
         */ 
        IMPORT_C virtual CSenElement& AddElementL(const TDesC8& aNsUri,
                                                  const TDesC8& aLocalName,
                                                  const TDesC8& aQName);

        /**
         * Constructs and adds a new element to the children elements. 
         * Sets this element to be the new parent of the given element.
         * Note: Element is created with no specific namespace, default namespace
         * of some of the upper level elements are in effect if there is such a 
         * namespace.
         * @param aLocalName:   local name of the new element
         * @return the added Element
         *  Leave codes:    
         *      KErrSenInvalidCharacters if aLocalName contains illegal characters.     
         *      KErrSenZeroLengthDescriptor if aLocalName is zero length.
         */     
        IMPORT_C virtual CSenElement& AddElementL(const TDesC8& aLocalName);

        /**
         *  Remove an element from the childs.
         *  @param  aElement:   the element to be removed.
         *  @return The removed element. May be NULL if nothing was removed
         *          (if element was not found from the childs).
         *          The caller TAKES OWNERSHIP of the removed element.
         */     
        IMPORT_C virtual CSenElement* RemoveElement(CSenElement& aElement);

        /**
         *  Remove an element from the childs.
         *  @param  aNsUri:     the namespace URI of the element to be removed.
         *  @param  aLocalName: the local name of the element to be removed.
         *  @return The removed element. May be NULL if nothing was removed
         *          (if element was not found from the childs).
         *          The caller TAKES OWNERSHIP of the removed element.
         */     
        IMPORT_C virtual CSenElement* RemoveElement(const TDesC8& aNsUri,
                                                    const TDesC8& aLocalName);

        /**
         *  Remove an element from the childs.
         *  @param  aLocalName: the local name of the element to be removed.
         *  @return The removed element. May be NULL if nothing was removed
         *          (if element was not found from the childs).
         *          The caller TAKES OWNERSHIP of the removed element.
         */     
        IMPORT_C virtual CSenElement* RemoveElement(const TDesC8& aLocalName);

        /**
         *  Replaces an element from the childs with another element. 
         *  Element's local name and namespace URI will be used to match the
         *  element to be replaced. If matching element is not found, will
         *  normally add the given element to the childs.
         *  @param  aElement:   the element to be added. Ownership is transferred.
         *  @return The old element. May be NULL if nothing was replaced
         *          (if element was not found from the childs).
         *          The caller TAKES OWNERSHIP of the old element.
         */ 
        IMPORT_C virtual CSenElement* ReplaceElementL(CSenElement& aElement);

        /**
         *  Gets the element as an XML buffer. Buffer will contain all the childs
         *  @return element as XML. Caller takes ownership.
         */
        IMPORT_C virtual HBufC8* AsXmlL();

        /**
         *  Gets the element as an unicode XML buffer. 
         *  Buffer will contain all the childs etc.
         *  @return element as XML. Caller takes ownership.
         */     
        IMPORT_C virtual HBufC* AsXmlUnicodeL();

        /**
         *  Element writes itself to a write stream using UTF-8 charset encoding.
         *  @param aWriteStream:    The stream to write to.
         */     
        IMPORT_C virtual void WriteAsXMLToL(RWriteStream& aWriteStream);

        /**
         *  Element writes its namespaces to a write stream using UTF-8 charset 
         *  encoding.
         *  @param aWriteStream:    The stream to write to.
         */     
        IMPORT_C virtual void WriteNamespacesToL(RWriteStream& aWriteStream);

        /**
         *  Gets the current element as XML element. Mostly used to get the
         *  classes which implement this interface as an instance of this 
         *  interface.
         *  @return the current object as element. Ownership is NOT transferred.
         */     
        IMPORT_C virtual MSenElement* AsElement();

        /**
         *  Copies content from given element to this element appending to the 
         *  existing content if there is any.
         *  @param aSource: The source element.
         */ 
        IMPORT_C void CopyFromL(CSenElement& aSource);

        /**
         * Detach the element from its parent.
         * If the element, or one of its children, is dependent
         * on a namespace declared in the scope of the parent
         * copy those namespace declarations to this element.
         * @return this Element. Ownership IS TRANSFERRED to the caller.
         */ 
        IMPORT_C virtual CSenElement* DetachL();

        /**
         *  Gets a child element from a specified index.
         *  @param  aIndex: the index what to get
         *  @return child element from a current index. NULL if no child in given
         *          index is found
         */ 
        IMPORT_C virtual CSenElement* Child(TInt aIndex);

        /**
         * (Re-) Set the name and namespace of this Element. The element will be
         * given the localName in the the given namespace. A prefix will be
         * computed from the qualified name.
         * This method should be used with care and is mainly intended for
         * protected use in implementations.
         * @param aNamespaceURI:    The new namespace URI.
         * @param aLocalName:       The new local name.
         * @param aQName:           The new qualified name.
         */ 
        IMPORT_C virtual void Set(const TDesC8& aNsUri,
                                  const TDesC8& aLocalName,
                                  const TDesC8& aQName);

        /**
         *  Adds new attributes to the element.
         *  @param  aAttrs: the array of attributes.
         */ 
        IMPORT_C virtual void AddAttributesL(const RAttributeArray& apAttrs);

        void Compress();
        
    protected:  // New functions
    
        /**
        * C++ default constructor.
        */
        IMPORT_C CSenXmlElement();

        /**
         *  Following BaseConstructL methods should be called from the deriving
         *  classes ConstructL() methods. Parameter info is found in the
         *  corresponding NewL-methods.
         */
        IMPORT_C void BaseConstructL(const TDesC8& aLocalName);

        IMPORT_C void BaseConstructL(const TDesC8& aNsUri,
                                     const TDesC8& aLocalName);
        
        IMPORT_C void BaseConstructL(const TDesC8& aNsUri,
                                     const TDesC8& aLocalName,
                                     const TDesC8& aQName);

        IMPORT_C void BaseConstructL(const TDesC8& aNsUri,
                                     const TDesC8& aLocalName,
                                     const TDesC8& aQName,
                                     const RAttributeArray& apAttrs);

        IMPORT_C void BaseConstructL(const TDesC8& aNsUri,
                                     const TDesC8& aLocalName,
                                     const TDesC8& aQName,
                                     const RAttributeArray& apAttrs,
                                     CSenElement& aParent);
    
        /**
         *  Method for finding an attribute with given name.
         *  @param aName    a name of the attribute to be searched for
         *  @return the 1st attribute with the name, or NULL. 
         *              Ownership is not transferred.
         */
        IMPORT_C virtual CSenBaseAttribute* FindAttr(const TDesC8& aName);

        /**
         *  Method for finding index for a wanted element.
         *  @param aNsUri       a namespace URI which needs to match
         *  @param aLocalName   a local name which needs to match
         *  @return Index of the element with given characteristics.
         *          or KErrNotFound if none matching
         */
        IMPORT_C virtual TInt IndexOfElement(const TDesC8& aNsUri,
                                             const TDesC8& aLocalName) const;
        
        /**
         *  Writes element's attributes into a writestream.
         *  @param aWriteStream writestream to write into
         */
        IMPORT_C virtual void WriteAttrsToL(RWriteStream& aWriteStream);

        /**
         *  Helper function to write an attribute into a writestream.
         *  @param aWriteStream writestream to write into
         *  @param aName    attribute name
         *  @param aValue   attribute value
         */
        IMPORT_C virtual void WriteAttrToL(RWriteStream& aWriteStream,
                                           const TDesC8& aName,
                                           const TDesC8& aValue);

        /**
         *  Writes all internal elements into a writestream.
         *  @param aWriteStream writestream to write into
         */
        IMPORT_C virtual void WriteElementsToL(RWriteStream& aWriteStream);

        /**
         *  Writes all element's content into a writestream.
         *  @param aWriteStream writestream to write into
         */
        IMPORT_C virtual void WriteContentToL(RWriteStream& aWriteStream);

        /**
        *   Adds an attribute into this element. Used also adding new namespaces
        *   into the element.
        * @param aQName     Attribute's qualified name
        * @param aLocalName Attribute's local name
        * @param aValue     Attribute's value
        * @return value of the attribute as string (TDesC&)
        *   Leave codes:    
        *       KErrSenInvalidCharacters if aLocalName or aQName contain illegal 
        *       characters.     
        *       KErrSenZeroLengthDescriptor if aLocalName or aQName is zero length.
        */
        IMPORT_C virtual const TDesC8& AddAttributeL(const TDesC8& aQName,
                                                     const TDesC8& aLocalName,
                                                     const TDesC8& aValue);

        /**
        *   Adds an attribute into this element. Used also adding new namespaces
        *   into the element.
        * @param aLocalName Attribute's local name
        * @param aValue     Attribute's value
        * @return value of the attribute as string (TDesC&)
        *   Leave codes:    
        *       KErrSenInvalidCharacters if aLocalName contains illegal characters.     
        *       KErrSenZeroLengthDescriptor if aAttrName is zero length, or
        *       if the local name part of it is zero length.
        */
        IMPORT_C virtual const TDesC8& AddAttributeL(const TDesC8& aAttrName,
                                                     const TDesC8& aValue);

        /** 
        * Adds an attribute into this element.
        * @param apAttribute    Attribute to be added. Ownership is transferred
        *                       to this element.
        * @return attribute value as a string (TDesC8&)
        */
        IMPORT_C const TDesC8& AddAttributeL(CSenBaseAttribute* apAttribute);

        /**
         *  Allocates a new buffer for saving content, if none allocated yet.
         */
        IMPORT_C virtual void AllocContentBufL();
        
        /**
         *  Writes element into a dynamic buffer.
         *  @param aBuf a dynamic buffer where to append everything.
         *  @return the modified buffer as TPtrC8.
         */
        IMPORT_C virtual TPtrC8 WriteToBufL(CBufBase& aBuf);

    private:
        void AddNamespaceMissingFromL(RPointerArray<CSenNamespace>& aNamespaces);

    private:    // Data
         
        HBufC8* ipLocalName;                            // Owned

        CBufFlat* ipContentBuf;                         // Owned

        RBufWriteStream* ipContentWriteStream;          // Owned

        RPointerArray<CSenBaseAttribute>* ipAttrs;      // Elements owned

        RPointerArray<CSenElement>* ipElements;         // Elements owned

        RPointerArray<CSenNamespace>* ipNamespaces;     // Elements owned

        CSenElement*    ipParent;                       // Not owned

        CSenNamespace*  ipNamespace;                    // Not Owned (deleted in upper level array)
        
    };

#endif // SEN_XML_ELEMENT_H

// End of File

