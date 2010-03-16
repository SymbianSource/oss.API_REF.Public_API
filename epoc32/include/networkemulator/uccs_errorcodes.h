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
* Filename: UCCS_ErrorCodes.h
*
*/


#ifndef __UCCSCERRORCODES_H__
#define __UCCSCERRORCODES_H__


/***********************************************************************************
 *
 * Types
 *
 **********************************************************************************/
typedef enum {
	UCCS_ERROR_NONE			= 0, // This is returned from the new services for no error
	UCCS_OK					= 100,

	// (2a) Returned by Invoke -- and then in turn by the execute command (IOutput::Error)
	UCCS_SERVICELISTFULL = -300,					
	UCCS_NOSERVICEID,
	UCCS_INVALIDSERVICEID,					
	UCCS_CANTSTARTSERVICE,
	UCCS_CANTSTOPSERVICE,
	UCCS_NOSERVICEHOST,
	UCCS_INVALIDSERVICEINDEX,				
    UCCS_NO_MATCHING_GENERIC_SERVICE_FOUND,

	// (2b) Returned by ParseCommand -- and then in turn by the execute command (IOutput::Error)
	UCCS_PARSERFAILEDTOSTOREVALUE,

	// (2c) Returned by Execute Command (IOutput::Error)
	UCCS_UNKNOWNCOMMAND,
	UCCS_REPLAYCOMMAND,
	UCCS_NORESULT,
	UCCS_QUIT,
	UCCS_REQUIREDVALUEERROR,
	UCCS_REQUIREDVALUEINCORRECT,		
	UCCS_REQUIREDNOTVALUEERROR,
	UCCS_REQUIREDNOTVALUEMATCH,
	UCCS_CHECKVALUEERROR,
	UCCS_CHECKVALUEINCORRECT,
	UCCS_CHECKNOTVALUEERROR,			
	UCCS_CHECKNOTVALUEMATCH,

	// (2d) Returned from other classes that eventually get returned by execute command
	UCCS_FIELDNOTFOUND,
	UCCS_SYSTEMERROR,
	UCCS_RECORDFULL,
	UCCS_NOMORECOMMANDS,				

	// (2e) Errors that are only used direct to IOutput
	UCCS_UNKNOWNCONTROLCOMMAND,
	UCCS_CLIENT_ERROR,

	// (3a) Errors returned to the control commands directly from CBatchEngine
	UCCS_ALREADYSTARTEDUSECASE,
	UCCS_NOUSECASERUNNING,
	UCCS_FAILEDTOCREATEEXECUTETHREAD,
	UCCS_COMMANDEXECUTIONNOTSTARTEDYET,
	UCCS_SCRIPTFINISHED,

	// (3b) Errors returned from other classes that eventually get returned to control commands
	UCCS_CANTOPENSCRIPTFILE,
	UCCS_CANTOPENOUTPUTFILE,				
	UCCS_VARIABLEVALTOOLONG,
	UCCS_VARIABLEDOESNOTEXIST,
	UCCS_NOENVIRONMENT,

	// (4) End
	UCCS_LAST							
} TUCCSErrors;


/***********************************************************************************
 *
 * Definitions
 *
 **********************************************************************************/
#define GetUccsErrorStringI(x)	GetUccsErrorString((TUCCSErrors)(x))


/***********************************************************************************
 *
 * Prototypes
 *
 **********************************************************************************/
char *GetUccsErrorString( TUCCSErrors aErrorCode );
char *GetPenstdErrorString( int aErrorCode );


#endif __UCCSCERRORCODES_H__
