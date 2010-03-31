// Copyright (c) 1997-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
// apacmdln.h
//

#ifndef __APACMDLN_H__
#define __APACMDLN_H__

#include <e32base.h>	// class CBase
#include <apadef.h>		// enum TApaCommand
#include <f32file.h>
#include <s32strm.h>


/** Information for launching an application.

To start an application, passed a CApaCommandLine object to the RApaLsSession::StartApp() method.

This class is often referred to as a command line and contains:
the name of an application EXE to be launched, a document name,
a command code that defines the way the application is launched
trailing data; the structure of this depends on the application to be launched.

To start an application, startup parameters are set on the CApaCommandLine object that is 
then externalized into a stream and attached to a new RProcess object. These parameters 
are then used to re-populate a new CApaCommandLine object inside the process by 
EikStart::RunApplication() and used to bootstrap the launching application.

@publishedAll
@released */
class CApaCommandLine : public CBase
	{
public:
	// Creates an empty command line object
	IMPORT_C static CApaCommandLine* NewL();
	IMPORT_C static CApaCommandLine* NewLC();
	// Specify how the application is to be started (see TApaCommand in apadef.h)
	IMPORT_C void SetCommandL(TApaCommand aCommand);
	IMPORT_C TApaCommand Command() const;
	// Launch the application associated with the mime-type of the document file
	IMPORT_C void SetDocumentNameL(const TDesC& aDocName);
	IMPORT_C TPtrC DocumentName() const;
	IMPORT_C void SetFileByHandleL(const RFile& aFile);
	IMPORT_C void GetFileByHandleL(RFile& aFile) const;
	// Launch the application explicitly named
	IMPORT_C void SetExecutableNameL(const TDesC& aAppName);
	IMPORT_C TPtrC ExecutableName() const;
	// Additional application execution arguments (added to the tail if the command line)
	IMPORT_C void SetTailEndL(const TDesC8& aTailEnd);
	IMPORT_C TPtrC8 TailEnd() const;
	// Set the process id of the application being the conceptual parent.
	// The child process will be closed down automatically when the parent is.
	IMPORT_C void SetParentProcessId(TProcessId aProcessId);
	IMPORT_C TProcessId ParentProcessId() const;
	// Starting the application on a specific screen
	IMPORT_C void SetDefaultScreenL(TInt aDefaultScreenNumber);
	IMPORT_C TInt DefaultScreen() const;
	IMPORT_C TBool IsDefaultScreenSet() const;
	// Managed order of applications' window groups.
	// A child applicatoin's windows will always be kept in front of the parent's windows.
	IMPORT_C void SetParentWindowGroupID(TInt aParentWindowGroupID);
	IMPORT_C TInt ParentWindowGroupID() const;
	// Process environment-slot for public use. These can be used for passing parameters 
	// to the starting application. However, use of the EndTail should be prefered.
	IMPORT_C static TInt NumberOfEnvironmentSlotsForPublicUse();
	IMPORT_C static TInt EnvironmentSlotForPublicUse(TInt aIndex);
public:	// Internal
	IMPORT_C ~CApaCommandLine();
	// Set opaque data sent to the application being started
	IMPORT_C void SetOpaqueDataL(const TDesC8& aOpaqueData);
	IMPORT_C TPtrC8 OpaqueData() const;
	// Getting/setting the CApaCommandLine to/from a server IPC-message
	IMPORT_C void GetIpcArgsLC(TIpcArgs& aIpcArgs) const;
	IMPORT_C void ConstructCmdLineFromMessageL(const RMessage2& aMessage);
	// Getting/setting the CApaCommandLine to/from process environment-slots
	IMPORT_C void SetProcessEnvironmentL(RProcess& aProcess) const;
	IMPORT_C static TInt GetCommandLineFromProcessEnvironment(CApaCommandLine*& aCommandLine);
	// operations to support passing memory-allocation failure settings in to applications
	IMPORT_C void SetDebugMemFailL(TInt aDebugMemFail);
	IMPORT_C TInt DebugMemFail() const;
	// operations to support the instrumentation (i.e. profiling) of application startup
	IMPORT_C void SetAppStartupInstrumentationEventIdBaseL(TInt aEventIdBase);
	IMPORT_C TInt AppStartupInstrumentationEventIdBase() const;
	// operations on the server requirement/differentiator number - 0 means no server, non-zero sets the differentiator for the server name
	IMPORT_C void SetServerNotRequiredL();
	IMPORT_C void SetServerRequiredL(TUint aServerDifferentiator);
	IMPORT_C TUint ServerRequired() const;
private:
	CApaCommandLine();
	void ExternalizeL(RWriteStream& aStream) const;
	void InternalizeL(RReadStream& aStream);
	HBufC8* StreamableAttributesLC() const;
	void DoGetCommandLineFromProcessEnvironmentL();
	TInt DoGetParametersFromCommandLineString(const TDesC& aCmdLine);
	static HBufC* NameOfExecutable(const TDesC& aCmdLine, TInt& aEndDocNameOffset);
	static TPtrC StripQuotes(const TDesC& aDes);
	void SetServerDifferentiatorL(TUint aServerDifferentiator);
public:
	enum	// for internal use only
		{
		EIpcFirstFreeSlot=3
		};
private:
	RBuf iDocumentName;
	RBuf iExecutableName;
	RBuf8 iOpaqueData;
	RBuf8 iTailEnd;
	TApaCommand iCommand;
	TUint iServerDifferentiator;
	TInt iDefaultScreenNumber;
	TInt iParentWindowGroupID;
	TInt iDebugMemFail;
	TInt iAppStartupInstrumentationEventIdBase;
	RFile iFile;
	TProcessId iParentProcessId;
	};

#endif // __APACMDLN_H__
