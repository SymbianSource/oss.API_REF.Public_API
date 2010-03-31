// Copyright (c) 1997-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
// which accompanies this distribution, and is available
// at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
//

#ifndef __FEPBUTILS_H__
#define __FEPBUTILS_H__




/** Macro to be called by a keyboard-based FEP at the start of its CCoeControl::OfferKeyEventL()-overriding 
function.

It causes key up and key down events to be consumed so that the FEP only receives 
standard key events (of type EEventKey, see the TEventCode enumeration). It 
also causes key events that turn the FEP on or off to be consumed. If the 
FEP is simulating key events, or is off, no key events are consumed (so that 
all are passed on to the underlying application) and the macro returns with 
EKeyWasNotConsumed.

This should be the first thing called in the OfferKeyEventL() function. The 
FEP_END_KEY_EVENT_HANDLER_L macro should be used to return from the function.

@param aFep The CCoeFep object, should not be a pointer
@param aKeyEvent The TKeyEvent object from OfferKeyEventL()
@param aEventCode The TEventCode object from OfferKeyEventL()

@see TEventCode 
@publishedAll
@released */
#define FEP_START_KEY_EVENT_HANDLER_L(aFep, aKeyEvent, aEventCode)\
	{\
	if ((aFep).IsSimulatingKeyEvent())\
		{\
		return EKeyWasNotConsumed;\
		}\
	(aFep).OnStartingHandlingKeyEvent_WithDownUpFilterLC();\
	if (((aEventCode)!=EEventKey))\
		{\
		return (aFep).OnFinishingHandlingKeyEvent_WithDownUpFilterL((aEventCode), (aKeyEvent), EKeyWasConsumed);\
		}\
	if (!(aFep).IsOn())\
		{\
		return (aFep).OnFinishingHandlingKeyEvent_WithDownUpFilterL((aEventCode), (aKeyEvent), EKeyWasNotConsumed);\
		}\
	}

/** Macro to be called by a keyboard-based FEP to return from its CCoeControl::OfferKeyEventL()-overriding 
function.

It should be used instead of the return statement. It should only be used 
if the FEP_START_KEY_EVENT_HANDLER_L macro was used at the start of the function. 

@param aFep The CCoeFep object, should not be a pointer
@param aKeyEvent The TKeyEvent object from OfferKeyEventL()
@param aKeyResponse Defined in EPOC32\INCLUDE\COEDEF.H 
					If set to EKeyWasNotConsumed, allows the key event to reach the underlying application. 
					If set to EKeyWasConsumed, prevents the key event reaching the underlying application.

@publishedAll
@released */
#define FEP_END_KEY_EVENT_HANDLER_L(aFep, aKeyEvent, aKeyResponse)\
	{\
	return (aFep).OnFinishingHandlingKeyEvent_WithDownUpFilterL(EEventKey, (aKeyEvent), (aKeyResponse));\
	}

/** Macro to be called by a keyboard-based FEP at the start of its CCoeControl::OfferKeyEventL()-overriding 
function.

It causes events that turn the FEP on or off to be consumed. This variant 
of the macro ignores key up and key down events so that it should be used 
in preference to FEP_START_KEY_EVENT_HANDLER_L in the rare cases where the 
FEP wishes to handle EEventKeyDown or EEventKeyUp events. If the FEP is simulating 
key events, or is off, no key events are consumed and OfferKeyEventL() returns 
with EKeyWasNotConsumed. 

This should be the first thing called in the OfferKeyEventL() function. The 
FEP_END_KEY_EVENT_HANDLER_NO_DOWN_UP_FILTER_L macro should be used to return 
from the function. 

@param aFep The CCoeFep object, should not be a pointer
@param aKeyEvent The TKeyEvent object from OfferKeyEventL()
@param aEventCode The TEventCode object from OfferKeyEventL()

@publishedAll
@released */
#define FEP_START_KEY_EVENT_HANDLER_NO_DOWN_UP_FILTER_L(aFep, aKeyEvent, aEventCode)\
	{\
	if ((aFep).IsSimulatingKeyEvent())\
		{\
		return EKeyWasNotConsumed;\
		}\
	(aFep).OnStartingHandlingKeyEvent_NoDownUpFilterLC();\
	if ((aEventCode)==EEventKey)\
		{\
		if (!(aFep).IsOn())\
			{\
			return (aFep).OnFinishingHandlingKeyEvent_NoDownUpFilterL((aEventCode), (aKeyEvent), EKeyWasNotConsumed);\
			}\
		}\
	}

/** Macro to be called by a keyboard-based FEP to return from its CCoeControl::OfferKeyEventL()-overriding 
function.

It should be used instead of the return statement. This variant of the macro 
should only be used if the FEP_START_KEY_EVENT_HANDLER_NO_DOWN_UP_FILTER_L 
macro was used at the start of the function. 

@param aFep The CCoeFep object, should not be a pointer
@param aKeyEvent The TKeyEvent object from OfferKeyEventL()
@param aEventCode The TEventCode object from OfferKeyEventL()
@param aKeyResponse Defined in EPOC32\INCLUDE\COEDEF. 
					If set to EKeyWasNotConsumed, allows the key event to reach the underlying application. 
					If set to EKeyWasConsumed, prevents the key event reaching the underlying application.

@publishedAll
@released */
#define FEP_END_KEY_EVENT_HANDLER_NO_DOWN_UP_FILTER_L(aFep, aKeyEvent, aEventCode, aKeyResponse)\
	{\
	return (aFep).OnFinishingHandlingKeyEvent_NoDownUpFilterL((aEventCode), (aKeyEvent), (aKeyResponse));\
	}



#endif // __FEPBUTILS_H__
