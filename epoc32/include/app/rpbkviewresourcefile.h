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
* Description: 
*     Helper class for loading PbkView resources.
*
*/


#ifndef __RPbkViewResourceFile_H__
#define __RPbkViewResourceFile_H__

//  INCLUDES
#include <e32std.h>
#include "ConeResLoader.h"

// CLASS DECLARATION

/**
 * Helper class for loading the PbkView DLL resource file.
 */
class RPbkViewResourceFile
    {
    public:  // Interface
        /**
         * Constructor.
         * @param aEnv CONE environment where to load the resource file.
         */
        IMPORT_C RPbkViewResourceFile(CCoeEnv& aEnv);

        /**
         * Opens the PbkView dll resource file for use. Leaves if the
         * resource file is already open.
         */
        IMPORT_C void OpenL();

        /**
         * Returns ETrue if the resource file is open.
         * @return ETrue if the resource file is open.
         */
        IMPORT_C TBool IsOpen() const;
    
        /**
         * Closes the PbkView dll resource file.
         * You must always remember to close the resource file when finished 
         * using it.
         */
        IMPORT_C void Close();

    private:  // Data
		/// Own: resource loader
        RConeResourceLoader iLoader;
		/// Own: file open flag
        TBool iOpen;
    };

#endif // __RPbkViewResourceFile_H__

// End of File
