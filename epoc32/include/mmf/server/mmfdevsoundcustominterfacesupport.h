
// MmfDevSoundCustomInterfaceSupport.h

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

#ifndef MMFDEVSOUNDCUSTOMINTERFACESUPPORT_H
#define MMFDEVSOUNDCUSTOMINTERFACESUPPORT_H

const TUid KMmfUidDevSoundAudioResourceCustomInterface = {0x101FD9F3};
const TUid KMmfUidDevSoundEmptyBuffersCustomInterface = {0x1027379c};
const TUid KMmfUidDevSoundCancelInitializeCustomInterface = {0x102834D3};
const TUid KMmfUidDevSoundAudioClientThreadInfoCustomInterface = {0x102834A7};

/**
@publishedAll
@released

Custom Interface providing support for AutoPauseResume Register, Cancel, GetResourceNotificationData and WillResumePlay.
*/

class MAutoPauseResumeSupport
	{
public:
	/**
	Registers the event for notification when resource is avaliable.

	@param aEventType
		The event which the client is notified of.
		
	@param aNotificationRegistrationData
		Notification registration specific data, which has been reserved for future use.

	@return An error code indicating if the function call was successful. KErrNone on success, otherwise
	        another of the system-wide error codes.
	*/
	virtual TInt RegisterAsClient(TUid aEventType, const TDesC8& aNotificationRegistrationData = KNullDesC8)=0;
	
	/**
	Cancels the registered notification event.

	@param  aEventType
		The event to notify the client.

	@return An error code indicating if the function call was successful. KErrNone on success, otherwise
	        another of the system-wide error codes.
	*/
	virtual TInt CancelRegisterAsClient(TUid aEventType)=0;
	/**
	Gets the notification data for the event.
	
	@param  aEventType
		The event which the client is notified of.
		
	@param aNotificationData
		The notification data for the client to resume playing. The actual data depends on the event type.
		Note that for the event type 'KMMFEventCategoryAudioResourceAvailable' the package buffer returned
		is TMMFTimeIntervalMicroSecondsPckg, but the contents should be converted to an integer and
		interpreted as the data returned is samples played, but not as a microsecond value.

	@return An error code indicating if the function call was successful. KErrNone on success, otherwise
	        another of the system-wide error codes.
	*/
	virtual TInt GetResourceNotificationData(TUid aEventType,TDes8& aNotificationData)=0;
	/**
	Waits for the client to resume the play even after the default timer expires.

	@return An error code indicating if the function call was successful. KErrNone on success, otherwise
	        another of the system-wide error codes.
	*/
	virtual TInt WillResumePlay()=0;
	};

/**
@publishedPartner
@prototype

Custom Interface class providing support for emptying the play buffers.
*/
class MMMFDevSoundEmptyBuffers
	{	
public:
	
	/**
	Empties the play buffers below DevSound without causing the codec to be deleted.

	@return An error code indicating if the function call was successful. KErrNone on success, KErrNotSupported 
			if called in record mode, otherwise another of the system-wide error codes.
	*/
	virtual TInt EmptyBuffers() = 0;
	};	

/**
@publishedPartner
@prototype

Custom Interface class providing support for canceling initialization.
*/
class MMMFDevSoundCancelInitialize
	{	
public:
	
	/** Cancels the initialization process of a CMMFDevSound object

	@return An error code indicating if the function call was successful. 
			KErrNone on success,
			KerrNotReady if this is called before InitializeL() call or after      
			the object has been initialized, 
	*/
	virtual TInt CancelInitialize() = 0;
	};	

/**
@internalComponent

The class is a mixin and is intended to support for closing the Mux and Demux pair in a
DevSound Custom Interface. The function encapsulated by this class is called whenever the 
MMMFDevSoundCustomInterfaceDeMuxPlugin::RefreshL method leaves.
*/
class MMMFDevSoundCustomInterfaceObserver
	{	
public:
	
	/**
	Closes the Mux and Demux pair of a DevSound Custom Interface.
	*/
	virtual void CloseCustomInterface(TInt aIndex) = 0;
	};	

/**
@publishedPartner
@released

Custom Interface class providing support for setting the client thread info for devsound.
*/
class MAudioClientThreadInfo
	{	
public:
	/**
	Set client thread info for devsound if plugin implementation requires this info
	
	@param  aTid the required thread Id
	@return An error code indicating if the function call was successful.

	@capability MultimediaDD
		A process requires MultimediaDD capability to make this call. 
	*/
	virtual TInt SetClientThreadInfo(TThreadId aTid) = 0;
	};	

/*****************************************************************************/
/**
UID associated with the Custom interface MMMFDevSoundGetTimePlayed

@publishedPartner
@released
*/
const TUid KMmfUidDevSoundTimePlayedCustomInterface = {0x10285CE4};

/**
This class provides an interface to querying current play time from DevSound.

@publishedPartner
@released
*/	
class MMMFDevSoundTimePlayed
	{
public:
	/** Retrieves the current play time from the audio renderer.
	@param  aTime
	        A reference to TTimeIntervalMicroSeconds object which will be filled with the current play time by this function.
	@return An error code indicating if the function call was successful. 
			KErrNone on success,
			KErrNotSupported if the underlying HwDevice does not support this custominterface
	*/
	virtual TInt GetTimePlayed(TTimeIntervalMicroSeconds& aTime) = 0;
	};

/*****************************************************************************/
/**
UID associated with the Custom interface MMMFDevSoundQueryIgnoresUnderflow

@publishedPartner
@released
*/
const TUid KMmfUidDevSoundQueryIgnoresUnderflowCustomInterface = {0x10285E7B};

/**
This class provides an interface for querying DevSound whether it ignores the underflow errors from the sound driver.
@publishedPartner
@released
*/	
class MMMFDevSoundQueryIgnoresUnderflow
	{
public:
	/** Queries the devsound whether it ignores the underflow errors from the sound driver
	@return ETrue 	if the devsound ignores all the underflow errors from the sound driver except for the last buffer. That means DevSound
					propagates the underflow error from sound driver to its clients only when client sets the last buffer flag on the CMMFBuffer type buffer.
			EFalse 	if devsound propagates the underflow errors from the sound driver in all the cases
	*/
	virtual TBool QueryIgnoresUnderflow() = 0;
	};


const TUid KMmfUidDevSoundTruePauseCustomInterface = {0x1028643E};

/**
This class provides an interface to be able to Resume from DevSound.
@publishedPartner
@release
*/	
class MMMFDevSoundTruePause
	{
public:
	/** Queries the devsound whether it supports True Pause or not
	This call is only valid when DevSound is initialized
	@return ETrue if the current DevSound configuration does support this feature
			EFalse otherwise
	*/
	virtual TBool IsResumeSupported() = 0;

	/** Resume the playback, recording or tone playing that was paused
	@return An error code indicating if the function call was successful. 
			KErrNone on success,
			KErrNotReady when is DevSound is not in pause
			KErrNotSupported if the DevSound configuration does support this feature
	*/
	virtual TInt Resume() = 0;
	};


#endif // MMFDEVSOUNDCUSTOMINTERFACESUPPORT_H
