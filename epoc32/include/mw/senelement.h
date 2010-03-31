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
* Description:        Central place for debug-type macros
*
*/








#ifndef SEN_ELEMENT_H
#define SEN_ELEMENT_H

//  INCLUDES
#include <e32base.h>
#include <s32strm.h>
#include <xml/attribute.h>
#include <stringpool.h>

#include <MSenElement.h>

using namespace Xml;

// CLASS DECLARATION

/**
*  Abstract class definition of XML element
*  @lib SenXML.dll
*  @since Series60 3.0
*/
class CSenElement : public CBase, public MSenElement
    {
    public: // Functions from base classes

        // From MSenElement 
        
        /**
        * Getter for local name.
        * @since Series60 3.0
        * @return KNullDesC if not set (argumentless constructor).
        */
        virtual const TDesC8& LocalName() const = 0;

        /**
        * Getter for namespace URI.
        * @since Series60 3.0
        * @return KNullDesC if not set.
        */      
        virtual const TDesC8& NamespaceURI() const = 0;

        /**
        * Setter for Element's namespace URI.
        * @since Series60 3.0
        * @param @param aNsUri: Namespace URI
        */      
        virtual void SetNamespaceL(const TDesC8& aNsUri) = 0;

        /**
        * Setter for Element's namespace URI.
        * @since Series60 3.0
        * @param aNsPrefix: Namespace prefix
        * @param aNsUri:        Namespace URI
        */      
        virtual void SetNamespaceL( const TDesC8& aNsPrefix,
                                    const TDesC8& aNsUri) = 0;

        /**
        * Method for adding a namespace for the Element.
        * @since Series60 3.0
        * @param aPrefix:   Namespace prefix
        * @param aUri:  Namespace URI
        * @return the added Namespace, or the equivalent pre-existing one.
        */      
        virtual const CSenNamespace* AddNamespaceL( const TDesC8& aPrefix,
                                                    const TDesC8& aUri) = 0;

        /**
        * Getter for Element's namespace.
        * @since Series60 3.0
        * @return const pointer to the CSenNamespace object of this Element.
        *         Returns NULL, if not set.
        */      
        virtual const CSenNamespace* Namespace() = 0;

        /**
        * @since Series60 3.0
        * @param prefix
        * @return the namespace that is declared for the given prefix
        *         within the scope of this Element. If no such prefix is
        *         declared return NULL.
        */      
        virtual const CSenNamespace* Namespace(const TDesC8& aNsPrefix) = 0;

        /**
        * Get namespace that is declared for the given prefix and namespace 
        * URI within the scope of this element. 
        * @since Series60 3.0
        * @param aNsPrefix  The prefix used to search
        * @param aUri           The namespace URI used to search.
        * @return the found namespace that is declared for the given prefix 
        *                   and namespace URI within the scope of this Element
        *                   or NULL if not found.
        */
        virtual const CSenNamespace* Namespace( const TDesC8& aNsPrefix,
                                                const TDesC8& aUri) = 0;

        /**
        * @since Series60 3.0
        * @param aNsPrefix      The prefix used to search
        * @param aCheckInParent The flag indicating whether to check parent's
        *                       namespaces too if not found in the current 
        *                       element. 
        *                       ETrue to check, EFalse for not to check.
        * @return the found Namespace that is declared for the given prefix 
        *                   and namespace URI within the scope of this Element
        *                   or NULL if not found
        */
        virtual const CSenNamespace* Namespace( const TDesC8& aNsPrefix,
                                                const TBool aCheckInParent) = 0;

        /**
        * Getter for namespace prefix of this element.
        * @since Series60 3.0
        * @return namespace prefix or KNullDesC8 if not set.
        */
        virtual const TDesC8& NsPrefix() const = 0;

        /**
        * Setter for namespace prefix of this element.
        * @since Series60 3.0
        * @param aPrefix:   new namespace prefix for the element.
        */
        virtual void SetPrefixL(const TDesC8& aPrefix) = 0;

        /**
        * Method for checking if the element has any content within.
        * @since Series60 3.0
        * @return ETrue if has content, EFalse if not.
        */
        virtual TBool HasContent() const = 0;

        /**
        * Getter for the content of the element.
        * @since Series60 3.0
        * @return the content or KNullDesC8 if empty.
        */
        virtual TPtrC8 Content() const = 0;

        /**
        * Getter for the content of the element, Unicode (UCS2) version
        * @since Series60 3.0
        * @return content as Unicode. Ownership is transferred to the caller.
        */
        virtual HBufC* ContentUnicodeL() const = 0;
        
        /**
        * Sets the content to the element. Old content is overwritten.
        * @since Series60 3.0
        * @param aContent   The content to be set. Can be KNullDesC8.
        * @return The content of the element or KNullDesC8 if no content was set.
        */
        virtual TPtrC8 SetContentL(const TDesC8& aContent) = 0;

        /**
        * Gets the write stream for the content for easy appending.
        * Writing 8-bit (UTF-8) string to the returned stream will be appended
        * to the content.
        * @since Series60 3.0
        * @return reference to the RWriteStream.
        */
        virtual RWriteStream& ContentWriteStreamL() = 0;

        /**
         * Checks if element matches to another element
         * by it's content and child elements. Element
         * can contain more data than the given pattern.
         * @since Series60 3.0
         * @param   aCandidate The pattern to be matched. Must contain 
         *          same or less data for match to come true.
         * @return  ETrue if content and possible children match exactly 
         *          to given pattern. EFalse otherwise.
         */
        virtual TBool ConsistsOfL(MSenElement& aCandidate) = 0;

        /**
        * Get a list of direct children element that have the given
        * name and namespace.
        * @since Series60 3.0
        * @param    aElementArray RPointerArray that will hold matching elements
        * @param    namespaceURI
        * @param    localName
        * @return   KErrNone or some system-wide error code, 
        *           if an error has occurred.
        */
        virtual TInt ElementsL(RPointerArray<CSenElement>& aElementArray,
                                const TDesC8& aNsUri,
                                const TDesC8& aLocalName) = 0;

        /**
        * Get a list of direct children element that have the given
        * name and same namespace as this parent Element.
        * @since Series60 3.0
        * @param    aElementArray RPointerArray that will hold matching elements
        * @param    localName
        * @return   KErrNone or some system-wide error code, 
        *           if an error has occurred.
        */
        virtual TInt ElementsL(RPointerArray<CSenElement>& aElementArray,
                                const TDesC8& aLocalName) = 0;

        /**
        * @since Series60 3.0
        * @return an array of child elements. This is an empty array if there
        * are no children. Any modifications made on the returned array modify
        * the element object.
        */
        virtual RPointerArray<CSenElement>& ElementsL() = 0;
        
        /**
        * Adds a namespace declaration.
        * If this element (or its parent if parameter aCheckInParent is ETrue) 
        * already has a namespace with the same prefix and URI the given
        * namespace is not added.
        * @since Series60 3.0
        * @param aNewNamespace
        * @param aCheckInParent
        * @return the added Namespace, or the equivalent pre-existing one.
        */
        virtual const CSenNamespace* AddNamespaceL(CSenNamespace& aNewNamespace,
                                                    TBool aCheckInParent) = 0;

        /**
        * Gets the value of the given attribute.
        * @since Series60 3.0
        * @param aName: Name of the attribute in question.
        * @return the value of the attribute, or NULL if not found. 
        * Ownership is not transferred to caller.
        */
        virtual const TDesC8* AttrValue(const TDesC8& aName) = 0;

        /**
        * Adds an attribute. If attribute is already existing, 
        *                  the value of the attribute will be replaced.
        * @since Series60 3.0
        * @param aName      Name of the attribute to be added.
        * @param aValue Value of the attribute to be added.
        */
        virtual void AddAttrL(const TDesC8& aName, const TDesC8& aValue) = 0;

        /**
        * Gets all the attributes of this element in an array.
        * @since Series60 3.0
        * @return array of attributes. Array will be empty if element has 
        *         no attributes.
        */
        virtual RPointerArray<CSenBaseAttribute>& AttributesL() = 0;

        /**
        * Gets all the namespaces of this element in an array.
        * @since Series60 3.0
        * @return array of namespaces. Array will be empty if element has 
        *         no namespaces.
        */
        virtual RPointerArray<CSenNamespace>& NamespacesL() = 0;

        /**
        * Gets the parent element of this element.
        * @since Series60 3.0
        * @return the parent element or NULL if no parent set. 
        *           Ownership is NOT transferred to the caller.
        */
        virtual CSenElement* Parent() = 0;

        /**
        * From MSenElement  Sets the parent element to this element. 
        * Notice that the element is not automatically added as a 
        * child of the parent. Parent's AddElementL() must be called 
        * to achieve that.
        *
        * @since Series60 3.0
        * @param apParent:  The wanted parent. Can be NULL.
        * @return   the parent element
        */
        virtual CSenElement* SetParent(CSenElement* apParent) = 0;

        /**
        * Detach the element from its parent.
        * If the element, or one of its children, is dependent
        * on a namespace declared in the scope of the parent
        * copy those namespace declarations to this element.
        * @since Series60 3.0
        * @return this Element. Ownership is NOT transferred to the caller.
        *         or NULL if no parent was set, and nothing was detached.
        */
        virtual CSenElement* DetachL() = 0;

        /**
        * Gets a child element from a specified index.
        * @since Series60 3.0
        * @param  aIndex:   the index what to get
        * @return child element from a current index. NULL if no child in given
        *         index is found
        */
        virtual CSenElement* Child(TInt aIndex) = 0;

        /**
        * Gets the root element. If no parent element, returns this element.
        * @since Series60 3.0
        * @return the root of the tree. Ownership is not transferred.
        */
        virtual MSenElement& Root() = 0;

        /**
        * Gets the child element with the specified local name.
        * Assumes that namespace is the same as this parent element.
        * @since Series60 3.0
        * @param aLocalName is the XML localname of the requested child element
        * @return   the child element or NULL if the child with the specified 
        *           local name is not found. Ownership is NOT transferred.
        */
        virtual CSenElement* Element(const TDesC8& aLocalName) = 0;

        /**
        * Gets the child element with the specified local name and namespace URI.
        * @since Series60 3.0
        * @param aNsUri is the XML namespace of the requested child element
        * @param aLocalName  is the XML localname of the requested child element
        * @return   the child element or NULL if the child with the specified 
        *           criterias is not found. Ownership is NOT transferred.
        */
        virtual CSenElement* Element(const TDesC8& aNsUri,
                                     const TDesC8& aLocalName) = 0;

        /**
        * Create a new element ready for adding or insertion.
        * If the given namespace prefix is not declared yet
        * the element will not be created and NULL will be returned.
        * @since Series60 3.0
        * @param aNsPrefix: The namespace prefix
        * @param aLocalName:    The new elements localname
        * @return   the new Element just created, or NULL if given prefix was not
        *           declared yet. Ownership is transferred to the caller.
        * Leave codes:  
        *       KErrSenInvalidCharacters if aLocalName contain illegal characters.      
        *       KErrSenZeroLengthDescriptor if aLocalName is zero length.
        */
        virtual CSenElement* CreateElementL(const TDesC8& aNsPrefix,
                                            const TDesC8& aLocalName) = 0;

        /**
        * Insert an Element into the list of children elements
        * so that the inserted Element is placed right before the aBeforeElement.
        * If aBeforeElement is not found, element will be appended to the last
        * position.
        * Function leaves if error occurs in inserting.
        * @since Series60 3.0
        * @param aInsertedElement   the element to be inserted. 
        *                           Ownership is transferred.
        * @param aBeforeElement     the element which will be right next to the 
        *                           element just inserted.
        * @return the inserted Element
        */
        virtual CSenElement& InsertElementL(CSenElement& aInsertedElement,
                                            const CSenElement& aBeforeElement) = 0;

        /**
        * Adds an Element to the children elements. 
        * Sets this element to be the new parent of the given element.
        * @since Series60 3.0
        * @param aElement:  the element to be added. Ownership is transferred.
        * @return the added Element
        */
        virtual CSenElement& AddElementL(CSenElement& aElement) = 0;

        /**
        * Constructs and adds a new element to the children elements. 
        * Sets this element to be the new parent of the given element.
        * @since Series60 3.0
        * @param aNsUri     namespace URI of the new element
        * @param aLocalName local name of the new element
        * @return the added Element
        * Leave codes:  
        *       KErrSenInvalidCharacters if aLocalName contains illegal characters.     
        *       KErrSenZeroLengthDescriptor if aLocalName is zero length.
        */
        virtual CSenElement& AddElementL(   const TDesC8& aNsUri,
                                            const TDesC8& aLocalName) = 0;
        
        /**
        * Constructs and adds a new element to the children elements. 
        * Sets this element to be the new parent of the given element.
        * @since Series60 3.0
        * @param aNsUri     namespace URI of the new element
        * @param aLocalName local name of the new element
        * @param aQName     qualified name of the new element
        * @return the added Element
        * Leave codes:  
        *       KErrSenInvalidCharacters if aLocalName or aQName contain illegal 
        *       characters.     
        *
        *       KErrSenZeroLengthDescriptor if aLocalName or aQName is zero 
        *       length.
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
        * @since Series60 3.0
        * @param aLocalName local name of the new element
        * @return the added Element
        * Leave codes:  
        *       KErrSenInvalidCharacters if aLocalName contains illegal 
        *       characters.     
        *
        *       KErrSenZeroLengthDescriptor if aLocalName is zero length.
        */
        virtual CSenElement& AddElementL(const TDesC8& aLocalName) = 0;

        /**
        * Remove an element from the childs.
        * @since Series60 3.0
        * @param aElement:  the element to be removed.
        * @return The removed element. May be NULL if nothing was removed
        *           (if child element was not found).
        *           The caller TAKES OWNERSHIP of the removed element.
        */
        virtual CSenElement* RemoveElement(CSenElement& aElement) = 0;

        /**
        * Remove an element from the childs.
        * @since Series60 3.0
        * @param    aNsUri:     the namespace URI of the element to be removed.
        * @param    aLocalName: the local name of the element to be removed.
        * @return The removed element. May be NULL if nothing was removed
        *           (if child element was not found).
        *           The caller TAKES OWNERSHIP of the removed element.
        */
        virtual CSenElement* RemoveElement( const TDesC8& aNsUri,
                                            const TDesC8& aLocalName) = 0;

        /**
        * Remove a child element.
        * @since Series60 3.0
        * @param    aLocalName: the local name of the element to be removed.
        * @return The removed element. May be NULL if nothing was removed
        *           (if child element was not found).
        *
        * The caller takes ownership of the removed element.
        */
        virtual CSenElement* RemoveElement(const TDesC8& aLocalName) = 0;

        /**
        * Replaces a child element with another element.
        * Element's local name and namespace URI will be used to check
        * whether or not that element matches with any existing child.
        * If no matching child element is found this method will add a 
        * new child element.
        *
        * @since Series60 3.0
        * @param aElement:  the element to be added. Ownership is transferred.
        * @return The old element. May be NULL if nothing was replaced
        *           (if element was not found from the childs).
        *           The caller TAKES OWNERSHIP of the old element.
        */
        virtual CSenElement* ReplaceElementL(CSenElement& aElement) = 0;

        /**
        * Gets the element as an XML buffer. Buffer will 
        * contain all the child elements.
        * @since Series60 3.0
        * @return element as XML. Caller takes ownership.
        */
        virtual HBufC8* AsXmlL() = 0;
        
        /**
        * Gets the element as an unicode (UCS2) XML buffer.
        * Buffer will contain all the child elements.
        * @since Series60 3.0
        * @return element as XML. Caller takes ownership.
        */
        virtual HBufC* AsXmlUnicodeL() = 0;

        /**
        * Element writes itself to a write stream using UTF-8 
        * character-set encoding.
        * @since Series60 3.0
        * @param aWriteStream The stream to write to.
        */
        virtual void WriteAsXMLToL(RWriteStream& aWriteStream) = 0;

        /**
        * Element writes its namespaces to a write stream 
        * using UTF-8 character-set encoding.
        * @since Series60 3.0
        * @param aWriteStream The stream to write to.
        */
        virtual void WriteNamespacesToL(RWriteStream& aWriteStream) = 0;

        /**
        * Offers the M-class interface pointer to this XML 
        * element.
        * @since Series60 3.0
        * @return the current object as element. Ownership is NOT transferred.
        */
        virtual MSenElement* AsElement() = 0;

        /**
        * Copies content from given element to this element appending to the 
        * existing content if there is any.
        * @since Series60 3.0
        * @param aSource The source element.
        */
        virtual void CopyFromL(CSenElement& aSource) = 0;

        /**
        * (Re-) Set the name and namespace of this Element. The element will be
        * given the localName in the the given namespace. A prefix will be
        * computed from the qualified name.
        * This method should be used with care and is mainly intended for
        * protected use in implementations.
        * @since Series60 3.0
        * @param aNamespaceURI The new namespace URI.
        * @param aLocalName The new local name.
        * @param aQName The new qualified name.
        */
        virtual void Set(const TDesC8& aNamespaceURI, const TDesC8& aLocalName, const TDesC8& aQName) = 0;

        /**
        * Adds new attributes to the element.
        * @since Series60 3.0
        * @param aAttrs:    the array of attributes.
        */
        virtual void AddAttributesL(const RAttributeArray& apAttrs) = 0;
    };

#endif //SEN_ELEMENT_H

// End of File

