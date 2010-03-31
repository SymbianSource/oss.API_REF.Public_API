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
// apaapp.h
//

#ifndef __APAAPP_H__
#define __APAAPP_H__

#ifdef SYMBIAN_ENABLE_SPLIT_HEADERS
#if !defined(__APAID_PARTNER_H__)
#include "apaidpartner.h"
#endif
#endif //SYMBIAN_ENABLE_SPLIT_HEADERS
#include <e32std.h>
#include <e32base.h>
#include <apadef.h>
#include <apaid.h>

class CApaApplication;
class CApaDocument;
class CApaProcess;
class CDictionaryStore;
class CImplementationInformation;
class CApaAppServer;


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
class CApaApplication : public CBase
// base class for applications; allows creation of documents & file stores + display of app icon and name.
	{
public:
	/** Completes construction of this application object.
	
	The function is called after an instance of a derived class has been successfully 
	created using the ordinal 1 function of the application DLL.
	
	After calling this function, an application can create document objects.
	
	An implementation of this function is supplied by the UI framework.
	
	@see CEikApplication */
	virtual void PreDocConstructL() = 0; // call once before creating document
	
	/** Creates a document object.
	
	The function is called by the application process when a new document is required. 
	The application process adds the new document to its list of documents.
	
	An implementation of this function is supplied by the UI framework.
	
	@param aProcess A pointer to the process associated with the application.
	@return A pointer to the newly created document.
	@see CApaProcess::AddNewDocumentL() */
	virtual CApaDocument* CreateDocumentL(CApaProcess* aProcess) = 0;
	
	/** Gets the application specific UID.
	
	The UID is used to differentiate between UI applications.
	
	An implementation of this function must be supplied by the UI application.
	
	@return The application specific UID. */
	virtual TUid AppDllUid() const = 0;
public: // utility functions
	IMPORT_C static TInt GenerateFileName(RFs& aFs, TFileName& aRootName);
	IMPORT_C CDictionaryStore* OpenIniFileL(RFs& aFs) const;
	
	/** Opens the .ini file associated with the application, constructs the dictionary 
	store object, returns a pointer to it and puts the pointer onto the cleanupstack.
	
	The .ini file must be created, if it does not already exist.
	
	An implementation of this function is supplied by the UI framework.
	
	@param aFs Handle to a file server session 
	@return A pointer to the dictionary store object that represents the application's .ini file. 
	@see CEikApplication */
	virtual CDictionaryStore* OpenIniFileLC(RFs& aFs) const = 0;
public: // enquiry functions
	IMPORT_C virtual TFileName AppFullName() const; // returns the full path and name of the app
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
	virtual void Capability(TDes8& aInfo) const = 0;
public:	// accessor function
	IMPORT_C TFileName DllName() const;
	IMPORT_C ~CApaApplication();
	IMPORT_C virtual void NewAppServerL(CApaAppServer*& aAppServer);
protected:
	IMPORT_C CApaApplication();
public: // internal use only
	void SetAppFileNameRef(const RBuf& aFileName);
private:
	IMPORT_C virtual void CApaApplication_Reserved1();
	IMPORT_C virtual void CApaApplication_Reserved2();
private:
	const RBuf* iAppFileNameRef;  // not owned
	TUid iEComDtorKey;
//	friend class CApaProcess;
	friend class TApaApplicationFactory; // so that it can access iDtorKey
private:
	TInt iCApaApplication_Reserved1;
	};


/** Encapsulates the functionality of creating an application, whether it be via a factory function
or an ECOM plugin. Instances of this class can usually be created implicitly when required as
function parameters - just specify the function pointer, ECOM plugin UID or CImplementationInformation
reference.

@publishedAll
@released
@see CApaProcess
@see EikStart */
class TApaApplicationFactory
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

	
#endif	// __APAAPP_H__
