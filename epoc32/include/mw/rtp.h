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

#ifndef RTP_H
#define RTP_H

#include <es_sock.h>
 
class TRtpEvent;
class RRtpSession;
class RRtpSendPacket;
class RRtpReceivePacket;
class RRtpReceiveSource;
class RRtpSendSource;
class RRtpHeaderExtension;
class RRtpCSRCs;
class CRtpSession;
class CRtpReceiveSource;
class CRtpSendSource;
class TRtpPacket;
class TRtpSendPacket;

class RRtcpRRPart;
class RRtcpSRPart;
class TRtcpStatistics;
class MPrePostProcessingCallback;

/**
@publishedAll
@released

A set of values that defines the event types that may be handled.

See all variants of the RegisterEventCallbackL() function. 

@see TRtpEvent
*/
enum TRtpEventType
	{
	/** 
	A special event type that is interpreted by all of
	the RegisterEventCallbackL() set of functions to mean that the registered
	callback function is to be called for any event except failure events.
    */
	ERtpAnyEvent = 0,
	
	
    /**
    Defines a base value for session events.
   
    All session event types have values that are greater than this.
    */
	ERtpSessionEventBase = 0x100,
	
	
	/**
	An event type that indicates that a session-level error has occurred.
	
	The event status is a standard Symbian OS error code.
	The callback parameter is used to register interest in only one 
	type of error.
	*/
	ERtpSessionFail      = 0x101, 
	
	
	/**
    An event type that indicates that a new stream has been received.
	
	The event status is the	SSRC of the stream.
	*/
	ERtpNewSource        = 0x102,
	
	
	/**
	An event type that indicates that an RTCP RR (Receiver Report) has been
	received.
	
	The event status is the SSRC of the sender.

	Note - This event type has not been implemented yet.
	*/
	ERtpNewRR            = 0x103,
	
	
	/**
	An event type that indicates that a packet bigger than the expected maximum
	has been received.
	
	When this event occurs, the packet is deleted.
	*/
	ERtpBufferOverflow   = 0x104,
	
	
	/**
	An event type that indicates that a packet has been recived that
	is smaller than its header.
	
	When this event occurs, the packet is deleted.
	*/
	ERtpUndersizedPacket = 0x105,
	
	/* An event type that indicates that an non RTP packet has been received */
	ENonRtpDataReceived = 0x106,
	
	/* An event type that indicates that an non RTCP packet has been received */
	ENonRtcpDataReceived = 0x107,
	/**
	Not an event type, but defines the upper limit for session event
	type values.
    */
	ERtpSessionEventEnd  = 0x1ff,


    /**
    Not an event type but defines a base value for send stream events.
   
    All send stream event types have values that are greater than this.
    */
	ERtpSendEventBase    = 0x200,


	/**
	An event type that indicates that an error has occurred while sending
	a packet.
	
	The event status is a standard Symbian OS error code. The callback parameter
	is used only to register interest in one type of error.
	*/
	ERtpSendFail         = 0x201, 
	
	
	/**
	An event type that indicates that a send packet operation has succeeded.
	*/
	ERtpSendSucceeded    = 0x202,
	
	
	/**
	Not an event type, but defines the upper limit for send stream event 
	type values.
	*/
	ERtpSendEventEnd     = 0x2ff,


    /**
    Not an event type but defines a base value for receive stream events.
   
    All receive stream event types have values that are greater than this.
    */
	ERtpSourceEventBase  = 0x300,
	
	
	/**
	An event type that indicates that an error has occurred.
	
    The event status is a standard Symbian OS error code. The callback parameter
    is used only to register interest in one type of error.
    */
	ERtpSourceFail       = 0x301,
	
	
	/**
	An event type that indicates that an in-sequence packet has been received.
	*/
	ERtpPacketReceived   = 0x302,
	
	
	/**
	An event type that indicates that the  codec has changed.
	
	The event status is the new payload type.
	*/
	ERtpCodecChange      = 0x303,
	
	
	/**
	An event type that indicates that a marker packet has arrived.
	*/
	ERtpMarker           = 0x304,
	
	
	/**
	An event type that indicates that a misordered packet has arrived.
	*/
	ERtpMisorder         = 0x305,
	
	
	/**
	An event type that indicates that a dropout has been detected.
	*/
	ERtpDropout          = 0x306,
	
	
	/**
	An event type that indicates that a SDES (Source Description) RTCP packet
	has been received.
	
	For SDES events, the callback parameter is used to specify the type of 
	SDES. Use a value from TRtpSendPacketType
	
	The event status is the SSRC of the sender.

	@see RRtpSession::TRtpSendPacketType
	*/
	ERtpSDES             = 0x307, 


	/**
	An event type that indicates that a APP (Application Defined) RTCP packet
	has been received.
	
	The event status is the SSRC of the sender.

	*/
	ERtpAPP              = 0x308,
	
	
	/**
	An event type that indicates that a SR (Sender Report) RTCP packet
	has been received.

	The event status is the SSRC of the sender.
	
	*/
	ERtpSR               = 0x309,
	
	
	/**
	An event type that indicates that a RR (Receiver Report) RTCP packet
	has been received.

	The event status is the SSRC of the sender.
	*/
	ERtpRR               = 0x30a,


	/**
	An event type that indicates that a BYE (Goodbye) RTCP packet
	has been received.

	The event status is the SSRC of the sender.
	*/
	ERtpBYE              = 0x30b,

	
	/**
	Not an event type, but defines the upper limit for receive stream event 
	type values.
	*/
	ERtpSourceEventEnd   = 0x3ff
	};


/**
@publishedAll
@released

Indicates whether a callback function can be called once, or more than once.

The appropriate enum value is passed as an argument to the
RegisterEventCallbackL() functions of RRtpSession, RRtpSendSource,
and RRtpReceiveSource, or to the equivalent static functions.

@see RRtpSession
@see RRtpSendSource
@see RRtpReceiveSource
*/
enum TRtpOneShotness 
	{
	/**
	Indicates that the call back function can be called more than once.
	*/
	ERtpNotOneShot = 0,

	
	/**
	Indicates that the call back function is only called once.
	*/
	ERtpOneShot = 0x40000000
	};




/**
@publishedAll
@released
*/
typedef void (*TRtpCallbackFunction)(TAny* aPtr, const TRtpEvent& aEvent);



/**
@publishedAll
*/
const TInt KRtpNoParameter = KRequestPending;


//Needed for recv-only option for RTP or RTCP
//This must map to TRtpType
enum TPacketType
	{	
	EPacketRtp,	
	EPacketRtcp
	};




/**
@publishedAll
@released

A value that can be passed as the second parameter in a call to either
RRtpSendSource::NewSendPacketL() or RRtpSendSource::NewSendPacketLC()
to indicate that no exension is required for the RTP send packet.
*/
const TInt KRtpNoExtension = -1;

/**
@publishedAll
@released

A handle to an RTP session.

This is the interface to the socket-level RTP service, and provides additional
facilities such as header parsing, re-ordering out-of-order packets,
demultiplexing multiple sources etc.

The class abstracts all RTP information going to/from a RTP socket, and its
corresponding RTCP data.

Each RTP endpoint on a device needs its own RTP session.

Multiple hosts streaming to a port on this device correspond
to different RRtpReceiveSource objects associated with the session.

The class behaviour assumes that an active scheduler has already been created
and started; the class does not function correctly if not.
*/
class RRtpSession
	{
 public:
    /**
    A set of bit values passed as a parameter to RRtpSession::SendRTCPPacketL()
    to specify the SDES (Source Description) items that are to be sent with
    the packet. One or more of these may be set.
    
    @see RRtpSession::SendRTCPPacketL()
	*/
	enum TRtpSendPacketType
		{
        /**
        Canonical End-Point Identifier SDES Item.
        */
		ERtcpPacketCNAME = 1, 
		
		/**
        User Name SDES Item.
	    */
		ERtcpPacketNAME  = 2, 
		
	    /**
        Electronic Mail Address SDES Item.
	    */
		ERtcpPacketEMAIL = 4, 
		
        /**
	    Phone Number SDES Item.
	    */		
		ERtcpPacketPHONE = 8, 
		
		/**
	    Geographic User Location SDES Item.
	    */
		ERtcpPacketLOC   = 16,
		
		/**
        Application or Tool Name SDES Item 
	    */
		ERtcpPacketTOOL  = 32,
		
		/**
	    Notice/Status SDES Item 
	    */
		ERtcpPacketNOTE  = 64,
		
		/**
	    Private Extensions SDES Item 
	    */
		ERtcpPacketPRIV  = 128
		};

	inline RRtpSession();
	inline TBool IsOpen() const;

	IMPORT_C void OpenL(RSocketServ& aServer, TSockAddr& aLocalAddr,
						TSockAddr& aRemoteAddr,
						TInt aMaxRXSize, RConnection& aConnection, TInt aPriority = EPriorityNormal, 
						const TDesC8& aCNAME = KNullDesC8);

	
	IMPORT_C void OpenL(RSocketServ& aServer, TSockAddr& aLocalAddr,
						TSockAddr& aRemoteAddr,
						TInt aMaxRXSize, TInt aPriority = EPriorityNormal, 
						const TDesC8& aCNAME = KNullDesC8);

    /**
	@publishedAll
	@released
   	
    Opens the session and initialises it.

    No events will be generated until after control returns to the
    active scheduler. The client has this time to initialise the
    object by adding event callbacks.

    @param aSocket     The connected socket.
    @param aMaxRXSize  The maximum size of a received packet.
    @param aRtcpSocket The RTCP socket.
    @param aPriority   The priority to be used for internal active objects
    @param aCNAME      The CNAME. A sensible default is supplied if none is
                       provided.
    */
	IMPORT_C void OpenL(RSocket& aSocket, TInt aMaxRXSize, 
						RSocket& aRtcpSocket,
						TInt aPriority = EPriorityNormal, 
						const TDesC8& aCNAME = KNullDesC8);

	IMPORT_C void OpenL(RSocket& aSocket, TInt aMaxRXSize,
						TInt aPriority = EPriorityNormal);

   
    /** 
	@internalComponent
    
	Opens the session and initialises it.

    No events will be generated until after control returns to the
    active scheduler. The client has this time to initialise the
    object by adding event callbacks.

	This API uses the RTP Stack implemented as a CF Prorotocol. The SubConnection
	which is passed to the API should be initialised with the RTP Params. 

    @param aServer         Socket Server. 
    @param aLocalAddr      The maximum size of a received packet.
    @param aRemoteAddr     The RTCP socket.
    @param aMaxRXSize      The maximum size of a received packet.
    @param aSubConnection  The subconnection with RTP Parametrs set on it.
    @param aCName          The CNAME. It needs to be same as the one set using the API:
    					   CSubConRTPGenericParamSet::SetCNAMEL(const TDesC8& aCName).
    					   If the descriptor is KNullDesC8,the RTCP session is not created.
                           
    */
    
    #ifndef SYMBIAN_ENABLE_SPLIT_HEADERS
    IMPORT_C void OpenL(RSocketServ& aServer, TSockAddr& aLocalAddr,
						TSockAddr& aRemoteAddr,
						TInt aMaxRXSize, RSubConnection& aSubConnection, TInt aPriority = EPriorityNormal, 
						const TDesC8& aCNAME = KNullDesC8);
	#endif

	

	IMPORT_C void Close();

	IMPORT_C void SetMaxRXSize(TInt aMaxRXSize);

	IMPORT_C TInt MaxRXSize();
    
    
    /** 
	@publishedAll
	@released
	
    Sets the estimated bandwidth used by the session.
    
    This is used to decide when to send RTCP status packets.
    The default	value is read from a resource file and should be a reasonably
	sensible default based on the maximum bandwidth of the handset.
	
	@param aBandwidth The bandwidth in bps.
    */
	IMPORT_C void SetBandwidth(TUint aBandwidth);


    /**
	@publishedAll
	@released
   	
   	Supplies information about the profile-specific RTP
    timestamps. 
    
    This is used to generate the RTP timestamps in RTCP packets.
    It is not used to generate timestamps in RTP packets as they must
    accurately relate to the time of the sample.
   	
   	@param aNow        The time now in RTP format
	@param aConversion The number of nanoseconds per RTP timer tick.
    */
	IMPORT_C void SetRTPTimeConversion(TUint aNow, TUint aConversion);
	IMPORT_C RRtpReceiveSource NewReceiveSourceL();
	IMPORT_C RRtpReceiveSource NewReceiveSourceLC();

    /**
    Registers a callback for the specified event.

	Some compilers may not support templated member functions. A static version
	of this function is available that offers the same behaviour:
    RegisterEventCallbackL(RRtpSession,TRtpEventType,void (*aCallback)(T*, const TRtpEvent&),T*,TRtpOneShotness,TInt)

    @param aType      The type of event.
    @param aCallback  The callback function. The function is templated, and is
                      prototyped to take a pointer to an object of the template
                      type and a const reference to a TRtpEvent. The function
                      returns void.
	@param aPtr       A pointer that is passed to the callback function when
	                  that function is called.
	@param aOneShot   Indicates whether the callback function is only
	                  called once, or can be called more than once.
	@param aParameter A parameter to be passed to the registration function.
	                  The meaning of this depends entirely on the event type.
	                  The parameter is optional - the other overload of this
	                  function is available for registrations that don't need
                      to pass a parameter.                      
	*/
	template <class T> inline void 
		RegisterEventCallbackL(TRtpEventType aType, 
							   void (*aCallback)(T*, const TRtpEvent&), 
							   T* aPtr, 
							   TRtpOneShotness aOneShot,
							   TInt aParameter)
			{
			PrivRegisterEventCallbackL(
				aType|aOneShot, 
				reinterpret_cast<TRtpCallbackFunction>(aCallback),
				static_cast<TAny*>(aPtr), aParameter);
			}

    /**
    Registers a callback for the specified event.

	Some compilers may not support templated member functions. A static version
	of this function is available that offers the same behaviour:
	RegisterEventCallbackL(RRtpSession,TRtpEventType,void (*aCallback)(T*, const TRtpEvent&),T*,TRtpOneShotness)

    @param aType      The type of event.
    @param aCallback  The callback function. The function is templated, and is
                      prototyped to take a pointer to an object of the template
                      type and a const reference to a TRtpEvent. The function
                      returns void.
	@param aPtr       A pointer that is passed to the callback function when
	                  that function is called.
	@param aOneShot   Indicates whether the callback function is only
	                  called once, or can be called more than once. If not
	                  specified, the default is to allow the callback function
	                  to be called more than once.
	*/
	template <class T> inline void 
		RegisterEventCallbackL(TRtpEventType aType, 
							   void (*aCallback)(T*, const TRtpEvent&), 
							   T* aPtr, 
							   TRtpOneShotness aOneShot = ERtpNotOneShot)
			{
			PrivRegisterEventCallbackL(
				aType|aOneShot, 
				reinterpret_cast<TRtpCallbackFunction>(aCallback),
				static_cast<TAny*>(aPtr));
			}


	/**
	@publishedAll
	@released
	
	Gets an array contining the most recent RR (Receiver Report) from
	all hosts who are reporting on our send stream.
	
	@return The array of RRs.
	*/
	IMPORT_C RRtcpRRPart GetRRs();


	/**
	@publishedAll
	@released
	
	Gets the data associated with the specified RTCP SDES (Source Description)
	item.

	Note a that the PRIV (Private Extensions) SDES item is not supported
	by this mechanism.
	
	@param aType  The value identifying the RTCP SDES item.
	
	@param aValue A descriptor reference to the SDES item data. 
	
	@return KErrNotFound if the item type was not found in the most recent RTCP packet
			KErrNone if the operation is successful
	*/
	IMPORT_C TInt GetSDES(const TInt aType, TDes8& aValue);

	
	/**
	@publishedAll
	@released
	
	Sets the data associated with the specified RTCP SDES (Source Description)
	item for sending in the next SDES packet only.

	The function Leaves if duplicate values are set for the same CNAME.

    The SDES Items set by this API is valid only till the stack sends the
    next RTCP Packet. The list of items(except CNAME and NONE) is flushed 
	after every RTCP report is sent

	Note a that the PRIV (Private Extensions) SDES item is not supported
	by this mechanism.
	
	NOTE - This call cannot be used to set a different CNAME for this session.
	The default CNAME is send with every SDES packets.
	
	@param aType  The value identfying the RTCP SDES item.
	@param aValue The SDES item data.

	@return KErrTooBig if the length of the aValue is more than KMaxSdesItemLength(=255)
			KErrNone if the operation is successful
	*/
	IMPORT_C TInt SetSDESL(TInt aType, const TDesC8& aValue);

	/**
	@publishedAll
	@released
	
	Sets the data associated with the PRIV (Private Extensions) SDES item.
	
	@param aPrefix The value identfying the RTCP SDES item.
	@param aValue The SDES item data.

  	@return KErrTooBig if the length of the aValue and aPrefix combined is more 
	                   than KMaxSdesItemLength(=255)
			KErrNone if the operation is successful
	*/
	IMPORT_C TInt SetPRIVL(const TDesC8& aPrefix, const TDesC8& aValue);

    
	/**
	@publishedAll
	@released
	Sends an APP (Application Defined) RTCP Packet.
	
	The packet is sent immediately.
	
	If used with RTCP auto-send, the function disrupts the auto-send
	intervals. Note however that Symbian reserves the right to fix this.
	
	@param aApp A handle to a RTCP APP (Application Defined) packet,
	            for experimental extensions to RTCP.
	*/
	IMPORT_C void SendAPPL(const TDesC8& aName, const TDesC8& aAppData = KNullDesC8, TUint8 aSubType = 0);


	/**
	@publishedAll
	@released
	
	Enables or disables the automatic sending of RTCP SR (Sender Report),
	RR (Receiver Report), and SDES (Source Description) packets.
	
	Note that if automatic sending is not enabled and RTCP sending is required,
	then explicit calls to SendRTCPPacketL() will be required.
	
	@param aAutoSend ETrue, if RTCP packets need to be send automatically
	                 EFalse otherwise.
	
	@see RRtpSession::SendRTCPPacketL()
	*/
	IMPORT_C void SetRTCPAutoSend(TBool aAutoSend);


	/** 
	@publishedAll
	@released
	
	Gets the RTCP Auto Send status. 

	@return True, if RTCP SR, RR and SDES packets are automatically sent,
	        false otherwise
	
	@see RRtpSession::SetRTCPAutoSend()
	*/
	IMPORT_C TBool RTCPAutoSend() const;

	/** 
	@publishedAll
	@released
	
	Sets the RTCP Auto Send interval.
	This disables the RFC based calculation of RTCP intervals.
	To re-enable auto calculation, set the interval to zero.

  	@param aInterval Time interval after which an RTCP auto-send will take place
	*/
	IMPORT_C void SetRtcpInterval(TTimeIntervalMicroSeconds32& aInterval);
	
	/** 
	@publishedAll
	@released	
	Enables Receive only option for rtp or rtcp

	@param aRtpOrRtcp Takes the values from the enum TPacketType

	*/
	IMPORT_C void DontReceive(TInt aRtpOrRtcp);
	
	/** 
	@publishedAll
	@released
    Sends an RTCP packet now. 

	Calling this function doesn't make much sense if auto-send is
	on, as it will result in packets being sent at rather
	incoherent intervals.

	@param aPacketType  Zero or more of the bit values defined by
	                    the TRtpSendPacketType enum. The packet sent will
	                    contain a SR (Sender Report) or RR (Receiver Report),
	                    depending on whether any packets have actually been
	                    sent, together with all SDES (Source Description) items
	                    specified by this parameter.
	                    
	                    Example:
	                    
	                    If every report has go with CNAME,LOC and PRIV...
	                    then set flags as fallows..
	                    
	                    SDES Flags:
	                    1  2  3  4  5  6  7 8 
	                    1  0  0  0  1  0  0 1
	                   

    @see TRtpSendPacketType
	*/
	IMPORT_C void SendRTCPPacketL(TDesC8& aPacket);

	
	/**
	@publishedAll
	@released
	Creates a new send stream, and returns the send stream handle.

	Only one send stream per session is permitted, which means that you must not
	call this function if the send stream has already been created.

	As the send stream is an active object, it cannot handle request
	completion events until control returns to the active scheduler.
	Typically, clients will want to add event registrations before that.

	The Code panics if the SendSource has alredy been opened.

	@return The send stream handle.

	This function may leave if memory is not enough.
	*/
	IMPORT_C RRtpSendSource NewSendSourceL(); 


	/**
	@publishedAll
	@released
	
	Gets the handle to the send stream object associated with this session.

	The send stream object is the one created in a previous call
	to NewSendSourceL(). If the send stream object has not been created, then
	the returned handle will refer to a closed send stream.

    @return The handle to the send stream object.
    
    @see RRtpSendSource NewSendSourceL()
    */
	IMPORT_C RRtpSendSource SendSource(); 


    /**
	@publishedAll
	@released
    
    Sets the number of sequential packets that must be received
	before a stream is considered good.
	
	Sets the maximum number of dropped packets to be considered a
	dropout, as opposed to an ended and restarted stream.
	
	Sets the maximum number of packets by which a packet can be delayed 
	before it is considered dropped.
			
	@param aMaxMisorder The maximum number of packets.
		
	@param aMaxDropout The number of sequential packets.
		
	@param aMinSequential The number of sequential packets.
	@post The session will be 'restarted', 
			i.e. it resets the sequence number sequence and resets all RTCP statistics.
	*/
	IMPORT_C void SetRtpStreamParameters(TInt aMinSequential, TInt aMaxMisorder, TInt aMaxDropout);

	inline TBool operator == (RRtpSession aThat) const;
	inline TBool operator != (RRtpSession aThat) const;

	/**
	@publishedAll
	@released

    The event manager contains a number of callback registrations, each of which 
	binds a function and pointer (normally an object) to a particular kind of
    event. Registrations can be bound to all events on a stream.

	If a function is registered for a particular event, it will be called when 
	that event occurs. One callback function can be associated with more than 1
	callback registration. Callback functions take a pointer argument
	which was supplied as part of the registration

    @param aType Event type
		
	@param aCallback Callback object
		
	@param aPtr Pointer to data that needs to be passed to the callback function

  	@param aParameter Parameter to be passed to internal callback subsystem
	*/
	IMPORT_C void PrivRegisterEventCallbackL(TUint aType, 
										  TRtpCallbackFunction aCallback, 
										  TAny* aPtr, 
										  TInt aParameter);

	/**
	@publishedAll
	@released

    The event manager contains a number of callback registrations, each of which 
	binds a function and pointer (normally an object) to a particular kind of
    event. Registrations can be bound to all events on a stream.

	If a function is registered for a particular event, it will be called when 
	that event occurs. One callback function can be associated with more than 1
	callback registration. Callback functions take a pointer argument
	which was supplied as part of the registration

    @param aType Event type
		
	@param aCallback Callback object
		
	@param aPtr Pointer to data that needs to be passed to the callback function
	*/
	IMPORT_C void PrivRegisterEventCallbackL(TUint aType, 
										  TRtpCallbackFunction aCallback, 
										  TAny* aPtr);
	
	/**
	@publishedAll
	@released
 
	Sets the sampling rate for a Particular Payloadtype
	@param aPayloadType  PayloadType ( Should be between 96-127 ) see RFC 3551
	@param asamplingrate Sampling rate is in rtp ticks per msecs. ( eg for AMR-NB give 8000).
	*/	
	IMPORT_C TInt SetSamplingRate(TInt aPayloadType, TUint aSamplingRate);
	/**
	@publishedAll
	@released

    Gets a handle to the RTP socket; 
	it provides a direct access to the functionality of RTP socket.

	@return The RTP socket for the current session
		
	*/									  
    IMPORT_C RSocket* RtpSocket();
    
    /**
	@publishedAll
	@released

    Gets a handle to the RTCP socket; 
	it provides a direct access to the functionality of RTCP socket.

	@return The RTCP socket for the current session
		
	*/
	IMPORT_C RSocket* RtcpSocket();
	
	/**
	@publishedAll
	@released

    Send a non-RTP (control) data packet asynchronously
    
    @param aSocketType SocketType that tells whether non RTP data has to go through RTP or RTCP socket
    
    @param aData Non RTP data that has to be sent
    
	@param aStatus Tells whether the data has been sent successfully

	*/
 	IMPORT_C void SendDataL(TBool aSocketType, const TDesC8& aData, TRequestStatus&  aStatus);
 	
 	/**
	@publishedAll
	@released

    Sets the remote RTP address for the current RTP session
    
    @param aRemoteAddr Remote RTP address to be set
    
    */
	
	IMPORT_C void SetRemoteAddress(const TSockAddr &aRemoteAddr);

	/**
	@publishedAll
	@released

    Gets the last received non RTP data, If no data found function leaves
    
    @return Returns the last received non RTP data
	*/
	IMPORT_C const TDesC8& NonRtpDataL();
	
	/**
	@publishedAll
	@released

    Gets the last received non RTCP data, If no data found function leaves
    
    @return Returns the last received non RTCP data
	*/
	IMPORT_C TPtr8 NonRtcpDataL();
	
	/**
	@publishedAll
	@released

    Disables the receipt of non RTP data
    
    */
	
	IMPORT_C void DisableNonRtpData();
	
	/**
	@publishedAll
	@released

    Sets the remote RTCP port for the current active RTP session
    
    @param Remote RTCP port value to be set
	*/
	
	IMPORT_C void SetRemoteRtcpPort(TUint aPort);
	
	/**
	@internalComponent

    Gets the remote RTCP Statistics for the current RTP session
    
    @param SSRC of the sender
    @param RTCP Statistics class that stores the RTCP statistics for the 
    current RTP session
	*/
	#ifndef SYMBIAN_ENABLE_SPLIT_HEADERS
    IMPORT_C TInt RtcpStatistics(TUint32 aSsrc, TRtcpStatistics &aRtcpStatistics);
    #endif
	
	/**
	@internalComponent

    Pre and Post processing function for RTP and RTCP packets

	If a function is registered for a particular event, it will be called when 
	that event occurs. One callback function can be associated with more than 1
	callback registration. Callback functions take a pointer argument
	which was supplied as part of the registration

    @param aType Event type
		
	@param aCallback Callback object
		
	@param aPtr Pointer to data that needs to be passed to the callback function
	*/
	#ifndef SYMBIAN_ENABLE_SPLIT_HEADERS
	IMPORT_C void SetPrePostProcessingRegisterCallback(MPrePostProcessingCallback* aPrePostProcessingCallback);
	#endif

 private:
	friend class TRtpEvent;
	#ifdef SYMBIAN_ENABLE_SPLIT_HEADERS
		friend class RRtpSession_Internal;
	#endif
	CRtpSession* iPtr;
	
	// Note: Comments that start with //\ are pseudo-variables used to get
	// Doxygen collaboration diagrams to look right. Ignore them.
	//\ RRtpSendSource sndSource_1_01;
	//\ RRtpReceiveSource rcvSource_1_n;
	//\ TRtpCallback callbacks_1_n;
	//\ TRtpEvent events_1_n;
	};




/**
@publishedAll
@released

A handle to a send stream.

Use this class to manage the creation and sending of packets. 
A session can have only one send stream.

Only one packet can be sent at any one time.
Once a packet has been sent, the packet cannot be closed and no further packets
can be sent until an event signalling the completion of the send operation has
occurred. This will be one of the events defined by the enum values:
ERtpSendSucceeded and ERtpSendFail.

A client must monitor these events so that it can schedule the sending of
subsequent packets.
It does this by implementing and registering callback functions that 
handle these events.

@see TRtpEventType
*/
class RRtpSendSource
	{
 public:
	inline RRtpSendSource();
	inline TBool IsOpen() const;
	IMPORT_C void Close();

	IMPORT_C void Cancel();
    
	template <class T> inline void 
		RegisterEventCallbackL(TRtpEventType aType, 
							   void (*aCallback)(T*, const TRtpEvent&), 
							   T* aPtr, 
							   TRtpOneShotness aOneShot,
							   TInt aParameter)
	{
	PrivRegisterEventCallbackL(aType|aOneShot,
				reinterpret_cast<TRtpCallbackFunction>(aCallback),
				static_cast<TAny*>(aPtr), aParameter);
	}


	template <class T> inline void 
		RegisterEventCallbackL(TRtpEventType aType, 
							   void (*aCallback)(T*, const TRtpEvent&), 
							   T* aPtr, 
							   TRtpOneShotness aOneShot = ERtpNotOneShot)
	{
	PrivRegisterEventCallbackL(aType|aOneShot,
				reinterpret_cast<TRtpCallbackFunction>(aCallback),
				static_cast<TAny*>(aPtr));
	}


	
	IMPORT_C RRtpSendPacket NewSendPacketL(TInt aPayloadSize = 0, 
										   TInt aHeaderExtensionSize = 
										   KRtpNoExtension);
	
	IMPORT_C RRtpSendPacket NewSendPacketLC(TInt aPayloadSize = 0, 
											TInt aHeaderExtensionSize = 
											KRtpNoExtension);

	IMPORT_C TBool IsSending();
	IMPORT_C void SetPayloadType(TUint aPayloadType);
	IMPORT_C void SetDefaultPayloadSize(TInt aPayloadSize);
	/**
	@publishedAll
	@released
	
	Sends a Bye RTCP packet.
	
	@param aReason The reason for sending the Bye RTCP packet.
	*/
	IMPORT_C void ByeL(TDesC8& aReason);
	IMPORT_C TUint32 GetLocalSSRC();

	IMPORT_C void SetAlignment(TInt aAlignment);
	IMPORT_C TInt Alignment() const;

	inline TBool operator == (RRtpSendSource aThat) const;
	inline TBool operator != (RRtpSendSource aThat) const;
	
	/**
	@publishedAll
	@released

    The event manager contains a number of callback registrations, each of which 
	binds a function and pointer (normally an object) to a particular kind of
    event. Registrations can be bound to all events on a stream.

	If a function is registered for a particular event, it will be called when 
	that event occurs. One callback function can be associated with more than 1
	callback registration. Callback functions take a pointer argument
	which was supplied as part of the registration

    @param aType Event type
		
	@param aCallback Callback object
		
	@param aPtr Pointer to data that needs to be passed to the callback function

  	@param aParameter Parameter to be passed to internal callback subsystem
	*/
	IMPORT_C void PrivRegisterEventCallbackL(TUint aType, 
										  TRtpCallbackFunction aCallback, 
										  TAny* aPtr, 
										  TInt aParameter);

	/**
	@publishedAll
	@released

    The event manager contains a number of callback registrations, each of which 
	binds a function and pointer (normally an object) to a particular kind of
    event. Registrations can be bound to all events on a stream.

	If a function is registered for a particular event, it will be called when 
	that event occurs. One callback function can be associated with more than 1
	callback registration. Callback functions take a pointer argument
	which was supplied as part of the registration

    @param aType Event type
		
	@param aCallback Callback object
		
	@param aPtr Pointer to data that needs to be passed to the callback function
	*/
	IMPORT_C void PrivRegisterEventCallbackL(TUint aType, 
										  TRtpCallbackFunction aCallback, 
										  TAny* aPtr);
										  
 private:
	friend class RRtpSession;
	friend class TRtpEvent;
	CRtpSendSource* iPtr;
	// Note: Comments that start with //\ are pseudo-variables used to get
	// Doxygen collaboration diagrams to look right. Ignore them.
	//\ TRtpCallback callbacks_1_n;
	//\ TRtpEvent events_1_n;
	//\ TRtpSendPacket packets_1_n;
	};




/**
@publishedAll
@released

A handle to a receive stream.

An object of this type represents the stream of data on a single SSRC and
delivers the RTP packets and RTCP information in the order they
arrive.

Note that RTP does not guarantee the order of delivery, which means that the 
client may want to buffer the data.
*/
class RRtpReceiveSource 
	{
 public:
	RRtpReceiveSource();
	inline TBool IsOpen() const;

	IMPORT_C void Close();

	
	template <class T> inline void 
		RegisterEventCallbackL(TRtpEventType aType, 
							   void (*aCallback)(T*, const TRtpEvent&), 
							   T* aPtr, 
							   TRtpOneShotness aOneShot,
							   TInt aParameter)
	{
	PrivRegisterEventCallbackL(aType|aOneShot, 
			reinterpret_cast<TRtpCallbackFunction>(aCallback),
			static_cast<TAny*>(aPtr), aParameter);
	}


	template <class T> inline void 
		RegisterEventCallbackL(TRtpEventType aType, 
							   void (*aCallback)(T*, const TRtpEvent&), 
							   T* aPtr, 
							   TRtpOneShotness aOneShot = ERtpNotOneShot)	
	{
	PrivRegisterEventCallbackL(aType|aOneShot, 
				reinterpret_cast<TRtpCallbackFunction>(aCallback),
				static_cast<TAny*>(aPtr));
	}

	/**
	@publishedAll
	@released
	
	Gets the data associated with the specified RTCP SDES (Source Description)
	item.

	Note a that the PRIV (Private Extensions) SDES item is not supported
	by this mechanism.

	@param aType  The value identifying the RTCP SDES item.
	
	@return A descriptor reference to the SDES item data. 
	*/
	IMPORT_C TInt GetSDES(const TInt aType, TDes8& aValue);


	/**
	@publishedAll
	@released
	
	Gets the most recent SR ((Sender Report) from this SSRC.
 
    @return A handle to the SR.
    */
	IMPORT_C RRtcpSRPart GetSR();


	/**
	@publishedAll
	@released
	
	Gets the reason for a BYE packet.
	
	@return A descriptor contaning the BYE message. This is
	        KNullDesC if the source has not sent a BYE packet.
    */
	IMPORT_C TDesC8& GetByeReason();


	/**
	@publishedAll
	@released
	
	Parameters from the last APP (Application Defined) packet.

  	@param aName  Four-bytes application name
	@param aAppData  Applciation specific data
	@param aSubType  Application defined sub-type of the APP packet
	*/
	IMPORT_C void GetLastApp(TPtrC8& aName, TPtrC8& aAppData, TUint& aSubType);

	IMPORT_C RRtpReceivePacket Packet();

	/**
	@publishedAll
	@released
	
	Gets the SSRC of the remote end

	@return The SSRC of the remote end
	*/
	IMPORT_C TUint SSRC() const;

	inline TBool operator == (RRtpReceiveSource aThat) const;
	inline TBool operator != (RRtpReceiveSource aThat) const;

	/**
	@publishedAll
	@released

    The event manager contains a number of callback registrations, each of which 
	binds a function and pointer (normally an object) to a particular kind of
    event. Registrations can be bound to all events on a stream.

	If a function is registered for a particular event, it will be called when 
	that event occurs. One callback function can be associated with more than 1
	callback registration. Callback functions take a pointer argument
	which was supplied as part of the registration

    @param aType Event type
		
	@param aCallback Callback object
		
	@param aPtr Pointer to data that needs to be passed to the callback function

  	@param aParameter Parameter to be passed to internal callback subsystem
	*/
	IMPORT_C void PrivRegisterEventCallbackL(TUint aType, 
										  TRtpCallbackFunction aCallback, 
										  TAny* aPtr, TInt aParameter);

	/**
	@publishedAll
	@released

    The event manager contains a number of callback registrations, each of which 
	binds a function and pointer (normally an object) to a particular kind of
    event. Registrations can be bound to all events on a stream.

	If a function is registered for a particular event, it will be called when 
	that event occurs. One callback function can be associated with more than 1
	callback registration. Callback functions take a pointer argument
	which was supplied as part of the registration

    @param aType Event type
		
	@param aCallback Callback object
		
	@param aPtr Pointer to data that needs to be passed to the callback function
	*/

	IMPORT_C void PrivRegisterEventCallbackL(TUint aType, 
										  TRtpCallbackFunction aCallback, 
										  TAny* aPtr);
	/**
	@publishedAll
	@released
    
    Returns the payloadtype of the newly arrived packet. Should be called before 
    the packet() function.
    If an open Packet is not present the function will leave with KErrNotFound.
 	*/
	IMPORT_C TUint PayLoadTypeL();
 private:
	friend class RRtpSession;
	friend class TRtpEvent;
	CRtpReceiveSource* iPtr;
	// Note: Comments that start with //\ are pseudo-variables used to get
	// Doxygen collaboration diagrams to look right. Ignore them.
	//\ TRtpCallback callbacks_1_n;
	//\ TRtpEvent events_1_n;
	//\ TRtpReceivePacket packets_1_n;
	};




/**
@publishedAll
@released

A handle to an RTP packet.

The packet is accessed through the interface provided by this handle.
*/
class RRtpPacket
	{
 public:
	inline RRtpPacket();
	inline TBool IsOpen() const;

	IMPORT_C void Close();
	IMPORT_C TPtrC8 Payload() const;
	IMPORT_C TUint SequenceNumber() const;
	IMPORT_C TUint Timestamp() const;
	IMPORT_C TUint SSRC() const;
	IMPORT_C RRtpCSRCs CSRCs() const;
	IMPORT_C TBool ExtensionPresent() const;
	IMPORT_C RRtpHeaderExtension Extension() const; 
	IMPORT_C TBool Marker() const;
	IMPORT_C TUint PayloadType() const;
	IMPORT_C TUint Flags() const;

	inline TBool operator == (RRtpPacket aThat) const;
	inline TBool operator != (RRtpPacket aThat) const;

 protected:
	TRtpPacket* iPtr;
	// Note: Comments that start with //\ are pseudo-variables used to get
	// Doxygen collaboration diagrams to look right. Ignore them.
	//\ RRtpHeaderExtension extension_1_01;
	//\ RRtpCSRCs csrcs_1_01;
	};




/**
@publishedAll
@released

A handle to an RTP packet to be sent (an RTP send packet).

@see RRtpSendSource
*/
class RRtpSendPacket : public RRtpPacket
	{
 public:
	IMPORT_C void Send();
	IMPORT_C void Close();
	IMPORT_C TInt SendSync();
	IMPORT_C TDes8& WritePayload();
	IMPORT_C void SetTimestamp(TUint aTimestamp);
	IMPORT_C void SetMarker(TBool aMark);
	IMPORT_C void SetPayloadType(TUint aPayloadType);
	IMPORT_C void SetFlags(TUint aFlags);

	friend class RRtpSendSource;
 private:
	 void InitRtpPacket(TRtpSendPacket* ptr);
	};




/**
@publishedAll
@released

A handle to an RTP packet received from another source.
*/
class RRtpReceivePacket : public RRtpPacket
	{
	friend class RRtpReceiveSource;
	friend class TRtpReceivePacket;
	};




/**
@publishedAll
@released

An RTP event.

An event is generated when anything happens that a client might want
to know about. The class encapulates two pieces of information:
1. An event type as defined by a TRtpEventType value.
2. Additional information whose meaning is dependent on the event type.

Additional information may be implicitly associated with the event, but still
needs to be fetched from another object, for example, when processing
an ERtpPacketReceived event, the packet (represented by a RRtpReceivePacket
handle) must be obtained from the receive stream (represented by a
RRtpReceiveStream handle).

Events are always associated with either an RTP session, a send stream or
a receive stream, and this class has functions for getting the corresponding
handle.

@see RRtpSession
@see RRtpSendSource
@see RRtpReceiveSource
*/
class TRtpEvent
	{
 public:
	IMPORT_C TRtpEvent(TRtpEventType aType, TInt aStatus, TAny* aData);
	IMPORT_C RRtpSession Session() const;
	IMPORT_C RRtpSendSource SendSource() const;
	IMPORT_C RRtpReceiveSource ReceiveSource() const;
	IMPORT_C TBool IsSessionEvent() const;
	IMPORT_C TBool IsSendSourceEvent() const;
	IMPORT_C TBool IsReceiveSourceEvent() const;
        
	inline TRtpEventType Type() const;
	inline TInt Status() const;
 private:
	TRtpEventType iType;
	TInt iStatus;
	TAny* iData;
	};




/**
@publishedAll
@released

Reresents an RTP packet's header extension.

The format of a header extension is profile-defined.
*/
class RRtpHeaderExtension
	{
 public:
	IMPORT_C TUint16 Type() const;
	IMPORT_C void SetType(TUint16 aType);
	IMPORT_C TPtrC8 Data();
 private:
	friend class RRtpPacket;
	TRtpPacket* iPtr;
	};




/**
@publishedAll
@released

A handle representing the list of CSRCs in an RTP packet.
*/
class RRtpCSRCs
	{
 public:
	IMPORT_C TInt Count() const;
	IMPORT_C TUint operator [](TUint aIndex) const;
 private:
	friend class RRtpPacket;
	
	TRtpPacket* iPtr;
	};


/**
@publishedAll
@released

A set of panic codes.

in release mode, different panic codes, such as
KERN-EXEC 3 may be generated instead.
*/
enum TRtpPanicCode
	{
	ERtpPacketIsClosed = 1, 
	ERtpPayloadTypeOutOfRange = 2,
	ERtpSessionIsClosed = 3,
	ERtpSourceIsClosed = 4,
	ERtpNoExtension = 5,
	ERtpLeaveInResponseToError = 6,
	ERtpCantSend2PacketsAtOnce = 7,
	ERtpWrongEventType = 8,
	ERtpWrongParameter = 9,
	ERtpSendSourceAlreadyOpen = 10,
	ERtpSessionAlreadyOpen = 11,
	//
	ERtpCoreController = 100,
	};


GLREF_C void Panic(TRtpPanicCode aPanicCode);

#include "rtp.inl"

#endif // RTP_H

