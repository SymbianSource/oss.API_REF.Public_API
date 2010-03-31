/*
* Copyright (c) 2002-2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Virtual Phonebook manager class for contact attributes.
*
*/
 

#ifndef MVPBKCONTACTATTRIBUTEMANAGER_H
#define MVPBKCONTACTATTRIBUTEMANAGER_H

// INCLUDE FILES
#include <e32cmn.h>
#include <e32std.h>

// FORWARD DECLARATIONS
class MVPbkContactOperationBase;
class MVPbkContactLink;
class MVPbkContactFindObserver;
class MVPbkStoreContact;
class MVPbkStoreContactField;
class MVPbkContactAttribute;
class MVPbkStoreContactFieldCollection;

/**
 * Virtual Phonebook single attribute presense observer interface.
 */
class MVPbkSingleAttributePresenceObserver
    {
    public:
        /**
         * Attribute presence query operation completed.
         * @param aOperation    Contact operation that was completed.
         * @param aResult   Result of the query.
         */
        virtual void AttributePresenceOperationComplete(
            MVPbkContactOperationBase& aOperation, TBool aResult ) = 0;

        /**
         * Attribute presence query operation failed.
         * @param aOperation    Contact operation that failed.
         * @param aError        Error code.
         */
        virtual void AttributePresenceOperationFailed(
            MVPbkContactOperationBase& aOperation, TInt aError) = 0;

        /**
         * Returns an extension point for this interface or NULL.
         * @param aExtensionUid Extension identifier.
         * @return Extension object.
         */
        virtual TAny* AttributeSinglePresenceOperationExtension(
            TUid /*aExtensionUid*/) { return NULL; }

    protected:  // Destructor
        /**
         * Destructor.
         */
        virtual ~MVPbkSingleAttributePresenceObserver() { }
    };

/**
 * Virtual Phonebook multiple attribute presense observer interface.
 */
class MVPbkMultiAttributePresenceObserver
    {
    public:
        /**
         * Attribute presence query operation completed.
         * @param aOperation    Contact operation that was completed.
         * @param aResult   Fields with attribute aAttribute, 
         *                  or NULL if there is no fields with that 
         *                  attribute in this contact.
         */
        virtual void AttributePresenceOperationComplete(
            MVPbkContactOperationBase& aOperation, 
            MVPbkStoreContactFieldCollection* aResult) = 0;

        /**
         * Attribute presence query operation failed.
         * @param aOperation    Contact operation that failed.
         * @param aError        Error code.
         */
        virtual void AttributePresenceOperationFailed(
            MVPbkContactOperationBase& aOperation, TInt aError) = 0;

        /**
         * Returns an extension point for this interface or NULL.
         * @param aExtensionUid Extension identifier.
         * @return Extension object.
         */
        virtual TAny* AttributeMultiPresenceOperationExtension(
            TUid /*aExtensionUid*/) { return NULL; }

    protected:  // Destructor
        /**
         * Destructor.
         */
        virtual ~MVPbkMultiAttributePresenceObserver() { }
    };


/**
 * Virtual Phonebook Set attribute observer interface.
 */
class MVPbkSetAttributeObserver
    {
    public:
        /**
         * Attribute operation completed.
         * @param aOperation    Contact operation that was completed.
         */
        virtual void AttributeOperationComplete(
            MVPbkContactOperationBase& aOperation) = 0;

        /**
         * Attribute operation failed.
         * @param aOperation    Contact operation that failed.
         * @param aError        Error code.
         */
        virtual void AttributeOperationFailed(
            MVPbkContactOperationBase& aOperation, TInt aError) = 0;

        /**
         * Returns an extension point for this interface or NULL.
         * @param aExtensionUid Extension identifier.
         * @return Extension object.
         */
        virtual TAny* SetAttributeObserverExtension(
                TUid /*aExtensionUid*/) { return NULL; }

    protected:  // Destructor
        /**
         * Destructor.
         */
        ~MVPbkSetAttributeObserver() { }
    };

/**
 * Abstract interface for contact attribute manager.
 *
 * Contact attribute manager can be used to set global attributes such as speed dials 
 * for contacts or fields of contacts. The attributes can be stored in external 
 * databases so that some kind of mapping is maintained between contacts and 
 * attributes. This interface provides unified access to all global attributes.
 */
class MVPbkContactAttributeManager
    {
    public:
        /**
         * Destructor.
         */
        virtual ~MVPbkContactAttributeManager() { }
        
        /**
         * Lists all contacts having the requested type of 
         * attribute asynchronously.
         *
         * @param aAttributeType    Type of the attribute to search for.
         * @param aObserver Observer for the asynchronous process.
         * @return Newly created handle to the process.
         */
        virtual MVPbkContactOperationBase* ListContactsL(
                TUid aAttributeType, 
                MVPbkContactFindObserver& aObserver) = 0;
                
        /**
         * Lists all contacts matching the given attribute asynchronously.
         *
         * @param aAttribute    Attribute prototype to match against.
         * @param aObserver Observer for the asynchronous process.
         * @return Newly created handle to the process.
         */
        virtual MVPbkContactOperationBase* ListContactsL(
                const MVPbkContactAttribute& aAttribute, 
                MVPbkContactFindObserver& aObserver) = 0;
            
        /**
         * Checks if the given contact has the given attribute.
         *
         * @param aAttributeType    Type of the attribute to check for.
         * @param aContact  Contact whose attributes are checked.
         * @return ETrue if aContact has an attribute of aAttributeType,
         *         EFalse otherwise.
         */
        virtual TBool HasContactAttributeL(
                TUid aAttributeType, 
                const MVPbkStoreContact& aContact) const = 0;
                
        /**
         * Checks if the given contact has an attribute matching the 
         * given attribute.
         *
         * @param aAttribute    Attribute prototype to match against.
         * @param aContact  Contact whose attributes are checked.
         * @return ETrue if aContact has an attribute matching the aAttribute,
         *         EFalse otherwise.
         */
        virtual TBool HasContactAttributeL(
                const MVPbkContactAttribute& aAttribute, 
                const MVPbkStoreContact& aContact) const = 0;

        /**
         * Checks if the given contact field has the given attribute.
         * 
         * @param aAttributeType    Type of the attribute to check for.
         * @param aField    Field whose attributes are checked.
         * @return ETrue if aField has an attribute of aAttributeType,
         *         EFalse otherwise.
         */
        virtual TBool HasFieldAttributeL(
                TUid aAttributeType, 
                const MVPbkStoreContactField& aField) const = 0;
                
        /**
         * Checks if the given contact field has an attribute matching 
         * the given attribute.
         *
         * @param aAttribute Attribute prototype to match against.
         * @param aField Contact field whose attribute is checked.
         * @return ETrue if aField has an attribute matching the aAttribute,
         *         EFalse otherwise.
         */
        virtual TBool HasFieldAttributeL(
                const MVPbkContactAttribute& aAttribute, 
                const MVPbkStoreContactField& aField) const = 0;
            
        /**
         * Returns fields with attribute type aAttributeType, or 
         * NULL if there is no fields with that attribute in this 
         * contact.
         *
         * @param aAttributeType Type of the attribute to find for.
         * @param aContact Contact whose attributes are checked.
         */
        virtual MVPbkStoreContactFieldCollection* FindFieldsWithAttributeLC(
                TUid aAttributeType,
                MVPbkStoreContact& aContact) const = 0;

        /**
         * Returns fields with attribute aAttribute, or NULL if there is no
         * fields with that attribute in this contact.
         *
         * @param aAttribute Attribute prototype to match against.
         * @param aContact Contact whose attributes are checked.
         */
        virtual MVPbkStoreContactFieldCollection* FindFieldsWithAttributeLC(
                const MVPbkContactAttribute& aAttribute,
                MVPbkStoreContact& aContact) const = 0;
        
        /**
         * Finds the first field that has the aAttr and returns
         * a reference to the field or NULL if not found.
         *
         * Note: the returned reference will become invalid if 
         * MVPbkStoreContactFieldCollection::FieldAt is called for
         * different field. If this is a problem then use
         * MVPbkStoreContactField::CloneLC for permanent copy of
         * the field.
         *
         * @param aAttr The attribute that is looked for.
         * @param aContact  Contact whose fields are iterated.
         * @return Returns a reference to the field or NULL if not found.
         */
        virtual MVPbkStoreContactField* FindFieldWithAttributeL(
                const MVPbkContactAttribute& aAttr,
                MVPbkStoreContact& aContact) const = 0;

        /**
         * Asynchronously sets the contact attribute for the contact referred 
         * by the given contact link.
         *
         * @param aContactLink  Link to contact whose attribute to set.
         * @param aAttribute    Attribute to set for the contact.
         * @param aObserver Observer for the asynchronous process.
         * @return Newly created handle to the operation.
         */          
        virtual MVPbkContactOperationBase* SetContactAttributeL(
                const MVPbkContactLink& aContactLink, 
                const MVPbkContactAttribute& aAttribute,
                MVPbkSetAttributeObserver& aObserver) = 0;
        /**
         * Asynchronously sets the contact field attribute for the 
         * give contact field.
         *
         * @param aField    Contact field whose attribute to set.
         * @param aAttribute    Attribute to set for the contact field.
         * @param aObserver Observer for the asynchronous process.
         * @return Newly created handle to the operation.
         */
        virtual MVPbkContactOperationBase* SetFieldAttributeL(
                MVPbkStoreContactField& aField, 
                const MVPbkContactAttribute& aAttribute,
                MVPbkSetAttributeObserver& aObserver) = 0;

        /**
         * asynchronously removes the given attribute from the contact 
         * referred by the aContactLink.
         * 
         * @param aContactLink  Link to the contact whose attribute 
         *                      to remove.
         * @param aAttribute    Attribute to remove from the contact.
         * @param aObserver Observer for the asynchronous process.
         * @return Newly created handle to the operation.
         */
        virtual MVPbkContactOperationBase* RemoveContactAttributeL(
                const MVPbkContactLink& aContactLink, 
                const MVPbkContactAttribute& aAttribute,
                MVPbkSetAttributeObserver& aObserver) = 0;
                
        /**
         * asynchronously removes all attributes having the attribute 
         * type aAttributeType from the contact.
         * 
         * @param aContactLink  Link to the contact whose attribute 
         *                      to remove.
         * @param aAttributeType    Type of the attributes to remove 
         *                          from the contact.
         * @param aObserver Observer for the asynchronous process.
         * @return Newly created handle to the operation.
         */
        virtual MVPbkContactOperationBase* RemoveContactAttributeL(
                const MVPbkContactLink& aContactLink, 
                TUid aAttributeType,
                MVPbkSetAttributeObserver& aObserver) = 0;

        /**
         * Asynchronously removes the given attribute from the 
         * given contact field.
         *
         * @param aField    Field whose attribute to remove.
         * @param aAttribute    Attribute to remove from the contact field.
         * @param aObserver Observer for the asynchronous process.
         * @return Newly created handle to the operation.
         */
        virtual MVPbkContactOperationBase* RemoveFieldAttributeL(
                MVPbkStoreContactField& aField, 
                const MVPbkContactAttribute& aAttribute,
                MVPbkSetAttributeObserver& aObserver) = 0;
                
        /**
         * Asynchronously removes all attributes having the attribute 
         * type aAttributeType from the contact field.
         *
         * @param aField    Field whose attribute to remove.
         * @param aAttributeType    Type of the attributes to remove 
         *                          from the contact field.
         * @param aObserver Observer for the asynchronous process.
         * @return Newly created handle to the operation.
         */
        virtual MVPbkContactOperationBase* RemoveFieldAttributeL(
                MVPbkStoreContactField& aField, 
                TUid aAttributeType,
                MVPbkSetAttributeObserver& aObserver) = 0;

        /**
         * Checks if the given contact has the given attribute asynchronously.
         *
         * @param aAttributeType    Type of the attribute to check for.
         * @param aContact  Contact whose attributes are checked.
         * @param aObserver Observer for the asynchronous process.
         * @return Newly created handle to the operation.
         */
        virtual MVPbkContactOperationBase* HasContactAttributeL(
                TUid aAttributeType, 
                const MVPbkStoreContact& aContact,
                MVPbkSingleAttributePresenceObserver& aObserver) const = 0;
                
        /**
         * Checks if the given contact has an attribute matching the 
         * given attribute asynchronously.
         *
         * @param aAttribute    Attribute prototype to match against.
         * @param aContact  Contact whose attributes are checked.
         * @param aObserver Observer for the asynchronous process.
         * @return Newly created handle to the operation.
         */
        virtual MVPbkContactOperationBase* HasContactAttributeL(
                const MVPbkContactAttribute& aAttribute, 
                const MVPbkStoreContact& aContact,
                MVPbkSingleAttributePresenceObserver& aObserver) const = 0;

        /**
         * Checks if the given contact field has the given attribute 
         * asynchronously.
         * 
         * @param aAttributeType    Type of the attribute to check for.
         * @param aField    Field whose attributes are checked.
         * @param aObserver Observer for the asynchronous process.
         * @return Newly created handle to the operation.
         */
        virtual MVPbkContactOperationBase* HasFieldAttributeL(
                TUid aAttributeType, 
                const MVPbkStoreContactField& aField,
                MVPbkSingleAttributePresenceObserver& aObserver) const = 0;
                
        /**
         * Checks if the given contact field has an attribute matching 
         * the given attribute asynchronously.
         *
         * @param aAttribute Attribute prototype to match against.
         * @param aField Contact field whose attribute is checked.
         * @param aObserver Observer for the asynchronous process.
         * @return Newly created handle to the operation.
         */
        virtual MVPbkContactOperationBase* HasFieldAttributeL(
                const MVPbkContactAttribute& aAttribute, 
                const MVPbkStoreContactField& aField,
                MVPbkSingleAttributePresenceObserver& aObserver) const = 0;
            
        /**
         * Initiates an asynchronous operation, which finds the aAttribute type 
         * attributed fields from the contact.
         *
         * @param aAttributeType Type of the attribute to find for.
         * @param aContact Contact whose attributes are checked.
         * @param aObserver Observer for the asynchronous process.
         * @return Newly created handle to the operation.
         */
        virtual MVPbkContactOperationBase* FindFieldsWithAttributeL(
                TUid aAttributeType,
                MVPbkStoreContact& aContact,
                MVPbkMultiAttributePresenceObserver& aObserver) const = 0;

        /**
         * Initiates an asynchronous operation, which finds the aAttribute type 
         * attributed fields from the contact.
         *
         * @param aAttribute Attribute prototype to match against.
         * @param aContact Contact whose attributes are checked.
         * @param aObserver Observer for the asynchronous process.
         * @return Newly created handle to the operation.
         */
        virtual MVPbkContactOperationBase* FindFieldsWithAttributeL(
                const MVPbkContactAttribute& aAttribute,
                MVPbkStoreContact& aContact,
                MVPbkMultiAttributePresenceObserver& aObserver) const = 0;

        /**
         * Returns an extension point for this interface or NULL.
         * @param aExtensionUid Extension identifier.
         * @return Extension point or NULL
         */
        virtual TAny* ContactAttributeManagerExtension(
                TUid /*aExtensionUid*/) { return NULL; }
    };
    
#endif // MVPBKCONTACTATTRIBUTEMANAGER_H

// End of File
