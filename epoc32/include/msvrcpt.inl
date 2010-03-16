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


inline CMsvRecipient::TRecipientStatus CMsvRecipient::Status() const
/** Gets the message sending status for the recipient.

@return Message sending status for the recipient */
	{
	return iStatus;
	}

inline void CMsvRecipient::SetStatus(TRecipientStatus aStatus)
/** Sets the message sending status for the recipient.

@param aStatus Message sending status for the recipient */
	{
	iStatus=aStatus;
	}

inline TInt CMsvRecipient::Error() const
/** Gets any error code for message sending to the recipient.

@return System wide error code */
	{
	return iError;
	}

inline void CMsvRecipient::SetError(TInt aError)
/** Sets any error code for message sending to the recipient.

@param aError System wide error code */
	{
	iError=aError;
	}

inline const TTime& CMsvRecipient::Time() const
/** Gets the (const) time for message sending to the recipient.

@return Time for message sending to the recipient */
	{
	return iTime;
	}

inline TTime& CMsvRecipient::Time()
/** Gets the (writable) time for message sending to the recipient.

@return Time for message sending to the recipient */
	{
	return iTime;
	}

inline TInt CMsvRecipient::Retries() const
/** Gets the number of retries for message sending to the recipient.

@return Number of retries */
	{
	return iRetries;
	}

inline void CMsvRecipient::IncreaseRetries()
/** Increments the number of retries for message sending to the recipient. */
	{
	iRetries++;
	}

inline void CMsvRecipient::ResetRetries()
/** Resets the number of retries for message sending to the recipient to zero. */
	{
	iRetries=0;
	}
