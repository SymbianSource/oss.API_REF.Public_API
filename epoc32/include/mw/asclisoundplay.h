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

#ifndef __ASCLISOUNDPLAY_H__
#define __ASCLISOUNDPLAY_H__

// System includes
#include <e32base.h>

// User includes
#include <asshddefs.h>

// Type definitions

// Constants

// Enumerations


///////////////////////////////////////////////////////////////////////////////////////
// ----> TASCliSoundPlayDefinition (header)
///////////////////////////////////////////////////////////////////////////////////////
class TASCliSoundPlayDefinition
/** Defines when alarm sounds are to be played, and for how long. 

Alarm sounds are played according to intervals that consist of a duration 
and an offset. 

The duration is the number of seconds that the alarm sound plays. 

The offset is the number of minutes after the alarm expires that the alarm 
sound plays. 

The sound play definition is set using class RASCliSession. 
@publishedAll
@released
*/
	{
///////////////////////////////////////////////////////////////////////////////////////
public:										// CONSTRUCT
///////////////////////////////////////////////////////////////////////////////////////

	inline TASCliSoundPlayDefinition();

	inline TASCliSoundPlayDefinition(TTimeIntervalMinutes aOffset, TTimeIntervalSeconds aDuration);

////////////////////////////////////////////////////////////////////////////////////////
public:										// ACCESS
///////////////////////////////////////////////////////////////////////////////////////

	inline TTimeIntervalMinutes	Offset() const 
	/** Retrieves the offset.
	
	@return The offset in minutes. */
		{ return iOffset; }

	inline TTimeIntervalSeconds	Duration() const 
	/** Retrieves the duration.
	
	@return The duration in seconds. */
		{ return iDuration; }

//////////////////////////////////////////////////////////////////////////////////////
private:									// MEMBER DATA
///////////////////////////////////////////////////////////////////////////////////////

	/*
	 * From the time an alarm is first displayed
	 */
	TTimeIntervalMinutes					iOffset;

	/*
	 * How long the alarm playing lasts
	 */
	TTimeIntervalSeconds					iDuration;
	};




///////////////////////////////////////////////////////////////////////////////////////
// ----> TASCliSoundPlayDefinition (inlines)
///////////////////////////////////////////////////////////////////////////////////////
inline TASCliSoundPlayDefinition::TASCliSoundPlayDefinition()
:	iOffset(KDefaultSoundPlayOffsetInSeconds), iDuration(KDefaultSoundPlayDurationInSeconds)
/** Default constructor. 

The default offset is zero, and the default duration is 30 seconds. */
	{}
inline TASCliSoundPlayDefinition::TASCliSoundPlayDefinition(TTimeIntervalMinutes aOffset, TTimeIntervalSeconds aDuration)
:	iOffset(aOffset), iDuration(aDuration)
/** Constructor that initializes the offset and duration to specified values.
	
@param aOffset Time in minutes for the offset. 
@param aDuration Time in seconds for the duration. */
	{}

#endif
