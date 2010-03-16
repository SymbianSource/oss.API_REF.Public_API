/*
* Copyright (c) 2002-2005 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:        This utility class provides static methods for conversions
*                between Symbian class types and XSD time-date type
*
*/








#ifndef SEN_DATE_UTILS_H
#define SEN_DATE_UTILS_H

//  INCLUDES
#include <e32base.h>

// CLASS DECLARATION

/**
* This utility class provides static methods for conversions between Symbian 
* class types and XSD time-date type.
*  @lib SenUtils.lib
*  @since Series60 3.0
*/
class SenDateUtils
    {
    public: 
        enum { KXmlDateTimeMaxLength = 31 };

        // New functions
        /**
        * Convert dateTime (from XML schema) to Symbian TTime. 
        * A panic will occur if an attempt is made to set an invalid 
        * value for any of the fields. 
        * Panics: User 3 if illegal date.
        * Leave codes:  KErrUnderflow   Not enough data given or 
        *                               negative values
        *               KErrOverflow    Too big values for e.g. month
        *               KErrGeneral     Invalid date structure
        * No check is made upon the validity of the year.
        * @since Series60 3.0
        * @param aXmlDateTime   source datetime to convert from
        * @return The returned time will be in UTC.
        */
        IMPORT_C static TTime FromXmlDateTimeL(const TDesC8& aXmlDateTime);

        /**
        * Convert Symbian TTime to dateTime (from XML schema).
        * Leave codes:  KErrOverflow    target descriptor is less than
        *               KXmlDateTimeMaxLength (25 bytes)
        * @since Series60 3.0
        * @param aDest (UTF8) result will be written here. It must be at least
        *                KXmlDateTimeMaxLength long.
        * @param TTime in UTC.
        */
        IMPORT_C static void ToXmlDateTimeUtf8L(TDes8& aDest, 
                                                const TTime& aSrc);

        /**
        * Convert Symbian TTime to dateTime (from XML schema).
        * Leave codes:  KErrOverflow    target descriptor is less than
        *               KXmlDateTimeMaxLength (25 bytes)
        * @since Series60 5.0
        * @param aDest (UTF8) result will be written here. It must be at least
        *                KXmlDateTimeMaxLength long.
        * @param TTime in UTC.
        */
	IMPORT_C static void ToXmlDateTimeUtf82L(TDes8& aDest, const TTime& aSrc) ;

    private:
        /**
        * Hide default C++ constructor.
        */
        SenDateUtils() { }

        /**
        * Prohibit copy constructor if not deriving from CBase.
        */
        SenDateUtils( const SenDateUtils& );

        /**
        * Prohibit assignment operator if not deriving from CBase.
        */
        SenDateUtils& operator=( const SenDateUtils& );
    };

#endif // SEN_DATE_UTILS_H
// End of File
