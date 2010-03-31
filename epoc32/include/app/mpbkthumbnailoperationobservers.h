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
*      Phonebook asyncronous thumbnail operation observer interfaces.
*
*/


#ifndef __MPbkThumbnailOperationObservers_H__
#define __MPbkThumbnailOperationObservers_H__

//  INCLUDES
#include <e32def.h>

//  FORWARD DECLARATIONS
class MPbkThumbnailOperation;
class CFbsBitmap;
class CPbkImageDataWithInfo;

// CLASS DECLARATION

/**
 * Observer interface for CPbkThumbnailManager get operation.
 * Only one of the event callbacks is called once by the operation.
 *
 * @see CPbkThumbnailManager::GetThumbnailAsyncL
 */
class MPbkThumbnailGetObserver
    {
    public:
        /**
         * Called when thumbnail loading is completed.
         *
         * @param aOperation    The completed operation.
         * @param aBitmap       The loaded bitmap. Callee is responsible of 
         *                      the bitmap.
         */
        virtual void PbkThumbnailGetComplete
            (MPbkThumbnailOperation& aOperation, CFbsBitmap* aBitmap) =0;

        /**
         * Called if the thumbnail loading fails.
         *
         * @param aOperation    The failed operation.
         * @param aError        Error code of the failure.
         */
        virtual void PbkThumbnailGetFailed
            (MPbkThumbnailOperation& aOperation, TInt aError) =0;
    };


/**
 * Observer interface for CPbkThumbnailManager get image operation.
 * Only one of the event callbacks is called once by the operation.
 *
 * @see CPbkThumbnailManager::GetThumbnailImageAsyncL
 */
class MPbkThumbnailGetImageObserver
    {
    public:
        /**
         * Called when thumbnail loading is completed.
         *
         * @param aOperation    The completed operation.
         * @param aImageData    The thumbnail image. Caller is responsible
         *                      of the object.
         */
        virtual void PbkThumbnailGetImageComplete
            (MPbkThumbnailOperation& aOperation, CPbkImageDataWithInfo* aImageData) =0;

        /**
         * Called if the thumbnail loading fails.
         *
         * @param aOperation    The failed operation.
         * @param aError        Error code of the failure.
         */
        virtual void PbkThumbnailGetImageFailed
            (MPbkThumbnailOperation& aOperation, TInt aError) =0;
    };


/**
 * Observer interface for CPbkThumbnailManager set operations.
 * Only one of the event callbacks is called once by the operation.
 *
 * @see CPbkThumbnailManager::SetThumbnailAsyncL
 */
class MPbkThumbnailSetObserver
    {
    public:
        /**
         * Called when thumbnail setting is completed.
         *
         * @param aOperation    The completed operation.
         */
        virtual void PbkThumbnailSetComplete
            (MPbkThumbnailOperation& aOperation) =0;

        /**
         * Called if the thumbnail setting fails.
         *
         * @param aOperation    The failed operation.
         * @param aError        Error code of the failure.
         */
        virtual void PbkThumbnailSetFailed
            (MPbkThumbnailOperation& aOperation, TInt aError) =0;
    };

#endif // __MPbkThumbnailOperationObservers_H__

// End of File
