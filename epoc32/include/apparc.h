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

#ifndef __APPARC_H__
#define __APPARC_H__

#if !defined(__E32STD_H__)
#include <e32std.h>
#endif
#if !defined(__E32BASE_H__)
#include <e32base.h>
#endif
#if !defined(__F32FILE_H__)
#include <f32file.h>
#endif
#if !defined(__GDI_H__)
#include <gdi.h>
#endif
#if !defined(__APADEF_H__)
#include <apadef.h>
#endif
#if !defined(__APAID_H__)
#include <apaid.h>
#endif

// classes defined:
class CApaApplication;
class CApaDocument;
class CApaProcess;
class MApaEmbeddedDocObserver;
//
// classes referenced:
class CApaDll;
class CApaExe;
class RFile;
class RReadStream;
class RWriteStream;
class CFileStore;
class CPersistentStore;
class CStreamDictionary;
class CDictionaryStore;
class TApaAppHolderInfo;
class CImplementationInformation;
class TApaApplicationFactory;
class CApaAppHolder;
class CApaAppServer;

/** Creates an application interface object.

Provides the basic roles of an application class as a factory that
creates concrete document objects, and supplies utility functions 
not specific to any particular instance of a document.

@publishedAll
@released
*/
typedef CApaApplication* (*CreateCApaApplication)();


// CApaApplication

class CApaApplication : public CBase
// base class for applications; allows creation of documents & file stores + display of app icon and name.
/** Defines the basic behaviour for applications.

The class defines the basic twin roles of an application class as a factory 
that creates concrete document objects, and as a supplier of utility functions 
not specific to any particular instance of a document. For example, returning 
an application's caption, or accessing its .ini file.

The class is derived from by the UI framework and is further derived from 
by the UI application.

@publishedAll 
@released 
@see CEikApplication */
	{
public:
	/** Completes construction of this application object.
	
	The function is called after an instance of a derived class has been successfully 
	created using the ordinal 1 function of the application DLL.
	
	After calling this function, an application can create document objects.
	
	An implementation of this function is supplied by the UI framework.
	
	@see CEikApplication */
	virtual void PreDocConstructL()=0; // call once before creating document
	
	/** Creates a document object.
	
	The function is called by the application process when a new document is required. 
	The application process adds the new document to its list of documents.
	
	An implementation of this function is supplied by the UI framework.
	
	@param aProcess A pointer to the process associated with the application.
	@return A pointer to the newly created document.
	@see CApaProcess::AddNewDocumentL() */
	virtual CApaDocument* CreateDocumentL(CApaProcess* aProcess)=0;
	
	/** Gets the application specific UID.
	
	The UID is used to differentiate between UI applications.
	
	An implementation of this function must be supplied by the UI application.
	
	@return The application specific UID. */
	virtual TUid AppDllUid()const=0;
	
	//
	// utility functions
	IMPORT_C static TInt GenerateFileName(RFs& aFs,TFileName& aRootName);
	IMPORT_C CDictionaryStore* OpenIniFileL(RFs& aFs)const;
	
	/** Opens the .ini file associated with the application, constructs the dictionary 
	store object, returns a pointer to it and puts the pointer onto the cleanupstack.
	
	The .ini file must be created, if it does not already exist.
	
	An implementation of this function is supplied by the UI framework.
	
	@param aFs Handle to a file server session 
	@return A pointer to the dictionary store object that represents the application's 
	.ini file. 
	@see CEikApplication */
	virtual CDictionaryStore* OpenIniFileLC(RFs& aFs)const=0;
	//
	// enquiry functions
	IMPORT_C virtual TFileName AppFullName()const; // returns the full path and name of the app
	/** Returns the capabilities of the application.
	
	Application capability information is represented by an instance of a TApaAppCapability 
	object wrapped in a packaged modifiable buffer descriptor.
	
	The function is called from a number of places within the application framework.
	
	An implementation of this function is supplied by the UI framework.
	
	@param aInfo A packaged modifiable buffer descriptor (a TPckgBuf), encapsulating 
	a TApaAppCapability object. 
	@see CEikApplication
	@see TApaAppCapability
	@see TPckgBuf */
	virtual void Capability(TDes8& aInfo)const=0;
	//
	// accessor function
	IMPORT_C TFileName DllName()const;
	
	IMPORT_C ~CApaApplication();

	// formerly a reserved virtual, Reserved_1()
	IMPORT_C virtual void NewAppServerL(CApaAppServer*& aAppServer);
protected:
	IMPORT_C CApaApplication();
	
	IMPORT_C virtual void CApaApplication_Reserved1();
	IMPORT_C virtual void CApaApplication_Reserved2();

private:
	CApaAppHolder* iAppHolder;  // the CApaAppHolder that owns me
	TUid iDtorKey;	//	TInt iSpare;
	friend class CApaAppHolder;
	friend class CApaProcess;
	friend class TApaApplicationFactory; // so that it can access iDtorKey
	
private:
	TInt iCApaApplication_Reserved1;
	};

class CApaDocument : public CBase
// base class for documents; allows insertion of glass doors.
/** Defines basic behaviour for documents.

This is the base class for all documents. A document contains the data associated 
with the application's content.

The class is derived from by the UI framework and is further derived from 
by the UI application.

@publishedAll 
@released
@see CEikDocument */
	{
public:
	class TCapability
	/** CApaDocument capabilities.*/
		{
	public:
		IMPORT_C TCapability();
		//
		inline TBool CanDrawGlass()const;
		inline TBool CanPrint()const;
		inline void SetCanDrawGlass();
		inline void SetCanPrint();
		//
	private:
		enum {
			ECanDrawGlass	=0x01,
			ECanPrint		=0x02
			};
	private:
		TUint iCapability;
		TInt TCapability_Reserved1;
		};
	//
public:
	// document instantiation functions
	/** Initialises a new, empty, document with a default setup.
	
	This can be the main document or an embedded document. The function is called 
	by the UI framework when it creates a default document file.
	
	An implementation of this function must be supplied by the UI application.
	
	If initialisation fails, the document must be left in the same state as it 
	was before the function was called. */
	virtual void NewDocumentL()=0; // builds a new embedded or main document without loading from a store (may create the content from eg code or a template file).
	
	/** Creates and fully initialises a new filestore and stores the document into it, 
	replacing any existing file of the same name.
	
	The function should put the pointer to the filestore object onto the cleanup 
	stack.
	
	An implementation of this function is supplied by the UI framework.
	
	@param aFs Handle to a file server session. 
	@param aFileName The full path name of the file to be created. 
	@return A pointer to the newly constructed file store. 
	@see CEikDocument */
	virtual CFileStore* CreateFileStoreLC(RFs& aFs,const TDesC& aFileName)=0; // creates a file for a document and stores itself to that store (store should be put on cleanup stack).
	//
	// interaction functions
	IMPORT_C virtual CPicture* GlassPictureL(); // Does nothing by default, override to return handle to glass picture.
	
	/** Starts an editing session on an embedded document.
	
	The function should cause the application's UI to be created and the document 
	to be fully restored for editing.
	
	An implementation of this function is supplied by the UI framework.
	
	@param aContainer This document's observer.
	@param aReadOnly True, the document should be opened in read-only mode and 
	should not persist any changes made to the content. False, the document can 
	be opened in read/write mode; this is the default. 
	@see CEikDocument */
	virtual void EditL(MApaEmbeddedDocObserver* aContainer,TBool aReadOnly=EFalse)=0; // Edit the document in the context of the container's environment. If aContainer is null, edit as the main document
	
	/** Prints the document without a need for it to be open for editing.
	
	Typically, this is called from a shell or a file manager type application 
	that wants to print the document without opening it fully.
	
	An empty implementation of this function is supplied by the UI framework.
	
	The UI application can provide its own implementation.
	
	@param aSourceStore A reference to the store containing the document. 
	@see CEikDocument */
	virtual void PrintL(const CStreamStore& aSourceStore)=0; // default print parameters, assume print context supplied by environment
	//
	// persistence functions

	/** Stores the document to the current file, commits the changes, and marks the 
	document status as unchanged.
	
	Typically, the function is called by the application when it implements a 
	"Save" type menu option in its User Interface.
	
	An implementation of this function is supplied by the UI framework. This is 
	adequate for direct file store applications. Applications using a permanent 
	file store model, need to provide their own implementation.
	
	If the function leaves, an implementation should ensure that any changes made 
	to the file are rolled back, leaving the file in the state it was in before 
	the function was called.
	
	@see CEikDocument */
	virtual void SaveL()=0; // save the doc to the file in the custody of iAppProcess. This fn should be called by any "Save" menu option. store->Commit() should be called within it.	
	/** Stores the document's content and state to the specified store, recording the 
	identity of any headstreams created in the specified stream dictionary.
	
	The store must be fully constructed before this function is called.
	
	An empty implementation of this function is supplied by the UI framework. 
	UI applications that need to persist any data must provide their own implementation.
	
	If the function leaves, an implementation should ensure that the store and 
	the stream dictionary are returned to the state they were in before the function 
	was called.
	
	@param aStore The store into which document data is to be stored. 
	@param aStreamDic The stream dictionary into which stream IDs and associated 
	UIDs are to be recorded. 
	@see CEikDocument */
	virtual void StoreL(CStreamStore& aStore,CStreamDictionary& aStreamDic) const=0; // store to aStore, lodging the headstream in aStreamDic
	
	/** Restores the document's content and state from data persisted in the specified 
	store.
	
	An empty implementation of this function is supplied by the UI framework. 
	UI applications that need to restore data must provide their own implementation.
	
	If the function leaves, an implementation should ensure that the store and 
	the stream dictionary are returned to the state they were in before the function 
	was called.
	
	@param aStore The store from which document data is to be restored. 
	@param aStreamDic The stream dictionary containing stream IDs and associated 
	UIDs. 
	@see CEikDocument */
	virtual void RestoreL(const CStreamStore& aStore,const CStreamDictionary& aStreamDic)=0; // restore from aStore using aStreamDic
	
	/** Restores the document to the extent that it does not need the store
	further.

	A document only keeps a pointer to a store if it implements deferred
	loading. This also tells the document that any store pointer that it
	might have is just about to become invalid.
	
	An empty implementation of this function is supplied by the UI framework. 
	UI applications that support deferred loading or embedding should provide an
	implementation.
	
	If a document supports embedding, then it should
	propagate the DetachFromStoreL() call on to all embedded objects that
	it contains.
	
	If the function leaves, the operation should be aborted
	because the document has not successfully detached from the store.
	Continuing with the operation may leave the document in an unsafe
	state or cause user data to be lost.

	@param aDegree The degree of detachment required. */
	virtual void DetachFromStoreL(CPicture::TDetach /*aDegree*/=CPicture::EDetachFull) {} // supply an implementation if you support deferred loading or embedding

	IMPORT_C virtual void ExternalizeL(RWriteStream& aStream)const;
	//
	// enquiry functions
	
	/** Tests whether the document is empty.
	
	The UI framework provides a default implementation which always returns a 
	true value.
	
	The UI application can provide its own implementation. Typically, any application 
	that has editable content should supply an implementation that acts according 
	to the state of that content. Applications without associated document data 
	need not supply an implementation.
	
	@return True if the document is empty, false otherwise. 
	@see CEikDocument */
	virtual TBool IsEmpty()const=0; // return ETrue if the document is empty
	IMPORT_C virtual void ValidatePasswordL()const; // return EFalse if there *is* a password *and* the user doesn't get it right, ETrue otherwise (ie they get it right or there isn't one). Returns ETrue by default
	
	IMPORT_C virtual TCapability Capability()const; // returns "cant do anything" by default
	inline CApaApplication* Application()const;
	inline CApaProcess* Process()const;
	
	/** Tests whether the document has changed since it was last persisted.
	
	An implementation of this function is supplied by the UI framework and need 
	not be changed by the UI application.
	
	@return True, if the document has changed since the last time that it was 
	persisted, false, otherwise.
	@see CEikDocument */
	virtual TBool HasChanged()const =0;
	//
	IMPORT_C virtual ~CApaDocument();
protected:
	IMPORT_C CApaDocument();
	IMPORT_C CApaDocument(CApaApplication& aApp,CApaProcess& aProcess);
private:
	IMPORT_C virtual void OpenFileL(CFileStore*& aFileStore, RFile& aFile); // was previously Reserved_1
	// Reserved virtual functions...
	IMPORT_C virtual void Reserved_2();
protected:
	MApaEmbeddedDocObserver* iContainer; // null unless this is an embedded object currently being edited
private:
	CApaApplication* iApplication; // the doc's associated application
	CApaProcess* iApaProcess;
	TInt iSpare;
	};



class TApaApplicationFactory
/** Encapsulates the functionality of creating an application, whether it be via a factory function
or an ECOM plugin. Instances of this class can usually be created implicitly when required as
function parameters - just specify the function pointer, ECOM plugin UID or CImplementationInformation
reference.

@publishedAll
@released
@see CApaProcess
@see EikStart */
	{
public:
	typedef CApaApplication* (*TFunction)();
public:
	IMPORT_C TApaApplicationFactory();
	IMPORT_C TApaApplicationFactory(TFunction aFunction);
	IMPORT_C TApaApplicationFactory(const CImplementationInformation& aEmbeddedApplicationInformation);
	IMPORT_C TApaApplicationFactory(TUid aEmbeddedApplicationUid);
	CApaApplication* CreateApplicationL() const;
	HBufC* AppFileNameL() const;
	TUid AppFileUid() const;
private:
	enum TType
		{
		ETypeFunction,							// if iType is this, iData is a TFunction
		ETypeEmbeddedApplicationInformation,	// if iType is this, iData is an ECOM CImplementationInformation
		ETypeEmbeddedApplicationUid				// if iType is this, iData is an ECOM implementation TUid
		};
private:
	static CApaApplication* CreateEmbeddedApplicationL(TUid aUid);
	static HBufC* EmbeddedApplicationDisplayNameLC(TUid aUid);
	static HBufC* FullAppFileNameL(const TDesC& aAppName);
	static void CleanupImplementationArray(TAny* aImplementationArray);
private:
	TType iType;
	TUint iData;
	mutable CApaApplication* iApplication; // used to be iSpare1
	TInt iSpare2;
	};

class CApaParentProcessMonitor;

class CApaProcess : public CBase
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
	{
public:
	IMPORT_C static CApaProcess* NewL(const RFs& aFs);
	IMPORT_C void ResetL();
	//
	// static utility functions
	IMPORT_C static CStreamDictionary* ReadRootStreamLC(RFs& aFs,CFileStore*& aStore,const TDesC& aDocFullFileName,TUint aFileMode); // opens aDocFileName as aStore and returns the stream dictionary contained in its root stream on the cleanup stack
	IMPORT_C static CStreamDictionary* ReadRootStreamLC(CFileStore*& aStore, const RFile& aFile);
	IMPORT_C static void WriteRootStreamL(CPersistentStore& aStore,CStreamDictionary& aStreamDic,const CApaApplication& aApp);
	IMPORT_C static void WriteRootStreamL(CPersistentStore& aStore,CStreamDictionary& aStreamDic,const TApaAppIdentifier& aAppId);
	IMPORT_C static TApaAppIdentifier ReadAppIdentifierL(const CStreamStore& aStore,const CStreamDictionary& aStreamDic);
	IMPORT_C static void WriteAppIdentifierL(CStreamStore& aStore,CStreamDictionary& aStreamDic,const TApaAppIdentifier& aAppId);
	//
	// document management
	IMPORT_C CApaDocument* AddNewDocumentL(TApaApplicationFactory aApplicationFactory);
	IMPORT_C CApaDocument* OpenNewDocumentL(CFileStore*& aStore,CStreamDictionary*& aStreamDic,const TDesC& aDocFullFileName,TUint aFileMode); // Open a file and restore the contained document
	IMPORT_C void DestroyDocument(CApaDocument* aDoc); // Removes a doc (identified by the object) from the list and destroys it. Also removes the app and closes the AppDll if appropriate.
	//
	// setter functions
	IMPORT_C void SetMainDocument(CApaDocument* aDocument);
	IMPORT_C void SetMainDocFileName(const TDesC& aMainDocFileName); // panics if the descriptor is too long
	IMPORT_C void SetMainDocFileNameL(const TDesC& aMainDocFileName);
	//
	// accessor functions
	IMPORT_C TPtrC MainDocFileName()const;
	inline RFs& FsSession()const;
	inline CApaDocument* MainDocument()const;
	//
	IMPORT_C ~CApaProcess();
protected:
	IMPORT_C CApaProcess();
	IMPORT_C CApaProcess(const RFs& aFs);
	IMPORT_C void ConstructL();
	IMPORT_C void ConstructL(TProcessId aParentProcessId);

	IMPORT_C virtual void CApaProcess_Reserved1();
	IMPORT_C virtual void CApaProcess_Reserved2();
public:
	static TInt IdleRemoveApplications(TAny* aThis);
	void RemoveMarkedApplications();
private:
	CApaDll* AddAppDllL(const TDesC& aDllFullPath);
	CApaExe* AddAppExeL(TApaApplicationFactory aApplicationFactory);
	void RemoveApp(CApaAppHolder* aAppHolder);
	CApaDocument* CreateDocL(CApaApplication* aApp);
	CApaAppHolder* FindAppInListL(const TDesC& aAppFileName,TUid aUid)const; // returns NULL if not in list
	void DeleteAllDocs();
	void MarkApplicationForRemoval(const CApaApplication* aApp);
	static void DoReadRootStreamL(CStreamDictionary& aStreamDictionary, const CFileStore& aStore);
private:
	CArrayFixFlat<TApaAppHolderInfo>* iAppList; // array of apps in use
	CArrayFixFlat<CApaDocument*>* iDocList; // array of documents (1 main + n embedded)
	CApaDocument* iMainDoc;
	HBufC* iMainDocFileName;
	RFs iFsSession; // file server session for doc store
	CIdle* iApplicationRemover;
	CApaParentProcessMonitor* iMonitor;
	TInt iCApaProcess_Reserved1;
	};


class MApaEmbeddedDocObserver
/** An interface class for handling the completion of the editing of an embedded 
document.

@publishedAll 
@released
@see CApaDocument::EditL() */
	{
public:
	/** Defines the state of the embedded document on completion of editing. */
	enum TExitMode {
		/** Changes to the embedded document must be saved. */
		EKeepChanges,
		/** Reverts back to the saved version of the embedded document, i.e. reloads the 
		whole document. */
		ERevertToSaved,
		/** No changes have been made to the embedded document. */
		ENoChanges,
		/** The embedded document is empty. */
		EEmpty
		};
public:
	/** Implements the required behaviour when the editing of an embedded document completes.
	
	@param aMode Indicates the state of the document. */
	virtual void NotifyExit(TExitMode aMode)=0; // called on completion of editing of an embedded document
protected:
	IMPORT_C MApaEmbeddedDocObserver();
private:
	IMPORT_C virtual void MApaEmbeddedDocObserver_Reserved1();
	IMPORT_C virtual void MApaEmbeddedDocObserver_Reserved2();
private:
	TInt iMApaEmbeddedDocObserver_Reserved1;
	};


//// inlines ////
inline CApaApplication* CApaDocument::Application()const
/** Returns a pointer to the application that created the document.

@return A pointer to the document's associated application. */
	{ return iApplication; }

inline CApaProcess* CApaDocument::Process()const
/** Returns a pointer to the application process associated with this document.

@return A pointer to the application process associated with this document. */
	{ return iApaProcess; }

inline TBool CApaDocument::TCapability::CanDrawGlass()const
/** Tests whether the document supports being embedded as a glass door.

@return True if embedding as a glass door is supported; false otherwise. */
	{ return iCapability&ECanDrawGlass; }

inline TBool CApaDocument::TCapability::CanPrint()const
/** Tests whether the document supports being printed without using the full application 
UI.

@return True, if printing is supported; false, otherwise. */
	{ return iCapability&ECanPrint; }

inline void CApaDocument::TCapability::SetCanDrawGlass()
/** Sets the document as being capable of being embedded as a glass door. */
	{ iCapability = iCapability|ECanDrawGlass; }

inline void CApaDocument::TCapability::SetCanPrint()
/** Sets the document as being capable of being printed without using the full application 
UI. */
	{ iCapability = iCapability|ECanPrint; }

inline RFs& CApaProcess::FsSession()const
/** Returns a handle to the file server session used by this application process.

@return The file server session. */
	{ return (RFs&)iFsSession; } //lint !e1536 Exposing low access member - Kept for backward BC

inline CApaDocument* CApaProcess::MainDocument()const
/** Returns a pointer to the main document.

@return A pointer to the main document. */
	{ return iMainDoc; }
	
#endif
