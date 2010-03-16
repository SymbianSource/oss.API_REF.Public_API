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
* CSetUpCommDb.h
*
*/


#ifndef _CSetUpCommDb_H
#define _CSetUpCommDb_H

/*****************************************************************************
 *
 * System Includes 
 *
 ****************************************************************************/
#include <commdb.h> 

/*****************************************************************************
 *
 * Local Includes
 *
 ****************************************************************************/

/*****************************************************************************
 *
 *  Types
 *
 ****************************************************************************/
typedef enum {
	TCommDB_Success,
	TCommDB_ErrorInitCommDb,
	TCommDB_ErrorTableNotFound,
	TCommDB_ErrorUpdatingRecord,
	TCommDB_ErrorReadingRecord,
	TCommDB_ErrorColNotFound,
	TCommDB_ErrorColTypeValueNotSupported,
	TCommDB_ErrorConvertingToUnicode,
	TCommDB_ErrorUnexpectedColType,
	TCommDB_RecNotFound
}TCommDBError;

typedef enum {
	TCOMMBD_IDLE,
	TCOMMBD_CONNECTED
}TCommDbStatus;

/*****************************************************************************
 *
 * Class Definition
 *
 ****************************************************************************/
class CSetUpCommDb : public CBase
{

public:
	// Constructor sets all member data to null
	IMPORT_C CSetUpCommDb();

	// Deletes the pointer, sets it to null.
	IMPORT_C ~CSetUpCommDb();

	// Method to initialise the database.
	IMPORT_C TCommDBError initialise(void);
	
	IMPORT_C TCommDBError updateEntry(TPtrC aTable, TUint32 aRecordID, TPtrC aFieldName, char* aFieldValue, int* aErrCode);	

	IMPORT_C TCommDBError getAsciiEntry(TPtrC aTable, TUint32 aRecordID, TPtrC aFieldName, TDes8& aFieldValue, int* aErrCode);
	IMPORT_C TCommDBError getUnicodeEntry(TPtrC aTable, TUint32 aRecordID, TPtrC aFieldName, TDes16& aFieldValue, int* aErrCode);
	IMPORT_C TCommDBError getIntEntry(TPtrC aTable, TUint32 aRecordID, TPtrC aFieldName, TUint32& aFieldValue, int* aErrCode);
	IMPORT_C TCommDBError getBoolEntry(TPtrC aTable, TUint32 aRecordID, TPtrC aFieldName, TBool& aFieldValue, int* aErrCode);

private:
	CCommsDbTableView* openTableL( CCommsDatabase *aDbComms, TPtrC aTable );

	TCommDBError FindAndUpdateRecord( CCommsDbTableView *aTable, TUint32 aRecordID, TPtrC aFieldName, char* aFieldValue, int* aErrCode);
	TCommDBError UpdateField( CCommsDbTableView *aTable, TPtrC aFieldName, char* aFieldValue, int* aErrCode );
	int SetUnicodeString(CCommsDbTableView* aTable, TPtrC aFieldName, char* aFieldValue, int* aErrCode);
	int SetUnicodeStringLong(CCommsDbTableView* aTable, TPtrC aFieldName, char* aFieldValue, int* aErrCode);
	HBufC16 *ConvertAsciiToUnicode( char *aAsciiString );

	TCommDBError FindRecordAndGetType( CCommsDbTableView *aTable, TUint32 aRecordID, TPtrC aFieldName, TDbColType *aColType, int* aErrCode );


	CCommsDatabase *iDbComms;
	TCommDbStatus iStatus;

};

#endif
