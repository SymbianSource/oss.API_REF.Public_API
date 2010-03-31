/*
* Copyright (c) 2002-2007 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  Virtual Phonebook attribute class for voice tags.
*
*/


#ifndef CVPBKVOICETAGATTRIBUTE_H
#define CVPBKVOICETAGATTRIBUTE_H

// INCLUDE FILES
#include <e32base.h>
#include <mvpbkcontactattribute.h>
#include <mvpbkcontactattributemanager.h>
#include <vpbkpublicuid.h>
#include <vpbkfieldtype.hrh>

// FORWARD DECLARATIONS

/**
 * Virtual Phonebook Voice tag attribute.
 * Responsible for encapsulating the voice tag attribute management for
 * contacts. 
 */
class CVPbkVoiceTagAttribute : 
        public CBase, 
        public MVPbkContactAttribute
    {
    public: // static data
        /**
         * Voice tag attribute implementation UID.
         * @return Voice tag attribute implementation UID.
         */
        inline static TUid Uid() 
            { return TUid::Uid(KVPbkVoiceTagAttributeImplementationUID); }

    public: // constructor and destructor    
        /**
         * Constructor.
         *
         * @return New instance of this class
         */
        IMPORT_C static CVPbkVoiceTagAttribute* NewL();
        
        /**
         * Destructor.
         */
        ~CVPbkVoiceTagAttribute();
        
    public: // from MVPbkContactAttribute
        TUid AttributeType() const;
        MVPbkContactAttribute* CloneLC() const;
        
    private: // implementation
        CVPbkVoiceTagAttribute();
    };
    
#endif // CVPBKVOICETAGATTRIBUTE_H

// End of File
