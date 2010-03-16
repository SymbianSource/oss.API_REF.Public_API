// Copyright (c) 1997-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// All the error codes returned by
// the ECOM framework to a client 
// are defined here.
// 
//



#ifndef __ECOMERRORCODES_H__
#define __ECOMERRORCODES_H__

/** 
The base value for Shared Error codes for the ECOM framework and client 
@publishedAll
@released
*/
const TInt KEComErrBase								= -17000;

/** 
The last value for ECom Frmework errors
This must be modified when error codes are added/deleted
@publishedAll
@released
*/
const TInt KEComErrLast								= -17030;

////////////////////////////////////////////////////////////
// Error codes which may be received by a client application
////////////////////////////////////////////////////////////
/** 
The call to instantiate an Interface Implementation failed 
because no registrations exist for this interface. 
@publishedAll
@released
*/
const TInt KEComErrNoInterfaceIdentified			= -17004;

/** 
The Non-Default resolver could not be instantiated.  The most likely
situation is that an incorrect implementation uid was supplied. 
@publishedAll
@released
*/
const TInt KEComErrNoResolver						= -17014;

/** 
The client has requested too many notifications.  ECom can only support
a finite number of notifications 
@publishedAll
@released
*/
const TInt KEComErrTooManyNotificationsOutstanding	= -17026;

/** 
An ECom service was requested with an essential parameter missing.  For example,
this error code will be supplied when calling an overload of CreateImplementationL 
which uses a non-default resolver if you fail to supply the resolver 
@publishedAll
@released
*/
const TInt KEComErrMissingParameter					= -17028;

/** The registry index is invalid but the client has requested notifications - so
they will receive a notification when the index is ready again 
@publishedAll
@released
*/
const TInt KEComErrListInvalidAwaitNotification		= -17029;

/** 
The registry index is invalid and the client has not requested notifications.
They will have to try again later after discoveries have completed. 
@publishedAll
@released
*/
const TInt KEComErrListCurrentlyUnavailable			= -17030;


////////////////////////////////////////////////////////////
// Error codes for internal use only
////////////////////////////////////////////////////////////
/** 
The Client requested a service which is not supplied by this framework 
@publishedAll
@released
*/
const TInt KEComErrInvalidUnloadPolicy				= -17003;

/** 
An attempt has been made to load an implementation contained within a dll
which no longer exists (deleted or is on a CF card that has been removed). 
@publishedAll
@released
*/
const TInt KEComErrInvalidIIC						= -17008;

/** 
An attempt has been made to update registry information for a dll on a
drive that does not exist. 
@publishedAll
@released
*/
const TInt KEComErrDriveNotFound					= -17019;


////////////////////////////////////////////////////////////
// Codes which are only used for Panics
////////////////////////////////////////////////////////////
/** 
The Client requested a service which is not supplied by this framework 
@publishedAll
@released
*/
const TInt KEComErrUnknownService					= -17002;

/** 
The Interface Implementation reference count is invalid 
@publishedAll
@released
*/
const TInt KEComErrReferenceCountInvalid			= -17013;

/** 
The Interface Implementations destruction could not be recorded 
@publishedAll
@released
*/
const TInt KEComErrDestructionFailed				= -17017;

/** 
An attempt has been made to update the registry information for a
non-existent DLL.  An ECom internal error. 
@publishedAll
@released
*/
const TInt KEComErrInvalidRegistryData				= -17022;

/**
The uid from a resource plugin does not match the uid from its
corrsponding DLL. 
@publishedAll
@released
*/
const TInt KEComErrMismatchedTags					= -17023;

/**
The scanning timer for re-discovering plugins is not found in the list
of scanning timers. 
@publishedAll
@released
*/
const TInt KEComErrNotFoundScanTimer					= -17024;
/** 
The client called DestroyedImplementation with a destruction
key of NULL.  This is an irrecoverable error because the object
cannot be deleted. 
@publishedAll
@released
*/
const TInt KEComErrDestroyingWithNullDtorKey		= -17027;


////////////////////////////////////////////////////////////
// Codes which are currently unused but reserved for future expansion
////////////////////////////////////////////////////////////
/**
@publishedAll
@released
*/
const TInt KEComErrAlreadyReceiving					= -17001;

/** 
The call to Enable the registered Interface Implementation failed 
@publishedAll
@released
*/
const TInt KEComErrEnableFailed						= -17005;

/** 
The call to Disable the registered Interface Implementation failed 
@publishedAll
@released
*/
const TInt KEComErrDisableFailed					= -17006;

/** 
The call to instantiate an Interface Implementation failed 
because no appropriate implementation was found. 
@publishedAll
@released
*/
const TInt KEComErrNoRegistrationsFound				= -17007;

/** 
The call to Remove the registered Interface Implementation failed 
@publishedAll
@released
*/
const TInt KEComErrUninstallFailed					= -17009;

/** 
The call to Re-register an Interface Implementation failed 
@publishedAll
@released
*/
const TInt KEComErrReinstallFailed					= -17010;

/** 
The call to Register an Interface Implementation failed 
@publishedAll
@released
*/
const TInt KEComErrRegistrationFailed				= -17011;

/** 
The client does not have a session open with the framework 
@publishedAll
@released
*/
const TInt KEComErrNotConnected						= -17012;

/** 
The call to Suspend registration activities failed 
@publishedAll
@released
*/
const TInt KEComErrSuspendFailed					= -17015;

/** 
The call to Resume registration activities failed 
@publishedAll
@released
*/
const TInt KEComErrResumeFailed						= -17016;

/** 
An attempt has been made to add a drive to the registry which
already exists 
@publishedAll
@released
*/
const TInt KEComErrDriveAlreadyInstalled			= -17018;

/**
@publishedAll
@released
*/
const TInt KEComErrIndexEntryNotFound				= -17020;

/** 
An IIC has been found which does not have a corresponding 
registration information file 
@publishedAll
@released
*/
const TInt KEComErrNoRegistrationData				= -17021;

/**
@publishedAll
@released
*/
const TInt KEComErrInstantiationPointerNotFound		= -17024;

/**
@publishedAll
@released
*/
const TInt KEComErrInstantiationPointerNotAvailable = -17025;

#endif	// __ECOMERRORCODES_H__
