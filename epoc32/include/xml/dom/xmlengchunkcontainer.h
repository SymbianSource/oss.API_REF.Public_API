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
* Description:       All memory chunk data functions
*
*/







#ifndef XMLENGINE_CHUNKCONTAINER_H_INCLUDED
#define XMLENGINE_CHUNKCONTAINER_H_INCLUDED

#include "xmlengdatacontainer.h"


/**
* Instance of TXmlEngChunkContainer class represents data stored in RChunks in DOM tree
*
* RChunk data is treated in general as text nodes in DOM tree.
* Some of the fields in xmlNode structure are reused in order to save memory. 
* Data is stored in memory referenced to by RChunk.
*
* Sample code for creating chunk container:
* @code  
*      RXmlEngDOMImplementation domImpl;
*      domImpl.OpenL();        ///< opening DOM implementation object 
*      RXmlEngDocument iDoc; 
*      ///< create document element
*      TXmlEngElement elem = iDoc.CreateDocumentElementL(_L8("doc"));
*      ///< create RChunk object with chunkName name and size
*      RChunk chunk;
*      chunk.CreateGlobal(chunkName, size, maxSize);
*      CleanupClosePushL(chunk); 
*      ///< create chunk container from Rchunk object with offset to the 
*      ///< binary data in chunk and binary data size in chunk (binarySize) 
*      TXmlEngChunkContainer binData = iDoc.CreateChunkContainerL(
*									cid,chunk,offset,binarySize); 
*      ///< append chunkcontainer to the dom tree          
*      TXmlEngNode ref = iDoc.DocumentElement().AppendChildL(binData);
*       ///< closing all opened objects
*      CleanupStack::PopAndDestroy();//chunk
*      iDoc.Close();              
*      domImpl.Close();
* @endcode 
*
* @lib XmlEngineDOM.lib
* @since S60 v3.2
*/
class TXmlEngChunkContainer : public TXmlEngDataContainer
{
public:
    /**
     * Get memory chunk reference
     *
     * @since S60 v3.2
     * @return Memory chunk reference
     * 
     */
    IMPORT_C RChunk& Chunk() const;

    /**
     * Get offset of binary data in memory chunk
     *
     * @since S60 v3.2
     * @return Offset of binary data in memory chunk
     */
    IMPORT_C TUint ChunkOffset() const;   
	
protected:
    /**
     * Default constructor
	 *
     * @since S60 v3.1
     */
	inline TXmlEngChunkContainer(); 
	
    /**
     * Constructor
     *
     * @since S60 v3.1
     * @param aInternal node pointer
     */
	inline TXmlEngChunkContainer(void* aInternal);
};



#include "xmlengchunkcontainer.inl"

#endif /* XMLENGINE_CHUNKCONTAINER_H_INCLUDED */
