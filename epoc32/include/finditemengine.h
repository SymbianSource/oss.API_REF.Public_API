/*
* Copyright (c) 2002-2006 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:  Find Item API offers methods for parsing phone numbers, email 
*                addresses, URL addresses and URI addresses from given text.
*
*/


#ifndef FINDITEMENGINE_H
#define FINDITEMENGINE_H

//  INCLUDES
#include <e32base.h>

// CLASS DECLARATION

/**
* Class is used to parse phone numbers and email, URL and URI addresses from 
* given text. Find Item API offers methods for parsing phone numbers and 
* e-mail, URL and URI addresses from the given text. The API consist of the 
* CFindItemEngine class.
*
* Usage:
* 
* @code
*  #include <finditemengine.h>
*
*  // SFoundItem instance
*  CFindItemEngine::SFoundItem item;
*
*  // Some text
*  TBufC<256> strSomeText(_L("Mail to me@someplace.com or call 040 1234567. 
*  You can also tune in to audio feed at rtsp://someplace.com/somefeed.ra."));
*	
*  // First the user has to create an instance of CFindItemEngine by using the
*  // factory method NewL(). The method takes two parameters. The first 
*  // parameter defines the text to be searched from and the second parameter 
*  // tells what exactly is being looked for.
*  CFindItemEngine* singleSearch = CFindItemEngine::NewL(strSomeText, 
*                   CFindItemEngine::EFindItemSearchMailAddressBin);
*
*  // The passed text is parsed in construction, and found items can be fetched 
*  // by using the ItemArray() method. It returns a constant array containing 
*  // all the found items. The interface offers also helper functions for 
*  // handling the item array by itself. 
*
*  // Get count of found items.
*  TInt count(singleSearch->ItemCount());
*
*  // Get currently selected item (me@someplace.com) to the result1 variable.
*  singleSearch->Item(item);
*  TPtrC16 result1(strSomeText.Mid(item.iStartPos, item.iLength));
*
*  // Deallocate memory
*  delete singleSearch;
*
*  // Create an instance of FindItemEngine and look for all possible 
*  // things (cases work as binary mask).
*  CFindItemEngine* multiSearch = CFindItemEngine::NewL(strSomeText,
*                   (CFindItemEngine::TFindItemSearchCase)
*                   (CFindItemEngine::EFindItemSearchPhoneNumberBin |           
*                   CFindItemEngine::EFindItemSearchURLBin | 
*                   CFindItemEngine::EFindItemSearchMailAddressBin | 
*                   CFindItemEngine::EFindItemSearchScheme));
*
*  // Get count of found items.
*  TInt count2(multiSearch->ItemCount());
*
*  // Get currently selected item to the result2 variable.
*  multiSearch->Item(item);
*
*  // Debug print all items and their type.
*  for( TInt i=0; i<count2; i++)
*      {
*      TPtrC16 result2(strSomeText.Mid(item.iStartPos, item.iLength));
*      RDebug::Print(_L("Found type %d item:"), item.iItemType);
*      RDebug::Print(_L("%S"), &result2);
*      multiSearch->NextItem(item);
*      }
*
*  // Deallocate memory
*  delete multiSearch;
* @endcode
*
* @lib commonengine.lib
* @since S60 2.0
*/

class CFindItemEngine :public CBase
    {
    public:

        /**
        * Enumeration to define the search case. 
        * Multiple enumerations can be used as binary mask.
        */
        enum TFindItemSearchCase
            {
            /** Searches phone numbers.
            */
			EFindItemSearchPhoneNumberBin = 4, 
            /** Searches mail addresses.
            */
            EFindItemSearchMailAddressBin = 8,
            /** Searches fixed start URLs ("http://", "https://", "rtsp://"), "www.", "wap." and IPv4 addresses.
            */
            EFindItemSearchURLBin  = 16,
            /** Searches for all URIs containing a scheme.
            */
            EFindItemSearchScheme  = 32
            };

        /** 
        * Struct to contain an item.
        */
        struct SFoundItem
            {
            /**Start position of the found item.
            */
            TInt iStartPos;
            /** Length of the found item (characters).
            */
            TInt iLength;
			/** Search case of the found item
			*/
            TFindItemSearchCase iItemType;
			};

    public:  // Constructors and destructor
        
        /**
        * Two-phase constructor method that is used to create a new instance
        * of the CFindItemEngine class. This instance can then be queried for
        * the items defined by the second parameter. The actual search is 
        * executed during construction.
        *
        * @param aText will be parsed.
        * @param aSearchCase identifies what items are we looking for: 
        * EFindItemSearchPhoneNumberBin
        * EFindItemSearchMailAddressBin
        * EFindItemSearchURLBin
        * EFindItemSearchScheme
        * Any combination of these flags can be given as a bit mask.
        * @return a pointer to an new instance of CFindItemEngine class.
        *
        * @panic ENoSearchCase in debug build if there is no valid search case.
        * @panic EItemOutOfDocumentRange in debug build if item's position 
        * and/or length is out of the document's range.
        * @leave one of the Symbian error codes.
        */
        IMPORT_C static CFindItemEngine* NewL( const TDesC& aText, 
                                               const TFindItemSearchCase aSearchCase );

        /**
        * Two-phase constructor method that is used to create a new instance
        * of the CFindItemEngine class. This instance can then be queried for
        * the items defined by the second parameter. The actual search is 
        * executed during construction.
        *
        * @param aText will be parsed.
        * @param aSearchCase identifies what items are we looking for: 
        * EFindItemSearchPhoneNumberBin
        * EFindItemSearchMailAddressBin
        * EFindItemSearchURLBin
        * EFindItemSearchScheme
        * Any combination of these flags can be given as a bit mask.
        * @param aMinNumbers defines minimun count of numbers in a string that 
        * the string is considered as a phone number when phone numbers are 
        * searched.
        * @return a pointer to an new instance of CFindItemEngine class.
        *
        * @panic ENoSearchCase in debug build if there is no valid search case.
        * @panic EItemOutOfDocumentRange in debug build if item's position 
        * and/or length is out of the document's range.
        * @leave one of the Symbian error codes.
        */
        IMPORT_C static CFindItemEngine* NewL( const TDesC& aText, 
                                               const TFindItemSearchCase aSearchCase,
                                               const TInt aMinNumbers );

        /**
        * Destructor.
        */
        IMPORT_C virtual ~CFindItemEngine();

    public:
        /**
        * Gets the currently 'selected' item in the array of found items. 
        *
        * @param aItem contains the currently selected item after returning.
        * @return ETrue if the item was found. EFalse if the item wasn't found.
        */
        IMPORT_C TBool Item( SFoundItem& aItem );

        /**
        * Gets the next found item relative to the currently selected item 
        * and moves the selection to point to the next item in the array of 
        * found items. 
        *
        * @param aItem contains the next item after returning.
        * @return ETrue if the item was found. EFalse if there's no next item.
        */
        IMPORT_C TBool NextItem( SFoundItem& aItem );

        /**
        * Gets the previous found item relative to the currently selected 
        * item and moves the selection to point to the previous item in the 
        * array of found items.. 
        *
        * @param aItem contains the previous item after returning.
        * @return ETrue if the item was found. EFalse if there's no previous item.
        */
        IMPORT_C TBool PrevItem( SFoundItem& aItem );
		
        /**
        * Gets the array of found items. Returns a constant pointer to the 
        * found items array of the CFindItemEngine instance. The items cannot
        * be modified through this pointer, only accessed. The ownership of 
        * the array stays with CFindItemEngine.
        *
        * @return a constant pointer to the array of found items. Ownership 
        * stays with CFindItemEngine.
        */
        IMPORT_C const CArrayFixFlat<SFoundItem>* ItemArray() const;

        /**
        * Gets the current position (or the position of the currently selected item) 
        * in the found items array.
        *
        * @return the current position in the found items array of the 
        * CFindItemEngine instance. If no items are in the array, zero is 
        * returned.
        */
		IMPORT_C TInt Position() const;	
	
        /**
        * Resets the position in item array to zero (beginning of the array).
        */
        IMPORT_C void ResetPosition();

        /**
        * Gets the number of items in the found items array.
        *
        * @return the number of items in the found items array. 
        */
		IMPORT_C TInt ItemCount() const;
		
        /**
        * Executes a new search with the already created CFindItemEngine 
        * instance. The position in the found items array is reset to the 
        * beginning of the array.
        *
        * @param aText will be parsed.
        * @param aSearchCase identifies what items are we looking for: 
        * EFindItemSearchPhoneNumberBin
        * EFindItemSearchMailAddressBin
        * EFindItemSearchURLBin
        * EFindItemSearchScheme
        * Any combination of these flags can be given as a bit mask.
        * @return number of found items.
        *
        * @panic ENoSearchCase in debug build if there is no valid search case.
        * @panic EItemOutOfDocumentRange in debug build if item's position 
        * and/or length is out of the document's range.
        * @leave one of the Symbian error codes.
        */
        IMPORT_C TInt DoNewSearchL( const TDesC& aText, const TFindItemSearchCase aSearchCase);

        /**
        * Executes a new search with the already created CFindItemEngine 
        * instance. The position in the found items array is reset to the 
        * beginning of the array.
        *
        * @param aText will be parsed.
        * @param aSearchCase identifies what items are we looking for: 
        * EFindItemSearchPhoneNumberBin
        * EFindItemSearchMailAddressBin
        * EFindItemSearchURLBin
        * EFindItemSearchScheme
        * Any combination of these flags can be given as a bit mask.
        * @param aMinNumbers defines minimun count of numbers in a string that 
        * the string is considered as a phone number when phone numbers are 
        * searched.
        * @return number of found items.
        *
        * @panic ENoSearchCase in debug build if there is no valid search case.
        * @panic EItemOutOfDocumentRange in debug build if item's position 
        * and/or length is out of the document's range.
        * @leave one of the Symbian error codes.
        */
        IMPORT_C TInt DoNewSearchL( const TDesC& aText, const TFindItemSearchCase aSearchCase, 
                                    const TInt aMinNumbers );

    private:
        
        /**
        * Adds item to search arrays. Adding is done so that arrays are always sorted.
        * If added element would overlap a previously found element, it is not added.
        *
        * @param aStartPos  Start position of the found item
        * @param aLength    Length of found item
        * @param aType      Type of the found item
        */
        void AddItemL( const TInt& aStartPos, const TInt& aLength, 
                       const TFindItemSearchCase& aType );

        /**
        * Search algorithm for searching phone numbers
        *
        * @param aText Text that will be parsed
        * @return Whether any items were found
        */
        TBool SearchPhoneNumberL( const TDesC& aText);  

        /**
        * Search algorithm for searching e-mail addresses
        *
        * @param aText Text that will be parsed
        * @return Whether any items were found
        */
        TBool SearchMailAddressL( const TDesC& aText);  

        /**
        * Search algorithm for searching generic URIs
        *
        * @param aText Text that will be parsed
        * @return Whether any items were found
        */
        TBool SearchGenericUriL( const TDesC& aText);

        /**
        * Search fixed start URLs, i.e. URLs without schema (www., wap.).
        * Also finds IPv4 addresses (*.*.*.*).
        * As a special case, supports deprecated hardcoded schematic addresses finding 
        * (http://, https://, rtsp://) to make sure deprecated search cases work 
        * as they did previously.
        *
        * @param aText Text that will be parsed
        * @param aFindFixedSchemas If true, will find old fixed schematic URLs also
        * @return Whether any items were found
        */
        TBool SearchUrlL( const TDesC& aText, const TBool aFindFixedSchemas);

        /**
        * Parses URL from a token. Is used by SearchUrlL method and if a URL
        * was found it's appended to item array. Note that parsing for generic URIs 
        * is done with SearchGenericUriL -method.
        *
        * @param aType  a Type of URL to seach, i.e.
        *                   www.
        *                   wap.
        *                   IP e.g.127.0.0.1
        * @param        aTokenPtr Pointer to token that will be parsed
        * @param        aTextOffset Offset of the token (start position in the whole text)
        * @return Whether any items were found
        */
        TBool ParseUrlL( const TDesC& aType, const TPtrC& aTokenPtr, const TInt aTextOffset );

        /**
        * Character information methods
        *
        * @param charac a Character to be investigated
        * @return Whether the parameter was a valid for:
        */
        TBool IsValidEmailChar( const TChar& charac ) const; // Login part of the e-mail address
        TBool IsValidEmailHostChar( const TChar& charac ) const; // Host part of the e-mail address
        TBool IsValidPhoneNumberChar( const TChar& charac ) const; // Phone number
        TBool IsValidUrlChar( const TChar& charac ) const; // URL

        /**
        * C++ default constructor.
        */
        CFindItemEngine();

        /**
        * Symbian OS constructor
        *
        * @param aText          Text that will be parsed
        * @param aSearchCase    Identifies what items are we looking for:
        *                           EFindItemSearchPhoneNumberBin
        *                           EFindItemSearchMailAddressBin
        *                           EFindItemSearchURLBin
        *                           EFindItemSearchScheme
        *                       Any combination of these flags can be given
        *                       as a bit mask.
        * @param aMinNumbers    Minimun count of numbers in a string when 
        *                       the string is considered as a phone number.
        */
        void ConstructL( const TDesC& aText, const TFindItemSearchCase aSearchCase, 
                         const TInt aMinNumbers );
        /**
        * Performs the search.
        * Uses search algorithms SearchGenericUriL(), SearchMailAddressL(), 
        * SearchUrlL() and SearchPhoneNumberL().
        *
        * @param aText Reference to the text to be parsed.
        * @param aSearchCase identifies what items are we looking for.
        */
		void PerformSearchL( const TDesC& aText , const TFindItemSearchCase aSearchCase );


        /**
        * Converts arabic numbers to western numbers. 
        * When returning the aBuf contains the modified text.
        *
        * @param aBuf A pointer to the buffer containing the text.
        */
		void ConvertArabicNumbersToWesternNumbers( HBufC* aBuf );

        /**
        * By default, prohibit copy constructor
        */
        CFindItemEngine( const CFindItemEngine& );
        /**
        * Prohibit assigment operator
        */
        CFindItemEngine& operator= ( const CFindItemEngine& );

    private:    // Data
        // Array of all found items.
        CArrayFixFlat<SFoundItem>* iItemArray;
		// Engine's position in the iItemArray and iItemTypeArray.
        TInt iPosition;
        // Minimum count of numbers in a phone number
        TInt iMinNumbers;
    };

#endif      // FINDITEMENGINE_H   
            
// End of File
