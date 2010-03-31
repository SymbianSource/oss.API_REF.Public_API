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
* Description:    LandmarksUi Content File -    This class provides functionality for viewing and editing
*                landmark data.
*
*/






#ifndef CLMKEDITORDLG_H
#define CLMKEDITORDLG_H

//  INCLUDES
#include "EPos_CPosLandmark.h"
#include <EPos_Landmarks.h> // Lm typedefs, constants etc.
#include <e32base.h>        // CBase

// FORWARD DECLARATIONS
class CPosLandmarkDatabase;
class CPosLandmark;
class CLmkEditorImpl;
class MObjectProvider;
class TCoeHelpContext;
class CLmkSender;

// TYPE DEFINITIONS
typedef TUint32 TLmkEditorAttributes;
typedef TInt TLmkEditorMode;

// CLASS DECLARATION
/**
*  This is a dialog class, which is used to launch landmark viewer/editor.
*  It provides functionality for viewing and editing landmark data.
*  By default all the fields are shown, but user can customize the total number of
*  displayable fields. It also supports mechanism to disable map and navigation
*  related menu option.
*/
class CLmkEditorDlg : public CBase
    {
    public: // Types

	      /*!
	      @enum _TLmkEditorAttributes
	      @discussion Defines the flag for displaying landmark fields on the viewer/editor dialog.
          Any combination of these flags,will display those fields,when viewer/editor is launched.
          By default the flag is set as ELmkAll.This flag is set in class TLmkEditorParams.
       */

        enum _TLmkEditorAttributes
            {
            /**This flag allows Name field of the landmark, to be shown.*/
            ELmkOnlyName            = 0x0000,
            /**This flag allows the Category/Categories field of the landmark , to be shown*/
            ELmkCategory            = 0x0001,
            /**This flag allows the Street name field of the landmark,to be shown.*/
            ELmkStreet              = 0x0002,
            /**This flag allows the City name field to be shown, where the landmark belongs.*/
            ELmkCity                = 0x0004,
            /**This flag allows the State name field to be shown,where the landmark belongs.*/
            ELmkStateProvince       = 0x0008,
            /**This flag allows the Country name field to be shown, where landmark belongs.*/
            ELmkCountry             = 0x0010,
            /**This flag allows the Postal Zip field of the landmark, to be shown.*/
            ELmkPostalZIP           = 0x0020,
            /**This flag allows the Latitude field of the landmark, to be shown.*/
            ELmkLatitude            = 0x0040,
            /**This flag allows the Longitude field of the landmark, to be shown.*/
            ELmkLongitude           = 0x0080,
            /**This flag allows the Position accuracy field of the landmark, to be shown.It specifies the
               horizontal accuracy of the landmark related to Longitude and Latitude values.
            */
            ELmkPositionAccuracy    = 0x0100,
            /**This flag allows the Altitude field of the landmark, to be shown. It specifies the vertical
               position of the landmark.*/
            ELmkAltitude            = 0x0200,
            /**This flag allows the Altitude accuracy field of the landmark, to be shown.It specifies the
               vertical accuracy of the landmark related to Landmark's Altitude value.*/
            ELmkAltitudeAccuracy    = 0x0400,
            /**This flag allows All fields of the landmark, to be shown.*/
            ELmkAll                 = 0xFFFF,
            /**This flag allows the Description field of the landmark, to be shown.*/
            ELmkDescription         = 0x0800,
            /**This flag allows the Phone number field of the landmark, to be shown.*/
            ELmkPhoneNumber         = 0x1000,
            /**This flag allows the Web address field of the landmark, to be shown.*/
            ELmkWebAddress          = 0x2000
            };

        /*!
         @enum _TLmkEditorMode
         @discussion Defines flag, that decides the mode in which the landmark
         dialog is launched(viewer or editor).
         By default, the flag is set as ELmkEditor.This flag is set in class
         TLmkEditorParams.
        */
	    enum _TLmkEditorMode
            {
            /**Landmark will be launched in editor mode. */
            ELmkEditor,
            /**Landmark will be launched in viewer mode. */
            ELmkViewer  // only viewing allowed
            };

        /**
        * This class is a wrapper, around the flags @ref _TLmkEditorAttributes and @ref _TLmkEditorMode.
        * It is used to set these flags to CLmkEditorDlg before launching the dialog.
        * It encapsualtes _TLmkEditorAttributes & _TLmkEditorMode.
        * It is used by class CLmkEditorDlg.
        */
        class TLmkEditorParams
            {
            public:  // Constructors and destructor
                /**
                * C++ Constructor.
                * @return newly instantiated object
                */
                IMPORT_C TLmkEditorParams();

                // Compiler-generated destructor is ok for this class;

            private:  // Unimplemented functions
                // Unimplemented copy constructor
                TLmkEditorParams( const TLmkEditorParams& );

                // Unimplemented assignment operator
                TLmkEditorParams& operator = ( const TLmkEditorParams& );

            public:  // Input parameters

                /**
                * This member,specifies what all landmark attributes to be shown in editor/viewer dialog.
                * It can have a combination of values from enum @ref _TLmkEditorAttributes.
                * By default ELmkAll attribute is used if no value is specified.
                */
                TLmkEditorAttributes iAttributes;

                /**
                * This member,specifies the mode (Viewer or Editor) in which the landmark dialog will be launched.
                * It holds a value from enum @ref _TLmkEditorMode, by default ELmkEditor is used if no value is specified.
                */
                TLmkEditorMode iEditorMode;
            };

    public:  // Constructors and destructor
        /**
        * This is a static function, which creates and returns an instance of this class,
        * based on landmark id, which exists in landmark database.
        * @param[in] aDb Reference to landmark database that includes this landmark.
        * @param[in] aLandmark Landmark id, which exists in Landmarks database.
        * @param[in] aParams Attribute, holds values for launching the landmark dialog
        *			 in viewer or editor mode, and number of landmark fields to be
        *            displayed.
        * @panic Panics with system-wide panic codes.
        * @leave Leaves with KErrNotFound,If the landmark does not exist in the database
        *        Leaves with KErrNotSupported if framework functionality is not available.
        * @return new instance of this class
        */
        IMPORT_C static CLmkEditorDlg* NewL( CPosLandmarkDatabase& aDb,
                                             TPosLmItemId aLandmarkId,
                                             TLmkEditorParams& aParams );

        /**
        * This is a static function, which creates and returns an instance of this class,
        * based on landmark object, which does not exist in landmark database.
        * @param[in] aDb reference to landmark database, where new landmark will be created,
        *            if launched in edit mode.
        * @param [in\out] aLandmark  pre-filled landmarks object. In case of edit mode,
        *  				 the passed aLandmark is updated with the information entered
        *                by the user along with the landmark id, which can be obtained
        *                by calling LandmarkId() method of CPosLandmark.
        * @param[in] aParams aParams attributes whether to launch landmark in viewer mode
        *            or editor mode.
        * @panic Panics with system-wide panic codes.
        * @leave Leaves with KErrNotSupported if framework functionality is not available.
        * @return new instance of this class
        */
        IMPORT_C static CLmkEditorDlg* NewL( CPosLandmarkDatabase& aDb,
                                             CPosLandmark& aLandmark,
                                             TLmkEditorParams& aParams );

        /**
        * Destructor.
        */
        IMPORT_C ~CLmkEditorDlg();

    public: // New functions
        /**
        * This method sets the context - that is, the enclosing parent control - for this control.
        * @param[in] aParent The parent object which is the context for the control.
        */
        IMPORT_C void SetMopParent( MObjectProvider* aParent );

        /**
        * This method sets help context. There are many applications using landmark editor
        * and they may have an own help topic to be shown, when editor's help
        * is launched. With this command it is possible to define the used
        * help content. Landmark's own help context is used as default.
        * @param[in] aContext help context to use
        */
        IMPORT_C void SetHelpContext( TCoeHelpContext aContext );

        /**
        * This function launches the landmark dialog.It launches the dialog either in viewer
        * or editor mode , depending upon the flag set.
        *
        * Editor mode:
        * 	When the dialog is launched in edit mode, the user can edit the landmark fields (some or all)
        * 	and can save the Landmark.
        * 	On closing the dialog, the landmark is saved to the landmark database. If saving a
        * 	landmark fails due to less memory, the user is notified with an information note. If any
        * 	of the landmark fields are filled and landmark name is not provided, user is asked to
        * 	provide the landmark name, else if nothing is entered the dialog will close without saving
        *   the landmark.
        *   In case of new landmark creation, once the dialog is closed and the application returns
        *   from ExecuteLD() method, client applications can obtain the landmark id of the newly
        *   created landmark by calling LandmarkId() method from CPosLandmark class.
        *
        * Viewer mode:
        * The user can view the Landmark contents by accepting the dialog
        *                      Canelling the dialog will close the dialog
        * @panic Panics with system-wide, panic codes.
        * @leave  Leaves with KErrNotSupported if framework functionality is not available.
        * @return Returns non-zero if accepted & saved in edit mode.
        		  Returns zero if fails due to less memory or any other error
        		  in edit mode.It always returns zero in view mode.
        */
        IMPORT_C TInt ExecuteLD();
        /**
        * This function, when invoked, disables the Map and Navigation related Menu Options
        * This needs to be invoked before ExecuteLD(). By default, the Map and Navigation
        * menu options are enabled and are shown.
        *
        */
        IMPORT_C void DisableMapAndNavigationMenuOptions();

    private:
        /**
        * C++ default constructor.
        * @return newly instantiated object
        */
        CLmkEditorDlg();

        /**
        * By default Symbian 2nd phase constructor is private.
        * @param aDb
        * @param aParams
        * @param aLandmarkId
        * @param aLandmark
        */
        void ConstructL( CPosLandmarkDatabase& aDb,
                         TLmkEditorParams& aParams,
                         TPosLmItemId aLandmarkId,
                         CPosLandmark* aLandmark );

    private:    // Data
        /// Own: Search implementor object
        CLmkEditorImpl* iEditorImpl;

        /// Own: A pointer to TBool
        TBool* iDestroyedPtr;

        /// Own: Landmark sender object
        CLmkSender* iSender;
    };

#endif      // CLMKEDITORDLG_H

// End of File
