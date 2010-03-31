// Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
//

#ifndef RTCP_H
#define RTCP_H

#include <e32std.h>

/** @file

RTCP is a protocol that only makes sense in the context of RTP, so
the RTCP implementation is an extension of the RTP code, and most
of the relevant classes are defined in rtp.h
*/

class TRtcpRRItem;
class TRtcpRRPart;
class TRtcpSRPart;

/**
@publishedAll
@released

A handle to an RR (Receiver Report) RTP packet.

An instance of this class represents the reception report of one host
about another host; it may have come from either a SR (Sender Report) or
a RR (Receiver Report) packet, which may contain
other RRs (Receiver Reports) as well.

An object of this type is returned from a call to the RRtcpRRPart
indexing operator and specifying the index of the required RR.

Note that resources accessed thorugh this handle are owned by other objects
and therefore has no Close() member function.

@see RRtcpRRPart
*/
class RRtcpRRItem 
	{
public:
    /**
    Default constructor.
    */
	IMPORT_C RRtcpRRItem();

    /**
    Gets the sender's SSRC, i.e. the sender's 32-bit numeric
    synchronisation source identifier.
    
    @return The sender's SSRC.
    */
	IMPORT_C TUint SenderSSRC() const;


    /**
    Gets the number of packets lost.
    
    @return The number of packets lost.
    */
	IMPORT_C TUint PacketsLost() const;


	/** 
	Gets the SSRC related to this packet.
	
	@return The sender's SSRC.
	*/
	IMPORT_C TUint AboutSSRC() const;


	/**
	Gets the number of packets lost, in 256ths of the total number.
	
	@return The number of last packets, in 256ths of the total number.
	*/
	IMPORT_C TUint FractionLost() const;


	/**
	Gets the extended highest sequence number recieved.
	
	@return The extended highest sequence number.
	*/
	IMPORT_C TUint ExtendedHighestSequenceNumber() const;
     
     
	/**
	Gets the interarrival jitter value.
	
	@return The interarrival jitter value.

	*/
	IMPORT_C TUint InterarrivalJitter() const;


	/**
	Gets the time of the last received SR (Sender Report)
	
	@return The time of the last received SR.
	*/
	IMPORT_C TUint LastSRTimestamp() const;


	/**
    Gets the time between the receipt of the last SR (Sender Report) and 
  	the time when this packet was sent.
  	
  	@return The tme difference in 65,536ths of a second. 
	*/
	IMPORT_C TUint DelaySinceLastSR() const;

private:
	friend class RRtcpRRPart;
	TRtcpRRItem* iPtr;
	};

/**
@publishedAll
@released

An array containing the most recent RRs (Receiver Reports) from
all hosts who are reporting on our send stream.

An object of this type is returned by calling RRs() on a handle to
an RTP session (an RRtpSession object).

@see RRtpSession::RRs()
*/	
class RRtcpRRPart
	{
public:
	IMPORT_C RRtcpRRPart(TRtcpRRPart& aRR);
 	/**
	Gets the number of Receiver Reports.
	
	@return The number fo receiver reports.
	*/
	IMPORT_C TInt Count() const;

	IMPORT_C TUint SenderSSRC() const;

	/**
	Gets a specific RR (Receiver Report) as identified by
	the specified index value.
	
	@param aIndex An index value identifying the specific RR.
	              The index is relative to zero, i.e. zero implies
	              the first RR report.
	              The value must not be negative and must be less than
	              the the value returned by Count().
	
	@return A handle to the RR (Receiver Report).
	*/
	IMPORT_C RRtcpRRItem operator [](TInt aIndex) const;
private:
	TRtcpRRPart&		iRRPart;
	};

/**
@publishedAll
@released

A handle to a SR (Sender Report) packet.

RRs (Receiver Reports) received as part of a SR (Sender Report) are classified
with the RRs. The resources accessed through this handle are owned by 
the receive stream object, a RRtpReceiveStream instance, and therefore has no
Close() member function.
*/
class RRtcpSRPart
	{
 public:
    /**
    Default constructor.
    */
	IMPORT_C RRtcpSRPart(TRtcpSRPart& aSr);


	/**
	Gets the absolute time when this SR was sent, in TTime format.
	
	@return The time in NTP format. 
	*/
	IMPORT_C void NTPTimestamp(TTime& aTime) const;


	/**
	Gets the RTP time when this packet was sent.
	
	Note that RTP time is profile dependant and may have an arbitrary start
	time, but this is useful for tying the SR with the timestamps in the
	data stream 
	
	@return The time when the packet was sent.
	*/
	IMPORT_C TUint RTPTimestamp() const;


	/**
	Gets the number of packets that have been sent.
	
	@return The number of packets.
    */
	IMPORT_C TUint PacketCount() const;


	/**
	Gets the number of bytes that have been sent.
	
	@return The number of bytes sent.
	*/
	IMPORT_C TUint ByteCount() const;


	/**
	Gets the profile-specific extension.
	
	@return An un-modifiable descriptor reference to the extension data.
	*/
	IMPORT_C const TDesC8& Extension();
	
	/**
	// added as Fix to Defect PDEF101761  
	Gets the timestamp when this SR was sent, in seconds and fraction
	
	@ return The time in Seconds  and Fraction
	*/
	IMPORT_C void NTPTimestamp(TUint32& aSec,TUint32& aFrac) const;


private:
	TRtcpSRPart& iSrPtr;
	};

#endif // RTCP_H

