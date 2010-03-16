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
//


// note: MergeToMark is not atomic - a leave means that data has been removed
template <TBool StackOwnsEntry>
inline void CRuleMarkedStack<StackOwnsEntry>::MergeToMarkL(TInt aMarkType)
	{
	const TInt lastMark=this->RemoveMark(aMarkType);
	if (this->Count()>lastMark)
		{
		CBNFNode* currentRule=this->Pop();
		if (StackOwnsEntry)
			CleanupStack::PushL(currentRule);
			
		while (this->Count()>lastMark)
			{
			CBNFNode* nextRule=this->Pop();
			if (StackOwnsEntry)
				CleanupStack::PushL(nextRule);
			currentRule->ReparentL(nextRule);
			if (StackOwnsEntry)
				{
				CleanupStack::Pop(2); // nextRule, currentRule
				CleanupStack::PushL(nextRule); // nextRule
				}
			
			currentRule=nextRule;
			}

		if (StackOwnsEntry)
			CleanupStack::Pop(); // currentRule
		this->PushL(currentRule);
		}
	}
