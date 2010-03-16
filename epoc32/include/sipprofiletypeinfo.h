/*
* Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Name        : sipprofiletypeinfo.h
* Part of     : SIP Profile Client
* Interface   : SDK API, SIP Profile API
* The class provides a container for the profile type information
* Version     : 1.0
*
*/



#ifndef TSIPPROFILETYPEINFO_H
#define TSIPPROFILETYPEINFO_H

//  INCLUDES
#include <e32base.h>

// FORWARD DECLARATIONS

// CLASS DECLARATION
/**
*  @publishedAll
*  @released
*
*  Container for the profile type information.
*
*  @lib sipprofilecli.lib
*/
class TSIPProfileTypeInfo
    {
    public:

        /** Profile type name */
        typedef TBuf8<25> TSIPProfileName;

        /** Profile classes */
        enum TSIPProfileClass
            {
            /** Network compliant with IETF standards */
            EInternet,
            /** Network compliant with 3GPP standards */
            EIms,
            /** Other */
            EOther,
            EMaxSIPProfileClass
            };

    public:  // data members

        /** Profile class */
        TSIPProfileClass iSIPProfileClass;

        /** Profile type name */
        TSIPProfileName iSIPProfileName;
    };

#endif // TSIPPROFILETYPEINFO_H
