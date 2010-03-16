/*
* Copyright (c) 2002 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:  ?Description
*
*/


#ifndef MMGFETCHCANCELER_H
#define MMGFETCHCANCELER_H

// CLASS DECLARATION

/**
*  Interface for canceling the fetch popup
*
*  @since 2.6
*/
class MMGFetchCanceler
    {
    public:  // New functions
        /**
        * Calling this method while the fetcher (MGFetch.h) popup is visible
        * (when the MMGFetchCanceler pointer is NOT NULL) causes the fetcher
        * to close.
        *
        * @since 2.6
        */
        virtual void CancelFetcherL() = 0;
    };

#endif // MMGFETCHCANCELER_H

// End of File
