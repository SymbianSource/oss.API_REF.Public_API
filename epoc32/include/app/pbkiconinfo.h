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
* Description: 
*           Phonebook icon info class definition.
*
*/


#ifndef __PbkIconInfo_H__
#define __PbkIconInfo_H__

//  INCLUDES
#include <e32base.h>        // CBase
#include <PbkIconId.hrh>    // TPbkIconId
#include <AknsItemID.h>     // TAknsItemID

// FORWARD DECLARATIONS
class TResourceReader;
class CCoeEnv;
class CGulIcon;
class CPbkIconInfoContainer;
class MAknsSkinInstance;

// CLASS DECLARATION

/**
 * Phonebook icon information encapsulating class.
 * @see CPbkIconInfoContainer
 * @deprecated
 */
class TPbkIconInfo
    {
    public: // interface
        /**
         * Returns the unique Phonebook icon id of this icon.
         * @return The unique Phonebook icon id of this icon.
         */
        IMPORT_C TPbkIconId PbkIconInfoId() const;

        /**
         * Returns the bitmap file name of this icon.
         * @return The bitmap file name of this icon.
         */
        IMPORT_C const TDesC& MbmFileName() const;

        /**
         * Returns this icon's id in the bitmap file.
         * @return This icon's id in the bitmap file.
         */
        IMPORT_C TInt IconId() const;

        /**
         * Returns this icon's mask id in the bitmap file.
         * @return This icon's mask id in the bitmap file.
         */
        IMPORT_C TInt MaskId() const;

        /**
         * Returns this icon's skin id.
         * @return This icon's skin id.
         */
        IMPORT_C TAknsItemID SkinId() const;

        /**
         * Returns this icon's color table id.
         * @return This icon's color table id.
         */
        TAknsItemID ColorId() const;

        /**
         * Returns this icon's index in the color table.
         * @return This icon's index in the color table.
         */
        TInt ColorIndex() const;

        /**
         * Returns this icon's index in the color table.
         * @return This icon's index in the color table.
         */
        TInt DefaultColorIndex() const;

    private:  // Interface for CPbkIconInfoContainer
        friend class CPbkIconInfoContainer;
        TPbkIconInfo();
        ~TPbkIconInfo();
        void ReadFromResourceLC(TResourceReader& aReader);
        void Destroy();

    private:  // Unimplemented functions
        /// Private, unimplemented copy constructor
        TPbkIconInfo(const TPbkIconInfo&);
        /// Private, unimplemented assignment operator
        TPbkIconInfo& operator=(const TPbkIconInfo&);

    private: // data members
        // Own: unique phonebook icon id
        TPbkIconId iPbkIconInfoId;
        // Own: Icon bitmap
        TInt iIconId;
        // Own: mask bitmap
        TInt iMaskId;
        // Ref: Mbm file name
        HBufC* iMbmFileName;
        /// Own: SkinId
        TAknsItemID iSkinId;        
        /// Own: ColorId
        TAknsItemID iColorId;
        /// Own: Color index
        TInt iColorIndex;
        /// Own: Default color index
        TInt iDefaultColorIndex;
    };


/**
 * Collection of phonebook icon info objects.
 * @see TPbkIconInfo
 * @deprecated
 */
class CPbkIconInfoContainer : public CBase
    {
    public: // Constructors and destructor
        /**
         * Creates a new instance of this class intialized with Phonebook 
         * default icon info from PbkView.rsc. Note that PbkView.rsc has to
         * be loaded, see RPbkViewResourceFile.
         *
         * @param aCoeEnv   Optional CCoeEnv instance. This function performs
         *                  faster if this parameter is provided.
         * @return A new instance of this class.
         */
        IMPORT_C static CPbkIconInfoContainer* NewL(CCoeEnv* aCoeEnv=NULL);
        
        /**
         * Creates a new instance of this class.
         *
         * @param aReader   Resource reader initialized to point to an array
         *                  of PBK_ICON_INFO resources.
         * @return A new instance of this class.
         */
        IMPORT_C static CPbkIconInfoContainer* NewL(TResourceReader& aReader);

        /**
         * Creates a new instance of this class.
         *
         * @param aResourceId Resource id of an array of PBK_ICON_INFO 
         *                  resources. Phonebook default icon info 
         *                  array's resource id is R_PBK_ICON_INFO_ARRAY
         *                  in PbkView.rsc.
         * @param aCoeEnv   Optional CCoeEnv instance. This function performs
         *                  faster if this parameter is provided.
         * @return A new instance of this class.
         */
        IMPORT_C static CPbkIconInfoContainer* NewL
            (TInt aResourceId, CCoeEnv* aCoeEnv=NULL);
        
        /**
         * Destructor.
         */
        ~CPbkIconInfoContainer();

    public:  // Interface
        /**
         * Finds a particular TPbkIconInfo in the container.
         *
         * @param aIconId   Id of the icon info to search.
         * @return Matching icon info or NULL if not found.
         */
        IMPORT_C const TPbkIconInfo* Find(TPbkIconId aIconId) const;

        /**
         * Creates and returns a CGulIcon object corresponding to the aIconId. 
         * ownership of the returned object is transferred to the client. Returns
         * NULL if icon id is not in the array.
         *
         * @param aIconId   Phonebook icon id.
         * @return Icon object corresponding to the icon id. NULL if not found.
         */
        IMPORT_C CGulIcon* LoadBitmapL(TPbkIconId aIconId) const;

        /**
         * Appends new icon info elements from aResourceId. The resource must
         * be of PBK_ICON_INFO type.
         *
         * @param aResourceId Resource id for icon infos to be added. 
         */
        IMPORT_C void AppendIconsFromResourceL(TInt aResourceId);

    private: // Implementation
        CPbkIconInfoContainer();
        void ConstructL(TResourceReader& aReader);
        void DoAppendIconsFromResourceL(TResourceReader& aReader);

    private: // data members
        /// Own: array of icon infos
        RArray<TPbkIconInfo> iIconArray;
    };

/**
 * Phonebook icon utilility class. This class is a helper class
 * for loading skinned bitmaps.
 */
class PbkIconUtils
    {
    public:
        /**
         * Creates a skinned icon from the aIconInfo information.
         * @param aSkin Pointer to a skin instance.
         * @param aBitmap   Bitmap to set.
         * @param aMask Mask to set.
         * @param aIconInfo Bitmap and mask information.
         */
        IMPORT_C static void CreateIconL(
                MAknsSkinInstance* aSkin, 
                CFbsBitmap*& aBitmap, 
                CFbsBitmap*& aMask, 
                const TPbkIconInfo& aIconInfo);

        /**
         * Creates a skinned icon from the aIconInfo information.
         * @param aSkin Pointer to a skin instance.
         * @param aBitmap   Bitmap to set.
         * @param aMask Mask to set.
         * @param aIconInfo Bitmap and mask information.
         */
        IMPORT_C static void CreateIconLC(
                MAknsSkinInstance* aSkin, 
                CFbsBitmap*& aBitmap, 
                CFbsBitmap*& aMask, 
                const TPbkIconInfo& aIconInfo);
    private:
        PbkIconUtils();
        ~PbkIconUtils();
    };


#endif // __PbkIconInfo_H__

// End of File
