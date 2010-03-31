/*
* Copyright (c) 2004-2006 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:       Attribute node functions
*
*/







#ifndef XMLENGINE_ATTR_H_INCLUDED
#define XMLENGINE_ATTR_H_INCLUDED

#include "xmlengnode.h"

/**
 * Instance of TXmlEngAttr class represents an XML attribute in the DOM tree.
 * 
 * Is a storage attributes properties. Implements DOM action for it.
 * 
 * @lib XmlEngineDOM.lib
 * @since S60 v3.1
 */
class TXmlEngAttr : public TXmlEngNode
{
  public:
    /**
     * Default constructor
     *
     * @since S60 v3.1
     */
    inline TXmlEngAttr();


    /**
     * Clones attribute node
     *
     * @since S60 v3.1
     * @return A copy of the attribute with its value
     *
     * @note Namespace of the attribute is reset; use 
     * TXmlEngNode::CopyToL(TXmlEngNode), which finds appropriate or creates
     * new namespace declaration on the new parent node (argument should be
     * an TXmlEngElement handle)
     *
     * @see CopyToL(TXmlEngNode)
     */
    IMPORT_C TXmlEngAttr CopyL() const;

    /**
     * Get owner element
     *
     * @since S60 v3.1
     * @return TXmlEngElement that contains the attribute
     *
     * Same as TXmlEngNode::ParentNode() but returns TXmlEngElement 
     * instead of TXmlEngNode.
     *
     * @note Copies of attributes [TXmlEngAttr::CopyL()] and newly created 
     * attribute nodes [RXmlEngDocument::CreateAttributeL(..)] do not have 
     * parent element until they are attached to some element.
     */
    IMPORT_C const TXmlEngElement OwnerElement() const;

    /**
     * Check attribute name.
     *
     * @since S60 v3.1
     * @return Local name of the attribute
     *
     * @note Equal to TXmlEngNode::Name(), but works faster.
     *
     * Never call this on NULL object!
     * @see TXmlEngNode::Name()
     */
    IMPORT_C TPtrC8 Name() const;

    /**
     * Get element value.
     *
     * @since S60 v3.1
     * @return Attribute's contents
     *
     * @note For values consisting of more then one TXmlEngTextNode node 
     * (as attribute's child) returns only the begining of the value; 
     * this happens when the value is represented by list of TXmlEngTextNode
     * and TXmlEngEntityReference nodes.
     * 
     * @see IsSimpleContents(), WholeValueCopyL()
     */
    IMPORT_C TPtrC8 Value() const; 

    /**
     * Get copy of attribute content
     *
     * @since S60 v3.1
     * @return Complex value of the attribute,
     *     probably consisting of text nodes and entity references
     *
     * Since the value may be composed from a set of TXmlEngTextNode
     * and EntityRefernce nodes, the returned result is newly allocated 
     * string, which should be freed by caller.
     * 
     * <B style="color: red">BE SURE TO FREE THE RESULT STRING!!!</B>
     *
     * Example usage of the API:
     * @code
     *    RBuf8 value;
	 *    attr.WholeValueCopyL(value);
     *    ...
     *    value.Close();
     * @endcode
     *
     * @see TXmlEngAttr::Value(), TXmlEngNode::Value(),
     * TXmlEngNode::IsSimpleTextContents(), 
     * TXmlEngNode::WholeTextContentsCopyL()
     *
     * @note In most cases using Value() is enough (and it needs no memory allocation).
     *     Use IsSimpleTextContents() if there doubts can Value() be used or not safely.
     */
    IMPORT_C void WholeValueCopyL(RBuf8& aBuffer) const;

    /**
     * Sets new value of the attribute. Provided new value will be escaped 
     * as needed.
     *
	 * @ since S60 v3.1
     * @param aNewValue A string value for the attribute
     *
     * The new value should not contain entity references. 
     * Entity references are not expanded, but used as text, because 
     * the ampersand (&) character of reference is escaped.
     *
     * @see SetEscapedValueL(const TDesC8&)
     */
    IMPORT_C void SetValueL(const TDesC8& aNewValue);

    /**
     * Sets new value from escaped XML character data that may contain 
     * entity references.
     *
     * The value as if it is an escaped contents from XML file.
     * If the value contains entity references, then the resulting
     * content of the attribute is a list of TXmlEngTextNode 
     * and TXmlEngEntityRefeerence nodes.
     * Predefined entities are converted into characters they represent.
     * 
     * @param aNewValue is a new attribute value
     * @since S60 v3.1
     *
     * @see TXmlEngAttr::SetValueL(const TDesC8&)
     */
    IMPORT_C void SetEscapedValueL(const TDesC8& aNewValue);

	/**
	 * Sets new attribute value exactly as presented in the string.
	 *
	 * Predefined entities are not converted into characters they represent.
	 *
     * @param aNewValue is a new attribute value 
     * @since S60 v3.2
     *
     * @see TXmlEngAttr::SetValueL(const TDesC8&)
     */
	IMPORT_C void SetValueNoEncL(const TDesC8& aNewValue );

protected:
    /**
     * Constructor
     *
     * @since S60 v3.1
     * @param aInternal attribute pointer
     */
    inline TXmlEngAttr(void* aInternal);
};

#include "xmlengattr.inl"

#endif /* XMLENGINE_ATTR_H_INCLUDED */
