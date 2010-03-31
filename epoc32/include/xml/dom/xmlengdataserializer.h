/*
* Copyright (c) 2006-2006 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:       Interface class describing class that may be used as
*                serializer for binary data
*
*/







#ifndef XMLENGINE_MDATASERIALIZER_H_INCLUDED
#define XMLENGINE_MDATASERIALIZER_H_INCLUDED

#include "xmlengnode.h"

/**
 * MXmlEngDataSerializer interface used by XML Engine to serialize binary data for example binary data
 * stored in node, external memory chunk (RChunk) or file. This interface may be implemented by client application.
 *
 * @lib XmlEngineDOM.lib
 * @since S60 v3.2
 */
class MXmlEngDataSerializer
    {
public:
    /**
     * Callback for serializing data
     *
     * @since S60 v3.1
     * @param aNode is a node to serialize
     * @return Replacement string for node data
     */
    virtual TPtrC8 SerializeDataL(TXmlEngNode aNode) = 0;
    };


#endif /* XMLENGINE_MDATASERIALIZER_H_INCLUDED */  
