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
// Camera specific errors
// 
//



/**
 @publishedAll
 @released
 @file
*/

#ifndef  ECAMERRORS_H
#define  ECAMERRORS_H

/** The camera has been disabled, hence calls do not succeed  */
static const TInt KErrECamCameraDisabled			= -12100;

/** This parameter or operation is supported, but presently is disabled. */ 
static const TInt KErrECamSettingDisabled			= -12101;

/** This value is out of range. */
static const TInt KErrECamParameterNotInRange 		= -12102;

/**
@deprecated Use sysytem wide error code KErrNotSupported, since there is no clear cut difference between the two 
*/ 
static const TInt KErrECamSettingNotSupported		= -12103;

/** The optimum focus is lost */
static const TInt KErrECamNotOptimalFocus 		= -12104;

/** The flash is not charged */
static const TInt KErrECamFlashNotCharged		= -12105;

/**
This error code is supposed to be used with new event KUidECamEventCIPSetColorSwapEntry 
and KUidECamEventCIPRemoveColorSwapEntry.
This would occur when the particular color is being targetted by 2 color entries for 
conversion to different colors.

*/
static const TInt KErrECamColorOperationConflict	= -12106;

/**
This error code is supposed to be used with new event KUidECamEvent2CameraRequestForcedTimedTakeOver 
and KUidECamEvent2CameraRequestTimedTakeOver.
This would mean that another such reserve request is outstanding and has higher priority than this client.

@internalTechnology
*/
static const TInt KErrECamHighPriorityReserveRequesterExists = -12107;

/**
This error code is supposed to be used whenever any fatal error occurs from which the client cannot recover.

@publishedPartner
@prototype
*/
static const TInt KErrECamFatalError = -12108;

/**
If error is KErrECamImageResourceNotReleased and client wants to successfully call the Prepare method again, 
client needs to delete all CCameraImageCapture objects and any Snapshot and Histogram objects associated with
it as well. 

@publishedPartner
@prototype
*/
static const TInt KErrECamImageResourceNotReleased = -12109;

/**
If error is KErrECamVideoResourceNotReleased and client wants to successfully call the Prepare method again,
client needs to call ReleaseVideoResource to unprepare video and then delete any Snapshot and Histogram 
objects associated with it as well.

@publishedPartner
@prototype
*/
static const TInt KErrECamVideoResourceNotReleased = -12110;

#endif // ECAMERRORS_H
