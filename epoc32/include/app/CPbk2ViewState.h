/*
* Copyright (c) 2005-2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Phonebook 2 view state.
*
*/



/**
 *  VIEW STATE BINARY STREAM FORMAT
 *
 *  - View parameter UID is 0x102072a0
 *
 *  - Format of the stream in (slightly freeform) EBNF:
 *
 *  stream  ::= version , { command } ;
 *  version ::= Int8(1) ;
 *  command ::= Int8(EFocusedContact) , contactlink ;
 *  command ::= Int8(ETopContact) , contactlink ;
 *  command ::= Int8(EMarkedContacts) , Uint16(length) , MVPbkContactLinkArray(links) ;
 *  command ::= Int8(EFocusedFieldIndex) , Int32(index) ;
 *  command ::= Int8(ETopFieldIndex) , Int32(index) ;
 *  command ::= Int8(EParentContact) , contactlink ;
 *  command ::= Int8(EFocusedPropertiesIndex) , Int32(index) ;
 *  command ::= Int8(ETopPropertiesIndex) , Int32(index) ;
 *  command ::= Int8(EFlags) , Int32(flags) ;
 *  command ::= EEnd ; // no further commands are read after EEnd,
 *                     // EEnd is not mandatory in a stream
 *  contactlink ::= Uint16(length) , MVPbkContactLink(link) ;
 *
 *  Constants:
 *      EEnd                    = 0,
 *      EFocusedContact         = 1,
 *      ETopContact             = 2,
 *      EMarkedContacts         = 3,
 *      EFocusedFieldIndex      = 4,
 *      ETopFieldIndex          = 5,
 *      EParentContact          = 6
 *      EFlags                  = 7
 *      EFocusedPropertiesIndex = 8,
 *      ETopPropertiesIndex     = 9,
 *
 *  - Example:
 *  Activate Phonebook2's contact info view to show a contact
 *  with field at index 3 focused. This example assumes there
 *  is a contactLink variable of type MVPbkContactLink.
 *
 *  // Write parameters in a buffer
 *  TBuf8<256> param;
 *  RDesWriteStream stream( param );
 *  stream.PushL();
 *  stream.WriteInt8L(1);                   // version number
 *  stream.WriteInt8L( 1 );                 // opcode EFocusedContact
 *  HBufC8* buf = contactLink->PackLC();   // pack the contact link
 *  stream.WriteUint16L( buf->Length() );   // write link length
 *  stream.WriteL( *buf );                  // write the actual link buffer
 *  CleanupStack::PopAndDestroy();         // cleanup buf
 *  stream.WriteInt8L( 4 );                 // opcode EFocusedFieldIndex
 *  stream.WriteInt32L( 3 );                // field index 3
 *  stream.CommitL();
 *  CleanupStack::PopAndDestroy();         // cleanup stream
 *
 *  // Make view id with Phonebook2's app UID3 and Contact Info View's id
 *  // (view ids are defined in Pbk2ViewId.hrh)
 *  const TVwsViewId viewId( TUid::Uid(0x101f4cce), 4 );
 *
 *  // Activate the view
 *  AppUi()->ActivateViewL( viewId, TUid::Uid( 0x102072a0 ), param );
 *
 *
 *  - Same example as above, now using CPbk2ViewState:
 *
 *  #include <Pbk2UID.h>           // Phonebook 2 UIDs
 *  #include <CPbk2ViewState.h>    // need also to add Pbk2CommonUI.lib
 *                                 // into projects .mmp
 *
 *  CPbk2ViewState* pbk2ViewParam = CPbk2ViewState::NewLC();
 *  pbk2ViewParam->SetFocusedContact( contactLink );
 *  pbk2ViewParam->SetFocusedFieldIndex( 3 );
 *  HBufC8* paramBuf = pbk2ViewParam->PackLC();
 *
 *  // Make view id with Phonebook2's app UID3 and Contact Info View's id
 *  const TVwsViewId viewId( TUid::Uid(0x101f4cce), EPbk2ContactInfoViewId );
 *
 *  // Activate the view
 *  AppUi()->ActivateViewL( viewId, CPbk2ViewState::Uid(), *paramBuf );
 *
 *  // Cleanup
 *  CleanupStack::PopAndDestroy( 2 ); // paramBuf, pbk2ViewParam
 *
 *  - The latter example is cleaner, but using CPbk2ViewState from your
 *  application means that your application will have a dependency to
 *  CPbk2ViewState.h and Pbk2CommonUI.lib at compile time and to
 *  Pbk2CommonUI.dll at run time.
 */

#ifndef CPBK2VIEWSTATE_H
#define CPBK2VIEWSTATE_H

//  INCLUDES
#include <e32base.h>

// FORWARD DECLARATIONS
class RReadStream;
class RWriteStream;
class MVPbkContactLink;
class MVPbkContactLinkArray;

// CLASS DECLARATION

/**
 * Phonebook 2 view state.
 *
 * Responsible for storing the state of a Phonebook 2 view.
 * The state includes, for example, focused contact, focused
 * contact field and other information for restoring the state later.
 * This state object can be externalized to a buffer and
 * initialized from a buffer.
 */
class CPbk2ViewState : public CBase
    {
    public: // Types

        /// View state data types
        enum TDataType
            {
            EEnd = 0,
            /// Focused contact
            EFocusedContact,
            // Top most contact of the view
            ETopContact,
            /// Array of marked contacts
            EMarkedContacts,
            /// Index of the focused field
            EFocusedFieldIndex,
            /// Index of the topmost field of the view
            ETopFieldIndex,
            /// Parent contact
            EParentContact,
            /// View state flags
            EFlags,
            /// Index of the focused properties item
            EFocusedPropertiesIndex,
            /// Index of the topmost properties item of the view
            ETopPropertiesIndex
            };

        /// View state flags
        enum TFlags
            {
            /// Reset flags
            ENullFlags = 0,
            /// Focus the first item in list views
            EFocusFirst  = 0x0001,
            /// Focus the last item in list views
            EFocusLast   = 0x0002,
            /// Reset state to the view's initial state
            EInitialized = 0x0004,
            /// Send application to background
            ESendToBackground = 0x0008
            };

    public: // Constructors and destructor

        /**
         * Creates a new instace of this class.
         *
         * @return  A new instance of this class.
         */
        IMPORT_C static CPbk2ViewState* NewL();

        /**
         * Creates a new instace of this class.
         *
         * @return  A new instance of this class.
         */
        IMPORT_C static CPbk2ViewState* NewLC();

        /**
         * Creates a new instace of this class initialized from a buffer.
         * @see CPbk2ViewState::PackL and CPbk2ViewState::PackLC for
         * constructing the buffer.
         *
         * @param aBuf  Buffer to initialize this instance from.
         * @return  A new instance of this class.
         */
        IMPORT_C static CPbk2ViewState* NewL(
                const TDesC8& aBuf );

        /**
         * Creates a new instace of this class initialized from a buffer.
         * @see CPbk2ViewState::PackL and CPbk2ViewState::PackLC for
         * constructing the buffer.
         *
         * @param aBuf  Buffer to initialize this instance from.
         * @return  A new instance of this class.
         */
        IMPORT_C static CPbk2ViewState* NewLC(
                const TDesC8& aBuf );

        /**
         * Destructor.
         */
        ~CPbk2ViewState();

    public: // Getters

        /**
         * Returns the message uid for use with view server messages.
         *
         * @return  Message uid.
         */
        IMPORT_C static TUid Uid();

        /**
         * Returns a link to the focused contact.
         * Null if not set.
         *
         * @return  Link to the focused contact.
         */
        IMPORT_C const MVPbkContactLink* FocusedContact() const;

        /**
         * Returns a link to the focused contact.
         * Null if not set. Ownership is transferred to the caller.
         *
         * @return  Link to the focused contact.
         */
        IMPORT_C MVPbkContactLink* TakeFocusedContact();

        /**
         * Returns a link to the the topmost contact.
         * Null if not set.
         *
         * @return  Link to the topmost contact.
         */
        IMPORT_C const MVPbkContactLink* TopContact() const;

        /**
         * Returns a link to the topmost contact.
         * Null if not set. Ownership is transferred to caller.
         *
         * @return  Link to the topmost contact.
         */
        IMPORT_C MVPbkContactLink* TakeTopContact();

        /**
         * Returns a link to the parent contact.
         *
         * @return  Link to the parent contact.
         */
        IMPORT_C const MVPbkContactLink* ParentContact() const;

        /**
         * Returns a link to the parent contact.
         * Null if not set. Ownership is transferred to caller.
         *
         * @return  Link to the parent contact.
         */
        IMPORT_C MVPbkContactLink* TakeParentContact();

        /**
         * Returns const array of marked contacts.
         * NULL if not set.
         *
         * @return  Marked contacts in a link array.
         */
        IMPORT_C const MVPbkContactLinkArray* MarkedContacts() const;

        /**
         * Returns const array of marked contacts.
         * NULL if not set. Ownership is transferred to caller.
         *
         * @return  Marked contacts in a link array.
         */
        IMPORT_C MVPbkContactLinkArray* TakeMarkedContacts();

        /**
         * Returns the index of the focused field.
         * KErrNotFound indicates there is no
         * focused field information available.
         *
         * @return  Field index.
         */
        IMPORT_C TInt FocusedFieldIndex() const;

        /**
         * Returns the index of the top field.
         * KErrNotFound indicates there is no
         * focused field information available.
         *
         * @return  Field index.
         */
        IMPORT_C TInt TopFieldIndex() const;
        
        /**
         * Returns the index of the focused properties item.
         * KErrNotFound indicates there is no
         * focused properties item information available.
         *
         * @return  Properties item index.
         */
        IMPORT_C TInt FocusedPropertiesIndex() const;

        /**
         * Returns the index of the top properties item.
         * KErrNotFound indicates there is no
         * focused properties item information available.
         *
         * @return  Properties item index.
         */
        IMPORT_C TInt TopPropertiesIndex() const;

        /**
         * Returns the view state flags.
         *
         * @return  View state flags.
         */
        IMPORT_C TUint Flags() const;

    public: // Setters

        /**
         * Sets focused contact to given contact.
         *
         * @param aContact  The contact to set.
         */
        IMPORT_C void SetFocusedContact(
                MVPbkContactLink* aContact );

        /**
         * Sets top contact to given contact.
         *
         * @param aTopContact  The contact to set.
         */
        IMPORT_C void SetTopContact(
                MVPbkContactLink* aTopContact );

        /**
         * Sets parent contact to given contact.
         *
         * @param aParentContact  The contact to set.
         */
        IMPORT_C void SetParentContact(
                MVPbkContactLink* aParentContact );

        /**
         * Sets marked contacts according to given array of contact links.
         *
         * @param aArray  The contacts to set marked.
         */
        IMPORT_C void SetMarkedContacts(
                MVPbkContactLinkArray* aArray );

        /**
         * Sets the index of the focused field to the given index.
         * KErrNotFound indicates there is no focused field
         * information available.
         *
         * @param aIndex    The index to set.
         */
        IMPORT_C void SetFocusedFieldIndex(
                TInt aIndex );

        /**
         * Sets the index of the topmost field to the given index.
         * KErrNotFound indicates there is no topmost field
         * information available.
         *
         * @param aIndex    The index to set.
         */
        IMPORT_C void SetTopFieldIndex(
                TInt aIndex );
        
        /**
         * Sets the index of the focused properties item to the given index.
         * KErrNotFound indicates there is no focused properties item
         * information available.
         *
         * @param aIndex    The index to set.
         */
        IMPORT_C void SetFocusedPropertiesIndex(
                TInt aIndex );

        /**
         * Sets the index of the topmost properties item to the given index.
         * KErrNotFound indicates there is no topmost properties item
         * information available.
         *
         * @param aIndex    The index to set.
         */
        IMPORT_C void SetTopPropertiesIndex(
                TInt aIndex );

        /**
         * Reset this view state to an empty state.
         */
        IMPORT_C void Reset();

        /**
         * Sets the view state flags.
         *
         * @param aFlags    The flags to set.
         */
        IMPORT_C void SetFlags(
                TUint aFlags );

    public: // Client-server support

        /**
         * Packages and returns this object in a buffer.
         * Caller is responsible for deleting the buffer.
         *
         * @return  This view state instance packaged into a buffer.
         */
        IMPORT_C HBufC8* PackL() const;

        /**
         * Packages and returns this object in a buffer.
         * Caller is responsible for deleting the buffer.
         *
         * @return  This view state instance packaged into a buffer.
         */
        IMPORT_C HBufC8* PackLC() const;

        /**
         * Sets this view state from given packaged buffer.
         *
         * @param aPack     Packaged view state buffer.
         */
        IMPORT_C void UnpackL(
                const TDesC8& aPack );


    public: // Support functions

        /**
         * Comparison operator.
         *
         * @param aRhs  View state instance to compare to this instance.
         * @return  ETrue if view states are equal, EFalse otherwise.
         */
        IMPORT_C TBool operator==(
                const CPbk2ViewState& aRhs ) const;

    private: // Implementation
        CPbk2ViewState();
        void ConstructL(
                const TDesC8& aBuf );
        void ExternalizeL(
                RWriteStream& aStream ) const;
        void InternalizeL(
                RReadStream& aStream );

    private: // Data
        /// Own: Link to the focused contact.
        MVPbkContactLink* iFocusedContact;
        /// Own: Link to the topmost contact.
        MVPbkContactLink* iTopContact;
        /// Own: Link to the parent contact.
        MVPbkContactLink* iParentContact;
        /// Own: Array of marked contacts.
        MVPbkContactLinkArray* iArray;
        /// Own: Index of the focused field
        TInt iFocusedFieldIndex;
        /// Own: Index of the top field
        TInt iTopFieldIndex;
        /// Own: Index of the properties item
        TInt iFocusedPropertiesIndex;
        /// Own: Index of the top properties item
        TInt iTopPropertiesIndex;
        /// Own: Flags
        TUint iFlags;

    private: // Const static data
        static const TUid KUid;
    };

#endif // CPBK2VIEWSTATE_H

// End of File
