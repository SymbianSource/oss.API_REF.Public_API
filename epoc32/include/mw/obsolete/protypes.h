/*
* ==============================================================================
*  Name        : protypes.h
*  Part of     : Webkit \ Plugin
*  Interface   : 
*  Description :
*  Version     : 3.1
*
*    The Original Code is from the Netscape Portable Runtime (NSPR).
*
*    Portions Copyright (c) 1998-2000, Netscape Communications Corporation
*    Portions Copyright (c) 2004-2006, Nokia Corporation
*    All rights reserved.
*  
*  	Redistribution and use in source and binary forms, with or without
*  	modification, are permitted provided that the following conditions
*  	are met:
*  
*      * Redistributions of source code must retain the above copyright
*        notice, this list of conditions and the following disclaimer.
*      * Redistributions in binary form must reproduce the above copyright
*        notice, this list of conditions and the following disclaimer in
*        the documentation and/or other materials provided with the
*        distribution.
*      * Neither the name of the Nokia Corporation nor the names of its
*        contributors may be used to endorse or promote products derived
*        from this software without specific prior written permission.
*  
*  	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  	"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  	LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  	A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
*  	OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
*  	SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
*  	LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  	DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  	THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
*  	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
*  	USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
*  	DAMAGE.
*  
*
* ==============================================================================
*/

/*
* NOTE:
* Nokia modified this file, originated from Netscape Communications Corporation,
* by changing certain variables for the purpose of porting the file to the
* Symbian platform on May 1st, 2004. As noted in the original license block
* provided for this file, we are using the alternatively acceptable license,
* LGPL. We have added our LGPL license to this file in accordance to the 
* license, and added the copyrights that where previously attached to this
* file. A copy of the original license is included in this directory,
* see MPL_GPL_LGPL.txt or http://www.mozilla.org/MPL/.
*/


#if !defined(PROTYPES_H)
#define PROTYPES_H

typedef PRUintn uintn;
#ifndef _XP_Core_
typedef PRIntn intn;
#endif

/*
 * It is trickier to define uint, int8, uint8, int16, uint16,
 * int32, uint32, int64, and uint64 because some of these int
 * types are defined by standard header files on some platforms.
 * Our strategy here is to include all such standard headers
 * first, and then define these int types only if they are not
 * defined by those standard headers.
 */

/*
 * BeOS defines all the int types below in its standard header
 * file SupportDefs.h.
 */
#ifdef XP_BEOS
#include <support/SupportDefs.h>
#endif

/*
 * OpenVMS defines all the int types below in its standard
 * header files ints.h and types.h.
 */
#ifdef VMS
#include <ints.h>
#include <types.h>
#endif

/*
 * SVR4 typedef of uint is commonly found on UNIX machines.
 *
 * On AIX 4.3, sys/inttypes.h (which is included by sys/types.h)
 * defines the types int8, int16, int32, and int64.
 */
#ifdef XP_UNIX
#include <sys/types.h>
#endif

/* model.h on HP-UX defines int8, int16, and int32. */
#ifdef HPUX
#include <model.h>
#endif

/*
 * uint
 */

#if !defined(XP_BEOS) && !defined(VMS) \
    && !defined(XP_UNIX) || defined(NTO)
typedef PRUintn uint;
#endif

/*
 * uint64
 */

#if !defined(XP_BEOS) && !defined(VMS)
typedef PRUint64 uint64;
#endif

/*
 * uint32
 */

#if !defined(XP_BEOS) && !defined(VMS)
#if !defined(XP_MAC) && !defined(_WIN32) && !defined(XP_OS2) && !defined(NTO)  && !defined(__SYMBIAN32__)
typedef PRUint32 uint32;
#else
typedef unsigned long uint32;
#endif
#endif

/*
 * uint16
 */

#if !defined(XP_BEOS) && !defined(VMS)
typedef PRUint16 uint16;
#endif

/*
 * uint8
 */

#if !defined(XP_BEOS) && !defined(VMS)
typedef PRUint8 uint8;
#endif

/*
 * int64
 */

#if !defined(XP_BEOS) && !defined(VMS) \
    && !defined(_PR_AIX_HAVE_BSD_INT_TYPES)
typedef PRInt64 int64;
#endif

/*
 * int32
 */

#if !defined(XP_BEOS) && !defined(VMS) \
    && !defined(_PR_AIX_HAVE_BSD_INT_TYPES) \
    && !defined(HPUX)
#if !defined(WIN32) || !defined(_WINSOCK2API_)  /* defines its own "int32" */
#if !defined(XP_MAC) && !defined(_WIN32) && !defined(XP_OS2) && !defined(NTO) && !defined(__SYMBIAN32__)
typedef PRInt32 int32;
#else
typedef long int32;
#endif
#endif
#endif

/*
 * int16
 */

#if !defined(XP_BEOS) && !defined(VMS) \
    && !defined(_PR_AIX_HAVE_BSD_INT_TYPES) \
    && !defined(HPUX)
typedef PRInt16 int16;
#endif

/*
 * int8
 */

#if !defined(XP_BEOS) && !defined(VMS) \
    && !defined(_PR_AIX_HAVE_BSD_INT_TYPES) \
    && !defined(HPUX)
typedef PRInt8 int8;
#endif

typedef PRFloat64 float64;
typedef PRUptrdiff uptrdiff_t;
typedef PRUword uprword_t;
typedef PRWord prword_t;


/* Re: prbit.h */
#define TEST_BIT	PR_TEST_BIT
#define SET_BIT		PR_SET_BIT
#define CLEAR_BIT	PR_CLEAR_BIT

/* Re: prarena.h->plarena.h */
#define PRArena PLArena
#define PRArenaPool PLArenaPool
#define PRArenaStats PLArenaStats
#define PR_ARENA_ALIGN PL_ARENA_ALIGN
#define PR_INIT_ARENA_POOL PL_INIT_ARENA_POOL
#define PR_ARENA_ALLOCATE PL_ARENA_ALLOCATE
#define PR_ARENA_GROW PL_ARENA_GROW
#define PR_ARENA_MARK PL_ARENA_MARK
#define PR_CLEAR_UNUSED PL_CLEAR_UNUSED
#define PR_CLEAR_ARENA PL_CLEAR_ARENA
#define PR_ARENA_RELEASE PL_ARENA_RELEASE
#define PR_COUNT_ARENA PL_COUNT_ARENA
#define PR_ARENA_DESTROY PL_ARENA_DESTROY
#define PR_InitArenaPool PL_InitArenaPool
#define PR_FreeArenaPool PL_FreeArenaPool
#define PR_FinishArenaPool PL_FinishArenaPool
#define PR_CompactArenaPool PL_CompactArenaPool
#define PR_ArenaFinish PL_ArenaFinish
#define PR_ArenaAllocate PL_ArenaAllocate
#define PR_ArenaGrow PL_ArenaGrow
#define PR_ArenaRelease PL_ArenaRelease
#define PR_ArenaCountAllocation PL_ArenaCountAllocation
#define PR_ArenaCountInplaceGrowth PL_ArenaCountInplaceGrowth
#define PR_ArenaCountGrowth PL_ArenaCountGrowth
#define PR_ArenaCountRelease PL_ArenaCountRelease
#define PR_ArenaCountRetract PL_ArenaCountRetract

/* Re: prhash.h->plhash.h */
#define PRHashEntry PLHashEntry
#define PRHashTable PLHashTable
#define PRHashNumber PLHashNumber
#define PRHashFunction PLHashFunction
#define PRHashComparator PLHashComparator
#define PRHashEnumerator PLHashEnumerator
#define PRHashAllocOps PLHashAllocOps
#define PR_NewHashTable PL_NewHashTable
#define PR_HashTableDestroy PL_HashTableDestroy
#define PR_HashTableRawLookup PL_HashTableRawLookup
#define PR_HashTableRawAdd PL_HashTableRawAdd
#define PR_HashTableRawRemove PL_HashTableRawRemove
#define PR_HashTableAdd PL_HashTableAdd
#define PR_HashTableRemove PL_HashTableRemove
#define PR_HashTableEnumerateEntries PL_HashTableEnumerateEntries
#define PR_HashTableLookup PL_HashTableLookup
#define PR_HashTableDump PL_HashTableDump
#define PR_HashString PL_HashString
#define PR_CompareStrings PL_CompareStrings
#define PR_CompareValues PL_CompareValues

#if defined(XP_MAC)
#ifndef TRUE				/* Mac standard is lower case true */
	#define TRUE 1
#endif
#ifndef FALSE				/* Mac standard is lower case false */
	#define FALSE 0
#endif
#endif

#endif /* !defined(PROTYPES_H) */
