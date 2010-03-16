// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// Declares the constants and typedefs which come from TIA637-B.
// 
//



/**
 @file
 @publishedAll
 @interim
*/

#if !(defined __TIA637_H__)
#define __TIA637_H__

#include <e32def.h>				// T Type  Definitions

namespace tia637
	{

	/** Defines the Transport Layer Parameter Id from TIA/EIA-637-B table 3.4.3-1
	@publishedAll
	@interim
	*/
	typedef TUint8 TTpParameterId; // Note: if you change this type, you will have to change the
									// Externalize and Internalize methods where this is used.

		const TTpParameterId		KTeleserviceId				= 0;
		const TTpParameterId		KServiceCategory			= 1;
		const TTpParameterId		KOriginatingAddress			= 2;
		const TTpParameterId		KOriginatingSubAddress		= 3;
		const TTpParameterId		KDestinationAddress			= 4;
		const TTpParameterId		KDestinationSubAddress		= 5;
		const TTpParameterId		KBearerReplyOption			= 6;
		const TTpParameterId		KCauseCode					= 7;
		const TTpParameterId		KBearerData					= 8;
		const TTpParameterId		KNumberOfParameterIds		= 9;	

	/** Defines the Reply Sequence Number type from TIA/EIA-637-B
	@publishedAll
	@interim
	*/
	typedef TUint8 	TReplySequenceNum;	
		const TReplySequenceNum		KMaxBearerReplySequenceNumber = 64;

	/** Defines the ServiceCategory from TSB58-D Table 9.3.1-1
	@publishedAll
	@interim
	*/
	typedef TUint16 TServiceCategory;
		const TServiceCategory	KUnknownServiceCategory			= 0;
		const TServiceCategory	KEmergencyBroadcasts			= 1;
		const TServiceCategory	KAdministrative					= 2;
		const TServiceCategory	KMaintenance					= 3;
		const TServiceCategory	KGeneralNewsLocal				= 4;
		const TServiceCategory	KGeneralNewsRegional			= 5;
		const TServiceCategory	KGeneralNewsNational			= 6;
		const TServiceCategory	KGeneralNewsInternational		= 7;
		const TServiceCategory	KBusinessFinancialNewsLocal		= 8;
		const TServiceCategory	KBusinessFinancialNewsRegional	= 9;
		const TServiceCategory	KBusinessFinancialNewsNational	= 10;
		const TServiceCategory	KBusinessFinancialNewsIntl		= 11;
		const TServiceCategory	KSportNewsLocal					= 12;
		const TServiceCategory	KSportNewsRegional				= 13;
		const TServiceCategory	KSportNewsNational				= 14;
		const TServiceCategory	KSportNewsInternational			= 15;
		const TServiceCategory	KEntertainmentNewsLocal			= 16;
		const TServiceCategory	KEntertainmentNewsRegional		= 17;
		const TServiceCategory	KEntertainmentNewsNational		= 18;
		const TServiceCategory	KEntertainmentNewsInternational	= 19;
		const TServiceCategory	KLocalWeather					= 20;
		const TServiceCategory	KAreaTrafficReports				= 21;
		const TServiceCategory	KLocalAirportFlightSchedules	= 22;
		const TServiceCategory	KRestaruants					= 23;
		const TServiceCategory	KLodgings						= 24;
		const TServiceCategory	KRetailDirectoryAdvertisements	= 25;
		const TServiceCategory	KAdvertisements					= 26;
		const TServiceCategory	KStockQuotes					= 27;
		const TServiceCategory	KEmploymentOpportunities		= 28;
		const TServiceCategory	KMedicalHealthHospitals			= 29;
		const TServiceCategory	KTechnologyNews					= 30;
		const TServiceCategory	KMulticategory					= 31;
		const TServiceCategory	KMaxCategory					= 31;
		

	/** Defines the Teleservises Id from TIA/EIA-41-E Reballot version
	@publishedAll
	@interim
	*/
	typedef TUint16 TTeleserviceId;
		const TTeleserviceId 	KTeleserviceNotUsed	= 0;   // Not Used
		const TTeleserviceId 	KTeleserviceCMT91 	= 4096;// IS-91 Extended Protocol Enhanced Services
		const TTeleserviceId	KTeleserviceWPT 	= 4097;// Wireless Paging Teleservice	
		const TTeleserviceId	KTeleserviceWMT 	= 4098;// Wireless Messaging Teleservice
		const TTeleserviceId	KTeleserviceVMN		= 4099;// Voice Mail Notification
		const TTeleserviceId	KTeleserviceWAP		= 4100;// Wireless Application Protocol
		const TTeleserviceId	KTeleserviceWEMT	= 4101;// Wireless Enhanced Messaging Teleservice
		const TTeleserviceId 	KTeleserviceSCPT	= 4102;// Service Category Programming Teleservice
		const TTeleserviceId 	KTeleserviceCATPT	= 4103;// Card Application Toolkit Protocol Teleservice
		const TInt KNumberOfTelservices                     = 8;

	/** Defines the Message Encoding from TSB58-D Table 9.1-1
	@publishedAll
	@interim
	*/
	typedef TUint8 TCdmaMessageEncoding;
		
		const TCdmaMessageEncoding	KCdmaEncodingOctetUnspecified			=0x0;
		const TCdmaMessageEncoding	KCdmaEncodingIS91ExtendedProtocolMessage=0x1;
		const TCdmaMessageEncoding	KCdmaEncoding7BitASCII					=0x2;
		const TCdmaMessageEncoding	KCdmaEncodingIA5						=0x3;
		const TCdmaMessageEncoding	KCdmaEncodingUnicode					=0x4;
		const TCdmaMessageEncoding	KCdmaEncodingShiftJIS					=0x5;
		const TCdmaMessageEncoding	KCdmaEncodingKorean						=0x6;
		const TCdmaMessageEncoding	KCdmaEncodingLatinHebrew				=0x7;
		const TCdmaMessageEncoding	KCdmaEncodingLatin						=0x8;
		const TCdmaMessageEncoding	KCdmaEncoding7BitGsm					=0x9;
		const TCdmaMessageEncoding	KCdmaEncodingMax						=0x9;

	/** Defines the Transport Layer Message Type from TIA/EIA-637-B Table 3.4-1
	@publishedAll
	@interim
	*/
	typedef TUint8 	TTpMessageType;
		const TTpMessageType 	KTpSmsPointToPoint				= 0;
		const TTpMessageType 	KTpSmsBroadCast					= 1;
		const TTpMessageType 	KTpSmsAcknowldege				= 2;

	/** Defines the CDMA Message Type from TIA/EIA-637-B Table 4.5.1-1
	@publishedAll
	@interim
	*/
	typedef TUint8 	TCdmaMessageType;
		const TCdmaMessageType 	KTReserved					= 0;
		const TCdmaMessageType 	KTDeliver					= 1;
		const TCdmaMessageType 	KTSubmit					= 2;
		const TCdmaMessageType	KTCancellation				= 3;
		const TCdmaMessageType	KTDeliveryAcknowledgement	= 4;
		const TCdmaMessageType	KTUserAcknowledgement		= 5;
		const TCdmaMessageType	KTReadAcknowledgement		= 6;
		const TCdmaMessageType	KTNumberOfMessageTypes		= 7;

	/** Defines the SMS Cause code from TIA/EIA-41-E Reballot version
	@publishedAll
	@interim
	*/
	typedef TUint8	TCauseCode;
		// network problems
		const TCauseCode 	KAddressVacant					= 0;
		const TCauseCode 	KAddressTranslationFailure 		= 1;
		const TCauseCode 	KNetworkResourceShortage		= 2;
		const TCauseCode 	KNetworkFailure					= 3;
		const TCauseCode 	KInvalidTeleserviceID			= 4;
		const TCauseCode 	KOtherNetworkProblem			= 5; // and 7 to 31
		const TCauseCode 	KUnsupportedNetworkInterface	= 6;
		// terminal problems
		const TCauseCode 	KNoPageResponse					= 32;
		const TCauseCode 	KDestinationBusy				= 33;
		const TCauseCode 	KNoAcknowledgment				= 34;
		const TCauseCode 	KDestinationResourceShortage	= 35;
		const TCauseCode 	KSMSDeliveryPostponed			= 36;
		const TCauseCode 	KDestinationOutOfService		= 37;
		const TCauseCode 	KDestinationNoLongerAtThisAddr	= 38;
		const TCauseCode 	KOtherTerminalProblem			= 39; // up to 47, 48-63 as 36
		// radio interface problems	
		const TCauseCode 	KRadioInterfaceShortage			= 64;
		const TCauseCode 	KRadioInterfaceIncompatibility	= 65;
		const TCauseCode 	KOtherRadioInterfaceProblem		= 66; // and 68 to 95
		const TCauseCode 	KUnsupportedBaseStationCapability= 67;
		// general problems
		const TCauseCode 	KEncodingProblem				= 96;
		const TCauseCode 	KSMSOriginationDenied			= 97;
		const TCauseCode 	KSMSTerminationDenied			= 98;
		const TCauseCode 	KSuppServiceNotSupported		= 99;
		const TCauseCode 	KServiceNotSupported			= 100;
		// 101 Reserved
		const TCauseCode 	KMissingExpectedParameter		= 102;
		const TCauseCode 	KMissingMandatoryParameter		= 103;
		const TCauseCode 	KUnrecognizedParameterValue		= 104;
		const TCauseCode 	KUnexpectedParameterValue		= 105;
		const TCauseCode 	KUserDataSizeError				= 106;
		const TCauseCode 	KOtherGeneralProblems			= 107; // 109 to 223
		const TCauseCode 	KSessionNotActive				= 108;
		// 224-255 TIA/EIA reserved protocol extension as 107

	/** Defines the Language Indicator from TSB58-D Table 9.2-1
	@publishedAll
	@interim
	*/
	typedef TUint8	TLanguageIndicator;
		const TLanguageIndicator	KLanguageUnknown 				= 0;
		const TLanguageIndicator	KLanguageEnglish 				= 1;
		const TLanguageIndicator	KLanguageFrench					= 2;  
		const TLanguageIndicator	KLanguageSpanish				= 3;
		const TLanguageIndicator	KLanguageJapanese				= 4;
		const TLanguageIndicator	KLanguageKorean					= 5;
		const TLanguageIndicator	KLanguageChinese				= 6;
		const TLanguageIndicator	KLanguageHebrew					= 7;
		const TLanguageIndicator	KLanguageMax					= 7;

	/** Defines the different classes of errors, as defined in TIA/EIA-637-B.
	@publishedAll
	@interim
	*/
	typedef TUint8 TTpErrorClass;
		/** For the case where there is no error. */
		const TTpErrorClass KNoError            = 0;
		// Reserved 1
		/** The error is caused by a temporary condition. */
		const TTpErrorClass KTemporaryCondition = 2;
		/** The error is caused by a permanent condition. */
		const TTpErrorClass KPermanentCondition = 3;

	/** Defines the number type from TIA/EIA/IS-2000.5-A Table 2.7.1.3.2.4-2, 
	see TIA/EIA-637-B section 3.4.3.3.
	@publishedAll
	@interim
	*/
	typedef TUint8 TNumberType; 
		// Number Type from TIA/EIA/IS-2000.5-A Table 2.7.1.3.2.4-2
		const TNumberType	KNTIsdnUnknown					= 0;
		const TNumberType	KNTIsdnInternationalNumber		= 1;
		const TNumberType	KNTIsdnNationalNumber			= 2;
		const TNumberType	KNTIsdnNetworkSpecificNumber	= 3;
		const TNumberType	KNTIsdnSubscriberNumber			= 4;
		// Reserved 5
		const TNumberType	KNTIsdnAbbreviatedNumber		= 6;
		// Reserved for extension 7
		
		// Number Type from TIA/EIA-637-B Table 3.4.3.3-1
		const TNumberType	KNTDataNetworkUnknown			= 0;
		const TNumberType	KNTDataNetworkIP				= 1;
		const TNumberType	KNTDataNetworkInternetEmailAddr	= 2;
		
	/**	Defines the numbering plan from TIA/EIA/IS-2000.5-A Table 2.7.1.3.2.4-3, 
	see TIA/EIA-637-B section 3.4.3.3.
	@publishedAll
	@interim
	*/
	typedef TUint8 TNumberPlan; 
		const TNumberPlan	KNPUnknown						= 0;
		const TNumberPlan	KNPIsdnTelephony				= 1;
		const TNumberPlan	KNPData							= 3;
		const TNumberPlan	KNPTelex						= 4;
		const TNumberPlan	KNPPrivate						= 9;
		// Others are reserved

	/** Defines the subaddress type as defined in TIA/EIA-637-B Table 3.4.3.4-1
	@publishedAll
	@interim
	*/
	typedef TUint8 TSubaddressType; 
		const TSubaddressType	KSTNsap						= 0;
		const TSubaddressType	KSTUserSpecified			= 1;

	/** Defines the Bearer Data Subparameter Id from TIA/EIA-637-B Table 4.5-1
	@publishedAll
	@interim
	*/
	typedef TUint8 TSubParameterId;
		const TSubParameterId KTMessageIdentifier				= 0; 
		const TSubParameterId KTUserData						= 1;
		const TSubParameterId KTUserResponseCode				= 2;
		const TSubParameterId KTMessageCenterTimeStamp			= 3;	
		const TSubParameterId KTValidityPeriodAbsolute			= 4;
		const TSubParameterId KTValidityPeriodRelative			= 5;
		const TSubParameterId KTDeferredDeliveryTimeAbsolute	= 6;
		const TSubParameterId KTDeferredDeliveryTimeRelative	= 7;
		const TSubParameterId KTPriorityIndicator				= 8;
		const TSubParameterId KTPrivacyIndicator				= 9;
		const TSubParameterId KTReplyOption						= 10;
		const TSubParameterId KTNumberOfMessages				= 11;
		const TSubParameterId KTAlertOnMessageDelivery			= 12;
		const TSubParameterId KTLanguageIndicator				= 13;
		const TSubParameterId KTCallBackNumber					= 14;
		const TSubParameterId KTMessageDisplayMode				= 15;
		const TSubParameterId KTMultipleEncodingUserData		= 16;
		const TSubParameterId KTMessageDepositIndex				= 17;
		const TSubParameterId KTServiceCategoryProgramData		= 18;
		const TSubParameterId KTServiceCategoryProgramResults	= 19;
		const TSubParameterId KTMessageStatus					= 20;
		const TSubParameterId KTNumberOfSubParameters			= 21;
		
	/** Defines the User Response Code as defined in TIA/EIA-637-B Section 4.5.3
	@publishedAll
	@interim
	*/
	typedef TUint8 	TResponseCode;

	/** Defines the Relative time validity period as defined in TIA/EIA-637-B Section 4.5.6
	@publishedAll
	@interim
	*/
		typedef TUint8 	TRelativeTimePeriod;
		const TRelativeTimePeriod	KBdIndefinite               = 245;
		const TRelativeTimePeriod	KBdImmediate                = 246;
		const TRelativeTimePeriod	KBdValidUntilActiveInactive = 247; 
		const TRelativeTimePeriod	KBdValidUntilAreaChanges   	= 248;
		const TRelativeTimePeriod	KBdelativeTimePeriodMax		= 248;

	/** Defines the Priority Indicator as defined in TIA/EIA-637-B Table 4.5.9-1
	@publishedAll
	@interim
	*/
	typedef TUint8 TPriorityIndicator;
		const TPriorityIndicator	KBdNormal 		= 0;
		const TPriorityIndicator	KBdInteractive 	= 1;
		const TPriorityIndicator	KBdUrgent		= 2;
		const TPriorityIndicator	KBdEmergency	= 3;
		const TPriorityIndicator	KBdMaxPriority	= 3;

	/** Defines the Privacy Indicator as defined in TIA/EIA-637-B Table 4.5.10-1
	@publishedAll
	@interim
	*/
	typedef TUint8 TPrivacy;
		const TPrivacy	KBdNotRestricted	= 0;
		const TPrivacy	KBdRestricted		= 1;
		const TPrivacy	KBdConfidential		= 2;
		const TPrivacy	KBdSecret			= 3;
		const TPrivacy	KBdMaxPrivacy		= 3;

	/** Defines the Alert Priority as defined in TIA/EIA-637-B Table 4.5.10-1
	@publishedAll`
	@interim
	*/
	typedef TUint8 TAlertPriority;
		const TAlertPriority	KBdUseMobileDefault 		= 0;
		const TAlertPriority	KBdUseLowPriorityDefault 	= 1;
		const TAlertPriority	KBdUseMediumPriorityAlert 	= 2;
		const TAlertPriority	KBdUseHighPriorityAlert		= 3;
		const TAlertPriority	KBdMaxAlert					= 3;

	/** Defines the Message Display as defined in TIA/EIA-637-B Table 4.5.16-1
	@publishedAll
	@interim
	*/
	typedef TUint8 TBdMode;
		const TBdMode KBdModeImmediate	= 0;
		const TBdMode KBdModeDefault		= 1;
		const TBdMode KBdModeUser		= 2;
		const TBdMode KBdModeMax			= 2;

	/** Defines the Error Class as defined in TIA/EIA-637-B Section 4.5.21
	@publishedAll
	@interim
	*/
	typedef TUint8 TMessageStatusErrorClass; 
		const TMessageStatusErrorClass KBdNone 					= 0;
		const TMessageStatusErrorClass KBdReservedErrorClass	= 1;		
		const TMessageStatusErrorClass KBdTemporaryCondition	= 2;
		const TMessageStatusErrorClass KBdPermanentCondition	= 3;
		const TMessageStatusErrorClass KBdMaxErrorClass 		= 3; 

	/** Defines the Message status code as defined in TIA/EIA-637-B Table 4.5.21-1
	@publishedAll
	@interim
	*/
	typedef TUint8 TMessageStatusCode;
		// No Error
		const TMessageStatusCode KBdAccepted 				= 0;
		const TMessageStatusCode KBdDeposited 			= 1;
		const TMessageStatusCode KBdDelivered				= 2;
		const TMessageStatusCode KBdCancelled				= 3;
		//  Temporary / Permanent Condition
		const TMessageStatusCode KBdNetworkCongestion	 	= 4;
		const TMessageStatusCode KBdNetworkError			= 5;
		// Permanent Condition Only
		const TMessageStatusCode KBdCancelFailed 			= 6;
		const TMessageStatusCode KBdBlockedDestination	= 7;
		const TMessageStatusCode KBdTextTooLong			= 8;
		const TMessageStatusCode KBdDuplicateMessage		= 9;
		const TMessageStatusCode KBdInvalidDestination	= 10;
		const TMessageStatusCode KBdMessageExpired		= 11;
		const TMessageStatusCode KBdUnknownError			= 31;
		const TMessageStatusCode KBdMaxStatusCode			= 31;

	/** Defines the Message deposit index as defined in TIA/EIA-637-B Section 4.5.18
	@publishedAll
	@interim
	*/
	typedef TUint16 TMessageDepositIndex;

	/** Defines the Service Category Programming Result from TIA/EIA-637-B Table 4.5.20-1
	@publishedAll
	@interim
	*/
	typedef TUint8 TCategoryResult;
		const TCategoryResult	KCRSuccess							= 0;
		const TCategoryResult	KCRMemoryLimitExceeded				= 1;
		const TCategoryResult	KCRServiceCategoryLimitExceeded		= 2;
		const TCategoryResult	KCRCategoryAlreadyProgrammed		= 3;

		const TCategoryResult	KCRCategoryNotPreviouslyProgrammed 	= 4;
		const TCategoryResult	KCRInvalidMaxMessages				= 5;
		const TCategoryResult	KCRInvalidAlertOption				= 6;
		const TCategoryResult	KCRInvalidServiceCategoryName		= 7;
		const TCategoryResult	KCRUnspecifiedProgrammingFailure	= 8;
		const TCategoryResult	KCRMaxResult						= 8;

	/** Defines the Operation Code from TIA/EIA-637-B Section 4.5.19
	@publishedAll
	@interim
	*/
	typedef TUint8 TOperationCode;
		const TOperationCode	KOCDelete			= 0;
		const TOperationCode	KOCAdd				= 1;
		const TOperationCode	KOCClearAll			= 2;
		const TOperationCode	KMaxOperationCode	= 2;

	/** Defines the Service Category Alert Option from TIA/EIA-637-B Table 4.5.19-1
	@publishedAll
	@interim
	*/
	typedef TUint8 TAlertOption;
		const TAlertOption		KNoAlert					= 0;
		const TAlertOption		KMobileStationDefault		= 1;
		const TAlertOption		KVibrateAlertOnce			= 2;
		const TAlertOption		KVinrateAlertRepeat			= 3;
		const TAlertOption		KVisualAlertOnce			= 4;
		const TAlertOption		KVisualAlertRepeat			= 5;
		const TAlertOption		KLowPriorityAlertOnce		= 6;
		const TAlertOption		KLowPriorityAlertRepeat		= 7;
		const TAlertOption		KMedPriorityAlertOnce		= 8;
		const TAlertOption		KMedPriorityAlertRepeat		= 9;
		const TAlertOption		KHighPriorityAlertOnce		= 10;
		const TAlertOption		KHighPriorityAlertRepeat	= 11;
		const TAlertOption		KMaxAlertOpton 				= 11;


	typedef TUint8 TWapApplication;
		const TWapApplication	KWdpApp			= 0;	/** @see WAP-259-WDP-20010614-a sec.6.5.2 */
		const TWapApplication	KWcmpApp		= 1;	/** @see WAP-202-WCMP-20010624-a sec 5.4.4 */		
		const TWapApplication	KUndefinedApp	= 0xFF;
		
	typedef TUint16 TWapPortNumber;
		
	}


#endif //__TIA637_H__
