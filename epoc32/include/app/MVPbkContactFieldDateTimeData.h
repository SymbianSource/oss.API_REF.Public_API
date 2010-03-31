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
* Description:  Virtual Phonebook interface for date/time type of contact 
*                field data.
*
*/


#ifndef MVPBKCONTACTFIELDDATETIMEDATA_H
#define MVPBKCONTACTFIELDDATETIMEDATA_H

// INCLUDES
#include <mvpbkcontactfielddata.h>


// CLASS DECLARATIONS

/**
 * Virtual Phonebook date/time field data.
 * This class is used to manipulate contact field data, which contains
 * a date/time type of data.
 */
class MVPbkContactFieldDateTimeData : 
        public MVPbkContactFieldData
    {
    public:  // Destructor
        /**
         * Destructor.
         */
        virtual ~MVPbkContactFieldDateTimeData() { }

    public:  // from MVPbkContactFieldData
        TVPbkFieldStorageType DataType() const
            {
            return EVPbkFieldStorageTypeDateTime;
            }

    public:  // Interface
        /**
         * Casts MVPbkContactFieldData to this interface.
         *
         * @precond aFieldData.DataType() == EVPbkFieldStorageTypeDateTime
         *          VPbkError::Panic(VPbkError::EFieldDataTypeMismatch)
         *          is raised if the precondition does not hold.
         * @param aFieldData    Data of the field.
         * @return Casted inteface for the date/time field data.
         */
        IMPORT_C static MVPbkContactFieldDateTimeData& Cast
            ( MVPbkContactFieldData& aFieldData );

        /**
         * Casts const MVPbkContactFieldData to this interface.
         *
         * @precond aFieldData.DataType() == EVPbkFieldStorageTypeDateTime
         *          VPbkError::Panic(VPbkError::EFieldDataTypeMismatch)
         *          is raised if the precondition does not hold.
         * @param aFieldData    Data of the field.
         * @return Casted inteface for the date/time field data.
         */
        IMPORT_C static const MVPbkContactFieldDateTimeData& Cast
            ( const MVPbkContactFieldData& aFieldData );

        /**
         * Returns the date/time data.
         * @return Date/time data.
         */
        virtual TTime DateTime() const = 0;

        /**
         * Sets the date/time data.
         * @param aTime Date/time to be set.
         */
        virtual void SetDateTime( const TTime& aTime ) = 0;

        /**
         * Returns an extension point for this interface or NULL.
         * @param aExtensionUid Uid of extension.
         * @return Extension point or NULL.
         */
        virtual TAny* ContactFieldDateTimeDataExtension( 
                TUid /*aExtensionUid*/ ) { return NULL; }
    };


#endif  // MVPBKCONTACTFIELDDATETIMEDATA_H

//End of file
