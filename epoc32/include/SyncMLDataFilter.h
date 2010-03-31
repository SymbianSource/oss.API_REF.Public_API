/*
* Copyright (c) 2002-2004 Nokia Corporation and/or its subsidiary(-ies). 
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description: For adding content to be synchronized.
*
*/


#ifndef __SYNCMLDATAFILTER_H__
#define __SYNCMLDATAFILTER_H__

//-------------------------------------------------------------------------------------------------
// Includes
//-------------------------------------------------------------------------------------------------
#include <e32base.h>
#include <s32strm.h>
#include <barsread.h>

//-------------------------------------------------------------------------------------------------
// Enumerations
//-------------------------------------------------------------------------------------------------

//  Filter type (inclusive/exclusive)
enum TSyncMLFilterType
	{
	ESyncMLTypeInclusive,
	ESyncMLTypeExclusive
	};

// Logical operator of CGI script
enum TSyncMLFilterMatchType
	{
	ESyncMLMatchDisabled,		// Value cannot be changed
	ESyncMLMatchNotSelected,	// Value is not set yet
	ESyncMLMatchAND,
	ESyncMLMatchOR
	};

// Data type of filter property
enum TSyncMLFilterPropertyDataType
	{
	ESyncMLDataTypeNull,
	ESyncMLDataTypeBool,
	ESyncMLDataTypeNumber,
	ESyncMLDataTypeDate,
	ESyncMLDataTypeTime,
	ESyncMLDataTypeText8,
	ESyncMLDataTypeText16
	};
	
// This is used when DataProvider makes some changes to dynamic filters
// or removes/adds filter based on store format of remote server
enum TSyncMLFilterChangeInfo
	{							
	ESyncMLDefault,
	ESyncMLNoChanges,
	ESyncMLDynamicFiltersUpdated,
	ESyncMLFiltersMoreFiltersSupportedByServer,
	ESyncMLFiltersLessFiltersSupportedByServer,
	ESyncMLFiltersUpdated		// General if many changes
	};


/**
* Filter Property Class.
*
* @lib syncmldatafilter.lib
*/
class CSyncMLFilterProperty : public CBase
	{
	public:
		/**
    	* Symbian two-phased constructor.
    	*/
		IMPORT_C static CSyncMLFilterProperty* NewLC();
		
		/**
    	* Symbian two-phased constructor.
    	* @param aReader TResourceReader for recource file that includes needed information to initialize filter property.
    	*/
		IMPORT_C static CSyncMLFilterProperty* NewLC( TResourceReader& aReader );
		
		/**
    	* Symbian two-phased constructor.
    	* @param aStream RReadStream for stream that includes needed information to initialize filter property.
    	*/
		IMPORT_C static CSyncMLFilterProperty* NewLC( RReadStream& aStream );
		
		/**
		* Destructor.
		*/
		IMPORT_C ~CSyncMLFilterProperty();

		/**
	    * Externalizes filter property.
	    * @param aStream Specifies stream where filter property is externalized.
	    */
		IMPORT_C void ExternalizeL( RWriteStream& aStream ) const;

		/**
	    * Name of filter property.
	    * @return TDesC Name of the filter property.
	    */
		IMPORT_C const TDesC& DisplayName() const;
		
		/**
	    * Data type of default values for filter property.
	    * @return TSyncMLFilterPropertyDataType Data type.
	    */
		IMPORT_C TSyncMLFilterPropertyDataType DefaultValueDataType() const;
		
		/**
	    * Data type of query value for filter property.
	    * @return TSyncMLFilterPropertyDataType Data type.
	    */
		IMPORT_C TSyncMLFilterPropertyDataType QueryValueDataType() const;
		
		/**
	    * Maximum text length of filter property. This is useful only if data type is text16 or text8.
	    * @return TUint Maximum text length of the filter property.
	    */
		IMPORT_C TUint MaxTextLength() const;
		
		/**
	    * Number of default values.
	    * @return TInt Number of default values of the filter property.
	    */
		IMPORT_C TInt DefaultValueCount() const;
		
		/**
	    * Default value from given index for text16 property. This is useful only if data type is text16.
	    * @param aIndex Specifies index where default value is returned.
	    * @return TDesC16 Default value from given index.
	    */
		IMPORT_C const TDesC16& DefaultValueText16L( TInt aIndex ) const;
		
		/**
	    * Default value from given index for text8 property. This is useful only if data type is text8.
	    * @param aIndex Specifies index where default value is returned.
	    * @return TDesC8 Default value from given index.
	    */
		IMPORT_C const TDesC8& DefaultValueText8L( TInt aIndex ) const;
		
		/**
	    * Default value from given index for number property. This is useful only if data type is number.
	    * @param aIndex Specifies index where default value is returned.
	    * @return TInt Default value from given index.
	    */
		IMPORT_C TInt DefaultValueIntL( TInt aIndex ) const;
		
		/**
	    * Default value from given index for boolean property. This is useful only if data type is boolean.
	    * @param aIndex Specifies index where default value is returned.
	    * @return TBool Default value from given index.
	    */
		IMPORT_C TBool DefaultValueBoolL( TInt aIndex ) const;
		
		/**
	    * Default value from given index for date property. This is useful only if data type is date.
	    * @param aIndex Specifies index where default value is returned.
	    * @return TTime Default value from given index.
	    */
		IMPORT_C const TTime& DefaultValueDateL( TInt aIndex ) const;
		
		/**
	    * Default value from given index for time property. This is useful only if data type is time.
	    * @param aIndex Specifies index where default value is returned.
	    * @return TTime Default value from given index.
	    */
		IMPORT_C const TTime& DefaultValueTimeL( TInt aIndex ) const;
		
		/**
	    * Clears all default values and value selections.
	    */
		IMPORT_C void ClearDefaultValuesL();
		
		/**
	    * Adds default value for text16 property. This is useful only if data type is text16.
	    * @param aNewDefaultValue Value of added default value.
	    * @param aSelected Specifies if value is selected or not.
	    */
		IMPORT_C void AddDefaultValueText16L( TDesC16& aNewDefaultValue, const TBool aSelected );
		
		/**
	    * Adds default value for text8 property. This is useful only if data type is text8.
	    * @param aNewDefaultValue Value of added default value.
	    * @param aSelected Specifies if value is selected or not.
	    */
		IMPORT_C void AddDefaultValueText8L( TDesC8& aNewDefaultValue, const TBool aSelected );
		
		/**
	    * Adds default value for number property. This is useful only if data type is number.
	    * @param aNewDefaultValue Value of added default value.
	    * @param aSelected Specifies if value is selected or not.
	    */
		IMPORT_C void AddDefaultValueIntL( const TInt aNewDefaultValue, const TBool aSelected );
		
		/**
	    * Adds default value for boolean property. This is useful only if data type is boolean.
	    * @param aNewDefaultValue Value of added default value.
	    * @param aSelected Specifies if value is selected or not.
	    */
		IMPORT_C void AddDefaultValueBoolL( const TBool aNewDefaultValue, const TBool aSelected );
		
		/**
	    * Adds default value for date property. This is useful only if data type is date.
	    * @param aNewDefaultValue Value of added default value.
	    * @param aSelected Specifies if value is selected or not.
	    */
		IMPORT_C void AddDefaultValueDateL( const TTime& aNewDefaultValue, const TBool aSelected );
		
		/**
	    * Adds default value for time property. This is useful only if data type is time.
	    * @param aNewDefaultValue Value of added default value.
	    * @param aSelected Specifies if value is selected or not.
	    */
		IMPORT_C void AddDefaultValueTimeL( const TTime& aNewDefaultValue, const TBool aSelected );
		
		/**
	    * Can use query value with default values or not.
	    * @return TBool Returns ETrue if query can be used. Otherwise EFalse is returned.
	    */
		IMPORT_C TBool CanUseQueryValue() const;
		
		/**
	    * Does filter property support multiple selection.
	    * @return TBool Returns ETrue if multiple values can be selected. Otherwise EFalse is returned.
	    */
		IMPORT_C TBool SupportsMultipleSelection() const;
		
		/**
	    * Does filter property support empty selection.
	    * @return TBool Returns ETrue if none of values can be selected. Otherwise EFalse is returned.
	    */
		IMPORT_C TBool SupportsEmptySelection() const;
		
		/**
	    * Returns information about which default values are selected.
	    * @param aIndex Specifies index where selection information is returned.
	    * @return TBool Returns ETrue if default value in given index is selected. Otherwise EFalse is returned.
	    */
		IMPORT_C TBool IsDefaultValueSelected( TInt aIndex ) const;
		
		/**
	    * Returns information about query value selection. This is useful only if query value can be used.
	    * @return TBool Returns ETrue if query value is selected. Otherwise EFalse is returned.
	    */
		IMPORT_C TBool IsQueryValueSelected() const;
		
		/**
	    * Selects default value from given index.
	    * @param aIndex Specifies index which is selected.
	    */
		IMPORT_C void SelectDefaultValueL( TInt aIndex );
		
		/**
	    * Unselects default value from given index.
	    * @param aIndex Specifies index which is unselected.
	    */
		IMPORT_C void UnselectDefaultValueL( TInt aIndex );
				
		/**
	    * Returns query value for text16 property. This is useful only if data type is text16 and if query value can be used.
	    * @return TDesC16 Query value.
	    */
		IMPORT_C const TDesC16& QueryValueText16L() const;
		
		/**
	    * Returns query value for text8 property. This is useful only if data type is text8 and if query value can be used.
	    * @return TDesC8 Query value.
	    */
		IMPORT_C const TDesC8& QueryValueText8L() const;
		
		/**
	    * Returns query value for number property. This is useful only if data type is number and if query value can be used.
	    * @return TInt Query value.
	    */
		IMPORT_C TInt QueryValueIntL() const;
		
		/**
	    * Returns query value for boolean property. This is useful only if data type is boolean and if query value can be used.
	    * @return TBool Query value.
	    */
		IMPORT_C TBool QueryValueBoolL() const;
		
		/**
	    * Returns query value for date property. This is useful only if data type is date and if query value can be used.
	    * @return TTime Query value.
	    */
		IMPORT_C const TTime& QueryValueDateL() const;

		/**
	    * Returns query value for time property. This is useful only if data type is time and if query value can be used.
	    * @return TTime Query value.
	    */
		IMPORT_C const TTime& QueryValueTimeL() const;
		
		/**
	    * Unselects query value. This is useful only if query value can be used.
	    * This method still keeps the value
	    */
		IMPORT_C void UnselectQueryValueL();
		
		/**
	    * Sets query value for text16 property. This is useful only if data type is text16 and if query value can be used.
	    * This method also selects query value.
	    * @param aValue Specifies new value for query value.
	    */
		IMPORT_C void SetQueryValueText16L( const TDesC16& aValue );
		
		/**
	    * Sets query value for text8 property. This is useful only if data type is text8 and if query value can be used.
	    * This method also selects query value.
	    * @param aValue Specifies new value for query value.
	    */
		IMPORT_C void SetQueryValueText8L( const TDesC8& aValue );
		
		/**
	    * Sets query value for number property. This is useful only if data type is number and if query value can be used.
	    * This method also selects query value.
	    * @param aValue Specifies new value for query value.
	    */
		IMPORT_C void SetQueryValueIntL( TInt aValue );
		
		/**
	    * Sets query value for boolean property. This is useful only if data type is boolean and if query value can be used.
	    * This method also selects query value.
	    * @param aValue Specifies new value for query value.
	    */
		IMPORT_C void SetQueryValueBoolL( TBool aValue );
		
		/**
	    * Sets query value for date property. This is useful only if data type is date and if query value can be used.
	    * This method also selects query value.
	    * @param aValue Specifies new value for query value.
	    */
		IMPORT_C void SetQueryValueDateL( const TTime& aValue );
		
		/**
	    * Sets query value for time property. This is useful only if data type is time and if query value can be used.
	    * This method also selects query value.
	    * @param aValue Specifies new value for query value.
	    */
		IMPORT_C void SetQueryValueTimeL( const TTime& aValue );
		
		/**
	    * Size of data
	    * @return Size of internal data
	    */
		IMPORT_C TInt DataSize();
			
	private:
		/**
	    * Basic constructor.
	    */
		CSyncMLFilterProperty();
		

	private:
		HBufC* 							iDisplayName;
		TSyncMLFilterPropertyDataType 	iDataTypeForDefaultValues;
		TSyncMLFilterPropertyDataType 	iDataTypeForQueryValue;
		TUint 							iMaxTextLength;
		
		RPointerArray<HBufC16>		 	iDefaultValueText16List;
		RPointerArray<HBufC8> 			iDefaultValueText8List;
		RArray<TInt>					iDefaultValueIntOrBoolList;
		RPointerArray<TTime> 			iDefaultValueDateOrTimeList;
		
		TBool 							iCanUseQueryValue;
		TBool 							iSupportsMultpleSelection;
		TBool							iSupportsEmptySelection;
		
		RArray<TBool>					iDefaultValueSelected;
		TBool							iQueryValueSelected;
		
		HBufC16*						iQueryValueText16;
		HBufC8*							iQueryValueText8;
  		TInt 							iQueryValueIntOrBool;
	  	TTime 							iQueryValueDateOrTime;

	};
	
	
/**
* Filter Class.
*
* @lib syncmldatafilter.lib
*/
class CSyncMLFilter : public CBase
	{
	public:
		/**
    	* Symbian two-phased constructor.
    	*/
		IMPORT_C static CSyncMLFilter* NewLC();
		
		/**
    	* Symbian two-phased constructor.
    	* @param aReader TResourceReader for recource file that includes needed information to initialize filter.
    	*/
		IMPORT_C static CSyncMLFilter* NewLC( TResourceReader& aReader );
		
		/**
    	* Symbian two-phased constructor.
    	* @param aStream RReadStream for stream that includes needed information to initialize filter.
    	*/
		IMPORT_C static CSyncMLFilter* NewLC( RReadStream& aStream );
		
		/**
		* Destructor.
		*/		
		IMPORT_C ~CSyncMLFilter();

		/**
	    * Externalizes filter.
	    * @param aStream Specifies stream where filter is externalized.
	    */
		IMPORT_C void ExternalizeL( RWriteStream& aStream ) const;
		
		/**
	    * ID of filter.
	    * @return TUint ID of the filter.
	    */
		IMPORT_C TUint FilterId() const;
		
		/**
	    * Name of filter.
	    * @return TDesC Name of the filter.
	    */
		IMPORT_C const TDesC& DisplayName() const
		;
		/**
	    * Description of filter.
	    * @return TDesC Description of the filter.
	    */
		IMPORT_C const TDesC& DisplayDescription() const;
		
		/**
	    * Filter enable/disable information.
	    * @return TBool ETrue if filter is enabled. Otherwise EFalse is returned.
	    */
		IMPORT_C TBool Enabled() const;
		
		/**
	    * Set filter enable/disable information.
	    * @param aEnabled ETrue if filter enabled and EFalse is filter is disabled
	    */
		IMPORT_C void SetEnabledL( const TBool aEnabled );
		
		/**
	    * Information about server capabilities to support this filter.
	    * @return TBool ETrue if filter is supported by server. Otherwise EFalse is returned.
	    */
		IMPORT_C TBool SupportedByServer() const;
		
		/**
	    * Set information about server capabilities to support this filter.
	    * @param aSupported ETrue if filter is supported by server and EFalse if it is not supported.
	    */
		IMPORT_C void SetSupportedByServerL( const TBool aSupported );
		
		/**
	    * Information about match type effect to filter.
	    * @return TBool ETrue if match type affect to filter. Otherwise EFalse is returned.
	    */
		IMPORT_C TBool MatchTypeSupported() const;
		
		/**
	    * Set information about match type effect to filter.
	    * @param aSupported ETrue if match type affect to filter and EFalse if it does not affect.
	    */
		IMPORT_C void SetMatchTypeSupported( const TBool aSupported );
		
		/**
	    * Properties of filter.
	    * @return RPointerArray Properties of filter.
	    */
		IMPORT_C RPointerArray<CSyncMLFilterProperty>& FilterProperties();
		
		/**
	    * Size of data
	    * @return Size of internal data
	    */
		IMPORT_C TInt DataSize();
		
	private:
		/**
	    * Basic constructor.
	    */
		CSyncMLFilter();
	

	private:
		TUint 									iFilterId;
  		HBufC* 									iDisplayName;
  		HBufC* 									iDisplayDescription;
  		TBool 									iEnabled;
  		TBool 									iSupportedByServer;
  		TBool 									iMatchTypeSupported;
  		RPointerArray<CSyncMLFilterProperty>	iProperties;
	
	};

#endif

// End of file
