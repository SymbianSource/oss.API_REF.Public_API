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
* Description:  Interface for SAX Parser Callback events.       
*
*/

#ifndef __MSENCONTENTHANDLERCLIENT_H
#define __MSENCONTENTHANDLERCLIENT_H

//  INCLUDES
#include <stringpool.h>
#include <xml/Attribute.h>

using namespace Xml;

// CLASS DECLARATION

/**
*  Interface for SAX Parser Callback events.
*  If an application (client) needs to be informed of basic parsing events, 
*  it implements this interface and registers an instance with the SAX parser 
*  using the SetContentHandler() method.
*  The parser uses the instance to report basic document-related events like 
*  the start and end of elements.*  
*
*  @lib SenXML.dll
*  @since Series60 3.0
*/
class MSenContentHandlerClient
    {
    public: // New functions
        /**
        * Receive notification of the beginning of a document.
        * Called when OnStartDocumentL callback is received from Symbian XML framework.
        * @return KErrNone or some of the system-wide Symbian error codes.
        */      
        virtual TInt StartDocument() = 0;

        /**
        * Receive notification of the end of a document.
        * Called when OnEndDocumentL callback is received from Symbian XML framework.
        * @return KErrNone or some of the system-wide Symbian error codes.
        */
        virtual TInt EndDocument() = 0;

        /**
        * Receive notification of the beginning of an element.
        * Called when OnStartElementL callback is received from Symbian XML framework.
        * @param aURI:          The Namespace URI, or the empty string if the element 
        *                       has no Namespace URI or if Namespace processing is not 
        *                       being performed.
        * @param aLocalName:    The local name (without prefix)
        * @param aName:         The qualified name
        * @param apAttrs:       The attributes attached to the element. 
        *                       If there are no attributes, it shall be an empty array.
        *                       Namespaces declared in the current element will be 
        *                       located in the array also.
        *        
        * @return               KErrNotSupported    If the class implementing this 
        *                                           interface doesn't override this.
        *                       KErrNone or other system-wide Symbian error codes.
        */
        inline virtual TInt StartElement(   const TDesC8& /*aURI*/, 
                                            const TDesC8& /*aLocalName*/, 
                                            const TDesC8& /*aName*/, 
                                            const RAttributeArray& /* apAttrs */)
            {
            return KErrNotSupported;
            }

        /**
        * Receive notification of the end of an element.
        * Called when OnEndElementL callback is received from Symbian XML framework.
        * @param aURI:          The Namespace URI, or the empty string if the element 
        *                       has no Namespace URI or if Namespace processing is not 
        *                       being performed.
        * @param aLocalName:    The local name (without prefix)
        * @param aName:         The qualified name
        *
        * @return               KErrNotSupported    If the class implementing this 
        *                                           interface doesn't override this.
        *                       KErrNone or other system-wide Symbian error codes.
        */
        inline virtual TInt EndElement( const TDesC8& /*aURI*/, 
                                        const TDesC8& /*aLocalName*/, 
                                        const TDesC8& /*aName*/)
            {
            return KErrNotSupported;
            }


        /**
        * Receive notification of character data inside an element.
        * Called when OnContentL callback is received from Symbian XML framework.
        * @param aBuff: The characters.
        * @param aStart: The start position in the character buffer.
        * @param aLength: The number of characters to use from the character buffer.
        * @return               KErrNotSupported    If the class implementing this 
        *                                           interface doesn't override this.
        *                       KErrNone or other system-wide Symbian error codes.
        */
        inline virtual TInt Characters(const TDesC8& /*aBuf*/, 
                                       const TInt /*aStart*/, 
                                       const TInt /*aLength*/)
            {
            return KErrNotSupported;
            }

        /**
        * Receive notification of a processing instruction
        * Called when OnProcessingInstructionL callback is received from Symbian XML framework.
        * @deprefaceted This method is currently not in use - inlined.
        * @param aTarget:       The processing instruction target.
        * @param aData:         The processing instruction data, 
        *                       or null if none is supplied.
        * @return               KErrNotSupported    If the class implementing this 
        *                                           interface doesn't override this.
        *                       KErrNone or other system-wide Symbian error codes.
        */
        inline virtual TInt ProcessingInstructions(const TDesC8& /*aTarget*/, 
                                                   const TDesC8& /*aData*/)
            {
            return KErrNotSupported;
            }

        /**
        * Receive notification of a skipped entity.
        * Called when OnSkippedEntityL callback is received from Symbian XML framework.
        * @param aName: The name of the skipped entity.
        * @return               KErrNotSupported    If the class implementing this 
        *                                           interface doesn't override this.
        *                       KErrNone or other system-wide Symbian error codes.
        */
        inline virtual TInt SkippedEntity(const TDesC8& /*aName*/)
            {
            return KErrNotSupported;
            } 


        /**
        * Receive notification of error situation during parsing.
        * Called when OnError callback is received from Symbian XML framework.
        * Complete list of error codes is listed under <Xml\XmlFrameworkErrors.h>
        * @param aErrorCode: Error status code.
        * @param aSeverity: Error Severity.
        * @return               KErrNotSupported    If the class implementing this 
        *                                           interface doesn't override this.
        *                       KErrNone or other system-wide Symbian error codes.
        */
        inline virtual TInt Error(TInt /*aErrorCode*/)
            {
            return KErrNotSupported;
            }

        /**
        * Receive notification of prefix mapping start.
        * Called when OnStartPrefixMappingL callback is received from Symbian XML framework.
        * @param aPrefix: The prefix
        * @param aUri: The URI mapped to the prefix.
        * @return               KErrNotSupported    If the class implementing this 
        *                                           interface doesn't override this.
        *                       KErrNone or other system-wide Symbian error codes.
        */
        inline virtual TInt StartPrefixMappingL(  const TDesC8& /* aPrefix */, 
                                                  const TDesC8& /* aUri */)
            {
            return KErrNotSupported;
            }
            
        /**
        * Receive notification of prefix mapping end.
        * Called when OnEndPrefixMappingL callback is received from Symbian XML framework.
        * @param aPrefix: The prefix
        * @return               KErrNotSupported    If the class implementing this 
        *                                           interface doesn't override this.
        *                       KErrNone or other system-wide Symbian error codes.
        */
        inline virtual TInt EndPrefixMappingL(const TDesC8& /* aPrefix */)
            {
            return KErrNotSupported;
            }
            
        /**
        * Receive notification of ignorable whitespace in element content.
        * Called when OnIgnorableWhiteSpaceL callback is received from Symbian XML framework.
        * @param aBytes: The whitespace characters.
        * @return               KErrNotSupported    If the class implementing this 
        *                                           interface doesn't override this.
        *                       KErrNone or other system-wide Symbian error codes.
        */
        inline virtual TInt OnIgnorableWhiteSpaceL(const TDesC8& /* aBytes */) 
            {
            return KErrNotSupported;
            }

        /**
        * Method obtains the interface matching the specified UID.
        * @param    aUid    the UID identifying the required interface.
        * @return   NULL if no interface matching the UID is found or method is not
        *           overridden in the implementing class.
        *           Otherwise, the this pointer cast to that interface.
        */
        inline virtual TAny* GetExtendedInterface(const TInt32 /* aUid */)
            {
            return NULL;
            }
    };

#endif      // __MSENCONTENTHANDLERCLIENT_H   
            
// End of File