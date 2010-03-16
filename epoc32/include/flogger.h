// Copyright (c) 1997-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// FLogger Client side header
// 
//



/**
 @file
 @internalTechnology
*/



#ifndef __FLOGGER_H__
#define __FLOGGER_H__

#include <e32base.h>

/** Maximum log buffer size.
@internalTechnology */
const TInt KLogBufferSize=150;

// [All of this start up stuff copied from DBMS]

class FLogger
/** Controls the flogger server.
@internalComponent */
	{
public:
	class TSignal
/**
@internalComponent
*/
		{
		friend class FLogger;
	public:
		inline TSignal() {}
		inline TInt Set(const TDesC& aCommand);
	
		inline TSignal(TRequestStatus& aStatus);

		inline TPtrC Command() const;

	private:
		TRequestStatus* iStatus;
		TThreadId iId;
		};
public:
	static TInt Start();

	IMPORT_C static TInt Run(TSignal& aSignal);

private:
	static TInt Init();
	};


/** The mode used to write to the log file.
@internalTechnology */
enum TFileLoggingMode 
	{
	/** Log file mode has not been explicitly set. */
	EFileLoggingModeUnknown =0,
	/** Open the log file in append mode. */
	EFileLoggingModeAppend,
	/** Open the log file in overwrite mode. */
	EFileLoggingModeOverwrite,
	EFileLoggingModeAppendRaw,
	EFileLoggingModeOverwriteRaw	
	};

NONSHARABLE_CLASS(TLogFormatter16Overflow) :public TDes16Overflow
/** Unicode overflow handler.
@internalComponent */
	{
public:
	virtual void Overflow(TDes16& aDes);
	};

NONSHARABLE_CLASS(TLogFormatter8Overflow) :public TDes8Overflow
/** Overflow handler.
@internalComponent */
	{
public:
	virtual void Overflow(TDes8& aDes);
	};

class TLogFormatter
/** Formatting methods for log file data.
@internalComponent */
	{
public:
	TLogFormatter();
	void SetDateAndTime(TBool aUseDate,TBool aUseTime);
	TInt FormatTextToWritableBuffer(TDes8& aBuf, const TDesC16& aText) const;
	TInt FormatTextToWritableBuffer(TDes8& aBuf, const TDesC8& aText) const;
	TInt ConvertToWritableBuffer(TDes8& aBuf, TRefByValue<const TDesC16> aFmt, VA_LIST& aList);
	TInt ConvertToWritableBuffer(TDes8& aBuf, TRefByValue<const TDesC8> aFmt, VA_LIST& aList);
private:
	void GetDateAndTimeL(TDes& aDate, TDes& aTime) const;
	void WriteL(TDes8& aTrg, const TDesC16& aSrc) const;
	void WriteL(TDes8& aTrg, const TDesC8& aSrc) const;
private:
	TBool iUseDate;
	TBool iUseTime;
	TLogFormatter16Overflow iOverflow16;
	TLogFormatter8Overflow iOverflow8;
	};

class TLogFile
/** General access to packaged log files.
@internalComponent */
	{
public:
	TLogFile();
	TLogFile(const TDesC& aDir, const TDesC& aName, TFileLoggingMode aMode);
	TBool operator==(const TLogFile& aLogFile) const;
	void Set(const TDesC& aDir, const TDesC& aName, TFileLoggingMode aMode);
	inline TBool Valid() const;
	inline TFileName Directory() const;
	inline TFileName Name() const;
	inline TFileLoggingMode Mode() const;
	inline void SetValid(TBool aValid);
private:
	TBool iValid;
	TFileName iDirectory;
	TFileName iName;
	TFileLoggingMode iMode;
	};

#include <flogger.inl>

class RFileLogger : public RSessionBase
/** Provides access methods to file logging.

The file logger API contains both static and non-static versions of access 
functions to the file logging system. 
@internalTechnology */
	{
public:
	IMPORT_C RFileLogger();
	IMPORT_C ~RFileLogger();
	IMPORT_C TVersion Version() const;
	IMPORT_C TInt Connect();
	IMPORT_C void SetDateAndTime(TBool aUseDate,TBool aUseTime);
	IMPORT_C void CreateLog(const TDesC& aDir, const TDesC& aName, TFileLoggingMode aMode);
	IMPORT_C void CloseLog();
	IMPORT_C void Write(const TDesC16& aText);
	IMPORT_C void WriteFormat(TRefByValue<const TDesC16> aFmt,...);
	IMPORT_C void WriteFormat(TRefByValue<const TDesC16> aFmt, VA_LIST& aList);
	IMPORT_C void Write(const TDesC8& aText);
	IMPORT_C void WriteFormat(TRefByValue<const TDesC8> aFmt,...);
	IMPORT_C void WriteFormat(TRefByValue<const TDesC8> aFmt, VA_LIST& aList);
	IMPORT_C void HexDump(const TText* aHeader, const TText* aMargin, const TUint8* aPtr, TInt aLen);
	IMPORT_C static void Write(const TDesC& aDir, const TDesC& aName, TFileLoggingMode aMode, const TDesC16& aText);
	IMPORT_C static void WriteFormat(const TDesC& aDir, const TDesC& aName, TFileLoggingMode aMode, TRefByValue<const TDesC16> aFmt,...);
	IMPORT_C static void WriteFormat(const TDesC& aDir, const TDesC& aName, TFileLoggingMode aMode, TRefByValue<const TDesC16> aFmt, VA_LIST& aList);
	IMPORT_C static void Write(const TDesC& aDir, const TDesC& aName, TFileLoggingMode aMode, const TDesC8& aText);
	IMPORT_C static void WriteFormat(const TDesC& aDir, const TDesC& aName, TFileLoggingMode aMode, TRefByValue<const TDesC8> aFmt,...);
	IMPORT_C static void WriteFormat(const TDesC& aDir, const TDesC& aName, TFileLoggingMode aMode, TRefByValue<const TDesC8> aFmt, VA_LIST& aList);
	IMPORT_C static void HexDump(const TDesC& aDir, const TDesC& aName, TFileLoggingMode aMode, const TText* aHeader, const TText* aMargin, const TUint8* aPtr, TInt aLen);
	IMPORT_C TInt LastError() const;
	IMPORT_C TBool LogValid() const;

private:
	TInt DoConnect();
	void DoWrite(const TDesC8& aBuf);
	void DoStaticWrite(const TDesC8& aBuf);
	void DoWriteFormat(TRefByValue<const TDesC16> aFmt, VA_LIST& aList);
	void DoWriteFormat(TRefByValue<const TDesC8> aFmt, VA_LIST& aList);
	static void DoStaticWriteFormat(const TDesC& aDir, const TDesC& aName, TFileLoggingMode aMode, TRefByValue<const TDesC16> aFmt, VA_LIST& aList);
	static void DoStaticWriteFormat(const TDesC& aDir, const TDesC& aName, TFileLoggingMode aMode, TRefByValue<const TDesC8> aFmt, VA_LIST& aList);
	void DoHexDump(const TText* aHeader, const TText* aMargin, const TUint8* aPtr, TInt aLen);
private:
	TLogFormatter iFormatter;
	TLogFile iLogFile;
	TInt iLastError;
	};

#endif
