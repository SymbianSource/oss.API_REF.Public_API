/*
* Copyright (c) 2002 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
* which accompanies this distribution, and is available
* at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  
*
*/



#ifndef DRMHELPERSERVERINTERNALCRKEYS_H
#define DRMHELPERSERVERINTERNALCRKEYS_H

//#include <DRMHelperServerSDKCRKeys.h>

const TUid KCRUidDRMHelperServer = {0x10205CA7};

/* Key format for both KDRMHelperServerNotification and KDRMHelperServerNotificationPassive

To inform the expiration event of automated usage to active clients. 
The first Tuint8 is the times the content has been informed, the second
 Tuint8 could either be 'E' or 'V', 'E' means expired and 'V' means 
 valid but about to expire. The third is permission type (which is 
 defined in caf.h, including EPlay, EExcute, EView, EPrint, EPeek). 
 The rest of data is the content ID. So, the whole format of the 
 values would be "<TUint8 aTimes><TUint8 aExpirationMark><TUint8
  aPermissionType><TDesC8 aContentID>".
  
*/ 

const TUint32 KDRMHelperServerNotification = 0x00000001;
const TUint32 KDRMHelperServerNotificationPassive = 0x00000002;

#endif      // DRMHELPERSERVERINTERNALCRKEYS_H

