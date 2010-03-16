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
* Description:  Offers methods for parsing and validating phone numbers.
*
*/


#ifndef COMMONPHONEPARSER_H
#define COMMONPHONEPARSER_H

//  INCLUDES
#include    <coemain.h>


// CLASS DECLARATION

/**
* Class offers static methods for parsing and validating phone numbers. 
* Phone Parser API provides methods which are used to parse and validate
* phone numbers. The API consist of the CommonPhoneParser class.
*
* Examples of valid phone numbers:
* 1.	+358501234567
* 2.	+358 (50) 123 4567
*
* Even though both of the above examples are valid phone numbers, only 1) is 
* accepted as a phone number by many systems. To convert 2) to 1), use the 
* parsing method of the API.
*
*
* Usage:
*   
* @code
*  #include <commonphoneparser.h> 
*
*  // Example shows how to use the parsing method of the API.
*
*  // A number to be parsed. 
*  TBuf<50> number1 = _L("+358 (40) 123 132");
* 
*  // Type of the phone number to be parsed is a regular phone number.
*  TBool validNumber1 = 
*  CommonPhoneParser::ParsePhoneNumber( number1,
*                                       CommonPhoneParser::EPlainPhoneNumber );
*
*  // The phone number number1 is a valid regular phone number.
*  // After parsing validNumber1 is ETrue and 
*  // number1 is "+35840123132".
*  // Do something like SendSMS( number1 ) etc.
* 
*  // A number to be parsed. 
*  TBuf<50> number2 = _L("+358 (40) 123p132"); // note 'p'
* 
*  // Type of the phone number to be parsed is a regular phone number.
*  TBool validNumber2 = 
*  CommonPhoneParser::ParsePhoneNumber( number2,
*                                       CommonPhoneParser::EPlainPhoneNumber );
*
*  // The phone number number2 is not a valid regular phone number.
*  // After parsing validNumber2 is EFalse and 
*  // number2 is "+358 (40) 123p132" (unchanged).
* @endcode
*
* @lib commonengine.lib
* @since S60 2.0
*/

class CommonPhoneParser
    {
    public:

        /** 
        * Enumeration for phone number types. 
        * Used to specify the type of phone numbers in methods of 
        * CommonPhoneParser class.
        */
        enum TPhoneNumberType
            {
            /** The associated phone number is a regular phone number.
            */
            EPlainPhoneNumber,
            /** The associated phone number is a contact card number.
            */
            EContactCardNumber,
            /** The associated phone number is is a phone client number.
            */
            EPhoneClientNumber,
			/** The associated phone number is an SMS number.
            */
            ESMSNumber
            };

        /**
        * Parses the supplied phone number. This method removes irrelevant 
        * characters and white spaces from the supplied phone number. Allowed
        * characters are determined by phone number type.
        *
        * @param aNumber will be checked and parsed. After returning contains
        * the parsed number if the supplied phone number was a valid phone 
        * number. If the number was not valid no parsing will be done.
        * @param aType is the type of the supplied phone number.
        * @return ETrue if the supplied phone number is a valid number of the
        * supplied type and the parsing succeeds. Otherwise EFalse.
        */
        IMPORT_C static TBool ParsePhoneNumber( TDes& aNumber, 
                                                TPhoneNumberType aType );

        /**
        * Checks if string is a valid phone number.
        * This method checks if the supplied phone number is a valid phone
        * number of the supplied type.
        *
        * @param aNumber which validity will be checked.
        * @param aType  is the type of the supplied phone number.
        * @return ETrue if the supplied phone number is a valid number of the 
        * supplied type. Otherwise EFalse.
        */
        IMPORT_C static TBool IsValidPhoneNumber( const TDesC& aNumber,
                                                  TPhoneNumberType aType );
        
        /**
        * This method is meant for internal use of Phone Parser. 
        * Check if string is a valid phone number
        *
        * @param aNumber Number which will be checked
        * @param aValidChars Characters that are valid for the number.
        *           Note! Some chars have special rules. See Find Item
        *           UI specification for more info.
        *
        * @return ETrue if the number was valid, otherwise EFalse.
        */
        static TBool IsValidPhoneNumber( const TDesC& aNumber,
                                         const TDesC& aValidChars);
        /**
        * This method is meant for internal use of Phone Parser.
        * Parses invalid characters from a string
        *
        * @param aNumber Number which will be parsed.
        * @param aInvalidChars Characters that are invalid.
        */
        static void ParseInvalidChars( TDes& aNumber,
                                       const TDesC& aInvalidChars);
    };

#endif      // COMMONPHONEPARSER_H
            
// End of File
