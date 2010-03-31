/*
* Copyright (c) 2004-2005 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:       CDATASection node functions
*
*/







#ifndef XMLENGINE_CDATASECTION_H_INCLUDED
#define XMLENGINE_CDATASECTION_H_INCLUDED

#include "xmlengtext.h"

/** 
 * Instance of TXmlEngCDATASection class represents an XML CDATASection in the DOM tree.
 * 
 * @lib XmlEngineDOM.lib
 * @since S60 v3.1
 */
class TXmlEngCDATASection : public TXmlEngTextNode
{
public:
    /** 
     * Default constructor
     */
	inline TXmlEngCDATASection();

    
protected:
    /** 
     * Constructor
     *
     * @since S60 v3.1
     * @param aInternal CDATASection pointer
     */
	inline TXmlEngCDATASection(void* aInternal);
};



#include "xmlengcdatasection.inl"

#endif /* XMLENGINE_CDATASECTION_H_INCLUDED */
