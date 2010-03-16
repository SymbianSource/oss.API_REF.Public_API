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
* Description:       All binary data functions
*
*/







#ifndef XMLENGINE_DATACONTAINER_H_INCLUDED
#define XMLENGINE_DATACONTAINER_H_INCLUDED

#include "xmlengnode.h"


/**
* TXmlEngDataContainer is a class for representing different types
* of binary data in DOM tree.
*
* It can be cusom-serialized using MXmlEngDataSerializer interface which can 
* be set in TXmlEngSerializationOptions used for saving the tree.
*
* @lib XmlEngineDOM.lib
* @since S60 v3.2
*/
class TXmlEngDataContainer : public TXmlEngNode
{
public:

    /**
     * Get CID of data container.
     *
     * @since S60 v3.2
     * @return Cid of data container
     * 
     */
    IMPORT_C TPtrC8 Cid() const;
        
    /**
     * Get data size in bytes
     *
     * @since S60 v3.1
     * @return Number of bytes occupied by data
     */
    IMPORT_C TUint Size() const;

protected:
    /**
     * Default constructor
	 *
     * @since S60 v3.1
     */
	inline TXmlEngDataContainer(); 

    /**
     * Constructor
     *
     * @since S60 v3.1
     * @param aInternal node pointer
     */
	inline TXmlEngDataContainer(void* aInternal);
};


 
#include "xmlengdatacontainer.inl"

#endif /* XMLENGINE_DATACONTAINER_H_INCLUDED */
