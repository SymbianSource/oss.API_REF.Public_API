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

/**
 @file
 @publishedAll
 @released
*/

#ifndef __CALINTERIMAPIPANIC_H__
#define __CALINTERIMAPIPANIC_H__

 /**
Panics raised from CallinterimAPI
 */
enum TCalInterimApiPanicCode
	{

	/**
	Trying to create a CCalCategory object and a wrong type is passed.
	*/
	EInvalidCategoryParameter		= 0,

	/**
	Attempt to pass wrong type of TChangeEntryType.
	*/
	EInvalidChangeEntryType			= 1,

	/**
	Trying to fetch an undefined TStatus/TCalStatus of an Entry.
	*/
	EInvalidEntryStatus				= 2,

	/**
	The TType of an Entry dosen't match the standard types
	*/
	EInvalidEntryType				= 3,

	/**
	Atttempt to create an object using NULL object of type CCalEntry.
	*/
	EInstanceCreatedFromNullEntry	= 4,

	/**
	Passed invalid Recurrence Range.
	*/
	EInvalidRecurrenceRangeParameter= 5,

	/**
	Attempt to pass a NULL object of type CCalInstance.
	*/
	ENullInstanceParameter			= 6,

	/**
	Wrong CCalEntry TType passed to API
	*/
	EInvalidEntryTypeParameter		= 7,

	/**
	Attempt to create an invalid repeat rule.
	*/
	ERepeatRuleBitFailure			= 8,

	/**
	Attempt to pass incorrect TCalRRule TType.
	*/
	EInvalidRepeatRuleType			= 9,
		
	/**
    Trying to set a repeat rule while one has already been set.
	*/
	ERepeatRuleTypeAlreadySet		= 10,

	/**
	Raised by the Class CCalSession's destructor if all the opened references
	have not been closed before destruction of CCalSession object.
	*/
	ESessionHasOpenReferences		= 11,

	/**
	The type of CCalAttachment is unknown.
	*/
	EInvalidAttachmentType			= 12,
	
	/**
	The instance iterator index is corrupt.
	*/
	EInstanceIteratorIndexCorrupt	= 13
	
	};

#endif 
