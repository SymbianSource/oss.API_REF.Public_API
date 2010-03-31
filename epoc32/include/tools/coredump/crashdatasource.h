// Copyright (c) 2006-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// Definition of Data Source API that supplies crash information. 
//



/**
 @file
 @publishedPartner 
 @released
*/


#ifndef CRASH_DATA_SOURCE_H
#define CRASH_DATA_SOURCE_H

#include <e32std.h>
#include <e32base.h>

#include <crashdata.h>
#include <processdata.h>
#include <executabledata.h>
#include <threaddata.h>


/**
Definition of the Data Source API. This API is used by formatters to obtain crash data from 
the Core Dump Server. The Core Dump Server derives and implements this API.
*/
class CCrashDataSource : public CBase
{
protected:

	/** Standard second-phase constructor. */
	virtual void ConstructL() = 0;
	
public:
	
	/** 
	This call returns information on all available registers. It does not
	return the register contents. This is used to establish which registers 
	a caller could ask for, in particular for Co Processor registers. 
	The callee (not the caller) allocates aRegisterList. 
	This method is used by a formatter to establish which registers it can ask for, 
	and thus need only be called once per session. 

    @param aRegisterList Returned register list with available registers.

    @see TRegisterData.
	@see RRegisterList.
	*/
	virtual void GetRegisterListL( RRegisterList  &	aRegisterList ) = 0;

	/** 
	Ask the Core Dump server for some register data. The caller allocates
	the array and fills in the details of the registers for which it would like 
	the contents.
	@param aThreadId Thread to read registers from.
	@param aRegisterList Returned register list with current values.

    @see TRegisterData.
	@see GetRegisterListL().
	@see RRegisterList.
	*/
	virtual void ReadRegistersL( const TUint64 aThreadId, RRegisterList &aRegisterList ) = 0;

	/**
 	Read data from target relative to a particular thread. 
	The caller assumes ownership of the resulting data descriptor.
 	
 	@param aThreadId Memory read is relative to this thread parameter
	@param aAddress Virtual address to read from
    @param aLength Number of bytes to read
	@param aData Descriptor for read data
	*/
	virtual void ReadMemoryL(
                   const TUint64    aThreadId,
                   const TUint32    aAddress,
                   const TUint32    aLength,
                   TDes8          & aData ) = 0;


	/**
 	Read the current process list.
	The caller assumes ownership of resulting data.
	@param aData Array of currently running processes . 
	
	@see RProcessPointerList.
	@see CProcessInfo.
	*/
	virtual void GetProcessListL( RProcessPointerList & aData )
		{
		TUint totalProcessListDescSize;
		GetProcessListL( aData, totalProcessListDescSize );
		};

	/**
 	Read the current process list.
	The caller assumes ownership of the resulting data.
	This call is only useful if the total descriptor size required for 
	transferring across the client-server boundary must be known.
	
 	@param aData	Array of currently running processes. 
	@param aTotalProcessListDescSize Total descriptor size required 
	to transfer the list across the client-server interface.

    @see RProcessPointerList.
	@see CProcessInfo.
	*/
	virtual void GetProcessListL( RProcessPointerList & aData, 
						         TUint & aTotalProcessListDescSize ) = 0;


	/**
 	Read the current executable list. The caller assumes ownership of the resulting data.
	@param aData Array of current executables. 

	@see RExecutablePointerList.
	@see CExecutableInfo
	*/
	virtual void GetExecutableListL( RExecutablePointerList & aData )
		{
		TUint totalExecutableListDescSize;
		GetExecutableListL( aData, totalExecutableListDescSize );
		};


	/**
 	Read the current executable list.
	The caller assumes ownership of the resulting data.
	This call is only useful if the total descriptor size required for 
	transferring across the client-server boundary must be known.
	
 	@param aData	Array of current executables. 
	@param aTotalExecutableListDescSize	Total descriptor size required 
	to transfer the list across the client-server interface.

	@see RExecutablePointerList.
	@see CExecutableInfo
	*/
	virtual void GetExecutableListL( RExecutablePointerList & aData, 
						         TUint & aTotalExecutableListDescSize ) = 0;


 	/** 
	Read the current thread list.
	This call is only useful if the total descriptor size required for 
	transferring across the client-server boundary must be known.

	@param aProcessId If this argument is -1, all the threads in the 
	system are returned. Otherwise the threads under the process with the id
	aProcessId are returned.
 	@param aThreadList Array of currently running threads. 
	@param aTotalThreadListDescSize Size in bytes of the descriptor 
	required to transfer the data over the client server interface.

  	@see CThreadInfo
    @see RThreadPointerList.
	@see GetThreadListL
	*/
	virtual void GetThreadListL( const TUint64 aProcessId, 
						RThreadPointerList & aThreadList,
						TUint & aTotalThreadListDescSize ) = 0;

	/**
 	Read the current thread list.
	The caller assumes ownership of the resulting data.
	
	@param aProcessId If this argument is -1, all the threads in the 
	system are returned. Otherwise the threads under the process with the id
	aProcessId are returned.
 	@param aThreadList	Array of currently running threads.
	
	@see CThreadInfo
	@see RThreadPointerList
	*/
  	virtual void GetThreadListL( const TUint64 aProcessId, 
								 RThreadPointerList & aThreadList )
		{
		TUint totalThreadListDescSize;
		GetThreadListL(	aProcessId, aThreadList, totalThreadListDescSize );
		};

    /**
	Obtain a list of the code segments for a process. 
	
	@param aTid Thread identifier to obtain code segments for.
	@param aCodeSegs Array of code segments. 
	@param aTotalCodeSegListDescSize Size in bytes of the descriptor 
	required to transfer the data over the client server interface.

	@see RCodeSegPointerList
	@see TSegmentInfo
	*/
    virtual void GetCodeSegmentsL(const TUint64 aTid, 
									RCodeSegPointerList &aCodeSegs, 
									TUint &aTotalCodeSegListDescSize ) = 0;

    /**
	Obtain a list of the code segments for a process. 

	@param aTid Thread identifier to obtain code segments for.
	@param aCodeSegs Array of code segments. 

	@see RCodeSegPointerList
	@see TSegmentInfo
	*/
    virtual void GetCodeSegmentsL(const TUint64 aTid, RCodeSegPointerList &aCodeSegs)
        {
        TUint totalThreadListDescSize;
        GetCodeSegmentsL(aTid, aCodeSegs, totalThreadListDescSize);
        };

	/** For future expansion
	@internalTechnology */
	TUint32 iSpare1;

	/** @internalTechnology */
	TUint32 iSpare2;
};

#endif // CRASH_DATA_SOURCE_H


