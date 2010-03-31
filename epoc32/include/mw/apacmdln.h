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

#if !defined(__APACMDLN_H__)
#define __APACMDLN_H__

#if !defined(__E32BASE_H__)
#include <e32base.h>
#endif

#if !defined(__APADEF_H__)
#include <apadef.h>
#endif

#if !defined(__F32FILE_H__)
#include <f32file.h>
#endif

#if !defined(__S32STRM_H__)
#include <s32strm.h>
#endif


class CApaCommandLine : public CBase
/** Information for launching an application.

This is often referred to as a command line and contains:

the name of an application EXE to be launched,

a document name,

a command code that defines the way the application is launched

trailing data; the structure of this depends on the application to be launched.

The information is held in a buffer implemented by a heap descriptor. 

@publishedAll
@released */
	{
public:
	// construction/destruction
	IMPORT_C static CApaCommandLine* NewL();
	IMPORT_C static CApaCommandLine* NewLC();
	IMPORT_C ~CApaCommandLine();

	// Getting/setting the CApaCommandLine to/from process environment-slots
	IMPORT_C void SetProcessEnvironmentL(RProcess& aProcess) const;
	IMPORT_C static TInt GetCommandLineFromProcessEnvironment(CApaCommandLine*& aCommandLine);

	// Getting/setting the CApaCommandLine to/from a server IPC-message
	IMPORT_C void GetIpcArgsLC(TIpcArgs& aIpcArgs) const;
	IMPORT_C void ConstructCmdLineFromMessageL(const RMessage2& aMessage);

	// operations on the document name
	IMPORT_C void SetDocumentNameL(const TDesC& aDocName);
	IMPORT_C TPtrC DocumentName() const;

	// operations on the executable name
	IMPORT_C void SetExecutableNameL(const TDesC& aAppName);
	IMPORT_C TPtrC ExecutableName() const;
	
	IMPORT_C void SetOpaqueDataL(const TDesC8& aOpaqueData);
	IMPORT_C TPtrC8 OpaqueData() const;

	// operations on the tail end
	IMPORT_C void SetTailEndL(const TDesC8& aTailEnd);
	IMPORT_C TPtrC8 TailEnd() const;

	// operations on the command
	IMPORT_C void SetCommandL(TApaCommand aCommand);
	IMPORT_C TApaCommand Command() const;

	// operations on the parent process id
	IMPORT_C void SetParentProcessId(TProcessId aProcessId);
	IMPORT_C TProcessId ParentProcessId() const;

	// operations on the file passed by handle
	IMPORT_C void SetFileByHandleL(const RFile& aFile);
	IMPORT_C void GetFileByHandleL(RFile& aFile) const;
public:

	// operations on the server requirement/differentiator number - 0 means no server, non-zero sets the differentiator for the server name
	IMPORT_C void SetServerNotRequiredL();
	IMPORT_C void SetServerRequiredL(TUint aServerDifferentiator);
	IMPORT_C TUint ServerRequired() const;

	// operations to support starting an application with a specific screen number
	IMPORT_C void SetDefaultScreenL(TInt aDefaultScreenNumber);
	IMPORT_C TInt DefaultScreen() const;
	IMPORT_C TBool IsDefaultScreenSet() const;

	// Operations to support window chaining
	IMPORT_C void SetParentWindowGroupID(TInt aParentWindowGroupID);
	IMPORT_C TInt ParentWindowGroupID() const;

	// operations to support passing memory-allocation failure settings in to applications
	IMPORT_C void SetDebugMemFailL(TInt aDebugMemFail);
	IMPORT_C TInt DebugMemFail() const;

	// operations to support the instrumentation (i.e. profiling) of application startup
	IMPORT_C void SetAppStartupInstrumentationEventIdBaseL(TInt aEventIdBase);
	IMPORT_C TInt AppStartupInstrumentationEventIdBase() const;

	IMPORT_C static TInt EnvironmentSlotForPublicUse(TInt aIndex);

private:
	struct SOption
		{
		const TDesC* iToken;
		TInt* iResult;
		TRadix iRadix;
		HBufC8* iHBufC8Result;
		};

private:
	CApaCommandLine();
	void SetServerDifferentiatorL(TUint aServerDifferentiator);
	void ExternalizeL(RWriteStream& aStream) const;
	void InternalizeL(RReadStream& aStream);
	HBufC8* StreamableAttributesLC() const;
	void GetCommandLineFromProcessEnvironmentL();
	TInt Parse(const TDesC& aCmdLine);
	TPtrC StripQuotes(const TDesC& aDes) const;

private:
	enum
		{
		EEnvironmentSlotUnused=0,

		EEnvironmentSlotMain=1,
		EEnvironmentSlotFsSession=2,
		EEnvironmentSlotFile=3,

		EFirstEnvironmentSlotForPublicUse=8,
		ENumberOfEnvironmentSlotsForPublicUse=4
		};

	enum
		{
		EIpcSlotMain=0,
		EIpcSlotFsSession=1,
		EIpcSlotFile=2
		};
public:
	enum
		{
		EIpcFirstFreeSlot=3
		};
private:
	HBufC* iDocumentName;
	HBufC* iExecutableName;
	HBufC8* iOpaqueData;
	HBufC8* iTailEnd;
	TApaCommand iCommand;
	TUint iServerDifferentiator;
	TInt iDefaultScreenNumber;
	TInt iParentWindowGroupID;
	TInt iDebugMemFail;
	TInt iAppStartupInstrumentationEventIdBase;
	RFile iFile;
	TProcessId iParentProcessId;
	};

#endif
