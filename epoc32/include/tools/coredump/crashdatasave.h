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
// Defines the ECOM Core Dump Writer interface. 
//



/**
 @file
 @publishedPartner
 @released
*/

#ifndef CRASH_DATA_SAVE_H
#define CRASH_DATA_SAVE_H


#include <e32std.h>
#include <ecom.h>

#include <ImplementationInformation.h>

/**
This is the ECOM interface UID that all Writer ECOM plugins supporting this interface
must implement. This must match with the implementation_uid field of the rss file.
*/
const TUid KCCrashDataSaveUid = {0x102831e3};


class COptionConfig;


/**
Class that defines the ECOM interface of a Core Dump Writer ECOM plugin.
The responsibility of a writer plugin is to be a repository or channel for a 
formatter's crash data.
The class is intended for derivation by implementations of the interface.
*/
class CCrashDataSave : public CBase
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
	static CCrashDataSave* NewL();
	static CCrashDataSave* NewL( const TDesC8 & aCue );
	static CCrashDataSave* NewL(const TUid& aUid);
	static void ListAllImplementationsL( RImplInfoPtrArray & aImplInfoArray );


	/**
	Obtain a description of the plugin.
	*/
	virtual void GetDescription( TDes & aPluginDescription ) = 0;

    /**
	Return the number of configuration parameters implemented by the plugin.
	*/
	virtual TInt GetNumberConfigParametersL( ) = 0;

	/**
	Return the configuration parameter with ordinal aIndex.
	@param  aIndex Parameter ordinal
	*/
	virtual COptionConfig * GetConfigParameterL( const TInt aIndex ) = 0;

	
	/**
	Change the configuration parameter with ordinal aIndex to the given values. 
	The plugin interprets and validates the values. Depending on the type of 
	parameter, the plugin may use the integer parameter aValue or the 
	descriptor parameter aDescValue
	@param  aIndex Parameter ordinal
	@param  aValue Integer value 
	@param  aDescValue Descriptor value
	*/
	virtual void SetConfigParameterL( const TInt aIndex, const TInt32 & aValue, const TDesC & aDescValue ) = 0;


	// Writer interface

	/**
	Used to start the saving of data. 
	@param aParam The interpretation of aParam is specific to the plugin.
	*/
	virtual void OpenL( const TDesC& aParam ) = 0;

	/**
	Used to start the saving of data. 
	@param aParam The interpretation of aParam is specific to the plugin.
	*/
	virtual TInt Open( const TDesC& aParam ) = 0;
	
	
	/**
	End the data save operation.
	@pre Must have called Open or OpenL
	*/
	virtual void CloseL() = 0;

	/**
	End the data save operation.
	@pre Must have called Open or OpenL
	*/
	virtual TInt Close() = 0;

	/**
	Save data. 
	@param aData TDesC8 with data to be saved.
	@pre Must have called Open or OpenL
	*/
	virtual void WriteL( const TDesC8& aData ) = 0;

	/**
	Save data. 
	@param aData TDesC8 with data to be saved.
	@pre Must have called Open or OpenL
	*/
	virtual TInt Write( const TDesC8& aData ) = 0;

	/**
	Save data from a pointer given the data size.
	@param aData Pointer to data to be saved.
	@param aSize Length of data to be saved in bytes
	@pre Must have called Open or OpenL
	*/
	virtual void WriteL( TAny* aData, TUint aSize ) = 0;

	/**
	Save data from a pointer given the data size.
	@param aData Pointer to data to be saved.
	@param aSize Length of data to be saved in bytes
	@pre Must have called Open or OpenL
	*/
	virtual TInt Write( TAny* aData, TUint aSize ) = 0;

	/**
	Save aData at the specific position.
	@param aPos The interpretation of aPos is specific to the plugin.
	@param aData TDesC8 with data to be saved.
	@pre Must have called Open or OpenL
	*/
	virtual void WriteL( TInt aPos, const TDesC8& aData ) = 0;

	/**
	Save aData at the specific position. 
	@param aPos The interpretation of aPos is specific to the plugin.
	@param aData TDesC8 with data to be saved.
	@pre Must have called Open or OpenL
	*/
	virtual TInt Write( TInt aPos, const TDesC8& aData ) = 0;

	/**
	Save aData at the specific position. 
	@param aPos The interpretation of aPos is specific to the plugin.
	@param aData Pointer to data to be saved.
	@param aSize Length of data to be saved in bytes
	@pre Must have called Open or OpenL
	*/
	virtual void WriteL( TInt aPos, TAny* aData, TUint aSize ) = 0;

	/**
	Save aData at the specific position. 
	@param aPos The interpretation of aPos is specific to the plugin.
	@param aData Pointer to data to be saved.
	@param aSize Length of data to be saved in bytes
	@pre Must have called Open or OpenL
	*/
	virtual TInt Write( TInt aPos, TAny* aData, TUint aSize ) = 0;
    
    //dtor
public:
    virtual ~CCrashDataSave();

    /**
	Writer plugin base configuration parameter identifiers. 
	Identifiers for derived interfaces should start where this enum ends.
	*/
	enum TDataSaveParams
		{
		/** This parameter is a root identifier for core dumps. Its use depends on the
		writer plugin and potentially the formatters. For example for an email data save 
		plugin this parameter could be an the email address. For a file writer it could be 
		a file name or a directory path. */
		ECoreFilePath,
		EDataSaveLastParam
		};

protected:

	/** Define the container for the plugin's configuration parameters */
	typedef RPointerArray<COptionConfig>	RConfigParameterList;

	/**
	List of COptionConfig configuration parameters implemented by the plugin.
	*/
	RConfigParameterList	 iConfigList;

private:
	TUid iDtor_ID_Key;

	TUint32 iSpare1;
	TUint32 iSpare2;
};

#include <crashdatasave.inl>

#endif
