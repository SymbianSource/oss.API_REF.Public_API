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
* Description:       Comment node functions
*
*/







#ifndef XMLENGINE_COMMENT_H_INCLUDED
#define XMLENGINE_COMMENT_H_INCLUDED

#include "xmlengcharacterdata.h"

/** 
 * Instance of TXmlEngComment class represents an XML comments in the DOM tree.
 * 
 * DOM spec: http://www.w3.org/TR/2004/REC-DOM-Level-3-Core-20040407/core.html#ID-FF21A306
 * 
 * @lib XmlEngineDOM.lib
 * @since S60 v3.1
 */
class TXmlEngComment : public TXmlEngCharacterData
{
public:
    /** 
     * Default constructor
     *
     * @since S60 v3.1
     */
    inline TXmlEngComment();

protected:
    /** 
     * Constructor
     *
     * @since S60 v3.1
     * @param aInternal Comment pointer
     */
    inline TXmlEngComment(void* aInternal);
};

#include "xmlengcomment.inl"

#endif /* XMLENGINE_COMMENT_H_INCLUDED */
