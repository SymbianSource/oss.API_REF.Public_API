/*
* Copyright (c) 2002-2004 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  Supports common base functionality for DMgr user interfaces
*
*/



#ifndef CDOWNLOADMGRUIBASE_H
#define CDOWNLOADMGRUIBASE_H

//  INCLUDES
#include <E32BASE.H>
#include <ConeResLoader.h>

// FORWARD DECLARATIONS
class CCoeEnv;
class CDownloadMgrUiLibRegistry;
class CUiBaseExtension;
class MAknServerAppExitObserver;

// CLASS DECLARATION

/**
*  Abstaract base class for UI Lib classes with UI controls.
*  It owns a set of downloads that belong to the derived concrete class.
*  Derived classes must implement MHttpDownloadMgrObserver.
*  When constructing one Download Manager must be added.
*
*  @lib Download Manager UI Lib
*  @since Series 60 2.8
*/
NONSHARABLE_CLASS( CDownloadMgrUiBase ) : public CBase
    {
    public: // New functions
        
        TPtrC ResourceFileName() const;

        /**
        * Set an oberver for embedded application exit events. 
        * @param aObserver Exit observer. Can be NULL.
        * @return None.
        */
        IMPORT_C void SetServerAppExitObserver( MAknServerAppExitObserver* aObserver );

        /**
        * Gets the value for a TInt attribute.
        * Leaves with KErrNotSupported, if the attribute is not supported.
        * @param aAttribute Identifies the attribute to be retrived.
        * @param aValue On completion, contains the requested TInt attribute.
        * @return None.
        */
        IMPORT_C virtual void GetIntAttributeL( const TUint aAttribute, TInt32& aValue ) = 0;

        /**
        * Gets the value for a TBool attribute.
        * Leaves with KErrNotSupported, if the attribute is not supported.
        * @param aAttribute Identifies the attribute to be retrived.
        * @param aValue On completion, contains the requested TBool attribute.
        * @return None.
        */
        IMPORT_C virtual void GetBoolAttributeL( const TUint aAttribute, TBool& aValue ) = 0;

        /**
        * Gets the value for a TDes16 attribute.
        * Leaves with KErrNotSupported, if the attribute is not supported.
        * @param aAttribute Identifies the attribute to be retrived.
        * @param aValue On completion, contains the requested TDes16 attribute.
        * @return None.
        */
        IMPORT_C virtual void GetStringAttributeL( const TUint aAttribute, TDes16& aValue  ) = 0;

        /**
        * Gets the value for a TDes8 attribute.
        * Leaves with KErrNotSupported, if the attribute is not supported.
        * @param aAttribute Identifies the attribute to be retrived.
        * @param aValue On completion, contains the requested TDes8 attribute.
        * @return None.
        */
        IMPORT_C virtual void GetStringAttributeL( const TUint aAttribute, TDes8& aValue  ) = 0;

        /**
        * Sets the value for a TInt attribute.
        * Leaves with KErrNotSupported, if the attribute is not supported.
        * @param aAttribute Identifies the attribute to be set.
        * @param aValue The value to be set.
        * @return None.
        */
        IMPORT_C virtual void SetIntAttributeL( const TUint aAttribute, TInt32 aValue ) = 0;

        /**
        * Sets the value for a TBool attribute.
        * Leaves with KErrNotSupported, if the attribute is not supported.
        * @param aAttribute Identifies the attribute to be set.
        * @param aValue The value to be set.
        * @return None.
        */
        IMPORT_C virtual void SetBoolAttributeL( const TUint aAttribute, TBool aValue ) = 0;

        /**
        * Sets the value for a TDesC attribute.
        * Leaves with KErrNotSupported, if the attribute is not supported.
        * @param aAttribute Identifies the attribute to be set.
        * @param aValue The value to be set.
        * @return None.
        */
        IMPORT_C virtual void SetStringAttributeL( const TUint aAttribute, const TDesC16& aValue ) = 0;

        /**
        * Sets the value for a TDesC8 attribute.
        * Leaves with KErrNotSupported, if the attribute is not supported.
        * @param aAttribute Identifies the attribute to be set.
        * @param aValue The value to be set.
        * @return None.
        */
        IMPORT_C virtual void SetStringAttributeL( const TUint aAttribute, const TDesC8& aValue ) = 0;

    protected: // Constructors

        /**
        * C++ default constructor.
        */
        CDownloadMgrUiBase( CDownloadMgrUiLibRegistry& aRegistryModel );

        /**
        * By default Symbian 2nd phase constructor is private.
        */
        void BaseConstructL();

        /**
        * Destructor.
        */
        virtual ~CDownloadMgrUiBase();

    protected:  // Data

        CCoeEnv& iCoeEnv; ///< Reference to CONE environment.

    protected:  // Data

        CDownloadMgrUiLibRegistry&  iRegistryModel; ///< Reference to the Registry.
        MAknServerAppExitObserver*  iServerAppExitObserver; ///< Reference to the observer.

    private:  // Data

        TFileName                   iResourceFileName; ///< Temp storage for the file name.
        RConeResourceLoader         iResourceLoader; ///< Resource loader.
        TBool                       iResourceOpened; ///< Indicate if the resource is opened.

        CUiBaseExtension*           iExtension; ///< Reserved pointer for future extension

    };

#endif /* CDOWNLOADMGRUIBASE_H */
