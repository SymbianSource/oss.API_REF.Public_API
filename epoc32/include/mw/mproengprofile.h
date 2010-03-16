/*
* Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Profile settings interface.
*
*/



#ifndef MPROENGPROFILE_H
#define MPROENGPROFILE_H

//  INCLUDES
#include <cntdef.h> // TContactItemId

// FORWARD DECLARATIONS
class MProEngProfileName;
class MProEngTones;
class MProEngToneSettings;
class MProEngProfileExt;

// CLASS DECLARATION

/**
*  Profile settings interface.
*  MProEngProfile offers methods to get the alert for items, profile settings
*  and profile name interface.
*  How to use:
*  @code
*  // Get active profile with MProEngEngine::ActiveProfileL().
*  MProEngProfile* profile = iProfileEngine->ActiveProfileL();
*
*  // Use profile object here...
*
*  // When you are ready, free resources with MProEngProfile::Release()
*  profile->Release();
*
*  // If you release resources in destructor then:
*  if( iProfile )
*      {
*      iProfile->Release();
*      }
*
*  // If you put this class to CleanupStack then use void CleanupReleasePushL()
*  CleanupReleasePushL( *profile );
*  @endcode
*
*  @lib ProfileEngine.lib
*  @since 3.1
*/
class MProEngProfile
    {
    protected:  // Destructor

        virtual ~MProEngProfile() {};

    public: // New functions

        /**
        * Free resources of the profile.
        * @since 3.1
        */
        virtual void Release() = 0;

        /**
        * Return the alert for item array.
        * Only the calls coming from people who belong to one or more
        * "Alert for" groups returned here trigger an audible alert.
        * @since 3.1
        * @return Alert for array
        */
        virtual const TArray<TContactItemId> AlertForL() = 0;

        /**
        * This method set alert for items to the profile.
        * Only the calls coming from people who belong to one or more
        * "Alert for" groups set here trigger an audible alert.
        * @since 3.1
        * @param aAlertFor Alert for array. If the length of this array is 0,
        *        it is interpreted: "alert for all calls".
        * @return KErrAccessDenied, if the "Alert for" groups setting of the
        *         profile is unmodifiable.
        *         KErrArgument, if the argument array is too large.
        *         KErrNone, if succesful.
        */
        virtual TInt SetAlertForL(
            const TArray<TContactItemId>& aAlertFor ) = 0;

        /**
        * Return whether this profile is silent. A profile being silent means
        * that either the ringing type is silent or all the alert tones are set
        * to "None".
        * @since 3.1
        * @return ETrue if this profile is silent.
        */
        virtual TBool IsSilent() const = 0;

        /**
        * Return profile name interface.
        * @since 3.1
        * @return Instance of the profile name interface.
        */
        virtual MProEngProfileName& ProfileName() const = 0;

        /**
        * Return profile tones interface.
        * @since 3.1
        * @return Instance of the profile tones interface.
        */
        virtual MProEngTones& ProfileTones() const = 0;

        /**
        * Returns tone settings of this profile.
        * @since 3.1
        * @return Returns tone settings of this profile.
        */
        virtual MProEngToneSettings& ToneSettings() const = 0;

        /**
        * Store profile settings.
        * Leaves with:
        * KErrAccessDenied if one or more of the settings of this profile is/are
        * read-only,<br>
        * KErrAlreadyExists if the profile name has been changed and there
        * already is a profile with the same name,<br>
        * KErrNotFound if a file set as an alert tone cannot be found,<br>
        * KErrNotSupported if the MIME type of a file set as an alert tone is
        * not supported to be used as an alert tone,<br>
        * KErrArgument if a file set as an alert tone is DRM-protected but the
        * platform does not allow the files of this MIME type to be set as alert
        * tones when protected,<br>
        * KErrPermissionDenied, if a file set as an alert tone is not
        * DRM-protected and the platform does not allow the files of this MIME
        * type to be set as alert tones when unprotected,<br>
        * KErrCancel, if a file set as an alert tone is an unactivated DRM file
        * and user does not want to activate it,<br>
        * KErrTooBig if the tone file set for ringing tone (line 1 or line 2) is
        * too big in case the platform has this kind of limitation set,<br>
        * another system-wide error code.
        * 
        * Only processes with WriteDeviceData capability can succesfully call
        * this method.
        * @since 3.1
        */
        virtual void CommitChangeL() = 0;

    private: // Extension interface

        /**
        * This member is internal and not intended for use.
        */
        virtual MProEngProfileExt* Extension() { return NULL; }

    };

#endif      //  MPROENGPROFILE_H

// End of File

