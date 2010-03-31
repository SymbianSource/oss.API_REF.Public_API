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

#if !defined(__APAFLREC_H__)
#define __APAFLREC_H__

#if !defined(__APADEF_H__)
#include <apadef.h>
#endif
#if !defined(__APAID_H__)
#include <apaid.h>
#endif

// classes defined:
class MApaAppStarter;
class CApaAppLocator;
class CApaFileRecognizer;
class CApaFileRecognizerType;
class CFileRecognizerExtension;
//
// classes referenced:
class TApaAppEntry;
class CApaCommandLine;
class RFs;
//

// KUidFileRecognizer is UID[1] for app recognizer dll's (UID[2] identifies a particular identifier)
/**
@publishedAll
@released
*/
#ifdef _UNICODE
#define KUidFileRecognizer KUidFileRecognizer16
#else
#define KUidFileRecognizer KUidFileRecognizer8
#endif

/**
@publishedAll 
@deprecated
*/
const TInt KFileRecognizerUidValue8=0x1000013E;

/**
@publishedAll 
@deprecated
*/
const TUid KUidFileRecognizer8={KFileRecognizerUidValue8};

/**
@publishedAll
@released
*/
const TUid KUidFileRecognizer16={0x10003A37};
//


class CApaAppLocator : public CBase
/**
@internalComponent
*/
	{
public:
	virtual TInt GetAppEntryByUid(TApaAppEntry& aAppEntry,TUid aAppUid)=0;
	virtual TInt GetAppCapabilityByUid(TDes8& aCapabilityBuf,TUid aAppUid)=0;
	};



class CApaFileRecognizer : public CBase
/**
@internalComponent
@deprecated
*/
	{
public:
	//
	IMPORT_C CApaFileRecognizerType* RecognizeFileL(const TDesC& aFullFileName,const TUidType* aUidType=NULL);
	IMPORT_C CApaAppLocator* AppLocator() const;
	//
	IMPORT_C ~CApaFileRecognizer();
protected:
	IMPORT_C CApaFileRecognizer(RFs& aFs);
	IMPORT_C void AddFileRecognizerType(CApaFileRecognizerType* aFileRecognizerType);
	IMPORT_C TInt RemoveFileRecognizerType(const CApaFileRecognizerType* aFileRecognizerType);
	IMPORT_C void SetAppLocator(CApaAppLocator* aAppLocator); // should be called by child-classes eg during construction
	static inline void SetAppStarter(CApaFileRecognizerType* aRecognizer,MApaAppStarter* aAppStarter);
	IMPORT_C void DestroyRecognizerList();
protected:
	RFs& iFs;
	CApaAppLocator* iAppLocator;
private:
	CApaFileRecognizerType *iFileRecognizerList;
	};



class MApaAppStarter
/** An interface used by the Application Architecture server to start applications.

CEikonEnv is derived from this class.

@publishedPartner
@released
@see CEikonEnv */
	{
public:
	virtual TThreadId StartAppL(const CApaCommandLine& aCommandLine)=0;
protected:
	IMPORT_C MApaAppStarter(); 
private:
	IMPORT_C virtual void MApaAppStarter_Reserved1();
	IMPORT_C virtual void MApaAppStarter_Reserved2();
private:
	TInt iMApaAppStarter_Reserved1;
	};



class CApaFileRecognizerType : public CBase
/**
@publishedPartner
@deprecated
*/
	{
public:
	enum TRecognizedType {EProgram,EDoc,EOtherFile,ENotRecognized};
public:
	virtual TThreadId RunL(TApaCommand aCommand,const TDesC* aDocFileName,const TDesC8* aTailEnd) const=0;
	inline TThreadId RunL(TApaCommand aCommand, const TDesC* aDocFileName) const;
	inline TThreadId RunL(TApaCommand aCommand) const;
	inline TUid AppUid()const;
	inline TUid TypeUid()const;
	inline TRecognizedType Type()const;
	IMPORT_C void Capability(TDes8& aCapabilityBuf)const;
	IMPORT_C void Lock();
	IMPORT_C void Unlock();
protected:
	IMPORT_C CApaFileRecognizerType();
	IMPORT_C ~CApaFileRecognizerType();
	IMPORT_C TThreadId AppRunL(const CApaCommandLine& aCommandLine) const;
private:
	inline void SetAppStarter(MApaAppStarter* aAppStarter); // must be called before AppRunL()
	virtual TRecognizedType DoRecognizeFileL(RFs& aFs,TUidType aUidType)=0;
	TRecognizedType RecognizeFileL(RFs& aFs,const TDesC& aFullFileName,TUidType aUidType);
	TBool Locked()const;
	IMPORT_C virtual void Reserved_1();
public:
	IMPORT_C static CApaFileRecognizerType* CreateFileRecognizerL(TUid aImplUid);
protected:
	CApaFileRecognizer* iFileRecognizer;
	MApaAppStarter* iAppStarter;
	HBufC* iFullFileName;
	TUid iFileType; // type UID of the recognizer file (ie UID[1])
	TUid iAppUid; // UID of the associated app (ie UID[2])
	TRecognizedType iRecognizedType;
	TApaAppCapabilityBuf* iCapabilityBuf;
private:
	CApaFileRecognizerType* iNext;
	TInt iLock;
	CFileRecognizerExtension* iFileRecognizerExtn;
private:
	friend class CApaFileRecognizer;
	};


//
// inlines
//

inline void CApaFileRecognizer::SetAppStarter(CApaFileRecognizerType* aRecognizer,MApaAppStarter* aAppStarter)
	{ aRecognizer->SetAppStarter(aAppStarter); }

inline void CApaFileRecognizerType::SetAppStarter(MApaAppStarter* aAppStarter)
	{ iAppStarter = aAppStarter; }

inline TUid CApaFileRecognizerType::AppUid() const
	{ return iAppUid; }

inline TUid CApaFileRecognizerType::TypeUid() const
	{ return iFileType; }

inline CApaFileRecognizerType::TRecognizedType CApaFileRecognizerType::Type()const
	{ return iRecognizedType; }

inline TThreadId CApaFileRecognizerType::RunL(TApaCommand aCommand, const TDesC* aDocFileName) const
	/** Calls RunL(TApaCommand,const TDesC*,const TDesC8*) with NULL as third parameter.
	@see CApaFileRecognizerType::RunL(TApaCommand,const TDesC*,const TDesC8*) */
	{ return RunL(aCommand, aDocFileName, NULL); }

inline TThreadId CApaFileRecognizerType::RunL(TApaCommand aCommand) const
	/** Calls RunL(TApaCommand,const TDesC*,const TDesC8*) with NULL as second and third parameter.
	@see CApaFileRecognizerType::RunL(TApaCommand,const TDesC*,const TDesC8*) */
	{ return RunL(aCommand, NULL, NULL); }	

#endif
