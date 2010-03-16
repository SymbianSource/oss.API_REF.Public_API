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

#if !defined(__APGCLI_H__)
#define __APGCLI_H__

#if !defined(__E32BASE_H__)
#include <e32base.h>
#endif
#if !defined(__APMSTD_H__)
#include <apmstd.h>
#endif
#if !defined(__APMREC_H__)
#include <apmrec.h>
#endif
#if !defined(__APAID_H__)
#include <apaid.h>
#endif
#if !defined(__BADESCA_H__)
#include <badesca.h>
#endif
#if !defined(__F32FILE_H__)
#include <f32file.h>
#endif

// classes referenced
class CApaCommandLine;
class CApaMaskedBitmap;
class MArrayFiller;
class RFile;

class CApaLsSessionExtension;

class CDataRecognitionResultArrayEntry;
class CApaRegistrationResourceFileWriter;
class CApaLocalisableResourceFileWriter;

/* @internalComponent
*/
IMPORT_C TUint MinApplicationStackSize();

class CDataRecognitionResultArray : public CBase
/**
This class holds the recognition results of a recognized directory.
@publishedAll
@released
*/
	{
public: // exported functions
	IMPORT_C CDataRecognitionResultArray();
	IMPORT_C virtual ~CDataRecognitionResultArray();
	IMPORT_C const TFileName& Path() const;
	IMPORT_C TUint Count() const;
	IMPORT_C void GetDataRecognitionResultL(TDataRecognitionResult& aResult, const TUint aIndex) const;
	IMPORT_C void GetFileNameL(TFileName& aFileName, const TUint aIndex) const;
public: // dll internally
	TUint InternalizeL(const CBufFlat& aBuffer);
	void SetPath(const TFileName& aPath);
private:
	TFileName iPath;
	RPointerArray<CDataRecognitionResultArrayEntry> iEntries;
	};



////////////////////////////////////
// RApaLsSession
////////////////////////////////////

class RApaLsSession : public RSessionBase
/** A session with the application architecture server.

The server provides access to a cached list of the applications on the device. 

To use this class, clients first need to connect to the server. 

Then, one of GetAllApps(), GetEmbeddableApps() or GetFilteredApps() needs to be called. 
These functions do some initialisation of server data in preparation for returning the 
application list (which is owned by the server).

Then, GetNextApp() is called in a loop. The first time around, it populates the session's 
application list and retrieves the first application in the list. Further calls to GetNextApp() 
retrieve the remaining applications in the list, until RApaLsSession::ENoMoreAppsInList is 
returned.

The session should be closed when it is no longer needed, before it goes out of scope.

Various functions in RApaLsSession need to access the application list, and may return 
RApaLsSession::EAppListInvalid to indicate that the function was called before the initial 
population of the list is complete. If this occurs, you could try again after a short delay.

This class provides many other functions, for instance launching applications, querying 
application-specific information, recognising data.

@publishedAll
@released */
	{
	friend class CApaLsSessionExtension;
public:
	enum {
		/** A possible return value from GetNextApp(), to indicate that there are no more 
		applications in the list. */
		ENoMoreAppsInList=1,
		/** Indicates that an RApaLsSession member function was called before the session's 
		application list is fully populated. */
		EAppListInvalid
		};
	/** Defines the way an application is launched. */
	enum TLaunchType {
		/** Launches a new instance of the application. */
		ELaunchNewApp=1,
		/** Launches a new instance of the application if no existing instance of the application 
		is running. If an instance of the application is already running, then it 
		is brought to the foreground. */
		ESwitchFiles
		};
	
public:
	IMPORT_C RApaLsSession();
	//
	IMPORT_C TInt Connect();
	IMPORT_C TVersion Version() const;
	//
	IMPORT_C TInt AppCount(TInt& aCount) const; // returns error
	IMPORT_C TInt EmbeddableAppCount(TInt& aCount) const; // returns error
	//
	IMPORT_C TInt GetAllApps() const; // Call to initialize
	IMPORT_C TInt GetAllApps(TInt aScreenMode) const; // Call to initialize
	IMPORT_C TInt GetEmbeddableApps() const; // Call to initialize
	IMPORT_C TInt GetEmbeddableApps(TInt aScreenMode) const; // Call to initialize
	// 7.0s
	IMPORT_C TInt GetFilteredApps(const TApaEmbeddabilityFilter& aFilter) const; // Call to initialize
	IMPORT_C TInt GetFilteredApps(const TApaEmbeddabilityFilter& aFilter, TInt aScreenMode) const; // Call to initialize
	// 8.1
	IMPORT_C TInt GetFilteredApps(TUint aCapabilityAttributeMask, TUint aCapabilityAttributeValue) const; // Call to initialize
	IMPORT_C TInt GetFilteredApps(TUint aCapabilityAttributeMask, TUint aCapabilityAttributeValue, TInt aScreenMode) const; // Call to initialize
	// 9.0
	IMPORT_C TInt GetServerApps(TUid aServiceUid) const; // Call to initialize
	IMPORT_C TInt GetServerApps(TUid aServiceUid, TInt aScreenMode) const; // Call to initialize
	//
	IMPORT_C TInt GetNextApp(TApaAppInfo& aInfo) const; // call repeatedly, returns err (inc ENoMoreAppsInList,EAppListInvalid)
	IMPORT_C TInt GetNextApp(TApaAppInfo& aInfo,TInt aScreenMode) const; // call repeatedly, returns err (inc ENoMoreAppsInList,EAppListInvalid)
	//
	IMPORT_C TInt GetAppInfo(TApaAppInfo& aInfo,TUid aAppUid) const;
	IMPORT_C TInt SetAppShortCaption(const TDesC& aShortCaption, TLanguage aLanguage, TUid aAppUid);
	IMPORT_C TInt GetDefaultScreenNumber(TInt& aDefaultScreenNumber, TUid aAppUid) const;
	
public:
	IMPORT_C TInt GetAppCapability(TDes8& aCapabilityBuf,TUid aAppUid) const;
	IMPORT_C TInt StartApp(const CApaCommandLine& aCommandLine); // This is only recommended for non document based apps
	IMPORT_C TInt StartApp(const CApaCommandLine& aCommandLine,TThreadId& aThreadId);
	IMPORT_C TInt StartApp(const CApaCommandLine& aCommandLine,TThreadId& aThreadId,TRequestStatus* aRequestStatusForRendezvous);
	//
	IMPORT_C TInt RecognizeData(const TDesC& aName, const TDesC8& aBuffer, TDataRecognitionResult& aDataType) const;
	IMPORT_C TInt RecognizeData(const RFile& aFile, TDataRecognitionResult& aDataType) const;
	IMPORT_C TInt RecognizeSpecificData(const TDesC& aName, const TDesC8& aBuffer, const TDataType& aDataType, TBool& aResult) const;
	IMPORT_C TInt RecognizeSpecificData(const RFile& aFile, const TDataType& aDataType, TBool& aResult) const;
	//
	IMPORT_C TInt AppForDataType(const TDataType& aDataType, TUid& aAppUid) const;
	IMPORT_C TInt StartDocument(const TDesC& aFileName, TThreadId& aThreadId, TLaunchType aLaunchType=ELaunchNewApp);
	IMPORT_C TInt StartDocument(RFile& aFile, TThreadId& aThreadId, TRequestStatus* aRequestStatusForRendezvous=NULL);
	IMPORT_C TInt StartDocument(const TDesC& aFileName, const TDataType& aDataType, TThreadId& aThreadId, TLaunchType aLaunchType=ELaunchNewApp);
	IMPORT_C TInt StartDocument(RFile& aFile, const TDataType& aDataType, TThreadId& aThreadId, TRequestStatus* aRequestStatusForRendezvous=NULL);
	IMPORT_C TInt StartDocument(const TDesC& aFileName, TUid aAppUid, TThreadId& aThreadId, TLaunchType aLaunchType=ELaunchNewApp);
	IMPORT_C TInt StartDocument(RFile& aFile, TUid aAppUid, TThreadId& aThreadId, TRequestStatus* aRequestStatusForRendezvous=NULL);
	IMPORT_C TInt CreateDocument(const TDesC& aFileName, TUid aAppUid, TThreadId& aThreadId, TLaunchType aLaunchType=ELaunchNewApp);
	//
	IMPORT_C TInt GetAppIcon(TUid aAppUid, TInt aSize, CApaMaskedBitmap& aAppBitmap) const;
	//
	IMPORT_C TInt AppForDocument(const TDesC& aFileName, TUid& aAppUid, TDataType& aDataType) const;
	IMPORT_C TInt AppForDocument(const RFile& aFile, TUid& aAppUid, TDataType& aDataType) const;
	IMPORT_C TInt IsProgram(const TDesC& aFileName, TBool& aProgram) const;
	IMPORT_C TInt GetAcceptedConfidence(TInt& aConfidence) const;
	IMPORT_C TInt SetAcceptedConfidence(TInt aConfidence);
	IMPORT_C TInt GetMaxDataBufSize(TInt& aBufSize) const;
	IMPORT_C TInt SetMaxDataBufSize(TInt aBufSize);
	IMPORT_C TInt GetPreferredBufSize(TInt& aPreferredBufSize) const;
	IMPORT_C TInt GetSupportedDataTypesL(CDataTypeArray& aDataTypes) const;
	//
	IMPORT_C TInt GetAppIconSizes(TUid aAppUid, CArrayFixFlat<TSize>& aArrayToFill) const;
	IMPORT_C TInt GetAppIcon(TUid aAppUid, TSize aSize, CApaMaskedBitmap& aAppBitmap) const;
	IMPORT_C TInt GetAppIcon(TUid aAppUid, RFile& aFile) const;
	//
	IMPORT_C TInt GetAppViews(CApaAppViewArray& aAppViews, TUid aAppUid) const;
	IMPORT_C TInt GetAppViewIcon(TUid aAppUid, TUid aViewUid, const TSize& aSize, CApaMaskedBitmap& aViewBitmap) const;
	IMPORT_C TInt GetAppOwnedFiles(CDesCArray& aAppOwnedFiles, TUid aAppUid) const;
	//
	IMPORT_C TInt NumberOfOwnDefinedIcons(TUid aAppUid, TInt& aCount) const;
	//
	IMPORT_C TInt GetAppIcon(TUid aAppUid, HBufC*& aFullFileName) const;
	IMPORT_C TInt GetAppViewIcon(TUid aAppUid, TUid aViewUid, HBufC*& aFullFileName) const;
	IMPORT_C TInt InsertDataMapping(const TDataType& aDataType, TDataTypePriority aPriority, TUid aUid);
	IMPORT_C TInt InsertDataMappingIfHigher(const TDataType& aDataType, TDataTypePriority aPriority, TUid aUid, TBool& aInserted);
	IMPORT_C TInt DeleteDataMapping(const TDataType& aDataType);
	/**
	@internalComponent
	@released
	*/
	IMPORT_C TInt InsertDataMapping(const TDataType& aDataType, TDataTypePriority aPriority, 
		TUid aUid, TUid aServiceUid);
	/**
	@internalComponent
	@released
	*/
	IMPORT_C TInt DeleteDataMapping(const TDataType& aDataType, TUid aServiceUid);
	/**
	@internalComponent
	@released
	*/
	IMPORT_C TInt GetAppByDataType(const TDataType& aDataType, TUid aServiceUid, TUid& aAppUid) const;

public:
	//
	IMPORT_C CApaAppServiceInfoArray* GetAppServicesLC(TUid aAppUid) const;
	IMPORT_C CApaAppServiceInfoArray* GetServiceImplementationsLC(TUid aServiceUid) const;
	IMPORT_C CApaAppServiceInfoArray* GetServiceImplementationsLC(TUid aServiceUid, const TDataType& aDataType) const;
	IMPORT_C void GetAppServicesL(TUid aAppUid, CArrayFixFlat<TUid>& aServiceUids) const;
	IMPORT_C CApaAppServiceInfoArray* GetAppServiceOpaqueDataLC(TUid aAppUid, TUid aServiceUid) const;
	IMPORT_C TInt AppForDataTypeAndService(const TDataType& aDataType, TUid aServiceUid, TUid& aAppUid) const;
	IMPORT_C TInt AppForDocumentAndService(const TDesC& aFileName, TUid aServiceUid, TUid& aAppUid, TDataType& aDataType) const;
	IMPORT_C TInt AppForDocumentAndService(const RFile& aFile, TUid aServiceUid, TUid& aAppUid, TDataType& aDataType) const;
	IMPORT_C TInt ApplicationLanguage(TUid aAppUid, TLanguage& aLanguage) const;
	IMPORT_C void Close(); //lint !e1511 Member hides non-virtual member

	IMPORT_C void RegisterListPopulationCompleteObserver(TRequestStatus& aStatus) const;
	IMPORT_C TInt CancelListPopulationCompleteObserver() const;
	IMPORT_C TInt MatchesSecurityPolicy(TBool& aMatches, TUid aAppUid, const TSecurityPolicy& aSecurityPolicy) const;
	IMPORT_C TInt RecognizeFilesL(const TDesC& aPath, CDataRecognitionResultArray& aResult) const;
	IMPORT_C void RecognizeFilesL(const TDesC& aPath, CDataRecognitionResultArray& aResult, TRequestStatus& aStatus);
	IMPORT_C TInt RecognizeFilesL(const TDesC& aPath, const TDesC8& aDataType, CDataRecognitionResultArray& aResult) const;
	IMPORT_C void RecognizeFilesL(const TDesC& aPath, const TDesC8& aDataType, CDataRecognitionResultArray& aResult, TRequestStatus& aStatus);
	IMPORT_C void CancelRecognizeFiles();

	IMPORT_C void RegisterNonNativeApplicationTypeL(TUid aApplicationType, const TDesC& aNativeExecutable);
	IMPORT_C void DeregisterNonNativeApplicationTypeL(TUid aApplicationType);
	IMPORT_C void PrepareNonNativeApplicationsUpdatesL();
	IMPORT_C void RegisterNonNativeApplicationL(TUid aApplicationType, const TDriveUnit& aDrive, CApaRegistrationResourceFileWriter& aRegistrationResourceFile, CApaLocalisableResourceFileWriter* aLocalisableResourceFile, const RFile* aIconFile);
	IMPORT_C void DeregisterNonNativeApplicationL(TUid aApplication);
	IMPORT_C void CommitNonNativeApplicationsUpdatesL();
	IMPORT_C TInt RollbackNonNativeApplicationsUpdates();
	IMPORT_C void NotifyOnDataMappingChange(TRequestStatus& aRequestStatus);
	IMPORT_C void CancelNotifyOnDataMappingChange();
	IMPORT_C TInt GetAppType(TUid& aTypeUid, TUid aAppUid) const;
	
	IMPORT_C TInt ForceRegistration(const RPointerArray<TDesC>& aRegFiles);
	
public:
	// not for public use
	IMPORT_C static void SetFsSessionL(RFs& aFsSession);
	IMPORT_C static void ClearFsSession();
	IMPORT_C static RFs* FsSession();
	IMPORT_C void SetNotify(TBool aCompleteImmediatelyIfNoScanImpendingOrInProgress, TRequestStatus& aStatus);
	IMPORT_C void CancelNotify();

private: // Reserved for future use
	IMPORT_C virtual void RApaLsSession_Reserved1();
	IMPORT_C virtual void RApaLsSession_Reserved2();

public:
	/**
	@publishedPartner
	@released
	*/
	IMPORT_C void ForceCommitNonNativeApplicationsUpdatesL(); 
	
private:
	void DoGetAppOwnedFilesL(CDesCArray& aArrayToFill, TUid aAppUid) const;
	void DoGetAppViewsL(CApaAppViewArray& aArrayToFill, TUid aAppUid) const;
	void DoGetAppIconSizesL(TUid aAppUid, CArrayFixFlat<TSize>& aArrayToFill) const;
	TInt DoAppCount(TInt& aCount,TInt aCommand) const;
	void FetchArrayL(MArrayFiller& aArrayFiller,TUid aAppUid, TInt aOpcode, TInt aInitialBufSize) const;
	CBufBase* GetServiceBufferLC(TInt aOpcode, TUid aUid1, TUid aUid2=KNullUid) const;
	TInt StartAndCreate(TInt aRqst,const TDesC& aFileName, TUid aAppUid, TThreadId& aThreadId, TLaunchType aLaunchType);
	CBufBase* GetServiceBufferLC(TInt aOpcode, TUid aUid1, const TDataType& aDataType) const;
	TInt SendReceiveWithReconnect(TInt aFunction,const TIpcArgs& aIpcArgs) const;
	TInt TransferAndInternalizeDataL(const TDesC& aPath, const TInt aRequiredBufferSize, CDataRecognitionResultArray& aResult) const;
	TInt GetExecutableName(TDes& aNativeExecutableName, TDes& aLogicalExecutableName, HBufC8*& aOpaqueData, TIpcArgs& aIpcArgs, TInt aOpcode) const;
	TInt GetOpaqueData(HBufC8*& aOpaqueData, TInt aLengthOfOpaqueData) const;
	TInt StartApplicationPassingFileHandle(const TDesC& aNativeExecutableName, const TDesC& aLogicalExecutableName, const TDesC8* aOpaqueData, const RFile& aFile, TThreadId& aThreadId, TRequestStatus* aRequestStatusForRendezvous);
	TInt StartApplicationPassingDocumentName(const TDesC& aNativeExecutableName, const TDesC& aLogicalExecutableName, const TDesC8* aOpaqueData, const TDesC& aDocumentName, TThreadId& aThreadId,TApaCommand aCommand, TRequestStatus* aRequestStatusForRendezvous);
	void StartApplicationL(const TDesC& aNativeExecutableName, const CApaCommandLine& aCommandLine, TThreadId& aThreadId, TRequestStatus* aRequestStatusForRendezvous);
	TInt DoAppForDocumentOptionallySpecifyingService(const TDesC& aFileName, TUid aServiceUid, TUid& aAppUid, TDataType& aDataType, TInt aOpcode) const;
	TInt DoAppForDocumentOptionallySpecifyingService(const RFile& aFile, TUid aServiceUid, TUid& aAppUid, TDataType& aDataType, TInt aOpcode) const;
	TInt GetBufferFromFile(HBufC8*& aBuffer, const TDesC& aFileName) const;
	TInt DoStartApp(const CApaCommandLine& aCommandLine, TThreadId* aThreadId,TRequestStatus* aRequestStatusForRendezvous);
	void DoStartAppL(const CApaCommandLine& aCommandLine, TThreadId* aThreadId,TRequestStatus* aRequestStatusForRendezvous);
	static void GetThreadIdL(TThreadId& aThreadId, const RProcess& aProcess);
	static void DeletePointerToPointerToTAny(TAny* aPointerToPointerToTAny);
	static CBufFlat* CreateRegFilesBufferL(const RPointerArray<TDesC>& aRegFiles);
	static void CleanupOperation(TAny* aAny);

private: // data
	CApaLsSessionExtension* iExtension; // friend!
	};


#endif
