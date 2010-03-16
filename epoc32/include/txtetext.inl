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
//


 
TBool CEditableText::HasChanged()const
/** Tests whether the editable text object has been changed by an operation on 
it, as set by SetHasChanged().

@return ETrue if a change has occurred to the text object. EFalse if there 
has been no change. */
	{return iHasChanged;}


TBool CPlainText::FieldSetPresent()const
	{return (iFieldSet.IsPtr() && iFieldSet.AsPtr()!=NULL);}


 

const MTextFieldFactory* CPlainText::FieldFactory()const
/** Gets a pointer to the field factory used by the text object. The field factory 
may be set up using SetFieldFactory(), or may be specified in the NewL().

@return The field factory. NULL if no field factory has been set up. */
	{return (FieldSetPresent()) ? iFieldSet->FieldFactory() : NULL;}


void CPlainText::ConsumeAdornmentL(RReadStream& aStream)
	{
	TStreamId id;
	aStream>> id;
	}


TUid CPlainText::UidFromStreamL(RReadStream& aStream)
	{
	TUid uid;
	aStream>> uid;
	return uid;
	}
