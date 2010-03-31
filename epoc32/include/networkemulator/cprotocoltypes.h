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
* Switches
*
*/


#ifndef __CPROTOCOLTYPE_H__
#define __CPROTOCOLTYPE_H__

/*************************************************************************************
 *
 * Defines
 *
 ************************************************************************************/
#define MAXVARNAMELEN		60
#define MAXCOMMANDLINELEN	1024

/*************************************************************************************
 *
 * Types
 *
 ************************************************************************************/
typedef enum {
	CMD_REQ_STARTUSECASEID,
	CMD_REQ_SIGNALID,
	CMD_REQ_RENDEZVOUSID,
	CMD_REQ_WAITID,
	CMD_REQ_ENDUSECASEID,
	CMD_REQ_GETVARIABLENAMEID,
	CMD_REQ_RUNCOMMAND,
	CMD_REP_STARTUSECASEID,
	CMD_REP_SIGNALID,
	CMD_REP_RENDEZVOUSID,
	CMD_REP_WAITID,
	CMD_REP_ENDUSECASEID,
	CMD_REP_GETVARIABLENAMEID,
	CMD_REP_RUNCOMMAND,
	CMD_QUITID,
	CMD_UNKNOWN
}TPCommand;

typedef struct {
	int iUid;
	TPCommand iCmdID;
	int iDataLen;
} TPHeader;

/*************************************************************************************
 * Request Structs
 ************************************************************************************/

typedef struct {
	int iUsecaseID;
} TStartUsecaseRequest;

typedef struct {
	int iUsecaseID;
} TSignalRequest;

typedef struct {
	int iUsecaseID;
} TRendezvousRequest;

typedef struct {
	int iUsecaseID;
} TWaitRequest;

typedef struct {
	int iUsecaseID;
	int iResult;
} TEndUsecaseRequest;

typedef struct {
	char iVariableName[MAXVARNAMELEN] ;
} TGetVariableNameRequest;

typedef struct {
	char iCommandLine[MAXCOMMANDLINELEN] ;
	int iResult;
} TRunCommandRequest;

/*************************************************************************************
 * Reply Requests
 ************************************************************************************/

typedef struct {
	int iResult;
} TStartUsecaseReply;

typedef struct {
	int iResult;
} TSignalReply;

typedef struct {
	int iResult;
} TRendezvousReply;

typedef struct {
	int iResult;
} TWaitReply;

typedef struct {
	int iCommandResult;
	int iScriptResult;
} TEndUsecaseReply;

typedef struct {
	char iVariableValue[MAXVARNAMELEN] ;
	int iResult;
} TGetVariableNameReply;

typedef struct {
	int iResult;
} TRunCommandReply;

#endif //__CPROTOCOLTYPE_H__
