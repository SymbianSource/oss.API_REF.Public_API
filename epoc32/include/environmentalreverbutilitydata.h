/*
* Copyright (c) 2004 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:  This file contains definitions of audio effects data structures for
*                EnvironmentalReverb.
*
*/



#ifndef ENVIRONMENTALREVERBUTILITYDATA_H
#define ENVIRONMENTALREVERBUTILITYDATA_H

//  INCLUDES
#include <e32std.h>

// CLASS DECLARATION

/**
*  This class defines the EnvironmentalReverb Effect Utility data structure.
*
*  @lib EnvironmentalReverbUtility.lib
*  @since 3.0
*/
class TEfEnvironmentalReverbUtilityPreset
    {
    public:

        /**
        * Constructor.
        */
        TEfEnvironmentalReverbUtilityPreset() : iPresetNameKey(0),iPresetDescriptionKey(0),iPresetName(NULL)
        {}

		TUint32 iPresetNameKey;
		TUint32 iPresetDescriptionKey;
		TBuf16<32>  iPresetName;

    };

#endif      // ENVIRONMENTALREVERBUTILITYDATA_H

// End of File
