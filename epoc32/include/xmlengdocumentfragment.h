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
* Description:       Document fragment node functions
*
*/







#ifndef XMLENGINE_DOCUMENTFRAGMENT_H_INCLUDED
#define XMLENGINE_DOCUMENTFRAGMENT_H_INCLUDED

#include "xmlengnode.h"



/** 
 * Instance of TXmlEngDocumentFragment class represents an document fragment of the DOM tree.
 * 
 * @lib XmlEngineDOM.lib
 * @since S60 v3.1
 */
class TXmlEngDocumentFragment : public TXmlEngNode
{
public:
    /** 
     * Default constructor
     *
     * @since S60 v3.1
     */
	inline TXmlEngDocumentFragment();

protected:
	/** 
     * Constructor
     *
     * @since S60 v3.1
     * @param aInternal Document fragment pointer
     */
	inline TXmlEngDocumentFragment(void* aInternal);
};

#include "xmlengdocumentfragment.inl"

#endif /* XMLENGINE_DOCUMENTFRAGMENT_H_INCLUDED */

