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
* Description:  Virtual Phonebook Filtered contact view.
*
*/


#ifndef CVPBKFILTEREDCONTACTVIEW_H
#define CVPBKFILTEREDCONTACTVIEW_H

// INCLUDES
#include <e32base.h>
#include <mvpbkcontactviewbase.h>
#include <mvpbkcontactviewobserver.h>
#include <mvpbkcontactviewfiltering.h>

// FORWARD DECLARATIONS
namespace VPbkEngUtils { class CVPbkAsyncOperation; }
class MVPbkContactSelector;

/**
 * Virtual Phonebook filtered contact view.
 * This class can be used for filtering an existing view. A client
 * gives the view for filtering and also a contact selector that
 * is used to select contacts from the given view.
 */
class CVPbkFilteredContactView : 
        public CBase,
        public MVPbkContactViewBase,
        public MVPbkContactViewObserver,
        public MVPbkContactViewFiltering
	{
    public:
        /**
         * Two-phase constructor. 
         * NOTE: Does not support find functionality.
         *
         * @param aBaseView The view to filter.
         * @param aObserver an observer that is notified when this
         *                  view is ready for use.
         * @param aContactSelector  A contact selector for selecting
         *                          contacts to the view.
         * @return A new instance of this class 
         */
        IMPORT_C static CVPbkFilteredContactView* NewL(
                MVPbkContactViewBase& aBaseView,
                MVPbkContactViewObserver& aObserver,
                MVPbkContactSelector& aContactSelector);
        
        /**
         * Two-phase constructor. 
         * Note: Supports find functionality.
         *
         * @param aBaseView The view to filter.
         * @param aObserver an observer that is notified when this
         *                  view is ready for use.
         * @param aContactSelector  A contact selector for selecting
         *                          contacts to the view.
         * @param aMasterFieldTypeList  Field type list
         * @return A new instance of this class 
         */        
        IMPORT_C static CVPbkFilteredContactView* NewL(
                MVPbkContactViewBase& aBaseView,
                MVPbkContactViewObserver& aObserver,
                MVPbkContactSelector& aContactSelector,
                const MVPbkFieldTypeList& aMasterFieldTypeList );
                
        /**
         * Destructor.
         */
        ~CVPbkFilteredContactView();

    protected: // From MVPbkContactViewBase
        TVPbkContactViewType Type() const;
        void ChangeSortOrderL(const MVPbkFieldTypeList& aSortOrder);
        const MVPbkFieldTypeList& SortOrder() const;
        void RefreshL();
        TInt ContactCountL() const;
        const MVPbkViewContact& ContactAtL(TInt aIndex) const;
        MVPbkContactLink* CreateLinkLC(TInt aIndex) const;
        TInt IndexOfLinkL(const MVPbkContactLink& aContactLink) const;
        void AddObserverL(MVPbkContactViewObserver& aObserver);
        void RemoveObserver(MVPbkContactViewObserver& aObserver);
        TBool MatchContactStore(const TDesC& aContactStoreUri) const;
        TBool MatchContactStoreDomain(const TDesC& aContactStoreDomain) const;
        MVPbkContactBookmark* CreateBookmarkLC(TInt aIndex) const;
        TInt IndexOfBookmarkL(
            const MVPbkContactBookmark& aContactBookmark) const;
        MVPbkContactViewFiltering* ViewFiltering();
    
    private: // From MVPbkContactViewFiltering    
        MVPbkContactViewBase* CreateFilteredViewLC( 
                MVPbkContactViewObserver& aObserver,
                const MDesCArray& aFindWords,
                const MVPbkContactBookmarkCollection* aAlwaysIncludedContacts );
            
        void UpdateFilterL( 
                const MDesCArray& aFindWords,
                const MVPbkContactBookmarkCollection* aAlwaysIncludedContacts );
        
    private: // From MVPbkContactViewObserver
        void ContactViewReady(MVPbkContactViewBase& aView);
        void ContactViewUnavailable(MVPbkContactViewBase& aView);
        void ContactAddedToView(
                MVPbkContactViewBase& aView, 
                TInt aIndex, const 
                MVPbkContactLink& aContactLink );
        void ContactRemovedFromView(
                MVPbkContactViewBase& aView, 
                TInt aIndex, 
                const MVPbkContactLink& aContactLink );
        void ContactViewError(
                MVPbkContactViewBase& aView, 
                TInt aError, 
                TBool aErrorNotified );

    private: // Implementation
        CVPbkFilteredContactView(
                MVPbkContactViewBase& aBaseView,
                MVPbkContactSelector& aContactSelector,
                const MVPbkFieldTypeList* aMasterFieldTypeList );
        void ConstructL( MVPbkContactViewObserver& aObserver );
        void BuildViewMappingL();
        void HandleBuildViewMapping();
        void DoAddObserverL(MVPbkContactViewObserver& aObserver);
        void AddObserverError(MVPbkContactViewObserver& aObserver, TInt aError);
        
        TInt UpdateViewMappingAfterAddingL( TInt aBaseIndex );
        TInt UpdateViewMappingAfterDeleting( TInt aBaseIndex );

    private: // Data
        ///Own: Indicated whether view is ready
        TBool iIsReady;
        ///Ref: Contact base view
        MVPbkContactViewBase& iBaseView;
        ///Ref: Contact view selection criteria
        MVPbkContactSelector& iContactSelector;
        ///Ref: Master field type list
        const MVPbkFieldTypeList* iMasterFieldTypeList;
        ///Own: Asynchronous operation
        VPbkEngUtils::CVPbkAsyncOperation* iAsyncOperation;
        ///Own: Mapping between base view and filtered view
        RArray<TInt> iContactMapping;
        ///Ref: Array to view observers
        RPointerArray<MVPbkContactViewObserver> iObservers;
    };

#endif // CVPBKFILTEREDCONTACTVIEW_H

//End of file


