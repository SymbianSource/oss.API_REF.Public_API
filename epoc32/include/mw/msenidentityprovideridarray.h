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
* Description:        An abstract class used to reference to some
*                CSenIdentityProviderIdArray owned elsewhere.
*
*/








#ifndef M_SEN_IDENTITY_PROVIDER_ID_ARRAY_H
#define M_SEN_IDENTITY_PROVIDER_ID_ARRAY_H

//  INCLUDES
#include <e32base.h>
#include <badesca.h>
#include <e32des8.h>

// CLASS DECLARATION

/**
* Abstract interface for ProviderID array classes
* @lib SenServDesc.lib
* @since Series60 3.0
*/
class MSenIdentityProviderIdArray
    {
    public: // New functions
        
        /**
        * Method to check if the array is defined as strict.
        * @since Series60 3.0
        * @return ETrue if array is strict, EFalse if not
        */
        IMPORT_C virtual TBool IsStrict() const = 0;

        /**
        * Method for setting the strict flag.
        * @since Series60 3.0
        * @param aStrict the value the flag should be set.
        */
        virtual void SetStrict(TBool aStrict) = 0; // check: altered in 3.0 BC FIX
        //IMPORT_C virtual void SetStrict(TBool aStrict) = 0;
    };

#endif // M_SEN_IDENTITY_PROVIDER_ID_ARRAY_H

// End of File


