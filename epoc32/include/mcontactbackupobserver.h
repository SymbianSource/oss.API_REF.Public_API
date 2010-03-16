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

#ifndef __MCONTACTBACKUPOBSERVER_H__
#define __MCONTACTBACKUPOBSERVER_H__


class MContactBackupObserver
/**	
	An observer class to which Contacts model clients should 
	subscribe in order to be informed about the progress of 
	a backup or restore operation.

	@publishedAll
	@released
*/
	{
public:
/**	
	Provides notification that a backup operation is to begin.
	The Contacts model client should not access the contacts database for 
	writing until BackupRestoreCompletedL() is called.
*/
	virtual void BackupBeginningL()	= 0;

/**	
	Provides notification that a restore operation is to begin.
	The Contacts model client should not access the contacts database at all 
	until BackupRestoreCompletedL() is called.
*/
	virtual void RestoreBeginningL() = 0;

/**	
	Provides notification that a backup/restore operation is complete.
	The contacts database can be accessed again.
*/
	virtual void BackupRestoreCompletedL() = 0;

	};


#endif // __MCONTACTBACKUPOBSERVER_H__
