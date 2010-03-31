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
*     View states.
*
*/


#ifndef __CPbkViewState_H__
#define __CPbkViewState_H__

//  INCLUDES
#include <e32base.h>    // CBase
#include <cntdef.h>     // TContactItemId, CContactIdArray

// FORWARD DECLARATIONS
class RReadStream;
class RWriteStream;
class CPbkFieldDataArray;

// CLASS DECLARATION

/**
 * Generic Phonebook view state class. Class can be used to pass parameters
 * the Phonebook application when launching the application with the symbian
 * view launching mechanism.
 */
class CPbkViewState : public CBase
    {
    public:  // Types
        enum TDataType
            {
            EEnd = 0,
            EFocusedContactId,
            ETopContactId,
            EMarkedContactIds,
            EFocusedFieldIndex,
            ETopFieldIndex,
            EFieldDataArray,
            EParentContactId,
            EFlags
            };

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

    public:  // Constructors and destructor
        /**
         * Creates and returns a new instance of this class.
         */
        IMPORT_C static CPbkViewState* NewL();

        /**
         * Like NewL(), but leaves the object on the cleanup stack
         * @see NewL
         */
        IMPORT_C static CPbkViewState* NewLC();
        
        /**
         * Creates and returns a new instance of this class initialized
         * from aStream.
         * @param aStream   A view state stream to internalize.
         */
        IMPORT_C static CPbkViewState* NewL(RReadStream& aStream);
        
        /**
         * Like NewL(RReadStream& aStream) but leaves the object on
         * the cleanup stack.
         * @see NewL(RReadStream& aStream)
         * @param aStream   A view state stream to internalize.
         */
        IMPORT_C static CPbkViewState* NewLC(RReadStream& aStream);
        
        /**
         * Creates and returns a new instance of this class initialized
         * from aBuf.
         * @param aBuf   A view state buffer to internalize.
         */
        IMPORT_C static CPbkViewState* NewL(const TDesC8& aBuf);
        
        /**
         * Like NewL(const TDesC8& aBuf) but leaves the object on
         * the cleanup stack.
         * @see NewL(const TDesC8& aBuf)
         * @param aBuf   A view state buffer to internalize.
         */
        IMPORT_C static CPbkViewState* NewLC(const TDesC8& aBuf);

        /**
         * Destructor.
         */
        ~CPbkViewState();

    public:  // Getters
        /**
         * Returns the message uid for use with view server messages.
         */
        IMPORT_C static TUid Uid();

        /**
         * Returns id of the focused contact.
         * @return  Contact item id of the focused contact, KNullContactId if not set.
         */
        IMPORT_C TContactItemId FocusedContactId() const;

        /**
         * Returns id of the topmost contact.
         * @return  Contact item id of the top contact, KNullContactId if not set.
         */
        IMPORT_C TContactItemId TopContactId() const;

        /**
         * Returns const array of marked contacts ids, NULL if not set. 
         * @return  Contact id array of the marked contacts, NULL if not set.
         */
        IMPORT_C const CContactIdArray* MarkedContactIds() const;

        /**
         * Returns array of marked contacts ids, NULL if not set. Owmership not
         * transferred.
         * @return  Contact id array of the marked contacts, NULL if not set.
         */
        IMPORT_C CContactIdArray* MarkedContactIds();

        /**
         * Returns index of the focused field (field is from FocusedContactId()), 
         * -1 when no field focused.
         * @return  Index of the focused field, -1 if no field is focused.
         */
        IMPORT_C TInt FocusedFieldIndex() const;

        /**
         * Returns index of the topmost field (field is from FocusedContactId()), 
         * -1 when no topmost field.
         * @return  Index of the topmost field, -1 if no topmost field.
         */
        IMPORT_C TInt TopFieldIndex() const;

        /**
         * Returns field data array, NULL if not set.
         * @return Field data array object, NULL if not set.
         */
        IMPORT_C CPbkFieldDataArray* FieldDataArray() const;

        /**
         * Returns the focused contact id's parent, KNullContactId if not set.
         * @return Focused contact id's parent, KNullContactId if not set.
         */
        IMPORT_C TContactItemId ParentContactId() const; 

        /**
         * Returns the view state flags. See CPbkViewState::TFlags.
         * @return  View state object flags
         */
        IMPORT_C TUint Flags() const;

    public:  // Setters
        /**
         * Sets id of the focused contact to aId.
         * @param aId   Sets the focused contact id.
         */
        IMPORT_C void SetFocusedContactId(TContactItemId aId);

        /**
         * Sets id of the topmost contact to aId.
         * @param aId   Sets the topmost contact id.
         */
        IMPORT_C void SetTopContactId(TContactItemId aId);

        /**
         * Sets the array of marked contact ids to aArray. Destroys previous
		 * array and takes ownership of aArray.
         * @param aArray    Sets the marked contact ids.
         */
        IMPORT_C void SetMarkedContactIds(CContactIdArray* aArray);

        /**
         * Sets index of the focused field to aIndex (field from
		 * FocusedContactId()), -1 when no field focused.
         * @param aIndex    Sets focused field index.
         */
        IMPORT_C void SetFocusedFieldIndex(TInt aIndex);

        /**
         * Sets index of the topmost field to aIndex (field from
		 * FocusedContactId()), -1 when no topmost field.
         * @param aIndex    Sets the topmost field index.
         */
        IMPORT_C void SetTopFieldIndex(TInt aIndex);

        /**
         * Sets field data array to aArray. Destroys previous array
         * and takes ownership of aArray.
         * @param aFieldDataArray   Sets the field data array.
         */
        IMPORT_C void SetFieldDataArray(CPbkFieldDataArray* aFieldDataArray);

        /**
         * Reset this state to empty.
         */
        IMPORT_C void Reset();

        /**
         * Sets the focused contact ids parent contact id.
         * @param aParentContactId  Sets the contact ids parent id.
         */
        IMPORT_C void SetParentContactId(TContactItemId aParentContactId);

        /**
         * Sets the view state flags.
         * @param aFlags    Sets the view state parameters. See CPbkViewState::TFlags.
         */
        IMPORT_C void SetFlags(TUint aFlags);

        /**
         * Merges another view state to this view state by setting values from the
         * parameter and overriding any previous values in this state.
         *
         * @param aOtherState   The state to merge to this state. The 
         *                      properties which have a value in aOtherState
         *                      override properties in this object. The aOtherState
         *                      object may be modified by this function.
         */
        /*IMPORT_C*/ void MergeViewState(CPbkViewState& aOtherState);

    public:  // Stream support
        /**
         * Packages and returns this object in a buffer. Caller is responsible
         * of deleting the buffer.
         * @return  Packaged state in a buffer.
         */
        IMPORT_C HBufC8* PackL() const;

        /**
         * Like PackL, but leaves the buffer on the cleanup stack.
         * @see PackL
         * @return Packaged state in a buffer.
         */
        IMPORT_C HBufC8* PackLC() const;

        /**
         * Sets this state from aPack previously created with PackL.
         * @see PackL
         * @see PackLC
         * @param aPack Previously packaged state.
         */
        IMPORT_C void UnpackL(const TDesC8& aPack);

        /**
         * Externalizes this object to aStream.
         * @see InternalizeL
         * @param aSteam    Stream where to externalize this objects state.
         */
        IMPORT_C void ExternalizeL(RWriteStream& aStream) const;

        /**
         * Internalizes this object from aStream.
         * @see ExternalizeL
         * @param aStream   A stream from where this objects state can be internalized from.
         */
        IMPORT_C void InternalizeL(RReadStream& aStream);

    public: // Support functions
        IMPORT_C TBool operator==(const CPbkViewState& aRhs) const; 

    private:  // Implementation
        CPbkViewState();

    private:  // data
        /// Own: Id of the focused contact
        TContactItemId iFocusedContactId;
        /// Own: Id of the topmost contact
        TContactItemId iTopContactId;
        /// Own: Index of the focused field
        TInt iFocusedFieldIndex;
        /// Own: Index of the top field
        TInt iTopFieldIndex;
        /// Own: Array of marked contacts
        CContactIdArray* iMarkedContactIds;
        /// Own: Field data array
        CPbkFieldDataArray* iFieldDataArray;
        /// Own: Id of the focused contacts parent
        TContactItemId iParentContactId;
        /// Own: Flags
        TUint iFlags;

    private:  // const static data
        static const TUid KUid;
    };


/*
   ** View state binary stream format **
   
    - View parameter UID is 0x101f4ccf

    - Format of the stream in (slightly freeform) BNF:

    <stream>  ::= <command>+
    <command> ::= Int8(opcode) parameters
    <opcode>  ::= EEnd | EFocusedContactId | ETopContactId | EMarkedContactIds |
                  EFocusedFieldIndex | ETopFieldIndex | EFieldDataArray
    <command> ::= EEnd  // no further commands are read after EEnd. EEnd is not mandatory in a stream.
    <command> ::= EFocusedContactId Int32(TContactItemId)
    <command> ::= ETopContactId Int32(TContactItemId)
    <command> ::= EMarkedContactIds (Int32(count) { Int32(TContactItemId) })  // count is count TContactItemIds
    <command> ::= EFocusedFieldIndex Int32(index)
    <command> ::= ETopFieldIndex Int32(index)
    <command> ::= EFieldDataArray <contactdata>
    <command> ::= EParentContactId Int32(TContactItemId)

    <contactdata> ::= Int32(count) { fielddata }  // count is count of fieldatas
    <fielddata> ::= <fieldtype> data
    <fieldtype> ::= ETypeText | ETypeTime
    <fielddata> ::= ETypeText (Int32(length) text)  // length is length of text in chars, text is unicode
    <fielddata> ::= ETypeTime (Int32(high) Int32(low))  // high and low words of a TTime's internal Int64

    Constants:
        EEnd = 0,
        EFocusedContactId = 1,
        ETopContactId = 2,
        EMarkedContactIds = 3,
        EFocusedFieldIndex = 4,
        ETopFieldIndex = 5,
        EFieldDataArray = 6,
        EParentContactId = 7

    - Example:
    Activate Phonebook's contact info view to show contact with id 5 and field 
    at index 3 focused:

    // Write parameters in a buffer
    TBuf8<16> param;
    RDesWriteStream stream(param);
    stream.PushL();
    param.WriteInt8L(1);  // opcode EFocusedContactId
    param.WriteInt32L(5);  // Contact id 5
    param.WriteInt8L(4);  // opcode EFocusedFieldIndex
    param.WriteInt32L(3);  // field index 3
    stream.CommitL();
    CleanupStack::PopAndDestroy();  // stream

    // Make view id with Phonebook's app UID3 and Contact Info View's id
    const TVwsViewId viewId(0x101f4cce, 4);

    // Activate the view
    AppUi()->ActivateViewL(viewId, TUid::Uid(0x101f4ccf), param);


    - Same example as above, now using CPbkViewState:

    #include <CPbkViewState.h>  // need also to add PbkView.lib into projects .mmp
    #include <PbkUID.h> // Phonebook UIDs

    CPbkViewState* pbkViewParam = CPbkViewState::NewLC();
    pbkViewParam->SetFocusedContactId(5);
    pbkViewParam->SetFocusedFieldIndex(3);
    HBufC8* paramBuf = pbkViewParam->PackLC();
    
    // Make view id with Phonebook's app UID3 and Contact Info View's id
    const TVwsViewId viewId(KPbkUID3, 4);

    // Activate the view
    AppUi()->ActivateViewL(viewId, CPbkViewState::Uid(), *paramBuf);

    // Cleanup
    CleanupStack::PopAndDestroy(2);  // paramBuf, pbkViewParam

    - The latter example is cleaner, but using CPbkViewState from your 
    application means that your application will have a dependency to 
    CPbkViewState.h and PbkView.lib at compile time and to PbkView.dll at
    run time.

*/

#endif // __CPbkViewState_H__
            
// End of File
