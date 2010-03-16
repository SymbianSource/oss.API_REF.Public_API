/*
* Copyright (c) 2003 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:               Inline methods for user dictionary class.
*
*/















// ---------------------------------------------------------------------------
// CPtiUserDictionary::SetFileName
// 
// ---------------------------------------------------------------------------
//
inline void CPtiUserDictionary::SetFileName(TDesC& aFileName)
	{
	iFileName.Copy(aFileName);
	}

// ---------------------------------------------------------------------------
// CPtiUserDictionary::Id
// 
// ---------------------------------------------------------------------------
//
inline TInt CPtiUserDictionary::Id() const
	{
	return iId;
	}

// ---------------------------------------------------------------------------
// CPtiUserDictionary::SetId
// 
// ---------------------------------------------------------------------------
//
inline void CPtiUserDictionary::SetId(TInt aId)
	{
	iId = aId;
	}

// ---------------------------------------------------------------------------
// CPtiUserDictionary::Size
// 
// ---------------------------------------------------------------------------
//
inline TInt CPtiUserDictionary::Size() const
	{
	return iData->Length();
	}

// ---------------------------------------------------------------------------
// CPtiUserDictionary::CoreUID
// 
// ---------------------------------------------------------------------------
//
inline TInt32 CPtiUserDictionary::CoreUID() const
	{
	return iCoreUID;
	}
	
// ---------------------------------------------------------------------------
// CPtiUserDictionary::SetCoreUID
// 
// ---------------------------------------------------------------------------
//
inline void CPtiUserDictionary::SetCoreUID(TInt32 aUid)
	{
	iCoreUID = aUid;
	}

// ---------------------------------------------------------------------------
// CPtiUserDictionary::Data
// 
// ---------------------------------------------------------------------------
//
inline TPtr8 CPtiUserDictionary::Data()
	{
	return TPtr8(iData->Des());
	}

// ---------------------------------------------------------------------------
// CPtiUserDictionary::IsDefault
// 
// ---------------------------------------------------------------------------
//
inline TBool CPtiUserDictionary::IsDefault() const
	{
	return iDefault;
	}

// ---------------------------------------------------------------------------
// CPtiUserDictionary::SetDefault
// 
// ---------------------------------------------------------------------------
//
inline void CPtiUserDictionary::SetDefault(TBool aValue)
	{
	iDefault = aValue;
	}

// ---------------------------------------------------------------------------
// CPtiUserDictionary::FileName
// 
// ---------------------------------------------------------------------------
//
inline TPtrC CPtiUserDictionary::FileName() const
	{
	return TPtrC(iFileName);
	}

// ---------------------------------------------------------------------------
// CPtiUserDictionary::UpdateFlag
// 
// ---------------------------------------------------------------------------
//
inline TBool CPtiUserDictionary::UpdateFlag() const
	{
	return iUpdateFlag;
	}

// ---------------------------------------------------------------------------
// CPtiUserDictionary::SetUpdateFlag
// 
// ---------------------------------------------------------------------------
//
inline void CPtiUserDictionary::SetUpdateFlag(TBool aFlag)	
	{
	iUpdateFlag = aFlag;
	}

// ---------------------------------------------------------------------------
// CPtiUserDictionary::SymbolClass
// 
// ---------------------------------------------------------------------------
//
inline TInt CPtiUserDictionary::SymbolClass() const
	{
	return iSymbolClass;		
	}

// ---------------------------------------------------------------------------
// CPtiUserDictionary::SetSymbolClass
// 
// ---------------------------------------------------------------------------
//
inline void CPtiUserDictionary::SetSymbolClass(TInt aSymbolClass)
	{
	iSymbolClass = aSymbolClass;
	}

// End of file
