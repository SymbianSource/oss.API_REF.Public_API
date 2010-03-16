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

#ifndef __BIFBASE_H__
#define __BIFBASE_H__

#include <e32base.h>
#include <s32std.h>				// for TSwizzle
#include <apmrec.h>				// for TRecognitionConfidence

/** Base classes for BIO-message Information File (BIF) Reader

@internalTechnology
@released
*/
class CBioInfoFile : public CBase
	{
public:
	~CBioInfoFile();

protected:
	CBioInfoFile(RFs& aFs);
	void ConstructL();

protected:
	class CIdHeader : public CBase
		{
	public:
		CIdHeader();
		~CIdHeader();

		void InternalizeL(RReadStream& aStream);			
		void ExternalizeL(RWriteStream& aStream) const;		

	public:
		TBioMsgIdType iType;
		CApaDataRecognizerType::TRecognitionConfidence iConfidence;
		TSwizzle<HBufC> iText;
		TUint16 iPort;
		TUid iCharacterSet;
		TInt16 iGeneralIdData;
		};

	class TIconZoomLevel
		{
	public:
		void InternalizeL(RReadStream& aStream);			
		void ExternalizeL(RWriteStream& aStream) const;		

	public:
		TInt16 iZoomLevel;
		};

protected:
	RFs& iFs;

	//
	// Simple data to be read/write to/from BIF file
	TUid iMessageTypeUid;

	HBufC* iMessageParserName;
	
	TUid iMessageAppUid;
	HBufC* iMessageAppCtrlName;	
	HBufC* iDescription;
	TInt16 iGeneralData1;
	TInt16 iGeneralData2;
	TInt16 iGeneralData3;
	HBufC* iFileExtension;
	HBufC* iIconsFilename;
		
	//
	// Complex data to be read/write to/from BIF file
	CArrayPtrFlat<CIdHeader>* iIdHeaderArray;
	CArrayFix<TIconZoomLevel>* iIconZoomLevelArray;
	};

#endif	// __BIFBASE_H__
