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


#define g_thread_functions_for_glib_use (*_g_thread_functions_for_glib_use())
#define g_thread_use_default_impl (*_g_thread_use_default_impl())
#define g_threads_got_initialized (*_g_threads_got_initialized()) 
#define g_idle_funcs (*_g_idle_funcs())
#define g_timeout_funcs (*_g_timeout_funcs())
#define g_child_watch_funcs (*_g_child_watch_funcs())
#define g_io_watch_funcs (*_g_io_watch_funcs())
#define _g_debug_flags (*__g_debug_flags())
#define _g_debug_initialized (*__g_debug_initialized())
#define glib_mem_profiler_table (*_glib_mem_profiler_table())
#define g_mem_gc_friendly (*_g_mem_gc_friendly())
#define g_ascii_table (*_g_ascii_table())
#define g_utf8_skip (*_g_utf8_skip())
#define glib_binary_age (*_glib_binary_age())
#define glib_interface_age (*_glib_interface_age())
#define glib_major_version (*_glib_major_version())
#define glib_micro_version (*_glib_micro_version())
#define glib_minor_version (*_glib_minor_version())
#define glib_on_error_halt (*_glib_on_error_halt())
