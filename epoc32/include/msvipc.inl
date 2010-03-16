// Copyright (c) 1998-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// TMsvPackedChangeNotification
// 
//

inline void TMsvPackedChangeNotification::Pack(TMsvServerChangeNotificationType aChangeType, const CMsvEntrySelection& aSelection, TInt aParameter1, TInt aParameter2)
//
// Packs all of the selection into the buffer
//
	{
	Pack(aChangeType, aSelection, aParameter1, aParameter2, 0, aSelection.Count()-1);
	}
