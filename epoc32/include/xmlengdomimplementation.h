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
* Description:       DOM implementation functions
*
*/







#ifndef XMLENGINE_DOMIMPLEMENTATION_H_INCLUDED
#define XMLENGINE_DOMIMPLEMENTATION_H_INCLUDED

#include <e32base.h>

/**
 * The RXmlEngDOMImplementation interface provides a number of methods for performing 
 * operations that are independent of any particular instance of the document object model. 
 *    
 * http://www.w3.org/TR/2004/REC-DOM-Level-3-Core-20040407/core.html#ID-102161490
 *
 * @lib XmlEngineDOM.lib
 * @since S60 v3.1
 */
class RXmlEngDOMImplementation
{
  public:
    
    
	/**
     * Open method needed to initialize the XmlEngineDOM library and should be called before using any
     * class/function from this library. The initialization is required in every client thread in which
     * it used. Calling this method multiple times in a thread is allowed. There should be a call to Close()
     * for every call to Open, per thread.
     *
     * @since S60 v3.2
     * @param aHeap - pointer to client created heap. If aHeap argument is NULL (by default) 
     *                client thread's default heap is used.- NOT IMPLEMENTED YET
     * @return Document handle
     */
    IMPORT_C void OpenL( RHeap* aHeap = NULL );

    /**
     * Close method. It does cleanup of resources used by XmlengineDOM library. Client should call this
     * method at the end of library usage. The library should not be used after this call. If needed, client
     * can initialize the library again by calling Open() method. Libxml2 uses Symbian implementation of POSIX
     * standard libraries. During closure of XmlEngineDOM library, the standard library is also closed by default.
     * User can choose not to close standard libraries when XmlEngine shuts down, by specifying FALSE in aCloseStdLib flag.
     * 
     * @since S60 v3.2
     * @param aCloseStdLib A flag, if TRUE will close the STDLIB resources belonging to this thread.
     *                     else STDLIB is not closed.
     */
    IMPORT_C void Close(TBool aCloseStdLib = ETrue);
};

#endif /* XMLENGINE_DOMIMPLEMENTATION_H_INCLUDED */
