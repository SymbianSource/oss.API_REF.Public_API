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
//

#ifndef __SMUTHDR_H__
#define __SMUTHDR_H__

#include <e32base.h>
#include <gsmubuf.h>
#include <bif.h>
#include <gsmupdu.h>
#include <msvstd.h>
#include <smutset.h>

class RMsvReadStream;
class RMsvWriteStream;
class CMsvStore;
class CSmsEmailFields;

/** 
The SMS MTM encapsulation of an SMS message.

This class allows a messaging client to access the lower-level message encapsulation 
used by the SMS stack.

It also provides functionality to restore and store an SMS message from/to the
message store.

An SMS message is encapsulated in a Protocol Data Unit (PDU). In GSM there are 
six types of SMS message PDU. In the descriptions below, SC means Service Center 
and MS means Mobile Station (the phone).

1. SMS-DELIVER - sent from SC to MS

2. SMS-DELIVER-REPORT - sent from MS to SC

3. SMS-SUBMIT - sent from MS to SC

4. SMS-SUBMIT-REPORT - sent from SC to MS

5. SMS-STATUS-REPORT - sent from SC to MS

6. SMS-COMMAND - sent from MS to SC

@publishedAll
@released
*/
class CSmsHeader : public CBase
	{
public:

	IMPORT_C static CSmsHeader* NewL(CSmsPDU::TSmsPDUType aType,CEditableText& aText);
	IMPORT_C static CSmsHeader* NewL(CSmsPDU::TSmsPDUType aType,CEditableText& aText,RFs& aFs);
	IMPORT_C static CSmsHeader* NewL(CSmsMessage* aMessage);
	IMPORT_C ~CSmsHeader();

	inline CSmsPDU::TSmsPDUType Type() const;

	inline CSmsSubmit& Submit();
	inline const CSmsSubmit& Submit() const;
	inline CSmsDeliver& Deliver();
	inline const CSmsDeliver& Deliver() const;
	inline CSmsCommand& Command();
	inline const CSmsCommand& Command() const;
	inline CSmsStatusReport& StatusReport();
	inline const CSmsStatusReport& StatusReport() const;
	
	inline CSmsMessage& Message();
	inline const CSmsMessage& Message() const;

	inline TBool ReplyPathProvided() const;
	inline void SetReplyPathProvided(TBool aReplyPathProvided);

	inline TBioMsgIdType BioMsgIdType() const;
	inline void SetBioMsgIdType(TBioMsgIdType aBioMsgIdType = EBioMsgIdNbs);
	
	inline TPtrC ServiceCenterAddress() const;
	inline void SetServiceCenterAddressL(const TDesC& aAddress);

	IMPORT_C void SetSmsSettingsL(const CSmsMessageSettings& aSmsSettings);
	IMPORT_C void GetSmsSettingsL(CSmsMessageSettings& aSmsSettings) const;

	inline const CArrayPtrFlat<CSmsNumber>& Recipients() const;
	inline CArrayPtrFlat<CSmsNumber>& Recipients();

	inline void SetFromAddressL(const TDesC& aAddress);
	inline TPtrC FromAddress() const;
	
	TPtrC ReplyAddressL() const;
	
	IMPORT_C void SetEmailFieldsL(const CSmsEmailFields& aEmailFields);
	void SetReplyEmailFieldsL(const CSmsEmailFields& aEmailFields, const TDesC& aReplySubjectFormat);
	void SetForwardEmailFieldsL(const CSmsEmailFields& aEmailFields, const TDesC& aForwardSubjectFormat);
	IMPORT_C const CSmsEmailFields& EmailFields() const;

	IMPORT_C void InternalizeL( RMsvReadStream& aStream);
	IMPORT_C void ExternalizeL( RMsvWriteStream& aStream) const;

	IMPORT_C void RestoreL(CMsvStore& aStore);
	IMPORT_C void StoreL(CMsvStore& aStore) const;

	IMPORT_C  TBool ContainsSmsHeaderL(const CMsvStore& aStore); 
	
private:
	CSmsHeader(CSmsMessage* aSmsMessage = NULL);
	void ConstructL(CSmsPDU::TSmsPDUType aType, CEditableText& aText);
	void ConstructL(CSmsPDU::TSmsPDUType aType, CEditableText& aText, RFs& aFs);
	void ConstructL();

	enum TSmsHeaderFlags
		{
		ESmsHeaderNoFlags			= 0x00,
		ESmsHeaderReplyPathProvided = 0x01,
		ESmsHeaderCanConcatenate	= 0x02
		};

	TBool CanConcatenate() const;
	void SetCanConcatenate(TBool aCanConcatenate);
	
	void SetEmailReplyForwardSubjectL(CSmsEmailFields* aEmailFields, const TDesC& aSubject, const TDesC& aSubjectFormat);
	
private:
	CArrayPtrFlat<CSmsNumber> iRecipients;
	CSmsMessage* iMessage;
	TUint32 iFlags;
	RFs iFs;

	// iBioMsgIdType is only used during sending and will be ignored if the 
	// TMsvEntry.iBioType == 0. The default is EBioMsgIdNbs.
	TBioMsgIdType iBioMsgIdType;
	CSmsEmailFields*	iEmailFields;
	TBool			iCloseFs;
	};
	
/**
A specialisation of the message server index class for SMS message entries.

It provides accessers for SMS message specific data, for instance the class type
of the SMS message.

@publishedPartner
@released
*/
class TMsvSmsEntry : public TMsvEntry
	{
public:

/**
Defines a set flags used to access message entry data specific to an SMS message.

@internalTechnology
@released

*/
	enum TMsvSmsEntryFlags
		{
/**
Clears the entire set of SMS flags.
*/
		EMsvSmsEntryClearFlag				= 0x00000000,
/**
Mask for the protocol identifier data.
*/
		EMsvSmsEntryProtocolIdentifier		= 0x000000FF,
/**
Mask for the User Prompt Indicator flag.
*/
		EMsvSmsEntryUserPromptIndicator 	= 0x00000100,
/**
Mask for the SMS class data.
*/
		EMsvSmsEntryClass					= 0x00000E00,
/**
Mask for the flag indicating whether the class data has been defined.
*/
		EMsvSmsEntryClassDefined			= 0x00001000,
/**
Mask for the flag indicating whether the message ID is valid. 
*/
		EMsvSmsMessageValid					= 0x00002000,
/**
Mask for the delivery acknowledgement information.
*/
		EMsvSmsEntryDeliveryAckSummary		= 0x0001C000,
/**
Parameter defining the number of bits to be shifted in order for the SMS class
data to be at the LSB of the data block.
*/
		EMsvSmsEntryClassShift				= 9,
/**
Parameter defining the number of bits to be shifted in order for the delivery
acknowlwdgement information to be at the LSB of the data block.
*/
		EMsvSmsEntryDeliveryAckSummaryShift	= 14
		};

/**
Defines the summary acknowledgement information.

This information indicates whether the SMS message is not supplying a summary 
for an acknowledgement, is still expecting acknowledgments or it has received 
all expected acknowledgements.

If all acknowledgements have been received the summary indicates whether all 
the recipients have successfully acknowledged the message, all failed or there
was a mixture of successful and failed acknowledgements from the recipients. 
*/
	enum TMsvSmsEntryAckSummary
		{
/**
No summary information is being formed.
*/
		ENoAckSummary			= 0,
/**
The message is waiting for acknowledgements to be received for all recipients
of this message. Some recipients may have received their acknowledgements but
there are still some recipients that have not.
*/
		EPendingAcks,
/**
The summary indicates that the message was successfully acknowledged by all recipients.
*/
		EAllSuccessful,
/**
The summary indicates that the message failed to be acknowledged by all recipients.
*/
		EAllFailed,
/**
The summary indicates a mixture of successful and failed acknowledgements from 
the recipients of the message. All recipients of this message have received 
their acknowledgements.
*/
		EMixed
		};

public:
	inline TMsvSmsEntry();
	inline TMsvSmsEntry(const TMsvEntry& aEntry);

	inline void SetUserPromptIndicator(TBool aUPI);
	inline TBool UserPromptIndicator() const;

	inline TUint8 ProtocolIdentifier() const;
	inline void SetProtocolIdentifier(TSmsProtocolIdentifier aPID);
	inline void SetProtocolIdentifier(TUint8 aPID);

	inline TBool Class(TSmsDataCodingScheme::TSmsClass& aClass) const;
	inline void SetClass(TBool aClassDefined,TSmsDataCodingScheme::TSmsClass aClass = TSmsDataCodingScheme::ESmsClass0);

	IMPORT_C TMsvSmsEntryAckSummary AckSummary(TSmsAckType aAckType) const;
	IMPORT_C void SetAckSummary(TSmsAckType aAckType, TMsvSmsEntryAckSummary aAckSummary);

	IMPORT_C TBool MessageId(TInt32& aMessageId) const;
	IMPORT_C void SetMessageId(TInt32 aMessageId, TBool aIsValid);
	};

#include <smuthdr.inl>

#endif	// __SMUTHDR_H__
