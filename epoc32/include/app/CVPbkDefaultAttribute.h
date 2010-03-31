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
* Description:  An attribute class for contact defaults.
*
*/


#ifndef CVPBKDEFAULTATTRIBUTE_H
#define CVPBKDEFAULTATTRIBUTE_H

// INCLUDE FILES
#include <e32base.h>
#include <mvpbkcontactattribute.h>
#include <mvpbkcontactattributemanager.h>
#include <vpbkpublicuid.h>
#include <vpbkfieldtype.hrh>


// CLASS DECLARATIONS
/**
 * Virtual Phonebook default attribute for contacts.
 * Responsible for encapsulating the default attribute management for
 * contacts. 
 * 
 * The supported default types are declared in TVPbkDefaultType.
 */
class CVPbkDefaultAttribute : 
		public CBase, 
		public MVPbkContactAttribute
    {
    public: // static data
        /**
         * KDefaultTypeNotDefined.
         */
        static const TVPbkDefaultType KDefaultTypeNotDefined = EVPbkDefaultTypeUndefined;

        /**
         * Returns the unique identifier associate with the default attribute.
         *
         * @return Default attribute implementation uid.
         */
        inline static TUid Uid() { return TUid::Uid(KVPbkDefaultAttributeImplementationUID); }

    public: // constructor and destructor        
        /**
         * Two-phased constructor.
         *
         * @param aType New default's type.
         * @return New instance of this class.
         */    
        IMPORT_C static CVPbkDefaultAttribute* NewL(
                TVPbkDefaultType aType);

        /**
         * Two-phased constructor.
         * Default type will be initialised to EVPbkDefaultTypeUndefined.
         *
         * @return New instance of this class.
         */    
        IMPORT_C static CVPbkDefaultAttribute* NewL();
        
        /**
         * Destructor.
         */
        ~CVPbkDefaultAttribute();
                
    public: // interface
        /**
         * Set default type.
         *
         * @param aType New default's type
         */
        IMPORT_C void SetDefaultType(TVPbkDefaultType aType);

        /**
         * Returns default's type.
         *
         * @return Default's type.
         */
        IMPORT_C TVPbkDefaultType DefaultType() const;
        
    public: // from MVPbkContactAttribute
        TUid AttributeType() const;
        MVPbkContactAttribute* CloneLC() const;
        
    private: // implementation
        CVPbkDefaultAttribute();

    private:  // Data
        /// Own: Default's type
        TVPbkDefaultType iDefaultType;
    };    
    
#endif // CVPBKDEFAULTATTRIBUTE_H

// End of File
