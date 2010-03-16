// Copyright (c) 2001-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef BTEXTNOTIFIERS_H
#define BTEXTNOTIFIERS_H

#include <e32std.h>
#include <bttypes.h>
#include <btdevice.h>


#define NOTIFIERS_SUPPORT_PASSKEY_MIN_LENGTH

/**
@file
@publishedAll
@released

UID to invoke the device selection dialog via the notifier framework.
**/
const TUid KDeviceSelectionNotifierUid={0x100069D1};

/**
@publishedPartner
@released

UID of the PBAP authentication notifier
*/
const TUid KPbapAuthNotifierUid={0x10282B22};

/**
@publishedPartner
@deprecated
@see "bt_subscribe.h"

UID to notify the UI that a bluetooth link is currently active.
Now deprecated by the publish/subscribe mechanism.
**/
const TUid KUidBTBasebandNotification={0x1000A5FB};

NONSHARABLE_CLASS(TBTDeviceSelectionParams)
/**
@publishedAll
@released

Class to allow parameters to be sent to the device selection dialog via the RNotifier API.
**/
	{
public:
	IMPORT_C TBTDeviceSelectionParams();
	IMPORT_C void SetUUID(const TUUID& aUUID);
	IMPORT_C void SetDeviceClass(TBTDeviceClass aClass);
	IMPORT_C const TUUID& UUID();
	IMPORT_C TBTDeviceClass DeviceClass();
	IMPORT_C TBool IsValidDeviceClass();
	IMPORT_C TBool IsValidUUID();
private:
	TBTDeviceClass iDeviceClass; /*!< The device class */
	TUUID iSdpUuid; /*!< The sdp uuid */
	TBool iValidDeviceClass; /*!< ETrue if iDeviceClass has been set, EFalse if not */
	TBool iValidUuid; /*!< ETrue if iSdpUuid has be set, EFalse if not */

	// This data padding has been added to help prevent future binary compatibility breaks	
	// Neither iPadding1 nor iPadding2 have been zero'd because they are currently not used
	TUint32     iPadding1; 
	TUint32     iPadding2; 	
	};

NONSHARABLE_CLASS(TBTDeviceResponseParams)
/**
@publishedAll
@released

Class to allow parameters to be received from the device selection dialog via the RNotifier API.
**/
	{
public:
	IMPORT_C TBTDeviceResponseParams();
	IMPORT_C void SetDeviceAddress(const TBTDevAddr& aBDAddr);	///< Set the address of the device
	IMPORT_C void SetDeviceName(const TDesC& aName);	///< Set the name of the device
	IMPORT_C void SetDeviceClass(TBTDeviceClass aClass);
	IMPORT_C const TBTDevAddr& BDAddr() const;				///< Returns the address of the device
	IMPORT_C const TDesC& DeviceName() const;		///< Returns the name of the device
	IMPORT_C TBTDeviceClass DeviceClass();
	IMPORT_C TBool IsValidBDAddr() const;			///< Has the address of the device been set?
	IMPORT_C TBool IsValidDeviceName() const;		///< Has the name of the device been set?
	IMPORT_C TBool IsValidDeviceClass();
private:
	TBTDevAddr iBDAddr; /*!< The BT address of the remote device */
	TBuf<KMaxBluetoothNameLen> iDeviceName; /*!< The name given by the remote device */
	TBTDeviceClass iDeviceClass; /*!< The device class */
	TBool iValidBDAddr; /*!< ETrue if iBDAddr has been set, EFalse if not */
	TBool iValidDeviceName; /*!< ETrue if iDeviceName has been set, EFalse if not */
	TBool iValidDeviceClass; /*!< ETrue if iDeviceClass has been set, EFalse if not */
	
	// This data padding has been added to help prevent future binary compatibility breaks	
	// Neither iPadding1 nor iPadding2 have been zero'd because they are currently not used	
	TUint32     iPadding1; 
	TUint32     iPadding2; 	
	};

/**
@publishedAll
@released

Typedef'ed pckgbuf to send paramaters to the device selection dialog via the notifier framework.
**/
typedef TPckgBuf<TBTDeviceSelectionParams> TBTDeviceSelectionParamsPckg;

/**
@publishedAll
@released

Typedef'ed pckgbuf to retrieve the response from the device selection dialog via the notifier framework.
**/
typedef TPckgBuf<TBTDeviceResponseParams> TBTDeviceResponseParamsPckg;

/**
@deprecated
Use TBTDeviceList::MaxNumberOfDevices() instead. Note however that 
you should call this function each time you wish to use this value
rather than storing a copy because the actual value is subject to 
change.
*/
const TUint KMaxPanDevicesForSimultaneousSelection = 8;

NONSHARABLE_CLASS(TBTDeviceList)
/**
A list of TBTDevAddrs
@note Used to pass a list of devices to which to connect.
@publishedPartner
@released
*/
	{
public:
	IMPORT_C TBTDeviceList();
	
	IMPORT_C TInt AddDevice(const TBTDevAddr& aDevAddr);
	IMPORT_C TInt GetDevice(TBTDevAddr& aDevAddr);
	IMPORT_C void Reset();
	
	IMPORT_C operator const TDesC8&();
	IMPORT_C operator TDes8&();
	
	IMPORT_C TUint MaxNumberOfDevices();
	
private:
	const static TUint KMaxDevicesForSimultaneousSelection = 8;

private:
	TInt iPosition;	// the position within the list for stateful reading
	TFixedArray<TBTDevAddr, KMaxDevicesForSimultaneousSelection> iDevices;
	TPckg<TFixedArray<TBTDevAddr, KMaxDevicesForSimultaneousSelection> > iPtr;
		
	const TBTDevAddr iKNullDevAddr;

	// This data padding has been added to help prevent future binary compatibility breaks	
	// Neither iPadding1 nor iPadding2 have been zero'd because they are currently not used
	TUint32     iPadding1; 
	TUint32     iPadding2; 	
	};


/** Maximum length of the Realm text buffer. */
const TUint KPbapAuthRealmLength = 256;

/** Maximum length of the password text buffer. */
const TUint KPbapAuthPasswordLength = 64;

NONSHARABLE_CLASS(TPbapAuthNotifierParams)
/**
Parameters passed to the PBAP authentication notifier plugin
@publishedPartner
@released
*/
	{
public:
	IMPORT_C TPbapAuthNotifierParams();

	IMPORT_C void SetRealm(const TDesC& aRealm);
	IMPORT_C void SetRemoteAddr(const TBTDevAddr& aBDAddr);

	IMPORT_C const TDesC& Realm() const;
	IMPORT_C TBool RealmTruncated() const;
	IMPORT_C const TBTDevAddr& RemoteAddr() const;

	IMPORT_C TBool IsValidRealm() const;
	IMPORT_C TBool IsValidRemoteAddr() const;
	
private:
	TBuf<KPbapAuthRealmLength> iRealm; /*!< The Realm specified by the device requesting authentication. */
	TBool iRealmTruncated; /*!< Set to ETrue if iRealm has been truncated */
	TBTDevAddr iRemoteAddr; /*!< The Bluetooth device address of the device requesting authentication. */ 

	TBool iValidRealm; /*!< ETrue if iRealm has been set, EFalse if not */
	TBool iValidRemoteAddr; /*!< ETrue if iRemoteAddr has been set, EFalse if not */

	// This data padding has been added to help prevent future binary compatibility breaks	
	// iPadding has not been zero'd because they are currently not used
	TUint32     iPadding;
	};

/**
Packaged version of <code>TPbapAuthNotifierParams</code> that allows data transfer over process boundaries.
@publishedPartner
@released
*/
typedef TPckgBuf<TPbapAuthNotifierParams> TPbapAuthNotifierParamsPckg;

NONSHARABLE_CLASS(TPbapAuthNotifierResponse)
/**
Response data from the PBAP authentication notifier plugin
@publishedPartner
@released
*/
	{
public:
	IMPORT_C TPbapAuthNotifierResponse();

	IMPORT_C TBool SetPassword(const TDesC& aPassword);
	IMPORT_C void ResetPassword();

	IMPORT_C const TDesC& Password() const;

	IMPORT_C TBool IsValidPassword() const;

private:
    /** The password used to create the challenge response. */
	TBuf<KPbapAuthPasswordLength> iPassword;

	TBool iValidPassword; /*!< ETrue if iPassword has been set, EFalse if not */

	// This data padding has been added to help prevent future binary compatibility breaks	
	// Neither iPadding1 nor iPadding2 have been zero'd because they are currently not used
	TUint32     iPadding1; 
	TUint32     iPadding2; 	
	};

/**
Packaged version of <code>TPbapAuthNotifierResponse</code> that allows data transfer over process boundaries.
@publishedPartner
@released
*/
typedef TPckgBuf<TPbapAuthNotifierResponse> TPbapAuthNotifierResponsePckg;


/**
A remote device address, and a boolean indicating if the remote device has access
to the uplink
@publishedPartner
@released
*/
NONSHARABLE_CLASS(TPanConnection)
	{
public:
	IMPORT_C TPanConnection(TBTDevAddr& aRemoteDeviceAddress,
				   			TBool aUplinkAccessAllowed);
				   
	IMPORT_C const TBTDevAddr& RemoteDeviceAddress() const;
	IMPORT_C TBool UplinkAccessAllowed() const;
	IMPORT_C TBool IsValid() const;
	
	// Non-exported constructor.  Allows creation of default NULL instance
	TPanConnection();
	
private:
	TBTDevAddr iRemoteDeviceAddress;
	TBool iUplinkAccessAllowed;

	// This data padding has been added to help prevent future binary compatibility breaks	
	// Neither iPadding1 nor iPadding2 have been zero'd because they are currently not used
	TUint32 iPadding1; 
	TUint32 iPadding2; 	
	};


/**
A list of TPanConnection instances
@see TPanConnection
@publishedPartner
@released
*/
NONSHARABLE_CLASS(TPanConnectionList)
	{
public:
	IMPORT_C TPanConnectionList();
	
	IMPORT_C void AddRemoteConnectionL(const TPanConnection& aRemoteConnection);
	IMPORT_C const TPanConnection* GetFirstRemoteConnection();
	IMPORT_C const TPanConnection* GetNextRemoteConnection();

	IMPORT_C void SetRequestedConnectionAddr(const TBTDevAddr& aRequestedConnectionAddr);
	IMPORT_C const TBTDevAddr* RequestedConnectionAddr();

	IMPORT_C const TUUID& CurrentLocalRole() const;
	IMPORT_C void SetCurrentLocalRole(const TUUID& aLocalRole);
		
	IMPORT_C TUint8 MaxNumberOfRemoteConnections();
	
private:
	const static TUint8 KMaxRemoteConnections = 7;

private:
	TUint8 iPosition;	// the position within the list for stateful reading
	TFixedArray<TPanConnection, KMaxRemoteConnections> iRemoteConnections;

	TBTDevAddr iRequestedConnectionAddr;

	TUUID iCurrentLocalRole;
	
	// This data padding has been added to help prevent future binary compatibility breaks	
	// Neither iPadding1 nor iPadding2 have been zero'd because they are currently not used
	TUint32 iPadding1; 
	TUint32 iPadding2; 	
	};

/**
@publishedAll
@released

Typedef'ed pckgbuf for TPanConnectionList.
**/
typedef TPckgBuf<TPanConnectionList> TPanConnectionListPckg;


/**
@publishedAll
@released

The response from the incoming PAN NAP connection selection dialog.
**/
enum TNapConnectionResult
	{
	EDisallowNewNapConnection,
	EAcceptNapConnectionAllowUplinkAccess,
	EAcceptNapConnectionDisallowUplinkAccess,
	};

/**
@publishedAll
@released

Typedef'ed pckgbuf to retrieve the response from the incoming PAN NAP connection 
selection dialog via the notifier framework.
**/
typedef TPckgBuf<TNapConnectionResult> TNapConnectionResultPckg;		




//
// Standard Bluetooth Authentication Notifiers
//


/**
UID of the "Numeric Comparison" confirmation request RNotifier plugin.

The notifier will be started with a parameter of type TBTNumericComparisonParamsPckg.

The notifier will receive updates of type TBTNotifierUpdateParamsPckg2.

@see TBTNotifierUpdateParamsPckg2

@publishedPartner
@released
*/
const TUid KBTNumericComparisonNotifierUid={0x10285AD5};

/**
UID of the "Passkey Entry" display RNotifier plugin.

The notifier will be started with a parameter of type TBTPasskeyDisplayParamsPckg.

The notifier will receive updates of type TBTNotifierUpdateParamsPckg2.

@see TBTNotifierUpdateParamsPckg2

@publishedPartner
@released
*/
const TUid KBTPasskeyDisplayNotifierUid={0x10285AD4};

/**
UID of the "PIN Code Entry" RNotifier plugin.

Note that this is an SSP aware notifier taking the new parameter type.  This is
intended to replace the deprecated KBTManPinNotifierUid RNotifier plugin.
@see KBTManPinNotifierUid

The notifier will be started with a parameter of type TBTPinCodeEntryNotifierParamsPckg.

The notifier will receive updates of type TBTNotifierUpdateParamsPckg2.

@see TBTNotifierUpdateParamsPckg2

@publishedPartner
@released
*/
const TUid KBTPinCodeEntryNotifierUid={0x10285D55};


/**
The base parameter for the secure simple pairing notifiers.
	
@publishedPartner
@released
*/
NONSHARABLE_CLASS(TBTNotifierParams2)	
	{
public:
	IMPORT_C TBTDevAddr DeviceAddress() const;
	IMPORT_C TPtrC DeviceName() const;
	
protected:
	TBTNotifierParams2(const TBTDevAddr& aDevAddr, const TDesC& aDeviceName);
	TBTNotifierParams2();
	
private:
	TBTDevAddr		iBDAddr;
	TBTDeviceName	iName;	
	
	// This data padding has been added to help prevent future binary compatibility breaks	
	// Neither iPadding1 nor iPadding2 have been zero'd because they are currently not used
	TUint32	iPadding1; 
	TUint32	iPadding2; 
	};


/** 
Secure simple pairing "Numeric Comparison" parameters.
This class packages the parameters passed to a numeric comparison notifier.
	
@publishedPartner
@released
*/
NONSHARABLE_CLASS(TBTNumericComparisonParams)
	: public TBTNotifierParams2
	{
public:
	/**
	This represents the type of comparison that is being performed.
	It is intended to allow the UI to present the user of the device
	with suitable information to help them complete the pairing.
	*/
	enum TComparisonScenario
		{
		ERemoteCannotConfirm,	/*!< Only the Symbian device can confirm the displayed numbers are the same. */
		ERemoteCanConfirm,		/*!< Both devices can confirm that the displayed numbers are the same */
		};
		
public:
	IMPORT_C TBTNumericComparisonParams(const TBTDevAddr& aDevAddr, const TDesC& aDeviceName, TUint32 aNumericalValue, TComparisonScenario aComparisonScenario, TBool aLocallyInitiated);
	IMPORT_C TBTNumericComparisonParams();
	
public:
	IMPORT_C TUint32 NumericalValue() const;
	IMPORT_C TComparisonScenario ComparisonScenario() const;
	IMPORT_C TBool LocallyInitiated() const;
	
private:
	TUint32				iNumericalValue;
	TComparisonScenario	iComparisonScenario;
	TBool				iLocallyInitiated;
	
	// This data padding has been added to help prevent future binary compatibility breaks	
	// Neither iPadding1 nor iPadding2 have been zero'd because they are currently not used
	TUint32	iPadding1;
	TUint32 iPadding2;
	};


/**
Secure simple pairing "Passkey Entry" display parameters.
This class packages the parameters passed to a passkey display notifier.
	
@publishedPartner
@released
*/
NONSHARABLE_CLASS(TBTPasskeyDisplayParams)
	: public TBTNotifierParams2	
	{
public:
	IMPORT_C TBTPasskeyDisplayParams(const TBTDevAddr& aDevAddr, const TDesC& aDeviceName, TUint32 aNumericalValue, TBool aLocallyInitiated);
	IMPORT_C TBTPasskeyDisplayParams();
	
public:
	IMPORT_C TUint32 NumericalValue() const;
	IMPORT_C TBool LocallyInitiated() const;
	
private:
	TUint32	iNumericalValue;
	TBool	iLocallyInitiated;
	
	// This data padding has been added to help prevent future binary compatibility breaks	
	// Neither iPadding1 nor iPadding2 have been zero'd because they are currently not used
	TUint32	iPadding1; 
	TUint32	iPadding2;
	};

/** 
Simple secure pairing aware "PIN Code Entry" request parameters.
This class packages the parameters passed to a PIN code entry notifier.
	
@publishedPartner
@released
*/
NONSHARABLE_CLASS(TBTPinCodeEntryNotifierParams)
	: public TBTNotifierParams2
	{
public:
	IMPORT_C TBTPinCodeEntryNotifierParams(const TBTDevAddr& aDevAddr, const TDesC& aDeviceName, TUint aPinCodeMinLength, TBool aLocallyInitiated, TBool aStrongPinCodeRequired, TUint aRecommendedPinCodeMinLength);
	IMPORT_C TBTPinCodeEntryNotifierParams();
	
public:
	IMPORT_C TUint PinCodeMinLength() const;
	IMPORT_C TBool LocallyInitiated() const;
	IMPORT_C TBool StrongPinCodeRequired() const;
	IMPORT_C TUint RecommendedPinCodeMinLength() const;
	
private:
	TUint	iPinCodeMinLength;
	TBool	iLocallyInitiated;
	TBool	iStrongPinCodeRequired;
	//TUint32 used here as this space was once a padding field.
	TUint32	iRecommendedPinCodeMinLength;
	
	// This data padding has been added to help prevent future binary compatibility breaks	
	// iPadding1 has not been zero'd because it is currently not used
	TUint32	iPadding1; 
	};


/**
The base update parameter for the Bluetooth pairing notifiers.
This class is intended to allow multiple different updates parameters to be
passed to the Bluetooth notifiers.
	
@publishedPartner
@released
*/
NONSHARABLE_CLASS(TBTNotifierUpdateParams2)
	{
public:
	enum TUpdateParamType
		{
		EDeviceName,
		EPasskeyDisplay,
		};
	
public:
	IMPORT_C TBTNotifierUpdateParams2();
	IMPORT_C TUpdateParamType Type() const;
	
protected:
	TBTNotifierUpdateParams2(TBTNotifierUpdateParams2::TUpdateParamType aType);
	
private:
	TUpdateParamType	iType;
	
	// This data padding has been added to help prevent future binary compatibility breaks	
	// Neither iPadding1 nor iPadding2 have been zero'd because they are currently not used
	TUint32	iPadding1;
	TUint32	iPadding2;
	};


/** 
Bluetooth device name update parameter.
This class provides the parameters to indicate an update to the name of
the Bluetooth device for which the notifier is waiting for input.
	
@publishedPartner
@released
*/
NONSHARABLE_CLASS(TBTDeviceNameUpdateParams)
	: public TBTNotifierUpdateParams2
	{
public:
	IMPORT_C TBTDeviceNameUpdateParams(const TDesC& aDeviceName, TInt aResult);
	IMPORT_C TBTDeviceNameUpdateParams();
	
public:
	IMPORT_C TPtrC DeviceName() const;
	IMPORT_C TInt Result() const;
	
private:
	TBTDeviceName	iDeviceName;
	TInt			iResult;
	
	// This data padding has been added to help prevent future binary compatibility breaks	
	// Neither iPadding1 nor iPadding2 have been zero'd because they are currently not used
	TUint32	iPadding1; 
	TUint32	iPadding2;
	};

/** 
Secure simple pairing "Passkey Entry" display update parameters.
This class provides the update parameters associated with a passkey entry
display notifier.  Notably it provides the notification of keypresses from
the remote device.

@publishedPartner
@released
*/
NONSHARABLE_CLASS(TBTPasskeyDisplayUpdateParams) 
	: public TBTNotifierUpdateParams2	
	{
public:
	IMPORT_C TBTPasskeyDisplayUpdateParams(THCIPasskeyEntryNotificationType aNotificationType);
	IMPORT_C TBTPasskeyDisplayUpdateParams();
	
public:
	IMPORT_C THCIPasskeyEntryNotificationType KeypressNotification() const;
	
private:
	THCIPasskeyEntryNotificationType iNotificationType;
	
	TUint32 iPadding1;
	TUint32 iPadding2;
	};

/**
Typedef'ed pckgbuf to send numeric comparison parameters to the notifier framework.
@publishedPartner
@released
*/
typedef TPckgBuf<TBTNumericComparisonParams> TBTNumericComparisonParamsPckg;
/**
Typedef'ed pckgbuf to send passkey entry display parameters to the notifier framework.
@publishedPartner
@released
*/
typedef TPckgBuf<TBTPasskeyDisplayParams> TBTPasskeyDisplayParamsPckg;
/**
Typedef'ed pckgbuf to send PIN code entry parameters to the notifier framework.
@publishedPartner
@released
*/
typedef TPckgBuf<TBTPinCodeEntryNotifierParams> TBTPinCodeEntryNotifierParamsPckg;

/**
Typedef'ed pckgbuf to represent the base class of Bluetooth update parameters.
@publishedPartner
@released
*/
typedef TPckgBuf<TBTNotifierUpdateParams2> TBTNotifierUpdateParamsPckg2;
/**
Typedef'ed pckgbuf to send device name update parameters to the notifier framework.
@publishedPartner
@released
*/
typedef TPckgBuf<TBTDeviceNameUpdateParams> TBTDeviceNameUpdateParamsPckg;
/**
Typedef'ed pckgbuf to send passkey entry display update parameters to the notifier framework.
@publishedPartner
@released
*/
typedef TPckgBuf<TBTPasskeyDisplayUpdateParams> TBTPasskeyDisplayUpdateParamsPckg;

#endif // BTEXTNOTIFIERS_H
