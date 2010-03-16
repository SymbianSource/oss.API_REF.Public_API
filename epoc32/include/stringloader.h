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
* Description:  String Loader API provides methods for loading resource
*                strings and formatting them.
*
*/

#ifndef STRINGLOADER_H
#define STRINGLOADER_H

// INCLUDE FILES
#include    <coemain.h>
#include    <biditext.h>

// CLASS DECLARATION

/**
* Class provides methods to load and format resource strings.
* String Loader API provides an interface to load and format resource strings
* that may contain parameter(s) (\%U for text or or \%N for numerical).
* Resource strings are usually defined in an RSS file.
*
* The API consists of the StringLoader class. All methods are static, so there is
* no need to explicitly allocate memory for the interface class.
* The implementation needs a CCoeEnv instance to access for example the
* resource files.
*
*
* Usage:
*
* Applications load and format resource strings from normal resources with
* static methods of the StringLoader class. The loading is done with the LoadL
* and LoadLC methods and with the Load method in situations where memory
* allocation from the heap is not possible. Formatting is done automatically
* after loading in the LoadL and LoadLC methods, but it can also be done
* separately with the Format method in situations where memory allocation from
* the heap is not possible. For reading the resource strings with the Load,
* LoadL and LoadLC methods, the user should provide a pointer to CCoeEnv for
* efficiency reasons. If the pointer is not provided, the implementation uses
* the CCoeEnv::Static method internally to get it.
*
* Different size displays can handle different length strings. To take full
* advantage of this fact, StringLoader supports resource strings with multiple
* options for string separated by 0x0001 character. Each such string can
* contain same or different sub string keys (\%U and \%N). StringLoader returns
* all strings, it is responsibility of the caller to parse the result and
* choose the proper string to display.
*
* Setting the maximum sub string length may be done in the text resources. Sub
* string maximum lengths can be localized separately for every language.
* The maximum sub string length is of the format: \%U[NN]
* where NN is a number [01..99]. Please note that NN must always consist of two
* characters, i.e. if the sub string maximum length is eight characters, the
* value to be used is 08, not plain 8. If the number of characters exceeds the
* maximum length, the sub string is cut to fit and the last character is
* replaced with an ellipsis character.
*
* The following examples describe the usage of the String Loader API.
*
* Usage when one TInt is added:
*
* @code
*  // In .loc -file
*  // #define text_example "You have %N undone tasks."
*
*  // In .rss -file
*  // RESOURCE TBUF r_text_example { buf = text_example; }
*
*  // (In the .cpp -file)
*  #include <stringloader.h>
*
*  // Get CCoeEnv instance
*  CEikonEnv* iEikonEnv = CEikonEnv::Static();
*
*  TInt number( 324 );
*
*  // Method reads a resource string with memory allocation
*  // and replaces all %N-strings in it with a replacement TInt.
*  // The heap descriptor must be destroyed when it is no longer needed.
*  // iEikonEnv is needed for loading the resource string.
*  HBufC* stringholder = StringLoader::LoadL( R_TEXT_EXAMPLE, number, iEikonEnv );
*
*  // The 'number' is added to the resource string. The result is
*  // that stringholder points to a heap descriptor containing string:
*  // "You have 324 undone tasks."
*
*  // Delete the heap descriptor
*  delete stringholder;
* @endcode
*
*
* Usage when several strings are added:
*
* Index can be included to parameters. Several parameters can have same index,
* if same replacement is needed multiple times.
*
* @code
*  // In .loc -file
*  // #define text_example "I'm %2U%1U %3U%0U fine."
*
*  // In .rss -file
*  // RESOURCE TBUF r_text_example { buf = text_example; }
*
*  // In the .cpp -file
*  #include <stringloader.h>
*
*  // Get CCoeEnv instance
*  CEikonEnv* iEikonEnv = CEikonEnv::Static();
*
*  CDesCArrayFlat* strings = new CDesCArrayFlat( 4 );
*  CleanupStack::PushL( strings );
*
*  strings->AppendL( _L("orking") ); //First string
*
*  strings->AppendL( _L("ll") ); //Second string
*
*  strings->AppendL( _L("sti") ); //Third string
*
*  strings->AppendL( _L("w") ); //Fourth string
*
*  // Method reads a resource string with memory allocation and replaces
*  // the %(index)U strings in it with replacement strings from an array.
*  // The heap descriptor must be destroyed when it is no longer needed.
*  // iEikonEnv is needed for loading the resource string.
*  HBufC* stringholder = StringLoader::LoadL( R_TEXT_EXAMPLE, *strings, iEikonEnv );
*
*  // Four strings are added to the resource string. The result is
*  // that stringholder points to a heap descriptor containing string:
*  // "I'm still working fine."
*
*  // Pop and delete strings array
*  CleanupStack::PopAndDestroy();
*
*  // Delete the heap descriptor
*  delete stringholder;
* @endcode
*
*
* Usage with scalable UI support:
*
* @code
*  // In .loc -file
*  // #define TEXT_EXAMPLE "You have missed %N messages from %U."<0x0001>"Missed %N msgs from %U."<0x0001>"Missed %N msgs."
*
*  // In .rss -file
*  // RESOURCE TBUF R_TEXT_EXAMPLE { buf = TEXT_EXAMPLE; }
*
*  // In the .cpp -file
*  #include <stringloader.h>
*
*  // Get CCoeEnv instance
*  CEikonEnv* iEikonEnv = CEikonEnv::Static();
*
*  TInt number( 12 );
*  _LIT(name, "John Doe");
*
*  // Method reads a resource string with memory allocation,
*  // replaces all %N strings in it with a replacement TInt and
*  // all %U strings in it with a replacement string.
*  // The heap descriptor must be destroyed  when it is no longer needed.
*  // iEikonEnv is needed for loading the resource string.
*  HBufC* stringholder = StringLoader::LoadL( R_TEXT_EXAMPLE, name, number, iEikonEnv );
*
*  // The number and name are added to the resource string. The result is
*  // that stringholder points to a heap descriptor containing string:
*  // "You have missed 12 messages from John Doe.\001Missed 12 msgs from John
*  // Doe.\001Missed 12 msgs."
*
*  // Delete the heap descriptor
*  delete stringholder;
* @endcode
*
*
* Error handling:
*
* The leave mechanism of the Symbian OS environment is used to handle memory
* exhaustion. The panic mechanism is used to handle programming errors while
* debugging. RStringLoader panics for seven different reasons. The panic 
* category is named STRINGLOADER. The panic codes are:
*
* - ETooFewArguments        = 0 (Unsolved parameters in resource string.)
* - ETooManyArguments       = 1 (Already solved all parameters in  resource string.)
* - EKeyStringNotFound      = 2 (The key string wasn't found in formatting.)
* - EInvalidIndex           = 3 (Invalid index in Format-method)
* - EDescriptorTooSmall     = 4 (Too small destination descriptor.)
* - ECCoeEnvNotInitialized  = 5 (CCoeEnv is not initialized)
* - EInvalidSubstitute      = 6 (Substituted string contains KSubStringSeparator)
*
* @lib commonengine.lib
* @since S60 2.0
*/
class StringLoader
    {
    public:

        /**
        * Load( TDes&, TInt ) reads a resource string without memory
        * allocation. The loaded string is stored in the destination TDes&.
        * Because this method doesn't allocate memory the destination 
        * descriptor must be long enough.
        *
        * @param aResourceId The numeric ID of the resource string to be read.
        * @param aDest Reference to the descriptor where the resource string
        *              is loaded.
        * @param aLoaderEnv Pointer to the control environment. If user doesn't
        *                   give this, CCoeEnv::Static is called to get it.
        *
        * @panic ECCoeEnvNotInitialized Parameter aLoaderEnv is NULL and 
        *                               CCoeEnv::Static returned NULL.
        */
        IMPORT_C static void Load( TDes& aDest, TInt aResourceId,
                                   CCoeEnv* aLoaderEnv = NULL );

        /**
        * Format( TDes&, TDesC&, TInt, TInt ) formats a resource string without
        * memory allocation. The formatted string is stored in the destination
        * TDes&. Because this method doesn't allocate memory the destination 
        * descriptor must be long enough. In aPosition -1 means that there is
        * no index in the key string and all \%N-strings in the original string 
        * are replaced with aSubs. In debug builds the Symbian OS panic 
        * mechanism is used to notify programming errors.
        *
        * @param aDest Reference to the descriptor where the resource string
        *              is formatted.
        * @param aSource Reference to the original string.
        * @param aPosition The index of the key string.
        * @param aSubs The replacing TInt.
        *
        * @panic EInvalidIndex In debug build if the index of the key string 
        *                      is invalid.
        * @panic EDescriptorTooSmall In debug build if the length of the 
        *                            destination descriptor is to small.
        * @panic EKeyStringNotFound In debug build if the key string 'N' wasn't
        *                           found, aDest is empty.
        *
        * One small sample describing the usage of the method.
        * @code
        * // Load example string "%0N %1N" defined in rss- and loc-files.
        * // %0N stands for area code and %1N for phone number.
        * HBufC* telFormat = StringLoader::LoadLC( R_TEL_FORMAT, iEikonEnv );
        *
        * // The replacing number.
        * TInt areaCode(123);
        *
        * StringLoader::Format( destBuf, telFormat, 
        *                       0, // %0N stands for area code
        *                       areaCode );
        *
        * // After returning destBuf contains string "123 %1N".
        */
        IMPORT_C static void Format( TDes& aDest, const TDesC& aSource,
                                   TInt aPosition, TInt aSubs );

        /**
        * Format( TDes&, TDesC&, TInt, TDesC& ) formats a resource string
        * without memory allocation. The formatted string is stored in the
        * destination TDes&. Because this method doesn't allocate memory the 
        * destination descriptor must be long enough. In aPosition -1 means 
        * that there is no index in the key string and all \%U-strings in the
        * original string are replaced with aSubs. In debug builds the 
        * Symbian OS panic mechanism is used to notify programming errors.
        *
        * @param aDest Reference to the descriptor where the resource string
        *              is formatted.
        * @param aSource Reference to the original string.
        * @param aPosition The index of the key string.
        * @param aSubs Reference to the replacing string.
        *       
        * @panic EInvalidIndex In debug build if the index of the key string 
        *                      is invalid.
        * @panic EDescriptorTooSmall In debug build if the length of the 
        *                            destination descriptor is to small.
        * @panic EKeyStringNotFound In debug build if the key string 'U' wasn't
        *                           found, aDest is empty.
        *
        * One small sample describing the usage of the method.
        * @code
        * // Load example string "%0U %1U" defined in rss- and loc-files.
        * // %0U stands for weekday string and %1U for date string.
        * HBufC* timeFormat = StringLoader::LoadLC( R_TIME_FORMAT, iEikonEnv );
        *
        * // The replacing string.
        * _LIT(dateString, "02/10/2006");
        *
        * StringLoader::Format( destBuf, timeFormat, 
        *                       1, // %1U stands for date string
        *                       dateString );
        *
        * // After returning destBuf contains string "%0U 02/10/2006".
        * @endcode
        */
        IMPORT_C static void Format( TDes& aDest, const TDesC& aSource,
                                   TInt aPosition, const TDesC& aSubs );

        /**
        * LoadL( TInt ) reads a resource string with memory allocation. 
        *
        * @param aResourceId The numeric ID of the resource string to be read.
        * @param aLoaderEnv Pointer to the control environment. If user doesn't
        *                   give this, CCoeEnv::Static is called to get it.
        * @return Pointer to a heap descriptor containing the resource
        *         string. The calling program must destroy the heap descriptor
        *         when it is no longer needed.
        *
        * @leave KErrNotSupported Parameter aLoaderEnv is NULL and 
        *                         CCoeEnv::Static returned NULL.
        */
        IMPORT_C static HBufC* LoadL( TInt aResourceId,
                                      CCoeEnv* aLoaderEnv = NULL );

        /**
        * LoadL( TInt, TInt ) reads a resource string with memory
        * allocation and replaces all \%N strings in it with a replacement
        * TInt. In debug builds the Symbian OS panic mechanism is used to 
        * notify programming errors.
        * 
        * @param aResourceId The numeric ID of the resource string to be read.
        * @param aInt The replacing TInt.
        * @param aLoaderEnv Pointer to the control environment. If user doesn't
        *                   give this, CCoeEnv::Static is called to get it.
        * @return Pointer to a heap descriptor containing the formatted
        *         resource string. The calling program must destroy the heap 
        *         descriptor when it is no longer needed.
        *
        * @panic EKeyStringNotFound In debug build if the key string 'N' wasn't
        *                           found in formatting.
        * @leave KErrNotSupported Parameter aLoaderEnv is NULL and 
        *                         CCoeEnv::Static returned NULL.
        */
        IMPORT_C static HBufC* LoadL( TInt aResourceId, TInt aInt,
                                      CCoeEnv* aLoaderEnv = NULL );

        /**
        * LoadL( TInt, const TDesC& ) reads a resource string with memory
        * allocation and replaces all \%U-strings in it with a replacement
        * string. In debug builds the Symbian OS panic mechanism is used to 
        * notify programming errors.
        *
        * @param aResourceId The numeric ID of the resource string to be read.
        * @param aString Reference to the replacing string.
        * @param aLoaderEnv Pointer to the control environment. If user doesn't
        *                   give this, CCoeEnv::Static is called to get it.
        * @return Pointer to a heap descriptor containing the formatted
        *         resource string. The calling program must destroy the heap 
        *         descriptor when it is no longer needed.
        *
        * @panic EKeyStringNotFound In debug build if the key string 'U' wasn't
        *                           found in formatting.
        * @leave KErrNotSupported Parameter aLoaderEnv is NULL and 
        *                         CCoeEnv::Static returned NULL.
        */
        IMPORT_C static HBufC* LoadL( TInt aResourceId,
                                    const TDesC& aString,
                                    CCoeEnv* aLoaderEnv = NULL );

        /**
        * LoadL( TInt, const TDesC&, TInt ) reads a resource string
        * with memory allocation, replaces all \%N-strings in it with
        * a replacement TInt and all \%U-strings in it with a replacement
        * string. In debug builds the Symbian OS panic mechanism is used to 
        * notify programming errors.
        *
        * @param aResourceId The numeric ID of the resource string to be
        *                    read.
        * @param aString Reference to the replacing string.
        * @param aInt The replacing TInt.
        * @param aLoaderEnv Pointer to the control environment. If user doesn't
        *                   give this, CCoeEnv::Static is called to get it.
        * @return Pointer to a heap descriptor containing the formatted
        *         resource string. The calling program must destroy the heap
        *         descriptor when it is no longer needed.
        *
        * @panic EKeyStringNotFound In debug build if the key string 'N' or 'U'
        *                           wasn't found in formatting.
        * @leave KErrNotSupported Parameter aLoaderEnv is NULL and 
        *                         CCoeEnv::Static returned NULL.
        */
        IMPORT_C static HBufC* LoadL( TInt aResourceId, const TDesC& aString,
                                    TInt aInt, CCoeEnv* aLoaderEnv = NULL );

        /**
        * LoadL( TInt, const CArrayFix<TInt>& ) reads a resource string with
        * memory allocation and replaces the \%(index)N-strings in it with
        * replacement TInts from an array. In debug builds the Symbian OS 
        * panic mechanism is used to notify programming errors.
        *
        * @param aResourceId The numeric ID of the resource string to be
        *                    read.
        * @param aInts Reference to the array including the replacing TInts.
        * @param aLoaderEnv Pointer to the control environment. If user doesn't
        *                   give this, CCoeEnv::Static is called to get it.
        * @return Pointer to a heap descriptor containing the formatted
        *         resource string. The calling program must destroy the heap
        *         descriptor when it is no longer needed.
        *
        * @panic ETooManyArguments In debug build if too many replacing 
        *                          elements in aInts array.
        * @leave KErrNotSupported Parameter aLoaderEnv is NULL and 
        *                         CCoeEnv::Static returned NULL.
        */
        IMPORT_C static HBufC* LoadL( TInt aResourceId,
                                    const CArrayFix<TInt>& aInts,
                                    CCoeEnv* aLoaderEnv = NULL );

        /**
        * LoadL( TInt, const MDesCArray& ) reads a resource string with
        * memory allocation and replaces the \%(index)U-strings in it with
        * replacement strings from an array. In debug builds the Symbian OS 
        * panic mechanism is used to notify programming errors.
        *
        * @param aResourceId The numeric ID of the resource string to be read.
        * @param aStrings Reference to the array  including pointers to the
        *                 replacing strings.
        * @param aLoaderEnv Pointer to the control environment. If user doesn't
        *                   give this, CCoeEnv::Static is called to get it.
        * @return Pointer to a heap descriptor containing the formatted
        *         resource string. The calling program must destroy the heap
        *         descriptor when it is no longer needed.        
        *        
        * @panic ETooManyArguments In debug build if too many replacing 
        *                          elements in aStrings 
        *                          array.
        * @leave KErrNotSupported Parameter aLoaderEnv is NULL and 
        *                         CCoeEnv::Static returned NULL.
        */
        IMPORT_C static HBufC* LoadL( TInt aResourceId,
                                    const MDesCArray& aStrings,
                                    CCoeEnv* aLoaderEnv = NULL );

        /**
        * LoadL( TInt, const MDesCArray&, const CArrayFix<TInt>& ) reads a
        * resource string with memory allocation and replaces the
        * \%(index)U-strings in it with replacement strings from an array and
        * the \%(index)N-strings in it with replacement TInts from another
        * array. In debug builds the Symbian OS panic mechanism is used to 
        * notify programming errors.
        *
        * @param aResourceId The numeric ID of the resource string to be read.
        * @param aStrings Reference to the array including pointers to the
        *                 replacing strings.
        * @param aInts Reference to the array including the replacing TInts.
        * @param aLoaderEnv Pointer to the control environment. If user doesn't
        *                   give this, CCoeEnv::Static is called to get it.
        * @return Pointer to a heap descriptor containing the formatted
        *         resource string. The calling program must destroy the heap
        *         descriptor when it is no longer needed.        
        *        
        * @panic ETooManyArguments In debug build if too many replacing 
        *                          elements in aStrings and/or aInts arrays.
        * @leave KErrNotSupported Parameter aLoaderEnv is NULL and 
        *                         CCoeEnv::Static returned NULL.
        */
        IMPORT_C static HBufC* LoadL( TInt aResourceId,
                                    const MDesCArray& aStrings,
                                    const CArrayFix<TInt>& aInts,
                                    CCoeEnv* aLoaderEnv = NULL );
        /**
        * LoadLC( TInt ) reads a resource string with memory allocation and
        * pushes the string onto the cleanup stack.
        *
        * @param aResourceId The numeric ID of the resource string to be read.
        * @param aLoaderEnv Pointer to the control environment. If user doesn't
        *                   give this, CCoeEnv::Static is called to get it.
        * @return Pointer to a heap descriptor containing the resource
        *         string. This pointer is in the cleanup stack. The calling 
        *         program should pop and destroy the heap descriptor when it is
        *         no longer needed.
        *        
        * @leave KErrNotSupported Parameter aLoaderEnv is NULL and 
        *                         CCoeEnv::Static returned NULL.
        */
        IMPORT_C static HBufC* LoadLC( TInt aResourceId,
                                        CCoeEnv* aLoaderEnv = NULL );

        /**
        * LoadLC( TInt, TInt ) reads a resource string with memory
        * allocation, replaces all \%N-strings in it with a replacement
        * TInt and pushes the string onto the cleanup stack. In debug builds
        * the Symbian OS panic mechanism is used to notify programming errors.
        *
        * @param aResourceId The numeric ID of the resource string to be read.
        * @param aInt the replacing TInt.
        * @param aLoaderEnv Pointer to the control environment. If user doesn't
        *                   give this, CCoeEnv::Static is called to get it.
        * @return pointer to a heap descriptor containing the formatted
        *         resource string. This pointer is in the cleanup stack. 
        *         The calling program should pop and destroy the heap 
        *         descriptor when it is no longer needed.
        *
        * @panic EKeyStringNotFound In debug build if the key string 'N' wasn't
        *                           found in formatting.
        * @leave KErrNotSupported Parameter aLoaderEnv is NULL and 
        *                         CCoeEnv::Static returned NULL.
        */
        IMPORT_C static HBufC* LoadLC( TInt aResourceId, TInt aInt,
                                        CCoeEnv* aLoaderEnv = NULL );

        /**
        * LoadLC( TInt, const TDesC& ) reads a resource string with memory
        * allocation, replaces all \%U-strings in it with a replacement
        * string and pushes the string onto the cleanup stack. In debug builds
        * the Symbian OS panic mechanism is used to notify programming errors.
        *
        * @param aResourceId The numeric ID of the resource string to be read.
        * @param aString Reference to the replacing string.
        * @param aLoaderEnv Pointer to the control environment. If user doesn't
        *                   give this, CCoeEnv::Static is called to get it.
        * @return Pointer to a heap descriptor containing the formatted
        *         resource string. This pointer is in the cleanup stack.
        *         The calling program should pop and destroy the heap 
        *         descriptor when it is no longer needed.
        *
        * @panic EKeyStringNotFound In debug build if the key string 'U' wasn't
        *                           found in formatting.
        * @leave KErrNotSupported Parameter aLoaderEnv is NULL and 
        *                         CCoeEnv::Static returned NULL.
        */
        IMPORT_C static HBufC* LoadLC( TInt aResourceId,
                                    const TDesC& aString,
                                    CCoeEnv* aLoaderEnv = NULL );

        /**
        * LoadLC( TInt, const TDesC&, TInt ) reads a resource string
        * with memory allocation, replaces all \%N-strings in it with
        * a replacement TInt and the first \%U-strings in it with a replacement
        * string and pushes the string onto the cleanup stack. In debug builds
        * the Symbian OS panic mechanism is used to notify programming errors.
        *
        * @param aResourceId The numeric ID of the resource string to be
        *                    read.
        * @param aString Reference to the replacing string.
        * @param aInt The replacing TInt.
        * @param aLoaderEnv Pointer to the control environment. If user doesn't
        *                   give this, CCoeEnv::Static is called to get it.
        * @return Pointer to a heap descriptor containing the formatted
        *         resource string. This pointer is in the cleanup stack.
        *         The calling program should pop and destroy the heap 
        *         descriptor when it is no longer needed.
        *
        * @panic EKeyStringNotFound In debug build if the key string 'N' or 'U'
        *                           wasn't found in formatting.
        * @leave KErrNotSupported Parameter aLoaderEnv is NULL and 
        *                         CCoeEnv::Static returned NULL.
        */
        IMPORT_C static HBufC* LoadLC( TInt aResourceId, const TDesC& aString,
                                    TInt aInt, CCoeEnv* aLoaderEnv = NULL );

        /**
        * LoadLC( TInt, const CArrayFix<TInt>& ) reads a resource string with
        * memory allocation, replaces the \%(index)N-strings in it with
        * replacement TInts from an array and pushes the string onto the
        * cleanup stack. In debug builds the Symbian OS panic mechanism is 
        * used to notify programming errors.
        *
        * @param aResourceId The numeric ID of the resource string to be
        *                    read.
        * @param aInts Reference to the array including the replacing TInts.
        * @param aLoaderEnv Pointer to the control environment. If user doesn't
        *                   give this, CCoeEnv::Static is called to get it.
        * @return Pointer to a heap descriptor containing the formatted
        *         resource string. This pointer is in the cleanup stack.
        *         The calling program should pop and destroy the heap 
        *         descriptor when it is no longer needed.
        *
        * @panic ETooManyArguments In debug build if too many replacing 
        *                          elements in aInts array.
        * @leave KErrNotSupported Parameter aLoaderEnv is NULL and 
        *                         CCoeEnv::Static returned NULL.
        */
        IMPORT_C static HBufC* LoadLC( TInt aResourceId,
                                    const CArrayFix<TInt>& aInts,
                                    CCoeEnv* aLoaderEnv = NULL );

        /**
        * LoadLC( TInt, const MDesCArray& ) reads a resource string with
        * memory allocation, replaces the \%(index)U-strings in it with
        * replacement strings from an array and pushes the string onto the
        * cleanup stack. In debug builds the Symbian OS panic mechanism is 
        * used to notify programming errors.
        *
        * @param aResourceId The numeric ID of the resource string to be read.
        * @param aStrings Reference to the array  including pointers to the
        *                 replacing strings.
        * @param aLoaderEnv Pointer to the control environment. If user doesn't
        *                   give this, CCoeEnv::Static is called to get it.
        * @return Pointer to a heap descriptor containing the formatted
        *         resource string. This pointer is in the cleanup stack.
        *         The calling program should pop and destroy the heap 
        *         descriptor when it is no longer needed.
        *
        * @panic ETooManyArguments In debug build if too many replacing 
        *                          elements in aStrings array.
        * @leave KErrNotSupported Parameter aLoaderEnv is NULL and 
        *                         CCoeEnv::Static returned NULL.
        */
        IMPORT_C static HBufC* LoadLC( TInt aResourceId,
                                    const MDesCArray& aStrings,
                                    CCoeEnv* aLoaderEnv = NULL );

        /**
        * LoadLC( TInt, const MDesCArray&, const CArrayFix<TInt>& ) reads a
        * resource string with memory allocation, replaces the
        * \%(index)U-strings in it with replacement strings from an array and
        * the \%(index)N-strings in it with replacement TInts from another
        * array and pushes the string onto the cleanup stack. In debug builds
        * the Symbian OS panic mechanism is used to notify programming errors.
        *
        * @param aResourceId The numeric ID of the resource string to be read.
        * @param aStrings Reference to the array including pointers to the
        *                 replacing strings.
        * @param aInts Reference to the array including the replacing TInts.
        * @param aLoaderEnv Pointer to the control environment. If user doesn't
        *                   give this, CCoeEnv::Static is called to get it.
        * @return Pointer to a heap descriptor containing the formatted
        *         resource string. This pointer is in the cleanup stack.
        *         The calling program should pop and destroy the heap 
        *         descriptor when it is no longer needed.
        *        
        * @panic ETooManyArguments In debug build if too many replacing 
        *                          elements in aStrings and/or aInts arrays.
        * @leave KErrNotSupported Parameter aLoaderEnv is NULL and 
        *                         CCoeEnv::Static returned NULL.
        */
        IMPORT_C static HBufC* LoadLC( TInt aResourceId,
                                    const MDesCArray& aStrings,
                                    const CArrayFix<TInt>& aInts,
                                    CCoeEnv* aLoaderEnv = NULL );

    private:

        /**
        * C++ default constructor.
        */
        StringLoader();

        // Prohibit copy constructor
        StringLoader( const StringLoader& );
        // Prohibit assigment operator
        StringLoader& operator= ( const StringLoader& );

        /**
		* FormatStringL( const TDesC&, const TDesC&, const TDesC& ) finds the
        * keystring from the source string and replaces it with the
        * replacement string.
        *
        * @param aSource Reference to the source string.
        * @param aKey Reference to the keystring.
        * @param aSubs Reference to the replacing string.
        * @param aDir directionality of the source text
        * @param aFound ETrue if there were any strongly directional 
        *               characters and EFalse if there were none
        * @return Pointer to a heap descriptor containing the formated string.
        */
        static HBufC* FormatStringL(
            const TDesC& aSource,
            const TDesC& aKey,
            const TDesC& aSubs,
            TBidiText::TDirectionality aDir
            );

        /**
		* FormatStringL( const TDesC&, const TDesC&, const TDesC& ) finds the
        * keystring from the source string and replaces it with the
        * replacement string.
        *
        * @param aSource Reference to the source string.
        * @param aKey Reference to the keystring.
        * @param aSubs Reference to the replacing string.
        * @param aDirectionality directionality of the source text
        * @param aParamCount Keeps track of remaining parameters.
        *        Value KUnknownCount denotes that count is not known yet.
        *        Value may be updated by this method to reflect change in count.
        * @param aSubCount Number of '|' separated substrings.
        *        Value KUnknownCount denotes that count is not known yet.
        * @return Pointer to a heap descriptor containing the formated string.
        */
        static HBufC* FormatStringL(
            const TDesC& aSource,
            const TDesC& aKey,
            const TDesC& aSubs,
            TBidiText::TDirectionality aDirectionality,
            TInt& aParamCount,
            TInt aSubCount 
            );

        /**
		* FormatStringL( HbufC*, const CArrayFix<TInt>&, TInt ) finds the
        * \%(index)N-keystrings from the source string and replaces it with the
        * replacement TInts.
        * @param aSource Reference to the source string.
        * @param aInts Reference to the array  containing the replacing TInts.
        * @param aMax Maximum number of key strings in the resource string.
        * @return Pointer to a heap descriptor containing the formated string.
        */
        static HBufC* FormatStringL( TDesC& aSource,
                                   const CArrayFix<TInt>& aInts,
                                   TInt aMax, 
                                   TBidiText::TDirectionality aDir 
                                   );

        /**
		* FormatStringL( HbufC*, const MDesCArray&, TInt ) finds the
        * \%(index)U-keystrings from the source string and replaces it with the
        * replacement strings.
        *
        * @param aSource Reference to the source string.
        * @param aStrings Reference to the array containing pointers to the
        *                 replacing strings.
        * @param aMax Maximum number of key strings in the resource string.
        * @return Pointer to a heap descriptor containing the formated
        *         string.
        */
        static HBufC* FormatStringL( TDesC& aSource,
                                   const MDesCArray& aStrings,
                                   TInt aMax,
                                   TBidiText::TDirectionality aDir
                                   );
        /**
		* Formater( TDes&, const TDesC&, const TDesC&, const TDesC& ) finds
        * the keystring from the source string and replaces it with the
        * replacement string. The formated string is stored in the destination
        * descriptor.
        *
        * @param aDest Reference to the destination descriptor.
        * @param aSource Reference to the source string.
        * @param aKey Reference to the keystring.
        * @param aSubs Reference to the replacing string.
        * @param aDirectionality directionality of the main text
        * @return Number of keystrings replaced.
        */
        static TInt Formater(
            TDes& aDest,
            const TDesC& aSource,
            const TDesC& aKey,
            const TDesC& aSubs,
            TBidiText::TDirectionality aDirectionality
            );

        /**
		* KeyStringFormater( TDes&, const TText&, TInt, const TDesC& ) formats
        * the keystring from given parameters.
        *
        * @param aDest Reference to the destination descriptor.
        * @param aKey Reference to the key letter.
        * @param aPosition index of the key string.
        * @param aKeyString Reference to the keystring.
        */
        static void KeyStringFormater( TDes& aDest, const TText& aKey,
                                        TInt aPosition, const TDesC& aKeyString );
        
        /**
        * Resolves directionality of the given source text.
        * Place-holder strings are removed so that they don't affect the result.
        */
        static TBidiText::TDirectionality ResolveDirectionality( TDes& aText, TBool* aFound );

        /**
        * Counts the number of parameters in the text.
        * Needed for correct memory allocations.
        *
        * @param aText  Source text
        * @param aIndex Index to count. If index is invalid, counts all indexes.
        * @return       Parameter count
        */
        static TInt GetParamCount( const TDesC& aText, TInt aIndex = -1);

        /**
        * Counts the number of substrings (separated by '|'s) in the text.
        * If no '|' is found, but aText length is greater than zero, return 1.
        * If aText length is zero, return zero.
        * Needed for correct memory allocations.
        *
        * @param aText  Source text
        * @return       Substring count
        */
        static TInt GetSubStringCount( const TDesC& aText );
        
        /**
        * Resolves directionality of the given source text.
        * Uses ResolveDirectionality().
        */
        static TBidiText::TDirectionality DirectionalityL( const TDesC& aText, TBool* aFound );
        
        /**
        * Resolves sub strings. Uses ResolveSubStringL()
        */
        static HBufC* ResolveSubStringDirsL( TDes& aText, TInt aCount, TBool* aMarker );
        
        /**
        * Resolves sub string and directionality of the sub string.
        * Adds no dir marker if directionality of the string not found.
        *        
        * @param aText  Source text. After returnig returned sub string 
        *               removed from aText.
        * @param aMarker After returning ETrue if no dir marker added, otherwise EFalse.
        * @return       Substring
        */
        static HBufC* ResolveSubStringL( TDes& aText, TBool* aMarker );
        
        /**
        * Removes no dir markers from source text.
        *
        * @param aText Source text.
        */
        static void RemoveNoDirMarkers( TDes& aText );
    
        /**
        * Used by exported Format methods.
        */                             
        static void FormatL( TDes& aDest, const TDesC& aSource,
                             const TDesC& aKeybuf, const TDesC& aSubs );
    };

#endif      // STRINGLOADER_H

// End of File
