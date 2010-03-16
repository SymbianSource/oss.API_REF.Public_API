// Copyright (c) 2000-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// A template class to provide a classic stack like interface & functionality
// The entries on the stack are owned (i.e. deleted) by the stack if the 
// StackOwnsEntry argument is ETrue
// 
//

#ifndef __CSTACK_H__
#define __CSTACK_H__

#include <e32base.h>

#pragma warning (disable : 4127) // conditional expression is constant


/**	
	@file
	@publishedAll
	@released
*/


template <class T, TBool StackOwnsEntry>
class CStack : /*protected CArrayPtrSeg<T>*/ public CArrayPtrSeg<T>
	{
public:
	inline CStack();
	inline ~CStack();

	inline void Clear();		
	inline TBool IsEmpty() const;
	inline void PushL(T* aItem);
	inline T* Pop();
	inline T* Head() const;
	inline T* Last() const;		
	};

#include <cstack.inl>

#pragma warning ( default : 4127 ) // conditional expression is constant

#endif // __CSTACK_H__
