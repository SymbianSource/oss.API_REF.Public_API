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

#if !defined(__APFREC_H__)
#define __APFREC_H__

#if !defined(__APADEF_H__)
#include <apadef.h>
#endif
#if !defined(__APAFLREC_H__)
#include <apaflrec.h>
#endif

#include <babackup.h>

// classes defined:
class CApaScanningFileRecognizer;

//
// classes referenced:
class CApaAppFinder;
class TApaAppEntry;
class TEntry;
class RFs;
class TDriveUnit;
//

// dir in which app recognizers should live - this dir is scanned on all drives

/**
@internalTechnology
*/
_LIT(KAppRecognizerSearchPath,"\\System\\Recogs\\");

/**
@internalComponent
*/
_LIT(KAppRecognizerSearchString,"?:\\System\\Recogs\\");

/**
@internalComponent
*/
_LIT(KAppRecognizerSearchAnyFile,"*");

/**
@internalComponent
*/
const TUid KUidFileRecogInterfaceUid={0x101F7D86};

class CApaRecognizerDll; // private class

/** Constructs a recognizer type 

@publishedPartner
@released
*/
typedef CApaFileRecognizerType* (*CreateCApaFileRecognizerType)();

class CApaScanningFileRecognizer : public CApaFileRecognizer
/**
@internalComponent
@deprecated
*/
	{
public:
	class TRecognizer
		{
	friend class CApaRecognizerDll;
	friend class CT_File1Step;
	public:
		TRecognizer(HBufC* aName);
		inline const TDesC& Name() const;
	public:
		//lint --e{1925} suppress "public data member" 
		TUid iUid;
		TInt iDrive;
	private:
		inline TRecognizer();
		TRecognizer(const TRecognizer&);
		TRecognizer& operator=(const TRecognizer&);
	private:
		HBufC* iName;
		};
	typedef CArrayFixFlat<TRecognizer> CRecognizerArray;
	//
private:
	class CApaBackupOperationObserver : public CBase, public MBackupOperationObserver
		{
	public:
		CApaBackupOperationObserver(CApaScanningFileRecognizer& aRecognizer);
		~CApaBackupOperationObserver();
		void RegisterObserverL();

		virtual void HandleBackupOperationEventL(const TBackupOperationAttributes& aBackupOperationAttributes);
		TInt UpdateCounter() const;
		void SetUpdateCounter( TInt aValue );
	private:
		CBaBackupSessionWrapper* iSession;
		CApaScanningFileRecognizer& iRecognizer;
		TInt iUpdateCounter;
		};
	friend class CApaScanningFileRecognizer::CApaBackupOperationObserver;
public:
	IMPORT_C static CApaScanningFileRecognizer* NewL(RFs& aFs,MApaAppStarter* aAppStarter);
	IMPORT_C ~CApaScanningFileRecognizer();
	IMPORT_C void ScanForRecognizersL();
	IMPORT_C TInt RecognizerCount();
	IMPORT_C CRecognizerArray* RecognizerListLC()const;
	IMPORT_C const TRecognizer& operator[](TInt aIndex)const; 
	IMPORT_C TInt UpdateCounter()const;

protected:
	IMPORT_C CApaScanningFileRecognizer(RFs& aFs,MApaAppStarter* aAppStarter);
	IMPORT_C void ConstructL();
	//
private:
	void ScanDriveL(TInt aDriveNum);
	void LoadRecognizerL(const TDesC& aFullName,TUid aUid);
	TInt RemoveRecognizer(CApaRecognizerDll& aDll);
	void LoadEcomRecognizerL(TDriveUnit& aDrive,TUid aUid);
	void ScanForEcomRecognizersL();
public:
	IMPORT_C void SetEcomRecognizersFromListL(const CRecognizerArray& aList);
	IMPORT_C void SetEcomRecognizerL(const TRecognizer& aRecognizer); 
private:
	CApaRecognizerDll* iRecognizerLib;
	MApaAppStarter* iAppStarter;
	CApaBackupOperationObserver* iObserver;
	};

inline const TDesC& CApaScanningFileRecognizer::TRecognizer::Name() const
	{
	return *iName;	
	}

inline CApaScanningFileRecognizer::TRecognizer::TRecognizer()
	{
	}

#endif
