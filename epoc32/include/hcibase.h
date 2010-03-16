// Copyright (c) 1999-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// This is the API that the bluetooth stack expects from the HCI layer.
// It comprises an event notification interface and a command sending interface.
// Implementations of the HCI must derive from CHCIBase.
// 
//



/**
 @file
 @publishedPartner
 @released
*/

#ifndef BT_HCIBASE_H_
#define BT_HCIBASE_H_

#include <bttypes.h>
#include <hcierrors.h>
#include <hcitypes.h>
#include <e32base.h>

#include <bluetooth/hci/hciopcodes.h>
#include <bluetooth/hci/aclpacketconsts.h>
#include <bluetooth/hci/hciconsts.h>
#include <bluetooth/hci/basebandpacketconsts.h>

class CHCICommandFrame;
class CHCIACLDataFrame;
class CHCISCODataFrame;
class CHCIBase;
class MHCIEventObserver;
class CESockIniData;

/** Factory for creating CHCIBase derived class.

To provide a new HCI implementation, re-implement this
class in a DLL, which has a factory fucntion at oridnal 1
which returns a TAny* to the instance of this factory.
NewHCIL() will then be called on the factory to actually
create the CHCIBase derived object.

@released
@publishedPartner
*/	
NONSHARABLE_CLASS(CHCIFactory) : public CBase
    {
public: 
	CHCIFactory();
    virtual TVersion Version() const;
    virtual CHCIBase* NewHCIL(MHCIEventObserver* aParent, CESockIniData* aIni=0);
	virtual CHCICommandFrame* NewHCICommandFrameL(THCIOpcode aOpcode);
	virtual CHCIACLDataFrame* NewHCIACLDataFrameL(TUint16 aSize);
	virtual CHCISCODataFrame* NewHCISCODataFrameL(TUint8 aSize);
	};


/** Abstract HCI Interface class.
 
The Symbian Bluetooth stack uses this abstract class as the 
polymorphic base through which it obtains host controller
access. The actual implementation is dependent on the DLL
loaded at run-time, as specified in the bt.bt.esk file.
The concrete class derived from this should be returned
by the CHCIFactory class, located through ordinal 1 in the
polymorphic DLL.

@publishedPartner
@released
@see 
CHCI for detailed description of the functions.
MHCIEventObserver for the callback interface for events received over HCI.
*/ 
NONSHARABLE_CLASS(CHCIBase) : public CBase
	{
public:

	/** Writes command frame.

	 @param aFrame command frame to write
	 @return KErrBcspWriteCommandDataFailed on failure, KErrNone otherwise
	 @released
	 @publishedPartner
	 */
	virtual TInt WriteCommand(const CHCICommandFrame& aFrame)=0;

	// HCI General exports
	/** Sets option.

	 @param aName option to set
	 @param aData option value
	 @return System wide error code
	 @released
	 @publishedPartner
	 */
    virtual TInt SetOption(TUint aName,const TDesC8& aData)=0;

    /** Gets option.

	 @param aName option to set
	 @param aData desriptor to be filled with option data
	 @return System wide error code
     @released
     @publishedPartner
     */
    virtual TInt GetOption(TUint aName,TDes8& aData)=0;
	
	// HCI Data Calls
    /** Formats ACL Data.

	 @param aFrame Reference to CHCIACLDataFrame which will be formatted with the data supplied in the other params
	 @param aConnH Connection handle for this frame
	 @param aFlags Flags to be set for this frame
	 @param aData Data for this frame
     @released
     @publishedPartner
     */
    virtual void FormatACLData(CHCIACLDataFrame& aFrame, THCIConnHandle aConnH,TUint8 aFlags,const TDesC8& aData)=0;
    
	/** Formats SCO Data.

	 @param aFrame Reference to CHCISCODataFrame which will be formatted with the data supplied in the other params
	 @param aConnH Connection handle for this frame
	 @param aData Data for this frame
     @released
     @publishedPartner
     */
    virtual void FormatSCOData(CHCISCODataFrame& aFrame, THCIConnHandle aConnH, const TDesC8& aData)=0;

    /** Writes ACL Data.

	This forwards a write from link layer to host controller.  The descriptor in the frame is owned by the link layer.

	 @param aFrame the formatted ACL payload from the linkmanager
	 @return System wide error code
     @released
     @publishedPartner
     */
	virtual TInt WriteACLData(const CHCIACLDataFrame& aFrame)=0;

	/** Writes SCO Data.

	This forwards a write from link layer to host controller.  The descriptor in the frame is owned by the link layer.
	 
	 @param aFrame the formatted SCO payload from the linkmanager
	 @return System wide error code
	 @released
	 @publishedPartner
	 */
    virtual TInt WriteSCOData(const CHCISCODataFrame& aFrame)=0;

	// HCI Frame information commands
    /** Gets frame connection handle

	 @param aFrame the frame to return the connection handle of
	 @return the connection handle from aFrame
     @released
     @publishedPartner
     */
	virtual THCIConnHandle FrameConnectionHandle(const CHCIACLDataFrame& aFrame) const =0;

	/** Gets frame opcode.

	 @param aFrame the frame to return the opcode of
	 @return the opcode of aFrame
	 @released
	 @publishedPartner
	 */
	virtual THCIOpcode FrameOpcode(const CHCICommandFrame& aFrame) const =0;
	
	// HCI Commands
	/**	Commands the host controller to start looking for remote devices within range.
  
	 The HCI client should not issue a second  Inquiry() before the first has 
	 completed, because the HC cannot cope with this and will return a 
	 COMMAND_DISALLOWED error

	 @param aFrame The HCI frame to format
	 @param aCode InquiryAccessCode (3 bytes)
	 @param aLength InquiryLength N where N * 1.28s is the no. of seconds for inquiry
	 @param aNumResponses Number of responses from inquiry before it is halted - default 0 is unlimited number of responses.
	 @released
	 @publishedPartner
	 */
    virtual void Inquiry(CHCICommandFrame& aFrame, const TUint aCode=KGIAC, const TUint8 aLength=10, const TUint8 aNumResponses=0)=0;

    /** Cancels an ongoing inquiry.

	 @param aFrame frame to apply any necessary formatting to for inquiry cancel.
     @released
     @publishedPartner
     */
    virtual void InquiryCancel(CHCICommandFrame& aFrame)=0;

    /** Commands the host controller to enter periodic enquiry mode

	 @param aFrame The HCI frame to format
	 @param aMax MaxPeriodLength. The HC chooses a value between aMax and aMin. 
	 @param aMin MinPeriodLength 
	 @param aCode InquiryAccessCode (3 bytes)
	 @param aLength InquiryLength (default N=2)
	 @param aNumResponses Number of Responses (default=0)
     @released
     @publishedPartner
     */
	virtual void PeriodicInquiryMode(CHCICommandFrame& aFrame, TUint16 aMax,TUint16 aMin, const TUint aCode=0,const TUint8 aLength=2,const TUint8 aNumResponses=0)=0;

	/** Exits the periodic inquiry.

	 @param aFrame The HCI frame to format
	 @released
	 @publishedPartner
	 */
    virtual void ExitPeriodicInquiryMode(CHCICommandFrame& aFrame)=0;

	/**	Initiates connection to remote device using the specified baseband packet type.

	 @param aFrame The HCI frame to format
	 @param aBdaddr remove device address
	 @param aPacketType Packet Type
	 @param aPageScanRepetitionMode pages scan repetition mode
	 @param aPageScanMode page scan mode
	 @param aClockOffset Offset between local and remote clock
	 @param aAllowRoleSwitch Whether the remote device is allowed to role switch the local device
	 @released
	 @publishedPartner
	 */
    virtual void CreateConnection(CHCICommandFrame& aFrame, const TBTDevAddr& aBdaddr,
					TUint16 aPacketType=KDM1Packet, TUint8 aPageScanRepetitionMode=0,
					TUint8 aPageScanMode=0, TUint16 aClockOffset=0, TUint8 aAllowRoleSwitch=1)=0;

    /**	Add an SCO connection between the Host Controller and the remote device.

	 @param aFrame The HCI frame to format
	 @param aConnHandle Connection handle
	 @param aPacketType Packet Type
     @released
     @publishedPartner
     */
    virtual void AddSCOConnection(CHCICommandFrame& aFrame, THCIConnHandle aConnHandle,TUint16 aPacketType)=0;







	/**
	Adds a new or modifies an existing synchronous logical transport (SCO or eSCO)
	@param aFrame The HCI frame to format	
	@param aConnHandle Connection handle (2 bytes)
	@param aTransmitBandwidth (4 bytes)
	@param aReceiveBandwidth  (4 bytes)
	@param aMaxLatency        (2 bytes)
	@param aVoiceSettings     (2 bytes)
	@param aRetransmissionEffort (1 bytes)	
	@param aPacketType 		     (2 bytes)	
	*/
	virtual void SetupSynchronousConnectionCommand(CHCICommandFrame& aFrame, TUint16 aConnHandle,
						TUint aTransmitBandwidth,	TUint aReceiveBandwidth, TUint16 aMaxLatency,
						TUint16 aVoiceSettings,	TUint8  aRetransmissionEffort,
						TUint16 aPacketType)=0;

	/**
	Accepts an incoming connection request for an synchronous connection.
	@param aFrame The HCI frame to format	
	@param aBdaddr BDADDR (6 bytes)
	@param aTransmitBandwidth (4 bytes)
	@param aReceiveBandwidth  (4 bytes)
	@param aMaxLatency        (2 bytes)
	@param aContentFormat        (2 bytes)
	@param aRetransmissionEffort (1 bytes)	
	@param aPacketType           (2 bytes)
	*/					
	virtual void AcceptSynchronousConnectionRequestCommand(CHCICommandFrame& aFrame, const TBTDevAddr& aBdaddr,
						TUint aTransmitBandwidth,	TUint aReceiveBandwidth, TUint16 aMaxLatency,
						TUint16 aContentFormat, TUint8  aRetransmissionEffort, TUint16 aPacketType)=0;
	/**
	Rejects the synchronous connction from thre remote device (aBdaddr).

	@param aFrame The HCI frame to format
	@param aBdaddr BDADDR
	@param THCIErrorCode Reject reason
	*/					
	virtual void RejectSynchronousConnectionRequestCommand(CHCICommandFrame& aFrame, const TBTDevAddr& aBdaddr,THCIErrorCode aReason)=0;
																	






    /**	Accepts an incoming connection request.

	 @param aFrame The HCI frame to format
	 @param aBdaddr bluetooth address of remote device
	 @param aRole Role - 0x00=Master, 0x01=Slave.
     @released
     @publishedPartner
     */
    virtual void AcceptConnectionRequest(CHCICommandFrame& aFrame, const TBTDevAddr& aBdaddr,TUint8 aRole)=0;

    /**	Rejects the connection from the remote device.

	 @param aFrame The HCI frame to format
	 @param aBdaddr Bluetooth address of remote device
	 @param THCIErrorCode Reject reason
     @released
     @publishedPartner
     */
    virtual void RejectConnectionRequest(CHCICommandFrame& aFrame, const TBTDevAddr& aBdaddr,THCIErrorCode aReason)=0;

    /**	Replies to the remote host with the supplied link key.

	 @param aFrame The HCI frame to format
	 @param aBdaddr bluetooth address of remote device
	 @param aLinkKey Link key (16 bytes)
     @released
     @publishedPartner
     */
    virtual void LinkKeyRequestReply(CHCICommandFrame& aFrame, const TBTDevAddr& aBdaddr,const TDesC8& aLinkKey)=0;

    /**	Notifies the remote host that the link key was not accepted.

	 @param aFrame The HCI frame to format
	 @param aBdaddr Bluetooth address of remote device
     @released
     @publishedPartner
     */
    virtual void LinkKeyRequestNegativeReply(CHCICommandFrame& aFrame, const TBTDevAddr& aBdaddr)=0;

    /**	Returns to the remote host the requested PIN.

	 @param aFrame The HCI frame to format
	 @param aBdaddr Bluetooth address of remote device
	 @param aPIN PIN Code (up to 16 bytes)
     @released
     @publishedPartner
     */
    virtual void PINCodeRequestReply(CHCICommandFrame& aFrame, const TBTDevAddr& aBdaddr,const TDesC8& aPIN)=0; 

    /**	Notifies the remote host that the PIN code was rejected.

	 @param aFrame The HCI frame to format
	 @param aBdaddr Bluetooth address of remote device
     @released
     @publishedPartner
     */
    virtual void PINCodeRequestNegativeReply(CHCICommandFrame& aFrame, const TBTDevAddr& aBdaddr)=0; 

    /**	Disconnect the ACL or SCO connection corresponding to the supplied handle.

	 @param aFrame The HCI frame to format
	 @param aConnHandle Handle of connection to disconnect
	 @param aReason Reason for disconnection
     @released
     @publishedPartner
     */
	virtual void Disconnect(CHCICommandFrame& aFrame, THCIConnHandle aConnHandle,THCIErrorCode aReason)=0;

	/**	Changes baseband packet type (e.g DH1, DM3 etc.).

	 @param aFrame The HCI frame to format
	 @param aConnHandle Connection Handle
	 @param aType Packet Type.  This should be one of the consts defined in hcibase.h e.g. KDM1Packet.
	 @released
	 @publishedPartner
	 */
	virtual void ChangeConnectionPacketType(CHCICommandFrame& aFrame, THCIConnHandle aConnHandle,TUint16 aType)=0;

	/** Perform authenticaction request.	

	 @param aFrame The HCI frame to format
	 @param aConnHandle Connection Handle
	 @released
	 @publishedPartner
	 */
    virtual void AuthenticationRequest(CHCICommandFrame& aFrame, THCIConnHandle aConnHandle)=0;

    /** Sets connection encryption

	 @param aFrame The HCI frame to format
	 @param aConnHandle Connection Handle
	 @param aEnable Enable flag ETrue=Enable link encryption, EFalse=Disable link encryption
     @released
     @publishedPartner
     */
    virtual void SetEncryptionEnable(CHCICommandFrame& aFrame, THCIConnHandle aConnHandle,TBool aEnable)=0;

    /**	Notifies host of need to change connection key for the supplied connection handle.

	 @param aFrame The HCI frame to format
	 @param aConnHandle Connection Handle
     @released
     @publishedPartner
     */
    virtual void ChangeConnectionLinkKey(CHCICommandFrame& aFrame, THCIConnHandle aConnHandle)=0;

    /**	Not used.

	 @param aFrame The HCI frame to format
	 @param aKeyFlag Link Key Flag. Possible values are ETrue to use temporary link key or EFalse to  use regular link key
     @released
     @publishedPartner
     */
    virtual void MasterLinkKey(CHCICommandFrame& aFrame, TBool aKeyFlag)=0;

    /**	Retrieves the remote hosts advertised hardware/firmware features.

	 @param aFrame The HCI frame to format
	 @param aConnHandle Connection Handle
     @released
     @publishedPartner
     */
    virtual void ReadRemoteSupportedFeatures(CHCICommandFrame& aFrame, THCIConnHandle aConnHandle)=0;

    /**	Retrieve remote hosts HW/Firmware revision information.

	 @param aFrame The HCI frame to format
	 @param aConnHandle Connection Handle
     @released
     @publishedPartner
     */
    virtual void ReadRemoteVersionInfo(CHCICommandFrame& aFrame, THCIConnHandle aConnHandle)=0;

	/** Request on human redable name of remote host.

	 @param aFrame The HCI frame to format
	 @param aBdaddr The bluetooth address of device on which we seek to find a name
	 @param aPageScanRepetitionMode Page scan repetition mode
	 @param aPageScanMode Page scan mode
	 @param aClockOffset Offset of remote device clock from local device clock
	 @released
	 @publishedPartner
	 */
    virtual void RemoteNameRequest(CHCICommandFrame& aFrame, const TBTDevAddr& aBdaddr, TUint8 aPageScanRepetitionMode=0,
					TUint8 aPageScanMode=0, TBasebandTime aClockOffset=0)=0;

    /**	Retrieve offset of remote clock from local clock.

	 @param aFrame The HCI frame to format
	 @param aConnHandle Connection Handle
     @released
     @publishedPartner
     */
    virtual void ReadClockOffset(CHCICommandFrame& aFrame, THCIConnHandle aConnHandle)=0;

	// HCI Link Policy Commands 
    /**	Write local link policy settings

	 @param aFrame The HCI frame to format
	 @param aConnHandle Connection Handle
	 @param aSettings @see Bluetooth HCI specification
     @released
     @publishedPartner
     */
	virtual void WriteLinkPolicySettings(CHCICommandFrame& aFrame, THCIConnHandle aConnHandle, TUint16 aSettings)=0;

	/**	Switch radio and host controller to Hold mode.

	 @param aFrame The HCI frame to format
	 @param aConnHandle Connection Handle 
	 @param aHoldMaxInterval Max Hold Interval N, where Time of Hold=N*0.625ms (1 baseband slot)
	 @param aHoldMinInterval Min Hold interval N, as above (both up to 40.9 sec)
	 @released
	 @publishedPartner
	 */
    virtual void HoldMode(CHCICommandFrame& aFrame, THCIConnHandle aConnHandle, TBasebandTime aHoldMaxInterval, 
		TBasebandTime aHoldMinInterval)=0;

	/**	Switch radio and host controller to Sniff mode.

	 @param aFrame The HCI frame to format
	 @param aConnHandle Connection Handle
	 @param aSniffMaxInterval Max Sniff length (Max number of acceptable slots in a sniff period) N, where the interval (time between sniffs)=N*0.625ms (1 baseband slot)
	 @param aSniffMinInterval Min Sniff interval , as above
	 @param aAttemptSlots Sniff Attempt - the period the slave will listen after each sniff interval
	 @param aTimeOutSlots Sniff Timeout - time listening for packets as long as some arrive
	 @released
	 @publishedPartner
	 */
    virtual void SniffMode(CHCICommandFrame& aFrame, THCIConnHandle aConnHandle,TBasebandTime aSniffMaxInterval,TBasebandTime
		aSniffMinInterval, TBasebandTime aAttempSlots, TBasebandTime aTimeOutSlots)=0;

	/**	Switch radio and host out of the Sniff mode.

	 @param aFrame The HCI frame to format
	 @param aConnHandle Connection Handle
	 @released
	 @publishedPartner
	 */
    virtual void ExitSniffMode(CHCICommandFrame& aFrame, THCIConnHandle aConnHandle)=0;

	/**	Switch radio and host controller to the Park mode.

	 @param aFrame The HCI frame to format
	 @param aConnHandle Connection Handle
	 @param aBeaconMax Beacon Max Interval Length N where interval between beacons=N*0.625ms
	 @param aBeaconMin Beacon Min Interval Length N where interval between beacons=N*0.625ms
	 @released
	 @publishedPartner
	 */
    virtual void ParkMode(CHCICommandFrame& aFrame, THCIConnHandle aConnHandle, TBasebandTime aBeaconMaxInterval, 
		TBasebandTime aBeaconMinInterval)=0;

    /**	Switch radio and host controller off the Park mode.

	 @param aFrame The HCI frame to format
 	 @param aConnHandle Connection Handle
     @released
     @publishedPartner
     */
    virtual void ExitParkMode(CHCICommandFrame& aFrame, THCIConnHandle aConnHandle)=0;

	/**	Initiate role discovery for the supplied connection handle.

	 @param aFrame The HCI frame to format
	 @param aConnHandle Connection Handle
	 @released
	 @publishedPartner
	 */
    virtual void RoleDiscovery(CHCICommandFrame& aFrame, THCIConnHandle aConnHandle)=0;

	/**	Switch current role (master / slave) for the physical link associated with the bluetooth device address provided.
	
	 @param aFrame The HCI frame to format
	 @param aRole New role 
	 @param aAddr Bluetooth device address of remote device 
	 @released
	 @publishedPartner
	 */
	virtual void SwitchRole(CHCICommandFrame& aFrame, TBTBasebandRole aRole, const TBTDevAddr& aAddr)=0;


	// HCI Host Controller and Baseband Commands 
	/**	Sets the mask for the reception or the filtering-out of HCI events from the host controller.

 	 @param aFrame The HCI frame to format
	 @param aMask Event Mask
	 @released
	 @publishedPartner
	 */
    virtual void SetEventMask(CHCICommandFrame& aFrame, const THCIEventMask& aMask)=0;

    /**	Resets the Host Controller hardware state. 

	 @param aFrame The HCI frame to format
     @released
     @publishedPartner
     */
    virtual void Reset(CHCICommandFrame& aFrame)=0;

    /**	Set the filter mask for remotely initiated  events.

	 @param aFrame The HCI frame to format
	 @param aData Denotes the filter 'category' and its particular properties as such its 'category'/type may be EClearAllFilters, EInquiryResultFilter or EConnectionSetupFilter. Then its condition type (aData.iConditionType) can be as defined in the spec
     @released
     @publishedPartner
     */
    virtual void SetEventFilter(CHCICommandFrame& aFrame, const THCIEventCondition& aData)=0;

    /**	Flush buffers corresponding to the supplied connection handle.

	 @param aFrame The HCI frame to format
	 @param aConnHandle Connection Handle
     @released
     @publishedPartner
     */
    virtual void Flush(CHCICommandFrame& aFrame, THCIConnHandle aConnHandle)=0;

    /**	Creates a new unit key in the host controller.

	 @param aFrame The HCI frame to format
     @released
     @publishedPartner
     */
    virtual void CreateNewUnitKey(CHCICommandFrame& aFrame)=0;

    /**	Reads out from the host controller the stored link key for given device address

	 @param aFrame The HCI frame to format
	 @param aBdaddr Bluetooth device address to read the link key for.
	 @param aFlag Read all keys flag
     @released
     @publishedPartner
     */
    virtual void ReadStoredLinkKey(CHCICommandFrame& aFrame, const TBTDevAddr& aBdaddr,THCIReadAllKeysFlag aFlag)=0;

	/**	Writes a Link Key to the Host Controllers volatile storage memory.  You can write as many keys as you want to storage - this function just does one at a time.
	
	 @param aFrame The HCI frame to format
	 @param aNumOfKeysToWrite Number of keys to write to storage
	 @param aBdaddr Bluetooth device address for the associated link key
	 @param aLinkKey The Link Key
	 @released
	 @publishedPartner
	 */
    virtual void WriteStoredLinkKey(CHCICommandFrame& aFrame, /*TUint8 aNumOfKeysToWrite,*/
		const TBTDevAddr& aBdaddr,const TDesC8& aLinkKey)=0;

    /**	Delete the link key stored in the host controller's volatile storage.

	 @param aFrame The HCI frame to format
	 @param aBdaddr Bluetooth device address associated with the link key to delete.
	 @param aFlag Delete options flag
     @released
     @publishedPartner
     */
    virtual void DeleteStoredLinkKey(CHCICommandFrame& aFrame, const TBTDevAddr& aBdaddr,THCIDeleteAllKeysFlag aFlag)=0;

    /**	Sets the local Bluetooth device name.

	 @param aFrame The HCI frame to format
	 @param aName Local device name (max 248 characters as defined in bluetooth specification).
     @released
     @publishedPartner
     */
    virtual void ChangeLocalName(CHCICommandFrame& aFrame, const TDesC8& aName)=0;

    /**	Reads out the stored local Bluetooth device name.
	
	 @param aFrame The HCI frame to format
     @released
     @publishedPartner
     */
	virtual void ReadLocalName(CHCICommandFrame& aFrame)=0;

	/**	Reads out of the Bluetooth device the connection accept timeout, for incoming connections.

	 @param aFrame The HCI frame to format
	 @released
	 @publishedPartner
	 */
    virtual void ReadConnectionAcceptTimeout(CHCICommandFrame& aFrame)=0;

    /**	Sets the connection accept timeout in the host controller.

	 @param aFrame The HCI frame to format
	 @param aTimeout The connection timeout
     @released
     @publishedPartner
     */
    virtual void WriteConnectionAcceptTimeout(CHCICommandFrame& aFrame, TBasebandTime aTimeout)=0;
    
    /**	Commands the Bluetooth hardware to respond with its Page Timeout.
	
	 @param aFrame The HCI frame to format
     @released
     @publishedPartner
     */
	virtual void ReadPageTimeout(CHCICommandFrame& aFrame)=0;

	/**	Sets the page timeout in the host controller.

	 @param aFrame The HCI frame to format
	 @param aTimeout Page Timeout.  This must be between KMaxPageTimeout and KMinPageTimeout.
	 @released
	 @publishedPartner
	 */
    virtual void WritePageTimeout(CHCICommandFrame& aFrame, TBasebandTime aTimeout)=0;

    /**	Read out of the host controller the scan options.
	
	 @param aFrame The HCI frame to format
     @released
     @publishedPartner
     */
    virtual void ReadScanEnable(CHCICommandFrame& aFrame)=0;

    /**	Sets the scan options on the host controller.

	 @param aFrame The HCI frame to format
	 @param  aScanEnable Scan enable options
     @released
     @publishedPartner
     */
    virtual void WriteScanEnable(CHCICommandFrame& aFrame, THCIScanEnable aEnable=EInquiryAndPageScan)=0;
	
    /**	Read out of the host controller the number of supported inquiry access codes.

	 @param aFrame The HCI frame to format
     @released
     @publishedPartner
     */
	virtual void ReadNumberOfSupportedIAC(CHCICommandFrame& aFrame)=0;

	/**	Write to the host controller the lower address parts supplied.

	 @param aFrame The HCI frame to format
	 @param aNumCurrentIAC The number of inquiry access code lower address parts being sent to the hardware
	 @param aIAC_LAP The inquiry access code lower address parts - 3 bytes each: e.g: GIACLAP=0x9e8b33, LIACLAP=0x9e8b00
	 @released
	 @publishedPartner
	 */
    virtual void WriteCurrentIACLAP(CHCICommandFrame& aFrame, TUint8 aNumCurrentIAC, TUint aIAC_LAP[])=0;

    /**	Read out the inquiry access code lower address parts.
	
	 @param aFrame The HCI frame to format
     @released
     @publishedPartner
     */
	virtual void ReadCurrentIACLAP(CHCICommandFrame& aFrame)=0;

	/**	Read out from the host controller whether authentication is enabled.

	 @param aFrame The HCI frame to format
	 @released
	 @publishedPartner
	 */
    virtual void ReadAuthenticationEnable(CHCICommandFrame& aFrame)=0;

    /**	Set/Unset authentication.

	 @param aFrame The HCI frame to format
	 @param aAuthEnable	Authentication Enable.  Possible values are EFalse for authentication disabled or ETrue for authentication enabled
     @released
     @publishedPartner
     */
    virtual void WriteAuthenticationEnable(CHCICommandFrame& aFrame, TBool aAuthEnable)=0;

    /**	Read out the encryption mode.

	 @param aFrame The HCI frame to format
     @released
     @publishedPartner
     */
    virtual void ReadEncryptionMode(CHCICommandFrame& aFrame)=0;

    /**	Set/unset the encryption.

	 @param aFrame The HCI frame to format
	 @param aFlag Whether to enable encryption.	 Possible values are EFalse to disable encryption or ETrue to enable encryption.
     @released
     @publishedPartner
     */
    virtual void WriteEncryptionMode(CHCICommandFrame& aFrame, THCIEncryptModeFlag aFlag)=0;

    /**	Reads out the class of device of the local Bluetooth device.

	 @param aFrame The HCI frame to format
     @released
     @publishedPartner
     */
    virtual void ReadClassOfDevice(CHCICommandFrame& aFrame)=0;

    /**	Sets the local Bluetooth class of device.

	 @param aFrame The HCI frame to format
	 @param aCoD Class Of Device
     @released
     @publishedPartner
     */
    virtual void WriteClassOfDevice(CHCICommandFrame& aFrame, TUint aCoD)=0;

    /**	Read the Bluetooth hardware voice settings.

	 @param aFrame The HCI frame to format
     @released
     @publishedPartner
     */
	virtual void ReadVoiceSetting(CHCICommandFrame& aFrame)=0;

	/**	Set the local Bluetooth device voice settings. 

	 @param aFrame The HCI frame to format
	 @param aVoiceChannelSetting	Voice channel settings as defined by the HCI specification.
	 @released
	 @publishedPartner
	 */
	virtual void WriteVoiceSetting(CHCICommandFrame& aFrame, TInt16 aVoiceChannelSetting)=0;
    
	// HCI Informational Parameters Commands
	/**	Retrieve local hardware/firmware revision info.

	 @param aFrame The HCI frame to format
	 @released
	 @publishedPartner
	 */
	virtual void ReadLocalVersionInformation(CHCICommandFrame& aFrame)=0;

	/**	Retrieve local hardware/firmware capabilities.

	 @param aFrame The HCI frame to format
	 @released
	 @publishedPartner
	 */
	virtual void ReadLocalSupportedFeatures(CHCICommandFrame& aFrame)=0;

	/**	Retrieve from the host controller its buffering capabilities.

	 @param aFrame The HCI frame to format
	 @released
	 @publishedPartner
	 */
    virtual void ReadBufferSize(CHCICommandFrame& aFrame)=0;  
  
    /**	Retrieve the hardware's intended country code (for security/encryption issues). 

	 @param aFrame The HCI frame to format
     @released
     @publishedPartner
     */
	virtual void ReadCountryCode(CHCICommandFrame& aFrame)=0;

	/**	Retrieve local Bluetooth device address.

	 @param aFrame The HCI frame to format
	 @released
	 @publishedPartner
	 */
    virtual void ReadBDADDR(CHCICommandFrame& aFrame)=0;
	
	// Host Controller to Host Data Flow Control
    /**	Set/unset notification of delivery of packets, from the host controller to the host.

	 @param aFrame The HCI frame to format
	 @param aFlowFlag Flow Control Enable flag
     @released
     @publishedPartner
     */
    virtual void SetHostControllerToHostFlowControl(CHCICommandFrame& aFrame, TBool aHC2HFlowFlag)=0;// may return KErrNoMemory

    /** Notification to host controller of the number of packets that the above 
	 layers (L2CAP) have consumed.  HostNumberOfCompletedPackets command to be 
	 issued by L2CAP.

	 @param aFrame The HCI frame to format
	 @param aNumHandles	Number of connectionhandles
	 @param aConnH Connection handle 
	 @param aCompletedPacketsNo	Host num of completed packets
     @released
     @publishedPartner
     */
	virtual void HostNumberOfCompletedPackets(CHCICommandFrame& aFrame, TUint8 aNumHandles, THCIConnHandle aConnH[], TUint16 aCompletedPacketsNo[])=0;

	/**	Notifies the host controller of the hosts buffering capabilities.

	 @param aFrame The HCI frame to format
	 @param aACLDataLength	Host's ACL Data Packet Length
	 @param aSCODataLength	Host's SCO Data Packet Length   
	 @param aTotalACLPackets Total Number of ACL Data Packets that the Host can handle
	 @param aTotalSCOPackets Total Number of SCO Data Packets that the Host can handle
	 @released
	 @publishedPartner
	 */
	virtual void HostBufferSize(CHCICommandFrame& aFrame, TUint16 aACLDataLength,TUint8 aSCODataLength,
        TUint16 aTotalACLPackets, TUint16 aTotalSCOPackets)=0;

	/** Writes link supervision timeout.

	 @param aFrame The HCI frame to format
	 @param aConnH Connection handle
	 @param aTimeout Timeout to write
	 @released
	 @publishedPartner
	 */
	virtual void WriteLinkSupervisionTimeout(CHCICommandFrame& aFrame, THCIConnHandle aConnH, TBasebandTime aTimeout)=0;

	/** This call allows for a raw HCI command frame to be written to the HC.

    This is intended for vendor specific commands for which the opcode 
	field will be known to the HCI.

    These raw frames should be constructed by calling the HCI factory
    function with the opcode constructed of the vendor debug opcode group field
	and the particular OCF required.  This function should then be called with the
    appropriately formatted parameters which shall be placed into the frame's
    payload.  It should be noted that the client need NOT to be concerned
    with the HCTL framing at all.

    The HCI will only then copy this frame to the host controller after putting 
	it in an HCTL frame.

    Note that the client is responsible for policing the size of the descriptor
    passed to this function.  The length should be: 0 <= n <= KHCIMaxCommandLength

     @param aFrame The HCI frame to format
     @param aData The frame parameters   
	 @released
	 @publishedPartner
	 */
	virtual void WriteVendorRawFrameCommand(CHCICommandFrame& aFrame, const TDesC8& aData)=0;


	// HCI Status Parameters Commands
	// not here yet
	
	// HCI Testing Commands
	// not here yet 
	/** Used for testing.

	 @released
	 @internalComponent
	 */
	virtual TAny *LogIndex() const=0;

	// methods to allow stack to query HCI about its features
	/** Reads ACL reporting interval.

	 @return the ACL reporting interval.
	 @released
	 @publishedPartner
	 */
	virtual TUint16 ReadACLReportingInterval() = 0; // Some hardware only reports on the nth ACL data packet being sent
	                                                // this is an opportunity for the HCI to supply a minimum value of n
													// to the Link Manager

	/** Reads size of HCI framing overhead per frame.

	 @return size of HCI framing overhead per frame.
	 @released
	 @publishedPartner
	 */
	virtual TUint16 ReadACLFramingOverhead() = 0; // Size of HCI framing overhead per frame

	// Adaptive Frequency Hopping (AFH)
	
	/**	Notifies the host controller of channels that are known by the host to be bad or to be about to be bad.
	
	 This allows those channels to be avoided if Adaptive Frequency Hopping is active on a connection.
	 
	 @param aFrame The HCI frame to format
	 @param aChannelClassification Bitwise representation of the bad channels
	 @released
	 @publishedPartner
	 */
    virtual void SetAFHHostChannelClassification(CHCICommandFrame& aFrame, const TDesC8& aChannelClassification)=0;

	/**	Retrieves the AFH channel map being used on the specified connection.
	
	 If we are master this will be the local AFH channel map. If we are slave it 
	 will be the remote master's AFH channel map.
	 
	 @param aFrame The HCI frame to format
	 @param aConnH Connection handle 
	 @released
	 @publishedPartner
	*/
	virtual void ReadAFHChannelMap(CHCICommandFrame& aFrame, THCIConnHandle aConnH)=0;

 	/**	Notifies the host controller whether or not it is required to keep checking for busy channels..
	
	 @param aFrame The HCI frame to format
	 @param aEnable Check for busy channels if ETrue, otherwise don't
	 @released
	 @publishedPartner
	 */
    virtual void WriteAFHChannelAssessmentMode(CHCICommandFrame& aFrame, TBool aEnable)=0;

 	/**	Asks the host controller whether or not it is checking for busy channels..
	
	 @param aFrame The HCI frame to format
	 @released
	 @publishedPartner
	 */
    virtual void ReadAFHChannelAssessmentMode(CHCICommandFrame& aFrame)=0;

    /** HCI level Ioctl

	 @param aLevel			The Ioctl level
	 @param aName			The Ioctl function number
	 @param aOption			Data associated with this Ioctl
	 @param aStackSAP		A pointer to the SAP, used to track Ioctls
     @released
     @publishedPartner
     */
	virtual void Ioctl(TUint aLevel,TUint aName, TDes8* aOption, TAny* aStackSAP) = 0;

    /** Cancel HCI level Ioctl

	 @param aLevel			The Ioctl level
	 @param aName			The Ioctl function number
	 @param aStackSAP		A pointer to the SAP, used to track Ioctls
     @released
     @publishedPartner
     */
	virtual void CancelIoctl(TUint aLevel,TUint aName, TAny* aStackSAP) = 0;
	};

enum THCIErrorCode;



/** Event handler mixin that must be implemented by the client of HCI.

A class that implements this interface must be passed into the
CHCIBase derived class on construction, and will be used by the HCI
class to notify the client of events received over the HCI interface.

@released
@publishedPartner
*/
class MHCIEventObserver
    {   
public:
	// Interfaces to allow HCI to notify LL
	/** This provides command credits.

	 @param aCredits Provided command credits.
	 @released
	 @publishedPartner
	 */
	virtual void SetCommandCredits(TUint16 aCredits)=0;

	/** Informs of the ACL MTU for this host.

	 @param aMTU Maximum size of ACL packet the host can send.
	 @released
	 @publishedPartner
	 */
	virtual void HCIMaximumACLPacketSize(TUint16 aMTU)=0;

	/** Called when transport channels have become free.

	 @param aChannel Channel that is free.
	 @released
	 @publishedPartner
	 */
	virtual void CanSend(THCITransportChannel aChannel = KHCITransportAllChannels)=0;

	// Events as per spec
	/** Called on an inquiry complete event.

	 @param aNumResponses Number of responses received from the inquiry.  This is zero if not supported or there is an error.
	 @param aErr HCI specific or system wide error code.
	 @released
	 @publishedPartner
	 */
    virtual void InquiryCompleteEvent(THCIErrorCode aErr, TUint8 aNumResponses)=0;

    /** Called on an inquiry result complete event.

	 @param aEntry TInquiryLogEntry containing results of inquiry.
     @param aErr HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void InquiryResultCompleteEvent(THCIErrorCode aErr,const TInquiryLogEntry& aEntry)=0;

    /** Called on a connection complete event.

	 @param aConn Contains information about the completed connection.
     @param aErr HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void ConnectionCompleteEvent(THCIErrorCode aErr, const TBTConnect &aConn)=0;

    /** Called on a connection request event.

	 @param aConn Information about the device requesting the connection.
     @released
     @publishedPartner
     */
    virtual void ConnectionRequestEvent(const TBTConnect &aConn)=0;

    /** Called on a disconnection complete event.

	 @param aConnH Connection handle
	 @param aReason Reason for disconnection.
     @param aErr HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void DisconnectionCompleteEvent(THCIErrorCode aErr, THCIConnHandle aConnH, THCIErrorCode aReason)=0;

    /** Called on an authentication complete event.

	 @param aConnH Connection handle
     @param aErr HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void AuthenticationCompleteEvent(THCIErrorCode aErr, THCIConnHandle aConnH)=0;

    /** Called on a remote name request complete event.

	 @param aBdaddr Bluetooth address of remote device
	 @param aBuf Name of remote device (max 248 bytes as defined by the bluetooth specification).
     @param aErr HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void RemoteNameReqCompleteEvent(THCIErrorCode aErr, const TBTDevAddr& aBdaddr, const TDesC8& aBuf)=0;

    /** Called on encryption change event.

	 @param aConnH Connection handle
	 @param aEnable Whether encryption is enabled
     @param aErr HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void EncryptionChangeEvent(THCIErrorCode aErr, THCIConnHandle aConnH,TBool aEnable)=0;

    /** Called on link key complete event.

	 @param Connection handle
     @param aErr HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void ChangeLinkKeyCompleteEvent(THCIErrorCode aErr, THCIConnHandle aConnH)=0;

    /** Called on master link key complete event.

	 @param aConnH Connection handle
	 @param aKeyFlag See bluetooth specification
     @param aErr HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void MasterLinkKeyCompleteEvent(THCIErrorCode aErr, THCIConnHandle aConnH,TBool aKeyFlag)=0;

    /** Called on read remote supported features complete event.

	 @param aConnH Connection handle
	 @param aBitMaskList LMP_Features Bit Mask List (8 bytes)
     @param aErr HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void ReadRemoteSupportedFeaturesCompleteEvent(THCIErrorCode aErr, THCIConnHandle aConnH, TUint64 aBitMaskList)=0;
    /**  Called  on read remote version info complete event.

	 @param aConnH Connection handle
	 @param aVer Information on remote hardware version
     @param aErr HCI specific or system wide error code.
     @released
     @publishedPartner
     */
	virtual void ReadRemoteVersionInfoCompleteEvent(THCIErrorCode aErr, THCIConnHandle aConnH, const TBTDevRemoteHwVersion& aVer)=0;

    /** Called on QOS setup complete event.
     
     @param  aQOS QOS information.
     @param aErr HCI specific or system wide error code.
     @param aConnH Connection handle
     @released
     @publishedPartner
     */
	virtual void QOSSetupCompleteEvent(THCIErrorCode aErr, THCIConnHandle aConnH, TBTQOS aQOS)=0;

    /**  Called on Command Complete Event.

     @param aErr HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void CommandCompleteEvent(THCIErrorCode aErr,THCIOpcode aOpcode)=0;

    /** Called on command status event.

     @param aOpcode Opcode of the successfully completed event.
     @released
     @publishedPartner
     */
    virtual void CommandStatusEvent(THCIOpcode aOpcode)=0;

    /** Called on Hardware Error Event.

	 @param aHwCode Hardware code.
     @released
     @publishedPartner
     */
    virtual void HardwareErrorEvent(TUint8 aHwCode)=0;

    /** Called on Flush Occurred Event.

     @param aErr HCI specific or system wide error code.
     @param aConnH Connection handle
     @released
     @publishedPartner
     */
	virtual void FlushOccurredEvent(THCIErrorCode aErr, THCIConnHandle aConnH)=0;

    /** Called on Role Change Event.

	 @param aRole New role.
	 @param aBdaddr Bluetooth device address of remote device.
     @param aErr HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void RoleChangeEvent(THCIErrorCode aErr, const TBTDevAddr& aBdaddr,TBTBasebandRole aRole)=0;

    /** Called on HCI Completed Packets event.

     @param aConnH Connection handle
	 @param aNumPacketsCompleted Number of packets completed.
     @released
     @publishedPartner
     */
    virtual void HCICompletedPackets(THCIConnHandle aConnH, TUint16 aNumPacketsCompleted)=0; //NumberCompletedPacketsEvent

    /** Called on Mode Change Event.

	 @param aMode Current mode.
	 @param aInterval Interval defined according to current mode (see bluetooth specification).
     @param aErr HCI specific or system wide error code.
     @param aConnH Connection handle
     @released
     @publishedPartner
     */
    virtual void ModeChangeEvent(THCIErrorCode aErr, THCIConnHandle aConnH, TBTLinkMode aMode, TUint16 aInterval)=0;

    /** Called on Return Link Keys Event.

	 @param aBdaddr Bluetooth device address of remote device.
	 @param aLinkKey Link key.
     @param aErr HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void ReturnLinkKeysEvent(THCIErrorCode aErr, const TBTDevAddr& aBdaddr,const TBTLinkKey& aLinkKey)=0;

    /** Called on PIN Code Request Event.

	 @param aBdaddr Bluetooth device address
     @released
     @publishedPartner
     */
    virtual void PINCodeRequestEvent(const TBTDevAddr& aBdaddr)=0;

    /** Called on Link Key Request Event.

	 @param aBdaddr Bluetooth device address
     @released
     @publishedPartner
     */
    virtual void LinkKeyRequestEvent(const TBTDevAddr& aBdaddr)=0;

    /** Called on Link Key Notification Event.

	 @param aBdaddr Bluetooth device address.
	 @param aLinkKey Link key.
     @released
     @publishedPartner
     */
    virtual void LinkKeyNotificationEvent(const TBTDevAddr& aBdaddr,const TBTLinkKey& aLinkKey)=0;

    /** Called on Loopback Command Event.  Not currently supported.

     @released
     @internalTechnology
     */
	virtual void LoopbackCommandEvent()=0; //not supported yet

    /** Called on Data Buffer Overflow Event. 

	 @param aLinkType
     @released
     @publishedPartner
     */
	virtual void DataBufferOverflowEvent(TUint8 aLinkType)=0;

    /** Called on Max Slots Change Event.

	 @param aMaxSlots New value of max slots.
     @param aConnH Connection handle
     @released
     @publishedPartner
     */
	virtual void MaxSlotsChangeEvent(THCIConnHandle aConnH, TUint8 aMaxSlots)=0;

    /** Called on Read Clock Offset Result Event.

	 @param aClockOffset Clock offset.
     @param aErr HCI specific or system wide error code.
     @param aConnH Connection handle
     @released
     @publishedPartner
     */
	virtual void ReadClockOffsetResultEvent(THCIErrorCode aErr, THCIConnHandle aConnH, TBasebandTime aClockOffset)=0;

    /** Called on Connection Packet Type Changed Event.

	 @param aPacketType New packet type.
     @param aErr HCI specific or system wide error code.
     @param aConnH Connection handle
     @released
     @publishedPartner
     */
	virtual void ConnectionPacketTypeChangedEvent(THCIErrorCode aErr,
					THCIConnHandle aConnH, TUint16 aPacketType)=0;

    /** Called on QOS Violation Event.

     @param aConnH Connection handle
     @released
     @publishedPartner
     */
	virtual void QOSViolationEvent(THCIConnHandle aConnH)=0;

    /** Called on Page Scan Mode Change Event.

	 @param aBdaddr Bluetooth device address.
	 @param aPageScanMode New page scan mode
     @released
     @publishedPartner
     */
	virtual void PageScanModeChangeEvent(const TBTDevAddr& aBdaddr, TUint8 aPageScanMode)=0;

    /** Called on Page Scan Repetition Mode Change Event.

	 @param aBdaddr Bluetooth device address
	 @param aPageScanRepetitionMode New page scan repetition mode
     @released
     @publishedPartner
     */
	virtual void PageScanRepetitionModeChangeEvent(const TBTDevAddr& aBdaddr, TUint8 aPageScanRepetitionMode)=0;

    // data events

    /** Called on ACLDataReceivedEvent.

     @param aConnH Connection handle
	 @param aData Received data
	 @param aFlag See bluetooth specification
     @released
     @publishedPartner
     */
	virtual void ACLDataReceivedEvent(THCIConnHandle aConnH,TUint8 aFlag,const TDesC8& aData)=0;

    /** Called on SCO Data Received Event.

	 @param aData Recieved data.
     @param aConnH Connection handle
     @released
     @publishedPartner
     */
	virtual void SCODataReceivedEvent(THCIConnHandle aConnH, const TDesC8& aData)=0;

	// complete events


    /** Called on Reset Complete Event.

     @param aStatus HCI specific or system wide error code.
     @released
     @publishedPartner
     */
	virtual void ResetCompleteEvent(THCIErrorCode aStatus)=0;

    /** Called on Write Link Supervision Timeout Complete Event.

     @param aStatus HCI specific or system wide error code.
     @released
     @publishedPartner
     */
	virtual void WriteLinkSupervisionTimeoutCompleteEvent(THCIErrorCode aStatus)=0;

    /** Called on Link Key Request Reply Complete Event.

     @param aStatus HCI specific or system wide error code.
     @released
     @publishedPartner
     */
	virtual void LinkKeyRequestReplyCompleteEvent(THCIErrorCode aStatus)=0;

    /** Called on Link Key Request Reply Negative Complete Event.

     @param aStatus HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void LinkKeyRequestReplyNegativeCompleteEvent(THCIErrorCode aStatus)=0;

    /** Called on PIN Code Request Reply Complete Event.

     @param aStatus HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void PINCodeRequestReplyCompleteEvent(THCIErrorCode aStatus)=0;

    /** Called on PIN Code Request Reply Negative Complete Event.

     @param aStatus HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void PINCodeRequestReplyNegativeCompleteEvent(THCIErrorCode aStatus)=0;

    /** Called on Inquiry Cancel Complete Event.

     @param aStatus HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void InquiryCancelCompleteEvent(THCIErrorCode aStatus)=0;

    /** Called on Periodic Inquiry Mode Complete Event.

     @param aStatus HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void PeriodicInquiryModeCompleteEvent(THCIErrorCode aStatus)=0;

    /** Called on Exit Periodic Inquiry Mode Complete Event.

     @param aStatus HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void ExitPeriodicInquiryModeCompleteEvent(THCIErrorCode aStatus)=0;

    /** Called on Set Event Mask Complete Event.

     @param aStatus HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void SetEventMaskCompleteEvent(THCIErrorCode aStatus)=0;

    /** Called on Set Event Filter Complete Event.

     @param aStatus HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void SetEventFilterCompleteEvent(THCIErrorCode aStatus)=0;

    /** Called on Create New Unit Key Complete Event.

     @param aStatus HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void CreateNewUnitKeyCompleteEvent(THCIErrorCode aStatus)=0;

    /** Called on Change Local Name Complete Event.

     @param aStatus HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void ChangeLocalNameCompleteEvent(THCIErrorCode aStatus)=0;

    /** Called on Write Authentication Enable Complete Event.

     @param aStatus HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void WriteAuthenticationEnableCompleteEvent(THCIErrorCode aStatus)=0;

    /** Called on Write Encryption Mode Complete Event.

     @param aStatus HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void WriteEncryptionModeCompleteEvent(THCIErrorCode aStatus)=0;

    /** Called on Write Page Timeout Complete Event.

     @param aStatus HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void WritePageTimeoutCompleteEvent(THCIErrorCode aStatus)=0;

    /** Called on Write Connection Accept Timeout Complete Event.

     @param aStatus HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void WriteConnectionAcceptTimeoutCompleteEvent(THCIErrorCode aStatus)=0;

    /** Called on Write Class Of Device Complete Event.

     @param aStatus HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void WriteClassOfDeviceCompleteEvent(THCIErrorCode aStatus)=0;

    /** Called on Write Voice Setting Complete Event.

     @param aStatus HCI specific or system wide error code.
     @released
     @publishedPartner
     */
	virtual void WriteVoiceSettingCompleteEvent(THCIErrorCode aStatus)=0;

    /** Called on Write Current IAC LAP Complete Event.

     @param aStatus HCI specific or system wide error code.
     @released
     @publishedPartner
     */
	virtual void WriteCurrentIACLAPCompleteEvent(THCIErrorCode aStatus)=0;

    /** Called on Set Host Controller To Host Flow Complete Event.

     @param aStatus HCI specific or system wide error code.
     @released
     @publishedPartner
     */
	virtual void SetHostControllerToHostFlowCompleteEvent(THCIErrorCode aStatus)=0;

    /** Called on Host Buffer Size Complete Event.

     @param aStatus HCI specific or system wide error code.
     @released
     @publishedPartner
     */
	virtual void HostBufferSizeCompleteEvent(THCIErrorCode aStatus)=0;

    /** Called on Host Number Of Completed Packets Complete Event.

     @param aStatus HCI specific or system wide error code.
     @released
     @publishedPartner
     */
	virtual void HostNumberOfCompletedPacketsCompleteEvent(THCIErrorCode aStatus)=0;

    /** Called on Write Scan Enable Complete Event.

     @param aStatus HCI specific or system wide error code.
     @released
     @publishedPartner
     */
	virtual void WriteScanEnableCompleteEvent(THCIErrorCode aStatus)=0;

    /** Called on Write Link Policy Settings Complete Event.

     @param aConnH Connection handle
     @param aStatus HCI specific or system wide error code.
     @released
     @publishedPartner
     */
	virtual void WriteLinkPolicySettingsCompleteEvent(THCIErrorCode aStatus, THCIConnHandle aConnH)=0;

	// results of local commands


    /** Called on Read Stored Link Key Result.

	 @param aNumKeysRead Number of keys read
	 @param aMaxNumKeys Max number of keys
     @param aErr HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void ReadStoredLinkKeyResult(THCIErrorCode aErr,TUint16 aNumKeysRead,TUint16 aMaxNumKeys)=0;

    /** Called on Write Stored Link Key Result.

	 @param aNumKeysStored Number of keys stored
     @param aErr HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void WriteStoredLinkKeyResult(THCIErrorCode aErr,TUint8 aNumKeysStored)=0;

    /** Called on Delete Stored Link Key Result.

	 @param aNumKeysDeleted Number of keys deleted
     @param aErr HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void DeleteStoredLinkKeyResult(THCIErrorCode aErr,TUint8 aNumKeysDeleted)=0;

    /** Called on Read Scan Enable Result.

	 @param aEnable See bluetooth specification
     @param aErr HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void ReadScanEnableResult(THCIErrorCode aErr,TUint8 aEnable)=0;

    /** Called on Read Authentication Enable Result.

	 @param aEnable See bluetooth specification
     @param aErr HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void ReadAuthenticationEnableResult(THCIErrorCode aErr,TUint8 aEnable)=0;

    /** Called on Read Encryption Enable Result.

	 @param aEnable See bluetooth specification
     @param aErr HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void ReadEncryptionEnableResult(THCIErrorCode aErr,THCIEncryptModeFlag aEnable)=0;

    /** Called on Read Bdaddr Result.

	 @param aBdaddr Bluetooth device address of remote device
     @param aErr HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void ReadBdaddrResult(THCIErrorCode aErr,const TBTDevAddr& aBdaddr)=0;

    /** Called on Read Class Of Device Result.

	 @param aCoD Class of device of remote device
     @param aErr HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void ReadClassOfDeviceResult(THCIErrorCode aErr,TUint aCoD)=0;

    /** Called on Read Voice Setting Result.

	 @param aVoiceChannelSetting Voice channel setting
     @param aErr HCI specific or system wide error code.
     @released
     @publishedPartner
     */
	virtual void ReadVoiceSettingResult(THCIErrorCode aErr,TUint16 aVoiceChannelSetting)=0;

    /** Called on Read Local Name Result.

	 @param aLocalName Local name
     @param aErr HCI specific or system wide error code.
     @released
     @publishedPartner
     */
	virtual void ReadLocalNameResult(THCIErrorCode aErr,const TDesC8& aLocalName)=0;

    /** Called on Read Timeout Result.

	 @param aType See bluetooth specification
	 @param aTimeout  See bluetooth specification
     @param aErr HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void ReadTimeoutResult(THCIErrorCode aErr,THCITimeoutType aType,TBasebandTime aTimeout)=0;

    /** Called on Read Local Version Info Result.

	 @param aHCIVersion Version information of local device hardware
	 @param aLMPVersion Version information of local LMP
     @param aErr HCI specific or system wide error code.
     @released
     @publishedPartner
     */
	virtual void ReadLocalVersionInfoResult(THCIErrorCode aErr, TBTDevHCIVersion aHCIVersion, TBTDevLMPVersion aLMPVersion)=0;

    /** Called on Read Local Supported Features Result.

	 @param aBitMaskList See bluetooth specification
     @param aErr HCI specific or system wide error code.
     @released
     @publishedPartner
     */
	virtual void ReadLocalSupportedFeaturesResult(THCIErrorCode aErr, TUint64 aBitMaskList)=0;
    /** Called on Read Country Code Result.

	 @param aCountryCode Country code
     @param aErr HCI specific or system wide error code.
     @released
     @publishedPartner
     */
	virtual void ReadCountryCodeResult(THCIErrorCode aErr, TUint8 aCountryCode)=0;

    /** Called on Read Number Of Supported IAC Result.

	 @param aNumIACs  Number of IACs
     @param aErr HCI specific or system wide error code.
     @released
     @publishedPartner
     */
	virtual void ReadNumberOfSupportedIACResult(THCIErrorCode aErr, TUint8 aNumIACs)=0;

    /** Called on Read Discoverability Result.

	 @param aNumIACs The number of concurrent IACs on which scanning is/would take place
	 @param aIAC IAC_LAP array.
     @param aErr HCI specific or system wide error code.
     @released
     @publishedPartner
     */
	virtual void ReadDiscoverabilityResult(THCIErrorCode aErr, TUint8 aNumIACs, TUint aIAC[])=0;

    /** Called on Read Buffer Size Result.

	 @param aAclMaxLen Maximum length of each ACL packet
	 @param aScoMaxLen Maximum length of each SCO packet
	 @param aNoACL Total number of ACL data packets
	 @param aNoSCO Total number of SCO data packets
     @param aErr HCI specific or system wide error code.
     @released
     @publishedPartner
     */
    virtual void ReadBufferSizeResult(THCIErrorCode aErr,TUint16 aAclMaxLen,
			      TUint8 aScoMaxLen,TUint16 aNoACL,TUint16 aNoSCO)=0;

    /** Called on Read Role Discovery Result.

	 @param aRole Current role
     @param aStatus HCI specific or system wide error code.
     @released
     @publishedPartner
     */
	virtual void ReadRoleDiscoveryResult(THCIErrorCode aStatus, TBTBasebandRole aRole)=0;

    /** Called on Vendor Specific Debug Event.
	
	 @param aEventFrame The frame holds the event parameters and parameter length field
     @released
     @publishedPartner
     */
	virtual void VendorSpecificDebugEvent(TPtrC8 aEventFrame)=0;

	// Power off event

    /** Called on Handle Power Status Change.

	 @param aState New power state
     @released
     @publishedPartner
     */
	virtual void HandlePowerStatusChange(TBTPowerState aState)=0;
	

	// Results of Adaptive Frequency Hopping (AFH) commands

    /** Called in response to a SetAFHHostChannelClassification command.

	 @param aStatus The success or not of the SetAFHHostChannelClassification command
	 @see SetAFHHostChannelClassification
     @released
     @publishedPartner
     */
	virtual void SetAFHHostChannelClassificationCompleteEvent(THCIErrorCode aStatus)=0;
 
    /** Called in response to a ReadAFHChannelMap command.

	 @param aStatus The success or not of the ReadAFHChannelMap command
	 @param aConnH Connection handle
	 @param aAFHMode ETrue if AFH is enabled, EFalse if not
	 @param aAFHChannelMap The AFH channel map being used on the specified connection
	 @see ReadAFHChannelMap
     @released
     @publishedPartner
     */
	virtual void ReadAFHChannelMapCompleteEvent(THCIErrorCode aStatus, THCIConnHandle aConnH, TBool aAFHMode, const TDesC8& aAFHChannelMap)=0;

    /** Called in response to a WriteAFHChannelAssessmentMode command.

	 @param aStatus The success or not of the WriteAFHChannelAssessmentMode command
	 @see WriteAFHChannelAssessmentMode
     @released
     @publishedPartner
     */
	virtual void WriteAFHChannelAssessmentModeCompleteEvent(THCIErrorCode aStatus)=0;

    /** Called in response to a ReadAFHChannelAssessmentMode command.

	 @param aStatus The success or not of the ReadAFHChannelAssessmentMode command
	 @param aChannelAssessmentMode The host controller is checking for busy channels if ETrue, otherwise it is not
	 @see ReadAFHChannelAssessmentMode
     @released
     @publishedPartner
     */
	virtual void ReadAFHChannelAssessmentModeCompleteEvent(THCIErrorCode aStatus, TBool aChannelAssessmentMode)=0;

	
    /** Called in response to a Flush command.

	 @param aStatus The success or not of the Flush command
	 @param aConnH  The connection handle
     @released
     @publishedPartner
     */
	virtual void FlushCompleteEvent(THCIErrorCode aStatus, THCIConnHandle aConnH)=0;


    /** Called on a synchronous connection complete event.  
 	@param aStatus
    @param aConnH HCI connection handle
    @param aBdaddr BT device address
    @param aLinkType Link Type:SCO, Reserved or eSCO
    @param aTransmissionInterval Transmission Interval
    @param aRetransmissionWindow Retransmission Window
    @param aRxPacketLength Rx Packet Length
    @param aTxPacketLength Tx Packet Length
    @param aAirMode Air Mode: uLaw, ALaw, CVSD or Transparent data
    @released
    @publishedPartner
     */
    virtual void SynchronousConnectionCompleteEvent(const THCIErrorCode aErr,
    												const THCIConnHandle aConnH,
    												const TBTDevAddr& aBdaddr,
    												const TLinkType aLinkType,
    												const TUint8 aTransmissionInterval,
    												const TUint8 aRetransmissionWindow,
    												const TUint16 aRxPacketLength,
    												const TUint16 aTxPacketLength,
    												const TAirMode aAirMode)=0;

    /** Called on a synchronous connection changed event
 	@param aStatus
    @param aConnH HCI connection handle
    @param aTransmissionInterval Transmission Interval
    @param aRetransmissionWindow Retransmission Window
    @param aRxPacketLength Rx Packet Length
    @param aTxPacketLength Tx Packet Length
    @released
    @publishedPartner
     */
    virtual void SynchronousConnectionChangedEvent(const THCIErrorCode aErr,
    											   const THCIConnHandle aConnH,
   												   const TUint8 aTransmissionInterval,
   												   const TUint8 aRetransmissionWindow,
   												   const TUint16 aRxPacketLength,
   												   const TUint16 aTxPacketLength)=0;
    
  

    /** Called when an HCI level Ioctl completes.

	 @param aLevel			The Ioctl level
	 @param aName			The Ioctl function number
	 @param aOption			Data associated with this Ioctl
	 @param aErr			System-wide error code
	 @param aStackSAP		A pointer to the SAP, used to track Ioctls
     @released
     @publishedPartner
     */
	virtual void CompleteIoctl(TUint aLevel,TUint aName,TDes8* aOption,TInt aErr, TAny* aStackSAP)=0;
    };
	

/* 
 * Constants used for Symbian's RHCIDirectAccess test functionality
 */

	// Test Ioctls
	enum THCIDirectAccessTestIoctl
		{
		EHCIDirectAccessTestIoctlSetFlag1 = 0,
		EHCIDirectAccessTestIoctlSetFlag2,
		EHCIDirectAccessTestIoctlGetFlag1,
		EHCIDirectAccessTestIoctlGetFlag2,
		EHCIDirectAccessTestIoctlValidateFlag1,
		EHCIDirectAccessTestIoctlValidateFlag2,
		EHCIDirectAccessTestIoctlTimerFiveSeconds,
		EHCIDirectAccessTestIoctlTimerEightSeconds,
		EHCIDirectAccessTestIoctlTestDataPath,
		EHCIDirectAccessTestIoctlNotifyOnEventX,
		EHCIDirectAccessTestIoctlTriggerEventX,
		};

	// text strings for testing data path
	_LIT8(KHCIDirectAccessTestExpectedText, "ExpectedText");
	_LIT8(KHCIDirectAccessTestUnexpectedText, "UnexpectedText");

#endif
