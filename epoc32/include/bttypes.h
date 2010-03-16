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
// BT protocol wide types
// 
//

#ifndef _BTTYPES_H
#define _BTTYPES_H

#include <e32std.h>
#include <bluetooth/eirdatacodec.h>

/**
@publishedAll
@released

Minimum eSCO connection latency in milliseconds.  Attempts to specify less than this will be silently
increased to this level.
*/
static const TInt KMinESCOLatency = 4;

/**
@publishedAll
@released

Typedef to represent a HCI connection handle.
*/
typedef TUint16 THCIConnHandle;

/**
@publishedAll
@released

Bluetooth SIG specified values for specification of (piconet) role.
*/
enum TBTBasebandRole
	{
	EMaster			= 0x00, /*!< Master role */
	ESlave			= 0x01, /*!< Slave role */
	ERoleUnknown,			/*!< Unknown role */
	};

/**
@publishedAll
@released

Bluetooth SIG specified values for indicating link modes.
*/
enum TBTLinkMode
    {
    EActiveMode		= 0x00, /*!< Active mode */
    EHoldMode		= 0x01, /*!< Hold mode */
    ESniffMode		= 0x02, /*!< Sniff mode */
    EParkMode		= 0x04, /*!< Park mode */
	EScatterMode	= 0x08, /*!< Scatter mode */
    };

/**
@publishedAll
@released

Typedef to represent a union of TBTLinkMode values.
*/
typedef TUint32 TBTLinkModeSet;

/**
@publishedAll
@released

Bitmask values to help request combinations of link modes.
@see TBTLinkMode
*/
enum TBTLinkModeCombinations
	{
	EAnyLowPowerMode = (EHoldMode | ESniffMode | EParkMode | EScatterMode) /*!< Any low power mode */
	};

/**
@publishedAll
@released

Bluetooth SIG specified values for indicating packet types.

DM1, DH1, DM3, DH3, DM5, DH5 are ACL packet types
HV1, HV2, HV3 are SCO (synchronous link) packet types
*/
enum TBTPacketType
	{
	EPacketsDM1			= 0x0008, /*!< DM1 ACL packet type */
	EPacketsDH1			= 0x0010, /*!< DH1 ACL packet type */
	EPacketsDM3			= 0x0400, /*!< DM3 ACL packet type */
	EPacketsDH3			= 0x0800, /*!< DH3 ACL packet type */
	EPacketsDM5			= 0x4000, /*!< DM5 ACL packet type */
	EPacketsDH5			= 0x8000, /*!< DH5 ACL packet type */
	
	EPackets2_DH1		= 0x0002, /*!< 2-DH1 ACL packet type */
	EPackets3_DH1		= 0x0004, /*!< 3-DH1 ACL packet type */
	EPackets2_DH3		= 0x0100, /*!< 2-DH3 ACL packet type */
	EPackets3_DH3		= 0x0200, /*!< 3-DH3 ACL packet type */
	EPackets2_DH5		= 0x1000, /*!< 2-DH5 ACL packet type */
	EPackets3_DH5		= 0x2000, /*!< 3-DH5 ACL packet type */

	EPacketsHV1			= 0x0020, /*!< HV1 SCO packet type */
	EPacketsHV2			= 0x0040, /*!< HV2 SCO packet type */
	EPacketsHV3			= 0x0080, /*!< HV3 SCO packet type */
	};

/**
@publishedAll
@released

Typedef to represent a set of SCO packet types.
*/
typedef TUint16 TBTSCOPackets;

/**
@publishedAll
@released

Typedef to represent a set of ACL packet types.
*/
typedef TUint16 TBTACLPackets;

/**
@publishedAll
@released

Bitmask values to help request combinations of packets.
@see TBTPacketType
*/
enum TBTPacketTypeCombinations
	{
	EAnyACLPacket	 = EPacketsDM1 | EPacketsDM3 | EPacketsDM5 | EPacketsDH1 | EPacketsDH3 | EPacketsDH5, /*!< Any ACL packet */
	EAnyNonEdrACLPacket = EAnyACLPacket | EPackets2_DH1 | EPackets3_DH1 | EPackets2_DH3 | EPackets3_DH3 | EPackets2_DH5 | EPackets3_DH5, /*!< Any Non-EDR ACL packet */
	EAnySCOPacket	 = EPacketsHV1 | EPacketsHV2 | EPacketsHV3, /*!< Any SCO packet */
	EAnyPacket		= EAnyACLPacket | EAnySCOPacket  /*!< Any packet */
	};


/**
@publishedAll
@released

Typedef to represent a set of synchronous packet types (SCO and eSCO on v1.2).
@see TBTSyncPackets::TSyncPackets
*/
typedef TUint32 TBTSyncPacketTypes;

/**
@publishedAll
@deprecated

This constant is no longer needed to translate the SCO mapping of HV packet types to Synchronous
because CBluetoothSynchronousLink::SetupConnection(const TBTDevAddr& aBDAddr, const TUint16 aPacketTypes)
adjusts aPacketTypes internally on behalf of clients.
*/
static const TInt KSCOvsSyncHVOffset = 5;

/**
@publishedAll
@released

Class to represent a set of synchronous packet types (SCO and eSCO on v1.2).
This differs from TBTSyncPacketTypes as it is the interface used by CBluetoothSynchronousLink
in order to detect the difference between a pre and post eSCO caller.  This is necessary
as HV1 packets in the SCO numbering clash with EV5 packets in the sync numbering.
*/
NONSHARABLE_CLASS(TBTSyncPackets)
	{
	public:
		/**
		@publishedAll
		@released
		
		Individual synchronous packet types.
		@see TBTSyncPacketTypes
		*/
		enum TSyncPackets
			{
			ESyncPacketsHV1		= 0x10001,
			ESyncPacketsHV2		= 0x10002,
			ESyncPacketsHV3		= 0x10004,

			ESyncPacketsEV3		= 0x20008,
			ESyncPacketsEV4		= 0x20010,
			ESyncPacketsEV5		= 0x20020,
			
			ESyncAnySCOPacket	= ESyncPacketsHV1 | ESyncPacketsHV2 | ESyncPacketsHV3,
			ESyncAnyESCOPacket	= ESyncPacketsEV3 | ESyncPacketsEV4 | ESyncPacketsEV5
			};
	
	public:
		IMPORT_C explicit TBTSyncPackets(TBTSyncPacketTypes aPackets);
		IMPORT_C TBTSyncPacketTypes operator()() const;
		
	private:
		TUint32 iPacketTypes;

		// This data padding has been added to help prevent future binary compatibility breaks	
		// Neither iPadding1 nor iPadding2 have been zero'd because they are currently not used
		TUint32     iPadding1; 
		TUint32     iPadding2; 		
	};


/**
@publishedAll
@released

eSCO links can have different retransmission options, optimised for link usage,
power or reliability.

@see CBluetoothSynchronousLink::SetRetransmissionEffort
*/
enum TBTeSCORetransmissionTypes
	{
	EeSCORetransmitNone			= 0,
	EeSCORetransmitPower		= 1,
	EeSCORetransmitReliability	= 2,
	EeSCORetransmitDontCare		= 0xff
	};

/**
@publishedAll
@released

eSCO unspecified bandwidth.  This value can only be used by the accepting side
of an eSCO link, to allow any bandwidth to be specified by the initiator.
Otherwise both sides of the link must agree on the same bandwidth.

@see CBluetoothSynchronousLink::SetBandwidth
@see CBluetoothSynchronousLink::AcceptConnection
*/
static const TUint32 KESCOBandwidthDontCare = KMaxTUint32;

/**
@internalTechnology

Bit positions of the individual local and remote features.
@see TBTFeatures
*/
enum TBTSupportedFeaturesBits
	{
	ESupportedThreeSlotPacketsBit				= 0,  /*!< Three slot packets are supported */
	ESupportedFiveSlotPacketsBit				= 1,  /*!< Five slot packets are supported */
	ESupportedEncryptionBit						= 2,  /*!< Encryption is supported */
	ESupportedSlotOffsetBit						= 3,  /*!< Slot offset is supported */
	ESupportedTimingAccuracyBit					= 4,  /*!< Timing accuracy is supported */
	ESupportedSwitchBit							= 5,  /*!< Role switch is supported */
	ESupportedHoldModeBit						= 6,  /*!< Hold mode is supported */
	ESupportedSniffModeBit						= 7,  /*!< Sniff mode is supported */
	ESupportedParkModeBit						= 8,  /*!< Park mode is supported */
	ESupportedRSSIBit							= 9,  /*!< Receive signal strength indication is supported */
	ESupportedChannelQualityDrivenDataRateBit	= 10, /*!< Channel quality driven data rate is supported */
	ESupportedSCOLinkBit						= 11, /*!< SCO links are supported */
	ESupportedHV2PacketsBit						= 12, /*!< HV2 packets are supported */
	ESupportedHV3PacketsBit						= 13, /*!< HV3 packets are supported */
	ESupportedu_lawLogBit						= 14, /*!< SCO u-law encoding is supported */
	ESupportedA_lawLogBit						= 15, /*!< SCO A-law encoding is supported */
	ESupportedCVSDBit							= 16, /*!< SCO Continuously variable slope delta modulation is supported */
	ESupportedPagingSchemeBit					= 17, /*!< Paging scheme is supported */
	ESupportedPowerControlBit					= 18, /*!< Power control is supported */
	ESupportedTransparentSCODataBit				= 19, /*!< Transparent SCO data is supported */
	ESupportedFlowControlLagBit0Bit				= 20, /*!< Flow control lag bit 0 is supported */
	ESupportedFlowControlLagBit1Bit				= 21, /*!< Flow control lag bit 1 is supported */
	ESupportedFlowControlLagBit2Bit				= 22, /*!< Flow control lag bit 2 is supported */
	ESupportedBroadcastEncryptionBit			= 23, /*!< Broadcast encryption is supported */
	
	EEDR_ACL_2MbpsModeBit						= 25, /*!< 2Mbps EDR ACL supported */
	EEDR_ACL_3MbpsModeBit						= 26, /*!< 3Mbps EDR ACL supported */
	ESupportedEnhancedEnquiryScanBit			= 27, /*!< Enhanced enquiry scan is supported */
	ESupportedInterlacedEnquiryScanBit			= 28, /*!< Interlaced enquiry scan is supported */
	ESupportedInterlacedPageScanBit				= 29, /*!< Interlaced page scan is supported */
	ESupportedRSSIWithInquiryResultsBit			= 30, /*!< Read signal strength indication with inquiry is supported */
	ESupportedExtendedSCOLinkBit				= 31, /*!< Extended SCO links are supported */
	ESupportedEV4PacketsBit						= 32, /*!< EV4 packets are supported */
	ESupportedEV5PacketsBit						= 33, /*!< EV5 packets are supported */
	
	ESupportedAFHCapableSlaveBit				= 35, /*!< Adaptive frequency hopping in slave role is supported */
	ESupportedAFHClassificationSlaveBit			= 36, /*!< Adaptive frequency hopping classification in slave role is supported */

	ESupportedEDRThreeSlotPacketsBit			= 39, /*!< Three slot EDR packets are supported */
	ESupportedEDRFiveSlotPacketsBit				= 40, /*!< Five slot EDR packets are supported */
	ESupportedSniffSubratingBit					= 41, /*!< Sniff subrating is supported */
	ESupportedEncryptionPauseResumeBit			= 42, /*!< Encryption Pause and Resume is supported */
	ESupportedAFHCapableMasterBit				= 43, /*!< Adaptive frequency hopping in master role is supported */
	ESupportedAFHClassificationMasterBit		= 44, /*!< Adaptive frequency hopping classification in master role is supported */
	EEDR_eSCO_2MbpsModeBit						= 45, /*!< 2Mbps EDR eSCO supported */
	EEDR_eSCO_3MbpsModeBit						= 46, /*!< 3Mbps EDR eSCO supported */
	ESupportedEDReSCOThreeSlotPacketsBit		= 47, /*!< Three slot EDR eSCO packets are supported */
	ESupportedExtendedInquiryResponseBit		= 48, /*!< Extended Inquiry Response */
	
	ESupportedSecureSimplePairingBit			= 51, /*!< Secure Simple Pairing */
	ESupportedEncapsulatedPDUBit				= 52, /*!< Encapsulated PDU */
	ESupportedErroneousDataReportingBit			= 53, /*!< Erroneous Data Reporting */
	ESupportedNonflushablePacketBoundaryFlagBit	= 54, /*!< Non-flushable Packet Boundary Flag */
	
	ESupportedLinkSupervisionTimeoutChangedEventBit	= 56, /*!< Link Supervision Timeout Changed Event */
	ESupportedInquiryResponseTXPowerLevelBit	= 57, /*!< Inquiry Response TX Power Level */
	
	ESupportedExtendedFeaturesBit				= 63, /*!< Additional features are supported */
	};

/**
@internalTechnology

Bit positions of the individual local supported HCI commands.
@see TBluetoothHciCommands
*/
enum TBluetoothSupportedCommandsBits
	{
	ESupportedInquiryCommand								= 0, /*!< Inquiry command is supported */
	ESupportedInquiryCancelCommand							= 1, /*!< Inquiry Cancel command is supported */
	ESupportedPeriodicInquiryModeCommand					= 2, /*!< Periodic Inquiry Mode command is supported */
	ESupportedExitPeriodicInquiryModeCommand				= 3, /*!< Exit Periodic Inquiry Mode command is supported */
	ESupportedCreateConnectionCommand						= 4, /*!< Create Connection command is supported */
	ESupportedDisconnectCommand								= 5, /*!< Disconnect command is supported */
	ESupportedAddSCOConnectionCommand						= 6, /*!< Add SCO Connection command is supported */
	ESupportedCancelCreateConnectionCommand					= 7, /*!< Cancel Create Connection command is supported */
	ESupportedAcceptConnectionRequestCommand				= 8, /*!< Accept Connection Request command is supported */
	ESupportedRejectConnectionRequestCommand				= 9, /*!< Reject Connection Request command is supported */
	ESupportedLinkKeyRequestReplyCommand					= 10, /*!< Link Key Request Reply command is supported */
	ESupportedLinkKeyRequestNegativeReplyCommand			= 11, /*!< Link Key Request Negative Reply command is supported */
	ESupportedPINCodeRequestReplyCommand					= 12, /*!< PIN Code Request Reply command is supported */
	ESupportedPINCodeRequestNegativeReplyCommand			= 13, /*!< PIN Code Request Negative Reply command is supported */
	ESupportedChangeConnectionPacketTypeCommand				= 14, /*!< Change Connection Packet Type command is supported */
	ESupportedAuthenticationRequestCommand					= 15, /*!< Authentication Request command is supported */
	ESupportedSetConnectionEncryptionCommand				= 16, /*!< Set Connection Encryption command is supported */
	ESupportedChangeConnectionLinkKeyCommand				= 17, /*!< Change Connection Link Key command is supported */
	ESupportedMasterLinkKeyCommand							= 18, /*!< Master Link Key command is supported */
	ESupportedRemoteNameRequestCommand						= 19, /*!< Remote Name Request command is supported */
	ESupportedCancelRemoteNameRequestCommand				= 20, /*!< Cancel Remote Name Request command is supported */
	ESupportedReadRemoteSupportedFeaturesCommand			= 21, /*!< Read Remote Supported Features command is supported */
	ESupportedReadRemoteExtendedFeaturesCommand				= 22, /*!< Read Remote Extended Features command is supported */
	ESupportedReadRemoteVersionInformationCommand			= 23, /*!< Read Remote Version Information command is supported */
	ESupportedReadClockOffsetCommand						= 24, /*!< Read Clock Offset command is supported */
	ESupportedReadLMPHandleCommand							= 25, /*!< Read LMP Handle command is supported */
	ESupportedHoldModeCommand								= 33, /*!< Hold Mode command is supported */
	ESupportedSniffModeCommand								= 34, /*!< Sniff Mode command is supported */
	ESupportedExitSniffModeCommand							= 35, /*!< Exit Sniff Mode command is supported */
	ESupportedParkStateCommand								= 36, /*!< Park State command is supported */
	ESupportedExitParkStateCommand							= 37, /*!< Exit Park State command is supported */
	ESupportedQoSSetupCommand								= 38, /*!< QoS Setup command is supported */
	ESupportedRoleDiscoveryCommand							= 39, /*!< Role Discovery command is supported */
	ESupportedSwitchRoleCommand								= 40, /*!< Switch Role command is supported */
	ESupportedReadLinkPolicySettingsCommand					= 41, /*!< Read Link Policy Settings command is supported */
	ESupportedWriteLinkPolicySettingsCommand				= 42, /*!< Write Link Policy Settings command is supported */
	ESupportedReadDefaultLinkPolicySettingsCommand			= 43, /*!< Read Default Link Policy Settings command is supported */
	ESupportedWriteDefaultLinkPolicySettingsCommand			= 44, /*!< Write Default Link Policy Settings command is supported */
	ESupportedFlowSpecificationCommand						= 45, /*!< Flow Specification command is supported */
	ESupportedSetEventMarkCommand							= 46, /*!< Set Event Mark command is supported */
	ESupportedResetCommand									= 47, /*!< Reset command is supported */
	ESupportedSetEventFilterCommand							= 48, /*!< Set Event Filter command is supported */
	ESupportedFlushCommand									= 49, /*!< Flush command is supported */
	ESupportedReadPINTypeCommand							= 50, /*!< Read PIN Type command is supported */
	ESupportedWritePINTypeCommand							= 51, /*!< Write PIN Type command is supported */
	ESupportedCreateNewUnitKeyCommand						= 52, /*!< Create New Unit Key command is supported */
	ESupportedReadStoredLinkKeyCommand						= 53, /*!< Read Stored Link Key command is supported */
	ESupportedWriteStoredLinkKeyCommand						= 54, /*!< Write Stored Link Key command is supported */
	ESupportedDeleteStoredLinkKeyCommand					= 55, /*!< Delete Stored Link Key command is supported */
	ESupportedWriteLocalNameCommand							= 56, /*!< Write Local Name command is supported */
	ESupportedReadLocalNameCommand							= 57, /*!< Read Local Name command is supported */
	ESupportedReadConnectionAcceptTimeoutCommand			= 58, /*!< Read Connection Accept Timeout command is supported */
	ESupportedWriteConnectionAcceptTimeoutCommand			= 59, /*!< Write Connection Accept Timeout command is supported */
	ESupportedReadPageTimeoutCommand						= 60, /*!< Read Page Timeout command is supported */
	ESupportedWritePageTimeoutCommand						= 61, /*!< Write Page Timeout command is supported */
	ESupportedReadScanEnableCommand							= 62, /*!< Read Scan Enable command is supported */
	ESupportedWriteScanEnableCommand						= 63, /*!< Write Scan Enable command is supported */
	ESupportedReadPageScanActivityCommand					= 64, /*!< Read Page Scan Activity command is supported */
	ESupportedWritePageScanActivityCommand					= 65, /*!< Write Page Scan Activity command is supported */
	ESupportedReadInquiryScanActivityCommand				= 66, /*!< Read Inquiry Scan Activity command is supported */
	ESupportedWriteInquiryScanActivityCommand				= 67, /*!< Write Inquiry Scan Activity command is supported */
	ESupportedReadClassOfDeviceCommand						= 72, /*!< Read Class Of Device command is supported */
	ESupportedWriteClassOfDeviceCommand						= 73, /*!< Write Class Of Device command is supported */
	ESupportedReadVoiceSettingCommand						= 74, /*!< Read Voice Setting command is supported */
	ESupportedWriteVoiceSettingCommand						= 75, /*!< Write Voice Setting command is supported */
	ESupportedReadAutomaticFlushTimeoutCommand				= 76, /*!< Read Automatic Flush Timeout command is supported */
	ESupportedWriteAutomaticFlushTimeoutCommand				= 77, /*!< Write Automatic Flush Timeout command is supported */
	ESupportedReadNumBroadcastRetransmissionsCommand		= 78, /*!< Read Num Broadcast Retransmissions command is supported */
	ESupportedWriteNumBroadcastRetransmissionsCommand		= 79, /*!< Write Num Broadcast Retransmissions command is supported */
	ESupportedReadHoldModeActivityCommand					= 80, /*!< Read Hold Mode Activity command is supported */
	ESupportedWriteHoldModeActivityCommand					= 81, /*!< Write Hold Mode Activity command is supported */
	ESupportedReadTransmitPowerLevelCommand					= 82, /*!< Read Transmit Power Level command is supported */
	ESupportedReadSynchronousFlowControlEnableCommand		= 83, /*!< Read Synchronous Flow Control Enable command is supported */
	ESupportedWriteSynchronousFlowControlEnableCommand		= 84, /*!< Write Synchronous Flow Control Enable command is supported */
	ESupportedSetHostControllerToHostFlowControlCommand		= 85, /*!< Set Host Controller To Host Flow Control command is supported */
	ESupportedHostBufferSizeCommand							= 86, /*!< Host Buffer Size command is supported */
	ESupportedHostNumberOfCompletedPacketsCommand			= 87, /*!< Host Number Of Completed Packets command is supported */
	ESupportedReadLinkSupervisionTimeoutCommand				= 88, /*!< Read Link Supervision Timeout command is supported */
	ESupportedWriteLinkSupervisionTimeoutCommand			= 89, /*!< Write Link Supervision Timeout command is supported */
	ESupportedReadNumberofSupportedIACCommand				= 90, /*!< Read Number of Supported IAC command is supported */
	ESupportedReadCurrentIACLAPCommand						= 91, /*!< Read Current IAC LAP command is supported */
	ESupportedWriteCurrentIACLAPCommand						= 92, /*!< Write Current IAC LAP command is supported */
	ESupportedReadPageScanModeCommand						= 95, /*!< Read Page Scan Mode command is supported */
	ESupportedWritePageScanModeCommand						= 96, /*!< Write Page Scan Mode command is supported */
	ESupportedSetAFHChannelClassificationCommand			= 97, /*!< Set AFH Channel Classification command is supported */
	ESupportedReadInquiryScanTypeCommand					= 100, /*!< Read Inquiry Scan Type command is supported */
	ESupportedWriteInquiryScanTypeCommand					= 101, /*!< Write Inquiry Scan Type command is supported */
	ESupportedReadInquiryModeCommand						= 102, /*!< Read Inquiry Mode command is supported */
	ESupportedWriteInquiryModeCommand						= 103, /*!< Write Inquiry Mode command is supported */
	ESupportedReadPageScanTypeCommand						= 104, /*!< Read Page Scan Type command is supported */
	ESupportedWritePageScanTypeCommand						= 105, /*!< Write Page Scan Type command is supported */
	ESupportedReadAFHChannelAssessmentModeCommand			= 106, /*!< Read AFH Channel Assessment Mode command is supported */
	ESupportedWriteAFHChannelAssessmentModeCommand			= 107, /*!< Write AFH Channel Assessment Mode command is supported */
	ESupportedReadLocalVersionInformationCommand			= 115, /*!< Read Local Version Information command is supported */
	ESupportedReadLocalSupportedFeaturesCommand				= 117, /*!< Read Local Supported Features command is supported */
	ESupportedReadLocalExtendedFeaturesCommand				= 118, /*!< Read Local Extended Features command is supported */
	ESupportedReadBufferSizeCommand							= 119, /*!< Read Buffer Size command is supported */
	ESupportedReadCountryCodeCommand						= 120, /*!< Read Country Code [Deprecated] command is supported */
	ESupportedReadBDADDRCommand								= 121, /*!< Read BD ADDR command is supported */
	ESupportedReadFailedContactCountCommand					= 122, /*!< Read Failed Contact Count command is supported */
	ESupportedResetFailedContactCountCommand				= 123, /*!< Reset Failed Contact Count command is supported */
	ESupportedGetLinkQualityCommand							= 124, /*!< Get Link Quality command is supported */
	ESupportedReadRSSICommand								= 125, /*!< Read RSSI command is supported */
	ESupportedReadAFHChannelMapCommand						= 126, /*!< Read AFH Channel Map command is supported */
	ESupportedReadBDClockCommand							= 127, /*!< Read BD Clock command is supported */
	ESupportedReadLoopbackModeCommand						= 128, /*!< Read Loopback Mode command is supported */
	ESupportedWriteLoopbackModeCommand						= 129, /*!< Write Loopback Mode command is supported */
	ESupportedEnableDeviceUnderTestModeCommand				= 130, /*!< Enable Device Under Test Mode command is supported */
	ESupportedSetupSynchronousConnectionCommand				= 131, /*!< Setup Synchronous Connection command is supported */
	ESupportedAcceptSynchronousConnectionCommand			= 132, /*!< Accept Synchronous Connection command is supported */
	ESupportedRejectSynchronousConnectionCommand			= 133, /*!< Reject Synchronous Connection command is supported */
	ESupportedReadExtendedInquiryResponseCommand			= 136, /*!< Read Extended Inquiry Response command is supported */
	ESupportedWriteExtendedInquiryResponseCommand			= 137, /*!< Write Extended Inquiry Response command is supported */
	ESupportedRefreshEncryptionKeyCommand					= 138, /*!< Refresh Encryption Key command is supported */
	ESupportedSniffSubratingCommand							= 140, /*!< Sniff Subrating command is supported */
	ESupportedReadSimplePairingModeCommand					= 141, /*!< Read Simple Pairing Mode command is supported */
	ESupportedWriteSimplePairingModeCommand					= 142, /*!< Write Simple Pairing Mode command is supported */
	ESupportedReadLocalOOBDataCommand						= 143, /*!< Read Local OOB Data command is supported */
	ESupportedReadInquiryResponseTransmitPowerCommand		= 144, /*!< Read Inquiry Response Transmit Power command is supported */
	ESupportedWriteInquiryTransmitPowerLevelCommand			= 145, /*!< Write Inquiry Transmit Power Level command is supported */
	ESupportedReadDefaultErroneousDataReportingCommand		= 146, /*!< Read Default Erroneous Data Reporting command is supported */
	ESupportedWriteDefaultErroneousDataReportingCommand		= 147, /*!< Write Default Erroneous Data Reporting command is supported */
	ESupportedIOCapabilityRequestReplyCommand				= 151, /*!< IO Capability Request Reply command is supported */
	ESupportedUserConfirmationRequestReplyCommand			= 152, /*!< User Confirmation Request Reply command is supported */
	ESupportedUserConfirmationRequestNegativeReplyCommand	= 153, /*!< User Confirmation Request Negative Reply command is supported */
	ESupportedUserPasskeyRequestReplyCommand				= 154, /*!< User Passkey Request Reply command is supported */
	ESupportedUserPasskeyRequestNegativeReplyCommand		= 155, /*!< User Passkey Request Negative Reply command is supported */
	ESupportedRemoteOOBDataRequestReplyCommand				= 156, /*!< Remote OOB Data Request Reply command is supported */
	ESupportedWriteSimplePairingDebugModeCommand			= 157, /*!< Write Simple Pairing Debug Mode command is supported */
	ESupportedEnhancedFlushCommand							= 158, /*!< Enhanced Flush command is supported */
	ESupportedRemoteOOBDataRequestNegativeReplyCommand		= 159, /*!< Remote OOB Data Request Negative Reply command is supported */
	ESupportedSendKeypressNotificationCommand				= 162, /*!< Send Keypress Notification command is supported */
	ESupportedIOCapabilitiesResponseNegativeReplyCommand	= 163, /*!< IO Capabilities Response Negative Reply command is supported */
	};

/**
@publishedAll
@released

Bluetooth SIG specified values indicating whether a device
is physically able to support a baseband (or link manager protocol) feature
*/
enum TBTSupportedFeatures
	{
	ESupportedThreeSlotPackets				= 1<<0,  /*!< Three slot packets are supported */
	ESupportedFiveSlotPackets				= 1<<1,  /*!< Five slot packets are supported */
	ESupportedEncryption					= 1<<2,  /*!< Encryption is supported */
	ESupportedSlotOffset					= 1<<3,  /*!< Slot offset is supported */
	ESupportedTimingAccuracy				= 1<<4,  /*!< Timing accuracy is supported */
	ESupportedSwitch						= 1<<5,  /*!< Role switch is supported */
	ESupportedHoldMode						= 1<<6,  /*!< Hold mode is supported */
	ESupportedSniffMode						= 1<<7,  /*!< Sniff mode is supported */
	ESupportedParkMode						= 1<<8,  /*!< Park mode is supported */
	ESupportedRSSI							= 1<<9,  /*!< Receive signal strength indication is supported */
	ESupportedChannelQualityDrivenDataRate	= 1<<10, /*!< Channel quality driven data rate is supported */
	ESupportedSCOLink						= 1<<11, /*!< SCO links are supported */
	ESupportedHV2Packets					= 1<<12, /*!< HV2 packets are supported */
	ESupportedHV3Packets					= 1<<13, /*!< HV3 packets are supported */
	ESupportedu_lawLog						= 1<<14, /*!< SCO u-law encoding is supported */
	ESupportedA_lawLog						= 1<<15, /*!< SCO A-law encoding is supported */
	ESupportedCVSD							= 1<<16, /*!< SCO Continuously variable slope delta modulation is supported */
	ESupportedPagingScheme					= 1<<17, /*!< Paging scheme is supported */
	ESupportedPowerControl					= 1<<18, /*!< Power control is supported */
	ESupportedTransparentSCOData			= 1<<19, /*!< Transparent SCO data is supported */
	ESupportedFlowControlLagBit0			= 1<<20, /*!< Flow control lag bit 0 is supported */
	ESupportedFlowControlLagBit1			= 1<<21, /*!< Flow control lag bit 1 is supported */
	ESupportedFlowControlLagBit2			= 1<<22, /*!< Flow control lag bit 2 is supported */
	};

/**
@publishedAll
@released

Bitmask values for notifying/requesting notification of the state of a physical link.

These values have a two fold purpose:
1) They can be used along with TBTPhysicalLinkStateNotifierCombinations to specify
a set of baseband change events for which notification is desired.
2) They can be used to notify the state of a physical link or a subset of that state.
For example if only mode change events are being monitored, then at each mode change event
only the bit reperesenting the new mode will be returned, however if the whole link state
is required, then a combination of bit values indicating that state will be returned.

THESE BIT VALUES MUST ONLY BE USED WHEN REQUESTING NOTIFICATION, OR WHEN PARSING THE
RESULTS OF A NOTIFICATION. All other baseband state activities should use one of the 
appropriate Bluetooth SIG specified enums
@see TBTBasebandRole
@see TBTLinkMode
@see TBTLinkModeCombinations
@see TBTPacketType
@see TBTPacketTypeCombinations
*/
enum TBTPhysicalLinkStateNotifier
	{
	ENotifyMaster					= 0x00000001, /*!< Master */
	ENotifySlave					= 0x00000002, /*!< Slave */

	ENotifyActiveMode				= 0x00000004, /*!< Active mode */
	ENotifySniffMode				= 0x00000008, /*!< Sniff mode */
	ENotifyParkMode					= 0x00000010, /*!< Park mode */
	ENotifyHoldMode					= 0x00000020, /*!< Hold mode */

	ENotifyMaxSlots1				= 0x00000040, /*!< Max slots 1 */
	ENotifyMaxSlots3				= 0x00000080, /*!< Max slots 3 */
	ENotifyMaxSlots5				= 0x00000100, /*!< Max slots 5 */

	ENotifyPacketsDM1				= 0x00000200, /*!< Packets DM1 */
	ENotifyPacketsDH1				= 0x00000400, /*!< Packets DH1 */
	ENotifyPacketsDM3				= 0x00000800, /*!< Packets DM3 */
	ENotifyPacketsDH3				= 0x00001000, /*!< Packets DH3 */
	ENotifyPacketsDM5				= 0x00002000, /*!< Packets DM5 */
	ENotifyPacketsDH5				= 0x00004000, /*!< Packets DH5 */

	ENotifyPacketsHV1				= 0x00008000, /*!< HV1 */
	ENotifyPacketsHV2				= 0x00010000, /*!< HV2 */
	ENotifyPacketsHV3				= 0x00020000, /*!< HV3 */

	ENotifyAuthenticationComplete	= 0x00040000, /*!< Authentication Complete */
	ENotifyEncryptionChangeOn		= 0x00080000, /*!< Encryption Change On */
	ENotifyEncryptionChangeOff		= 0x00100000, /*!< Encryption Change Off */

	ENotifyPhysicalLinkUp			= 0x00200000, /*!< Physical Link Up */
	ENotifyPhysicalLinkDown			= 0x00400000, /*!< Physical Link Down */
	ENotifyPhysicalLinkError		= 0x00800000, /*!< Physical Link Error */

	ENotifySynchronousLinkUp		= 0x01000000, /*!< Synchronous Link Up */
	ENotifySynchronousLinkDown		= 0x02000000, /*!< Synchronous Link Down */
	ENotifySynchronousLinkError		= 0x04000000, /*!< Synchronous Link Error */

	/**
 	@deprecated This has been superseded by ENotifySynchronousLinkUp
 	@see ENotifySynchronousLinkUp 
 	*/
 	ENotifySCOLinkUp				= ENotifySynchronousLinkUp,
 	/**
 	@deprecated This has been superseded by ENotifySynchronousLinkDown
 	@see ENotifySynchronousLinkDown 
 	*/
 	ENotifySCOLinkDown				= ENotifySynchronousLinkDown, 
 	/**
 	@deprecated This has been superseded by ENotifySynchronousLinkError
 	@see ENotifySynchronousLinkError 
 	*/
 	ENotifySCOLinkError				= ENotifySynchronousLinkError 

	};

/**
@publishedAll
@released

Bitmask values to help request notification of the state of a physical link.
@see TBTPhysicalLinkStateNotifier
*/
enum TBTPhysicalLinkStateNotifierCombinations
	{
	ENotifyAnyRole					= ENotifyMaster | ENotifySlave,
	ENotifyAnyLowPowerMode			= ENotifySniffMode | ENotifyParkMode | ENotifyHoldMode,
	ENotifyAnyPowerMode				= ENotifyActiveMode | ENotifyAnyLowPowerMode,
	ENotifyAnyMaxSlots				= ENotifyMaxSlots1 | ENotifyMaxSlots3 | ENotifyMaxSlots5,
	ENotifyAnyACLPacketType			= ENotifyPacketsDM1 | ENotifyPacketsDH1 | ENotifyPacketsDM3 | EPacketsDH3 | EPacketsDM5 | EPacketsDH5,
	ENotifyAnySCOPacketType			= ENotifyPacketsHV1 | ENotifyPacketsHV2 | ENotifyPacketsHV3,
	ENotifyAnyPacketType			= ENotifyAnyACLPacketType | ENotifyAnySCOPacketType,
	ENotifyAnyPhysicalLinkState		= 0xffffffff,
	};

/**
@publishedAll
@released

The maximum length of an SDP UUID.
*/
static const TInt KSdpUUIDMaxLength			= 16;

/**
@publishedAll
@released

The size of a bluetooth device address in bytes.
*/
const TInt KBTDevAddrSize=0x06;

/**
@publishedAll
@released

The size of a bluetooth device address in bytes.
*/
const TInt KBTMaxDevAddrSize = KBTDevAddrSize;

/**
@publishedAll
@released

48-bit bluetooth device address.
Each bluetooth device has a unique address built into the hardware, which
is represented by this class. Used for identifying remote addresses.
The interface operates in a big-endian manner -- e.g. addr[0] refers
to the most significant byte of the address. This is the same ordering
as the addresses would naturally be written down on paper.
**/
NONSHARABLE_CLASS(TBTDevAddr)
    {
public:
    IMPORT_C TBTDevAddr();
    IMPORT_C TBTDevAddr(const TInt64 &aInt);
    IMPORT_C TBTDevAddr(const TDesC8 &aDes);
    IMPORT_C TBool operator==(const TBTDevAddr& aAddr) const;
    IMPORT_C TBool operator!=(const TBTDevAddr& aAddr) const;
	IMPORT_C const TUint8 &operator[](TInt aIndex) const;
	IMPORT_C TUint8 &operator[](TInt aIndex);
	IMPORT_C void Reset();
	IMPORT_C TPtr8 Des();
	IMPORT_C const TPtrC8 Des() const;
	IMPORT_C TInt SetReadable(const TDesC& aSource);
	IMPORT_C void GetReadable(TDes& aDest) const;
	IMPORT_C void GetReadable(TDes& aDest, const TDesC& aPrepend, const TDesC& aByteSeperator, const TDesC& aAppend) const;
    IMPORT_C TBool operator<=(const TBTDevAddr& aAddr) const;
private:
	TFixedArray<TUint8, KBTDevAddrSize> iAddr;

	// This data padding has been added to help prevent future binary compatibility breaks	
	// iPadding hasn't been zero'd because it is currently not used
	TUint16     iPadding; 			
    };

/**
@publishedAll
@released

A Bluetooth Universally Unique Identifier.

This is a 128-bit quantity that can be created without a central registry 
while still being globally unique.
UUIDs are always held in full 128 bit format, however they can be set from 
BT SIG short form (16 or 32 bit) addresses, and returned as down to their 
shortest form using ShortestForm().
**/
NONSHARABLE_CLASS(TUUID)
	{
public:
	IMPORT_C TUUID();
	IMPORT_C TUUID(TUint32 aLong);
	IMPORT_C TUUID(TUint32 aHH, TUint32 aHL, TUint32 aLH, TUint32 aLL);
	IMPORT_C TUUID(const TUid& aUid);
	IMPORT_C void SetL(const TDesC8& aDes);
	IMPORT_C const TPtrC8 LongForm() const;
	IMPORT_C const TPtrC8 ShortestForm() const;
	IMPORT_C const TPtrC8 Des() const;
	/**
	@deprecated
	Use SpecifiedLengthL(TInt aLength) instead
	*/
	IMPORT_C const TPtrC8 FixedLengthL(TInt aLength) const;
	IMPORT_C TInt MinimumSize() const;
    IMPORT_C TBool operator==(const TUUID& aUUID) const;
    IMPORT_C TBool operator!=(const TUUID& aUUID) const;
	IMPORT_C const TUint8 &operator[](TInt aIndex) const;
	IMPORT_C TUint8 &operator[](TInt aIndex);
	IMPORT_C const TPtrC8 SpecifiedLengthL(TInt aLength) const;
	IMPORT_C void SetFromLittleEndianL(const TDesC8& aDes);
private:
	TFixedArray<TUint8, KSdpUUIDMaxLength> iUUID;	

	// This data padding has been added to help prevent future binary compatibility breaks	
	// Neither iPadding1 nor iPadding2 have been zero'd because they are currently not used
	TUint32		iPadding1;
	TUint32		iPadding2;
	};


/**
@publishedAll
@released

A UUID container class
*/
NONSHARABLE_CLASS(RUUIDContainer)
	{
public:
	IMPORT_C void Close();
	IMPORT_C void Reset();
	IMPORT_C TInt Count() const;
	IMPORT_C TUUID& operator[](TInt aIndex);
	IMPORT_C const TUUID& operator[](TInt aIndex) const;
	IMPORT_C const TUUID& At(TInt aIndex) const;
	IMPORT_C TBool IsPresent(const TUUID& aUuid) const;
	IMPORT_C TInt Add(const TUUID& aUuid);

private:
	RArray<TUUID> iUUIDs;
	
	// This data padding has been added to help prevent future binary compatibility breaks
	// Neither iPadding1 nor iPadding2 have been zero'd because they are currently not used
	TUint32		iPadding1;
	TUint32		iPadding2;
	};


/**
@publishedAll
@released

An EIR UUID container class. Contains UUIDs and indications of data completeness
*/
NONSHARABLE_CLASS(RExtendedInquiryResponseUUIDContainer)
	{
public:
	enum TUUIDType
		{
		EUUID16  = 0x1,
		EUUID32  = 0x2,
		EUUID128 = 0x4,
		};
	
public:
	IMPORT_C void Close();
	IMPORT_C RUUIDContainer& UUIDs();
	IMPORT_C void SetCompleteness(TUUIDType aType, TBool aIsComplete);
	IMPORT_C TBool GetCompleteness(TUUIDType aType) const;

private:
	RUUIDContainer iUUIDs;
	TInt iCompleteness;
	
	// This data padding has been added to help prevent future binary compatibility breaks
	// Neither iPadding1 nor iPadding2 have been zero'd because they are currently not used
	TUint32     iPadding1;
	TUint32     iPadding2;
	};

/**
@publishedAll
@released

The size of a link key, in bytes.
*/
const TUint8 KHCILinkKeySize=16;

/**
@publishedAll
@released

The size of a pin code, in bytes.
*/
const TUint8 KHCIPINCodeSize=16;

/**
@publishedAll
@released

Link key structure.
*/
NONSHARABLE_CLASS(TLinkKeyV10)
    {
public:
    TUint8 iLinkKey[KHCILinkKeySize]; /*!< The link key */
    };

/**
@publishedAll
@released

Typedef'ed TPckgBuf of the class TLinkKeyV10.
*/
typedef TPckgBuf<TLinkKeyV10> TBTLinkKey;

/**
The type of a link key with a remote device
@publishedAll
@released
*/
enum TBTLinkKeyType
	{
	ELinkKeyCombination,					/*!< this key has been generated with pairing with pre-v2.1 Bluetooth devices. */
	ELinkKeyUnauthenticatedUpgradable,		/*!< this key hasn't yet been tried with MITM protection */
	ELinkKeyUnauthenticatedNonUpgradable,	/*!< this key tried MITM protection; remote device incapable */
	ELinkKeyAuthenticated,					/*!< this key authenticated with MITM protection */
	ELinkKeyDebug							/*!< this key has been generated when in simple pairing debug mode */
	};

/**
@publishedAll
@released

Bluetooth PIN Code structure.
*/
NONSHARABLE_CLASS(TPINCodeV10)
    {
public:
	IMPORT_C TBool operator==(const TPINCodeV10& aTPINCodeV10) const;
	
public:
    TUint8 iLength; /*!< The length of the pin key */
    TUint8 iPIN[KHCIPINCodeSize]; /*!< The pin code */
    };

/**
@publishedAll
@released

Typedef'ed TPckgBuf of the class TPINCodeV10.
*/
typedef TPckgBuf<TPINCodeV10> TBTPinCode;

/**
The size of a simple pairing hash in bytes.
@publishedPartner
@released
*/
const TInt KBluetoothSimplePairingHashSize = 16;
/**
A representation of the simple pairing hash.
@publishedPartner
@released
*/
typedef TBuf8<KBluetoothSimplePairingHashSize> TBluetoothSimplePairingHash;

/**
The size of a simple pairing hash in randomizer.
@publishedPartner
@released
*/
const TInt KBluetoothSimplePairingRandomizerSize = 16;
/**
A representation of the simple pairing randomizer.
@publishedPartner
@released
*/
typedef TBuf8<KBluetoothSimplePairingRandomizerSize> TBluetoothSimplePairingRandomizer;

/**
Extended Inquiry Response Class
This class takes a reference from inquiry result, which could hold both local name and Extended Inquiry Response. 
It provides API to parse and return the local name and data for any Extended Inquiry Response tag.
To get Device Name, Manufacturer Specific Data or Flags, firstly getting length of the data, 
and then allocating a suitable buffer, which is where the data will be placed. 
*/
NONSHARABLE_CLASS(TBluetoothNameRecordWrapper)
{
public:
	IMPORT_C explicit TBluetoothNameRecordWrapper(const TNameRecord& aNameRecord);
	IMPORT_C TInt GetDeviceName(TDes16& aName, TBool& aIsComplete) const;
	IMPORT_C TInt GetServiceClassUuids(RExtendedInquiryResponseUUIDContainer& aEIRContainer) const;
	IMPORT_C TInt GetVendorSpecificData(TDes8& aDes) const;
	IMPORT_C TInt GetTxPowerLevel(TInt8& aTxPowerLevel) const;
	IMPORT_C TInt GetFlags(TDes8& aDes) const;
	IMPORT_C TInt GetDeviceNameLength() const;
	IMPORT_C TInt GetVendorSpecificDataLength() const;
	IMPORT_C TInt GetFlagsLength() const;

private:
	TInt AddUuids16(RExtendedInquiryResponseUUIDContainer& aEIRContainer, TPtrC8& aUuids) const;
	TInt AddUuids128(RExtendedInquiryResponseUUIDContainer& aEIRContainer, TPtrC8& aUuids) const;
private:
	TExtendedInquiryResponseDataCodec iEirCodec;
	
	// This data padding has been added to help prevent future binary compatibility breaks	
	// Neither iPadding1 nor iPadding2 have been zero'd because they are currently not used
	TUint32		iPadding1;
	TUint32		iPadding2;
};

/**
@publishedAll
@released

Contains information resulting from a baseband notification.
*/
NONSHARABLE_CLASS(TBTBasebandEventNotification)
	{
public:
	/** 
	Constructor.
	@param aEventType The type of event.
	@param aErrorCode The error code.
	*/
	TBTBasebandEventNotification(TUint32 aEventType, TInt aErrorCode = KErrNone) : iEventType(aEventType), iErrorCode(aErrorCode) {};

	/**
	Default constructor.
	*/
	TBTBasebandEventNotification() : iEventType(0), iErrorCode(KErrNone) {};

	/**
	Copy constructor.
	@param aEvent The event to copy.
	*/
	TBTBasebandEventNotification(const TBTBasebandEventNotification& aEvent) : iEventType(aEvent.iEventType), iErrorCode(aEvent.iErrorCode) {};

	/**
	The event type.
	@return The event type.
	*/
	TUint32 EventType() const	{ return iEventType; };

	/**
	The Bluetooth SIG error code associated with the event.
	@return The SIG error code.
	*/
	TInt ErrorCode() const		{ return iErrorCode; };

	/**
	The Symbian HCI error code associated with the event.
	@return The Symbian error code.
	*/
	IMPORT_C TInt SymbianErrorCode() const;

	/**
	Set the event type.
	@param aEventType The event type.
	*/
	void SetEventType(TUint32 aEventType)	{ iEventType = aEventType; };

	/**
	Set the error code.
	@param aErrorCode The Bluetooth SIG error code.
	*/
	void SetErrorCode(TInt aErrorCode)		{ iErrorCode = aErrorCode; };

private:
	TUint32 iEventType;
	TInt iErrorCode;
	};

/**
@publishedAll
@released

Typedef'ed pckgbuf of the class TBTBasebandEventNotification.
*/
typedef TPckgBuf<TBTBasebandEventNotification> TBTBasebandEvent;

/**
@publishedAll
@released

General Unlimited Inquiry Access Code
*/
const TUint KGIAC=0x9e8b33;

/**
@publishedAll
@released

Limited Inquiry Access Code
*/
const TUint KLIAC=0x9e8b00;


/**
@publishedAll
@released

API class for setting up an L2Cap configuration

This class may be used to set all or a subset of the following configuration items:
Channel Reliability (and associated timer)
Maximum Transmission Unit
Maximum Receive Unit
Channel Priority

If a configuration item is to be set, then its 'Set' or 'Setup'
method should be called.

Once a TL2CapConfig object has been set up it should be sent using
RSocket::SetOption or RSocket::Ioctl (or the CBluetoothSocket) equivalents.

@see RSocket
@see CBluetoothSocket
*/
NONSHARABLE_CLASS(TL2CapConfig)
	{
public:
	/**	
	Priority required for data on L2Cap channel
	*/
	enum TChannelPriority
		{
		EHigh		= 2,
		EMedium		= 1,
		ELow		= 0,
		};

	/**	
	Reliability of data tranfer required for L2Cap channel
	*/
	enum TChannelReliability
		{
		EReliableChannel,
		EUnreliableChannel,
		};	

	/**	
	Timer values in milliseconds for reliable and unreliable channels
	*/
	enum TL2CapConfigSpecifiedTimers
		{
		/**
		This is a time in milliseconds. However 0xffff has been given a special meaning 
		in this interface. It means	"Allow up 256 transmissions of a single packet before 
		giving up and disconnecting the L2Cap channel.". This is the maximum number of
		transmissions effectively allowed by the spec.
		*/
		EDefaultRetransmission = 0xffff,
		/**
		Minimum data obsolescence timeout required because data packets 
		will not ever be sent if we flush them too quickly.
		Speed of sending data depends on how many channels are open and channel priority.
		*/
		EMinDataObsolescenceTimeout = 0x0a,
		/**
		This is translated to mean never flush (as per spec).
		*/
		EDefaultDataObsolescenceTimeout = 0xffff, 
		};	

	/**	
	Used to indicate which config options have been specified by the user
	*/
	enum TL2CapConfigSpecifiedMask
		{
		ENoConfigElementsSpecified			= 0x0000,
		EMTUSizeSpecifiedMask				= 0x0001,
		EMRUSizeSpecifiedMask				= 0x0002,
		EReliabilitySpecifiedMask			= 0x0004,
		EPrioritySpecifiedMask				= 0x0008,
		};
		
	IMPORT_C TL2CapConfig();

	IMPORT_C TInt SetMaxTransmitUnitSize(TUint16 aSize = 0xffff);
	IMPORT_C TUint16 MaxTransmitUnitSize(TBool& aIsSpecified) const;
	IMPORT_C TInt SetMaxReceiveUnitSize(TUint16 aSize = 0xffff);
	IMPORT_C TUint16 MaxReceiveUnitSize(TBool& aIsSpecified) const;

	IMPORT_C TInt ConfigureReliableChannel(TUint16 aRetransmissionTimer);
	IMPORT_C TInt ConfigureUnreliableChannel(TUint16 aObsolescenceTimer);
	IMPORT_C TChannelReliability ChannelReliability(TBool& aIsSpecified, TUint16& aAssociatedTimer) const;
	
	IMPORT_C TInt ConfigureChannelPriority(TChannelPriority aPriority);
	IMPORT_C TChannelPriority ChannelPriority(TBool& aIsSpecified) const;
	
	/**
	@deprecated
	Use ConfigureReliableChannel(TUint16 aRetransmissionTimer) instead
	*/
	IMPORT_C TInt SetupReliableChannel(TUint16 aRetransmissionTimer = EDefaultRetransmission);
	/**
	@deprecated
	Use ConfigureUnreliableChannel(TUint16 aObsolescenceTimer) instead
	*/
	IMPORT_C TInt SetupUnreliableChannel(TUint16 aObsolescenceTimer = EDefaultDataObsolescenceTimeout);
	/**
	@deprecated
	Use ConfigureChannelPriority(TChannelPriority aPriority) instead
	*/
	IMPORT_C TInt SetChannelPriority(TChannelPriority aPriority = ELow);
		
private:
	TUint16 iMTUSize;
	TUint16 iMRUSize;
	TChannelReliability iChannelReliability;
	TUint16	iChannelReliabilityTimer;
	TChannelPriority iChannelPriority;
	TUint16 iSpecifiedMask;

	// This data padding has been added to help prevent future binary compatibility breaks
	// Neither iPadding1 nor iPadding2 have been zero'd because they are currently not used	
	TUint32     iPadding1; 
	TUint32     iPadding2; 
	};

/**
@publishedAll
@released

Typedef to represent a L2CAP Config object.
*/
typedef TPckgBuf<TL2CapConfig> TL2CapConfigPkg;


enum TEirWrapperPanics
	{
	EEirBadUuid16List = 0,
	EEirBadUuid128List = 1,
	};
_LIT(KEirWrapperPanicName, "ExtendedInquiryResponseWrapper");

#endif	//_BTTYPES_H
