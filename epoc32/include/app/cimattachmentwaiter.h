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
//

#ifndef __CIMATTACHMENTWAITER_H__
#define __CIMATTACHMENTWAITER_H__

#include <e32base.h>

class CImEmailMessage;

/**
An Waiter object used to wait for an attachment to be added to an email message.

@publishedAll
@released
*/
class CImAttachmentWaiter : public CActive
	{
public:
	IMPORT_C static CImAttachmentWaiter* NewL();
	IMPORT_C ~CImAttachmentWaiter();
	IMPORT_C void StartWaitingL(TRequestStatus& aStatus, CImEmailMessage* aMailMessage, TBool aDeleteMessage = ETrue);
	
private:
	CImAttachmentWaiter();
	void Reset();
	
	// from CActive
	void RunL();
	void DoCancel();
	
private:
	TRequestStatus* iReportStatus;
	CImEmailMessage* iMailMessage;
	TBool iDeleteMessage;
	};

#endif // __CIMATTACHMENTWAITER_H__
