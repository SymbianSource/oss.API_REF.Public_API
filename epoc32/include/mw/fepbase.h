// Copyright (c) 1997-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
//

#ifndef __FEPBASE_H__
#define __FEPBASE_H__

#include <e32std.h>
#include <e32base.h>
#include <f32file.h>
#include <w32std.h>
#include <coedef.h>
#include <coemain.h>
#include <fepbutils.h>
#include <fepbconfig.h>

class CCoeControl;


/** Specifies the mixin protocol for observing a FEP transaction.

Applications which need to implement this protocol should derive from this 
class. The functions are not pure virtual because most applications will only 
need to override one of them.

@see CCoeFep::MakeDeferredFunctionCall() 
@publishedAll 
@released */
class MCoeFepObserver
	{
public:
	// both of these functions do nothing by default - the reason that they are not pure 
	// virtual is that most applications will only want to override one of them
	IMPORT_C virtual void HandleStartOfTransactionL(); // the responsibility of FEPs to call
	IMPORT_C virtual void HandleCompletionOfTransactionL(); // the responsibility of FEPBASE to call - not to be called if the transaction is canceled
private: // reserved. do not override!	
	IMPORT_C virtual void MCoeFepObserver_Reserved_1();
	IMPORT_C virtual void MCoeFepObserver_Reserved_2();
	};

/** Handles the start of a FEP transaction. 

This is a non-member function which just calls aFepObserver.HandleStartOfTransactionL().

It is called indirectly by a FEP to notify the application that it is starting a transaction. 
This is done by calling CCoeEnv::ForEachFepObserverCall() passing in 
FepObserverHandleStartOfTransactionL. Internally, this calls HandleStartOfTransactionL() for 
each MCoeFepObserver object that has been registered with the control environment.

@param aFepObserver The FEP observer.
@see MCoeFepObserver::HandleStartOfTransactionL()
@publishedAll 
@released */
IMPORT_C void FepObserverHandleStartOfTransactionL(MCoeFepObserver& aFepObserver);


/** Abstract base class for all FEPs.

FEP authors must derive a class from CCoeFep. The CCoeFep-derived class should 
implement all of its pure virtual functions including the ones which CCoeFep 
inherits from its base classes. For information on these functions, see the 
documentation of the base classes. The global NewFepL() function is used to 
create a fully initialised object of the derived class. 

FEPs that need to intercept key events should own a CCoeControl-derived object. 
This object is referred to as the FEP control. The FEP control should 
be added to the control stack at a priority of ECoeStackPriorityFep, so that 
it receives first refusal of key events from the window server.

In general, focus is retained by the underlying application. This has the 
advantage that the user can see where the output produced by the FEP will 
go. When focus is switched between controls, the FEP must be notified in case 
the input capability of the focussed control changes. For instance, the FEP 
needs to prevent the user composing a large amount of text only for it to 
be passed to a newly focussed control that cannot accept text input. CCoeFep 
derives from MCoeFocusObserver, which enables FEPs to receive notification 
when the focus for the underlying control changes. The implementation of MCoeFocusObserver's 
functions can call the enquiry functions of class TCoeInputCapabilities to 
find out what input capabilities are supported by the new target control (you 
need to get the TCoeInputCapabilities object from the application UI first: 
see CCoeAppUi::InputCapabilities()).

@see NewFepL() 
@publishedAll 
@released */
class CCoeFep : public CBase, protected MFepAttributeStorer, public MCoeForegroundObserver, public MCoeFocusObserver, private MCoeMessageObserver
	{
public:
	/** Response to key or pointer event */
	enum TEventResponse
		{
		EEventWasNotConsumed,	/** < Indicates that the FEP did not process the event. */
		EEventWasConsumed		/** < Indicates that the FEP did process the event. */
		};

	/** Enables FEPs to have some code called but not in the context of the current 
	call stack, hence the name "deferred".

	For an explanation of the intended use of this class, see 
	CCoeFep::MakeDeferredFunctionCall(). */
	class MDeferredFunctionCall
		{
	public:
		/** This function is called from within a high-priority active object's RunL() 
		shortly after the active object has been queued by calling CCoeFep::MakeDeferredFunctionCall(). */
		virtual void ExecuteFunctionL()=0;
	private: // reserved. do not override!	
		IMPORT_C virtual void MDeferredFunctionCall_Reserved_1();
		IMPORT_C virtual void MDeferredFunctionCall_Reserved_2();
		};

	/** FEPs send character codes to the application underneath them using SimulateKeyEventsL(). 
	Occasionally a FEP may wish to also specify the modifiers (e.g. Fn, Ctrl, 
	Shift) to be sent with that character code. In this case, they should use 
	the overload of CCoeFep::SimulateKeyEventsL() which takes an array of MModifiedCharacters. */
	class MModifiedCharacter
		{
	public:
		/** Returns the character code of the key combination.
		
		@return The character code of the key combination. */
		virtual TUint CharacterCode() const=0;
		/** Returns a TUint which indicates which modifiers to override, rather than using 
		the current state of the keyboard's modifiers.
	
		@return The modifiers to override in the key combination. */
		virtual TUint ModifierMask() const=0;
		/** Returns a TUint which indicates which of the modifiers specified in the mask 
		(returned by ModifierMask()) must be on and which must be off.
	
		@return Indicates which of the modifiers specified in the mask (returned by 
		ModifierMask()) must be on and which must be off. */
		virtual TUint ModifierValues() const=0;
	private: // reserved. do not override!	
		IMPORT_C virtual void MModifiedCharacter_Reserved_1();
		IMPORT_C virtual void MModifiedCharacter_Reserved_2();
		};

public:
	IMPORT_C virtual ~CCoeFep();
	IMPORT_C TBool IsSimulatingKeyEvent() const;
	IMPORT_C TBool IsTurnedOnByL(const TKeyEvent& aKeyEvent) const;
	IMPORT_C TBool IsTurnedOffByL(const TKeyEvent& aKeyEvent) const;
public: // new public virtual functions
	/** Cancels the FEP transaction.
	
	A FEP transaction begins when an event is first intercepted by the FEP and 
	ends either when the processed text is committed to the application underneath, 
	or if it is cancelled. */
	virtual void CancelTransaction()=0;
public:
	IMPORT_C void OnStartingHandlingKeyEvent_WithDownUpFilterLC();
	IMPORT_C void OnStartingHandlingKeyEvent_NoDownUpFilterLC();
	IMPORT_C TKeyResponse OnFinishingHandlingKeyEvent_WithDownUpFilterL(TEventCode aEventCode, const TKeyEvent& aKeyEvent, TKeyResponse aKeyResponse);
	IMPORT_C TKeyResponse OnFinishingHandlingKeyEvent_NoDownUpFilterL(TEventCode aEventCode, const TKeyEvent& aKeyEvent, TKeyResponse aKeyResponse);
protected:
	IMPORT_C CCoeFep(CCoeEnv& aConeEnvironment);
	IMPORT_C void BaseConstructL(const CCoeFepParameters& aFepParameters);
	IMPORT_C void ReadAllAttributesL();
	IMPORT_C void MakeDeferredFunctionCall(MDeferredFunctionCall& aDeferredFunctionCall);
	IMPORT_C void SimulateKeyEventsL(const TArray<TUint>& aArrayOfCharacters);
	IMPORT_C void SimulateKeyEventsL(const TArray<MModifiedCharacter>& aArrayOfModifiedCharacters);
	IMPORT_C void WriteAttributeDataAndBroadcastL(TUid aAttributeUid);
	IMPORT_C void WriteAttributeDataAndBroadcastL(const TArray<TUid>& aAttributeUids);
	IMPORT_C TBool IsOn() const;
public: // not for external use
	void SetOnState(TBool aOnState);
private:
	class CHighPriorityActive;
	class CLowPriorityActive;
	class CCoeFepExtra;
private:
	void DoOnStartingHandlingKeyEventLC(TUint aFlagNoDownUpFilter);
	TKeyResponse DoOnFinishingHandlingKeyEventL(TEventCode aEventCode, const TKeyEvent& aKeyEvent, TKeyResponse aKeyResponse);
	static void TurnOffKeyEventHandlingFlags(TAny* aFlags);
	// from MFepAttributeStorer
	IMPORT_C virtual void MFepAttributeStorer_Reserved_1();
	IMPORT_C virtual void MFepAttributeStorer_Reserved_2();
	// from MCoeForegroundObserver
	IMPORT_C virtual void MCoeForegroundObserver_Reserved_1();
	IMPORT_C virtual void MCoeForegroundObserver_Reserved_2();
	// from MCoeFocusObserver
	IMPORT_C virtual void MCoeFocusObserver_Reserved_1();
	IMPORT_C virtual void MCoeFocusObserver_Reserved_2();
	// from MCoeMessageObserver
	IMPORT_C virtual TMessageResponse HandleMessageL(TUint32 aClientHandleOfTargetWindowGroup, TUid aMessageUid, const TDesC8& aMessageParameters);
	IMPORT_C virtual void MCoeMessageObserver_Reserved_1();
	IMPORT_C virtual void MCoeMessageObserver_Reserved_2();
	// new private virtual functions
	/** Called to notify the FEP that it has either just been turned on or just been 
	turned off (it can find out which by calling CCoeFep::IsOn()). 
	
	If FEPs want to change their appearance when they are off (e.g. make themselves 
	invisible), then they should implement this function accordingly. 

	@publishedAll
	@released */
	virtual void IsOnHasChangedState()=0;
	
	/**
	@deprecated */
	virtual void OfferKeyEventL(TEventResponse& /*aEventResponse*/, const TKeyEvent& /*aKeyEvent*/, TEventCode /*aEventCode*/){};

	/**
	@deprecated */
	virtual void OfferPointerEventL(TEventResponse& /*aEventResponse*/, const TPointerEvent& /*aPointerEvent*/, const CCoeControl* /*aWindowOwningControl*/){};

	/**
	@deprecated */
	virtual void OfferPointerBufferReadyEventL(TEventResponse& /*aEventResponse*/, const CCoeControl* /*aWindowOwningControl*/){};
private:	// reserved. do not override!	
	IMPORT_C virtual void CCoeFep_Reserved_1();
	IMPORT_C virtual void CCoeFep_Reserved_2();
private:
	class SKeyEvent;
	CCoeEnv& iConeEnvironment;
	TUint iFlags;
	CHighPriorityActive* iHighPriorityActive;
	CCoeFepExtra* iExtra;
	SKeyEvent* iLastKeyEvent;
	TUint iSpare[13];
	};


/** Specifies the mixin protocol for handling pointer events in inline text. 

This class should be overridden by front end processors which support inline editing.

An instance of a class which implements this protocol should be passed to 
MCoeFepAwareTextEditor::StartFepInlineEditL(). 

@publishedAll 
@released */
class MFepPointerEventHandlerDuringInlineEdit // to be overridden by inline-editing front-end processors
	{
public:
	/** This function is called when a pointer event is received within the inline 
	text. It may need to update the cursor position within the inline text and 
	do text selection in response to drag events.
	
	@param aType Pointer event types.
	@param aModifiers Modifier keys (SHIFT, CTRL, FN etc.).
	@param aPositionInInlineText The position at which the pointer event occurred, 
	as an offset from the start of the inline text string. */
	virtual void HandlePointerEventInInlineTextL(TPointerEvent::TType aType, TUint aModifiers, TInt aPositionInInlineText)=0;
private: // reserved. do not override!	
	IMPORT_C virtual void MFepPointerEventHandlerDuringInlineEdit_Reserved_1();
	IMPORT_C virtual void MFepPointerEventHandlerDuringInlineEdit_Reserved_2();
	};

class TCharFormat;
class TCursorSelection;
class MFormCustomDraw;
class MFepInlineTextFormatRetriever;
class MCoeFepAwareTextEditor_Extension1;


/** Specifies a protocol for FEP-aware text editors.

TCoeInputCapabilities::FepAwareTextEditor() returns a pointer to an object 
of this class. A NULL return value indicates that the interface is not supported 
by any of the currently focused controls.

Inline editing means composing text directly in the target text editor control 
rather than in the FEP's edit window first. The target text editor must implement 
the MCoeFepAwareTextEditor interface in order to support inline text. The 
inline text may be differentiated from the surrounding text by the use of 
different formatting. These differences are removed when the inline text transaction 
is committed (causing the inline text to become a real part of the document). 
Cancelling the inline text transaction deletes the inline text and restores 
any previously selected text. A benefit of inline editing is that the user 
only has to concentrate on one area of the screen rather than two. 

An inline editing transaction consists of the following sequence of function 
calls:

- a call to StartFepInlineEditL()

- zero, one or more calls to UpdateFepInlineTextL()

- a call to either CommitFepInlineEditL() or CancelFepInlineEdit() 

@publishedAll 
@released */
class MCoeFepAwareTextEditor // to be overridden by text-editors
	{
public:
	/** 
	Starts a FEP inline editing transaction. 
	
	Inserts a descriptor containing the initial inline text into the text editor. 
	The inline text should normally replace any selected text.
	
	The final three parameters are instances of abstract classes, so that the 
	caller of this function must create and instantiate classes deriving from 
	them. These instances must remain in existence for the entire duration of 
	the inline editing transaction.
	
	Inline editing should not already be taking place when this function is called.
	
	@param aInitialInlineText The inline text to insert into the text editor.
	@param aPositionOfInsertionPointInInlineText An insertion position within the 
	inline text. This is an offset from the start of the inline text.
	@param aCursorVisibility ETrue for visible text cursor, EFalse for invisible 
	text cursor in the text editor.
	@param aCustomDraw Pointer to a custom drawing object. May be used to do advanced 
	formatting of the inline text. This parameter is optional; a NULL pointer 
	may be specified.
	@param aInlineTextFormatRetriever Defines a single member function, GetFormatOfFepInlineText() 
	which is used by the text editor to find out the formatting to apply to the 
	inline text. It is also possible to apply different formatting to different 
	parts of the inline text.
	@param aPointerEventHandlerDuringInlineEdit Defines a single function, HandlePointerEventInInlineTextL() 
	which is called when a pointer event is received within the inline text. This 
	function might update the cursor position within the inline text and do text 
	selection. 
	*/
	virtual void StartFepInlineEditL(const TDesC& aInitialInlineText, TInt aPositionOfInsertionPointInInlineText, 
		TBool aCursorVisibility, const MFormCustomDraw* aCustomDraw, MFepInlineTextFormatRetriever& aInlineTextFormatRetriever, 
		MFepPointerEventHandlerDuringInlineEdit& aPointerEventHandlerDuringInlineEdit)=0;
	/** Updates the inline text. 
	
	Called when a character is added to or deleted from the inline text. 
	
	The descriptor aNewInlineText contains the entire new inline text string, 
	not just the new text to be combined with the old inline text.
	
	@param aNewInlineText Descriptor which holds the entire new inline text string.
	@param aPositionOfInsertionPointInInlineText The position of the insertion 
	point (i.e. the cursor) within the inline text string aNewInlineText. This 
	is an offset from the start of the string. */
	virtual void UpdateFepInlineTextL(const TDesC& aNewInlineText, TInt aPositionOfInsertionPointInInlineText)=0;
	/** Sets the visibility of the text cursor in the text editor.
	
	The cursor visibility is initialised using StartFepInlineEditL(). SetInlineEditingCursorVisibilityL() 
	is provided for FEPs which need to change the visibility of the cursor during 
	the inline editing transaction.
	
	@param aCursorVisibility ETrue for visible text cursor, EFalse for invisible 
	text cursor. */
	virtual void SetInlineEditingCursorVisibilityL(TBool aCursorVisibility)=0;
	IMPORT_C void CommitFepInlineEditL(CCoeEnv& aConeEnvironment);
	/** Cancels the inline editing transaction. 
	
	The edit window should be rolled back to the state it was in before the FEP 
	transaction started, i.e. any inline text in the document which has not yet 
	been committed should be removed. If the inline text has replaced existing text, 
	(e.g. a selection) the replaced text should be reinstated. */
	virtual void CancelFepInlineEdit()=0;
	// with regard to the behaviour of the following functions (except GetScreenCoordinatesForFepL), 
	// note that when inline editing, the contents of the editor will be such that the text constituting 
	// the selection immediately prior to inline editing will be replaced by the inline text 
	// (CancelFepInlineEdit reinstates the previous selection)
	/** Returns the total number of characters in the text editor.
	
	@return The total number of characters in the text editor. */
	virtual TInt DocumentLengthForFep() const=0;
	/** Returns the upper limit (if any) on the length of text that the text editor 
	can hold.
	
	@return The maximum number of characters that the text editor can hold. */
	virtual TInt DocumentMaximumLengthForFep() const=0;
	/** Sets the range of characters in the text editor which should be selected.
	
	@param aCursorSelection Contains the cursor and anchor positions for the selection. */
	virtual void SetCursorSelectionForFepL(const TCursorSelection& aCursorSelection)=0;
	/** Gets the range of characters in the text editor which are selected.
	
	@param aCursorSelection On return, contains the cursor and anchor positions 
	of the selection. */
	virtual void GetCursorSelectionForFep(TCursorSelection& aCursorSelection) const=0;
	/** Copies a portion of the text editor's text content into a descriptor.
	
	@param aEditorContent A descriptor; on return contains a copy of a portion 
	of the text.
	@param aDocumentPosition The document position in the text editor from which 
	to copy.
	@param aLengthToRetrieve The number of characters to copy. */
	virtual void GetEditorContentForFep(TDes& aEditorContent, TInt aDocumentPosition, TInt aLengthToRetrieve) const=0;
	/** Gets the character formatting which applies to the document position specified. 

	This function allows FEPs to find out the ambient formatting so that the FEP 
	can choose a format for the inline text that will clearly differentiate it 
	from the surrounding text.
	
	@param aFormat On return, contains the character formatting which applies 
	to the character at aDocumentPosition.
	@param aDocumentPosition The document position of interest. */
	virtual void GetFormatForFep(TCharFormat& aFormat, TInt aDocumentPosition) const=0;
	/** Gets the x,y screen coordinates for the left hand side of the baseline of the 
	character located at a specified document position. 

	Also gets the height (ascent + descent) and ascent of the font of the character. 
	This function could be used to position the FEP window as close as possible to 
	the insertion point in the text editor.
	
	@param aLeftSideOfBaseLine On return, contains the x,y coordinates of the 
	left side of the baseline of the character located at aDocumentPosition.
	@param aHeight On return, contains the height (ascent + descent) of the font 
	of the character at aDocumentPosition.
	@param aAscent On return, contains the ascent of the font of the character 
	at aDocumentPosition.
	@param aDocumentPosition The document position of interest. */
	virtual void GetScreenCoordinatesForFepL(TPoint& aLeftSideOfBaseLine, TInt& aHeight, TInt& aAscent, TInt aDocumentPosition) const=0;
	
	IMPORT_C MCoeFepAwareTextEditor_Extension1* Extension1();
private:
	/** Private function called by CommitFepInlineEditL(). 
	
	Implementations should commit the inline text to the document. This 
	ends the inline editing transaction and causes the inline text to 
	become a part of the document. 

	@publishedAll
	@released */
	virtual void DoCommitFepInlineEditL()=0;
	IMPORT_C virtual MCoeFepAwareTextEditor_Extension1* Extension1(TBool& aSetToTrue);
private: // reserved. do not override!	
	IMPORT_C virtual void MCoeFepAwareTextEditor_Reserved_2();
	};


class MLayDoc;

/**
MCoeFepLayDocExtension is an interface class which should be derived from by test editors to
provide access to the current MLayDoc object, and to set a new MLayDoc object.
Used directly from the FEP to decorate the inline edit text, without changing
the actual document text.

@publishedAll 
@released  
*/
class MCoeFepLayDocExtension
	{
public:
	/**
	Retrives the current MLayDoc object from the text editor
	
	@return Pointer to a MLayDoc object.
	*/
	virtual MLayDoc* GetCurrentMLayDoc() const = 0;
	
	/**
	Sets a new MLayDoc object into the CTextLayout object
	
	@param aLayDoc The new layout document
	*/
	virtual void SetMLayDoc(MLayDoc* aLayDoc) = 0;
	
	/**
	Retrives inline edit positioning information from the editor
	@param 	"TInt& aPositionInDocument" 		Position of the text in the document
	@param 	"TInt& aCursorPositionInDocument" 	Position of the cursor in the document
	@param 	"TInt& aSelectionLength"			The number of characters in the selected text
	*/	 
	virtual void GetFepEditorState(TInt& aPositionInDocument, TInt& aCursorPositionInDocument, TInt& aSelectionLength) = 0;

	/**
	Used to tell the editor when the size of the inline edit has changed, so
	the text layout can update itself. Should be called before and after the inline
	edit has been decorated.
	@param     	"TCursorSelection aSelection" 	Position of the line edit from the beginning of the text
    @param     	"TInt aDeletedChars" 			Number of character deleted since the last time the text was formatted.
	
	*/
	virtual void HandleInsertDeleteL(TCursorSelection aSelection,TInt aDeletedChars) = 0;
private: // reserved. do not override!	
	IMPORT_C virtual void MCoeFepLayDocExtension_Reserved_1();
	IMPORT_C virtual void MCoeFepLayDocExtension_Reserved_2();
	};


/** An interface class which may be derived from by text editors to enable FEPs 
to store state information inside the editor. 
To be overridden by text-editors

The CState class, defined within the scope of MCoeFepAwareTextEditor_Extension1 
represents the state information. This is information specific to the control 
which is only of interest to the FEP.

A class which implements this interface must implement the pure virtual functions 
State() and SetStateTransferingOwnershipL() , to get and set the state. The 
class should also implement the MCoeFepAwareTextEditor interface. It must 
override the private virtual MCoeFepAwareTextEditor::Extension1() to return 
a pointer to itself (the default implementation returns NULL). The private 
virtual MCoeFepAwareTextEditor::Extension1() function is called by the public, 
non-virtual MCoeFepAwareTextEditor::Extension1() function.

For example, if a FEP wants to set some state information in a text editor 
which is about to lose focus, the FEP should first call the editor's Extension1() 
function. If this returns non-NULL, the FEP should call the editor's implementation 
of SetStateTransferingOwnershipL() , passing in an object of a class derived 
from CState , which holds the state information. It should also pass in a 
UID which uniquely identifies the FEP. Later, when focus returns to the editor, 
the FEP can call State() to retrieve the state information it previously set. 
Note that CState has several reserved functions, to enable it to be extended 
in future, while retaining backwards compatibility. 

@publishedAll 
@released */
class MCoeFepAwareTextEditor_Extension1 
	{
public:
	class CState : public CBase
	/** State information for a text editor control. 
	This is information specific to the control which is only of interest to the 
	FEP which sets it. */
		{
	protected:
		IMPORT_C CState();
		IMPORT_C void BaseConstructL();
	public:
		IMPORT_C virtual ~CState();
	private: // reserved. do not override!	
		IMPORT_C virtual void CState_Reserved_1();
		IMPORT_C virtual void CState_Reserved_2();
		IMPORT_C virtual void CState_Reserved_3();
		IMPORT_C virtual void CState_Reserved_4();
	private:
		TAny* iSpareForFutureUse;
		};
public:
	/** Sets state information in the text editor.
	
	This function must only transfer ownership of the state object after it has 
	successfully done everything that can leave.
	
	@param aState Pointer to the state information object.
	@param aTypeSafetyUid A UID which uniquely identifies the FEP which is calling 
	this function. The text editor should store this value for use by the State() 
	function. */
	virtual void SetStateTransferingOwnershipL(CState* aState, TUid aTypeSafetyUid)=0; // this function must only transfer ownership after it has successfully done everything that can leave
	/** Gets the state information previously set using SetStateTransferingOwnershipL(). 

	This function does not transfer ownership. The function should first check 
	that aTypeSafetyUid matches the UID value previously specified by SetStateTransferingOwnershipL(). 
	If it doesn't match, the function should return NULL.
	
	@param aTypeSafetyUid A UID which uniquely identifies the FEP which is calling 
	this function. The purpose of this is to enable the FEP to safely downcast 
	the CState pointer returned by this function to a pointer to a derived class 
	known about by the FEP.
	@return Pointer to the state information object. */
	virtual CState* State(TUid aTypeSafetyUid)=0;
public:
	/** Updates the inline text. 
	
	Called when a character is added to or deleted from the inline text. 
	
	The descriptor aNewInlineText contains the entire new inline text string, 
	not just the new text to be combined with the old inline text.
	
	@param aSetToTrue 		Boolean set to EFalse by the caller and subsequently to ETrue by the function indicating that
							this is the implemented version and not the previous reserved funtion.
	@param aCursorSelection The position of any hilighted text.
	@param aNewInlineText 	Descriptor which holds the entire new inline text string.
	@param aPositionOfInsertionPointInInlineText 
	The position of the insertion point (i.e. the cursor) within the inline text string aNewInlineText. 
	This is an offset from the start of the string. 
	*/
	IMPORT_C virtual void StartFepInlineEditL(TBool& aSetToTrue, const TCursorSelection& aCursorSelection, 
		const TDesC& aInitialInlineText, TInt aPositionOfInsertionPointInInlineText, TBool aCursorVisibility, 
		const MFormCustomDraw* aCustomDraw, MFepInlineTextFormatRetriever& aInlineTextFormatRetriever, 
		MFepPointerEventHandlerDuringInlineEdit& aPointerEventHandlerDuringInlineEdit);
	
	/** Changes the cursor displayed to indicate different modes of operation. For example how text is enterered
	@param aSetToTrue 		Boolean set to EFalse by the caller and subsequently to ETrue by the function indicating that
							this is the implemented version and not the previously reserved funtion.
	@param aTextCursor		The new cursor to be displayed.
	*/	
	IMPORT_C virtual void SetCursorType(TBool& aSetToTrue, const TTextCursor& aTextCursor);
	
	/**
	Retrieves the current MCoeFepLayDocExtension object from the text editor
	@param aSetToTrue 		Boolean set to EFalse by the caller and subsequently to ETrue by the function indicating that
							this is the implemented version and not the previously reserved funtion.
	*/
	IMPORT_C virtual MCoeFepLayDocExtension* GetFepLayDocExtension(TBool& aSetToTrue);
private: // reserved. do not override!	
	IMPORT_C virtual void MCoeFepAwareTextEditor_Extension1_Reserved_4();
	};


/** Retrieves a control's caption for use by a FEP. 

An example of a caption is the non-editable text description displayed 
alongside each item in a dialog.

TCoeInputCapabilities::CaptionRetrieverForFep() returns a pointer to an object 
of this class. A NULL return value indicates that the interface is not supported 
by any of the currently focused controls. If not NULL, call GetCaptionForFep(), 
which fills the supplied buffer with the control's caption, truncating it 
if the supplied buffer is too small for the whole caption. 

@publishedAll
@released */
class MCoeCaptionRetrieverForFep // to be overridden by captioned-controls
	{
public:
	/** An implementation of this function should fill aCaption with the target control's 
	caption (or as much of the caption as will fit).
	
	For example, code similar to the following might be used (assuming that your caption is 
	stored internally in iCaption):
	
	@code
	const TInt maximumLength=aCaption.MaxLength();
	if (iCaption.Length()>maximumLength)
	    aCaption=iCaption.Left(maximumLength);
	else
	    aCaption=iCaption;

	@endcode
	@param aCaption On return, this should be set to the caption of the target 
	control. */
	virtual void GetCaptionForFep(TDes& aCaption) const=0; // gets as much as will fit in aCaption
private: // reserved. do not override!	
	IMPORT_C virtual void MCoeCaptionRetrieverForFep_Reserved_1();
	IMPORT_C virtual void MCoeCaptionRetrieverForFep_Reserved_2();
	};

#endif	// __FEPBASE_H__

