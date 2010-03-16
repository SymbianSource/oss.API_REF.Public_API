// Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
// which accompanies this distribution, and is available
// at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
//

#ifndef OBEX_PANICS_H
#define OBEX_PANICS_H

/**
@file
@publishedAll
@released

This file contains details of all OBEX and OBEX Transport panics which may be raised
as a result programming error by the users of OBEX (e.g. Client or Server Application
or a proprietry transport controller).

Internal panic codes should not be raised due to user errors but would reflect
internal Obex programming errors - see inc/obexfaults.h
*/


/**
Category for Obex panics
@see TObexPanicCode
*/
_LIT(KObexPanicCategory, "Obex");

/**
@publishedAll
@released

All Obex panics which may be raised as a result of a client (i.e. external) programming error.
Internal Obex panics are errors listed in TObexFaultCode
@see TObexFaultCode
*/
enum TObexPanicCode
	{
	/** A NULL value was supplied for the data buffer.  Note that this
	pointer can refer to either a memory buffer or a pointer to a RFile object.
 	@see CObexBufObject
 	*/
	ENullPointer					= 0,
	
	
	/** The supplied buffer is of zero length.
	@see CObexBufObject
	*/
	EEmptyBuffer					= 1,
	
	
	/** The header is not of the requested type.
	@see CObexHeader
	*/
	EHeaderAsBadType				= 2,
	
	
	/** An unknown TFileBuffering value was supplied.
 	@see CObexBufObject
 	*/
	EInvalidBufferStrategy			= 3,
	
	
 	/** The RFile object does not point to a valid (open) file.
 	@see CObexBufObject
 	*/
 	ENullFileHandle					= 4,
 	
 	
 	/** An unknown TObexBufferingDetails object was supplied to a buffer object.
 	@see CObexBufObject
 	*/
 	EInvalidBufferDetails			= 5,
 	
 	
	/** A call has been made to CObexServer::RequestIndicationCallback when no
	asynchronous request is outstanding.
	@see MObexNotifyAsync
	@see CObexServer
	*/
	ENoNotificationToComplete		= 6,


	/** A call has been made to CObexServer::Start when an asynchronous request
	is outstanding.
	@see MObexNotifyAsync
	@see CObexServer
	*/
	EChangeInterfaceDuringWait		= 7,



 	/** An invalid packet process event has been signalled.
	*/
	EBadPacketProcessEvent			= 8,


	/** An event is available for signalling, but there is no observer set.
	*/
	ENoPacketProcessObserverSet		= 9,
	
	/** In CObexServer, a call has been made to RequestCompleteIndicationCallback(TObexResponse)
	or RequestIndicationCallback(TObexResponse) with invalid response code or 
    RequestCompleteIndicationCallback(TInt) with invalid Symbian error code
	*/
	EInvalidResponseCodeFromServerApp = 10,
	
	/** In CObexServer, RequestCompleteIndicationCallback has been called in response to Put/GetRequestIndication
	or ReuqestIndicationCallback has been called in response to Put/GetComplete or SetPath Indication
	*/
	EInvalidResponseCallback = 11,

	/** The last server response code has been requested prior to a response from the server.
	*/
	ENoResponseCodeToReturn			= 12,

	/** Adding End of Body header when there is data in the object. 
	*/
	EAddingInvalidEoBHeader = 13,
	
	/** A user has requested to override the handling of a request
	packet at an invalid time.
	*/
	EOverrideRequestHandlingInBadState = 14,
	};



/** 
The category for obex transport panics
*/
_LIT(KObexTransportPanicCat, "ObexTransPanics");

/**
Obex transport panics raised as a result of client programming error
*/
enum TObexTransportPanicCode
	{
	/**
	The number of transport implementations for a given transport name is more than what is allowed.  
	Check that there is not more than the allowed number of plugin resource files containing the same default
	data and inteface uid.
	*/
 	EInvalidNumberOfTransportImplementations	= 0,	
	};

#endif
