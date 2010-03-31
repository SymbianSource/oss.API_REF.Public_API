/*
* Copyright (c) 2006 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  Handle links and embedded content that are not fetched from the network
*
*/


#ifndef BRCTLLINKRESOLVER_H
#define BRCTLLINKRESOLVER_H

//  INCLUDES
#include <e32std.h>
#include <e32base.h>


/**
* The browser guesses the expected content type from 
* the HTML element in which the content was defined.
*/
enum TBrCtlLoadContentType
    {
    ELoadContentTypeAny, ///< The content type is unknown
    /**
    * The content is one of the following:
    * HTML, XHTML, WML
    */
    ELoadContentTypeMarkup,
    ELoadContentTypeImage, ///< The content is an image
    ELoadContentTypeCss, ///< The content is a cascading style sheet
    ELoadContentTypeJavascript, ///< The content is Javascript
    ELoadContentTypePlugin, ///< The content is data for a Netscape plug-in
    /**
    * The content is data for SoundStart. SoundStart is an attribute 
    * that is added to an anchor <a> tag to play audio when an anchor 
    * is in focus or selected.
    */
    ELoadContentTypeSound
    };


// FORWARD DECLARATIONS
class MBrCtlLinkContent;

/**
* The MBrCtlLinkResolver class provides the content of an embedded link 
* or the content of a load request that was initiated by the user. 
* This class is used when the host application stores markup text or 
* other information in a private store. For example, this class could be 
* used for e-mail applications.
*
* Usage:
*
* @code
*  #include <brctllinkresolver.h>
*
*  
* @see S60 Platform: Browser Control API Developer's Guide Version 2.0
* @lib BrowserEngine.lib
* @file brctllinkresolver.h
* @endcode     *
*/
class MBrCtlLinkResolver
    {
    public: // New functions
        
      /**
      * Browser plug-in calls this method when embedded link is found. 
        * Used with ECapabilityClientResolveEmbeddedURL
        * @since 2.8
      * @param aEmbeddedUrl The url of the embedded content
      * @param aCurrentUrl The url of the current page
      * @param aLoadContentType Type of the embedded content
        * Values: One of the following:
        * ELoadContentTypeAny, ELoadContentTypeMarkup, ELoadContentTypeImage
        * ELoadContentTypeCss, ELoadContentTypeJavascript, ELoadContentTypePlug-in
      * @param aEmbeddedLinkContent a callback interface to return the embedded content
      * @return ETrue if the host application resolves the link.  
        * EFalse if the host application does not resolve the link. 
        * @attention The host application makes this request by setting 
        * the ECapabilityClientResolveEmbeddedURL function.
      */
        virtual TBool ResolveEmbeddedLinkL(const TDesC& aEmbeddedUrl,
                                       const TDesC& aCurrentUrl,
                                         TBrCtlLoadContentType aLoadContentType, 
                                         MBrCtlLinkContent& aEmbeddedLinkContent) = 0; 
    
      /**
      * Browser plug-in calls this method when the user requests to load content via selecting a link, or any other way. Used with ECapabilityClientNotifyURL 
        * @since 2.8
      * @param aUrl The requested url
      * @param aCurrentUrl The url of the current page
      * @param aBrCtlLinkContent a callback interface to return the embedded content
      * @return ETrue if the host application resolves the link.
        * EFalse if the host application does not resolve the link. 
        * @attention The host application requests that the browser plug-in call 
        * this function to load new content by setting the ECapabilityClientNotifyURL function.
      */
        virtual TBool ResolveLinkL(const TDesC& aUrl, const TDesC& aCurrentUrl,
                                   MBrCtlLinkContent& aBrCtlLinkContent) = 0;

    /**
    * Cancel all outstanding resolving operations
        * @since 2.8
      * @return void
      */
        virtual void CancelAll() = 0;
    };


/**
* The MBrCtlLinkContent class is an interface that loads the resolved content. 
*
* Usage:
*
* @code
*  #include <brctllinkresolver.h>
*
*  
* @see S60 Platform: Browser Control API Developer's Guide Version 2.0
* @lib BrowserEngine.lib
* @file brctllinkresolver.h
* @endcode     *
*/
class MBrCtlLinkContent
    {
    public: // New functions
        /**
      * Resolver calls this method when content is resolved.
      * @param aContentType The content type of the response
      * @param aCharset The charset of the response. May be empty in case of image
      * @param aContentBuf content data. Ownership is not transfered
      * @return void
      */
        virtual void HandleResolveComplete(const TDesC& aContentType,
                                           const TDesC& aCharset,
                                           const HBufC8* aContentBuf) = 0;

    /**
      * This method is called if there is some error while resolving the content
      * @param aError system wide error code.
      * @return void
      */
        virtual void HandleResolveError(TInt aError) = 0;
    };



#endif      // BRCTLLINKRESOLVER_H
            
// End of File
