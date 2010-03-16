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
// Clears the following flags:
// KPhoneNumberMobile
// KPhoneNumberUsePulseDial
// KPhoneNumberPbxUsePulseDial
// KPhoneNumberWaitForDialingTone
// KPhoneNumberWaitForProceedTone
// KReturnPhoneNumberWithPlusFormat
// 
//



/**
 @publishedAll
 @deprecated 9.1
*/
inline void TDialLocation::ClearDialLocationFlags (TUint aFlags)
    {
    iFlags &= ~aFlags;
    }

/**
True if the KReturnPhoneNumberWithPlusFormat flag is set

@publishedAll
@deprecated 9.1
*/
inline TBool TDialLocation::IsReturnPhoneNumberWithPlusFormat() const
    {
    return(iFlags & KReturnPhoneNumberWithPlusFormat);
    }
