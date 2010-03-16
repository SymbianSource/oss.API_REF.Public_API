/*
* Copyright (c) 2004 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
* which accompanies this distribution, and is available
* at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:    LandmarksUi Content File -    This class provides functionality for selecting either one or
*                multiple landmarks.
*
*/







#ifndef CLMKLANDMARKSELECTORDLG_H
#define CLMKLANDMARKSELECTORDLG_H

//  INCLUDES
#include <e32base.h>            // CBase
#include <e32std.h>			//RArray and RPointerArray
#include <EPos_Landmarks.h>     // Lm typedefs, constants etc.
#include <EPos_CPosLandmarkDatabase.h>

// FORWARD DECLARATIONS
//class CPosLandmarkDatabase;
class CLmkDlgSelectorImplBase;
class MObjectProvider;

// For multiple database support
class TLmkItemIdDbCombiInfo;

// CLASS DECLARATION

/**
*  This is a dialog class, which is used to launch landmark selector dialog and
*  to get the selected landmark ids.It displays the landmarks present in landmarks
*  database,as a list.The dialog can be a single selector or multiple selector dialog,
*  depending upon argument passed by the client (in ExecuteLD function)  at the time
*  when it is launched.Based on whether it is a single selector or multiple selector
*  dialog, user can select single landmark or multiple landmarks.
*/
class CLmkLandmarkSelectorDlg : public CBase
    {
    public:  // Constructors and destructor
        /**
        * This is a static function, which creates and returns an instance of this class.
        * All the landmarks present in the landmark database are shown in the selector.
    	*
        * @leave  Leaves with KErrNotSupported if framework functionality is not available.
        * @panic  Panics with system-wide panic codes.
        * @return new instance of this class
        */
        IMPORT_C static CLmkLandmarkSelectorDlg* NewL();

        /**
        * Destructor.
        */
        IMPORT_C ~CLmkLandmarkSelectorDlg();

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
        * This function launches the landmark selector dialog. Client uses this function
        * to launch single landmark selector dialog.
        * This object is destroyed when this function returns or leaves.
        * @param [in/out] aSelected Passed as reference and when the function returns,
        *                contains the selected landmark id.
        * @leave Leaves with system-wide leave codes.
        * @panic Panics with KLmkPanicNullMember, if the selector is not constructed properly.
        * @return Returns non-zero if accepted, else zero.
        */
        IMPORT_C TInt ExecuteLD( TLmkItemIdDbCombiInfo& aSelected );

        /**
        * This function launches the landmark selector dialog. Client uses this function
        * to launch multiple landmark selector dialog.
        * This object is destroyed when this function returns or leaves.
        * If the array(aSelectedItems) is passed with already filled landmark ids, then
        * such landmarks will be shown as selected when the dialog is launched, but if
        * any of these ids do not exist in landmarks database, it will be ignored.
        *
        * @param [in/out] aSelectedItems Passed as reference, either filled with landmark
        *                ids for pre-selection or an empty array. On return of the function
        *                contains the selected landmark ids.
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
        CLmkLandmarkSelectorDlg();

        /**
        * By default Symbian 2nd phase constructor is private.
        */

        void ConstructL( );


    private:    // Data
        // ETrue if executed in multiple item selector mode
        TBool iIsMultiSelector;

        /// Own: Search implementor object
        CLmkDlgSelectorImplBase* iSelector;

        // Set to ETrue in destructor
        TBool* iDestroyedPtr;

        // For multiple database support
        RPointerArray <CPosLandmarkDatabase> iDbs; //


    };

#endif      // CLMKLANDMARKSELECTORDLG_H

// End of File
