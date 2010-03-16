/*
* Copyright (c) 2002-2004 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Defines an internal concrete class CAknsAppSkinInstance and
*                related types. This class encapsulates the concrete skin 
*                instance which is a singleton in thread scope.
*
*/


#ifndef AKNSWALLPAPERUTILS_H
#define AKNSWALLPAPERUTILS_H

#include <e32base.h>
#include <badesca.h>

class CCoeEnv;

/*
  Special error codes for SetIdleWallpaper.
*/
enum TAknsWpuError 
   {
   // Returned when the drm protected image has
   // only preview rights
   KAknsWpuErrorPreviewOnly = -8000
   };

/*
* An utility class for manipulating the Idle state wallpaper. This function will show
* all drm related messages and queries, if the content is drm protected.
*
* No copies of the given file, but the file is used directly where it is located.
*
* 
* @since 3.0
*/
class AknsWallpaperUtils
{
    public:
        /*
        * Sets the idle state wallpaper
        *
        * @param aFilename, the filename(incl. full path) of the image to be 
        * set as the idle state wallpaper, or KNullDesC if wallpaper is to
        * be removed. If resource id:s are given, the user must ensure that
        * the correct resource file is loaded to the given aCCoeEnv. The 
        * waitnote is type of CAknWaitNoteWrapper and is automatically launched
        * when correct resource id:s are given. 
        *
        * @param aCoeEnv a valid pointer to Control Environment, or NULL. As this function will potentially
        * show drm related messages, a valid coeenv is needed. If no messages are wanted, NULL can be given
        * as the parameter. Note that even when passing NULL, DRM related stuff will not be skipped, but
        * they are done silenty.
        *
        * @param aWaitNoteResourceTextID the resource id of the waitnote text to show
        * @param aWaitNoteResourceID the resource id of the wait note to show.
        * @return KErrNone on success or one of the system wide error codes.
        */
        IMPORT_C static TInt SetIdleWallpaper(const TDesC& aFilename, CCoeEnv* aCoeEnv, TInt aWaitNoteTextResourceID = 0, TInt aWaitNoteResourceID = 0);

        IMPORT_C static TInt SetSlidesetWallpaper(CDesCArray& aSelectedFiles, CCoeEnv* aCoeEnv, TInt aWaitNoteTextResourceID = 0, TInt aWaitNoteResourceID = 0);

};


#endif // AKNSAPPSKININSTANCE_H
            
// End of File
