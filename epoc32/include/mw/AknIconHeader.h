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
* Description:  Describes functionalities for Extended Bitmap Icon Header.
*  Author : Shakti Prakash Chittara
*
*/



#ifndef AKNICONHEADER_
#define AKNICONHEADER_

// INCLUDES
#include <e32std.h>

struct THeader         // be aware of padding!
{
  TUint16	sign;             
  TUint8	version;
  TUint8	headerSize;
  TUint32	reserved1;
  TUint16	reserved2;
  TUint8	reserved3;
  TUint8  reserved4:4;                /// flags 
  TUint8  isMarginCorrection:1;           /// flags
	TUint8  isMask:1;  // flags
  TUint8  aspectRatio:2;             /// flags
  TInt32	rotation;
  TInt32	iconColor;
  TInt32	bitmapid;
} ;



// CONSTANTS
static const TInt KIconHeaderLength = sizeof(THeader);
class TAknIconHeader
    {
    
public:
    inline  TAknIconHeader(TDes8 &aData);

    inline ~TAknIconHeader();
    
    inline void Initialize();
    
    inline void SetRotation(TInt aAngle);
  
    inline TInt GetRotation() const;
  
   inline void SetScaleMode(TInt aMode);
  
    inline TInt GetScaleMode() const;
  
     inline void SetIconColor(TUint32 aColor);
  
    inline TUint32 GetIconColor() const;
  
    inline void SetMarginCorrection(TBool isMarginFlag);
  
    inline TBool IsMarginCorrection() const;
  
     inline void SetBitmapId(TInt aBitmapId);
  
    inline TInt GetBitmapId() const;

  inline void SetIsMask(TBool isMask);
  
  inline TBool IsMask() const;
  
private:  

   THeader *iHeader;
    };

#include "AknIconHeader.inl"
#endif /*AKNICONHEADER_*/
