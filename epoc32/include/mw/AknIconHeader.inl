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
* Description:  AknIconHeader Functionality.
 *  Author	 : Shakti Prakash Chittara
 *
*/

#ifndef AKNICONHEADER_INL
#define AKNICONHEADER_INL
#include <e32std.h> 

inline TAknIconHeader::TAknIconHeader(TDes8 &aData)
    {
    __ASSERT_ALWAYS(aData.Length() >= KIconHeaderLength, User::Panic(_L("not sufficient size"), KErrBadDescriptor));
       iHeader = (THeader *)(aData.LeftTPtr(KIconHeaderLength).Ptr());
    }

inline void TAknIconHeader::Initialize()
    {
       Mem::FillZ(iHeader,KIconHeaderLength);
       iHeader->headerSize = KIconHeaderLength; 
    }

inline TAknIconHeader::~TAknIconHeader()
    {
    }

inline void TAknIconHeader::SetRotation(TInt aAngle)
    {
    iHeader->rotation = aAngle;
    }

inline TInt TAknIconHeader::GetRotation() const
    {
    return iHeader->rotation;
    }

inline void TAknIconHeader::SetScaleMode(TInt aMode)
    {
    iHeader->aspectRatio = aMode;
    }

inline TInt TAknIconHeader::GetScaleMode() const
    {
    return iHeader->aspectRatio;
    }

inline void TAknIconHeader::SetIconColor(TUint32 aColor)
    {
    iHeader->iconColor = aColor;
    }

inline TUint32 TAknIconHeader::GetIconColor() const
    {
    return iHeader->iconColor;
    }

inline void TAknIconHeader::SetMarginCorrection(TBool isMarginFlag)
    {
    iHeader->isMarginCorrection= isMarginFlag;
    }

inline TBool TAknIconHeader::IsMarginCorrection() const
    {
    return iHeader->isMarginCorrection;
    }

inline void TAknIconHeader::SetBitmapId(TInt aBitmapId)
    {
    iHeader->bitmapid = aBitmapId;
    }

inline TInt TAknIconHeader::GetBitmapId() const
    {
    return iHeader->bitmapid;
    }

inline void TAknIconHeader::SetIsMask(TBool isMask)
    {
    iHeader->isMask = isMask;
    }

inline TBool TAknIconHeader::IsMask() const
    {
    return iHeader->isMask;
    }
#endif
// End of File
