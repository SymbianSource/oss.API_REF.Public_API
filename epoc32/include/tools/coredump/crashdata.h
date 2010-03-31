// Copyright (c) 2007-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// Common Crash Data definitions used between the core dump server, 
// formatters and user interfaces
//



/**
 @file
 @publishedPartner 
 @released
 @see CCrashDataSource
 @see RCoreDumpSession
*/

#ifndef CRASH_DATA_H
#define CRASH_DATA_H

#include <e32std.h>
#include <e32const.h>
#include <rm_debug_api.h>

using namespace Debug;

/**
Crash event information. This is given to a formatter when a crash occurs.
@see CCoreDumpFormatter::CrashEventL()
*/
struct TCrashInfo
{

	/** 
	Type of crash event
	*/
	enum TCrashType 
	{ 
	/** ECrashException is raised when a hardware exception occurs */
	ECrashException, 

	/** ECrashKill is raised when a thread is killed or panicked */
	ECrashKill,

    /** 
	@internalTechnology
	Guard
	*/
    ECrashLast
	};

    /** Type of crash
	@see  TCrashType 
	*/
	TCrashType		iType; 

	/** Exception type or exit type. 
	If crash type iType is ECrashException, this is set to e32const.h::TExcType 
	If crash type iType is ECrashKill, this is set to e32const.h::TExitType.
	*/
    TUint32			iExcNumber;

	/** This is only set when iType is ECrashKill. Kernel panic code. */
	TInt			iReason; 

	/** Crash category description. Valid when crash type is ECrashKill */
    TBuf<KMaxExitCategoryName> iCategory; 

	/** Crashed thread id */
	TUint64			iTid;

	/** Crashed process id */
	TUint64			iPid;

	/** Crash time */
    TUint64			iTime; 

	/** Register context at time of crash. 
	@see TRmdArmExcInfo
	@see Debug::TRmdArmExcInfo
	*/
    TRmdArmExcInfo  iContext;

    /** Reserved for future.
	@internalTechnology */
    TUint32 iSpare1;
	/** @internalTechnology */
    TUint32 iSpare2;
	/** @internalTechnology */
    TUint32 iSpare3;
};

/**
Code segment information. 
@see CServerCrashDataSource::GetCodeSegmentsL()
*/
struct TCodeSegInfo
{

	/**
	Name of code segment. 
	*/
    TBufC<KMaxPath> iName;

	/**
	Set to trie to indicates that this executable is executing in place.
	*/
    TBool		iXIP;


	/**
	Type of the code segment. 
	@see Debug::TCodeSegType
	@see TCodeSegType
	*/
    TCodeSegType iType;

	/**	Code size in bytes	*/
    TUint32		iCodeSize;

	/**	Code segment run address. If code segment is XIP then 
	this is the same as iCodeLoadAddr */
    TLinAddr	iCodeRunAddr;

	/**	Address where code segement was loaded from */
    TLinAddr	iCodeLoadAddr;

	/**	Size on bytes of the read only data */
    TUint32		iRoDataSize;

	/**	Address of read only data at run time. If code segment is XIP then 
	this is the same as iRoDataLoadAddr */
    TLinAddr	iRoDataRunAddr;

	/**	Address where read only data was loaded from */
    TLinAddr	iRoDataLoadAddr;

	/** Writable data size in bytes. Combined .bss and .data sections  */
    TUint32		iDataSize;

	/** Address of writable data at run time */
    TLinAddr	iDataRunAddr;

	/** Build time address of initialised writable data */
    TLinAddr	iDataLoadAddr;

    /** reserved for future 
	@internalTechnology */
    TUint32 iSpare1;
	/** @internalTechnology */
    TUint32 iSpare2;
	/** @internalTechnology */
    TUint32 iSpare3;
};

/**
Pointer array of TCodeSegInfo objects.
@see TCodeSegInfo
*/
typedef RPointerArray<TCodeSegInfo> RCodeSegPointerList;


/**
Detailed information about a register. 
The Symbian ELF format defines the register identification format.
The Debug Security Server implements this format.
@see CCrashDataSource::ReadRegistersL()
*/
class TRegisterData
{

public: 

	IMPORT_C    TUint16		GetId()   const;
	IMPORT_C    TUint16		GetSubId() const;
	IMPORT_C    TUint8		GetSize() const;
	IMPORT_C    TUint8		GetClass() const;
	IMPORT_C    TBool		SameRegister( const TRegisterData & other ) const;
	
	IMPORT_C    TUint8		GetContent8()  const;
	IMPORT_C    TUint16		GetContent16() const;
	IMPORT_C    TUint32		GetContent32() const;
	IMPORT_C    TUint64		GetContent64() const;

	IMPORT_C    void		SetContent8(  const TUint8 aVal );
	IMPORT_C    void		SetContent16( const TUint16 aVal );
	IMPORT_C    void		SetContent32( const TUint32 aVal );
	IMPORT_C    void		SetContent64( const TUint64 aVal );
	IMPORT_C    void		SetContent( const TUint aVal );

	IMPORT_C    void		SetContent( const TRegisterData & other );

	IMPORT_C    TBool		Available( ) const;
	IMPORT_C    void		SetAvailable( const TBool aAvailable );


	/**
	This is the same as symbianelfdefs.h ESYM_REGREP. 
	@see ESYM_REGREP
	*/
	typedef enum TRegisterRepresentation
		{
		/** 8 Bit register */
		ERegRepr8	= 0,	
		/** 16 Bit register */
		ERegRepr16	= 1,
		/** 32 Bit register */
		ERegRepr32	= 2,
		/** 64 Bit register */
		ERegRepr64	= 3,
		/** 
		@internalTechnology
		*/
		ERegReprLast
		};
    
	/**
	This is the same as symbianelfdefs.h ESYM_REGCLASS. 
	@see ESYM_REGCLASS
	*/
	typedef enum TRegisterClass
		{
		/** A Core register */
		ERegClassCore	= 0,	
		/** A Co Processor register */
		ERegClassCoPro	= 1, 
		/** 
		@internalTechnology
		*/
		ERegClassLast
		};


	/**
	Register identifier
	*/
	union 
        {
	    /** Used when calling the Debug Security Server */
        TRegisterInfo regInfo;

        /** Same as Sym32_reginfod::rd_id
	    if rid_class == ESYM_REG_CORE 
	      rd_id is one of rm_debug_api.h::TFunctionalityRegister
	    else 
	      rd_id is CoProcessor number, eg 15 for ARM CP15 

		@see Sym32_reginfod::rd_id
		*/
		TUint16		iId;
        };

	/** Same as Sym32_reginfod::rid_class
		Type of register ESYM_REG_CLASS :{ ESYM_REG_CORE = 0, ESYM_REG_COPRO = 1 } 
	@see Sym32_reginfod::rid_class
	*/
	TUint8		iRegClass;

	/** Same as Sym32_reginfod::rd_sub_id		
		Only used if rid_clas == ESYM_REG_COPRO

  	   Bitfield is made up of the following fields:
         bits 13 to 11  : OpCode2
         bits 10 to 8   : OpCode1
         bits 7  to 4   : CRn
         bits 3  to 0   : CRm 

	@see Sym32_reginfod::rd_sub_id		
	*/
	TUint16		iSubId;

	/** Same as Sym32_reginfod::rd_repre
		{ ESYM_REG_8 == 0, ESYM_REG_16 == 1, ESYM_REG_32 == 2, ESYM_REG_64 == 3 }
		Determines which version of GetContent*() to use 
	@see Sym32_reginfod::rd_repre
	*/
	TUint8		iSize;


	/** True if the content of this register was succesfully obtained from 
	the target */
	TBool       iAvailable;

	/** Register value */
	union
	{
		/** Value of an 8 bit register */
		TUint8		iValue8;

		/** Value of a 16 bit register */
		TUint16		iValue16;

		/** Value of a 32 bit register */
		TUint32		iValue32;

		/** Value of a 64 bit register */
		TUint64		iValue64;
	};

	/** Reserved for future use
	@internalTechnology */
	TUint32 iSpare1;

	/** @internalTechnology */
	TUint32 iSpare2;

	/** @internalTechnology */
	TUint32 iSpare3;
};


/**
@publishedPartner 
@released

List of TRegisterData objects.
@see TRegisterData
@see RArray
*/
typedef RArray<TRegisterData> RRegisterList;


#endif // CRASH_DATA_H


