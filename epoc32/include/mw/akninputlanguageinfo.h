/*
* Copyright (c) 2002 Nokia Corporation and/or its subsidiary(-ies). 
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0""
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:              
*       Interface class providing information on available input languages
*	    This header is exported
*
*/
















#ifndef __AKNINPUTLANGUAGEINFO_H__
#define __AKNINPUTLANGUAGEINFO_H__

// INCLUDES

#include <e32base.h>

// For TBitFlags
#include <eikdef.h>
#include <bamdesca.h>

#include <babitflags.h>

// Typedefs
typedef TBuf<32> TAknLanguageName;


// CLASS DECLARATIONS

/**
* Input language capabilities
*
*/
class TAknInputLanguageCapabilities
	{
    public:
	    /**
	    * These indices are used to set/clear capabilities.
	    * Terms: 
	    * - multitap refers to capability to enter alphabetic chars by pressing the same key repeatedly 
	    * - predictive refers to the device matching (non-multitap) keypresses with potential words 
	    *	in a dictionary. That is, what words would map to the current set of keypad presses
	    * 
	    * 
	    */
	    enum TAknInputLanguageCapabilityIndex
	        {
	        EMultitap =				0x00000000, 
	        EPredictive =			0x00000001 
	        };

	    /**
	    * C++ Constructor.  Initializes the internal state to "no capabilities"
	    */
	    IMPORT_C TAknInputLanguageCapabilities();

	    /**
	    * Sets the capability at a given index index to the logical value passed 
	    *
	    * @param aCapability	which capability to set
	    * @param aSet			ETrue - enable the capability; EFalse - disable the capability
	    */
	    IMPORT_C void AssignCapability( TInt aCapabilityIndex, TBool aSet ); 

	    /**
	    * Tests a capability
	    *
	    * @param	aCapability		which capability to test
	    * @return	EFalse if the capability is not present; not EFalse otherwise	
	    */
	    IMPORT_C TBool HasCapability( TInt aCapabilityIndex ) const;

	    /**
	    * Sets all capabilities (existing and potential)
	    */
	    IMPORT_C void SetAllCapabilities();

	    IMPORT_C TAknInputLanguageCapabilities FilteredCapabilities( TAknInputLanguageCapabilities& aFilter) const;

	    IMPORT_C TBool HasAnySupport() const;

    private:
	    // Holds the internal state
	    TBitFlags32	iCapabilities;	
	};


/**
* Input Language Item class.
* 
* This object bring together Symbian language code, a language name, and its capabilities
*
* This method is not meant to be derived from.
*
*/
NONSHARABLE_CLASS(CAknInputLanguageItem) : public CBase
	{
    public:
	    /** 
	    * static 2-stage construction of the object. The language name descriptor is copied 
	    * by the time the method returns.
	    *
	    * Normally this is constructed by the class that supplies the language information.  It would 
	    * not normally be called by clients who want to find out about system input languages
	    *
	    * @param	aLanguageCode	Symbian OS language code
	    * @param	aName			Language name to be attached to code
	    * @param	aCapabilities	Sets the capabilities
	    * @return	Fully constructed input language item
	    */
	    static CAknInputLanguageItem* NewL( TLanguage aLanguageCode, const TDesC& aName, TAknInputLanguageCapabilities aCapabilities );

	    /**
	    * C++ destructor
	    *
	    */
	    IMPORT_C ~CAknInputLanguageItem();

	    IMPORT_C TLanguage LanguageCode() const;
	    IMPORT_C TPtrC LanguageName() const;
	    IMPORT_C TAknInputLanguageCapabilities Capabilities() const;
	    
    private:
	    /**
	    * Sets only the langauge code
	    */
	    CAknInputLanguageItem( TLanguage aLanguageCode);
	    /**
	    * 2nd stage construction.  This sets the name and the capabilies
	    */
	    void ConstructL( const TDesC& aName, TAknInputLanguageCapabilities aCapabilities );

    private:
	    TLanguage iLanguageCode;
	    HBufC* iLanguageName;			// Owned
	    TAknInputLanguageCapabilities	iCapabilities;
	    TInt iSpare;					// for expansion
	};

/**
*
* Class to hold a list of CAknInputLanguageItem objects
*
*/
class CAknInputLanguageList : public CArrayPtrFlat<CAknInputLanguageItem>, public MDesCArray
    {
    public:
	    /**
	    * C++ Constructor 
	    *
	    */
	    IMPORT_C CAknInputLanguageList(TInt aGranularity);

	    /**
	    * Destructor
	    *
	    */
	    IMPORT_C ~CAknInputLanguageList();

    public: // from MDesCArray
	    IMPORT_C TInt MdcaCount() const;
	    IMPORT_C TPtrC MdcaPoint(TInt aIndex) const;
    };

/**
*
* Input Language information interface.  This object is instantiated to create a standard interface
* to the native input language services. 
*
*/
class CAknInputLanguageInfo : public CBase
	{
    public:
	    /**
	    * This method returns the input capabilities of a language. The capability object can then 
	    * be queried to see what it is capable of.
	    *
	    * @param	aLanguageId		Symbian language code
	    * @return	a structure indicating what the language is capable of
	    */
	    virtual TAknInputLanguageCapabilities LanguageCapabilitiesFromLanguage(TLanguage aLanguageId) = 0;

	    /**
	    * Get the language name that corresponds to the passed-in Symbian OS language code.
	    * This name should be localized, or not, depending upon the policy decided for the product
	    * 
	    * @param	aLanguageCode	- language code for the language whose name is required
	    * @return	TAknLanguageName - buffer containing 
	    */
	    virtual TAknLanguageName LanguageName( TLanguage aLanguageCode ) const = 0;

	    /**
	    * Provide a language list corresponding to the input list of SymbianOS language codes.
	    * The order of the languages in the output list is that order implemented in the 
	    * interface object, and the order of the input list of language codes is ignored.
	    *
	    * @param aInputLanguageList Append to this list; 
	    * @param aLanguageCodeList	Append only languages whose code is in this list. If Null is passed, then no language code filtering is done
	    * @param aCapabilityFilter	Append only languages with capabilities set in this filter.
	    *							If a filter with no capabilities whatsoever is passed, then all capabilities are included
	    *
	    */ 
	    virtual void AppendLanguagesL( 
		    CAknInputLanguageList* aInputLanguageList, 
		    CArrayFix<TInt>* aLanguageCodeList,
		    TAknInputLanguageCapabilities& aCapabilityFilter ) = 0;
	    
	    /**
	    * Appends to an externally owned array of CAknInputLanguageItem-s. These can be interrogated to provide 
	    * information upon return.
	    *
	    * @param aInputLanguageList		Passed-in array is appended to by this method
	    */
	    virtual void AppendAvailableLanguagesL( CAknInputLanguageList* aInputLanguageList ) = 0;

	    /**
	    * Return a langauge that is suitable in the product for a URL input language
	    *
	    * @return	TLanguage	A language code for the designated URL language
	    */
	    virtual TLanguage UrlLanguage() const = 0;
	};

/**
* This factory class exists to supply an available input language interface 
*/
class AknInputLanguageInfoFactory
	{
    public:
	    /**
	    * Factory method to return a generic object from which information on available
	    * languages can be obtained.
	    *
	    * @return a pointer to a fully constructed object conformant to CAknInputLanguageInfo 
	    */
	    IMPORT_C static CAknInputLanguageInfo* CreateInputLanguageInfoL();
	};

#endif // __AKNINPUTLANGUAGEINFO_H__

// End of File
