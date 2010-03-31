/*
* Copyright (c) 2004-2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  An interface for static contact store properties
*
*/


#ifndef MVPBKCONTACTSTOREPROPERTIES_H
#define MVPBKCONTACTSTOREPROPERTIES_H


// INCLUDES
#include <e32cmn.h>
#include <tvpbkcontactstoreuriptr.h>

// FORWARD DECLARATIONS
class MVPbkFieldTypeList;

//Use this UID to access contact store propertiesextension 2. 
//Used as a parameter to ContactStorePropertiesExtension() method.
const TUid KMVPbkContactStorePropertiesExtension2Uid = { 2 };

// CLASS DECLARATIONS

/**
 * An interface for static contact store properties.
 *
 * Client can retrieve the static store properties using this
 * interface. The store must be opened before usage.
 *
 * @see MVPbkContactStore::StoreProperties
 */
class MVPbkContactStoreProperties
    {
    public:  // Destructor
        virtual ~MVPbkContactStoreProperties() {}

    public:  // New functions
        /**
         * Returns the EContactStoreUriStoreLocation component of the URI.
         *
         * The name could be e.g. contacts.cdb.
         *
         * @return The EContactStoreUriStoreLocation component of the URI
         */
        virtual TVPbkContactStoreUriPtr Name() const =0;

        /**
         * Returns the complete URI of the contact store.
         *
         * The URI could be e.g cntdb://c:contacts.cdb
         * @return The complete URI of the store.
         */
        virtual TVPbkContactStoreUriPtr Uri() const =0;

        /**
         * Returns true if the store is read-only.
         * 
         * Contacts can not be created, edited nor deleted if the store 
         * is read-only.
         *
         * @return ETrue if the store is read-only.
         */
        virtual TBool ReadOnly() const =0;

        /**
         * Returns true if the store is persistent. 
         * 
         * Persistent means that if you do changes to a store and 
         * then switch of the power of the phone the contact doesn't disappear 
         * but can be retrieved from the store later. E.g. a store in RAM
         * wouldn't be persistent.
         *
         * @return ETrue if the store is persistent.
         */
        virtual TBool Persistent() const =0;

        /**
         * Returns true if the store is local. 
         *
         * The data is stored in the device.
         * This is the opposite of the remote stores. E.g. stores that
         * are in device memory, memory card or SIM card are local stores.
         * Stores that reside in an external device are not local.
         *
         * @return ETrue if the store is local
         */
        virtual TBool Local() const =0;

        /**
         * Returns true if the data is stored on removable media.
         *
         * It means that store can be removed from the device 
         * run time by the user. Memory card is typically this kind of
         * memory and also SIM card can be removed run time in some devices.
         * Remote stores are also removable since user can e.g. switch to
         * offline mode.
         *
         * @return ETrue if the store data is stored on removable media.
         */
        virtual TBool Removable() const =0;

        /**
         * Returns true if the store supports field labels. 
         * 
         * The support here means a global support i.e all fields of
         * the store support labels.
         *
         * @return ETrue if the store supports field labels.
         * @see MVPbkStoreContactField::SupportsLabel
         */
        virtual TBool SupportsFieldLabels() const =0;

        /**
         * Returns true if the store supports defaults fields.
         *
         * Default field information is a contact field attribute and can be
         * retrieved using the attribute manager.
         *
         * @return ETrue if the store supports defaults.
         * @see MVPbkContactAttributeManager
         * @see CVPbkDefaultAttribute
         */
        virtual TBool SupportsDefaults() const =0;

        /**
         * Returns true if the store supports voice tags.
         *
         * Voice tag information is a contact field attribute and can be
         * retrieved using the attribute manager.
         *
         * @return ETrue if the store supports voice tags
         * @see MVPbkContactAttributeManager
         * @see CVPbkVoiceTagAttribute
         */
        virtual TBool SupportsVoiceTags() const =0;

        /**
         * Returns true if the store supports speed dials.
         *
         * Speed dial information is a contact field attribute and can be
         * retrieved using the attribute manager.
         *
         * @return ETrue if the store supports speed dials.
         * @see MVPbkContactAttributeManager
         * @see CVPbkSpeedDialAttribute
         */
        virtual TBool SupportsSpeedDials() const =0;

        /**
         * Returns true if the store supports contact groups.
         *
         * @return ETrue if the store supports contact groups.
         */
        virtual TBool SupportsContactGroups() const =0;

        /**
         * Returns list of supported fields.
         *
         * The list contains a sub set of field types from
         * the master field type list in CVPbkContactManager.
         *
         * @return The list of supported fields
         * @see CVPbkContactManager::FieldTypes
         */
        virtual const MVPbkFieldTypeList& SupportedFields() const =0;

        /**
         * Returns true if the store supports the requested service.
         *
         * @param aServiceUid   The UID that is mapped to a service.
         * @return ETrue if the store supports the requested service.
         */
        virtual TBool SupportsService(TUid aServiceUid) const =0;

        /**
         * Returns an extension point for this interface or NULL.
         *
         * @param aExtensionUid no extensions defined currently.
         * @return an extension point for this interface or NULL.
         */
        virtual TAny* ContactStorePropertiesExtension(TUid /*aExtensionUid*/) { return NULL; }
    };


#endif  // MVPBKCONTACTSTOREPROPERTIES_H

//End of file
