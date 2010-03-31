// Copyright (c) 1998-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#if !defined(__MSVRCPT_H__)
#define __MSVRCPT_H__

class RWriteStream;

//**********************************
// CMsvRecipient
//**********************************
//
// Base class for  multiple recipients
//

class CMsvRecipient : public CBase
/** Base class for information relating to a message recipient. 
@publishedAll
@released
*/
	{
public:
	/** Message sending status for a recipient. 
@publishedAll
@released
*/
	enum TRecipientStatus 
							{	
	/** Message is not sent. */
							ENotYetSent=0,
	/** Message has been sent. */
							ESentSuccessfully=1,
	/** Message sending failed. */
				 			EFailedToSend=2};
	IMPORT_C virtual void InternalizeL(RReadStream& aStream);
	IMPORT_C virtual void ExternalizeL(RWriteStream& aStream) const;
	inline TRecipientStatus Status() const;
	inline void SetStatus(TRecipientStatus aStatus);
	inline TInt Error() const;
	inline void SetError(TInt aError);
	inline const TTime& Time() const;
	inline TTime& Time();
	inline TInt Retries() const;
	inline void IncreaseRetries();
	inline void ResetRetries();
protected:
	IMPORT_C CMsvRecipient();
private:
	TRecipientStatus iStatus;
	TInt   iError;
	TInt   iRetries;
	TTime	 iTime;
	};

#include <msvrcpt.inl>

#endif
