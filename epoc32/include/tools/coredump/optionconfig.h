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
// Define the Option Configuration interface class COptionConfig.
//



/**
 @file
 @publishedPartner 
 @released
 @see COptionConfig
*/


#ifndef OPTION_CONFIG_H
#define OPTION_CONFIG_H



#include <streamelement.h>

/** 
Maximum number of characters allowed for the descriptors of a COptionConfig object.
@see COptionConfig* NewL().
*/
#define KCDSMaxConfigParamStr 128


/**
@publishedPartner 
@released

Class that represents a configuration parameter. It is based on CStreamElementBase so
it can be streamed between client and server.
*/
class COptionConfig : public CStreamElementBase
{

public:

	/**
	Type of parameter
	*/
	enum TOptionType
		{
		/** Signed integer */
		ETInt,
		/** Unsigned integer */
		ETUInt,
		/** String */
		ETString,
		/** Filename */
		ETFileName,

        /** Unused */
		ETSingleEntryEnum,	

		/** Set string values allowed. */
		ETMultiEntryEnum,

		/** True/False */
		ETBool	

		};

	/**
	Owning component type
	*/
	enum TParameterSource
		{
		/** Core Dump Server is owner of the parameter */
		ECoreDumpServer,

		/** Formatter plugin is owner of the parameter */
		EFormatterPlugin,

		/** Writer plugin is owner of the parameter */
		EWriterPlugin
		};

	IMPORT_C static COptionConfig* NewL( const TUint32	       & aIndex, 
										const TUint32	       & aUID, 
										const TParameterSource & aSource, 
										const TOptionType	   & aType, 
										const TDesC            & aPrompt, 
										const TUint32	       & aNumOptions,
										const TDesC            & aOptions,
										const TInt32	       & aVal, 
										const TDesC            & aStrValue );

	IMPORT_C static COptionConfig* NewL( const TDesC8 & aStreamData );

	IMPORT_C ~COptionConfig();

public:
	// Methods specific to COptionConfig
	
	IMPORT_C TOptionType Type() const;
	IMPORT_C TParameterSource Source() const;
	IMPORT_C TUint32 Index() const;
	IMPORT_C TUint32 Uid( ) const;

	IMPORT_C const TDesC & Prompt() const;

	IMPORT_C TUint32 NumOptions( ) const;
	IMPORT_C const TDesC & Options() const;

	IMPORT_C TInt32 Value() const;
	IMPORT_C TBool ValueAsBool() const;
	IMPORT_C const TDesC & ValueAsDesc() const;

	IMPORT_C void Value( const TInt32 aValue );
	IMPORT_C void ValueL( const TDesC & aValue );

public:
	// Methods required by streaming interface 

	IMPORT_C static TInt MaxSize();
	IMPORT_C TInt Size() const;
	
	// Initializes ’this’ from stream
	IMPORT_C void InternalizeL( RReadStream & aStream );

	// Writes ’this’ to the stream
	IMPORT_C void ExternalizeL( RWriteStream & aStream, CBufFlat* buf );


private:

	COptionConfig(  const TOptionType		& aType, 
					const TParameterSource	& aSource, 
					const TUint32			& aIndex, 
					const TUint32			& aUID,
					const TUint32			& aNumOptions,
					const TInt32			& aValue );

	void ConstructStringL( const TDesC & aSource, HBufC ** aDest );

	COptionConfig();

	void ConstructL( const TDesC & aPrompt, 
					const TDesC & aOptions,
					const TDesC & aStrValue );

private:

	// Since this is passed accross the Client Server interface, we should keep the type native.
	TOptionType iType;

	TParameterSource iSource;

	// This index is not globally unique. It is valid within a group of parameters only. 
	// For example the params from the formatter are say 0 to 3, then for the writer they are 0 to 2.
	TUint32 iIndex;

	TUint32 iUID;

	HBufC * iPrompt;

	TUint32 iNumOptions;

	HBufC * iOptions;

	TInt32  iValue;

	HBufC * iStrValue;

	/** 
	Externalized size
	*/
	TUint	iSize;

	TUint32 iSpare1;
	TUint32 iSpare2;
	};


#endif // OPTION_CONFIG_H
