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







#ifndef XMLENGINE_BINARYCONTAINER_H_INCLUDED
#define XMLENGINE_BINARYCONTAINER_H_INCLUDED

#include "xmlengdatacontainer.h"

/**
* Instance of TXmlEngBinaryContainer class represents binary data in 
* DOM tree.
*
* Binary data is treated in general as text nodes in DOM tree. 
* Some of the fields in xmlNode structure are reused in order to save memory. 
* Data is stored in process's heap memory.
*
* Sample code for creating binary container:
* @code  
*      RXmlEngDOMImplementation domImpl;
*      domImpl.OpenL();        ///< opening DOM implementation object 
*      RXmlEngDocument iDoc; 
*      ///< create document element
*      TXmlEngElement elem = iDoc.CreateDocumentElementL(_L8("doc"));
*      ///< create binary container from buffer (str1) and CID equals cid
*      TXmlEngBinaryContainer binData=iDoc.CreateBinaryContainerL(cid,*str1);  
*      elem.AppendChildL(binData);      ///< append container to the dom tree       
*      iDoc.Close();               ///< closing all opened objects
*      domImpl.Close();
* @endcode 
*
* @lib XmlEngineDOM.lib
* @since S60 v3.2
*/
class TXmlEngBinaryContainer : public TXmlEngDataContainer
{
public:

    /**
     * Get content of the container.
     *
     * @since S60 v3.2
     * @return TPtrC8 with container content
     * 
     */
    IMPORT_C TPtrC8 Contents() const;
    
    /**
     * Sets contents of binary container
     *
     * @since S60 v3.2
     * @param aNewContents  The actual value to store
     */
    IMPORT_C void SetContentsL( const TDesC8& aNewContents );

    /**
     * Appends contents to binary container
     *
     * @since S60 v3.2
     * @param aData  Content to be appended to current content
     */    
    EXPORT_C void AppendContentsL( const TDesC8& aData );

    /**
     * Default constructor
	 *
     * @since S60 v3.1
     */
	inline TXmlEngBinaryContainer(); 

protected:

    /**
     * Constructor
     *
     * @since S60 v3.1
     * @param aInternal node pointer
     */
	inline TXmlEngBinaryContainer(void* aInternal);
};

#include "xmlengbinarycontainer.inl"

#endif /* XMLENGINE_BINARYCONTAINER_H_INCLUDED */
