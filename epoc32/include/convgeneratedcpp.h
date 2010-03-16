// Copyright (c) 2000-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#if !defined(__CONVGENERATEDCPP_H__)
#define __CONVGENERATEDCPP_H__

#if !defined(__E32STD_H__)
#include <e32std.h>
#endif

#if !defined(__CONVDATA_H__)
#include <convdata.h>
#endif

/** 
Contains the conversion data for the foreign character set. This object can 
be passed as the first parameter to CCnvCharacterSetConverter::DoConvertFromUnicode() 
or CCnvCharacterSetConverter::DoConvertToUnicode() 
@publishedAll
@released
*/
GLREF_D const SCnvConversionData conversionData;

 
/** 
Returns the single character (as one or more byte values) which is used by 
default as the replacement for unconvertible Unicode characters. These byte 
values are output when converting from Unicode into a foreign character set 
for each Unicode character that has no equivalent in the foreign character 
set.

@return The single character which is used to replace unconvertible characters. 
@publishedAll
@released
*/
GLREF_C const TDesC8& ReplacementForUnconvertibleUnicodeCharacters_internal();

#endif
