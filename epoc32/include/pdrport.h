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
//

#ifndef PDRPORT_H
#define PDRPORT_H

#include <e32std.h>
#include <c32comm.h>
#include <gdi.h>
#include <s32file.h>


/**
 @publishedAll
 @released 
 */
class CFilePrinterPort : public CPrinterPort
	{
public:
	IMPORT_C static CFilePrinterPort* NewL(const TDesC& aFileName);
	IMPORT_C ~CFilePrinterPort();
	void WriteRequest(const TDesC8& aBuf,TRequestStatus& aRequestStatus);
	void Cancel();
	inline const TDesC& FileName() { return iFileName; }
private:
	void ConstructL();
	CFilePrinterPort(const TDesC& aFileName);
private:
	RFs iFs;
	TFileName iFileName;
	RFile iFile;
	TBool iCancelled;
	};

/**
 * @internalTechnology
 * Internal to Symbian
 */
class TOutputHandshake
	{
public:
	IMPORT_C TOutputHandshake();
	IMPORT_C void InternalizeL(RReadStream& aStream);
	IMPORT_C void ExternalizeL(RWriteStream& aStream) const;
public:
	TBool iXonXoff;
	TBool iCts;
	TBool iDsr;
	TBool iDcd;
	};

/**
 * @internalTechnology
 * Internal to Symbian
 */
class TSerialPrinterPortConfig
	{
public:
	IMPORT_C TSerialPrinterPortConfig();
	IMPORT_C void InternalizeL(RReadStream& aStream);
	IMPORT_C void ExternalizeL(RWriteStream& aStream) const;
public:
	TBps iRate;
	TDataBits iDataBits;
	TStopBits iStopBits;
	TParity iParity;
	TBool iIgnoreParity;
	TOutputHandshake iHandshake;
	};

/**
 * @internalTechnology
 * Internal to Symbian
 */
class CCommPrinterPort : public CPrinterPort
	{
public:
	IMPORT_C static CCommPrinterPort* NewL(const TDesC& aCsyName, const TDesC& aPortName, const TSerialPrinterPortConfig& aConfig, const TFifo aFifo = EFifoEnable);
	IMPORT_C ~CCommPrinterPort();
	IMPORT_C void WriteRequest(const TDesC8& aBuf, TRequestStatus& aRequestStatus);
	IMPORT_C void Cancel();
protected:
	IMPORT_C void ConstructL(const TDesC& aCsyName, const TDesC& aPortName, const TSerialPrinterPortConfig& aConfig, const TFifo aFifo = EFifoEnable);
	IMPORT_C CCommPrinterPort();
protected:
	RCommServ iCommServ;
	RComm iComm;
	};

/**
 * @internalTechnology
 * Internal to Symbian
 */
class CSerialPrinterPort : public CCommPrinterPort
	{
public:
	IMPORT_C static CSerialPrinterPort* NewL(const TDesC& aPortName, const TSerialPrinterPortConfig& aConfig);
	IMPORT_C ~CSerialPrinterPort();
	IMPORT_C TSerialPrinterPortConfig Config();  // returns the current port config
private:
	void ConstructL(const TDesC& aPortName);
	CSerialPrinterPort(const TSerialPrinterPortConfig& aConfig);
private:
	TSerialPrinterPortConfig iConfig;
	};

/**
 * @internalTechnology
 * Internal to Symbian
 */
class CParallelPrinterPort : public CCommPrinterPort
	{
public:
	IMPORT_C static CParallelPrinterPort* NewL(const TDesC& aPortName);
	IMPORT_C ~CParallelPrinterPort();
private:
	void ConstructL(const TDesC& aPortName);
	CParallelPrinterPort();
	};

/**
 * @internalTechnology
 * Internal to Symbian
 */
class CIrdaPrinterPort : public CCommPrinterPort
	{
public:
	IMPORT_C static CIrdaPrinterPort* NewL();
	IMPORT_C ~CIrdaPrinterPort();
private:
	void ConstructL();
	CIrdaPrinterPort();
	};

/**
 * @internalTechnology
 * Internal to Symbian
 */
class CEpocConnectPort : public CCommPrinterPort
	{
public:
	IMPORT_C static CEpocConnectPort* NewL();
	IMPORT_C ~CEpocConnectPort();
private:
	void ConstructL();
	CEpocConnectPort();
	};

#endif
