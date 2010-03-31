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
* Description:  ?Description
*
*/


// INLINED MEMBERS
inline void TAknsItemID::Set( const TInt aMajor, const TInt aMinor )
    {
    iMajor = aMajor; iMinor = aMinor; 
    }

inline void TAknsItemID::Set( const TUid aMajor, const TInt aMinor )
    {
    iMajor = aMajor.iUid; iMinor = aMinor; 
    } //lint !e1746 TUid is a single word struct

inline void TAknsItemID::Set( const TAknsItemID& aID )
    {
    iMajor = aID.iMajor; iMinor = aID.iMinor;
    }

inline TBool operator==( const TAknsItemID& aFirst, const TAknsItemID& aSecond )
    { 
    return (aFirst.iMajor==aSecond.iMajor)&&(aFirst.iMinor==aSecond.iMinor); 
    }

inline TBool operator!=( const TAknsItemID& aFirst, const TAknsItemID& aSecond )
    { 
    return (aFirst.iMajor!=aSecond.iMajor)||(aFirst.iMinor!=aSecond.iMinor); 
    }

//  End of File  
