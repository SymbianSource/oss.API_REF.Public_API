
// Copyright (c) 2002-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// ImageConstruct.h - classes used during construction of decoders/encoders
// 
//

#ifndef __ImageConstruct_h
#define __ImageConstruct_h

#include <e32base.h>

// forward declarations
class CImageDecoder;
class CImageDecoderPlugin;
class CImageEncoder;
class CImageEncoderPlugin;
class RCImageDecodeConstructTest;
class RCImageEncodeConstructTest;

/**
@publishedAll
@released

Provides functions related to constructing decoders.

Objects of this class are loaded by ECOM, and it is this class which
is responsible for instantiating the decoder plugins. Plugin writers
must derive their own plugin specific variants. The derived class
is responsible for defining its own factory function to create instances
of itself.
*/

class CImageDecodeConstruct : public CBase
	{
	friend class CImageDecoder;
public:
	IMPORT_C ~CImageDecodeConstruct();

	IMPORT_C TUid ImplementationUid() const;
	// create new CImageDecoder - default creates basic CImageDecoder
	IMPORT_C virtual CImageDecoder* NewDecoderL() const;

	/**
	Creates a new concrete CImageDecoderPlugin object.

	This is a pure virtual function that each derived class must implement.

	@return A pointer to a fully constructed CImageDecoderPlugin.
	*/
	virtual CImageDecoderPlugin* NewPluginL() const = 0;

	// request threaded decode - default false
	IMPORT_C virtual TBool RequestThread() const;
protected:
	IMPORT_C CImageDecodeConstruct();
	IMPORT_C void ConstructL();

private:
	IMPORT_C virtual void ReservedVirtual1();
	IMPORT_C virtual void ReservedVirtual2();
	IMPORT_C virtual void ReservedVirtual3();
	IMPORT_C virtual void ReservedVirtual4();
private:
	/**
	This member is internal and not intended for use.
	*/
	TUid iDtorIDKey;

	/**
	This member is internal and not intended for use.
	*/
	TAny* iReserved;

friend class RCImageDecodeConstructTest;
	};

/**
@publishedAll
@released

Provides functions related to constructing encoders.

Objects of this class are loaded by ECOM, and it is this class which
is responsible for instantiating the encoder plugins. Plugin writers
must derive their own plugin specific variants. The derived class
is responsible for defining its own factory function to create instances
of itself.
*/
class CImageEncodeConstruct : public CBase
	{
	friend class CImageEncoder;
public:
	IMPORT_C ~CImageEncodeConstruct();

	IMPORT_C TUid ImplementationUid() const;
	// create new CImageEncoder - default creates basic CImageEncoder
	IMPORT_C virtual CImageEncoder* NewEncoderL() const;

	/**
	Creates new concrete CImageEncoderPlugin object.

	This is a virtual function that each derived class must implement.

	@return A pointer to fully constructed CImageEncoderPlugin.
	*/
	virtual CImageEncoderPlugin* NewPluginL() const = 0;

	// request threaded encode - default false
	IMPORT_C virtual TBool RequestThread() const;
protected:
	IMPORT_C CImageEncodeConstruct();
	IMPORT_C void ConstructL();

private:
	IMPORT_C virtual void ReservedVirtual1();
	IMPORT_C virtual void ReservedVirtual2();
	IMPORT_C virtual void ReservedVirtual3();
	IMPORT_C virtual void ReservedVirtual4();
private:
	TUid iDtorIDKey;
	TAny* iReserved;
friend class RCImageEncodeConstructTest;
	};

#endif //__ImageConstruct_h
