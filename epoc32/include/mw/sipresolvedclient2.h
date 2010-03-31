/*
* Copyright (c) 2007-2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:
* Name        : sipresolvedclient2.h
* Part of     : SIP Client Resolver API
* Version     : 1.0
*
*/



#ifndef CSIPRESOLVEDCLIENT2_H
#define CSIPRESOLVEDCLIENT2_H

// INCLUDES
#include <sipacceptcontactheader.h>
#include <sipeventheader.h>
#include <stringpool.h>
#include <uri8.h>
#include <sipheaderbase.h>
#include <sipcontenttypeheader.h>
#include <e32base.h>

// FORWARD DECLARATIONS
class CSdpMediaField;

// CONSTANTS
/** Interface UID of this ECOM interface*/
const TUid KSIPResolvedClient2IFUid = { 0x10282EE5 };

// CLASS DEFINITION
/**
* @publishedAll
* @released
*
* Interface that SIP stack's clients must realize 
* in order to be able to receive incoming SIP requests outside SIP dialogs.
* Note that channel UIDs must be unique accross all SIP clients 
* e.g. clients may use UIDs assigned for binaries.
* 
* SIP stack utilizes the plug-ins that implement 
* this interface in the following manner:
*
* 1) If the SIP request does not contain Accept-Contact-header(s), go to step 2.
*    SIP stack calls CSIPResolvedClient2::MatchAcceptContactsL 
*    for all the plug-ins and applies the following logic: 
*    a) None of the clients match -> go to step 2
*    b) One client matches -> the SIP request is routed to the matching client
*    c) Several clients match -> go to step 2
*
* 2) If the SIP request does not contain Event-header, go to step 3.
*    SIP stack calls CSIPResolvedClient2::MatchEventL 
*    for all the plug-ins and applies the following logic:
*    a) None of the clients match -> go to step 3
*    b) One client matches -> the SIP request is routed to the matching client
*    c) Several clients match -> go to step 3
*
* 3) SIP stack calls CSIPResolvedClient2::MatchRequestL for all the plug-ins.
*    a) None of the clients match -> SIP generates an error response
*    b) One client matches -> the SIP request is routed to the matching client
*    c) Several clients match -> 
*       SIP picks one of these clients randomly and routes the request to it. 
*       The ROM-based clients are preferred.
*/
class CSIPResolvedClient2 : public CBase
    {
    public:    // Destructor

        /**
        * Destructor
        */
        inline ~CSIPResolvedClient2();

    public: // Abstract methods

        /**
        * Matches the Accept-Contact-headers 
        * to the client(s) represented by this plug-in.
        * This function is called for an incoming SIP request 
        * if it contains Accept-Contact-header(s).
        * @param aMethod the method of the SIP request
        * @param aRequestUri the request-URI of the SIP request
        * @param aHeaders all the headers in the SIP request
        * @param aContent SIP request body; 
        *        zero-length descriptor if not present
        * @param aContentType the content-type of the SIP request. 
        *        Zero-pointer if body is not present.
        * @param aClientUid indicates client's UID for 
        *        SIP e.g. the one passed as a parameter to CSIP::NewL().
        * @return ETrue, if the Accept-Contact-headers match to the client
        *         represented by this plug-in, otherwise EFalse. 
        */
        virtual TBool MatchAcceptContactsL(
            RStringF aMethod,
            const CUri8& aRequestUri,
            const RPointerArray<CSIPHeaderBase>& aHeaders,
            const TDesC8& aContent,
            const CSIPContentTypeHeader* aContentType,
            TUid& aClientUid) = 0;

        /**
        * Matches the Event-header to the client(s) represented by this plug-in.
        * This function is called for an incoming SIP request, 
        * if it contains an Event-header and 
        * MatchAcceptContactsL returned EFalse.
        * @param aMethod the method of the SIP request
        * @param aRequestUri the request-URI of the SIP request
        * @param aHeaders all the headers in the SIP request
        * @param aContent SIP request body; 
        *        zero-length descriptor if not present
        * @param aContentType the content-type of the SIP request. 
        *        Zero-pointer if body is not present.
        * @param aClientUid indicates client's UID for 
        *        SIP e.g. the one passed as a parameter to CSIP::NewL().
        * @return ETrue, if the Event-header matches to the client
        *         represented by this plug-in, otherwise EFalse. 
        */
        virtual TBool MatchEventL(
            RStringF aMethod,
            const CUri8& aRequestUri,
            const RPointerArray<CSIPHeaderBase>& aHeaders,
            const TDesC8& aContent,
            const CSIPContentTypeHeader* aContentType,
            TUid& aClientUid) = 0;

        /**
        * Matches the whole SIP request to the client(s) 
        * represented by this plug-in.
        * This function is called if the SIP request does not contain 
        * Accept- or Event-headers or  
        * MatchAcceptContactsL and MatchEventL returned EFalse.
        * @param aMethod the method of the SIP request
        * @param aRequestUri the request-URI of the SIP request
        * @param aHeaders all the headers in the SIP request
        * @param aContent SIP request body; 
        *        zero-length descriptor if not present
        * @param aContentType the content-type of the SIP request. 
        *        Zero-pointer if body is not present.
        * @param aClientUid indicates client's UID for 
        *        SIP e.g. the one passed as a parameter to CSIP::NewL().
        * @return ETrue, if the request can be handled by the client
        *         represented by this plug-in, otherwise EFalse. 
        */
        virtual TBool MatchRequestL(
            RStringF aMethod,
            const CUri8& aRequestUri,
            const RPointerArray<CSIPHeaderBase>& aHeaders,
            const TDesC8& aContent,
            const CSIPContentTypeHeader* aContentType,
            TUid& aClientUid) = 0;

        /**
        * Indicates whether the plug-in implements CSIPResolvedClient2::ConnectL
        * and by calling CSIPResolvedClient2::ConnectL 
        * SIP stack is able to force the client to connect to SIP stack.
        * @return ETrue, if the plug-in supports 
        *         CSIPResolvedClient2::ConnectL, otherwise EFalse.
        */
        virtual TBool ConnectSupported() = 0;

        /**
        * Requests the client to connect to SIP with 
        * the resolved UID in case there's no client connection with the UID.
        * @param aClientUid previously resolved client UID
        */
        virtual void ConnectL(const TUid& aClientUid) = 0;
        
        /**
        * Cancels a ConnectL request for a client.
        * Is called when for example a CANCEL for an INVITE is received 
        * before the client connects to SIP stack.
        * @param aClientUid a UID for which ConnectL was previously called
        */
        virtual void CancelConnect(const TUid& aClientUid) = 0;

        /** 
        * Gets all the SIP message content types supported by the client.
        * @return 0..n SIP Content-Type-headers.
        *         The ownership of the headers is transferred. 
        */
        virtual RPointerArray<CSIPContentTypeHeader> 
            SupportedContentTypesL() = 0;

        /** 
        * Gets all the SDP media-fields supported by the client.
        * @return 0..n SDP media-fields describing the client's media support.
        *         The ownership of the media-fields is transferred. 
        */
        virtual RPointerArray<CSdpMediaField> 
            SupportedSdpMediasL() = 0;
            

        /**
        * Adds client specific SIP-headers for the 200 OK for OPTIONS.
        * Each plug-in must check that the header to be added
        * is not yet in the array. For example when adding header 
        * "Allow: INVITE" the client must check that 
        * the header is not already present in the array.
        * @param aHeaders headers to be added to 200 OK for OPTIONS. 
        *        The ownership of the added headers is transferred to the caller.
        */            
        virtual void AddClientSpecificHeadersForOptionsResponseL(
            RPointerArray<CSIPHeaderBase>& aHeaders) = 0;

    public: // Data

        /// Unique key for implementations of this interface.
        TUid iInstanceKey;
		
		TUid iImplementationUid;
		
    protected: // Constructors:

        inline CSIPResolvedClient2();
    };

#include "sipresolvedclient2.inl"

#endif // CSIPRESOLVEDCLIENT2_H
