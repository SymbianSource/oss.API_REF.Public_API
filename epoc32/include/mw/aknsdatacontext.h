/*
* Copyright (c) 2002 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Defines a public interface class MAknsDataContext.
*
*/


#ifndef AKNSDATACONTEXT_H
#define AKNSDATACONTEXT_H

//  INCLUDES
#include <AknsConstants.h>
#include <AknsItemID.h>
#include <coemop.h>

// CLASS DECLARATION

/**
* Interface that provides context sensitive control over data allocation.
* MAknsDataContext can be used to indicate need for specific skin items
* and thus to ensure that they are allocated before first use.
*
* This is a public class with exported functions.
* The class is not usually intended for user derivation - concrete classes
* implementing the interface are provided by the library.
* See @c AknsUtils::CreateDataContextForContainerL() for further 
* details.
*
* @lib AknSkins.lib
*
* @since 2.0
*/
class MAknsDataContext 
    {
    public: // Type UID
        /**         
        * Type ID declaration.
        * Type ID is used to make it possible to retrieve data context
        * through @c MObjectProvider::MopSupplyObject interface.
        */
        DECLARE_TYPE_ID(0x10005a28)

    public:  // Constructors and destructor    

        /**
        * Destructor.
        * Destructor is only provided to enable deletion using base class
        * pointer. Caller should never delete context retrieved using
        * @c MObjectProvider interface.
        */
        inline virtual ~MAknsDataContext() {}
        
    public: // New functions

        /**
        * Reserves and allocates specified item.
        * Instructs the data context that the specified item will be used
        * by caller and should be allocated and cached by skin instance.
        * Any control using cached skin items should reserve them, preferably
        * in @c ConstructL(), by calling this method.
        * Note that reservation does not guarantee that the item will be
        * available in cache - it's only a tentative request for allocation.
        *
        * @since 2.0
        *
        * @param aID Item ID of the item to be reserved.
        *
        * @par Exceptions:
        *   If item data allocation fails, function leaves with error code.
        */
        virtual void ReserveItemL( const TAknsItemID& aID ) =0;

		/**
        * Indicates that specified item will no longer be used.
        * Instructs the data context that the specified item will not
        * be used by caller anymore. Exact behavior (e.g. whether cached
        * instance is deallocated) depends on the cache policy of data
        * context and skin instance. Controls should not usually call this
        * method, but instead allow data context (in most cases implemented
        * by a container) go out of scope. 
        *
        * @since 2.0
        * 
        * @param aID Item ID of the item to be released.
        */
        virtual void ReleaseItem( const TAknsItemID& aID ) =0;

    protected: // Reserved virtual functions

        /**
        * Reserved for future use.
        *
        * @since 2.0
        */
        virtual TInt Reserved1();

        /**
        * Reserved for future use.
        *
        * @since 2.0
        */
        virtual TInt Reserved2();

    public: // New functions

        /**
        * Returns type UID pointer that can be used in MopSupplyObject.
        *
        * @since 2.0
        *
        * @param aId Type UID, should be the same that was given as aId
        *   parameter of MopSupplyObject.
        *
        * @param aContext Pointer to an MAknsDataContext instance.
        *
        * @return Type UID pointer containing aContext, or @c NULL type UID
        *   pointer if given type UID does not match MAknsDataContext or
        *   aContext is @c NULL.
        */
        IMPORT_C static TTypeUid::Ptr SupplyMopObject( TTypeUid aId, 
            MAknsDataContext* aContext );

    };

#endif // AKNSDATACONTEXT_H
            
// End of File
