/*
* Copyright (c) 2002 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  This file contains the constant definitions of the Central
 *                Repository keys and the Central Repository UID of Profiles
 *                Engine Active Profile Settings API.
 *
*/



#ifndef PROFILEENGINESDKCRKEYS_H
#define PROFILEENGINESDKCRKEYS_H


//  INCLUDES
#include <e32std.h>

// CONSTANTS

/**
 * This is a READ-ONLY API to get information about the settings of the
 * currently active profile.
 *
 * How to use:
 *
 * @code
 * #include <centralrepository.h>
 * #include <ProfileEngineSDKCRKeys.h>
 *
 * CRepository* cr = CRepository::NewLC( KCRUidProfileEngine );
 * TInt value;
 *
 * // Get the ID of the currently active profile:
 * User::LeaveIfError( cr->Get( KProEngActiveProfile, value ) );
 * // use value
 *
 * // Get the ringing type of the active profile:
 * User::LeaveIfError( cr->Get( KProEngActiveRingingType, value ) );
 * // use value
 *
 * // Get the keypad tones volume level of the active profile:
 * User::LeaveIfError( cr->Get( KProEngActiveKeypadVolume, value ) );
 * // use value
 *
 * // Get the ringing volume of the active profile:
 * User::LeaveIfError( cr->Get( KProEngActiveRingingVolume, value ) );
 * // use value
 *
 * // Get the game and warning tone setting of the active profile:
 * User::LeaveIfError( cr->Get( KProEngActiveWarningTones, value ) );
 * // use value
 *
 * // Get the message alert setting of the active profile:
 * User::LeaveIfError( cr->Get( KProEngActiveMessageAlert, value ) );
 * // use value
 *
 * CleanupStack::PopAndDestroy( cr );
 * @endcode
 * 
 * The UID of the Central Repository file containing the settings. Should be
 * given as a parameter in CRepository::NewL() call.
 */
const TUid KCRUidProfileEngine = {0x101F8798};

/**
* The id of the currently active profile, integer value.
* Possible values:
*
* 0 = General profile (default value)<br>
* 1 = Silent profile<br>
* 2 = Meeting profile<br>
* 3 = Outdoor profile<br>
* 4 = Pager profile<br>
* 5 = Off-line profile<br>
* 6 = Drive profile<br>
* 30-49 = User-created profiles<br>
**/
const TUint32 KProEngActiveProfile = 0x7E000001;

/**
* Ringing type of the active profile, integer value.
*
* Possible values:
*
* 0 = Ringing (default value)<br>
* 1 = Ascending<br>
* 2 = Ring once<br>
* 3 = Beep once<br>
* 4 = Silent<br>
**/
const TUint32 KProEngActiveRingingType = 0x7E000002;

/**
* Keypad volume of the active profile, integer value.
*
* Possible values:
*
* 0 (keypad tones off)<br>
* 1<br>
* 2 (default)<br>
* 3<br>
**/
const TUint32 KProEngActiveKeypadVolume = 0x7E000004;

/**
* Ringing volume of the active profile, integer value.
*
* Possible value range: 1-10
*
* Default value : 7
**/
const TUint32 KProEngActiveRingingVolume = 0x7E000008;

/**
* Warning & Game Tones of the active profile, integer value.
*
* Possible values:
*
* 0 = off<br>
* 1 = on (default value)<br>
**/
const TUint32 KProEngActiveWarningTones = 0x7E000020;

/**
* Message Alert Tone of the active profile, integer value.
*
* Possible values:
*
* 0 = Off (= the profile is silent)<br>
* 1 = On (default value)<br>
**/
const TUint32 KProEngActiveMessageAlert = 0x7E000040;


#endif      // PROFILEENGINESDKCRKEYS_H

// End of File
