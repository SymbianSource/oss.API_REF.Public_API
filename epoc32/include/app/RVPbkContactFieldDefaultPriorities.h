/*
* Copyright (c) 2004-2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  An array of default field priorities.
*
*/


#ifndef RVPBKCONTACTFIELDDEFAULTPRIORITIES_H
#define RVPBKCONTACTFIELDDEFAULTPRIORITIES_H

//  INCLUDES
#include <e32std.h>
#include <vpbkfieldtype.hrh> // TVPbkDefaultType

// CONSTANTS
namespace VPbkContactFieldDefaultPriorities
    {
    /**
     * The maximum amount of elements that can be appended to the array.
     */
    const TInt KMaxElementCount = 255;
    /**
     * The maximum value of TVPbkDefaultType
     */
    const TInt KMaxElementValue = 255;
    }

// CLASS DECLARATION

/**
 * An array of default field priorities.
 *
 * A helper class for client to manage default attribute priorities
 * of the contact fields. For accessing default information the client uses
 * the attribute manager.
 *
 * @see CVPbkContactManager::ContactAttributeManagerL
 * @see CVPbkDefaultAttribute
 */
class RVPbkContactFieldDefaultPriorities
    {
    public:  // Interface
        /**
         * Default constructor for an empty array.
         */
        RVPbkContactFieldDefaultPriorities();
        /**

        /**
         * Releases resources used for storing the array.
         *
         * This object must not be used after Close() has been called to it.
         */
        void Close();

        /**
         * Returns the number of elements in the array.
         *
         * @return The number of elements in the array.
         */
        TInt Count() const;

        /**
         * Returns true if this array is empty.
         *
         * @return ETrue if the array is empty.
         */
        TBool IsEmpty() const;
        
        /**
         * Returns a type at aIndex.
         *
         * @param aIndex A zero based index of the element.
         * @return A type at aIndex.
         */
        TVPbkDefaultType At(const TInt aIndex) const;
        
        /**
         * Appends a default type to the array.
         *
         * @param aDefaultType The default type to append in to the array.
         * @return KErrNone or a system wide error code.
         */
        TInt Append(const TVPbkDefaultType aDefaultType);

        /**
         * Outputs this objects state to a buffer.
         *
         * @return A buffer containing the state of the object.
         */
        IMPORT_C HBufC8* ExternalizeLC() const;
        
        /**
         * Initializes the instance from the buffer.
         *
         * @param aBuffer A buffer that was created using ExternalizeLC.
         */
        IMPORT_C void InternalizeL(const TDesC8& aBuffer);

    private: // Data
        /// Own: An array of default types to use.
        RArray<TVPbkDefaultType> iDefaultTypes;
    };

// INLINE IMPLEMENTATION

inline RVPbkContactFieldDefaultPriorities::RVPbkContactFieldDefaultPriorities()
    {
    }

inline void RVPbkContactFieldDefaultPriorities::Close()
    {
    iDefaultTypes.Close();
    }

inline TInt RVPbkContactFieldDefaultPriorities::Count() const
    {
    return iDefaultTypes.Count();
    }

inline TBool RVPbkContactFieldDefaultPriorities::IsEmpty() const
    {
    return !iDefaultTypes.Count();
    }

inline TVPbkDefaultType RVPbkContactFieldDefaultPriorities::At
        (const TInt aIndex) const
    {
    return iDefaultTypes[aIndex];
    }

inline TInt RVPbkContactFieldDefaultPriorities::Append
        (const TVPbkDefaultType aDefaultType)
    {
    TInt ret = KErrOverflow;
    if (Count() < VPbkContactFieldDefaultPriorities::KMaxElementCount)
        {
        if (aDefaultType > VPbkContactFieldDefaultPriorities::KMaxElementValue)
            {
            ret = KErrTooBig;
            }
        else
            {
            ret = iDefaultTypes.Append(aDefaultType);
            }
        }
    return ret;
    }

#endif // RVPBKCONTACTFIELDDEFAULTPRIORITIES_H

// End of File
