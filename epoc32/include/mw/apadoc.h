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
// apadoc.h
//

#ifndef __APADOC_H__
#define __APADOC_H__

#include <e32std.h>
#include <e32base.h>
#include <gdi.h>	// class CPicture::TDetach

class CApaApplication;
class CApaProcess;
class MApaEmbeddedDocObserver;
class RFile;
class RWriteStream;
class CFileStore;
class CStreamDictionary;
class RFs;
class CPicture;
class CStreamStore;

/** Defines basic behaviour for documents.

This is the base class for all documents. A document contains the data associated 
with the application's content.

The class is derived from by the UI framework and is further derived from 
by the UI application.

@publishedAll 
@released
@see CEikDocument */
class CApaDocument : public CBase
// base class for documents; allows insertion of glass doors.
	{
public:
	class TCapability
	/** CApaDocument capabilities.*/
		{
	public:
		IMPORT_C TCapability();
		inline TBool CanDrawGlass()const;
		inline TBool CanPrint()const;
		inline void SetCanDrawGlass();
		inline void SetCanPrint();
	private:
		enum {
			ECanDrawGlass	=0x01,
			ECanPrint		=0x02
			};
	private:
		TUint iCapability;
		TInt TCapability_Reserved1;
		};
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
	virtual void PrintL(const CStreamStore& aSourceStore) = 0; // default print parameters, assume print context supplied by environment
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
	virtual void SaveL() = 0; // save the doc to the file in the custody of iAppProcess. This fn should be called by any "Save" menu option. store->Commit() should be called within it.	
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
	virtual void StoreL(CStreamStore& aStore,CStreamDictionary& aStreamDic) const = 0; // store to aStore, lodging the headstream in aStreamDic
	
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
	virtual void RestoreL(const CStreamStore& aStore, const CStreamDictionary& aStreamDic) = 0; // restore from aStore using aStreamDic
	
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

	IMPORT_C virtual void ExternalizeL(RWriteStream& aStream) const;
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
	virtual TBool IsEmpty() const = 0; // return ETrue if the document is empty
	IMPORT_C virtual void ValidatePasswordL() const; // return EFalse if there *is* a password *and* the user doesn't get it right, ETrue otherwise (ie they get it right or there isn't one). Returns ETrue by default
	
	IMPORT_C virtual TCapability Capability() const; // returns "cant do anything" by default
	inline CApaApplication* Application() const;
	inline CApaProcess* Process() const;
	
	/** Tests whether the document has changed since it was last persisted.
	
	An implementation of this function is supplied by the UI framework and need 
	not be changed by the UI application.
	
	@return True, if the document has changed since the last time that it was 
	persisted, false, otherwise.
	@see CEikDocument */
	virtual TBool HasChanged()const = 0;
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


/** An interface class for handling the completion of the editing of an embedded 
document.

@publishedAll 
@released
@see CApaDocument::EditL() */
class MApaEmbeddedDocObserver
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


// inlines //

/** Returns a pointer to the application that created the document.
@return A pointer to the document's associated application. */
inline CApaApplication* CApaDocument::Application() const
	{ return iApplication; }

/** Returns a pointer to the application process associated with this document.
@return A pointer to the application process associated with this document. */
inline CApaProcess* CApaDocument::Process()const
	{ return iApaProcess; }

/** Tests whether the document supports being embedded as a glass door.
@return True if embedding as a glass door is supported; false otherwise. */
inline TBool CApaDocument::TCapability::CanDrawGlass()const
	{ return iCapability&ECanDrawGlass; }

/** Tests whether the document supports being printed without using the full application UI.
@return True, if printing is supported; false, otherwise. */
inline TBool CApaDocument::TCapability::CanPrint()const
	{ return iCapability&ECanPrint; }

/** Sets the document as being capable of being embedded as a glass door. */
inline void CApaDocument::TCapability::SetCanDrawGlass()
	{ iCapability = iCapability|ECanDrawGlass; }

/** Sets the document as being capable of being printed without using the full application UI. */
inline void CApaDocument::TCapability::SetCanPrint()
	{ iCapability = iCapability|ECanPrint; }
	
#endif	// __APADOC_H__
