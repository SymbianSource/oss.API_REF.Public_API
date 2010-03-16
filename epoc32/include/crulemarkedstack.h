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
// A speciales marked stack specifically for PARSE rules.
// Allows a rule stack to merge rules upto a given mark type.
// 
//

#ifndef __CRULEMARKEDSTACK_H__
#define __CRULEMARKEDSTACK_H__


// includes
#include <e32base.h>
#include <cmarkedstack.h>
#include <cbnfnode.h>

#pragma warning (disable : 4127) // conditional expression is constant


template <TBool StackOwnsEntry>
class CRuleMarkedStack : public CMarkedStack<CBNFNode, StackOwnsEntry>
/**	
@publishedAll
@released
*/
	{
public:
	void MergeToMarkL(TInt aMarkType);
	};

#include <crulemarkedstack.inl>

#pragma warning ( default : 4127 ) // conditional expression is constant

#endif // __CRULEMARKEDSTACK_H__
