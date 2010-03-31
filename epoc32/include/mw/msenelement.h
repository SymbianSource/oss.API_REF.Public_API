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
* Description:        The abstract interface of an XML element
*
*/








#ifndef M_SEN_ELEMENT_H
#define M_SEN_ELEMENT_H

//  INCLUDES
#include <e32base.h>
#include <s32strm.h>
#include <xml/attribute.h>

// FORWARD DECLARATIONS
class CSenElement;
class CSenBaseAttribute;
class CSenNamespace;

using namespace Xml;

// CLASS DECLARATION

/**
*  The abstract interface of an XML element
*  @lib SenXML.dll
*  @since Series60 3.0
*/
class MSenElement
    {
    public: // New functions

        /**
        *   Getter for Element's local name.
        *  @return KNullDesC if not set
        */
        virtual const TDesC8& LocalName() const = 0;

        /**
        *   Getter for Element's namespace URI.
        *   @return Namespace URI or KNullDesC if not set.
        */
        virtual const TDesC8& NamespaceURI() const = 0;

        /**
        *   Setter for Element's namespace URI.
        *   @param aNsUri:  Namespace URI
        */
        virtual void SetNamespaceL(const TDesC8& aNsUri) = 0;

        /**
        *   Setter for Element's namespace URI.
        *   @param aNsPrefix:   Namespace prefix
        *   @param aNsUri:      Namespace URI
        */
        virtual void SetNamespaceL( const TDesC8& aNsPrefix,
                                    const TDesC8& aNsUri) = 0;

        /**
        *   Method for adding a namespace for the Element.
        *   @param aNsPrefix:   Namespace prefix
        *   @param aNsUri:      Namespace URI
        *   @return the added Namespace, or the equivalent pre-existing one.
        */
        virtual const CSenNamespace* AddNamespaceL( const TDesC8& aPrefix,
                                                    const TDesC8& aUri) = 0;

        /**
         * Adds a namespace declaration.
         * If this element (or its parent if parameter aCheckInParent is ETrue) 
         * already has a Namespace with the same prefix and URI the given
         * Namespace is not added.
         * @param aNewNamespace
         * @param aCheckInParent
         * @return the added Namespace, or the equivalent pre-existing one.
         */
        virtual const CSenNamespace* AddNamespaceL( CSenNamespace& aNewNamespace,
                                                    TBool aCheckInParent) = 0;
        /**
        *   Getter for Element's namespace.
        *   @return const pointer to the CSenNamespace object of this Element.
        *           NULL if not set.
        */
        virtual const CSenNamespace* Namespace() = 0;

        /**
         * Get namespace that is declared for the given prefix
         * @param aNsPrefix:    The prefix to be used in searching.
        * @return the found Namespace that is declared for the given prefix
        * within the scope of this Element or NULL if not found.
         */
        virtual const CSenNamespace* Namespace( const TDesC8& aNsPrefix) = 0;

        /**
         * Get namespace that is declared for the given prefix and namespace
         * URI within the scope of this Element. 
         *
         * @param aNsPrefix:    The prefix used to search
         * @param aUri:         The namespace URI used to search.
        * @return the found Namespace that is declared for the given prefix and namespace
        * URI within the scope of this Element or NULL if not found.
         */
        virtual const CSenNamespace* Namespace( const TDesC8& aNsPrefix,
                                                const TDesC8& aUri) = 0;

        /**
         * Get namespace that is declared for the given prefix and namespace
         * URI within the scope of this Element. 
         *
         * @param aNsPrefix:        The prefix used to search
         * @param aCheckInParent:   The flag indicating whether to check parent's
         *                          namespaces too if not found in the current 
         *                          element. 
         *                          ETrue to check, EFalse for not to check.
        * @return the found Namespace that is declared for the given prefix and namespace
        * URI within the scope of this Element or NULL if not found
         */
        virtual const CSenNamespace* Namespace( const TDesC8& aNsPrefix,
                                                const TBool aCheckInParent) = 0;

        /**
         *  Getter for namespace prefix of this element.
         *  @return namespace prefix or KNullDesC8 if not set.
         */
        virtual const TDesC8& NsPrefix() const = 0;

        /**
         *  Setter for namespace prefix of this element.
         *  @param aPrefix: new namespace prefix for the element.
         */
        virtual void SetPrefixL(const TDesC8& aPrefix) = 0;
        
        /**
         *  Method for checking if the element has any content within.
         *  @return ETrue if has content, EFalse if not.
         */
        virtual TBool HasContent() const = 0;

        /**
         *  Getter for the content of the element.
         *  @return the content or KNullDesC8 if empty.
         */
        virtual TPtrC8 Content() const = 0;

        /**
         *  Getter for the content of the element, unicode version.
         *  @return content as unicode. Ownership IS TRANSFERRED to the caller.
         */
        virtual HBufC* ContentUnicodeL() const = 0;

        /**
         *  Sets the content to the element. Old content is overwritten.
         *  @param  aContent:   The content to be set. Can be KNullDesC8.
         *  @return The content of the element or KNullDesC8 if no content was set.
         */
        virtual TPtrC8 SetContentL(const TDesC8& aContent) = 0;

        /**
         *  Gets the write stream for the content for easy appending.
         *  Writing 8-bit (UTF-8) string to the returned stream will be appended
         *  to the content.
         *  @return reference to the RWriteStream.
         */
        virtual RWriteStream& ContentWriteStreamL() = 0;

        /**
         * Checks if element matches to another element by its content and 
         * child elements. Element can contain more data than the given 
         * pattern.
         * @since Series60 3.0
         * @param aCandidate    The pattern to be matched. Must contain same or 
         *                      less data for match to come true.
         * @return ETrue if content and possible children match exactly 
         *          to given pattern. EFalse otherwise.
         */
        virtual TBool ConsistsOfL(MSenElement& aCandidate) = 0;
        
        /**
         *  Getting the child elements of this element.
         *  @return an array of child elements. This is an empty array if there
         *          are no children. Any modifications made on the returned array
         *          modify the element object.
         */
        virtual RPointerArray<CSenElement>& ElementsL() = 0;

        /**
         *  Gets a child element from a specified index.
         *  @param  aIndex: the index what to get
         *  @return child element from a current index. NULL if no child in given
         *          index is found
         */
        virtual CSenElement* Child(TInt aIndex) = 0;

        /**
         *  Gets the value of the given attribute.
         *  @param aName:   Name of the attribute in question.
         *  @return the value of the attribute, or NULL if not found. Ownership is
         *          NOT TRANSFERRED.
         */
        virtual const TDesC8* AttrValue(const TDesC8& aName) = 0;

        /**
         *  Adds an attribute. If attribute is already existing, 
         *  the value of the attribute will be replaced.
         * @param aName     Name of the attribute to be added.
         * @param aValue    Value of the attribute to be added.
         */
        virtual void AddAttrL(const TDesC8& aName, const TDesC8& aValue) = 0;

        /**
         *  Gets all the attributes of this element in an array.
         *  @return array of attributes. Array will be empty if element has 
         *          no attributes.
         */
        virtual RPointerArray<CSenBaseAttribute>& AttributesL() = 0;

        /**
         *  Gets all the namespaces of this element in an array.
         *  @return array of namespaces. Array will be empty if element has 
         *          no namespaces.
         */
        virtual RPointerArray<CSenNamespace>& NamespacesL() = 0;

        /**
         *  Gets the parent element of this element.
         *  @return the parent element or NULL if no parent set. 
         *          Ownership is NOT transferred to the caller.
         */
        virtual CSenElement* Parent() = 0;

        /**
         *  Sets the parent element to this element. Notice that the element is not
         *  automatically added as a child of the parent. Parent's 
         *  AddElementL() should be called instead.
         *  @param apParent:    The wanted parent. Can be NULL.
         *  @return the parent element
         */
        virtual CSenElement* SetParent(CSenElement* apParent) = 0;

        /**
         * Detach the element from its parent.
         * If the element, or one of its children, is dependent
         * on a namespace declared in the scope of the parent
         * copy those namespace declarations to this element.
         * @return this Element. Ownership is NOT transferred to the caller.
         *          Returns NULL if no parent was set, and nothing was detached.
         */
        virtual CSenElement* DetachL() = 0;

        /**
         *  Gets the root element. If no parent element, returns this element.
         *  @return the root of the tree. Ownership is not transferred.
         */
        virtual MSenElement& Root() = 0;

        /**
         *  Gets the child element with the specified local name.
         *  Assumes that namespace is the same as this parent element.
         *  @return the child element or NULL if the child with the specified 
         *          local name is not found. Ownership is NOT transferred.
         */
        virtual CSenElement* Element(const TDesC8& aLocalName) = 0;

        /**
         *  Gets the child element with the specified local name and namespace URI.
         *  @return the child element or NULL if the child with the specified 
         *          criterias is not found. Ownership is NOT transferred.
         */
        virtual CSenElement* Element(const TDesC8& aNsUri,
                                     const TDesC8& aLocalName) = 0;

        /**
         * Create a new element ready for adding or insertion.
         * If the given namespace prefix is not declared yet
         * the element will not be created and NULL will be returned.
         * @param aNsPrefix:    The namespace prefix
         * @param aLocalName:   The new elements localname
         * @return  the new Element just created, or NULL if given prefix was not
         *          declared yet. Ownership is transferred to the caller.
         * Leave codes: 
         *      KErrSenInvalidCharacters if aLocalName or aQName contain illegal 
         *      characters.     
         *      KErrSenZeroLengthDescriptor if aLocalName is zero length.
         */
        virtual CSenElement* CreateElementL(const TDesC8& aNsPrefix,
                                            const TDesC8& aLocalName) = 0;

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
        virtual CSenElement& InsertElementL(CSenElement& aInsertedElement,
                                            const CSenElement& aBeforeElement) = 0;

        /**
         * Adds an Element to the children elements. 
         * Sets this element to be the new parent of the given element.
         * @param aElement: the element to be added. Ownership is transferred.
         * @return the added Element
         */
        virtual CSenElement& AddElementL(CSenElement& aElement) = 0;

        /**
         * Constructs and adds a new element to the children elements. 
         * Sets this element to be the new parent of the given element.
         * @param aNsUri:       namespace URI of the new element
         * @param aLocalName:   local name of the new element
         * @return the added Element
         * Leave codes: 
         *      KErrSenInvalidCharacters if aLocalName contains illegal characters.     
         *      KErrSenZeroLengthDescriptor if aLocalName is zero length.
         */
        virtual CSenElement& AddElementL(const TDesC8& aNsUri,
                                         const TDesC8& aLocalName) = 0;

        /**
         * Constructs and adds a new element to the children elements. 
         * Sets this element to be the new parent of the given element.
         * @param aNsUri:       namespace URI of the new element
         * @param aLocalName:   local name of the new element
         * @param aQName:       qualified name of the new element
         * @return the added Element
         * Leave codes: 
         *      KErrSenInvalidCharacters if aLocalName or aQName contain illegal 
         *      characters.     
         *      KErrSenZeroLengthDescriptor if aLocalName or aQName is zero length.
         */
        virtual CSenElement& AddElementL(const TDesC8& aNsUri,
                                         const TDesC8& aLocalName,
                                         const TDesC8& aQName) = 0;

        /**
         * Constructs and adds a new element to the children elements. 
         * Sets this element to be the new parent of the given element.
         * Note: Element is created with no specific namespace, default namespace
         * of some of the upper level elements are in effect if there is such a 
         * namespace.
         * @param aLocalName:   local name of the new element
         * @return the added Element
         * Leave codes: 
         *      KErrSenInvalidCharacters if aLocalName contains illegal characters.     
         *      KErrSenZeroLengthDescriptor if aLocalName is zero length.
         */
        virtual CSenElement& AddElementL(const TDesC8& aLocalName) = 0;

        /**
         *  Remove an element from the childs.
         *  @param  aElement:   the element to be removed.
         *  @return The removed element. May be NULL if nothing was removed
         *          (if element was not found from the childs).
         *          The caller TAKES OWNERSHIP of the removed element.
         */
        virtual CSenElement* RemoveElement(CSenElement& aElement) = 0;

        /**
         *  Remove an element from the childs.
         *  @param  aNsUri:     the namespace URI of the element to be removed.
         *  @param  aLocalName: the local name of the element to be removed.
         *  @return The removed element. May be NULL if nothing was removed
         *          (if element was not found from the childs).
         *          The caller TAKES OWNERSHIP of the removed element.
         */
        virtual CSenElement* RemoveElement( const TDesC8& aNsUri,
                                            const TDesC8& aLocalName) = 0;

        /**
         *  Remove an element from the childs.
         *  @param  aLocalName: the local name of the element to be removed.
         *  @return The removed element. May be NULL if nothing was removed
         *          (if element was not found from the childs).
         *          The caller TAKES OWNERSHIP of the removed element.
         */
        virtual CSenElement* RemoveElement(const TDesC8& aLocalName) = 0;

        /**
         *  Replaces an element from the childs with another element. 
         *  Element's local name and namespace URI will be used to match the
         *  element to be replaced. If matching element is not found, will
         *  normally add the given element to the childs.
         *  
         *  @param  aElement:   the element to be added. Ownership is transferred.
         *  @return The old element. May be NULL if nothing was replaced
         *          (if element was not found from the childs).
         *          The caller TAKES OWNERSHIP of the old element.
         */
        virtual CSenElement* ReplaceElementL(CSenElement& aElement) = 0;

        /**
         *  Gets element as an UTF-8 form XML.
         *  @return element as XML (in UTF-8 format). Caller takes ownership.
         */
        virtual HBufC8* AsXmlL() = 0;

        /**
        * Gets the element as XML fragment in Unicode UCS2 format.
        * @since Series60 3.0
        * @return the service description as XML, which ownership is
        *         transferred to the caller.
        */
        virtual HBufC* AsXmlUnicodeL() = 0;

        /**
        * Writes this element as XML, in UTF-8 form to a stream
        * @since Series60 3.0
        * @param aWriteStream   to write into.
        */
        virtual void WriteAsXMLToL(RWriteStream& aWriteStream) = 0;

        /**
         *  Element writes its namespaces to a write stream using UTF-8 charset 
         *  encoding.
         *
         *  @param aWriteStream:    The stream to write to.
         */
        virtual void WriteNamespacesToL(RWriteStream& aWriteStream) = 0;

        /**
         *  Gets the current element as XML element. Mostly used to get the
         *  classes which implement this interface as an instance of this 
         *  interface.
         *  @return the current object as element. Ownership is NOT transferred.
         */
        virtual MSenElement* AsElement() = 0;

        /**
         *  Copies content from given element to this element appending to the 
         *  existing content if there is any.
         *  @param aSource: The source element.
         */
        virtual void CopyFromL(CSenElement& aSource) = 0;

        /**
         * (Re-) Set the name and namespace of this Element. The element will be
         * given the localName in the the given namespace. A prefix will be
         * computed from the qualified name.
         *
         * This method should be used with care and is mainly intended for
         * protected use in implementations.
         *
         * @param aNamespaceURI:    The new namespace URI.
         * @param aLocalName:       The new local name.
         * @param aQName:           The new qualified name.
         */
        virtual void Set(const TDesC8& aNamespaceURI,
                         const TDesC8& aLocalName,
                         const TDesC8& aQName) = 0;

        /**
         *  Adds new attributes to the element.
         *  @param  aAttrs: the array of attributes.
         */
        virtual void AddAttributesL(const RAttributeArray& aAttrs) = 0;

};

#endif // M_SEN_ELEMENT_H

// End of File


