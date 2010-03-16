/*
* Copyright (c) 2002-2006 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:  Cone Resource Loader API enables adding and removing 
*                localized resource files into the CONE environment.
*
*/


#ifndef CONERESLOADER_H
#define CONERESLOADER_H

// forward declarations
class CCoeEnv;

/** 
* Class encapsulates methods for opening and closing localised resource files
* in the CONE environment. The actual reading of resources from an opened 
* resource file is done using various CCoeEnv provided resource-reading 
* methods. Cone Resource Loader API consist of the RConeResourceLoader class.
*
* Only one resource at a time may be open by one RConeResourceLoader instance. 
* You can use several RConeResourceLoader instances for accessing several 
* resources simultaneously or use one instance and close the previous resource
* before opening a new one.
*
* The implementation uses BaflUtils::NearestLanguageFile to search for
* a localised resource in proper search order.
* 
* Usage example:  
*
* @code
*  #include <ConeResLoader.h>  
*
*  // Get CCoeEnv instance
*  CEikonEnv* eikEnv = CEikonEnv::Static();
*
*  // Initialize loader
*  RConeResourceLoader rLoader(eikEnv);
*
*  // Open resource file
*  _LIT( KSampleResourceFileName, "Z:\\System\\Apps\\sample\\sample.rsc" );
*  TFileName fileName(KSampleResourceFileName);
*  rLoader.OpenL(fileName);
*
*  // Push resource loader to cleanup stack, so that it will always be properly 
*  // closed when popped.
*  CleanupClosePushL(rLoader);
*
*  // Read a resource   
*  iSomeArray = eikEnv->ReadDesC16ArrayResourceL(R_SOME_RESOURCE);
*
*  // Pop and destroy rLoader from stack. 
*  // This also calls close on rLoader since CleanupClosePushL was used.
*  CleanupStack::PopAndDestroy(); // rLoader
*
* @endcode
*
* @lib commonengine.lib
* @since S60 2.0
*/
class RConeResourceLoader
    {
    public:
        /**
         * Constructor. 
         *
         * @param aEnv is a reference to Control environment in which resource
         * is loaded.
         */
        IMPORT_C RConeResourceLoader(CCoeEnv& aEnv);

        /**
         * Opens the resource file for reading. Only one resource may be open 
         * at a time. Panics if this instance already has a file open. 
         * The implementation uses BaflUtils::NearestLanguageFile to search 
         * for a localized resource file in proper search order.
         * 
         * @param aFileName is the resource file name to open. This parameter
         * value is changed to the best matching language file found. The drive
         * letter is required in the filename.
         * @return a Symbian OS error code.
         *
         * @panic KErrNotSupported The instance already has a file open.
         */
        IMPORT_C TInt Open(TFileName& aFileName);

        /**
         * Opens the resource file for reading. Only one resource may be open 
         * at a time. Leaves if this instance already has a file open.
         * The implementation uses BaflUtils::NearestLanguageFile to search
         * for a localized resource file in proper search order.
         * 
         * @param aFileName Reference for resource file name. Please
         *                  note that drive letter is required ! 
         *
         * @leave KErrNotSupported The instance already has a file open.
         */
        IMPORT_C void OpenL(TFileName& aFileName);


        /**
         * Closes the opened resource file, if one is open. Does nothing if no
         * file has been opened. New resource file may be opened after the 
         * previous has been closed. Always remember to close the resource when 
         * finished using it.
         */
        IMPORT_C void Close();

    private:
                
        // Prohibit copy constructor and assigment operator because not deriving from CBase.
        RConeResourceLoader(const RConeResourceLoader&);
        RConeResourceLoader& operator= ( const RConeResourceLoader& );
    
        // Needed for closing
        CCoeEnv& iEnv; 
        TInt iResourceFileOffset;
    };


#endif

// End of File
