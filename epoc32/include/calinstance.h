// Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __CALINSTANCE_H__
#define __CALINSTANCE_H__

#include <caltime.h>

class CCalEntry;
class CCalInstanceImpl;

/** Class representing an instance of a calendar entry.

A calendar entry (CCalEntry) can have any number of instances. 
A non-repeating entry will only have one instance.
Any further instances will appear if the entry has recurrence data.

The time of an instance is the start time of that instance of the entry.

@publishedAll
@released
*/
NONSHARABLE_CLASS(CCalInstance) : public CBase
	{
public:
	static CCalInstance* NewL(CCalEntry* aEntry, const TCalTime& iTime);
	IMPORT_C ~CCalInstance();
	
	IMPORT_C CCalEntry& Entry() const;
	IMPORT_C TCalTime Time() const;
	IMPORT_C TCalTime StartTimeL() const;
	IMPORT_C TCalTime EndTimeL() const;

private:
	CCalInstance();
	void ConstructL(CCalEntry* aEntry, const TCalTime& aTime);
	
private:
	CCalInstanceImpl* iImpl;
	};

#endif // __CALINSTANCE_H__
