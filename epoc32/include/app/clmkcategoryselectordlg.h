/*
* Copyright (c) 2004 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:    LandmarksUi Content File -    This class provides functionality for selecting either one or
*                multiple categories.
*
*/







#ifndef CLMKCATEGORYSELECTORDLG_H
#define CLMKCATEGORYSELECTORDLG_H

//  INCLUDES
#include <e32base.h>                    // CBase
#include <e32std.h>			//RArray and RPointerArray
#include <EPos_Landmarks.h>             // Lm typedefs, constants etc.
#include <EPos_CPosLandmarkDatabase.h>
// FORWARD DECLARATIONS
//class CPosLandmarkDatabase;
class CLmkDlgSelectorImplBase;
class MObjectProvider;

// For multiple database support
class TLmkItemIdDbCombiInfo;

// CLASS DECLARATION

/**
*  This is a dialog class, which is used to launch category selector dialog and
*  to get the selected category ids.It displays the categories present in landmarks
*  database,as a list.The dialog can be a single selector or multiple selector dialog,
*  depending upon argument passed by the client (in ExecuteLD function) at the time
*  when it is launched.Based on whether it is a single selector or multiple selector
*  dialog, user can select single category or multiple categories.
*/
class CLmkCategorySelectorDlg : public CBase
    {
    public:  // Constructors and destructor
        /**
        * This is a static function, which create and return an instance of this class.
        * Categories present in the landmark database, are shown in selector.
        *
        * @param [in] aShowEmptyCategories specifies whether categories without
        *            landmarks are shown or not
        * @leave Leaves with KErrNotSupported if framework functionality is not available.
        * @panic Panics with system-wide panic codes.
        * @return new instance of this class
        */
        IMPORT_C static CLmkCategorySelectorDlg* NewL(TBool aShowEmptyCategories = EFalse );

        /**
        * Destructor.
        */
        IMPORT_C ~CLmkCategorySelectorDlg();

    public: // New functions
        /**
        * This function sets the context - that is, the enclosing parent control - for this control.
        *
        * @param [in] aParent The parent object which is the context for the control.
        * @panic Panics with KLmkPanicNullMember, if the selector is not
        *        constructed properly.
        */
        IMPORT_C void SetMopParent( MObjectProvider* aParent );

        /**
        * This function launches the category selector dialog.Client use this function
        * to launch single category selector dialog.
        * This object is destroyed when this function returns or leaves.
        * @param [in/out] aSelected Passed as reference and when the function returns,
        *                contains the selected category id.
        * @leave Leaves with system-wide leave codes.
        * @panic Panics with KLmkPanicNullMember, if the selector is not constructed properly.
        * @return Returns non-zero if accepted, else zero.
        */
        IMPORT_C TInt ExecuteLD( TLmkItemIdDbCombiInfo& aSelected );

        /**
        * This function launches the category selector dialog.Client use this function
        * to launch multiple category selector dialog.
        * This object is destroyed when this function returns or leaves.
        * If the array(aSelectedItems) is passed with already filled cateogry ids, then
        * such categories will be shown as selected when the dialog is launched,but if
        * any of these ids do not exist in landmarks database,will be ignored.
        *
        * @param [in/out] aSelectedItems Passed as reference,either filled with category
        *                ids for pre-selection or an empty array.On return of the function
        *                contains the selected category ids.
        * @leave Leaves with system-wide leave codes.
        * @panic Panics with KLmkPanicNullMember, if the selector is not constructed properly.
        * @return Returns non-zero if accepted, else zero.
        */
        IMPORT_C TInt ExecuteLD( RArray<TLmkItemIdDbCombiInfo>& aSelectedItems );

    private:
        /**
        * C++ default constructor.
        * @return newly instantiated object
        */
        CLmkCategorySelectorDlg();

        /**
        * By default Symbian 2nd phase constructor is private.
        * @param aShowEmptyCategories
        */
        void ConstructL( TBool aShowEmptyCategories );

    private:    // Data
        // ETrue if executed in multiple item selector mode
        TBool iIsMultiSelector;

        ///Own: Search implementor object
        CLmkDlgSelectorImplBase* iSelector;

        //Own: Set to ETrue in destructor
        TBool* iDestroyedPtr;

        // Multiple database support
        RPointerArray <CPosLandmarkDatabase> iDbs;

    };

#endif      // CLMKCATEGORYSELECTORDLG_H

// End of File
