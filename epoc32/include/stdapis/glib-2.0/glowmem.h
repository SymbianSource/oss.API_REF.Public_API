/*
* Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies). All rights reserved.

* Redistribution and use in source and binary forms, with or without 
* modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this 
* list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice, 
* this list of conditions and the following disclaimer in the documentation 
* and/or other materials provided with the distribution.
* Neither the name of Nokia Corporation nor the names of its contributors 
* may be used to endorse or promote products derived from this software 
* without specific prior written permission.

* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE 
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, 
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
* Description:
*
*/

#ifndef __G_LOW_MEM_H__
#define __G_LOW_MEM_H__
 
#include <unistd.h> 
#include <setjmp.h>

/*-------------------------- Data Structure Decleration ----------------*/
typedef struct _cleanUpStack cleanUpStack ;
typedef struct _mem_info mem_info ;

struct _cleanUpStack
{
	void *ptr[1000];
	int top;
};

struct _mem_info
{
	int is_setjmp_called;
	jmp_buf buf;
	cleanUpStack stack;
};

 
/*--------------------Function declerations------------------*/ 
#ifdef __cplusplus
extern "C"
{
#endif    /* __cplusplus */

IMPORT_C mem_info * _get_thread_specific_data();
IMPORT_C int _set_thread_specific_data(mem_info *m);
IMPORT_C int _push(cleanUpStack *cs,void *ptr);
IMPORT_C void *_pop(cleanUpStack *cs);
IMPORT_C void _findAndDestroy(cleanUpStack *cs,void *ptr);
IMPORT_C void _destroCleanUpStack(cleanUpStack *cs);
IMPORT_C void _clearCleanUpStack(cleanUpStack *cs);
IMPORT_C void * _pAlloc(size_t size);
IMPORT_C void _dummy1();
IMPORT_C void _dummy2();
IMPORT_C void _dummy3();

#ifdef __cplusplus
}
#endif    /* __cplusplus */

/*--------------------MACRO declerations------------------*/

#define SET_LOW_MEMORY_TRAP_VOID()	\
gboolean did_i_set = FALSE;\
{\
	mem_info *m = _get_thread_specific_data();\
	if(m == NULL)\
	{\
		m = (mem_info *)_pAlloc(sizeof(mem_info));\
		if(!m)\
			return;\
		m->is_setjmp_called = FALSE;\
		_clearCleanUpStack(&(m->stack));\
		if(_set_thread_specific_data(m))\
			return;\
	}\
	if(!m->is_setjmp_called)\
	{\
  		if(setjmp(m->buf) > 0)\
  		{\
  			m->is_setjmp_called = FALSE;\
  			_destroCleanUpStack(&(m->stack));\
  			return ;\
  		}\
  		m->is_setjmp_called = TRUE;\
  		did_i_set = TRUE;\
  	}\
}

#define SET_LOW_MEMORY_TRAP(failure_value)	\
gboolean did_i_set = FALSE;\
{\
	mem_info *m = _get_thread_specific_data();\
	if(m == NULL)\
	{\
		m = (mem_info *)_pAlloc(sizeof(mem_info));\
		if(!m)\
			return failure_value;\
		m->is_setjmp_called = FALSE;\
		_clearCleanUpStack(&(m->stack));\
		if(_set_thread_specific_data(m))\
			return failure_value;\
	}\
	if(!m->is_setjmp_called)\
	{\
  		if(setjmp(m->buf) > 0)\
  		{\
  			m->is_setjmp_called = FALSE;\
  			_destroCleanUpStack(&(m->stack));\
  			return failure_value;\
  		}\
  		m->is_setjmp_called = TRUE;\
  		did_i_set = TRUE;\
  	}\
}


#define REMOVE_LOW_MEMORY_TRAP()	{\
if(did_i_set)\
	{\
	mem_info *m = _get_thread_specific_data();\
	if(m)\
		m->is_setjmp_called = FALSE;\
		_clearCleanUpStack(&(m->stack));\
	}\
}

#endif /* __G_LOW_MEM_H__ */