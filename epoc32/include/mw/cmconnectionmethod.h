/*
* Copyright (c) 2006 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:  Connection Method interface class.
*
*/

#ifndef CMCONNECTIONMETHOD_H
#define CMCONNECTIONMETHOD_H

// INCLUDES
#include <e32base.h>
#include <cmconnectionmethoddef.h>

// CLASS DECLARATION
class CCmPluginBaseEng;
class RCmDestination;

/**
 *  RCmConnectionMethod is for getting/setting values of a connection method.
 *  @lib cmmanager.lib
 *  @since S60 v3.2
 */
NONSHARABLE_CLASS( RCmConnectionMethod )
    {
    //=====================================================================
    // Constructors/Destructors
    // 
    public:
    
        /**
        * Default constructor. 
        */
        IMPORT_C RCmConnectionMethod();


        /**
        * Copy constructor. 
        */
        IMPORT_C RCmConnectionMethod(const RCmConnectionMethod& aItem);


        /**
        * Destructor. 
        */
        IMPORT_C ~RCmConnectionMethod();

    //=====================================================================
    // API functions
    public:
    
        /**
        * Close the session
        *
        * @since S60 3.2
        */
        IMPORT_C void Close();
        
        /**
        * Gets the value for a TInt attribute.
        *
        * @since S60 3.2
        * @param aAttribute Identifies the attribute to be retrieved.
        * @return contains the requested TInt attribute.
        */
        IMPORT_C TUint32 GetIntAttributeL( TUint32 aAttribute ) const;

        /**
        * Gets the value for a TBool attribute.
        *
        * @since S60 3.2
        * @param aAttribute Identifies the attribute to be retrieved.
        * @return contains the requested TBool attribute.
        */
        IMPORT_C TBool GetBoolAttributeL( TUint32 aAttribute ) const;

        /**
        * Gets the value for a String16 attribute.
        * HBuf ownership is passed to the caller
        *
        * @since S60 3.2
        * @param aAttribute Identifies the attribute to be retrieved.
        * @return copy of the requested attribute. Ownership is passed.
        */
        IMPORT_C HBufC* GetStringAttributeL( TUint32 aAttribute ) const;
        
        /**
        * Gets the value for a String8 attribute.
        * HBuf ownership is passed to the caller
        *
        * @since S60 3.2
        * @param aAttribute Identifies the attribute to be retrieved.
        * @return copy of the requested attribute. Ownership is passed.
        */
        IMPORT_C HBufC8* GetString8AttributeL( 
                                        const TUint32 aAttribute ) const;

        /**
        * Call this function only if this CM is an embedded destination!
        *
        * @since S60 3.2
        * @return embedded destination
        */
        IMPORT_C RCmDestination DestinationL() const;

        
        /**
        * checks if connection methods are the same 
        * 
        * @since S60 3.2
        * @param aConnMethod the connection method being compared
        * @return ETrue if the destinations are the same
        */
        IMPORT_C TBool operator==( RCmConnectionMethod& aConnMethod ) const;
        
        /**
        * checks if connection methods are not the same 
        * 
        * @since S60 3.2
        * @param aConnMethod the connection method being compared
        * @return ETrue if the destinations are different
        */
        IMPORT_C TBool operator!=( RCmConnectionMethod& aConnMethod ) const;
        

        /**
        * assignment operator 
        * 
        * @since S60 3.2
        * @return RCmConnectionMethod
        */
        IMPORT_C RCmConnectionMethod& operator=(const RCmConnectionMethod& 
                                                    aConnMethod);

        /**
        * Creates a copy of this connection method. UpdateL() has to be called 
        * to store new connection method in database. Ownership is passed.
        */
        IMPORT_C RCmConnectionMethod CreateCopyL();

                /**
        * Sets the value for a TInt attribute.
        * @param aAttribute Identifies the attribute to be set.
        * @param aValue The value to be set.
        * @return None.
        */
        IMPORT_C void SetIntAttributeL( TUint32 aAttribute, TUint32 aValue );

        /**
        * Sets the value for a TBool attribute.
        * @param aAttribute Identifies the attribute to be set.
        * @param aValue The value to be set.
        * @return None.
        */
        IMPORT_C void SetBoolAttributeL( TUint32 aAttribute, TBool aValue );

        /**
        * Sets the value for a String16 attribute.
        * @param aAttribute Identifies the attribute to be set.
        * @param aValue The value to be set.
        * @return None.
        */
        IMPORT_C void SetStringAttributeL( TUint32 aAttribute, 
                                           const TDesC16& aValue );

        /**
        * Sets the value for a String8 attribute.
        * @param aAttribute Identifies the attribute to be set.
        * @param aValue The value to be set.
        * @return None.
        */
        IMPORT_C void SetString8AttributeL( TUint32 aAttribute, 
                                            const TDesC8& aValue );

        /**
        * Try to delete the connection method. If it is referenced from 
        * any destination, then the references are removed and the 
        * connection method is deleted.
        * Do NOT call this function if you got this
        * connection method from a destination. Call destination's
        * DeleteConnectionMethodL() function instead.
        * @return ETrue if connection method deleted.
        */
        IMPORT_C TBool DeleteL();

        /**
        * Update in the database.
        * @return None.
        */        
        IMPORT_C void UpdateL();

    private:
    
        friend class RCmDestination;
        friend class RCmManager;
        
    private:
        
        /**
         * the implementation class
         */
        CCmPluginBaseEng* iImplementation;
    };

#include <cmconnectionmethod.inl>
    
#endif      // CMCONNECTIONMETHOD_H
