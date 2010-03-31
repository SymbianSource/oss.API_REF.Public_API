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
//

#ifndef __SYMBIANELFDEFS_H__
#define __SYMBIANELFDEFS_H__

#include <elfdefs.h>

/**
@file
@publishedPartner 
@released

Symbian Core Dump specific ELF definitions. 

The definitions in this file implement the interface described in document
SGL_TS0028_027_symbian_core_dump_file_format.doc. 

@see CSymbianElfFormatter
*/

/** Definition of 64 bit memory */
typedef unsigned long long Elf64_Word;

/** Definition of 8 bit memory */
typedef unsigned char Elf32_Byte;



/**
Value of the d_type field of the standard descriptor header. 
*/
typedef enum
{
	/**  Value to identify Sym32_syminfod */
	ESYM_NOTE_SYM	= 0x00000000,

	/**  Value to identify Sym32_thrdinfod */
	ESYM_NOTE_THRD	= 0x00000010,

	/** Value to identify Sym32_procinfod */
	ESYM_NOTE_PROC	= 0x00000020,

	/** Value to identify Sym32_execinfod */
	ESYM_NOTE_EXEC	= 0x00000040,

	/** Value to identify Sym32_reginfod */
	ESYM_NOTE_REG	= 0x00000080,

	/** Value to identify string information */
	ESYM_NOTE_STR	= 0x00000100

} ESYM_NOTE_TYPE;


/**
To uniquely identify executables associated with the crashed process an executable 
identifier is required, this identifier is defined as follows
*/
typedef struct
{
	/** ID of the executable to match symbolic debug information to executable binary 
	[Currently crash time iTimeLo (LSW) and iTimeHi (MSW)] */
	Elf64_Word		exec_id;

	/** CCITT CRC-32 Checksum of up to the first 1Kbytes of code segment. */
	Elf32_Word		exec_crc;

	/** @internalTechnology */
    Elf32_Word		exec_spare;
} Sym32_execid;

/** Size of Sym32_execid in bytes. @see Sym32_execid */
#define SYM32_EXECID_SIZE	16

/**
The Symbian Info segment contains generic crash information. 
It is defined as a program segment with type PT_NOTE which 
references the segment descriptor Sym32_dhdr.
The d_name field of the standard descriptor header is "CORE.SYMBIAN".
The d_type field of the standard descriptor header is ESYM_NOTE_SYM.
*/
typedef struct
{
	/** Date and time of the crash */
	Elf64_Word		sd_date_time;

	/** The ID of the crashed process as defined by Sym32_execid */
	Sym32_execid	sd_execid;

	/** The id of the thread causing the crash */
	Elf64_Word		sd_thread_id;

	/** The crashing threads owning process */
	Elf64_Word		sd_proc_id;

	/** Identifies whether the crash was caused by a Hardware Exception (set to 0) 
	or Thread Kill (set to 1) */
	Elf32_Word		sd_exit_type;

	/** If sd_exit_type is Hardware Exception then set to e32const.h::TExcType 
	if is Thread Kill then set to e32const.h::TExitType */
	Elf32_Word		sd_exit_reason;

	/** Only set if sd_exit_type is Thread Kill. Index into the CORE.SYMBIAN.STR 
	note segment identifying the reason for the crash or ESYM_STR_UNDEF */
	Elf32_Word		sd_exit_cat;

	/** @internalTechnology */
    Elf32_Word		sd_spare;
} Sym32_syminfod;

/** Size of Sym32_syminfod in bytes. @see Sym32_syminfod */
#define SYM32_SYMINFO_SIZE	56

/**
 The descriptor contents immediately follow the header. 
 To obtain the nth segment: nth segment offset = 
 (Elf32_Phdr) element -> p_offset + sizeof(Sym32_dhdr) + n * d_descrsz
 */
typedef struct {
	/** Index into the CORE.SYMBIAN.STR note segment defining the name of 
	the descriptor or ESYM_STR_UNDEF */
	Elf32_Word	d_name;

	/** Size of a single descriptor element */
	Elf32_Word	d_descrsz;	

	/** Type of the descriptor defined */
	Elf32_Word	d_type;		

	/** Index into the CORE.SYMBIAN.STR note segment defining the version 
	of the following segment descriptor */
	Elf32_Word	d_version;	

	/** Number of descriptor elements */
	Elf32_Word	d_elemnum;	
} Sym32_dhdr;

/** Size of Sym32_dhdr in bytes. @see Sym32_dhdr */
#define SYM32_DESCHDR_SIZE	20

/**
The Thread Info segment contains thread related information for one or more 
threads of the owning process. 
It is defined as a program segment with type PT_NOTE referencing the segment 
descriptor defined below.
The d_name field of the standard descriptor header is "CORE.SYMBIAN.THREAD".
The d_type field of the standard descriptor header is ESYM_NOTE_THRD.
*/
typedef struct {
	/** Id of the thread */
	Elf64_Word	td_id;

	/** Id of the owning process */
	Elf64_Word	td_owning_process;

	/** Index into the CORE.SYMBIAN.STR note segment defining the name of the 
	thread or ESYM_STR_UNDEF */
	Elf32_Word	td_name;

	/** Priority of thread */
	Elf32_Word	td_priority;
	/** Supervisor stack pointer */
	Elf32_Word	td_svc_sp;

	/** Address of the supervisor stack */
	Elf32_Word	td_svc_stack;

	/** Size of the supervisor stack */
	Elf32_Word	td_svc_stacksz;

	/** Address of the user stack */
	Elf32_Word	td_usr_stack; 

	/** Size of the user stack */
	Elf32_Word	td_usr_stacksz;

	/** @internalTechnology */
	Elf32_Word	td_spare;
} Sym32_thrdinfod;

/** Size of Sym32_thrdinfod in bytes. @see Sym32_thrdinfod */
#define SYM32_THRINFO_SIZE	48

/**
The Process Info segment contains process related information for the 
crashed threads owning process. It is defined as a program segment with 
type PT_NOTE referencing the segment descriptor defined below.
The d_name field of the standard descriptor header is "CORE.SYMBIAN.PROCESS".
The d_type field of the standard descriptor header is ESYM_NOTE_PROC.
*/
typedef struct {
	/** ID of the process */
	Elf64_Word	pd_id;

	/** Index into the CORE.SYMBIAN.STR note segment defining the 
	name of the Process or ESYM_STR_UNDEF */
	Elf32_Word	pd_name;

	/** Priority of the process */
	Elf32_Word	pd_priority;

} Sym32_procinfod;

/** Size of Sym32_procinfod in bytes. @see Sym32_procinfod */
#define SYM32_PROCINFO_SIZE	16


/**
The Executable Info segment contains information defining the location of the given executables image segments in the processes address space; this includes statically and dynamically linked executables also. It is defined as a program segment with type PT_NOTE referencing the segment descriptor defined below.
The d_name field of the standard descriptor header is "CORE.SYMBIAN.EXECUTABLE".
The d_type field of the standard descriptor header is ESYM_NOTE_EXEC.
*/
typedef struct {
	/** The ID of the executable as defined by Sym32_execid */
	Sym32_execid	ed_execid;

	/** Index into the CORE.SYMBIAN.STR note segment defining the name of 
	the executable or ESYM_STR_UNDEF */
	Elf32_Word		ed_name;

	/** Execute in place TRUE (1) for XIP ROM code FALSE (0) otherwise */
	Elf32_Word		ed_XIP;

	/** Size of the executables code segment */
	Elf32_Word		ed_codesize;

	/** Execution address of the code segment */
	Elf32_Word		ed_coderunaddr;

	/** Build address of the code section (Non XIP only) */
	Elf32_Word		ed_codeloadaddr;

	/** Size of the executable rodata segment */
	Elf32_Word		ed_rodatasize;

	/** Execution address of the rodata segment */
	Elf32_Word		ed_rodatarunaddr;

	/** Build address of the rodata section (Non XIP only) */
	Elf32_Word		ed_rodataloadaddr;

	/** Size of the executable data segment */
	Elf32_Word		ed_datasize;

	/** Execution address of the data segment */
	Elf32_Word		ed_datarunaddr;

	/** Build address of the data section (Non XIP only) */
	Elf32_Word		ed_dataloadaddr;

	/** @internalTechnology */
	Elf32_Word		ed_spare;
} Sym32_execinfod;

/** Size of Sym32_execinfod in bytes. @see Sym32_execinfod */
#define SYM32_EXECINFO_SIZE	64


/**
The register descriptor member Sym32_reginfod::rid_class is defined by this enumeration.
@see Sym32_reginfod.
*/
typedef enum 
{
	/** Core processor register */
	ESYM_REG_CORE = 0, 	
	/** Coprocessor register */
	ESYM_REG_COPRO = 1	
} ESYM_REGCLASS;	

/**
The register descriptor member Sym32_reginfod::rid_repre is defined by this enumeration.
@see Sym32_reginfod
*/
typedef enum
{
	/** 8 Bit register contents */
	ESYM_REG_8	= 0,	
	/** 16 Bit register contents */
	ESYM_REG_16	= 1,	
	/** 32 Bit register contents */
	ESYM_REG_32	= 2,	
	/** 64 Bit register contents */
	ESYM_REG_64	= 3		
} ESYM_REGREP;


/**
The Register Info segment contains a register context for a given thread. The core dump file may include zero or more register contexts for one or more threads within the owning process. It is defined as a program segment with type PT_NOTE referencing the segment descriptor defined below.
The d_name field of the standard descriptor header is "CORE.SYMBIAN.REGISTER.<THREADID>".
The d_type field of the standard descriptor header is ESYM_NOTE_REG.
*/
typedef struct {
	/** Thread which context relates to */
	Elf64_Word	rid_thread_id;

	/** Index into the CORE.SYMBIAN.STR note segment defining the version of 
	the Register Data Info descriptor */
	Elf32_Word	rid_version;

	/** Number of registers this descriptor defines */
	Elf32_Half	rid_num_registers;

	/** Register class defined by ESYM_REGCLASS */
	Elf32_Byte	rid_class;

	/** Register representation defined by ESYM_REGREP */
	Elf32_Byte	rid_repre;

} Sym32_reginfod;

/** Size of Sym32_reginfod in bytes. @see Sym32_reginfod */
#define SYM32_REGINFO_SIZE	16


/**
Immediately following the Register Info descriptor header is the information describing 
the individual registers. See document for register identifiers. 
The register identification scheme is the same as that used by the run mode debug interface.
*/
typedef struct {	
	/** Register ID */
	Elf32_Half	rd_id;

	/**  Sub register ID */
	Elf32_Half	rd_sub_id;

	/** Offset in bytes from the beginning of the file to the register data */
	Elf32_Word	rd_data; 
} Sym32_regdatad;

/** Size of Sym32_regdatad in bytes. @see Sym32_regdatad */
#define SYM32_REGDATA_SIZE	8


/** Program header member p_flags indicating that the segment may be executed. */
#define PF_X 1

/** Program header member p_flags indicating that the segment may be written to. */
#define PF_W 2

/** Program header member p_flags indicating that the segment may be read from. */
#define PF_R 4 


/**
Index to the NULL string, ie string is not defined.
*/
#define ESYM_STR_UNDEF 0

#endif

