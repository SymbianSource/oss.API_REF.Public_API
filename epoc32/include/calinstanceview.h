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

#ifndef __CALINSTANCEVIEW_H__
#define __CALINSTANCEVIEW_H__

#include <calentry.h>
#include <calentryview.h>
#include <calinstanceiterator.h>

class CCalFindInstanceSettings;
class CCalInstance;
class CCalInstanceIterator;
class CCalInstanceViewImpl;
class CCalSession;
class MCalProgressCallBack;
class TCalTime;
class CCalLiteEntry;
class TAgnInstanceId;
struct TASShdAlarmedInstanceParams;

/** View class for accessing instances of calendar entries.

Once a session to a calendar file has been created, a view to the session
can be created.

An instance is a calendar entry, a repeated instance of a calendar entry, 
or an RDate added to an entry.

This view can be used to search for instances and also to delete instances.

@publishedAll
@released
*/
NONSHARABLE_CLASS(CCalInstanceView) : public CBase
    {	
public:

	/** Parameter struct for storing search data.
	This contains a descriptor to store search text and an enum to describe the text search behaviour.

	@publishedAll
	@released
	*/
	class TCalSearchParams
		{
	public:
		IMPORT_C TCalSearchParams(const TDesC& aText, CalCommon::TCalSearchBehaviour aBehaviour);
		IMPORT_C const TDesC& Text() const;
		IMPORT_C CalCommon::TCalSearchBehaviour Behaviour() const;
	
	private:
		TPtrC iSearchText;
		CalCommon::TCalSearchBehaviour iSearchBehaviour;
		};
		
	IMPORT_C static CCalInstanceView* NewL(CCalSession& aSession, MCalProgressCallBack& aProgressCallBack);
	IMPORT_C static CCalInstanceView* NewL(CCalSession& aSession);
	IMPORT_C ~CCalInstanceView();
	
	IMPORT_C void FindInstanceL(RPointerArray<CCalInstance>& aInstanceList, 
					   			CalCommon::TCalViewFilter aCalViewFilter, 
					   			const CalCommon::TCalTimeRange& aTimeRange) const;
	
	IMPORT_C void FindInstanceL(RPointerArray<CCalInstance>& aMatchedInstanceList,
								CalCommon::TCalViewFilter aCalViewFilter, 
								const CalCommon::TCalTimeRange& aTimeRange, 
								const TCalSearchParams& aSearchParams) const;
					   
	IMPORT_C CCalInstanceIterator* FindInstanceL(const CCalFindInstanceSettings& aSettings) const;

    IMPORT_C void FindAlarmedInstanceL(RPointerArray<CCalInstance>& aAlarmedInstanceList,    
    								   TASShdAlarmedInstanceParams aAlarmedInstanceParams) const;	
	
	IMPORT_C void DeleteL(CCalInstance* aInstance, CalCommon::TRecurrenceRange aWhichInstances);
								
	IMPORT_C TCalTime NextInstanceL(CalCommon::TCalViewFilter aCalViewFilter, const TCalTime& aStartDate) const;
	IMPORT_C TCalTime PreviousInstanceL(CalCommon::TCalViewFilter aCalViewFilter, const TCalTime& aStartDate) const;
	
private:
	CCalInstanceView();
	void ConstructL(CCalSession& aSession, MCalProgressCallBack* aProgressCallBack);
	
private: 
	CCalInstanceViewImpl* iImpl;
	};

/** Class for specifying the search criteria for use in @see CCalInstanceView::FindInstanceL.

@publishedPartner
@released
*/
NONSHARABLE_CLASS(CCalFindInstanceSettings) : public CBase
	{
public:
	IMPORT_C static CCalFindInstanceSettings* NewL(CalCommon::TCalViewFilter aFilter, const CalCommon::TCalTimeRange& aTimeRange);
	IMPORT_C ~CCalFindInstanceSettings();

	IMPORT_C void SetFilter(CalCommon::TCalViewFilter aFilter);
	IMPORT_C void SetTimeRange(const CalCommon::TCalTimeRange& aTimeRange);
	IMPORT_C void SetTextSearchL(const CCalInstanceView::TCalSearchParams& aSearchParams);
	
	CalCommon::TCalSearchBehaviour Behaviour() const;
	CalCommon::TCalViewFilter Filter() const;
	const CalCommon::TCalTimeRange TimeRange() const;
	const TDesC& Text() const;
private:
	CCalFindInstanceSettings(CalCommon::TCalViewFilter aFilter, const CalCommon::TCalTimeRange& aTimeRange);

private:
	CalCommon::TCalTimeRange		iTimeRange;
	CalCommon::TCalViewFilter		iFilter;
	HBufC*							iSearchText;
	CalCommon::TCalSearchBehaviour	iSearchBehaviour;
	};
	
#endif // __CALINSTANCEVIEW_H__
