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
*
*/




#ifndef AKN_ICON_SRV_CLIENT_H
#define AKN_ICON_SRV_CLIENT_H

#include <e32base.h>
#include <AknIconUtils.h>

struct TAknIconParams;
struct TAknIconInitData;
class CAknBitmap;
class CAknIconManager;


/**
 * A client-side handle to a session with an icon server which allows handling
 * icons (bitmaps).
 * 
 * @since 3.0
 */
class RAknIconSrvClient : public RSessionBase
    {
    
    public: // New functions

        /**
         * C++ default constructor.
         */      
        RAknIconSrvClient();

        /**
         * Connects AknIconSrv session. It is stored in TLS.
         * Application framework calls this in application startup.
         *
         * @since 3.0
         * @return Symbian OS standard error code.
         */      
        IMPORT_C static TInt Connect();

        /**
         * Disconnects the session.
         * @since 3.0
         */
        IMPORT_C static void Disconnect();

        /**
         * Returns the connected server client from TLS.
         *
         * @return The connected server client from TLS.
         * @panic EClientSessionNotConnected @c Connect() has not been called
         *        successfully earlier.
         */
        static RAknIconSrvClient* GetSession();

    public: // But not exported.

        /**
         * Initializes the given bitmap and mask according to the member data 
         * stored in them and the given pixel size.
         *
         * @param[in] aBitmap Bitmap.
         * @param[in] aMask Mask of the bitmap.
         * @param[out] aContentDimensions The content dimensions if it is 
         *             a SVG icon.
         * @param aInfo parameters of the icon.
         */
        void InitializeIconL( 
                CAknBitmap& aBitmap,
                CAknBitmap& aMask,
                TAknContentDimensions& aContentDimensions, 
                const TAknIconParams& aInfo ) const;

        /**
         * Frees the shared bitmap.
         *
         * @param aBitmap Bitmap.
         */
        void FreeBitmap( CAknBitmap& aBitmap ) const;

        /**
         * Gets content dimensions of the icon.
         *
         * @param[in] aBitmap Bitmap.
         * @param[out] aContentDimensions The content dimensions of an icon.
         * @return Symbian OS standard error code .
         */
        TInt GetContentDimensions( 
                CAknBitmap& aBitmap, 
                TAknContentDimensions& aContentDimensions ) const;

        /**
         * Preserves icon data (e.g. SVG-T DOM tree) in memory.
         *
         * @param aBitmap Bitmap.
         * @return Symbian OS standard error code .
         */
        TInt PreserveIconData( CAknIconManager& aBitmap ) const;

        /**
         * Removes icon data (e.g. SVG-T DOM tree) from the memory.
         *
         * @param aBitmap Bitmap.
         */
        void DestroyIconData( CAknIconManager& aBitmap ) const;

        /**
         * Retrieves initialization data from server side.
         *
         * @param[out] aData Initialization data.
         */
        void GetInitData( TAknIconInitData& aData ) const;

        /**
         * Test functions (debug only).
         */
        void __SERVER_HEAP_MARK() const;
        void __SERVER_HEAP_MARKEND() const;
        void __SERVER_HEAP_FAILNEXT( TInt aCount ) const;
        void __SERVER_HEAP_FAILNEXT_INCREASING( TInt aCount ) const;
        void __SERVER_HEAP_RESET() const;
        void __SERVER_RESET_DYNAMICALLY_CHANGING_ALLOCATIONS() const;
        TInt __SERVER_HEAP_USED() const;
        void __SERVER_SET_PREFERRED_ICON_DISPLAY_MODE(
                                                    TDisplayMode aMode ) const;

        /**
         * Connects to server.
         *
         * @return Symbian OS standard error code .
         */
        TInt ConnectToServer();
        
		/**
		 * Enable or disable the AknIcon cache.
		 *
		 * @return Symbian OS standard error code .
  		 */
        TInt EnableCache(TBool aEnable);

    private: // Data
        TInt iConnections;
    };

#endif // AKN_ICON_SRV_CLIENT_H

// End of File
