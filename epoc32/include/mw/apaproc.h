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
// The main startup of the AppArc server
// 
// apaproc.h
//

#ifndef __APAPROC_H__
#define __APAPROC_H__

#include <e32std.h>
#include <e32base.h>
#include <f32file.h>	// class RFs
#include <apadef.h>
#include <apaid.h>

class CApaApplication;
class CApaDocument;
class RApaApplication;
class RFile;
class CFileStore;
class CPersistentStore;
class CStreamDictionary;
class TApaApplicationFactory;
class CStreamStore;

class CApaParentProcessMonitor;

/** Maintains a list of documents and all of the potentially shared resources used 
by documents.

This includes the application DLLs. The class also supplies utility functions 
that provide the basic structure for persisted document files.

The class deals with the loading of application DLLs and manages the creation 
and destruction of application (CApaApplication) objects and document (CApaDocument) 
objects.

The class is derived from by the UI framework and further derivation by the 
UI application is not necessary unless it needs to add extra utility functions 
for the use of applications.

@publishedAll
@released
@see CApaApplication
@see CApaDocument */
class CApaProcess : public CBase
	{
public:
	IMPORT_C static CApaProcess* NewL(const RFs& aFs);
	IMPORT_C void ResetL();
	// static utility functions
	IMPORT_C static CStreamDictionary* ReadRootStreamLC(RFs& aFs,CFileStore*& aStore, const TDesC& aDocFullFileName, TUint aFileMode); // opens aDocFileName as aStore and returns the stream dictionary contained in its root stream on the cleanup stack
	IMPORT_C static CStreamDictionary* ReadRootStreamLC(CFileStore*& aStore, const RFile& aFile);
	IMPORT_C static void WriteRootStreamL(CPersistentStore& aStore, CStreamDictionary& aStreamDic, const CApaApplication& aApp);
	IMPORT_C static void WriteRootStreamL(CPersistentStore& aStore, CStreamDictionary& aStreamDic, const TApaAppIdentifier& aAppId);
	IMPORT_C static TApaAppIdentifier ReadAppIdentifierL(const CStreamStore& aStore, const CStreamDictionary& aStreamDic);
	IMPORT_C static void WriteAppIdentifierL(CStreamStore& aStore, CStreamDictionary& aStreamDic, const TApaAppIdentifier& aAppId);
	// document management
	IMPORT_C CApaDocument* AddNewDocumentL(TApaApplicationFactory aApplicationFactory);
	IMPORT_C CApaDocument* OpenNewDocumentL(CFileStore*& aStore, CStreamDictionary*& aStreamDic, const TDesC& aDocFullFileName, TUint aFileMode); // Open a file and restore the contained document
	IMPORT_C void DestroyDocument(CApaDocument* aDoc); // Removes a doc (identified by the object) from the list and destroys it. Also removes the app and closes the AppDll if appropriate.
	// setter functions
	IMPORT_C void SetMainDocument(CApaDocument* aDocument);
	IMPORT_C void SetMainDocFileName(const TDesC& aMainDocFileName); // panics if the descriptor is too long
	IMPORT_C void SetMainDocFileNameL(const TDesC& aMainDocFileName);
	// accessor functions
	IMPORT_C TPtrC MainDocFileName() const;
	inline RFs& FsSession() const;
	inline CApaDocument* MainDocument() const;

	IMPORT_C ~CApaProcess();
protected:
	IMPORT_C CApaProcess();
	IMPORT_C CApaProcess(const RFs& aFs);
	IMPORT_C void ConstructL();
	IMPORT_C void ConstructL(TProcessId aParentProcessId);

	IMPORT_C virtual void CApaProcess_Reserved1();
	IMPORT_C virtual void CApaProcess_Reserved2();
private:
	RApaApplication* AddAppL(TApaApplicationFactory aApplicationFactory);
	void RemoveApp(RApaApplication* aApp);
	CApaDocument* CreateDocL(CApaApplication* aApp);
	RApaApplication* FindAppInListL(const TDesC& aAppFileName,TUid aUid) const; // returns NULL if not in list
	static void DoReadRootStreamL(CStreamDictionary& aStreamDictionary, const CFileStore& aStore);
	void DeleteAllDocs();
	void MarkApplicationForAsyncRemoval(const CApaApplication* aApp);
	static TInt IdleRemoveApplications(TAny* aApaProcess);
	void RemoveMarkedApplications();
private:
	CArrayPtrFlat<RApaApplication>* iAppList; // array of apps in use
	CArrayPtrFlat<CApaDocument>* iDocList; // array of documents (1 main + n embedded)
	CApaDocument* iMainDoc;
	HBufC* iMainDocFileName;
	RFs iFsSession; // file server session for doc store
	CIdle* iAsyncAppRemover;
	CApaParentProcessMonitor* iMonitor;
	TInt iCApaProcess_Reserved1;
	};



// inlines //

/** Returns a handle to the file server session used by this application process.
@return The file server session. */
inline RFs& CApaProcess::FsSession()const
	{ return (RFs&)iFsSession; } //lint !e1536 Exposing low access member - Kept for backward BC

/** Returns a pointer to the main document.
@return A pointer to the main document. */
inline CApaDocument* CApaProcess::MainDocument()const
	{ return iMainDoc; }
	
#endif	// __APAPROC_H__
