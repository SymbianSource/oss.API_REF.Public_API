// Copyright (c) 1999-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __VWSDEF_H__
#define __VWSDEF_H__

#include <e32std.h>

/**
@publishedPartner
*/
#define KUidCustomCrossCheckValue 0x80282748

/**
@publishedPartner
*/
const TUid KUidCustomCrossCheck={KUidCustomCrossCheckValue};

class TVwsViewId
/** Identifies an application view using two unique identifiers (UIDs): a view 
UID and an application UID. 

The application UID is required so that the application associated with the view 
can be started if it is not already running.

@publishedAll 
@released */
	{
public:
	inline TVwsViewId();
	inline TVwsViewId(const TVwsViewId& aUid);
	inline TVwsViewId(TUid aAppUid,TUid aViewUid);
	inline TBool operator==(const TVwsViewId& aUid) const;
	inline TBool operator!=(const TVwsViewId& aUid) const;
public:
	/** A unique application ID (or application UID).
	
	Uniquely identifies the application associated with the view. */
	TUid iAppUid;
	/** A unique view ID (or view UID).
	
	Uniquely identifies the view. */
	TUid iViewUid;
	};

/** @internalTechnology */
#define KNullViewId TVwsViewId(KNullUid,KNullUid)

/** @internalTechnology */
const TInt KErrViewWrongMode=1; // !!! Wrong error code - should be -ve & unique


class TVwsViewIdAndMessage
/**
The TVwsViewIdAndMessage class identifies a view and encapsulates a message to
be read by the view when it is activated.

@publishedAll 
@released 
*/
	{
public:
	inline TVwsViewIdAndMessage();
	inline TVwsViewIdAndMessage(const TVwsViewId& aId);
	inline TVwsViewIdAndMessage(const TVwsViewId& aId,TUid aCustomMessageId,const TDesC8& aCustomMessage);
	inline TVwsViewIdAndMessage& operator=(const TVwsViewIdAndMessage& aVwsViewIdAndMessage);
public:
	TVwsViewId iViewId;
	TUid iCustomMessageId;
	TInt iCustomMessageLength;
	TPtrC8 iCustomMessage;
	};



class TVwsViewEvent
/**
The TVwsViewEvent class encapsulates the attributes of a view server event.
These are:
- The event type
- The view ids of the two views associated with the event
- The attributes of any message which can go with the event.

@publishedPartner
@released 
*/
	{
public:
	enum TVwsViewEventType
		{
		EVwsActivateView,
		EVwsDeactivateView,
		EVwsScreenDeviceChanged,
		EVwsDeactivationNotification,
		EVwsActivationNotification,
		EVwsDeactivateViewDifferentInstance
		};
public:
	inline TVwsViewEvent();
	inline TVwsViewEvent(TVwsViewEventType aEventType);
	inline TVwsViewEvent(TVwsViewEventType aEventType,const TVwsViewId& aViewOneId);
	inline TVwsViewEvent(TVwsViewEventType aEventType,const TVwsViewId& aViewOneId,const TVwsViewId& aViewTwoId);
	inline TVwsViewEvent(TVwsViewEventType aEventType,const TVwsViewId& aViewOneId,const TVwsViewId& aViewTwoId,TUid aCustomMessageId,TInt aCustomMessageLength);
public:
	/**
	The event type.
	*/
	TVwsViewEventType iEventType;
	/**
	The first view id associated with the event. This has a different meaning for each of the event types:
	- For ActivateView events, it is the view to activate
	- For DeactivateView events, it is the view to deactivate
	- For ScreenDeviceChange events, it is the id of the currently active view
	- For ActivationNotification events, it is the id of the activated view
	- For DeactivationNotification events, it is the id of the deactivated view
	*/
	TVwsViewId iViewOneId;
	/**
	The second view id associated with the event. This has a different meaning for each of the event types:
	- For ActivateView events, it is the view that will be deactivated
	- For DeactivateView events, it is the view that has been activated
	- For ScreenDeviceChange events, it is unused
	- For ActivationNotification events, it is the view that will be deactivated
	- For DeactivationNotification events, it is the id of the view that has been activated
	*/
	TVwsViewId iViewTwoId;
	/**
	The type of message being passed in the custom message buffer
	*/
	TUid iCustomMessageId;
	/**
	The length of the custom message being held by the server.
	To retrieve the message itself from the server, a buffer of this length must be allocated
	*/
	TInt iCustomMessageLength;
	};


//
// Typedefs.
//
/** @internalComponent */
typedef TPckgBuf<TVwsViewIdAndMessage> TVwsViewIdAndMessageBuf;

/** @internalComponent */
typedef TPckgBuf<TVwsViewEvent> TVwsViewEventBuf;


//
// Inlines
//

inline TVwsViewId::TVwsViewId()
/** Constructs a TVwsViewId object, and initialises both the application UID and 
the view UID to NULL. */
	: iAppUid(KNullUid), iViewUid(KNullUid) {}

inline TVwsViewId::TVwsViewId(const TVwsViewId& aUid)
/** Constructs a new TVwsViewId object from an existing one. This simply performs 
a member-wise copy, each member variable of the passed in object is individually 
copied to the corresponding member variable of the new object.

@param aUid A reference to the TVwsViewId object to be copied. */
	: iAppUid(aUid.iAppUid), iViewUid(aUid.iViewUid) {}

inline TVwsViewId::TVwsViewId(TUid aAppUid,TUid aViewUid)
/** Constructs a TVwsViewId object with the specified application UID and view UID.

@param aAppUid The application UID.
@param aViewUid The view UID. */
	: iAppUid(aAppUid), iViewUid(aViewUid) {}

inline TBool TVwsViewId::operator==(const TVwsViewId& aUid) const
/** Checks whether the TVwsViewId object being operated upon and the TVwsViewId 
object specified are the same.

Returns true if both application UIDs and both view UIDs are the same, otherwise 
returns false.

@param aUid A reference to a TVwsViewId object.
@return ETrue if objects are the same, EFalse otherwise. */
	{
	return (aUid.iAppUid==iAppUid && aUid.iViewUid==iViewUid);
	}

inline TBool TVwsViewId::operator!=(const TVwsViewId& aUid) const
/** Checks whether the TVwsViewId object being operated upon and the TVwsViewId 
object specified are different.

Returns true if either the application UIDs or view UIDs are different, otherwise 
returns false.

@param aUid A reference to a TVwsViewId object.
@return ETrue if objects are different, EFalse otherwise. */
	{
	return (aUid.iAppUid!=iAppUid || aUid.iViewUid!=iViewUid);
	}


/** Constructs a TVwsViewIdAndMessage object, and initialises it to contain a
NULL view UID and an empty message */
inline TVwsViewIdAndMessage::TVwsViewIdAndMessage()
	: iViewId(TVwsViewId()), iCustomMessageLength(0)
	{
	iCustomMessageId.iUid=0;
	iCustomMessage.Set(KNullDesC8);
	}

/** Constructs a TVwsViewIdAndMessage object, and initialises it to contain the
specified view UID and an empty message

@param aId A reference to the TVwsViewId to be used
*/
inline TVwsViewIdAndMessage::TVwsViewIdAndMessage(const TVwsViewId& aId)
	: iViewId(aId), iCustomMessageLength(0)
	{
	iCustomMessageId.iUid=0;
	iCustomMessage.Set(KNullDesC8);
	}

/** Constructs a TVwsViewIdAndMessage object, and initialises it to contain the
specified view UID and the specified message

@param aId A reference to the TVwsViewId to be used
@param aCustomMessageId The message Id to use
@param aCustomMessage A narrow descriptor containing the message
*/
inline TVwsViewIdAndMessage::TVwsViewIdAndMessage(const TVwsViewId& aId,TUid aCustomMessageId,const TDesC8& aCustomMessage)
	: iViewId(aId), iCustomMessageId(aCustomMessageId)
	{
	iCustomMessageLength=aCustomMessage.Length();
	iCustomMessage.Set(aCustomMessage);
	}

/** Copies the contents of another TVwsViewIdAndMessage into this one

@param aVwsViewIdAndMessage A reference to the TVwsViewIdAndMessage to be copied

@return A reference to the object being copied into
*/
inline TVwsViewIdAndMessage& TVwsViewIdAndMessage::operator=(const TVwsViewIdAndMessage& aVwsViewIdAndMessage)
	{
	iViewId=aVwsViewIdAndMessage.iViewId;
	iCustomMessageId=aVwsViewIdAndMessage.iCustomMessageId;
	iCustomMessageLength=aVwsViewIdAndMessage.iCustomMessage.Length();
	iCustomMessage.Set(aVwsViewIdAndMessage.iCustomMessage);
	return(*this);
	}

inline TVwsViewEvent::TVwsViewEvent() {}

inline TVwsViewEvent::TVwsViewEvent(TVwsViewEventType aEventType)
	: iEventType(aEventType),iViewOneId(),iViewTwoId(),iCustomMessageId(KNullUid),iCustomMessageLength(0) {}

inline TVwsViewEvent::TVwsViewEvent(TVwsViewEventType aEventType,const TVwsViewId& aViewOneId)
	: iEventType(aEventType),iViewOneId(aViewOneId),iViewTwoId(),iCustomMessageId(KNullUid),iCustomMessageLength(0) {}

inline TVwsViewEvent::TVwsViewEvent(TVwsViewEventType aEventType,const TVwsViewId& aViewOneId,const TVwsViewId& aViewTwoId)
	: iEventType(aEventType),iViewOneId(aViewOneId),iViewTwoId(aViewTwoId),iCustomMessageId(KNullUid),iCustomMessageLength(0) {}

inline TVwsViewEvent::TVwsViewEvent(TVwsViewEventType aEventType,const TVwsViewId& aViewOneId,const TVwsViewId& aViewTwoId,TUid aCustomMessageId,TInt aCustomMessageLength)
	: iEventType(aEventType),iViewOneId(aViewOneId),iViewTwoId(aViewTwoId),iCustomMessageId(aCustomMessageId),iCustomMessageLength(aCustomMessageLength) {}


#endif
