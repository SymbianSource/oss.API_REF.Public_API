/*
* Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Name        : semaphore.h
* Part of     : semaphore
* Interface   : POSIX, semaphores
* POSIX implementation of semaphores on Symbian
* Version     : 
* All rights reserved.
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



#ifndef __SEMAPHORE_H__
#define __SEMAPHORE_H__

#include <sys/types.h>

#ifdef __cplusplus
extern "C"
{
#endif              /* __cplusplus */

/*Semaphores supported */

#define SEM_FAILED -1
typedef struct _sem_t* sem_t;

/*
This function initializes the semaphore object.
The semaphore count is set to the initial count value. 
*/
IMPORT_C extern int sem_init (sem_t * sem, int pshared, unsigned int value);

/*
This function destroys the semaphore  object. 
*/
IMPORT_C extern int  sem_destroy (sem_t* sem);

/*
This function atomically decrements sem's count if it is greater than 0 and returns immediately,
or it returns immediately with a return code of -1 after having set errno to EAGAIN. 
sem_trywait never blocks.
*/
IMPORT_C extern int sem_trywait (sem_t* sem);

/*
This function atomically decrements sem's count if it is greater than 0 and returns immediately
or it suspends the calling thread until it can resume following a call to sem_post or sem_post_multiple
*/
IMPORT_C extern int sem_wait (sem_t* sem);

/*
This function atomically decrements sem's count if it is greater than 0 and returns immediately, or it 
suspends the calling thread. If timeout time lapses before the thread can be resumed because of a sem_post,
case, then sem_timedwait returns with a return code of -1 after having set errno to ETIMEDOUT. If the 
thread  can return without suspending then abstime parameter is not checked.
*/
IMPORT_C extern int sem_timedwait (sem_t* sem, const struct timespec* abstime);

/*
The function increments (unlocks) the semaphore pointed to by sem .
If there are threads blocked on the semaphore when sem_post is called, the highest priority thread that has been blocked the longest on
the semaphore will be allowed to return from sem_wait .
If successful, the function returns zero; otherwise, it returns -1 and set errno to indicate the error.
*/
IMPORT_C extern int sem_post (sem_t* sem);

/*
This function establish a connection between a named semaphore and a process
*/
/* IMPORT_C extern sem_t* sem_open (const char* name,int oflag,mode_t mode, unsigned int value); */

/*
This function indicate that the calling process is finished using the named semaphore indicated by sem*/
/* IMPORT_C extern int sem_close (sem_t* sem); */

/*
This function cleans up resources associated with a system-wide semaphore.
*/
/* IMPORT_C extern int sem_unlink (const char* name); */

/*
This function updates the location referenced by the sval argument with the value of the semaphore 
referenced by sem without affecting the state of the semaphore. 
The updated value represents an actual semaphore value that occurred at some unspecified time 
during the call, but it need not be the actual value of the semaphore when it is returned to 
the calling process. If sem is locked, then the object to which sval points shall either be set 
to zero or to a negative number whose absolute value represents the number of processes waiting
for the semaphore at some unspecified time during the call.
*/
IMPORT_C extern int sem_getvalue (sem_t* sem, int* sval);


#ifdef __cplusplus
}               /* End of extern "C" */
#endif              /* __cplusplus */

#endif              /* __SEMAPHORE_H__ */
