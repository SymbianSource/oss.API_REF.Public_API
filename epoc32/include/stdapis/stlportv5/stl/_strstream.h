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

#ifndef _STLP_INTERNAL_STREAMBUF
#include <stl/_streambuf.h>
#endif
#ifndef _STLP_ISTREAM
#include <istream>              // Includes <ostream>, <ios>, <iosfwd>
#endif
#ifndef _STLP_STRING_H
#include <stl/_string.h>
#endif

_STLP_BEGIN_NAMESPACE

#ifndef _STLP_USE_NAMESPACES
# define strstream _STLP_strstream 
# define ostrstream _STLP_ostrstream
# define istrstream _STLP_istrstream
# define strstreambuf _STLP_strstreambuf
#endif

//----------------------------------------------------------------------
// Class strstreambuf, a streambuf class that manages an array of char.
// Note that this class is not a template.
#ifdef __SYMBIAN32__
class strstreambuf : public basic_streambuf<char, char_traits<char> > 
#else
class _STLP_CLASS_DECLSPEC strstreambuf : public basic_streambuf<char, char_traits<char> >
#endif
{
public:                         // Types.
  typedef char_traits<char>              _Traits;
  typedef basic_streambuf<char, char_traits<char> > _Base;
  typedef void* (*__alloc_fn)(size_t);
  typedef void (*__free_fn)(void*);
public:                         // Constructor, destructor

  explicit strstreambuf(streamsize _Initial_capacity = 0);

  _STLP_DECLSPEC strstreambuf(__alloc_fn, __free_fn);

  _STLP_DECLSPEC strstreambuf(char* __get, streamsize __n, char* __put = 0);
  _STLP_DECLSPEC strstreambuf(signed char* __get, streamsize __n, signed char* __put = 0);
  _STLP_DECLSPEC strstreambuf(unsigned char* __get, streamsize __n, unsigned char* __put=0);

  _STLP_DECLSPEC strstreambuf(const char* __get, streamsize __n);
  _STLP_DECLSPEC strstreambuf(const signed char* __get, streamsize __n);
  _STLP_DECLSPEC strstreambuf(const unsigned char* __get, streamsize __n);

  virtual ~strstreambuf();

public:                         // strstreambuf operations.
  _STLP_DECLSPEC void freeze(bool = true);
  _STLP_DECLSPEC char* str();
  _STLP_DECLSPEC int pcount() const;

protected:                      // Overridden virtual member functions.
  virtual int_type overflow(int_type __c  = _Traits::eof());
  virtual int_type pbackfail(int_type __c = _Traits::eof());
  virtual int_type underflow();
  virtual _Base* setbuf(char* __buf, streamsize __n);
  virtual pos_type seekoff(off_type __off, ios_base::seekdir __dir,
                           ios_base::openmode __mode 
                                      = ios_base::in | ios_base::out);
  virtual pos_type seekpos(pos_type __pos, ios_base::openmode __mode 
                                      = ios_base::in | ios_base::out);

private:                        // Helper functions.
  // Dynamic allocation, possibly using _M_alloc_fun and _M_free_fun.
  char* _M_alloc(size_t);
  inline void  _M_free(char*);

  // Helper function used in constructors.
  void _M_setup(char* __get, char* __put, streamsize __n);
private:                        // Data members.
  __alloc_fn _M_alloc_fun;
  __free_fn  _M_free_fun;
  bool _M_dynamic  : 1;
  bool _M_frozen   : 1;
  bool _M_constant : 1;
#ifdef __SYMBIAN32__
  char* _pfrozenendsave;
  char* _pgetfrozenendsave;
#endif
};

inline strstreambuf::~strstreambuf()
{
#ifdef __SYMBIAN32__
  if (_M_dynamic && !_M_frozen)
  {
  	if (_M_free_fun)
  		_M_free_fun(eback());
  	else
  		_M_free(eback());
  }
#else  
	if (_M_dynamic && !_M_frozen)
        _M_free(eback());
#endif	
}

inline void strstreambuf::_M_free(char* p)
{
  if (p)
    if (_M_free_fun)
      _M_free_fun(p);
    else
      delete[] p;
}


//----------------------------------------------------------------------
// Class istrstream, an istream that manages a strstreambuf.

#ifdef __SYMBIAN32__
NONSHARABLE_CLASS (istrstream) : public basic_istream<char, char_traits<char> >
#else
class _STLP_CLASS_DECLSPEC istrstream : public basic_istream<char, char_traits<char> >
#endif
{
public:
  _STLP_DECLSPEC explicit istrstream(char*);
  _STLP_DECLSPEC explicit istrstream(const char*);
  _STLP_DECLSPEC istrstream(char* , streamsize);
  _STLP_DECLSPEC istrstream(const char*, streamsize);
  virtual ~istrstream();
  
  _STLP_DECLSPEC strstreambuf* rdbuf() const;
  _STLP_DECLSPEC char* str();

private:
  strstreambuf _M_buf;
};

//----------------------------------------------------------------------
// Class ostrstream
#ifdef __SYMBIAN32__
NONSHARABLE_CLASS (ostrstream) : public basic_ostream<char, char_traits<char> >
#else
class _STLP_CLASS_DECLSPEC ostrstream : public basic_ostream<char, char_traits<char> >
#endif
{
public:
  _STLP_DECLSPEC ostrstream();
  _STLP_DECLSPEC ostrstream(char*, int, ios_base::openmode = ios_base::out);
  virtual ~ostrstream();

  _STLP_DECLSPEC strstreambuf* rdbuf() const;
  _STLP_DECLSPEC void freeze(bool = true);
  _STLP_DECLSPEC char* str();
  _STLP_DECLSPEC int pcount() const;

private:
  strstreambuf _M_buf;
};

//----------------------------------------------------------------------
// Class strstream
#ifdef __SYMBIAN32__
NONSHARABLE_CLASS (strstream) : public basic_iostream<char, char_traits<char> >
#else
class _STLP_CLASS_DECLSPEC strstream : public basic_iostream<char, char_traits<char> >
#endif
{
public:
  typedef char                        char_type;
  typedef char_traits<char>::int_type int_type;
  typedef char_traits<char>::pos_type pos_type;
  typedef char_traits<char>::off_type off_type;

  _STLP_DECLSPEC strstream();
  _STLP_DECLSPEC strstream(char*, int, ios_base::openmode = ios_base::in | ios_base::out);
  virtual ~strstream();

  _STLP_DECLSPEC strstreambuf* rdbuf() const;
  _STLP_DECLSPEC void freeze(bool = true);
  _STLP_DECLSPEC int pcount() const;
  _STLP_DECLSPEC char* str();

private:
  strstreambuf _M_buf;
};

_STLP_END_NAMESPACE
