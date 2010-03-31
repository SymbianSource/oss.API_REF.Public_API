/*
* Copyright (c) 2005-2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Virtual Phonebook attribute class for contact speed dialing.
*
*/


#ifndef CVPBKSPEEDDIALATTRIBUTE_H
#define CVPBKSPEEDDIALATTRIBUTE_H

// INCLUDE FILES
#include <e32base.h>
#include <mvpbkcontactattribute.h>
#include <mvpbkcontactattributemanager.h>
#include <vpbkpublicuid.h>

// FORWARD DECLARATIONS

/**
 * Virtual Phonebook Speed dial attribute.
 * Responsible for encapsulating the speed dial attribute management for
 * contacts. 
 */
class CVPbkSpeedDialAttribute : 
        public CBase, 
        public MVPbkContactAttribute
    {
    public: // static data
        /**
         * An undefined speed dial index. When this is used then implementation
         * will assume that client is interested in all speed dial indexes.
         */
        static const TInt KSpeedDialIndexNotDefined = -1;
        
    public: // constructor and destructor
        /**
         * Two-phased constructor.
         *
         * @param aIndex    Speed dial index.
         * @return A new instance of this class
         */
        IMPORT_C static CVPbkSpeedDialAttribute* NewL(TInt aIndex);
                
        /**
         * Two-phased constructor.
         * Index will be initialised with KSpeedDialIndexNotDefined.
         * Using this constructor it's possible to handle all the
         * contacts that have speed dials assigned. E.g. remove all speed
         * dial assignments or list all speed dial assignments.
         *
         * @return A new instance of this class
         */
        IMPORT_C static CVPbkSpeedDialAttribute* NewL();      
        
        /**
         * Destructor.
         */          
        ~CVPbkSpeedDialAttribute();
                
    public: // interface                
        /**
         * Sets new index for speed dial attribute.
         *
         * @param aIndex a new index
         */
        IMPORT_C void SetIndex(TInt aIndex);

        /**
         * Returns index of the speed dial attribute.
         *
         * @return Index of the speed dial attribute.
         */
        IMPORT_C TInt Index() const;
        
        /**
         * Internal identification of speed dial attribute.
         * @return Unique id of the speed dial attribute.
         */
        inline static TUid Uid() 
            { 
            return TUid::Uid(KVPbkSpeedDialAttributeImplementationUID);
            }
        
    public: // from MVPbkContactAttribute
        TUid AttributeType() const;
        MVPbkContactAttribute* CloneLC() const;        
        
    private: // implementation
        CVPbkSpeedDialAttribute();
        
    private: // data
        /// Own: Speed dial index
        TInt iIndex;
    };
    
#endif // CVPBKSPEEDDIALATTRIBUTE_H

// End of File
