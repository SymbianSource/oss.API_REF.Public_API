/*
* Copyright (c) 2002-2005 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:        Class extends Symbian XML framework parser functionality
*
*/








#ifndef SEN_XMLREADER_H
#define SEN_XMLREADER_H

//  INCLUDES
#include <Xml/Parser.h>
#include <Xml/ParserFeature.h> // for TParserFeature enumeration
#include <Xml/ContentHandler.h>
#include <badesca.h>

using namespace Xml;

// CONSTANTS
const TInt KSenDefaultParserFeature = (TInt)EReportNamespaceMapping;


   
// FORWARD DECLARATIONS
class MSenContentHandlerClient;
class RFs;

// CLASS DECLARATION

/**
*  Class extends Symbian XML framework parser functionality
*  Callers of this class must register some handler which will
*  then receive XML callback events from underlying Symbian
*  XML framework.
*  @lib SenXML.dll
*  @since Series60 3.0
*/
class CSenXmlReader : public CBase, public MContentHandler 
    {
    public:  // Constructors and destructor
    
        /**
        * Standard two-phase constructor.
        * Creates new parser instance using default
        * MIME type "text/xml" (KXmlParserMimeType).
        * @since Series60 3.0
        * @return pointer to a new CSenXmlReader instance.
        */
        IMPORT_C static CSenXmlReader* NewL();

        /**
        * Standard two-phase constructor.
        * Creates new parser instance using default
        * MIME type "text/xml" (KXmlParserMimeType).
        * @since Series60 3.0
        * @return pointer to a new CSenXmlReader instance
        * which is left on cleanup stack.
        */
        IMPORT_C static CSenXmlReader* NewLC();

        /**
        * A constructor with parser feature enabling. Uses default
        * parser MIME type "text/xml" (KXmlParserMimeType).        
        * @since Series60 3.0
        * @param aParserFeature is typically some enumeration introduced 
        *      in Xml::TParserFeature or some other feature introduced in 
        *      some XML parser implementation.
        *  Leave codes:
        *      KErrArgument    if aParserFeature value is negative.
        */ 
        IMPORT_C static CSenXmlReader* NewL(TInt aParserFeature);

        /**
        * A constructor with parser feature enabling. Uses default
        * parser MIME type "text/xml" (KXmlParserMimeType). 
        * @since Series60 3.0
        * @param aParserMimeType is the XML parser MIME type.
        *      If descriptor is of zero-length, then default 
        *      MIME type KXmlParserMimeType is used ("text/xml").
        *      Availability of other MIME types depends on 
        *      underlying parser implementation.
        * @param aParserFeature is typically some enumeration introduced 
        *      in Xml::TParserFeature or some other feature introduced in 
        *      some XML parser implementation.
        *  Leave codes:
        *      KErrArgument    if aParserFeature value is negative.
        */ 
        IMPORT_C static CSenXmlReader* NewLC(TInt aParserFeature);

        /**
        * A constructor with parser MIME type.
        * Standard two-phase constructor.
        * @since Series60 3.0
        * @param aParserMimeType is the XML parser MIME type.
        *      If descriptor is of zero-length, then default 
        *      MIME type KXmlParserMimeType is used ("text/xml").
        *      Availability of other MIME types depends on 
        *      underlying parser implementation.
        * @return pointer to a new CSenXmlReader instance.
        */
        IMPORT_C static CSenXmlReader* NewL(const TDesC8& aParserMimeType);

        /**
        * A constructor with parser MIME type.
        * @since Series60 3.0
        * @param aParserMimeType is the XML parser MIME type.
        *      If descriptor is of zero-length, then default 
        *      MIME type KXmlParserMimeType is used ("text/xml").
        *      Availability of other MIME types depends on 
        *      underlying parser implementation.
        * @return pointer to a new CSenXmlReader instance
        * which is left on cleanup stack.
        */
        IMPORT_C static CSenXmlReader* NewLC(const TDesC8& aParserMimeType);

        /**
        * A constructor with parser MIME type and parser feature enabling.
        * @since Series60 3.0
        * @param aParserFeature is typically some enumeration introduced 
        *      in Xml::TParserFeature or some other feature introduced in 
        *      some XML parser implementation.
        *  Leave codes:
        *      KErrArgument    if aParserFeature value is negative.
        */ 
        IMPORT_C static CSenXmlReader* NewL(const TDesC8& aParserMimeType,
                                            TInt aParserFeature);

        /**
        * A constructor with parser MIME type and parser feature enabling.
        * @since Series60 3.0
        * @param aParserMimeType is the XML parser MIME type.
        *      If descriptor is of zero-length, then default 
        *      MIME type KXmlParserMimeType is used ("text/xml").
        *      Availability of other MIME types depends on 
        *      underlying parser implementation.
        * @param aParserFeature is typically some enumeration introduced 
        *      in Xml::TParserFeature or some other feature introduced in 
        *      some XML parser implementation.
        *  Leave codes:
        *      KErrArgument    if aParserFeature value is negative.
        */ 
        IMPORT_C static CSenXmlReader* NewLC(const TDesC8& aParserMimeType,
                                             TInt aParserFeature);

        /**
        * Destructor.
        */
        IMPORT_C virtual ~CSenXmlReader();

        // New functions

        /**
        * Method to allow client to register a content event handler (for XML) for
        * the current reader.
        * @since Series60 3.0
        * @param aContentHandler The new event handler.
        */
        IMPORT_C virtual void SetContentHandler(
                    MSenContentHandlerClient& aContentHandler);

        /**
        * Method for checking which feature has been enabled in the parser.
        * @since Series60 3.0
        * @return the corresponding integer id of the feature
        */
        IMPORT_C virtual TInt EnabledParserFeature();

        /**
        * @deprecated - use EnabledParserFeature() instead.
        */
        IMPORT_C virtual TInt ParserFeature();

        /**
        * Method for enabling a parser feature.
        * @since Series60 3.0
        * @param aParserFeature is typically some enumeration introduced 
        *           in Xml::TParserFeature or some other feature introduced in 
        *           some XML parser implementation.
        * @return KErrNone or some system-wide error code, if an error has 
        *         occurred.
        */
        TInt SetParserFeature(TInt aParserFeature);     

        /**
        * Parse an XML buffer.
        * @since Series60 3.0
        * @param aBuff Buffer containing document to parse.
        * Note that this method will also leave, if an error
        * is returned from Symbian XML framework. Here are
        * the corresponding enums, and their respective
        * error code values (-1000, -999... and up)
        * (XML-specific errors returned by the XML parser)
        * [from XmlParserErrors.h]
    	* EXmlParserError = -1000,
    	* EXmlSyntax = 2+EXmlParserError,		// -998
    	* EXmlNoElements,						// -997
    	* EXmlInvalidToken,					    // -996
    	* EXmlUnclosedToken,					// -995
    	* EXmlPartialChar,                      // -994
    	* EXmlTagMismatch,                      // -993
    	* EXmlDuplicateAttribute,               // -992
    	* EXmlJunkAfterDocElement,              // -991
    	* EXmlPeRef,                            // -990
    	* EXmlUndefinedEntity,                  // -989
    	* EXmlRecursiveEntity,                  // -988
    	* EXmlAsyncEntity,                      // -987
    	* EXmlBadCharRef,                       // -986
    	* EXmlBinaryEntityRef,                  // -985
    	* EXmlAttributeExternalEntityRef,       // -984
    	* EXmlMisplacedPi,                      // -983
    	* EXmlUnknownEncoding,                  // -982
    	* EXmlIncorrectEncoding,                // -981
    	* EXmlUnclosedCdata,                    // -980
    	* EXmlExternalEntityHandling,           // -979
    	* EXmlNotStandalone,                    // -978
    	* EXmlUnexpectedState,                  // -977
    	* EXmlEntityDeclInPe,                   // -976
    	* EXmlDtdRequired,                      // -975
    	* EXmlFeatureLockedWhileParsing         // -974
        */
        IMPORT_C void ParseL(const TDesC8& aBuff);

        /**
        * Parse an XML document.
        * @since Series60 3.0
        * @param aRFs An open filesession.
        * @param aFileToParse Filename of file to parse.
        */
        IMPORT_C void ParseL(RFs &aRFs, const TDesC& aFileToParse);
        
        // Functions from base classes 
        
        // Callback functions implementing Symbian MContentHandler interface

        /**
        * @since Series60 3.0
        *   Leave codes:
        *       KErrSenXmlContentHandlerNotSet  if XML content handler
        *       for this XML reader has not been set. This leave can
        *               be avoided calling SetContentHandlerL() method prior
        *               parsing some XML document.
        */
        virtual void OnStartDocumentL(const RDocumentParameters& aDocParam, 
                                      TInt aErrorCode);

        /**
        * @since Series60 3.0
        *   Leave codes:
        *       KErrSenXmlContentHandlerNotSet  if XML content handler
        *       for this XML reader has not been set. This leave can
        *       be avoided calling SetContentHandlerL() method prior
        *       parsing some XML document.
        */
        virtual void OnEndDocumentL(TInt aErrorCode);

        /**
        * @since Series60 3.0
        *   Leave codes:
        *       KErrSenXmlContentHandlerNotSet  if XML content handler
        *       for this XML reader has not been set. This leave can
        *       be avoided calling SetContentHandlerL() method prior
        *       parsing some XML document.
        */
        virtual void OnStartElementL(const RTagInfo& aElement, 
                                     const RAttributeArray& aAttributes, 
                                     TInt aErrorCode);

        /**
        * @since Series60 3.0
        *   Leave codes:
        *       KErrSenXmlContentHandlerNotSet  if XML content handler
        *       for this XML reader has not been set. This leave can
        *       be avoided calling SetContentHandlerL() method prior
        *       parsing some XML document.
        */
        virtual void OnEndElementL(const RTagInfo& aElement, TInt aErrorCode);

        /**
        * @since Series60 3.0
        * @param aBytes is the actual XML data, content in UTF-8 form
        * @param aErrorCode KErrNone, or some system-wide error code
        *        if an error has occured.
        */
        virtual void OnContentL(const TDesC8& aBytes, TInt aErrorCode);

        /**
        * @since Series60 3.0
        *   Leave codes:
        *       KErrSenXmlContentHandlerNotSet  if XML content handler
        *       for this XML reader has not been set. This leave can
        *       be avoided calling SetContentHandlerL() method prior
        *       parsing some XML document.
        */
        virtual void OnStartPrefixMappingL(const RString& aPrefix, 
                                           const RString& aUri, 
                                           TInt aErrorCode);

        /**
        * @since Series60 3.0
        *   Leave codes:
        *       KErrSenXmlContentHandlerNotSet  if XML content handler
        *       for this XML reader has not been set. This leave can
        *       be avoided calling SetContentHandlerL() method prior
        *       parsing some XML document.
        */
        virtual void OnEndPrefixMappingL(const RString& aPrefix, TInt aErrorCode);

        /**
        * @since Series60 3.0
        *   Leave codes:
        *       KErrSenXmlContentHandlerNotSet  if XML content handler
        *       for this XML reader has not been set. This leave can
        *       be avoided calling SetContentHandlerL() method prior
        *       parsing some XML document.
        */
        virtual void OnIgnorableWhiteSpaceL(const TDesC8& aBytes, TInt aErrorCode);

        /**
        * @since Series60 3.0
        *   Leave codes:
        *       KErrSenXmlContentHandlerNotSet  if XML content handler
        *       for this XML reader has not been set. This leave can
        *       be avoided calling SetContentHandlerL() method prior
        *       parsing some XML document.
        */
        virtual void OnSkippedEntityL(const RString& aName, TInt aErrorCode);

        /**
        * @since Series60 3.0
        *   Leave codes:
        *       KErrSenXmlContentHandlerNotSet  if XML content handler
        *       for this XML reader has not been set. This leave can
        *       be avoided calling SetContentHandlerL() method prior
        *       parsing some XML document.
        */
        virtual void OnProcessingInstructionL(const TDesC8& aTarget, 
                                              const TDesC8& aData, 
                                              TInt aErrorCode);

        /**
        * OnError is a callback method signalled by Symbian XML
        * framework. Current implementation of this class issues
        * a leave in original ParseL() call on any received by
        * this callback implementation. Used leave code will be
        * the received error code.
        *
        * @since Series60 3.0
        * @param aErrorCode is one of the Symbian XML framework
        * errors listed in XmlFrameworkErrors.h
        *
        * Currently any s
        *
        * If content handler was not set, ParseL will leaves with
        * KErrSenXmlContentHandlerNotSet.
        */
        virtual void OnError(TInt aErrorCode);

        /**
        * This method obtains the interface matching the specified UID.
        * @since Series60 3.0
        * @param    aUid    the UID identifying the required interface.
        * @return   NULL    if no interface matching the UID is found or
        *                    if content handler was not set. Otherwise, 
        *                    returns pointer to the interface.
        */
        virtual TAny* GetExtendedInterface(const TInt32 aUid);
        
    protected:
        
        /**
        * C++ constructor.
        */
        IMPORT_C CSenXmlReader(TInt aParserFeature);
        
        /**
        * Symbian 2nd phase constructor.
        * @param aParserMimeType sets the MIME type of 
        * this XML parser.
        */
        void ConstructL(const TDesC8& aParserMimeType);
        
        // New functions
        
        /**
        * This method re-initializes encapsulated CParser class instance.
        * @since Series60 3.0
        */
        void RecreateParserL();
        
    private:
        static void CleanupParser(TAny* apReader);

        void CleanUp();

    private:    // Data
            // Owned instance of Symbian XML framework (default) XML parser
        CParser* iParser;
            // Not owned pointer to XML content handler.
        MSenContentHandlerClient* iContentHandler;
        // Owned pointer to XML namespace prefix strings
        CDesC8Array* ipNsPrefixes;
        // Owned pointer to XML namespace URI strings
        CDesC8Array* ipNsUris;
        // Owned string pool for XML attribute handling.
        RStringPool iStringPool;
            // Integer indicating currently enabled features
        TInt iEnabledFeature;
    };

#endif  // SEN_XMLREADER_H
    
// End of File

