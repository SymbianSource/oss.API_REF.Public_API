// Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// Default constructor
// 
//



inline RRtpSession::RRtpSession()
		: iPtr(NULL)
	{
	}




/**
Tests whether the RTP session represented by this handle is open.

@return ETrue, if the session is open, false otherwise. 
*/
inline TBool RRtpSession::IsOpen() const
	{
	return (iPtr != NULL);
	}




/**
Tests whether this session handle represents the same session as
the one represented by the specified handle.

@param aThat The handle of the session to be compared.

@return ETrue, if the represented sessions are the same, false otherwise.
*/
inline TBool RRtpSession::operator == (RRtpSession aThat) const 
	{ 
	return aThat.iPtr == iPtr;
	}




/**
Tests whether this session handle represents a different session to the one
represented by the specified handle.

@param aThat The handle of the session to be compared.

@return ETrue, if the represented sessions are different, false otherwise.
*/
inline TBool RRtpSession::operator != (RRtpSession aThat) const 
	{
	return !(aThat == *this);
	}




/**
Default constructor
*/
inline RRtpSendSource::RRtpSendSource()
		: iPtr(NULL)
	{
	}



/**
Tests whether the send stream represented by this handle is open.

@return ETrue, if the send stream is open, false otherwise. 
*/
inline TBool RRtpSendSource::IsOpen() const
	{
	return (iPtr != NULL);
	}




/**
Tests whether this send stream handle represents the same send stream as
the one represented by the specified handle.

@param aThat The handle of the send stream to be compared.

@return ETrue, if the represented send streams are the same, false otherwise.
*/
inline TBool RRtpSendSource::operator == (RRtpSendSource aThat) const 
	{ 
	return aThat.iPtr == iPtr;
	}




/**
Tests whether this send stream handle represents a different send stream to the one
represented by the specified handle.

@param aThat The handle of the send stream to be compared.

@return ETrue, if the represented send streams are different, false otherwise.
*/
inline TBool RRtpSendSource::operator != (RRtpSendSource aThat) const 
	{
	return !(aThat == *this);
	}


/**
Default constructor
*/
inline RRtpReceiveSource::RRtpReceiveSource()
		: iPtr(NULL)
	{
	}




/**
Tests whether the receive stream represented by this handle is open.

@return ETrue, if the receive stream is open, false otherwise. 
*/
inline TBool RRtpReceiveSource::IsOpen() const
	{
	return (iPtr != NULL);
	}




/**
Tests whether this receive stream handle represents the same receive stream as
the one represented by the specified handle.

@param aThat The handle of the receive stream to be compared.

@return ETrue, if the represented receive streams are the same, false otherwise.
*/
inline TBool RRtpReceiveSource::operator == (RRtpReceiveSource aThat) const 
	{ 
	return aThat.iPtr == iPtr;
	}




/**
Tests whether this receive stream handle represents a different receive stream to the one
represented by the specified handle.

@param aThat The handle of the receive stream to be compared.

@return ETrue, if the represented receive streams are different, false otherwise.
*/
inline TBool RRtpReceiveSource::operator != (RRtpReceiveSource aThat) const 
	{
	return !(aThat == *this);
	}


/**
Default constructor.
*/
inline RRtpPacket::RRtpPacket()
		: iPtr(NULL)
	{
	}




/**
Tests whether this packet object is open.

@return ETrue, if the packet is open, false otherwise.
*/
inline TBool RRtpPacket::IsOpen() const
	{
	return (iPtr != NULL);
	}




/**
Tests whether this packet handle represents the same packet as
the one represented by the specified handle.

@param aThat The handle of the packet to be compared.

@return ETrue, if the represented packets are the same, false otherwise.
*/
inline TBool RRtpPacket::operator == (RRtpPacket aThat) const 
	{ 
	return aThat.iPtr == iPtr;
	}




/**
Tests whether this packet handle represents a different packet to the one
represented by the specified handle.

@param aThat The handle of the packet to be compared.

@return ETrue, if the represented packets are different, false otherwise.
*/
inline TBool RRtpPacket::operator != (RRtpPacket aThat) const 
	{
	return !(aThat == *this);
	}

/**
Gets the type of this event.
    
@return The event type.
*/
inline TRtpEventType TRtpEvent::Type() const 
	{ 
	return iType;
	}
	
/**	
Gets the event status.
	
The meaning of this depends on the event type.
	
@see TRtpEventType
*/
inline TInt TRtpEvent::Status() const 
	{ 
	return iStatus;
	}
