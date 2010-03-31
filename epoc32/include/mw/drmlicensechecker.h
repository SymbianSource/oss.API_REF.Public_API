/*
* Copyright (c) 2002 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  DRM License Checker interface definition
*
*/


#ifndef DRMLICENSECHECKER_H
#define DRMLICENSECHECKER_H

/**
*  Check and decrypt protected data files encrypted by the license manager.
*
*  @lib DRMLicenseChecker.lib
*  @since Series 60 2.5
*/
class CDRMLicenseChecker: public CBase
    {
    public:  // Local enumerations and types

        enum
            {
            ENoRights = -100000,
            ERightsExpired = -100001,
            };

    public:  // Constructors and destructor
        
        /**
        * Two-phased constructor.
        */
        IMPORT_C static CDRMLicenseChecker* NewL();
        
        /**
        * Destructor.
        */
        IMPORT_C virtual ~CDRMLicenseChecker();

    public: // New functions
        
        /**
        * This function performs a license check by decrypting a data file and
        * returning the decrypted contents of the data file. A license check
        * can only succeed if a rights object associated with the calling
        * application exists and sufficient rights are present. If the license
        * check fails, an error is returned.
        *
        * @since Series 60 2.6
        * @param aDataFile: the data file to be decrypted
        * @param aDataBuffer: memory buffer which contains the decrypted
        *        contents of the data file.
        * @return ENoRights, ERightsExpired if the data file could not be opened
        *         because of insufficient rights, Symbian-wide error codes or
        *         KErrNone in case of success.
        */
        IMPORT_C TInt CheckLicense(
            const TDesC& aDataFile,
            HBufC8*& aDataBuffer);

    private:

        /**
        * C++ default constructor.
        */
        CDRMLicenseChecker();

        /**
        * By default Symbian 2nd phase constructor is private.
        */
        void ConstructL();
        
        /**
        * Leaving version of CheckLicense
        *
        * @since Series 60 3.0
        * @param aDataFile: the data file to be decrypted
        * @param aDataBuffer: memory buffer which contains the decrypted
        *        contents of the data file.
        * @return ENoRights, ERightsExpired if the data file could not be opened
        *         because of insufficient rights, Symbian-wide error codes or
        *         KErrNone in case of success.
        */
        void CheckLicenseL(
            const TDesC& aDataFile,
            HBufC8*& aDataBuffer);

    };

#endif      // DRMLICENSECHECKER_H   
            
// End of File
