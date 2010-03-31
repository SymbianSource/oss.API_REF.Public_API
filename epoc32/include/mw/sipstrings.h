/*
* Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Name        : sipstrings.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0 
*
*/



#ifndef SIPSTRINGS_H
#define SIPSTRINGS_H

//  INCLUDES
#include <e32base.h>
#include <stringpool.h>
#include "_sipcodecdefs.h"

// FORWARD DECLARATIONS
class CSIPStrings;

// CLASS DECLARATION
/**
 * @publishedAll
 * @released
 *
 * This class defines string pool for SIP Codec.
 * The client of SIP Codec must call OpenL() before 
 * invoking any function of SIP Codec classes.
 * The client must close the string pool when finished using
 * SIP Codec classes.
 *
 * @lib sipcodec.lib
 */
class SIPStrings
	{
	public:	// Constructors and destructor
 		
		/**
		* Opens SIP Codec string pool.
		* Implemented with a reference count.
		*/
		IMPORT_C static void OpenL();

		/**
		* Closes SIP Codec string pool.
		* In other words decrements reference count and if it reaches
		* zero, closes the string pool.	 
		* The user must not call Close() if it has not called OpenL().
		*/
		IMPORT_C static void Close(); 


	public: // New functions
	
		/**
		* Gets a case-insensitive string specified 
		* in the original string table.
		*
		* @param aIndex The string table enumeration value
		* @return Initialised RStringF object
		*/
		IMPORT_C static RStringF StringF(TInt aIndex);

		/**
		* Gets the string pool used by SIP Codec.
		*
		* @return RStringPool: A handle to a string pool
		*/
		IMPORT_C static RStringPool Pool();

		/**
		* Gets the string table used by SIP Codec.
		*
		* @return TStringTable&: The string pool table
		*/
		IMPORT_C static const TStringTable& Table();
	
	private:

		static CSIPStrings* Strings();
		};

#endif // SIPSTRINGS_H

// End of File
