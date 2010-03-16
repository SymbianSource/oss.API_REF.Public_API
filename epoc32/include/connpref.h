// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#if !(defined __CONNPREF_H__)
#define __CONNPREF_H__

#define TCommSnapPref TConnSnapPref
#include <e32std.h>

/**
@publishedAll
@released since v7.0s
*/
const TUint KMaxConnPrefSize = 0x40;

/**
@internalTechnology
*/
struct SConnPref
	{
	TInt16 iExtensionId; ///< Extension ID
	TInt16 iSpare;
	};

class TConnPref : public TBuf8<KMaxConnPrefSize>
/**
Overrides the connection preferences.
@publishedAll
@released since v7.0s
*/
	{
public:
	enum
		{
		EConnPrefUnknown = 0x00,     ///< Unknown Connection preference
		EConnPrefCommDb = 0x01,      ///< CommDb Connection preference
		EConnPrefCommDbMulti = 0x02, ///< CommDbMulti Connection preferenc
		EConnPrefSnap = 0x03,
		EConnPrefIdList = 0x04,
		EConnPrefSip = 0x05          ///< Sip Connection preference
		};

	IMPORT_C TConnPref();
	IMPORT_C TConnPref(TInt aExtensionId);
	
	IMPORT_C TInt ExtensionId() const;
	IMPORT_C TInt GetUserLen();

protected:
	IMPORT_C void SetExtensionId(TInt aExtensionId);
	IMPORT_C void SetUserLen(TInt aLen);
	inline TUint8* UserPtr() const;

private:
	inline SConnPref* BasePtr() const;
	};

inline SConnPref* TConnPref::BasePtr() const
	{
	return (SConnPref*)iBuf;
	}

inline TUint8* TConnPref::UserPtr() const
	{
	return (TUint8*)(BasePtr()+1);
	}

class TConnSnapPref : public TConnPref
/**
An instance of the class is passed to RConnection::Start when user wants to start connection based on
Service Network Access Point that represents a collection of AP to try out.

@publishedAll
@released since v9.1
@see RConnection::Start
*/
	{
public:
	IMPORT_C TConnSnapPref();
	IMPORT_C TConnSnapPref(TUint32 aSnap);

	IMPORT_C void SetSnap(TUint32 aSnap);
	IMPORT_C TUint32 Snap() const;
	};

#endif // __CONNPREF_H__
