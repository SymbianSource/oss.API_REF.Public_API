// Copyright (c) 2001-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __MMFBASE_H__
#define __MMFBASE_H__

// Standard EPOC32 includes
#include <e32base.h>


/** 
@publishedAll
@released

The priority for clients accessing a sound output device for audio playback or audio streaming.

This is a value between EMdaPriorityMin and EMdaPriorityMax. The higher value indicates a more 
important request. It is used to resolve conflicts when more than one client tries to access the
same hardware resource simultaneously.

One of these values is passed in the first parameter to CMdaAudioOutputStream::SetPriority().

@see CMdaAudioOutputStream::SetPriority()
*/
enum TMdaPriority
	{
  	/**
	The lowest priority (= – 100). This indicates that the client can be interrupted 
	by any other client.
	*/
    EMdaPriorityMin = -100,
	/**
	Normal priority. This indicates that the client can be interrupted but only by higher priority clients.
	*/
    EMdaPriorityNormal = 0,
	/**
    The highest priority (= 100). This indicates that the client cannot be interrupted by other clients.
	*/
    EMdaPriorityMax = 100
	};

/**
@publishedAll
@released

A set of priority values which define the behaviour to be adopted by an
audio client if a higher priority client takes over the device.
*/
enum TMdaPriorityPreference
	{
	/**
	No priority.
	*/
    EMdaPriorityPreferenceNone =	0x00000000,
	/**
	The audio data is time sensitive. The playback operation fails if it cannot happen when 
	requested but degraded output such as mixing or muting is allowed.
	*/
    EMdaPriorityPreferenceTime =	0x00000001,
	/**
    The audio data must be played at the best possible quality (for example, it must not be degraded by 
	muting or mixing). The playback operation is delayed until the sound device is available for exclusive use.
	*/
    EMdaPriorityPreferenceQuality = 0x00000002,
	/**
    The audio data is both time and quality sensitive. The playback operation fails if it cannot 
	happen immediately at the highest quality.
	*/
    EMdaPriorityPreferenceTimeAndQuality = EMdaPriorityPreferenceTime|EMdaPriorityPreferenceQuality
	};

/**
@publishedAll
@released

Holds the current state of DevSound.
*/
enum TMMFState
{
	/** Idle state.
	*/
	EMMFStateIdle,
	/** The MMF is currently playing.
	*/
	EMMFStatePlaying,
	/** The MMF is playing a tone.
	*/
	EMMFStateTonePlaying,
	/** The MMF is currently recording.
	*/
	EMMFStateRecording,
	/** The MMF is playing and recording.
	*/
	EMMFStatePlayingRecording,
	/** The MMF is converting data.
	*/
	EMMFStateConverting
};

/**
@publishedAll
@released

A class type representing the audio client's priority,
priority preference and state settings.
*/
class TMMFPrioritySettings
	{
public:
	TMMFPrioritySettings();
	/**
	Absolute priority of a client of the MMF Server.

	Used by the policy server to determine which client should gain access to the sound device.

	The priority which should be an integer in the range -100 to +100.
	*/
	TInt iPriority;

	/**
    The priority preference that expresses the nature of the priority that can be none, 
	time (or speed), quality or both time and quality.

	If this is set to EMdaPriorityPreferenceTime then the audio data is time sensitive. The playback 
	operation fails if it cannot happen when requested but degraded output such as mixing or muting 
	is allowed.

	If this is set to EMdaPriorityPreferenceQuality then the audio data must be played at the best possible 
	quality (for example, it must not be degraded by muting or mixing). The playback operation is delayed
	until the sound device is available for exclusive use.

	If this is set to EMdaPriorityPreferenceTimeAndQuality then the audio data is both time and quality 
	sensitive. The playback operation fails if it cannot happen immediately at the highest quality.
	*/
	TMdaPriorityPreference iPref;

	/**
    The state of the MMF player such as idle, playing, recording and so on. See the TMMFState enum for possible states.
	*/
	TMMFState iState;
private:
	/**
	This member is internal and not intended for use.
	*/
	TInt iReserved1;
	};

/**
@publishedAll
@released

This is a TPckgBuf package of a TMMFPrioritySettings.
*/
typedef TPckgBuf<TMMFPrioritySettings> TMMFPrioritySettingsPckg;

/**
Initializes the object with arbitrary values.
*/
inline TMMFPrioritySettings::TMMFPrioritySettings() : iPriority(EMdaPriorityNormal), iPref(EMdaPriorityPreferenceNone), iState(EMMFStateIdle), iReserved1(0)
	{
	}

#endif
