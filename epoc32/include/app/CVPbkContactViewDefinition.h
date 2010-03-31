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
* Description:  A contact view definition.
*
*/


#ifndef CVPBKCONTACTVIEWDEFINITION_H
#define CVPBKCONTACTVIEWDEFINITION_H

#include <e32base.h>
#include <vpbkcontactview.hrh>

class TResourceReader;
class CVPbkFieldTypeSelector;
class MVPbkContactSelector;

/**
 * A contact view definition.
 * 
 * This class is needed when a client needs to create a contact view.
 * A client can define a structure of VPBK_CONTACT_VIEW from VPbkContactView.rh
 * and use this class to read the definition or construct an empty definition
 * and then set the information to it.
 *
 * A view definition enables complex view structures. A client can e.g.
 * create a composite view that contains subviews from multiple contact
 * stores. However, it's up to client to understand that there are certain
 * limits for the structure. E.g. a contact view is a leaf view and can
 * not have subviews. Another important thing to keep in mind is that complex
 * view structures consumes more RAM that can be a problem if there are
 * thousands of contacts in the view.
 * 
 * @see VPBK_CONTACT_VIEW in VPbkContactView.rh
 * @see CVPbkContactManager::CreateContactViewLC
 * @lib VPbkEng.lib
 */
class CVPbkContactViewDefinition : public CBase
    {
    public: // Construction & destruction
        /**
         * Creates a new contact view definition and initializes
         * it from resource. Takes a VPBK_CONTACT_VIEW resource
         * structure as a parameter.
         *
         * @param aReader A resource reader to a VPBK_CONTACT_VIEW
         *                structure.
         * @return A new instance of this class.
         */
        IMPORT_C static CVPbkContactViewDefinition* NewL(
                TResourceReader& aReader );

        /**
         * Creates a new empty contact view definition.
         * Client must then set the needed information.
         *
         * @return A new instance of this class.
         */
        IMPORT_C static CVPbkContactViewDefinition* NewL();

        /**
         * Constructs a new contact view definition from an existing one
         * by copying the data.
         *
         * @param aViewDef A view definition to copy.
         * @return A new instance of this class.
         */
        IMPORT_C static CVPbkContactViewDefinition* NewL(
                const CVPbkContactViewDefinition& aViewDef );
        
        /**
         * Creates a new contact view definition and initializes
         * it from resource. Takes a VPBK_CONTACT_VIEW resource
         * structure as a parameter.
         *
         * @param aReader A resource reader to a VPBK_CONTACT_VIEW
         *                structure.
         * @return A new instance of this class.
         */
        IMPORT_C static CVPbkContactViewDefinition* NewLC(
                TResourceReader& aReader );

        /**
         * Creates a new empty contact view definition.
         * Client must then set the needed information.
         *
         * @return A new instance of this class.
         */
        IMPORT_C static CVPbkContactViewDefinition* NewLC();

        /**
         * Constructs a new contact view definition from an existing one
         * by copying the data.
         *
         * @param aViewDef A view definition to copy.
         * @return A new instance of this class.
         */
        IMPORT_C static CVPbkContactViewDefinition* NewLC(
                const CVPbkContactViewDefinition& aViewDef );

        /**
         * Destructor.
         */
        ~CVPbkContactViewDefinition();

    public: // Interface
        /**
         * Returns the number of sub views owned by this view.
         *
         * @return The number of sub views.
         */
        IMPORT_C TInt SubViewCount() const;

        /**
         * Returns the sub view definition at aIndex.
         *
         * @param aIndex The index of the sub view definition.
         * @return The sub view definition at aIndex.
         */
        IMPORT_C const CVPbkContactViewDefinition& SubViewAt( 
                TInt aIndex ) const;

        /**
         * Returns the sub view definition at aIndex.
         *
         * @param aIndex    The index to query.
         * @return The sub view definition.
         */
        IMPORT_C CVPbkContactViewDefinition& SubViewAt( TInt aIndex );

        /**
         * Returns the type of this view.
         *
         * @return The type of this view.
         */
        IMPORT_C TVPbkContactViewType Type() const;

        /**
         * Returns ETrue if aFlag is on, otherwise EFalse.
         *
         * @param aFlag The flag to check.
         * @return A flag state.
         */
        IMPORT_C TBool FlagIsOn( TVPbkContactViewFlag aFlag ) const;

        /**
         * Returns the URI of this view. KNullDesC if this is not a leaf node.
         *
         * @return The URI of this view or KNullDesC.
         */
        IMPORT_C const TDesC& Uri() const;

        /**
         * Returns the sorting policy of this view.
         *
         * @return The sorting policy of this view.
         */
        IMPORT_C TVPbkContactViewSortPolicy SortPolicy() const;

        /**
         * Returns the name of the view. Default is KNullDesC.
         *
         * In view types EVPbkContactsView and EVPbkGroupsView
         * the name can be used as a shared view identifier by the
         * store. Shared view creation is indicated by
         * TVPbkContactViewSharing. If the name is empty for shared
         * view then store implementation uses its default name.
         * This is a preferred way to use shared views in the platform.
         * 
         * In view type EVPbkFoldingView the name is the label
         * of the only contact in the view.
         *
         * In view type EVPbkCompositeView the name has no meaning.
         *
         * @return The name of the view.
         */
        IMPORT_C const TDesC& Name() const;

        /**
         * Returns the view sharing type. The store can support
         * a shared view creation for saving RAM. 
         *
         * Default value for types EVPbkContactsView and EVPbkGroupsView
         * is EVPbkSharedView. Store implementation creates
         * then a shared view if it's possible for the store.
         * Prefer using the default values for saving resources.
         * 
         * For view types EVPbkFoldingView and EVPbkCompositeView the
         * sharing has no effect.
         *
         * See also the documentation of Name()
         *
         * @return The view sharing type.
         * 
         */
        IMPORT_C TVPbkContactViewSharing Sharing() const;
        
        /**
         * Returns the field type selector used to filter the view or NULL.
         *
         * The view contains only contacts having the fields defined
         * by the field type filter.
         *
         * @return The field type filter.
         */
        IMPORT_C CVPbkFieldTypeSelector* FieldTypeFilter() const;

        /**
         * Returns the id of this view.
         *
         * @return the id of this view.
         */
        IMPORT_C TInt Id() const;
        /**
         * Adds new view as a subview. This object takes ownership
         * of the subview. If this function leaves ownership is not taken.
         *
         * @param aSubView The new subview to add.
         */
        IMPORT_C void AddSubViewL( CVPbkContactViewDefinition* aSubView );

        /**
         * Sets aType as this views type.
         *
         * @param aType The type to set.
         */
        IMPORT_C void SetType( TVPbkContactViewType aType );

        /**
         * Sets aId as this views id.
         *
         * @param aId the id to set.
         */
        IMPORT_C void SetId( TInt aId );
        /**
         * Sets the saFlag's state as aState.
         *
         * @param aFlag The flag to modify.
         * @param aState The state to set.
         */
        IMPORT_C void SetFlag( TVPbkContactViewFlag aFlag, TBool aState );

        /**
         * Sets aUri as this views URI. This function takes a copy of aUri.
         *
         * @param aUri The URI to set.
         */
        IMPORT_C void SetUriL( const TDesC& aUri );

        /**
         * Sets aSortPolicy as this views sorting policy.
         *
         * @param aSortPolicy The sort policy to set.
         */
        IMPORT_C void SetSortPolicy( TVPbkContactViewSortPolicy aSortPolicy );

        /**
         * Sets aName as this views Name. This function takes a copy of aName.
         *
         * @param aName The name to set.
         */
        IMPORT_C void SetNameL( const TDesC& aName );

        /**
         * Sets the view sharing type.
         *
         * @param aViewSharing One of the values defined in
         *                     VPbkContactView.hrh.
         */
        IMPORT_C void SetSharing( TVPbkContactViewSharing aViewSharing );
        
        /**
         * Sets the field type selector used to filter the view.
         *
         * The view contains only contacts having the fields defined
         * by the field type filter.
         *
         * @param aFilter The field type filter. Use NULL to
         *                filter nothing.
         */
        IMPORT_C void SetFieldTypeFilterL( CVPbkFieldTypeSelector* aFilter );

        /**
         * Sets the contact selector used to filter the view.
         *
         * The view contains only contacts accepted by the selector.
         *
         * @param aContactSelector The contact selector. Use NULL to
         *                filter nothing. Ownership not transferred.
         */
        IMPORT_C void SetContactSelector( MVPbkContactSelector* aContactSelector );

        /**
         * Gives either the contact selector or NULL. Ownership is not transferred.
         */
        IMPORT_C MVPbkContactSelector* ContactSelector() const;

    private: // Implementation
        CVPbkContactViewDefinition();
        void ConstructL();
        void ConstructL(
                const CVPbkContactViewDefinition& aViewDef );
        void ConstructFromResourceL(
                TResourceReader& aReader );
        void InitializeSharing();

    private: // Data
        /// Own: URI of this view, may be NULL if this is inner node
        HBufC* iUri;
        /// Own: Type of this view
        TVPbkContactViewType iType;
        /// Own: Flags for this view
        TUint32 iFlags;
        /// Own: Sorting policy for this view
        TVPbkContactViewSortPolicy iSortPolicy;
        /// Own: Subviews of this view
        RPointerArray<CVPbkContactViewDefinition> iSubViews;
        /// Own: Name of the view, may be NULL if name is not applicable
        HBufC* iName;
        /// Own: Field type filter
        CVPbkFieldTypeSelector* iFilter;
        /// Own: Defines the sharing of the view
        TVPbkContactViewSharing iSharing;
        /// Not owned
        MVPbkContactSelector* iContactSelector;
        /// Own: Id for this view
        TInt iId;
    };

#endif // CVPBKCONTACTVIEWDEFINITION_H

// End of File
