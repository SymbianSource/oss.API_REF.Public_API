/*
* Copyright (c) 2005 Nokia Corporation and/or its subsidiary(-ies). 
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description: Definition of dm constants/exported methods
* 	This is part of remotemgmt_plat. 
*/


#ifndef __SMLDMADAPTER_H__
#define __SMLDMADAPTER_H__

#include <e32base.h>
#include <ecom/ecom.h>

class MSmlDmDDFObject;
class MSmlDmCallback;
class RWriteStream;

/** ECOM interface uid for DM plugin adapters */
#define KSmlDMInterfaceUid 0x102018B4

/** Maximum length of a URI segment supported by the DM framework */
#define KSmlMaxURISegLen 32

struct TSmlDmMappingInfo
/**
The struct combines an URI segment to a LUID in a device.
@publishedPartner
@prototype
*/
	{
	/** The URI segment. When using this structure, a path of the URI segment must be known */
	TBufC8<KSmlMaxURISegLen> iURISeg;

	/** Local UID in the device */
	TPtrC8 iURISegLUID;	
	};

class MSmlDmAdapter
/**
Abstract Device Management adapter.  Implementations of this interface are able to map settings
in device stores to portions of the Device Management Tree.
@publishedPartner
@prototype
*/
	{
public: //enums

	/** An enumeration of the error codes which may be returned by DM adapters.
	@publishedPartner
	@prototype
	*/
	enum TError 
		{
		/** The command was successful */
		EOk = 0,
		/** The command failed because no setting exists in the store which corresponds to the
			URI or LUID passed to the adapter */
		ENotFound,
		/** The command failed because the setting can't take the value being passed to the adapter */
		EInvalidObject,
		/** The command failed because the setting already exists in the store */
		EAlreadyExists,
		/** The command failed because the setting value is too large to be accommodated in the store */
		ETooLargeObject,
		/** The command failed because the disk on which the device store resides is full */
		EDiskFull,
		/** The command failed for an unspecified reason */
		EError,
		/** The command could not be rolled back successfully */
		ERollbackFailed,
		/** The command failed because the setting is being used by another client */
		EObjectInUse,
		/** The command failed because no memory could be allocated */
		ENoMemory,
		/** The command succesfully committed */
		ECommitOK,
		/** The command rolled back succesfully */
		ERollbackOK,
		/** The commit of command failed */
		ECommitFailed,
		ENotAllowed,
		EAcceptedForProcessing,
		
		EExecSuccess,
		EExecClientError,
		EExecUserCancelled,
		EExecDownloadFailed,
		EExecAltDwnldAuthFail,
		EExecDownFailOOM,
		EExecInstallFailed,
		EExecInstallOOM,
		EExecPkgValidationFail,
		EExecRemoveFailed,
		EExecActivateFailed,
		EExecDeactivateFailed,
		EExecNotImplemented,
		EExecUndefError,
		EExecOperationReject,
		EExecAltDwnldSrvError,
		EExecAltDwnldSrvUnavailable
		
		};

public:
	/**
	The function returns current version of the DDF.
	By asking current DDF versions from adapters DM Module can control
	possible changes in the data structure and send the changed DDF
	description to a management server.
	This function is always called after DDFStructureL.
    @param aVersion DDF version of the adapter. (filled by the adapter)
	@publishedPartner
	@prototype
	*/
	virtual void DDFVersionL( CBufBase& aVersion ) = 0;
	
	/**
	The function for filling the DDF structure of the adapter
	This function is only called once, immediately after the adapter is created.
	@param aDDFObject	Reference to root object. A DM adapter starts filling
						the data structure by calling AddChildObjectL to the root object and
						so describes the DDF of the adapter. 
	@publishedPartner
	@prototype
	*/
	virtual void DDFStructureL( MSmlDmDDFObject& aDDF ) = 0;
	
	/**
	The function creates new leaf objects, or replaces data in existing leaf
	objects. The information about the success of the command should be
	returned by calling SetStatusL function of MSmlDmCallback callback
	interface. This makes it possible to buffer the commands.  However, all
	the status codes for buffered commands must be returned at the latest when
	the adapter's CompleteOutstandingCmdsL() is called.
	@param aURI			URI of the object
	@param aLUID		LUID of the object (if the adapter has earlier returned a
						LUID to the DM Module). For new objects, this is the LUID
						inherited through the parent node.
	@param aObject		Data of the object.
	@param aType		MIME type of the object
	@param aStatusRef	Reference to correct command, i.e. this reference
						must be used when calling the SetStatusL of this command
	@publishedPartner
	@prototype
	*/
	virtual void UpdateLeafObjectL( const TDesC8& aURI, const TDesC8& aLUID,
									const TDesC8& aObject, const TDesC8& aType,
									TInt aStatusRef ) = 0;
		
	/**
	The function creates new leaf objects, or replaces data in existing leaf
	objects, in the case where data is large enough to be streamed. The
	information about the success of the command should be returned by calling
	SetStatusL function of MSmlDmCallback callback interface. This makes it
	possible to buffer the commands.  However, all the status codes for buffered
	commands must be returned at the latest when the CompleteOutstandingCmdsL()
	of adapter is called.
	@param aURI		URI of the object
	@param aLUID		LUID of the object (if the adapter has earlier returned a
						LUID to the DM Module). For new objects, this is the LUID
						inherited through the parent node.
	@param aStream	Data of the object. Adapter should create write stream
						and return, when data is written to stream by DM agent,
						StreamCommittedL() is called by DM engine
	@param aType		MIME type of the object
	@param aStatusRef	Reference to correct command, i.e. this reference
						must be used when calling the SetStatusL of this
						command.
	@publishedPartner
	@prototype
	*/
	virtual void UpdateLeafObjectL( const TDesC8& aURI, const TDesC8& aLUID,
									RWriteStream*& aStream, const TDesC8& aType,
		 							TInt aStatusRef ) = 0;
	
	/**
	The function deletes an object and its child objects. The SetStatusL
	should be used as described in UpdateLeafObjectL()
	@param aURI		URI of the object
	@param aLUID		LUID of the object (if the adapter have earlier returned
						LUID to the DM Module).
	@param aStatusRef	Reference to correct command, i.e. this reference must
						be used when calling the SetStatusL of this command.
	@publishedPartner
	@prototype
	*/
	virtual void DeleteObjectL( const TDesC8& aURI, const TDesC8& aLUID,
								TInt aStatusRef ) = 0;
	
	/**
	The function fetches data of a leaf object. The SetStatusL should be used
	as described in UpdateLeafObjectL(). The data is returned by using the
	SetResultsL function of MSmlCallback callback interface, and may be streamed.
	@param aURI			URI of the object
	@param aLUID			LUID of the object (if the adapter have earlier
							returned LUID to the DM Module).   
	@param aType 			MIME type of the object
	@param aResultsRef	Reference to correct results, i.e. this reference
							must be used when returning the result by calling
							the SetResultsL.
	@param aStatusRef		Reference to correct command, i.e. this reference
							must be used when calling the SetStatusL of this
							command.
	@publishedPartner
	@prototype
	*/
	virtual void FetchLeafObjectL( const TDesC8& aURI, const TDesC8& aLUID,
								   const TDesC8& aType, TInt aResultsRef,
								   TInt aStatusRef ) = 0;
	
	/**
	The function fetches the size of the data of a leaf object. The size is
	in bytes, and must reflect the number of bytes that will be transferred
	when the framework calls FetchLeafObjectL. The SetStatusL should be used
	as described in FetchLeafObjectL(). The size value is returned by using
	the SetResultsL function of MSmlCallback callback interface, and must be
	a decimal integer expressed as a string, eg. "1234".
	Results from this call MUST NOT be streamed.
	@param aURI			URI of the object
	@param aLUID			LUID of the object (if the adapter have earlier
							returned LUID to the DM Module).   
	@param aType 			MIME type of the object
	@param aResultsRef	Reference to correct results, i.e. this reference
							must be used when returning the result by calling
							the SetResultsL.
	@param aStatusRef		Reference to correct command, i.e. this reference
							must be used when calling the SetStatusL of this
							command.
	@publishedPartner
	@prototype
	*/
	virtual void FetchLeafObjectSizeL( const TDesC8& aURI, const TDesC8& aLUID,
									   const TDesC8& aType, TInt aResultsRef,
									   TInt aStatusRef ) = 0;
	/**
	The function fetches URI list. An adapter returns the list of URI segments
	under the given URI be separated by slash ("/"). The URI segment names for
	new objects must be given by the adapter.
	The list is returned by calling the SetResultsL function of MSmlCallback
	callback interface.	Results from this call MUST NOT be streamed.
	@param aParentURI					URI of the parent object
	@param aParentLUID				LUID of the parent object (if the
										adapter have earlier returned LUID to
										the DM Module).   
	@param aPreviousURISegmentList	URI list with mapping LUID information,
										which is known by DM engine. An adapter
										can use this information when verifying
										if old objects still exists. An adapter
										also knows what objects are new to DM
										engine and can provide LUID mapping for
										them. aPreviousURISegmentList parameter
										(see above) helps to recognise new
										objects.
	@param aResultsRef				Reference to correct results, i.e. this
										reference must be used when returning
										the result by calling the SetResultsL.
	@param aStatusRef					Reference to correct command, i.e. this
										reference must be used when calling the
										SetStatusL of this command.
	@publishedPartner
	@prototype
	*/
	virtual void ChildURIListL( const TDesC8& aURI, const TDesC8& aLUID,
					const CArrayFix<TSmlDmMappingInfo>& aPreviousURISegmentList,
					TInt aResultsRef, TInt aStatusRef ) = 0;
	
	/**
	The function adds node object. In some cases an implementation of the
	function may be empty function, if the node object does not need concrete
	database update. Still this function may be helpful to an adapter, i.e. in
	passing mapping LUID of the node to DM Module. The SetStatusL should be
	used as described in UpdateLeafObjectL()
	@param aURI			URI of the object
	@param aParentLUID	LUID of the parent object (if the adapter have
							earlier returned LUID to the DM Module).   
	@param aStatusRef		Reference to correct command, i.e. this reference
							must be used when calling the SetStatusL of this
							command.
	@publishedPartner
	@prototype
	*/
	virtual void AddNodeObjectL( const TDesC8& aURI, const TDesC8& aParentLUID,
								 TInt aStatusRef )=0;

	/**
	The function implements execute command. The information about the success
	of the command should be returned by calling SetStatusL function of
	MSmlDmCallback callback interface. This makes it possible to buffer the
	commands.
	However, all the status codes for buffered commands must be returned at
	the latest when the CompleteOutstandingCmdsL() of adapter is called.
	@param aURI			URI of the command
	@param aLUID			LUID of the object (if the adapter have earlier
							returned LUID to the DM Module).   
	@param aArgument		Argument for the command
	@param aType			MIME type of the object 
	@param aStatusRef		Reference to correct command, i.e. this reference
							must be used when calling the SetStatusL of this
							command.
	@publishedPartner
	@prototype
	*/
	virtual void ExecuteCommandL( const TDesC8& aURI, const TDesC8& aLUID,
							      const TDesC8& aArgument, const TDesC8& aType,
								  TInt aStatusRef ) = 0;

	/**
	The function implements execute command. The information about the
	success of the command should be returned by calling SetStatusL function
	of MSmlDmCallback callback interface. This makes it possible to buffer the
	commands.
	However, all the status codes for buffered commands must be returned at
	the latest when the CompleteOutstandingCmdsL() of adapter is called.
	@param aURI			URI of the command
	@param aLUID			LUID of the object (if the adapter have earlier
							returned LUID to the DM Module).   
	@param aStream		Argument for the command. Adapter should create
							write stream and return, when data is written to
							stream by DM agent, StreamCommittedL() is called by
							DM engine
	@param aType			MIME type of the object 
	@param aStatusRef		Reference to correct command, i.e. this reference
							must be used when calling the SetStatusL of this
							command.
	@publishedPartner
	@prototype
	*/
	virtual void ExecuteCommandL( const TDesC8& aURI, const TDesC8& aLUID,
								  RWriteStream*& aStream, const TDesC8& aType,
								  TInt aStatusRef ) = 0;

	/**
	The function implements copy command. The information about the success of
	the command should be returned by calling SetStatusL function of
	MSmlDmCallback callback interface. This makes it possible to buffer the
	commands.
	However, all the status codes for buffered commands must be returned at
	the latest when the CompleteOutstandingCmdsL() of adapter is called.
	@param aTargetURI		Target URI for the command
	@param aSourceLUID	LUID of the target object (if one exists, and if the adapter
							has	earlier returned a LUID to the DM Module).   
	@param aSourceURI		Source URI for the command
	@param aSourceLUID	LUID of the source object (if the adapter has
							earlier returned a LUID to the DM Module).   
	@param aType			MIME type of the objects
	@param aStatusRef		Reference to correct command, i.e. this reference
							must be used when calling the SetStatusL of this
							command.
	@publishedPartner
	@prototype
	*/
	virtual void CopyCommandL( const TDesC8& aTargetURI, const TDesC8& aTargetLUID,
							   const TDesC8& aSourceURI, const TDesC8& aSourceLUID,
							   const TDesC8& aType, TInt aStatusRef ) = 0;

	/**
	The function indicates start of Atomic command.
	@publishedPartner
	@prototype
	*/
	virtual void StartAtomicL() = 0;
	
	/**
	The function indicates successful end of Atomic command. The adapter
	should commit all changes issued between StartAtomicL() and
	CommitAtomicL()
	@publishedPartner
	@prototype
	*/
	virtual void CommitAtomicL() = 0;
	
	/**
	The function indicates unsuccessful end of Atomic command. The adapter
	should rollback all changes issued between StartAtomicL() and
	RollbackAtomicL(). If rollback fails for a command, adapter should use
	SetStatusL() to indicate it.
	@publishedPartner
	@prototype
	*/
	virtual void RollbackAtomicL() = 0;
	
	/**
    Returns ETrue if adapter supports streaming otherwise EFalse.
	@param aItemSize size limit for stream usage
    @return TBool ETrue for streaming support
	@publishedPartner
	@prototype
    */
	virtual TBool StreamingSupport( TInt& aItemSize ) = 0;
	
	/**
    Called when stream returned from UpdateLeafObjectL or ExecuteCommandL has
	been written to and committed. Not called when fetching item.
	@publishedPartner
	@prototype
    */	
	virtual void StreamCommittedL() = 0;
	
	/**
	The function tells the adapter that all the commands of the message that
	can be passed to the adapter have now been passed.  This indciates that
	the adapter must supply status codes and results to any buffered commands.
	This must be done at latest by the time this function returns.
	This function is used at the end of SyncML messages, and during processing
	of Atomic.   In the case of Atomic processing, the function will be
	followed by a call to CommitAtomicL or RollbackAtomicL.
	@publishedPartner
	@prototype
	*/
	virtual void CompleteOutstandingCmdsL() = 0;
	};


class TSmlDmAccessTypes
/**
This class sets the access types which are allowed for a DM object.
@publishedPartner
@prototype
*/
	{
public:
	enum 
	/**
	This enumeration describes the possible access types for a DM object
	@publishedPartner
	@prototype
	*/
		{
		/** The DM Command Add is permitted on this DM object */
		EAccessType_Add		= 0x01,
		/** The DM Command Copy is permitted on this DM object */
		EAccessType_Copy	= 0x02,
		/** The DM Command Delete is permitted on this DM object */
		EAccessType_Delete	= 0x04,
		/** The DM Command Exec is permitted on this DM object */
		EAccessType_Exec	= 0x08,
		/** The DM Command Get is permitted on this DM object */
		EAccessType_Get		= 0x10,
		/** The DM Command Replace is permitted on this DM object */
		EAccessType_Replace = 0x20
		};
public:
	inline TSmlDmAccessTypes();
	inline void SetAdd();
	inline void SetCopy();
	inline void SetDelete();
	inline void SetExec();
	inline void SetGet();
	inline void SetReplace();
	inline TUint8 GetACL();
	inline void Reset();
	
private:
	TUint8 iACL;
	};



class CSmlDmAdapter : public CBase, public MSmlDmAdapter
/**
The class CSmlDmAdapter is an ECOM interface for Device Management adapter plugins.
This interface which must be implemented by every DM plugin adapter
@publishedPartner
@prototype
*/

	{
public:
	inline static CSmlDmAdapter* NewL( const TUid& aImplementationUid,
									   MSmlDmCallback& aDmCallback ); 
	inline virtual ~CSmlDmAdapter();

protected:
	inline CSmlDmAdapter(TAny* aEcomArguments);
	inline MSmlDmCallback& Callback();
	
private:
	/** ECOM framework requires this ID in object destructor
	@internalTechnology
	@prototype
	*/
	TUid iDtor_ID_Key;
	
	/** The DM Framework's callback for returning command results and data
	@internalTechnology
	@prototype
	*/
	MSmlDmCallback& iCallback;
	};

class MSmlDmCallback
/**
This class is callback interface which is implemented in DM Module. An
instance is passed by reference as an argument to the CSmlDmAdapter::NewL()
function. This interface is mostly used for returning results and status
codes for completed commands to the DM framework. The interface also has
functionality for mapping LUIDs and fetching from other parts of the DM Tree.
The adapter does not necessarily need to use any other functions but the
SetStatusL and SetResultsL, if it handles the LUID mapping itself.
@publishedPartner
@prototype
*/
	{
	public:
	/**
	The function is used to return the data in case of FetchLeafObjectL(),
	FetchLeafObjectSizeL() and ChildURIListL() functions. It should not be
	called where the DM command has failed, i.e. the error code returned in
	SetStatusL is something other than EOk.
	@param aResultsRef	Reference to correct command
	@param aObject		The data which should be returned
	@param aType			MIME type of the object
	@publishedPartner
	@prototype
	*/
	virtual void SetResultsL( TInt aResultsRef, CBufBase& aObject,
							  const TDesC8& aType ) = 0;
	
	/**
	The function is used to return the data in case of FetchLeafObjectL() and
	ChildURIListL() functions, where the size of the data being returned is
	large enough for the Adapter to stream it. This function should not be
	called when command was failed, i.e. the error code returned in SetStatusL
	is something other than EOk.
	@param aResultsRef	Reference to correct command
	@param aStream		Large data which should be returned, DM engine
							closes stream when it has read all the data
	@param aType			MIME type of the object
	@publishedPartner
	@prototype
	*/
	virtual void SetResultsL( TInt aResultsRef, RReadStream*& aStream,
							  const TDesC8& aType ) = 0;

	/**
	The function returns information about the Add,Update,Delete and Fetch
	commands success to DM engine. The reference to correct command must be
	used when calling the SetStatusL function, the reference is got from the
	argument of the command functions. The SetStatusL function must be called
	separately for every single command.
	@param aStatusRef	Reference to correct command
	@param aErrorCode	Information about the command success
	@publishedPartner
	@prototype
	*/
	virtual void SetStatusL( TInt aStatusRef,
							 MSmlDmAdapter::TError aErrorCode ) = 0;

	/**
	The function passes map information to DM Module. This function is called
	for a new management object, both for node objects and for leaf objects.
	In addition if ChildURIListL() function has returned new objects a mapping
	information of the new objects must be passed. A mapping is treated as
	inheritable. If the mapping is not set with this function, the mapping
	LUID of the parent object is passed in following commands to the object.
	@param aURI	URI of the object. 
	@param aLUID	LUID of the object. LUID must contain the all information,
					which is needed for retrieve the invidual object from the
					database. Typically it is ID for the database table. In
					more complicated structures it can be combination of IDs,
					which represent path to the object.
	@publishedPartner
	@prototype
	*/
	virtual void SetMappingL( const TDesC8& aURI, const TDesC8& aLUID ) = 0;

	/**
	The function is used to make a fetch to other adapters. The most common
	use is to make a fetch to the AP adapter, because when managing the access
	points, the data comes as URI. For example, there are ToNAPId field in
	some adapters, and data to it can be something like AP/IAPidx, and then
	the link to AP adapter is needed.
	Using FetchLinkL causes the DM Framework to make a Get request to the
	appropriate DM adapter.  The receiving adapter MUST complete the Get
	request synchronously.
	@param aURI		URI of the object. 
	@param aData		Reference to data, i.e. data is returned here
	@param aStatus	The status of fetch command is returned here
	@publishedPartner
	@prototype
	*/
	virtual void FetchLinkL( const TDesC8& aURI, CBufBase& aData,
							 MSmlDmAdapter::TError& aStatus ) = 0;

	/**
	The function returns the LUID which is mapped to aURI. If LUID is not
	found, the function allocates a null length string, i.e. the function
	allocates memory in every case.
	@param aURI	URI of the object. 
	@publishedPartner
	@prototype
	*/
	virtual HBufC8* GetLuidAllocL( const TDesC8& aURI ) = 0;
	
	/**
	The function is used to remove a mapped URI. Returns the error code about mapping removal.
	@param aAdapterId	Settings Adapter id
	@param aURI                 Mapped Uri
	@param aChildAlso          Indicates the child nodes removal
	@publishedPartner
	@prototype
	*/
	virtual TInt RemoveMappingL( TUint32 aAdapterId, const TDesC8& aURI, TBool aChildAlso ) = 0;
	};


class MSmlDmDDFObject 
/**
This class structure includes DDF description. When used as an argument in DM
Adapters Interface each adapter fills its own branch of DDF Tree to the data
structure. 
@publishedPartner
@prototype
*/
	{
	public:

	enum TDFFormat
	/**
	The possible formats of a node.
	@publishedPartner
	@prototype
	*/
		{
		/** Base64 encoded */
		EB64,
		/** Boolean */
		EBool,
		/** Character data */
		EChr,
		/** Integer */
		EInt,
		/** A DM Tree interior node */
		ENode,
		/** No data */
		ENull,
		/** XML character data*/
		EXml,
		/** Binary data */
		EBin,
        /** Date data */     
		EDate,
		/** Time data */
		ETime,
		/** Float */ 
		EFloat
		};

	enum TOccurence
	/**
	The possible occurrences of a node.
	@publishedPartner
	@prototype
	*/
		{
		/** The node appears exactly once */
		EOne,
		/** The node is optional and may appear zero or once */
		EZeroOrOne,
		/** The node is optional and may appear zero or more times */
		EZeroOrMore,
		/** The node is mandatory and may appear once or more times */
		EOneOrMore,
		/** The node is optional and may appear between once and 'N' times */
		EZeroOrN,
		/** The node is mandatory and may appear between once and 'N' times */
		EOneOrN
		};

	enum TScope
	/**
	The possible scopes of a node.
	@publishedPartner
	@prototype
	*/
		{
		/** The node is permanent in the DM Tree */
		EPermanent,
		/** The node is created at run-time in the DM Tree */
		EDynamic
		};

	/**
	The function sets permitted access types property to the object. Access
	types property is a mandatory element. If this function is not called all
	accesses are denied.
	@param aAccessTypes	Access types property.
	@publishedPartner
	@prototype
	*/
	virtual void SetAccessTypesL( TSmlDmAccessTypes aAccessTypes )=0;

	/**
	The function sets a default value property to the object. Default value
	is not a mandatory element. If this function is not called, it means that
	the default value property is not set at all.
	@param aDefaultValue	Default value property.
	@publishedPartner
	@prototype
	*/
	virtual void SetDefaultValueL( const TDesC8& aDefaultValue )=0; 

	/**
	The function sets a description property to the object. Description is
	not a mandatory element. If this function is not called, it means that the
	description property value is not set at all. 
	@param aDescription	Description property.
	@publishedPartner
	@prototype
	*/
	virtual void SetDescriptionL( const TDesC8& aDescription )=0;

	/**
	The function sets a format property to the object. Format is a mandatory
	element. If this function is not called for node element, Format is set as
	'node'. For leaf elements this function must be called.
	@param aFormat	Format property.
	@publishedPartner
	@prototype
	*/
	virtual void SetDFFormatL( TDFFormat aFormat )= 0;

	/**
	The function sets an occurence property to the object.  If this function
	is not called, an occurence is set as TOccurence::EOne. 
	@param aOccurence	Occurence property.
	@publishedPartner
	@prototype
	*/
	virtual void SetOccurenceL( TOccurence aOccurence ) =0;

	/**
	The function sets a scope property to the object.  If this function is not
	called, the scope is set as TScope::EDynamic. 
	@param aScope	Scope property.
	@publishedPartner
	@prototype
	*/
	virtual void SetScopeL( TScope aScope ) = 0;

	/**
	The function sets a title property to the object. Title is not a mandatory
	element. If this function is not called, it means that a Title property
	value is not set at all. 
	@param aTitle	DFTitle property.
	@publishedPartner
	@prototype
	*/
	virtual void SetDFTitleL( const TDesC8& aTitle ) = 0;

	/**
	The function sets a MIME type property to the object. MIME Type is a
	mandatory element for leaf objects. If this function is not called (for
	node elements), it means that the MIME type property value is not set at
	all.
	@param aMimeType	MIME type property.
	@publishedPartner
	@prototype
	*/
	virtual void AddDFTypeMimeTypeL( const TDesC8& aMimeType ) = 0;

	/**
	The function sets an object as an object group. If this function is not
	called, it means that the object is not an object group. Object group is a
	term used with for the node in the management tree that is used as a
	container for other object groups, container for management objects or a
	container for both object groups and management objects. The term 'object
	group' is not used when talked about the nodes which are part of
	the management object itself.
	@publishedPartner
	@withdrawn - This is not supported.  MSmlDmDDFObject::AddChildObjectGroupL
	*			   must be used instead of AddChildObjectL,SetAsObjectGroup.
	*/
	virtual void SetAsObjectGroup() = 0;

	/**
	The function adds a child object and sets name of the URI segment, which
	is used by the DM server. The highest object must be directly under root.
	An adapter is not able to set properties of the root object. The aNodeName
	argument should be an empty string, when the name is not fixed in DDF,
	i.e. in case of dynamic nodes.
	@param aNodeName	The name of the node
	@publishedPartner
	@prototype
	*/
	virtual MSmlDmDDFObject& AddChildObjectL(const TDesC8& aNodeName) = 0;

	/**
	The function adds a child object, to be used as an object group. As an
	object group, there is no node name (these nodes are 'unnamed' in the DDF).
	Object group is a term used with for nodes in the management tree that are
	used as a container for other object groups, container for management
	objects or a container for both object groups and management objects. The
	term 'object group' is not used when referring to nodes which are part
	of the management object itself.
	@publishedPartner
	@prototype
	*/
	virtual MSmlDmDDFObject& AddChildObjectGroupL() = 0;
	};

#include "smldmadapter.inl"

#endif // __SMLDMADAPTER_H__