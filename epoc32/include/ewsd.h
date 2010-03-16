/*
* Copyright (c) 2006-2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
* which accompanies this distribution, and is available
* at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:
* Name        : ewsd.h
* Part of     : ewsd library
* Contains the declarations of the APIs of the emulator WSD library 
* Redistribution and use in source and binary forms, with or without 
* modification, are permitted provided that the following conditions are met:
* Redistributions of source code must retain the above copyright notice, this 
* list of conditions and the following disclaimer. 
* Redistributions in binary form must reproduce the above copyright notice, 
* this list of conditions and the following disclaimer in the documentation 
* and/or other materials provided with the distribution. 
* Neither the name of the <ORGANIZATION> nor the names of its contributors 
* may be used to endorse or promote products derived from this software 
* without specific prior written permission. 
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/


 
#ifndef __EWSD_H__
#define __EWSD_H__

#ifdef __WINSCW__

/** 
* The following functions should not be used directly.
* Libraries that require to use the emulator WSD library
* should use the Pls() API defined in pls.h
*/

/**  
Finds and returns the PLS (Process Local Storage) object of the specified 
library for the current process, if the object exists.
Takes as a parameter the TUid of the library DLL whose PLS object is to 
be returned for the current process.
Returns a pointer to the PLS object if it exists, otherwise NULL					
*/
IMPORT_C TAny* CheckPls(const TUid& aLibraryUid);

/**  
Sets the PLS object of the specified library, for the current process.
Takes as parameters the PLS object to be set, and the TUid of the library 
DLL whose PLS object it is. 
Returns KErrNone on success, and KErrNoMemory if the PLS object could not
be stored because a size limit of the WSD array has been reached
*/
IMPORT_C TInt SetPls(TAny* aPls, const TUid& aLibraryUid);

/**  
Allocates the specified number of bytes of memory from the emulator's
Virtual Address Space.
Takes as a parameter the number of bytes of memory to allocate.
Returns	a pointer to the allocated memory on success, otherwise NULL
*/
IMPORT_C TAny* AllocatePls(const TInt& aSize);

/**  
Frees the specified memory in the emulator's Virtual Address Space.
Takes as a parameter the PLS object location to be freed.
Returns KErrNone on success, otherwise KErrAccessDenied
*/
IMPORT_C TInt FreePls(TAny* aPls); 

/**  
Gets a handle to the mutex, waits until it obtains ownership of it
and then returns the handle.
Returns a handle to the mutex, of which the caller now has ownership.
Note that the handle is returned as a TAny* (the Windows HANDLE type 
is typedefed to void*)
*/
IMPORT_C TAny* ObtainPlsMutex();

/**  
Releases ownership of the mutex, which allows another thread 
to acquire ownership of it.
Takes as a parameter a handle to the mutex										
*/
IMPORT_C void ReleasePlsMutex(TAny* aMutexHandle);

#endif // __WINSCW__

#endif // __EWSD_H__

