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
* Description:  Connection manager IF class.
*
*/

#ifndef CMMANAGER_H
#define CMMANAGER_H

// System Includes
#include <e32std.h>
#include <e32base.h>
#include <e32cmn.h>
#include <cmdefconnvalues.h>
#include <cmgenconnsettings.h>

// Forward Declarations
class RCmConnectionMethod;
class RCmDestination;
class CCmManagerImpl;
class TBearerPriority;
class CGulIcon;

/**
 *  RCmManager gives access to network destinations and connection methods.
 *
 *  @lib cmmanager.lib
 *  @since S60 v3.2
 */
NONSHARABLE_CLASS(RCmManager)
      {          
    //=====================================================================
    // Constructors/Destructors
    // 
    public:
    
        /**
        * Default constructor. 
        */
        inline RCmManager();

    //=====================================================================
    // API functions
    public:
        
        /**
        * Symbian constructor
        *
        * @since S60 3.2
        */
        IMPORT_C void OpenL();    
        
        /**
        * Symbian constructor
        * Pushes the object on the cleanup stack
        *
        * @since S60 3.2
        */
        IMPORT_C void OpenLC();    
        
        /**
        * Secondary destructor
        *
        * @since S60 3.2
        */
        IMPORT_C void Close();
        
    //=======================================================================
    // Getter API
    public:    
      
        /**
        * Used to query bearer information that doesn't belong
        * to a specific connection method, such as 
        * ECmCoverage or ECmDefaultPriority etc.
        *
        * @since S60 3.2
        * @param aBearerType the bearer
        * @param aAttribute the setting value
        * @return the setting value
        */
        IMPORT_C TUint32 GetBearerInfoIntL( TUint32 aBearerType,
                                  TUint32 aAttribute ) const;
                                  
        
        /**
        * Used to query bearer information that doesn't belong
        * to a specific connection method, such as 
        * ECmCoverage or ECmDefaultPriority etc.
        *
        * @since S60 3.2
        * @param aBearerType the bearer
        * @param aAttribute the setting value
        * @return the setting value
        */
        IMPORT_C TBool GetBearerInfoBoolL( TUint32 aBearerType,
                                 TUint32 aAttribute ) const;
        /**
        * Used to query bearer information that doesn't belong
        * to a specific connection method, such as 
        * ECmCoverage or ECmDefaultPriority etc.
        * HBuf ownership is passed to the caller
        *
        * @since S60 3.2
        * @param aBearerType the bearer
        * @param aAttribute the setting value
        * @return the setting value
        */        
        IMPORT_C HBufC* GetBearerInfoStringL( TUint32 aBearerType,
                                    TUint32 aAttribute ) const;
        /**
        * Used to query bearer information that does not belong
        * to a specific connection method, such as 
        * ECmCoverage or ECmDefaultPriority, etc.
        * HBuf ownership is passed to the caller
        *
        * @since S60 3.2
        * @param aBearerType the bearer
        * @param aAttribute the setting value
        * @return the setting value
        */
        IMPORT_C HBufC8* GetBearerInfoString8L( TUint32 aBearerType,
                                    TUint32 aAttribute ) const;
                    
        /**
        * Used to query any non-bearer specific information about
        * a given connection method. This can be e.g. ECmBearerType,
        * ECmName, ECmStartPage, etc.
        *
        * @since S60 3.2
        * @param aIapId the connection method id
        * @param aAttribute the setting value
        * @return the setting value
        */
        IMPORT_C TUint32 GetConnectionMethodInfoIntL( TUint32 aIapId,
                                             TUint32 aAttribute ) const;
        
        /**
        * Used to query any, non-bearer specific information about
        * a given connection method. This can be e.g. ECmBearerType,
        * ECmName, ECmStartPage, etc.
        *
        * @since S60 3.2
        * @param aIapId the connection method id
        * @param aAttribute the setting value
        * @return the setting value
        */
        IMPORT_C TBool GetConnectionMethodInfoBoolL( TUint32 aIapId,
                                            TUint32 aAttribute ) const;

        /**
        * Used to query any non-bearer specific information about
        * a given connection method. This can be e.g. ECmBearerType,
        * ECmName, ECmStartPage, etc.
        * HBuf ownership is passed to the caller
        *
        * @since S60 3.2
        * @param aIapId the connection method id
        * @param aAttribute the setting value
        * @return the setting value
        */
        IMPORT_C HBufC* GetConnectionMethodInfoStringL( TUint32 aIapId,
                                               TUint32 aAttribute ) const;

        /**
        * Used to query any non-bearer specific information about
        * a given connection method. This can be e.g. ECmBearerType,
        * ECmName, ECmStartPage, etc.
        * HBuf ownership is passed to the caller
        *
        * @since S60 3.2
        * @param aIapId the connection method id
        * @param aAttribute the setting value
        * @return the setting value
        */
        IMPORT_C HBufC8* GetConnectionMethodInfoString8L( TUint32 aIapId,
                                               TUint32 aAttribute ) const;
                
        /**
        * Returns the connection method queried by its ID
        *
        * @since S60 3.2
        * @param aConnectionMethodId id of the connection method
        * @return RCmConnectionMethod connection method
        */
        IMPORT_C RCmConnectionMethod ConnectionMethodL( 
                                     TUint32 aConnectionMethodId ) const;
                        
        /**
        * Returns the list of connection methods. Connection Methods are 
        * filtered by the switch parameters e.g. aLegacyOnly.
        *
        * @since S60 3.2
        * @param aCMArray on return it is the array of IAP ids.
        * @param aCheckBearerType If ETrue only connection methods with 
        *                         supported bearer type are returned
        * @param aLegacyOnly when set to ETrue only Legacy IAP ids will
        *                         be returned
        * @param aEasyWlan when set to ETrue EasyWlan id is returned, too
        */
        IMPORT_C void ConnectionMethodL( RArray<TUint32>& aCMArray, 
                                         TBool aCheckBearerType = ETrue,
                                         TBool aLegacyOnly = ETrue,
                                         TBool aEasyWlan = EFalse ) const;
        
        /**
        * Returns an array of all destination id's
        *
        * @since S60 3.2
        * @param aDestArray list all available destinations' id
        */ 
        IMPORT_C void AllDestinationsL( RArray<TUint32>& aDestArray ) const;

        /**
        * Returns the destination to which a specified 
        * connection method belongs, search is by destination ID
        *
        * @since S60 3.2
        * @param aDestinationId id of destination
        * @return RCmDestination network destination 
        */
        IMPORT_C RCmDestination DestinationL( TUint32 aDestinationId ) const;
       
        /**
        * Returns the copy of the bearer priority array. Ownership is passed.
        *
        * @since S60 3.2
        * @param aArray bearer priority array
        */          
        IMPORT_C void BearerPriorityArrayL( 
                                   RArray<TBearerPriority>& aArray ) const;
       
        /**
        * Clean up passed global bearer priority array. Delete
        * the elements and calls Reset and Close on the array.
        *
        * @since S60 3.2
        * @param aArray array to be cleaned up
        */
        IMPORT_C void CleanupGlobalPriorityArray( 
                                   RArray<TBearerPriority>& aArray ) const;
        
        /**
        * Returns the id of the EasyWlan connection method.
        *
        * @since S60 3.2
        * @return id of the EasyWLan connection method. 0 if not found.
        */
        IMPORT_C TUint32 EasyWlanIdL() const;
        
        /**
        * Returns the default connection method/SNAP.
        *
        * @since S60 3.2
        */
        IMPORT_C void ReadDefConnL( TCmDefConnValue& aDCSetting );

        /**
        * Stores the default connection method/SNAP.
        *
        * @since S60 3.2
        */
        IMPORT_C void WriteDefConnL( const TCmDefConnValue& aDCSetting );  


        /**
        * Returns the general connection settings.
        *
        * @since S60 9.2
        */
        IMPORT_C void ReadGenConnSettingsL( TCmGenConnSettings& aGenConnSettings );

        /**
        * Writes the general connection settings.
        *
        * @since S60 9.2
        */
        IMPORT_C void WriteGenConnSettingsL( const TCmGenConnSettings& aGenConnSettings );
        
        
        /** Open session and create tables if they don't exist*/
        IMPORT_C void CreateTablesAndOpenL();    

        /**
        * Creates a Destination with the passed name. 
        * @param aName the name of the new destination.
        * @return RCmDestination new destination. ownership is passed to the 
        * caller
        */
        IMPORT_C RCmDestination CreateDestinationL( const TDesC& aName );

        /**
        * Creates a connection method does not belong to any destination
        * @param aImplementationUid - bearer type of the new connection method
        * @return RCmConnectionMethod newly created connection method.
        */
        IMPORT_C RCmConnectionMethod CreateConnectionMethodL( TUint32 aBearerType );        

        /**
        * Copies a connection method belonging to one destination to 
        * another. The connection method becomes shared.
        * Calls UpdateL on the destination
        * @param aTargetDestination
        * @param aConnectionMethodId
        * @return TInt - index in the Connection Method list
        */
        IMPORT_C TInt CopyConnectionMethodL( RCmDestination& aTargetDestination,
                                             RCmConnectionMethod& aConnectionMethod );

        /**
        * Moves a connection method belonging to one destination to 
        * another. The connection method is removed from the source destination
        * @param aSourceDestination
        * @param aTargetDestination
        * @param aConnectionMethod
        * @return TInt - index in the Connection Method list
        */
        IMPORT_C TInt MoveConnectionMethodL( RCmDestination& aSourceDestination,
                                             RCmDestination& aTargetDestination,
                                             RCmConnectionMethod& aConnectionMethod );

        /**
        * Remove connection method from the destination
        * @param aDestination destination the connection method is attached to
        * @param aConnectionMethod connection method to be removed
        */
        IMPORT_C void RemoveConnectionMethodL( RCmDestination& aDestination,
                                               RCmConnectionMethod& aConnectionMethod );

        /**
        * Removes connection method from every destination and make it 
        * uncategorized.
        * @param aConnectionMethod connection method to be removed
        */
        IMPORT_C void RemoveAllReferencesL( RCmConnectionMethod& aConnectionMethod );

        /**
        * Update bearer priority array
        * @param aArray array with new global bearer priority
        */          
        IMPORT_C void UpdateBearerPriorityArrayL( const RArray<TBearerPriority>& aArray );

        /**
        * Creates a Destination with the passed name and id. 
        * @param aName the name of the new destination.
        * @param aDestId Predefined id of the destination.
        * @return RCmDestination newly created destination or leaves with
        * KErrAlreadyExists if there exists CM with the same Id.
        * Ownership is passed to the caller.
        */
        IMPORT_C RCmDestination CreateDestinationL( const TDesC& aName,
                                                       TUint32      aDestId );

        /**
        * Creates a connection method does not belong to any destination
        * @param aImplementationUid - bearer type of the new connection
        * method
        * @param aConnMethodId Predefined id for the connection method.
        * @return RCmConnectionMethod newly created connection
        * method or leaves with KErrAlreadyExists if there exists CM
        * with the same Id.
        */
        IMPORT_C RCmConnectionMethod CreateConnectionMethodL( TUint32 aImplementationUid,
                                                              TUint32 aConnMethodId );

        /**
        * Query all of the supported bearer types.
        * @param aArray list of all supported bearer types.
        */          
        IMPORT_C void SupportedBearersL( RArray<TUint32>& aArray ) const;

        /**
        * Returns "Uncategorized" icon.
        * This fucton leaves if the client does not have a valid UI context
        * @return CGulIcon* Icon of uncategorized connection methods. Ownership 
        * is passed.
        */          
        IMPORT_C CGulIcon* UncategorizedIconL() const;
        
    private:
        /**
        * This is a private copy constructor without implementation.
        * The sole purpose of this declaration is to forbid the copying of 
        * the objects of this class.
        */          
        RCmManager(RCmManager&  );
        /**
        * This is a private copy constructor without implementation.
        * The sole purpose of this declaration is to forbid the copying of 
        * the objects of this class.
        */          
        RCmManager& operator=( RCmManager& );
    //=========================================================================
    // Member data
    
    private:
    
        /**
         * the implementation class
         */
        CCmManagerImpl* iImplementation;
    };

#include "cmmanager.inl"
    
#endif // CMMANAGER_H
