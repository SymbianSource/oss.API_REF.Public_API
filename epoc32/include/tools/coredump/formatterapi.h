// Copyright (c) 2006-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef FORMATTER_API_H
#define FORMATTER_API_H

/**
@file
@publishedPartner
@released

Defines the ECOM Core Dump Formatting interface. 

*/

#include <e32base.h>
#include <badesca.h>
#include <ecom.h>
#include <ImplementationInformation.h>
#include <crashdata.h>

/**
This is the ECOM interface UID that all Formatter ECOM plugins supporting this interface
must implement. This must match with the implementation_uid field of the rss file.
*/
const TUid KCCoreDumpFormatterUid = {0x10282fe2};

class CCrashDataSource;
class CCrashDataSave;
class COptionConfig;

/**
@publishedPartner
@released

Definition of the ECOM Core Dump Formatting interface. 
The interface is pure virtual. Formatters must implement this interface for the 
core dump server to be able to load them.
*/
class CCoreDumpFormatter : public CBase
{

public:

    /** Interface for passing initialisation parameters
    to the derived class constructor. Standard ECOM implementation. 
	*/
    struct TExampleInterfaceInitParams
        {
		/** Integer cue */
        TInt integer;
		/** Descriptor cue */
        const TDesC* descriptor;
        };

	// mandatory ECOM functions

	static CCoreDumpFormatter* NewL();
	static CCoreDumpFormatter* NewL( const TDesC8 & aCue );
	static CCoreDumpFormatter* NewL(const TUid& aUid);

	virtual ~CCoreDumpFormatter();
	static void ListAllImplementationsL( RImplInfoPtrArray & aImplInfoArray );

public:
	// The formatter interface


	/**
	Core dump server makes this call to supply the formatter with the 
	data save object. The formatter can then use this object to store 
	its crash data. The formatter does not own the object.
	@param aDataSave Data save object to save crash data to.
	@see CCrashDataSave 
	*/
	virtual void ConfigureDataSaveL( CCrashDataSave * aDataSave ) = 0;

	/**
	Core dump server makes this call to supply the formatter with the 
	data source object. The formatter can then use this object to obtain
	crash data. The formatter does not own the object.
	@param aDataSource Data source object to obtain crash data from.
	@see CCrashDataSource
	*/
	virtual void ConfigureDataSourceL( CCrashDataSource * aDataSource ) = 0;

	/**
	Call used to obtain a text description of the formatter. Can be used by
	UIs to present a description to the user.
	@param aPluginDescription Descriptor with formatter descriptor.
	*/
	virtual void GetDescription( TDes & aPluginDescription ) = 0;

	/** 
	This method informs the formatter that a crash event has occured. 
	Called by Core Dump Server, which owns the TCrashInfo object.
	@param aCrashInfo Crash event information with crash data. 
	Object is owned by caller.
	@see TCrashInfo
	*/
    virtual void CrashEventL(TCrashInfo* aCrashInfo) = 0;

	/** 
	Used to obtain the number of configuration parameters implemented by the 
	formatter. Use this call in conjunction with GetConfigParameterL().
	@return Number of configuration parameters implemented by formatter.
	@see COptionConfig
	*/
	virtual TInt GetNumberConfigParametersL( ) = 0;

	/** 
	Return the configuration parameter indexed by aIndex. aIndex should be less
	than the value returned by GetNumberConfigParametersL().
	@param aIndex Parameter ordinal to retrieve.
	@return Pointer to a COptionConfig object that is then owned by the caller.
	@see COptionConfig.
	@see GetNumberConfigParametersL().
	*/
	virtual COptionConfig * GetConfigParameterL( const TInt aIndex ) = 0;

	/** 
	Set the value of a configuration parameters indexed by aIndex. 
	@param  aIndex Parameter ordinal to change.
	@param  aValue Integer value.
	@param  aDescValue Descriptor value.
	@see COptionConfig
	*/
	virtual void SetConfigParameterL( const TInt aIndex, 
									const TInt32 & aValue, 
									const TDesC & aDescValue ) = 0;
	
protected:
	CCoreDumpFormatter();

private:
	
	TUid iDtor_ID_Key;

	TUint32 iSpare1;
	TUint32 iSpare2;
};

#include <formatterapi.inl>

#endif // FORMATTER_API_H
