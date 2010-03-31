/*
* Copyright (c) 2002 Nokia Corporation and/or its subsidiary(-ies).
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
* Description: 
*     Represents a connection to the Phonebook contact database
*
*/


#ifndef __CPBKCONTACTENGINE_H__
#define __CPBKCONTACTENGINE_H__

//  INCLUDES
#include <e32base.h>        // CBase
#include <cntdef.h>         // TContactItemId
#include <cntdbobs.h>       // MContactDbObserver
#include <f32file.h>        // RFs
#include "PbkFields.hrh"    // TPbkFieldId


// FORWARD DECLARATIONS
class CContactDatabase;
class MIdleFindObserver;
class MPbkContactDbObserver;
class CContactGroup;
class CPbkFieldsInfo;
class CPbkContactItem;
class CPbkContactIter;
class CPbkContactChangeNotifier;
class CPbkIdleFinder;
class MPbkCompressUi;
class CPbkConstants;
class MPbkContactNameFormat;
class MPbkFieldDataArray;
class CContactViewBase;
class CContactItem;
class RSharedDataClient;
class TResourceReader;
class CPbkEngineExtension;
class CPbkSortOrderManager;
class CPbkSINDHandlerInterface;


// CLASS DECLARATION

/**
 * The main entrypoint to the Phonebook contact engine. The Phonebook
 * contact engine builds on top of the Symbian Contacts model and
 * implements platform specific functionality and policies that can be 
 * reused and followed by clients to implement functionality that is
 * better integrated to the platform functionality. Functionality like
 * contact field typing is implemented by this engine. 
 */
class   CPbkContactEngine :
        public CBase,
        private MContactDbObserver
    {
    public: // Constructors and destructor
        /**
         * Creates a new Phonebook engine object and connects to the default
         * contact database. If the default database does not exist it is
         * created.
         *
         * @param aFs   An open file server connection. If !=NULL aFs is used
         *              instead of a locally created RFs connection. aFs must
         *              remain connected for the lifetime of the returned
         *              object.
         * @return A new instance of this class.
         * @exception KErrCorrupt if the database is corrupted.
         */
		IMPORT_C static CPbkContactEngine* NewL(RFs* aFs=NULL);

        /**
         * @internal
         * TESTING ONLY
         * Creates a new engine object and connects it to a specified
         * database file. If the database file does not exist it is created.
         *
         * @param aFileName The database filename.
         * @param aReplace  If ETrue replaces exisiting file with an empty one.
         *                  PLEASE NOTE: all data in the existing file
         *                  will be lost!
         * @param aFs   An open file server connection. If !=NULL aFs is used
         *              instead of a locally created RFs connection. aFs must
         *              remain connected for the lifetime of the returned
         *              object.
         * @return A new instance of this class.
         * @exception KErrCorrupt if the database is corrupted.
         * @deprecated
         */
		IMPORT_C static CPbkContactEngine* NewL
            (const TDesC& aFileName, TBool aReplace=EFalse, RFs* aFs=NULL);

        /**
         * Replaces the default contact database and connects to it. See
         * Symbian Contacs model documentation for CContactDatabase::ReplaceL
         * for possible leave codes.
         * PLEASE NOTE: all data in the existing database will be lost!
         *
         * @param aFs   An open file server connection. If !=NULL aFs is used
         *              instead of a locally created RFs connection. aFs must
         *              remain connected for the lifetime of the returned
         *              object.
         * @return A new instance of this class.
         * @see CContactDatabase::ReplaceL
         */
        IMPORT_C static CPbkContactEngine* ReplaceL(RFs* aFs=NULL);

        /**
		* Destructor. Destroys this object and closes the contact database
		* connection. REComSession::FinalClose() is called. Notice that
		* FinalClose -call releases resource handles of already destroyed ECom
		* plugins also outside CPbkContactEngine. See REComSession
		* documentation.
		*/
		~CPbkContactEngine();

    public: // Accessors
        /**
         * Returns the global Phonebook engine instance, NULL if no instance
         * created yet.
         * Note1: Uses thread local storage (TLS), which is slow. Cache the
         * returned pointer if it is used more than one time!
         * Note2: Only the first engine instance created in calling thread can
         * be accessed with this function.
         * @return  Global Phonebook engine instance.
         */
        IMPORT_C static CPbkContactEngine* Static();

        /**
         * Returns the underlying CContactDatabase object. Use only if this class's API
         * is not enough for your purposes.
         *
         * @return The underlying Symbian Contacts model CContactDatabase instance.
         * @see CContactDatabase
         */
        IMPORT_C CContactDatabase& Database();

        /**
         * Returns the field type info array.
         * @return  All the Phonebook field types.
         * @see CPbkFieldsInfo
         */
        IMPORT_C const CPbkFieldsInfo& FieldsInfo();

        /**
         * Returns an open file server session.
         * @return  A handle to a file server session.
         */
        IMPORT_C RFs& FsSession() const;

    public:  // Creating contacts
        /**
         * Returns a new contact card with default fields.
         * @return  A new empty contact item object.
         */
        IMPORT_C CPbkContactItem* CreateEmptyContactL();

         /**
          * Adds a new contact to the contact database.
          *
          * @param aContact         The new contact item to add.
          * @param aImmediateNotify Send notification to observers immediately.
          *                         NOTE: send immediately will result in
          *                         observers (MPbkContactDbObserver) receiving
          *                         the event twice!
          * @return The id of the new contact item.
          * @see CContactDatabase::AddNewContactL
          */
        IMPORT_C TContactItemId AddNewContactL
            (CPbkContactItem& aContact, TBool aImmediateNotify=EFalse);

        /**
         * Duplicates a contact in the database.
         *
         * @param aId               Id of the contact to duplicate.
         * @param aImmediateNotify  Send notification to observers immediately.
         *                          NOTE: send immediately will result in
         *                          observers (MPbkContactDbObserver) receiving
         *                          the event twice!
         * @return  Contact id of the new duplicate.
         */
        IMPORT_C TContactItemId DuplicateContactL
            (TContactItemId aId, TBool aImmediateNotify=EFalse);

    public:  // Reading contacts
        /**
         * Reads a contact and returns a phonebook contact item.
         *
         * @param aContactId Contact item id to be read.
         * @param aFieldTypes   Array of types of fields to read in, all
         *                      fields are read if NULL (which is default).
         *                      NOTE: when using this parameter ReadContactL
         *                      may return more fields than expected; for example
         *                      if aFieldTypes contains any phonenumber the
         *                      method may return all phone number fields
         *                      of the contact.
         * @return A new Phonebook contact item.
         * @see CContactDatabase::ReadContactL
         */
        IMPORT_C CPbkContactItem* ReadContactL
            (TContactItemId aContactId, const CPbkFieldIdArray* aFieldTypes=NULL);

        /**
         * Same as ReadContactL, but leaves the returned contact item
         * on the cleanup stack.
         *
         * @param aContactId Contact item id to be read.
         * @param aFieldTypes   Array of types of fields to read in, all
         *                      fields are read if NULL (which is default).
         *                      NOTE: when using this parameter ReadContactL
         *                      may return more fields than expected; for example
         *                      if aFieldTypes contains any phonenumber the
         *                      method may return all phone number fields
         *                      of the contact.
         * @return A new Phonebook contact item.
         */
        IMPORT_C CPbkContactItem* ReadContactLC
            (TContactItemId aContactId, const CPbkFieldIdArray* aFieldTypes=NULL);

        /**
         * Same as ReadContactLC but reads only minimal information. See
         * Symbian Contacts Model documentation for definition of "minimal" in this
         * case.
         *
         * @param aContactId Contact item id to be read.
         * @return A new phonebook contact item. Leaves the item on the cleanup stack.
         * @see CContactDatabase::ReadMinimalContactL
         */
        IMPORT_C CPbkContactItem* ReadMinimalContactLC(TContactItemId aContactId);

        /**
         * Returns a Phonebook contact iterator.
         * @param aUseMinimalRead   If ETrue the iterator will use the Symbian
         * Contacts model CContactDatabase::ReadMinimalContactL, EFalse will read 
         * all the contact fields. Default behaviour is to read all fields.
         * @see CPbkContactIter::NewL.
         * @see CContactDatabase::ReadMinimalContactL
         */
        IMPORT_C CPbkContactIter* CreateContactIteratorLC
            (TBool aUseMinimalRead=EFalse);

    public:  // Modifying contacts
        /**
         * Opens a contact and returns a phonebook contact item.
         * @param aContactId Contact item id to be opened.
         * @return A Phonebook contact item that is marked as open in the database.
         * @see CContactDatabase::OpenContactL
         */
        IMPORT_C CPbkContactItem* OpenContactL(TContactItemId aContactId);

        /**
         * Same as OpenContactL, but leaves a lock record AND the opened
         * contact object on the cleanup stack.
         * Use CleanupStack::PopAndDestroy(2) to close the contact and destroy
         * the returned object. First pop pops the contact object and second
         * the lock object.
         * @param aContactId    Contact item id to open.
         * @return A Phonebook contact item that is marked as open in the database.
         * @see CContactDatabase::OpenContactLX
         */
        IMPORT_C CPbkContactItem* OpenContactLCX(TContactItemId aContactId);

        /**
         * Commit changes to a previously opened contact item into the contact
         * database.
         *
         * @param aContact          Contact item to be updated in the database.
         * @param aImmediateNotify  Send notification to observers immediately.
         *                          NOTE: send immediately will result in
         *                          observers (MPbkContactDbObserver) receiving
         *                          the event twice!
         * @see CContactDatabase::CommitContactL
         */
        IMPORT_C void CommitContactL
            (CPbkContactItem& aContact, TBool aImmediateNotify=EFalse);

        /**
         * Closes a previously opened contact item without saving changes.
         * @param aContactId Contact item to be closed.
         * @see CContactDatabase::CloseContactL
         */
    	IMPORT_C void CloseContactL(TContactItemId aContactId);

    public:  // Deleting contacts
        /**
         * Deletes a contact item from the database.
         * @param aContactId    Contact item to be deleted.
         * @param aImmediateNotify  Send notification to observers immediately.
         *                          NOTE: send immediately will result in
         *                          observers (MPbkContactDbObserver) receiving
         *                          the event twice!
         * @see CContactDatabase::DeleteContactL
         */
    	IMPORT_C void DeleteContactL
            (TContactItemId aContactId, TBool aImmediateNotify=EFalse);

        /**
         * Deletes multiple contact items from the database.
         * @param aContactIds    Contact items to be deleted.
         * @param aImmediateNotify  Send notification to observers immediately.
         *                          NOTE: send immediately will result in
         *                          observers (MPbkContactDbObserver) receiving
         *                          the event twice!
         * @see CContactDatabase::DeleteContactsL
         */
    	IMPORT_C void DeleteContactsL
            (const CContactIdArray& aContactIds, TBool aImmediateNotify=EFalse);

        /**
         * Deletes multiple contacts from the database in an active object
         * -driven asynchronous background process.
         *
         * @param aContactIds   Contacts to delete.
         */
        IMPORT_C void DeleteContactsOnBackgroundL
            (const CContactIdArray& aContactIds);

    public:  // Contact groups
        /**
         * Creates a new contact group.
         *
         * @param aGroupLabel   Group name.
         * @param aInTransaction    See Symbian Contacts Model documentation
         * for CContactDatabase::CreateContactGroupL documentation.
         * @see CContactDatabase::CreateContactGroupL
         */
        IMPORT_C CContactGroup* CreateContactGroupL
            (const TDesC& aGroupLabel,TBool aInTransaction=EFalse);

        /**
         * Adds a Contact to a group.
         *
         * @param aItemId   Contact to be added to group.
         * @param aGroupId  Group where the contact will be added to.
         * @see CContactDatabase::AddContactToGroupL
         */
    	IMPORT_C void AddContactToGroupL
            (TContactItemId aItemId, TContactItemId aGroupId);

        /**
         * Removes a contact from a group
         *
         * @param aItemId   Contact to be removed from group.
         * @param aGroupId  Group where the contact will be removed from.
         * @see CContactDatabase::RemoveContactFromGroupL
         */
    	IMPORT_C void RemoveContactFromGroupL
            (TContactItemId aItemId, TContactItemId aGroupId);

        /**
         * Reads a Contact group.
         *
         * @param aId Group id.
         * @return Contact group object.
         * @see CContactDatabase::ReadContactL
         */
        IMPORT_C CContactGroup* ReadContactGroupL(TContactItemId aId);

        /**
         * Opens a Contact group for modification.
         *
         * @param aId Groups id
         * @return Contact group object.
         * @see CContactDatabase::OpenContactL
         */
        IMPORT_C CContactGroup* OpenContactGroupL(TContactItemId aId);

        /**
         * Opens a Contact group for modification. Pushes the returned
         * contact group object and a lock item on the cleanup stack.
         *
         * @param aId Groups id
         * @return Contact group object.
         * @see CContactDatabase::OpenContactLX
         */
        IMPORT_C CContactGroup* OpenContactGroupLCX(TContactItemId aId);

        /**
         * Commits changes to a contact group to the database.
         *
         * @param aId Groups id
         * @param aImmediateNotify  Send notification to observers immediately.
         *                          NOTE: send immediately will result in
         *                          observers (MPbkContactDbObserver) receiving
         *                          the event twice!
         * @see CContactDatabase::CommitContactL
         */
        IMPORT_C void CommitContactGroupL(CContactGroup& aGroup, TBool aImmediateNotify=EFalse);

        /**
         * Deletes a contact group from the database.
         * @param aContactId    Contact group to be deleted.
         * @param aImmediateNotify  Send notification to observers immediately.
         *                          NOTE: send immediately will result in
         *                          observers (MPbkContactDbObserver) receiving
         *                          the event twice!
         * @see CContactDatabase::DeleteContactL
         */
        IMPORT_C void DeleteContactGroupL
            (TContactItemId aContactId, TBool aImmediateNotify=EFalse);

    public:  // Speed dials
        /**
         * Sets a speed dial to a contact field.
         *
         * @param aItem         Contact item to add speed dial to.
         * @param aFieldIndex   Field index to add Speed dial to.
         * @param aSpeedDialPosition    Speed dial position number to set to
         *                              the field.
         * @see CContactDatabase::SetFieldAsSpeedDialL
         */
        IMPORT_C void SetFieldAsSpeedDialL
            (CPbkContactItem& aItem, TInt aFieldIndex, TInt aSpeedDialPosition);

        /**
         * Returns a speed dial contact.
         *
         * @param   aSpeedDialPosition  Speed dial position number.
         * @param   aPhoneNumber        Phone number
         * @see CContactDatabase::GetSpeedDialFieldL.
         */
      	IMPORT_C TContactItemId GetSpeedDialFieldL
            (TInt aSpeedDialPosition, TDes& aPhoneNumber) const;

        /**
         * Removes a speed dial from a contact.
         *
         * @param   aContactId  Contact item to remove the speed dial from.
         * @param   aSpeedDialPosition  Speed dial position number to remove.
         * @see CContactDatabase::RemoveSpeedDialFieldL.
         */
    	IMPORT_C void RemoveSpeedDialFieldL
            (TContactItemId aContactId, TInt aSpeedDialPosition);

        /**
         * Returns ETrue if this field has been assigned a speed dial position.
         *
         * @param aItem contact Item to check for speed dial.
         * @param aFieldIndex   Index of the field to check. This is an index
         *                      into aItem.CardFields().
         * @return  ETrue if Speed dial exitst, EFalse if not.
         */
        IMPORT_C TBool IsSpeedDialAssigned
            (const CPbkContactItem& aItem, TInt aFieldIndex) const;

    public:  // Contact views
        /**
         * Returns a contact view object containing all the contacts in the
         * database.
         *
         * @return  Contact view containing all the contacts in the database.
         * @see CContactViewBase
         */
        IMPORT_C CContactViewBase& AllContactsView();

        /**
         * Returns a contact view object containing all the groups in the
         * database.
         *
         * @return  Contact view containing all the groups in the database.
         * @see CContactViewBase
         */
        IMPORT_C CContactViewBase& AllGroupsViewL();

        /**
         * Returns a contact view object containing all the contacts in the
         * database that match a filter.
         *
         * @param aFilter   Use CContactDatabase::TContactViewFilter.
         * @see CContactViewBase
         */
        IMPORT_C CContactViewBase& FilteredContactsViewL(TInt aFilter);

    public:  // Events
        /**
         * Creates and returns a new CPbkContactChangeNotifier for the
         * default contact database. The returned object attaches aObserver
         * to this engine instance as long as the object exists.
         *
         * @param aObserver Observer to attach to this object.
         * @return  New CPbkContactChangeNotifier object. Caller is responsible
         *          of the object.
         * @see CPbkContactChangeNotifier
         * @see MPbkContactDbObserver
         */
        IMPORT_C CPbkContactChangeNotifier* CreateContactChangeNotifierL
            (MPbkContactDbObserver* aObserver);

    public:  // Contact name formatting
        /**
         * Gets a title text for a contact or localised text for unnamed
         * contact if contact contains no title.
         *
         * @param   aItem   Contact item for which to make the title.
         * @return  A buffer containing the title or unnamed text if no title
         *          can be generated. Caller is responsible of deleting the
         *          returned buffer.
         */
        IMPORT_C HBufC* GetContactTitleL(const CPbkContactItem& aItem) const;

        /**
         * Similar to GetContactTitleL but returns NULL if contact contains no
         * title. Uses the MPbkFieldDataArray interface to access the field 
         * content.
         * @param aContactData  The contact field data array.
         * @return  Contact title, NULL if field array did not contain any fields
         * used to for constructing contact titles.
         * @see CPbkContactEngine::GetContactTitleL
         */
        IMPORT_C HBufC* GetContactTitleOrNullL
            (const MPbkFieldDataArray& aContactData);

        /**
         * Returns ETrue if field is one of the fields used in building the
         * contact title.
         *
         * @param aFieldId  The id of the field.
         * @return  ETrue if aFieldId is type of a field used to build contact
         *          titles.
         * @see GetContactTitleL
         * @see GetContactTitleOrNullL
         */
        IMPORT_C TBool IsTitleField(TPbkFieldId aFieldId) const;

        /**
         * @internal
         * Returns the contact name formatter.
         *
         * @see MPbkContactNameFormat
         * @deprecated
         */
        IMPORT_C MPbkContactNameFormat& ContactNameFormat() const;

        /**
         * Returns the localised title text to use for unnamed contacts.
         * @return  Localised title text to use for unnamed contacts.
         */
        IMPORT_C const TDesC& UnnamedTitle() const;

    public: // Searching
        /**
         * Call-through for new Phone number matching function in 6.2 version
         * of class CContactDatabase. If you don't need any other functionality
         * from CPbkContactEngine than this consider using the CContactDatabase
         * API directly. See Symbian Contacts Model documentation for 
         * CContactDatabase::MatchPhoneNumberL use.
         *
         * @see CContactDatabase::MatchPhoneNumberL(const TDesC&,const TInt)
         */
        IMPORT_C CContactIdArray* MatchPhoneNumberL
            (const TDesC& aNumber, const TInt aMatchLengthFromRight);

        /**
         * Searches all contacts in the database for aText.
         *
         * @param aText         Text to search.
         * @param aFieldTypes   Phonebook fields types to <i>at least</i>
         *                      include in the search. If NULL searches all
         *                      fields.<br>
         *                      <b>PLEASE NOTE:</b> The find matches in most
         *                      cases also other fields than those specified
         *                      in aFieldTypes. Always loop through the
         *                      returned contacts to check match in the
         *                      required fields.
         * @return Array of matching contact IDs.
         * @see CContactDatabase::FindLC.
         */
        IMPORT_C CContactIdArray* FindLC
            (const TDesC& aText, const CPbkFieldIdArray* aFieldTypes=NULL);

        /**
         * Searches all contacts in the database for aText asynchronously.
         *
         * @param aText         Text to search.
         * @param aFieldTypes   Phonebook fields types to <i>at least</i>
         *                      include in the search. If NULL searches all
         *                      fields.<br>
         *                      <b>PLEASE NOTE:</b> The find matches in most
         *                      cases also other fields than those specified
         *                      in aFieldTypes. Always loop through the
         *                      returned contacts to check match in the
         *                      required fields.
         * @param  aObserver    Observer for this operation.
         * @return  CPbkIdleFinder object which is used to access the find
         *          results when complete. Deleting this object will cancel
         *          this asyncronous find operation.
         * @see CContactDatabase::FindAsyncL.
         * @see CPbkIdleFinder
         */
	    IMPORT_C CPbkIdleFinder* FindAsyncL(
            const TDesC& aText,
            const CPbkFieldIdArray* aFieldTypes=NULL,
            MIdleFindObserver *aObserver=NULL);

    public:  // Phonebook internal API
        /**
         * @internal
         * Sets the compression UI for this engine.
         * To be called by Phonebook only!
         *
         * @see MPbkCompressUi
         * @see CheckCompress
         * @see CancelCompress
         * @deprecated
         */
        IMPORT_C void SetCompressUi(MPbkCompressUi* aCompressiUi);

        /**
         * @internal
         * Checks if the contact database needs a compression.
         * To be called by Phonebook only!
         *
         * @see SetCompressUi
         * @see CompressL
         * @see CancelCompress
         * @deprecated
         */
        IMPORT_C TBool CheckCompress();

        /**
         * @internal
         * Compresses the database if necessary. To be called by Phonebook only.
         *
         * @see SetCompressUi
         * @see CancelCompress
         * @deprecated
         */
        IMPORT_C void CompressL();

        /**
         * @internal
         * Call to cancel any ongoing database compression started with
         * CheckCompressL(). Calls PbkCompressCanceled() for any registered
         * compression UI. To be called by Phonebook only.
         *
         * @see SetCompressUi
         * @see CheckCompress
         * @deprecated
         */
        IMPORT_C void CancelCompress();

        /**
         * @internal
         * Checks current file system space and amount of wasted space in
         * Phonebook's database. Compresses the database synchronously if
         * Phonebook's database can be made smaller by compression. If file
         * system space is still under critical level after compression,
         * leaves with KErrDiskFull.
         *
         * @exception KErrDiskFull if file system is out of space.
         * @deprecated
         */
        IMPORT_C void CheckFileSystemSpaceAndCompressL();

		/**
		 * @internal
		 * Phonebook name ordering information.
         * @deprecated
		 */
		enum TPbkNameOrder
			{
			EPbkNameOrderLastNameFirstName = 0, /// Last name then first name order
			EPbkNameOrderFirstNameLastName, /// First name then last name order
			EPbkNameOrderNotDefined /// undefined name order
			};

		/**
		 * @internal
		 * Sets name display order.
		 * @param aNameOrder The ordering to use
         * @deprecated
		 */
		IMPORT_C void SetNameDisplayOrderL(TPbkNameOrder aNameOrder);

		/**
		 * @internal
		 * Gets name display order.
		 * @return The name ordering in use
         * @deprecated
		 */
		IMPORT_C TPbkNameOrder NameDisplayOrderL();

		/**
		 * @internal
		 * Returns the phonebook constants object.
         * @return Phonebook constants manager
         * @deprecated
		 */
		IMPORT_C CPbkConstants* Constants();

        /**
         * @internal
         * Returns the sort order manager of the engine.
         */
        const CPbkSortOrderManager& SortOrderManager() const;


		/**
		 * @internal
		 * Sets whether a separator character is shown between
		 * last and first names.
		 * @param aSeparator This parameter should contain the character to be
		 *	      used as separator. If value is 0 then separator will not be
		 * 	      used between names.
		 */
		IMPORT_C void SetNameSeparatorL(TChar aSeparator);

        /**
		 * @internal
		 * Return info on whether separator character is used between last
		 * and first names.
		 * @return The separator character. Empty (value 0) if there is no
         *         separator.
		 */
		IMPORT_C TChar NameSeparator() const;



    private:  // from MContactDbObserver
        void HandleDatabaseEventL(TContactDbObserverEvent aEvent);

    private:  // Interface for CPbkContactChangeNotifier
        friend class CPbkContactChangeNotifier;
        void AddObserverL(MPbkContactDbObserver* aObserver);
        void RemoveObserver(MPbkContactDbObserver* aObserver);
        void SendEventToAllObservers(const TContactDbObserverEvent& aEvent);

    private:  // Implementation
		CPbkContactEngine();
		void ConstructL(const TDesC* aFileName, TBool aReplace, RFs* aFs);
        void ConnectFsL(RFs* aRfs);
        void ReadResourcesL(TBool& aSettingsVisibility);
        void CreateDbConnectionL(const TDesC* aFileName, 
                                 TBool aReplace, 
                                 TInt& aDbOpenError,
                                 TBool aSettingsVisible);
        void SendImmidiateEventToAllObservers(
            TContactDbObserverEventType aEventType,
            TContactItemId aContactId, TBool aSendEvent);
        void doDeleteContactL(TContactItemId aContactId);
        class CContactDbConnection;
        friend class CContactDbConnection;
		friend class CPbkSharedDataObserver;

    private:  // Data
        /// Ref: file server connection
        RFs iFs;
        /// Own: file server connection
        RFs iOwnFs;
        /// Own: Contact database connection object.
		CContactDbConnection* iDbConnection;
        /// Own: Observer array
        CArrayPtr<MPbkContactDbObserver>* iObservers;
        /// Own: fields info array.
        CPbkFieldsInfo* iPbkFieldsInfo;
        /// Own: Phonebook constants
        CPbkConstants* iPbkConstants;
        /// Own: shared data client
        RSharedDataClient* iSharedDataClient;
        /// Own: maximum free space required to delete a contact from the DB
        TInt iFreeSpaceRequiredToDelete;
        /// Own: Engine extension interface
        CPbkEngineExtension* iExtension;
        /// Is separator used between first- and last-names of contacts
        TBool iUseSeparator;
        /// The separator to be used between first- and last-names of contacts
        TChar iSeparator;
        /// CPbkSINDHandler instance identifier key.
        TUid iDtorIDKey;
        /// Own: SIND Handler
        CPbkSINDHandlerInterface* iSINDHandler;



    };

#endif   // __CPBKCONTACTENGINE_H__

// End of File
