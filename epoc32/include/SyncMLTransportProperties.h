/*
* Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies). 
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description: SyncML Transport properties.
*
*/
///////////////////////////////////////////////////////////////////////////////
// SyncMLTransportProperties.h
//
//
///////////////////////////////////////////////////////////////////////////////
#ifndef __SYNCMLTRANSPORTPROPERTIES_H__
#define __SYNCMLTRANSPORTPROPERTIES_H__
//
#include <e32base.h>
#include <SyncMLDef.h>

class RReadStream;
class RWriteStream;
//

/**
	Data type of a SyncML transport property value.
*/
enum TSyncMLTransportPropertyDataType
	{
	/** Narrow text. */
	EDataTypeText8,
	/** Number. */
	EDataTypeNumber,
	/** Boolean. */
	EDataTypeBoolean
	};

class TSyncMLTransportPropertyInfo
/**	Information about a SyncML transport property.
	@see CSmlTransportPropertiesArray
	@publishedAll
	@released
*/
	{
public:
	IMPORT_C void InternalizeL(RReadStream& aStream);
	IMPORT_C void ExternalizeL(RWriteStream& aStream) const;
public:
	/** Property data type. */
	TSyncMLTransportPropertyDataType iDataType;
	/** Property name. */
	TBuf8<KSmlMaxTransportPropertyNameLen> iName;
	};


class CSyncMLTransportPropertiesArray : public CBase
/**	An array of SyncML transport property information.
	
	This is used to store information about the properties supported by a transport type.
	@publishedAll
	@released
	@see RSyncMLTransport::Properties() 
*/
	{
public:
	/** Information about a property. */
	typedef TSyncMLTransportPropertyInfo TPropertyInfo;
public:
	IMPORT_C CSyncMLTransportPropertiesArray(TInt aGranularity);
	IMPORT_C void InternalizeL(RReadStream&);
	IMPORT_C void ExternalizeL(RWriteStream&) const;
	IMPORT_C TInt AddL(const TPropertyInfo&);
	IMPORT_C void Delete(TInt aIndex);
	IMPORT_C TInt Find(const TDesC8& aPropertyName) const;
	IMPORT_C TInt Count() const;
	IMPORT_C TPropertyInfo& At(TInt aIndex);
	IMPORT_C const TPropertyInfo& At(TInt aIndex) const;
	inline TPropertyInfo& operator[](TInt aIndex);
	inline const TPropertyInfo& operator[](TInt aIndex) const;
private:
	CArrayFixFlat<TPropertyInfo> iElements;
	};

inline TSyncMLTransportPropertyInfo& CSyncMLTransportPropertiesArray::operator[](TInt aIndex)
/**
Gets the member of the array with the specified index value.
@return	Property value at array index aIndex		
@param aIndex Index value
*/
	{ return At(aIndex); }

inline const TSyncMLTransportPropertyInfo& CSyncMLTransportPropertiesArray::operator[](TInt aIndex) const
/**
Gets the member of the array with the specified index value (const overload).
@return	Property value at array index aIndex		
@param aIndex Index value
*/
	{ return At(aIndex); }


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#endif // __SYNCMLTRANSPORTPROPERTIES_H__