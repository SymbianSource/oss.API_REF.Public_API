/*
* Copyright (c) 2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:   Central repository keys and repository identifiers for the S60
*                Messaging UI components
*
*/



#ifndef MESSAGINGSDKCRKEYS_H
#define MESSAGINGSDKCRKEYS_H

//  INCLUDES
#include <e32std.h>

/**
 * This is a READ-ONLY API to get information about the Messaging UI
 * settings.
 *
 * How to use:
 *
 * @code
 * #include <centralrepository.h>
 * #include <MessagingSDKCRKeys.h>
 *
 * CRepository* cr = CRepository::NewLC( KCRUidMessagingUiSettings );
 * TInt value;
 *
 * // Get the current zoom level of messaging editors:
 * User::LeaveIfError( cr->Get( KMessagingEditorLocalUiZoom, value ) );
 * // use value
 *
 * CleanupStack::PopAndDestroy( cr );
 * @endcode
 */

/**
 * The UID of the Central Repository file containing the settings. Should be
 * given as a parameter in CRepository::NewL() call.
 */
const TUid KCRUidMessagingUiSettings = {0x102072E2};

/**
 * Zoom level of the message editors (and viewers), integer value.
 *
 * Possible values (corresponding enumeration from "akndef.hrh" in parentheses):
 *
 * -1 = Automatic (EAknUiZoomAutomatic)<br>
 * 0 = Normal (EAknUiZoomNormal)<br>
 * 1 = Small (EAknUiZoomSmall)<br>
 * 2 = Large (EAknUiZoomLarge)<br>
 */
const TUint32 KMessagingEditorLocalUiZoom = 0x00000001;


#endif // MESSAGINGSDKCRKEYS_H