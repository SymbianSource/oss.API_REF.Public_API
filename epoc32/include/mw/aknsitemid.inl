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
