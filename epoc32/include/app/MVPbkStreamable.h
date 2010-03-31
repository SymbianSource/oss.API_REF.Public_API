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
* Description:  An interface for objects that can be written into stream.
*
*/


#ifndef MVPBKSTREAMABLE_H
#define MVPBKSTREAMABLE_H

// INCLUDES
#include <e32std.h>

// FORWARD DECLARATIONS
class RReadStream;
class RWriteStream;

// CLASS DECLARATIONS

/**
 * An interface for objects that can be written into stream.
 */
class MVPbkStreamable
    {
    protected: // destructor
        /**
         * Destructor.
         */
        virtual ~MVPbkStreamable() { }

    public: // interface
        /**
         * Outputs this objects state to aStream.
         *
         * @param aStream A stream for writing the object state.
         */
        virtual void ExternalizeL( RWriteStream& aStream ) const = 0;
        
        /**
         * Returns the externalized size of the object in bytes.
         *
         * @return The externalized size of the object.
         */
        virtual TInt ExternalizedSize() const = 0;

        /**
         * Returns an extension point for this interface or NULL.
         *
         * @param aExtensionUid no extensions defined currently.
         * @return An extension point for this interface or NULL.
         */
        virtual TAny* StreamableExtension( TUid /*aExtensionUid*/ ) 
                { return NULL; }

    };

#endif // MVPBKSTREAMABLE_H

//End of file
