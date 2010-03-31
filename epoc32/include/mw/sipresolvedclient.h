/*
* Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:
* Name        : SipResolvedClient.h
* Part of     : SDK API, SIP Client Resolver API
* Version     : 1.0
*
*/



#ifndef CSIPRESOLVEDCLIENT_H
#define CSIPRESOLVEDCLIENT_H

// INCLUDES
#include <ecom/ecom.h>
#include <stringpool.h>

//FORWARD DECLARATIONS
class CSIPHeaderBase;
class CSIPContentTypeHeader;

// CONSTANTS
/** Interface UID of this ECOM interface*/
const TUid KSIPResolvedClientIFUid = { 0x102010dd };

// CLASS DEFINITION
/**
* @publishedAll
* @released
*
* Interface that clients must realize
* in order to enable client resolution mechanism upon the reception
* of SIP request outside the SIP dialog. Data provided in 
* the ECOM resource file or optionally requested from the interface implementation 
* will be used for target client determination by the SIP implementation.
* Note that channel UIDs must be unique accross all SIP clients e.g. clients may
* use UIDs assigned for binaries.
*/
class CSIPResolvedClient : public CBase
	{
	public:	// Destructor

		/**
		* Destructor
		*/
		virtual inline ~CSIPResolvedClient();

	public: // Abstract methods

		/**
		* Returns the SIP client's channel UID that indicates client's
		* channel UID for connection with SIP e.g. CSIP::NewL()
		* @param aMethod the method of the SIP request
        * @param aRequestUri the request-URI of the SIP request
        * @param aHeaders all the headers in the SIP request
        * @param aContent SIP request body; zero-length descriptor if not present
        * @param aContentType the content-type of the SIP request. 
        *        Zero-pointer if body is not present.
		* @return SIP client's communication channel's UID
		*/
		virtual TUid ChannelL(RStringF aMethod,
                              const TDesC8& aRequestUri,
                              const RPointerArray<CSIPHeaderBase>& aHeaders,
                              const TDesC8& aContent,
                              const CSIPContentTypeHeader* aContentType=0) = 0;

		/**
		* Requests the client to connect to SIP with resolved
		* UID in case there's no connection with resolved channel UID.
		* @param aUid previously resolved channel UID
		* @leave KErrNoMemory if out of memory
		* @leave KErrNotFound in case non-existing channel UID was provided
		*/
		virtual void ConnectL(TUid aUid) = 0;

		/**
		* Requests the implementation to provide capabilities in XML format
		* in case they were not defined in the ECOM resource file. The cabablities
		* to be returned must be defined according to the same DTD.
		* This function will be invoked only if the capabilities are not
		* defined in the ECOM resource file.
		*/
		virtual const TDesC8& Capabilities();

	public: // Data

		/// Unique key for implementations of this interface.
		TUid iInstanceKey;

	protected: // Constructors:

		inline CSIPResolvedClient();
	};

#include <sipresolvedclient.inl>

#endif // CSIPRESOLVEDCLIENT_H
