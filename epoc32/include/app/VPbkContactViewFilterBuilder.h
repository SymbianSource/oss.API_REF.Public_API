/*
* Copyright (c) 2006-2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  A factory for creating contact view filters.
*
*/


#ifndef VPBKCONTACTVIEWFILTERBUILDER_H
#define VPBKCONTACTVIEWFILTERBUILDER_H

//  INCLUDES
#include <e32base.h>
#include <vpbkcontactview.hrh>

// FORWARD DECLARATIONS
class CVPbkFieldTypeSelector;
class CVPbkContactManager;

// CLASS DECLARATION

/**
 * A factory for creating contact view filters.
 *
 * A contact view filter can be used in a contact view definition
 * when the client wants to create a view that is filtered by
 * field types i.e. only contacts that have a certain fields
 * are included in the view.
 *
 * @see CVPbkContactViewDefinition::SetFieldTypeFilterL
 * @lib VPbkEng.lib
 */
class VPbkContactViewFilterBuilder
    {
    public: // Interface
        /**
         * Appends a filter for the given field type selector.
         *
         * @param aFieldTypeSelector The selector object to that is modified.
         * @param aFilter Defines the field types that are added to the
         *                selector.
         * @param aContactManager The contact manager.
         * @return A reference to the passed selector object for enabling
         *         chained calls.
         */
        IMPORT_C static CVPbkFieldTypeSelector& BuildContactViewFilterL(
                CVPbkFieldTypeSelector& aFieldTypeSelector,
                TVPbkContactViewFilter aFilter,
                CVPbkContactManager& aContactManager );
    };

#endif // VPBKCONTACTVIEWFILTERBUILDER_H

// End of File
