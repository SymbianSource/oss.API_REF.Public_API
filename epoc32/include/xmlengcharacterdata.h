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
* Description:       All text nodes functions
*
*/







#ifndef XMLENGINE_CHARACTERDATA_H_INCLUDED
#define XMLENGINE_CHARACTERDATA_H_INCLUDED

#include "xmlengnode.h"

/**
* Instance of TXmlEngCharacterData class represents all kinds of XML text nodes 
* (i.e. text node, comment node) in the DOM tree.
*
* Describe DOM action for nodes that contains text data.
* DOM spec: 
* http://www.w3.org/TR/2004/REC-DOM-Level-3-Core-20040407/core.html#ID-FF21A306
*
* @lib XmlEngineDOM.lib
* @since S60 v3.1
*/
class TXmlEngCharacterData : public TXmlEngNode
{
public:

    /**
     * Get content of the node.
     *
     * @since S60 v3.1
     * @return String with nodes content
     * 
     * This method applies to TXmlEngCDATASection, TXmlEngComment and TXmlEngTextNode nodes.
     */
    IMPORT_C TPtrC8 Contents() const;
    
    /**
     * Sets contents of basic character nodes: TXmlEngTextNode, TXmlEngComment, TXmlEngCDATASection
     *
     * @since S60 v3.1
     * @param aNewContents  The actual value to store
     * 
     * The input is taken as non-escaped: for example, 
     * aNewContents = "123 > 34 && P" will be serialized as "123 &gt; 34 &amp;&amp; P"
     * 
     * Escaped contents may be set only for TXmlEngElement and TXmlEngAttr nodes.
     * @see TXmlEngAttr::SetEscapedValueL(const TDesC8&), TXmlEngElement::SetEscapedTextL(const TDesC8&), 
     */
    IMPORT_C void SetContentsL(const TDesC8& aNewContents);

    /**
     * Extends the contents of the node by appending aString
     *
     * @since S60 v3.1
     * @param aString Content to be added to current content
     */
    IMPORT_C void AppendContentsL(const TDesC8& aString);

    /**
     * Get length of the content
     *
     * @since S60 v3.1
     * @return Number of characters in the contents
     */
    IMPORT_C TUint Length() const;

protected:
    /**
     * Default constructor
	 *
     * @since S60 v3.1
     */
	inline TXmlEngCharacterData(); // protected from API users

    /**
     * Constructor
     *
     * @since S60 v3.1
     * @param aInternal node pointer
     */
	inline TXmlEngCharacterData(void* aInternal);
};


#include "xmlengcharacterdata.inl"

#endif /* XMLENGINE_CHARACTERDATA_H_INCLUDED */

