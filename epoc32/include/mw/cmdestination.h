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
* Description:  Destination interface class.
*
*/

#ifndef DESTINATION_H
#define DESTINATION_H

// System includes
#include <cmconnectionmethod.h>
#include <cmmanagerdef.h>
#include <e32def.h>
#include <e32base.h>
#include <metadatabase.h>

// FORWARD DECLARATIONS
class CCmManagerImpl;
class CCmDestinationData;
class CGulIcon;

/**
 *  RCmDestination is for setting/getting values of a network destination.
 *
 *  @lib cmmanager.lib
 *  @since S60 v3.2
 */
NONSHARABLE_CLASS(RCmDestination)
    {
    //=====================================================================
    // Constructors/Destructors
    // 
    public:
    
        /** Default constructor. */
        IMPORT_C RCmDestination();

        IMPORT_C ~RCmDestination();

        IMPORT_C RCmDestination(const RCmDestination& aCmDestination);
        
    //=====================================================================
    // API functions
    public:

        /**
        * Close the session.
        *
        * @since S60 3.2
        */
        IMPORT_C void Close();
            
        /**
        * Returns the number of connection methods of the destination
        *
        * @since 3.2
        * @return the number of connection methods belonging to a destination        
        */                 
        IMPORT_C TInt ConnectionMethodCount() const;
        
        /**
        * Returns a reference to the connection method. 
        * The index must be less than the return value of 
        * ConnectionMethodCount().
        *
        * @since 3.2
        * @param anIndex
        * @return a connection method
        */        
        IMPORT_C RCmConnectionMethod ConnectionMethodL( TInt anIndex ) const;

        /**
        * Returns the connection method with the ECmId.
        * Leaves with KErrNotFound if not found.
        * @param aCmId unique id of the requested connection method.
        * @return connection method
        */
        IMPORT_C RCmConnectionMethod ConnectionMethodByIDL( 
                                                        TInt aCmId ) const;

        /**
        * Return the priority of the passed connection method
        *
        * @since 3.2
        * @param aCCMItem connection method
        * @return the priority of the queried connection method 
        */
        IMPORT_C TUint PriorityL(const RCmConnectionMethod& aCCMItem ) const;
        
        //Getting attributes

        /**
        * Returns the destination's Name attribute
        * HBuf ownership is passed to the caller
        *
        * @since 3.2
        * @return HBufC* Passes returned value's ownership to the caller
        */      
        IMPORT_C HBufC* NameLC() const;                        
        
        /**
        * Returns the destination's Id attribute
        *
        * @since 3.2
        * @return the destination's id
        */                    
        IMPORT_C TUint32 Id() const;
        
        /**
        * Returns the destination's ElementId attribute
        *
        * @since 3.2
        * @return the destination's element id        
        */            
        IMPORT_C TUint32 ElementId() const;        
                
        /**
        * Returns the Icon pointer
        * This function leaves if the client does not have a valid UI context
        *
        * @since 3.2
        * @return the destination icon  
        */ 
        IMPORT_C CGulIcon* IconL() const;

        /**
        * Returns the Metadata
        *
        * @since 3.2
        * @param aMetaField the meta data field to query
        * @return the value of the requested field        
        */            
        IMPORT_C TUint32 MetadataL( CMManager::TSnapMetadataField aMetaField ) const;
    
        /**
        * Return the protection level of the destination.
        *
        * @since 3.2              
        * @return protection level of the destination
        */
        IMPORT_C CMManager::TProtectionLevel ProtectionLevel() const;

        /**
        * Returns if there's a connection created with any of the destination's
        * connection method.
        *
        * @since 3.2        
        * @return ETrue if there's a connection with any of the destination's
        * connection method.
        */
        IMPORT_C TBool IsConnectedL() const;
        
        /**
        * Returns whether the destination is hidden or not.
        *
        * @since 3.2
        * @return ETrue if the destination is hidden
        */
        IMPORT_C TBool IsHidden() const;

        /**
        * checks if destinations are the same 
        * 
        * @since S60 3.2
        * @param aDestination the destination being compared
        * @return ETrue if the destinations are the same
        */
        IMPORT_C TBool operator==(const RCmDestination& aDestination ) const;
        
        /**
        * checks if destinations are not the same 
        * 
        * @since S60 3.2
        * @param aDestination the destination being compared
        * @return ETrue if the destinations are different
        */
        IMPORT_C TBool operator!=(const RCmDestination& aDestination ) const;

        /**
        * assignment operator 
        * 
        * @since S60 3.2
        * @param aDestination the destination being compared
        * @return RCmDestination
        */
        IMPORT_C RCmDestination& operator=(const RCmDestination& 
                                                    aCmDestination);

                /**
        * Create a connection method that belongs to this destination.
        * @param aImplementationUid - implementation uid (bearer type) of the 
        * connection method to be created
        * @return newly created connection method
        */
        IMPORT_C RCmConnectionMethod CreateConnectionMethodL( TUint32 aBearerType );

        /*
        * Adds an existing connection method to a destination
        * @param aConnectionMethod Connection method to be added
        * @return index in the Connection Method list
        */
        IMPORT_C TInt AddConnectionMethodL( RCmConnectionMethod aConnectionMethod );            

        /*
        * Embeds an existing destination into this destination.
        * @param RCmDestination - Destination to be embedded
        * @return TInt - index in the Connection Method list
        */
        IMPORT_C TInt AddEmbeddedDestinationL( const RCmDestination& aDestination );     

        /**
        * Remove a connection method from a destination and delete it
        * on update. 
        * Exception: conenction method is not deleted  if it's referenced 
        * from any other destination.
        * @param aConnectionMethod the connection method to be deleted.
        */
        IMPORT_C void DeleteConnectionMethodL( RCmConnectionMethod& aConnectionMethod );

        /**
        * Remove connection method from the destination
        * @param aConnectionMethod connection method to be removed
        */
        IMPORT_C void RemoveConnectionMethodL( RCmConnectionMethod aConnectionMethod );


        /**
        * Set the connection method's priority based on the passed index.
        * @param aCCMItem the connection method item
        * @param aIndex the new priority of the connection method in the 
        * destination
        */
        IMPORT_C void ModifyPriorityL( RCmConnectionMethod& aCCMItem, 
                                       TUint aIndex );

        /**
        * Set the destination's name
        * @param aDestinationName new name of the destination
        */
        IMPORT_C void SetNameL( const TDesC& aName );

        /**
        * Set the destination's icon index.
        * This fucton leaves if the client does not have a valid UI context
        * @param aIconIndex new icon index of the destination
        */
        IMPORT_C void SetIconL( TUint32 anIndex );

        /**
        * Set the Metadata
        * @param aMetaField field to be modified
        * @param aValue value to be set
        */            
        IMPORT_C void SetMetadataL( CMManager::TSnapMetadataField aMetaField, 
                                    TUint32 aValue );

        /**
        * Set the protection level of the destination.
        * @param aProtLevel new protection level 
        */
        IMPORT_C void SetProtectionL( CMManager::TProtectionLevel aProtLevel );

        /**
        * Set if the destination is hidden or not.
        * @param aHidden - ETrue if destination is hidden
        */
        IMPORT_C void SetHiddenL( TBool aHidden );         

        /**
        * Update all values of the destination and its connection method.
        * Nothing if stored, if update leaves due to any reason.
        */
        IMPORT_C void UpdateL();               

        /**
        * Delete destination and its connection methods from CommsDat.
        * Connection methods that belong to other destination, too, are
        * not deleted.
        */
        IMPORT_C void DeleteLD();

        /**
        * Create a connection method with given id that belongs to this destination.
        * @param aImplementationUid - implementation uid (bearer type) of the 
        * connection method to be created
        * @return newly created connection method or leaves with
        * KErrAlreadyExists if there exists CM with the same Id.
        */
        IMPORT_C RCmConnectionMethod CreateConnectionMethodL( TUint32 aBearerType,
                                                              TUint32 aConnMethId );


    //=======================================================================
    // Member variables
    //
    private: 
        
        /**
         * the implementation class
         */
        CCmDestinationData* iDestinatonData;

    private:
    
        friend class RCmManager;
        friend class RCmConnectionMethod;
    };
    

#endif // DESTINATION_H
