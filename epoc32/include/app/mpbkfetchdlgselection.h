/*
* Copyright (c) 2005 Nokia Corporation and/or its subsidiary(-ies).
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
* Description: 
*       Interface to allow observer accept/decline selections in 
*		phonebook fetch dialog
*
*/


#ifndef __MPbkFetchDlgSelection_H__
#define __MPbkFetchDlgSelection_H__

#include <cntdef.h>     // TContactItemId


// CLASS DECLARATION

/**
 * Interface for accepting/refusing selections in Phonebook fetch dialog.
 * A client can use this interface to implement restrictions on fetch dialog
 * selection. For example on the maximum number of contacts selected by 
 * the user.
 */
class MPbkFetchDlgSelection
	{

	public: // Interface
        /**
         * Decides whether a contact selection made in fetch dialog should be
         * accepted or declined
         * @param aItemId ID of the item that is being selected.
         * @param aCurrentSelectedCount Number of already selected items BEFORE
         *		  current selection
         * @return ETrue if the selection is accepted. Otherwise EFalse
         */	
        virtual TBool ContactSelectionAcceptedL
        	(TContactItemId aItemId, 
        	 TInt aCurrentSelectedCount) const = 0;
    };
	
#endif // __MPbkFetchDlgSelection_H__

// End of File
