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
// include\mmf\common\mmfutilities.h
// 
//

#ifndef __MMF_COMMON_UTILITIES_H__
#define __MMF_COMMON_UTILITIES_H__

#include <e32base.h>
#include <mmf/server/mmfdatabuffer.h>
#include <mmf/common/mmffourcc.h>


/** 
@publishedAll
@released

Identifies the particular stream of the given media type.
*/
class TMediaId
	{
public:

	/**
	Constructs the class with the supplied arguments.

	This constructor is used when there are multiple streams of the same media type on the same
	MDataSource.

	@param  aMediaType
	        The media type (video, audio etc.).
	@param  aStreamId
	        Identifies a specific stream when there are multiple streams of the same media type on 
	        the same MDataSource.
	*/
	TMediaId(TUid aMediaType, TUint aStreamId);

	/**
    Constructs the class with the supplied argument.

	This constructor is used when there is a single stream of the same media type on the same
	MDataSource.

	@param  aMediaType
	        The media type (video, audio etc.).
	*/
	TMediaId(TUid aMediaType);

	/**
	Default constructor.
	*/
	TMediaId();
public:
	/**
	The media type (KUidMediaTypeAudio, KUidMediaTypeVideo, etc).
	*/
	TUid iMediaType;

	/**
	Identifies a particular media stream used in case where multiple streams
	of the same media type are present on the same MDataSource.
	*/
	TUint iStreamId;
private:
	/**
	This member is internal and not intended for use.
	*/
	TInt iReserved1;
	TInt iReserved2;
	TInt iReserved3;
	};

/**
@publishedAll
@released

The FourCC code that represents NULL.
*/
const TInt KFourCCNULL = KMMFFourCCCodeNULL;

/**
@publishedAll
@released

A class that holds a four character code, representing supported data encodings for the
conversion destination. The four character codes are packed into a single TUint32.

FourCC codes are a representation of the datatypes used to identify codecs. FourCC codes are used in 
codec .rss files as a match string used by ECOM to correctly load the required DLL.
*/
class TFourCC
{
public:

	/**
	Default constructor initialises the class to KMMFFourCCCodeNULL.
	*/
	TFourCC() {iFourCC = KMMFFourCCCodeNULL;} //'NULL'

	/**
	Packs the four arguments into a single TUint32.

	The four arguments are packed in little-endian format.

	@param  aChar1
	        A character that represents part of the FourCC code. This character will be the least 
	        significant byte of the code.
	@param  aChar2
            A character that represents part of the FourCC code.
	@param  aChar3
            A character that represents part of the FourCC code.
	@param  aChar4
	        A character that represents part of the FourCC code. This character will be the most 
	        significant byte of the code.
	*/
	TFourCC(TUint8 aChar1, TUint8 aChar2, TUint8 aChar3, TUint8 aChar4) {iFourCC =(aChar4<<24)+(aChar3<<16)+(aChar2<<8)+aChar1;}

	/**
	Constructs a FourCC code with the given 8 bit desciptor where the descriptor contains the
	characters that make up the FourCC code.

	@param  aDes
	        The descriptor containing the characters from which to make the FourCC code.
	*/
	TFourCC(const TDesC8& aDes) {iFourCC =(aDes[3]<<24)+(aDes[2]<<16)+(aDes[1]<<8)+aDes[0];}

	/**
    Constructor with a TInt32 in little-endian format.

	@param  aFourCC
            The FourCC code.
	*/
	TFourCC(TInt32 aFourCC) {iFourCC = aFourCC;}

	/**
    Returns the FourCC code in little-endian format.

	@return The FourCC code in little-endian format.
	*/
	TUint32 FourCC() {return iFourCC;}
	inline void FourCC( TPtr8* aDes ) const ;

	/**
    Sets the FourCC code equal to the value in the supplied argument.

	@param  aFourCC
	        The required TFourCC containting the FourCC code.
	*/
	void Set(TFourCC aFourCC) {iFourCC = aFourCC.iFourCC;}

	/**
    Sets the FourCC code equal to the supplied argument.

	@param  aFourCC
	        The required FourCC code.
	*/
	void Set(TUint32 aFourCC) {iFourCC = aFourCC;}

	/**
	Equality operator.

	@param  aA
	        The TFourCC code that *this will be tested against.

	@return A boolean indicating if the two values are equal. ETrue if the two values are equal, 
	        otherwise false.
	*/
	TBool operator==(const TFourCC& aA) const {return (iFourCC == aA.iFourCC);}

	/**
    Equality operator.

	@param  aUint
	        The FourCC code that *this will be tested against.

	@return A boolean indicating if the two values are equal. ETrue if the two values are equal, 
	        otherwise false.
	*/
	TBool operator==(const TUint32& aUint) const {return (iFourCC == aUint);}

	/**
    Inequality operator.

	@param  aA
	        The TFourCC code that *this will be tested against.
	
	@return A boolean indicating if the two values are not equal. ETrue if the two values are 
	        unequal, otherwise false.
	*/
	TBool operator!=(const TFourCC& aA) const {return (iFourCC != aA.iFourCC);}

	/**
    Inequality operator.

	@param  aUint
	        The FourCC code that *this will be tested against.
	*/
	TBool operator!=(const TUint32& aUint) const {return (iFourCC != aUint);}

private:
	TUint32 iFourCC;
};

/**
@internalAll

Base utility class to change the sample rate of audio data in a buffer
*/
class CMMFChannelAndSampleRateConverter : public CBase
	{
public:
	/**
	Reads the audio data from the source buffer,
	converts the number of channels and the sample rate
	and copies the result to the destination buffer

	@param  aSrcBuffer
	        A pointer to a source buffer containing the audio data to convert.
	@param  aDstBuffer
	        A pointer to a destination buffer.

	@return The length of the destination buffer.
	*/
	virtual TInt Convert(const CMMFDataBuffer& aSrcBuffer, CMMFDataBuffer& aDstBuffer) =0;
	virtual void Reset() {};

	/*
	Indicates what buffer size is required to hold the converted data.
	*/
	virtual TUint MaxConvertBufferSize(TUint aSrcBufferSize) {return aSrcBufferSize;}

	void SetRates(TInt aSrcRate,TInt aSrcChannels,TInt aDstRate,TInt aDstChannels);
public:
	/*
	The sample rate of the data in the source buffer
	*/
	TInt iFromRate;
	/*
	The sample rate of the data in the destination buffer
	*/
	TInt iToRate;
	/*
	The number of channels of data in the source buffer
	*/
	TInt iFromChannels;
	/*
	The number of channels of data in the destination buffer
	*/
	TInt iToChannels;
protected:
	TReal iRatio;
	TInt iFraction;
	TInt iIndex;
	};

/**
@internalAll
*/
class CMMFStereoToMonoRateConverter : public CMMFChannelAndSampleRateConverter
	{
	public:
		virtual TInt Convert(const CMMFDataBuffer& aSrcBuffer, CMMFDataBuffer& aDstBuffer);
		virtual TUint MaxConvertBufferSize(TUint aSrcBufferSize);

	};

/**
@internalAll
*/
class CMMFStereoToMonoConverter : public CMMFChannelAndSampleRateConverter
	{
	public:
		virtual TInt Convert(const CMMFDataBuffer& aSrcBuffer, CMMFDataBuffer& aDstBuffer);
		virtual TUint MaxConvertBufferSize(TUint aSrcBufferSize);
	};

/**
@internalAll
*/
class CMMFStereoToStereoRateConverter : public CMMFChannelAndSampleRateConverter
	{
	public:
		virtual TInt Convert(const CMMFDataBuffer& aSrcBuffer, CMMFDataBuffer& aDstBuffer);
	};

/**
@internalAll
*/
class CMMFMonoToMonoRateConverter : public CMMFChannelAndSampleRateConverter
	{
	public:
		virtual TInt Convert(const CMMFDataBuffer& aSrcBuffer, CMMFDataBuffer& aDstBuffer);
	};

/**
@internalAll
*/
class CMMFMonoToStereoConverter : public CMMFChannelAndSampleRateConverter
	{
	public:
		virtual TInt Convert(const CMMFDataBuffer& aSrcBuffer, CMMFDataBuffer& aDstBuffer);
		virtual TUint MaxConvertBufferSize(TUint aSrcBufferSize);
	};

/**
@internalAll
*/
class CMMFMonoToStereoRateConverter : public CMMFChannelAndSampleRateConverter
	{
	public:
		virtual TInt Convert(const CMMFDataBuffer& aSrcBuffer, CMMFDataBuffer& aDstBuffer);
		virtual TUint MaxConvertBufferSize(TUint aSrcBufferSize);
	};

/**
@internalAll

Factory class to create the appropriate CMMFChannelAndSampleRateConverter-derived
class depending on the supplied number of channels and bit rate
*/
class CMMFChannelAndSampleRateConverterFactory : public CBase
	{

public:
	IMPORT_C CMMFChannelAndSampleRateConverter* CreateConverterL(TInt aFromRate,TInt aFromChannels,
												 TInt aToRate,TInt aToChannels);
	IMPORT_C CMMFChannelAndSampleRateConverter* CreateConverterL();
	CMMFChannelAndSampleRateConverter* Converter() {return iConverter;}
	IMPORT_C ~CMMFChannelAndSampleRateConverterFactory();
	TInt Rate() {return iToRate;}
	TInt Channels() {return iToChannels;}
public:
	/**
	The sample rate of the data in the source buffer
	*/
	TInt iFromRate;
	/**
	The sample rate of the data in the destination buffer
	*/
	TInt iToRate;
	/**
	The number of channels of data in the source buffer
	*/
	TInt iFromChannels;
	/**
	The number of channels of data in the destination buffer
	*/
	TInt iToChannels;
private:
	CMMFChannelAndSampleRateConverter* iConverter;
	};

#include <mmf/common/mmfutilities.inl>

#endif
