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
* Description:       DOM parser functions
*
*/







#ifndef XMLENGINE_DOMPARSER_H_INCLUDED
#define XMLENGINE_DOMPARSER_H_INCLUDED

#include <f32file.h>

class RXmlEngDOMImplementation;
class RXmlEngDocument;

/** 
 * DOM parser class implements methods for parsing XML data.
 *
 * Parse XML data in one chunk. Data can be parsed from file 
 * or memory buffer.
 *
 * Sample code for parsing from buffer:
 * @code
 *      RXmlEngDOMImplementation domImpl;
 *      domImpl.OpenL();              ///< opening DOM implementation object 
 *      RXmlEngDOMParser parser;
 *      parser.Open( domImpl );   ///< opening parser object
 *      RXmlEngDocument iDoc;
 *      iDoc =parser.ParseL( *aInput );   ///< parsing aInput - buffer  
 *      iDoc.Close();               ///< closing all opened objects
 *      parser.Close();
 *      domImpl.Close();
 * @endcode 
 * 
 * Sample code for parsing from file:
 * @code
 *      RXmlEngDOMImplementation domImpl;
 *      domImpl.OpenL();              ///< opening DOM implementation object 
 *      RXmlEngDOMParser parser;
 *      parser.Open( domImpl );   ///< opening parser object
 *      RXmlEngDocument iDoc;
 *      iDoc =parser.ParseFileL( aFileName );   ///< parsing from file  
 *      iDoc.Close();               ///< closing all openend objects
 *      parser.Close();
 *      domImpl.Close();
 * @endcode 
 * 
 * @lib XmlEngineDOM.lib
 * @since S60 v3.1
 */
class RXmlEngDOMParser
{
public:
    /**
     * Default constructor
     */
    IMPORT_C RXmlEngDOMParser();
	
    /** 
     * Opens the parser.
     *
	 * @since S60 v3.2
	 * @param aDOMImpl DOM implementation object
     * @return KErrNone if succeed.
     */
    IMPORT_C TInt Open(RXmlEngDOMImplementation& aDOMImpl);
    
    /** 
     * Closes the parser.
     *
	 * @since S60 v3.2
	 */
    IMPORT_C void Close();

    /** 
     * Parses chunk of XML data from memory buffer and builds DOM RXmlEngDocument.
     *
     * @since S60 v3.2
     * @param aBuffer XML data buffer
     * 
     * @leave KXmlEngErrParsing or one of general codes (e.g. KErrNoMemory)
     */
    IMPORT_C void ParseChunkL(const TDesC8& aBuffer);
    /** 
     * Creates document from parsed chunks of data.
     * Should be called after parsing of allchunks.
     * Ownership over returned RXmlEngDocument object is transferred to the caller of the method.
     *
     * @since S60 v3.2
     * @return RXmlEngDocument created document.
     * 
     * @leave KXmlEngErrParsing or one of general codes (e.g. KErrNoMemory)
     */
    IMPORT_C RXmlEngDocument FinishL();
    
    /** 
     * Parses XML file and builds DOM RXmlEngDocument
     *
     * @since S60 v3.2
	 * @param aRFs File server session
     * @param aFileName File name
     * @param aChunkSize Size of chunk (if 0 chunks won't be used)
     * @return Document handle
     * 
     * @leave KXmlEngErrParsing or one of general codes (e.g. KErrNoMemory)
	 */
    IMPORT_C RXmlEngDocument ParseFileL(RFs &aRFs, const TDesC& aFileName, TUint aChunkSize = 0);

    /** 
     * Parses XML file and builds DOM RXmlEngDocument
     *
     * @since S60 v3.2
	 * @param aFileName File name
     * @param aChunkSize Size of chunk (if 0 chunks won't be used)
     * @return Document handle
     * 
     * @leave KXmlEngErrParsing or one of general codes (e.g. KErrNoMemory)
     */
    IMPORT_C RXmlEngDocument ParseFileL(const TDesC& aFileName, TUint aChunkSize = 0);

    /** 
     * Parses XML data from memory buffer and builds DOM RXmlEngDocument without chunks
     *
	 * @since S60 v3.1
	 * @param aBuffer XML data buffer
     * @return Document handle
     * 
     * @leave KXmlEngErrParsing code (besides system I/O error codes)
     */
    IMPORT_C RXmlEngDocument ParseL(const TDesC8& aBuffer);  

    /** 
     * Return last parsing error code. 
     *
     * @since S60 v3.2
	 * @return positive number
     *
     * @note Error codes are positive numbers. User can find them
     *         in XmlEngDErrors.h
     */
    IMPORT_C TInt GetLastParsingError();
private:
    /** 
     * Parses XML file and builds DOM RXmlEngDocument without usage of chunks
     *
     * @param aRFs File server session
     * @param aFileName File name
     * @return Document handle
     * 
     * @leave KXmlEngErrParsing code (besides system I/O error codes)
	 */
    RXmlEngDocument ParseFileWithoutChunksL(RFs& aRFs, const TDesC& aFileName);

    /** 
     * Cleanup internal data.
     *
     * @since S60 v3.2
     */
    void Cleanup();
private:
    void* iInternal;
    TInt iError;
    RXmlEngDOMImplementation* iImpl;
};



#endif /* XMLENGINE_DOMPARSER_H_INCLUDED */
