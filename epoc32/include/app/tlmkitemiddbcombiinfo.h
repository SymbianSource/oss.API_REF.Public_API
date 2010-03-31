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
* Description:    LandmarksUi Content File -    This class provides methods for fetching the ID of selected
*			   : landmark or category and the handle to database to which either
*			   : landmark or category belongs.
*
*/







#ifndef TLMKITEMIDDBCOMBIINFO_H
#define TLMKITEMIDDBCOMBIINFO_H

//  INCLUDES
#include <e32base.h>            // CBase
#include <EPos_Landmarks.h>     // Lm typedefs, constants etc.

class CPosLandmarkDatabase;


/**
*
*This class provides methods for fetching the ID of selected landmark or category
*and the handle to database to which either landmark or category belongs.
*
*/
class TLmkItemIdDbCombiInfo
{

   public:  // Constructors and destructor
        /**
        * C++ default constructor.
        * @return newly instantiated object
        */

        IMPORT_C TLmkItemIdDbCombiInfo();

        /**
        * Destructor.
        */
        IMPORT_C ~TLmkItemIdDbCombiInfo();

   public: // Functions for getting/setting the info

        /**
        *The client application executes this method to get the ID of a landmark or category
        *@return id of the landmark or category
        */
        IMPORT_C TPosLmItemId GetItemId() const;

        /**
        *The client application executes this method to get the handle to a landmark database.
        *The client takes the ownership of database handle.
		*The database pointer is the same for all landmarks from the same database.
		*It is the responsibilty of the API client to manage these database pointers
		*and delete those pointers.
        *
        *@return handle to database to which the landmark or category belongs
        */

        IMPORT_C CPosLandmarkDatabase* GetLmDb() const;

        /**
        * This function is used to set the landmark or category id to the object of this class.
        * Basically this function is used by the API implementation logic.
        *@param [in] aLmItemId will contain reference to id of landmark or category
        */

        IMPORT_C void SetItemId( TPosLmItemId &aLmItemId);

        /**
        * This function is used to set the landmark database handle to the object of this class.
        * Objects of this class owns the database handle.Basically this function is used by the
        * API implementation logic.
        *@param [in] aDb contains the pointer to database handle
        */

        IMPORT_C void SetLmDb ( CPosLandmarkDatabase* aDb);

private: // own data
	CPosLandmarkDatabase* iLmDb;
	TPosLmItemId iLmItemId;
};


#endif // TLmkItemIdDbCombiInfo_H
